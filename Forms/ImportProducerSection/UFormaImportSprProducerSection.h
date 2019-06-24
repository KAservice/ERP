//---------------------------------------------------------------------------

#ifndef UFormaImportSprProducerSectionH
#define UFormaImportSprProducerSectionH
//---------------------------------------------------------------------------
#include "IFormaSpiskaSprInfBase.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprImportSet.h"
#include "IDMSprImportSet.h"

#include "IDMFibConnection.h"

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
class TFormaImportSprProducerSection : public TForm
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
	TLabel *Label4;
	TcxSpinEdit *NamecxSpinEdit;
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
	TcxGridBandedColumn *cxGrid1BandedTableView1ID_REM_SPRSECTION;
	TcxGridBandedColumn *cxGrid1BandedTableView1NAME;
	TcxButton *cxButtonUpdateSpr;
	TLabel *LabelError;
	TcxButtonEdit *NameGrpNomcxButtonEdit;
	TLabel *Label20;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TAction *ActionDeleteString;
	TcxButton *cxButtonDelString;
	TAction *ActionClose;
	TcxGridBandedColumn *cxGrid1BandedTableView1ART;
	TcxSpinEdit *ArtcxSpinEdit;
	TLabel *Label21;
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
	TcxTabSheet *cxTabSheet4;
	TcxButton *cxButtonProverit;
	TcxGrid *cxGrid3;
	TcxGridDBTableView *cxGridDBTableView2;
	TcxGridBandedTableView *cxGridBandedTableView2;
	TcxGridBandedColumn *TableUpdateID_REM_SPRSECTION;
	TcxGridBandedColumn *TableUpdateART;
	TcxGridBandedColumn *TableUpdateNAME;
	TcxGridLevel *cxGridLevel2;
	TcxGridBandedColumn *TableUpdateTypeUpdate;
	TcxSpinEdit *NumLastStringcxSpinEdit;
	TLabel *Label32;
	TProgressBar *ProgressBar1;
	TLabel *LabelInfo;
	TcxGridBandedColumn *cxGrid1BandedTableView1NAME_ENG;
	TcxGridBandedColumn *TableUpdateNAME_ENG;
	TLabel *Label2;
	TcxSpinEdit *NameEngcxSpinEdit;
	TcxCheckBox *cxCheckBoxVidelyatCod;
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
	void __fastcall cxButtonUpdateSprClick(TObject *Sender);
	void __fastcall cxButtonDelStringClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
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


		int KolRecordUpdate;

			void VidelitCodIsNameRus(UnicodeString * out_name, UnicodeString * out_code, UnicodeString in_name);

public:		// User declarations
	__fastcall TFormaImportSprProducerSection(TComponent* Owner);

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
extern PACKAGE TFormaImportSprProducerSection *FormaImportSprProducerSection;
//---------------------------------------------------------------------------
#endif
