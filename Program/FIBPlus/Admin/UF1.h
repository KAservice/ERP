//---------------------------------------------------------------------------

#ifndef UF1H
#define UF1H
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "UMainObject.h"
#include "UDM.h"
#include "UFormaViborBase.h"
#include "IDMInterfToolBar.h"
#include "IDMInterfMainMenuGrp.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <IBQuery.hpp>
#include <ImgList.hpp>
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TF1 : public TForm
{
__published:	// IDE-managed Components
        TStatusBar *StatusBar;
        TToolBar *ToolBar1;
        TMainMenu *MainMenu1;
        TMenuItem *Windows;
        TMenuItem *Window;
        TMenuItem *Help;
	TMenuItem *MainMenuAbout;
	TMenuItem *MainMenuHelp;
	TImageList *ImageListToolBar;
	TActionList *ActionList1;
	TAction *ActionOpenHelp;
	TAction *ActionShowMessageOnClose;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);

	//Главное меню
	void __fastcall MainMenuHelpClick(TObject *Sender);
	void __fastcall MainMenuAboutClick(TObject *Sender);
	void __fastcall MainMenuSetupMainMenuClick(TObject *Sender);
	void __fastcall MainMenuOpenSprUserClick(TObject *Sender);
	void __fastcall MainMenuOpenSprProgramModuleClick(TObject *Sender);
	void __fastcall MainMenuOpenSprObjectBasePrivClick(TObject *Sender);

	void __fastcall ExecuteModuleClick(TObject *Sender);
	void __fastcall ExecuteModuleToolBarClick(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ActionShowMessageOnCloseExecute(TObject *Sender);


private:	// User declarations
 void ExecuteModule(UnicodeString str_guid);
 void CreateMainMenu(void);
 void CreateToolBar(void);

 typedef int  (__import  DllkanGetInterfaceComType(REFIID id_class, REFIID id_interface, void ** ppv));
 typedef int  (__import  DllkanSendApplicationType(TApplication * app));
	//COM система
	HINSTANCE dllInstanceCom;
	DllkanGetInterfaceComType * DllkanGetInterfaceCom;
	DllkanSendApplicationType * DllkanSendApplication;
	IkanCom * InterfaceGlobalCom;

	//Подключение
	IDMFibConnection * DM_Connection;

	IDMInterfMainMenuGrp * DMGrpMenu;
public:		// User declarations
		__fastcall TF1(TComponent* Owner);

		TMainObject * MainObject;
		IkanUnknown * InterfaceMainObject;

		bool Demo;
		
		HANDLE grd;
       // TDM *DM;
		UnicodeString User;
        UnicodeString ConnectionString;

       void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);

       TFormaViborBase * FormaViborBase;
       void __fastcall EndViborBase(TObject *Sender);

       void ConnectDevice(void);

	   void CheckGlobSetup(void);
	   void CheckKey(void);
	   bool CheckEnableNew(void);

	   int glRegNumber; //unsigned long
	   bool glDemo;

	   IScaner * glScaner;
	   IFiskReg * glFR;
	   IDisplayPok * glDisplayPok;

	   bool ShowMessageOnClose;

	   void RunAutoStart(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TF1 *F1;
//---------------------------------------------------------------------------
#endif
