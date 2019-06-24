//---------------------------------------------------------------------------

#ifndef UREM_FormaDocAktH
#define UREM_FormaDocAktH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IFormaSpiskaSprInfBase.h"
#include "UDM.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprSklad.h"
#include "IREM_DMDocAkt.h"
#include "IREM_FormaGurZ.h"
#include "IFormaSpiskaSprKlient.h"
#include "IDMTableExtPrintForm.h"
#include "IFormaSpiskaSprProject.h"
#include "IFormaSpiskaSprBusinessOper.h"
//--------------------------------------------------------------------------
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
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
#include "cxCheckBox.hpp"
#include "cxContainer.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCalendar.hpp"
#include "cxLabel.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxDBLookupComboBox.hpp"
#include "cxDBLookupEdit.hpp"
#include "cxLookupEdit.hpp"
#include "cxDBLabel.hpp"
#include "cxGridBandedTableView.hpp"
#include "cxGridDBBandedTableView.hpp"
#include "cxLookAndFeels.hpp"
#include "cxMemo.hpp"
#include "cxImageComboBox.hpp"
#include "cxPC.hpp"
//---------------------------------------------------------------------------
class TREM_FormaDocAkt : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
        TToolBar *ToolBar2;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonInsert;
        TToolButton *ToolButtonDelete;
        TLabel *Label5;
        TLabel *Label6;
        TDBText *DBTextFNameUser;
        TLabel *ProsmotrLabel;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxDBTextEdit *NumDoccxDBTextEdit;
	TcxDBDateEdit *PosDoccxDBDateEdit;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TcxDBButtonEdit *NameInfBasecxDBButtonEdit;
	TcxLabel *cxLabel1;
	TcxDBButtonEdit *NameSkladcxDBButtonEdit;
	TcxButton *cxButtonPrint;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TAction *ActionAddString;
	TAction *ActionDeleteString;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
	TAction *ActionPrint;
	TToolButton *ToolButtonOpenExtModule;
	TPopupMenu *PopupMenuExtModule;
	TcxLabel *cxLabel9;
	TcxDBButtonEdit *NameBusinessOpercxDBButtonEdit;
	TcxDBButtonEdit *NameProjectcxDBButtonEdit;
	TcxLabel *cxLabel4;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TcxDBTextEdit *cxDBTextEditNEISPR_KLIENTA_REM_DAKT;
	TLabel *Label7;
	TcxGrid *cxGrid1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxGridDBColumn *cxGrid1DBTableView1INDEX_REM_DAKTT;
	TcxGridDBColumn *cxGrid1DBTableView1TEXT_REM_DAKTT;
	TcxGridLevel *cxGrid1Level1;
	TcxDBTextEdit *PrimcxDBTextEdit;
	TLabel *Label3;
	TLabel *Label9;
	TcxDBButtonEdit *NameZcxDBButtonEdit;
	TcxDBImageComboBox *TypecxDBImageComboBox;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TLabel *Label4;
	TcxDBLabel *SerNumZcxDBLabel;
	TcxDBLabel *ModelcxDBLabel;
	TcxDBCheckBox *KlSoglasencxDBCheckBox;
	TcxDBCheckBox *PodpisancxDBCheckBox;
	TcxDBLabel *SerNum2ZcxDBLabel;
	TLabel *Label8;
	TcxDBTextEdit *cxDBTextEditNUM_U_PROISV_REM_DAKT;
	TcxTabSheet *cxTabSheet3;
	TcxTabSheet *cxTabSheet4;
	TcxDBTextEdit *cxDBTextEditNEISPR_SC_REM_DAKT;
	TLabel *Label10;
	TcxDBTextEdit *cxDBTextEditNEISPR_BLOK_REM_DAKT;
	TLabel *Label12;
	TcxTabSheet *cxTabSheet5;
	TcxDBImageComboBox *cxDBImageComboBoxFL_FULL_KOMPL_REM_DAKT;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TcxDBTextEdit *cxDBTextEditKOMPL_STR_REM_DAKT;
	TcxDBTextEdit *cxDBTextEditNEKOMPL_STR_REM_DAKT;
	TcxDBTextEdit *cxDBTextEditMEXPOVR_STR_REM_DAKT;
	TLabel *Label17;
	TcxDBImageComboBox *cxDBImageComboBoxFL_MEXPOVR_REM_DAKT;
	TLabel *Label18;
	TcxTabSheet *cxTabSheet6;
	TcxDBImageComboBox *cxDBImageComboBoxFL_PRICHINA_ACTA_REM_DAKT;
	TLabel *Label11;
	TLabel *Label19;
	TLabel *Label20;
	TcxDBTextEdit *cxDBTextEditPRICHINA_SOST_DR_REM_DAKT;
	TcxDBTextEdit *cxDBTextEditPRICHINA_ACTA_DR_STR_REM_DAKT;
	TLabel *Label13;
	TcxDBImageComboBox *cxDBImageComboBoxFL_PRICHINA_SOST_REM_DAKT;
	TcxDBTextEdit *cxDBTextEditISD_NAME_REM_DAKT;
	TcxDBTextEdit *cxDBTextEditISD_MODEL_REM_DAKT;
	TcxDBTextEdit *cxDBTextEditISD_SERNUM1_REM_DAKT;
	TcxDBTextEdit *cxDBTextEditISD_SERNUM2_REM_DAKT;
	TcxDBDateEdit *cxDBDateEditISD_DATE_PRODAGI_REM_DAKT;
	TcxDBTextEdit *cxDBTextEditISD_SERNUM3_REM_DAKT;
	TcxDBTextEdit *cxDBTextEditISD_NUMUP_REM_DAKT;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label23;
	TLabel *Label24;
	TLabel *Label25;
	TLabel *Label26;
	TLabel *Label27;
	TLabel *Label28;
	TcxDBTextEdit *cxDBTextEditISD_NUMTEXLIST_REM_DAKT;
	TcxDBTextEdit *cxDBTextEditKLIENT_NAME_REM_DAKT;
	TcxDBTextEdit *cxDBTextEditKLIENT_PHONE_REM_DAKT;
	TcxDBTextEdit *cxDBTextEditPRODAVEC_TEL_REM_DAKT;
	TLabel *Label29;
	TLabel *Label30;
	TLabel *Label31;
	TLabel *Label32;
	TLabel *Label33;
	TLabel *Label34;
	TcxDBTextEdit *cxDBTextEditPRODAVEC_NAME_REM_DAKT;
	TcxDBTextEdit *cxDBTextEditRODAVEC_ADR_REM_DAKT;
	TcxDBTextEdit *cxDBTextEditKLIENT_ADR_REM_DAKT;
	TcxDBImageComboBox *cxDBImageComboBoxFL_MESTONAX_REM_DAKT;
	TLabel *Label35;
	TToolButton *ToolButtonAddDataIsZ;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
 //       void __fastcall AddNewStringClick(TObject *Sender);
 //       void __fastcall DeleteStringClick(TObject *Sender);
        void __fastcall NumberDocKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FDateDocKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall PrimKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PosDoccxDBDateEditPropertiesChange(TObject *Sender);
	void __fastcall NameFirmcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameInfBasecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionAddStringExecute(TObject *Sender);
	void __fastcall ActionDeleteStringExecute(TObject *Sender);
	void __fastcall NumDoccxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PosDoccxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PrimcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall NameKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameZcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);

					//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall NumDocKlientcxDBTextEditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall PosDocKlientcxDBDateEditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall cxGrid1DBTableView1NAME_REM_ZPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButtonAddDataIsZClick(TObject *Sender);



