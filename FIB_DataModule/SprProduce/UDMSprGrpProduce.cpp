//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprGrpProduce.h"
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
__fastcall TDMSprGrpProduce::TDMSprGrpProduce(TComponent* Owner)
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
bool TDMSprGrpProduce::Init(void)
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
int TDMSprGrpProduce::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprGrpProduce::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
bool  TDMSprGrpProduce::OpenTable()
{
bool result=true;
Table->Active=false;
Table->Open();
return result;
}

//---------------------------------------------------------------------------

bool  TDMSprGrpProduce::NewElement(__int64 id_grp)
{
bool result=true;
Element->Active=false;
Element->Open();
Element->Append();
if (id_grp!=0)
        {
		ElementIDGRP_SPRODUCE_GRP->AsString=id_grp;
		Element->Post();
		}

return result;
}
//---------------------------------------------------------------------------

bool TDMSprGrpProduce::OpenElement(__int64 id)
{
bool result=true;
Element->Active=false;
Element->ParamByName("ID")->AsInt64=id;
Element->Active=true;



return result;
}
//---------------------------------------------------------------------------

bool  TDMSprGrpProduce::SaveElement()
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
bool TDMSprGrpProduce::DeleteElement(__int64 id)
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
__int64 TDMSprGrpProduce::GetIDElement(UnicodeString gid)
{
__int64 res=0;

if (gid!="" || gid!=" " )
		{
			pFIBQ->Close();
			pFIBQ->SQL->Clear();
				pFIBQ->SQL->Add("select ID_SPRODUCE_GRP from SPRODUCE_GRP where GID_SPRODUCE_GRP=:PARAM_GID");
				pFIBQ->ParamByName("PARAM_GID")->AsString=Trim(gid);
				pFIBQ->ExecQuery();
				if (pFIBQ->RecordCount==1)
						{
						res=pFIBQ->FieldByName("ID_SPRODUCE_GRP")->AsInt64;
						}
				else res=0;
			pFIBQ->Close();
	}
return res;
}
//-----------------------------------------------------------------
UnicodeString TDMSprGrpProduce::GetGIDElement(__int64 id)
{
UnicodeString result="";

pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select GID_SPRODUCE_GRP  from SPRODUCE_GRP where ID_SPRODUCE_GRP=:PARAM_ID");
pFIBQ->ParamByName("PARAM_ID")->AsString=id;
pFIBQ->ExecQuery();
				if (pFIBQ->RecordCount==1)
						{
						result=pFIBQ->FieldByName("GID_SPRODUCE_GRP")->AsString;
						}
				else result="";
pFIBQ->Close();

return result;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprGrpProduce::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------
__int64 TDMSprGrpProduce::FindPoName(UnicodeString name)
{
__int64 result=0;

pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select ID_PRODUCE_GRP from SPRODUCE_GRP where NAME_SPRODUCE_GRP=:PARAM_NAME");
pFIBQ->ParamByName("PARAM_NAME")->AsString=Trim(name);
pFIBQ->ExecQuery();
result=glStrToInt64(pFIBQ->FieldByName("ID_SPRODUCE_GRP")->AsString);
pFIBQ->Close();

return result;
}
//---------------------------------------------------------------------------

