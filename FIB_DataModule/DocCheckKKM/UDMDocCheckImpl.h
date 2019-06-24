#ifndef UDMDocCheckImplH
#define UDMDocCheckImplH
#include "IDMDocCheck.h"
#include "UDMDocCheck.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocCheckImpl)) TDMDocCheckImpl : public IDMDocCheck
{
public:
   TDMDocCheckImpl();
   ~TDMDocCheckImpl();
   TDMDocCheck * Object;
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

//IDMDocCheck
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

   virtual TFIBDateTimeField * get_DocAllPOSDOC(void);
   virtual void set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC);

   virtual TFIBSmallIntField * get_DocAllPRDOC(void);
   virtual void set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC);

   virtual TFIBIntegerField * get_DocAllNUMDOC(void);
   virtual void set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC);

   virtual TpFIBTransaction * get_IBTrDvReg(void);
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TpFIBDataSet * get_SpisokTypePrice(void);
   virtual void set_SpisokTypePrice(TpFIBDataSet * SpisokTypePrice);

   virtual TFIBIntegerField * get_SpisokTypePriceID_TPRICE(void);
   virtual void set_SpisokTypePriceID_TPRICE(TFIBIntegerField * SpisokTypePriceID_TPRICE);

   virtual TpFIBQuery * get_QueryCancelDvReg(void);
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg);

   virtual TpFIBQuery * get_QueryDvReg(void);
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg);

   virtual TpFIBDataSet * get_DocOsn(void);
   virtual void set_DocOsn(TpFIBDataSet * DocOsn);

   virtual TDataSource * get_DataSourceDocOsn(void);
   virtual void set_DataSourceDocOsn(TDataSource * DataSourceDocOsn);

   virtual TpFIBDataSet * get_DocOpl(void);
   virtual void set_DocOpl(TpFIBDataSet * DocOpl);

   virtual TDataSource * get_DataSourceDocOpl(void);
   virtual void set_DataSourceDocOpl(TDataSource * DataSourceDocOpl);

   virtual TFIBLargeIntField * get_DocAllIDDOC(void);
   virtual void set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC);

   virtual TFIBWideStringField * get_DocAllTDOC(void);
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC);

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

   virtual TFIBWideStringField * get_DocAllFNAME_USER(void);
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER);

   virtual TFIBWideStringField * get_DocAllNAME_SDOG(void);
   virtual void set_DocAllNAME_SDOG(TFIBWideStringField * DocAllNAME_SDOG);

   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void);
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT);

   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void);
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void);
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM);

   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void);
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD);

   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void);
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT);

   virtual TFIBWideStringField * get_DocOsnTDOC(void);
   virtual void set_DocOsnTDOC(TFIBWideStringField * DocOsnTDOC);

   virtual TFIBDateTimeField * get_DocOsnPOSDOC(void);
   virtual void set_DocOsnPOSDOC(TFIBDateTimeField * DocOsnPOSDOC);

   virtual TFIBIntegerField * get_DocOsnNUMDOC(void);
   virtual void set_DocOsnNUMDOC(TFIBIntegerField * DocOsnNUMDOC);

   virtual TIntegerField * get_DocOplRECNO(void);
   virtual void set_DocOplRECNO(TIntegerField * DocOplRECNO);

   virtual TFIBLargeIntField * get_DocIDCHK(void);
   virtual void set_DocIDCHK(TFIBLargeIntField * DocIDCHK);

   virtual TFIBLargeIntField * get_DocIDDOCCHK(void);
   virtual void set_DocIDDOCCHK(TFIBLargeIntField * DocIDDOCCHK);

   virtual TFIBLargeIntField * get_DocIDKKMCHK(void);
   virtual void set_DocIDKKMCHK(TFIBLargeIntField * DocIDKKMCHK);

   virtual TFIBLargeIntField * get_DocIDTPRICE(void);
   virtual void set_DocIDTPRICE(TFIBLargeIntField * DocIDTPRICE);

   virtual TFIBIntegerField * get_DocNCHECKCHK(void);
   virtual void set_DocNCHECKCHK(TFIBIntegerField * DocNCHECKCHK);

   virtual TFIBIntegerField * get_DocNKLCHK(void);
   virtual void set_DocNKLCHK(TFIBIntegerField * DocNKLCHK);

   virtual TFIBIntegerField * get_DocOPERCHK(void);
   virtual void set_DocOPERCHK(TFIBIntegerField * DocOPERCHK);

   virtual TFIBBCDField * get_DocOPLNALCHK(void);
   virtual void set_DocOPLNALCHK(TFIBBCDField * DocOPLNALCHK);

   virtual TFIBBCDField * get_DocOPLPCCHK(void);
   virtual void set_DocOPLPCCHK(TFIBBCDField * DocOPLPCCHK);

   virtual TFIBBCDField * get_DocNALCHK(void);
   virtual void set_DocNALCHK(TFIBBCDField * DocNALCHK);

   virtual TFIBWideStringField * get_DocPRIMCHK(void);
   virtual void set_DocPRIMCHK(TFIBWideStringField * DocPRIMCHK);

   virtual TFIBWideStringField * get_DocGID_DCHK(void);
   virtual void set_DocGID_DCHK(TFIBWideStringField * DocGID_DCHK);

   virtual TFIBSmallIntField * get_DocDVREGCHK(void);
   virtual void set_DocDVREGCHK(TFIBSmallIntField * DocDVREGCHK);

   virtual TFIBWideStringField * get_DocSAVNUMCHK(void);
   virtual void set_DocSAVNUMCHK(TFIBWideStringField * DocSAVNUMCHK);

   virtual TFIBWideStringField * get_DocMODELCHK(void);
   virtual void set_DocMODELCHK(TFIBWideStringField * DocMODELCHK);

   virtual TFIBWideStringField * get_DocREGNUMCHK(void);
   virtual void set_DocREGNUMCHK(TFIBWideStringField * DocREGNUMCHK);

   virtual TFIBLargeIntField * get_DocIDDCARDCHK(void);
   virtual void set_DocIDDCARDCHK(TFIBLargeIntField * DocIDDCARDCHK);

   virtual TFIBLargeIntField * get_DocIDBASE_DCHK(void);
   virtual void set_DocIDBASE_DCHK(TFIBLargeIntField * DocIDBASE_DCHK);

   virtual TFIBBCDField * get_DocSDACHA_DCHK(void);
   virtual void set_DocSDACHA_DCHK(TFIBBCDField * DocSDACHA_DCHK);

   virtual TFIBLargeIntField * get_DocIDBSCHET_DCHK(void);
   virtual void set_DocIDBSCHET_DCHK(TFIBLargeIntField * DocIDBSCHET_DCHK);

   virtual TFIBBCDField * get_DocOPLPLATCARD_DCHK(void);
   virtual void set_DocOPLPLATCARD_DCHK(TFIBBCDField * DocOPLPLATCARD_DCHK);

   virtual TFIBBCDField * get_DocOPLCREDITCARD_DCHK(void);
   virtual void set_DocOPLCREDITCARD_DCHK(TFIBBCDField * DocOPLCREDITCARD_DCHK);

   virtual TFIBBCDField * get_DocOPLPLATCARD_ALL_DCHK(void);
   virtual void set_DocOPLPLATCARD_ALL_DCHK(TFIBBCDField * DocOPLPLATCARD_ALL_DCHK);

   virtual TFIBBCDField * get_DocOPLCREDITCARD_ALL_DCHK(void);
   virtual void set_DocOPLCREDITCARD_ALL_DCHK(TFIBBCDField * DocOPLCREDITCARD_ALL_DCHK);

   virtual TFIBWideStringField * get_DocNAMEKKM(void);
   virtual void set_DocNAMEKKM(TFIBWideStringField * DocNAMEKKM);

   virtual TFIBWideStringField * get_DocNAME_SDISCOUNT_CARD(void);
   virtual void set_DocNAME_SDISCOUNT_CARD(TFIBWideStringField * DocNAME_SDISCOUNT_CARD);

   virtual TFIBWideStringField * get_DocNAMEBSCHET(void);
   virtual void set_DocNAMEBSCHET(TFIBWideStringField * DocNAMEBSCHET);

   virtual TFIBLargeIntField * get_DocTIDCHKT(void);
   virtual void set_DocTIDCHKT(TFIBLargeIntField * DocTIDCHKT);

   virtual TFIBLargeIntField * get_DocTIDDOCCHKT(void);
   virtual void set_DocTIDDOCCHKT(TFIBLargeIntField * DocTIDDOCCHKT);

   virtual TFIBLargeIntField * get_DocTIDNOMCHKT(void);
   virtual void set_DocTIDNOMCHKT(TFIBLargeIntField * DocTIDNOMCHKT);

   virtual TFIBLargeIntField * get_DocTIDEDCHKT(void);
   virtual void set_DocTIDEDCHKT(TFIBLargeIntField * DocTIDEDCHKT);

   virtual TFIBBCDField * get_DocTKOLCHKT(void);
   virtual void set_DocTKOLCHKT(TFIBBCDField * DocTKOLCHKT);

   virtual TFIBBCDField * get_DocTKFCHKT(void);
   virtual void set_DocTKFCHKT(TFIBBCDField * DocTKFCHKT);

   virtual TFIBBCDField * get_DocTPRICECHKT(void);
   virtual void set_DocTPRICECHKT(TFIBBCDField * DocTPRICECHKT);

   virtual TFIBBCDField * get_DocTSUMCHKT(void);
   virtual void set_DocTSUMCHKT(TFIBBCDField * DocTSUMCHKT);

   virtual TFIBBCDField * get_DocTSKCHKT(void);
   virtual void set_DocTSKCHKT(TFIBBCDField * DocTSKCHKT);

   virtual TFIBBCDField * get_DocTNADCHKT(void);
   virtual void set_DocTNADCHKT(TFIBBCDField * DocTNADCHKT);

   virtual TFIBBCDField * get_DocTPRSKCHKT(void);
   virtual void set_DocTPRSKCHKT(TFIBBCDField * DocTPRSKCHKT);

   virtual TFIBBCDField * get_DocTPRNADCHKT(void);
   virtual void set_DocTPRNADCHKT(TFIBBCDField * DocTPRNADCHKT);

   virtual TFIBWideStringField * get_DocTGID_DCHKT(void);
   virtual void set_DocTGID_DCHKT(TFIBWideStringField * DocTGID_DCHKT);

   virtual TFIBLargeIntField * get_DocTIDBASE_DCHKT(void);
   virtual void set_DocTIDBASE_DCHKT(TFIBLargeIntField * DocTIDBASE_DCHKT);

   virtual TFIBBCDField * get_DocTPRSK_CARD_DCHKT(void);
   virtual void set_DocTPRSK_CARD_DCHKT(TFIBBCDField * DocTPRSK_CARD_DCHKT);

   virtual TFIBBCDField * get_DocTPRSK_AUTO_DCHKT(void);
   virtual void set_DocTPRSK_AUTO_DCHKT(TFIBBCDField * DocTPRSK_AUTO_DCHKT);

   virtual TFIBIntegerField * get_DocTNDS_DCHKT(void);
   virtual void set_DocTNDS_DCHKT(TFIBIntegerField * DocTNDS_DCHKT);

   virtual TFIBBCDField * get_DocTSUMNDS_DCHKT(void);
   virtual void set_DocTSUMNDS_DCHKT(TFIBBCDField * DocTSUMNDS_DCHKT);

   virtual TFIBWideStringField * get_DocTKRNAMENOM(void);
   virtual void set_DocTKRNAMENOM(TFIBWideStringField * DocTKRNAMENOM);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBSmallIntField * get_DocTTNOM(void);
   virtual void set_DocTTNOM(TFIBSmallIntField * DocTTNOM);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TFIBLargeIntField * get_DocOplID_DCHK_OPL(void);
   virtual void set_DocOplID_DCHK_OPL(TFIBLargeIntField * DocOplID_DCHK_OPL);

   virtual TFIBLargeIntField * get_DocOplIDBASE_DCHK_OPL(void);
   virtual void set_DocOplIDBASE_DCHK_OPL(TFIBLargeIntField * DocOplIDBASE_DCHK_OPL);

   virtual TFIBLargeIntField * get_DocOplIDCARD_DCHK_OPL(void);
   virtual void set_DocOplIDCARD_DCHK_OPL(TFIBLargeIntField * DocOplIDCARD_DCHK_OPL);

   virtual TFIBBCDField * get_DocOplSUMPLAT_DCHK_OPL(void);
   virtual void set_DocOplSUMPLAT_DCHK_OPL(TFIBBCDField * DocOplSUMPLAT_DCHK_OPL);

   virtual TFIBBCDField * get_DocOplSUMCREDIT_DCHK_OPL(void);
   virtual void set_DocOplSUMCREDIT_DCHK_OPL(TFIBBCDField * DocOplSUMCREDIT_DCHK_OPL);

   virtual TFIBLargeIntField * get_DocOplIDDOC_DCHK_OPL(void);
   virtual void set_DocOplIDDOC_DCHK_OPL(TFIBLargeIntField * DocOplIDDOC_DCHK_OPL);

   virtual TFIBWideStringField * get_DocOplNAME_SDISCOUNT_CARD(void);
   virtual void set_DocOplNAME_SDISCOUNT_CARD(TFIBWideStringField * DocOplNAME_SDISCOUNT_CARD);

   virtual TFloatField * get_DocALLOPL(void);
   virtual void set_DocALLOPL(TFloatField * DocALLOPL);

   virtual TFIBWideStringField * get_SpisokTypePriceNAME_TPRICE(void);
   virtual void set_SpisokTypePriceNAME_TPRICE(TFIBWideStringField * SpisokTypePriceNAME_TPRICE);

   virtual TFIBWideStringField * get_SpisokTypePriceGID_STPRICE(void);
   virtual void set_SpisokTypePriceGID_STPRICE(TFIBWideStringField * SpisokTypePriceGID_STPRICE);

   virtual TFIBIntegerField * get_DocTCODENOM(void);
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM);

   virtual TFIBWideStringField * get_DocTARTNOM(void);
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM);

   virtual TFIBWideStringField * get_DocTSHED(void);
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED);

   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_GALLDOC(void);
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC);

   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void);
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER);

   virtual TFIBBCDField * get_DocOPL_OTHER_DCHK(void);
   virtual void set_DocOPL_OTHER_DCHK(TFIBBCDField * DocOPL_OTHER_DCHK);

   virtual TFIBBCDField * get_DocTPRSK_HAND_DCHKT(void);
   virtual void set_DocTPRSK_HAND_DCHKT(TFIBBCDField * DocTPRSK_HAND_DCHKT);

   virtual TFIBSmallIntField * get_DocTNO_SK_DCHKT(void);
   virtual void set_DocTNO_SK_DCHKT(TFIBSmallIntField * DocTNO_SK_DCHKT);

   virtual TFIBLargeIntField * get_DocTIDGRPNOM(void);
   virtual void set_DocTIDGRPNOM(TFIBLargeIntField * DocTIDGRPNOM);

   virtual TFIBLargeIntField * get_DocTIDVID_SNOM(void);
   virtual void set_DocTIDVID_SNOM(TFIBLargeIntField * DocTIDVID_SNOM);

   virtual TFIBWideStringField * get_DocTNAMEGN(void);
   virtual void set_DocTNAMEGN(TFIBWideStringField * DocTNAMEGN);

   virtual TFIBWideStringField * get_DocTNAME_SVIDNOM(void);
   virtual void set_DocTNAME_SVIDNOM(TFIBWideStringField * DocTNAME_SVIDNOM);

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC);








   virtual TFIBLargeIntField * get_DocTIDTNOM_DCHKT(void);
   virtual void set_DocTIDTNOM_DCHKT(TFIBLargeIntField * DocTIDTNOM_DCHKT);


   virtual TFIBLargeIntField * get_DocTIDDEPARTMENT_DCHKT(void);
   virtual void set_DocTIDDEPARTMENT_DCHKT(TFIBLargeIntField * DocTIDDEPARTMENT_DCHKT);


   virtual TFIBIntegerField * get_DocTNUMOTDKKT_SDEPARTMENT(void);
   virtual void set_DocTNUMOTDKKT_SDEPARTMENT(TFIBIntegerField * DocTNUMOTDKKT_SDEPARTMENT);


   virtual TFIBWideStringField * get_DocTNAME_SDEPARTMENT(void);
   virtual void set_DocTNAME_SDEPARTMENT(TFIBWideStringField * DocTNAME_SDEPARTMENT);


   virtual TFIBWideStringField * get_DocTNAME_STNOM(void);
   virtual void set_DocTNAME_STNOM(TFIBWideStringField * DocTNAME_STNOM);


   virtual TFIBWideStringField * get_DocFISCALSIGN_DCHK(void);
   virtual void set_DocFISCALSIGN_DCHK(TFIBWideStringField * DocFISCALSIGN_DCHK);


   virtual TFIBWideStringField * get_DocPHONE_DCHK(void);
   virtual void set_DocPHONE_DCHK(TFIBWideStringField * DocPHONE_DCHK);


   virtual TFIBWideStringField * get_DocEMAIL_DCHK(void);
   virtual void set_DocEMAIL_DCHK(TFIBWideStringField * DocEMAIL_DCHK);














   virtual bool get_NewElement(void);
   virtual void set_NewElement(bool NewElement);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual UnicodeString get_ProsmotrText(void);
   virtual void set_ProsmotrText(UnicodeString ProsmotrText);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdElementaMaster(void);
   virtual void set_IdElementaMaster(__int64 IdElementaMaster);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual int get_Operation(void);
   virtual void set_Operation(int Operation);

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
   virtual bool OpenDoc(__int64 IdDoc);
   virtual void OpenDocOsn(void);
   virtual bool SaveDoc(void);
   virtual bool BeforeSaveDoc(void);
   virtual bool AfterSaveDoc(void);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual void AddDocNewString(void);
   virtual void DeleteStringDoc(void);
   virtual void CloseDoc(void);
   virtual void ValidateProsmotr(void);
   virtual void AdddRecordInGurOperDiscountCard(void);
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TDMDocCheckImpl __uuidof(TDMDocCheckImpl)
#endif
