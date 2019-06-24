#ifndef UDMDocOstNomImplH
#define UDMDocOstNomImplH
#include "IDMDocOstNom.h"
#include "UDMDocOstNom.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDocOstNomImpl)) TDMDocOstNomImpl : public IDMDocOstNom
{
public:
   TDMDocOstNomImpl();
   ~TDMDocOstNomImpl();
   TDMDocOstNom * Object;
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

//IDMDocOstNom
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

   virtual TpFIBTransaction * get_IBTrDvReg(void);
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_DocT(void);
   virtual void set_DocT(TpFIBDataSet * DocT);

   virtual TFIBBCDField * get_DocTKOLOSNT(void);
   virtual void set_DocTKOLOSNT(TFIBBCDField * DocTKOLOSNT);

   virtual TFIBBCDField * get_DocTKFOSNT(void);
   virtual void set_DocTKFOSNT(TFIBBCDField * DocTKFOSNT);

   virtual TFIBBCDField * get_DocTPRICEOSNT(void);
   virtual void set_DocTPRICEOSNT(TFIBBCDField * DocTPRICEOSNT);

   virtual TFIBBCDField * get_DocTSUMOSNT(void);
   virtual void set_DocTSUMOSNT(TFIBBCDField * DocTSUMOSNT);

   virtual TFIBIntegerField * get_DocTTNOM(void);
   virtual void set_DocTTNOM(TFIBIntegerField * DocTTNOM);

   virtual TIntegerField * get_DocTRECNO(void);
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO);

   virtual TpFIBDataSet * get_NumDoc(void);
   virtual void set_NumDoc(TpFIBDataSet * NumDoc);

   virtual TpFIBDataSet * get_Grp(void);
   virtual void set_Grp(TpFIBDataSet * Grp);

   virtual TpFIBDataSet * get_El(void);
   virtual void set_El(TpFIBDataSet * El);

   virtual TpFIBDataSet * get_IBQ(void);
   virtual void set_IBQ(TpFIBDataSet * IBQ);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TpFIBDataSet * get_DocOsn(void);
   virtual void set_DocOsn(TpFIBDataSet * DocOsn);

   virtual TFIBIntegerField * get_DocOsnNUMDOC(void);
   virtual void set_DocOsnNUMDOC(TFIBIntegerField * DocOsnNUMDOC);

   virtual TFIBDateTimeField * get_DocOsnPOSDOC(void);
   virtual void set_DocOsnPOSDOC(TFIBDateTimeField * DocOsnPOSDOC);

   virtual TFIBBCDField * get_DocRSUM_DOSN(void);
   virtual void set_DocRSUM_DOSN(TFIBBCDField * DocRSUM_DOSN);

   virtual TFIBBCDField * get_DocTRPRICE_DOSNT(void);
   virtual void set_DocTRPRICE_DOSNT(TFIBBCDField * DocTRPRICE_DOSNT);

   virtual TFIBBCDField * get_DocTRSUM_DOSNT(void);
   virtual void set_DocTRSUM_DOSNT(TFIBBCDField * DocTRSUM_DOSNT);

   virtual TFIBBCDField * get_DocTNAC_DOSNT(void);
   virtual void set_DocTNAC_DOSNT(TFIBBCDField * DocTNAC_DOSNT);

   virtual TpFIBQuery * get_QueryCancelDvReg(void);
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg);

   virtual TpFIBQuery * get_QueryDvReg(void);
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg);

   virtual TFIBIntegerField * get_DocTNDS_DOSNT(void);
   virtual void set_DocTNDS_DOSNT(TFIBIntegerField * DocTNDS_DOSNT);

   virtual TFIBBCDField * get_DocTSUMNDS_DOSNT(void);
   virtual void set_DocTSUMNDS_DOSNT(TFIBBCDField * DocTSUMNDS_DOSNT);

   virtual TFIBDateTimeField * get_DocTSRGODNPART(void);
   virtual void set_DocTSRGODNPART(TFIBDateTimeField * DocTSRGODNPART);

   virtual TFIBWideStringField * get_DocOsnTDOC(void);
   virtual void set_DocOsnTDOC(TFIBWideStringField * DocOsnTDOC);

   virtual TFIBWideStringField * get_GrpNAMEGN(void);
   virtual void set_GrpNAMEGN(TFIBWideStringField * GrpNAMEGN);

   virtual TFIBLargeIntField * get_GrpIDGN(void);
   virtual void set_GrpIDGN(TFIBLargeIntField * GrpIDGN);

   virtual TFIBBCDField * get_GrpSUMMA(void);
   virtual void set_GrpSUMMA(TFIBBCDField * GrpSUMMA);

   virtual TFIBWideStringField * get_ElNAMENOM(void);
   virtual void set_ElNAMENOM(TFIBWideStringField * ElNAMENOM);

   virtual TFIBWideStringField * get_ElNAMEED(void);
   virtual void set_ElNAMEED(TFIBWideStringField * ElNAMEED);

   virtual TFIBBCDField * get_ElSUMMA(void);
   virtual void set_ElSUMMA(TFIBBCDField * ElSUMMA);

   virtual TFIBFloatField * get_ElSUMKOL(void);
   virtual void set_ElSUMKOL(TFIBFloatField * ElSUMKOL);

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

   virtual TFIBWideStringField * get_DocAllFNAME_USER(void);
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER);

   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void);
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void);
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM);

   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void);
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD);

   virtual TFIBLargeIntField * get_DocIDOSN(void);
   virtual void set_DocIDOSN(TFIBLargeIntField * DocIDOSN);

   virtual TFIBLargeIntField * get_DocIDDOCOSN(void);
   virtual void set_DocIDDOCOSN(TFIBLargeIntField * DocIDDOCOSN);

   virtual TFIBWideStringField * get_DocPRIMOSN(void);
   virtual void set_DocPRIMOSN(TFIBWideStringField * DocPRIMOSN);

   virtual TFIBLargeIntField * get_DocIDTPRICEOSN(void);
   virtual void set_DocIDTPRICEOSN(TFIBLargeIntField * DocIDTPRICEOSN);

   virtual TFIBWideStringField * get_DocGID_DOSN(void);
   virtual void set_DocGID_DOSN(TFIBWideStringField * DocGID_DOSN);

   virtual TFIBLargeIntField * get_DocIDRTPRICE_DOSN(void);
   virtual void set_DocIDRTPRICE_DOSN(TFIBLargeIntField * DocIDRTPRICE_DOSN);

   virtual TFIBLargeIntField * get_DocIDBASE_DOSN(void);
   virtual void set_DocIDBASE_DOSN(TFIBLargeIntField * DocIDBASE_DOSN);

   virtual TFIBIntegerField * get_DocOPER_DOSN(void);
   virtual void set_DocOPER_DOSN(TFIBIntegerField * DocOPER_DOSN);

   virtual TFIBWideStringField * get_DocNAME_TPRICE(void);
   virtual void set_DocNAME_TPRICE(TFIBWideStringField * DocNAME_TPRICE);

   virtual TFIBLargeIntField * get_DocTIDOSNT(void);
   virtual void set_DocTIDOSNT(TFIBLargeIntField * DocTIDOSNT);

   virtual TFIBLargeIntField * get_DocTIDDOCOSNT(void);
   virtual void set_DocTIDDOCOSNT(TFIBLargeIntField * DocTIDDOCOSNT);

   virtual TFIBLargeIntField * get_DocTIDNOMOSNT(void);
   virtual void set_DocTIDNOMOSNT(TFIBLargeIntField * DocTIDNOMOSNT);

   virtual TFIBLargeIntField * get_DocTIDEDOSNT(void);
   virtual void set_DocTIDEDOSNT(TFIBLargeIntField * DocTIDEDOSNT);

   virtual TFIBLargeIntField * get_DocTIDPARTOSNT(void);
   virtual void set_DocTIDPARTOSNT(TFIBLargeIntField * DocTIDPARTOSNT);

   virtual TFIBWideStringField * get_DocTGID_DOSNT(void);
   virtual void set_DocTGID_DOSNT(TFIBWideStringField * DocTGID_DOSNT);

   virtual TFIBLargeIntField * get_DocTIDBASE_DOSNT(void);
   virtual void set_DocTIDBASE_DOSNT(TFIBLargeIntField * DocTIDBASE_DOSNT);

   virtual TFIBWideStringField * get_DocTNAMENOM(void);
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM);

   virtual TFIBWideStringField * get_DocTNAMEED(void);
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED);

   virtual TFIBWideStringField * get_DocTGTDPART(void);
   virtual void set_DocTGTDPART(TFIBWideStringField * DocTGTDPART);

   virtual TFIBWideStringField * get_DocTSERTPART(void);
   virtual void set_DocTSERTPART(TFIBWideStringField * DocTSERTPART);

   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_GALLDOC(void);
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC);

   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void);
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT);

   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void);
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER);

   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void);
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC);

   virtual TFIBWideStringField * get_DocTARTNOM(void);
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM);

   virtual TFIBIntegerField * get_DocTCODENOM(void);
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM);

   virtual TFIBWideStringField * get_DocTSHED(void);
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED);

   virtual TpFIBDataSet * get_TypeNom(void);
   virtual void set_TypeNom(TpFIBDataSet * TypeNom);

   virtual TFIBLargeIntField * get_TypeNomID_STNOM(void);
   virtual void set_TypeNomID_STNOM(TFIBLargeIntField * TypeNomID_STNOM);

   virtual TFIBWideStringField * get_TypeNomNAME_STNOM(void);
   virtual void set_TypeNomNAME_STNOM(TFIBWideStringField * TypeNomNAME_STNOM);

   virtual TFIBLargeIntField * get_DocTIDTNOM_DOSNT(void);
   virtual void set_DocTIDTNOM_DOSNT(TFIBLargeIntField * DocTIDTNOM_DOSNT);

   virtual TStringField * get_DocTNAME_TYPE_NOM(void);
   virtual void set_DocTNAME_TYPE_NOM(TStringField * DocTNAME_TYPE_NOM);

   virtual TFIBLargeIntField * get_DocAllIDOBJECT_GALLDOC(void);
   virtual void set_DocAllIDOBJECT_GALLDOC(TFIBLargeIntField * DocAllIDOBJECT_GALLDOC);

   virtual TFIBWideStringField * get_DocAllNAME_SOBJECT(void);
   virtual void set_DocAllNAME_SOBJECT(TFIBWideStringField * DocAllNAME_SOBJECT);

   virtual bool get_NewElement(void);
   virtual void set_NewElement(bool NewElement);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdElementaMaster(void);
   virtual void set_IdElementaMaster(__int64 IdElementaMaster);

   virtual bool get_SkladRozn(void);
   virtual void set_SkladRozn(bool SkladRozn);

   virtual bool get_EnableDvReg(void);
   virtual void set_EnableDvReg(bool EnableDvReg);

   virtual void NewDoc(void);
   virtual void OpenDoc(__int64 id_doc);
   virtual bool SaveDoc(void);
   virtual void CloseDoc(void);
   virtual bool DvRegDoc(void);
   virtual bool CancelDvRegDoc(void);
   virtual void AddDocNewString(void);
   virtual void DeleteStringDoc(void);
   virtual bool DeleteDoc(__int64 id);
   virtual __int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc);
   virtual bool AddDataInv(void);
   virtual bool SearchStringPoNom(__int64 id_nom);
   virtual int GetNumberNewDoc(void);
};
#define CLSID_TDMDocOstNomImpl __uuidof(TDMDocOstNomImpl)
#endif
