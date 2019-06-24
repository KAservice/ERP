//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop


#include "UDMInterfToolBar.h"
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
__fastcall TDMInterfToolBar::TDMInterfToolBar(TComponent* Owner)
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
bool TDMInterfToolBar::Init(void)
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
int TDMInterfToolBar::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMInterfToolBar::DataModuleDestroy(TObject *Sender)
{

Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TDMInterfToolBar::OpenTable(int num_application, __int64 id_grp_user)
{
IdGrpUser=id_grp_user;
NumApplication=num_application;

Table->Active=false;

Table->ParamByName("PARAM_APPLICATION")->AsInteger=num_application;
Table->ParamByName("PARAM_IDGRP_USER")->AsInt64=id_grp_user;


Table->Open();
}

//---------------------------------------------------------------------------

bool  TDMInterfToolBar::SaveIsmen()
{
bool result=false;
try
		{
		Table->ApplyUpdates();
		if (IBTrUpdate->Active==true)
			{
			IBTrUpdate->Commit();
			}
		OpenTable(NumApplication,IdGrpUser);
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

void  TDMInterfToolBar::CancelIsmen()
{
try
        {
		Table->CancelUpdates();
		if (IBTrUpdate->Active==true)
			{
			IBTrUpdate->Commit();
			}
		OpenTable(NumApplication,IdGrpUser);
        }
        catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
}
//---------------------------------------------------------------------------
bool TDMInterfToolBar::Table_Delete(void)
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
bool TDMInterfToolBar::Table_AppendString(int num_application, __int64 id_grp_user)
{
bool result=false;
IdGrpUser=id_grp_user;
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
bool  TDMInterfToolBar::NewElement(int num_application, __int64 id_grp_user)
{
bool result=false;
IdGrpUser=id_grp_user;
NumApplication=num_application;

try
	{
	Element->Active=true;
	Element->Append();

	ElementAPPLICATION_INTERF_TOOLBAR->AsInteger=num_application;
	ElementIDGRPUSER_INTERF_TOOLBAR->AsString=id_grp_user;
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
bool TDMInterfToolBar::OpenElement(__int64 id)
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
bool TDMInterfToolBar::DeleteElement(__int64 id)
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
bool TDMInterfToolBar::InsertElement(int num_application, __int64 id_grp_user)
{
bool result=false;
try
		{
		IdGrpUser=id_grp_user;
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
void __fastcall TDMInterfToolBar::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMInterfToolBar::TableNewRecord(TDataSet *DataSet)
{
TableIDGRPUSER_INTERF_TOOLBAR->AsString=IdGrpUser;
TableAPPLICATION_INTERF_TOOLBAR->AsInteger=NumApplication;
TableIMAGEINDEX_INTERF_TOOLBAR->AsInteger=-1;
}
//-----------------------------------------------------------------------------
void TDMInterfToolBar::Element_Edit(void)
{
Element->Edit();
}
//-----------------------------------------------------------------------------
void TDMInterfToolBar::Element_Post(void)
{
Element->Post();
}
//-----------------------------------------------------------------------------
bool  TDMInterfToolBar::SaveElement()
{
bool result=false;
__int64 id=glStrToInt64(ElementID_INTERF_TOOLBAR->AsString);
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

