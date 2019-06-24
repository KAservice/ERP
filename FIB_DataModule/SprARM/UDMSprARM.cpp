//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "UDMSprARM.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMSprARM::TDMSprARM(TComponent* Owner)
        : TDataModule(Owner)
{
flSaveElement=false;
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//---------------------------------------------------------------------------
bool TDMSprARM::Init(void)
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

DM_Connection->GetPrivDM(GCPRIV_DM_Setup);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprARM::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprARM::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void __fastcall TDMSprARM::Element1CalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;
}
//---------------------------------------------------------------------------
void  TDMSprARM::OpenTable()
{
Table->Active=false;
Table->Open();

}

//---------------------------------------------------------------------------

void  TDMSprARM::NewElement()
{
Element->Active=false;
Element->Open();
Element->Insert();

flSaveElement=false;
}
//---------------------------------------------------------------------------

int TDMSprARM::OpenElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
if (Res>0) flSaveElement=true;
return Res;
}
//---------------------------------------------------------------------------

bool  TDMSprARM::SaveElement()
{
__int64 id=glStrToInt64(ElementID_SARM->AsString);
bool result=false;
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
		result=true;
		flSaveElement=true;
		OpenElement(id);
        }
        catch(Exception &exception)
				{
				//IBTrUpdate->Rollback();
				CodeError=1;
				TextError=exception.Message;
				result=false;
				}
return result;
}
//---------------------------------------------------------------------------
void TDMSprARM::DeleteElement(__int64 Id)
{
flSaveElement=false;
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
        catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				CodeError=1;
				TextError=exception.Message;
                }
        }
}

//---------------------------------------------------------------------------
int TDMSprARM::FindPoCodu(int code)
{
int res=0;
TpFIBQuery * query=new TpFIBQuery(0);
try {

		query->Database=DM_Connection->pFIBData;
		query->Transaction=IBTr;
		query->SQL->Add("select ID_SARM from SARM where CODE_SARM="+IntToStr(code));
        if (IBTr->Active==false) IBTr->StartTransaction();
		query->ExecQuery();
		res=OpenElement(query->FieldByName("ID_SARM")->AsInt64);
	}
__finally
	{
	delete query;
	}
return res;
}
//---------------------------------------------------------------------------
int TDMSprARM::FindPoName(String name)
{
int res=0;
TpFIBQuery * query=new TpFIBQuery(0);
try { 
		query->Database=DM_Connection->pFIBData;
		query->Transaction=IBTr;
		query->SQL->Add("select ID_SARM from SARM where NAME_SARM='"+name+"'");
		if (IBTr->Active==false) IBTr->StartTransaction();
		query->ExecQuery();
		res=OpenElement(query->FieldByName("ID_SARM")->AsInt64);
	}
__finally
	{
	delete query;
	}
return res;
}
//---------------------------------------------------------------------------


AnsiString TDMSprARM::GetGIDElement(__int64 id)
{
AnsiString res=0;
		if (id!=0 )
				{
				TpFIBQuery * query=new TpFIBQuery(0);
				try {
					query->Database=DM_Connection->pFIBData;
					query->Transaction=IBTr;
					query->SQL->Add("select GID_SARM from SARM where ID_SARM=:PARAM_ID");
					query->ParamByName("PARAM_ID")->AsInt64=id;
					if (IBTr->Active==false) IBTr->StartTransaction();
					query->ExecQuery();
					res=OpenElement(query->FieldByName("ID_SARM")->AsInt64);

					if (query->RecordCount==1)
						{
						res=Trim(query->FieldByName("GID_SARM")->AsString);
						}
					else res="";
					}
				__finally
					{
					delete query;
					}
				}

return res;
}
//---------------------------------------------------------------------------
AnsiString TDMSprARM::GetParameter(AnsiString parameter)
{
AnsiString str_parameter=ElementSTRPAR_SARM->AsString;
AnsiString result="";
int position=0;
position=str_parameter.AnsiPos(parameter);
if (position!=0)
        {
        str_parameter.Delete(1,position+parameter.Length());
        for(int i=1; i<=str_parameter.Length();i++)
                {
                if (str_parameter[i]==';')
                        {
                         break;
                        }
                else
                        {
                         result=result+str_parameter[i];
                        }
                }
        }
return result;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprARM::TableCalcFields(TDataSet *DataSet)
{
Table->FieldByName("RECNO")->AsInteger=Table->RecNo;
}
//---------------------------------------------------------------------------

void __fastcall TDMSprARM::ElementNewRecord(TDataSet *DataSet)
{
ElementCODE_SARM->AsInteger=GetMaxCode()+1;
}
//---------------------------------------------------------------------------
int TDMSprARM::GetMaxCode(void)
{
int result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select max(CODE_SARM) AS MAXCODE from  SARM ");
Query->ExecQuery();
result=Query->FieldByName("MAXCODE")->AsInteger;

return result;
}
//----------------------------------------------------------------------------
