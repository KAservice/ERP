//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UREM_DMSprKKTDv.h"
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
__fastcall TREM_DMSprKKTDv::TREM_DMSprKKTDv(TComponent* Owner)
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
bool TREM_DMSprKKTDv::Init(void)
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
int TREM_DMSprKKTDv::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMSprKKTDv::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------

void TREM_DMSprKKTDv::OpenTable(__int64 id_owner)
{

Table->Active=false;
Table->ParamByName("PARAM_IDOWNER")->AsString=id_owner;
Table->Active=true;

}
//---------------------------------------------------------------------------

int TREM_DMSprKKTDv::OpenElement(__int64 id)  //возвращает количество элементов
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsString=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//----------------------------------------------------------------------------

bool TREM_DMSprKKTDv::NewElement(__int64 id_owner)
{
IdOwner=id_owner;
Element->Active=false;
Element->Open();
Element->Append();
ElementIDKKT_REM_SKKT_DV->AsString=id_owner;

return true;

}

//-----------------------------------------------------------------------------
bool  TREM_DMSprKKTDv::SaveElement(void)
{
bool result=false;
__int64 id=glStrToInt64(ElementID_REM_SKKT_DV->AsString);
try
        {
		Element->ApplyUpdToBase();
		IBTrUpdate->Commit();
		Element->CommitUpdToCach();
		OpenElement(id);
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
//----------------------------------------------------------------------------

bool TREM_DMSprKKTDv::DeleteElement(__int64 Id)
{
bool result=false;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsString=Id;
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


void __fastcall TREM_DMSprKKTDv::ElementNewRecord(TDataSet *DataSet)
{

ElementIDKKT_REM_SKKT_DV->AsString=IdOwner;
}

//---------------------------------------------------------------------------
bool TREM_DMSprKKTDv::AddRecordDv(TDateTime pos,             //
						__int64 id_owner,           //
						__int64 id_klient,          //
						UnicodeString mesto_ust,       //
						UnicodeString reg_num,         //
						UnicodeString svk_gr,          //
						UnicodeString svk_so,          //
						UnicodeString num_contract,    //
						TDate date_contract,
						double sum_contract,
						UnicodeString eklz_ser_num,
						UnicodeString eklz_reg_num,
						TDate eklz_act,
						__int64 id_user
						)
{
bool result=false;

NewElement(id_owner);
Element->Edit();

ElementPOS_REM_SKKT_DV->AsDateTime=pos;
ElementIDKLIENT_REM_SKKT_DV->AsString=id_klient;
ElementMESTOUST_REM_SKKT_DV->AsString=mesto_ust;
ElementREGNUM_REM_SKKT_DV->AsString=reg_num;
ElementCBKGR_REM_SKKT_DV->AsString=svk_gr;
ElementCBKCO_REM_SKKT_DV->AsString=svk_so;
ElementNUMCONTRACT_REM_SKKT_DV->AsString=num_contract;
ElementDATECONTRACT_REM_SKKT_DV->AsDateTime=date_contract;
ElementSUMCONTRACT_REM_SKKT_DV->AsFloat=sum_contract;
ElementEKLZ_SERNUM_REM_SKKT_DV->AsString=eklz_ser_num;
ElementEKLZ_REGNUM_REM_SKKT_DV->AsString=eklz_reg_num;
ElementEKLZ_ACT_REM_SKKT_DV->AsDateTime=eklz_act;
ElementIDUSER_REM_SKKT_DV->AsString=id_user;

Element->Post();
if (SaveElement()==true)
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
