//---------------------------------------------------------------------------

#ifndef UFormaImportEdH
#define UFormaImportEdH
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

//---------------------------------------------------------------------------
class TFormaImportEd : public TForm
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
	TLabel *Label4;
	TcxSpinEdit *NameNomcxSpinEdit;
	TcxSpreadSheet *cxSpreadSheet1;
	TcxButton *cxButtonImport;
	TpFIBDataSet *DataSetEd;
	TpFIBTransaction *TrUpdate;
	TpFIBTransaction *TrRead;
	TcxSpinEdit *ConStringcxSpinEdit;
	TLabel *Label5;
	TpFIBQuery *QueryNom;
	TcxGroupBox *cxGroupBox1;
	TLabel *Label12;
	TcxSpinEdit *CodeEdcxSpinEdit;
	TLabel *Label14;
	TcxSpinEdit *NameEdcxSpinEdit;
	TLabel *Label15;
	TcxSpinEdit *TypeShEdcxSpinEdit;
	TcxSpinEdit *ShEdcxSpinEdit;
	TLabel *Label16;
	TcxSpinEdit *KF2EdcxSpinEdit;
	TLabel *Label18;
	TcxSpinEdit *KF1EdcxSpinEdit;
	TLabel *Label17;
	TpFIBQuery *QueryCodeEd;
	TFIBBCDField *DataSetEdIDED;
	TFIBStringField *DataSetEdNAMEED;
	TFIBBCDField *DataSetEdKFED;
	TFIBIntegerField *DataSetEdTSHED;
	TFIBStringField *DataSetEdSHED;
	TFIBBCDField *DataSetEdIDNOMED;
	TFIBBCDField *DataSetEdIDOKEIED;
	TFIBSmallIntField *DataSetEdNEISPED;
	TFIBStringField *DataSetEdGID_SED;
	TFIBBCDField *DataSetEdIDBASE_SED;
	TFIBIntegerField *DataSetEdCODE_SED;
	TFIBBCDField *DataSetEdKF2_SED;
	TFIBBCDField *DataSetEdVES_SED;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall FileNamecxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonImportClick(TObject *Sender);
private:	// User declarations





public:		// User declarations
	__fastcall TFormaImportEd(TComponent* Owner);


    void UpdateForm(void);
	void UpdateSetup(void);
    void SaveSetup(void);
	__int64 VibTovarId;
	__int64 VibTovarIdGrp;

  AnsiString GetNewBarCode(AnsiString code, int type_bar_code);
  AnsiString AddEAN13(AnsiString cod);
  String DopStrL(String Str, String Symbol, int Len);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaImportEd *FormaImportEd;
//---------------------------------------------------------------------------
#endif
