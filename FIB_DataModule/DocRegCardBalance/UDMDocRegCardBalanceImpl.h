#ifndef UDMDocRegCardBalanceImplH
#define UDMDocRegCardBalanceImplH
#include "IDMDocRegCardBalance.h"
#include "UDMDocRegCardBalance.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocRegCardBalanceImpl)) TDMDocRegCardBalanceImpl : public IDMDocRegCardBalance
{
public:
   TDMDocRegCardBalanceImpl();
   ~TDMDocRegCardBalanceImpl();
   TDMDocRegCardBalance * Object;
   int NumRefs;
   bool flDeleteObject;
   void DeleteImpl(void);

   //IUnknown
   virtual int kanQueryInterface(REFIID id_interface,void ** ppv);
   virtual int kanAddRef(void);
   virtual int kanRelease(void);

   //IMainInterface
   virtual int  get_CodeError(void);
   virtual void set_CodeError(int CodeError);
   virtual UnicodeString  get_TextError(void);
   virtual void set_TextError(UnicodeString  TextError);
   virtual int Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object);
   virtual int Done(void);

//IDMDocRegCardBalance
   virtual TDataSource * get_DataSourceDoc(void);
   virtual void set_DataSourceDoc(TDataSource * DataSourceDoc);

   virtual TDataSource * get_DataSourceDocT(void);
   virtual void set_DataSourceDocT(TDataSource * DataSourceDocT);

   virtual TDataSource * get_DataSourceDocAll(void);
   virtual void set_DataSourceDocAll(TDataSource * DataSourceDocAll);

   virtual TpFIBDataSet * get_DocAll(void);
   virtual void set_DocAll(TpFIBDataSet * DocAll);

   virtual TpFIBDataSet * get_Doc(void);
   virtual void set_Doc(TpFIBDataSet * Doc);

   virtual TpFIBDataSet * get_DocT(void);
   virtual void set_DocT(TpFIBDataSet * DocT);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBTransaction * get_IBTrDvReg(void);
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TpFIBQuery * get_QueryCancelDvReg(void);
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg);

   virtual TpFIBQuery * get_QueryDvReg(void);
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg);

   virtual TFIBDateTimeField * get_DocAllPOSDOC(void);
   virtual void set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC);

   virtual TFIBSmallIntField * get_DocAllPRDOC(void);
   virtual void set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC);

   virtual TFIBIntegerField * get_DocAllNUMDOC(void);
   virtual void set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC);

   virtual TFIBBCDField * get_DocAllSUMDOC(void);
   virtual void set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC);

   virtual TFIBBCDField * get_DocAllIDUSERDOC(void);
   virtual void set_DocAllIDUSERDOC(TFIBBCDField * DocAllIDUSERDOC);

   virtual TFIBLargeIntField * get_DocAllIDDOC(void);
   virtual void set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC);

   virtual TFIBLargeIntField * get_DocAllIDFIRMDOC(void);
   virtual void set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC);

   virtual TFIBLargeIntField * get_DocAllIDSKLDOC(void);
   virtual void set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC);

   virtual TFIBLargeIntField * get_DocAllIDKLDOC(void);
   virtual void set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC);

   virtual TFIBLargeIntField * get_DocAllIDDOGDOC(void);
   virtual void set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC);

   virtual TFIBLargeIntField * get_DocAllIDDOCOSNDOC(void);
   virtual void set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC);

   virtual TFIBLargeIntField * get_DocAllIDEXTDOC(void);
   virtual void set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC);

   virtual TFIBLargeIntField * get_DocAllIDBASE_GALLDOC(void);
   virtual void set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDPROJECT_GALLDOC(void);
   virtual void set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC);

   virtual TFIBLargeIntField * get_DocID_DRG_CARD_BALANCE(void);
   virtual void set_DocID_DRG_CARD_BALANCE(TFIBLargeIntField * DocID_DRG_CARD_BALANCE);

   virtual TFIBLargeIntField * get_DocIDBASE_DRG_CARD_BALANCE(void);
   virtual void set_DocIDBASE_DRG_CARD_BALANCE(TFIBLargeIntField * DocIDBASE_DRG_CARD_BALANCE);

   virtual TFIBLargeIntField * get_DocIDDOC_DRG_CARD_BALANCE(void);
   virtual void set_DocIDDOC_DRG_CARD_BALANCE(TFIBLargeIntField * DocIDDOC_DRG_CARD_BALANCE);

   virtual TFIBLargeIntField * get_DocTID_DRG_CARD_BALANCET(void);
   virtual void set_DocTID_DRG_CARD_BALANCET(TFIBLargeIntField * DocTID_DRG_CARD_BALANCET);

   virtual TFIBLargeIntField * get_DocTIDBASE_DRG_CARD_BALANCET(void);
   virtual void set_DocTIDBASE_DRG_CARD_BALANCET(TFIBLargeIntField * DocTIDBASE_DRG_CARD_BALANCET);

   virtual TFIBLargeIntField * get_DocTIDDOC_DRG_CARD_BALANCET(void);
   virtual void set_DocTIDDOC_DRG_CARD_BALANCET(TFIBLargeIntField * DocTIDDOC_DRG_CARD_BALANCET);

   virtual TFIBSmallIntField * get_DocTTDV_DRG_CARD_BALANCET(void);
   virtual void set_DocTTDV_DRG_CARD_BALANCET(TFIBSmallIntField * DocTTDV_DRG_CARD_BALANCET);

   virtual TFIBLargeIntField * get_DocTIDFIRM_DRG_CARD_BALANCET(void);
   virtual void set_DocTIDFIRM_DRG_CARD_BALANCET(TFIBLargeIntField * DocTIDFIRM_DRG_CARD_BALANCET);

   virtual TFIBLargeIntField * get_DocTIDCARD_DRG_CARD_BALANCET(void);
   virtual void set_DocTIDCARD_DRG_CARD_BALANCET(TFIBLargeIntField * DocTIDCARD_DRG_CARD_BALANCET);

   virtual TFIBBCDField * get_DocTSUM_DRG_CARD_BALANCET(void);
   virtual void set_DocTSUM_DRG_CARD_BALANCET(TFIBBCDField * DocTSUM_DRG_CARD_BALANCET);

   virtual TFIBIntegerField * get_DocTOPER_DRG_CARD_BALANCET(void);
   virtual void set_DocTOPER_DRG_CARD_BALANCET(TFIBIntegerField * DocTOPER_DRG_CARD_BALANCET);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TFIBWideStringField * get_DocAllTDOC(void);
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC);

   virtual TFIBWideStringField * get_DocAllGID_DOC(void);
   virtual void set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC);

   virtual TFIBWideStringField * get_DocAllPREFIKSDOC(void);
   virtual void set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC);

   virtual TFIBIntegerField * get_DocAllTYPEEXTDOC(void);
   virtual void set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC);

   virtual TFIBWideStringField * get_DocAllFNAME_USER(void);
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER);

   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void);
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_DocDESCR_DRG_CARD_BALANCE(void);
   virtual void set_DocDESCR_DRG_CARD_BALANCE(TFIBWideStringField * DocDESCR_DRG_CARD_BALANCE);

   virtual TFIBWideStringField * get_DocTNAMEFIRM(void);
   virtual void set_DocTNAMEFIRM(TFIBWideStringField * DocTNAMEFIRM);

   virtual TFIBWideStringField * get_DocTNAME_SDISCOUNT_CARD(void);
   virtual void set_DocTNAME_SDISCOUNT_CARD(TFIBWideStringField * DocTNAME_SDISCOUNT_CARD);

   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_GALLDOC(void);
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC);

   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void);
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT);

   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void);
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER);

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_EnableDvReg(void);
   virtual void set_EnableDvReg(bool EnableDvReg);

   virtual bool NewDoc(void);
   virtual bool OpenDoc(__int64 IdDoc);
   virtual bool SaveDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual void TableAppend(void);
   virtual void TableDelete(void);
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TDMDocRegCardBalanceImpl __uuidof(TDMDocRegCardBalanceImpl)
#endif
