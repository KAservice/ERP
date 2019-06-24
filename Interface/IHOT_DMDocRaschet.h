#ifndef UIHOT_DMDocRaschetH
#define UIHOT_DMDocRaschetH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{E63D2834-E46B-4FCA-8C52-06B7D159C4DF}")) IHOT_DMDocRaschet : public IMainInterface
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

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBDateTimeField * DocAllPOS_HOT_GALLDOC = {read = get_DocAllPOS_HOT_GALLDOC , write = set_DocAllPOS_HOT_GALLDOC};
   virtual TFIBDateTimeField * get_DocAllPOS_HOT_GALLDOC(void)=0;
   virtual void set_DocAllPOS_HOT_GALLDOC(TFIBDateTimeField * DocAllPOS_HOT_GALLDOC)=0;

   __property TFIBSmallIntField * DocAllPR_HOT_GALLDOC = {read = get_DocAllPR_HOT_GALLDOC , write = set_DocAllPR_HOT_GALLDOC};
   virtual TFIBSmallIntField * get_DocAllPR_HOT_GALLDOC(void)=0;
   virtual void set_DocAllPR_HOT_GALLDOC(TFIBSmallIntField * DocAllPR_HOT_GALLDOC)=0;

   __property TFIBBCDField * DocAllSUM_HOT_GALLDOC = {read = get_DocAllSUM_HOT_GALLDOC , write = set_DocAllSUM_HOT_GALLDOC};
   virtual TFIBBCDField * get_DocAllSUM_HOT_GALLDOC(void)=0;
   virtual void set_DocAllSUM_HOT_GALLDOC(TFIBBCDField * DocAllSUM_HOT_GALLDOC)=0;

   __property TpFIBQuery * QueryDvReg = {read = get_QueryDvReg , write = set_QueryDvReg};
   virtual TpFIBQuery * get_QueryDvReg(void)=0;
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg)=0;

   __property TpFIBQuery * QueryCancelDvReg = {read = get_QueryCancelDvReg , write = set_QueryCancelDvReg};
   virtual TpFIBQuery * get_QueryCancelDvReg(void)=0;
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)=0;

   __property TpFIBDataSet * TypePriceDataSet = {read = get_TypePriceDataSet , write = set_TypePriceDataSet};
   virtual TpFIBDataSet * get_TypePriceDataSet(void)=0;
   virtual void set_TypePriceDataSet(TpFIBDataSet * TypePriceDataSet)=0;

   __property TFIBSmallIntField * DocTTUSL_HOT_DRASCHETT = {read = get_DocTTUSL_HOT_DRASCHETT , write = set_DocTTUSL_HOT_DRASCHETT};
   virtual TFIBSmallIntField * get_DocTTUSL_HOT_DRASCHETT(void)=0;
   virtual void set_DocTTUSL_HOT_DRASCHETT(TFIBSmallIntField * DocTTUSL_HOT_DRASCHETT)=0;

   __property TFIBBCDField * DocTKOL_HOT_DRASCHETT = {read = get_DocTKOL_HOT_DRASCHETT , write = set_DocTKOL_HOT_DRASCHETT};
   virtual TFIBBCDField * get_DocTKOL_HOT_DRASCHETT(void)=0;
   virtual void set_DocTKOL_HOT_DRASCHETT(TFIBBCDField * DocTKOL_HOT_DRASCHETT)=0;

   __property TFIBBCDField * DocTKF_HOT_DRASCHETT = {read = get_DocTKF_HOT_DRASCHETT , write = set_DocTKF_HOT_DRASCHETT};
   virtual TFIBBCDField * get_DocTKF_HOT_DRASCHETT(void)=0;
   virtual void set_DocTKF_HOT_DRASCHETT(TFIBBCDField * DocTKF_HOT_DRASCHETT)=0;

   __property TFIBBCDField * DocTPRICE_HOT_DRASCHETT = {read = get_DocTPRICE_HOT_DRASCHETT , write = set_DocTPRICE_HOT_DRASCHETT};
   virtual TFIBBCDField * get_DocTPRICE_HOT_DRASCHETT(void)=0;
   virtual void set_DocTPRICE_HOT_DRASCHETT(TFIBBCDField * DocTPRICE_HOT_DRASCHETT)=0;

   __property TIntegerField * DocTRECNO = {read = get_DocTRECNO , write = set_DocTRECNO};
   virtual TIntegerField * get_DocTRECNO(void)=0;
   virtual void set_DocTRECNO(TIntegerField * DocTRECNO)=0;

   __property TFIBBCDField * DocTSUM_HOT_DRASCHETT = {read = get_DocTSUM_HOT_DRASCHETT , write = set_DocTSUM_HOT_DRASCHETT};
   virtual TFIBBCDField * get_DocTSUM_HOT_DRASCHETT(void)=0;
   virtual void set_DocTSUM_HOT_DRASCHETT(TFIBBCDField * DocTSUM_HOT_DRASCHETT)=0;

   __property TFIBDateTimeField * DocTPOSNACH_HOT_DRASCHETT = {read = get_DocTPOSNACH_HOT_DRASCHETT , write = set_DocTPOSNACH_HOT_DRASCHETT};
   virtual TFIBDateTimeField * get_DocTPOSNACH_HOT_DRASCHETT(void)=0;
   virtual void set_DocTPOSNACH_HOT_DRASCHETT(TFIBDateTimeField * DocTPOSNACH_HOT_DRASCHETT)=0;

   __property TFIBDateTimeField * DocTPOSCON_HOT_DRASCHETT = {read = get_DocTPOSCON_HOT_DRASCHETT , write = set_DocTPOSCON_HOT_DRASCHETT};
   virtual TFIBDateTimeField * get_DocTPOSCON_HOT_DRASCHETT(void)=0;
   virtual void set_DocTPOSCON_HOT_DRASCHETT(TFIBDateTimeField * DocTPOSCON_HOT_DRASCHETT)=0;

   __property TStringField * DocTVIBOR_TYPE_PRICE = {read = get_DocTVIBOR_TYPE_PRICE , write = set_DocTVIBOR_TYPE_PRICE};
   virtual TStringField * get_DocTVIBOR_TYPE_PRICE(void)=0;
   virtual void set_DocTVIBOR_TYPE_PRICE(TStringField * DocTVIBOR_TYPE_PRICE)=0;

   __property TpFIBDataSet * SpisokGuestOsnUslug = {read = get_SpisokGuestOsnUslug , write = set_SpisokGuestOsnUslug};
   virtual TpFIBDataSet * get_SpisokGuestOsnUslug(void)=0;
   virtual void set_SpisokGuestOsnUslug(TpFIBDataSet * SpisokGuestOsnUslug)=0;

   __property TpFIBDataSet * SpisokGuestDopUslug = {read = get_SpisokGuestDopUslug , write = set_SpisokGuestDopUslug};
   virtual TpFIBDataSet * get_SpisokGuestDopUslug(void)=0;
   virtual void set_SpisokGuestDopUslug(TpFIBDataSet * SpisokGuestDopUslug)=0;

   __property TFIBFloatField * SpisokGuestOsnUslugSUMKOL = {read = get_SpisokGuestOsnUslugSUMKOL , write = set_SpisokGuestOsnUslugSUMKOL};
   virtual TFIBFloatField * get_SpisokGuestOsnUslugSUMKOL(void)=0;
   virtual void set_SpisokGuestOsnUslugSUMKOL(TFIBFloatField * SpisokGuestOsnUslugSUMKOL)=0;

   __property TFIBBCDField * SpisokGuestDopUslugSUM = {read = get_SpisokGuestDopUslugSUM , write = set_SpisokGuestDopUslugSUM};
   virtual TFIBBCDField * get_SpisokGuestDopUslugSUM(void)=0;
   virtual void set_SpisokGuestDopUslugSUM(TFIBBCDField * SpisokGuestDopUslugSUM)=0;

   __property TFIBBCDField * SpisokGuestOsnUslugIDKLIENT = {read = get_SpisokGuestOsnUslugIDKLIENT , write = set_SpisokGuestOsnUslugIDKLIENT};
   virtual TFIBBCDField * get_SpisokGuestOsnUslugIDKLIENT(void)=0;
   virtual void set_SpisokGuestOsnUslugIDKLIENT(TFIBBCDField * SpisokGuestOsnUslugIDKLIENT)=0;

   __property TFIBBCDField * SpisokGuestDopUslugIDKLIENT = {read = get_SpisokGuestDopUslugIDKLIENT , write = set_SpisokGuestDopUslugIDKLIENT};
   virtual TFIBBCDField * get_SpisokGuestDopUslugIDKLIENT(void)=0;
   virtual void set_SpisokGuestDopUslugIDKLIENT(TFIBBCDField * SpisokGuestDopUslugIDKLIENT)=0;

   __property TpFIBDataSet * NumDoc = {read = get_NumDoc , write = set_NumDoc};
   virtual TpFIBDataSet * get_NumDoc(void)=0;
   virtual void set_NumDoc(TpFIBDataSet * NumDoc)=0;

   __property TFIBIntegerField * NumDocMAXNUMBER = {read = get_NumDocMAXNUMBER , write = set_NumDocMAXNUMBER};
   virtual TFIBIntegerField * get_NumDocMAXNUMBER(void)=0;
   virtual void set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)=0;

   __property TFIBWideStringField * SpisokGuestOsnUslugNAMEKLIENT = {read = get_SpisokGuestOsnUslugNAMEKLIENT , write = set_SpisokGuestOsnUslugNAMEKLIENT};
   virtual TFIBWideStringField * get_SpisokGuestOsnUslugNAMEKLIENT(void)=0;
   virtual void set_SpisokGuestOsnUslugNAMEKLIENT(TFIBWideStringField * SpisokGuestOsnUslugNAMEKLIENT)=0;

   __property TFIBWideStringField * SpisokGuestDopUslugNAMEKLIENT = {read = get_SpisokGuestDopUslugNAMEKLIENT , write = set_SpisokGuestDopUslugNAMEKLIENT};
   virtual TFIBWideStringField * get_SpisokGuestDopUslugNAMEKLIENT(void)=0;
   virtual void set_SpisokGuestDopUslugNAMEKLIENT(TFIBWideStringField * SpisokGuestDopUslugNAMEKLIENT)=0;

   __property TFIBWideStringField * DocAllTDOC_HOT_GALLDOC = {read = get_DocAllTDOC_HOT_GALLDOC , write = set_DocAllTDOC_HOT_GALLDOC};
   virtual TFIBWideStringField * get_DocAllTDOC_HOT_GALLDOC(void)=0;
   virtual void set_DocAllTDOC_HOT_GALLDOC(TFIBWideStringField * DocAllTDOC_HOT_GALLDOC)=0;

   __property TFIBIntegerField * DocAllNUMBER_HOT_GALLDOC = {read = get_DocAllNUMBER_HOT_GALLDOC , write = set_DocAllNUMBER_HOT_GALLDOC};
   virtual TFIBIntegerField * get_DocAllNUMBER_HOT_GALLDOC(void)=0;
   virtual void set_DocAllNUMBER_HOT_GALLDOC(TFIBIntegerField * DocAllNUMBER_HOT_GALLDOC)=0;

   __property TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN = {read = get_DocAllNAME_SINFBASE_OBMEN , write = set_DocAllNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * DocAllNAMEFIRM = {read = get_DocAllNAMEFIRM , write = set_DocAllNAMEFIRM};
   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void)=0;
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)=0;

   __property TFIBWideStringField * DocAllNAMEKLIENT = {read = get_DocAllNAMEKLIENT , write = set_DocAllNAMEKLIENT};
   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void)=0;
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)=0;

   __property TFIBWideStringField * DocAllFNAME_USER = {read = get_DocAllFNAME_USER , write = set_DocAllFNAME_USER};
   virtual TFIBWideStringField * get_DocAllFNAME_USER(void)=0;
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)=0;

   __property TFIBWideStringField * DocAllNAMESKLAD = {read = get_DocAllNAMESKLAD , write = set_DocAllNAMESKLAD};
   virtual TFIBWideStringField * get_DocAllNAMESKLAD(void)=0;
   virtual void set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)=0;

   __property TFIBWideStringField * DocPRIM_HOT_DRASCHET = {read = get_DocPRIM_HOT_DRASCHET , write = set_DocPRIM_HOT_DRASCHET};
   virtual TFIBWideStringField * get_DocPRIM_HOT_DRASCHET(void)=0;
   virtual void set_DocPRIM_HOT_DRASCHET(TFIBWideStringField * DocPRIM_HOT_DRASCHET)=0;

   __property TFIBWideStringField * DocNAMEBSCHET = {read = get_DocNAMEBSCHET , write = set_DocNAMEBSCHET};
   virtual TFIBWideStringField * get_DocNAMEBSCHET(void)=0;
   virtual void set_DocNAMEBSCHET(TFIBWideStringField * DocNAMEBSCHET)=0;

   __property TFIBWideStringField * DocTNAMENOM = {read = get_DocTNAMENOM , write = set_DocTNAMENOM};
   virtual TFIBWideStringField * get_DocTNAMENOM(void)=0;
   virtual void set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)=0;

   __property TFIBWideStringField * DocTNAMEED = {read = get_DocTNAMEED , write = set_DocTNAMEED};
   virtual TFIBWideStringField * get_DocTNAMEED(void)=0;
   virtual void set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)=0;

   __property TFIBSmallIntField * DocTTNOM = {read = get_DocTTNOM , write = set_DocTTNOM};
   virtual TFIBSmallIntField * get_DocTTNOM(void)=0;
   virtual void set_DocTTNOM(TFIBSmallIntField * DocTTNOM)=0;

   __property TFIBWideStringField * DocTNAME_TPRICE = {read = get_DocTNAME_TPRICE , write = set_DocTNAME_TPRICE};
   virtual TFIBWideStringField * get_DocTNAME_TPRICE(void)=0;
   virtual void set_DocTNAME_TPRICE(TFIBWideStringField * DocTNAME_TPRICE)=0;

   __property TFIBWideStringField * DocTNAME_HOT_SNF = {read = get_DocTNAME_HOT_SNF , write = set_DocTNAME_HOT_SNF};
   virtual TFIBWideStringField * get_DocTNAME_HOT_SNF(void)=0;
   virtual void set_DocTNAME_HOT_SNF(TFIBWideStringField * DocTNAME_HOT_SNF)=0;

   __property TFIBWideStringField * DocTNAME_HOT_SCATNOM = {read = get_DocTNAME_HOT_SCATNOM , write = set_DocTNAME_HOT_SCATNOM};
   virtual TFIBWideStringField * get_DocTNAME_HOT_SCATNOM(void)=0;
   virtual void set_DocTNAME_HOT_SCATNOM(TFIBWideStringField * DocTNAME_HOT_SCATNOM)=0;

   __property TFIBWideStringField * DocTNAME_HOT_STYPEPOS = {read = get_DocTNAME_HOT_STYPEPOS , write = set_DocTNAME_HOT_STYPEPOS};
   virtual TFIBWideStringField * get_DocTNAME_HOT_STYPEPOS(void)=0;
   virtual void set_DocTNAME_HOT_STYPEPOS(TFIBWideStringField * DocTNAME_HOT_STYPEPOS)=0;

   __property TFIBWideStringField * DocTNAMEKLIENT = {read = get_DocTNAMEKLIENT , write = set_DocTNAMEKLIENT};
   virtual TFIBWideStringField * get_DocTNAMEKLIENT(void)=0;
   virtual void set_DocTNAMEKLIENT(TFIBWideStringField * DocTNAMEKLIENT)=0;

   __property TFIBLargeIntField * DocAllID_HOT_GALLDOC = {read = get_DocAllID_HOT_GALLDOC , write = set_DocAllID_HOT_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllID_HOT_GALLDOC(void)=0;
   virtual void set_DocAllID_HOT_GALLDOC(TFIBLargeIntField * DocAllID_HOT_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDFIRM_HOT_GALLDOC = {read = get_DocAllIDFIRM_HOT_GALLDOC , write = set_DocAllIDFIRM_HOT_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDFIRM_HOT_GALLDOC(void)=0;
   virtual void set_DocAllIDFIRM_HOT_GALLDOC(TFIBLargeIntField * DocAllIDFIRM_HOT_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDKL_HOT_GALLDOC = {read = get_DocAllIDKL_HOT_GALLDOC , write = set_DocAllIDKL_HOT_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDKL_HOT_GALLDOC(void)=0;
   virtual void set_DocAllIDKL_HOT_GALLDOC(TFIBLargeIntField * DocAllIDKL_HOT_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDUSER_HOT_GALLDOC = {read = get_DocAllIDUSER_HOT_GALLDOC , write = set_DocAllIDUSER_HOT_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDUSER_HOT_GALLDOC(void)=0;
   virtual void set_DocAllIDUSER_HOT_GALLDOC(TFIBLargeIntField * DocAllIDUSER_HOT_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDDOCOSN_HOT_GALLDOC = {read = get_DocAllIDDOCOSN_HOT_GALLDOC , write = set_DocAllIDDOCOSN_HOT_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDDOCOSN_HOT_GALLDOC(void)=0;
   virtual void set_DocAllIDDOCOSN_HOT_GALLDOC(TFIBLargeIntField * DocAllIDDOCOSN_HOT_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDSKLAD_HOT_GALLDOC = {read = get_DocAllIDSKLAD_HOT_GALLDOC , write = set_DocAllIDSKLAD_HOT_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDSKLAD_HOT_GALLDOC(void)=0;
   virtual void set_DocAllIDSKLAD_HOT_GALLDOC(TFIBLargeIntField * DocAllIDSKLAD_HOT_GALLDOC)=0;

   __property TFIBLargeIntField * DocAllIDBASE_HOT_GALLDOC = {read = get_DocAllIDBASE_HOT_GALLDOC , write = set_DocAllIDBASE_HOT_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDBASE_HOT_GALLDOC(void)=0;
   virtual void set_DocAllIDBASE_HOT_GALLDOC(TFIBLargeIntField * DocAllIDBASE_HOT_GALLDOC)=0;

   __property TFIBLargeIntField * DocID_HOT_DRASCHET = {read = get_DocID_HOT_DRASCHET , write = set_DocID_HOT_DRASCHET};
   virtual TFIBLargeIntField * get_DocID_HOT_DRASCHET(void)=0;
   virtual void set_DocID_HOT_DRASCHET(TFIBLargeIntField * DocID_HOT_DRASCHET)=0;

   __property TFIBLargeIntField * DocIDDOCH_HOT_DRASCHET = {read = get_DocIDDOCH_HOT_DRASCHET , write = set_DocIDDOCH_HOT_DRASCHET};
   virtual TFIBLargeIntField * get_DocIDDOCH_HOT_DRASCHET(void)=0;
   virtual void set_DocIDDOCH_HOT_DRASCHET(TFIBLargeIntField * DocIDDOCH_HOT_DRASCHET)=0;

   __property TFIBLargeIntField * DocIDBSCHET_HOT_DRASCHET = {read = get_DocIDBSCHET_HOT_DRASCHET , write = set_DocIDBSCHET_HOT_DRASCHET};
   virtual TFIBLargeIntField * get_DocIDBSCHET_HOT_DRASCHET(void)=0;
   virtual void set_DocIDBSCHET_HOT_DRASCHET(TFIBLargeIntField * DocIDBSCHET_HOT_DRASCHET)=0;

   __property TFIBLargeIntField * DocIDBASE_HOT_DRASCHET = {read = get_DocIDBASE_HOT_DRASCHET , write = set_DocIDBASE_HOT_DRASCHET};
   virtual TFIBLargeIntField * get_DocIDBASE_HOT_DRASCHET(void)=0;
   virtual void set_DocIDBASE_HOT_DRASCHET(TFIBLargeIntField * DocIDBASE_HOT_DRASCHET)=0;

   __property TFIBLargeIntField * DocIDTPRICE_HOT_DRASCHET = {read = get_DocIDTPRICE_HOT_DRASCHET , write = set_DocIDTPRICE_HOT_DRASCHET};
   virtual TFIBLargeIntField * get_DocIDTPRICE_HOT_DRASCHET(void)=0;
   virtual void set_DocIDTPRICE_HOT_DRASCHET(TFIBLargeIntField * DocIDTPRICE_HOT_DRASCHET)=0;

   __property TFIBLargeIntField * DocTID_HOT_DRASCHETT = {read = get_DocTID_HOT_DRASCHETT , write = set_DocTID_HOT_DRASCHETT};
   virtual TFIBLargeIntField * get_DocTID_HOT_DRASCHETT(void)=0;
   virtual void set_DocTID_HOT_DRASCHETT(TFIBLargeIntField * DocTID_HOT_DRASCHETT)=0;

   __property TFIBLargeIntField * DocTIDDOCH_HOT_DRASCHETT = {read = get_DocTIDDOCH_HOT_DRASCHETT , write = set_DocTIDDOCH_HOT_DRASCHETT};
   virtual TFIBLargeIntField * get_DocTIDDOCH_HOT_DRASCHETT(void)=0;
   virtual void set_DocTIDDOCH_HOT_DRASCHETT(TFIBLargeIntField * DocTIDDOCH_HOT_DRASCHETT)=0;

   __property TFIBLargeIntField * DocTIDTPRICE_HOT_DRASCHETT = {read = get_DocTIDTPRICE_HOT_DRASCHETT , write = set_DocTIDTPRICE_HOT_DRASCHETT};
   virtual TFIBLargeIntField * get_DocTIDTPRICE_HOT_DRASCHETT(void)=0;
   virtual void set_DocTIDTPRICE_HOT_DRASCHETT(TFIBLargeIntField * DocTIDTPRICE_HOT_DRASCHETT)=0;

   __property TFIBLargeIntField * DocTIDNOM_HOT_DRASCHETT = {read = get_DocTIDNOM_HOT_DRASCHETT , write = set_DocTIDNOM_HOT_DRASCHETT};
   virtual TFIBLargeIntField * get_DocTIDNOM_HOT_DRASCHETT(void)=0;
   virtual void set_DocTIDNOM_HOT_DRASCHETT(TFIBLargeIntField * DocTIDNOM_HOT_DRASCHETT)=0;

   __property TFIBLargeIntField * DocTIDED_HOT_DRASCHETT = {read = get_DocTIDED_HOT_DRASCHETT , write = set_DocTIDED_HOT_DRASCHETT};
   virtual TFIBLargeIntField * get_DocTIDED_HOT_DRASCHETT(void)=0;
   virtual void set_DocTIDED_HOT_DRASCHETT(TFIBLargeIntField * DocTIDED_HOT_DRASCHETT)=0;

   __property TFIBLargeIntField * DocTIDNOMER_HOT_DRASCHETT = {read = get_DocTIDNOMER_HOT_DRASCHETT , write = set_DocTIDNOMER_HOT_DRASCHETT};
   virtual TFIBLargeIntField * get_DocTIDNOMER_HOT_DRASCHETT(void)=0;
   virtual void set_DocTIDNOMER_HOT_DRASCHETT(TFIBLargeIntField * DocTIDNOMER_HOT_DRASCHETT)=0;

   __property TFIBLargeIntField * DocTIDCAT_HOT_DRASCHETT = {read = get_DocTIDCAT_HOT_DRASCHETT , write = set_DocTIDCAT_HOT_DRASCHETT};
   virtual TFIBLargeIntField * get_DocTIDCAT_HOT_DRASCHETT(void)=0;
   virtual void set_DocTIDCAT_HOT_DRASCHETT(TFIBLargeIntField * DocTIDCAT_HOT_DRASCHETT)=0;

   __property TFIBLargeIntField * DocTIDGUEST_HOT_DRASCHETT = {read = get_DocTIDGUEST_HOT_DRASCHETT , write = set_DocTIDGUEST_HOT_DRASCHETT};
   virtual TFIBLargeIntField * get_DocTIDGUEST_HOT_DRASCHETT(void)=0;
   virtual void set_DocTIDGUEST_HOT_DRASCHETT(TFIBLargeIntField * DocTIDGUEST_HOT_DRASCHETT)=0;

   __property TFIBLargeIntField * DocTIDTPOS_HOT_DRASCHETT = {read = get_DocTIDTPOS_HOT_DRASCHETT , write = set_DocTIDTPOS_HOT_DRASCHETT};
   virtual TFIBLargeIntField * get_DocTIDTPOS_HOT_DRASCHETT(void)=0;
   virtual void set_DocTIDTPOS_HOT_DRASCHETT(TFIBLargeIntField * DocTIDTPOS_HOT_DRASCHETT)=0;

   __property TFIBLargeIntField * DocTIDBASE_HOT_DRASCHETT = {read = get_DocTIDBASE_HOT_DRASCHETT , write = set_DocTIDBASE_HOT_DRASCHETT};
   virtual TFIBLargeIntField * get_DocTIDBASE_HOT_DRASCHETT(void)=0;
   virtual void set_DocTIDBASE_HOT_DRASCHETT(TFIBLargeIntField * DocTIDBASE_HOT_DRASCHETT)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property bool NoEdit = {read = get_NoEdit , write = set_NoEdit};
   virtual bool get_NoEdit(void)=0;
   virtual void set_NoEdit(bool NoEdit)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   virtual void NewDoc(void)=0;
   virtual void OpenDoc(__int64 IdDoc)=0;
   virtual bool SaveDoc(void)=0;
   virtual bool DvRegDoc(void)=0;
   virtual bool CancelDvRegDoc(void)=0;
   virtual void AddString(void)=0;
   virtual void DeleteString(void)=0;
   virtual void CloseDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual void GetSpisokGuest(void)=0;
   virtual double GetKolOsnUslugGuest(__int64 id_guest)=0;
   virtual double GetSumDopUslugGuest(__int64 id_guest)=0;
};
#define IID_IHOT_DMDocRaschet __uuidof(IHOT_DMDocRaschet)
#endif
