//---------------------------------------------------------------------------

#ifndef UFormaElementaSprKlientH
#define UFormaElementaSprKlientH
//---------------------------------------------------------------------------
#include "IFormaElementaSprKlientDopFisL.h"
#include "IFormaElementaSprKlientDopUrL.h"
#include "IFormaSpiskaSprVidKlient.h"
#include "IFormaSpiskaSprCountry.h"
#include "IFormaSpiskaSprGrpNom.h"
#include "IFormaKladr.h"
#include "IDMSprTypePrice.h"
#include "IDMSprKlient.h"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ActnList.hpp>
#include "cxButtonEdit.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxDropDownEdit.hpp"
#include "cxGraphics.hpp"
#include "cxPC.hpp"
#include <ExtCtrls.hpp>
#include "cxMemo.hpp"
#include "cxCalc.hpp"
#include "cxLookAndFeels.hpp"
#include "cxImageComboBox.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprKlient : public TForm
{
__published:	// IDE-managed Components
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxPageControl *cxPageControl1;
	TPanel *Panel1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TLabel *Label1;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label7;
	TLabel *Label2;
	TDBText *IDKlientDBText;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TcxDBButtonEdit *VidKlientcxDBButtonEdit;
	TcxDBButtonEdit *NameCountrycxDBButtonEdit;
	TcxButton *cxButtonOpenSprDiscountCard;
	TcxDBButtonEdit *AdresscxDBButtonEdit;
	TcxDBTextEdit *TelcxDBTextEdit;
	TcxDBTextEdit *INNcxDBTextEdit;
	TcxDBTextEdit *FNamecxDBTextEdit;
	TcxDBTextEdit *NamecxDBTextEdit;
	TcxComboBox *TKlient;
	TcxDBTextEdit *KrNameKlientcxDBTextEdit;
	TLabel *Label6;
	TLabel *Label8;
	TcxDBTextEdit *OKPOcxDBTextEdit;
	TcxDBTextEdit *KPPcxDBTextEdit;
	TPanel *Panel2;
	TcxButton *cxButtonDogovora;
	TcxButton *cxButtonTelNum;
	TcxButton *cxButtonRaschScheta;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxButton *cxButtonDoc;
	TcxButton *cxButtonDopFL;
	TcxButton *cxButtonDopUL;
	TcxComboBox *TypePriceComboBox;
	TLabel *Label21;
	TcxDBMemo *DescrcxDBMemo;
	TcxDBMemo *MessagecxDBMemo;
	TcxDBCalcEdit *MaxCreditcxDBCalcEdit;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TcxDBTextEdit *EmailcxDBTextEdit;
	TcxDBTextEdit *WWWcxDBTextEdit;
	TLabel *Label16;
	TLabel *Label15;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
	TcxDBMemo *YurAdresscxDBMemo;
	TLabel *Label17;
	TcxDBMemo *PochtAdresscxDBMemo;
	TLabel *Label18;
	TcxDBImageComboBox *cxDBImageComboBoxTYPE_POISK_SKLIENT;
	TLabel *Label19;
	TcxTabSheet *cxTabSheet3;
	TLabel *Label20;
	TLabel *Label22;
	TcxDBButtonEdit *cxDBButtonEditNAMEGN;
	TcxDBButtonEdit *cxDBButtonEditNAME_REM_SGRP_HARDWARE;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall NameKlientKeyPress(TObject *Sender, char &Key);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall VidKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameCountrycxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonOpenSprDiscountCardClick(TObject *Sender);
	void __fastcall AdresscxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonDogovoraClick(TObject *Sender);
	void __fastcall cxButtonTelNumClick(TObject *Sender);
	void __fastcall cxButtonRaschSchetaClick(TObject *Sender);
	void __fastcall cxButtonDocClick(TObject *Sender);
	void __fastcall cxButtonDopFLClick(TObject *Sender);
	void __fastcall cxButtonDopULClick(TObject *Sender);
	void __fastcall NamecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall FNamecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall TelcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall INNcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall OKPOcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall KPPcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall TypePriceComboBoxPropertiesChange(TObject *Sender);
	void __fastcall KrNameKlientcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall cxDBButtonEditNAMEGNPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall cxDBButtonEditNAME_REM_SGRP_HARDWAREPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);

private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

				IFormaElementaSprKlientDopFisL *  FormaElementaSprKlientDopFisL;
		void OpenFormaElementaSprKlientFisL(void);

		IFormaElementaSprKlientDopUrL *  FormaElementaSprKlientDopUrL;
		void OpenFormaElementaSprKlientUrL(void);

		//выбор вида клиента
		IFormaSpiskaSprVidKlient * FormaSpiskaSprVidKlient;
		void ViborVidKlient(void);
		void __fastcall EndViborVidKlient(void);

		//выбор страны
		IFormaSpiskaSprCountry * FormaSpiskaSprCountry;
		void ViborCountry(void);
		void __fastcall EndViborCountry(void);

		//выбор адреса
		IFormaKladr  *FormaKladr;
		void ViborAdressByKladr(void);
		void __fastcall EndViborAdressByKladr(void);

		bool flObrabatChangeTypeKlient;
		bool flObrabatChangeTypePrice;

		IDMSprTypePrice *DMSprTypePrice;

				//выбор группы номенклатуры
		IFormaSpiskaSprGrpNom * FormaSpiskaSprGrpNom;
		void ViborGrpNom(void);
		void EndViborGrpNom(void);

			enum {ER_NoRekv, ER_No, ER_DopFisL, ER_DopUrL,
			ER_VidKlient, ER_Country, ER_Kladr, ER_GrpNom}  EditRekvisit;


public:		// User declarations
		__fastcall TFormaElementaSprKlient(TComponent* Owner);


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
		IDMSprKlient * DM;
		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме


		void UpdateForm(void);


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprKlient *FormaElementaSprKlient;
//---------------------------------------------------------------------------
#endif
