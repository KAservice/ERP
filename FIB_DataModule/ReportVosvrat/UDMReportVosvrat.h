//---------------------------------------------------------------------------

#ifndef UDMReportVosvratH
#define UDMReportVosvratH
//---------------------------------------------------------------------------
#include "UDM.h"

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
class TDMReportVosvrat : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDataSet *ReportNal;
	TpFIBTransaction *pFIBTr;
	TFIBIntegerField *ReportNalOPERATION_DRKOROZN;
	TFIBIntegerField *ReportNalNCHECK_DRKOROZN;
	TFIBIntegerField *ReportNalNKL_DRKOROZN;
	TFIBStringField *ReportNalMODEL_DRKOROZN;
	TFIBStringField *ReportNalREGNUM_DRKOROZN;
	TFIBStringField *ReportNalSAVNUM_DRKOROZN;
	TFIBDateTimeField *ReportNalPOSDOC;
	TFIBIntegerField *ReportNalNUMDOC;
	TFIBBCDField *ReportNalSUMDOC;
	TDataSource *DataSourceNal;
	TFIBStringField *ReportNalNAMEKKM;
	TFIBBCDField *ReportNalIDKKM;
	TFIBBCDField *ReportNalIDKKM_DRKOROZN;
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDMReportVosvrat(TComponent* Owner);

	void OpenReportNal(__int64 id_firm, __int64 id_kassa, TDateTime pos_nach, TDateTime pos_con);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMReportVosvrat *DMReportVosvrat;
//---------------------------------------------------------------------------
#endif
