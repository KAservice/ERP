//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprPriceSchedule.h"
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
__fastcall TDMSprPriceSchedule::TDMSprPriceSchedule(TComponent* Owner)
        : TDataModule(Owner)
{
Error=false;
TextError="Ошибок нет!";
IdBasEd=0;
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//---------------------------------------------------------------------------
bool TDMSprPriceSchedule::Init(void)
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
TPrice->Database=DM_Connection->pFIBData;
Query->Database=DM_Connection->pFIBData;
SpisokEd->Database=DM_Connection->pFIBData;


//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;


TPrice->Open();

result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprPriceSchedule::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprPriceSchedule::DataModuleDestroy(TObject *Sender)
{

Table->Active=false;
SpisokEd->Close();
Element->Close();
TPrice->Close();
Query->Close();
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void TDMSprPriceSchedule::OpenTable(__int64 id_nom)
{
IdNom=id_nom;
Table->Active=false;
Table->ParamByName("PARAM_IDNOM")->AsInt64=IdNom;
Table->Active=true;

UpdateSpisokEd(id_nom);
}
//----------------------------------------------------------------------------
bool TDMSprPriceSchedule::SaveIsmen(void)
{
bool result=false;
if (Table->Active==true )
	{
	try
        {
		Table->ApplyUpdates();
		if (IBTrUpdate->Active==true)
			{
			IBTrUpdate->Commit();
			}
		OpenTable(IdNom);
		result=true;
        }
	catch(Exception &exception)
		{
		result=false;
				//IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
		}
	}
return result;
}
//----------------------------------------------------------------------------

void  TDMSprPriceSchedule::NewElement()
{
Element->Active=false;
Element->Open();
Element->Append();
}
//---------------------------------------------------------------------------

int TDMSprPriceSchedule::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool TDMSprPriceSchedule::SaveElement()
{
bool result=false;

__int64 id=ElementID_SPRICE_SCHEDULE->AsInt64;
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
		OpenElement(id);
		result=true;
        }
catch(Exception &exception)
		{
			   //	IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				result=false;
		}
		
return result;
}
//----------------------------------------------------------------------------
void TDMSprPriceSchedule::CancelIsmen(void)
{
Table->CancelUpdates();

}
//---------------------------------------------------------------------------
void TDMSprPriceSchedule::DeleteElement(__int64 id)
{
OpenElement(id);
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

void __fastcall TDMSprPriceSchedule::TableAfterInsert(TDataSet *DataSet)
{
TableIDNOM_SPRICE_SCHEDULE->AsInt64=IdNom;
}
//---------------------------------------------------------------------------

void __fastcall TDMSprPriceSchedule::TableNewRecord(TDataSet *DataSet)
{
TableIDNOM_SPRICE_SCHEDULE->AsInt64=IdNom;
TablePOS_SPRICE_SCHEDULE->AsDateTime=Now();
if (IdBasEd>0)
	{
	TableIDED_SPRICE_SCHEDULE->AsString=IdBasEd;
	}
else
	{//получим базовую единицу
		Query->Close();
		Query->SQL->Clear();
		Query->SQL->Add("select IDBASEDNOM from SNOM ");
		Query->SQL->Add(" where IDNOM=:PARAM_IDNOM ");
		Query->ParamByName("PARAM_IDNOM")->AsInt64=TableIDNOM_SPRICE_SCHEDULE->AsInt64;
		Query->ExecQuery();
		IdBasEd=glStrToInt64(Query->FieldByName("IDBASEDNOM")->AsString);
		Query->Close();
	if (IdBasEd>0)
		{
		TableIDED_SPRICE_SCHEDULE->AsString=IdBasEd;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TDMSprPriceSchedule::ElementNewRecord(TDataSet *DataSet)
{
ElementIDNOM_SPRICE_SCHEDULE->AsInt64=IdNom;
ElementIDTYPE_SPRICE_SCHEDULE->AsInt64=IdTypePrice;
ElementPOS_SPRICE_SCHEDULE->AsDateTime=Now();

if (IdBasEd>0)
	{
	ElementIDED_SPRICE_SCHEDULE->AsString=IdBasEd;
	}
else
	{//получим базовую единицу
		Query->Close();
		Query->SQL->Clear();
		Query->SQL->Add("select IDBASEDNOM from SNOM ");
		Query->SQL->Add(" where IDNOM=:PARAM_IDNOM ");
		Query->ParamByName("PARAM_IDNOM")->AsInt64=ElementIDNOM_SPRICE_SCHEDULE->AsInt64;
		Query->ExecQuery();
		IdBasEd=glStrToInt64(Query->FieldByName("IDBASEDNOM")->AsString);
		Query->Close();
	if (IdBasEd>0)
		{
		ElementIDED_SPRICE_SCHEDULE->AsString=IdBasEd;
		}
	}

}
//---------------------------------------------------------------------------
void TDMSprPriceSchedule::UpdateSpisokEd(__int64 id_nom)
{
SpisokEd->Active=false;
SpisokEd->ParamByName("PARAM_IDNOM")->AsInt64=id_nom;
SpisokEd->Active=true;
}
//----------------------------------------------------------------------------
double TDMSprPriceSchedule::GetValuePrice(__int64 id_nom,
							__int64 id_type_price,
							__int64 id_ed,
							TDateTime pos)
{
double result=0;

Query->Close();
Query->SQL->Clear();
AnsiString zapros="select  first  1                 \
		sprice_schedule.value_sprice_schedule        \
from sprice_schedule                                           \
where sprice_schedule.idnom_sprice_schedule=:PARAM_IDNOM       \
		and sprice_schedule.ided_sprice_schedule=:PARAM_IDED    \
		and sprice_schedule.idtype_sprice_schedule=:PARAM_IDTPRICE   \
		and sprice_schedule.pos_sprice_schedule <= :PARAM_POS    \
		order by sprice_schedule.pos_sprice_schedule desc";

Query->SQL->Add(zapros);
Query->ParamByName("PARAM_IDNOM")->AsInt64=id_nom;
Query->ParamByName("PARAM_IDED")->AsInt64=id_ed;
Query->ParamByName("PARAM_IDTPRICE")->AsInt64=id_type_price;
Query->ParamByName("PARAM_POS")->AsDateTime=pos;
Query->ExecQuery();
result=Query->FieldByName("value_sprice_schedule")->AsFloat;
Query->Close();

return result;
}
//----------------------------------------------------------------------------
