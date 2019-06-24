//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprGrpNomInetCatalog.h"
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
__fastcall TDMSprGrpNomInetCatalog::TDMSprGrpNomInetCatalog(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//--------------------------------------------------------------------------
bool TDMSprGrpNomInetCatalog::Init(void)
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
int TDMSprGrpNomInetCatalog::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprGrpNomInetCatalog::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void  TDMSprGrpNomInetCatalog::OpenTable(__int64 id_inet_catalog)
{
IdInetCatalog=id_inet_catalog;
Table->Active=false;
Table->ParamByName("PARAM_IDINETCATALOG")->AsInt64=id_inet_catalog;
Table->Open();

}

//---------------------------------------------------------------------------

void  TDMSprGrpNomInetCatalog::NewElement(__int64 id_inet_catalog, __int64 id_grp)
{
IdInetCatalog=id_inet_catalog;
Element->Active=false;
Element->Open();
Element->Append();
if (id_inet_catalog!=0)
        {
		ElementIDINETCAT_SNOMINETCAT_GRP->AsString=id_inet_catalog;
        }
if(id_grp!=0)
        {
		ElementIDGRP_SNOMINETCAT_GRP->AsString=id_grp;
        }
Element->Post();
}
//---------------------------------------------------------------------------

int TDMSprGrpNomInetCatalog::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  TDMSprGrpNomInetCatalog::SaveElement()
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
		   //		IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				result=false;
		}
return result;
}
//---------------------------------------------------------------------------
void TDMSprGrpNomInetCatalog::DeleteElement(__int64 id)
{
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
                }
		catch(Exception &exception)
                {
				IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
                }
        }
}
//-----------------------------------------------------------------

void __fastcall TDMSprGrpNomInetCatalog::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;
}
//---------------------------------------------------------------------------


