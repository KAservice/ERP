//---------------------------------------------------------------------------

#ifndef UFormaImportNomH
#define UFormaImportNomH
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
#include "cxLookAndFeels.hpp"

//---------------------------------------------------------------------------
class TFormaImportNom : public TForm
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
	TcxSpinEdit *NameOwnerGrpcxSpinEdit;
	TLabel *Label4;
	TcxSpinEdit *NameNomcxSpinEdit;
	TcxSpreadSheet *cxSpreadSheet1;
	TcxButton *cxButtonImport;
	TpFIBDataSet *DataSetNom;
	TpFIBTransaction *TrUpdate;
	TpFIBQuery *QueryOwnerGrp;
	TpFIBTransaction *TrRead;
	TcxSpinEdit *ConStringcxSpinEdit;
	TLabel *Label5;
	TcxSpinEdit *TypeNomcxSpinEdit;
	TcxSpinEdit *CodecxSpinEdit;
	TcxSpinEdit *ArtikulcxSpinEdit;
	TcxSpinEdit *KrNameNomcxSpinEdit;
	TcxSpinEdit *FullNameNomcxSpinEdit;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TcxSpinEdit *cxSpinEdit1;
	TLabel *Label11;
	TpFIBQuery *QueryCodeNom;
	TcxSpinEdit *DescrcxSpinEdit;
	TLabel *Label12;
	TcxSpinEdit *CountrycxSpinEdit;
	TLabel *Label14;
	TpFIBDataSet *DataSetCountry;
	TpFIBTransaction *TransCountry;
	TFIBBCDField *DataSetCountryID_SCOUNTRY;
	TFIBWideStringField *DataSetCountryCODE_SCOUNTRY;
	TFIBWideStringField *DataSetCountryNAME_SCOUNTRY;
	TFIBBCDField *DataSetNomIDNOM;
	TFIBIntegerField *DataSetNomTNOM;
	TFIBIntegerField *DataSetNomCODENOM;
	TFIBWideStringField *DataSetNomNAMENOM;
	TFIBWideStringField *DataSetNomFNAMENOM;
	TFIBWideStringField *DataSetNomKRNAMENOM;
	TFIBBCDField *DataSetNomIDBASEDNOM;
	TFIBBCDField *DataSetNomIDOSNEDNOM;
	TFIBBCDField *DataSetNomIDFISED_SNOM;
	TFIBBCDField *DataSetNomIDGRPNOM;
	TFIBWideStringField *DataSetNomARTNOM;
	TFIBWideStringField *DataSetNomGID_SNOM;
	TFIBWideStringField *DataSetNomDESCR_SNOM;
	TFIBBCDField *DataSetNomIDFIRMNOM;
	TFIBIntegerField *DataSetNomSTNDSNOM;
	TFIBWideStringField *DataSetNomGTDNOM;
	TFIBBCDField *DataSetNomIDCOUNTRYNOM;
	TFIBSmallIntField *DataSetNomFL_CHANGE_NOM;
	TFIBBCDField *DataSetNomMINOSTNOM;
	TFIBBCDField *DataSetNomSKIDKA1_SNOM;
	TFIBBCDField *DataSetNomSKIDKA2_SNOM;
	TFIBBCDField *DataSetNomSKIDKA3_SNOM;
	TFIBBCDField *DataSetNomIDVID_SNOM;
	TFIBSmallIntField *DataSetNomTYPESRGODN_SNOM;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall FileNamecxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonImportClick(TObject *Sender);
private:	// User declarations





public:		// User declarations
	__fastcall TFormaImportNom(TComponent* Owner);


    void UpdateForm(void);
	void UpdateSetup(void);
    void SaveSetup(void);
	__int64 VibTovarId;
	__int64 VibTovarIdGrp;



};
//---------------------------------------------------------------------------
extern PACKAGE TFormaImportNom *FormaImportNom;
//---------------------------------------------------------------------------
#endif
