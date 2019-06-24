//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UDMSprCustomerMainMenu.h"
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
__fastcall TDMSprCustomerMainMenu::TDMSprCustomerMainMenu(TComponent* Owner)
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
bool TDMSprCustomerMainMenu::Init(void)
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

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprCustomerMainMenu::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprCustomerMainMenu::DataModuleDestroy(TObject *Sender)
{

Table->Active=false;
Element->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TDMSprCustomerMainMenu::OpenTable(__int64 id_account, __int64 id_grp_user, __int64 id_grp, bool all)
{

IdGrpUser=id_grp_user;
IdGrp=id_grp;
AllElement=all;
IdAccount=id_account;

Table->Active=false;
Table->SelectSQL->Clear();
if(all==true)
		{
				AnsiString zapros="	select cust_mainmenu.*,                                                                       \
							program_module.name_program_module,                                                                   \
							program_module.progid_program_module,                                                                 \
							program_module.patch_program_module,                                                                  \
								 program_module.typemod_program_module                                                            \
						from cust_mainmenu                                                                                        \
						left outer join program_module on cust_mainmenu.idmod_cust_mainmenu=program_module.id_program_module      \
						where                                                                                                     \
						 cust_mainmenu.idgrpuser_cust_mainmenu=:PARAM_IDGRP_USER                                                  \
						 and cust_mainmenu.idaccount_cust_mainmenu=:PARAM_IDACCOUNT                                               \
						order by cust_mainmenu.index_cust_mainmenu desc ";


			   Table->SelectSQL->Add(zapros);
			   Table->ParamByName("PARAM_IDACCOUNT")->AsInt64=id_account;
			   Table->ParamByName("PARAM_GRPUSER")->AsInt64=id_grp_user;
		}
else
		{
		if (id_grp==0)
				{
				AnsiString zapros="	select cust_mainmenu.*,                                                                                      \
											program_module.name_program_module,                                                                  \
											program_module.progid_program_module,                                                                \
											program_module.patch_program_module,                                                                 \
												 program_module.typemod_program_module                                                           \
										from cust_mainmenu                                                                                       \
										left outer join program_module on cust_mainmenu.idmod_cust_mainmenu=program_module.id_program_module     \
										where                                                                                                    \
										 cust_mainmenu.idgrpuser_cust_mainmenu=:PARAM_IDGRP_USER                                                \
										 and cust_mainmenu.idaccount_cust_mainmenu=:PARAM_IDACCOUNT                                            \
										 and cust_mainmenu.idgrp_cust_mainmenu is null                                                         \
										order by cust_mainmenu.index_cust_mainmenu desc   ";

			   Table->SelectSQL->Add(zapros);
			   Table->ParamByName("PARAM_IDACCOUNT")->AsInt64=id_account;
			   Table->ParamByName("PARAM_IDGRP_USER")->AsInt64=id_grp_user;


                }
        else
				{
				AnsiString zapros="	select cust_mainmenu.*,                                                                                  \
									program_module.name_program_module,                                                                      \
									program_module.progid_program_module,                                                                    \
									program_module.patch_program_module,                                                                     \
										 program_module.typemod_program_module                                                              \
								from cust_mainmenu                                                                                          \
								left outer join program_module on cust_mainmenu.idmod_cust_mainmenu=program_module.id_program_module         \
								where                                                                                                       \
								 cust_mainmenu.idgrpuser_cust_mainmenu=:PARAM_IDGRP_USER                                                    \
								 and cust_mainmenu.idaccount_cust_mainmenu=:PARAM_IDACCOUNT                                                 \
								 and cust_mainmenu.idgrp_cust_mainmenu=:PARAM_IDGRP                                                         \
								order by cust_mainmenu.index_cust_mainmenu desc   ";
			   Table->SelectSQL->Add(zapros);
			   Table->ParamByName("PARAM_IDGRP")->AsInt64=id_grp;
			   Table->ParamByName("PARAM_IDACCOUNT")->AsInt64=id_account;
			   Table->ParamByName("PARAM_IDGRP_USER")->AsInt64=id_grp_user;
			   }
		}

Table->Open();
}

//---------------------------------------------------------------------------

bool  TDMSprCustomerMainMenu::SaveIsmen()
{
bool result=false;
try
		{
		Table->ApplyUpdates();
		if (IBTrUpdate->Active==true)
			{
			IBTrUpdate->Commit();
			}
		OpenTable(IdAccount,IdGrpUser,IdGrp,AllElement);
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

void  TDMSprCustomerMainMenu::CancelIsmen()
{
try
        {
		Table->CancelUpdates();
		if (IBTrUpdate->Active==true)
			{
			IBTrUpdate->Commit();
			}
		OpenTable(IdAccount,IdGrpUser,IdGrp,AllElement);
        }
        catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
}
//---------------------------------------------------------------------------
bool TDMSprCustomerMainMenu::Table_Delete(void)
{
bool result=true;
try
        {
		Table->Delete();
        }
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//----------------------------------------------------------------------------
bool TDMSprCustomerMainMenu::Table_AppendString(__int64 id_account, __int64 id_grp_user, __int64 id_grp)
{
bool result=false;
IdGrpUser=id_grp_user;
IdGrp=id_grp;
IdAccount=id_account;

try
	{
	Table->Append();
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
//------------------------------------------------------------------------------
bool  TDMSprCustomerMainMenu::NewElement(__int64 id_account, __int64 id_grp_user, __int64 id_grp)
{
bool result=false;
IdGrpUser=id_grp_user;
IdGrp=id_grp;
IdAccount=id_account;

try
	{
	Element->Active=true;
	Element->Append();

	ElementIDACCOUNT_CUST_MAINMENU->AsInteger=id_account;
	ElementIDGRPUSER_CUST_MAINMENU->AsString=id_grp_user;
	if(id_grp!=0)
		{
		ElementIDGRP_CUST_MAINMENU->AsString=id_grp;
		}
	Element->Post();
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
//----------------------------------------------------------------------------
bool TDMSprCustomerMainMenu::OpenElement(__int64 id)
{
bool result=false;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        result=true;
        }
return result;
}
//---------------------------------------------------------------------------
bool TDMSprCustomerMainMenu::DeleteElement(__int64 id)
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

//-----------------------------------------------------------------------------------
bool TDMSprCustomerMainMenu::InsertElement(__int64 id_account, __int64 id_grp_user, __int64 id_grp)
{
bool result=false;
try
        {
		IdGrpUser=id_grp_user;
		IdGrp=id_grp;
		IdAccount=id_account;
        Table->Active=true;
        Table->Insert();
		Table->ApplyUpdates();
		IBTrUpdate->Commit();
		Table->Active=false;
		result=true;
        }
catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				result=false;
				}
return result;
}
//----------------------------------------------------------------------------

void __fastcall TDMSprCustomerMainMenu::TableNewRecord(TDataSet *DataSet)
{
TableIDGRPUSER_CUST_MAINMENU->AsString=IdGrpUser;
TableIDGRP_CUST_MAINMENU->AsString=IdGrp;
TableIDACCOUNT_CUST_MAINMENU->AsString=IdAccount;
}

//---------------------------------------------------------------------------
void TDMSprCustomerMainMenu::ChancheGrp(__int64 id_new_grp)
{
Table->Edit();
TableIDGRP_CUST_MAINMENU->AsString=id_new_grp;
Table->Post();
SaveIsmen();
OpenTable(IdAccount,IdGrpUser,IdGrp,AllElement);
}
//-----------------------------------------------------------------------------
void TDMSprCustomerMainMenu::Element_Edit(void)
{
Element->Edit();
}
//-----------------------------------------------------------------------------
void TDMSprCustomerMainMenu::Element_Post(void)
{
Element->Post();
}
//-----------------------------------------------------------------------------
bool  TDMSprCustomerMainMenu::SaveElement()
{
bool result=false;
__int64 id=glStrToInt64(ElementID_CUST_MAINMENU->AsString);
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
		OpenElement(id);
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
//-----------------------------------------------------------------------------
