//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprStrObject.h"
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
__fastcall TDMSprStrObject::TDMSprStrObject(TComponent* Owner)
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
bool TDMSprStrObject::Init(void)
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
Code->Database=DM_Connection->pFIBData;

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprStrObject::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprStrObject::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void  TDMSprStrObject::OpenTable()
{
Table->Active=false;
Table->Open();

}

//---------------------------------------------------------------------------

void  TDMSprStrObject::NewElement(__int64 IdGrp)
{
Element->Active=false;
Code->Active=false;
Code->Active=true;
Element->Open();
Element->Insert();
if (IdGrp!=0)
        {
		ElementIDGRP_STROB->AsInt64=IdGrp;
        }
ElementCODE_STROB->AsInteger=CodeMAXCODE->AsInteger+1;
Element->Post();
}
//---------------------------------------------------------------------------

int TDMSprStrObject::OpenElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("ID")->AsInt64=Id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool   TDMSprStrObject::SaveElement()
{
bool result=false;
try
        {
		Id=ElementID_STROB->AsInt64;
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
		OpenElement(Id);
		result=true;
        }
        catch(Exception &exception)
				{
			   //	IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				result=false;
				}
return result;
}
//---------------------------------------------------------------------------
void TDMSprStrObject::DeleteElement(__int64 Id)
{
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
}
//------------------------------------------------------------------------
__int64 TDMSprStrObject::FindPoCodu(int code)
{
__int64 result=0;
TpFIBQuery * query=new TpFIBQuery(0);
try {
		query->Database=DM_Connection->pFIBData;
		query->Transaction=IBTr;
		query->SQL->Add("select ID_STROB from SSTROB where CODE_STROB=:PARAM_CODE");
		query->ParamByName("PARAM_CODE")->AsInteger=code;
		if (IBTr->Active==false) IBTr->StartTransaction();
		query->ExecQuery();
		result=query->RecordCount;
		if (result>0)
			{
			OpenElement(query->FieldByName("ID_STROB")->AsInt64);
			}
	}
__finally
	{
	delete query;
	}
return result;
}
//---------------------------------------------------------------------------


