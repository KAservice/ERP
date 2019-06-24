//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop


//---------------------------------------------------------------------------
#include "UDMSprFirm.h"
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
__fastcall TDMSprFirm::TDMSprFirm(TComponent* Owner)
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
void __fastcall TDMSprFirm::DataModuleCreate(TObject *Sender)
{
Error=false;

ExecPriv=true;
InsertPriv=true;
EditPriv=true;
DeletePriv=true;

}
//----------------------------------------------------------------------------
bool TDMSprFirm::Init(void)
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

result=true;

return result;
}
//----------------------------------------------------------------------------
int TDMSprFirm::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TDMSprFirm::GetPriv(void)
{
DM_Connection->GetPrivDM(GCPRIV_DM_SprFirm);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprFirm::DataModuleDestroy(TObject *Sender)
{

Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------

bool  TDMSprFirm::OpenTable()
{
bool result=false;
if (ExecPriv==false)
	{
	TextError="Ошибка: Справочник Фирмы! Недостаточно прав доступа для выполнения операции!";
    return result;
	}
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

bool  TDMSprFirm::NewElement()
{
bool result=false;
if (InsertPriv==false)
	{
	TextError="Ошибка: Справочник Фирмы! Недостаточно прав доступа для выполнения операции!";
    return result;
	}
try
	{
	Element->Active=false;
	Element->Open();
	Element->Insert();
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

int TDMSprFirm::OpenElement(__int64 Id)
{
int result=0;

if (ExecPriv==false)
	{
	TextError="Ошибка: Справочник Фирмы! Недостаточно прав доступа для выполнения операции!";
	return result;
	}
try
	{
	Element->Active=false;
	Element->ParamByName("ID")->AsInt64=Id;
	Element->Active=true;

	result=Element->RecordCount;
	}
catch(Exception &exception)
	{
	TextError=exception.Message;
	result=0;
	}
return result;
}
//---------------------------------------------------------------------------

bool  TDMSprFirm::SaveElement()
{
bool result=false;
if (EditPriv==false)
	{
	TextError="Ошибка: Справочник Фирмы! Недостаточно прав доступа для выполнения операции!";
	return result;
	}


__int64 id=ElementIDFIRM->AsInt64;
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
		OpenElement(id);
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
bool TDMSprFirm::DeleteElement(__int64 Id)
{
bool result=false;
if (DeletePriv==false)
	{
	TextError="Ошибка: Справочник Фирмы! Недостаточно прав доступа для выполнения операции!";
	return result;
	}

Element->Active=false;
Element->ParamByName("ID")->AsInt64=Id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        Element->Delete();
        try
                {
                Element->ApplyUpdates();
				IBTrUpdate->Commit();
                }
		catch(Exception &exception)
                {
				IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
		}

return result;
}


//---------------------------------------------------------------------------
UnicodeString TDMSprFirm::GetGIDElement(__int64 id)
{
UnicodeString res=0;
		if (id!=0 )
                {
				pFIBQ->Close();
				pFIBQ->SQL->Clear();
					pFIBQ->SQL->Add("select GID_SFIRM from SFIRM where IDFIRM=:PARAM_ID");
					pFIBQ->ParamByName("PARAM_ID")->AsInt64=id;
					pFIBQ->ExecQuery();
					if (pFIBQ->RecordCount==1)
						{
						res=Trim(pFIBQ->FieldByName("GID_SFIRM")->AsString);
						}
					else res="";
				pFIBQ->Close();
				} 
return res;
}
//---------------------------------------------------------------------------
__int64 TDMSprFirm::GetIDElement(AnsiString gid)
{
__int64 res=0;
		if (gid!="" )
                {
				pFIBQ->Close();
				pFIBQ->SQL->Clear();
				pFIBQ->SQL->Add("select IDFIRM from SFIRM where GID_SFIRM=:PARAM_GID");
				pFIBQ->ParamByName("PARAM_GID")->AsString=gid;
				pFIBQ->ExecQuery();
					if (pFIBQ->RecordCount==1)
						{
						res=glStrToInt64(Trim(pFIBQ->FieldByName("GID_SFIRM")->AsString));
						}
					else res=0;
				pFIBQ->Close();
				} 
return res;
}
//---------------------------------------------------------------------------


void __fastcall TDMSprFirm::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------
int TDMSprFirm::GetIndexElementaPoID(__int64 id)
{    //индекс начинается с 1, если 0 то не найден элемент
int result=0;
int index=0;
Table->First();
while(!Table->Eof)
	{
	if(TableIDFIRM->AsInt64==id)
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


