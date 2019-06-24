#ifndef UDMDocRealRoznImplH
#define UDMDocRealRoznImplH
#include "IDMDocRealRozn.h"
#include "UDMDocRealRozn.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocRealRoznImpl)) TDMDocRealRoznImpl : public IDMDocRealRozn
{
public:
   TDMDocRealRoznImpl();
   ~TDMDocRealRoznImpl();
   TDMDocRealRozn * Object;
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

//IDMDocRealRozn
   virtual TDataSource * get_DataSourceDoc(void);
   virtual void set_DataSourceDoc(TDataSource * DataSourceDoc);

   virtual TDataSource * get_DataSourceDocT(void);
   virtual void set_DataSourceDocT(TDataSource * DataSourceDocT);

   virtual TDataSource * get_DataSourceDocAll(void);
   virtual void set_DataSourceDocAll(TDataSource * DataSourceDocAll);

   virtual TDataSource * get_DataSourcePay(void);
   virtual void set_DataSourcePay(TDataSource * DataSourcePay);

   virtual TpFIBDataSet * get_DocAll(void);
   virtual void set_DocAll(TpFIBDataSet * DocAll);

   virtual TpFIBDataSet * get_Doc(void);
   virtual void set_Doc(TpFIBDataSet * Doc);

   virtual TpFIBDataSet * get_DocT(void);
   virtual void set_DocT(TpFIBDataSet * DocT);

   virtual TpFIBDataSet * get_Pay(void);
   virtual void set_Pay(TpFIBDataSet * Pay);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TFIBBCDField * get_DocFIRSTSUM_DREALROZN(void);
   virtual void set_DocFIRSTSUM_DREALROZN(TFIBBCDField * DocFIRSTSUM_DREALROZN);

   virtual TFIBDateTimeField * get_DocAllPOSDOC(void);
   virtual void set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC);

   virtual TFIBSmallIntField * get_DocAllPRDOC(void);
   virtual void set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC);

   virtual TFIBIntegerField * get_DocAllNUMDOC(void);
   virtual void set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC);

   virtual TFIBBCDField * get_DocAllSUMDOC(void);
   virtual void set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC);

   virtual TFIBBCDField * get_DocTKOL_DREALROZNT(void);
   virtual void set_DocTKOL_DREALROZNT(TFIBBCDField * DocTKOL_DREALROZNT);

   virtual TFIBBCDField * get_DocTKF_DREALROZNT(void);
   virtual void set_DocTKF_DREALROZNT(TFIBBCDField * DocTKF_DREALROZNT);

   virtual TFIBBCDField * get_DocTPRICE_DREALROZNT(void);
   virtual void set_DocTPRICE_DREALROZNT(TFIBBCDField * DocTPRICE_DREALROZNT);

   virtual TFIBBCDField * get_DocTSUM_DREALROZNT(void);
   virtual void set_DocTSUM_DREALROZNT(TFIBBCDField * DocTSUM_DREALROZNT);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TFIBDateField * get_PayDO_DREALROZN_PAY(void);
   virtual void set_PayDO_DREALROZN_PAY(TFIBDateField * PayDO_DREALROZN_PAY);

   virtual TFIBBCDField * get_PaySUM_DREALROZN_PAY(void);
   virtual void set_PaySUM_DREALROZN_PAY(TFIBBCDField * PaySUM_DREALROZN_PAY);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TpFIBTransaction * get_IBTrDvReg(void);
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg);

   virtual TIntegerField * get_PayRECNO(void);
   virtual void set_PayRECNO(TIntegerField * PayRECNO);

   virtual TpFIBQuery * get_QueryCancelDvReg(void);
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg);

   virtual TpFIBQuery * get_QueryDvReg(void);
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg);

   virtual TFIBBCDField * get_DocTPRICEFULL_DREALROZNT(void);
   virtual void set_DocTPRICEFULL_DREALROZNT(TFIBBCDField * DocTPRICEFULL_DREALROZNT);

   virtual TFIBBCDField * get_DocTPRSK_DREALROZNT(void);
   virtual void set_DocTPRSK_DREALROZNT(TFIBBCDField * DocTPRSK_DREALROZNT);

   virtual TFIBBCDField * get_DocTSUMSK_DREALROZNT(void);
   virtual void set_DocTSUMSK_DREALROZNT(TFIBBCDField * DocTSUMSK_DREALROZNT);

   virtual TFIBBCDField * get_DocTPRNAD_DREALROZNT(void);
   virtual void set_DocTPRNAD_DREALROZNT(TFIBBCDField * DocTPRNAD_DREALROZNT);

   virtual TFIBBCDField * get_DocTSUMNAD_DREALROZNT(void);
   virtual void set_DocTSUMNAD_DREALROZNT(TFIBBCDField * DocTSUMNAD_DREALROZNT);

   virtual TFIBIntegerField * get_DocTNDS_DREALROZNT(void);
   virtual void set_DocTNDS_DREALROZNT(TFIBIntegerField * DocTNDS_DREALROZNT);

   virtual TFIBBCDField * get_DocTSUMNDS_DREALROZNT(void);
   virtual void set_DocTSUMNDS_DREALROZNT(TFIBBCDField * DocTSUMNDS_DREALROZNT);

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

   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void);
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void);
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM);

   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void);
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD);

   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void);
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT);

   virtual TFIBWideStringField * get_DocAllFNAME_USER(void);
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER);

   virtual TFIBWideStringField * get_DocAllNAME_SDOG(void);
   virtual void set_DocAllNAME_SDOG(TFIBWideStringField * DocAllNAME_SDOG);

   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void);
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT);

   virtual TFIBLargeIntField * get_DocID_DREALROZN(void);
   virtual void set_DocID_DREALROZN(TFIBLargeIntField * DocID_DREALROZN);

   virtual TFIBLargeIntField * get_DocIDDOC_DREALROZN(void);
   virtual void set_DocIDDOC_DREALROZN(TFIBLargeIntField * DocIDDOC_DREALROZN);

   virtual TFIBWideStringField * get_DocGID_DREALROZN(void);
   virtual void set_DocGID_DREALROZN(TFIBWideStringField * DocGID_DREALROZN);

   virtual TFIBLargeIntField * get_DocIDTPRICE_DREALROZN(void);
   virtual void set_DocIDTPRICE_DREALROZN(TFIBLargeIntField * DocIDTPRICE_DREALROZN);

   virtual TFIBWideStringField * get_DocPRIM_DREALROZN(void);
   virtual void set_DocPRIM_DREALROZN(TFIBWideStringField * DocPRIM_DREALROZN);

   virtual TFIBLargeIntField * get_DocIDKKM_DREALROZN(void);
   virtual void set_DocIDKKM_DREALROZN(TFIBLargeIntField * DocIDKKM_DREALROZN);

   virtual TFIBLargeIntField * get_DocIDDCARD_DREALROZN(void);
   virtual void set_DocIDDCARD_DREALROZN(TFIBLargeIntField * DocIDDCARD_DREALROZN);

   virtual TFIBLargeIntField * get_DocIDBASE_DREALROZN(void);
   virtual void set_DocIDBASE_DREALROZN(TFIBLargeIntField * DocIDBASE_DREALROZN);

   virtual TFIBWideStringField * get_DocNAME_TPRICE(void);
   virtual void set_DocNAME_TPRICE(TFIBWideStringField * DocNAME_TPRICE);

   virtual TFIBWideStringField * get_DocNAMEKKM(void);
   virtual void set_DocNAMEKKM(TFIBWideStringField * DocNAMEKKM);

   virtual TFIBLargeIntField * get_DocTID_DREALROZNT(void);
   virtual void set_DocTID_DREALROZNT(TFIBLargeIntField * DocTID_DREALROZNT);

   virtual TFIBLargeIntField * get_DocTIDDOC_DREALROZNT(void);
   virtual void set_DocTIDDOC_DREALROZNT(TFIBLargeIntField * DocTIDDOC_DREALROZNT);

   virtual TFIBWideStringField * get_DocTGID_DREALROZNT(void);
   virtual void set_DocTGID_DREALROZNT(TFIBWideStringField * DocTGID_DREALROZNT);

   virtual TFIBLargeIntField * get_DocTIDNOM_DREALROZNT(void);
   virtual void set_DocTIDNOM_DREALROZNT(TFIBLargeIntField * DocTIDNOM_DREALROZNT);

   virtual TFIBLargeIntField * get_DocTIDED_DREALROZNT(void);
   virtual void set_DocTIDED_DREALROZNT(TFIBLargeIntField * DocTIDED_DREALROZNT);

   virtual TFIBLargeIntField * get_DocTIDBASE_DREALROZNT(void);
   virtual void set_DocTIDBASE_DREALROZNT(TFIBLargeIntField * DocTIDBASE_DREALROZNT);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBSmallIntField * get_DocTTNOM(void);
   virtual void set_DocTTNOM(TFIBSmallIntField * DocTTNOM);

   virtual TFIBLargeIntField * get_PayID_DREALROZN_PAY(void);
   virtual void set_PayID_DREALROZN_PAY(TFIBLargeIntField * PayID_DREALROZN_PAY);

   virtual TFIBLargeIntField * get_PayIDDOC_DREALROZN_PAY(void);
   virtual void set_PayIDDOC_DREALROZN_PAY(TFIBLargeIntField * PayIDDOC_DREALROZN_PAY);

   virtual TFIBWideStringField * get_PayGID_DREALROZN_PAY(void);
   virtual void set_PayGID_DREALROZN_PAY(TFIBWideStringField * PayGID_DREALROZN_PAY);

   virtual TFIBLargeIntField * get_PayIDBASE_DREALROZN_PAY(void);
   virtual void set_PayIDBASE_DREALROZN_PAY(TFIBLargeIntField * PayIDBASE_DREALROZN_PAY);

   virtual TFIBWideStringField * get_DocAllTDOC(void);
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC);

   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_GALLDOC(void);
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC);

   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void);
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER);

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC);

   virtual TFIBBCDField * get_DocTPRSK_CARD_DREALROZNT(void);
   virtual void set_DocTPRSK_CARD_DREALROZNT(TFIBBCDField * DocTPRSK_CARD_DREALROZNT);

   virtual TFIBBCDField * get_DocTPRSK_AUTO_DREALROZNT(void);
   virtual void set_DocTPRSK_AUTO_DREALROZNT(TFIBBCDField * DocTPRSK_AUTO_DREALROZNT);

   virtual TFIBBCDField * get_DocTPRSK_HAND_DREALROZNT(void);
   virtual void set_DocTPRSK_HAND_DREALROZNT(TFIBBCDField * DocTPRSK_HAND_DREALROZNT);

   virtual TFIBSmallIntField * get_DocTNO_SK_DREALROZNT(void);
   virtual void set_DocTNO_SK_DREALROZNT(TFIBSmallIntField * DocTNO_SK_DREALROZNT);

   virtual TFIBWideStringField * get_DocTARTNOM(void);
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM);

   virtual TFIBIntegerField * get_DocTCODENOM(void);
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM);

   virtual TFIBWideStringField * get_DocTSHED(void);
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED);

   virtual bool get_NewElement(void);
   virtual void set_NewElement(bool NewElement);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_NoEdit(void);
   virtual void set_NoEdit(bool NoEdit);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual __int64 get_IdSklad(void);
   virtual void set_IdSklad(__int64 IdSklad);

   virtual bool get_AutoRaschet(void);
   virtual void set_AutoRaschet(bool AutoRaschet);

   virtual bool get_EnableDvReg(void);
   virtual void set_EnableDvReg(bool EnableDvReg);

   virtual bool get_SkladRozn(void);
   virtual void set_SkladRozn(bool SkladRozn);

   virtual bool get_NoOtrOstatok(void);
   virtual void set_NoOtrOstatok(bool NoOtrOstatok);

   virtual void NewDoc(void);
   virtual void OpenDoc(__int64 IdDoc);
   virtual bool SaveDoc(void);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual void AddDocNewString(void);
   virtual void DeleteStringDoc(void);
   virtual void CloseDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TDMDocRealRoznImpl __uuidof(TDMDocRealRoznImpl)
#endif
