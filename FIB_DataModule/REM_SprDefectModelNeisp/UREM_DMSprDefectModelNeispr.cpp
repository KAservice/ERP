//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UREM_DMSprDefectModelNeispr.h"
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
__fastcall TREM_DMSprDefectModelNeispr::TREM_DMSprDefectModelNeispr(TComponent* Owner)
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
bool TREM_DMSprDefectModelNeispr::Init(void)
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
int TREM_DMSprDefectModelNeispr::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMSprDefectModelNeispr::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;


}
//---------------------------------------------------------------------------

void TREM_DMSprDefectModelNeispr::OpenTable(__int64 id_model_neispr)
{

Table->Active=false;
Table->ParamByName("PARAM_IDMODELNEISPR")->AsString=id_model_neispr;
Table->Active=true;

}
//---------------------------------------------------------------------------

int TREM_DMSprDefectModelNeispr::OpenElement(__int64 id)  //возвращает количество элементов
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsString=id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
return Res;
}
//----------------------------------------------------------------------------

bool TREM_DMSprDefectModelNeispr::NewElement(__int64 id_model_neispr)
{
Element->Active=false;
Element->Open();
Element->Append();
ElementIDNEISMOD_REM_SDEFECT_MODNE->AsString=id_model_neispr;

return true;

}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool  TREM_DMSprDefectModelNeispr::SaveElement(void)
{
bool result=false;
__int64 id=glStrToInt64(ElementID_REM_SDEFECT_MODNE->AsString);
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

bool TREM_DMSprDefectModelNeispr::DeleteElement(__int64 id)
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
				Element->ApplyUpdToBase();
				IBTrUpdate->Commit();
				Element->CommitUpdToCach();
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

//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

void __fastcall TREM_DMSprDefectModelNeispr::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------


