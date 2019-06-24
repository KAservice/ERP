//---------------------------------------------------------------------------

#ifndef UHOT_FormaDocRealH
#define UHOT_FormaDocRealH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "UDM.h"
#include "IHOT_DMDocReal.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprEd.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IDMSprTypePrice.h"
#include "USheetEditor.h"
#include "IFormaSpiskaSprSklad.h"
#include "IHOT_FormaSpiskaSprNF.h"
#include "IHOT_FormaSpiskaSprTypePosel.h"
#include "IHOT_FormaSpiskaSprCatNom.h"
#include "IFormaDocCheck.h"
#include "IDMTableExtPrintForm.h"
#include "IDMSprTypePrice.h"
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
#include <Buttons.hpp>
#include <ActnList.hpp>
#include "cxClasses.hpp"
#include "cxControls.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include "cxButtonEdit.hpp"
#include "cxCalc.hpp"
#include "cxCalendar.hpp"
#include "cxContainer.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxDBLookupComboBox.hpp"
#include "cxGridBandedTableView.hpp"
#include "cxGridDBBandedTableView.hpp"
#include "cxGroupBox.hpp"
#include "cxDBLookupEdit.hpp"
#include "cxLabel.hpp"
#include "cxLookupEdit.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class THOT_FormaDocReal : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TLabel *FSummaCheck;
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label7;
        TToolBar *ToolBar2;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonInsert;
        TToolButton *ToolButtonDelete;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TDBText *SumDocDBText;
        TDBText *DBTextFNameUser;
        TLabel *ProsmotrLabel;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButtonPrintNakl;
        TToolButton *ToolButtonPrintAkt;
	TToolButton *ToolButtonPrintSF;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1TUSL_HOT_DREALT;
	TcxGridDBColumn *cxGrid1DBTableView1KOL_HOT_DREALT;
	TcxGridDBColumn *cxGrid1DBTableView1KF_HOT_DREALT;
	TcxGridDBColumn *cxGrid1DBTableView1PRICE_HOT_DREALT;
	TcxGridDBColumn *cxGrid1DBTableView1SUM_HOT_DREALT;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxDBButtonEdit *NameInfBasecxDBButtonEdit;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TcxDBTextEdit *NumberDoccxDBTextEdit;
	TcxDBDateEdit *PosDoccxDBDateEdit;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TcxDBTextEdit *PrimcxDBTextEdit;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxGridDBColumn *cxGrid1DBTableView1VIBORTYPEPRICE;
	TcxButton *cxButton1;
	TcxButton *cxButton2;
	TcxButton *cxButton3;
	TcxDBButtonEdit *NameSkladcxDBButtonEdit;
	TLabel *Label4;
	TcxGridDBBandedTableView *cxGrid1DBBandedTableView1;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1TUSL_HOT_DREALT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1KOL_HOT_DREALT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1KF_HOT_DREALT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1PRICE_HOT_DREALT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1SUM_HOT_DREALT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAMENOM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAMEED;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1RECNO;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1VIBORTYPEPRICE;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1POSNACH_HOT_DREALT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1POSCON_HOT_DREALT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAME_HOT_SNF;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAME_HOT_SCATNOM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAME_HOT_STYPEPOS;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAMEKLIENT;
	TcxGroupBox *cxGroupBox1;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label8;
	TLabel *Label9;
	TcxDBTextEdit *NameKKMcxDBTextEdit;
	TcxDBTextEdit *ZavNumbercxDBTextEdit;
	TcxDBTextEdit *RegNumbercxDBTextEdit;
	TcxDBTextEdit *NumberKLcxDBTextEdit;
	TcxDBTextEdit *NumCheckcxDBTextEdit;
	TToolButton *ToolButtonPrintSFNoDopUslug;
	TToolButton *ToolButtonPrintOneGuest;
	TToolButton *ToolButtonPrintSFOneGuest;
	TAction *ActionAddString;
	TAction *ActionDeleteString;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TcxDBLookupComboBox *TypePricecxDBLookupComboBox;
	TcxLabel *cxLabel2;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonPrintNaklClick(TObject *Sender);
        void __fastcall ToolButtonPrintAktClick(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall NameKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButton1Click(TObject *Sender);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxButton3Click(TObject *Sender);
	void __fastcall NameSkladcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1NAMEEDPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1NAME_HOT_SNFPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1NAME_HOT_SCATNOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1NAMEKLIENTPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1NAME_HOT_STYPEPOSPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall ToolButtonPrintSFClick(TObject *Sender);
	void __fastcall ToolButtonPrintSFNoDopUslugClick(TObject *Sender);
	void __fastcall ToolButtonPrintOneGuestClick(TObject *Sender);
	void __fastcall ToolButtonPrintSFOneGuestClick(TObject *Sender);
	void __fastcall NumberDoccxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PosDoccxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PrimcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall NameKKMcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ZavNumbercxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall RegNumbercxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall NumberKLcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall NumCheckcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionAddStringExecute(TObject *Sender);
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


		enum  { aoNO,aoAddNewString} ActionOperation;


		//выбор фирмы
		IFormaSpiskaSprFirm * FormaSpiskaSprFirm;
		void ViborFirm(void);
		void __fastcall EndViborFirm(void);

		//выбор информационной базы
		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
		void ViborInfBase(void);
		void __fastcall EndViborInfBase(void);

		//выбор склада
		IFormaSpiskaSprSklad * FormaSpiskaSprSklad;
		void ViborSklad(void);
		void __fastcall EndViborSklad(void);


		IFormaSpiskaSprKlient * FormaSpiskaSprKlient;

		//выбор плательщика
		void ViborPlat(void);
		void __fastcall EndViborPlat(void);
		//выбор гостя
		void ViborGuest(void);
		void __fastcall EndViborGuest(void);

		//выбор номенклатуры
		IFormaSpiskaSprNom * FormaSpiskaSprNom;
		void ViborNom(void);
		void __fastcall EndViborNom(void);

		//выбор единицы измерения
		IFormaSpiskaSprEd * FormaSpiskaSprEd;
		void ViborEd(void);
		void __fastcall EndViborEd(void);

		//выбор номера
		IHOT_FormaSpiskaSprNF * HOT_FormaSpiskaSprNF;
		void ViborNomer(void);
		void __fastcall EndViborNomer(void);

		//выбор типа поселения
		IHOT_FormaSpiskaSprTypePosel * HOT_FormaSpiskaSprTypePosel;
		void ViborTypePosel(void);
		void __fastcall EndViborTypePosel(void);

		//выбор категории
		IHOT_FormaSpiskaSprCatNom * HOT_FormaSpiskaSprCatNom;
		void ViborCatNom(void);
		void __fastcall EndViborCatNom(void);

		enum {ER_NoRekv,ER_Firm,ER_InfBase,ER_Sklad,
		ER_Plat,ER_Guest,ER_Nomer,ER_Cat,ER_TypePos,
		ER_Nomenkl,ER_Ed,
		ER_DocCheck} EditRekvisit;

		bool CreateDocRealRozn(void);
		bool CreateDocReal(void);


		void OpenPrintFormSF(void);
		void OutputStringSF(TSheetEditor *prForm,
										AnsiString por_number,
										AnsiString name_nom,
										AnsiString name_ed,
										AnsiString kol,
										AnsiString price_bes_nds,
										AnsiString sum_bes_nds,
										AnsiString akciz,
										AnsiString stavka_nds,
										AnsiString sum_nds,
										AnsiString sum_all,
										AnsiString country,
										AnsiString gtd) ;
		void OutputZagolovokSF(TSheetEditor *prForm);
		void OutputPodavalSF(TSheetEditor *prForm);
		double SumNDS;

		void OpenPrintFormSFPoGuest(void);
		void OpenPrintFormSFPoOneGuest(void);

		IDMSprTypePrice * DMSprTypePrice;

		int NumStrOsnUslugi;
		double KolOsnUslug;
		double SummaOsnUslug;
		bool OutputDopUslug;
		int KolStrokDopUslug;

		void OpenPrintFormSchet(void);
		void OutputZagolovokReportSchet(TSheetEditor *prForm);
		void OutputPodavalReportSchet(TSheetEditor *prForm);

		void OpenPrintFormSchetPoGuest(void);
		void OpenPrintFormSchetPoOneGuest(void);
		void OutputStringSchet(TSheetEditor *prForm,
													AnsiString por_number,
													AnsiString pos_nach,
													AnsiString pos_con,
													AnsiString tarif,
													AnsiString nomer,
													AnsiString guest,
													AnsiString name_nom,
													AnsiString kol,
													AnsiString name_ed,
													AnsiString kf_ed,
													AnsiString price,
													AnsiString summa) ;

		int numRow;
		int numCol;
		int porNumStr;

		int NumPage;

		IFormaDocCheck * FormaDocCheck;
		bool CreateDocCheckKKM(void);
		void __fastcall EndCreateDocCheck(void);
public:		// User declarations
		__fastcall THOT_FormaDocReal(TComponent* Owner);

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
		IHOT_DMDocReal *DM;

		bool Prosmotr;    //только просмотр
		bool NoEdit;
		__int64 IdDoc;           //идентификатор текущей записи
		void UpdateForm(void);





};
//---------------------------------------------------------------------------
extern PACKAGE THOT_FormaDocReal *HOT_FormaDocReal;
//---------------------------------------------------------------------------
#endif
