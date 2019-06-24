//---------------------------------------------------------------------------

#ifndef UFormaImportKlientH
#define UFormaImportKlientH
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
class TFormaImportKlient : public TForm
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
	TcxSpinEdit *NameKlientcxSpinEdit;
	TcxSpreadSheet *cxSpreadSheet1;
	TcxButton *cxButtonImport;
	TpFIBDataSet *DataSet;
	TpFIBTransaction *TrUpdate;
	TpFIBQuery *QueryOwnerGrp;
	TpFIBTransaction *TrRead;
	TcxSpinEdit *ConStringcxSpinEdit;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label8;
	TcxSpinEdit *AdrcxSpinEdit;
	TcxSpinEdit *INNcxSpinEdit;
	TcxSpinEdit *KPPcxSpinEdit;
	TcxSpinEdit *PhonecxSpinEdit;
	TcxSpinEdit *FullNamecxSpinEdit;
	TcxSpinEdit *EmailcxSpinEdit;
	TLabel *Label11;
	TcxSpinEdit *DescrcxSpinEdit;
	TLabel *Label12;
	TcxSpinEdit *KrNamecxSpinEdit;
	TLabel *Label14;
	TFIBBCDField *DataSetIDKLIENT;
	TFIBWideStringField *DataSetNAMEKLIENT;
	TFIBWideStringField *DataSetFNAME;
	TFIBWideStringField *DataSetADRKLIENT;
	TFIBWideStringField *DataSetTELKLIENT;
	TFIBWideStringField *DataSetINNKLIENT;
	TFIBWideStringField *DataSetKPPKLIENT;
	TFIBIntegerField *DataSetTKLIENT;
	TFIBBCDField *DataSetIDTPRICEKLIENT;
	TFIBBCDField *DataSetIDGRPKLIENT;
	TFIBWideStringField *DataSetGID_SKLIENT;
	TFIBWideStringField *DataSetOKPOKLIENT;
	TFIBBCDField *DataSetIDVIDKLIENT;
	TFIBBCDField *DataSetIDCOUNTRYKLIENT;
	TFIBWideStringField *DataSetKRNAME_SKLIENT;
	TFIBWideStringField *DataSetDESCR_SKLIENT;
	TFIBWideStringField *DataSetMESSAGE_SKLIENT;
	TFIBWideStringField *DataSetEMAIL_SKLIENT;
	TFIBWideStringField *DataSetWWW_SKLIENT;
	TFIBBCDField *DataSetMAXCREDIT_SKLIENT;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall FileNamecxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonImportClick(TObject *Sender);
private:	// User declarations





public:		// User declarations
	__fastcall TFormaImportKlient(TComponent* Owner);


    void UpdateForm(void);
	void UpdateSetup(void);
    void SaveSetup(void);
	__int64 VibTovarId;
	__int64 VibTovarIdGrp;



};
//---------------------------------------------------------------------------
extern PACKAGE TFormaImportKlient *FormaImportKlient;
//---------------------------------------------------------------------------
#endif
