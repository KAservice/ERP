//---------------------------------------------------------------------------

#ifndef UFormaDocIsmPriceH
#define UFormaDocIsmPriceH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "ISheetEditor.h"
#include "IFormaRunExternalModule.h"

#include "IDMDocIsmPrice.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprEd.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IDMSprTypePrice.h"
#include "USheetEditor.h"
#include "IDMTableExtPrintForm.h"
#include "IFormaSpiskaSprInv.h"
#include "IFormaSpiskaSprProject.h"
#include "IFormaSpiskaSprBusinessOper.h"
#include "IFormaSpiskaSprGrpNom.h"
//-------------------------------------------------------------------------------
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
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxMaskEdit.hpp"
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
#include "UDM.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
class TFormaDocIsmPrice : public TForm
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
	TToolButton *AddNomSoSkladaToolButtonInsert;
        TToolButton *ToolButtonDelete;
        TLabel *Label12;
        TLabel *Label13;
        TDBText *DBTextFNameUser;
        TLabel *ProsmotrLabel;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TLabel *Label4;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1KOL_DISMPRICET;
	TcxGridDBColumn *cxGrid1DBTableView1KF_DISMPRICET;
	TcxGridDBColumn *cxGrid1DBTableView1OLDPRICE_DISMPRICET;
	TcxGridDBColumn *cxGrid1DBTableView1NEWPRICE_DISMPRICET;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxDBTextEdit *NumDoccxDBTextEdit;
	TcxDBDateEdit *PosDoccxDBDateEdit;
	TcxDBButtonEdit *NameSkladcxDBButtonEdit;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TcxDBButtonEdit *NameInfBasecxDBButtonEdit;
	TcxLabel *cxLabel1;
	TcxComboBox *TypePriceComboBox;
	TcxDBTextEdit *DescrcxDBTextEdit;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TAction *ActionAddNomSoSklada;
	TAction *ActionDeleteRecord;
	TToolButton *AddNomToolButton;
	TAction *ActionAddNom;
	TLabel *ProsmotrTextLabel;
	TToolButton *ToolButton4;
	TPopupMenu *PopupMenuExtModule;
	TcxButton *cxButtonPrint;
	TcxGridDBColumn *cxGrid1DBTableView1OLDSUM;
	TcxGridDBColumn *cxGrid1DBTableView1NEWSUM;
	TcxGridDBColumn *cxGrid1DBTableView1SUMISM;
	TToolButton *ToolButtonUpdatePriceInSpr;
	TcxDBButtonEdit *NameInvcxDBButtonEdit;
	TcxLabel *cxLabel2;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
	TAction *ActionPrint;
	TcxDBButtonEdit *NameBusinessOpercxDBButtonEdit;
	TcxLabel *cxLabel9;
	TcxDBButtonEdit *NameProjectcxDBButtonEdit;
	TcxLabel *cxLabel3;
	TToolButton *ToolButtonAddOstatkiPoGrp;
	TToolButton *ToolButtonAddAllOstatki;
	TcxDBTextEdit *PrefiksNumcxDBTextEdit;
	TcxGridDBColumn *cxGrid1DBTableView1SEB_PRICE_DISMPRICET;
	TcxGridDBColumn *cxGrid1DBTableView1SEB_SUM_DISMPRICET;
	TcxGridDBColumn *cxGrid1DBTableView1NAC_SUM;
	TcxGridDBColumn *cxGrid1DBTableView1NAC_NEW_DISMPRICET;
	TcxGridDBColumn *cxGrid1DBTableView1NAC_OLD_DISMPRICET;
	TToolButton *ToolButtonAddSebest;
	TcxGridDBColumn *cxGrid1DBTableView1ARTNOM;
	TcxGridDBColumn *cxGrid1DBTableView1CODENOM;
	TcxGridDBColumn *cxGrid1DBTableView1SHED;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAMEEDPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameInfBasecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionAddNomSoSkladaExecute(TObject *Sender);
	void __fastcall ActionDeleteRecordExecute(TObject *Sender);
	void __fastcall NumDoccxDBTextEditKeyDown(TObject *Sender, WORD &Key,
		  TShiftState Shift);
	void __fastcall PosDoccxDBDateEditKeyDown(TObject *Sender, WORD &Key,
		  TShiftState Shift);
	void __fastcall DescrcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
		  TShiftState Shift);
	void __fastcall TypePriceComboBoxPropertiesValidate(TObject *Sender,
		  Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall ActionAddNomExecute(TObject *Sender);

		//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ToolButtonUpdatePriceInSprClick(TObject *Sender);
	void __fastcall NameInvcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);
	void __fastcall ActionPrintExecute(TObject *Sender);
	void __fastcall NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButtonAddOstatkiPoGrpClick(TObject *Sender);
	void __fastcall ToolButtonAddAllOstatkiClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAC_NEW_DISMPRICETPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall ToolButtonAddSebestClick(TObject *Sender);

