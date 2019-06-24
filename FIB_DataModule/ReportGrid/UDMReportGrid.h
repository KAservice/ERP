//---------------------------------------------------------------------------

#ifndef UDMReportGridH
#define UDMReportGridH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"

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
class TDMReportGrid : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDataSet *Report;
	TpFIBTransaction *Tr;
	TDataSource *DataSourceReport;
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDMReportGrid(TComponent* Owner);

		IDMFibConnection * DM_Connection;
		bool Init(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		void SetTextQuery(AnsiString zapros);
		void OpenReport(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMReportGrid *DMReportGrid;
//---------------------------------------------------------------------------
#endif
