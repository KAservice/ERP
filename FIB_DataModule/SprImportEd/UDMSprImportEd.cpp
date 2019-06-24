//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprImportEd.h"
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
__fastcall TDMSprImportEd::TDMSprImportEd(TComponent* Owner)
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
bool TDMSprImportEd::Init(void)
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
int TDMSprImportEd::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprImportEd::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}

}
//---------------------------------------------------------------------------

void TDMSprImportEd::OpenTable(__int64 id_ed)
{

Table->Active=false;
Table->ParamByName("IDED")->AsInt64=id_ed;
Table->Active=true;

}
//---------------------------------------------------------------------------

int TDMSprImportEd::OpenElement(__int64 id)  //возвращает количество элементов
{
Element->Active=false;
Element->ParamByName("ID")->AsInt64=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//----------------------------------------------------------------------------

bool TDMSprImportEd::NewElement(__int64 id_nom, __int64 id_ed)
{
bool result=false;
Element->Active=false;

Element->Open();
Element->Insert();
ElementIDNOM_SIMPORTED->AsInt64=id_nom;
ElementIDED_SIMPORTED->AsInt64=id_ed;
result=true;

return result; 
}

//-----------------------------------------------------------------------------
bool  TDMSprImportEd::SaveElement(void)
{
bool result=false;
__int64 id=ElementID_SIMPORTED->AsInt64;


try
        {
		Element->ApplyUpdates();
		IBTrUpdate->Commit();

		OpenElement(id);
        result=true;
        }
catch(Exception &exception)
        {
		TextError=exception.Message;
        result=false;
        }

return result;
}
//----------------------------------------------------------------------------

bool TDMSprImportEd::DeleteElement(__int64 id)
{
bool result=false;
Element->Active=false;
Element->ParamByName("ID")->AsInt64=id;
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
				TextError=exception.Message;
				result=false;
				}
		}

return result;
}

//----------------------------------------------------------------------------

void __fastcall TDMSprImportEd::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;
}
//---------------------------------------------------------------------------

