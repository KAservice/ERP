//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "UDMSprNomFind.h"
#include "IDMQueryUpdate.h"
#include "IDMSprEd.h"
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

__fastcall TDMSprNomFind::TDMSprNomFind(TComponent* Owner)
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
bool TDMSprNomFind::Init(void)
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
Table->Database=DM_Connection->pFIBData;
SpTPrice->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;


SpTPrice->Active=true;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprNomFind::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprNomFind::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
SpTPrice->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
bool TDMSprNomFind::SetTextQuery(UnicodeString text)
{
bool result=false;
Table->Active=false;

try
        {
		Table->SelectSQL->Clear();
		Table->SelectSQL->Add(text);
		Table->Open();
		result=true;
        }
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}


return result;
}
//---------------------------------------------------------------------------
bool TDMSprNomFind::SetIntegerParam(UnicodeString name_param, int value_param)
{
bool result=false;
try
		{
		Table->ParamByName(name_param)->AsInteger=value_param;
		result=true;
        }
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}
//---------------------------------------------------------------------------
bool TDMSprNomFind::SetInt64Param(UnicodeString name_param, __int64 value_param)
{
bool result=false;
try
		{
		Table->ParamByName(name_param)->AsString=value_param;
		result=true;
        }
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}
//---------------------------------------------------------------------------
bool TDMSprNomFind::SetStringParam(UnicodeString name_param, UnicodeString value_param)
{
bool result=false;
try
		{
		Table->ParamByName(name_param)->AsString=value_param;
		result=true;
		}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}
//---------------------------------------------------------------------------
bool TDMSprNomFind::OpenTableResult(void)
{
bool result=false;
try
		{
		Table->Open();
		result=true;
		}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}

//---------------------------------------------------------------------------