private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

			//внешние формы и скрипты
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

		//выбор информационной базы
		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
		void ViborInfBase(void);
		void __fastcall EndViborInfBase(void);

		//выбор фирмы
		IFormaSpiskaSprFirm * FormaSpiskaSprFirm;
		void ViborFirm(void);
		void __fastcall EndViborFirm(void);

		//выбор склада
		IFormaSpiskaSprSklad * FormaSpiskaSprSklad;
		void ViborSklad(void);
		void __fastcall EndViborSklad(void);

		//выбор клиента
		IFormaSpiskaSprKlient * FormaSpiskaSprKlient;
		void ViborKlient(void);
		void __fastcall EndViborKlient(void);

		//выбор заявки
		IREM_FormaGurZ* FormaGurZ;
		void ViborRemZ(void);
		void __fastcall EndViborRemZ(void);

		enum  { aoNO,aoAddNewString} ActionOperation;
		enum {ER_NoRekv,ER_No, ER_InfBase,ER_Firm,ER_Sklad,ER_Klient,
						ER_Zayavka,ER_Nom,ER_Ed, ER_Hardware,ER_CreateCheck,ER_BusinessOper, ER_Project} EDitRekvisit;

		void BeforeSaveDoc(void);

		void AfterSaveDoc(void);

	IFormaSpiskaSprBusinessOper *SpisokBusinessOper;
	void OpenFormSpiskaSprBusinessOper(void);
	void EndViborBusinessOper(void);

	IFormaSpiskaSprProject *SpisokProject;
	void OpenFormSpiskaSprProject(void);
	void EndViborProject(void);

public:		// User declarations
		__fastcall TREM_FormaDocAkt(TComponent* Owner);
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
		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме

		IREM_DMDocAkt * DM;

		bool Prosmotr;    //только просмотр

		__int64 IdDoc;           //идентификатор текущей записи


		void UpdateForm(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaDocAkt *REM_FormaDocAkt;
//---------------------------------------------------------------------------
#endif
