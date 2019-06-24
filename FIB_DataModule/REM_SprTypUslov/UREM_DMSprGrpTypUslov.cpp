//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UREM_DMSprGrpTypUslov.h"
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
__fastcall TREM_DMSprGrpTypUslov::TREM_DMSprGrpTypUslov(TComponent* Owner)
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
bool TREM_DMSprGrpTypUslov::Init(void)
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
int TREM_DMSprGrpTypUslov::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMSprGrpTypUslov::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void  TREM_DMSprGrpTypUslov::OpenTable()
{
Table->Active=false;
Table->Open();

}

//---------------------------------------------------------------------------

void  TREM_DMSprGrpTypUslov::NewElement(__int64 id_grp)
{
Element->Active=false;
Element->Open();
Element->Append();
if (id_grp!=0)
        {
		ElementIDGRP_REM_STYPUSLOV_GRP->AsString=id_grp;
        Element->Post();
        }
}
//---------------------------------------------------------------------------

int TREM_DMSprGrpTypUslov::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsString=id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  TREM_DMSprGrpTypUslov::SaveElement()
{
bool result=false;
__int64 id=glStrToInt64(ElementID_REM_STYPUSLOV_GRP->AsString);
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
//---------------------------------------------------------------------------
void TREM_DMSprGrpTypUslov::DeleteElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsString=id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        Element->Delete();
        try
                {
				Element->ApplyUpdToBase();
				IBTrUpdate->Commit();
				Element->CommitUpdToCach();
				}
        catch(Exception &exception)
                {
				IBTrUpdate->Rollback();
				TextError=exception.Message;
                }
        }
}
//-----------------------------------------------------------------
int TREM_DMSprGrpTypUslov::GetIDElement(UnicodeString gid)
{
int res=0;

if (gid!="" || gid!=" " )
		{
			pFIBQ->Close();
			pFIBQ->SQL->Clear();
				pFIBQ->SQL->Add("select rem_stypuslov_grp.id_rem_stypuslov_grp from rem_stypuslov_grp where rem_stypuslov_grp.gid_rem_stypuslov_grp=:PARAM_GID");
				pFIBQ->ParamByName("PARAM_GID")->AsString=Trim(gid);
				pFIBQ->ExecQuery();
				if (pFIBQ->RecordCount==1)
						{
						res=pFIBQ->FieldByName("id_rem_stypuslov_grp")->AsInteger;
						}
				else res=0;
			pFIBQ->Close();
	}
return res;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMSprGrpTypUslov::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------
__int64 TREM_DMSprGrpTypUslov::FindPoName(UnicodeString name)
{
__int64 result=0;

pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select rem_stypuslov_grp.id_rem_stypuslov_grp from rem_stypuslov_grp where rem_stypuslov_grp.name_rem_stypuslov_grp=:PARAM_NAME");
pFIBQ->ParamByName("PARAM_NAME")->AsString=Trim(name);
pFIBQ->ExecQuery();
result=glStrToInt64(pFIBQ->FieldByName("id_rem_stypuslov_grp")->AsString);
pFIBQ->Close();

return result;
}
//---------------------------------------------------------------------------

