//---------------------------------------------------------------------------

#ifndef UFormaDocSpisNomH
#define UFormaDocSpisNomH
//---------------------------------------------------------------------------
#include "IDMDocSpisNom.h"
#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprEd.h"
#include "IFormaSpiskaSprNom.h"
#include "USheetEditor.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IDMTableExtPrintForm.h"
#include "IDMSprTypePrice.h"
#include "IDMSprPrice.h"
#include "IFormaSpiskaSprProject.h"
#include "IFormaSpiskaSprBusinessOper.h"
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
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxContainer.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCalendar.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaDocSpisNom : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
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
        TPanel *Panel3;
        TDBText *NameUserDBText;
        TLabel *ProsmotrLabel;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TLabel *DocOsnLabel;
	TLabel *TypeRPriceLabel;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1KOLSPNT;
	TcxGridDBColumn *cxGrid1DBTableView1KFSPNT;
	TcxGridDBColumn *cxGrid1DBTableView1PRICESPNT;
	TcxGridDBColumn *cxGrid1DBTableView1SUMSPNT;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxGridDBColumn *cxGrid1DBTableView1RPRICE_DSPNT;
	TcxGridDBColumn *cxGrid1DBTableView1RSUM_DSPNT;
	TcxButton *cxButtonPoGrp;
	TcxButton *cxButtonPrint;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBTextEdit *PrimcxDBTextEdit;
	TcxComboBox *TypeRPriceComboBox;
	TcxDBDateEdit *PosDoccxDBDateEdit;
	TcxDBTextEdit *NumDoccxDBTextEdit;
	TcxDBButtonEdit *NameSkladcxDBButtonEdit;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TcxDBButtonEdit *NameInfBasecxDBButtonEdit;
	TcxLabel *cxLabel1;
	TAction *ActionAddString;
	TAction *ActionDeleteString;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
	TAction *ActionDvReg;
	TAction *ActionPrint;
	TcxDBButtonEdit *NameBusinessOpercxDBButtonEdit;
	TcxLabel *cxLabel9;
	TcxLabel *cxLabel3;
	TcxDBButtonEdit *NameProjectcxDBButtonEdit;
	TToolButton *ToolButtonAddOstSoSklada;
	TcxDBTextEdit *PrefiksNumcxDBTextEdit;
	TcxGridDBColumn *cxGrid1DBTableView1ARTNOM;
	TcxGridDBColumn *cxGrid1DBTableView1CODENOM;
	TcxGridDBColumn *cxGrid1DBTableView1SHED;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAMEEDPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonPoGrpClick(TObject *Sender);
	void __fastcall TypeRPriceComboBoxPropertiesChange(TObject *Sender);
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
	void __fastcall PrimcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormDeactivate(TObject *Sender);

				//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);
	void __fastcall ActionPrintExecute(TObject *Sender);
	void __fastcall NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButtonAddOstSoSkladaClick(TObject *Sender);

private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму


	//внешние формы и скрипты
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);


		IFormaSpiskaSprFirm *SpisokFirm;
		IFormaSpiskaSprSklad * SpisokSklad;
		IFormaSpiskaSprNom *SpisokNom;
		IFormaSpiskaSprEd * SpisokEd;

        void OpenFormSpiskaSprEd(void);
        void OpenFormSpiskaSprNom(void);
        void OpenFormSpiskaSprFirm(void);
        void OpenFormSpiskaSprSklad(void);

		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
        void OpenFormSpiskaSprInfBase(void);


		enum  {ER_NoRekv,ViborTovar,ViborEdinica,ViborFirm,ViborSklad, ViborInfBase,ER_BusinessOper, ER_Project, NO} EditRekvisit;
        enum  {aoNO,aoAddNewString} ActionOperation;

        void SummaCheck(void);
        void OpenPrintForm(void);
		void OutputString(TSheetEditor *prForm);
		void OutputZagolovokReport(TSheetEditor *prForm);
		void OutputPodavalReport(TSheetEditor *prForm);
		int numRow;
		int numCol;
		int porNumStr;

		 __int64 VibTovarId;
		 __int64 VibTovarIdGrp;

		 IDMSprTypePrice *DMSprTypeRPrice;


		void  PrintPoGrp(void);
		bool flObrabatChangeTypePrice;

		double RoznSummaForPrint;

	IFormaSpiskaSprBusinessOper *SpisokBusinessOper;
	void OpenFormSpiskaSprBusinessOper(void);
	void __fastcall EndViborBusinessOper(void);

	IFormaSpiskaSprProject *SpisokProject;
	void OpenFormSpiskaSprProject(void);
	void __fastcall EndViborProject(void);

public:		// User declarations
		__fastcall TFormaDocSpisNom(TComponent* Owner);

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


		IDMDocSpisNom *DM;


		bool Prosmotr;    //только просмотр
		__int64 IdDoc;           //идентификатор текущей записи


		void UpdateForm(void);


		void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocSpisNom *FormaDocSpisNom;
//---------------------------------------------------------------------------
#endif
