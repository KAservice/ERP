//---------------------------------------------------------------------------

#ifndef UFormaImportSprProducerNomH
#define UFormaImportSprProducerNomH
//---------------------------------------------------------------------------
#include "IFormaSpiskaSprInfBase.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaSpiskaSprEd.h"
#include "IFormaSpiskaSprImportSet.h"
#include "IDMSprImportSet.h"
#include "IFormaSpiskaSprGrpNom.h"
#include "IDMFibConnection.h"
#include "IFormaSprNomFind.h"
#include "IFormaSpiskaSprProducer.h"
//----------------------------------------------------------------------------

#include "cxButtonEdit.hpp"
#include "cxButtons.hpp"
#include "cxCalc.hpp"
#include "cxCheckBox.hpp"
#include "cxClasses.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridBandedTableView.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxMaskEdit.hpp"
#include "cxPC.hpp"
#include "cxSpinEdit.hpp"
#include "cxSSheet.hpp"
#include "cxStyles.hpp"
#include "cxTextEdit.hpp"
#include <ActnList.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <DB.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <StdCtrls.hpp>

#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include "cxMemo.hpp"
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
class TFormaImportSprProducerNom : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TLabel *Label1;
	TcxButton *cxButtonClose;
	TOpenDialog *OpenDialog1;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TPanel *Panel3;
	TLabel *Label3;
	TcxSpinEdit *StartStringcxSpinEdit;
	TLabel *Label2;
	TcxSpinEdit *CodeNomcxSpinEdit;
	TLabel *Label5;
	TcxSpinEdit *KolcxSpinEdit;
	TLabel *Label4;
	TcxSpinEdit *NameNomcxSpinEdit;
	TLabel *Label7;
	TcxSpinEdit *PricecxSpinEdit;
	TLabel *Label9;
	TcxSpinEdit *RoznPricecxSpinEdit;
	TLabel *Label6;
	TcxSpinEdit *NameEdcxSpinEdit;
	TLabel *Label8;
	TcxSpinEdit *SumcxSpinEdit;
	TLabel *Label10;
	TcxSpinEdit *RoznSumcxSpinEdit;
	TLabel *Label12;
	TcxComboBox *TypeSearchcxComboBox;
	TcxSpreadSheet *cxSpreadSheet1;
	TcxButtonEdit *FileNamecxButtonEdit;
	TLabel *Label13;
	TLabel *Label11;
	TcxButtonEdit *NameImportSetcxButtonEdit;
	TcxButton *cxButtonSaveParams;
	TcxButtonEdit *NameInfBasecxButtonEdit;
	TcxButtonEdit *NameFirmcxButtonEdit;
	TcxButtonEdit *NameSkladcxButtonEdit;
	TcxButtonEdit *NameKlientcxButtonEdit;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TcxButton *cxButtonImport;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridBandedTableView *cxGrid1BandedTableView1;
	TcxGridBandedColumn *cxGrid1BandedTableView1IDNOM;
	TcxGridBandedColumn *cxGrid1BandedTableView1CODENOM;
	TcxGridBandedColumn *cxGrid1BandedTableView1NAMENOMPOST;
	TcxGridBandedColumn *cxGrid1BandedTableView1KOL;
	TcxGridBandedColumn *cxGrid1BandedTableView1NAMEED;
	TcxGridBandedColumn *cxGrid1BandedTableView1ROZNPRICE;
	TcxGridBandedColumn *cxGrid1BandedTableView1ROZNSUM;
	TcxButton *cxButtonSynhro;
	TcxButton *cxButtonUpdateSpr;
	TcxSpinEdit *BarCodecxSpinEdit;
	TLabel *Label18;
	TcxGridBandedColumn *cxGrid1BandedTableView1BARCODE;
	TcxGridBandedColumn *cxGrid1BandedTableView1PRICE;
	TcxGridBandedColumn *cxGrid1BandedTableView1SUM;
	TLabel *Label19;
	TcxCheckBox *ExternalCodcxCheckBox;
	TcxCheckBox *ExternalBarCodecxCheckBox;
	TLabel *LabelError;
	TcxButtonEdit *NameGrpNomcxButtonEdit;
	TLabel *Label20;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TAction *ActionDeleteString;
	TcxButton *cxButtonDelString;
	TAction *ActionClose;
	TcxGridBandedColumn *cxGrid1BandedTableView1ARTNOM;
	TcxSpinEdit *ArtNomcxSpinEdit;
	TLabel *Label21;
	TcxSpinEdit *CountrycxSpinEdit;
	TcxSpinEdit *GTDcxSpinEdit;
	TLabel *Label22;
	TLabel *Label23;
	TcxGridBandedColumn *cxGrid1BandedTableView1COUNTRY;
	TcxGridBandedColumn *cxGrid1BandedTableView1GTD;
	TToolBar *ToolBar1;
	TToolButton *ToolButtonNoAddNomInSpr;
	TToolButton *ToolButton2;
	TToolButton *ToolButtonAddNewNom;
	TLabel *Label24;
	TcxButtonEdit *NameProducercxButtonEdit;
	TcxSpinEdit *KolErrorForStopcxSpinEdit;
	TLabel *Label25;
	TToolButton *ToolButtonSaveExcel;
	TSaveDialog *SaveDialog1;
	TcxSpinEdit *TypeNomcxSpinEdit;
	TLabel *Label26;
	TLabel *Label27;
	TLabel *Label28;
	TLabel *Label29;
	TLabel *Label30;
	TLabel *Label31;
	TcxSpinEdit *DostupnocxSpinEdit;
	TcxSpinEdit *ModelcxSpinEdit;
	TcxSpinEdit *AnalogcxSpinEdit;
	TcxSpinEdit *FullNamecxSpinEdit;
	TcxSpinEdit *KrNamecxSpinEdit;
	TcxGridBandedColumn *cxGrid1BandedTableView1TNOM;
	TcxGridBandedColumn *cxGrid1BandedTableView1MODEL;
	TcxGridBandedColumn *cxGrid1BandedTableView1ANALOG;
	TcxGridBandedColumn *cxGrid1BandedTableView1DOSTUPNO;
	TcxGridBandedColumn *cxGrid1BandedTableView1FULLNAME;
	TcxGridBandedColumn *cxGrid1BandedTableView1KRNAME;
	TcxCheckBox *ZamenacxCheckBox;
	TcxTabSheet *cxTabSheet4;
	TcxButton *cxButtonProverit;
	TcxGrid *cxGrid3;
	TcxGridDBTableView *cxGridDBTableView2;
	TcxGridBandedTableView *cxGridBandedTableView2;
	TcxGridBandedColumn *TableUpdateID_SPRNOM;
	TcxGridBandedColumn *TableUpdateCODE_SPRNOM;
	TcxGridBandedColumn *TableUpdateART_SPRNOM;
	TcxGridBandedColumn *TableUpdateNAME_SPRNOM;
	TcxGridBandedColumn *TableUpdatePRICE_ZAKUP_SPRNOM;
	TcxGridBandedColumn *TableUpdatePRICE_SPRNOM;
	TcxGridBandedColumn *TableUpdateCODE_ANALOG_STR_SPRNOM;
	TcxGridBandedColumn *TableUpdateMODEL_STR_SPRNOM;
	TcxGridBandedColumn *TableUpdateFL_DOSTUPNO_SPRNOM;
	TcxGridLevel *cxGridLevel2;
	TcxGridBandedColumn *TableUpdateTypeUpdate;
	TcxGridBandedColumn *TableUpdateFNAME_SPRNOM;
	TcxGridBandedColumn *TableUpdateKRNAME_SPRNOM;
	TcxSpinEdit *NumLastStringcxSpinEdit;
	TLabel *Label32;
	TProgressBar *ProgressBar1;
	TcxSpinEdit *RepairCodecxSpinEdit;
	TcxSpinEdit *LocationcxSpinEdit;
	TLabel *Label33;
	TLabel *Label34;
	TcxGridBandedColumn *cxGrid1BandedTableView1REP_CODE;
	TcxGridBandedColumn *cxGrid1BandedTableView1LOCATION;
	TcxGridBandedColumn *TableUpdateREPAIRCODE_SPRNOM;
	TcxGridBandedColumn *TableUpdateLOCATION_SPRNOM;
	TLabel *LabelInfo;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FileNamecxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameImportSetcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonSaveParamsClick(TObject *Sender);
	void __fastcall cxButtonImportClick(TObject *Sender);
	void __fastcall NameInfBasecxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameKlientcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1BandedTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxButtonSynhroClick(TObject *Sender);
	void __fastcall cxButtonUpdateSprClick(TObject *Sender);
	void __fastcall ExternalCodcxCheckBoxPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall ExternalBarCodecxCheckBoxPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error);
	void __fastcall NameGrpNomcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxButtonDelStringClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall ToolButtonNoAddNomInSprClick(TObject *Sender);
	void __fastcall ToolButtonAddNewNomClick(TObject *Sender);
	void __fastcall NameProducercxButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall ToolButtonSaveExcelClick(TObject *Sender);
	void __fastcall cxButtonProveritClick(TObject *Sender);

