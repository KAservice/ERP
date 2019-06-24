//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprKlientDopFisL.h"
#include "UGlobalConstant.h"
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

__fastcall TDMSprKlientDopFisL::TDMSprKlientDopFisL(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//----------------------------------------------------------------------------
bool TDMSprKlientDopFisL::Init(void)
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

Element->Database=DM_Connection->pFIBData;


DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprKlientDopFisL::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------

void __fastcall TDMSprKlientDopFisL::DataModuleDestroy(TObject *Sender)
{

Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TDMSprKlientDopFisL::NewElement(void)
{
Element->Active=false;
Element->Open();
Element->Insert();
}
//---------------------------------------------------------------------------

int TDMSprKlientDopFisL::OpenElement(void)
{
Element->Active=false;
Element->ParamByName("PARAM_IDKLIENT_SKLIENT_DOPFISL")->AsInt64=IdKlient;

Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------
bool  TDMSprKlientDopFisL::SaveElement()
{
bool res=false;
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
        OpenElement();
        res=true;
        }
catch(Exception &exception)
        {
        Error=true;
        TextError="Не удалось записать элемент справочника!";
        }

return res;
}
//---------------------------------------------------------------------------
bool TDMSprKlientDopFisL::DeleteElement(void)
{
bool result=false;
Element->Active=false;
Element->ParamByName("PARAM_IDKLIENT_SKLIENT_DOPFISL")->AsInt64=IdKlient;
Element->Active=true;
if (Element->RecordCount==1)
        {
        Element->Delete();
        try
                {
                Element->ApplyUpdates();
				IBTrUpdate->Commit();
				result=true;
                }
		catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				result=false;
                }
		}
else
	{
	if (Element->RecordCount==0)
		{
		 result=true;
		}
	}
return result;
}

//---------------------------------------------------------------------------




void __fastcall TDMSprKlientDopFisL::ElementNewRecord(TDataSet *DataSet)
{
ElementIDKLIENT_SKLIENT_DOPFISL->AsInt64=IdKlient;

}
//---------------------------------------------------------------------------



void __fastcall TDMSprKlientDopFisL::ElementPOL_SKLIENT_DOPFISLGetText(TField *Sender,
          UnicodeString &Text, bool DisplayText)
{
switch (ElementPOL_SKLIENT_DOPFISL->AsInteger)
		{
		case 1 :
				{
				Text="Мужской";
				} break;
		case 2 :
				{
				Text="Женский";
				} break;
        default :
                {
                Text="Не задан";
                } break;
		}
}
//---------------------------------------------------------------------------

void __fastcall TDMSprKlientDopFisL::ElementPOL_SKLIENT_DOPFISLSetText(TField *Sender,
          const UnicodeString Text)
{
bool a=false;
if(Text=="Мужской")
		{
		ElementPOL_SKLIENT_DOPFISL->AsInteger=1;
		a=true;
		}
if(Text=="Женский")
		{
		ElementPOL_SKLIENT_DOPFISL->AsInteger=2;
		a=true;
		}

if (a==false)
		{
		ElementPOL_SKLIENT_DOPFISL->AsInteger=0;
		}
}
//---------------------------------------------------------------------------

