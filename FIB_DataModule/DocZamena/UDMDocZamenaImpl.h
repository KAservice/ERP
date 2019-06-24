#ifndef UDMDocZamenaImplH
#define UDMDocZamenaImplH
#include "IDMDocZamena.h"
#include "UDMDocZamena.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocZamenaImpl)) TDMDocZamenaImpl : public IDMDocZamena
{
public:
   TDMDocZamenaImpl();
   ~TDMDocZamenaImpl();
   TDMDocZamena * Object;
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

//IDMDocZamena
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

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TFIBLargeIntField * get_DocAllIDDOC(void);
   virtual void set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC);

   virtual TFIBDateTimeField * get_DocAllPOSDOC(void);
   virtual void set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC);

   virtual TFIBSmallIntField * get_DocAllPRDOC(void);
   virtual void set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC);

   virtual TFIBWideStringField * get_DocAllTDOC(void);
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC);

   virtual TFIBIntegerField * get_DocAllNUMDOC(void);
   virtual void set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC);

   virtual TFIBLargeIntField * get_DocAllIDFIRMDOC(void);
   virtual void set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC);

   virtual TFIBLargeIntField * get_DocAllIDSKLDOC(void);
   virtual void set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC);

   virtual TFIBLargeIntField * get_DocAllIDKLDOC(void);
   virtual void set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC);

   virtual TFIBLargeIntField * get_DocAllIDDOGDOC(void);
   virtual void set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC);

   virtual TFIBBCDField * get_DocAllSUMDOC(void);
   virtual void set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC);

   virtual TFIBLargeIntField * get_DocAllIDUSERDOC(void);
   virtual void set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC);

   virtual TFIBWideStringField * get_DocAllGID_DOC(void);
   virtual void set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC);

   virtual TFIBWideStringField * get_DocAllPREFIKSDOC(void);
   virtual void set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC);

   virtual TFIBLargeIntField * get_DocAllIDDOCOSNDOC(void);
   virtual void set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC);

   virtual TFIBLargeIntField * get_DocAllIDEXTDOC(void);
   virtual void set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC);

   virtual TFIBIntegerField * get_DocAllTYPEEXTDOC(void);
   virtual void set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC);

   virtual TFIBLargeIntField * get_DocAllIDBASE_GALLDOC(void);
   virtual void set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDPROJECT_GALLDOC(void);
   virtual void set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC);

   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_GALLDOC(void);
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC);

   virtual TFIBWideStringField * get_DocAllFNAME_USER(void);
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER);

   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void);
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void);
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM);

   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void);
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD);

   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void);
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT);

   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void);
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER);

   virtual TFIBLargeIntField * get_DocID_DZAMENA(void);
   virtual void set_DocID_DZAMENA(TFIBLargeIntField * DocID_DZAMENA);

   virtual TFIBLargeIntField * get_DocIDBASE_DZAMENA(void);
   virtual void set_DocIDBASE_DZAMENA(TFIBLargeIntField * DocIDBASE_DZAMENA);

   virtual TFIBLargeIntField * get_DocIDDOC_DZAMENA(void);
   virtual void set_DocIDDOC_DZAMENA(TFIBLargeIntField * DocIDDOC_DZAMENA);

   virtual TFIBIntegerField * get_DocOPER_DZAMENA(void);
   virtual void set_DocOPER_DZAMENA(TFIBIntegerField * DocOPER_DZAMENA);

   virtual TFIBWideStringField * get_DocDESCR_DZAMENA(void);
   virtual void set_DocDESCR_DZAMENA(TFIBWideStringField * DocDESCR_DZAMENA);

   virtual TFIBLargeIntField * get_DocIDRTPRICE_DZAMENA(void);
   virtual void set_DocIDRTPRICE_DZAMENA(TFIBLargeIntField * DocIDRTPRICE_DZAMENA);

   virtual TFIBBCDField * get_DocS_RSUM_DZAMENA(void);
   virtual void set_DocS_RSUM_DZAMENA(TFIBBCDField * DocS_RSUM_DZAMENA);

   virtual TFIBBCDField * get_DocP_RSUM_DZAMENA(void);
   virtual void set_DocP_RSUM_DZAMENA(TFIBBCDField * DocP_RSUM_DZAMENA);

   virtual TFIBLargeIntField * get_DocTID_DZAMENAT(void);
   virtual void set_DocTID_DZAMENAT(TFIBLargeIntField * DocTID_DZAMENAT);

   virtual TFIBLargeIntField * get_DocTIDBASE_DZAMENAT(void);
   virtual void set_DocTIDBASE_DZAMENAT(TFIBLargeIntField * DocTIDBASE_DZAMENAT);

   virtual TFIBLargeIntField * get_DocTIDDOC_DZAMENAT(void);
   virtual void set_DocTIDDOC_DZAMENAT(TFIBLargeIntField * DocTIDDOC_DZAMENAT);

   virtual TFIBLargeIntField * get_DocTS_IDNOM_DZAMENAT(void);
   virtual void set_DocTS_IDNOM_DZAMENAT(TFIBLargeIntField * DocTS_IDNOM_DZAMENAT);

   virtual TFIBLargeIntField * get_DocTS_IDED_DZAMENAT(void);
   virtual void set_DocTS_IDED_DZAMENAT(TFIBLargeIntField * DocTS_IDED_DZAMENAT);

   virtual TFIBBCDField * get_DocTS_KF_DZAMENAT(void);
   virtual void set_DocTS_KF_DZAMENAT(TFIBBCDField * DocTS_KF_DZAMENAT);

   virtual TFIBBCDField * get_DocTS_KOL_DZAMENAT(void);
   virtual void set_DocTS_KOL_DZAMENAT(TFIBBCDField * DocTS_KOL_DZAMENAT);

   virtual TFIBBCDField * get_DocTS_RPRICE_DZAMENAT(void);
   virtual void set_DocTS_RPRICE_DZAMENAT(TFIBBCDField * DocTS_RPRICE_DZAMENAT);

   virtual TFIBBCDField * get_DocTS_RSUM_DZAMENAT(void);
   virtual void set_DocTS_RSUM_DZAMENAT(TFIBBCDField * DocTS_RSUM_DZAMENAT);

   virtual TFIBLargeIntField * get_DocTP_IDNOM_DZAMENAT(void);
   virtual void set_DocTP_IDNOM_DZAMENAT(TFIBLargeIntField * DocTP_IDNOM_DZAMENAT);

   virtual TFIBLargeIntField * get_DocTP_IDED_DZAMENAT(void);
   virtual void set_DocTP_IDED_DZAMENAT(TFIBLargeIntField * DocTP_IDED_DZAMENAT);

   virtual TFIBLargeIntField * get_DocTP_IDPART_DZAMENAT(void);
   virtual void set_DocTP_IDPART_DZAMENAT(TFIBLargeIntField * DocTP_IDPART_DZAMENAT);

   virtual TFIBBCDField * get_DocTP_KF_DZAMENAT(void);
   virtual void set_DocTP_KF_DZAMENAT(TFIBBCDField * DocTP_KF_DZAMENAT);

   virtual TFIBBCDField * get_DocTP_KOL_DZAMENAT(void);
   virtual void set_DocTP_KOL_DZAMENAT(TFIBBCDField * DocTP_KOL_DZAMENAT);

   virtual TFIBBCDField * get_DocTP_RPRICE_DZAMENAT(void);
   virtual void set_DocTP_RPRICE_DZAMENAT(TFIBBCDField * DocTP_RPRICE_DZAMENAT);

   virtual TFIBBCDField * get_DocTP_RSUM_DZAMENAT(void);
   virtual void set_DocTP_RSUM_DZAMENAT(TFIBBCDField * DocTP_RSUM_DZAMENAT);

   virtual TFIBWideStringField * get_DocTS_NAMENOM(void);
   virtual void set_DocTS_NAMENOM(TFIBWideStringField * DocTS_NAMENOM);

   virtual TFIBWideStringField * get_DocTS_NAMEED(void);
   virtual void set_DocTS_NAMEED(TFIBWideStringField * DocTS_NAMEED);

   virtual TFIBWideStringField * get_DocTP_NAMENOM(void);
   virtual void set_DocTP_NAMENOM(TFIBWideStringField * DocTP_NAMENOM);

   virtual TFIBWideStringField * get_DocTP_NAMEED(void);
   virtual void set_DocTP_NAMEED(TFIBWideStringField * DocTP_NAMEED);

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_SkladRozn(void);
   virtual void set_SkladRozn(bool SkladRozn);

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
   virtual __int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc);
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TDMDocZamenaImpl __uuidof(TDMDocZamenaImpl)
#endif
