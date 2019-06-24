//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMTableNumberDoc.h"

#include "DateUtils.hpp"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMTableNumberDoc::TDMTableNumberDoc(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//---------------------------------------------------------------------------
void __fastcall TDMTableNumberDoc::DataModuleCreate(TObject *Sender)
{
ExecPriv=true;
InsertPriv=true;
EditPriv=true;
DeletePriv=true;
}
//---------------------------------------------------------------------------
bool TDMTableNumberDoc::Init(void)
{
bool result=false;
if (InterfaceMainObject>0)
	{
	//получим соединение
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//получим интерфейс COM системы для создания новых объектов
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}
IBTr->DefaultDatabase=DM_Connection->pFIBData;
IBTrUpdate->DefaultDatabase=DM_Connection->pFIBData;

Table->Database=DM_Connection->pFIBData;
Element->Database=DM_Connection->pFIBData;
Query->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_TableNumberDoc);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}

//---------------------------------------------------------------------------
int TDMTableNumberDoc::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMTableNumberDoc::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TDMTableNumberDoc::OpenTable(void)
{

Table->Active=false;
Table->Open();
}

//---------------------------------------------------------------------------

void  TDMTableNumberDoc::SaveIsmen()
{
try
        {
        Table->ApplyUpdates();
		IBTrUpdate->Commit();
        OpenTable();
        }
        catch(Exception &exception)
				{
			   //	IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
}
//---------------------------------------------------------------------------

void  TDMTableNumberDoc::CancelIsmen()
{
try
        {
        Table->CancelUpdates();
		//IBTrUpdate->Commit();
        OpenTable();
        }
		catch(Exception &exception)
				{
				//IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
}
//---------------------------------------------------------------------------

void  TDMTableNumberDoc::NewElement()
{
Element->Active=false;
Element->Open();
Element->Insert();

}
//---------------------------------------------------------------------------

int TDMTableNumberDoc::OpenElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
Element->Active=true;
int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

void  TDMTableNumberDoc::SaveElement()
{
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
        }
catch(...)
        {
        Error=true;
        TextError="Не удалось записать элемент!";
        }
}
//---------------------------------------------------------------------------
void TDMTableNumberDoc::DeleteElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        Element->Delete();
        try
                {
                Element->ApplyUpdates();
				IBTrUpdate->Commit();
                }
        catch(...)
                {
                Error=true;
                TextError="Не удалось удалить элемент!";
                }
        }
}
//---------------------------------------------------------------------------



void __fastcall TDMTableNumberDoc::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMTableNumberDoc::TableTYPE_TNUM_DOCGetText(TField *Sender,
      AnsiString &Text, bool DisplayText)
{
if (TableTYPE_TNUM_DOC->AsInteger==0)
		{
		Text="Не задан";
		}
if (TableTYPE_TNUM_DOC->AsInteger==1)
		{
		Text="С начала года";
		}
if (TableTYPE_TNUM_DOC->AsInteger==2)
		{
		Text="С начала квартала";
		}
if (TableTYPE_TNUM_DOC->AsInteger==3)
		{
		Text="С начала месяца";
		}
if (TableTYPE_TNUM_DOC->AsInteger==4)
		{
		Text="С начала дня";
		}
}
//---------------------------------------------------------------------------

void __fastcall TDMTableNumberDoc::TableTYPE_TNUM_DOCSetText(TField *Sender,
      const AnsiString Text)
{
if(Text=="Не задан")
		{
		TableTYPE_TNUM_DOC->AsInteger=0;
		}
if(Text=="С начала года")
		{
		TableTYPE_TNUM_DOC->AsInteger=1;
		}
if(Text=="С начала квартала")
		{
		TableTYPE_TNUM_DOC->AsInteger=2;
		}
if(Text=="С начала месяца")
		{
		TableTYPE_TNUM_DOC->AsInteger=3;
		}
if(Text=="С начала дня")
		{
		TableTYPE_TNUM_DOC->AsInteger=4;
		}
}
//----------------------------------------------------------------------------
TDateTime TDMTableNumberDoc::GetPosNachNumDoc(AnsiString type_doc)
{
TDateTime result=0;
int type_num=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select TYPE_TNUM_DOC from TNUM_DOC where DOC_TNUM_DOC='"+type_doc+"'");
Query->ExecQuery();
type_num=Query->FieldByName("TYPE_TNUM_DOC")->AsInteger;
Query->Close();


switch (type_num)
	{
	case 0:  //не задан
		{
		result=0;
		}break;
	case 1:  //начало года
		{
		result=EncodeDate(YearOf(Date()),1,1);
		}break;
	case 2:   //начало квартала
		{
		if (EncodeDate(YearOf(Date()),1,1)< Date() && Date()< EncodeDate(YearOf(Date()),4,1))
			{
			result=EncodeDate(YearOf(Date()),1,1);
			}
		if (EncodeDate(YearOf(Date()),4,1)< Date() && Date()< EncodeDate(YearOf(Date()),7,1))
			{
			result=EncodeDate(YearOf(Date()),4,1);
			}
		if (EncodeDate(YearOf(Date()),7,1)< Date() && Date()< EncodeDate(YearOf(Date()),10,1))
			{
			result=EncodeDate(YearOf(Date()),7,1);
			}
		if (EncodeDate(YearOf(Date()),10,1)< Date() && Date()< EncodeDate(YearOf(Date())+1,1,1))
			{
			result=EncodeDate(YearOf(Date()),7,1);
			}

		}break;
	case 3:   //начало месяца
		{
        result=Date()-DayOf(Date())+1;
		}break;
	case 4:  //начало дня
		{
        result=Date();
		}break;
	}

return result;



}
//----------------------------------------------------------------------------


