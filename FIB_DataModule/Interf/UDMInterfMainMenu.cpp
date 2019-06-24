//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UDMInterfMainMenu.h"
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
__fastcall TDMInterfMainMenu::TDMInterfMainMenu(TComponent* Owner)
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
bool TDMInterfMainMenu::Init(void)
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
int TDMInterfMainMenu::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMInterfMainMenu::DataModuleDestroy(TObject *Sender)
{

Table->Active=false;
Element->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TDMInterfMainMenu::OpenTable(int num_application, __int64 id_grp_user, __int64 id_grp, bool all)
{

IdGrpUser=id_grp_user;
IdGrp=id_grp;
AllElement=all;
NumApplication=num_application;

Table->Active=false;
Table->SelectSQL->Clear();
if(all==true)
		{
				AnsiString zapros="	select INTERF_MAINMENU.*,                                                                                          \
											NAME_SGRPUSER,                                                                                             \
											program_module.name_program_module,                                                                        \
											program_module.progid_program_module,                                                                      \
											program_module.patch_program_module,                                                                       \
											program_module.typemod_program_module                                                                        \
									from INTERF_MAINMENU                                                                                               \
									left outer join sgrpuser on ID_SGRPUSER=IDGRPUSER_INTERF_MAINMENU                                                  \
									left outer join program_module on interf_mainmenu.idmod_interf_mainmenu=program_module.id_program_module          \
									where                                                                                                              \																   \
											interf_mainmenu.application_interf_mainmenu=:PARAM_MODUL and        \                                      \
											interf_mainmenu.idgrpuser_interf_mainmenu=:PARAM_GRPUSER   ";


			   Table->SelectSQL->Add(zapros);
			   Table->ParamByName("PARAM_MODUL")->AsInteger=num_application;
			   Table->ParamByName("PARAM_GRPUSER")->AsInt64=id_grp_user;
		}
else
        {
		if (id_grp==0)
				{
				AnsiString zapros="	select INTERF_MAINMENU.*,                                                                                          \
											NAME_SGRPUSER,                                                                                             \
											program_module.name_program_module,                                                                        \
											program_module.progid_program_module,                                                                      \
											program_module.patch_program_module    ,                                                                  \
											program_module.typemod_program_module                                                                    \
									from INTERF_MAINMENU                                                                                               \
									left outer join sgrpuser on ID_SGRPUSER=IDGRPUSER_INTERF_MAINMENU                                                  \
									left outer join program_module on interf_mainmenu.idmod_interf_mainmenu=program_module.id_program_module          \
									where                                                                                                              \
											IDGRP_INTERF_MAINMENU is null   and                                                                      \
											interf_mainmenu.application_interf_mainmenu=:PARAM_MODUL and        \                                      \
											interf_mainmenu.idgrpuser_interf_mainmenu=:PARAM_GRPUSER   ";

			   Table->SelectSQL->Add(zapros);
			   Table->ParamByName("PARAM_MODUL")->AsInteger=num_application;
			   Table->ParamByName("PARAM_GRPUSER")->AsInt64=id_grp_user;


                }
        else
				{
				AnsiString zapros="	select INTERF_MAINMENU.*,                                                                                          \
											NAME_SGRPUSER,                                                                                             \
											program_module.name_program_module,                                                                        \
											program_module.progid_program_module,                                                                      \
											program_module.patch_program_module      ,                                                                \
											program_module.typemod_program_module                                                                  \
									from INTERF_MAINMENU                                                                                               \
									left outer join sgrpuser on ID_SGRPUSER=IDGRPUSER_INTERF_MAINMENU                                                  \
									left outer join program_module on interf_mainmenu.idmod_interf_mainmenu=program_module.id_program_module          \
									where                                                                                                              \
											IDGRP_INTERF_MAINMENU=:PARAM_IDGRP  and                                                                       \
											interf_mainmenu.application_interf_mainmenu=:PARAM_MODUL and        \                                      \
											interf_mainmenu.idgrpuser_interf_mainmenu=:PARAM_GRPUSER   ";
			   Table->SelectSQL->Add(zapros);
			   Table->ParamByName("PARAM_IDGRP")->AsInt64=id_grp;
			   Table->ParamByName("PARAM_MODUL")->AsInteger=num_application;
			   Table->ParamByName("PARAM_GRPUSER")->AsInt64=id_grp_user;
			   }
		}

Table->Open();
}

//---------------------------------------------------------------------------

bool  TDMInterfMainMenu::SaveIsmen()
{
bool result=false;
try
		{
		Table->ApplyUpdates();
		if (IBTrUpdate->Active==true)
			{
			IBTrUpdate->Commit();
			}
		OpenTable(NumApplication,IdGrpUser,IdGrp,AllElement);
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

void  TDMInterfMainMenu::CancelIsmen()
{
try
        {
		Table->CancelUpdates();
		if (IBTrUpdate->Active==true)
			{
			IBTrUpdate->Commit();
			}
		OpenTable(NumApplication,IdGrpUser,IdGrp,AllElement);
        }
        catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
}
//---------------------------------------------------------------------------
bool TDMInterfMainMenu::Table_Delete(void)
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
bool TDMInterfMainMenu::Table_AppendString(int num_application, __int64 id_grp_user, __int64 id_grp)
{
bool result=false;
IdGrpUser=id_grp_user;
IdGrp=id_grp;
NumApplication=num_application;

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
bool  TDMInterfMainMenu::NewElement(int num_application, __int64 id_grp_user, __int64 id_grp)
{
bool result=false;
IdGrpUser=id_grp_user;
IdGrp=id_grp;
NumApplication=num_application;

try
	{
	Element->Active=true;
	Element->Append();

	ElementAPPLICATION_INTERF_MAINMENU->AsInteger=num_application;
	ElementIDGRPUSER_INTERF_MAINMENU->AsString=id_grp_user;
	if(id_grp!=0)
		{
		ElementIDGRP_INTERF_MAINMENU->AsString=id_grp;
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
bool TDMInterfMainMenu::OpenElement(__int64 id)
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
bool TDMInterfMainMenu::DeleteElement(__int64 id)
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
bool TDMInterfMainMenu::InsertElement(int num_application, __int64 id_grp_user, __int64 id_grp)
{
bool result=false;
try
        {
		IdGrpUser=id_grp_user;
		IdGrp=id_grp;
		NumApplication=num_application;
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
void __fastcall TDMInterfMainMenu::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMInterfMainMenu::TableNewRecord(TDataSet *DataSet)
{
TableIDGRPUSER_INTERF_MAINMENU->AsString=IdGrpUser;
TableIDGRP_INTERF_MAINMENU->AsString=IdGrp;
TableAPPLICATION_INTERF_MAINMENU->AsInteger=NumApplication;
}

//---------------------------------------------------------------------------
void TDMInterfMainMenu::ChancheGrp(__int64 id_new_grp)
{
Table->Edit();
TableIDGRP_INTERF_MAINMENU->AsString=id_new_grp;
Table->Post();
SaveIsmen();
OpenTable(NumApplication,IdGrpUser,IdGrp,AllElement);
}
//-----------------------------------------------------------------------------
void TDMInterfMainMenu::Element_Edit(void)
{
Element->Edit();
}
//-----------------------------------------------------------------------------
void TDMInterfMainMenu::Element_Post(void)
{
Element->Post();
}
//-----------------------------------------------------------------------------
bool  TDMInterfMainMenu::SaveElement()
{
bool result=false;
__int64 id=glStrToInt64(ElementID_INTERF_MAINMENU->AsString);
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
