//---------------------------------------------------------------------------

#ifndef UFormaDocOstNomH
#define UFormaDocOstNomH
//---------------------------------------------------------------------------
#include "IFormaElementaSprPart.h"
#include "IDMFibConnection.h"

#include "IFormaSpiskaSprEd.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprTypePrice.h"
#include "IDMDocOstNom.h"
#include "IDMSprPrice.h"
#include "USheetEditor.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IDMSprARM.h"
#include "IDMTableExtPrintForm.h"
#include "IDMSprTypePrice.h"
#include "IFormaSpiskaSprProject.h"
#include "IFormaSpiskaSprBusinessOper.h"
#include "IFormaSpiskaSprObject.h"
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
#include "cxDBEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxLabel.hpp"
#include "cxCalendar.hpp"
#include "cxDropDownEdit.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxGridBandedTableView.hpp"
#include "cxGridDBBandedTableView.hpp"
#include "cxPC.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaDocOstNom : public TForm
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
        TLabel *Label5;
        TLabel *Label6;
        TDBText *NameUserDBText;
        TToolButton *ToolButton2;
        TToolButton *ToolButtonAddPrice;
        TLabel *ProsmotrLabel;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TLabel *Label4;
	TLabel *DocOsnLabel;
	TLabel *TypeRPriceLabel;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TcxDBButtonEdit *NameInfBasecxDBButtonEdit;
	TcxLabel *cxLabel1;
	TcxDBTextEdit *NumDoccxDBTextEdit;
	TcxDBDateEdit *PosDoccxDBDateEdit;
	TcxDBButtonEdit *NameSkladcxDBButtonEdit;
	TcxDBTextEdit *PrimcxDBTextEdit;
	TcxComboBox *TypePriceComboBox;
	TcxComboBox *TypeRPriceComboBox;
	TcxButton *cxButtonPoGrp;
	TcxButton *cxButtonPrint;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonDvReg;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TAction *ActionAddRecord;
	TAction *ActionDeleteRecord;
	TcxButton *EditPropPartcxButton;
	TcxPageControl *TablecxPageControl;
	TcxTabSheet *MaincxTabSheet;
	TcxTabSheet *AdditionallycxTabSheet;
	TcxGrid *cxGrid1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1KOLOSNT;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1KFOSNT;
	TcxGridDBColumn *cxGrid1DBTableView1PRICEOSNT;
	TcxGridDBColumn *cxGrid1DBTableView1SUMOSNT;
	TcxGridDBColumn *cxGrid1DBTableView1NDS_DOSNT;
	TcxGridDBColumn *cxGrid1DBTableView1SUMNDS_DOSNT;
	TcxGridDBColumn *cxGrid1DBTableView1NAC_DOSNT;
	TcxGridDBColumn *cxGrid1DBTableView1RPRICE_DOSNT;
	TcxGridDBColumn *cxGrid1DBTableView1RSUM_DOSNT;
	TcxGridLevel *cxGrid1Level1;
	TcxGridDBTableView *cxGrid2DBTableView1;
	TcxGridLevel *cxGrid2Level1;
	TcxGrid *cxGrid2;
	TcxGridDBBandedTableView *cxGrid2DBBandedTableView1;
	TcxGridDBBandedColumn *cxGrid2DBBandedTableView1KOLOSNT;
	TcxGridDBBandedColumn *cxGrid2DBBandedTableView1KFOSNT;
	TcxGridDBBandedColumn *cxGrid2DBBandedTableView1NAMENOM;
	TcxGridDBBandedColumn *cxGrid2DBBandedTableView1NAMEED;
	TcxGridDBBandedColumn *cxGrid2DBBandedTableView1RECNO;
	TcxGridDBBandedColumn *cxGrid2DBBandedTableView1GTDPART;
	TcxGridDBBandedColumn *cxGrid2DBBandedTableView1SERTPART;
	TcxGridDBBandedColumn *cxGrid2DBBandedTableView1SRGODNPART;
	TAction *ActionSetMainTabSheet;
	TAction *ActionSetAdditionallyTabSheet;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
	TPopupMenu *PopupMenuExtModule;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
	TAction *ActionPrint;
	TcxLabel *cxLabel9;
	TcxDBButtonEdit *NameBusinessOpercxDBButtonEdit;
	TcxDBButtonEdit *NameProjectcxDBButtonEdit;
	TcxLabel *cxLabel3;
	TToolButton *ToolButtonAddOstatki;
	TcxDBTextEdit *PrefiksNumcxDBTextEdit;
	TcxDBButtonEdit *NameObjectcxDBButtonEdit;
	TLabel *Label7;
	TcxGridDBColumn *cxGrid1DBTableView1ARTNOM;
	TcxGridDBColumn *cxGrid1DBTableView1CODENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_TYPE_NOM_LOOCUP;
	TcxGridDBColumn *cxGrid1DBTableView1SHED;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonAddPriceClick(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAMEEDPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameInfBasecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall TypePriceComboBoxPropertiesChange(TObject *Sender);
	void __fastcall TypeRPriceComboBoxPropertiesChange(TObject *Sender);
	void __fastcall cxButtonPoGrpClick(TObject *Sender);
	void __fastcall ActionAddRecordExecute(TObject *Sender);
	void __fastcall ActionDeleteRecordExecute(TObject *Sender);
	void __fastcall NumDoccxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PosDoccxDBDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall PrimcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall EditPropPartcxButtonClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall ActionSetMainTabSheetExecute(TObject *Sender);
	void __fastcall ActionSetAdditionallyTabSheetExecute(TObject *Sender);
	void __fastcall ToolButton5Click(TObject *Sender);


	//внешние формы и скрипты
	void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall ActionPrintExecute(TObject *Sender);
	void __fastcall NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButtonAddOstatkiClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAC_DOSNTPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall NameObjectcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);

	
