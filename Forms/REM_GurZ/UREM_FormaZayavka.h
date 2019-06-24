//---------------------------------------------------------------------------

#ifndef UREM_FormaZayavkaH
#define UREM_FormaZayavkaH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "UDM.h"
#include "IREM_DMZayavka.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaSpiskaSprEd.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IREM_FormaSpiskaSprKomplModel.h"
#include "IREM_FormaSpiskaSprModel.h"
#include "IREM_FormaSpiskaSprNeispr.h"
#include "IREM_FormaSpiskaSprSost.h"
#include "IREM_FormaSpiskaSprTypeRemont.h"
#include "IDMTableExtPrintForm.h"
#include "IREM_FormaSpiskaSprHardware.h"
#include "IFormaSpiskaSprBrand.h"
#include "IFormaSpiskaSprProducer.h"
#include "IREM_FormaSpiskaSprProducerModel.h"
#include "IFormaSpiskaSprSeller.h"
#include "IREM_FormaSpiskaSprActCategory.h"
#include "IREM_FormaSpiskaSprTypDefect.h"
#include "IREM_FormaSpiskaSprTypRabot.h"
#include "IFormaElementaSprAddressVibor.h"
#include "IREM_FormaSpiskaSprProducerNeispr.h"
#include "IREM_FormaSpiskaSprProducerCondition.h"
#include "IFormaDocPKORozn.h"
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
//---------------------------------------------------------------------------
class TREM_FormaZayavka : public TForm
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
	TLabel *Label9;
	TcxDBButtonEdit *NameSkladTeccxDBButtonEdit;
	TLabel *Label8;
	TcxDBButtonEdit *NameTypeRemontcxDBButtonEdit;
	TLabel *Label18;
	TcxDBTextEdit *NamecxDBTextEdit;
	TcxTabSheet *cxTabSheet6;
	TcxTabSheet *cxTabSheet7;
	TToolButton *ToolButtonCreateCQuery;
	TcxTabSheet *cxTabSheet8;
	TPopupMenu *PopupMenuAddKompl;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N9;
	TcxTabSheet *cxTabSheet9;
	TcxTabSheet *cxTabSheet10;
	TcxTabSheet *cxTabSheet11;
	TcxTabSheet *cxTabSheet12;
	TToolBar *ToolBar4;
	TToolButton *ToolButton12;
	TToolButton *ToolButton8;
	TToolButton *ToolButton9;
	TToolButton *ToolButton11;
	TcxGrid *cxGrid3;
	TcxGridDBTableView *cxGrid3DBTableView1;
	TcxGridDBColumn *cxGrid3DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid3DBTableView1TEXTNOM_REM_ZDOPUSL;
	TcxGridDBColumn *cxGrid3DBTableView1KOL_REM_ZDOPUSL;
	TcxGridDBColumn *cxGrid3DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid3DBTableView1KF_REM_ZDOPUSL;
	TcxGridDBColumn *cxGrid3DBTableView1PRICE_REM_ZDOPUSL;
	TcxGridDBColumn *cxGrid3DBTableView1SUM_REM_ZDOPUSL;
	TcxGridLevel *cxGrid3Level1;
	TToolBar *ToolBar5;
	TToolButton *ToolButton13;
	TToolButton *ToolButton14;
	TToolButton *ToolButton15;
	TcxGrid *cxGrid4;
	TcxGridDBTableView *cxGrid4DBTableView1;
	TcxGridDBColumn *cxGrid4DBTableView1POS_REM_ZPERFWORK;
	TcxGridDBColumn *cxGrid4DBTableView1SHOWFORUSER_REM_ZPERFWORK;
	TcxGridDBColumn *cxGrid4DBTableView1ADDACT_REM_ZPERFWORK;
	TcxGridDBColumn *cxGrid4DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid4DBTableView1TEXTNOM_REM_ZPERFWORK;
	TcxGridDBColumn *cxGrid4DBTableView1KOL_REM_ZPERFWORK;
	TcxGridDBColumn *cxGrid4DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid4DBTableView1KF_REM_ZPERFWORK;
	TcxGridDBColumn *cxGrid4DBTableView1PRICE_REM_ZPERFWORK;
	TcxGridDBColumn *cxGrid4DBTableView1SUM_REM_ZPERFWORK;
	TcxGridDBColumn *cxGrid4DBTableView1RESULT_REM_ZPERFWORK;
	TcxGridDBColumn *cxGrid4DBTableView1NAME_USER;
	TcxGridLevel *cxGrid4Level1;
	TLabel *Label14;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TLabel *Label19;
	TcxDBTextEdit *KlientNamecxDBTextEdit;
	TLabel *Label20;
	TcxDBTextEdit *KlientAdtrcxDBTextEdit;
	TLabel *Label21;
	TcxDBTextEdit *KlientPhonecxDBTextEdit;
	TLabel *Label29;
	TcxDBTextEdit *EmailcxDBTextEdit;
	TLabel *Label30;
	TcxDBMemo *DopInfocxDBMemo;
	TcxDBTextEdit *AdrCodeRegioncxDBTextEdit;
	TcxDBTextEdit *AdrRegioncxDBTextEdit;
	TcxDBTextEdit *AdrNasPunktcxDBTextEdit;
	TcxDBTextEdit *AdrPostCodecxDBTextEdit;
	TcxDBTextEdit *AdrStreetcxDBTextEdit;
	TcxDBTextEdit *AdrDomcxDBTextEdit;
	TcxDBTextEdit *AdrKVcxDBTextEdit;
	TLabel *Label16;
	TcxDBButtonEdit *NameModelcxDBButtonEdit;
	TLabel *Label22;
	TLabel *Label24;
	TLabel *Label17;
	TLabel *Label23;
	TcxDBTextEdit *SerNum2cxDBTextEdit;
	TcxDBTextEdit *SerNumcxDBTextEdit;
	TcxDBTextEdit *NumGarDoccxDBTextEdit;
	TcxDBTextEdit *ModelcxDBTextEdit;
	TcxDBMemo *SostcxDBMemo;
	TcxLabel *cxLabel9;
	TcxLabel *cxLabel10;
	TcxLabel *cxLabel11;
	TcxLabel *cxLabel16;
	TcxDBButtonEdit *SellercxDBButtonEdit;
	TcxDBButtonEdit *ProducerModelcxDBButtonEdit;
	TcxDBButtonEdit *NameproducercxDBButtonEdit;
	TcxDBButtonEdit *NameBrandcxDBButtonEdit;
	TLabel *Label26;
	TcxTabSheet *cxTabSheet13;
	TcxDBCheckBox *IsmGarDoccxDBCheckBox;
	TcxDBCheckBox *IsmSerNumcxDBCheckBox;
	TcxDBCheckBox *IsmSerNum2cxDBCheckBox;
	TcxDBTextEdit *NewSerNum2cxDBTextEdit;
	TcxDBTextEdit *NewSerNumcxDBTextEdit;
	TcxDBTextEdit *NewNumGarDoccxDBTextEdit;
	TLabel *Label25;
	TLabel *Label27;
	TLabel *Label28;
	TcxDBButtonEdit *NameFirmcxDBButtonEdit;
	TLabel *Label12;
	TLabel *Label6;
	TcxDBButtonEdit *NameInfBasecxDBButtonEdit;
	TLabel *Label13;
	TLabel *Label3;
	TcxDBButtonEdit *NameDialercxDBButtonEdit;
	TcxDBButtonEdit *NameSkladPrcxDBButtonEdit;
	TGroupBox *GroupBox1;
	TcxDBLabel *ModelcxDBLabel;
	TcxDBLabel *SerNumber1cxDBLabel;
	TcxDBLabel *SerNumber2cxDBLabel;
	TcxDBLabel *NameKlientcxDBLabel;
	TcxDBLabel *NameDilercxDBLabel;
	TcxDBLabel *SostcxDBLabel;
	TcxDBLabel *NeisprcxDBLabel;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
	TToolButton *ToolButton16;
	TcxGrid *cxGrid1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_REM_SKOMPLMODEL;
	TcxGridDBColumn *cxGrid1DBTableView1KOL_REM_ZKOMPL;
	TcxGridLevel *cxGrid1Level1;
	TcxDBMemo *KomplcxDBMemo;
	TcxDBButtonEdit *NameHardwarecxDBButtonEdit;
	TcxLabel *cxLabel5;
	TcxDBLabel *SerNumcxDBLabel;
	TcxDBLabel *SerNum2cxDBLabel;
	TcxLabel *cxLabel3;
	TcxDBImageComboBox *KlientOtvetNaZaproscxDBImageComboBox;
	TcxLabel *cxLabel7;
	TcxDBImageComboBox *TrebKonsultKlientacxDBImageComboBox;
	TcxLabel *cxLabel8;
	TcxDBImageComboBox *KlientUvedomlencxDBImageComboBox;
	TcxLabel *cxLabel6;
	TcxDBCheckBox *AddReportcxDBCheckBox;
	TcxDBMemo *CommentscxDBMemo;
	TcxDBDateEdit *SrokcxDBDateEdit;
	TLabel *Label15;
	TcxDBImageComboBox *OutcxDBImageComboBox;
	TcxDBImageComboBox *GotovoKVadachecxDBImageComboBox;
	TLabel *Label10;
	TcxDBButtonEdit *NameSostcxDBButtonEdit;
	TcxDBDateEdit *OtremontcxDBDateEdit;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
	TcxDBDateEdit *VidanocxDBDateEdit;
	TcxDBCalcEdit *SumcxDBCalcEdit;
	TLabel *Label11;
	TcxLabel *cxLabel4;
	TcxDBCalcEdit *WarrantycxDBCalcEdit;
	TcxDBLabel *TypeRemontcxDBLabel;
	TcxTabSheet *cxTabSheet1;
	TcxDBImageComboBox *FlProblemKlientcxDBImageComboBox;
	TcxDBCheckBox *FictivcxDBCheckBox;
	TcxDBCheckBox *flNeOtchcxDBCheckBox;
	TcxDBCheckBox *flNadoOtchcxDBCheckBox;
	TLabel *Label7;
	TcxDBMemo *DescrcxDBMemo;
	TcxDBImageComboBox *FlProblemDevicecxDBImageComboBox;
	TLabel *Label4;
	TLabel *Label5;
	TcxDBCheckBox *PlombaSetcxDBCheckBox;
	TcxDBTextEdit *TextPlombacxDBTextEdit;
	TcxDBTextEdit *StroencxDBTextEdit;
	TcxDBTextEdit *RayoncxDBTextEdit;
	TcxDBMemo *DefectEngcxDBMemo;
	TcxDBMemo *SolutionEngcxDBMemo;
	TLabel *Label31;
	TLabel *Label32;
	TcxDBTextEdit *StrCodeVigrcxDBTextEdit;
	TcxDBTextEdit *IDcxDBTextEdit;
	TLabel *Label33;
	TLabel *Label34;
	TcxDBCheckBox *OnlyDiagnosticcxDBCheckBox;
	TcxDBLabel *SostDevicecxDBLabel;
	TcxDBImageComboBox *FlPovtorcxDBImageComboBox;
	TLabel *Label35;
	TcxLabel *cxLabel17;
	TcxDBButtonEdit *NameActivecategorycxDBButtonEdit;
	TcxButton *ViborTypDefectcxButton;
	TcxButton *VibortyprabotcxButton;
	TLabel *Label36;
	TLabel *Label37;
	TLabel *Label38;
	TcxDBTextEdit *cxDBTextEditFAMILIYA_REM_Z_1;
	TcxDBTextEdit *cxDBTextEditIMYA_REM_Z_1;
	TcxDBTextEdit *cxDBTextEditOTCHESTVO_REM_Z_1;
	TButton *ButtonAddressVibor;
	TPanel *Panel2;
	TcxDBLabel *NameGrpCFCcxDBLabel;
	TcxDBButtonEdit *cxDBButtonEditNAME_REM_SPRNEISPR;
	TLabel *Label39;
	TcxDBLabel *CodeNeisprPrcxDBLabel;
	TcxDBLabel *cxDBLabelNAME_ENG_REM_SPRNEISPR;
	TcxDBLabel *cxDBLabelNAME_ENG_REM_SPRNEISPR_GRP;
	TcxDBImageComboBox *FlDefectDemocxDBImageComboBox;
	TcxDBImageComboBox *FlVklcxDBImageComboBox;
	TcxLabel *cxLabel12;
	TcxLabel *cxLabel13;
	TLabel *Label40;
	TcxDBTextEdit *cxDBTextEditSERNUM3_REM_Z_1;
	TLabel *Label41;
	TcxDBTextEdit *cxDBTextEditSERNUM4_REM_Z_1;
	TLabel *Label42;
	TcxDBTextEdit *cxDBTextEditNUMBAT_REM_Z_1;
	TcxLabel *cxLabel14;
	TcxDBImageComboBox *FlZipcxDBImageComboBox;
	TcxDBImageComboBox *FlKlientPreupregdencxDBImageComboBox;
	TcxLabel *cxLabel15;
	TcxDBTextEdit *cxDBTextEditPARTNUM_REM_Z_1;
	TLabel *Label43;
	TcxDBTextEdit *cxDBTextEditREFERENCE_REM_Z_1;
	TLabel *Label44;
	TcxDBTextEdit *cxDBTextEditSWCODE_REM_Z_1;
	TLabel *Label45;
	TcxDBTextEdit *cxDBTextEditHWCODE_REM_Z_1;
	TLabel *Label46;
	TcxDBTextEdit *cxDBTextEditPODO_REM_Z_1;
	TLabel *Label47;
	TcxDBTextEdit *cxDBTextEditPOPOSLE_REM_Z_1;
	TLabel *Label48;
	TLabel *Label49;
	TcxDBDateEdit *cxDBDateEditDATE_VIPUSK_REM_Z_1;
	TLabel *Label50;
	TcxDBDateEdit *cxDBDateEditDATE_PRODAGI_REM_Z_1;
	TcxDBImageComboBox *KEM_SDANOcxDBImageComboBox;
	TLabel *Label51;
	TcxDBDateEdit *cxDBDateEditPOS_ZAPROSA_NA_AKT_REM_Z_1;
	TcxLabel *cxLabel18;
	TcxDBTextEdit *cxDBTextEditSERNUM3_NEW_REM_Z_1;
	TLabel *Label52;
	TLabel *Label53;
	TcxDBTextEdit *cxDBTextEditSERNUM4_NEW_REM_Z_1;
	TLabel *Label54;
	TcxDBTextEdit *cxDBTextEditPARTNUM_NEW_REM_Z_1;
	TLabel *Label55;
	TcxDBTextEdit *cxDBTextEditREFERENCE_NEW_REM_Z_1;
	TLabel *Label56;
	TcxDBTextEdit *cxDBTextEditSWCODE_NEW_REM_Z_1;
	TLabel *Label57;
	TcxDBTextEdit *cxDBTextEditHWCODE_NEW_REM_Z_1;
	TcxDBCheckBox *cxDBCheckBoxFL_ISM_SERNUM3_REM_Z_1;
	TcxDBCheckBox *cxDBCheckBoxFL_ISM_SERNUM4_REM_Z_1;
	TcxDBCheckBox *cxDBCheckBoxFL_ISM_PARTNUM_REM_Z_1;
	TcxDBCheckBox *cxDBCheckBoxFL_ISM_REFERENCE_REM_Z_1;
	TcxDBCheckBox *cxDBCheckBoxFL_ISM_SWCODE_REM_Z_1;
	TcxDBCheckBox *cxDBCheckBoxFL_ISM_HWCODE_REM_Z_1;
	TToolButton *ToolButton17;
	TToolButton *ToolButtonCreateDocPost;
	TToolButton *ToolButtonCreateDocZVidacha;
	TPanel *Panel5;
	TPanel *Panel6;
	TToolBar *ToolBar6;
	TToolButton *ToolButton18;
	TToolButton *ToolButton19;
	TToolButton *ToolButton20;
	TcxGrid *cxGrid2;
	TcxGridDBTableView *cxGrid2DBTableView1;
	TcxGridDBColumn *cxGrid2DBTableView1RECNO;
	TcxGridDBColumn *cxGrid2DBTableView1NAME_REM_SGRPNEISPR;
	TcxGridDBColumn *cxGrid2DBTableView1NAME_ENG_REM_SGRPNEISPR;
	TcxGridDBColumn *cxGrid2DBTableView1NAME_REM_SNEISPR;
	TcxGridDBColumn *cxGrid2DBTableView1NAME_ENG_REM_SNEISPR;
	TcxGridLevel *cxGrid2Level1;
	TPanel *Panel7;
	TcxDBMemo *NeisprcxDBMemo;
	TcxDBMemo *NeisprEngcxDBMemo;
	TcxGridDBTableView *cxGrid5DBTableView1;
	TcxGridLevel *cxGrid5Level1;
	TcxGrid *cxGrid5;
	TcxGridDBColumn *cxGrid5DBTableView1CODE_REM_SPRCOND_GRP;
	TcxGridDBColumn *cxGrid5DBTableView1NAME_REM_SPRCOND_GRP;
	TcxGridDBColumn *cxGrid5DBTableView1CODE_REM_SPRCONDITION;
	TcxGridDBColumn *cxGrid5DBTableView1NAME_REM_SPRCONDITION;
	TcxGridDBColumn *cxGrid5DBTableView1NAME_REM_SPRNEISPR_GRP;
	TcxGridDBColumn *cxGrid5DBTableView1CODE_REM_SPRNEISPR;
	TcxGridDBColumn *cxGrid5DBTableView1NAME_REM_SPRNEISPR;
	TToolButton *ToolButton2;
	TToolButton *ToolButtonAddProducerNeispr;
	TToolButton *ToolButtonEditProducerNeispr;
	TToolButton *ToolButtonDelProducerneispr;
	TToolButton *ToolButton3;
	TToolButton *ToolButtonOpenGarTalon;
	TcxDBCalcEdit *cxDBCalcEditPREDOPLATA_REM_Z_1;
	TLabel *Label58;
	TToolButton *ToolButtonCreateDocPrihNal;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ActionAddNewKomplExecute(TObject *Sender);
	void __fastcall ActionEditKomplExecute(TObject *Sender);
	void __fastcall ActionAddNeisprExecute(TObject *Sender);
	void __fastcall ActionEditNeisprExecute(TObject *Sender);
	void __fastcall ActionDeleteKomplExecute(TObject *Sender);
	void __fastcall ActionDeleteNeisprExecute(TObject *Sender);
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
	void __fastcall NameStrcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameModelcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSostcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladTeccxDBButtonEditPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
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
	void __fastcall ToolButtonOpenDocRemontClick(TObject *Sender);
	void __fastcall ToolButtonCreateDocRemontClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall ActionAddNewDopUslExecute(TObject *Sender);
	void __fastcall ActionDeleteDopUslExecute(TObject *Sender);
	void __fastcall cxGrid3DBTableView1NAMENOMPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid3DBTableView1NAMEEDPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionAddPerformedWorkExecute(TObject *Sender);
	void __fastcall ActionDeletePerformedWorkExecute(TObject *Sender);
	void __fastcall cxGrid4DBTableView1NAMENOMPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid4DBTableView1NAMEEDPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonOpenSpisokImageClick(TObject *Sender);
	void __fastcall NameHardwarecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameBrandcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall ToolButtonCreateCQueryClick(TObject *Sender);
	void __fastcall AddComplClick(TObject *Sender);
	void __fastcall NameproducercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ProducerModelcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall SellercxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall NameActivecategorycxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ViborTypDefectcxButtonClick(TObject *Sender);
	void __fastcall VibortyprabotcxButtonClick(TObject *Sender);
	void __fastcall cxDBTextEditOTCHESTVO_REM_Z_1KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall ButtonAddressViborClick(TObject *Sender);
	void __fastcall CFCcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall ToolButtonCreateDocPostClick(TObject *Sender);
	void __fastcall ToolButtonCreateDocZVidachaClick(TObject *Sender);
	void __fastcall ToolButtonAddProducerNeisprClick(TObject *Sender);
	void __fastcall cxGrid5DBTableView1NAME_REM_SPRCONDITIONPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid5DBTableView1NAME_REM_SPRNEISPRPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ToolButtonOpenGarTalonClick(TObject *Sender);
	void __fastcall ToolButtonCreateDocPrihNalClick(TObject *Sender);
	void __fastcall ToolButtonDelProducerneisprClick(TObject *Sender);












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
		IREM_FormaSpiskaSprKomplModel * REM_FormaSpiskaSprKomplModel;
		IREM_FormaSpiskaSprModel * REM_FormaSpiskaSprModel;
		IREM_FormaSpiskaSprNeispr * REM_FormaSpiskaSprNeispr;
		IREM_FormaSpiskaSprSost *  REM_FormaSpiskaSprSost;
		IREM_FormaSpiskaSprTypeRemont * REM_FormaSpiskaSprTypeRemont;


		void __fastcall EventEndEditInfBase(void);
		void __fastcall EventEndEditFirm(void);
		void __fastcall EventEndEditSkladPr(void);
		void __fastcall EventEndEditSkladTec(void);
		void __fastcall EventEndEditKlient(void);
		void __fastcall EventEndEditDiler(void);
		void __fastcall EventEndEditModel(void);
		void __fastcall EventEndEditTypeRemont(void);
		void __fastcall EventEndEditTecSost(void);

		void __fastcall EventEndEditZkompl(void);
		void __fastcall EventEndEditZNeispr(void);



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
						ER_ViborProducerNeispr,
						ER_ViborProducerNesprInTable,
						ER_ViborProducerCondition,
						ER_CloseDocPKORozn} EditRekvisit;


		IFormaSpiskaSprNom * FormaSpiskaSprNom;
		IFormaSpiskaSprEd * FormaSpiskaSprEd;

		void OpenFormSpiskaSprEd(void);
		void OpenFormSpiskaSprNom(void);
		void __fastcall EventEndEditNom(void);
		void __fastcall EventEndEditEd(void);


		void OpenFormSpiskaSprEdPerfWork(void);
		void OpenFormSpiskaSprNomPerfWork(void);
		void __fastcall EventEndEditNomPerfWork(void);
		void __fastcall EventEndEditEdPerfWork(void);


		//выбор оборудования
		IREM_FormaSpiskaSprHardware* FormaSpiskaSprHardware;
		void ViborHardware(void);
		void __fastcall EndViborHardware(void);

		//Бренд
		IFormaSpiskaSprBrand * SpisokBrand;
		void ViborBrand(void);
		void __fastcall EndViborBrand(void);





		IREM_FormaSpiskaSprProducerModel  * REM_FormaSpiskaSprProducerModel;
		void ViborProducerModel(void);
		void EventEndEditProdcerModel(void);

		IFormaSpiskaSprProducer * FormaSpiskaSprProducer;
		void ViborProducer(void);
		void EventEndEditProdcer(void);


		IFormaSpiskaSprSeller* FormaSpiskaSprSeller;
		void ViborSeller(void);
		void EndViborSeller(void);

		IREM_FormaSpiskaSprActCategory * REM_FormaSpiskaSprActCategory;
		void ViborActCategory(void);
		void EndViborActCategory(void);

		IREM_FormaSpiskaSprTypDefect * REM_FormaSpiskaSprTypDefect;
		void ViborTypDefect(void);
		void EndViborTypDefect(void);

		IREM_FormaSpiskaSprTypRabot * REM_FormaSpiskaSprTypRabot;
		void ViborTypRabot(void);
		void EndViborTypRabot(void);

		IFormaElementaSprAddressVibor * FormaElementaSprAddressVibor;
		void ViborAddress(void);
		void EndViborAddress(void);

		IREM_FormaSpiskaSprProducerNeispr* FormaSpiskaSprProducerNeispr;
		void ViborProducerNeispr(void);
		void EndViborProducerNeispr(void);

		void ViborProducerNeisprInTable(void);
		void EndViborProducerNeisprInTable(void);

		IREM_FormaSpiskaSprProducerCondition* FormaSpiskaSprProducerCondition;
		void ViborProducerCondition(void);
		void EndViborProducerCondition(void);

public:		// User declarations
		__fastcall TREM_FormaZayavka(TComponent* Owner);

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

		IREM_DMZayavka *DM;

		bool Prosmotr;    //только просмотр
		__int64 IdZ;           //идентификатор текущей записи
		void UpdateForm(void);
        void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaZayavka *REM_FormaZayavka;
//---------------------------------------------------------------------------
#endif
