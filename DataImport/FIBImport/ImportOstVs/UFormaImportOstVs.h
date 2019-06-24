//---------------------------------------------------------------------------

#ifndef UFormaImportOstVsH
#define UFormaImportOstVsH
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
#include "cxGroupBox.hpp"
#include "cxDBLookupComboBox.hpp"
#include "cxDBLookupEdit.hpp"
#include "cxLookupEdit.hpp"
#include "cxLookAndFeels.hpp"

//---------------------------------------------------------------------------
class TFormaImportOstVs : public TForm
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
	TcxSpinEdit *NameKlientcxSpinEdit;
	TLabel *Label4;
	TcxSpinEdit *PrihodcxSpinEdit;
	TcxSpreadSheet *cxSpreadSheet1;
	TcxButton *cxButtonImport;
	TpFIBDataSet *DocAll;
	TpFIBTransaction *TrUpdate;
	TpFIBQuery *QueryKlient;
	TpFIBTransaction *TrRead;
	TcxSpinEdit *ConStringcxSpinEdit;
	TLabel *Label5;
	TpFIBDataSet *Doc;
	TpFIBDataSet *DocT;
	TpFIBDataSet *InfBase;
	TcxLookupComboBox *NameInfBasecxLookupComboBox;
	TDataSource *DataSourceInfBase;
	TFIBBCDField *DocID_DKORRVS;
	TFIBBCDField *DocIDDOC_DKORRVS;
	TFIBBCDField *DocIDBASE_DKORRVS;
	TFIBStringField *DocPRIM_DKORRVS;
	TFIBBCDField *DocTID_DKORRVST;
	TFIBBCDField *DocTIDDOC_DKORRVST;
	TFIBBCDField *DocTIDBASE_DKORRVST;
	TFIBBCDField *DocTIDKLIENT_DKORRVST;
	TFIBBCDField *DocTPRIHOD_DKORRVST;
	TFIBBCDField *DocTRASHOD_DKORRVST;
	TFIBIntegerField *DocTDVREGPAYSALE_DKORRVST;
	TLabel *Label6;
	TcxSpinEdit *RashodcxSpinEdit;
	TFIBBCDField *InfBaseID_SINFBASE_OBMEN;
	TFIBWideStringField *InfBaseGID_SINFBASE_OBMEN;
	TFIBWideStringField *InfBaseNAME_SINFBASE_OBMEN;
	TFIBWideStringField *InfBasePREFIKS_SINFBASE_OBMEN;
	TFIBIntegerField *InfBaseIDTIZM_SINFBASE_OBMEN;
	TFIBBCDField *InfBaseIDBASE_SINFBASE_OBMEN;
	TFIBSmallIntField *InfBaseNOACT_SINFBASE_OBMEN;
	TFIBBCDField *DocAllIDDOC;
	TFIBDateTimeField *DocAllPOSDOC;
	TFIBSmallIntField *DocAllPRDOC;
	TFIBWideStringField *DocAllTDOC;
	TFIBIntegerField *DocAllNUMDOC;
	TFIBBCDField *DocAllIDFIRMDOC;
	TFIBBCDField *DocAllIDSKLDOC;
	TFIBBCDField *DocAllIDKLDOC;
	TFIBBCDField *DocAllIDDOGDOC;
	TFIBBCDField *DocAllSUMDOC;
	TFIBBCDField *DocAllIDUSERDOC;
	TFIBWideStringField *DocAllGID_DOC;
	TFIBWideStringField *DocAllPREFIKSDOC;
	TFIBBCDField *DocAllIDDOCOSNDOC;
	TFIBBCDField *DocAllIDEXTDOC;
	TFIBIntegerField *DocAllTYPEEXTDOC;
	TFIBBCDField *DocAllIDBASE_GALLDOC;
	TFIBBCDField *DocAllIDPROJECT_GALLDOC;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall FileNamecxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonImportClick(TObject *Sender);
private:	// User declarations





public:		// User declarations
	__fastcall TFormaImportOstVs(TComponent* Owner);


    void UpdateForm(void);
	void UpdateSetup(void);
    void SaveSetup(void);
	__int64 VibTovarId;
	__int64 VibTovarIdGrp;



};
//---------------------------------------------------------------------------
extern PACKAGE TFormaImportOstVs *FormaImportOstVs;
//---------------------------------------------------------------------------
#endif
