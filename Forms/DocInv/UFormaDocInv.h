//---------------------------------------------------------------------------

#ifndef UFormaDocInvH
#define UFormaDocInvH
//---------------------------------------------------------------------------
//-----------------------------------------------------------------------
#include "IDMFibConnection.h"

#include "IFormaSpiskaSprEd.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprSklad.h"
#include "IDMDocInv.h"
#include "IFormaSpiskaSprTypePrice.h"
#include "IDMSprPrice.h"
#include "IDMSprTypePrice.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IFormaSpiskaSprInv.h"
#include "USheetEditor.h"
#include "IDMTableExtPrintForm.h"
//--------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <Grids.hpp>
#include <IBCustomDataSet.hpp>
#include <IBQuery.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <IBDatabase.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
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
#include "cxContainer.hpp"
#include "cxDBEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxCalendar.hpp"
#include "cxLabel.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"


//---------------------------------------------------------------------------
class TFormaDocInv : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TToolBar *ToolBar2;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonInsert;
        TToolButton *ToolButtonDelete;
        TLabel *Label5;
        TLabel *Label6;
        TDBText *NameUserDBText;
        TToolButton *ToolButtonOstatki;
        TToolButton *ToolButton2;
        TToolButton *ToolButtonCreateDocSpis;
        TToolButton *ToolButtonCreateDocOstNom;
        TLabel *ProsmotrLabel;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TToolButton *AddAllTovarToolButton;
        TToolButton *AddOstatkiToolButton;
        TLabel *Label4;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TLabel *Label8;
	TToolButton *ToolButtonAddDataRev;
	TLabel *Label9;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEGN;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1CODENOM;
	TcxGridDBColumn *cxGrid1DBTableView1KF_INVT;
	TcxGridDBColumn *cxGrid1DBTableView1KOLUCH_INVT;
	TcxGridDBColumn *cxGrid1DBTableView1KOLFAKT_INVT;
	TcxGridDBColumn *cxGrid1DBTableView1PRICE_INVT;
	TcxGridDBColumn *cxGrid1DBTableView1SUMF_INVT;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TcxDBButtonEdit *NameSkladcxDBButtonEdit;
	TcxDBTextEdit *PrimcxDBTextEdit;
	TcxComboBox *TypeInvComboBox;
	TcxDBButtonEdit *NameInvcxDBButtonEdit;
	TcxDBTextEdit *NumDoccxDBTextEdit;
	TcxDBDateEdit *PosDoccxDBDateEdit;
	TcxDBButtonEdit *NameInfcxDBButtonEdit;
	TcxLabel *cxLabel1;
	TcxButton *cxButtonPoGrp;
	TcxButton *cxButtonPrintFaktOst;
	TcxButton *cxButtonPrint;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxComboBox *TypePriceComboBox;
	TAction *ActionInsertRecord;
	TAction *ActionDeleteRecord;
	TcxButton *cxButton1;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
	TAction *ActionPrint;
	TcxDBTextEdit *PrefiksNumcxDBTextEdit;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonVibFirmClick(TObject *Sender);
        void __fastcall AddNewStringClick(TObject *Sender);
        void __fastcall DeleteStringClick(TObject *Sender);
        void __fastcall ToolButtonOstatkiClick(TObject *Sender);
        void __fastcall ToolButtonCreateDocSpisClick(TObject *Sender);
        void __fastcall ToolButtonCreateDocOstNomClick(TObject *Sender);
        void __fastcall AddAllTovarToolButtonClick(TObject *Sender);
        void __fastcall AddOstatkiToolButtonClick(TObject *Sender);
        void __fastcall VibGrpComboBoxChange(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ToolButtonAddDataRevClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall NamecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxDBButtonEdit1PropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall TypeInvcxComboBoxPropertiesChange(TObject *Sender);
	void __fastcall NameInvcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameInfcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonPoGrpClick(TObject *Sender);
	void __fastcall cxButtonPrintFaktOstClick(TObject *Sender);
	void __fastcall TypePriceComboBoxPropertiesChange(TObject *Sender);
	void __fastcall NumDoccxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PosDoccxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PrimcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionInsertRecordExecute(TObject *Sender);
	void __fastcall ActionDeleteRecordExecute(TObject *Sender);
	void __fastcall cxButton1Click(TObject *Sender);

			//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionPrintExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);

private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		IkanCallBack * InterfaceCallBackImpl;//интерфейс реализации текущего модуля
											 //для передачи в форму выбора

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму
	//внешние формы и скрипты
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);



