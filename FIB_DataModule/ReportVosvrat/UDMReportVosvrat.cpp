//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMReportVosvrat.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMReportVosvrat::TDMReportVosvrat(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMReportVosvrat::DataModuleCreate(TObject *Sender)
{
ReportNal->Active=false;
}
//---------------------------------------------------------------------------
void __fastcall TDMReportVosvrat::DataModuleDestroy(TObject *Sender)
{
ReportNal->Active=false;
}
//---------------------------------------------------------------------------
void TDMReportVosvrat::OpenReportNal(__int64 id_firm, __int64 id_kassa, TDateTime pos_nach, TDateTime pos_con)
{
ReportNal->Active=false;
AnsiString zapros="";
zapros=zapros+" select *";
zapros=zapros+" from drkorozn";
zapros=zapros+" left outer join galldoc on drkorozn.iddoc_drkorozn=galldoc.iddoc";
zapros=zapros+" left outer join SKKM on IDKKM_DRKOROZN=IDKKM";
zapros=zapros+" where galldoc.posdoc between :PARAM_POSNACH and :PARAM_POSCON";
if (id_firm!=0)
	{
	zapros=zapros+" and IDFIRMDOC="+IntToStr(id_firm);
	}

if (id_kassa!=0)
	{
	zapros=zapros+" and IDKKM_DRKOROZN="+IntToStr(id_kassa);
	}
ReportNal->SelectSQL->Clear();
ReportNal->SelectSQL->Add(zapros);
ReportNal->ParamByName("PARAM_POSNACH")->AsDateTime=pos_nach;
ReportNal->ParamByName("PARAM_POSCON")->AsDateTime=pos_con;
ReportNal->Active=true;
}
//----------------------------------------------------------------------------
