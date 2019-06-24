//---------------------------------------------------------------------------

#ifndef UHOT_FormaDocRasmH
#define UHOT_FormaDocRasmH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IHOT_DMDocRasm.h"
#include "UDM.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IHOT_FormaSpiskaSprNF.h"
#include "IHOT_FormaSpiskaSprSostNom.h"
#include "IHOT_FormaSpiskaSprTypePosel.h"
#include "IHOT_FormaSpiskaTableSostNF.h"
#include "IHOT_FormaElementaTableSostNF.h"
#include "IHOT_FormaSpiskaSprCelPriesda.h"
#include "IDMTableExtPrintForm.h"
#include "IDMSprTypePrice.h"
#include "IHOT_FormaSpiskaSprCatNom.h"
//---------------------------------------------------------------------------
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
#include <ActnList.hpp>
#include "cxButtonEdit.hpp"
#include "cxCalendar.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCalc.hpp"
#include "cxDBLabel.hpp"
#include "cxLabel.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxPC.hpp"
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridBandedTableView.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBBandedTableView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include "cxDBLookupComboBox.hpp"
#include "cxDBLookupEdit.hpp"
#include "cxLookupEdit.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class THOT_FormaDocRasm : public TForm
{
__published:	// IDE-managed Components
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxDBButtonEdit *NameInfBasecxDBButtonEdit;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label1;
	TcxDBTextEdit *NumbercxDBTextEdit;
	TLabel *Label2;
	TcxDBDateEdit *PosDoccxDBDateEdit;
	TPanel *Panel1;
	TcxButton *cxButtonClose;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonSave;
	TLabel *ProsmotrLabel;
	TDBText *DBTextFNameUser;
	TcxDBButtonEdit *CelPrcxDBButtonEdit;
	TLabel *Label14;
	TcxDBTextEdit *DescrcxDBTextEdit;
	TLabel *Label6;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TLabel *Label5;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBBandedTableView *cxGrid1DBBandedTableView1;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1BR_NAME_HOT_SNF;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1BR_NAME_HOT_SCATNOM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1BR_NAME_HOT_STYPEPOS;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1BR_NAMEGUEST;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1BR_NAME_HOT_SSOSTNOM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1BR_POSNACH_HOT_SOSTNF;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1BR_POSCON_HOT_SOSTNF;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1BR_KOLM_HOT_SOSTNF;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1RASM_NAME_HOT_SNF;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1RASM_NAME_HOT_SCATNOM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1RASM_NAME_HOT_STYPEPOS;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1RASM_NAMEGUEST;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1RASM_NAME_HOT_SSOSTNOM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1RASM_POSNACH_HOT_SOSTNF;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1RASM_POSCON_HOT_SOSTNF;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1RASM_KOLM_HOT_SOSTNF;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1BR2_NAME_HOT_SNF;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1BR2_NAME_HOT_SCATNOM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1BR2_NAME_HOT_STYPEPOS;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1BR2_NAMEGUEST;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1BR2_NAME_HOT_SSOSTNOM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1BR2_POSNACH_HOT_SOSTNF;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1BR2_POSCON_HOT_SOSTNF;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1BR2_KOLM_HOT_SOSTNF;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1BR;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1RASM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1BR2;
	TToolBar *ToolBar2;
	TToolButton *ToolButton1;
	TToolButton *ToolButtonInsert;
	TToolButton *ToolButtonDelete;
	TToolButton *ToolButton2;
	TcxButton *cxButtonCreateDocReal;
	TcxButton *cxButtonPrintAnketa;
	TcxDBTextEdit *OrgcxDBTextEdit;
	TLabel *Label7;
	TcxButton *cxButtonCreateDocViezd;
	TAction *ActionAddString;
	TAction *ActionDeleteString;
	TPanel *Panel5;
	TToolButton *ToolButton3;
	TPopupMenu *PopupMenuExtModule;
	TcxDBLookupComboBox *TypePricecxDBLookupComboBox;
	TcxLabel *cxLabel2;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall NameInfBasecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonViborSostNFClick(TObject *Sender);
	void __fastcall cxGrid1DBBandedTableView1BRPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1RASM_NAME_HOT_SNFPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1BR2_NAME_HOT_SNFPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1RASM_NAME_HOT_SCATNOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1BR2_NAME_HOT_SCATNOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1RASM_NAME_HOT_STYPEPOSPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1RASM_NAME_HOT_SSOSTNOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1RASM_NAMEGUESTPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxButtonCreateDocRealClick(TObject *Sender);
	void __fastcall cxButtonPrintAnketaClick(TObject *Sender);
	void __fastcall CelPrcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonCreateDocViezdClick(TObject *Sender);
	void __fastcall ActionAddStringExecute(TObject *Sender);
	void __fastcall NumbercxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PosDoccxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall OrgcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall DescrcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionDeleteStringExecute(TObject *Sender);


			//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);

private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

	   IDMTableExtPrintForm * DMTableExtPrintForm;
	   void RunExternalModule(__int64 id_module, int type_module);

		//выбор фирмы
		IFormaSpiskaSprFirm * FormaSpiskaSprFirm;
		void ViborFirm(void);
		void __fastcall EndViborFirm(void);

		//выбор информационной базы
		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
		void ViborInfBase(void);
		void __fastcall EndViborInfBase(void);

		//выбор состояния бронирования
		IHOT_FormaSpiskaTableSostNF * HOT_FormaSpiskaTableSostNF;
		void ViborSostBron(void);
		void __fastcall EndViborSostBron(void);



		IFormaSpiskaSprKlient * FormaSpiskaSprKlient;

		//выбор плательщика
		void ViborPlat(void);
		void __fastcall EndViborPlat(void);
		//выбор гостя
		void ViborGuest(void);
		void __fastcall EndViborGuest(void);
		void ViborGuestRasm(void);
		void __fastcall EndViborGuestRasm(void);
		void ViborGuestBr2(void);
		void __fastcall EndViborGuestBr2(void);

		//выбор номера
		IHOT_FormaSpiskaSprNF * HOT_FormaSpiskaSprNF;
		void ViborNomerRasm(void);
		void __fastcall EndViborNomerRasm(void);
		void ViborNomerBr2(void);
		void __fastcall EndViborNomerBr2(void);


		//выбор состояния
		IHOT_FormaSpiskaSprSostNom * HOT_FormaSpiskaSprSostNom;
		void ViborSostRasm(void);
		void __fastcall EndViborSostRasm(void);
		void ViborSostBr2(void);
		void __fastcall EndViborSostBr2(void);

		//выбор типа поселения
		IHOT_FormaSpiskaSprTypePosel * HOT_FormaSpiskaSprTypePosel;
		void ViborTypePoselRasm(void);
		void __fastcall EndViborTypePoselRasm(void);
		void ViborTypePoselBr2(void);
		void __fastcall EndViborTypePoselBr2(void);

		//выбор параметров размещения
		IHOT_FormaElementaTableSostNF * HOT_FormaElementaTableSostNF;
		void ViborParamPosel(void);
		void __fastcall EndViborParamPosel(void);

		//выбор параметров бронирования 2
		void ViborParamBron2(void);
		void __fastcall EndViborParamBron2(void);

		//выбор категории
		IHOT_FormaSpiskaSprCatNom * HOT_FormaSpiskaSprCatNom;
		void ViborCatRasm(void);
		void __fastcall EndViborCatRasm(void);
		void ViborCatBr2(void);
		void __fastcall EndViborCatBr2(void);

		//выбор цели приезда
		IHOT_FormaSpiskaSprCelPriesda * HOT_FormaSpiskaSprCelPriesda;
		void ViborCelPriesda(void);
		void __fastcall EndViborCelPriesda(void);

        int numRow;
		int numCol;

		int KolMest;


		void CreateDocReal(void);
		void CreateDocViesd(void);
		void PrintAnketa(void);

		IDMSprTypePrice * DMSprTypePrice;

		enum {ER_NoRekv,ER_Firm,ER_InfBase,ER_SostBron,ER_Plat,
				ER_Guest,ER_GuestRasm,ER_GuestBr2,
				ER_NomerRasm,ER_NomerBr2,
				ER_SostRasm, ER_SostBr2,
				ER_TypePoselRasm,ER_TypePoselBr2,
				ER_ParamPosel,ER_ParamBron2,
				ER_CatRasm,ER_CatBr2,
				ER_CelPriesda

		  } EditRekvisit;

public:		// User declarations
		__fastcall THOT_FormaDocRasm(TComponent* Owner);

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


		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме


		//Текущий интерфейс
		IHOT_DMDocRasm *DM;


		bool Prosmotr;    //только просмотр
		__int64 IdDoc;           //идентификатор текущей записи



		void UpdateForm(void);




};
//---------------------------------------------------------------------------
extern PACKAGE THOT_FormaDocRasm *HOT_FormaDocRasm;
//---------------------------------------------------------------------------
#endif
