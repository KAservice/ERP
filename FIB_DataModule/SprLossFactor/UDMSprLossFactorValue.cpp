//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprLossFactorValue.h"
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
__fastcall TDMSprLossFactorValue::TDMSprLossFactorValue(TComponent* Owner)
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
bool TDMSprLossFactorValue::Init(void)
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
Query->Database=DM_Connection->pFIBData;
FactorList->Database=DM_Connection->pFIBData;

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_SprPrice);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprLossFactorValue::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprLossFactorValue::DataModuleDestroy(TObject *Sender)
{

Table->Active=false;
Element->Close();
Query->Close();
FactorList->Close();
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
bool TDMSprLossFactorValue::OpenTable(__int64 id_loss_factor)
{
bool result=true;
IdLossFactor=id_loss_factor;
UpdateSpisokFactors();

Table->Active=false;
Table->ParamByName("PARAM_IDLOSS_FACTOR")->AsInt64=id_loss_factor;
Table->Active=true;

return result;
}
//----------------------------------------------------------------------------
bool TDMSprLossFactorValue::SaveIsmen(void)
{
bool result=false;
if (Table->Active==true )
	{
	try
        {
		Table->ApplyUpdates();
		if (IBTrUpdate->Active==true)
			{
			IBTrUpdate->Commit();
			}
		OpenTable(IdLossFactor);
		result=true;
        }
	catch(Exception &exception)
		{
		result=false;
		TextError=exception.Message;
		}
	}
return result;
}
//----------------------------------------------------------------------------

bool  TDMSprLossFactorValue::NewElement(void)
{
bool result=true;
Element->Active=false;
Element->Open();
Element->Append();
return result;
}
//---------------------------------------------------------------------------

bool TDMSprLossFactorValue::OpenElement(__int64 id)
{
bool result=true;

Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;


if (Element->RecordCount>0)
	{
	result=true;
	}
else
	{
	result=false;
	}
return result;
}
//---------------------------------------------------------------------------

bool TDMSprLossFactorValue::SaveElement()
{
bool result=false;

__int64 id=glStrToInt64(ElementID_SLOSS_FACTOR_VAL->AsString);
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
void TDMSprLossFactorValue::CancelIsmen(void)
{
Table->CancelUpdates();

}
//---------------------------------------------------------------------------
bool TDMSprLossFactorValue::DeleteElement(__int64 id)
{
bool result=false;
OpenElement(id);
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
				TextError=exception.Message;
				result=false;
				}
		}
return result;
}
//---------------------------------------------------------------------------
__int64 TDMSprLossFactorValue::FindElement(__int64 id_factor, __int64 id_loss_factor)
{
__int64 result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select ID_SLOSS_FACTOR_VAL from SLOSS_FACTOR_VAL ");
Query->SQL->Add(" where IDFACTOR_SLOSS_FACTOR_VAL=:PARAM_IDFACTOR and IDLOSS_FSCTOR_SFACTOR_VAL=:PARAM_IDLOSS_FACTOR ");
Query->ParamByName("PARAM_IDFACTOR")->AsInt64=id_factor;
Query->ParamByName("PARAM_IDLOSS_FACTOR")->AsInt64=id_loss_factor;
Query->ExecQuery();
result=Query->FieldByName("ID_SLOSS_FACTOR_VAL")->AsInt64;

Query->Close();
return result;
}
//---------------------------------------------------------------------------

void __fastcall TDMSprLossFactorValue::TableAfterInsert(TDataSet *DataSet)
{
TableIDLOSS_FACTOR_SLOSS_FACTOR_VAL->AsString=IdLossFactor;
UpdateSpisokFactors();
}
//---------------------------------------------------------------------------
void __fastcall TDMSprLossFactorValue::TableNewRecord(TDataSet *DataSet)
{
TableIDFACTOR_SLOSS_FACTOR_VAL->AsString=IdFactor;
}
//---------------------------------------------------------------------------

void __fastcall TDMSprLossFactorValue::ElementNewRecord(TDataSet *DataSet)
{
ElementIDLOSS_FACTOR_SLOSS_FACTOR_VAL->AsString=IdLossFactor;
ElementIDFACTOR_SLOSS_FACTOR_VAL->AsString=IdFactor;
}
//---------------------------------------------------------------------------
bool TDMSprLossFactorValue::UpdateSpisokFactors(void)
{
bool result=true;
FactorList->Active=false;
FactorList->Active=true;
return result;
}
//----------------------------------------------------------------------------






