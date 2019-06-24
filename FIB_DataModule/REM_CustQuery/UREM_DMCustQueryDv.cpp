//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UREM_DMCustQueryDv.h"
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
__fastcall TREM_DMCustQueryDv::TREM_DMCustQueryDv(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
Prosmotr=false;
}
//---------------------------------------------------------------------------

bool TREM_DMCustQueryDv::Init(void)
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
int TREM_DMCustQueryDv::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMCustQueryDv::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//----------------------------------------------------------------------------
void TREM_DMCustQueryDv::OpenTable(__int64 id_cqt)
{

Table->Active=false;
Table->ParamByName("PARAM_IDCQT")->AsString=id_cqt;
Table->Active=true;

}
//---------------------------------------------------------------------------

int TREM_DMCustQueryDv::OpenElement(__int64 id)  //возвращает количество элементов
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsString=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//----------------------------------------------------------------------------

bool TREM_DMCustQueryDv::NewElement(__int64 id_cqt)
{
IdCustQueryT=id_cqt;
Element->Active=false;
Element->Open();
Element->Append();
ElementIDCQT_REM_CQUERYT_DV->AsString=id_cqt;

return true;

}

//-----------------------------------------------------------------------------
bool  TREM_DMCustQueryDv::SaveElement(void)
{
bool result=false;
__int64 id=glStrToInt64(ElementID_REM_CQUERYT_DV->AsString);
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

bool TREM_DMCustQueryDv::DeleteElement(__int64 id)
{
bool result=false;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsString=id;
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

__int64 TREM_DMCustQueryDv::GetIDElement(String gid)
{
__int64 res=0;




return res;
}
//---------------------------------------------------------------------------
UnicodeString TREM_DMCustQueryDv::GetGIDElement(__int64 id)
{
UnicodeString res=0;



return res;
}

//----------------------------------------------------------------------------


void __fastcall TREM_DMCustQueryDv::ElementNewRecord(TDataSet *DataSet)
{

ElementIDCQT_REM_CQUERYT_DV->AsString=IdCustQueryT;
}

//---------------------------------------------------------------------------
bool TREM_DMCustQueryDv::AddRecordDv(TDateTime pos,
						__int64 id_cqt,
						__int64 id_sost,
						__int64 id_user,
						int act,
						int run
						)
{
bool result=false;

NewElement(id_cqt);
Element->Edit();
ElementPOS_REM_CQUERYT_DV->AsDateTime=pos;
ElementIDSOST_REM_CQUERYT_DV->AsString=id_sost;
ElementIDUSER_REM_CQUERYT_DV->AsString=id_user;
ElementACT_REM_CQUERY_DV->AsInteger=act;
ElementRUN_REM_CQUERY_DV->AsInteger=run;
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
