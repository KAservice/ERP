//---------------------------------------------------------------------------

#ifndef UREM_FormaDocZAktPrH
#define UREM_FormaDocZAktPrH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IDMSprTypePrice.h"
#include "UDM.h"
#include "IFormaSpiskaSprEd.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprSklad.h"
#include "IREM_DMDocZAktPr.h"
#include "IREM_FormaGurZ.h"
#include "IFormaSpiskaSprKlient.h"
#include "IDMTableExtPrintForm.h"
#include "IREM_FormaSpiskaSprHardware.h"

#include "IFormaSpiskaSprProducer.h"
#include "IFormaSpiskaSprSeller.h"
#include "IREM_FormaSpiskaSprProducerModel.h"
#include "IREM_FormaSpiskaSprProducerNeispr.h"
#include "IFormaSpiskaSprProject.h"
#include "IFormaSpiskaSprBusinessOper.h"

#include "IREM_FormaSpiskaSprProducerDefect.h"
#include "IREM_FormaSpiskaSprProducerNeispr.h"
#include "IREM_FormaSpiskaSprProducerRabota.h"
#include "IFormaInputText.h"
#include "IREM_FormaElementaSprHardware.h"
#include "IREM_FormaSpiskaSprProducerCondition.h"
#include "IREM_FormaSpiskaSprProducerSection.h"
#include "IREM_FormaSpiskaSprTypUslov.h"
#include "IFormaSpiskaSprStorageLocation.h"
//--------------------------------------------------------------------------
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
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
#include "cxDBLookupComboBox.hpp"
#include "cxDBLookupEdit.hpp"
#include "cxLookupEdit.hpp"
#include "cxDBLabel.hpp"
#include "cxGridBandedTableView.hpp"
#include "cxGridDBBandedTableView.hpp"
#include "cxLookAndFeels.hpp"
#include "cxImageComboBox.hpp"
#include "cxMemo.hpp"
#include "cxPC.hpp"
//---------------------------------------------------------------------------
class TREM_FormaDocZAktPr : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
        TToolBar *ToolBar2;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonInsert;
        TToolButton *ToolButtonDelete;
        TLabel *Label5;
        TLabel *Label6;
        TDBText *DBTextFNameUser;
        TLabel *ProsmotrLabel;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
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
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionDvReg;
	TAction *ActionSave;
	TAction *ActionPrint;
	TToolButton *ToolButtonOpenExtModule;
	TPopupMenu *PopupMenuExtModule;
	TToolButton *ToolButtonCreateCheck;
	TToolButton *ToolButtonCreateRealRozn;
	TToolButton *ToolButtonCreateReal;
	TcxDBImageComboBox *TypeRemontcxDBImageComboBox;
	TLabel *Label12;
	TToolButton *ToolButtonOpenGarTalon;
	TcxLabel *cxLabel9;
	TcxDBButtonEdit *NameBusinessOpercxDBButtonEdit;
	TcxDBButtonEdit *NameProjectcxDBButtonEdit;
	TcxLabel *cxLabel4;
	TToolButton *ToolButtonZapolnit;
	TToolButton *ToolButtonOpenZayavka;
	TToolButton *ToolButtonCopyPrimkaGarant;
	TToolButton *ToolButtonSetOtchitanZayvka;
	TToolButton *ToolButtonCreateDocRemont;
	TToolButton *ToolButtonAddDataIsZayavki;
	TToolButton *ToolButton4;
	TToolButton *ToolButtonOpenFormNewHW;
	TToolButton *ToolButtonOpenFormOldHW;
	TToolButton *ToolButton5;
	TToolButton *ToolButtonAddPoCodHW;
	TToolButton *ToolButtonAddPoIdHW;
	TToolButton *ToolButton6;
	TToolButton *ToolButtonAddOldPoCoduHW;
	TToolButton *ToolButtonAddOldHWPoID;
	TToolButton *ToolButtonNewOldHW;
	TToolButton *ToolButton7;
	TToolButton *ToolButtonAddPoCoduNom;
	TcxGridDBBandedTableView *cxGrid1DBBandedTableView1;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAME_REM_SPRCOND_GRP;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAME_REM_SPRCONDITION;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAME_REM_SPRNEISPR;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAME_REM_SPRSECTION_GRP;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAME_REM_SPRSECTION;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAME_REM_SPRDEFECT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAME_REM_SPRRABOTA;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAMENOM;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAME_REM_SHARDWARE;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1CODE_REM_SHARDWARE;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1SERNUM_REM_SHARDWARE;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1OLD_CODE_REM_SHARDWARE;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1OLD_NAME_REM_SHARDWARE;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1OLD_SERNUM_REM_SHARDWARE;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1KOL_REM_DZAKTPRT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1KF_REM_DZAKTPRT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1PRICE_REM_DZAKTPRT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1SUM_REM_DZAKTPRT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1DVREG_REM_DZAKTPRT;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TcxTabSheet *cxTabSheet3;
	TcxTabSheet *cxTabSheet4;
	TcxDBButtonEdit *ProducercxDBButtonEdit;
	TLabel *Label27;
	TLabel *Label4;
	TLabel *Label34;
	TcxDBButtonEdit *NamePostZipcxDBButtonEdit;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TcxDBTextEdit *PrimcxDBTextEdit;
	TLabel *Label3;
	TcxDBCheckBox *OtchetPostcxDBCheckBox;
	TcxDBCheckBox *PrigKGarRemontucxDBCheckBox;
	TLabel *RTPriceLabel;
	TcxDBLookupComboBox *TypePricecxDBLookupComboBox;
	TcxDBImageComboBox *KEM_SDANOcxDBImageComboBox;
	TLabel *Label13;
	TLabel *Label29;
	TcxDBLabel *NeisprZcxDBLabel;
	TLabel *Label30;
	TcxDBTextEdit *NeisprcxDBTextEdit;
	TcxButton *cxButtonCopyNeispr;
	TcxDBLabel *CodeNeisprPrcxDBLabel;
	TcxDBLabel *NameGrpCFCcxDBLabel;
	TcxDBButtonEdit *CFCcxDBButtonEdit;
	TLabel *Label14;
	TLabel *Label15;
	TcxDBButtonEdit *DFCcxDBButtonEdit;
	TcxDBTextEdit *KlientPhonecxDBTextEdit;
	TLabel *Label33;
	TcxDBMemo *ClientAdrcxDBMemo;
	TLabel *Label32;
	TcxDBTextEdit *KlientNаmecxDBTextEdit;
	TcxButton *cxButtonZapolnIsZayvki;
	TcxButton *cxButtonViborIsSpr;
	TLabel *Label31;
	TLabel *Label28;
	TcxDBButtonEdit *ProducerModelcxDBButtonEdit;
	TcxDBTextEdit *CodePrModelcxDBTextEdit;
	TLabel *Label35;
	TLabel *Label23;
	TcxDBTextEdit *NumGTcxDBTextEdit;
	TcxButton *cxButtonCopyNemGT;
	TcxDBTextEdit *SerNumcxDBTextEdit;
	TcxDBTextEdit *SerNum2cxDBTextEdit;
	TcxDBTextEdit *SerNum3cxDBTextEdit;
	TcxDBTextEdit *SerNum4cxDBTextEdit;
	TcxDBTextEdit *NumBatcxDBTextEdit;
	TLabel *Label24;
	TLabel *Label26;
	TLabel *Label25;
	TLabel *Label11;
	TLabel *Label10;
	TcxDBDateEdit *DateVipuskcxDBDateEdit;
	TLabel *Label20;
	TLabel *Label21;
	TcxDBDateEdit *DateProdagicxDBDateEdit;
	TLabel *Label22;
	TcxDBTextEdit *ProdaveccxDBTextEdit;
	TLabel *Label16;
	TcxDBTextEdit *PODOcxDBTextEdit;
	TcxDBTextEdit *POPOSLEcxDBTextEdit;
	TLabel *Label40;
	TLabel *Label42;
	TcxDBButtonEdit *NameSSellercxDBButtonEdit;
	TLabel *Label18;
	TLabel *Label19;
	TcxDBTextEdit *DescrcxDBTextEdit;
	TcxDBTextEdit *SOSTcxDBTextEdit;
	TcxDBCheckBox *FictivcxDBCheckBox;
	TcxDBCheckBox *flNeOtchcxDBCheckBox;
	TcxDBCheckBox *flNadoOtchcxDBCheckBox;
	TcxDBDateEdit *PosPriemacxDBDateEdit;
	TLabel *Label36;
	TcxTabSheet *cxTabSheet5;
	TLabel *Label7;
	TcxDBButtonEdit *NameZcxDBButtonEdit;
	TcxDBLabel *NumZcxDBLabel;
	TLabel *Label8;
	TcxDBLabel *NameKlientcxDBLabel;
	TcxDBLabel *ModelcxDBLabel;
	TLabel *Label9;
	TcxDBLabel *PosZcxDBLabel;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1FL_VOSVRAT_ZIP_REM_DZAKTPRT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1FL_ISP_REM_DZAKTPRT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1CODE_REM_SPRCOND_GRP;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1CODE_REM_SPRCONDITION;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1CODE_REM_SPRNEISPR;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAME_REM_SPRNEISPR_GRP;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1CODE_REM_SPRSECTION;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1CODE_REM_SPRDEFECT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1CODE_REM_SPRRABOTA;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1IDHW_REM_DZAKTPRT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1IDHWOLD_REM_DZAKTPRT;
	TDBText *DBTextSUM_REM_GALLDOC;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1Column1;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1CODE_REM_SPRSECTION_GRP;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1Column2;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAME_REM_SPRDEFECT_GRP;
	TToolButton *ToolButton8;
	TToolButton *ToolButton9;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1ARTNOM;
	TToolButton *ToolButtonAddStrin;
	TToolButton *ToolButtonOpenGarTalonIsZayavkiPoNumGarTalona;
	TToolButton *ToolButtonOpenFilePoZayavkePoSerNum1;
	TcxDBCheckBox *cxDBCheckBoxFL_OST_NA_OTV_XRAN_REM_DZAKTPR;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAME_TYPE_NOM_LOOCUP;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAME_REM_STYPUSLOV;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1DESCR_REM_DZAKTPRT;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1DONOR_NAME_REM_SHARDWARE;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1DONOR_CODE_REM_SHARDWARE;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1DONOR_SERNUM_REM_SHARDWARE;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1IDHW_DONOR_REM_DZAKTPRT;
	TcxDBButtonEdit *cxDBButtonEdit1;
	TToolButton *ToolButtonCreateDocVzip;
	TcxGridDBBandedColumn *cxGrid1DBBandedTableView1NAME_SMHRAN;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
 //       void __fastcall AddNewStringClick(TObject *Sender);
 //       void __fastcall DeleteStringClick(TObject *Sender);
        void __fastcall NumberDocKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FDateDocKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall PrimKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall TypeRPriceComboBoxPropertiesChange(TObject *Sender);
	void __fastcall PosDoccxDBDateEditPropertiesChange(TObject *Sender);
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
	void __fastcall PrimcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall NameKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameZcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAMEEDPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionDvRegExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);

					//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAME_REM_SHARDWAREPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ProducercxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall ProducerModelcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall CFCcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall DFCcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall cxButtonCopyNeisprClick(TObject *Sender);
	void __fastcall cxButtonCopyNemGTClick(TObject *Sender);
	void __fastcall ToolButtonOpenGarTalonClick(TObject *Sender);
	void __fastcall NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButtonZapolnitClick(TObject *Sender);
	void __fastcall cxButtonZapolnIsZayvkiClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAME_REM_SPRDEFECTPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButtonOpenZayavkaClick(TObject *Sender);
	void __fastcall ToolButtonSetOtchitanZayvkaClick(TObject *Sender);
	void __fastcall ToolButtonCopyPrimkaGarantClick(TObject *Sender);
	void __fastcall cxButtonViborIsSprClick(TObject *Sender);
	void __fastcall NamePostZipcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButtonCreateDocRemontClick(TObject *Sender);
	void __fastcall NameSSellercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButtonAddDataIsZayavkiClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAME_REM_SPRNEISPRPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAME_REM_SPRRABOTAPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBTableView1OLD_NAME_REM_SHARDWAREPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButtonOpenFormNewHWClick(TObject *Sender);
	void __fastcall ToolButtonOpenFormOldHWClick(TObject *Sender);
	void __fastcall ToolButtonNewOldHWClick(TObject *Sender);
	void __fastcall ToolButtonAddPoCodHWClick(TObject *Sender);
	void __fastcall ToolButtonAddPoIdHWClick(TObject *Sender);
	void __fastcall ToolButtonAddOldPoCoduHWClick(TObject *Sender);
	void __fastcall ToolButtonAddOldHWPoIDClick(TObject *Sender);
	void __fastcall ToolButtonAddPoCoduNomClick(TObject *Sender);
	void __fastcall cxGrid1DBBandedTableView1NAME_REM_SPRCONDITIONPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1NAME_REM_SPRNEISPRPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1NAME_REM_SPRSECTIONPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1NAME_REM_SPRDEFECTPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1NAME_REM_SPRRABOTAPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1NAMENOMPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1NAME_REM_SHARDWAREPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1OLD_NAME_REM_SHARDWAREPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButton9Click(TObject *Sender);
	void __fastcall ToolButtonAddStrinClick(TObject *Sender);
	void __fastcall ToolButtonOpenGarTalonIsZayavkiPoNumGarTalonaClick(TObject *Sender);
	void __fastcall ToolButtonOpenFilePoZayavkePoSerNum1Click(TObject *Sender);
	void __fastcall cxGrid1DBBandedTableView1DONOR_NAME_REM_SHARDWAREPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBBandedTableView1NAME_REM_STYPUSLOVPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButtonCreateDocVzipClick(TObject *Sender);
	void __fastcall cxGrid1DBBandedTableView1NAME_SMHRANPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);




