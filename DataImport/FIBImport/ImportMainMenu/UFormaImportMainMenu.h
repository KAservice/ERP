//---------------------------------------------------------------------------

#ifndef UFormaImportMainMenuH
#define UFormaImportMainMenuH
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxSpinEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtonEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxGraphics.hpp"
#include "cxPC.hpp"
#include "cxSSheet.hpp"
#include <Dialogs.hpp>
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxFilter.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
#include "cxGridBandedTableView.hpp"
#include "cxCalc.hpp"
#include "cxCheckBox.hpp"
#include <ActnList.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
#include "cxDBLookupComboBox.hpp"
#include "cxDBLookupEdit.hpp"
#include "cxLookupEdit.hpp"
#include "cxLabel.hpp"
#include "cxImageComboBox.hpp"
#include "cxLookAndFeels.hpp"

//---------------------------------------------------------------------------
class TFormaImportMainMenu : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TLabel *Label1;
	TcxButton *cxButtonClose;
	TOpenDialog *OpenDialog1;
	TcxButtonEdit *FileNamecxButtonEdit;
	TLabel *Label13;
	TLabel *LabelError;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TAction *ActionDeleteString;
	TLabel *Label3;
	TcxSpinEdit *StartStringcxSpinEdit;
	TLabel *Label2;
	TcxSpinEdit *NameGrpcxSpinEdit;
	TLabel *Label4;
	TcxSpinEdit *NameMenucxSpinEdit;
	TcxSpreadSheet *cxSpreadSheet1;
	TcxButton *cxButtonImport;
	TpFIBDataSet *DataSet;
	TpFIBTransaction *TrUpdate;
	TpFIBQuery *QueryOwnerGrp;
	TpFIBTransaction *TrRead;
	TcxSpinEdit *ConStringcxSpinEdit;
	TLabel *Label5;
	TpFIBDataSet *SpisokGrpUser;
	TFIBBCDField *SpisokGrpUserID_SGRPUSER;
	TDataSource *DataSourceSpisokGrpUser;
	TcxLookupComboBox *NameGrpcxLookupComboBox;
	TcxLabel *cxLabel1;
	TcxImageComboBox *ApplicationcxImageComboBox;
	TcxLabel *cxLabel2;
	TcxSpinEdit *NumModulecxSpinEdit;
	TLabel *Label6;
	TFIBWideStringField *SpisokGrpUserNAME_SGRPUSER;
	TFIBBCDField *DataSetID_INTERF_MAINMENU;
	TFIBBCDField *DataSetIDGRP_INTERF_MAINMENU;
	TFIBWideStringField *DataSetNAME_INTERF_MAINMENU;
	TFIBIntegerField *DataSetMODUL_INTERF_MAINMENU;
	TFIBBCDField *DataSetIDGRPUSER_INTERF_MAINMENU;
	TFIBIntegerField *DataSetAPPLICATION_INTERF_MAINMENU;
	TFIBWideStringField *DataSetSHORTCUT_INTERF_MAINMENU;
	TFIBIntegerField *DataSetINDEX_INTERF_MAINMENU;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall FileNamecxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonImportClick(TObject *Sender);
private:	// User declarations





public:		// User declarations
	__fastcall TFormaImportMainMenu(TComponent* Owner);


    void UpdateForm(void);
	void UpdateSetup(void);
    void SaveSetup(void);
	__int64 VibTovarId;
	__int64 VibTovarIdGrp;



};
//---------------------------------------------------------------------------
extern PACKAGE TFormaImportMainMenu *FormaImportMainMenu;
//---------------------------------------------------------------------------
#endif
