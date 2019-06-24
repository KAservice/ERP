//---------------------------------------------------------------------------

#ifndef UFormaDocVosvratPokForCashierH
#define UFormaDocVosvratPokForCashierH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IFormaViborSprEd.h"
#include "IFormaViborSprNom.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprDogovor.h"
#include "IDMDocVosvratPok.h"
#include "USheetEditor.h"
#include "IDMSprTypePrice.h"


//---------------------------------------------------------------------------
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
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxButtonEdit.hpp"
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
#include "cxContainer.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCalendar.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaDocVosvratPokForCashier : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TLabel *LabelSumma;
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
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TDBText *DBTextFNameUser;
        TLabel *Label7;
        TDBText *SumDocDBText;
        TLabel *ProsmotrLabel;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TDBText *NameBaseDBText;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label11;
	TcxButton *cxButtonPrint;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1KOL_DVPOKT;
	TcxGridDBColumn *cxGrid1DBTableView1KF_DVPOKT;
	TcxGridDBColumn *cxGrid1DBTableView1RPRICE_DVPOKT;
	TcxGridDBColumn *cxGrid1DBTableView1RSUM_DVPOKT;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxDBTextEdit *DescrcxDBTextEdit;
	TcxComboBox *TypeRPriceComboBox;
	TcxComboBox *TypePriceComboBox;
	TcxComboBox *OperComboBox;
	TcxDBButtonEdit *NameDogovorcxDBButtonEdit;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TcxDBTextEdit *NumDoccxDBTextEdit;
	TcxDBDateEdit *PosDoccxDBDateEdit;
	TcxDBTextEdit *NameSkladcxDBTextEdit;
	TcxDBTextEdit *NameFirmcxDBTextEdit;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
	TAction *ActionPrint;
	TcxDBTextEdit *PrefiksNumcxDBTextEdit;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonInsertClick(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
        void __fastcall NumberDocKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall DescrDBEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ToolButton5Click(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAMEEDPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall TypePriceComboBoxPropertiesChange(TObject *Sender);
	void __fastcall TypeRPriceComboBoxPropertiesChange(TObject *Sender);
	void __fastcall OperComboBoxPropertiesChange(TObject *Sender);
	void __fastcall NameDogovorcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxDBButtonEdit1PropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall PosDoccxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall ActionPrintExecute(TObject *Sender);
private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

        void InputNewDoc(void);
        void OpenDoc(void);
        bool SaveNewDoc(void);
        bool SaveDoc(void);
        bool DvRegDoc(void);
        bool CancelDvDoc(void);
        void OpenFSSprNom(void);
        void OpenFSSprEd(void);


		enum  {ER_NoRekv,Tovar,Edinica,FirmaRekvisit,KlientRekvisit,
        SkladRekvisit, PodborNom, ViborInfBase,ViborDogovor, NO} EditRekvisit;

         enum  {aoNO,aoAddNewString} ActionOperation;


		IFormaViborSprEd * Ed;
		IFormaViborSprNom * Nom;

		IFormaSpiskaSprKlient * Klient;
		IFormaSpiskaSprDogovor * FormaSpiskaSprDogovor;



		 __int64 VibTovarId;
		 __int64 VibTovarIdGrp;
		 double SummaDoc;

		void  OpenFormSpiskaSprKlient(void);
		void OpenFormSpiskaSprDogovor(void);


		void OpenPrintForm(void);
		void OutputString(TSheetEditor *prForm);
		void OutputZagolovokReport(TSheetEditor *prForm);
		void OutputPodavalReport(TSheetEditor *prForm);
		int numRow;
		int numCol;
		int porNumStr;

		IDMSprTypePrice *DMSprTypePrice;
		IDMSprTypePrice *DMSprRTypePrice;
		bool flObrabatChangePrice;
		bool flObrabatChangeRoznPrice;
		bool flObrabatChangeOperation;
public:		// User declarations
		__fastcall TFormaDocVosvratPokForCashier(TComponent* Owner);

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
		void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);

        IDMDocVosvratPok * DM;

		bool Prosmotr;    //только просмотр
		bool Vibor;       //для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме
		bool ObjectSave;

        void UpdateForm(void);




};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocVosvratPokForCashier *FormaDocVosvratPokForCashier;
//---------------------------------------------------------------------------
#endif
