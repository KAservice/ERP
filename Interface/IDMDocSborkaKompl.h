#ifndef UIDMDocSborkaKomplH
#define UIDMDocSborkaKomplH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMDocSborkaKompl)) IDMDocSborkaKompl : public IMainInterface
{
public:
   __property TDataSource * DataSourceDoc = {read = get_DataSourceDoc , write = set_DataSourceDoc};
   virtual TDataSource * get_DataSourceDoc(void)=0;
   virtual void set_DataSourceDoc(TDataSource * DataSourceDoc)=0;

   __property TDataSource * DataSourceDocT = {read = get_DataSourceDocT , write = set_DataSourceDocT};
   virtual TDataSource * get_DataSourceDocT(void)=0;
   virtual void set_DataSourceDocT(TDataSource * DataSourceDocT)=0;

   __property TDataSource * DataSourceDocAll = {read = get_DataSourceDocAll , write = set_DataSourceDocAll};
   virtual TDataSource * get_DataSourceDocAll(void)=0;
   virtual void set_DataSourceDocAll(TDataSource * DataSourceDocAll)=0;

   __property TpFIBDataSet * DocAll = {read = get_DocAll , write = set_DocAll};
   virtual TpFIBDataSet * get_DocAll(void)=0;
   virtual void set_DocAll(TpFIBDataSet * DocAll)=0;

   __property TpFIBDataSet * Doc = {read = get_Doc , write = set_Doc};
   virtual TpFIBDataSet * get_Doc(void)=0;
   virtual void set_Doc(TpFIBDataSet * Doc)=0;

   __property TpFIBDataSet * DocT = {read = get_DocT , write = set_DocT};
   virtual TpFIBDataSet * get_DocT(void)=0;
   virtual void set_DocT(TpFIBDataSet * DocT)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TpFIBTransaction * IBTrDvReg = {read = get_IBTrDvReg , write = set_IBTrDvReg};
   virtual TpFIBTransaction * get_IBTrDvReg(void)=0;
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)=0;

   __property TpFIBDataSet * NumDoc = {read = get_NumDoc , write = set_NumDoc};
   virtual TpFIBDataSet * get_NumDoc(void)=0;
   virtual void set_NumDoc(TpFIBDataSet * NumDoc)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TpFIBQuery * QueryCancelDvReg = {read = get_QueryCancelDvReg , write = set_QueryCancelDvReg};
   virtual TpFIBQuery * get_QueryCancelDvReg(void)=0;
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)=0;

   __property TpFIBQuery * QueryDvReg = {read = get_QueryDvReg , write = set_QueryDvReg};
   virtual TpFIBQuery * get_QueryDvReg(void)=0;
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg)=0;

   __property TFIBBCDField * DocAllIDDOC = {read = get_DocAllIDDOC , write = set_DocAllIDDOC};
   virtual TFIBBCDField * get_DocAllIDDOC(void)=0;
   virtual void set_DocAllIDDOC(TFIBBCDField * DocAllIDDOC)=0;

   __property TFIBDateTimeField * DocAllPOSDOC = {read = get_DocAllPOSDOC , write = set_DocAllPOSDOC};
   virtual TFIBDateTimeField * get_DocAllPOSDOC(void)=0;
   virtual void set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)=0;

   __property TFIBSmallIntField * DocAllPRDOC = {read = get_DocAllPRDOC , write = set_DocAllPRDOC};
   virtual TFIBSmallIntField * get_DocAllPRDOC(void)=0;
   virtual void set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)=0;

   __property TFIBIntegerField * DocAllNUMDOC = {read = get_DocAllNUMDOC , write = set_DocAllNUMDOC};
   virtual TFIBIntegerField * get_DocAllNUMDOC(void)=0;
   virtual void set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)=0;

   __property TFIBBCDField * DocAllIDFIRMDOC = {read = get_DocAllIDFIRMDOC , write = set_DocAllIDFIRMDOC};
   virtual TFIBBCDField * get_DocAllIDFIRMDOC(void)=0;
   virtual void set_DocAllIDFIRMDOC(TFIBBCDField * DocAllIDFIRMDOC)=0;

   __property TFIBBCDField * DocAllIDSKLDOC = {read = get_DocAllIDSKLDOC , write = set_DocAllIDSKLDOC};
   virtual TFIBBCDField * get_DocAllIDSKLDOC(void)=0;
   virtual void set_DocAllIDSKLDOC(TFIBBCDField * DocAllIDSKLDOC)=0;

   __property TFIBBCDField * DocAllIDKLDOC = {read = get_DocAllIDKLDOC , write = set_DocAllIDKLDOC};
   virtual TFIBBCDField * get_DocAllIDKLDOC(void)=0;
   virtual void set_DocAllIDKLDOC(TFIBBCDField * DocAllIDKLDOC)=0;

   __property TFIBBCDField * DocAllIDDOGDOC = {read = get_DocAllIDDOGDOC , write = set_DocAllIDDOGDOC};
   virtual TFIBBCDField * get_DocAllIDDOGDOC(void)=0;
   virtual void set_DocAllIDDOGDOC(TFIBBCDField * DocAllIDDOGDOC)=0;

   __property TFIBBCDField * DocAllSUMDOC = {read = get_DocAllSUMDOC , write = set_DocAllSUMDOC};
   virtual TFIBBCDField * get_DocAllSUMDOC(void)=0;
   virtual void set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)=0;

   __property TFIBBCDField * DocAllIDUSERDOC = {read = get_DocAllIDUSERDOC , write = set_DocAllIDUSERDOC};
   virtual TFIBBCDField * get_DocAllIDUSERDOC(void)=0;
   virtual void set_DocAllIDUSERDOC(TFIBBCDField * DocAllIDUSERDOC)=0;

   __property TFIBBCDField * DocAllIDDOCOSNDOC = {read = get_DocAllIDDOCOSNDOC , write = set_DocAllIDDOCOSNDOC};
   virtual TFIBBCDField * get_DocAllIDDOCOSNDOC(void)=0;
   virtual void set_DocAllIDDOCOSNDOC(TFIBBCDField * DocAllIDDOCOSNDOC)=0;

   __property TFIBBCDField * DocAllIDEXTDOC = {read = get_DocAllIDEXTDOC , write = set_DocAllIDEXTDOC};
   virtual TFIBBCDField * get_DocAllIDEXTDOC(void)=0;
   virtual void set_DocAllIDEXTDOC(TFIBBCDField * DocAllIDEXTDOC)=0;

   __property TFIBBCDField * DocAllIDBASE_GALLDOC = {read = get_DocAllIDBASE_GALLDOC , write = set_DocAllIDBASE_GALLDOC};
   virtual TFIBBCDField * get_DocAllIDBASE_GALLDOC(void)=0;
   virtual void set_DocAllIDBASE_GALLDOC(TFIBBCDField * DocAllIDBASE_GALLDOC)=0;

   __property TFIBBCDField * DocID_DSBKOMPL = {read = get_DocID_DSBKOMPL , write = set_DocID_DSBKOMPL};
   virtual TFIBBCDField * get_DocID_DSBKOMPL(void)=0;
   virtual void set_DocID_DSBKOMPL(TFIBBCDField * DocID_DSBKOMPL)=0;

   __property TFIBBCDField * DocIDBASE_DSBKOMPL = {read = get_DocIDBASE_DSBKOMPL , write = set_DocIDBASE_DSBKOMPL};
   virtual TFIBBCDField * get_DocIDBASE_DSBKOMPL(void)=0;
   virtual void set_DocIDBASE_DSBKOMPL(TFIBBCDField * DocIDBASE_DSBKOMPL)=0;

   __property TFIBBCDField * DocIDDOC_DSBKOMPL = {read = get_DocIDDOC_DSBKOMPL , write = set_DocIDDOC_DSBKOMPL};
   virtual TFIBBCDField * get_DocIDDOC_DSBKOMPL(void)=0;
   virtual void set_DocIDDOC_DSBKOMPL(TFIBBCDField * DocIDDOC_DSBKOMPL)=0;

   __property TFIBBCDField * DocIDNOM_DSBKOMPL = {read = get_DocIDNOM_DSBKOMPL , write = set_DocIDNOM_DSBKOMPL};
   virtual TFIBBCDField * get_DocIDNOM_DSBKOMPL(void)=0;
   virtual void set_DocIDNOM_DSBKOMPL(TFIBBCDField * DocIDNOM_DSBKOMPL)=0;

   __property TFIBBCDField * DocIDED_DSBKOMPL = {read = get_DocIDED_DSBKOMPL , write = set_DocIDED_DSBKOMPL};
   virtual TFIBBCDField * get_DocIDED_DSBKOMPL(void)=0;
   virtual void set_DocIDED_DSBKOMPL(TFIBBCDField * DocIDED_DSBKOMPL)=0;

   __property TFIBBCDField * DocKF_DSBKOMPL = {read = get_DocKF_DSBKOMPL , write = set_DocKF_DSBKOMPL};
   virtual TFIBBCDField * get_DocKF_DSBKOMPL(void)=0;
   virtual void set_DocKF_DSBKOMPL(TFIBBCDField * DocKF_DSBKOMPL)=0;

   __property TFIBBCDField * DocKOL_DSBKOMPL = {read = get_DocKOL_DSBKOMPL , write = set_DocKOL_DSBKOMPL};
   virtual TFIBBCDField * get_DocKOL_DSBKOMPL(void)=0;
   virtual void set_DocKOL_DSBKOMPL(TFIBBCDField * DocKOL_DSBKOMPL)=0;

   __property TFIBBCDField * DocRPRICE_DSBKOMPL = {read = get_DocRPRICE_DSBKOMPL , write = set_DocRPRICE_DSBKOMPL};
   virtual TFIBBCDField * get_DocRPRICE_DSBKOMPL(void)=0;
   virtual void set_DocRPRICE_DSBKOMPL(TFIBBCDField * DocRPRICE_DSBKOMPL)=0;

   __property TFIBBCDField * DocTID_DSBKOMPLT = {read = get_DocTID_DSBKOMPLT , write = set_DocTID_DSBKOMPLT};
   virtual TFIBBCDField * get_DocTID_DSBKOMPLT(void)=0;
   virtual void set_DocTID_DSBKOMPLT(TFIBBCDField * DocTID_DSBKOMPLT)=0;

   __property TFIBBCDField * DocTIDBASE_DSBKOMPLT = {read = get_DocTIDBASE_DSBKOMPLT , write = set_DocTIDBASE_DSBKOMPLT};
   virtual TFIBBCDField * get_DocTIDBASE_DSBKOMPLT(void)=0;
   virtual void set_DocTIDBASE_DSBKOMPLT(TFIBBCDField * DocTIDBASE_DSBKOMPLT)=0;

   __property TFIBBCDField * DocTIDDOC_DSBKOMPLT = {read = get_DocTIDDOC_DSBKOMPLT , write = set_DocTIDDOC_DSBKOMPLT};
   virtual TFIBBCDField * get_DocTIDDOC_DSBKOMPLT(void)=0;
   virtual void set_DocTIDDOC_DSBKOMPLT(TFIBBCDField * DocTIDDOC_DSBKOMPLT)=0;

   __property TFIBBCDField * DocTIDNOM_DSBKOMPLT = {read = get_DocTIDNOM_DSBKOMPLT , write = set_DocTIDNOM_DSBKOMPLT};
   virtual TFIBBCDField * get_DocTIDNOM_DSBKOMPLT(void)=0;
   virtual void set_DocTIDNOM_DSBKOMPLT(TFIBBCDField * DocTIDNOM_DSBKOMPLT)=0;

   __property TFIBBCDField * DocTIDED_DSBKOMPLT = {read = get_DocTIDED_DSBKOMPLT , write = set_DocTIDED_DSBKOMPLT};
   virtual TFIBBCDField * get_DocTIDED_DSBKOMPLT(void)=0;
   virtual void set_DocTIDED_DSBKOMPLT(TFIBBCDField * DocTIDED_DSBKOMPLT)=0;

   __property TFIBBCDField * DocTKF_DSBKOMPLT = {read = get_DocTKF_DSBKOMPLT , write = set_DocTKF_DSBKOMPLT};
   virtual TFIBBCDField * get_DocTKF_DSBKOMPLT(void)=0;
   virtual void set_DocTKF_DSBKOMPLT(TFIBBCDField * DocTKF_DSBKOMPLT)=0;

   __property TFIBBCDField * DocTKOL_DSBKOMPLT = {read = get_DocTKOL_DSBKOMPLT , write = set_DocTKOL_DSBKOMPLT};
   virtual TFIBBCDField * get_DocTKOL_DSBKOMPLT(void)=0;
   virtual void set_DocTKOL_DSBKOMPLT(TFIBBCDField * DocTKOL_DSBKOMPLT)=0;

   __property TFIBBCDField * DocTRPRICE_DSBKOMPLT = {read = get_DocTRPRICE_DSBKOMPLT , write = set_DocTRPRICE_DSBKOMPLT};
   virtual TFIBBCDField * get_DocTRPRICE_DSBKOMPLT(void)=0;
   virtual void set_DocTRPRICE_DSBKOMPLT(TFIBBCDField * DocTRPRICE_DSBKOMPLT)=0;

   __property TFIBBCDField * DocTRSUM_DSBKOMPLT = {read = get_DocTRSUM_DSBKOMPLT , write = set_DocTRSUM_DSBKOMPLT};
   virtual TFIBBCDField * get_DocTRSUM_DSBKOMPLT(void)=0;
   virtual void set_DocTRSUM_DSBKOMPLT(TFIBBCDField * DocTRSUM_DSBKOMPLT)=0;

   __property TFIBBCDField * DocIDRTPRICE_DSBKOMPL = {read = get_DocIDRTPRICE_DSBKOMPL , write = set_DocIDRTPRICE_DSBKOMPL};
   virtual TFIBBCDField * get_DocIDRTPRICE_DSBKOMPL(void)=0;
   virtual void set_DocIDRTPRICE_DSBKOMPL(TFIBBCDField * DocIDRTPRICE_DSBKOMPL)=0;

   __property TFIBBCDField * DocIDPART_DSBKOMPL = {read = get_DocIDPART_DSBKOMPL , write = set_DocIDPART_DSBKOMPL};
   virtual TFIBBCDField * get_DocIDPART_DSBKOMPL(void)=0;
   virtual void set_DocIDPART_DSBKOMPL(TFIBBCDField * DocIDPART_DSBKOMPL)=0;

   __property TIntegerField * DocTRECNO = {read = get_DocTRECNO , write = set_DocTRECNO};
   virtual TIntegerField * get_DocTRECNO(void)=0;
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO)=0;

   __property TFIBWideStringField * DocAllGID_DOC = {read = get_DocAllGID_DOC , write = set_DocAllGID_DOC};
   virtual TFIBWideStringField * get_DocAllGID_DOC(void)=0;
   virtual void set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)=0;

   __property TFIBIntegerField * DocAllTYPEEXTDOC = {read = get_DocAllTYPEEXTDOC , write = set_DocAllTYPEEXTDOC};
   virtual TFIBIntegerField * get_DocAllTYPEEXTDOC(void)=0;
   virtual void set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)=0;

   __property TFIBWideStringField * DocAllFNAME_USER = {read = get_DocAllFNAME_USER , write = set_DocAllFNAME_USER};
   virtual TFIBWideStringField * get_DocAllFNAME_USER(void)=0;
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)=0;

   __property TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN = {read = get_DocAllNAME_SINFBASE_OBMEN , write = set_DocAllNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * DocAllNAMEFIRM = {read = get_DocAllNAMEFIRM , write = set_DocAllNAMEFIRM};
   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void)=0;
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)=0;

   __property TFIBWideStringField * DocAllNAMESKLAD = {read = get_DocAllNAMESKLAD , write = set_DocAllNAMESKLAD};
   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void)=0;
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)=0;

   __property TFIBWideStringField * DocDESCR_DSBKOMPL = {read = get_DocDESCR_DSBKOMPL , write = set_DocDESCR_DSBKOMPL};
   virtual TFIBWideStringField * get_DocDESCR_DSBKOMPL(void)=0;
   virtual void set_DocDESCR_DSBKOMPL(TFIBWideStringField * DocDESCR_DSBKOMPL)=0;

   __property TFIBWideStringField * DocNAMENOM = {read = get_DocNAMENOM , write = set_DocNAMENOM};
   virtual TFIBWideStringField * get_DocNAMENOM(void)=0;
   virtual void set_DocNAMENOM(TFIBWideStringField * DocNAMENOM)=0;

   __property TFIBWideStringField * DocNAMEED = {read = get_DocNAMEED , write = set_DocNAMEED};
   virtual TFIBWideStringField * get_DocNAMEED(void)=0;
   virtual void set_DocNAMEED(TFIBWideStringField * DocNAMEED)=0;

   __property TFIBWideStringField * DocTNAMENOM = {read = get_DocTNAMENOM , write = set_DocTNAMENOM};
   virtual TFIBWideStringField * get_DocTNAMENOM(void)=0;
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)=0;

   __property TFIBWideStringField * DocTNAMEED = {read = get_DocTNAMEED , write = set_DocTNAMEED};
   virtual TFIBWideStringField * get_DocTNAMEED(void)=0;
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)=0;

   __property TFIBWideStringField * DocAllTDOC = {read = get_DocAllTDOC , write = set_DocAllTDOC};
   virtual TFIBWideStringField * get_DocAllTDOC(void)=0;
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)=0;

   __property TFIBBCDField * DocAllIDPROJECT_GALLDOC = {read = get_DocAllIDPROJECT_GALLDOC , write = set_DocAllIDPROJECT_GALLDOC};
   virtual TFIBBCDField * get_DocAllIDPROJECT_GALLDOC(void)=0;
   virtual void set_DocAllIDPROJECT_GALLDOC(TFIBBCDField * DocAllIDPROJECT_GALLDOC)=0;

   __property TFIBBCDField * DocAllIDBUSINOP_GALLDOC = {read = get_DocAllIDBUSINOP_GALLDOC , write = set_DocAllIDBUSINOP_GALLDOC};
   virtual TFIBBCDField * get_DocAllIDBUSINOP_GALLDOC(void)=0;
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBBCDField * DocAllIDBUSINOP_GALLDOC)=0;

   __property TFIBWideStringField * DocAllNAME_SPROJECT = {read = get_DocAllNAME_SPROJECT , write = set_DocAllNAME_SPROJECT};
   virtual TFIBWideStringField * get_DocAllNAME_SPROJECT(void)=0;
   virtual void set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)=0;

   __property TFIBWideStringField * DocAllNAME_SBUSINESS_OPER = {read = get_DocAllNAME_SBUSINESS_OPER , write = set_DocAllNAME_SBUSINESS_OPER};
   virtual TFIBWideStringField * get_DocAllNAME_SBUSINESS_OPER(void)=0;
   virtual void set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)=0;

   __property TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC = {read = get_DocAllPREFIKS_NUM_GALLDOC , write = set_DocAllPREFIKS_NUM_GALLDOC};
   virtual TFIBWideStringField * get_DocAllPREFIKS_NUM_GALLDOC(void)=0;
   virtual void set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)=0;

   __property TFIBWideStringField * DocTARTNOM = {read = get_DocTARTNOM , write = set_DocTARTNOM};
   virtual TFIBWideStringField * get_DocTARTNOM(void)=0;
   virtual void set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)=0;

   __property TFIBIntegerField * DocTCODENOM = {read = get_DocTCODENOM , write = set_DocTCODENOM};
   virtual TFIBIntegerField * get_DocTCODENOM(void)=0;
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)=0;

   __property TFIBWideStringField * DocTSHED = {read = get_DocTSHED , write = set_DocTSHED};
   virtual TFIBWideStringField * get_DocTSHED(void)=0;
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property bool SkladRozn = {read = get_SkladRozn , write = set_SkladRozn};
   virtual bool get_SkladRozn(void)=0;
   virtual void set_SkladRozn(bool SkladRozn)=0;

   __property bool EnableDvReg = {read = get_EnableDvReg , write = set_EnableDvReg};
   virtual bool get_EnableDvReg(void)=0;
   virtual void set_EnableDvReg(bool EnableDvReg)=0;

   virtual bool NewDoc(void)=0;
   virtual bool OpenDoc(__int64 IdDoc)=0;
   virtual bool SaveDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual bool DvRegDoc(void)=0;
   virtual bool CancelDvRegDoc(void)=0;
   virtual void TableAppend(void)=0;
   virtual void TableDelete(void)=0;
   virtual __int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)=0;
   virtual int GetNumberNewDoc(void)=0;
};
#define IID_IDMDocSborkaKompl __uuidof(IDMDocSborkaKompl)
#endif
