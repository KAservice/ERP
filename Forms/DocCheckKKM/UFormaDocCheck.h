//---------------------------------------------------------------------------

#ifndef UFormaDocCheckH
#define UFormaDocCheckH
//---------------------------------------------------------------------------
#include "UDM.h"
#include "UFormaViborFR.h"
#include "USheetEditor.h"
#include "IDMSprTypePrice.h"
#include "IFormaSpiskaSprDiscountCard.h"
#include "IFormaGurAllDoc.h"
#include "IDMDocCheck.h"
#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprEd.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaSpiskaSprKKM.h"
#include "IFormaSpiskaSprDogovor.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IDMTableExtPrintForm.h"
#include "IFormaSpiskaSprBankSchet.h"
#include "IFormaSpiskaSprDiscountCard_1.h"
#include "IFormaSpiskaSprProject.h"
#include "IFormaSpiskaSprBusinessOper.h"
#include "IkasFormSpr.h"
//---------------------------------------------------------------------------
#include "cxButtonEdit.hpp"
#include "cxButtons.hpp"
#include "cxCalc.hpp"
#include "cxCalendar.hpp"
#include "cxClasses.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxDBEdit.hpp"
#include "cxDBLabel.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxImageComboBox.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxMaskEdit.hpp"
#include "cxPC.hpp"
#include "cxStyles.hpp"
#include "cxTextEdit.hpp"
#include <ActnList.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <StdCtrls.hpp>
#include <ToolWin.hpp>


//---------------------------------------------------------------------------
class TFormaDocCheck : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel3;
        TDBText *DBTextFNameUser;
        TLabel *ProsmotrLabel;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1KOLCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1KFCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1PRICECHKT;
	TcxGridDBColumn *cxGrid1DBTableView1SUMCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1SKCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1NADCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxButton *cxButtonPrintCheckFR;
	TcxButton *cxButtonPrint;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TcxDBTextEdit *PrimcxDBTextEdit;
	TLabel *Label7;
	TcxDBButtonEdit *NameKassacxDBButtonEdit;
	TLabel *Label15;
	TLabel *Label6;
	TLabel *Label14;
	TLabel *Label12;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TLabel *Label1;
	TcxDBTextEdit *NumDoccxDBTextEdit;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TcxDBButtonEdit *NameDogcxDBButtonEdit;
	TDBText *IdKlientDBText;
	TLabel *Label17;
	TcxDBDateEdit *PosDoccxDBDateEdit;
	TLabel *Label2;
	TLabel *Label13;
	TcxDBButtonEdit *NameSkladcxDBButtonEdit;
	TcxComboBox *TypePriceComboBox;
	TcxComboBox *Operation;
	TLabel *Label16;
	TcxDBTextEdit *NumCheckcxDBTextEdit;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label19;
	TLabel *Label18;
	TcxDBTextEdit *ModelcxDBTextEdit;
	TcxDBTextEdit *SavNumcxDBTextEdit;
	TcxDBTextEdit *NumKLcxDBTextEdit;
	TcxDBTextEdit *RegNumcxDBTextEdit;
	TLabel *Label3;
	TToolBar *ToolBar2;
	TToolButton *ToolButton1;
	TToolButton *ToolButtonInsert;
	TToolButton *ToolButtonDelete;
	TToolButton *ToolButton2;
	TDBText *NameBaseDBText;
	TToolButton *ToolButton3;
	TButton *ViborBaseButton;
	TLabel *Label20;
	TLabel *Label21;
	TcxDBButtonEdit *NameDCardcxDBButtonEdit;
	TcxLabel *cxLabel2;
	TAction *ActionInsertString;
	TAction *ActionDeleteString;
	TcxDBButtonEdit *DocOsncxDBButtonEdit;
	TLabel *Label22;
	TLabel *ProsmotrTextLabel;
	TcxDBButtonEdit *NameProjectcxDBButtonEdit;
	TcxLabel *cxLabel3;
	TcxGridDBColumn *cxGrid1DBTableView1NDS_DCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1SUMNDS_DCHKT;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TcxDBButtonEdit *NameBSchetcxDBButtonEdit;
	TcxLabel *cxLabel4;
	TcxTabSheet *cxTabSheet3;
	TPanel *Panel1;
	TPanel *Panel5;
	TPanel *Panel6;
	TLabel *Label11;
	TcxDBCalcEdit *NalCHKcxDBCalcEdit;
	TLabel *Label9;
	TcxDBCalcEdit *OplNalcxDBCalcEdit;
	TcxDBCalcEdit *OplPCcxDBCalcEdit;
	TLabel *Label10;
	TLabel *Label8;
	TLabel *Label23;
	TcxDBCalcEdit *OplPlatCardcxDBCalcEdit;
	TcxDBCalcEdit *OplCreditCardcxDBCalcEdit;
	TGroupBox *GroupBox1;
	TToolBar *ToolBar4;
	TToolButton *ToolButton4;
	TToolButton *ToolButtonAddPrice;
	TToolButton *ToolButtonDeletePrice;
	TcxGrid *cxGrid2;
	TcxGridDBTableView *cxGrid2DBTableView1;
	TcxGridDBColumn *cxGrid2DBTableView1NAME_SDISCOUNT_CARD;
	TcxGridDBColumn *cxGrid2DBTableView1SUMPLAT_DCHK_OPL;
	TcxGridDBColumn *cxGrid2DBTableView1SUMCREDIT_DCHK_OPL;
	TcxGridLevel *cxGrid2Level1;
	TcxGridDBColumn *cxGrid2DBTableView1RECNO;
	TPanel *Panel7;
	TcxDBLabel *SdachacxDBLabel;
	TcxLabel *cxLabel1;
	TcxDBLabel *AllOplcxDBLabel;
	TcxLabel *cxLabel7;
	TcxLabel *cxLabel8;
	TcxDBLabel *SumDoccxDBLabel;
	TPanel *Panel8;
	TcxLabel *cxLabel5;
	TcxDBLabel *AllOplPlatCardcxDBLabel;
	TcxLabel *cxLabel6;
	TcxDBLabel *AllOplCreditCardcxDBLabel;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
	TAction *ActionPrint;
	TcxDBButtonEdit *NameBusinessOpercxDBButtonEdit;
	TcxLabel *cxLabel9;
	TcxGridDBColumn *cxGrid1DBTableView1CODENOM;
	TcxGridDBColumn *cxGrid1DBTableView1ARTNOM;
	TcxGridDBColumn *cxGrid1DBTableView1SHED;
	TcxDBTextEdit *PrefiksNumcxDBTextEdit;
	TcxGridDBColumn *cxGrid1DBTableView1NUMOTDKKT_SDEPARTMENT;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SDEPARTMENT;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ViborBaseButtonClick(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAMEEDPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonPrintCheckFRClick(TObject *Sender);
	void __fastcall TypePriceComboBoxPropertiesChange(TObject *Sender);
	void __fastcall OperationPropertiesChange(TObject *Sender);
	void __fastcall NameFirmcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameDogcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameKassacxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameDCardcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NumDoccxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PosDoccxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall OplNalcxDBCalcEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall OplPCcxDBCalcEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall NalCHKcxDBCalcEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PrimcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionInsertStringExecute(TObject *Sender);
	void __fastcall ActionDeleteStringExecute(TObject *Sender);
	void __fastcall DocOsncxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
		  int AButtonIndex);

		//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);

	void __fastcall NameBSchetcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButtonAddPriceClick(TObject *Sender);
	void __fastcall ToolButtonDeletePriceClick(TObject *Sender);
	void __fastcall cxGrid2DBTableView1NAME_SDISCOUNT_CARDPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall ActionPrintExecute(TObject *Sender);
	void __fastcall NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall PrefiksNumcxDBTextEditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall cxGrid1DBTableView1NAME_SDEPARTMENTPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);


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
		IFormaSpiskaSprKKM * SpisokKKM;
		IFormaSpiskaSprDogovor * FormaSpiskaSprDogovor;


        void OpenFormSpiskaSprEd(void);
        void OpenFormSpiskaSprNom(void);
        void OpenFormSpiskaSprFirm(void);
        void OpenFormSpiskaSprSklad(void);
        void OpenFormSpiskaSprKlient(void);
		void OpenFormSpiskaSprKKM(void);
		void OpenFormSpiskaSprDogovor(void);

		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
		void OpenFormSpiskaSprInfBase(void);

		enum  {aoNO,aoAddNewString} ActionOperation;
		void SummaCheck(void);

		IFormaSpiskaSprDiscountCard * FormaSpiskaSprDiscountCard ;
		void ViborDiscountCard(void);
		void __fastcall EndViborDiscountCard(void);

		IFormaSpiskaSprDiscountCard_1 * SprCardOpl;
		void ViborCardOpl(void);
		void __fastcall EndViborCardOpl(void);
		enum  {ER_NoRekv,ActionOperationCardOpl_New, ActionOperationCardOpl_NO} ActionOperationCardOpl;



		IFormaSpiskaSprBankSchet *SpisokBSchet;
		void OpenFormSpiskaSprBSchet(void);
		void __fastcall EndViborBSchet(void);