int * SpisokGrp;
        void OpenFSSprNom(void);
		void OpenFSSprEd(void);
		IFormaSpiskaSprNom * Nom;

		 enum  {aoNO,aoAddNewString} ActionOperation;
         		enum  {ER_NoRekv,Tovar,Edinica,FirmaRekvisit,SkladRekvisit, ViborTypePrice,
		ViborInv, ViborInfBase, NO} EditRekvisit;

		IDMSprPrice* DMSprPrice;
		IDMSprTypePrice *DMSprTypePrice;

		IFormaSpiskaSprFirm * Firma;
		IFormaSpiskaSprSklad * Sklad;
		void  OpenFormSpiskaSprFirm(void);
		void  OpenFormSpiskaSprSklad(void);

		void OpenFormSpiskaSprInfBase(void);
		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;

		IFormaSpiskaSprInv  * FormaSpiskaSprInv;
		void OpenFormSpiskaSprSprInv(void);



		void OpenPrintForm(void) ;
		void OutputString(TSheetEditor *prForm);
		void OutputZagolovokReport(TSheetEditor *prForm);
		void OutputPodavalReport(TSheetEditor *prForm);

		void OpenPrintFormPrice(void) ;
		void OutputStringPrice(TSheetEditor *prForm);
		void OutputZagolovokReportPrice(TSheetEditor *prForm);
		void OutputPodavalReportPrice(TSheetEditor *prForm);


		void OpenPrintFormPoGrp(void) ;
        void OutputStringReportPoGrp(TSheetEditor *prForm);
        void OutputStringGroupReportPoGrp(TSheetEditor *prForm);
        int numRow;
        int numCol;
		int porNumStr;

        __int64 IdTypePrice;
		double SummaReport;

		void OutputZagolovokReportPoGrpPrice(TSheetEditor *prForm);
		void OpenPrintFormPoGrpPrice(void) ;
		void OutputStringReportPoGrpPrice(TSheetEditor *prForm);
		void OutputStringGroupReportPoGrpPrice(TSheetEditor *prForm);
		void OutputStringItogiGroupReportPoGrpPrice(TSheetEditor *prForm);
		void OutputPodavalReportPoGrpPrice(TSheetEditor *prForm);
		double AllSumNedostacha;
		double AllSumIslishek;
		double AllSumFact;
		double AllSumUch;
		double AllResult;

		int numRowGrp;
		double GrpSumNedostacha;
		double GrpSumIslishek;
		double GrpSumFact;
		double GrpSumUch;
		double GrpResult;

		bool flObrabatChangeTypeInv;
		bool flObrabatChangeTypePrice;

		 __int64 VibTovarId;
		 __int64 VibTovarIdGrp;
public:		// User declarations
		__fastcall TFormaDocInv(TComponent* Owner);

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
		IDMDocInv * DM;
        bool NewElement;  // новый элемент
        bool Prosmotr;    //только просмотр
        bool ObjectSave;
        bool NoEdit;

		void NewDoc(void);
		void OpenDoc(void);
		bool SaveDoc(void);
		bool DvRegDoc(void);
		bool CancelDvDoc(void);


		__int64 IdDoc;           //идентификатор текущей записи

        void UpdateForm(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocInv *FormaDocInv;
//---------------------------------------------------------------------------
#endif
