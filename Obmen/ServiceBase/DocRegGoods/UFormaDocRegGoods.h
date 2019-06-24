//---------------------------------------------------------------------------

#ifndef UFormaDocRegGoodsH
#define UFormaDocRegGoodsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxDBLookupComboBox.hpp"
#include "cxDBLookupEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxLookupEdit.hpp"
#include "cxMaskEdit.hpp"
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFormaDocRegGoods : public TForm
{
__published:	// IDE-managed Components
	TpFIBTransaction *IBTr;
	TpFIBDataSet *DocAll;
	TpFIBDataSet *Doc_RegGoods;
	TpFIBDataSet *DocT_RegGoods;
	TpFIBTransaction *IBTrUpdate;
	TcxTextEdit *NameServercxTextEdit;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
	TcxTextEdit *FilecxTextEdit;
	TcxButton *cxButtonViborFile;
	TcxLabel *cxLabel3;
	TcxTextEdit *NameUsercxTextEdit;
	TcxTextEdit *PasswordUsercxTextEdit;
	TcxLabel *cxLabel4;
	TpFIBDataSet *DocRegGoodsSource;
	TpFIBTransaction *TransactionSource;
	TpFIBDatabase *DataBaseSource;
	TLabel *Label1;
	TFIBBCDField *DocRegGoodsSourceID_RGGOODS;
	TFIBBCDField *DocRegGoodsSourceIDFIRM_RGGOODS;
	TFIBBCDField *DocRegGoodsSourceIDSKLAD_RGGOODS;
	TFIBBCDField *DocRegGoodsSourceIDNOM_RGGOODS;
	TFIBBCDField *DocRegGoodsSourceRPRICE_RGGOODS;
	TFIBBCDField *DocRegGoodsSourceKOL_RGGOODS;
	TFIBBCDField *DocRegGoodsSourceIDBASE_RGGOODS;
	TFIBLargeIntField *DocAllIDDOC;
	TFIBDateTimeField *DocAllPOSDOC;
	TFIBSmallIntField *DocAllPRDOC;
	TFIBWideStringField *DocAllTDOC;
	TFIBIntegerField *DocAllNUMDOC;
	TFIBLargeIntField *DocAllIDFIRMDOC;
	TFIBLargeIntField *DocAllIDSKLDOC;
	TFIBLargeIntField *DocAllIDKLDOC;
	TFIBLargeIntField *DocAllIDDOGDOC;
	TFIBBCDField *DocAllSUMDOC;
	TFIBLargeIntField *DocAllIDUSERDOC;
	TFIBWideStringField *DocAllGID_DOC;
	TFIBWideStringField *DocAllPREFIKSDOC;
	TFIBLargeIntField *DocAllIDDOCOSNDOC;
	TFIBLargeIntField *DocAllIDEXTDOC;
	TFIBIntegerField *DocAllTYPEEXTDOC;
	TFIBLargeIntField *DocAllIDBASE_GALLDOC;
	TFIBLargeIntField *DocAllIDEXT_DOUT_GALLDOC;
	TFIBLargeIntField *DocAllIDEXT_BASE_GALLDOC;
	TFIBLargeIntField *DocAllIDPROJECT_GALLDOC;
	TDataSource *DataSourceBaseList;
	TpFIBDataSet *BaseList;
	TFIBBCDField *BaseListID_SINFBASE_OBMEN;
	TFIBWideStringField *BaseListGID_SINFBASE_OBMEN;
	TFIBWideStringField *BaseListNAME_SINFBASE_OBMEN;
	TFIBWideStringField *BaseListPREFIKS_SINFBASE_OBMEN;
	TFIBIntegerField *BaseListIDTIZM_SINFBASE_OBMEN;
	TFIBBCDField *BaseListIDBASE_SINFBASE_OBMEN;
	TFIBSmallIntField *BaseListNOACT_SINFBASE_OBMEN;
	TcxLookupComboBox *NameBasecxLookupComboBox;
	TLabel *Label2;
	TpFIBDataSet *FirmList;
	TpFIBDataSet *SkladList;
	TDataSource *DataSourceFirm;
	TDataSource *DataSourceSklad;
	TcxLookupComboBox *NameFirmcxLookupComboBox;
	TcxLookupComboBox *NameSkladcxLookupComboBox;
	TLabel *Label3;
	TLabel *Label4;
	TFIBWideStringField *FirmListNAMEFIRM;
	TFIBBCDField *FirmListIDFIRM;
	TFIBWideStringField *SkladListNAMESKLAD;
	TFIBBCDField *SkladListIDSKLAD;
	TOpenDialog *OpenDialog1;
	TButton *Button1;
	TFIBLargeIntField *DocT_RegGoodsID_DRG_GOODST;
	TFIBLargeIntField *DocT_RegGoodsIDBASE_DRG_GOODST;
	TFIBLargeIntField *DocT_RegGoodsIDDOC_DRG_GOODST;
	TFIBSmallIntField *DocT_RegGoodsTDV_DRG_GOODST;
	TFIBLargeIntField *DocT_RegGoodsIDFIRM_DRG_GOODST;
	TFIBLargeIntField *DocT_RegGoodsIDSKLAD_DRG_GOODST;
	TFIBLargeIntField *DocT_RegGoodsIDNOM_DRG_GOODST;
	TFIBBCDField *DocT_RegGoodsRPRICE_DRG_GOODST;
	TFIBBCDField *DocT_RegGoodsKOL_DRG_GOODST;
	TFIBIntegerField *DocT_RegGoodsOPER_DRG_GOODST;
	TFIBIntegerField *DocT_RegGoodsTYPE_DRG_GOODST;
	TFIBLargeIntField *Doc_RegGoodsID_DRG_GOODS;
	TFIBLargeIntField *Doc_RegGoodsIDBASE_DRG_GOODS;
	TFIBLargeIntField *Doc_RegGoodsIDDOC_DRG_GOODS;
	TFIBWideStringField *Doc_RegGoodsDESCR_DRG_GOODS;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonViborFileClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormaDocRegGoods(TComponent* Owner);

    bool ConnectBaseSource(void);
	bool CreateDocRegGoods(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocRegGoods *FormaDocRegGoods;
//---------------------------------------------------------------------------
#endif
