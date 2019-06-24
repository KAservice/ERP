//---------------------------------------------------------------------------

#ifndef UFormaElementaSprNomH
#define UFormaElementaSprNomH
//---------------------------------------------------------------------------
#include "IFormaSpiskaSprEd.h"
#include "IFormaSpiskaSprPart.h"
#include "IFormaSpiskaSprSostProd.h"
#include "IFormaSpiskaSprPrice.h"
#include "IFormaSpiskaSprNachisl.h"
#include "IFormaSpiskaSprMod.h"
#include "IFormaSpiskaSprMPrig.h"
#include "IFormaSpiskaSprNomRest.h"
#include "IFormaSpiskaSprSezKF.h"
#include "UDM.h"
#include "IDMSprNom.h"
#include "IFormaSpiskaSprVidNom.h"
#include "IFormaSpiskaSprImportNom.h"
#include "IFormaElementaSprEd.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprPriceSchedule.h"
#include "IFormaSpiskaSprBrand.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprCountry.h"
#include "IDMSprEd.h"
#include "IDMSprPrice.h"
#include "IFormaSpiskaSprOKEI.h"
#include "IDMFibConnection.h"

#include "IFormaSpiskaSprNomImage.h"
#include "IFormaSpiskaSprNomPropertiesValue.h"
#include "IFormaSpiskaSprNomAnalog.h"
#include "IkasFormSpr.h"
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
class TFormaElementaSprNom : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TLabel *Label6;
	TLabel *Label19;
	TLabel *Label20;
	TcxDBCalcEdit *MinOstcxDBCalcEdit;
	TcxLabel *cxLabel1;
	TLabel *Label21;
	TLabel *Label18;
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
	TcxDBMemo *DescrcxDBMemo;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TcxDBButtonEdit *NameCountrycxDBButtonEdit;
	TcxDBTextEdit *GTDcxDBTextEdit;
	TcxButton *cxButtonPrice;
	TcxButton *cxButtonEd;
	TcxButton *cxButtonPart;
	TcxButton *cxButtonMod;
	TcxButton *cxButtonProd;
	TcxButton *cxButtonSezKF;
	TcxDBButtonEdit *VidNomcxDBButtonEdit;
	TcxDBCalcEdit *Skidka1cxDBCalcEdit;
	TcxDBCalcEdit *Skidka2cxDBCalcEdit;
	TcxDBCalcEdit *Skidka3cxDBCalcEdit;
	TLabel *Label22;
	TLabel *Label23;
	TLabel *Label24;
	TLabel *Label25;
	TcxDBCalcEdit *SrokGodncxDBCalcEdit;
	TLabel *Label26;
	TLabel *Label27;
	TcxButton *cxButtonOpenFormSpiskaSprImportNom;
	TcxDBImageComboBox *NDScxDBImageComboBox;
	TcxDBImageComboBox *TNomcxDBImageComboBox;
	TcxDBImageComboBox *TypeSrokaGodncxDBImageComboBox;
	TGroupBox *GroupBoxFisEd;
	TGroupBox *GroupBoxOsnEd;
	TGroupBox *GroupBoxBasEd;
	TcxDBLabel *NameBasEdcxDBLabel;
	TcxDBLabel *CodeBasEdcxDBLabel;
	TcxLabel *cxLabel2;
	TcxDBLabel *BarCodeBasEdcxDBLabel;
	TcxLabel *cxLabel3;
	TcxLabel *cxLabel4;
	TcxDBLabel *KFBasEdcxDBLabel;
	TcxDBLabel *KF2BasEdcxDBLabel;
	TcxDBLabel *CodeOsnEdcxDBLabel;
	TcxLabel *cxLabel5;
	TcxDBLabel *BarCodeOsnEdcxDBLabel;
	TcxLabel *cxLabel6;
	TcxDBLabel *KF2OsnEdcxDBLabel;
	TcxDBLabel *KFOsnEdcxDBLabel;
	TcxLabel *cxLabel7;
	TcxDBLabel *CodeFisEdcxDBLabel;
	TcxLabel *cxLabel8;
	TcxDBLabel *BarCodeFisEdcxDBLabel;
	TcxLabel *cxLabel9;
	TcxDBLabel *KF2FisEdcxDBLabel;
	TcxDBLabel *KFFisEdcxDBLabel;
	TcxLabel *cxLabel10;
	TcxButton *cxButtonEditBasEd;
	TcxButton *cxButtonAddOsnEd;
	TcxButton *cxButtonEditOsnEd;
	TcxButton *cxButtonAddFisEd;
	TcxButton *cxButtonEditFisEd;
	TcxDBDateEdit *GodenDocxDBDateEdit;
	TcxLabel *cxLabel11;
	TcxDBButtonEdit *SuppliercxDBButtonEdit;
	TcxDBButtonEdit *ProducercxDBButtonEdit;
	TcxLabel *cxLabel12;
	TcxLabel *cxLabel13;
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
	TcxGridDBColumn *cxGrid1DBTableView1FL_CHANGE_PRICE;
	TcxGridDBColumn *cxGrid1DBTableView1NAMETPRICE;
	TcxGridDBColumn *cxGrid1DBTableView1ZNACH_PRICE;
	TcxGridLevel *cxGrid1Level1;
	TcxDBCalcEdit *PogrcxDBCalcEdit;
	TcxLabel *cxLabel15;
	TcxButton *cxButtonpriceSchedule;
	TcxDBSpinEdit *WarrantycxDBSpinEdit;
	TcxDBCheckBox *TransportcxDBCheckBox;
	TcxDBCheckBox *CreditcxDBCheckBox;
	TcxLabel *cxLabel16;
	TcxDBButtonEdit *NameBrandcxDBButtonEdit;
	TcxLabel *cxLabel17;
	TcxGridDBColumn *cxGrid1DBTableView1NameEd;
	TcxDBLookupComboBox *OsnEdcxDBLookupComboBox;
	TcxDBLookupComboBox *FisEdcxDBLookupComboBox;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
	TLabel *NameGrpLabel;
	TcxDBCheckBox *cxDBCheckBoxAddInSprOborud;
	TcxDBCheckBox *FlDvRegcxDBCheckBox;
	TcxButton *cxButtonOpenSprNomImage;
	TcxButton *cxButtonOpenSprNomProperties;
	TcxButton *cxButtonNachisl;
	TcxButton *cxButtonAnalog;
	TcxTabSheet *cxTabSheet3;
	TcxDBButtonEdit *cxDBButtonEditNAME_SDEPARTMENT;
	TcxLabel *cxLabel18;
	TcxLabel *cxLabel19;
	TcxDBButtonEdit *cxDBButtonEditNAME_SPROPNABOR;
	TcxLabel *cxLabel20;
	TcxDBButtonEdit *cxDBButtonEditNAME_SVIDIMAGE_NABOR;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall NameNomKeyPress(TObject *Sender, char &Key);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxDBButtonEdit1PropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameCountrycxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonPriceClick(TObject *Sender);
	void __fastcall cxButtonEdClick(TObject *Sender);
	void __fastcall cxButtonPartClick(TObject *Sender);
	void __fastcall cxButtonModClick(TObject *Sender);
	void __fastcall cxButtonProdClick(TObject *Sender);
	void __fastcall cxButtonSezKFClick(TObject *Sender);
	void __fastcall StNDScxDBCalcEditKeyPress(TObject *Sender, char &Key);
	void __fastcall MinOstcxDBCalcEditKeyPress(TObject *Sender, char &Key);
	void __fastcall NameBasEdPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall CodecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ArtcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall Price2EditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall VidNomcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonOpenFormSpiskaSprImportNomClick(TObject *Sender);
	void __fastcall ToolButtonAddPriceClick(TObject *Sender);
	void __fastcall ToolButtonDeletePriceClick(TObject *Sender);
	void __fastcall OsnEdcxDBLookupComboBoxPropertiesChange(TObject *Sender);
	void __fastcall FisEdcxDBLookupComboBoxPropertiesChange(TObject *Sender);
	void __fastcall cxButtonEditBasEdClick(TObject *Sender);
	void __fastcall cxButtonAddOsnEdClick(TObject *Sender);
	void __fastcall cxButtonEditOsnEdClick(TObject *Sender);
	void __fastcall cxButtonAddFisEdClick(TObject *Sender);
	void __fastcall cxButtonEditFisEdClick(TObject *Sender);
	void __fastcall ProducercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall SuppliercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionSetMainTabSheetExecute(TObject *Sender);
	void __fastcall ActionSetAdditionallyTabSheetExecute(TObject *Sender);
	void __fastcall PogrcxDBCalcEditKeyPress(TObject *Sender, char &Key);
	void __fastcall cxButtonpriceScheduleClick(TObject *Sender);
	void __fastcall NameBrandcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall KrNamecxDBTextEditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall GTDcxDBTextEditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall NameNomcxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall FNamecxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cxButtonOpenSprNomImageClick(TObject *Sender);
	void __fastcall cxButtonOpenSprNomPropertiesClick(TObject *Sender);
	void __fastcall cxButtonNachislClick(TObject *Sender);
	void __fastcall cxButtonAnalogClick(TObject *Sender);
	void __fastcall cxDBButtonEditNAME_SDEPARTMENTPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);






