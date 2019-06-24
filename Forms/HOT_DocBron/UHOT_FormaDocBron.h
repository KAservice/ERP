//---------------------------------------------------------------------------

#ifndef UHOT_FormaDocBronH
#define UHOT_FormaDocBronH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IHOT_DMDocBron.h"
#include "UDM.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IHOT_FormaSpiskaSprNF.h"
#include "IHOT_FormaSpiskaSprSostNom.h"
#include "IHOT_FormaSpiskaSprTypePosel.h"
#include "IHOT_FormaSpiskaSprCatNom.h"
#include "USheetEditor.h"
#include "IDMTableExtPrintForm.h"
#include "IDMSprTypePrice.h"
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
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include "cxDBLookupComboBox.hpp"
#include "cxDBLookupEdit.hpp"
#include "cxLookupEdit.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class THOT_FormaDocBron : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TcxDBButtonEdit *NameInfBasecxDBButtonEdit;
	TcxDBTextEdit *NumbercxDBTextEdit;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TLabel *Label6;
	TcxDBTextEdit *DescrcxDBTextEdit;
	TPanel *Panel2;
	TDBText *DBTextFNameUser;
	TLabel *ProsmotrLabel;
	TcxButton *cxButtonClose;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonSave;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1KOLM_HOT_SOSTNF;
	TcxGridDBColumn *cxGrid1DBTableView1POSNACH_HOT_SOSTNF;
	TcxGridDBColumn *cxGrid1DBTableView1POSCON_HOT_SOSTNF;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_HOT_SNF;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_HOT_SCATNOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_HOT_STYPEPOS;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEKLIENT;
	TcxDBLabel *NameSostcxDBLabel;
	TToolBar *ToolBar2;
	TToolButton *ToolButton1;
	TToolButton *ToolButtonInsert;
	TToolButton *ToolButtonDelete;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TcxDBDateEdit *PosDoccxDBDateEdit;
	TcxButton *cxButtonCreateDocRaschet;
	TcxButton *cxButtonCreateDocRasm;
	TToolButton *ToolButton4;
	TcxButton *cxButtonCreateDocOtmenaBron;
	TAction *ActionAddString;
	TAction *ActionDeleteString;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TcxDBLookupComboBox *TypePricecxDBLookupComboBox;
	TcxLabel *cxLabel1;
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
	void __fastcall cxGrid1DBTableView1NAME_HOT_SNFPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAME_HOT_SCATNOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAME_HOT_STYPEPOSPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAMEKLIENTPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxButtonCreateDocRaschetClick(TObject *Sender);
	void __fastcall cxButtonCreateDocRasmClick(TObject *Sender);
	void __fastcall ToolButton4Click(TObject *Sender);
	void __fastcall cxButtonCreateDocOtmenaBronClick(TObject *Sender);
	void __fastcall ActionAddStringExecute(TObject *Sender);
	void __fastcall ActionDeleteStringExecute(TObject *Sender);
	void __fastcall NumbercxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PosDoccxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall DescrcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
		  TShiftState Shift);

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

		IFormaSpiskaSprKlient * FormaSpiskaSprKlient;

		//выбор плательщика
		void ViborPlat(void);
		void __fastcall EndViborPlat(void);
		//выбор гостя
		void ViborGuest(void);
		void __fastcall EndViborGuest(void);

		//выбор номера
		IHOT_FormaSpiskaSprNF * HOT_FormaSpiskaSprNF;
		void ViborNomer(void);
		void __fastcall EndViborNomer(void);

		//выбор категории
		IHOT_FormaSpiskaSprCatNom * HOT_FormaSpiskaSprCatNom;
		void ViborCat(void);
		void __fastcall EndViborCat(void);

		//выбор типа поселения
		IHOT_FormaSpiskaSprTypePosel * HOT_FormaSpiskaSprTypePosel;
		void ViborTypePosel(void);
		void __fastcall EndViborTypePosel(void);

		//выбор состояния
		IHOT_FormaSpiskaSprSostNom * HOT_FormaSpiskaSprSostNom;
		void ViborSost(void);
		void __fastcall EndViborSost(void);

		enum {ER_NoRekv,ER_Firm,ER_InfBase,ER_Plat,ER_Guest,ER_Nomer,ER_Cat,ER_TypePos,ER_Sost} EditRekvisit;
		int numRow;
		int numCol;
		int KolMest;

		void CreateDocRaschet(void);
		void CreateDocRasm(void);

		void OpenPrintFormPotvBron(void);
		void CreateDocOtmenaBron(void);

		IDMSprTypePrice * DMSprTypePrice;
public:		// User declarations
		__fastcall THOT_FormaDocBron(TComponent* Owner);

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
		IHOT_DMDocBron *DM;

        bool Prosmotr;    //только просмотр
		__int64 IdDoc;           //идентификатор текущей записи



		void UpdateForm(void);



};
//---------------------------------------------------------------------------
extern PACKAGE THOT_FormaDocBron *HOT_FormaDocBron;
//---------------------------------------------------------------------------
#endif
