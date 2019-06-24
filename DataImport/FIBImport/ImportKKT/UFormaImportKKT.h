//---------------------------------------------------------------------------

#ifndef UFormaImportKKTH
#define UFormaImportKKTH
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
class TFormaImportKKT : public TForm
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
	TcxSpinEdit *NameKKTcxSpinEdit;
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
	TcxSpinEdit *MestoUstcxSpinEdit;
	TcxSpinEdit *SavNumcxSpinEdit;
	TcxSpinEdit *RegNumcxSpinEdit;
	TcxSpinEdit *SvkGRcxSpinEdit;
	TcxSpinEdit *ModelcxSpinEdit;
	TpFIBQuery *QueryKlient;
	TpFIBQuery *QueryModel;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TpFIBDataSet *DataSetDv;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label23;
	TLabel *Label24;
	TLabel *Label25;
	TLabel *Label26;
	TLabel *Label27;
	TLabel *Label28;
	TLabel *Label29;
	TLabel *Label30;
	TLabel *Label31;
	TLabel *Label32;
	TcxSpinEdit *NumDogovorcxSpinEdit;
	TcxSpinEdit *DateDogovorcxSpinEdit;
	TcxSpinEdit *PriceDogovorcxSpinEdit;
	TcxSpinEdit *EKLZSavNumcxSpinEdit;
	TcxSpinEdit *EKLZRegNumcxSpinEdit;
	TcxSpinEdit *EKLZDateActcxSpinEdit;
	TcxSpinEdit *VvodcxSpinEdit;
	TcxSpinEdit *NumPaspcxSpinEdit;
	TcxSpinEdit *NumVercxSpinEdit;
	TcxSpinEdit *NumPUcxSpinEdit;
	TcxSpinEdit *NumSPcxSpinEdit;
	TcxSpinEdit *NumPOSPcxSpinEdit;
	TcxSpinEdit *NumFPcxSpinEdit;
	TcxSpinEdit *NumPOFPcxSpinEdit;
	TcxSpinEdit *numDOcxSpinEdit;
	TcxSpinEdit *NumPODOcxSpinEdit;
	TcxSpinEdit *NumPPPcxSpinEdit;
	TcxSpinEdit *SvedODorcxSpinEdit;
	TcxSpinEdit *PrimcxSpinEdit;
	TcxSpinEdit *SvkSOcxSpinEdit;
	TcxSpinEdit *DataVipcxSpinEdit;
	TcxSpinEdit *NumKlientcxSpinEdit;
	TLabel *Label33;
	TFIBBCDField *DataSetID_REM_SKKT;
	TFIBBCDField *DataSetIDBASE_REM_SKKT;
	TFIBWideStringField *DataSetNAME_REM_SKKT;
	TFIBWideStringField *DataSetSERNUM_REM_SKKT;
	TFIBBCDField *DataSetIDMODEL_REM_SKKT;
	TFIBWideStringField *DataSetREGNUM_REM_SKKT;
	TFIBBCDField *DataSetIDKLIENT_REM_SKKT;
	TFIBWideStringField *DataSetMESTOUST_REM_SKKT;
	TFIBDateField *DataSetRELEASE_REM_SKKT;
	TFIBDateField *DataSetVVOD_REM_SKKT;
	TFIBWideStringField *DataSetCBKGR_REM_SKKT;
	TFIBWideStringField *DataSetCBKCO_REM_SKKT;
	TFIBWideStringField *DataSetNUMCONTRACT_REM_SKKT;
	TFIBDateField *DataSetDATECONTRACT_REM_SKKT;
	TFIBBCDField *DataSetSUMCONTRACT_REM_SKKT;
	TFIBWideStringField *DataSetEKLZ_SERNUM_REM_SKKT;
	TFIBWideStringField *DataSetEKLZ_REGNUM_REM_SKKT;
	TFIBDateField *DataSetEKLZ_ACT_REM_SKKT;
	TFIBWideStringField *DataSetPAS_NUMVER_REM_SKKT;
	TFIBWideStringField *DataSetPAS_NUMPAS_REM_SKKT;
	TFIBWideStringField *DataSetPAS_NUMPU_REM_SKKT;
	TFIBWideStringField *DataSetPAS_NUMSP_REM_SKKT;
	TFIBWideStringField *DataSetPAS_NUMSPPO_REM_SKKT;
	TFIBWideStringField *DataSetPAS_NUMFP_REM_SKKT;
	TFIBWideStringField *DataSetPAS_NUMFPPO_REM_SKKT;
	TFIBWideStringField *DataSetPAS_NUMDO_REM_SKKT;
	TFIBWideStringField *DataSetPAS_NUMDOPO_REM_SKKT;
	TFIBWideStringField *DataSetPAS_NUMPPP_REM_SKKT;
	TFIBWideStringField *DataSetPAS_DOR_REM_SKKT;
	TFIBWideStringField *DataSetPAS_PRIM_REM_SKKT;
	TFIBBCDField *DataSetIDGRP_REM_SKKT;
	TFIBWideStringField *DataSetPRIM_REM_SKKT;
	TFIBBCDField *DataSetDvID_REM_SKKT_DV;
	TFIBBCDField *DataSetDvIDKKT_REM_SKKT_DV;
	TFIBDateTimeField *DataSetDvPOS_REM_SKKT_DV;
	TFIBBCDField *DataSetDvIDKLIENT_REM_SKKT_DV;
	TFIBWideStringField *DataSetDvMESTOUST_REM_SKKT_DV;
	TFIBWideStringField *DataSetDvREGNUM_REM_SKKT_DV;
	TFIBWideStringField *DataSetDvCBKGR_REM_SKKT_DV;
	TFIBWideStringField *DataSetDvCBKCO_REM_SKKT_DV;
	TFIBWideStringField *DataSetDvNUMCONTRACT_REM_SKKT_DV;
	TFIBDateField *DataSetDvDATECONTRACT_REM_SKKT_DV;
	TFIBBCDField *DataSetDvSUMCONTRACT_REM_SKKT_DV;
	TFIBWideStringField *DataSetDvEKLZ_SERNUM_REM_SKKT_DV;
	TFIBWideStringField *DataSetDvEKLZ_REGNUM_REM_SKKT_DV;
	TFIBDateField *DataSetDvEKLZ_ACT_REM_SKKT_DV;
	TFIBBCDField *DataSetDvIDUSER_REM_SKKT_DV;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall FileNamecxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonImportClick(TObject *Sender);
private:	// User declarations





public:		// User declarations
	__fastcall TFormaImportKKT(TComponent* Owner);


    void UpdateForm(void);
	void UpdateSetup(void);
    void SaveSetup(void);
	__int64 VibTovarId;
	__int64 VibTovarIdGrp;



};
//---------------------------------------------------------------------------
extern PACKAGE TFormaImportKKT *FormaImportKKT;
//---------------------------------------------------------------------------
#endif
