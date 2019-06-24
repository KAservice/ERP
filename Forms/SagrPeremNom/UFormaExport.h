//---------------------------------------------------------------------------

#ifndef UFormaExportH
#define UFormaExportH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ADODB.hpp>
#include "UDMGurDocCheckKKM.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <ActnList.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TFormaExport : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel3;
        TPanel *Panel4;
        TPanel *Panel5;
        TDataSource *DataSource2;
        TDateTimePicker *DateCon;
        TLabel *Label2;
        TPanel *Panel6;
        TDateTimePicker *DateNach;
        TLabel *Label1;
        TRichEdit *RichEdit1;
        TADOTable *ADOTable1;
        TADOTable *ADOTable2;
	TpFIBTransaction *IBTr;
	TpFIBDataSet *IBQuery2;
	TFIBIntegerField *IBQuery2IDCHKT;
	TFIBIntegerField *IBQuery2IDDOCCHKT;
	TFIBIntegerField *IBQuery2IDNOMCHKT;
	TFIBIntegerField *IBQuery2IDEDCHKT;
	TFIBBCDField *IBQuery2KOLCHKT;
	TFIBBCDField *IBQuery2KFCHKT;
	TFIBBCDField *IBQuery2PRICECHKT;
	TFIBBCDField *IBQuery2SUMCHKT;
	TFIBBCDField *IBQuery2SKCHKT;
	TFIBBCDField *IBQuery2NADCHKT;
	TFIBBCDField *IBQuery2PRICEFULLCHKT;
	TFIBBCDField *IBQuery2PRSKCHKT;
	TFIBBCDField *IBQuery2PRNADCHKT;
	TFIBStringField *IBQuery2GID_DCHKT;
	TFIBStringField *IBQuery2NAMENOM;
	TFIBIntegerField *IBQuery2CODENOM;
	TFIBStringField *IBQuery2NAMEED;
	TFIBStringField *IBQuery2SHED;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonCreate;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
	void __fastcall cxButtonCreateClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaExport(TComponent* Owner);
        String CatalogObmena;
        String CatalogOtcheta;
        void CreateReport(TDMGurDocCheckKKM * gurnal);
        void CopyTableOtchet(String NameCatalog);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaExport *FormaExport;
//---------------------------------------------------------------------------
#endif
