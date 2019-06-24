//---------------------------------------------------------------------------

#ifndef UFormaElementaSprProducerNomH
#define UFormaElementaSprProducerNomH
//---------------------------------------------------------------------------
#include "IFormaSpiskaSprProducerEd.h"
#include "IFormaSpiskaSprProducerPrice.h"
#include "UDM.h"
#include "IDMSprProducerNom.h"
#include "IFormaElementaSprProducerEd.h"
#include "IDMSprProducerEd.h"
#include "IDMSprProducerPrice.h"
#include "IDMFibConnection.h"
#include "IFormaSpiskaSprNom.h"
//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <ActnList.hpp>
#include "cxCalc.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxLabel.hpp"
#include "cxPC.hpp"
#include "cxButtonEdit.hpp"
#include "cxGroupBox.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxGraphics.hpp"
#include "cxButtons.hpp"
#include "cxMemo.hpp"
#include "cxImageComboBox.hpp"
#include "cxDBLookupComboBox.hpp"
#include "cxDBLookupEdit.hpp"
#include "cxLookupEdit.hpp"
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxFilter.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
#include "cxDBLabel.hpp"
#include "cxCalendar.hpp"
#include "cxCheckBox.hpp"
#include "cxSpinEdit.hpp"
#include "cxCurrencyEdit.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprProducerNom : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TLabel *Label9;
	TLabel *Label1;
	TLabel *Label12;
	TLabel *Label4;
	TLabel *Label2;
	TLabel *Label3;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBTextEdit *FNamecxDBTextEdit;
	TcxDBTextEdit *KrNamecxDBTextEdit;
	TcxDBTextEdit *NameNomcxDBTextEdit;
	TcxDBTextEdit *ArtcxDBTextEdit;
	TcxDBTextEdit *CodecxDBTextEdit;
	TcxButton *cxButtonPrice;
	TcxButton *cxButtonEd;
	TcxDBImageComboBox *TNomcxDBImageComboBox;
	TGroupBox *GroupBoxBasEd;
	TcxDBLabel *NameBasEdcxDBLabel;
	TcxDBLabel *CodeBasEdcxDBLabel;
	TcxLabel *cxLabel2;
	TcxDBLabel *BarCodeBasEdcxDBLabel;
	TcxLabel *cxLabel3;
	TcxLabel *cxLabel4;
	TcxDBLabel *KFBasEdcxDBLabel;
	TcxDBLabel *KF2BasEdcxDBLabel;
	TcxButton *cxButtonEditBasEd;
	TcxLabel *cxLabel14;
	TAction *ActionSetMainTabSheet;
	TAction *ActionSetAdditionallyTabSheet;
	TGroupBox *GroupBox1;
	TToolBar *ToolBar4;
	TToolButton *ToolButton1;
	TToolButton *ToolButtonAddPrice;
	TToolButton *ToolButtonDeletePrice;
	TcxGrid *cxGrid1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridDBColumn *cxGrid1DBTableView1NAMETPRICE;
	TcxGridDBColumn *cxGrid1DBTableView1ZNACH_PRICE;
	TcxGridLevel *cxGrid1Level1;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
	TLabel *NameGrpLabel;
	TcxDBTextEdit *ModelcxDBTextEdit;
	TcxDBTextEdit *CodeAnalogcxDBTextEdit;
	TcxDBCheckBox *DostupnocxDBCheckBox;
	TcxDBCalcEdit *PriceZakupcxDBCalcEdit;
	TcxDBCalcEdit *PricecxDBCalcEdit;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TcxDBButtonEdit *NameNomcxDBButtonEdit;
	TcxDBLabel *CodeNomcxDBLabel;
	TcxDBLabel *ArtNomcxDBLabel;
	TcxDBLabel *BarCodecxDBLabel;
	TLabel *Label10;
	TcxDBDateEdit *IamcxDBDateEdit;
	TLabel *Label11;
	TcxDBTextEdit *LocationcxDBTextEdit;
	TcxDBTextEdit *RepairCodecxDBTextEdit;
	TLabel *Label13;
	TLabel *Label14;
	TcxDBTextEdit *Art2cxDBTextEdit;
	TLabel *Label15;
	TcxDBMemo *Angl_NamecxDBMemo;
	TLabel *Label16;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall NameNomKeyPress(TObject *Sender, char &Key);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxButtonPriceClick(TObject *Sender);
	void __fastcall cxButtonEdClick(TObject *Sender);
	void __fastcall NameBasEdPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall CodecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ArtcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ToolButtonAddPriceClick(TObject *Sender);
	void __fastcall ToolButtonDeletePriceClick(TObject *Sender);
	void __fastcall cxButtonEditBasEdClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall KrNamecxDBTextEditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall NameNomcxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall FNamecxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall NameNomcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);







private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму
		enum {NO, VR_ViborNom, VR_ViborSpisokEd,VR_ViborBasEd,VR_ViborSpisokPrice} ViborRekv;

		IFormaSpiskaSprProducerEd * FormaSpiskaSprEd;
		IFormaSpiskaSprProducerPrice * FormaSpiskaSprPrice;

		IDMSprProducerPrice * DMPrice;


		//редактирование базовой единицы
		IFormaElementaSprProducerEd * FormaElementaSprEd;
		void EditBasEd(void);
		void __fastcall EndEditBasEd(void);

		//выбор номенклатуры
		IFormaSpiskaSprNom * FormaSpiskaSprNom;
		void ViborNom(void);
		void __fastcall EndViborNom(void);

public:		// User declarations
		__fastcall TFormaElementaSprProducerNom(TComponent* Owner);

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
        IDMSprProducerNom * DM;

		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме

		__int64 IdProducerTypePrice;

		void UpdateForm(void);

		__int64 IdGrpNom;
		UnicodeString NameGrpNom;
		__int64 IdProducer;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprProducerNom *FormaElementaSprProducerNom;
//---------------------------------------------------------------------------
#endif
