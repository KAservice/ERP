//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprKlientDopUrL.h"
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

__fastcall TDMSprKlientDopUrL::TDMSprKlientDopUrL(TComponent* Owner)
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
bool TDMSprKlientDopUrL::Init(void)
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
int TDMSprKlientDopUrL::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprKlientDopUrL::DataModuleDestroy(TObject *Sender)
{

Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TDMSprKlientDopUrL::NewElement(void)
{
Element->Active=false;
Element->Open();
Element->Insert();
}
//---------------------------------------------------------------------------

int TDMSprKlientDopUrL::OpenElement(void)
{
Element->Active=false;
Element->ParamByName("PARAM_IDKLIENT_SKLIENT_DOPURL")->AsInt64=IdKlient;

Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------
bool  TDMSprKlientDopUrL::SaveElement()
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
				TextError=exception.Message;
        }

return res;
}
//---------------------------------------------------------------------------
bool TDMSprKlientDopUrL::DeleteElement(void)
{
bool result=false;
Element->Active=false;
Element->ParamByName("PARAM_IDKLIENT_SKLIENT_DOPURL")->AsInt64=IdKlient;
Element->Active=true;
if (Element->RecordCount==1)
        {
		Element->Delete();
        try
                {
                Element->ApplyUpdates();
				IBTr->Commit();
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




void __fastcall TDMSprKlientDopUrL::ElementNewRecord(TDataSet *DataSet)
{
ElementIDKLIENT_SKLIENT_DOPURL->AsInt64=IdKlient;

}
//---------------------------------------------------------------------------

