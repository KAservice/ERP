//---------------------------------------------------------------------------

#ifndef UFH
#define UFH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include <ToolWin.hpp>
#include <DBCtrls.hpp>
#include "UFormaViborBase.h"
//---------------------------------------------------------------------------
class TF : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TLabel *LabelNumberCheck;
        TLabel *LabelSostCheck;
        TToolBar *ToolBar1;
        TPanel *Panel2;
        TLabel *LabelSummaNach;
        TLabel *LabelProcent;
        TLabel *LabelSoobshenie;
        TPanel *Panel3;
        TPanel *Panel4;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TDBGrid *DBGrid1;
        TTabSheet *TabSheet2;
        TRichEdit *RE;
        TStatusBar *StatusBar;
        TDBText *DBText1;
        TDBText *DBText2;
        TDBText *DBText3;
        TDBText *DBText5;
        TPanel *Panel5;
        TDBText *DBText4;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TF(TComponent* Owner);

        bool ObrabExternalEvent(void);

        void FSvobProd(void);
        void FProdPoKodu(void);
        void FSvobOplata(void);
        void FSakrCheck(void);
        void FAnnCheck(void);
        void FPodtver(void);

        bool Opros;
        bool NewCheck;

        bool CloseProgramm;
        TFormaViborBase * FormaViborBase;
        void __fastcall EndViborBase(TObject *Sender);
        void ConnectDevice(void);
        void OpenFormViborBase(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TF *F;
//---------------------------------------------------------------------------
#endif
