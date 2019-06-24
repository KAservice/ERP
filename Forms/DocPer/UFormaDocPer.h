//---------------------------------------------------------------------------

#ifndef UFormaDocPerH
#define UFormaDocPerH
//---------------------------------------------------------------------------
#include "IDMTableExtPrintForm.h"
#include "USheetEditor.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IDMDocPer.h"
#include "IDMFibConnection.h"
#include "ISheetEditor.h"
#include "IFormaRunExternalModule.h"

#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprEd.h"
#include "IFormaSpiskaSprNom.h"
#include "IDMFibConnection.h"
#include "IFormaSpiskaSprProject.h"
#include "IFormaSpiskaSprBusinessOper.h"
//--------------------------------------------------------------------------
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
#include <Menus.hpp>
#include <Buttons.hpp>
#include <ActnList.hpp>
#include "IDMSprTypePrice.h"
#include "cxButtonEdit.hpp"
#include "cxCalc.hpp"
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
#include "cxCalendar.hpp"
#include "cxContainer.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxLabel.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "UDM.h"

//---------------------------------------------------------------------------
class TFormaDocPer : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
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
        TDBText *NameUserDBText;
        TLabel *ProsmotrLabel;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TLabel *Label4;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1KOLPERT;
	TcxGridDBColumn *cxGrid1DBTableView1KFPERT;
	TcxGridDBColumn *cxGrid1DBTableView1PRICEPERT;
	TcxGridDBColumn *cxGrid1DBTableView1SUMPERT;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxDBTextEdit *PrimcxDBTextEdit;
	TcxComboBox *RoznTypePriceComboBox;
	TcxDBButtonEdit *NameSkladPolcxDBButtonEdit;
	TcxDBTextEdit *NumDoccxDBTextEdit;
	TcxDBDateEdit *PosDoccxDBDateEdit;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TcxDBButtonEdit *NameInfBasecxDBButtonEdit;
	TcxLabel *cxLabel1;
	TcxDBButtonEdit *NameSkladcxDBButtonEdit;
	TcxButton *cxButtonPrint;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TAction *ActionAddRecord;
	TAction *ActionDeleteRecord;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
	TAction *ActionDvReg;
	TAction *ActionPrint;
	TcxLabel *cxLabel9;
	TcxDBButtonEdit *NameBusinessOpercxDBButtonEdit;
	TcxDBButtonEdit *NameProjectcxDBButtonEdit;
	TcxLabel *cxLabel3;
	TcxGridDBColumn *cxGrid1DBTableView1CODENOM;
	TcxGridDBColumn *cxGrid1DBTableView1ARTNOM;
	TcxGridDBColumn *cxGrid1DBTableView1SHED;
	TcxDBTextEdit *PrefiksNumcxDBTextEdit;
	TcxGridDBColumn *cxGrid1DBTableView1SEB_PRICE_DPERT;
	TcxGridDBColumn *cxGrid1DBTableView1SEB_SUM_DPERT;
	TcxGridDBColumn *cxGrid1DBTableView1NAC_SUM_ED;
	TcxGridDBColumn *cxGrid1DBTableView1NAC_SUM;
	TToolButton *ToolButtonAddSebest;
	TToolButton *ToolButtonAddNomSoSklada;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall AddNewStringClick(TObject *Sender);
        void __fastcall DeleteStringClick(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAMEEDPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall RoznTypePriceComboBoxPropertiesChange(TObject *Sender);
	void __fastcall NameFirmcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameInfBasecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladPolcxDBButtonEditPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall NameSkladcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionAddRecordExecute(TObject *Sender);
	void __fastcall ActionDeleteRecordExecute(TObject *Sender);
	void __fastcall NumDoccxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PosDoccxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PrimcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);
	void __fastcall ActionPrintExecute(TObject *Sender);
	void __fastcall NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButtonAddSebestClick(TObject *Sender);
	void __fastcall ToolButtonAddNomSoSkladaClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAC_SUM_EDPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);

private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

			//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);

		IFormaSpiskaSprFirm *SpisokFirm;
		IFormaSpiskaSprSklad * SpisokSklad;
		IFormaSpiskaSprNom *SpisokNom;
		IFormaSpiskaSprEd * SpisokEd;


        void OpenFormSpiskaSprEd(void);
        void OpenFormSpiskaSprNom(void);
        void OpenFormSpiskaSprFirm(void);
        void OpenFormSpiskaSprSklad(void);
        void OpenFormSpiskaSprSkladPol(void);

		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
        void OpenFormSpiskaSprInfBase(void);


		 enum  {aoNO,aoAddNewString} ActionOperation;
		 enum  {ER_NoRekv,ER_InfBase, ER_Firm, ER_Sklad, ER_SkladPol,
					 ER_BusinessOper, ER_Project, ER_Nom, ER_Ed,ER_NomSoSklada, ER_NO} EditRekvisit;

        void SummaCheck(void);
	//внешние формы и скрипты
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

	 double SumCheck;
	         void OpenPrintForm(void);
		void OutputString(TSheetEditor *prForm);
		void OutputZagolovokReport(TSheetEditor *prForm);
		void OutputPodavalReport(TSheetEditor *prForm);
		int numRow;
		int numCol;
		int porNumStr;
		double RoznSumDoc;

		bool flObrabatChangeTypePrice;
		IDMSprTypePrice *DMSprRoznTypePrice;

	IFormaSpiskaSprBusinessOper *SpisokBusinessOper;
	void OpenFormSpiskaSprBusinessOper(void);
	void __fastcall EndViborBusinessOper(void);

	IFormaSpiskaSprProject *SpisokProject;
	void OpenFormSpiskaSprProject(void);
	void __fastcall EndViborProject(void);


	void ViborNomSoSklada(void);
	void __fastcall EndViborNomSoSklada(void);
public:		// User declarations
		__fastcall TFormaDocPer(TComponent* Owner);

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
         IDMDocPer * DM;

		bool Prosmotr;    //только просмотр
		bool NoEdit;
		bool Vibor;       //для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме
		__int64 IdDoc;           //идентификатор текущей записи




		void UpdateForm(void);
		void CreateDocNaOsnPrihNakl(__int64 id_doc_osn);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocPer *FormaDocPer;
//---------------------------------------------------------------------------
#endif
