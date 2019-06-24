//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

//---------------------------------------------------------------------------

#include "UHOT_DMReportRasmK_S.h"
#include "DateUtils.hpp"
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
__fastcall THOT_DMReportRasmK_S::THOT_DMReportRasmK_S(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall THOT_DMReportRasmK_S::DataModuleCreate(TObject *Sender)
{
Report->Active=false;
}
//---------------------------------------------------------------------------
bool THOT_DMReportRasmK_S::Init(void)
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
void __fastcall THOT_DMReportRasmK_S::DataModuleDestroy(TObject *Sender)
{
Report->Active=false;
}
//---------------------------------------------------------------------------
void THOT_DMReportRasmK_S::OpenReport(TDateTime pos_nach, TDateTime pos_con)
{
PosNach=pos_nach;
PosCon=pos_con;
Report->Active=false;
Report->ParamByName("PARAM_POSNACH")->AsDateTime=pos_nach;
Report->ParamByName("PARAM_POSCON")->AsDateTime=pos_con;
Report->Active=true;
}
//----------------------------------------------------------------------------

void __fastcall THOT_DMReportRasmK_S::ReportCalcFields(TDataSet *DataSet)
{
int kol_mest=ReportKOLM_HOT_SOSTNF->AsInteger;
if (kol_mest==0) kol_mest=1;
int kol_sutok=0;
TDateTime pos_nach,pos_con;

if (ReportPOSNACH_HOT_SOSTNF->AsDateTime<=PosNach &&
			ReportPOSCON_HOT_SOSTNF->AsDateTime>=PosNach)
	{
	//kol_sutok=DaySpan(ReportPOSCON_HOT_SOSTNF->AsDateTime,PosNach);
	pos_nach=PosNach;
	pos_con=ReportPOSCON_HOT_SOSTNF->AsDateTime;
	}

if (ReportPOSNACH_HOT_SOSTNF->AsDateTime>=PosNach &&
			ReportPOSCON_HOT_SOSTNF->AsDateTime<=PosCon)
	{
	//kol_sutok=DaySpan(ReportPOSCON_HOT_SOSTNF->AsDateTime,ReportPOSNACH_HOT_SOSTNF->AsDateTime);
	pos_nach=ReportPOSNACH_HOT_SOSTNF->AsDateTime;
	pos_con=ReportPOSCON_HOT_SOSTNF->AsDateTime;
	}

if (ReportPOSNACH_HOT_SOSTNF->AsDateTime<PosCon &&
			ReportPOSCON_HOT_SOSTNF->AsDateTime>PosCon)
	{
	//kol_sutok=DaySpan(PosCon,ReportPOSNACH_HOT_SOSTNF->AsDateTime);
	pos_nach=ReportPOSNACH_HOT_SOSTNF->AsDateTime;
	pos_con=PosCon;
	}


if (ReportPOSNACH_HOT_SOSTNF->AsDateTime<=PosNach &&
			ReportPOSCON_HOT_SOSTNF->AsDateTime>=PosCon)
	{
	//kol_sutok=DaySpan(PosCon,PosNach);
	pos_nach=PosNach;
	pos_con=PosCon;
	}

//*****************

unsigned short year,month,day,hour,min,sec,msec;
DecodeDateTime(pos_nach,year,month,day,hour,min,sec,msec);

	
TDateTime tek_pos;
int int_rasch_hour=12;


tek_pos=EncodeDateTime(year,month,day,int_rasch_hour,0,0,0);
//	ShowMessage("Начало отсчета:"+DateTimeToStr(tek_pos));

double tek_kol=0;

if (tek_pos+1<=pos_con)
	{ 

	Loop:

		tek_kol++;
		tek_pos++;
		if (tek_pos+1<=pos_con) goto Loop;

	}
//****************

kol_sutok=tek_kol;
if (kol_sutok==0) kol_sutok=1;

ReportKOL_K_S->AsInteger=kol_mest*kol_sutok;
ReportKOLSUTOK->AsInteger=kol_sutok;

if (0<ReportKOL_K_S->AsInteger && ReportKOL_K_S->AsInteger<=3)
	{
	ReportINTERVAL->AsString="1-3 к/сут.";
	}

if (3<ReportKOL_K_S->AsInteger && ReportKOL_K_S->AsInteger<=7)
	{
	ReportINTERVAL->AsString="4-7 к/сут.";
	}

if (7<ReportKOL_K_S->AsInteger && ReportKOL_K_S->AsInteger<=14)
	{
	ReportINTERVAL->AsString="8-14 к/сут.";
	}

if (14<ReportKOL_K_S->AsInteger && ReportKOL_K_S->AsInteger<=28)
	{
	ReportINTERVAL->AsString="15-28 к/сут.";
	}

if (28<ReportKOL_K_S->AsInteger && ReportKOL_K_S->AsInteger<=91)
	{
	ReportINTERVAL->AsString="29-91 к/сут.";
	}

if (91<ReportKOL_K_S->AsInteger)
	{
	ReportINTERVAL->AsString="Больше 91";
	}
}
//---------------------------------------------------------------------------

