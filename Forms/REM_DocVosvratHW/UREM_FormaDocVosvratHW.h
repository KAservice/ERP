//---------------------------------------------------------------------------

#ifndef UREM_FormaDocVosvratHWH
#define UREM_FormaDocVosvratHWH
//---------------------------------------------------------------------------
#include "UDM.h"
#include "IREM_DMDocVosvratHW.h"
#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IDMTableExtPrintForm.h"
#include "IFormaSpiskaSprProject.h"
#include "IFormaSpiskaSprBusinessOper.h"
#include "IREM_FormaSpiskaSprHardware.h"
#include "IFormaInputText.h"
#include "IREM_FormaGurZ.h"
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
#include "UREM_DMDocReal.h"
#include "cxCheckBox.hpp"
#include "cxMemo.hpp"


//---------------------------------------------------------------------------
class TREM_FormaDocVosvratHW : public TForm
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
	TcxButton *cxButtonSave;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxDBTextEdit *PrimcxDBTextEdit;
	TLabel *Label7;
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
	TToolBar *ToolBar2;
	TToolButton *ToolButton1;
	TToolButton *ToolButtonInsert;
	TToolButton *ToolButtonDelete;
	TToolButton *ToolButton2;
	TDBText *NameBaseDBText;
	TToolButton *ToolButton3;
	TButton *ViborBaseButton;
	TAction *ActionInsertString;
	TAction *ActionDeleteString;
	TLabel *ProsmotrTextLabel;
	TcxDBButtonEdit *NameProjectcxDBButtonEdit;
	TcxLabel *cxLabel3;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TPanel *Panel7;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
	TAction *ActionPrint;
	TcxDBButtonEdit *NameBusinessOpercxDBButtonEdit;
	TcxLabel *cxLabel9;
	TcxGridDBColumn *cxGrid1DBTableView1ID_REM_DVOSVRAT_HWT;
	TcxGridDBColumn *cxGrid1DBTableView1IDHW_REM_DVOSVRAT_HWT;
	TcxGridDBColumn *cxGrid1DBTableView1kol_REM_DVOSVRAT_HWT;
	TcxGridDBColumn *cxGrid1DBTableView1KF_REM_DVOSVRAT_HWT;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1CODE_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1SERNUM_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TLabel *LabelEditRekvisitBarCode;
	TToolButton *ToolButtonChangeERBC;
	TAction *ActionChangeERBC;
	TAction *ActionAddHWPoCodu;
	TAction *ActionAddPoId;
	TToolButton *ToolButtonAddPoCoduHW;
	TToolButton *ToolButtonAddPoIdHW;
	TcxGridDBColumn *cxGrid1DBTableView1SERNUM2_REM_SHARDWARE;
	TLabel *Label9;
	TcxDBButtonEdit *NameZcxDBButtonEdit;
	TcxDBLabel *ModelcxDBLabel;
	TcxDBLabel *SerNumZcxDBLabel;
	TcxDBLabel *SerNum2ZcxDBLabel;
	TcxGridDBColumn *cxGrid1DBTableView1POVREGD_REM_DVIDACHA_HWT;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ViborBaseButtonClick(TObject *Sender);
	void __fastcall NameFirmcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladcxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
	void __fastcall NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
		  int AButtonIndex);

		//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAME_REM_SHARDWAREPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall ActionChangeERBCExecute(TObject *Sender);
	void __fastcall ActionAddHWPoCoduExecute(TObject *Sender);
	void __fastcall ActionAddPoIdExecute(TObject *Sender);
	void __fastcall NameZcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);


private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

	//внешние формы и скрипты
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

		IFormaSpiskaSprFirm *SpisokFirm;
		IFormaSpiskaSprSklad * SpisokSklad;
		IFormaSpiskaSprKlient * SpisokKlient;

        void OpenFormSpiskaSprFirm(void);
		void OpenFormSpiskaSprSklad(void);
		void OpenFormSpiskaSprKlient(void);

		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
		void OpenFormSpiskaSprInfBase(void);

		enum  {aoNO,aoAddNewString} ActionOperation;
		void SummaCheck(void);





		IFormaSpiskaSprBusinessOper *SpisokBusinessOper;
		void OpenFormSpiskaSprBusinessOper(void);
		void __fastcall EndViborBusinessOper(void);

		IFormaSpiskaSprProject *SpisokProject;
		void OpenFormSpiskaSprProject(void);
		void __fastcall EndViborProject(void);

		 enum  {ER_NoRekv,ER_InfBase, ER_Firm, ER_Sklad, ER_Klient, ER_Card,
					 ER_BusinessOper, ER_Project, ER_Nom, ER_PodborNom, ER_GrpNom,
					  ER_Ed,ER_Part, ER_ElementNom, ER_ElementEd,ER_Hardware,
					  ER_InputCodeHW, ER_InputIdHW,ER_SkladPol,ER_InputProcent,ER_Zayavka, ER_NO} EditRekvisit;

		 //выбор оборудования
		IREM_FormaSpiskaSprHardware* FormaSpiskaSprHardware;
		void ViborHardware(void);
		void EndViborHardware(void);

		__int64 VibTovarId;
		__int64 VibTovarIdGrp;
		__int64 VibHWId;
		__int64 VibHWIdGrp;

		enum  {ERBC_NoRekv,ERBC_Nom, ERBC_HW, ERBC_NO} EditRekvisitBarCode;

		void ObrabotatReadBarCodeHardware(UnicodeString sh);


		IFormaInputText* FormaInputText;
		void OpenFormInputCodeHW(void);
		void EndInputCodeHW(void);

		void OpenFormInputIdHW(void);
		void EndInputIdHW(void);

		//выбор заявки
		IREM_FormaGurZ* FormaGurZ;
		void ViborRemZ(void);
		void EndViborRemZ(void);


public:		// User declarations
		__fastcall TREM_FormaDocVosvratHW(TComponent* Owner);

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

        //IAsyncExternalEvent
		void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);


		//Текущий интерфейс
		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме

		IREM_DMDocVosvratHW *DM;
		void UpdateForm(void);

        bool NewElement;  // новый элемент
		bool Prosmotr;    //только просмотр
		__int64 IdDoc;    //идентификатор текущей записи




};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaDocVosvratHW *REM_FormaDocVosvratHW;
//---------------------------------------------------------------------------
#endif
