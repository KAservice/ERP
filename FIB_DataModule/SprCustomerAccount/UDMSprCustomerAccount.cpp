//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "UDMSprCustomerAccount.h"
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

__fastcall TDMSprCustomerAccount::TDMSprCustomerAccount(TComponent* Owner)
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
bool TDMSprCustomerAccount::Init(void)
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

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprCustomerAccount::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprCustomerAccount::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
UnicodeString TDMSprCustomerAccount::GetTextQuery(__int64 id_grp, bool all)
{
UnicodeString result="";



if(all==true)
		{
		 result=" select cust_account.*,       \
								suser.name_user,        \
								suser.idgrp_user,        \
								sgrpuser.name_sgrpuser   \
						from cust_account                 \
						left outer join suser on suser.id_user=cust_account.iduser_cust_account     \
						left outer join sgrpuser on sgrpuser.id_sgrpuser=suser.idgrp_user ";

        }
else
        {
        if (IdGrp==0)
				{
		 result=" select cust_account.*,       \
								suser.name_user,        \
								suser.idgrp_user,        \
								sgrpuser.name_sgrpuser   \
						from cust_account                 \
						left outer join suser on suser.id_user=cust_account.iduser_cust_account     \
						left outer join sgrpuser on sgrpuser.id_sgrpuser=suser.idgrp_user           \
						where cust_account.idgrp_cust_account is null ";

                }
        else
                {
				result=
						" select cust_account.*,       \
								suser.name_user,        \
								suser.idgrp_user,        \
								sgrpuser.name_sgrpuser   \
						from cust_account                 \
						left outer join suser on suser.id_user=cust_account.iduser_cust_account     \
						left outer join sgrpuser on sgrpuser.id_sgrpuser=suser.idgrp_user           \
						where cust_account.idgrp_cust_account='"+IntToStr(id_grp)+"' ";
				}
		}

return result;
}
//---------------------------------------------------------------------------
void  TDMSprCustomerAccount::OpenTable(__int64 id_grp,bool all)
{
IdGrp=id_grp;
AllElement=all;
Table->Active=false;
Table->SelectSQL->Clear();
Table->SelectSQL->Add(GetTextQuery(id_grp,all));
Table->Open();
}

//---------------------------------------------------------------------------

bool  TDMSprCustomerAccount::NewElement(__int64 id_grp)
{
bool result=true;
IdGrp=id_grp;
Element->Active=false;

Element->Open();
Element->Insert();
if (id_grp!=0)
	{
	ElementIDGRP_CUST_ACCOUNT->AsString=IdGrp;
	}


return result;
}
//---------------------------------------------------------------------------

int TDMSprCustomerAccount::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}

//----------------------------------------------------------------------------
__int64 TDMSprCustomerAccount::FindPoName(UnicodeString name)
{
__int64 result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select cust_account.id_cust_account from cust_account where cust_account.name_cust_account=:PARAM_NAME");
Query->ParamByName("PARAM_NAME")->AsString=name;
Query->ExecQuery();
result=Query->FieldByName("id_cust_account")->AsInt64;
Query->Close();
return result;


}

//---------------------------------------------------------------------------
bool  TDMSprCustomerAccount::SaveElement()
{
bool res=false;
IdElement=glStrToInt64(ElementID_CUST_ACCOUNT->AsString);




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
bool TDMSprCustomerAccount::DeleteElement(__int64 id)
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
void TDMSprCustomerAccount::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
OpenElement(id_element);
Element->Edit();
ElementIDGRP_CUST_ACCOUNT->AsString=id_new_grp;
Element->Post();
SaveElement();
}
//------------------------------------------------------------------------------


__int64 TDMSprCustomerAccount::GetIdGrp(__int64 id_el)
{
__int64 res;
res=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select cust_account.idgrp_cust_account from cust_account where cust_account.id_cust_account=:PARAM_ID");
Query->ParamByName("PARAM_ID")->AsString=id_el;
Query->ExecQuery();
res=Query->FieldByName("idgrp_cust_account")->AsInt64;
Query->Close();
return res;

}
//-----------------------------------------------------------------------------

