//---------------------------------------------------------------------------

#ifndef UHOT_DMReportRasmK_SH
#define UHOT_DMReportRasmK_SH
//---------------------------------------------------------------------------
#include "UDM.h"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------


#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>
//---------------------------------------------------------------------------
class THOT_DMReportRasmK_S : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDataSet *Report;
	TpFIBTransaction *pFIBTr;
	TDataSource *DataSourceReport;
	TFIBIntegerField *ReportKOLM_HOT_SOSTNF;
	TFIBDateTimeField *ReportPOSNACH_HOT_SOSTNF;
	TFIBDateTimeField *ReportPOSCON_HOT_SOSTNF;
	TIntegerField *ReportKOL_K_S;
	TIntegerField *ReportKOLSUTOK;
	TStringField *ReportINTERVAL;
	TFIBWideStringField *ReportNAME_HOT_SOBJECT;
	TFIBWideStringField *ReportNAMEKLIENT;
	TFIBWideStringField *ReportNAME_SCOUNTRY;
	TFIBWideStringField *ReportNAME_SVIDKLIENT;
	TFIBWideStringField *ReportNAME_HOT_SCELPR;
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall ReportCalcFields(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


public:		// User declarations
	__fastcall THOT_DMReportRasmK_S(TComponent* Owner);

	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
	bool Init(void);

	void OpenReport( TDateTime pos_nach, TDateTime pos_con);

	TDateTime PosNach;
	TDateTime PosCon;

	};
//---------------------------------------------------------------------------
extern PACKAGE THOT_DMReportRasmK_S *HOT_DMReportRasmK_S;
//---------------------------------------------------------------------------
#endif
