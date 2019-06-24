//---------------------------------------------------------------------------

#ifndef UHOT_DMReportSvobodNFH
#define UHOT_DMReportSvobodNFH
//---------------------------------------------------------------------------
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
class THOT_DMReportSvobodNF : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDataSet *Report;
	TpFIBTransaction *pFIBTr;
	TDataSource *DataSourceReport;
	TFIBIntegerField *ReportOUT_KOL_MEST_ALL;
	TFIBIntegerField *ReportOUT_KOL_MEST_ZAN;
	TFIBIntegerField *ReportOUT_KOL_MEST_SVOB;
	TFIBBCDField *ReportOUT_ID_NF;
	TFIBWideStringField *ReportOUT_NAME_OBJECT;
	TFIBWideStringField *ReportOUT_NAME_CAT;
	TFIBWideStringField *ReportOUT_NAME_NOM;
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall THOT_DMReportSvobodNF(TComponent* Owner);

	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
	bool Init(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

	void OpenReport( TDateTime pos_nach, TDateTime pos_con);

	TDateTime PosNach;
	TDateTime PosCon;

	};
//---------------------------------------------------------------------------
extern PACKAGE THOT_DMReportSvobodNF *HOT_DMReportSvobodNF;
//---------------------------------------------------------------------------
#endif
