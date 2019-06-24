//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

//---------------------------------------------------------------------------

#include "UHOT_DMSprPrOsnUslug.h"
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
__fastcall THOT_DMSprPrOsnUslug::THOT_DMSprPrOsnUslug(TComponent* Owner)
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
bool THOT_DMSprPrOsnUslug::Init(void)
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
//---------------------------------------------------------------------------
int THOT_DMSprPrOsnUslug::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall THOT_DMSprPrOsnUslug::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
Query->Close();
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void  THOT_DMSprPrOsnUslug::OpenTable()
{
Table->Active=false;
Table->Open();

}
//---------------------------------------------------------------------------
void  THOT_DMSprPrOsnUslug::UpdateTable()
{
int id=TableID_HOT_SPROSNUSL->AsInt64;
DataSourceTable->Enabled=false;
OpenTable();
TLocateOptions Opt;
Opt<<loCaseInsensitive;
Table->Locate("ID_HOT_SPROSNUSL",IntToStr(id),Opt);
DataSourceTable->Enabled=true;

}
//---------------------------------------------------------------------------

bool  THOT_DMSprPrOsnUslug::NewElement()
{
bool result=false;
try
	{
	Element->Active=false;
	Element->Open();
	Element->Append();
	result=true;
	}
catch(Exception &exception)
	{
	result=false;
	TextError=exception.Message;
	}
return result;
}
//---------------------------------------------------------------------------

int THOT_DMSprPrOsnUslug::OpenElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
Element->Active=true;



int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  THOT_DMSprPrOsnUslug::SaveElement()
{
bool result;
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
return result;
}
//---------------------------------------------------------------------------

void  THOT_DMSprPrOsnUslug::CloseElement()
{

Element->CancelUpdates();

}
//---------------------------------------------------------------------------
bool THOT_DMSprPrOsnUslug::DeleteElement(__int64 Id)
{
bool result=false;
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

//---------------------------------------------------------------------------
void __fastcall THOT_DMSprPrOsnUslug::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

int THOT_DMSprPrOsnUslug::GetIndexElementaPoID(__int64 id)
{   //индекс начинается с 1, если 0 то не найден элемент
int result=0;
int index=0;
Table->First();
while(!Table->Eof)
	{
	if(TableID_HOT_SPROSNUSL->AsInt64==id)
		{
		result=index+1;
		break;
		}
	index++;
	Table->Next();
	}
return result;
}
//----------------------------------------------------------------------------

void THOT_DMSprPrOsnUslug::GetNomBronAndProg(__int64 id_cat,__int64 id_type_pos)
{
IdNomBron=0;
IdNomProg=0;
Query->Close();
Query->SQL->Clear();
AnsiString zapros="select hot_sprosnusl.idnompr_hot_sprosnusl, \
	   hot_sprosnusl.idnombr_hot_sprosnusl                     \
from hot_sprosnusl                                             \
where hot_sprosnusl.idcat_hot_sprosnusl=:PARAM_IDCAT           \
		and hot_sprosnusl.idtpos_hot_sprosnusl=:PARAM_IDTPOS ";

Query->SQL->Add(zapros);
Query->ParamByName("PARAM_IDCAT")->AsInt64=id_cat;
Query->ParamByName("PARAM_IDTPOS")->AsInt64=id_type_pos;
Query->ExecQuery();
IdNomBron=Query->FieldByName("idnombr_hot_sprosnusl")->AsInt64;
IdNomProg=Query->FieldByName("idnompr_hot_sprosnusl")->AsInt64;
Query->Close();

}
//---------------------------------------------------------------------------
