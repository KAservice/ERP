//---------------------------------------------------------------------------

#ifndef UArmOfH
#define UArmOfH
//---------------------------------------------------------------------------
#include "GlobalInterface.h"
#include "UMainObject.h"
#include "UDM.h"
#include "UFormaViborBaseTouch.h"
#include "IScaner.h"
#include "IFiskReg.h"
#include "IDisplayPok.h"
#include "IKalkulator.h"
//--------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <ToolWin.hpp>
#include <ActnList.hpp>
#include <Menus.hpp>
#include <AppEvnts.hpp>

//---------------------------------------------------------------------------
class TArmOf : public TForm
{
__published:	// IDE-managed Components
        TStatusBar *StatusBar;
        TPanel *Panel1;
        TBitBtn *BitBtnOpenStrobject;
        TBitBtn *BitBtnExit;
        TButton *Button1;
        TButton *Button2;
        TBitBtn *BitBtnCreateCheck;
        TButton *ButtonPrintXReport;
        TButton *ButtonPrintZReport;
        TButton *ButtonSumma;
	TActionList *ActionList1;
	TAction *ActionOpenCheck;
	TAction *ActionOpenHelp;
	TAction *ActionNo;
	TApplicationEvents *ApplicationEvents1;
	TButton *ButtonReports;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall BitBtnOpenStrObjectClick(TObject *Sender);
        void __fastcall BitBtnExitClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall BitBtnCreateCheckClick(TObject *Sender);
        void __fastcall ButtonPrintXReportClick(TObject *Sender);
        void __fastcall ButtonPrintZReportClick(TObject *Sender);
        void __fastcall ButtonSummaClick(TObject *Sender);
	void __fastcall ActionOpenCheckExecute(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ApplicationEvents1Idle(TObject *Sender, bool &Done);
	void __fastcall ButtonReportsClick(TObject *Sender);


private:	// User declarations

 typedef int  (__import  DllkanGetInterfaceComType(REFIID id_class, REFIID id_interface, void ** ppv));
 typedef int  (__import  DllkanSendApplicationType(TApplication * app));
	//COM система
	HINSTANCE dllInstanceCom;
	DllkanGetInterfaceComType * DllkanGetInterfaceCom;
	DllkanSendApplicationType * DllkanSendApplication;
	IkanCom * InterfaceGlobalCom;

	//Подключение
	IDMFibConnection * DM_Connection;


public:		// User declarations
		__fastcall TArmOf(TComponent* Owner);

		bool ShowMessageOnClose;

		TMainObject * MainObject;
		IkanUnknown * InterfaceMainObject;

		IScaner * glScaner;
		IFiskReg * glFR;
		IDisplayPok * glDisplayPok;

        IKalkulator * Kalk;


        enum  {ER_NoRekv,StrObjectRekvisit,PodrRekvisit,InputPassword,
                 CreateCheck,DocPer, NO} EditRekvisit;

        void __fastcall EndEdit(TObject *Sender);

        TFormaViborBaseTouch * FormaViborBase;
        void __fastcall EndViborBase(TObject *Sender);
		void ConnectDevice(void);

        HANDLE grd;
		void CheckKey();
		bool CheckEnableNew(void);
		
		void CheckDateTimeFR(void);

		bool glDemo;
		int glRegNumber; //unsigned long



};
//---------------------------------------------------------------------------
extern PACKAGE TArmOf *ArmOf;

//---------------------------------------------------------------------------
#endif
