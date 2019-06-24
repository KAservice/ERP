//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UREM_DMZayavkaDv.h"
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
__fastcall TREM_DMZayavkaDv::TREM_DMZayavkaDv(TComponent* Owner)
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

bool TREM_DMZayavkaDv::Init(void)
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
int TREM_DMZayavkaDv::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMZayavkaDv::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//----------------------------------------------------------------------------
void TREM_DMZayavkaDv::OpenTable(__int64 id_z)
{

Table->Active=false;
Table->ParamByName("PARAM_IDZ")->AsString=id_z;
Table->Active=true;

}
//---------------------------------------------------------------------------

int TREM_DMZayavkaDv::OpenElement(__int64 id)  //возвращает количество элементов
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsString=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//----------------------------------------------------------------------------

bool TREM_DMZayavkaDv::NewElement(__int64 id_z)
{
IdZ=id_z;
Element->Active=false;
Element->Open();
Element->Append();
ElementIDZ_REM_Z_DV->AsString=id_z;

return true;

}

//-----------------------------------------------------------------------------
bool  TREM_DMZayavkaDv::SaveElement(void)
{
bool result=false;
__int64 id=glStrToInt64(ElementID_REM_Z_DV->AsString);
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

bool TREM_DMZayavkaDv::DeleteElement(__int64 id)
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

__int64 TREM_DMZayavkaDv::GetIDElement(String gid)
{
__int64 res=0;

pFIBQ->Close();
pFIBQ->SQL->Clear();
		pFIBQ->SQL->Add("select ID_REM_Z_DV from REM_Z_DV where GID_REM_Z_DV=:PARAM_GID");
		pFIBQ->ParamByName("PARAM_GID")->AsString=Trim(gid);
		pFIBQ->ExecQuery();
		if (pFIBQ->RecordCount==1)
			{
			res=glStrToInt64(pFIBQ->FieldByName("ID_REM_Z_DV")->AsString);
			}
		else res=0;

pFIBQ->Close();


return res;
}
//---------------------------------------------------------------------------
UnicodeString TREM_DMZayavkaDv::GetGIDElement(__int64 id)
{
UnicodeString res=0;

if (id==0) return res;

pFIBQ->Close();
pFIBQ->SQL->Clear();
		pFIBQ->SQL->Add("select GID_REM_Z_DV from REM_Z_DV where ID_REM_Z_DV=:PARAM_ID");
		pFIBQ->ParamByName("PARAM_ID")->AsString=id;
		pFIBQ->ExecQuery();
		if (pFIBQ->RecordCount==1)
			{
			res=Trim(pFIBQ->FieldByName("GID_REM_Z_DV")->AsString);
			}
		else res="";
pFIBQ->Close();

return res;
}

//----------------------------------------------------------------------------


void __fastcall TREM_DMZayavkaDv::ElementNewRecord(TDataSet *DataSet)
{

ElementIDZ_REM_Z_DV->AsString=IdZ;
ElementIDBASE_REM_Z_DV->AsString=IdBaseZayavki;
}

//---------------------------------------------------------------------------
bool TREM_DMZayavkaDv::AddRecordDv(TDateTime pos,
						__int64 id_z,
						int oper,
						__int64 id_sost,
						__int64 id_type_remont,
						__int64 id_user,
						__int64 id_tec_sklad,
						double sum,
						TDate date,
						int out
						)
{
bool result=false;

NewElement(id_z);
Element->Edit();
ElementPOS_REM_Z_DV->AsDateTime=pos;
ElementOPER_REM_Z_DV->AsInteger=oper;
if (id_sost==0)
	{

	}
else
	{
	ElementIDSOST_REM_Z_DV->AsString=id_sost;
	}

if (id_type_remont==0)
	{

	}
else
	{
	ElementIDTREMONT_REM_Z_DV->AsString=id_type_remont;
	}
ElementIDUSER_REM_Z_DV->AsString=id_user;

if(id_tec_sklad==0)
	{

	}
else
	{
	ElementIDTECSKL_REM_Z_DV->AsString=id_tec_sklad;
	}

ElementSUM_REM_Z_DV->AsFloat=sum;
ElementSROK_REM_Z_DV->Value=date;
ElementOUT_REM_Z_DV->AsInteger=out;
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
