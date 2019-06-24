//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UDMObjectBasePriv.h"
#include "UGlobalFunction.h"
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
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMObjectBasePriv::TDMObjectBasePriv(TComponent* Owner)
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
void __fastcall TDMObjectBasePriv::DataModuleCreate(TObject *Sender)
{
ExecPriv=false;
InsertPriv=false;
EditPriv=false;
DeletePriv=false;

}
//----------------------------------------------------------------------------
bool TDMObjectBasePriv::Init(void)
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
int TDMObjectBasePriv::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMObjectBasePriv::DataModuleDestroy(TObject *Sender)
{

Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TDMObjectBasePriv::OpenTable(int application, __int64 id_grp_user, __int64 id_grp, bool all)
{

IdGrpUser=id_grp_user;
IdGrp=id_grp;
AllElement=all;
NumApplication=application;

Table->Active=false;
Table->SelectSQL->Clear();
if(all==true)
		{
			   UnicodeString zapros=" select object_base_priv.*,                         \
											program_module.name_program_module,          \
											program_module.progid_program_module,        \
											program_module.patch_program_module          \
									from object_base_priv                                \
									left outer join program_module on object_base_priv.guid_object_base_priv=program_module.guid_program_module    \
									where                                                                                                          \
											object_base_priv.idgrpuser_object_base_priv=:PARAM_IDGRP_USER and                                      \
											object_base_priv.application_object_base_priv=:PARAM_APL  ";

			   Table->SelectSQL->Add(zapros);
			   Table->ParamByName("PARAM_IDGRP_USER")->AsString=id_grp_user;
			   Table->ParamByName("PARAM_APL")->AsInteger=application;
		}
else
		{
		if (id_grp==0)
                {
			   UnicodeString zapros=" select object_base_priv.*,                         \
											program_module.name_program_module,          \
											program_module.progid_program_module,        \
											program_module.patch_program_module          \
									from object_base_priv                                \
									left outer join program_module on object_base_priv.guid_object_base_priv=program_module.guid_program_module    \
									where                                                                                                          \
											object_base_priv.idgrpuser_object_base_priv=:PARAM_IDGRP_USER and                                      \
											object_base_priv.idgrp_object_base_priv is null                                                    \
											and object_base_priv.application_object_base_priv=:PARAM_APL  ";

			   Table->SelectSQL->Add(zapros);
			   Table->ParamByName("PARAM_IDGRP_USER")->AsInteger=id_grp_user;
			   Table->ParamByName("PARAM_APL")->AsInteger=application;


                }
        else
				{
			   UnicodeString zapros=" select object_base_priv.*,                         \
											program_module.name_program_module,          \
											program_module.progid_program_module,        \
											program_module.patch_program_module          \
									from object_base_priv                                \
									left outer join program_module on object_base_priv.guid_object_base_priv=program_module.guid_program_module    \
									where                                                                                                          \
											object_base_priv.idgrpuser_object_base_priv=:PARAM_IDGRP_USER and                                      \
											object_base_priv.idgrp_object_base_priv=:PARAM_IDGRP                                                   \
											and object_base_priv.application_object_base_priv=:PARAM_APL  ";
			   Table->SelectSQL->Add(zapros);
			   Table->ParamByName("PARAM_IDGRP_USER")->AsInteger=id_grp_user;
			   Table->ParamByName("PARAM_IDGRP")->AsInt64=id_grp;
			   Table->ParamByName("PARAM_APL")->AsInteger=application;
			   }
		}

Table->Open();
}

//---------------------------------------------------------------------------

bool  TDMObjectBasePriv::SaveIsmen()
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

void  TDMObjectBasePriv::CancelIsmen()
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
bool TDMObjectBasePriv::Table_Delete(void)
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
bool TDMObjectBasePriv::Table_AppendString(int application, __int64 id_grp_user, __int64 id_grp)
{
bool result=false;
IdGrpUser=id_grp_user;
IdGrp=id_grp;
NumApplication=application;
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
bool  TDMObjectBasePriv::NewElement(int application, __int64 id_grp_user, __int64 id_grp)
{
bool result=false;
IdGrpUser=id_grp_user;
IdGrp=id_grp;
NumApplication=application;
try
	{
	Element->Active=true;
	Element->Append();

	ElementIDGRPUSER_OBJECT_BASE_PRIV->AsString=id_grp_user;
	ElementAPPLICATION_OBJECT_BASE_PRIV->AsString=application;
	if(id_grp!=0)
		{
		ElementIDGRP_OBJECT_BASE_PRIV->AsString=id_grp;
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
bool TDMObjectBasePriv::OpenElement(__int64 id)
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
bool TDMObjectBasePriv::DeleteElement(__int64 id)
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
bool TDMObjectBasePriv::InsertElement(int application, __int64 id_grp_user, __int64 id_grp)
{
bool result=false;
try
        {
		IdGrpUser=id_grp_user;
		IdGrp=id_grp;
		NumApplication=application;
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
void __fastcall TDMObjectBasePriv::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMObjectBasePriv::TableNewRecord(TDataSet *DataSet)
{
TableIDGRPUSER_OBJECT_BASE_PRIV->AsString=IdGrpUser;
if (IdGrp>0)
	{
	TableIDGRP_OBJECT_BASE_PRIV->AsString=IdGrp;
	}
TableAPPLICATION_OBJECT_BASE_PRIV->AsString=NumApplication;
}

//---------------------------------------------------------------------------
void TDMObjectBasePriv::ChancheGrp(__int64 id_new_grp)
{
Table->Edit();
TableIDGRP_OBJECT_BASE_PRIV->AsString=id_new_grp;
Table->Post();
SaveIsmen();
OpenTable(NumApplication,IdGrpUser,IdGrp,AllElement);
}
//-----------------------------------------------------------------------------
void TDMObjectBasePriv::Element_Edit(void)
{
Element->Edit();
}
//-----------------------------------------------------------------------------
void TDMObjectBasePriv::Element_Post(void)
{
Element->Post();
}
//-----------------------------------------------------------------------------
bool  TDMObjectBasePriv::SaveElement()
{
bool result=false;
__int64 id=glStrToInt64(ElementID_OBJECT_BASE_PRIV->AsString);
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
bool TDMObjectBasePriv::GetPrivDM(int application, __int64 id_grp_user, int object)
{
bool result=false;
ExecPriv=false;
InsertPriv=false;
EditPriv=false;
DeletePriv=false;

Query->Close();

UnicodeString zapros="select object_base_priv.exec_object_base_priv, \
							object_base_priv.ins_object_base_priv,                       \
							object_base_priv.edit_object_base_priv,                      \
							object_base_priv.del_object_base_priv      \
							from object_base_priv                                                \
						where object_base_priv.idgrpuser_object_base_priv=:PARAM_IDGRP_USER  \
							and object_base_priv.application_object_base_priv=:PARAM_APPL    \
							and object_base_priv.number_object_base_priv=:PARAM_OBJECT";

Query->SQL->Clear();
Query->SQL->Add(zapros);
Query->ParamByName("PARAM_IDGRP_USER")->AsString=id_grp_user;
Query->ParamByName("PARAM_APPL")->AsInteger=application;
Query->ParamByName("PARAM_OBJECT")->AsInteger=object;

try
	{
	Query->ExecQuery();
	if (Query->FieldByName("EXEC_OBJECT_BASE_PRIV")->AsInteger==1)
		{
		ExecPriv=true;
		}

	if (Query->FieldByName("INS_OBJECT_BASE_PRIV")->AsInteger==1)
		{
		InsertPriv=true;
		}

	if (Query->FieldByName("EDIT_OBJECT_BASE_PRIV")->AsInteger==1)
		{
		EditPriv=true;
		}

	if (Query->FieldByName("DEL_OBJECT_BASE_PRIV")->AsInteger==1)
		{
		DeletePriv=true;
		}
	result=true;
	}
catch(Exception &exception)
	{
	TextError=exception.Message;
	result=false;
	}


Query->Close();

return result;
}
//----------------------------------------------------------------------------
bool TDMObjectBasePriv::GetPrivForm(__int64 id_grp_user, int object)
{
bool result=false;
ExecPriv=false;
InsertPriv=false;
EditPriv=false;
DeletePriv=false;

Query->Close();

UnicodeString zapros="select object_base_priv.exec_object_base_priv, \
							object_base_priv.ins_object_base_priv,                       \
							object_base_priv.edit_object_base_priv,                      \
							object_base_priv.del_object_base_priv      \
							from object_base_priv                                                \
						where object_base_priv.idgrpuser_object_base_priv=:PARAM_IDGRP_USER  \
							and object_base_priv.number_object_base_priv=:PARAM_OBJECT";

Query->SQL->Clear();
Query->SQL->Add(zapros);
Query->ParamByName("PARAM_IDGRP_USER")->AsString=id_grp_user;
Query->ParamByName("PARAM_OBJECT")->AsInteger=object;

try
	{
	Query->ExecQuery();
	if (Query->FieldByName("EXEC_OBJECT_BASE_PRIV")->AsInteger==1)
		{
		ExecPriv=true;
		}

	if (Query->FieldByName("INS_OBJECT_BASE_PRIV")->AsInteger==1)
		{
		InsertPriv=true;
		}

	if (Query->FieldByName("EDIT_OBJECT_BASE_PRIV")->AsInteger==1)
		{
		EditPriv=true;
		}

	if (Query->FieldByName("DEL_OBJECT_BASE_PRIV")->AsInteger==1)
		{
		DeletePriv=true;
		}
	result=true;
	}
catch(Exception &exception)
	{
	TextError=exception.Message;
	result=false;
	}

Query->Close();
return result;
}
//-----------------------------------------------------------------------------

