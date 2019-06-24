//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprGrpVesNom.h"
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
__fastcall TDMSprGrpVesNom::TDMSprGrpVesNom(TComponent* Owner)
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
bool TDMSprGrpVesNom::Init(void)
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
int TDMSprGrpVesNom::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprGrpVesNom::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void  TDMSprGrpVesNom::OpenTable(__int64 id_scale)
{
IdScale=id_scale;
Table->Active=false;
Table->ParamByName("PARAM_IDSCALE")->AsInt64=id_scale;
Table->Open();

}

//---------------------------------------------------------------------------

void  TDMSprGrpVesNom::NewElement(__int64 id_scale, __int64 id_grp)
{
IdScale=id_scale;
Element->Active=false;
Element->Open();
Element->Insert();
if (id_scale!=0)
        {
		ElementIDSCALE_SGRPVESNOM->AsInt64=id_scale;
        }
if(id_grp!=0)
        {
		ElementIDGRP_SGRPVESNOM->AsInt64=id_grp;
        }
Element->Post();
}
//---------------------------------------------------------------------------

int TDMSprGrpVesNom::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  TDMSprGrpVesNom::SaveElement()
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
				Error=true;
				TextError=exception.Message;
				result=false;
		}
return result;
}
//---------------------------------------------------------------------------
void TDMSprGrpVesNom::DeleteElement(__int64 id)
{
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
                }
		catch(Exception &exception)
                {
				IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
                }
        }
}
//-----------------------------------------------------------------

void __fastcall TDMSprGrpVesNom::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;
}
//---------------------------------------------------------------------------


