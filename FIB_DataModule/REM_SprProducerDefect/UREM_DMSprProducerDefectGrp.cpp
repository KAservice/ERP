//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_DMSprProducerDefectGrp.h"
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
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_DMSprProducerDefectGrp::TREM_DMSprProducerDefectGrp(TComponent* Owner)
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
bool TREM_DMSprProducerDefectGrp::Init(void)
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
int TREM_DMSprProducerDefectGrp::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMSprProducerDefectGrp::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void  TREM_DMSprProducerDefectGrp::OpenTable(__int64 id_group_element)
{
IdGroupElement=id_group_element;
Table->Active=false;
Table->ParamByName("PARAM_ID_GROUP_ELEMENT")->AsInt64=id_group_element;
Table->Open();

}

//---------------------------------------------------------------------------

bool  TREM_DMSprProducerDefectGrp::NewElement(__int64 id_group_element, __int64 id_grp)
{
bool result=true;
IdGroupElement=id_group_element;
Element->Active=false;
Element->Open();
Element->Append();
if (id_group_element!=0)
        {
		ElementIDPR_REM_SPRDEFECT_GRP->AsString=id_group_element;
        }
if(id_grp!=0)
        {
		ElementIDGRP_REM_SPRDEFECT_GRP->AsString=id_grp;
        }
Element->Post();
return result;
}
//---------------------------------------------------------------------------

int TREM_DMSprProducerDefectGrp::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  TREM_DMSprProducerDefectGrp::SaveElement()
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
		   //		IBTrUpdate->Rollback();
				TextError=exception.Message;
				result=false;
		}
return result;
}
//---------------------------------------------------------------------------
bool TREM_DMSprProducerDefectGrp::DeleteElement(__int64 id)
{
bool result=true;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
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

void __fastcall TREM_DMSprProducerDefectGrp::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;
}
//---------------------------------------------------------------------------