private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму


	  IFormaSpiskaSprImportSet * FormaSpiskaSprImportSet;
	  void OpenFormSpiskaSprImportSet(void);
	  void __fastcall EndViborImportSet(void);


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

		//выбор поставщика
		IFormaSpiskaSprKlient * FormaSpiskaSprKlient;
		void ViborKlient(void);
		void __fastcall EndViborKlient(void);

		//выбор группы номенклатуры
		IFormaSpiskaSprGrpNom * FormaSpiskaSprGrpNom;
		void ViborGrpNom(void);
		void __fastcall EndViborGrpNom(void);

		//выбор номенклатуры
		IFormaSpiskaSprNom * FormaSpiskaSprNom;
		void ViborNom(void);
		void __fastcall EndViborNom(void);

		//выбор номенклатуры
		IFormaSprNomFind * FormaSprNomFind;
		void ViborNomFind(void);
		void __fastcall EndViborNomFind(void);

		//выбор единицы
		IFormaSpiskaSprEd * FormaSpiskaSprEd;
		void ViborEd(void);
		void __fastcall EndViborEd(void);

	enum {ER_NoRekv,ER_ImportSet, ER_InfBase, ER_Firm, ER_Sklad, ER_Post,
						ER_GrpNom, ER_Nom, ER_Ed,
						ER_NomFind,ER_ViborProducer, ER_No}  EditRekvisit;

	void UpdateSetup(void);
	void SaveSetup(void);
	IDMSprImportSet * DMSprImportSet;

	__int64 VibTovarId;
	__int64 VibTovarIdGrp;



//UnicodeString	FormatTxtString(UnicodeString s);
		IFormaSpiskaSprProducer * SpisokProducer;
		void OpenFormSpiskaSprProducer(void);

		double GetRoznPrice(double price);

		int KolRecordUpdate;

public:		// User declarations
	__fastcall TFormaImportSprProducerNom(TComponent* Owner);

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

   __int64 IdInfBase;
   __int64 IdFirm;
   __int64 IdSklad;
   __int64 IdKlient;
   __int64 IdGrpNom;
  __int64 IdProducer;

    void UpdateForm(void);



	__int64 IdImportSet;

    void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaImportSprProducerNom *FormaImportSprProducerNom;
//---------------------------------------------------------------------------
#endif
