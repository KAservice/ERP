//---------------------------------------------------------------------------

#ifndef UFormaDocRealRoznForCashierH
#define UFormaDocRealRoznForCashierH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IFormaSpiskaSprProject.h"
#include "UDM.h"
#include "IDMDocRealRozn.h"
#include "IFormaViborSprEd.h"
#include "IFormaViborSprNom.h"
#include "IDMSprTypePrice.h"
#include "USheetEditor.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprDogovor.h"
#include "IDMTableExtPrintForm.h"
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
#include <Buttons.hpp>
#include <Menus.hpp>
#include "cxButtons.hpp"
#include "cxCalendar.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCalc.hpp"
#include "cxButtonEdit.hpp"
#include "cxPC.hpp"
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
#include <ActnList.hpp>
#include "cxLabel.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaDocRealRoznForCashier : public TForm
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
        TDBText *NameBaseDBText;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButtonPrintNakl;
        TLabel *Label3;
        TLabel *Label6;
        TDBText *NameTPriceDBText;
        TLabel *Label4;
        TToolButton *ToolButtonPrintOnFR;
        TToolButton *ToolButtonAddGrafikPlat;
        TLabel *Label5;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBTextEdit *NameFirmcxDBTextEdit;
	TcxDBTextEdit *NameSkladcxDBTextEdit;
	TcxDBTextEdit *NumDoccxDBTextEdit;
	TcxDBDateEdit *PosDoccxDBDateEdit;
	TcxDBTextEdit *PrimcxDBTextEdit;
	TcxDBCalcEdit *FirstSumcxDBCalcEdit;
	TcxDBTextEdit *NameKKMcxDBTextEdit;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TcxDBButtonEdit *NameDogovorcxDBButtonEdit;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1KOL_DREALROZNT;
	TcxGridDBColumn *cxGrid1DBTableView1KF_DREALROZNT;
	TcxGridDBColumn *cxGrid1DBTableView1PRICE_DREALROZNT;
	TcxGridDBColumn *cxGrid1DBTableView1SUM_DREALROZNT;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxGridDBTableView *cxGrid2DBTableView1;
	TcxGridLevel *cxGrid2Level1;
	TcxGrid *cxGrid2;
	TcxGridDBColumn *cxGrid2DBTableView1DO_DREALROZN_PAY;
	TcxGridDBColumn *cxGrid2DBTableView1SUM_DREALROZN_PAY;
	TcxGridDBColumn *cxGrid2DBTableView1RECNO;
	TActionList *ActionList1;
	TAction *OpenHelp;
	TcxDBButtonEdit *NameProjectcxDBButtonEdit;
	TcxLabel *cxLabel3;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
	TAction *ActionDvReg;
	TcxDBTextEdit *PrefiksNumcxDBTextEdit;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonInsertClick(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
        void __fastcall ToolButtonPrintNaklClick(TObject *Sender);
        void __fastcall ToolButtonPrintOnFRClick(TObject *Sender);
        void __fastcall ToolButtonAddGrafikPlatClick(TObject *Sender);
	void __fastcall NameKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameDogovorcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAMEEDPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall OpenHelpExecute(TObject *Sender);
	void __fastcall NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);

private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

		IFormaSpiskaSprKlient * SpisokKlient;
		IFormaSpiskaSprDogovor * FormaSpiskaSprDogovor;
		IFormaViborSprNom *SpisokNom;
		IFormaViborSprEd * SpisokEd;


        void OpenFormSpiskaSprEd(void);
        void OpenFormSpiskaSprNom(void);
        void OpenFormSpiskaSprKlient(void);
        void OpenFormSpiskaSprDogovor(void);



		enum  {ER_NoRekv,ViborTovar,ViborEdinica,ViborKlient, ViborDogovor,ViborProject, NO} EditRekvisit;

		IFormaSpiskaSprProject *SpisokProject;
		void OpenFormSpiskaSprProject(void);
		void __fastcall EndViborProject(void);
        void OpenPrintFormNakl(void);
		void OutputStringNakl(TSheetEditor *prForm);
		void OutputZagolovokReportNakl(TSheetEditor *prForm);
		void OutputPodavalReportNakl(TSheetEditor *prForm);
		int numRow;
		int numCol;
		int porNumStr;

		bool PrintDocOnFR(void);

		enum  {aoNO,aoAddNewString} ActionOperation;
public:		// User declarations
		__fastcall TFormaDocRealRoznForCashier(TComponent* Owner);

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
		IDMDocRealRozn *DM;


        bool Prosmotr;    //только просмотр
        bool NoEdit;
		bool Vibor;       //для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме

		__int64 IdDoc;           //идентификатор текущей записи

        void UpdateForm(void);




};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocRealRoznForCashier *FormaDocRealRoznForCashier;
//---------------------------------------------------------------------------
#endif
