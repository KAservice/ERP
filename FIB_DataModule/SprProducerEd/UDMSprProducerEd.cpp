//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprProducerEd.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IObjectBarCode.h"
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
__fastcall TDMSprProducerEd::TDMSprProducerEd(TComponent* Owner)
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
bool TDMSprProducerEd::Init(void)
{
bool result=false;
if (InterfaceMainObject>0)
	{
	//������� ����������
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//������� ��������� COM ������� ��� �������� ����� ��������
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
int TDMSprProducerEd::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprProducerEd::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void TDMSprProducerEd::OpenTable(__int64 id_producer_nom)
{

Table->Active=false;
Table->ParamByName("PARAM_IDPRNOM")->AsInt64=id_producer_nom;
Table->Active=true;

}
//---------------------------------------------------------------------------

int TDMSprProducerEd::OpenElement(__int64 id)  //���������� ���������� ���������
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//----------------------------------------------------------------------------

bool TDMSprProducerEd::NewElement(__int64 id_producer_nom)
{
bool result=false;
Element->Active=false;

	Element->Open();
	Element->Append();
	ElementIDPRNOM_SPRED->AsString=id_producer_nom;
	ElementKF_SPRED->AsFloat=1;
	result=true;

return result;

}
//-----------------------------------------------------------------------------
bool  TDMSprProducerEd::SaveElement(void)
{
bool result=false;
__int64 id=glStrToInt64(ElementID_SPRED->AsString);


try
        {
		Element->ApplyUpdates();
		IBTrUpdate->Commit();

        OpenElement(id);
		result=true;
        }
catch(Exception &exception)
        {
		TextError=exception.Message;
        result=false;
        }

return result;
}
//----------------------------------------------------------------------------

bool TDMSprProducerEd::DeleteElement(__int64 id)
{
bool result=false;
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
				TextError=exception.Message;
				result=false;
				}
		}

return result;
}
//----------------------------------------------------------------------------

void __fastcall TDMSprProducerEd::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

