//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMReportSale.h"

#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMReportSale::TDMReportSale(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
bool TDMReportSale::Init(void)
{
bool result=false;

pFIBTr->DefaultDatabase=DM_Connection->pFIBData;

IBQ->Database=DM_Connection->pFIBData;


DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
void __fastcall TDMReportSale::DataModuleDestroy(TObject *Sender)
{
IBQ->Active=false;
}
//---------------------------------------------------------------------------
void TDMReportSale::OpenReport(TDateTime pos_nach, TDateTime pos_con,
											__int64 id_firm, __int64 id_sklad)
{
IBQ->Active=false;
IBQ->ParamByName("PARAM_POSNACH")->AsDateTime=pos_nach;
IBQ->ParamByName("PARAM_POSCON")->AsDateTime=pos_con;
IBQ->ParamByName("PARAM_IDFIRM")->AsInt64=id_firm;
IBQ->ParamByName("PARAM_IDSKLAD")->AsInt64=id_sklad;
IBQ->Active=true;
}
//-------------------------------------------------------------------------