#ifndef UIDMGurDocCheckKKMH
#define UIDMGurDocCheckKKMH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMGurDocCheckKKM)) IDMGurDocCheckKKM : public IMainInterface
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

   __property TFIBLargeIntField * TableIDDOC = {read = get_TableIDDOC , write = set_TableIDDOC};
   virtual TFIBLargeIntField * get_TableIDDOC(void)=0;
   virtual void set_TableIDDOC(TFIBLargeIntField * TableIDDOC)=0;

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

   __property TFIBBCDField * TableOPLNALCHK = {read = get_TableOPLNALCHK , write = set_TableOPLNALCHK};
   virtual TFIBBCDField * get_TableOPLNALCHK(void)=0;
   virtual void set_TableOPLNALCHK(TFIBBCDField * TableOPLNALCHK)=0;

   __property TFIBBCDField * TableOPLPCCHK = {read = get_TableOPLPCCHK , write = set_TableOPLPCCHK};
   virtual TFIBBCDField * get_TableOPLPCCHK(void)=0;
   virtual void set_TableOPLPCCHK(TFIBBCDField * TableOPLPCCHK)=0;

   __property TFIBBCDField * TableOPLPLATCARD_ALL_DCHK = {read = get_TableOPLPLATCARD_ALL_DCHK , write = set_TableOPLPLATCARD_ALL_DCHK};
   virtual TFIBBCDField * get_TableOPLPLATCARD_ALL_DCHK(void)=0;
   virtual void set_TableOPLPLATCARD_ALL_DCHK(TFIBBCDField * TableOPLPLATCARD_ALL_DCHK)=0;

   __property TFIBBCDField * TableOPLCREDITCARD_ALL_DCHK = {read = get_TableOPLCREDITCARD_ALL_DCHK , write = set_TableOPLCREDITCARD_ALL_DCHK};
   virtual TFIBBCDField * get_TableOPLCREDITCARD_ALL_DCHK(void)=0;
   virtual void set_TableOPLCREDITCARD_ALL_DCHK(TFIBBCDField * TableOPLCREDITCARD_ALL_DCHK)=0;

   __property TFIBBCDField * TableOPL_OTHER_DCHK = {read = get_TableOPL_OTHER_DCHK , write = set_TableOPL_OTHER_DCHK};
   virtual TFIBBCDField * get_TableOPL_OTHER_DCHK(void)=0;
   virtual void set_TableOPL_OTHER_DCHK(TFIBBCDField * TableOPL_OTHER_DCHK)=0;

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

   virtual void OpenTable()=0;
   virtual void UpdateTable(void)=0;
};
#define IID_IDMGurDocCheckKKM __uuidof(IDMGurDocCheckKKM)
#endif
