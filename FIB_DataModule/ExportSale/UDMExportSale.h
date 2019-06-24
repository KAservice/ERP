//---------------------------------------------------------------------------

#ifndef UDMExportSaleH
#define UDMExportSaleH
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
class TDMExportSale : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBTransaction *pFIBTr;
	TpFIBDataSet *Report;
	TFIBIntegerField *ReportCODENOM;
	TFIBStringField *ReportARTNOM;
	TFIBStringField *ReportNAMENOM;
	TFIBStringField *ReportNAMEED;
	TFIBIntegerField *ReportCODE_SED;
	TFIBStringField *ReportSHED;
	TFIBBCDField *ReportKFED;
	TFIBFloatField *ReportKOL_SALE;
	TFIBBCDField *ReportSUM_SALE;
	TDataSource *DataSourceReport;
	TFIBSmallIntField *ReportOPERCHK;
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDMExportSale(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMExportSale *DMExportSale;
//---------------------------------------------------------------------------
#endif
