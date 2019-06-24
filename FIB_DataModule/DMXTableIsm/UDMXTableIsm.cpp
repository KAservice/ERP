//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UDMXTableIsm.h"
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
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMXTableIsm::TDMXTableIsm(TComponent* Owner)
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
bool TDMXTableIsm::Init(void)
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
int TDMXTableIsm::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMXTableIsm::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void  TDMXTableIsm::OpenTable(__int64 id_max)
{

Table->Active=false;
Table->ParamByName("PARAM_IDMAX")->AsInt64=id_max;
Table->Open();

}

//---------------------------------------------------------------------------

void  TDMXTableIsm::NewElement(void)
{
Element->Active=false;
Element->Open();
Element->Insert();

}
//---------------------------------------------------------------------------

int TDMXTableIsm::OpenElement(__int64 id)
{
Id=id;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

void  TDMXTableIsm::SaveElement()
{
Id=ElementID_XTISM->AsInt64;
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
        OpenElement(Id);
        }
        catch(Exception &exception)
				{
				//IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
}
//---------------------------------------------------------------------------
void TDMXTableIsm::DeleteElement(__int64 id)
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
//---------------------------------------------------------------------------

__int64 TDMXTableIsm::GetMaxID(void)
{
__int64 result=0;
TpFIBQuery * query=new TpFIBQuery(0);
query->Database=DM_Connection->pFIBData;
query->Transaction=IBTr;
query->SQL->Add("select max(ID_XTISM)AS MAXID from XTISM");
if (IBTr->Active==false) IBTr->StartTransaction();
query->ExecQuery();
result=query->FieldByName("MAXID")->AsInt64;
delete query;
return result;
}
//-----------------------------------------------------------------------------
void __fastcall TDMXTableIsm::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------


