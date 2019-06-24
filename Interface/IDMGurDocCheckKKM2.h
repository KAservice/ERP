#ifndef UIDMGurDocCheckKKM2H
#define UIDMGurDocCheckKKM2H
#include "IMainInterface.h"
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{E8687925-6526-480F-8777-F9568420A1A7}")) IDMGurDocCheckKKM2 : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

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

   __property TFIBIntegerField * TableNCHECKCHK = {read = get_TableNCHECKCHK , write = set_TableNCHECKCHK};
   virtual TFIBIntegerField * get_TableNCHECKCHK(void)=0;
   virtual void set_TableNCHECKCHK(TFIBIntegerField * TableNCHECKCHK)=0;

   __property TFIBIntegerField * TableNKLCHK = {read = get_TableNKLCHK , write = set_TableNKLCHK};
   virtual TFIBIntegerField * get_TableNKLCHK(void)=0;
   virtual void set_TableNKLCHK(TFIBIntegerField * TableNKLCHK)=0;

   __property TFIBIntegerField * TableOPERCHK = {read = get_TableOPERCHK , write = set_TableOPERCHK};
   virtual TFIBIntegerField * get_TableOPERCHK(void)=0;
   virtual void set_TableOPERCHK(TFIBIntegerField * TableOPERCHK)=0;

   __property TFIBWideStringField * TableNAMEKKM = {read = get_TableNAMEKKM , write = set_TableNAMEKKM};
   virtual TFIBWideStringField * get_TableNAMEKKM(void)=0;
   virtual void set_TableNAMEKKM(TFIBWideStringField * TableNAMEKKM)=0;

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

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property TDateTime PosNach = {read = get_PosNach , write = set_PosNach};
   virtual TDateTime get_PosNach(void)=0;
   virtual void set_PosNach(TDateTime PosNach)=0;

   __property TDateTime PosCon = {read = get_PosCon , write = set_PosCon};
   virtual TDateTime get_PosCon(void)=0;
   virtual void set_PosCon(TDateTime PosCon)=0;

   __property __int64 IdKKM = {read = get_IdKKM , write = set_IdKKM};
   virtual __int64 get_IdKKM(void)=0;
   virtual void set_IdKKM(__int64 IdKKM)=0;

   __property int NumberKL = {read = get_NumberKL , write = set_NumberKL};
   virtual int get_NumberKL(void)=0;
   virtual void set_NumberKL(int NumberKL)=0;

   virtual bool OpenTable(void)=0;
   virtual void UpdateTable(void)=0;
};
#define IID_IDMGurDocCheckKKM2 __uuidof(IDMGurDocCheckKKM2)
#endif
