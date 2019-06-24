//---------------------------------------------------------------------------

#ifndef UFormaSpiskaSprObmenSkladH
#define UFormaSpiskaSprObmenSkladH
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
#include "UDMSprObmenSklad.h"
#include <DBCtrls.hpp>
#include "UFormaSpiskaSprSklad.h"
#include <ActnList.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TFormaSpiskaSprObmenSklad : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TDBGrid *DBGrid1;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonNew;
        TToolButton *ToolButtonEdit;
        TToolButton *ToolButtonDelete;
        TToolButton *ToolButton4;
        TLabel *HintLabel;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonClose;
	TcxButton *cxButtonOK;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonNewClick(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall DBGrid1EditButtonClick(TObject *Sender);
        void __fastcall ToolButtonEditClick(TObject *Sender);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall cxButtonOKClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaSpiskaSprObmenSklad(TComponent* Owner);
        TNotifyEvent FOnCloseForm;
        HANDLE IdRodForm;
        HANDLE IdDochForm;

        TDMSprObmenSklad* DM;


        bool Vibor;
        bool OutReady;

		__int64 IdBase;

        __int64 ViborIdNom;  //выбранная номенклатура
        bool AllElement;//текущее значение все элементы или нет
        bool Prosmotr;

        void __fastcall EndEdit(TObject *Sender);

        TFormaSpiskaSprSklad* SpisokSklad;

        void OpenFormSpiskaSprSklad();

        void DeleteElement();


        void UpdateForm(void);

        enum{NO,ViborSklad} ViborRekvisit;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSpiskaSprObmenSklad *FormaSpiskaSprObmenSklad;
//---------------------------------------------------------------------------
#endif
