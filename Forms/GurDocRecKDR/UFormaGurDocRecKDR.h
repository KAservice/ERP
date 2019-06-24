//---------------------------------------------------------------------------

#ifndef UFormaGurDocRecKDRH
#define UFormaGurDocRecKDRH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UDM.h"
#include "UDMGurDocRecKDR.h"
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include "UPrintFormAll.h"
#include "UFormaViborPerioda.h"
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TFormaGurDocRecKDR : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TDBGrid *DBGrid1;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonDelete;
        TToolButton *ToolButton3;
        TToolButton *ToolButtonViborPerioda;
        TLabel *LabelInterval;
        TLabel *Label1;
        TToolButton *ToolButtonNewDoc;
        TToolButton *ToolButton2;
        TToolButton *ToolButton4;
        TToolButton *ToolButtonPrint;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall DBGrid1DblClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
        void __fastcall ToolButton3Click(TObject *Sender);
        void __fastcall ToolButtonViborPeriodaClick(TObject *Sender);
        void __fastcall ToolButtonNewDocClick(TObject *Sender);
        void __fastcall ToolButton4Click(TObject *Sender);
        void __fastcall DBGrid1DrawColumnCell(TObject *Sender,
          const TRect &Rect, int DataCol, TColumn *Column,
          TGridDrawState State);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaGurDocRecKDR(TComponent* Owner);
        TNotifyEvent FOnCloseForm;

        HANDLE IdRodForm;
        HANDLE IdDochForm;
        TDMGurDocRecKDR * DM;
        bool Vibor;

        int IdDoc;

        void __fastcall EndEdit(TObject *Sender);
        enum {NO,ViborPerioda} ViborRekv;
        TFormaViborPerioda *FormaViborPerioda;


        void OpenFormDoc();
        void DeleteDoc(void);
        void CanceDvRegDoc(void);

        TDateTime PosNach;
        TDateTime PosCon;

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaGurDocRecKDR *FormaGurDocRecKDR;
//---------------------------------------------------------------------------
#endif
