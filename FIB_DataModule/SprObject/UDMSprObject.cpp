//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprObject.h"
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
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMSprObject::TDMSprObject(TComponent* Owner)
        : TDataModule(Owner)
{
TextError="Ошибок нет!";
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//---------------------------------------------------------------------------
bool TDMSprObject::Init(void)
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
pFIBQ->Database=DM_Connection->pFIBData;


//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//-----------------------------------------------------------------------------
int TDMSprObject::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprObject::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

bool  TDMSprObject::OpenTable(void)
{

bool result=false;
	try
		{
		Table->Active=false;
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

bool  TDMSprObject::NewElement()
{
bool result=false;
	try
		{
		Element->Active=false;
		Element->Open();
		Element->Append();
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

bool TDMSprObject::OpenElement(__int64 id)
{
bool result=false;
	try
		{
		Element->Active=false;
		Element->ParamByName("PARAM_ID")->AsInt64=id;
		Element->Active=true;
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

bool  TDMSprObject::SaveElement(void)
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
				TextError=exception.Message;
				result=false;
				}
return result;
}
//---------------------------------------------------------------------------

void  TDMSprObject::CloseElement(void)
{

        Element->CancelUpdates();
		IBTr->Rollback();
}
//---------------------------------------------------------------------------
bool TDMSprObject::DeleteElement(__int64 id)
{
bool result=false;
try
	{
	Element->Active=false;
	Element->ParamByName("PARAM_ID")->AsInt64=id;
	Element->Active=true;
	if (Element->RecordCount==1)
		{
		Element->Delete();
		Element->ApplyUpdates();
		IBTrUpdate->Commit();
		result=true;
		}
	}
catch(Exception &exception)
	{
	IBTrUpdate->Rollback();
	TextError=exception.Message;
	result=false;
	}
return result;
}
//-----------------------------------------------------------------------------
__int64 TDMSprObject::GetIdElementPoName(UnicodeString name)
{
int result=0;
//TLocateOptions Opt;
//Opt<<loCaseInsensitive;
//if(Table->Locate("NAME_TPRICE",name,Opt)==true)
//		{
//		result=TableID_TPRICE->AsInt64;
//		}

return result;
}
//-----------------------------------------------------------------------------
__int64 TDMSprObject::GetIdElementPoGid(UnicodeString gid)
{
__int64 res=0;
//pFIBQ->Close();
//		if (gid!="" || gid!=" " )
//				{
//				pFIBQ->SQL->Clear();
//				pFIBQ->SQL->Add("select ID_TPRICE from STPRICE where GID_STPRICE=:PARAM_GID");
//				pFIBQ->ParamByName("PARAM_GID")->AsString=Trim(gid);
//				pFIBQ->ExecQuery();
//				if (pFIBQ->RecordCount==1)
//						{
//						res=pFIBQ->FieldByName("ID_TPRICE")->AsInt64;
//                        }
//				else res=0;
//				}
//pFIBQ->Close();

return res;
}
//-----------------------------------------------------------------------------
UnicodeString TDMSprObject::GetGidElementPoId(__int64 id)
{
UnicodeString result="";
//pFIBQ->Close();
//
//				pFIBQ->SQL->Clear();
//				pFIBQ->SQL->Add("select GID_STPRICE from STPRICE where ID_TPRICE=:PARAM_ID");
//				pFIBQ->ParamByName("PARAM_ID")->AsString=id;
//				pFIBQ->ExecQuery();
//				if (pFIBQ->RecordCount==1)
//						{
//						res=pFIBQ->FieldByName("GID_STPRICE")->AsString;
//						}
//				else res="";
//
//pFIBQ->Close();

return result;
}
//----------------------------------------------------------------------------
int TDMSprObject::GetIndexInTablePoId(__int64 id_element)
{
int result=0;
Table->First();
while (!Table->Eof)
        {
        result=result+1;
		if (id_element == glStrToInt64(TableID_SOBJECT->AsString))
                {
                return result;
                }
        Table->Next();
        }

return 0;
}
//---------------------------------------------------------------------------

