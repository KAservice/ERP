//---------------------------------------------------------------------------

#ifndef UFormaDialogH
#define UFormaDialogH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
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
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TFormaDialog : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TpFIBDataSet *pFIBDataSet1;
	TpFIBTransaction *pFIBTransaction1;
	TDataSource *DataSource1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TFIBBCDField *pFIBDataSet1IDNOM;
	TFIBIntegerField *pFIBDataSet1TNOM;
	TFIBIntegerField *pFIBDataSet1CODENOM;
	TFIBStringField *pFIBDataSet1NAMENOM;
	TFIBStringField *pFIBDataSet1FNAMENOM;
	TFIBStringField *pFIBDataSet1KRNAMENOM;
	TFIBBCDField *pFIBDataSet1IDBASEDNOM;
	TFIBBCDField *pFIBDataSet1IDOSNEDNOM;
	TFIBBCDField *pFIBDataSet1IDFISED_SNOM;
	TFIBBCDField *pFIBDataSet1IDGRPNOM;
	TFIBStringField *pFIBDataSet1ARTNOM;
	TFIBStringField *pFIBDataSet1GID_SNOM;
	TFIBStringField *pFIBDataSet1DESCR_SNOM;
	TFIBBCDField *pFIBDataSet1IDFIRMNOM;
	TFIBIntegerField *pFIBDataSet1STNDSNOM;
	TFIBStringField *pFIBDataSet1GTDNOM;
	TFIBBCDField *pFIBDataSet1IDCOUNTRYNOM;
	TFIBSmallIntField *pFIBDataSet1FL_CHANGE_NOM;
	TFIBBCDField *pFIBDataSet1MINOSTNOM;
	TFIBBCDField *pFIBDataSet1IDBASE_SNOM;
	TFIBBCDField *pFIBDataSet1IDEXT_DOUT_SNOM;
	TFIBBCDField *pFIBDataSet1IDEXT_BASE_SNOM;
	TFIBBCDField *pFIBDataSet1SKIDKA1_SNOM;
	TFIBBCDField *pFIBDataSet1SKIDKA2_SNOM;
	TFIBBCDField *pFIBDataSet1SKIDKA3_SNOM;
	TFIBBCDField *pFIBDataSet1IDVID_SNOM;
	TFIBSmallIntField *pFIBDataSet1TYPESRGODN_SNOM;
	TFIBSmallIntField *pFIBDataSet1SRGODN_SNOM;
	TFIBDateTimeField *pFIBDataSet1GODEN_DO_SNOM;
	TFIBBCDField *pFIBDataSet1IDSUPPLIER_SNOM;
	TFIBBCDField *pFIBDataSet1IDPRODUCER_SNOM;
	TFIBBCDField *pFIBDataSet1POGR_SNOM;
	TcxGridDBColumn *cxGrid1DBTableView1IDNOM;
	TcxGridDBColumn *cxGrid1DBTableView1TNOM;
	TcxGridDBColumn *cxGrid1DBTableView1CODENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1FNAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1KRNAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1IDBASEDNOM;
	TcxGridDBColumn *cxGrid1DBTableView1IDOSNEDNOM;
	TcxGridDBColumn *cxGrid1DBTableView1IDFISED_SNOM;
	TcxGridDBColumn *cxGrid1DBTableView1IDGRPNOM;
	TcxGridDBColumn *cxGrid1DBTableView1ARTNOM;
	TcxGridDBColumn *cxGrid1DBTableView1GID_SNOM;
	TcxGridDBColumn *cxGrid1DBTableView1DESCR_SNOM;
	TcxGridDBColumn *cxGrid1DBTableView1IDFIRMNOM;
	TcxGridDBColumn *cxGrid1DBTableView1STNDSNOM;
	TcxGridDBColumn *cxGrid1DBTableView1GTDNOM;
	TcxGridDBColumn *cxGrid1DBTableView1IDCOUNTRYNOM;
	TcxGridDBColumn *cxGrid1DBTableView1FL_CHANGE_NOM;
	TcxGridDBColumn *cxGrid1DBTableView1MINOSTNOM;
	TcxGridDBColumn *cxGrid1DBTableView1IDBASE_SNOM;
	TcxGridDBColumn *cxGrid1DBTableView1IDEXT_DOUT_SNOM;
	TcxGridDBColumn *cxGrid1DBTableView1IDEXT_BASE_SNOM;
	TcxGridDBColumn *cxGrid1DBTableView1SKIDKA1_SNOM;
	TcxGridDBColumn *cxGrid1DBTableView1SKIDKA2_SNOM;
	TcxGridDBColumn *cxGrid1DBTableView1SKIDKA3_SNOM;
	TcxGridDBColumn *cxGrid1DBTableView1IDVID_SNOM;
	TcxGridDBColumn *cxGrid1DBTableView1TYPESRGODN_SNOM;
	TcxGridDBColumn *cxGrid1DBTableView1SRGODN_SNOM;
	TcxGridDBColumn *cxGrid1DBTableView1GODEN_DO_SNOM;
	TcxGridDBColumn *cxGrid1DBTableView1IDSUPPLIER_SNOM;
	TcxGridDBColumn *cxGrid1DBTableView1IDPRODUCER_SNOM;
	TcxGridDBColumn *cxGrid1DBTableView1POGR_SNOM;
	TpFIBDatabase *pFIBDatabase1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormaDialog(TComponent* Owner);

	typedef void (*FOnCloseFormType)(void);
	FOnCloseFormType FOnCloseForm;

    void RunReport();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDialog *FormaDialog;
//---------------------------------------------------------------------------
#endif
