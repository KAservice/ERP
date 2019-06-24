//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprGrpLossFactor.h"
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
__fastcall TDMSprGrpLossFactor::TDMSprGrpLossFactor(TComponent* Owner)
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
bool TDMSprGrpLossFactor::Init(void)
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


DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprGrpLossFactor::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprGrpLossFactor::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
Query->Close();
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
bool  TDMSprGrpLossFactor::OpenTable()
{
bool result=true;
Table->Active=false;
Table->Open();
return result;
}

//---------------------------------------------------------------------------

bool  TDMSprGrpLossFactor::NewElement(__int64 id_grp)
{
bool result=true;
Element->Active=false;
Element->Open();
Element->Append();
if (id_grp!=0)
        {
		ElementIDGRP_SLOSS_FACTOR_GRP->AsString=id_grp;
		Element->Post();
		}

return result;
}
//---------------------------------------------------------------------------

bool TDMSprGrpLossFactor::OpenElement(__int64 id)
{
bool result=true;
Element->Active=false;
Element->ParamByName("ID")->AsInt64=id;
Element->Active=true;



return result;
}
//---------------------------------------------------------------------------

bool  TDMSprGrpLossFactor::SaveElement()
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
bool TDMSprGrpLossFactor::DeleteElement(__int64 id)
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
//-----------------------------------------------------------------
__int64 TDMSprGrpLossFactor::GetIDElement(UnicodeString gid)
{
__int64 res=0;

if (gid!="" || gid!=" " )
		{
		Query->Close();
		Query->SQL->Clear();
		Query->SQL->Add("select ID_SLOSS_FACTOR_GRP from SLOSS_FACTOR_GRP where GID_SLOSS_FACTOR_GRP=:PARAM_GID");
		Query->ParamByName("PARAM_GID")->AsString=Trim(gid);
		Query->ExecQuery();
				if (Query->RecordCount==1)
						{
						res=Query->FieldByName("ID_SLOSS_FACTOR_GRP")->AsInt64;
						}
				else res=0;
			Query->Close();
	}
return res;
}
//-----------------------------------------------------------------
UnicodeString TDMSprGrpLossFactor::GetGIDElement(__int64 id)
{
UnicodeString result="";

Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select GID_SLOSS_FACTOR_GRP  from SLOSS_FACTOR_GRP where ID_SLOSS_FACTOR_GRP=:PARAM_ID");
Query->ParamByName("PARAM_ID")->AsString=id;
Query->ExecQuery();
				if (Query->RecordCount==1)
						{
						result=Query->FieldByName("GID_SLOSS_FACTOR_GRP")->AsString;
						}
				else result="";
Query->Close();

return result;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprGrpLossFactor::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------
__int64 TDMSprGrpLossFactor::FindPoName(UnicodeString name)
{
__int64 result=0;

Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select ID_SLOSS_FACTOR_GRP from SLOSS_FACTOR_GRP where NAME_SLOSS_FACTOR_GRP=:PARAM_NAME");
Query->ParamByName("PARAM_NAME")->AsString=Trim(name);
Query->ExecQuery();
result=glStrToInt64(Query->FieldByName("ID_SLOSS_FACTOR_GRP")->AsString);
Query->Close();

return result;
}
//---------------------------------------------------------------------------

