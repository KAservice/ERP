//---------------------------------------------------------------------------

#ifndef UREM_FormaDocPrihNaklH
#define UREM_FormaDocPrihNaklH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IREM_DMDocPrihNakl.h"
#include "IFormaRunExternalModule.h"
#include "IFormaSpiskaSprEd.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprGrpNom.h"
#include "IDMTableExtPrintForm.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IDMSprTypePrice.h"
#include "IFormaSpiskaSprProject.h"
#include "IFormaSpiskaSprBusinessOper.h"
#include "IREM_FormaSpiskaSprHardware.h"
#include "IFormaGurDocPrihNakl.h"
#include "IREM_FormaGurCustQueryDetal.h"
#include "IFormaSpiskaSprStorageLocation.h"
//----------------------------------------------------------------------------
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
#include "cxPC.hpp"
#include "cxGridBandedTableView.hpp"
#include "cxGridDBBandedTableView.hpp"
#include "cxLookAndFeels.hpp"

//---------------------------------------------------------------------------
class TREM_FormaDocPrihNakl : public TForm
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
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TDBText *DBTextFNameUser;
        TLabel *Label7;
        TPopupMenu *PopupMenu1;
        TMenuItem *AddNewString;
        TMenuItem *DeleteString;
        TLabel *ProsmotrLabel;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TLabel *RTPriceLabel;
	TcxDBTextEdit *PrimcxDBTextEdit;
	TcxComboBox *TypeRPriceComboBox;
	TcxComboBox *TypePriceComboBox;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
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
	TcxPageControl *TablecxPageControl;
	TcxTabSheet *MaincxTabSheet;
	TcxGrid *cxGrid1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TAction *ActionSetMainTabSheet;
	TAction *ActionSetAdditionallyTabSheet;
	TcxDBDateEdit *PosDocPostcxDBDateEdit;
	TcxDBTextEdit *NumDocPostcxDBTextEdit;
	TcxLabel *cxLabel2;
	TcxLabel *cxLabel3;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
	TAction *ActionPrint;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
	TAction *ActionEditNom;
	TAction *ActionEditEd;
	TcxLabel *cxLabel9;
	TcxDBButtonEdit *NameBusinessOpercxDBButtonEdit;
	TcxDBButtonEdit *NameProjectcxDBButtonEdit;
	TcxLabel *cxLabel4;
	TcxGridDBColumn *cxGrid1DBTableView1ID_REM_DPRNT;
	TcxGridDBColumn *cxGrid1DBTableView1IDNOM_REM_DPRNT;
	TcxGridDBColumn *cxGrid1DBTableView1IDED_REM_DPRNT;
	TcxGridDBColumn *cxGrid1DBTableView1IDHW_REM_DPRNT;
	TcxGridDBColumn *cxGrid1DBTableView1KOL_REM_DPRNT;
	TcxGridDBColumn *cxGrid1DBTableView1KF_REM_DPRNT;
	TcxGridDBColumn *cxGrid1DBTableView1PRICE_REM_DPRNT;
	TcxGridDBColumn *cxGrid1DBTableView1SUM_REM_DPRNT;
	TcxGridDBColumn *cxGrid1DBTableView1RPRICE_REM_DPRNT;
	TcxGridDBColumn *cxGrid1DBTableView1RSUM_REM_DPRNT;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1CODENOM;
	TcxGridDBColumn *cxGrid1DBTableView1ARTNOM;
	TcxGridDBColumn *cxGrid1DBTableView1SHED;
	TcxGridDBColumn *cxGrid1DBTableView1CODE_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1SERNUM_REM_SHARDWARE;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_REM_SHARDWARE;
	TToolButton *ToolButtonLoadNaOsnPrihNakl;
	TToolButton *ToolButtonAddSprHW;
	TcxGridDBColumn *cxGrid1DBTableView1DVREG_REM_DPRNT;
	TToolButton *ToolButton4;
	TAction *ActionEditOborud;
	TToolButton *ToolButtonSetDvRegAll;
	TToolButton *ToolButtonCancelDvRegAll;
	TcxDBCheckBox *OtchetPostcxDBCheckBox;
	TcxDBCheckBox *OtvHrancxDBCheckBox;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_REM_CQUERY;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_REM_Z;
	TcxGridDBColumn *cxGrid1DBTableView1FL_ADD_IN_SOBORUD_SNOM;
	TDBText *DBTextSUM_REM_GALLDOC;
	TToolButton *ToolButton7;
	TToolButton *ToolButtonCreateDocPrihNakl;
	TToolButton *ToolButtonSetPostupilo;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SMHRAN;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall AddNewStringClick(TObject *Sender);
        void __fastcall DeleteStringClick(TObject *Sender);
        void __fastcall NumberDocKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FDateDocKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall PrimKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAMEEDPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall TypeRPriceComboBoxPropertiesChange(TObject *Sender);
	void __fastcall TypePriceComboBoxPropertiesChange(TObject *Sender);
	void __fastcall NameKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
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
	void __fastcall IsmPriceCheckBoxKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PrimcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall NumDocPostcxDBTextEditKeyPress(TObject *Sender, char &Key);
	void __fastcall PosDocPostcxDBDateEditKeyPress(TObject *Sender, char &Key);

				//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall ActionEditNomExecute(TObject *Sender);
	void __fastcall ActionEditEdExecute(TObject *Sender);
	void __fastcall NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAME_REM_SHARDWAREPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButtonLoadNaOsnPrihNaklClick(TObject *Sender);
	void __fastcall ToolButtonAddSprHWClick(TObject *Sender);
	void __fastcall ActionEditOborudExecute(TObject *Sender);
	void __fastcall ToolButtonSetDvRegAllClick(TObject *Sender);
	void __fastcall ToolButtonCancelDvRegAllClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAME_REM_CQUERYPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButtonCreateDocPrihNaklClick(TObject *Sender);
	void __fastcall ToolButtonSetPostupiloClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAME_SMHRANPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму
	//внешние формы и скрипты
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);


        void InputNewDoc(void);
        void OpenDoc(void);
        bool SaveNewDoc(void);
        bool SaveDoc(void);
        bool DvRegDoc(void);
		bool CancelDvDoc(void);

		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
        void OpenFormSpiskaSprInfBase(void);


		 enum  {aoNO,aoAddNewString} ActionOperation;

		IFormaSpiskaSprEd * Ed;
		IFormaSpiskaSprNom * Nom;
		IFormaSpiskaSprFirm * Firma;
		IFormaSpiskaSprSklad * Sklad;
		IFormaSpiskaSprKlient * Klient;
	         double SummaDoc;

		void  OpenFormSpiskaSprFirm(void);
		void  OpenFormSpiskaSprSklad(void);
		void  OpenFormSpiskaSprKlient(void);

		IDMSprTypePrice *DMSprTypePrice;
		IDMSprTypePrice *DMSprTypeRPrice;


		bool flObrabatChangeTypePrice;
		bool flObrabatChangeRoznTypePrice;


		void BeforeSaveDoc(void);

		IFormaSpiskaSprBusinessOper *SpisokBusinessOper;
	void OpenFormSpiskaSprBusinessOper(void);
	void __fastcall EndViborBusinessOper(void);

	IFormaSpiskaSprProject *SpisokProject;
	void OpenFormSpiskaSprProject(void);
	void __fastcall EndViborProject(void);

		 enum  {ER_NoRekv,ER_InfBase, ER_Firm, ER_Sklad, ER_Klient,
					 ER_BusinessOper, ER_Project, ER_Nom, ER_PodborNom, ER_GrpNom,
					  ER_Ed,ER_Part, ER_ElementNom, ER_ElementEd, ER_Hardware,
					  ER_PrihNakl,ER_ElementHW,
					  ER_ViborCustomerQuery,
					  ER_ViborStorageLocation,
					  ER_NO} EditRekvisit;

		 void OpenFSSprNom(void);
		 void OpenFSSprEd(void);


		 //выбор оборудования
		IREM_FormaSpiskaSprHardware* FormaSpiskaSprHardware;
		void ViborHardware(void);
		void EndViborHardware(void);

		//выбор документа Приходная накладная
		IFormaGurDocPrihNakl *FormaGurDocPrihNakl;
		void ViborDocPrihNakl(void);
		void __fastcall EndViborDocPrihNakl(void);

        IREM_FormaGurCustQueryDetal * REM_FormaGurCustQuery;
		void OpenFormGurCustQuery(void);
		void EndViborCustQuery(void);

		IFormaSpiskaSprStorageLocation* FormaSpiskaSprStorageLocation;
		void ViborStorageLocation(void);
		void EndViborStorageLocation(void);

public:		// User declarations
		__fastcall TREM_FormaDocPrihNakl(TComponent* Owner);

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

		IREM_DMDocPrihNakl * DM;

        bool ObjectSave;
		bool Prosmotr;    //только просмотр
		__int64 IdDoc;           //идентификатор текущей записи
		__int64 IdGrp;        // идентификатор группы
		__int64 IdElementaMaster;  //идентификатор внешенго справочника-владельца


		 __int64 VibTovarId;
         __int64 VibTovarIdGrp;


        void UpdateForm(void);


	void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaDocPrihNakl *REM_FormaDocPrihNakl;
//---------------------------------------------------------------------------
#endif
