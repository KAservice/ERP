//---------------------------------------------------------------------------

#ifndef UMainFormH
#define UMainFormH
//---------------------------------------------------------------------------
//  свои модули
#include "UFormaViborBase.h"
#include "UDM.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include "FIBDataSet.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>
#include <ImgList.hpp>


//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu;
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
	TMenuItem *OpenHelpMainMenu;
	TMenuItem *FullGurMainMenu;
	TMenuItem *N2;
	TMenuItem *NewDocRemontMainMenu;
	TMenuItem *OpenRemSprHardwareMainMenu;
	TMenuItem *NewDocRemontHWMainMenu;
	TMenuItem *opemSprKKTMainMenu;
	TMenuItem *NewDocRemontKKTMainMenu;
	TMenuItem *NewDocKM1MainMenu;
	TMenuItem *NewDocKm2MainMenu;
	TMenuItem *NewDocServiceKKTMainMenu;
	TMenuItem *NewDocSetServHWMainMenu;
	TMenuItem *N4;
	TMenuItem *N5;
	TImageList *ImageListToolBar;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);

	//
	void __fastcall OpenFormAboutClick(TObject *Sender);
	void __fastcall OpenHelpMainMenuClick(TObject *Sender);

	void __fastcall ExecuteModuleToolBarClick(TObject *Sender);
	void __fastcall ExecuteModuleClick(TObject *Sender);

private:	// User declarations

	  void ExecuteModule(int num_module);
	   void CreateToolBar(void);
	   void CreateMainMenu(void);
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);

		TDM * DM_Connection;
	   int glRegNumber; //unsigned long
	   bool glDemo;

		HANDLE grd;
       // TDM *DM;
		UnicodeString User;
		UnicodeString ConnectionString;

       void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);

       TFormaViborBase * FormaViborBase;
       void __fastcall EndViborBase(TObject *Sender);
	   void CheckKey(void);
	   bool CheckEnableNew(void);





};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
