//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

//---------------------------------------------------------------------------

#include "UHOT_DMReportSvobodNF.h"
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
__fastcall THOT_DMReportSvobodNF::THOT_DMReportSvobodNF(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall THOT_DMReportSvobodNF::DataModuleCreate(TObject *Sender)
{
Report->Active=false;
}
//---------------------------------------------------------------------------
bool THOT_DMReportSvobodNF::Init(void)
{
bool result=false;


Report->Database=DM_Connection->pFIBData;
pFIBTr->DefaultDatabase=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
void __fastcall THOT_DMReportSvobodNF::DataModuleDestroy(TObject *Sender)
{
Report->Active=false;
}
//---------------------------------------------------------------------------
void THOT_DMReportSvobodNF::OpenReport(TDateTime pos_nach, TDateTime pos_con)
{
PosNach=pos_nach;
PosCon=pos_con;
Report->Active=false;
Report->ParamByName("PARAM_POSNACH")->AsDateTime=pos_nach;
Report->ParamByName("PARAM_POSCON")->AsDateTime=pos_con;
Report->Active=true;
}
//----------------------------------------------------------------------------


