//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

//---------------------------------------------------------------------------

#include "UHOT_DMSprNF.h"
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
__fastcall THOT_DMSprNF::THOT_DMSprNF(TComponent* Owner)
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
bool THOT_DMSprNF::Init(void)
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

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
void __fastcall THOT_DMSprNF::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int THOT_DMSprNF::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------

void  THOT_DMSprNF::OpenTable()
{
Table->Active=false;
Table->Open();

}
//----------------------------------------------------------------------------
void  THOT_DMSprNF::UpdateTable()
{
__int64 id=TableID_HOT_SNF->AsInt64;
DataSourceTable->Enabled=false;
OpenTable();
TLocateOptions Opt;
Opt<<loCaseInsensitive;
Table->Locate("ID_HOT_SNF",IntToStr(id),Opt);
DataSourceTable->Enabled=true;
}
//---------------------------------------------------------------------------

bool  THOT_DMSprNF::NewElement()
{
bool result=false;
try
	{
	Element->Active=false;
	Element->Open();
	Element->Append();
	ElementPOSIN_HOT_SNF->AsDateTime=Now();
	ElementPOSOUT_HOT_SNF->AsDateTime=ElementPOSIN_HOT_SNF->AsDateTime+100000;
	result=true;
	}
catch(Exception &exception)
	{
	result=false;
	TextError=exception.Message;
	}
return result;
}
//---------------------------------------------------------------------------

int THOT_DMSprNF::OpenElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  THOT_DMSprNF::SaveElement()
{
bool result;
try
		{
		Element->ApplyUpdToBase();
		IBTrUpdate->Commit();
		Element->CommitUpdToCach();
		result=true;

        }
catch(Exception &exception)
		{
		IBTrUpdate->Rollback();
		TextError=exception.Message;
		result=false;
		}
return result;
}
//---------------------------------------------------------------------------

void  THOT_DMSprNF::CloseElement()
{

Element->CancelUpdates();

}
//---------------------------------------------------------------------------
bool THOT_DMSprNF::DeleteElement(__int64 Id)
{
bool result=false;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        Element->Delete();
        try
                {
				Element->ApplyUpdToBase();
				IBTrUpdate->Commit();
				Element->CommitUpdToCach();
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

//---------------------------------------------------------------------------
void __fastcall THOT_DMSprNF::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

int THOT_DMSprNF::GetIndexElementaPoID(__int64 id)
{   //индекс начинается с 1, если 0 то не найден элемент
int result=0;
int index=0;
Table->First();
while(!Table->Eof)
	{
	if(TableID_HOT_SNF->AsInt64==id)
		{
		result=index+1;
		break;
		}
	index++;
	Table->Next();
	}
return result;
}
//----------------------------------------------------------------------------
