//---------------------------------------------------------------------------

#ifndef UDMReportSaleH
#define UDMReportSaleH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
//---------------------------------------------------------------------------
class TDMReportSale : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDataSet *IBQ;
	TpFIBTransaction *pFIBTr;
	TFIBBCDField *IBQSUMREAL;
	TFIBBCDField *IBQSUMKOL;
	TFIBBCDField *IBQIDFIRM_RGREAL_DV;
	TFIBBCDField *IBQIDSKLAD_RGREAL_DV;
	TFIBBCDField *IBQIDGN;
	TFIBBCDField *IBQIDNOM;
	TFIBWideStringField *IBQNAMEFIRM;
	TFIBWideStringField *IBQNAMESKLAD;
	TFIBWideStringField *IBQNAMEGN;
	TFIBWideStringField *IBQNAMENOM;
	TFIBWideStringField *IBQNAMEED;
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDMReportSale(TComponent* Owner);

		IDMFibConnection * DM_Connection;
		bool Init(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

	void OpenReport(TDateTime pos_nach, TDateTime pos_con,
											__int64 id_firm, __int64 id_sklad);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMReportSale *DMReportSale;
//---------------------------------------------------------------------------
#endif