private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

			//внешние формы и скрипты
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

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

		//выбор клиента
		IFormaSpiskaSprKlient * FormaSpiskaSprKlient;
		void ViborKlient(void);
		void __fastcall EndViborKlient(void);

		void ViborVlad(void);
		void __fastcall EndViborVlad(void);

		void ViborPostZIP(void);
		void __fastcall EndViborPostZIP(void);

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

		enum  { aoNO,aoAddNewString} ActionOperation;
		enum {ER_NoRekv,ER_No, ER_InfBase,ER_Firm,ER_Sklad,ER_Klient,
						ER_Zayavka,ER_Nom,ER_Ed, ER_Hardware,ER_CreateCheck,
						ER_ViborProducer,
						ER_ViborProducerModel,
						ER_ViborCFC, ER_ViborDFC,ER_BusinessOper, ER_Project,
						ER_ProducerDefect,
						ER_ViborVlad,
						ER_Post_ZIP,
						ER_CloseDocRemont,
						ER_ViborSeller,
						ER_Hardware_Old,
						ER_Hardware_Donor,
						ER_ProducerNeisprTable,
						ER_Rabota,
						ER_ElementHWNew,
						ER_ElementHWOld,
						ER_NewElementHWOld,
						ER_InputCodeHW, ER_InputIdHW,
						ER_InputBarCode,
						ER_InputCodeNom,
						ER_InputCodeHWOld, ER_InputIdHWOld,
						ER_ViborProducerCondition,
						ER_ViborProducerSection,
						ER_ViborTypUsla,
						ER_ViborStorageLocation} EDitRekvisit;

		IDMSprTypePrice *DMSprTypeRPrice;
		void BeforeSaveDoc(void);

		void AfterSaveDoc(void);



		 //выбор оборудования
		IREM_FormaSpiskaSprHardware* FormaSpiskaSprHardware;
		void ViborHardware(void);
		void EndViborHardware(void);



		IFormaSpiskaSprProducer* FormaSpiskaSprProducer;
		void ViborProducer(void);
		void EndViborProducer(void);

		IFormaSpiskaSprSeller* FormaSpiskaSprSeller;
		void ViborSeller(void);
		void EndViborSeller(void);

		IREM_FormaSpiskaSprProducerModel* FormaSpiskaSprProducerModel;
		void ViborProducerModel(void);
		void EndViborProducerModel(void);

		IREM_FormaSpiskaSprProducerNeispr* FormaSpiskaSprProducerNeispr;
		void ViborCFC(void);
		void EndViborCFC(void);

		void ViborDFC(void);
		void EndViborDFC(void);

		IFormaSpiskaSprBusinessOper *SpisokBusinessOper;
	void OpenFormSpiskaSprBusinessOper(void);
	void EndViborBusinessOper(void);

	IFormaSpiskaSprProject *SpisokProject;
	void OpenFormSpiskaSprProject(void);
	void EndViborProject(void);

			//выбор
		IREM_FormaSpiskaSprProducerDefect * FormaSpiskaSprProducerDefect;
		void ViborProducerDefect(void);
		void __fastcall EndViborProducerDefect(void);


		int CheckDetalForOtchetPost(__int64 id_nom, double kol);


		void ViborOldHardware(void);
		void EndViborOldHardware(void);

		void ViborProducerNeisprTable(void);
		void EndViborProducerNeisprTable(void);

		IREM_FormaSpiskaSprProducerRabota * FormaSpiskaSprProducerRabota;
		void ViborProducerRabota(void);
		void __fastcall EndViborProducerRabota(void);

		IFormaInputText* FormaInputText;
		void OpenFormInputCodeHW(void);
		void EndInputCodeHW(void);

		void OpenFormInputIdHW(void);
		void EndInputIdHW(void);

		void EndCreateNewElementOldHardware(void);
		IREM_FormaElementaSprHardware * FormaElementaSprHW;


		void OpenFormInputCodeHWOld(void);
		void EndInputCodeHWOld(void);

		void OpenFormInputIdHWOld(void);
		void EndInputIdHWOld(void);

		void OpenFormInputCodeNom(void);
		void EndInputCodeNom(void);


		IREM_FormaSpiskaSprProducerCondition* FormaSpiskaSprProducerCondition;
		void ViborProducerCondition(void);
		void EndViborProducerCondition(void);


		IREM_FormaSpiskaSprProducerSection* FormaSpiskaSprProducerSection;
		void ViborProducerSection(void);
		void EndViborProducerSection(void);

		void ViborDonorHardware(void);
		void EndViborDonorHardware(void);


				//выбор типового узла
		IREM_FormaSpiskaSprTypUslov * FormaSpiskaSprTypUslov;
		void ViborTypUsla(void);
		void __fastcall EndViborTypUsla(void);

		IFormaSpiskaSprStorageLocation* FormaSpiskaSprStorageLocation;
		void ViborStorageLocation(void);
		void EndViborStorageLocation(void);

public:		// User declarations
		__fastcall TREM_FormaDocZAktPr(TComponent* Owner);
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
		IREM_DMDocZAktPr * DM;


		bool Prosmotr;    //только просмотр

		__int64 IdDoc;           //идентификатор текущей записи
		bool OutReady;

		 __int64 VibTovarId;
		 __int64 VibTovarIdGrp;


		void UpdateForm(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaDocZAktPr *REM_FormaDocZAktPr;
//---------------------------------------------------------------------------
#endif
