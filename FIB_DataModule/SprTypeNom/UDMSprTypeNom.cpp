//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprTypeNom.h"
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
__fastcall TDMSprTypeNom::TDMSprTypeNom(TComponent* Owner)
        : TDataModule(Owner)
{
TextError="������ ���!";
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//---------------------------------------------------------------------------
bool TDMSprTypeNom::Init(void)
{
bool result=false;

if (InterfaceMainObject>0)
	{
	//������� ����������
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//������� ��������� COM ������� ��� �������� ����� ��������
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


//����������
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//-----------------------------------------------------------------------------
int TDMSprTypeNom::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprTypeNom::DataModuleDestroy(TObject *Sender)
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

bool  TDMSprTypeNom::OpenTable(void)
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

bool  TDMSprTypeNom::NewElement()
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

bool TDMSprTypeNom::OpenElement(__int64 id)
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

bool  TDMSprTypeNom::SaveElement(void)
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

void  TDMSprTypeNom::CloseElement(void)
{

        Element->CancelUpdates();
		IBTr->Rollback();
}
//---------------------------------------------------------------------------
bool TDMSprTypeNom::DeleteElement(__int64 id)
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
__int64 TDMSprTypeNom::GetIdElementPoName(UnicodeString name)
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
__int64 TDMSprTypeNom::GetIdElementPoGid(UnicodeString gid)
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
UnicodeString TDMSprTypeNom::GetGidElementPoId(__int64 id)
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
int TDMSprTypeNom::GetIndexInTablePoId(__int64 id_element)
{
int result=0;
Table->First();
while (!Table->Eof)
        {
        result=result+1;
		if (id_element == glStrToInt64(TableID_STNOM->AsString))
                {
                return result;
                }
        Table->Next();
        }

return 0;
}
//---------------------------------------------------------------------------

