//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UART_DMSprNaborInfBlockSostavGrp.h"
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
__fastcall TART_DMSprNaborInfBlockSostavGrp::TART_DMSprNaborInfBlockSostavGrp(TComponent* Owner)
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
bool TART_DMSprNaborInfBlockSostavGrp::Init(void)
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
int TART_DMSprNaborInfBlockSostavGrp::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TART_DMSprNaborInfBlockSostavGrp::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
bool  TART_DMSprNaborInfBlockSostavGrp::OpenTable(__int64 id_group_element)
{
bool result=false;
IdGroupElement=id_group_element;

try
		{
        Table->Active=false;
		Table->ParamByName("PARAM_ID_GROUP_ELEMENT")->AsInt64=id_group_element;
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

bool  TART_DMSprNaborInfBlockSostavGrp::NewElement(__int64 id_group_element, __int64 id_grp)
{
bool result=false;

IdGroupElement=id_group_element;
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

bool TART_DMSprNaborInfBlockSostavGrp::OpenElement(__int64 id)
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

bool  TART_DMSprNaborInfBlockSostavGrp::SaveElement()
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
bool TART_DMSprNaborInfBlockSostavGrp::DeleteElement(__int64 id)
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



void __fastcall TART_DMSprNaborInfBlockSostavGrp::ElementNewRecord(TDataSet *DataSet)
{
ElementIDNABOR_ART_N_IB_S_GRP->AsString=IdGroupElement;
if(IdGrp !=0)
	{
	ElementIDGRP_ART_N_IB_S_GRP->AsString=IdGrp;
	}
}
//---------------------------------------------------------------------------

