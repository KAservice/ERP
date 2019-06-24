//---------------------------------------------------------------------------

#ifndef UFormaViborSprDogovorH
#define UFormaViborSprDogovorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UDMSprDogovor.h"
#include <ComCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ToolWin.hpp>
#include "cxButtons.hpp"
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
#include "cxLookAndFeelPainters.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
#include <Menus.hpp>
#include <ActnList.hpp>
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaViborSprDogovor : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonNew;
        TToolButton *ToolButtonEdit;
        TToolButton *ToolButtonDelete;
        TLabel *LabelKlient;
        TToolButton *ToolButton2;
        TLabel *HintLabel;
	TcxButton *cxButtonClose;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SDOG;
	TcxGridDBColumn *cxGrid1DBTableView1DO_SDOG;
	TcxGridDBColumn *cxGrid1DBTableView1NUMBER_SDOG;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TActionList *ActionList1;
	TAction *OpenHelp;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall OpenHelpExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaViborSprDogovor(TComponent* Owner);

	IDMFibConnection * DM_Connection;
	bool Init(void);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		HANDLE IdRodForm;
        TDMSprDogovor * DM;
        bool Vibor;
        bool OutReady;
        __int64 IdKlient;


        void __fastcall CloseElementSpr(TObject *Sender);
        TNotifyEvent FOnCloseForm;

        void UpdateForm();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaViborSprDogovor *FormaViborSprDogovor;
//---------------------------------------------------------------------------
#endif
