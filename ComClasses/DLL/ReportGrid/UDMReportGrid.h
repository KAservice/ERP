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
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
	__fastcall TDMReportGrid(TComponent* Owner);

		IDMFibConnection * DM_Connection;


		//IMainInterface

		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);

		void SetTextQuery(AnsiString zapros);
		void OpenReport(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMReportGrid *DMReportGrid;
//---------------------------------------------------------------------------
#endif
