//---------------------------------------------------------------------------

#ifndef UMainFormH
#define UMainFormH
//---------------------------------------------------------------------------
#include "UFormaViborBase.h"


//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TStatusBar *StatusBar;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *OpenTableIsmMainMenu;
	TMenuItem *N7;
	TMenuItem *CreateNewBase;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TActionList *ActionList1;
	TAction *ActionOpenFormCreateNewBase;
	TAction *ActionOpenFormCreateLog;
	TAction *ActionOpenFormaXTableBase;
	TMenuItem *OpenFormaXTablebaseMainMenu;
	TMenuItem *N8;
	TMenuItem *SetGeneratorsMainMenu;
	TMenuItem *GreateServDoc;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall N6Click(TObject *Sender);
	void __fastcall OpenTableIsmMainMenuClick(TObject *Sender);
	void __fastcall ActionOpenFormCreateNewBaseExecute(TObject *Sender);
	void __fastcall ActionOpenFormCreateLogExecute(TObject *Sender);
	void __fastcall ActionOpenFormaXTableBaseExecute(TObject *Sender);
	void __fastcall SetGeneratorsMainMenuClick(TObject *Sender);
	void __fastcall GreateServDocClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);



	TFormaViborBase * FormaViborBase;
	void __fastcall EndViborBase(TObject *Sender);


};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
