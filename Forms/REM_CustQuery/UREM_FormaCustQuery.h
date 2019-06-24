//---------------------------------------------------------------------------

#ifndef UREM_FormaCustQueryH
#define UREM_FormaCustQueryH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "UDM.h"
#include "IREM_DMCustQuery.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IREM_FormaSpiskaSprModel.h"
#include "IREM_FormaSpiskaSprSostCustQuery.h"
#include "IDMTableExtPrintForm.h"
#include "IFormaSpiskaSprEd.h"
#include "IFormaSpiskaSprNom.h"
#include "IREM_FormaGurZ.h"
#include "IFormaSpiskaSprProducer.h"
#include "IFormaSpiskaSprBrand.h"
#include "IFormaSpiskaSprProducerNom.h"
#include "IREM_FormaSpiskaSprHardware.h"
#include "IREM_FormaSpiskaSprProducerModel.h"
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
#include "cxGridBandedTableView.hpp"
#include "cxGridDBBandedTableView.hpp"
#include "UREM_DMCustQuery.h"
#include "cxDBLabel.hpp"
#include "cxImageComboBox.hpp"
#include "cxSpinEdit.hpp"
#include "cxPC.hpp"
//---------------------------------------------------------------------------
class TREM_FormaCustQuery : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label12;
        TLabel *Label13;
	TDBText *DBTextNameUser;
        TLabel *ProsmotrLabel;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TPanel *Panel5;
	TToolBar *ToolBar1;
	TPanel *Panel6;
	TLabel *Label6;
	TToolButton *ToolButton1;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
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
	TcxDBButtonEdit *NameInfBasecxDBButtonEdit;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TcxDBButtonEdit *NameSkladPrcxDBButtonEdit;
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
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBBandedTableView *cxGrid1DBBandedTableView1;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAMENOM_REM_CQUERYT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1KOL_REM_CQUERYT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1KF_REM_CQUERYT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1PRICE_REM_CQUERYT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1SUM_REM_CQUERYT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1PRICE_DO_REM_CQUERYT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1PRICE_TEC_REM_CQUERYT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1PRICE_SOGL_REM_CQUERYT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1SROK_POST_REM_CQUERYT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1POS_POST_REM_CQUERYT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1RUN_REM_CQUERYT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1COMMENTS_REM_CQUERYT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAMENOM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAMEED;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAME_REM_SSOST_CQUERY;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1RECNO;
	TToolButton *ToolButtonShowHistori;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1ACT_REM_CQUERYT;
	TcxDBImageComboBox *SostcxDBImageComboBox;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1CODENOM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1ARTNOM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1SHED;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1ART_SPRNOM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1CODE_SPRNOM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAME_SPRNOM;
	TcxDBImageComboBox *TypeCQuerycxDBImageComboBox;
	TLabel *Label5;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1ART_REM_CQUERYT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1FL_ADD_IN_SOBORUD_SNOM;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TcxTabSheet *cxTabSheet3;
	TcxTabSheet *cxTabSheet4;
	TcxTabSheet *cxTabSheet5;
	TcxDBButtonEdit *NameBrandcxDBButtonEdit;
	TcxLabel *cxLabel9;
	TLabel *Label27;
	TcxDBButtonEdit *ProducercxDBButtonEdit;
	TcxLabel *cxLabel2;
	TcxDBSpinEdit *NumZakazacxDBSpinEdit;
	TcxLabel *cxLabel3;
	TcxDBDateEdit *DateZakazacxDBDateEdit;
	TcxLabel *cxLabel6;
	TcxDBImageComboBox *KlientUvedomlencxDBImageComboBox;
	TcxLabel *cxLabel5;
	TcxDBDateEdit *PlanPostavkicxDBDateEdit;
	TcxDBDateEdit *ZakazanocxDBDateEdit;
	TcxLabel *cxLabel7;
	TcxDBDateEdit *OtpravlenocxDBDateEdit;
	TcxLabel *cxLabel8;
	TcxLabel *cxLabel4;
	TcxDBDateEdit *PostupilocxDBDateEdit;
	TLabel *Label14;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TLabel *Label19;
	TcxDBTextEdit *KlientNamecxDBTextEdit;
	TLabel *Label20;
	TcxDBTextEdit *KlientAdtrcxDBTextEdit;
	TLabel *Label21;
	TcxDBTextEdit *KlientPhonecxDBTextEdit;
	TcxDBTextEdit *cxDBTexNUM_STR_ZAK_POST_REM_CQUERY;
	TcxDBDateEdit *cxDBDateEditPOS_ZAK_POST_REM_CQUERY;
	TcxDBTextEdit *cxDBTextEditNUM_STR_ZAK_SPROV_REM_CQUERY;
	TcxDBDateEdit *cxDBDateEditPOS_ZAK_SPROV_REM_CQUERY;
	TcxDBTextEdit *cxDBTextEditNUM_DOC_OTPR_POST_REM_CQUERY;
	TcxDBDateEdit *cxDBDateEditPOS_DOC_OTPR_POST_REM_CQUERY;
	TcxDBTextEdit *cxDBTextEditNUMDOCTK_REM_CQUERY;
	TcxDBTextEdit *cxDBTextEditTK_REM_CQUERY;
	TcxDBTextEdit *cxDBTextEditNUM_STR_ZAK_POST_REM_CQUERY;
	TLabel *Label7;
	TLabel *Label16;
	TLabel *Label4;
	TLabel *Label22;
	TcxDBTextEdit *ModelcxDBTextEdit;
	TcxDBButtonEdit *NameProducerModelcxDBButtonEdit;
	TcxDBButtonEdit *NameModelcxDBButtonEdit;
	TcxDBButtonEdit *NameZcxDBButtonEdit;
	TcxLabel *cxLabel1;
	TLabel *Label3;
	TcxDBButtonEdit *NameSprHardwarecxDBButtonEdit;
	TcxDBLabel *SerNumSprHardwarecxDBLabel;
	TcxDBLabel *SerNum2SprhardwarecxDBLabel;
	TcxDBLabel *PosZcxDBLabel;
	TcxDBLabel *NumZcxDBLabel;
	TcxDBLabel *ModelZcxDBLabel;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label15;
	TcxDBLabel *cxDBLabelKLIENT_NAME_REM_CQUERY;
	TcxDBLabel *cxDBLabelNAME_MODEL_REM_CQUERY;
	TcxDBButtonEdit *cxDBButtonEditPRODAVEC_NAME;
	TLabel *Label17;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1REF_REM_CQUERYT;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall NameInfBasecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxDBButtonEdit1PropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladPrcxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
	void __fastcall KlientNamecxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall KlientAdtrcxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall KlientPhonecxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall ModelcxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall SerNumcxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall SerNum2cxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall NamecxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall DescrcxDBTextEditKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall ToolButton1Click(TObject *Sender);
	void __fastcall cxGrid1DBBandedTableView1NAME_REM_SSOST_CQUERYPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButton6Click(TObject *Sender);
	void __fastcall cxGrid1DBBandedTableView1NAMENOMPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameZcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall ToolButtonShowHistoriClick(TObject *Sender);
	void __fastcall ProducercxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall NameBrandcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1NAME_REM_SPRNOMPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSprHardwarecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameProducerModelcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxDBButtonEditPRODAVEC_NAMEPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);










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
		IREM_FormaSpiskaSprSostCustQuery *  REM_FormaSpiskaSprSostCustQuery;

		void __fastcall EventEndEditInfBase(void);
		void __fastcall EventEndEditFirm(void);
		void __fastcall EventEndEditSklad(void);
		void __fastcall EventEndEditKlient(void);
		void __fastcall EventEndEditModel(void);
		void __fastcall EventEndEditSostCustQuery(void);

		enum  { aoNO,aoAddNewString} ActionOperation;
		enum  {ER_NoRekv,ER_InfBase,ER_Firm,ER_Sklad,ER_SkladTec,ER_Klient,ER_Diler,ER_Model,ER_TypeRemont,
						ER_SostCustQuery,ER_Kompl,ER_Neispr, ER_CloseDocRemont, ER_Nom,ER_Ed,ER_Zayavka,
						ER_ViborProducer,
						ER_ViborBrand,
						ER_ViborProducerNom,
						ER_ViborHardware,
						ER_ProducerModel,
						ER_ViborProdavec} EditRekvisit;

		//выбор заявки
		IREM_FormaGurZ* FormaGurZ;
		void ViborRemZ(void);
		void __fastcall EndViborRemZ(void);

		//выбор номенклатуры
		IFormaSpiskaSprNom * FormaSpiskaSprNom;
		void ViborNom(void);
		void __fastcall EndViborNom(void);


		//выбор единицы
		IFormaSpiskaSprEd * FormaSpiskaSprEd;
		void ViborEd(void);
		void __fastcall EndViborEd(void);


		//Бренд
		IFormaSpiskaSprBrand * SpisokBrand;
		void ViborBrand(void);
		void EndViborBrand(void);


		IFormaSpiskaSprProducer* FormaSpiskaSprProducer;
		void ViborProducer(void);
		void EndViborProducer(void);


		IFormaSpiskaSprProducerNom* FormaSpiskaSprProducerNom;
		void ViborProducerNom(void);
		void EndViborProducerNom(void);

				//выбор оборудования
		IREM_FormaSpiskaSprHardware* FormaSpiskaSprHardware;
		void ViborHardware(void);
		void __fastcall EndViborHardware(void);

		IREM_FormaSpiskaSprProducerModel * REM_FormaSpiskaSprProducerModel;
		void __fastcall EventEndEditProducerModel(void);
		void __fastcall ViborProducerModel(void);

		void ViborProdavec(void);
		void __fastcall EndViborProdavec(void);

public:		// User declarations
		__fastcall TREM_FormaCustQuery(TComponent* Owner);

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

		IREM_DMCustQuery *DM;

		bool Prosmotr;    //только просмотр
		__int64 IdCQ;           //идентификатор текущей записи
        __int64 IdCQT;
		void UpdateForm(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaCustQuery *REM_FormaCustQuery;
//---------------------------------------------------------------------------
#endif