private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

		IFormaSpiskaSprEd * FormaSpiskaSprEd;
		IFormaSpiskaSprPart * FormaSpiskaSprPart;
		IFormaSpiskaSprSostProd *SostavProd;
		IFormaSpiskaSprPrice * FormaSpiskaSprPrice;
		IFormaSpiskaSprNachisl * FormaSpiskaSprNachisl;
		IFormaSpiskaSprMod *FormaSpiskaSprMod;
		IFormaSpiskaSprNomRest *FormaSpiskaSprNomRest;
		IFormaSpiskaSprSezKF * FormaSpiskaSprSezKF;
		IFormaSpiskaSprImportNom * FormaSpiskaSprImportNom;

		IFormaSpiskaSprFirm * FormaSpiskaSprFirm;
		IFormaSpiskaSprCountry * FormaSpiskaSprCountry;
		IFormaSpiskaSprOKEI *FormaSpiskaSprOKEI;
		void OpenFormSpiskaSprOKEI(void);

		IDMSprPrice * DMPrice;

		void OpenFormSpiskaSprNomRest(void);
		IFormaSpiskaSprVidNom  * FormaSpiskaSprVidNom;
		void OpenFormaSpiskaSprVidNom(void);
		void __fastcall EndViborVidNom(void);


		//редактирование базовой единицы
		IFormaElementaSprEd * FormaElementaSprEd;
		void EditBasEd(void);
		void __fastcall EndEditBasEd(void);

		//редактирование основной единицы
		void NewOsnEd(void);
		void EditOsnEd(void);
		void __fastcall EndEditOsnEd(void);

		//редактирование физической единицы
		void NewFisEd(void);
		void EditFisEd(void);
		void __fastcall EndEditFisEd(void);


		//редактирование Поставщика и производителя
		IFormaSpiskaSprKlient * FormaSpiskaSprKlient;
		void ViborSupplier(void);
		void ViborProducer(void);
		void __fastcall EndViborSupplier(void);
		void __fastcall EndViborProducer(void);

		IFormaSpiskaSprPriceSchedule * SpisokSprPriceSchedule;
		void EditPriceSchedule(void);
		void __fastcall EndEditPriceSchedule(void);

		//Бренд
		IFormaSpiskaSprBrand * SpisokBrand;
		void ViborBrand(void);
		void __fastcall EndViborBrand(void);


		IFormaSpiskaSprNomImage * FormaSpiskaSprNomImage;
		IFormaSpiskaSprNomPropertiesValue * FormaSpiskaSprNomPropertiesValue;


		//Аналоги
		IFormaSpiskaSprNomAnalog * FormaSpiskaSprNomAnalog;
		void ViborAnalog(void);
		void __fastcall EndViborAnalog(void);


		IkasFormSpr * kasFormSpr;
		void ViborDepartment(void);
		void EndViborDepartment(void);


public:		// User declarations
		__fastcall TFormaElementaSprNom(TComponent* Owner);

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
        IDMSprNom * DM;

		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме

		__int64 IdTypePrice;
		__int64 IdFirm;

		void UpdateForm(void);

		__int64 IdGrpNom;
		UnicodeString NameGrpNom;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprNom *FormaElementaSprNom;
//---------------------------------------------------------------------------
#endif
