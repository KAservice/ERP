//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMGurOperDiscountCard.h"
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
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMGurOperDiscountCard::TDMGurOperDiscountCard(TComponent* Owner)
        : TDataModule(Owner)
{
elSave=false;
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//---------------------------------------------------------------------------
void __fastcall TDMGurOperDiscountCard::DataModuleCreate(TObject *Sender)
{
ExecPriv=true;
InsertPriv=true;
EditPriv=true;
DeletePriv=true;
}
//---------------------------------------------------------------------------
bool TDMGurOperDiscountCard::Init(void)
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
Query->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}

//----------------------------------------------------------------------------
int TDMGurOperDiscountCard::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMGurOperDiscountCard::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------

void TDMGurOperDiscountCard::OpenTable(void)
{

Table->Active=false;
Table->ParamByName("PARAM_NACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_CON")->AsDateTime=PosCon; 
Table->Active=true;


}
//---------------------------------------------------------------------------

int TDMGurOperDiscountCard::OpenElement(__int64 id)  //возвращает количество элементов
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;

if (Res>0) elSave=true;
return Res;
}
//----------------------------------------------------------------------------

void TDMGurOperDiscountCard::NewElement(void)
{
elSave=false;
Element->Active=false;
Element->Open();
Element->Append();
}
//-----------------------------------------------------------------------------
bool TDMGurOperDiscountCard::SaveElement(void)
{
bool result=false;
int id=ElementID_GUROPER_DCARD->AsInt64;
try
        {
		Element->ApplyUpdToBase();
		IBTrUpdate->Commit();
		Element->CommitUpdToCach();
        elSave=true;
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

void TDMGurOperDiscountCard::DeleteElement(__int64 Id)
{
elSave=false;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
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
//----------------------------------------------------------------------------
void __fastcall TDMGurOperDiscountCard::TableCalcFields(TDataSet *DataSet)
{
Table->FieldByName("RECNO")->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

double TDMGurOperDiscountCard::GetSumPokupok(__int64 id_klient, TDateTime pos_nach)
{
double result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add(" select SUM(guroper_dcard.sum_guroper_dcard) ");
Query->SQL->Add(" from  guroper_dcard ");
Query->SQL->Add(" where guroper_dcard.idklient_guroper_dcard=:PARAM_IDKLIENT ");
Query->SQL->Add(" and guroper_dcard.pos_guroper_dcard>:PARAM_POSNACH ");
Query->ParamByName("PARAM_IDKLIENT")->AsInt64=id_klient;
Query->ParamByName("PARAM_POSNACH")->AsDateTime=pos_nach;
Query->ExecQuery();
result=Query->FieldByName("SUM")->AsFloat;
Query->Close();
return result;
}
//----------------------------------------------------------------------------
__int64 TDMGurOperDiscountCard::PoiskPoCoduDoc(__int64 code_doc)
{
__int64 result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add(" select guroper_dcard.id_guroper_dcard from guroper_dcard ");
Query->SQL->Add(" where guroper_dcard.iddoc_guroper_dcard=:PARAM_CODEDOC ");
Query->ParamByName("PARAM_CODEDOC")->AsInt64=code_doc;
Query->ExecQuery();
result=Query->FieldByName("ID_GUROPER_DCARD")->AsInt64;
return result; 
}
//-----------------------------------------------------------------------------






