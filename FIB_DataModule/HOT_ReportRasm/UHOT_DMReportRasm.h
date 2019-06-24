//---------------------------------------------------------------------------

#ifndef UHOT_DMReportRasmH
#define UHOT_DMReportRasmH
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
class THOT_DMReportRasm : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDataSet *Report;
	TpFIBTransaction *pFIBTr;
	TDataSource *DataSourceReport;
	TFIBIntegerField *ReportKOLM_HOT_SOSTNF;
	TFIBDateTimeField *ReportPOSNACH_HOT_SOSTNF;
	TFIBDateTimeField *ReportPOSCON_HOT_SOSTNF;
	TFIBWideStringField *ReportNAME_HOT_SOBJECT;
	TFIBWideStringField *ReportNAME_HOT_SCATNOM;
	TFIBWideStringField *ReportNAME_HOT_SSOSTNOM;
	TFIBWideStringField *ReportNAME_HOT_SNF;
	TFIBWideStringField *ReportNAMEKLIENT;
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;



public:		// User declarations
	__fastcall THOT_DMReportRasm(TComponent* Owner);

	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
	bool Init(void);


	void OpenReport( TDateTime pos_nach, TDateTime pos_con);

	TDateTime PosNach;
	TDateTime PosCon;

	};
//---------------------------------------------------------------------------
extern PACKAGE THOT_DMReportRasm *HOT_DMReportRasm;
//---------------------------------------------------------------------------
#endif
