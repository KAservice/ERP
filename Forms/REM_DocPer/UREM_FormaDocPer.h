//---------------------------------------------------------------------------

#ifndef UREM_FormaDocPerH
#define UREM_FormaDocPerH
//---------------------------------------------------------------------------
#include "UDM.h"
#include "IDMSprTypePrice.h"
#include "IREM_DMDocPer.h"
#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprEd.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IDMTableExtPrintForm.h"
#include "IFormaSpiskaSprProject.h"
#include "IFormaSpiskaSprBusinessOper.h"
#include "IREM_FormaSpiskaSprHardware.h"
#include "IFormaInputText.h"
#include "IFormaSpiskaSprStorageLocation.h"
#include "IFormaSpiskaSprTypeNom.h"
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


//---------------------------------------------------------------------------
class TREM_FormaDocPer : public TForm
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
	TcxComboBox *TypePriceComboBox;
	TToolBar *ToolBar2;
	TToolButton *ToolButton1;
	TToolButton *ToolButtonInsert;
	TToolButton *ToolButtonDelete;
	TToolButton *ToolButton2;
	TDBText *NameBaseDBText;
	TToolButton *ToolButton3;
	TButton *ViborBaseButton;
	TLabel *Label21;
	TcxDBButtonEdit *NameSkladPolcxDBButtonEdit;
	TcxLabel *cxLabel2;
	TAction *ActionInsertString;
	TAction *ActionDeleteString;
	TcxDBButtonEdit *DocOsncxDBButtonEdit;
	TLabel *Label22;
	TLabel *ProsmotrTextLabel;
	TcxDBButtonEdit *NameProjectcxDBButtonEdit;
	TcxLabel *cxLabel3;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TPanel *Panel7;
	TcxLabel *cxLabel7;
	TcxDBLabel *SumDoccxDBLabel;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
	TAction *ActionPrint;
	TcxDBButtonEdit *NameBusinessOpercxDBButtonEdit;
	TcxLabel *cxLabel9;
	TcxGridDBColumn *cxGrid1DBTableView1ID_REM_DPERT;
	TcxGridDBColumn *cxGrid1DBTableView1IDNOM_REM_DPERT;
	TcxGridDBColumn *cxGrid1DBTableView1IDED_REM_DPERT;
	TcxGridDBColumn *cxGrid1DBTableView1IDHW_REM_DPERT;
	TcxGridDBColumn *cxGrid1DBTableView1KOL_REM_DPERT;
	TcxGridDBColumn *cxGrid1DBTableView1KF_REM_DPERT;
	TcxGridDBColumn *cxGrid1DBTableView1RPRICE_REM_DPERT;
	TcxGridDBColumn *cxGrid1DBTableView1RSUM_REM_DPERT;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1CODENOM;
	TcxGridDBColumn *cxGrid1DBTableView1ARTNOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1SHED;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1CODE_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1SERNUM_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxGridDBColumn *cxGrid1DBTableView1DVREG_REM_DPERT;
	TLabel *LabelEditRekvisitBarCode;
	TToolButton *ToolButtonChangeERBC;
	TAction *ActionChangeERBC;
	TAction *ActionAddHWPoCodu;
	TAction *ActionAddPoId;
	TToolButton *ToolButtonAddPoCoduHW;
	TToolButton *ToolButtonAddPoIdHW;
	TToolButton *ToolButtonCreateDocPer;
	TToolButton *ToolButtonAddProcent;
	TToolButton *ToolButtonSetDvRegAll;
	TToolButton *ToolButtonCancalDvRegAll;
	TcxGridDBColumn *cxGrid1DBTableView1DVREG_POL_REM_DPERT;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_STNOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SMHRAN_POL;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SMHRAN_OTPR;
	TToolButton *ToolButtonAddMHran;
	TToolButton *ToolButton4;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
	TToolButton *ToolButton7;
	TToolButton *ToolButtonAddPoCodu;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ViborBaseButtonClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAMEEDPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall TypePriceComboBoxPropertiesChange(TObject *Sender);
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
	void __fastcall ToolButtonCreateDocPerClick(TObject *Sender);
	void __fastcall NameSkladPolcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButtonAddProcentClick(TObject *Sender);
	void __fastcall ToolButtonSetDvRegAllClick(TObject *Sender);
	void __fastcall ToolButtonCancalDvRegAllClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAME_SMHRAN_OTPRPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAME_SMHRAN_POLPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAME_STNOMPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButtonAddMHranClick(TObject *Sender);
	void __fastcall ToolButton4Click(TObject *Sender);
	void __fastcall ToolButton5Click(TObject *Sender);
	void __fastcall ToolButton6Click(TObject *Sender);
	void __fastcall ToolButton7Click(TObject *Sender);
	void __fastcall ToolButtonAddPoCoduClick(TObject *Sender);

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
		void OpenFormSpiskaSprSkladPol(void);
		void OpenFormSpiskaSprKlient(void);

		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
		void OpenFormSpiskaSprInfBase(void);

		enum  {aoNO,aoAddNewString} ActionOperation;
		void SummaCheck(void);


		enum  {ER_ActionOperationCardOpl,ActionOperationCardOpl_New, ActionOperationCardOpl_NO} ActionOperationCardOpl;


double SumCheck;
IDMSprTypePrice *DMSprTypePrice;


		bool flNoChangeTypePrice;


		IFormaSpiskaSprBusinessOper *SpisokBusinessOper;
		void OpenFormSpiskaSprBusinessOper(void);
		void __fastcall EndViborBusinessOper(void);

		IFormaSpiskaSprProject *SpisokProject;
		void OpenFormSpiskaSprProject(void);
		void __fastcall EndViborProject(void);

		 enum  {ER_NoRekv,ER_InfBase, ER_Firm, ER_Sklad, ER_Klient, ER_Card,
					 ER_BusinessOper, ER_Project, ER_Nom, ER_PodborNom, ER_GrpNom,
					  ER_Ed,ER_Part, ER_ElementNom, ER_ElementEd,ER_Hardware,
					  ER_InputCodeHW, ER_InputIdHW,ER_SkladPol,ER_InputProcent,
					  ER_ViborStorageLocationOtpr,
					  ER_ViborStorageLocationPol,
					  ER_ViborTypeNom,
					  ER_InputCodeNom,
					   ER_NO} EditRekvisit;

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

		void OpenFormInputProcent(void);
		void EndInputProcent(void);

		IFormaSpiskaSprStorageLocation* FormaSpiskaSprStorageLocation;
		void ViborStorageLocationOtpr(void);
		void EndViborStorageLocationOtpr(void);
		void ViborStorageLocationPol(void);
		void EndViborStorageLocationPol(void);


		IFormaSpiskaSprTypeNom* FormaSpiskaSprTypeNom;
		void ViborTypeNom(void);
		void EndViborTypeNom(void);

		void OpenFormInputCodeNom(void);
		void EndInputCodeNom(void);


public:		// User declarations
		__fastcall TREM_FormaDocPer(TComponent* Owner);

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

		IREM_DMDocPer *DM;
		void UpdateForm(void);

        bool NewElement;  // новый элемент
		bool Prosmotr;    //только просмотр
		__int64 IdDoc;    //идентификатор текущей записи




};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaDocPer *REM_FormaDocPer;
//---------------------------------------------------------------------------
#endif
