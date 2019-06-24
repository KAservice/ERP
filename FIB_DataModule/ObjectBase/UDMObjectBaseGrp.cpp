//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMObjectBaseGrp.h"
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
__fastcall TDMObjectBaseGrp::TDMObjectBaseGrp(TComponent* Owner)
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
bool TDMObjectBaseGrp::Init(void)
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
int TDMObjectBaseGrp::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMObjectBaseGrp::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void  TDMObjectBaseGrp::OpenTable(void)
{

Table->Active=false;
Table->Open();

}

//---------------------------------------------------------------------------
void TDMObjectBaseGrp::Table_First(void)
{
Table->First();
}
//---------------------------------------------------------------------------
void TDMObjectBaseGrp::Table_Next(void)
{
Table->Next();
}
//----------------------------------------------------------------------------
void  TDMObjectBaseGrp::NewElement( __int64 id_grp)
{
IdGrp=id_grp;
Element->Active=false;
Element->Open();

Element->Insert();
if(id_grp!=0)
        {
		ElementIDGRP_OBJECT_BASE_GRP->AsString=id_grp;
		}
Element->Post();
}
//---------------------------------------------------------------------------

int TDMObjectBaseGrp::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------
void TDMObjectBaseGrp::Element_Edit(void)
{
Element->Edit();
}
//-------------------------------------------------------------------------
void TDMObjectBaseGrp::Element_Post(void)
{
Element->Post();
}
//----------------------------------------------------------------------------
bool  TDMObjectBaseGrp::SaveElement()
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
bool TDMObjectBaseGrp::DeleteElement(__int64 id)
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
				result=true;
                }
		catch(Exception &exception)
                {
				IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				result=false;
                }
		}
return result;
}
//-----------------------------------------------------------------

void __fastcall TDMObjectBaseGrp::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;
}
//---------------------------------------------------------------------------


