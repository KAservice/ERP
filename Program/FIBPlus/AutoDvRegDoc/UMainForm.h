//---------------------------------------------------------------------------

#ifndef UMainFormH
#define UMainFormH
//---------------------------------------------------------------------------


//-----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include "inifiles.hpp"
#include <ExtCtrls.hpp>
#include "FIBDatabase.hpp"
#include "pFIBDatabase.hpp"
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>

//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TProgressBar *ProgressBar1;
        TMemo *Memo1;
        TStatusBar *StatusBar1;
        TTimer *Timer1;
	TpFIBDatabase *Database;
	TpFIBTransaction *DefaultTransaction;
	TpFIBQuery *Query;
	TpFIBTransaction *TransactionRead;
	TpFIBQuery *QueryUpdate;
	TpFIBTransaction *TransactionUpdate;
	TpFIBDataSet *GurAllDoc;
	TFIBBCDField *GurAllDocIDDOC;
	TFIBDateTimeField *GurAllDocPOSDOC;
	TFIBWideStringField *GurAllDocTDOC;
	TFIBIntegerField *GurAllDocNUMDOC;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
		TIniFile * Ini;
        UnicodeString CatalogProtocol;
        void DvRegAllDoc(void);
		bool CanceDvRegAllDoc(void);

		void RunObrabDoc(void);

       // bool DvRegDoc(void);
       // void CanceDvRegDoc(void);

		void RunOnlyDvReg(void);

		TDateTime PosGrPosled;
		TDateTime PosFirstNoDvRegDoc;
		TDateTime PosZapretaRedakt;
        TDateTime PosStart;
		TDateTime PosNull;

		bool Zapusk;

        bool SetZapretProved (void);
		bool DeleteZapretProved (void);
		bool DeleteGrPosled (void);
		bool RunComandCancelDvRegDoc(UnicodeString type_doc,__int64 id_doc);
		bool RunComandDvRegDoc(UnicodeString type_doc,__int64 id_doc);

		void glSaveProtocol(UnicodeString str);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
