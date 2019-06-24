//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMGurPlat.h"
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
__fastcall TDMGurPlat::TDMGurPlat(TComponent* Owner)
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

void __fastcall TDMGurPlat::DataModuleCreate(TObject *Sender)
{
IdPlat=0;
NoOnlyOut=false;
CodeTel="";
}
//---------------------------------------------------------------------------
bool TDMGurPlat::Init(void)
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
IBQ->Database=DM_Connection->pFIBData;
pFIBQ->Database=DM_Connection->pFIBData;
GurPlat->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMGurPlat::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMGurPlat::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
IBQ->Active=false;
GurPlat->Active=false;
pFIBQ->Close();
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void TDMGurPlat::OpenTable()
{


AnsiString zapros="select  GURNALPLAT.*, NAME_USER, NAMEKLIENT,  \
		  scodetel.name_codetel,                                 \
		  scodetel.codoper_codetel " ;
zapros=zapros+" from GURNALPLAT";
zapros=zapros+" left outer join SUSER on  IDUSER_GURNALPLAT= ID_USER";
zapros=zapros+" left outer join SKLIENT on IDKLIENT_GURNALPLAT=IDKLIENT";
zapros=zapros+" left outer join scodetel on GURNALPLAT.idcodetel_gurnalplat=scodetel.id_codetel";
zapros=zapros+" where POS_GURNALPLAT between  :PARAM_DATE_NACH and :PARAM_DATE_CON ";
if (NoOnlyOut==true)
        {
        zapros=zapros+" and (OUT_GURNALPLAT=0 or OUT_GURNALPLAT IS NULL)";
        }

if (CodeTel!="")
        {
        zapros=zapros+" and CODE_GURNALPLAT='"+CodeTel+"'";
        }

zapros=zapros+" order by POS_GURNALPLAT";


Table->Active=false;
Table->SelectSQL->Clear();
Table->SelectSQL->Add(zapros);
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=PosCon; 
Table->Active=true;

}
//---------------------------------------------------------------------------
void TDMGurPlat::UpdateTable(void)
{
IdPlat=glStrToInt64(TableID_GURNALPLAT->AsString);
DataSourceTable->Enabled=false;

OpenTable();
TLocateOptions Opt;
Opt<<loCaseInsensitive;
Table->Locate("ID_GURNALPLAT",IntToStr(IdPlat),Opt);

DataSourceTable->Enabled=true;
}
//----------------------------------------------------------------------------


void  TDMGurPlat::NewElement(void)
{
Element->Active=false;
Element->Open();
Element->Insert();
ElementPOS_GURNALPLAT->AsDateTime=Now();
}
//---------------------------------------------------------------------------

int TDMGurPlat::OpenElement(__int64 id)
{
IdPlat=id;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

void  TDMGurPlat::SaveElement()
{

try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();

        }
		catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				TextError=exception.Message;
				}
}
//---------------------------------------------------------------------------
void TDMGurPlat::DeleteElement(__int64 id)
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
				TextError=exception.Message;
				}
        }
}
//--------------------------------------------------------------------
void TDMGurPlat::DeleteAllElement(bool NoDeleteEndRecord)
{
GurPlat->Active=true;

GurPlat->Last();
__int64 id_record_end=glStrToInt64(GurPlatID_GURNALPLAT->AsString);
GurPlat->First();
while (!GurPlat->Eof)
        {
        if (NoDeleteEndRecord==true)
                {
				if (glStrToInt64(GurPlatID_GURNALPLAT->AsString)!=id_record_end)
                        {
						DeleteElement(glStrToInt64(GurPlatID_GURNALPLAT->AsString));
                        }
                }
        else
                {
				DeleteElement(glStrToInt64(GurPlatID_GURNALPLAT->AsString));
				}
		GurPlat->Next();
        }
GurPlat->Active=false;
}
//--------------------------------------------------------------------
bool TDMGurPlat::CheckPlat(AnsiString cod,
                       AnsiString number,
                       double sum,
					   int number_kv,
					   __int64 id_spr_code_tel)
{
bool result=false;
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select max(ID_GURNALPLAT) AS M from GURNALPLAT");
pFIBQ->ExecQuery();
__int64 ID=pFIBQ->FieldByName("M")->AsInt64;
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select *  from GURNALPLAT where ID_GURNALPLAT="+IntToStr(ID));
pFIBQ->ExecQuery();

if (pFIBQ->FieldByName("CODE_GURNALPLAT")->AsString==cod
		 && pFIBQ->FieldByName("NUMTEL_GURNALPLAT")->AsString==number
		 && pFIBQ->FieldByName("SUM_GURNALPLAT")->AsFloat==sum
		 && glStrToInt64(pFIBQ->FieldByName("IDCODETEL_GURNALPLAT")->AsString)==id_spr_code_tel)
        {
        result=true;
        }
pFIBQ->ExecQuery();
return result;
}
//-----------------------------------------------------------------
bool TDMGurPlat::AddPlat(AnsiString cod,
                       AnsiString number,
                       double sum,
                       int number_kv,
                       AnsiString code_operator,
                       double procent_commission,
                       double sum_klient,
					   __int64 id_klient,
					   __int64 id_spr_code_tel)
{
bool result=false;
Element->Active=true;
Element->Append();
ElementPOS_GURNALPLAT->AsDateTime=Now();
ElementCODE_GURNALPLAT->AsString=cod;
ElementNUMTEL_GURNALPLAT->AsString=number;
ElementSUM_GURNALPLAT->AsFloat=sum;
ElementNUMKV_GURNALPLAT->AsInteger=number_kv;
ElementCODOPER_GURNALPLAT->AsString=code_operator;
ElementPROCENT_COMMISSION_GURNALPLAT->AsFloat=procent_commission;
ElementSUMKL_GURNALPLAT->AsFloat=sum_klient;
ElementIDUSER_GURNALPLAT->AsString=DM_Connection->UserInfoID_USER->AsString;
if (id_spr_code_tel!=0)ElementIDCODETEL_GURNALPLAT->AsString=id_spr_code_tel;
if (id_klient!=0) ElementIDKLIENT_GURNALPLAT->AsString=id_klient;
Element->Post();
SaveElement();
Element->Active=false;
result=true;

return result;
}
//------------------------------------------------------------------
int TDMGurPlat::GetNumberKv(AnsiString cod)
{
int result=0;;
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select max(NUMKV_GURNALPLAT) AS M from GURNALPLAT ");
pFIBQ->ExecQuery();
result=pFIBQ->FieldByName("M")->AsInteger;
pFIBQ->Close();
return result;

}
//------------------------------------------------------------------