double SumCheck;
IDMSprTypePrice *DMSprTypePrice;
        void PrintGoodsCheck(void);
		void PrintGoodsCheck_OutputHeadline(TSheetEditor *SE);
		void PrintGoodsCheck_OutputString(TSheetEditor *SE);
		void PrintGoodsCheck_OutputPodval(TSheetEditor *SE);


		int x, y;

		TFormaViborFR *FormaViborFR;
		void PrintCheckFR(void);
		void __fastcall EndViborFR(TObject *Sender);

		bool flNoChangeTypePrice;


		IFormaGurAllDoc * FormaGurAllDoc;
		void ViborDocOsn(void);
		void __fastcall EndViborDocOsn(void);

		IFormaSpiskaSprBusinessOper *SpisokBusinessOper;
		void OpenFormSpiskaSprBusinessOper(void);
		void __fastcall EndViborBusinessOper(void);

		IFormaSpiskaSprProject *SpisokProject;
		void OpenFormSpiskaSprProject(void);
		void __fastcall EndViborProject(void);

		IkasFormSpr * kasFormSpr;
		void ViborDepartment(void);
		void EndViborDepartment(void);


public:		// User declarations
		__fastcall TFormaDocCheck(TComponent* Owner);

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
		IDMDocCheck *DM;
        void UpdateForm(void);




        bool NewElement;  // новый элемент
		bool Prosmotr;    //только просмотр
		__int64 IdDoc;           //идентификатор текущей записи


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocCheck *FormaDocCheck;
//---------------------------------------------------------------------------
#endif
