#ifndef UIDMDocInvH
#define UIDMDocInvH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMDocInv)) IDMDocInv : public IMainInterface
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

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TpFIBDataSet * DocT = {read = get_DocT , write = set_DocT};
   virtual TpFIBDataSet * get_DocT(void)=0;
   virtual void set_DocT(TpFIBDataSet * DocT)=0;

   __property TpFIBTransaction * IBTrDvReg = {read = get_IBTrDvReg , write = set_IBTrDvReg};
   virtual TpFIBTransaction * get_IBTrDvReg(void)=0;
   virtual void set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)=0;

   __property TpFIBDataSet * NumDoc = {read = get_NumDoc , write = set_NumDoc};
   virtual TpFIBDataSet * get_NumDoc(void)=0;
   virtual void set_NumDoc(TpFIBDataSet * NumDoc)=0;

   __property TpFIBDataSet * IBQPoGrp = {read = get_IBQPoGrp , write = set_IBQPoGrp};
   virtual TpFIBDataSet * get_IBQPoGrp(void)=0;
   virtual void set_IBQPoGrp(TpFIBDataSet * IBQPoGrp)=0;

   __property TFIBIntegerField * IBQPoGrpTNOM = {read = get_IBQPoGrpTNOM , write = set_IBQPoGrpTNOM};
   virtual TFIBIntegerField * get_IBQPoGrpTNOM(void)=0;
   virtual void set_IBQPoGrpTNOM(TFIBIntegerField * IBQPoGrpTNOM)=0;

   __property TFIBIntegerField * IBQPoGrpCODENOM = {read = get_IBQPoGrpCODENOM , write = set_IBQPoGrpCODENOM};
   virtual TFIBIntegerField * get_IBQPoGrpCODENOM(void)=0;
   virtual void set_IBQPoGrpCODENOM(TFIBIntegerField * IBQPoGrpCODENOM)=0;

   __property TFIBBCDField * IBQPoGrpKF_INVT = {read = get_IBQPoGrpKF_INVT , write = set_IBQPoGrpKF_INVT};
   virtual TFIBBCDField * get_IBQPoGrpKF_INVT(void)=0;
   virtual void set_IBQPoGrpKF_INVT(TFIBBCDField * IBQPoGrpKF_INVT)=0;

   __property TFIBBCDField * IBQPoGrpKOLUCH_INVT = {read = get_IBQPoGrpKOLUCH_INVT , write = set_IBQPoGrpKOLUCH_INVT};
   virtual TFIBBCDField * get_IBQPoGrpKOLUCH_INVT(void)=0;
   virtual void set_IBQPoGrpKOLUCH_INVT(TFIBBCDField * IBQPoGrpKOLUCH_INVT)=0;

   __property TFIBBCDField * IBQPoGrpKOLFAKT_INVT = {read = get_IBQPoGrpKOLFAKT_INVT , write = set_IBQPoGrpKOLFAKT_INVT};
   virtual TFIBBCDField * get_IBQPoGrpKOLFAKT_INVT(void)=0;
   virtual void set_IBQPoGrpKOLFAKT_INVT(TFIBBCDField * IBQPoGrpKOLFAKT_INVT)=0;

   __property TFIBBCDField * IBQPoGrpPRICE_INVT = {read = get_IBQPoGrpPRICE_INVT , write = set_IBQPoGrpPRICE_INVT};
   virtual TFIBBCDField * get_IBQPoGrpPRICE_INVT(void)=0;
   virtual void set_IBQPoGrpPRICE_INVT(TFIBBCDField * IBQPoGrpPRICE_INVT)=0;

   __property TFIBBCDField * IBQPoGrpSUMF_INVT = {read = get_IBQPoGrpSUMF_INVT , write = set_IBQPoGrpSUMF_INVT};
   virtual TFIBBCDField * get_IBQPoGrpSUMF_INVT(void)=0;
   virtual void set_IBQPoGrpSUMF_INVT(TFIBBCDField * IBQPoGrpSUMF_INVT)=0;

   __property TpFIBDataSet * IBQ = {read = get_IBQ , write = set_IBQ};
   virtual TpFIBDataSet * get_IBQ(void)=0;
   virtual void set_IBQ(TpFIBDataSet * IBQ)=0;

   __property TpFIBDataSet * GoodsDataSet = {read = get_GoodsDataSet , write = set_GoodsDataSet};
   virtual TpFIBDataSet * get_GoodsDataSet(void)=0;
   virtual void set_GoodsDataSet(TpFIBDataSet * GoodsDataSet)=0;

   __property TFIBFloatField * GoodsDataSetSUMKOL = {read = get_GoodsDataSetSUMKOL , write = set_GoodsDataSetSUMKOL};
   virtual TFIBFloatField * get_GoodsDataSetSUMKOL(void)=0;
   virtual void set_GoodsDataSetSUMKOL(TFIBFloatField * GoodsDataSetSUMKOL)=0;

   __property TFIBBCDField * GoodsDataSetRSUM = {read = get_GoodsDataSetRSUM , write = set_GoodsDataSetRSUM};
   virtual TFIBBCDField * get_GoodsDataSetRSUM(void)=0;
   virtual void set_GoodsDataSetRSUM(TFIBBCDField * GoodsDataSetRSUM)=0;

   __property TFIBIntegerField * GoodsDataSetCODENOM = {read = get_GoodsDataSetCODENOM , write = set_GoodsDataSetCODENOM};
   virtual TFIBIntegerField * get_GoodsDataSetCODENOM(void)=0;
   virtual void set_GoodsDataSetCODENOM(TFIBIntegerField * GoodsDataSetCODENOM)=0;

   __property TpFIBDataSet * OstatkiDataSet = {read = get_OstatkiDataSet , write = set_OstatkiDataSet};
   virtual TpFIBDataSet * get_OstatkiDataSet(void)=0;
   virtual void set_OstatkiDataSet(TpFIBDataSet * OstatkiDataSet)=0;

   __property TFIBIntegerField * OstatkiDataSetCODENOM = {read = get_OstatkiDataSetCODENOM , write = set_OstatkiDataSetCODENOM};
   virtual TFIBIntegerField * get_OstatkiDataSetCODENOM(void)=0;
   virtual void set_OstatkiDataSetCODENOM(TFIBIntegerField * OstatkiDataSetCODENOM)=0;

   __property TFIBBCDField * OstatkiDataSetKFED = {read = get_OstatkiDataSetKFED , write = set_OstatkiDataSetKFED};
   virtual TFIBBCDField * get_OstatkiDataSetKFED(void)=0;
   virtual void set_OstatkiDataSetKFED(TFIBBCDField * OstatkiDataSetKFED)=0;

   __property TFIBBCDField * OstatkiDataSetSUMKOL = {read = get_OstatkiDataSetSUMKOL , write = set_OstatkiDataSetSUMKOL};
   virtual TFIBBCDField * get_OstatkiDataSetSUMKOL(void)=0;
   virtual void set_OstatkiDataSetSUMKOL(TFIBBCDField * OstatkiDataSetSUMKOL)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBIntegerField * DocTCODENOM = {read = get_DocTCODENOM , write = set_DocTCODENOM};
   virtual TFIBIntegerField * get_DocTCODENOM(void)=0;
   virtual void set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)=0;

   __property TFIBBCDField * DocTKF_INVT = {read = get_DocTKF_INVT , write = set_DocTKF_INVT};
   virtual TFIBBCDField * get_DocTKF_INVT(void)=0;
   virtual void set_DocTKF_INVT(TFIBBCDField * DocTKF_INVT)=0;

   __property TFIBBCDField * DocTKOLUCH_INVT = {read = get_DocTKOLUCH_INVT , write = set_DocTKOLUCH_INVT};
   virtual TFIBBCDField * get_DocTKOLUCH_INVT(void)=0;
   virtual void set_DocTKOLUCH_INVT(TFIBBCDField * DocTKOLUCH_INVT)=0;

   __property TFIBBCDField * DocTKOLFAKT_INVT = {read = get_DocTKOLFAKT_INVT , write = set_DocTKOLFAKT_INVT};
   virtual TFIBBCDField * get_DocTKOLFAKT_INVT(void)=0;
   virtual void set_DocTKOLFAKT_INVT(TFIBBCDField * DocTKOLFAKT_INVT)=0;

   __property TFIBBCDField * DocTPRICE_INVT = {read = get_DocTPRICE_INVT , write = set_DocTPRICE_INVT};
   virtual TFIBBCDField * get_DocTPRICE_INVT(void)=0;
   virtual void set_DocTPRICE_INVT(TFIBBCDField * DocTPRICE_INVT)=0;

   __property TFIBBCDField * DocTSUMF_INVT = {read = get_DocTSUMF_INVT , write = set_DocTSUMF_INVT};
   virtual TFIBBCDField * get_DocTSUMF_INVT(void)=0;
   virtual void set_DocTSUMF_INVT(TFIBBCDField * DocTSUMF_INVT)=0;

   __property TIntegerField * DocTRECNO = {read = get_DocTRECNO , write = set_DocTRECNO};
   virtual TIntegerField * get_DocTRECNO(void)=0;
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO)=0;

   __property TpFIBQuery * QueryCancelDvReg = {read = get_QueryCancelDvReg , write = set_QueryCancelDvReg};
   virtual TpFIBQuery * get_QueryCancelDvReg(void)=0;
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)=0;

   __property TpFIBQuery * QueryDvReg = {read = get_QueryDvReg , write = set_QueryDvReg};
   virtual TpFIBQuery * get_QueryDvReg(void)=0;
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg)=0;

   __property TFIBBCDField * GoodsDataSetIDNOM_DREVT = {read = get_GoodsDataSetIDNOM_DREVT , write = set_GoodsDataSetIDNOM_DREVT};
   virtual TFIBBCDField * get_GoodsDataSetIDNOM_DREVT(void)=0;
   virtual void set_GoodsDataSetIDNOM_DREVT(TFIBBCDField * GoodsDataSetIDNOM_DREVT)=0;

   __property TFIBBCDField * GoodsDataSetIDED_DREVT = {read = get_GoodsDataSetIDED_DREVT , write = set_GoodsDataSetIDED_DREVT};
   virtual TFIBBCDField * get_GoodsDataSetIDED_DREVT(void)=0;
   virtual void set_GoodsDataSetIDED_DREVT(TFIBBCDField * GoodsDataSetIDED_DREVT)=0;

   __property TFIBBCDField * OstatkiDataSetIDNOM = {read = get_OstatkiDataSetIDNOM , write = set_OstatkiDataSetIDNOM};
   virtual TFIBBCDField * get_OstatkiDataSetIDNOM(void)=0;
   virtual void set_OstatkiDataSetIDNOM(TFIBBCDField * OstatkiDataSetIDNOM)=0;

   __property TFIBBCDField * OstatkiDataSetIDED = {read = get_OstatkiDataSetIDED , write = set_OstatkiDataSetIDED};
   virtual TFIBBCDField * get_OstatkiDataSetIDED(void)=0;
   virtual void set_OstatkiDataSetIDED(TFIBBCDField * OstatkiDataSetIDED)=0;

   __property TFIBBCDField * IBQPoGrpIDGN = {read = get_IBQPoGrpIDGN , write = set_IBQPoGrpIDGN};
   virtual TFIBBCDField * get_IBQPoGrpIDGN(void)=0;
   virtual void set_IBQPoGrpIDGN(TFIBBCDField * IBQPoGrpIDGN)=0;

   __property TFIBBCDField * IBQPoGrpID_INVT = {read = get_IBQPoGrpID_INVT , write = set_IBQPoGrpID_INVT};
   virtual TFIBBCDField * get_IBQPoGrpID_INVT(void)=0;
   virtual void set_IBQPoGrpID_INVT(TFIBBCDField * IBQPoGrpID_INVT)=0;

   __property TFIBBCDField * IBQPoGrpIDDOC_INVT = {read = get_IBQPoGrpIDDOC_INVT , write = set_IBQPoGrpIDDOC_INVT};
   virtual TFIBBCDField * get_IBQPoGrpIDDOC_INVT(void)=0;
   virtual void set_IBQPoGrpIDDOC_INVT(TFIBBCDField * IBQPoGrpIDDOC_INVT)=0;

   __property TFIBBCDField * IBQPoGrpIDNOM_INVT = {read = get_IBQPoGrpIDNOM_INVT , write = set_IBQPoGrpIDNOM_INVT};
   virtual TFIBBCDField * get_IBQPoGrpIDNOM_INVT(void)=0;
   virtual void set_IBQPoGrpIDNOM_INVT(TFIBBCDField * IBQPoGrpIDNOM_INVT)=0;

   __property TFIBBCDField * IBQPoGrpIDED_INVT = {read = get_IBQPoGrpIDED_INVT , write = set_IBQPoGrpIDED_INVT};
   virtual TFIBBCDField * get_IBQPoGrpIDED_INVT(void)=0;
   virtual void set_IBQPoGrpIDED_INVT(TFIBBCDField * IBQPoGrpIDED_INVT)=0;

   __property TFIBLargeIntField * DocAllIDDOC = {read = get_DocAllIDDOC , write = set_DocAllIDDOC};
   virtual TFIBLargeIntField * get_DocAllIDDOC(void)=0;
   virtual void set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)=0;

   __property TFIBDateTimeField * DocAllPOSDOC = {read = get_DocAllPOSDOC , write = set_DocAllPOSDOC};
   virtual TFIBDateTimeField * get_DocAllPOSDOC(void)=0;
   virtual void set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)=0;

   __property TFIBSmallIntField * DocAllPRDOC = {read = get_DocAllPRDOC , write = set_DocAllPRDOC};
   virtual TFIBSmallIntField * get_DocAllPRDOC(void)=0;
   virtual void set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)=0;

   __property TFIBWideStringField * DocAllTDOC = {read = get_DocAllTDOC , write = set_DocAllTDOC};
   virtual TFIBWideStringField * get_DocAllTDOC(void)=0;
   virtual void set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)=0;

   __property TFIBIntegerField * DocAllNUMDOC = {read = get_DocAllNUMDOC , write = set_DocAllNUMDOC};
   virtual TFIBIntegerField * get_DocAllNUMDOC(void)=0;
   virtual void set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)=0;

   __property TFIBLargeIntField * DocAllIDFIRMDOC = {read = get_DocAllIDFIRMDOC , write = set_DocAllIDFIRMDOC};
   virtual TFIBLargeIntField * get_DocAllIDFIRMDOC(void)=0;
   virtual void set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)=0;

   __property TFIBLargeIntField * DocAllIDSKLDOC = {read = get_DocAllIDSKLDOC , write = set_DocAllIDSKLDOC};
   virtual TFIBLargeIntField * get_DocAllIDSKLDOC(void)=0;
   virtual void set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)=0;

   __property TFIBLargeIntField * DocAllIDKLDOC = {read = get_DocAllIDKLDOC , write = set_DocAllIDKLDOC};
   virtual TFIBLargeIntField * get_DocAllIDKLDOC(void)=0;
   virtual void set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)=0;

   __property TFIBLargeIntField * DocAllIDDOGDOC = {read = get_DocAllIDDOGDOC , write = set_DocAllIDDOGDOC};
   virtual TFIBLargeIntField * get_DocAllIDDOGDOC(void)=0;
   virtual void set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)=0;

   __property TFIBBCDField * DocAllSUMDOC = {read = get_DocAllSUMDOC , write = set_DocAllSUMDOC};
   virtual TFIBBCDField * get_DocAllSUMDOC(void)=0;
   virtual void set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)=0;

   __property TFIBLargeIntField * DocAllIDUSERDOC = {read = get_DocAllIDUSERDOC , write = set_DocAllIDUSERDOC};
   virtual TFIBLargeIntField * get_DocAllIDUSERDOC(void)=0;
   virtual void set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)=0;

   __property TFIBWideStringField * DocAllGID_DOC = {read = get_DocAllGID_DOC , write = set_DocAllGID_DOC};
   virtual TFIBWideStringField * get_DocAllGID_DOC(void)=0;
   virtual void set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)=0;

   __property TFIBWideStringField * DocAllPREFIKSDOC = {read = get_DocAllPREFIKSDOC , write = set_DocAllPREFIKSDOC};
   virtual TFIBWideStringField * get_DocAllPREFIKSDOC(void)=0;
   virtual void set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)=0;

   __property TFIBLargeIntField * DocAllIDDOCOSNDOC = {read = get_DocAllIDDOCOSNDOC , write = set_DocAllIDDOCOSNDOC};
   virtual TFIBLargeIntField * get_DocAllIDDOCOSNDOC(void)=0;
   virtual void set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)=0;

   __property TFIBLargeIntField * DocAllIDEXTDOC = {read = get_DocAllIDEXTDOC , write = set_DocAllIDEXTDOC};
   virtual TFIBLargeIntField * get_DocAllIDEXTDOC(void)=0;
   virtual void set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)=0;

   __property TFIBIntegerField * DocAllTYPEEXTDOC = {read = get_DocAllTYPEEXTDOC , write = set_DocAllTYPEEXTDOC};
   virtual TFIBIntegerField * get_DocAllTYPEEXTDOC(void)=0;
   virtual void set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)=0;

   __property TFIBLargeIntField * DocAllIDBASE_GALLDOC = {read = get_DocAllIDBASE_GALLDOC , write = set_DocAllIDBASE_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDBASE_GALLDOC(void)=0;
   virtual void set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDPROJECT_GALLDOC = {read = get_DocAllIDPROJECT_GALLDOC , write = set_DocAllIDPROJECT_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDPROJECT_GALLDOC(void)=0;
   virtual void set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)=0;

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

   __property TFIBLargeIntField * DocID_INV = {read = get_DocID_INV , write = set_DocID_INV};
   virtual TFIBLargeIntField * get_DocID_INV(void)=0;
   virtual void set_DocID_INV(TFIBLargeIntField * DocID_INV)=0;

   __property TFIBLargeIntField * DocIDDOC_INV = {read = get_DocIDDOC_INV , write = set_DocIDDOC_INV};
   virtual TFIBLargeIntField * get_DocIDDOC_INV(void)=0;
   virtual void set_DocIDDOC_INV(TFIBLargeIntField * DocIDDOC_INV)=0;

   __property TFIBWideStringField * DocPRIM_INV = {read = get_DocPRIM_INV , write = set_DocPRIM_INV};
   virtual TFIBWideStringField * get_DocPRIM_INV(void)=0;
   virtual void set_DocPRIM_INV(TFIBWideStringField * DocPRIM_INV)=0;

   __property TFIBWideStringField * DocGID_INV = {read = get_DocGID_INV , write = set_DocGID_INV};
   virtual TFIBWideStringField * get_DocGID_INV(void)=0;
   virtual void set_DocGID_INV(TFIBWideStringField * DocGID_INV)=0;

   __property TFIBLargeIntField * DocIDTPRICE_INV = {read = get_DocIDTPRICE_INV , write = set_DocIDTPRICE_INV};
   virtual TFIBLargeIntField * get_DocIDTPRICE_INV(void)=0;
   virtual void set_DocIDTPRICE_INV(TFIBLargeIntField * DocIDTPRICE_INV)=0;

   __property TFIBLargeIntField * DocIDINV_INV = {read = get_DocIDINV_INV , write = set_DocIDINV_INV};
   virtual TFIBLargeIntField * get_DocIDINV_INV(void)=0;
   virtual void set_DocIDINV_INV(TFIBLargeIntField * DocIDINV_INV)=0;

   __property TFIBIntegerField * DocTYPE_INV = {read = get_DocTYPE_INV , write = set_DocTYPE_INV};
   virtual TFIBIntegerField * get_DocTYPE_INV(void)=0;
   virtual void set_DocTYPE_INV(TFIBIntegerField * DocTYPE_INV)=0;

   __property TFIBLargeIntField * DocIDBASE_DINV = {read = get_DocIDBASE_DINV , write = set_DocIDBASE_DINV};
   virtual TFIBLargeIntField * get_DocIDBASE_DINV(void)=0;
   virtual void set_DocIDBASE_DINV(TFIBLargeIntField * DocIDBASE_DINV)=0;

   __property TFIBWideStringField * DocNAME_SINV = {read = get_DocNAME_SINV , write = set_DocNAME_SINV};
   virtual TFIBWideStringField * get_DocNAME_SINV(void)=0;
   virtual void set_DocNAME_SINV(TFIBWideStringField * DocNAME_SINV)=0;

   __property TFIBWideStringField * DocTNAMEGN = {read = get_DocTNAMEGN , write = set_DocTNAMEGN};
   virtual TFIBWideStringField * get_DocTNAMEGN(void)=0;
   virtual void set_DocTNAMEGN(TFIBWideStringField * DocTNAMEGN)=0;

   __property TFIBLargeIntField * DocTIDGN = {read = get_DocTIDGN , write = set_DocTIDGN};
   virtual TFIBLargeIntField * get_DocTIDGN(void)=0;
   virtual void set_DocTIDGN(TFIBLargeIntField * DocTIDGN)=0;

   __property TFIBWideStringField * DocTNAMENOM = {read = get_DocTNAMENOM , write = set_DocTNAMENOM};
   virtual TFIBWideStringField * get_DocTNAMENOM(void)=0;
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)=0;

   __property TFIBIntegerField * DocTTNOM = {read = get_DocTTNOM , write = set_DocTTNOM};
   virtual TFIBIntegerField * get_DocTTNOM(void)=0;
   virtual void set_DocTTNOM(TFIBIntegerField * DocTTNOM)=0;

   __property TFIBLargeIntField * DocTID_INVT = {read = get_DocTID_INVT , write = set_DocTID_INVT};
   virtual TFIBLargeIntField * get_DocTID_INVT(void)=0;
   virtual void set_DocTID_INVT(TFIBLargeIntField * DocTID_INVT)=0;

   __property TFIBLargeIntField * DocTIDDOC_INVT = {read = get_DocTIDDOC_INVT , write = set_DocTIDDOC_INVT};
   virtual TFIBLargeIntField * get_DocTIDDOC_INVT(void)=0;
   virtual void set_DocTIDDOC_INVT(TFIBLargeIntField * DocTIDDOC_INVT)=0;

   __property TFIBLargeIntField * DocTIDNOM_INVT = {read = get_DocTIDNOM_INVT , write = set_DocTIDNOM_INVT};
   virtual TFIBLargeIntField * get_DocTIDNOM_INVT(void)=0;
   virtual void set_DocTIDNOM_INVT(TFIBLargeIntField * DocTIDNOM_INVT)=0;

   __property TFIBLargeIntField * DocTIDED_INVT = {read = get_DocTIDED_INVT , write = set_DocTIDED_INVT};
   virtual TFIBLargeIntField * get_DocTIDED_INVT(void)=0;
   virtual void set_DocTIDED_INVT(TFIBLargeIntField * DocTIDED_INVT)=0;

   __property TFIBWideStringField * DocTGID_INVT = {read = get_DocTGID_INVT , write = set_DocTGID_INVT};
   virtual TFIBWideStringField * get_DocTGID_INVT(void)=0;
   virtual void set_DocTGID_INVT(TFIBWideStringField * DocTGID_INVT)=0;

   __property TFIBLargeIntField * DocTIDBASE_DINVT = {read = get_DocTIDBASE_DINVT , write = set_DocTIDBASE_DINVT};
   virtual TFIBLargeIntField * get_DocTIDBASE_DINVT(void)=0;
   virtual void set_DocTIDBASE_DINVT(TFIBLargeIntField * DocTIDBASE_DINVT)=0;

   __property TFIBWideStringField * DocTNAMEED = {read = get_DocTNAMEED , write = set_DocTNAMEED};
   virtual TFIBWideStringField * get_DocTNAMEED(void)=0;
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)=0;

   __property TFIBWideStringField * DocAllFNAMEFIRM = {read = get_DocAllFNAMEFIRM , write = set_DocAllFNAMEFIRM};
   virtual TFIBWideStringField * get_DocAllFNAMEFIRM(void)=0;
   virtual void set_DocAllFNAMEFIRM(TFIBWideStringField * DocAllFNAMEFIRM)=0;

   __property TFIBWideStringField * DocAllINNFIRM = {read = get_DocAllINNFIRM , write = set_DocAllINNFIRM};
   virtual TFIBWideStringField * get_DocAllINNFIRM(void)=0;
   virtual void set_DocAllINNFIRM(TFIBWideStringField * DocAllINNFIRM)=0;

   __property TFIBWideStringField * DocAllPADRFIRM = {read = get_DocAllPADRFIRM , write = set_DocAllPADRFIRM};
   virtual TFIBWideStringField * get_DocAllPADRFIRM(void)=0;
   virtual void set_DocAllPADRFIRM(TFIBWideStringField * DocAllPADRFIRM)=0;

   __property TFIBWideStringField * IBQPoGrpNAMEGN = {read = get_IBQPoGrpNAMEGN , write = set_IBQPoGrpNAMEGN};
   virtual TFIBWideStringField * get_IBQPoGrpNAMEGN(void)=0;
   virtual void set_IBQPoGrpNAMEGN(TFIBWideStringField * IBQPoGrpNAMEGN)=0;

   __property TFIBWideStringField * IBQPoGrpNAMENOM = {read = get_IBQPoGrpNAMENOM , write = set_IBQPoGrpNAMENOM};
   virtual TFIBWideStringField * get_IBQPoGrpNAMENOM(void)=0;
   virtual void set_IBQPoGrpNAMENOM(TFIBWideStringField * IBQPoGrpNAMENOM)=0;

   __property TFIBWideStringField * IBQPoGrpNAMEED = {read = get_IBQPoGrpNAMEED , write = set_IBQPoGrpNAMEED};
   virtual TFIBWideStringField * get_IBQPoGrpNAMEED(void)=0;
   virtual void set_IBQPoGrpNAMEED(TFIBWideStringField * IBQPoGrpNAMEED)=0;

   __property TFIBWideStringField * GoodsDataSetNAMENOM = {read = get_GoodsDataSetNAMENOM , write = set_GoodsDataSetNAMENOM};
   virtual TFIBWideStringField * get_GoodsDataSetNAMENOM(void)=0;
   virtual void set_GoodsDataSetNAMENOM(TFIBWideStringField * GoodsDataSetNAMENOM)=0;

   __property TFIBWideStringField * GoodsDataSetNAMEED = {read = get_GoodsDataSetNAMEED , write = set_GoodsDataSetNAMEED};
   virtual TFIBWideStringField * get_GoodsDataSetNAMEED(void)=0;
   virtual void set_GoodsDataSetNAMEED(TFIBWideStringField * GoodsDataSetNAMEED)=0;

   __property TFIBWideStringField * OstatkiDataSetNAMENOM = {read = get_OstatkiDataSetNAMENOM , write = set_OstatkiDataSetNAMENOM};
   virtual TFIBWideStringField * get_OstatkiDataSetNAMENOM(void)=0;
   virtual void set_OstatkiDataSetNAMENOM(TFIBWideStringField * OstatkiDataSetNAMENOM)=0;

   __property TFIBWideStringField * OstatkiDataSetNAMEED = {read = get_OstatkiDataSetNAMEED , write = set_OstatkiDataSetNAMEED};
   virtual TFIBWideStringField * get_OstatkiDataSetNAMEED(void)=0;
   virtual void set_OstatkiDataSetNAMEED(TFIBWideStringField * OstatkiDataSetNAMEED)=0;

   __property TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC = {read = get_DocAllIDBUSINOP_GALLDOC , write = set_DocAllIDBUSINOP_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDBUSINOP_GALLDOC(void)=0;
   virtual void set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)=0;

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

   __property TFIBWideStringField * DocTSHED = {read = get_DocTSHED , write = set_DocTSHED};
   virtual TFIBWideStringField * get_DocTSHED(void)=0;
   virtual void set_DocTSHED(TFIBWideStringField * DocTSHED)=0;

   __property bool NewElement = {read = get_NewElement , write = set_NewElement};
   virtual bool get_NewElement(void)=0;
   virtual void set_NewElement(bool NewElement)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property bool NoEdit = {read = get_NoEdit , write = set_NoEdit};
   virtual bool get_NoEdit(void)=0;
   virtual void set_NoEdit(bool NoEdit)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdElementaMaster = {read = get_IdElementaMaster , write = set_IdElementaMaster};
   virtual __int64 get_IdElementaMaster(void)=0;
   virtual void set_IdElementaMaster(__int64 IdElementaMaster)=0;

   __property __int64 IdGrpNom = {read = get_IdGrpNom , write = set_IdGrpNom};
   virtual __int64 get_IdGrpNom(void)=0;
   virtual void set_IdGrpNom(__int64 IdGrpNom)=0;

   __property bool ChangeTable = {read = get_ChangeTable , write = set_ChangeTable};
   virtual bool get_ChangeTable(void)=0;
   virtual void set_ChangeTable(bool ChangeTable)=0;

   __property bool ErrorRaschet = {read = get_ErrorRaschet , write = set_ErrorRaschet};
   virtual bool get_ErrorRaschet(void)=0;
   virtual void set_ErrorRaschet(bool ErrorRaschet)=0;

   __property bool EnableDvReg = {read = get_EnableDvReg , write = set_EnableDvReg};
   virtual bool get_EnableDvReg(void)=0;
   virtual void set_EnableDvReg(bool EnableDvReg)=0;

   virtual void NewDoc(void)=0;
   virtual void OpenDoc(__int64 id_doc)=0;
   virtual bool SaveDoc(void)=0;
   virtual bool DvRegDoc(void)=0;
   virtual bool CancelDvRegDoc(void)=0;
   virtual void AddDocNewString(void)=0;
   virtual void DeleteStringDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual __int64 GetIDDocPoNomeruDoc(int number_doc, TDate date_doc)=0;
   virtual void AddDataRev(void)=0;
   virtual bool SearchStringPoNom(__int64 id_nom)=0;
   virtual int GetNumberNewDoc(void)=0;
};
#define IID_IDMDocInv __uuidof(IDMDocInv)
#endif
