//---------------------------------------------------------------------------

#ifndef UFormaDocRealH
#define UFormaDocRealH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IDMSprTypePrice.h"
#include "USheetEditor.h"
#include "IFormaSpiskaSprBankSchet.h"
#include "IFormaRunExternalModule.h"
#include "IDMDocReal.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprEd.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IDMTableExtPrintForm.h"
#include "IFormaSpiskaSprProject.h"
#include "IFormaSpiskaSprBusinessOper.h"
#include "IFormaSpiskaSprRaschSchet.h"
//------------------------------------------------------------------------------
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
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxContainer.hpp"
#include "cxDBEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxCalendar.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaDocReal : public TForm
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
        TDBText *DBTextFNameUser;
        TLabel *ProsmotrLabel;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TLabel *Label3;
        TLabel *Label4;
        TToolButton *ToolButtonPrintNakl;
        TToolButton *ToolButtonPrintAkt;
        TToolButton *ToolButtonPrintTorg12;
        TLabel *Label5;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1KOLREAT;
	TcxGridDBColumn *cxGrid1DBTableView1KFREAT;
	TcxGridDBColumn *cxGrid1DBTableView1PRICEREAT;
	TcxGridDBColumn *cxGrid1DBTableView1SUMREAT;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxButton *cxButtonCreateSF;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBTextEdit *PrimcxDBTextEdit;
	TcxDBButtonEdit *NameGrPolcxDBButtonEdit;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TcxComboBox *TypePriceComboBox;
	TcxDBTextEdit *NumDoccxDBTextEdit;
	TcxDBDateEdit *PosDoccxDBDateEdit;
	TcxDBButtonEdit *NameSkladcxDBButtonEdit;
	TcxDBButtonEdit *NameBSchetcxDBButtonEdit;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TcxDBButtonEdit *NameInfBasecxDBButtonEdit;
	TcxLabel *cxLabel1;
	TAction *ActionAddString;
	TAction *ActionDeleteString;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
	TcxLabel *cxLabel9;
	TcxDBButtonEdit *NameBusinessOpercxDBButtonEdit;
	TcxDBButtonEdit *NameProjectcxDBButtonEdit;
	TcxLabel *cxLabel3;
	TcxDBButtonEdit *NameRaschScetKlientcxDBButtonEdit;
	TcxDBButtonEdit *NameRaschSchetGrpolcxDBButtonEdit;
	TLabel *Label6;
	TLabel *Label8;
	TcxDBTextEdit *PrefiksNumcxDBTextEdit;
	TcxGridDBColumn *cxGrid1DBTableView1ARTNOM;
	TcxGridDBColumn *cxGrid1DBTableView1CODENOM;
	TcxGridDBColumn *cxGrid1DBTableView1SHED;
	TToolButton *ToolButtonCreateOtchetPost;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonPrintNaklClick(TObject *Sender);
        void __fastcall ToolButtonPrintAktClick(TObject *Sender);
        void __fastcall ToolButtonPrintTorg12Click(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAMEEDPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonCreateSFClick(TObject *Sender);
	void __fastcall NameGrPolcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxDBButtonEdit1PropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall TypePriceComboBoxPropertiesChange(TObject *Sender);
	void __fastcall NameSkladcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameBSchetcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameInfBasecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionAddStringExecute(TObject *Sender);
	void __fastcall ActionDeleteStringExecute(TObject *Sender);
	void __fastcall NumDoccxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PosDoccxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PrimcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);

		  			//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);
	void __fastcall NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameRaschScetKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameRaschSchetGrpolcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButtonCreateOtchetPostClick(TObject *Sender);
private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

	//внешние формы и скрипты
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);


		IFormaSpiskaSprFirm *SpisokFirm;
		IFormaSpiskaSprSklad * SpisokSklad;
		IFormaSpiskaSprKlient * SpisokKlient;
		IFormaSpiskaSprNom *SpisokNom;
		IFormaSpiskaSprEd * SpisokEd;

        void OpenFormSpiskaSprEd(void);
        void OpenFormSpiskaSprNom(void);
        void OpenFormSpiskaSprFirm(void);
        void OpenFormSpiskaSprSklad(void);
        void OpenFormSpiskaSprKlient(void);
        void OpenFormSpiskaSprGrPol(void);

		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
        void OpenFormSpiskaSprInfBase(void);

		IFormaSpiskaSprBankSchet * FormSpiskaSprBSchet;
        void OpenFormSpiskaSprBSchet(void);

		 enum  {aoNO,aoAddNewString} ActionOperation;
		IDMSprTypePrice *DMSprTypePrice;

        void OpenPrintFormNakl(void);
        void OutputStringNakl(TSheetEditor *prForm);
		void OutputZagolovokReportNakl(TSheetEditor *prForm);
        void OutputPodavalReportNakl(TSheetEditor *prForm);
        int numRow;
		int numCol;
        int porNumStr;

		void OpenPrintFormAkt(void);
        void OutputStringAkt(TSheetEditor *prForm);
        void OutputZagolovokReportAkt(TSheetEditor *prForm);
		void OutputZagolovokReportAktKompl(TSheetEditor *prForm);
        void OutputPodavalReportAkt(TSheetEditor *prForm);

		void OpenPrintFormTORG12(void);
        void OutputShapkaReportTORG12(TSheetEditor *prForm);
        void OutputZagolovokPageTORG12(TSheetEditor *prForm);
		void OutputStringTORG12(TSheetEditor *prForm);
        void OutputItogiPageTORG12(TSheetEditor *prForm);
		void OutputVsegoTORG12(TSheetEditor *prForm);
		void OutputPodavalReportTORG12(TSheetEditor *prForm);


		int NumPage;

		int KolStr;

		int HeightPage;
		int TecHeight;
		int HeightPodval;
		int HeightString;


		double ItogoKolNaPage;
		double ItogoSumNaPage;
		double ItogoNDSNaPage;
		double ItogoSumSNDSNaPage;

        double ItigoKol;
		double ItogoSum;
        double ItogoNDS;
		double ItogoSumSNDS;

        AnsiString FioDir;
		AnsiString FioBuh;
		int SizeShapka;
		int SizePodval;
		bool flObrabatChangeTypePrice;


	IFormaSpiskaSprBusinessOper *SpisokBusinessOper;
	void OpenFormSpiskaSprBusinessOper(void);
	void __fastcall EndViborBusinessOper(void);

	IFormaSpiskaSprProject *SpisokProject;
	void OpenFormSpiskaSprProject(void);
	void __fastcall EndViborProject(void);


		enum  {ER_NoRekv,ER_InfBase, ER_Firm, ER_BankSchet, ER_Sklad, ER_Klient, ER_GrPol,
					 ER_BusinessOper, ER_Project, ER_Nom,
					  ER_Ed,ER_Part, ER_RaschSchetKlient,ER_RaschSchetGrpol,ER_NO} EditRekvisit;


	   IFormaSpiskaSprRaschSchet  *  FormaSpiskaSprRaschSchet;
		void ViborRaschSchetKlient(void);
		void ViborRaschSchetGrpol(void);
		void EndViborRaschSchetKlient(void);
		void EndViborRaschSchetGrpol(void);


public:		// User declarations
		__fastcall TFormaDocReal(TComponent* Owner);

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

		void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);

		//Текущий интерфейс
		IDMDocReal *DM;

		bool Prosmotr;    //только просмотр
		bool NoEdit;
		bool Vibor;       //для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме
		__int64 IdDoc;           //идентификатор текущей записи

		void UpdateForm(void);




	   

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocReal *FormaDocReal;
//---------------------------------------------------------------------------
#endif
