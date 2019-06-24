#ifndef UIDMGurDocPrihNaklH
#define UIDMGurDocPrihNaklH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{98667FC0-5033-4813-84CE-2B4AB74538B1}"))IDMGurDocPrihNakl : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TFIBIntegerField * TableNUMDOC = {read = get_TableNUMDOC , write = set_TableNUMDOC};
   virtual TFIBIntegerField * get_TableNUMDOC(void)=0;
   virtual void set_TableNUMDOC(TFIBIntegerField * TableNUMDOC)=0;

   __property TFIBDateTimeField * TablePOSDOC = {read = get_TablePOSDOC , write = set_TablePOSDOC};
   virtual TFIBDateTimeField * get_TablePOSDOC(void)=0;
   virtual void set_TablePOSDOC(TFIBDateTimeField * TablePOSDOC)=0;

   __property TFIBSmallIntField * TablePRDOC = {read = get_TablePRDOC , write = set_TablePRDOC};
   virtual TFIBSmallIntField * get_TablePRDOC(void)=0;
   virtual void set_TablePRDOC(TFIBSmallIntField * TablePRDOC)=0;

   __property TFIBBCDField * TableSUMDOC = {read = get_TableSUMDOC , write = set_TableSUMDOC};
   virtual TFIBBCDField * get_TableSUMDOC(void)=0;
   virtual void set_TableSUMDOC(TFIBBCDField * TableSUMDOC)=0;

   __property TFIBBCDField * TableIDDOC = {read = get_TableIDDOC , write = set_TableIDDOC};
   virtual TFIBBCDField * get_TableIDDOC(void)=0;
   virtual void set_TableIDDOC(TFIBBCDField * TableIDDOC)=0;

   __property TFIBBCDField * TableRSUM_DPRN = {read = get_TableRSUM_DPRN , write = set_TableRSUM_DPRN};
   virtual TFIBBCDField * get_TableRSUM_DPRN(void)=0;
   virtual void set_TableRSUM_DPRN(TFIBBCDField * TableRSUM_DPRN)=0;

   __property TFIBWideStringField * TableNAMEFIRM = {read = get_TableNAMEFIRM , write = set_TableNAMEFIRM};
   virtual TFIBWideStringField * get_TableNAMEFIRM(void)=0;
   virtual void set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)=0;

   __property TFIBWideStringField * TableNAMESKLAD = {read = get_TableNAMESKLAD , write = set_TableNAMESKLAD};
   virtual TFIBWideStringField * get_TableNAMESKLAD(void)=0;
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)=0;

   __property TFIBWideStringField * TableNAMEKLIENT = {read = get_TableNAMEKLIENT , write = set_TableNAMEKLIENT};
   virtual TFIBWideStringField * get_TableNAMEKLIENT(void)=0;
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)=0;

   __property TFIBWideStringField * TableNAME_USER = {read = get_TableNAME_USER , write = set_TableNAME_USER};
   virtual TFIBWideStringField * get_TableNAME_USER(void)=0;
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)=0;

   __property TFIBWideStringField * TablePRIMDOC = {read = get_TablePRIMDOC , write = set_TablePRIMDOC};
   virtual TFIBWideStringField * get_TablePRIMDOC(void)=0;
   virtual void set_TablePRIMDOC(TFIBWideStringField * TablePRIMDOC)=0;

   __property TFIBWideStringField * TableNUMDOCPOST_DPRN = {read = get_TableNUMDOCPOST_DPRN , write = set_TableNUMDOCPOST_DPRN};
   virtual TFIBWideStringField * get_TableNUMDOCPOST_DPRN(void)=0;
   virtual void set_TableNUMDOCPOST_DPRN(TFIBWideStringField * TableNUMDOCPOST_DPRN)=0;

   __property TFIBDateTimeField * TablePOSDOCPOST_DPRN = {read = get_TablePOSDOCPOST_DPRN , write = set_TablePOSDOCPOST_DPRN};
   virtual TFIBDateTimeField * get_TablePOSDOCPOST_DPRN(void)=0;
   virtual void set_TablePOSDOCPOST_DPRN(TFIBDateTimeField * TablePOSDOCPOST_DPRN)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property TDateTime PosNach = {read = get_PosNach , write = set_PosNach};
   virtual TDateTime get_PosNach(void)=0;
   virtual void set_PosNach(TDateTime PosNach)=0;

   __property TDateTime PosCon = {read = get_PosCon , write = set_PosCon};
   virtual TDateTime get_PosCon(void)=0;
   virtual void set_PosCon(TDateTime PosCon)=0;

   virtual void OpenTable()=0;
   virtual void UpdateTable(void)=0;
};
#define IID_IDMGurDocPrihNakl __uuidof(IDMGurDocPrihNakl)
#endif
