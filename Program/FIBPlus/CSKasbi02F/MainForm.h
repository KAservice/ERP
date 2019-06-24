//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------


#include "UFormaViborBase.h"

//----------------------------------------------------------------------------
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
#include <Buttons.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------


class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *LabelSostCheck;
        TLabel *LabelActiveKKM;
        TPanel *Panel2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label2;
        TPanel *Panel3;
        TPanel *Panel4;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TDBGrid *DBGrid1;
        TRichEdit *RE;
        TStatusBar *StatusBar;
        TLabel *LabelSoobshenie;
        TDBText *NameFirm;
        TDBText *NameSklad;
        TDBText *OperCHK;
        TDBText *SumFull;
        TDBText *SumDoc;
        TDBText *KlChk;
        TDBText *NumberDoc;
        TDBText *SummaSkidok;
        TDBText *SummaNadbavok;
        TLabel *Label5;
        TLabel *Label6;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);

        double Price;
        int IdCheck;
        
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
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
