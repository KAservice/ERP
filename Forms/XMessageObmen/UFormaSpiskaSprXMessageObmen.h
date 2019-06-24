//---------------------------------------------------------------------------

#ifndef UFormaSpiskaSprXMessageObmenH
#define UFormaSpiskaSprXMessageObmenH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ToolWin.hpp>
#include "UDMXMessageObmen.h"
#include "UFormaViborPerioda.h"
#include "UFormaSpiskaSprInfBase.h"
#include "USheetEditor.h"
#include <ActnList.hpp>
#include "cxClasses.hpp"
#include "cxControls.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
//---------------------------------------------------------------------------
class TFormaSpiskaSprXMessageObmen : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TLabel *LabelInterval;
        TLabel *LabelOtbor;
        TToolButton *ToolButtonViborInfBase;
        TToolButton *ToolButtonOtbor;
        TToolButton *ToolButtonPrintForm;
        TToolButton *ToolButton4;
        TToolButton *ToolButtonSortPoDate;
        TToolButton *ToolButtonSortPoGid;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1GID_XMESSAGE_OBMEN;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_XMESSAGE_OBMEN;
	TcxGridDBColumn *cxGrid1DBTableView1KOLERR_XMESSAGE_OBMEN;
	TcxGridDBColumn *cxGrid1DBTableView1POS_XMESSAGE_OBMEN;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SINFBASE_OBMEN;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButton1Click(TObject *Sender);
        void __fastcall ToolButton3Click(TObject *Sender);
        void __fastcall ToolButtonViborInfBaseClick(TObject *Sender);
        void __fastcall ToolButtonOtborClick(TObject *Sender);
        void __fastcall ToolButtonPrintFormClick(TObject *Sender);
        void __fastcall ToolButtonSortPoDateClick(TObject *Sender);
        void __fastcall ToolButtonSortPoGidClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1KOLERR_XMESSAGE_OBMENCustomDrawCell(
          TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
          TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaSpiskaSprXMessageObmen(TComponent* Owner); 

        TDMXMessageObmen *DM;

        TNotifyEvent FOnCloseForm;
        bool Vibor;
        bool OutReady;

       // void __fastcall CloseElementSpr(TObject *Sender);
        TFormaViborPerioda *FormaViborPerioda;

        void UpdateForm(void);
        void OpenFormElement();
        void OpenFormNewElement();
        void DeleteElement();

        TDateTime PosNach;
        TDateTime PosCon;
        __int64 IdBase;
        AnsiString NameInfBase;
        TFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
        bool Otbor;
        enum {NO,ViborPerioda, ViborInfBase} ViborRekv;
        void __fastcall EndEdit(TObject *Sender);
        HANDLE IdRodForm;
        HANDLE IdDochForm;



        int numRow;
        int numCol;
        void CreateReport(void);
        void OutputZagolovokReport(TSheetEditor *prForm);
        void OutputPodavalReport(TSheetEditor *prForm);
        void OutputStringReport(TSheetEditor *prForm);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSpiskaSprXMessageObmen *FormaSpiskaSprXMessageObmen;
//---------------------------------------------------------------------------
#endif
