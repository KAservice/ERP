//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UDMExtModulePriv.h"
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
__fastcall TDMExtModulePriv::TDMExtModulePriv(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
TextError="Ошибок нет!";
}
//---------------------------------------------------------------------------
bool TDMExtModulePriv::Init(void)
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

Query->Database=DM_Connection->pFIBData;
Table->Database=DM_Connection->pFIBData;
SprGrpUser->Database=DM_Connection->pFIBData;

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
int TDMExtModulePriv::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMExtModulePriv::DataModuleDestroy(TObject *Sender)
{

Table->Active=false;
SprGrpUser->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}

}
//---------------------------------------------------------------------------
void TDMExtModulePriv::OpenTable(__int64 id_module)
{
SprGrpUser->Active=true;
IdModule=id_module;
Table->Active=false;
Table->ParamByName("PARAM_IDMODULE")->AsInt64=id_module;
Table->Active=true;

}
//----------------------------------------------------------------------------
void TDMExtModulePriv::SaveIsmen(void)
{
if (Table->Active==true )
	{
	try
        {
		Table->ApplyUpdates();
		if (IBTrUpdate->Active==true)
			{
			IBTrUpdate->Commit();
			}
		OpenTable(IdModule);
		}
	catch(Exception &exception)
		{
				//IBTrUpdate->Rollback();
				TextError=exception.Message;
		}
	}
}

//----------------------------------------------------------------------------
void TDMExtModulePriv::CancelIsmen(void)
{
Table->CancelUpdates();

}
//---------------------------------------------------------------------------

void __fastcall TDMExtModulePriv::TableNewRecord(TDataSet *DataSet)
{
TableIDMODULE_EXT_MODULE_PRIV->AsInt64=IdModule;

}
//---------------------------------------------------------------------------
bool TDMExtModulePriv::CheckPriv(__int64 id_module, __int64 idgrp_user)
{
bool result=false;

Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select EXEC_EXT_MODULE_PRIV from EXT_MODULE_PRIV ");
Query->SQL->Add(" where IDMODULE_EXT_MODULE_PRIV="+IntToStr(id_module));
Query->SQL->Add(" and IDGRPUSER_EXT_MODULE_PRIV="+IntToStr(idgrp_user));

Query->ExecQuery();

if (Query->RecordCount>0)
	{
	if (Query->FieldByName("EXEC_EXT_MODULE_PRIV")->AsInteger==1)
		{
		 result=true;
		} 
	}
	
Query->Close();
return result;
}
//---------------------------------------------------------------------------
void TDMExtModulePriv::DeleteElement(__int64 id)
{


}
//--------------------------------------------------------------------------


