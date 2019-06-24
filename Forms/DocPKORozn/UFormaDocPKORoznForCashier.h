//---------------------------------------------------------------------------

#ifndef UFormaDocPKORoznForCashierH
#define UFormaDocPKORoznForCashierH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IDMDocPKORozn.h"

#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprDogovor.h"
#include "IFiskReg.h"

//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBQuery.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <DBGrids.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>

#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtonEdit.hpp"
#include "cxCalc.hpp"
#include "cxDBEdit.hpp"
#include "cxCalendar.hpp"
#include <ActnList.hpp>
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaDocPKORoznForCashier : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TLabel *Label2;
        TLabel *Label12;
        TLabel *Label14;
        TLabel *Label15;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label6;
        TLabel *Label7;
        TDBText *DBTextFNameUser;
        TDBText *NameBaseDBText;
        TLabel *ProsmotrLabel;
        TLabel *Label9;
        TLabel *Label1;
        TLabel *Label5;
        TCoolBar *CoolBar1;
        TToolBar *ToolBar1;
        TToolButton *ToolButtonPrintDoc;
        TToolButton *ToolButtonPrintDocOnFR;
	TcxButton *cxButtonPrint;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxComboBox *OperationComboBox;
	TcxDBCalcEdit *SumDoccxDBCalcEdit;
	TcxDBTextEdit *PrimcxDBTextEdit;
	TcxDBTextEdit *OsncxDBTextEdit;
	TcxDBTextEdit *PrOtcxDBTextEdit;
	TcxDBButtonEdit *NameDogovorcxDBButtonEdit;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TcxDBTextEdit *NumDoccxDBTextEdit;
	TcxDBDateEdit *PoscxDBDateEdit;
	TcxDBTextEdit *NameKKMcxDBTextEdit;
	TcxDBTextEdit *NameFirmcxDBTextEdit;
	TActionList *ActionList1;
	TAction *OpenHelp;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
	TAction *ActionPrint;
	TcxDBTextEdit *PrefiksNumcxDBTextEdit;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonPrintDocClick(TObject *Sender);
        void __fastcall ToolButtonPrintDocOnFRClick(TObject *Sender);
	void __fastcall OperationComboBoxPropertiesChange(TObject *Sender);
	void __fastcall NameDogovorcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall OpenHelpExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall ActionPrintExecute(TObject *Sender);

private:	// User declarations


	   bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
       int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

		IFormaSpiskaSprKlient * SpisokKlient;
		IFormaSpiskaSprDogovor * FormaSpiskaSprDogovor;

        void OpenFormSpiskaSprKlient(void);
        void OpenFormSpiskaSprDogovor(void);



        enum  {ER_NoRekv,ViborKlient,ViborDogovor, NO} EditRekvisit;
		bool PrintDocOnFR(void);
		void PrintDoc(void);
		bool flObrabatChangeOperation;
		int numRow;
		int numCol;
		IFiskReg  *glFR;
public:		// User declarations
		__fastcall TFormaDocPKORoznForCashier(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //функция удаления реализации интерфейса
		bool flDeleteImpl;   //надо ли удалять реализацию при удалении текущего модуля

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

		//из этой формы открыта другая для выбора
		//обработка события выбора в другой форме (которая была открыта из этой для выбора чего-то)
		int ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект (форму в которой производится выбор)
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									);


		//IMainInterface
		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);



		//Текущий интерфейс
		IDMDocPKORozn *DM;

        bool Prosmotr;    //только просмотр
		bool Vibor;       //для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме
		__int64 IdDoc;           //идентификатор текущей записи




        void UpdateForm(void);


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocPKORoznForCashier *FormaDocPKORoznForCashier;
//---------------------------------------------------------------------------
#endif
