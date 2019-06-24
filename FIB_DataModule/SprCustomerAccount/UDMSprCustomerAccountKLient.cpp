//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprCustomerAccountKLient.h"
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
__fastcall TDMSprCustomerAccountKlient::TDMSprCustomerAccountKlient(TComponent* Owner)
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
bool TDMSprCustomerAccountKlient::Init(void)
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

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprCustomerAccountKlient::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprCustomerAccountKlient::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TDMSprCustomerAccountKlient::OpenTable(__int64 id_account)
{
IdAccount=id_account;
Table->Active=false;
Table->ParamByName("PARAM_IDACCOUNT")->AsInt64=id_account;
Table->Open();
}

//---------------------------------------------------------------------------
int TDMSprCustomerAccountKlient::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}

//----------------------------------------------------------------------------
bool  TDMSprCustomerAccountKlient::NewElement(__int64 id_account)
{
IdAccount=id_account;

bool result=true;

Element->Active=false;

Element->Open();
Element->Append();
if (id_account!=0)
	{
	ElementIDACCOUNT_CUST_KLIENT->AsString=id_account;
	}


return result;
}

//---------------------------------------------------------------------------
bool  TDMSprCustomerAccountKlient::SaveElement()
{
bool res=false;
IdElement=glStrToInt64(ElementID_CUST_KLIENT->AsString);

try
        {

        Element->ApplyUpdates();
		IBTrUpdate->Commit();

        OpenElement(IdElement);
        res=true;
        }
catch(Exception &exception)
        {
        Error=true;
		TextError=exception.Message;
		//ShowMessage(TextError);
        }

return res;
}
//---------------------------------------------------------------------------
bool TDMSprCustomerAccountKlient::DeleteElement(__int64 id)
{
bool result=true;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
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
				TextError=exception.Message;
				result=false;
				}
		}

return result;
}
//----------------------------------------------------------------------------




void __fastcall TDMSprCustomerAccountKlient::TableNewRecord(TDataSet *DataSet)
{
//TableIDNOM_SPROD->AsInteger=IdNom;
TableIDACCOUNT_CUST_KLIENT->AsString=IdAccount;


}
//---------------------------------------------------------------------------
bool TDMSprCustomerAccountKlient::SaveIsmen(void)
{
bool result=false;
try
		{
		Table->ApplyUpdates();
		if (IBTrUpdate->Active==true)
			{
			IBTrUpdate->Commit();
			}
		OpenTable(IdAccount);
		result=true;
		}
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//---------------------------------------------------------------------------
bool TDMSprCustomerAccountKlient::CancelIsmen(void)
{
bool result=true;
try
        {
		Table->CancelUpdates();
		if (IBTrUpdate->Active==true)
			{
			IBTrUpdate->Commit();
			}
		OpenTable(IdAccount);
        }
        catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
return result;

}
//---------------------------------------------------------------------------
bool TDMSprCustomerAccountKlient::TableAppend(__int64 id_account)
{
bool result=true;

Table->Append();
if (id_account!=0)
	{
	TableIDACCOUNT_CUST_KLIENT->AsString=id_account;
	}
return result;

}
//---------------------------------------------------------------------------
bool TDMSprCustomerAccountKlient::TableDelete(void)
{
bool result=true;
Table->Delete();
return result;

}
//---------------------------------------------------------------------------





