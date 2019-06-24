//---------------------------------------------------------------------------

#ifndef UFormaSpiskaSprObmenTypeDocH
#define UFormaSpiskaSprObmenTypeDocH
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
#include "UDM.h"
#include "UDMSprObmenTypeDoc.h"
#include <DBCtrls.hpp>
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
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TFormaSpiskaSprObmenTypeDoc : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonNew;
        TToolButton *ToolButtonDelete;
        TToolButton *ToolButton4;
        TLabel *HintLabel;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_STYPEDOC_OBMEN;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonNewClick(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxButtonOKClick(TObject *Sender);
	void __fastcall cxButtonCloseClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaSpiskaSprObmenTypeDoc(TComponent* Owner);
        TNotifyEvent FOnCloseForm;
        HANDLE IdRodForm;
        HANDLE IdDochForm;

        TDMSprObmenTypeDoc* DM;


        bool Vibor;
        bool OutReady;

        __int64 IdBase;   

        int ViborIdNom;  //выбранная номенклатура
        bool AllElement;//текущее значение все элементы или нет
        bool Prosmotr;

        void __fastcall EndEdit(TObject *Sender);





        void DeleteElement();


        void UpdateForm(void);

        enum{NO} ViborRekvisit;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSpiskaSprObmenTypeDoc *FormaSpiskaSprObmenTypeDoc;
//---------------------------------------------------------------------------
#endif
