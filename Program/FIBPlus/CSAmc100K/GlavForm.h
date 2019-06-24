//---------------------------------------------------------------------------

#ifndef GlavFormH
#define GlavFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <ToolWin.hpp>
#include <IBQuery.hpp>
#include <inifiles.hpp>
#include <DBCtrls.hpp>
#include "UFormaViborBase.h"
#include <Menus.hpp>
//---------------------------------------------------------------------------

const MyTrayIcon=WM_USER+2;

class TFormGl : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TLabel *LabelNumberCheck;
        TLabel *LabelSostCheck;
        TLabel *LabelOperation;
        TLabel *LabelActiveKKM;
        TPanel *Panel2;
        TLabel *LabelSummaCheck;
        TLabel *LabelSummaNach;
        TLabel *LabelItog;
        TLabel *LabelNumberKl;
        TLabel *LabelProcent;
        TPanel *Panel3;
        TPanel *Panel4;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TDBGrid *DBGrid1;
        TRichEdit *RE;
        TStatusBar *StatusBar;
        TLabel *LabelSoobshenie;
        TDBText *DBText1;
        TDBText *DBText2;
	TMainMenu *MainMenu1;
	TMenuItem *OpenAbout;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
	void __fastcall OpenAboutClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormGl(TComponent* Owner);


        __int64 IdCheck;

        void __fastcall ObrabotatZaprosKKM();
        String StrokaMemo;
        bool NewCheck;
        double TekSummaCheck;


        void __fastcall ObrabExternalEvent(void);
        void  __fastcall UpdateForm(void);
        void RaspredNachislenie(void);




        bool CloseProgramm;
        TFormaViborBase * FormaViborBase;
        void __fastcall EndViborBase(TObject *Sender);
        void ConnectDevice(void);
		void OpenFormViborBase(void);

		double Price;

};
//---------------------------------------------------------------------------
extern PACKAGE TFormGl *FormGl;
//---------------------------------------------------------------------------
#endif
