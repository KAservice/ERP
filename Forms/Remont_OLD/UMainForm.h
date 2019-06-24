//---------------------------------------------------------------------------

#ifndef UMainFormH
#define UMainFormH
//---------------------------------------------------------------------------
//  свои модули
#include "UFormaViborBase.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>


//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TStatusBar *StatusBar;
	TMenuItem *N1;
	TMenuItem *WindowsAll;
	TMenuItem *OpenFormAbout;
	TMenuItem *N3;
	TMenuItem *OpenSprNeispr;
	TMenuItem *OpenSprModel;
	TMenuItem *OpenSprSost;
	TMenuItem *OpenSprTRemont;
	TMenuItem *N8;
	TMenuItem *OpenGurnalZ;
	TToolBar *ToolBar1;
	TMenuItem *Windows;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall OpenFormAboutClick(TObject *Sender);
	void __fastcall OpenSprNeisprClick(TObject *Sender);
	void __fastcall OpenSprModelClick(TObject *Sender);
	void __fastcall OpenSprTRemontClick(TObject *Sender);
	void __fastcall OpenSprSostClick(TObject *Sender);
	void __fastcall OpenGurnalZClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);

		HANDLE grd;
       // TDM *DM;
        String User;
        String ConnectionString;

       void __fastcall ReadShtrihCodEvent(int number, char * sh);

       TFormaViborBase * FormaViborBase;
       void __fastcall EndViborBase(TObject *Sender);
	   void CheckKey(void);
	   bool CheckEnableNew(void);


};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
