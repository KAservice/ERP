//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UREM_DMSprGrpTypDefect.h"
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
__fastcall TREM_DMSprGrpTypDefect::TREM_DMSprGrpTypDefect(TComponent* Owner)
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
bool TREM_DMSprGrpTypDefect::Init(void)
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
int TREM_DMSprGrpTypDefect::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMSprGrpTypDefect::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void  TREM_DMSprGrpTypDefect::OpenTable()
{
Table->Active=false;
Table->Open();

}

//---------------------------------------------------------------------------

void  TREM_DMSprGrpTypDefect::NewElement(__int64 id_grp)
{
Element->Active=false;
Element->Open();
Element->Append();
if (id_grp!=0)
        {
		ElementIDGRP_REM_STYPDEFECT_GRP->AsString=id_grp;
        Element->Post();
        }
}
//---------------------------------------------------------------------------

int TREM_DMSprGrpTypDefect::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsString=id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  TREM_DMSprGrpTypDefect::SaveElement()
{
bool result=false;
__int64 id=glStrToInt64(ElementID_REM_STYPDEFECT_GRP->AsString);
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
void TREM_DMSprGrpTypDefect::DeleteElement(__int64 id)
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

//---------------------------------------------------------------------------
void __fastcall TREM_DMSprGrpTypDefect::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------
__int64 TREM_DMSprGrpTypDefect::FindPoName(UnicodeString name)
{
__int64 result=0;

pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select rem_stypdefect_grp.id_rem_stypdefect_grp from rem_stypdefect_grp where rem_stypdefect_grp.name_rem_stypdefect_grp=:PARAM_NAME");
pFIBQ->ParamByName("PARAM_NAME")->AsString=Trim(name);
pFIBQ->ExecQuery();
result=glStrToInt64(pFIBQ->FieldByName("id_rem_stypdefect_grp")->AsString);
pFIBQ->Close();

return result;
}
//---------------------------------------------------------------------------

