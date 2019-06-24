//---------------------------------------------------------------------------

#ifndef UFormaDocRepKKMH
#define UFormaDocRepKKMH
//---------------------------------------------------------------------------

#include "IFormaRunExternalModule.h"
#include "IDMTableExtPrintForm.h"
#include "IFormaSpiskaSprBankSchet.h"
#include "IDMDocRepKKM.h"
#include "IDMFibConnection.h"

#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprEd.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaSpiskaSprKKM.h"
#include "IFormaSpiskaSprDogovor.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IDMSprTypePrice.h"
#include "IFormaSpiskaSprProject.h"
#include "IFormaSpiskaSprBusinessOper.h"
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
#include "cxContainer.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtons.hpp"
#include "cxCalendar.hpp"
#include "cxDBEdit.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxCheckBox.hpp"
#include "cxPC.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaDocRepKKM : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TLabel *Label9;
        TLabel *Label10;
        TDBText *DBTextFNameUser;
        TLabel *ProsmotrLabel;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1PRICE_DREPKKMT;
	TcxGridDBColumn *cxGrid1DBTableView1KOL_DREPKKMT;
	TcxGridDBColumn *cxGrid1DBTableView1KF_DREPKKMT;
	TcxGridDBColumn *cxGrid1DBTableView1SUM_DREPKKMT;
	TcxGridDBColumn *cxGrid1DBTableView1SK_DREPKKMT;
	TcxGridDBColumn *cxGrid1DBTableView1NAD_DREPKKMT;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBCalcEdit *OplPCcxDBCalcEdit;
	TcxDBCalcEdit *OplNalcxDBCalcEdit;
	TAction *ActionAddString;
	TAction *ActionDeleteString;
	TToolBar *ToolBar2;
	TToolButton *ToolButton1;
	TToolButton *ToolButtonInsert;
	TToolButton *ToolButtonDelete;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TcxLabel *cxLabel1;
	TcxDBButtonEdit *NameInfBasecxDBButtonEdit;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TLabel *Label12;
	TLabel *Label1;
	TcxDBTextEdit *NumDoccxDBTextEdit;
	TLabel *Label2;
	TcxDBDateEdit *PosDoccxDBDateEdit;
	TLabel *Label13;
	TcxDBButtonEdit *NameSkladcxDBButtonEdit;
	TcxDBCheckBox *DvRegcxDBCheckBox;
	TcxComboBox *TypePriceComboBox;
	TLabel *Label4;
	TcxDBTextEdit *PrimcxDBTextEdit;
	TcxDBButtonEdit *NameKKMcxDBButtonEdit;
	TcxDBButtonEdit *NameDogovorcxDBButtonEdit;
	TLabel *Label6;
	TLabel *Label15;
	TLabel *Label14;
	TLabel *Label7;
	TcxDBTextEdit *NumKLcxDBTextEdit;
	TLabel *Label5;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label3;
	TLabel *Label8;
	TLabel *Label20;
	TcxDBButtonEdit *NameBSchetcxDBButtonEdit;
	TLabel *Label11;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
	TcxDBButtonEdit *NameBusinessOpercxDBButtonEdit;
	TcxLabel *cxLabel9;
	TcxLabel *cxLabel3;
	TcxDBButtonEdit *NameProjectcxDBButtonEdit;
	TcxDBTextEdit *PrefiksNumcxDBTextEdit;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAMEEDPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameKKMcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameDogovorcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladcxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
	void __fastcall NumKLcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PrimcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall OplNalcxDBCalcEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall OplPCcxDBCalcEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall TypePriceComboBoxPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);

				//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
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

		IFormaSpiskaSprBankSchet *SpisokBSchet;
		void OpenFormSpiskaSprBSchet(void);
		void __fastcall EndViborBSchet(void);
		double SumCheck;
		bool flObrabatChangeTypePrice;
		IDMSprTypePrice *DMSprTypePrice;

	IFormaSpiskaSprBusinessOper *SpisokBusinessOper;
	void OpenFormSpiskaSprBusinessOper(void);
	void __fastcall EndViborBusinessOper(void);

	IFormaSpiskaSprProject *SpisokProject;
	void OpenFormSpiskaSprProject(void);
	void __fastcall EndViborProject(void);

		enum  {ER_NoRekv,ER_InfBase, ER_Firm, ER_BankSchet, ER_Sklad, ER_Klient, ER_Dogovor, ER_Kassa,
					 ER_BusinessOper, ER_Project, ER_Nom,
					  ER_Ed,ER_Part,ER_NO} EditRekvisit;
public:		// User declarations
		__fastcall TFormaDocRepKKM(TComponent* Owner);


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

         IDMDocRepKKM *DM;
         void UpdateForm(void);

        bool Prosmotr;    //только просмотр
		__int64 IdDoc;           //идентификатор текущей записи
		bool NoEdit;



};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocRepKKM *FormaDocRepKKM;
//---------------------------------------------------------------------------
#endif
