//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMSprCustomerMainMenuGrp.h"
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
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMSprCustomerMainMenuGrp::TDMSprCustomerMainMenuGrp(TComponent* Owner)
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
void __fastcall TDMSprCustomerMainMenuGrp::DataModuleCreate(TObject *Sender)
{
ExecPriv=true;
InsertPriv=true;
EditPriv=true;
DeletePriv=true;
}
//---------------------------------------------------------------------------
bool TDMSprCustomerMainMenuGrp::Init(void)
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
MenuTable->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}

//---------------------------------------------------------------------------
int TDMSprCustomerMainMenuGrp::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprCustomerMainMenuGrp::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
MenuTable->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void  TDMSprCustomerMainMenuGrp::OpenTable(__int64 id_account, __int64 id_grp_user)
{
IdGrpUser=id_grp_user;
IdAccount=id_account;

Table->Active=false;
Table->ParamByName("PARAM_IDGRPUSER")->AsInt64=id_grp_user;
Table->ParamByName("PARAM_IDACCOUNT")->AsInt64=id_account;
Table->Open();

}

//---------------------------------------------------------------------------
void TDMSprCustomerMainMenuGrp::Table_First(void)
{
Table->First();
}
//---------------------------------------------------------------------------
void TDMSprCustomerMainMenuGrp::Table_Next(void)
{
Table->Next();
}
//----------------------------------------------------------------------------
void  TDMSprCustomerMainMenuGrp::NewElement(__int64 id_account,__int64 id_grp_user, __int64 id_grp)
{
IdGrpUser=id_grp_user;
IdAccount=id_account;
Element->Active=false;
Element->Open();

Element->Append();
ElementIDACCOUNT_CUST_MAINMENU_GRP->AsString=id_account;

if (id_grp_user!=0)
        {
		ElementIDGRPUSER_CUST_MAINMENU_GRP->AsString=id_grp_user;
        }
if(id_grp!=0)
        {
		ElementIDGRP_CUST_MAINMENU_GRP->AsString=id_grp;
		}
Element->Post();
}
//---------------------------------------------------------------------------

int TDMSprCustomerMainMenuGrp::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------
void TDMSprCustomerMainMenuGrp::Element_Edit(void)
{
Element->Edit();
}
//-------------------------------------------------------------------------
void TDMSprCustomerMainMenuGrp::Element_Post(void)
{
Element->Post();
}
//----------------------------------------------------------------------------
bool  TDMSprCustomerMainMenuGrp::SaveElement()
{
bool result=false;
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
		result=true;
        }
catch(Exception &exception)
        {
		   //		IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				result=false;
		}
return result;
}
//---------------------------------------------------------------------------
bool TDMSprCustomerMainMenuGrp::DeleteElement(__int64 id)
{
bool result=false;
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
				Error=true;
				TextError=exception.Message;
				result=false;
                }
		}
return result;
}
//-----------------------------------------------------------------

void TDMSprCustomerMainMenuGrp::OpenMenuTable(int num_application, __int64 id_grp_user)
{
MenuTable->Active=false;
MenuTable->ParamByName("PARAM_APPLICATION")->AsInteger=num_application;
MenuTable->ParamByName("PARAM_IDGRPUSER")->AsInt64=id_grp_user;
MenuTable->Active=true;
}
//---------------------------------------------------------------------



