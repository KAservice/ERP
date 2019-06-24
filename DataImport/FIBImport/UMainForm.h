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
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *OpenFormImportGrpNom;
	TMenuItem *OpenFormImportNomMainMenu;
	TMenuItem *OpenFormImportEdMainMenu;
	TMenuItem *OpenFormSetEdNomMainMenu;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *N11;
	TMenuItem *N12;
	TMenuItem *N13;
	TMenuItem *N14;
	TMenuItem *N31;
	TMenuItem *N17;
	TMenuItem *N18;
	TMenuItem *N19;
	TMenuItem *N15;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall OpenFormImportGrpNomClick(TObject *Sender);
	void __fastcall OpenFormImportNomMainMenuClick(TObject *Sender);
	void __fastcall OpenFormImportEdMainMenuClick(TObject *Sender);
	void __fastcall OpenFormSetEdNomMainMenuClick(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
	void __fastcall N6Click(TObject *Sender);
	void __fastcall N8Click(TObject *Sender);
	void __fastcall N9Click(TObject *Sender);
	void __fastcall N14Click(TObject *Sender);
	void __fastcall N31Click(TObject *Sender);
	void __fastcall N11Click(TObject *Sender);
	void __fastcall N12Click(TObject *Sender);
	void __fastcall N18Click(TObject *Sender);
	void __fastcall N19Click(TObject *Sender);
	void __fastcall N15Click(TObject *Sender);
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
