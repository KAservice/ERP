//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprNomRest.h"
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

__fastcall TDMSprNomRest::TDMSprNomRest(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
flSaveElement=false;
}
//----------------------------------------------------------------------------
bool TDMSprNomRest::Init(void)
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
IBQ->Database=DM_Connection->pFIBData;


DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprNomRest::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprNomRest::DataModuleDestroy(TObject *Sender)
{

Element->Active=false;
IBQ->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//--------------------------------------------------------------------------
void TDMSprNomRest::OpenTable(void)
{

Table->Active=false;
Table->ParamByName("PARAM_IDNOM")->AsInt64=IdNom;
Table->Active=true;

}
//---------------------------------------------------------------------------

void  TDMSprNomRest::NewElement(void)
{
Element->Active=false;
Element->Open();
Element->Insert();
flSaveElement=false;
}
//---------------------------------------------------------------------------

int TDMSprNomRest::OpenElement(void)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;

Element->Active=true;
flSaveElement=true;
int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------
bool  TDMSprNomRest::SaveElement()
{
bool res=false;
try
        {
		Id=ElementID_NOMREST->AsInt64;
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
        OpenElement();
        res=true;
        }
catch(Exception &exception)
        {
				Error=true;
				TextError=exception.Message;
        }

return res;
}
//---------------------------------------------------------------------------
void TDMSprNomRest::DeleteElement(void)
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
                IBTr->Commit();
                }
		catch(Exception &exception)
                {
                IBTr->Rollback();
				Error=true;
				TextError=exception.Message;
                }
        }
}

//---------------------------------------------------------------------------


__int64 TDMSprNomRest::GetTekSostav(__int64 idNom, TDateTime pos)
{
__int64 ID=0;

IdNom=idNom;
OpenTable();
Table->First();

TDateTime MinPos;

if (Table->RecordCount>0)
        {
        MinPos=pos-TablePOS_NOMREST->AsDateTime;
		ID=TableID_NOMREST->AsInt64;
        }


while  (!Table->Eof)
        {
        if ((pos-TablePOS_NOMREST->AsDateTime) < MinPos &&
            (pos>=TablePOS_NOMREST->AsDateTime))
                {
                 MinPos=pos-TablePOS_NOMREST->AsDateTime;
				 ID=TableID_NOMREST->AsInt64;
                }
        Table->Next();
        }

if (ID>0)
        {
        Id=ID;
        OpenElement();
        }

return ID;
}
//----------------------------------------------------------------------------
void __fastcall TDMSprNomRest::ElementNewRecord(TDataSet *DataSet)
{
ElementIDNOM_NOMREST->AsInt64=IdNom;
ElementPOS_NOMREST->AsDateTime=Now();

}
//---------------------------------------------------------------------------

void __fastcall TDMSprNomRest::TableNAME_NOMRESTGetText(TField *Sender,
      AnsiString &Text, bool DisplayText)
{
if (TableNAME_NOMREST->AsString==""  ||
	 TableNAME_NOMREST->AsString==" "   )
		{
		Text="Наименование не задано";
		}
else
		{
		Text=TableNAME_NOMREST->AsString;
		}
}
//---------------------------------------------------------------------------

void __fastcall TDMSprNomRest::IBQCalcFields(TDataSet *DataSet)
{
if (IBQVALUE_SSEZKF->AsFloat==0)
		{
		IBQSEZKF->AsFloat=1;
		}
else
		{
		IBQSEZKF->AsFloat=IBQVALUE_SSEZKF->AsFloat;
		}


		// сезонный к на эту продукцию данного ингридиента
if (IBQVALUE_SSEZKF_SPROD->AsFloat==0)
		{
		IBQSEZKF_SPROD->AsFloat=1;
		}
else
		{
		IBQSEZKF_SPROD->AsFloat=IBQVALUE_SSEZKF_SPROD->AsFloat;
		}
}
//---------------------------------------------------------------------------