private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

	//внешние формы и скрипты
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);
	
        void OpenFormSpiskaSprNom(void);
        void OpenFormSpiskaSprEd(void);
        void OpenFormSpiskaSprFirm(void);
        void OpenFormSpiskaSprSklad(void);
        void OpenFormSpiskaSprTypePrice(void);

		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
        void OpenFormSpiskaSprInfBase(void);
		enum  {aoNO,aoAddNewString} ActionOperation;

		IDMSprPrice* DMSprPrice;
		IDMSprARM * DMSprARM;
		IFormaSpiskaSprEd * Ed;
		IFormaSpiskaSprNom * Nom;
		IFormaSpiskaSprFirm * Firma;
		IFormaSpiskaSprSklad * Sklad;
		IFormaSpiskaSprTypePrice *FormaSpiskaSprTypePrice;


		IDMSprTypePrice *DMSprTypePrice;
		IDMSprTypePrice *DMSprTypeRPrice;

		bool flObrabatChangeTypePrice;
		bool flObrabatChangeRoznTypePrice;

		IFormaElementaSprPart *FormaElementaSprPart;
		void OpenFormElementaSprPart(void);
		void __fastcall EndEditPart(void);

		AnsiString VesPrefiksBarCode;
		int VesTypeBarCode;
		int VesTypeSearch;


		double  ObrabotatVesBarCode(AnsiString bar_code,
										 IDMSprNom * nom,
										 IDMSprEd * ed,
										 AnsiString ves_prefiks_bar_code,
										 int ves_type_bar_code,
										 int ves_type_search);

		double RoznSummaForPrint;

			void OpenPrintForm(void);
		void OutputString(TSheetEditor *prForm);
		void OutputZagolovokReport(TSheetEditor *prForm);
		void OutputPodavalReport(TSheetEditor *prForm);
		int numRow;
		int numCol;
		int porNumStr;
			 __int64 VibTovarId;
		 __int64 VibTovarIdGrp;
		 double SummaDoc;


	IFormaSpiskaSprBusinessOper *SpisokBusinessOper;
	void OpenFormSpiskaSprBusinessOper(void);
	void __fastcall EndViborBusinessOper(void);

	IFormaSpiskaSprProject *SpisokProject;
	void OpenFormSpiskaSprProject(void);
	void __fastcall EndViborProject(void);

			 enum  {ER_NoRekv,ER_InfBase, ER_Firm, ER_Klient, ER_Sklad, ER_TypePrice, ER_Part,
					 ER_BusinessOper, ER_Project, ER_Nom, ER_Ed, ER_NO,
					 ER_Object} EditRekvisit;


	IFormaSpiskaSprObject *SpisokObject;
	void OpenFormSpiskaSprObject(void);
	void __fastcall EndViborObject(void);
public:		// User declarations
		__fastcall TFormaDocOstNom(TComponent* Owner);

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

		IDMDocOstNom * DM;


		__int64 IdDoc;           //идентификатор текущей записи


        bool Prosmotr;    //только просмотр
        bool ObjectSave;

		void UpdateForm(void);


		void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocOstNom *FormaDocOstNom;
//---------------------------------------------------------------------------
#endif
