//---------------------------------------------------------------------------

#ifndef UFormaElementaSprNomRestH
#define UFormaElementaSprNomRestH
//---------------------------------------------------------------------------

#include "IFormaSpiskaSprSostProd.h"
#include "IFormaSpiskaSprMPrig.h"
#include "IFormaSpiskaSprProduce.h"
#include "IFormaSpiskaSprLossFactor.h"
#include "UDM.h"
#include "IDMSprNomRest.h"
#include "ISheetEditor.h"
#include "IFormaSpiskaSprEd.h"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include <Buttons.hpp>
#include <ActnList.hpp>
#include "FIBDatabase.hpp"
#include "pFIBDatabase.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxButtonEdit.hpp"
#include "cxCalc.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxMemo.hpp"
#include "cxTextEdit.hpp"
#include "cxCalendar.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#include "cxPC.hpp"
#include <ExtCtrls.hpp>
#include "cxLabel.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprNomRest : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TcxButton *cxButtonSost;
	TcxButton *cxButtonPrint;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TLabel *LabelNom;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet2;
	TLabel *Label5;
	TLabel *Label1;
	TLabel *Label3;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TDBText *KFEdDBText;
	TLabel *Label9;
	TcxDBButtonEdit *NameEdcxDBButtonEdit;
	TcxDBCalcEdit *KolEdProdcxDBCalcEdit;
	TcxDBMemo *SostKrcxDBMemo;
	TcxDBButtonEdit *MPrigcxDBButtonEdit;
	TcxDBTextEdit *NomercxDBTextEdit;
	TcxDBTextEdit *VihodcxDBTextEdit;
	TcxDBDateEdit *PoscxDBDateEdit;
	TcxDBTextEdit *NamecxDBTextEdit;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
	TAction *ActionPrint;
	TcxTabSheet *cxTabSheet3;
	TcxDBButtonEdit *NameEdFactorcxDBButtonEdit;
	TLabel *Label10;
	TcxTabSheet *cxTabSheet1;
	TLabel *Label4;
	TcxDBTextEdit *SrokcxDBTextEdit;
	TcxDBTextEdit *VidcxDBTextEdit;
	TcxDBTextEdit *TempcxDBTextEdit;
	TLabel *Label11;
	TLabel *Label12;
	TcxDBTextEdit *ApperancecxDBTextEdit;
	TcxLabel *cxLabel1;
	TcxDBTextEdit *ColourcxDBTextEdit;
	TcxDBTextEdit *TastecxDBTextEdit;
	TcxDBTextEdit *SmellcxDBTextEdit;
	TcxDBTextEdit *ConsistencecxDBTextEdit;
	TcxLabel *cxLabel2;
	TcxLabel *cxLabel3;
	TcxLabel *cxLabel4;
	TcxLabel *cxLabel5;
	TcxDBTextEdit *MDSVcxDBTextEdit;
	TcxDBTextEdit *MDGcxDBTextEdit;
	TcxDBTextEdit *MIScxDBTextEdit;
	TcxDBTextEdit *KMAMcxDBTextEdit;
	TcxDBTextEdit *BGKPcxDBTextEdit;
	TcxDBTextEdit *ECOLIcxDBTextEdit;
	TcxDBTextEdit *KPScxDBTextEdit;
	TcxDBTextEdit *PROTEUScxDBTextEdit;
	TcxDBTextEdit *PMScxDBTextEdit;
	TcxLabel *cxLabel6;
	TcxLabel *cxLabel7;
	TcxLabel *cxLabel8;
	TcxLabel *cxLabel9;
	TcxLabel *cxLabel10;
	TcxLabel *cxLabel11;
	TcxLabel *cxLabel12;
	TcxLabel *cxLabel13;
	TcxLabel *cxLabel14;
	TcxDBMemo *TehnologcxDBMemo;
	TLabel *Label2;
	TcxLabel *cxLabel15;
	TcxLabel *cxLabel16;
	TLabel *Label13;
	TcxDBButtonEdit *NameProducecxDBButtonEdit;
	TcxDBButtonEdit *NameLossFactorcxDBButtonEdit;
	TLabel *Label14;
	TLabel *Label15;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxButtonSostClick(TObject *Sender);
	void __fastcall NameEdcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall MPrigcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NamecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PoscxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall NomercxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall VihodcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall SrokcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall KolEdProdcxDBCalcEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall ActionPrintExecute(TObject *Sender);
	void __fastcall NameEdFactorcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameProducecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameLossFactorcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

		IFormaSpiskaSprMPrig *FormaSpiskaSprMPrig;
		IFormaSpiskaSprEd * FormaSpiskaSprEd;
		IFormaSpiskaSprSostProd * SostavProd;


		void OpenFormSpiskaSprMPrig(void);

        void PrintTehnologKart(void);
		void OutputString(ISheetEditor *prForm);
		void OutputZagolovokReport(ISheetEditor *prForm);
		void OutputPodavalReport(ISheetEditor *prForm);
		int numRow;
		int numCol;
		int porNumStr;
		bool SaveElement;


		IFormaSpiskaSprProduce *FormaSpiskaSprProduce;
		IFormaSpiskaSprLossFactor *FormaSpiskaSprLossFactor;
		void OpenFormaSpiskaSprProduce(void);
		void OpenFormaSpiskaSprLossFactor(void);
		void EndViborProduce(void);
		void EndViborLossFactor(void);

		enum  {ER_NoRekv,ER_EdProd, ER_EdFactor, ER_Produce, ER_LossFactor,
							ER_MPrig,ER_Sostav, ER_NO} EditRekvisit;


		void ViborEdFactor(void);
		void EndViborEdFactor(void);

public:		// User declarations
		__fastcall TFormaElementaSprNomRest(TComponent* Owner);

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
		IDMSprNomRest * DM;
		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форм

        void UpdateForm(void);

		UnicodeString NameNom;
		__int64 Id;
        __int64 IdNom;


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprNomRest *FormaElementaSprNomRest;
//---------------------------------------------------------------------------
#endif
