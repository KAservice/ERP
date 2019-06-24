#ifndef UIHOT_DMDocRasmH
#define UIHOT_DMDocRasmH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{62205786-4B6E-4555-8B60-4DB8BD07451F}")) IHOT_DMDocRasm : public IMainInterface
{
public:
   __property TDataSource * DataSourceDoc = {read = get_DataSourceDoc , write = set_DataSourceDoc};
   virtual TDataSource * get_DataSourceDoc(void)=0;
   virtual void set_DataSourceDoc(TDataSource * DataSourceDoc)=0;

   __property TDataSource * DataSourceDocAll = {read = get_DataSourceDocAll , write = set_DataSourceDocAll};
   virtual TDataSource * get_DataSourceDocAll(void)=0;
   virtual void set_DataSourceDocAll(TDataSource * DataSourceDocAll)=0;

   __property TpFIBDataSet * DocAll = {read = get_DocAll , write = set_DocAll};
   virtual TpFIBDataSet * get_DocAll(void)=0;
   virtual void set_DocAll(TpFIBDataSet * DocAll)=0;

   __property TpFIBDataSet * Doc = {read = get_Doc , write = set_Doc};
   virtual TpFIBDataSet * get_Doc(void)=0;
   virtual void set_Doc(TpFIBDataSet * Doc)=0;

   __property TpFIBDataSet * NumDoc = {read = get_NumDoc , write = set_NumDoc};
   virtual TpFIBDataSet * get_NumDoc(void)=0;
   virtual void set_NumDoc(TpFIBDataSet * NumDoc)=0;

   __property TFIBIntegerField * NumDocMAXNUMBER = {read = get_NumDocMAXNUMBER , write = set_NumDocMAXNUMBER};
   virtual TFIBIntegerField * get_NumDocMAXNUMBER(void)=0;
   virtual void set_NumDocMAXNUMBER(TFIBIntegerField * NumDocMAXNUMBER)=0;

   __property TFIBDateTimeField * DocAllPOS_HOT_GALLDOC = {read = get_DocAllPOS_HOT_GALLDOC , write = set_DocAllPOS_HOT_GALLDOC};
   virtual TFIBDateTimeField * get_DocAllPOS_HOT_GALLDOC(void)=0;
   virtual void set_DocAllPOS_HOT_GALLDOC(TFIBDateTimeField * DocAllPOS_HOT_GALLDOC)=0;

   __property TFIBSmallIntField * DocAllPR_HOT_GALLDOC = {read = get_DocAllPR_HOT_GALLDOC , write = set_DocAllPR_HOT_GALLDOC};
   virtual TFIBSmallIntField * get_DocAllPR_HOT_GALLDOC(void)=0;
   virtual void set_DocAllPR_HOT_GALLDOC(TFIBSmallIntField * DocAllPR_HOT_GALLDOC)=0;

   __property TFIBBCDField * DocAllSUM_HOT_GALLDOC = {read = get_DocAllSUM_HOT_GALLDOC , write = set_DocAllSUM_HOT_GALLDOC};
   virtual TFIBBCDField * get_DocAllSUM_HOT_GALLDOC(void)=0;
   virtual void set_DocAllSUM_HOT_GALLDOC(TFIBBCDField * DocAllSUM_HOT_GALLDOC)=0;

   __property TFIBIntegerField * DocAllNUMBER_HOT_GALLDOC = {read = get_DocAllNUMBER_HOT_GALLDOC , write = set_DocAllNUMBER_HOT_GALLDOC};
   virtual TFIBIntegerField * get_DocAllNUMBER_HOT_GALLDOC(void)=0;
   virtual void set_DocAllNUMBER_HOT_GALLDOC(TFIBIntegerField * DocAllNUMBER_HOT_GALLDOC)=0;

   __property TpFIBQuery * QueryDvReg = {read = get_QueryDvReg , write = set_QueryDvReg};
   virtual TpFIBQuery * get_QueryDvReg(void)=0;
   virtual void set_QueryDvReg(TpFIBQuery * QueryDvReg)=0;

   __property TpFIBQuery * QueryCancelDvReg = {read = get_QueryCancelDvReg , write = set_QueryCancelDvReg};
   virtual TpFIBQuery * get_QueryCancelDvReg(void)=0;
   virtual void set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)=0;

   __property TpFIBDataSet * DocT = {read = get_DocT , write = set_DocT};
   virtual TpFIBDataSet * get_DocT(void)=0;
   virtual void set_DocT(TpFIBDataSet * DocT)=0;

   __property TDataSource * DataSourceDocT = {read = get_DataSourceDocT , write = set_DataSourceDocT};
   virtual TDataSource * get_DataSourceDocT(void)=0;
   virtual void set_DataSourceDocT(TDataSource * DataSourceDocT)=0;

   __property TFIBWideStringField * DocAllTDOC_HOT_GALLDOC = {read = get_DocAllTDOC_HOT_GALLDOC , write = set_DocAllTDOC_HOT_GALLDOC};
   virtual TFIBWideStringField * get_DocAllTDOC_HOT_GALLDOC(void)=0;
   virtual void set_DocAllTDOC_HOT_GALLDOC(TFIBWideStringField * DocAllTDOC_HOT_GALLDOC)=0;

   __property TFIBWideStringField * DocAllFNAME_USER = {read = get_DocAllFNAME_USER , write = set_DocAllFNAME_USER};
   virtual TFIBWideStringField * get_DocAllFNAME_USER(void)=0;
   virtual void set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)=0;

   __property TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN = {read = get_DocAllNAME_SINFBASE_OBMEN , write = set_DocAllNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_DocAllNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * DocAllNAMEFIRM = {read = get_DocAllNAMEFIRM , write = set_DocAllNAMEFIRM};
   virtual TFIBWideStringField * get_DocAllNAMEFIRM(void)=0;
   virtual void set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)=0;

   __property TFIBWideStringField * DocAllNAMEKLIENT = {read = get_DocAllNAMEKLIENT , write = set_DocAllNAMEKLIENT};
   virtual TFIBWideStringField * get_DocAllNAMEKLIENT(void)=0;
   virtual void set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)=0;

   __property TFIBWideStringField * DocDESCR_HOT_DRASM = {read = get_DocDESCR_HOT_DRASM , write = set_DocDESCR_HOT_DRASM};
   virtual TFIBWideStringField * get_DocDESCR_HOT_DRASM(void)=0;
   virtual void set_DocDESCR_HOT_DRASM(TFIBWideStringField * DocDESCR_HOT_DRASM)=0;

   __property TFIBWideStringField * DocORG_HOT_DRASM = {read = get_DocORG_HOT_DRASM , write = set_DocORG_HOT_DRASM};
   virtual TFIBWideStringField * get_DocORG_HOT_DRASM(void)=0;
   virtual void set_DocORG_HOT_DRASM(TFIBWideStringField * DocORG_HOT_DRASM)=0;

   __property TFIBWideStringField * DocNAME_HOT_SCELPR = {read = get_DocNAME_HOT_SCELPR , write = set_DocNAME_HOT_SCELPR};
   virtual TFIBWideStringField * get_DocNAME_HOT_SCELPR(void)=0;
   virtual void set_DocNAME_HOT_SCELPR(TFIBWideStringField * DocNAME_HOT_SCELPR)=0;

   __property TFIBWideStringField * DocTBR_NAME_HOT_SNF = {read = get_DocTBR_NAME_HOT_SNF , write = set_DocTBR_NAME_HOT_SNF};
   virtual TFIBWideStringField * get_DocTBR_NAME_HOT_SNF(void)=0;
   virtual void set_DocTBR_NAME_HOT_SNF(TFIBWideStringField * DocTBR_NAME_HOT_SNF)=0;

   __property TFIBWideStringField * DocTBR_NAME_HOT_SCATNOM = {read = get_DocTBR_NAME_HOT_SCATNOM , write = set_DocTBR_NAME_HOT_SCATNOM};
   virtual TFIBWideStringField * get_DocTBR_NAME_HOT_SCATNOM(void)=0;
   virtual void set_DocTBR_NAME_HOT_SCATNOM(TFIBWideStringField * DocTBR_NAME_HOT_SCATNOM)=0;

   __property TFIBWideStringField * DocTBR_NAME_HOT_STYPEPOS = {read = get_DocTBR_NAME_HOT_STYPEPOS , write = set_DocTBR_NAME_HOT_STYPEPOS};
   virtual TFIBWideStringField * get_DocTBR_NAME_HOT_STYPEPOS(void)=0;
   virtual void set_DocTBR_NAME_HOT_STYPEPOS(TFIBWideStringField * DocTBR_NAME_HOT_STYPEPOS)=0;

   __property TFIBWideStringField * DocTBR_NAMEGUEST = {read = get_DocTBR_NAMEGUEST , write = set_DocTBR_NAMEGUEST};
   virtual TFIBWideStringField * get_DocTBR_NAMEGUEST(void)=0;
   virtual void set_DocTBR_NAMEGUEST(TFIBWideStringField * DocTBR_NAMEGUEST)=0;

   __property TFIBWideStringField * DocTBR_NAME_HOT_SSOSTNOM = {read = get_DocTBR_NAME_HOT_SSOSTNOM , write = set_DocTBR_NAME_HOT_SSOSTNOM};
   virtual TFIBWideStringField * get_DocTBR_NAME_HOT_SSOSTNOM(void)=0;
   virtual void set_DocTBR_NAME_HOT_SSOSTNOM(TFIBWideStringField * DocTBR_NAME_HOT_SSOSTNOM)=0;

   __property TFIBDateTimeField * DocTBR_POSNACH_HOT_SOSTNF = {read = get_DocTBR_POSNACH_HOT_SOSTNF , write = set_DocTBR_POSNACH_HOT_SOSTNF};
   virtual TFIBDateTimeField * get_DocTBR_POSNACH_HOT_SOSTNF(void)=0;
   virtual void set_DocTBR_POSNACH_HOT_SOSTNF(TFIBDateTimeField * DocTBR_POSNACH_HOT_SOSTNF)=0;

   __property TFIBDateTimeField * DocTBR_POSCON_HOT_SOSTNF = {read = get_DocTBR_POSCON_HOT_SOSTNF , write = set_DocTBR_POSCON_HOT_SOSTNF};
   virtual TFIBDateTimeField * get_DocTBR_POSCON_HOT_SOSTNF(void)=0;
   virtual void set_DocTBR_POSCON_HOT_SOSTNF(TFIBDateTimeField * DocTBR_POSCON_HOT_SOSTNF)=0;

   __property TFIBIntegerField * DocTBR_KOLM_HOT_SOSTNF = {read = get_DocTBR_KOLM_HOT_SOSTNF , write = set_DocTBR_KOLM_HOT_SOSTNF};
   virtual TFIBIntegerField * get_DocTBR_KOLM_HOT_SOSTNF(void)=0;
   virtual void set_DocTBR_KOLM_HOT_SOSTNF(TFIBIntegerField * DocTBR_KOLM_HOT_SOSTNF)=0;

   __property TFIBWideStringField * DocTRASM_NAME_HOT_SNF = {read = get_DocTRASM_NAME_HOT_SNF , write = set_DocTRASM_NAME_HOT_SNF};
   virtual TFIBWideStringField * get_DocTRASM_NAME_HOT_SNF(void)=0;
   virtual void set_DocTRASM_NAME_HOT_SNF(TFIBWideStringField * DocTRASM_NAME_HOT_SNF)=0;

   __property TFIBWideStringField * DocTRASM_NAME_HOT_SCATNOM = {read = get_DocTRASM_NAME_HOT_SCATNOM , write = set_DocTRASM_NAME_HOT_SCATNOM};
   virtual TFIBWideStringField * get_DocTRASM_NAME_HOT_SCATNOM(void)=0;
   virtual void set_DocTRASM_NAME_HOT_SCATNOM(TFIBWideStringField * DocTRASM_NAME_HOT_SCATNOM)=0;

   __property TFIBWideStringField * DocTRASM_NAME_HOT_STYPEPOS = {read = get_DocTRASM_NAME_HOT_STYPEPOS , write = set_DocTRASM_NAME_HOT_STYPEPOS};
   virtual TFIBWideStringField * get_DocTRASM_NAME_HOT_STYPEPOS(void)=0;
   virtual void set_DocTRASM_NAME_HOT_STYPEPOS(TFIBWideStringField * DocTRASM_NAME_HOT_STYPEPOS)=0;

   __property TFIBWideStringField * DocTRASM_NAMEGUEST = {read = get_DocTRASM_NAMEGUEST , write = set_DocTRASM_NAMEGUEST};
   virtual TFIBWideStringField * get_DocTRASM_NAMEGUEST(void)=0;
   virtual void set_DocTRASM_NAMEGUEST(TFIBWideStringField * DocTRASM_NAMEGUEST)=0;

   __property TFIBWideStringField * DocTRASM_NAME_HOT_SSOSTNOM = {read = get_DocTRASM_NAME_HOT_SSOSTNOM , write = set_DocTRASM_NAME_HOT_SSOSTNOM};
   virtual TFIBWideStringField * get_DocTRASM_NAME_HOT_SSOSTNOM(void)=0;
   virtual void set_DocTRASM_NAME_HOT_SSOSTNOM(TFIBWideStringField * DocTRASM_NAME_HOT_SSOSTNOM)=0;

   __property TFIBDateTimeField * DocTRASM_POSNACH_HOT_SOSTNF = {read = get_DocTRASM_POSNACH_HOT_SOSTNF , write = set_DocTRASM_POSNACH_HOT_SOSTNF};
   virtual TFIBDateTimeField * get_DocTRASM_POSNACH_HOT_SOSTNF(void)=0;
   virtual void set_DocTRASM_POSNACH_HOT_SOSTNF(TFIBDateTimeField * DocTRASM_POSNACH_HOT_SOSTNF)=0;

   __property TFIBDateTimeField * DocTRASM_POSCON_HOT_SOSTNF = {read = get_DocTRASM_POSCON_HOT_SOSTNF , write = set_DocTRASM_POSCON_HOT_SOSTNF};
   virtual TFIBDateTimeField * get_DocTRASM_POSCON_HOT_SOSTNF(void)=0;
   virtual void set_DocTRASM_POSCON_HOT_SOSTNF(TFIBDateTimeField * DocTRASM_POSCON_HOT_SOSTNF)=0;

   __property TFIBIntegerField * DocTRASM_KOLM_HOT_SOSTNF = {read = get_DocTRASM_KOLM_HOT_SOSTNF , write = set_DocTRASM_KOLM_HOT_SOSTNF};
   virtual TFIBIntegerField * get_DocTRASM_KOLM_HOT_SOSTNF(void)=0;
   virtual void set_DocTRASM_KOLM_HOT_SOSTNF(TFIBIntegerField * DocTRASM_KOLM_HOT_SOSTNF)=0;

   __property TFIBWideStringField * DocTBR2_NAME_HOT_SNF = {read = get_DocTBR2_NAME_HOT_SNF , write = set_DocTBR2_NAME_HOT_SNF};
   virtual TFIBWideStringField * get_DocTBR2_NAME_HOT_SNF(void)=0;
   virtual void set_DocTBR2_NAME_HOT_SNF(TFIBWideStringField * DocTBR2_NAME_HOT_SNF)=0;

   __property TFIBWideStringField * DocTBR2_NAME_HOT_SCATNOM = {read = get_DocTBR2_NAME_HOT_SCATNOM , write = set_DocTBR2_NAME_HOT_SCATNOM};
   virtual TFIBWideStringField * get_DocTBR2_NAME_HOT_SCATNOM(void)=0;
   virtual void set_DocTBR2_NAME_HOT_SCATNOM(TFIBWideStringField * DocTBR2_NAME_HOT_SCATNOM)=0;

   __property TFIBWideStringField * DocTBR2_NAME_HOT_STYPEPOS = {read = get_DocTBR2_NAME_HOT_STYPEPOS , write = set_DocTBR2_NAME_HOT_STYPEPOS};
   virtual TFIBWideStringField * get_DocTBR2_NAME_HOT_STYPEPOS(void)=0;
   virtual void set_DocTBR2_NAME_HOT_STYPEPOS(TFIBWideStringField * DocTBR2_NAME_HOT_STYPEPOS)=0;

   __property TFIBWideStringField * DocTBR2_NAMEGUEST = {read = get_DocTBR2_NAMEGUEST , write = set_DocTBR2_NAMEGUEST};
   virtual TFIBWideStringField * get_DocTBR2_NAMEGUEST(void)=0;
   virtual void set_DocTBR2_NAMEGUEST(TFIBWideStringField * DocTBR2_NAMEGUEST)=0;

   __property TFIBWideStringField * DocTBR2_NAME_HOT_SSOSTNOM = {read = get_DocTBR2_NAME_HOT_SSOSTNOM , write = set_DocTBR2_NAME_HOT_SSOSTNOM};
   virtual TFIBWideStringField * get_DocTBR2_NAME_HOT_SSOSTNOM(void)=0;
   virtual void set_DocTBR2_NAME_HOT_SSOSTNOM(TFIBWideStringField * DocTBR2_NAME_HOT_SSOSTNOM)=0;

   __property TFIBDateTimeField * DocTBR2_POSNACH_HOT_SOSTNF = {read = get_DocTBR2_POSNACH_HOT_SOSTNF , write = set_DocTBR2_POSNACH_HOT_SOSTNF};
   virtual TFIBDateTimeField * get_DocTBR2_POSNACH_HOT_SOSTNF(void)=0;
   virtual void set_DocTBR2_POSNACH_HOT_SOSTNF(TFIBDateTimeField * DocTBR2_POSNACH_HOT_SOSTNF)=0;

   __property TFIBDateTimeField * DocTBR2_POSCON_HOT_SOSTNF = {read = get_DocTBR2_POSCON_HOT_SOSTNF , write = set_DocTBR2_POSCON_HOT_SOSTNF};
   virtual TFIBDateTimeField * get_DocTBR2_POSCON_HOT_SOSTNF(void)=0;
   virtual void set_DocTBR2_POSCON_HOT_SOSTNF(TFIBDateTimeField * DocTBR2_POSCON_HOT_SOSTNF)=0;

   __property TFIBIntegerField * DocTBR2_KOLM_HOT_SOSTNF = {read = get_DocTBR2_KOLM_HOT_SOSTNF , write = set_DocTBR2_KOLM_HOT_SOSTNF};
   virtual TFIBIntegerField * get_DocTBR2_KOLM_HOT_SOSTNF(void)=0;
   virtual void set_DocTBR2_KOLM_HOT_SOSTNF(TFIBIntegerField * DocTBR2_KOLM_HOT_SOSTNF)=0;

   __property TStringField * DocTBR = {read = get_DocTBR , write = set_DocTBR};
   virtual TStringField * get_DocTBR(void)=0;
   virtual void set_DocTBR(TStringField * DocTBR)=0;

   __property TStringField * DocTRASM = {read = get_DocTRASM , write = set_DocTRASM};
   virtual TStringField * get_DocTRASM(void)=0;
   virtual void set_DocTRASM(TStringField * DocTRASM)=0;

   __property TStringField * DocTBR2 = {read = get_DocTBR2 , write = set_DocTBR2};
   virtual TStringField * get_DocTBR2(void)=0;
   virtual void set_DocTBR2(TStringField * DocTBR2)=0;

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

   __property TFIBLargeIntField * DocAllIDBASE_HOT_GALLDOC = {read = get_DocAllIDBASE_HOT_GALLDOC , write = set_DocAllIDBASE_HOT_GALLDOC};
   virtual TFIBLargeIntField * get_DocAllIDBASE_HOT_GALLDOC(void)=0;
   virtual void set_DocAllIDBASE_HOT_GALLDOC(TFIBLargeIntField * DocAllIDBASE_HOT_GALLDOC)=0;

   __property TFIBLargeIntField * DocID_HOT_DRASM = {read = get_DocID_HOT_DRASM , write = set_DocID_HOT_DRASM};
   virtual TFIBLargeIntField * get_DocID_HOT_DRASM(void)=0;
   virtual void set_DocID_HOT_DRASM(TFIBLargeIntField * DocID_HOT_DRASM)=0;

   __property TFIBLargeIntField * DocIDDOCH_HOT_DRASM = {read = get_DocIDDOCH_HOT_DRASM , write = set_DocIDDOCH_HOT_DRASM};
   virtual TFIBLargeIntField * get_DocIDDOCH_HOT_DRASM(void)=0;
   virtual void set_DocIDDOCH_HOT_DRASM(TFIBLargeIntField * DocIDDOCH_HOT_DRASM)=0;

   __property TFIBLargeIntField * DocIDCELPR_HOT_DRASM = {read = get_DocIDCELPR_HOT_DRASM , write = set_DocIDCELPR_HOT_DRASM};
   virtual TFIBLargeIntField * get_DocIDCELPR_HOT_DRASM(void)=0;
   virtual void set_DocIDCELPR_HOT_DRASM(TFIBLargeIntField * DocIDCELPR_HOT_DRASM)=0;

   __property TFIBLargeIntField * DocIDBASE_HOT_DRASM = {read = get_DocIDBASE_HOT_DRASM , write = set_DocIDBASE_HOT_DRASM};
   virtual TFIBLargeIntField * get_DocIDBASE_HOT_DRASM(void)=0;
   virtual void set_DocIDBASE_HOT_DRASM(TFIBLargeIntField * DocIDBASE_HOT_DRASM)=0;

   __property TFIBLargeIntField * DocIDTPRICE_HOT_DRASM = {read = get_DocIDTPRICE_HOT_DRASM , write = set_DocIDTPRICE_HOT_DRASM};
   virtual TFIBLargeIntField * get_DocIDTPRICE_HOT_DRASM(void)=0;
   virtual void set_DocIDTPRICE_HOT_DRASM(TFIBLargeIntField * DocIDTPRICE_HOT_DRASM)=0;

   __property TFIBLargeIntField * DocTID_HOT_DRASMT = {read = get_DocTID_HOT_DRASMT , write = set_DocTID_HOT_DRASMT};
   virtual TFIBLargeIntField * get_DocTID_HOT_DRASMT(void)=0;
   virtual void set_DocTID_HOT_DRASMT(TFIBLargeIntField * DocTID_HOT_DRASMT)=0;

   __property TFIBLargeIntField * DocTIDDOCH_HOT_DRASMT = {read = get_DocTIDDOCH_HOT_DRASMT , write = set_DocTIDDOCH_HOT_DRASMT};
   virtual TFIBLargeIntField * get_DocTIDDOCH_HOT_DRASMT(void)=0;
   virtual void set_DocTIDDOCH_HOT_DRASMT(TFIBLargeIntField * DocTIDDOCH_HOT_DRASMT)=0;

   __property TFIBLargeIntField * DocTIDSOSTBR_HOT_DRASMT = {read = get_DocTIDSOSTBR_HOT_DRASMT , write = set_DocTIDSOSTBR_HOT_DRASMT};
   virtual TFIBLargeIntField * get_DocTIDSOSTBR_HOT_DRASMT(void)=0;
   virtual void set_DocTIDSOSTBR_HOT_DRASMT(TFIBLargeIntField * DocTIDSOSTBR_HOT_DRASMT)=0;

   __property TFIBLargeIntField * DocTIDSOSTRASM_HOT_DRASMT = {read = get_DocTIDSOSTRASM_HOT_DRASMT , write = set_DocTIDSOSTRASM_HOT_DRASMT};
   virtual TFIBLargeIntField * get_DocTIDSOSTRASM_HOT_DRASMT(void)=0;
   virtual void set_DocTIDSOSTRASM_HOT_DRASMT(TFIBLargeIntField * DocTIDSOSTRASM_HOT_DRASMT)=0;

   __property TFIBLargeIntField * DocTIDSOSTBR2_HOT_DRASMT = {read = get_DocTIDSOSTBR2_HOT_DRASMT , write = set_DocTIDSOSTBR2_HOT_DRASMT};
   virtual TFIBLargeIntField * get_DocTIDSOSTBR2_HOT_DRASMT(void)=0;
   virtual void set_DocTIDSOSTBR2_HOT_DRASMT(TFIBLargeIntField * DocTIDSOSTBR2_HOT_DRASMT)=0;

   __property TFIBLargeIntField * DocTIDBASE_HOT_DRASMT = {read = get_DocTIDBASE_HOT_DRASMT , write = set_DocTIDBASE_HOT_DRASMT};
   virtual TFIBLargeIntField * get_DocTIDBASE_HOT_DRASMT(void)=0;
   virtual void set_DocTIDBASE_HOT_DRASMT(TFIBLargeIntField * DocTIDBASE_HOT_DRASMT)=0;

   __property TFIBLargeIntField * DocTRASM_ID_HOT_SNF = {read = get_DocTRASM_ID_HOT_SNF , write = set_DocTRASM_ID_HOT_SNF};
   virtual TFIBLargeIntField * get_DocTRASM_ID_HOT_SNF(void)=0;
   virtual void set_DocTRASM_ID_HOT_SNF(TFIBLargeIntField * DocTRASM_ID_HOT_SNF)=0;

   __property TFIBLargeIntField * DocTRASM_ID_HOT_SCATNOM = {read = get_DocTRASM_ID_HOT_SCATNOM , write = set_DocTRASM_ID_HOT_SCATNOM};
   virtual TFIBLargeIntField * get_DocTRASM_ID_HOT_SCATNOM(void)=0;
   virtual void set_DocTRASM_ID_HOT_SCATNOM(TFIBLargeIntField * DocTRASM_ID_HOT_SCATNOM)=0;

   __property TFIBLargeIntField * DocTRASM_ID_HOT_STYPEPOS = {read = get_DocTRASM_ID_HOT_STYPEPOS , write = set_DocTRASM_ID_HOT_STYPEPOS};
   virtual TFIBLargeIntField * get_DocTRASM_ID_HOT_STYPEPOS(void)=0;
   virtual void set_DocTRASM_ID_HOT_STYPEPOS(TFIBLargeIntField * DocTRASM_ID_HOT_STYPEPOS)=0;

   __property TFIBLargeIntField * DocTRASM_IDGUEST = {read = get_DocTRASM_IDGUEST , write = set_DocTRASM_IDGUEST};
   virtual TFIBLargeIntField * get_DocTRASM_IDGUEST(void)=0;
   virtual void set_DocTRASM_IDGUEST(TFIBLargeIntField * DocTRASM_IDGUEST)=0;

   __property TFIBLargeIntField * DocTRASM_ID_HOT_SSOSTNOM = {read = get_DocTRASM_ID_HOT_SSOSTNOM , write = set_DocTRASM_ID_HOT_SSOSTNOM};
   virtual TFIBLargeIntField * get_DocTRASM_ID_HOT_SSOSTNOM(void)=0;
   virtual void set_DocTRASM_ID_HOT_SSOSTNOM(TFIBLargeIntField * DocTRASM_ID_HOT_SSOSTNOM)=0;

   __property TFIBLargeIntField * DocTBR2_ID_HOT_SNF = {read = get_DocTBR2_ID_HOT_SNF , write = set_DocTBR2_ID_HOT_SNF};
   virtual TFIBLargeIntField * get_DocTBR2_ID_HOT_SNF(void)=0;
   virtual void set_DocTBR2_ID_HOT_SNF(TFIBLargeIntField * DocTBR2_ID_HOT_SNF)=0;

   __property TFIBLargeIntField * DocTBR2_ID_HOT_SCATNOM = {read = get_DocTBR2_ID_HOT_SCATNOM , write = set_DocTBR2_ID_HOT_SCATNOM};
   virtual TFIBLargeIntField * get_DocTBR2_ID_HOT_SCATNOM(void)=0;
   virtual void set_DocTBR2_ID_HOT_SCATNOM(TFIBLargeIntField * DocTBR2_ID_HOT_SCATNOM)=0;

   __property TFIBLargeIntField * DocTBR2_ID_HOT_STYPEPOS = {read = get_DocTBR2_ID_HOT_STYPEPOS , write = set_DocTBR2_ID_HOT_STYPEPOS};
   virtual TFIBLargeIntField * get_DocTBR2_ID_HOT_STYPEPOS(void)=0;
   virtual void set_DocTBR2_ID_HOT_STYPEPOS(TFIBLargeIntField * DocTBR2_ID_HOT_STYPEPOS)=0;

   __property TFIBLargeIntField * DocTBR2_IDGUEST = {read = get_DocTBR2_IDGUEST , write = set_DocTBR2_IDGUEST};
   virtual TFIBLargeIntField * get_DocTBR2_IDGUEST(void)=0;
   virtual void set_DocTBR2_IDGUEST(TFIBLargeIntField * DocTBR2_IDGUEST)=0;

   __property TFIBLargeIntField * DocTBR2_ID_HOT_SSOSTNOM = {read = get_DocTBR2_ID_HOT_SSOSTNOM , write = set_DocTBR2_ID_HOT_SSOSTNOM};
   virtual TFIBLargeIntField * get_DocTBR2_ID_HOT_SSOSTNOM(void)=0;
   virtual void set_DocTBR2_ID_HOT_SSOSTNOM(TFIBLargeIntField * DocTBR2_ID_HOT_SSOSTNOM)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   virtual void NewDoc(void)=0;
   virtual void OpenDoc(__int64 IdDoc)=0;
   virtual bool SaveDoc(void)=0;
   virtual bool DvRegDoc(void)=0;
   virtual bool CancelDvRegDoc(void)=0;
   virtual void CloseDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual void AddString(void)=0;
   virtual void DeleteString(void)=0;
};
#define IID_IHOT_DMDocRasm __uuidof(IHOT_DMDocRasm)
#endif
