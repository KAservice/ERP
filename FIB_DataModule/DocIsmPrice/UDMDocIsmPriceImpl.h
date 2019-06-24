#ifndef UDMDocIsmPriceImplH
#define UDMDocIsmPriceImplH
#include "IDMDocIsmPrice.h"
#include "UDMDocIsmPrice.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocIsmPriceImpl)) TDMDocIsmPriceImpl : public IDMDocIsmPrice
{
public:
   TDMDocIsmPriceImpl();
   ~TDMDocIsmPriceImpl();
   TDMDocIsmPrice * Object;
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

//IDMDocIsmPrice
   virtual TDataSource * get_DataSourceDoc(void);
   virtual void set_DataSourceDoc(TDataSource * DataSourceDoc);

   virtual TDataSource * get_DataSourceDocT(void);
   virtual void set_DataSourceDocT(TDataSource * DataSourceDocT);

   virtual TDataSource * get_DataSourceDocAll(void);
   virtual void set_DataSourceDocAll(TDataSource * DataSourceDocAll);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_DocAll(void);
   virtual void set_DocAll(TpFIBDataSet * DocAll);

   virtual TpFIBDataSet * get_Doc(void);
   virtual void set_Doc(TpFIBDataSet * Doc);

   virtual TpFIBDataSet * get_DocT(void);
   virtual void set_DocT(TpFIBDataSet * DocT);

   virtual TpFIBTransaction * get_IBTrDvReg(void);
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TpFIBQuery * get_QueryCancelDvReg(void);
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg);

   virtual TpFIBQuery * get_QueryDvReg(void);
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TFloatField * get_DocTOLDSUM(void);
   virtual void set_DocTOLDSUM(TFloatField * DocTOLDSUM);

   virtual TFloatField * get_DocTNEWSUM(void);
   virtual void set_DocTNEWSUM(TFloatField * DocTNEWSUM);

   virtual TFloatField * get_DocTSUMISM(void);
   virtual void set_DocTSUMISM(TFloatField * DocTSUMISM);

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

   virtual TFIBLargeIntField * get_DocID_DISMPRICE(void);
   virtual void set_DocID_DISMPRICE(TFIBLargeIntField * DocID_DISMPRICE);

   virtual TFIBWideStringField * get_DocGID_DISMPRICE(void);
   virtual void set_DocGID_DISMPRICE(TFIBWideStringField * DocGID_DISMPRICE);

   virtual TFIBLargeIntField * get_DocIDDOC_DISMPRICE(void);
   virtual void set_DocIDDOC_DISMPRICE(TFIBLargeIntField * DocIDDOC_DISMPRICE);

   virtual TFIBWideStringField * get_DocDESCR_DISMPRICE(void);
   virtual void set_DocDESCR_DISMPRICE(TFIBWideStringField * DocDESCR_DISMPRICE);

   virtual TFIBLargeIntField * get_DocIDNEWTPRICE_DISMPRICE(void);
   virtual void set_DocIDNEWTPRICE_DISMPRICE(TFIBLargeIntField * DocIDNEWTPRICE_DISMPRICE);

   virtual TFIBLargeIntField * get_DocIDBASE_DISMPRICE(void);
   virtual void set_DocIDBASE_DISMPRICE(TFIBLargeIntField * DocIDBASE_DISMPRICE);

   virtual TFIBIntegerField * get_DocOPER_DISMPRICE(void);
   virtual void set_DocOPER_DISMPRICE(TFIBIntegerField * DocOPER_DISMPRICE);

   virtual TFIBLargeIntField * get_DocIDINV_DISMPRICE(void);
   virtual void set_DocIDINV_DISMPRICE(TFIBLargeIntField * DocIDINV_DISMPRICE);

   virtual TFIBWideStringField * get_DocNAME_SINV(void);
   virtual void set_DocNAME_SINV(TFIBWideStringField * DocNAME_SINV);

   virtual TFIBLargeIntField * get_DocTID_DISMPRICET(void);
   virtual void set_DocTID_DISMPRICET(TFIBLargeIntField * DocTID_DISMPRICET);

   virtual TFIBWideStringField * get_DocTGID_DISMPRICET(void);
   virtual void set_DocTGID_DISMPRICET(TFIBWideStringField * DocTGID_DISMPRICET);

   virtual TFIBLargeIntField * get_DocTIDDOC_DISMPRICET(void);
   virtual void set_DocTIDDOC_DISMPRICET(TFIBLargeIntField * DocTIDDOC_DISMPRICET);

   virtual TFIBLargeIntField * get_DocTIDNOM_DISMPRICET(void);
   virtual void set_DocTIDNOM_DISMPRICET(TFIBLargeIntField * DocTIDNOM_DISMPRICET);

   virtual TFIBLargeIntField * get_DocTIDED_DISMPRICET(void);
   virtual void set_DocTIDED_DISMPRICET(TFIBLargeIntField * DocTIDED_DISMPRICET);

   virtual TFIBBCDField * get_DocTKOL_DISMPRICET(void);
   virtual void set_DocTKOL_DISMPRICET(TFIBBCDField * DocTKOL_DISMPRICET);

   virtual TFIBBCDField * get_DocTKF_DISMPRICET(void);
   virtual void set_DocTKF_DISMPRICET(TFIBBCDField * DocTKF_DISMPRICET);

   virtual TFIBBCDField * get_DocTOLDPRICE_DISMPRICET(void);
   virtual void set_DocTOLDPRICE_DISMPRICET(TFIBBCDField * DocTOLDPRICE_DISMPRICET);

   virtual TFIBBCDField * get_DocTNEWPRICE_DISMPRICET(void);
   virtual void set_DocTNEWPRICE_DISMPRICET(TFIBBCDField * DocTNEWPRICE_DISMPRICET);

   virtual TFIBLargeIntField * get_DocTIDBASE_DISMPRICET(void);
   virtual void set_DocTIDBASE_DISMPRICET(TFIBLargeIntField * DocTIDBASE_DISMPRICET);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBIntegerField * get_DocTTNOM(void);
   virtual void set_DocTTNOM(TFIBIntegerField * DocTTNOM);

   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_GALLDOC(void);
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC);

   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void);
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT);

   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void);
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER);

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC);

   virtual TFIBBCDField * get_DocTSEB_PRICE_DISMPRICET(void);
   virtual void set_DocTSEB_PRICE_DISMPRICET(TFIBBCDField * DocTSEB_PRICE_DISMPRICET);

   virtual TFIBBCDField * get_DocTSEB_SUM_DISMPRICET(void);
   virtual void set_DocTSEB_SUM_DISMPRICET(TFIBBCDField * DocTSEB_SUM_DISMPRICET);

   virtual TFIBBCDField * get_DocTNAC_SUM_ED(void);
   virtual void set_DocTNAC_SUM_ED(TFIBBCDField * DocTNAC_SUM_ED);

   virtual TFIBBCDField * get_DocTNAC_SUM(void);
   virtual void set_DocTNAC_SUM(TFIBBCDField * DocTNAC_SUM);

   virtual TFIBBCDField * get_DocTNAC_NEW_DISMPRICET(void);
   virtual void set_DocTNAC_NEW_DISMPRICET(TFIBBCDField * DocTNAC_NEW_DISMPRICET);

   virtual TFIBBCDField * get_DocTNAC_OLD_DISMPRICET(void);
   virtual void set_DocTNAC_OLD_DISMPRICET(TFIBBCDField * DocTNAC_OLD_DISMPRICET);

   virtual TFIBWideStringField * get_DocTSHED(void);
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED);

   virtual TFIBWideStringField * get_DocTARTNOM(void);
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM);

   virtual TFIBIntegerField * get_DocTCODENOM(void);
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM);

   virtual bool get_NewElement(void);
   virtual void set_NewElement(bool NewElement);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual UnicodeString get_ProsmotrText(void);
   virtual void set_ProsmotrText(UnicodeString ProsmotrText);

   virtual bool get_NoEdit(void);
   virtual void set_NoEdit(bool NoEdit);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdElementaMaster(void);
   virtual void set_IdElementaMaster(__int64 IdElementaMaster);

   virtual bool get_IsmPrice(void);
   virtual void set_IsmPrice(bool IsmPrice);

   virtual __int64 get_IdSklad(void);
   virtual void set_IdSklad(__int64 IdSklad);

   virtual bool get_AutoRaschet(void);
   virtual void set_AutoRaschet(bool AutoRaschet);

   virtual bool get_EnableDvReg(void);
   virtual void set_EnableDvReg(bool EnableDvReg);

   virtual void NewDoc(void);
   virtual void OpenDoc(__int64 IdDoc);
   virtual void ValidateProsmotr(void);
   virtual bool SaveDoc(void);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual void AddDocNewString(void);
   virtual void DeleteStringDoc(void);
   virtual void CloseDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TDMDocIsmPriceImpl __uuidof(TDMDocIsmPriceImpl)
#endif
