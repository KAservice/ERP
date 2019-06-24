//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UHLP_DMSprNaborInfBlockGrp.h"
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
__fastcall THLP_DMSprNaborInfBlockGrp::THLP_DMSprNaborInfBlockGrp(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//--------------------------------------------------------------------------
bool THLP_DMSprNaborInfBlockGrp::Init(void)
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


DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int THLP_DMSprNaborInfBlockGrp::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall THLP_DMSprNaborInfBlockGrp::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
bool  THLP_DMSprNaborInfBlockGrp::OpenTable(void)
{
bool result=false;

try
		{
		Table->Active=false;
		Table->Open();
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

bool  THLP_DMSprNaborInfBlockGrp::NewElement( __int64 id_grp)
{
bool result=false;

IdGrp=id_grp;

try
		{
		Element->Active=true;
		Element->Append();


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

bool THLP_DMSprNaborInfBlockGrp::OpenElement(__int64 id)
{
bool result=false;

        try
                {
				Element->Active=false;
				Element->ParamByName("PARAM_ID")->AsInt64=id;
				Element->Active=true;
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

bool  THLP_DMSprNaborInfBlockGrp::SaveElement()
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
bool THLP_DMSprNaborInfBlockGrp::DeleteElement(__int64 id)
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



void __fastcall THLP_DMSprNaborInfBlockGrp::ElementNewRecord(TDataSet *DataSet)
{

if(IdGrp !=0)
	{
	ElementIDGRP_HLP_N_IB_GRP->AsString=IdGrp;
	}

GUID guid;
CoCreateGuid(&guid);
ElementGUID_HLP_N_IB_GRP->AsString=GUIDToString(guid);
}
//---------------------------------------------------------------------------

