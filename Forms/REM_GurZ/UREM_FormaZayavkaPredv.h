//---------------------------------------------------------------------------

#ifndef UREM_FormaZayavkaPredvH
#define UREM_FormaZayavkaPredvH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "UDM.h"
#include "IREM_DMZayavkaPredv.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaSpiskaSprEd.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IREM_FormaSpiskaSprModel.h"
#include "IREM_FormaSpiskaSprNeispr.h"
#include "IDMTableExtPrintForm.h"
#include "IREM_FormaSpiskaSprHardware.h"
#include "IFormaSpiskaSprBrand.h"
#include "IFormaSpiskaSprProducer.h"
#include "IREM_FormaSpiskaSprProducerModel.h"
#include "IFormaSpiskaSprSeller.h"
#include "IREM_FormaSpiskaSprActCategory.h"

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
#include "cxClasses.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxMaskEdit.hpp"
#include "cxStyles.hpp"
#include "cxTextEdit.hpp"
#include "cxCalendar.hpp"
#include "cxDropDownEdit.hpp"
#include "cxCalc.hpp"
#include "cxCheckBox.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxLookAndFeels.hpp"
#include "cxMemo.hpp"
#include "cxLabel.hpp"
#include "cxImageComboBox.hpp"
#include "cxPC.hpp"
#include "UREM_DMZayavka.h"
#include "cxDBLabel.hpp"
#include "cxSpinEdit.hpp"
//---------------------------------------------------------------------------
class TREM_FormaZayavkaPredv : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel3;
        TPanel *Panel4;
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
	TDBText *DBTextNameUser;
        TLabel *ProsmotrLabel;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TAction *ActionViborInfBase;
	TAction *ActionViborFirm;
	TAction *ActionViborSkladPr;
	TAction *ActionViborDiler;
	TAction *ActionViborKlient;
	TAction *ActionViborTypeRemont;
	TAction *ActionViborModel;
	TAction *ActionViborSost;
	TAction *ActionViborTecSklad;
	TAction *ActionAddNewKompl;
	TAction *ActionEditKompl;
	TAction *ActionAddNeispr;
	TAction *ActionEditNeispr;
	TAction *ActionDeleteKompl;
	TAction *ActionDeleteNeispr;
	TcxDBTextEdit *NumcxDBTextEdit;
	TcxDBDateEdit *PoscxDBDateEdit;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
	TToolBar *ToolBar3;
	TToolButton *ToolButton10;
	TToolButton *ToolButton7;
	TPopupMenu *PopupMenuExtModule;
	TToolButton *ToolButtonCreateDocRemont;
	TToolButton *ToolButtonOpenDocRemont;
	TAction *ActionAddNewDopUsl;
	TAction *ActionDeleteDopUsl;
	TAction *ActionEditNomDopUsl;
	TAction *ActionAddPerformedWork;
	TAction *ActionDeletePerformedWork;
	TAction *ActionEditPerformedWork;
	TcxButton *cxButtonOpenSpisokImage;
	TcxPageControl *cxPageControl2;
	TcxTabSheet *cxTabSheet5;
	TLabel *Label18;
	TcxDBTextEdit *NamecxDBTextEdit;
	TToolButton *ToolButtonCreateCQuery;
	TcxTabSheet *cxTabSheet10;
	TcxDBButtonEdit *NameHardwarecxDBButtonEdit;
	TcxLabel *cxLabel5;
	TcxDBLabel *SerNumcxDBLabel;
	TcxDBLabel *SerNum2cxDBLabel;
	TcxLabel *cxLabel3;
	TcxDBMemo *CommentscxDBMemo;
	TcxDBCalcEdit *cxDBCalcEditSUMNACHA_REM_Z2;
	TLabel *Label11;
	TcxDBMemo *DescrcxDBMemo;
	TLabel *Label7;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TLabel *Label14;
	TLabel *Label19;
	TLabel *Label21;
	TLabel *Label29;
	TLabel *Label20;
	TcxDBTextEdit *KlientAdtrcxDBTextEdit;
	TcxDBTextEdit *EmailcxDBTextEdit;
	TcxDBTextEdit *KlientPhonecxDBTextEdit;
	TcxDBTextEdit *KlientNamecxDBTextEdit;
	TLabel *Label22;
	TLabel *Label17;
	TcxDBTextEdit *SerNumcxDBTextEdit;
	TcxDBTextEdit *ModelcxDBTextEdit;
	TLabel *Label23;
	TcxDBTextEdit *SerNum2cxDBTextEdit;
	TLabel *Label26;
	TcxDBMemo *SostcxDBMemo;
	TcxDBMemo *NeisprcxDBMemo;
	TcxDBButtonEdit *NameBrandcxDBButtonEdit;
	TcxLabel *cxLabel9;
	TcxLabel *cxLabel10;
	TLabel *Label16;
	TcxLabel *cxLabel11;
	TcxLabel *cxLabel16;
	TcxDBButtonEdit *SellercxDBButtonEdit;
	TcxDBButtonEdit *ProducerModelcxDBButtonEdit;
	TcxDBButtonEdit *NameModelcxDBButtonEdit;
	TcxDBButtonEdit *NameproducercxDBButtonEdit;
	TLabel *Label4;
	TcxDBButtonEdit *NameSkladPrcxDBButtonEdit;
	TLabel *Label13;
	TcxLabel *cxLabel17;
	TcxDBButtonEdit *NameActivecategorycxDBButtonEdit;
	TcxDBButtonEdit *NameDialercxDBButtonEdit;
	TLabel *Label3;
	TLabel *Label12;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TcxDBButtonEdit *NameInfBasecxDBButtonEdit;
	TLabel *Label6;
	TLabel *Label33;
	TcxDBTextEdit *IDcxDBTextEdit;
	TLabel *Label5;
	TcxDBCalcEdit *cxDBCalcEditSUMKLIENTA_REM_Z2;
	TcxDBMemo *cxDBMemoPRICHINA_REM_Z2;
	TLabel *Label8;
	TLabel *Label9;
	TcxDBImageComboBox *cxDBImageComboBoxRESULT_REM_Z2;
	TcxDBSpinEdit *cxDBSpinEditSROK_REM_Z2;
	TLabel *Label10;
	TcxDBImageComboBox *cxDBImageComboBoxPRICHINA_LIST_REM_Z2;
	TLabel *Label15;
	TcxDBMemo *cxDBMemoDOPOPISANIE_REM_Z2;
	TLabel *Label24;
	TToolButton *ToolButton1;
	TToolButton *ToolButtonCreateZayavku;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall NameInfBasecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxDBButtonEdit1PropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladPrcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameDialercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameModelcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);

						//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall NumcxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall PoscxDBDateEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall KlientNamecxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall KlientAdtrcxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall KlientPhonecxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall ModelcxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall SerNumcxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall SerNum2cxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall NamecxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall DescrcxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall NameHardwarecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameBrandcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall NameproducercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall SellercxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall NameActivecategorycxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButtonCreateZayavkuClick(TObject *Sender);











