//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

//---------------------------------------------------------------------------

#include "UHOT_DMTableSostNF.h"
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
__fastcall THOT_DMTableSostNF::THOT_DMTableSostNF(TComponent* Owner)
        : TDataModule(Owner)
{
IdPlat=0;
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//---------------------------------------------------------------------------
bool THOT_DMTableSostNF::Init(void)
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
int THOT_DMTableSostNF::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall THOT_DMTableSostNF::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void __fastcall THOT_DMTableSostNF::Element1CalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;
}
//---------------------------------------------------------------------------
void  THOT_DMTableSostNF::OpenTable()
{
Table->Active=false;
Table->SelectSQL->Clear();
AnsiString zapros="";
zapros=zapros+" select hot_sostnf.*,";
zapros=zapros+"  PLAT.NAMEKLIENT as NAMEPLAT,";
zapros=zapros+"  GUEST.NAMEKLIENT as NAMEGUEST,";
zapros=zapros+"  hot_snf.name_hot_snf,";
zapros=zapros+"  hot_ssostnom.name_hot_ssostnom,";
zapros=zapros+"  hot_stypepos.name_hot_stypepos";
zapros=zapros+"  from hot_sostnf";
zapros=zapros+"  left outer join sklient as PLAT on PLAT.IDKLIENT=hot_sostnf.idplat_hot_sostnf";
zapros=zapros+"  left outer join sklient as GUEST on GUEST.IDKLIENT=hot_sostnf.idguest_hot_sostnf";
zapros=zapros+"  left outer join hot_snf on hot_snf.id_hot_snf=hot_sostnf.idnomer_hot_sostnf";
zapros=zapros+"  left outer join hot_stypepos on hot_stypepos.id_hot_stypepos=hot_sostnf.idtpos_hot_sostnf";
zapros=zapros+"  left outer join hot_ssostnom on hot_ssostnom.id_hot_ssostnom=hot_sostnf.idsost_hot_sostnf";

if (IdPlat!=0)
	{
	zapros=zapros+"  where PLAT.IDKLIENT =:PARAM_IDPLAT";
	}

Table->SelectSQL->Add(zapros);

if (IdPlat!=0)
	{
	Table->ParamByName("PARAM_IDPLAT")->AsInt64=IdPlat;
	}


Table->Open();

}

//---------------------------------------------------------------------------

bool  THOT_DMTableSostNF::NewElement()
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

int THOT_DMTableSostNF::OpenElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  THOT_DMTableSostNF::SaveElement()
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
bool THOT_DMTableSostNF::DeleteElement(__int64 Id)
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
void __fastcall THOT_DMTableSostNF::TableCalcFields(TDataSet *DataSet)
{
Table->FieldByName("RECNO")->AsInteger=Table->RecNo;
}
//---------------------------------------------------------------------------