private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму


		IDMTableExtPrintForm * DMTableExtPrintForm;
		void RunExternalModule(__int64 id_module, int type_module);

		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
		void OpenFormSpiskaSprInfBase(void);
		void __fastcall EndViborInfBase(void);

		IFormaSpiskaSprFirm *SpisokFirm;
		void OpenFormSpiskaSprFirm(void);
		void __fastcall EndViborFirm(void);

		IFormaSpiskaSprSklad * SpisokSklad;
		void OpenFormSpiskaSprSklad(void);
		void __fastcall EndViborSklad(void);

		IFormaSpiskaSprNom *SpisokNom;
		void OpenFormSpiskaSprNom(void);
		void __fastcall EndViborNom(void);

		void ViborNomSoSklada(void);
		void __fastcall EndViborNomSoSklada(void);


		IFormaSpiskaSprEd * SpisokEd;
		void OpenFormSpiskaSprEd(void);
		void __fastcall EndViborEd(void);


		IFormaSpiskaSprInv  * FormaSpiskaSprInv;
		void OpenFormSpiskaSprInv(void);
		void __fastcall EndViborInv(void);


		 enum  {aoNO,aoAddNewString} ActionOperation;

	   void OpenPrintForm(void);
	   void OutputString(TSheetEditor *prForm);
	   void OutputZagolovokReport(TSheetEditor *prForm);
	   void OutputPodavalReport(TSheetEditor *prForm);
	   int numRow;
	   int numCol;
	   int porNumStr;
	   double SumKol;
	   double SumOld;
	   double SumNew;
	   double SumIsm;
	   IDMSprTypePrice *DMSprTypePrice;

	   IFormaSpiskaSprBusinessOper *SpisokBusinessOper;
	   void OpenFormSpiskaSprBusinessOper(void);
	   void __fastcall EndViborBusinessOper(void);

	   IFormaSpiskaSprProject *SpisokProject;
	   void OpenFormSpiskaSprProject(void);
	   void __fastcall EndViborProject(void);

	   enum  {ER_NoRekv, ER_InfBase, ER_Firm, ER_Sklad, ER_Nom, ER_NomSoSklada,
						 ER_Ed, ER_Inv, ER_BusinessOper, ER_Project,ER_ViborGrpNom, ER_NO} EditRekvisit;

	   IFormaSpiskaSprGrpNom * FormaViborGrpNomSpr;
		void OpenFormViborGrpNom(void);
		void EndViborGrpNom(void);

public:		// User declarations
		__fastcall TFormaDocIsmPrice(TComponent* Owner);

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

		 IDMDocIsmPrice *DM;


        bool NewElement;  // новый элемент
        bool Prosmotr;    //только просмотр
		bool NoEdit;
		__int64 IdDoc;           //идентификатор текущей записи

		void UpdateForm(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocIsmPrice *FormaDocIsmPrice;
//---------------------------------------------------------------------------
#endif