private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

			//внешние формы и скрипты
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

		void OpenFormSpiskaSprInfBase(void);
		void OpenFormSpiskaSprFirm(void);
		void OpenFormSpiskaSprSklad(void);
		void OpenFormSpiskaSprKlient(void);



		IFormaSpiskaSprFirm * FormaSpiskaSprFirm;
		IFormaSpiskaSprKlient * FormaSpiskaSprKlient;
		IFormaSpiskaSprSklad *  FormaSpiskaSprSklad;
		IFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
		IREM_FormaSpiskaSprModel * REM_FormaSpiskaSprModel;
		IREM_FormaSpiskaSprNeispr * REM_FormaSpiskaSprNeispr;


		void __fastcall EventEndEditInfBase(void);
		void __fastcall EventEndEditFirm(void);
		void __fastcall EventEndEditSkladPr(void);
		void __fastcall EventEndEditKlient(void);
		void __fastcall EventEndEditDiler(void);
		void __fastcall EventEndEditModel(void);





		enum  { aoNO,aoAddNewString} ActionOperation;
		enum  {ER_NoRekv,ER_InfBase,ER_Firm,ER_SkladPr,ER_SkladTec,ER_Klient,ER_Diler,ER_Model,ER_TypeRemont,
						ER_TecSost,ER_Kompl,ER_Neispr, ER_CloseDocRemont,
						ER_ViborNomDopUsl, ER_ViborEdDopUsl,
						ER_ViborNomPerfWork, ER_ViborEdPerfWork,
						ER_ViborFoto,
						ER_ViborHardware,
						ER_ViborBrand,
						ER_ViborProducer,
						ER_ViborSeller,
						ER_ViborProducerModel,
						ER_ViborActCategory,
						ER_ViborEngTypDefect,
						ER_ViborEngTypRabot,
						ER_ViborAddress,
						ER_ViborProducerNeispr} EditRekvisit;


		//выбор оборудования
		IREM_FormaSpiskaSprHardware* FormaSpiskaSprHardware;
		void ViborHardware(void);
		void __fastcall EndViborHardware(void);

		//Бренд
		IFormaSpiskaSprBrand * SpisokBrand;
		void ViborBrand(void);
		void __fastcall EndViborBrand(void);



		IFormaSpiskaSprProducer * FormaSpiskaSprProducer;
		void ViborProducer(void);
		void EventEndEditProdcer(void);


		IFormaSpiskaSprSeller* FormaSpiskaSprSeller;
		void ViborSeller(void);
		void EndViborSeller(void);

		IREM_FormaSpiskaSprActCategory * REM_FormaSpiskaSprActCategory;
		void ViborActCategory(void);
		void EndViborActCategory(void);

public:		// User declarations
		__fastcall TREM_FormaZayavkaPredv(TComponent* Owner);

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

		IREM_DMZayavkaPredv *DM;

		bool Prosmotr;    //только просмотр
		__int64 IdZ;           //идентификатор текущей записи
		void UpdateForm(void);
		void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaZayavkaPredv *REM_FormaZayavkaPredv;
//---------------------------------------------------------------------------
#endif
