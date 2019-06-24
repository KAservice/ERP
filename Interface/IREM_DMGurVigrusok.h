#ifndef UIREM_DMGurVigrusokH
#define UIREM_DMGurVigrusokH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMGurVigrusok)) IREM_DMGurVigrusok : public IMainInterface
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

   __property TpFIBDataSet * IBQ = {read = get_IBQ , write = set_IBQ};
   virtual TpFIBDataSet * get_IBQ(void)=0;
   virtual void set_IBQ(TpFIBDataSet * IBQ)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBLargeIntField * TableID_REM_GUR_VIGR = {read = get_TableID_REM_GUR_VIGR , write = set_TableID_REM_GUR_VIGR};
   virtual TFIBLargeIntField * get_TableID_REM_GUR_VIGR(void)=0;
   virtual void set_TableID_REM_GUR_VIGR(TFIBLargeIntField * TableID_REM_GUR_VIGR)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_GUR_VIGR = {read = get_TableIDBASE_REM_GUR_VIGR , write = set_TableIDBASE_REM_GUR_VIGR};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_GUR_VIGR(void)=0;
   virtual void set_TableIDBASE_REM_GUR_VIGR(TFIBLargeIntField * TableIDBASE_REM_GUR_VIGR)=0;

   __property TFIBLargeIntField * TableIDUSER_REM_GUR_VIGR = {read = get_TableIDUSER_REM_GUR_VIGR , write = set_TableIDUSER_REM_GUR_VIGR};
   virtual TFIBLargeIntField * get_TableIDUSER_REM_GUR_VIGR(void)=0;
   virtual void set_TableIDUSER_REM_GUR_VIGR(TFIBLargeIntField * TableIDUSER_REM_GUR_VIGR)=0;

   __property TFIBDateTimeField * TablePOS_REM_GUR_VIGR = {read = get_TablePOS_REM_GUR_VIGR , write = set_TablePOS_REM_GUR_VIGR};
   virtual TFIBDateTimeField * get_TablePOS_REM_GUR_VIGR(void)=0;
   virtual void set_TablePOS_REM_GUR_VIGR(TFIBDateTimeField * TablePOS_REM_GUR_VIGR)=0;

   __property TFIBIntegerField * TableNUM_REM_GUR_VIGR = {read = get_TableNUM_REM_GUR_VIGR , write = set_TableNUM_REM_GUR_VIGR};
   virtual TFIBIntegerField * get_TableNUM_REM_GUR_VIGR(void)=0;
   virtual void set_TableNUM_REM_GUR_VIGR(TFIBIntegerField * TableNUM_REM_GUR_VIGR)=0;

   __property TFIBWideStringField * TableGUID_TRANSACTION_REM_GUR_VIGR = {read = get_TableGUID_TRANSACTION_REM_GUR_VIGR , write = set_TableGUID_TRANSACTION_REM_GUR_VIGR};
   virtual TFIBWideStringField * get_TableGUID_TRANSACTION_REM_GUR_VIGR(void)=0;
   virtual void set_TableGUID_TRANSACTION_REM_GUR_VIGR(TFIBWideStringField * TableGUID_TRANSACTION_REM_GUR_VIGR)=0;

   __property TFIBWideStringField * TableCODE_STR_VIGR_REM_GUR_VIGR = {read = get_TableCODE_STR_VIGR_REM_GUR_VIGR , write = set_TableCODE_STR_VIGR_REM_GUR_VIGR};
   virtual TFIBWideStringField * get_TableCODE_STR_VIGR_REM_GUR_VIGR(void)=0;
   virtual void set_TableCODE_STR_VIGR_REM_GUR_VIGR(TFIBWideStringField * TableCODE_STR_VIGR_REM_GUR_VIGR)=0;

   __property TFIBWideStringField * TableGUID_VIGR_REM_GUR_VIGR = {read = get_TableGUID_VIGR_REM_GUR_VIGR , write = set_TableGUID_VIGR_REM_GUR_VIGR};
   virtual TFIBWideStringField * get_TableGUID_VIGR_REM_GUR_VIGR(void)=0;
   virtual void set_TableGUID_VIGR_REM_GUR_VIGR(TFIBWideStringField * TableGUID_VIGR_REM_GUR_VIGR)=0;

   __property TFIBLargeIntField * TableIDKLIENT_REM_GUR_VIGR = {read = get_TableIDKLIENT_REM_GUR_VIGR , write = set_TableIDKLIENT_REM_GUR_VIGR};
   virtual TFIBLargeIntField * get_TableIDKLIENT_REM_GUR_VIGR(void)=0;
   virtual void set_TableIDKLIENT_REM_GUR_VIGR(TFIBLargeIntField * TableIDKLIENT_REM_GUR_VIGR)=0;

   __property TFIBLargeIntField * TableIDPRODUCER_REM_GUR_VIGR = {read = get_TableIDPRODUCER_REM_GUR_VIGR , write = set_TableIDPRODUCER_REM_GUR_VIGR};
   virtual TFIBLargeIntField * get_TableIDPRODUCER_REM_GUR_VIGR(void)=0;
   virtual void set_TableIDPRODUCER_REM_GUR_VIGR(TFIBLargeIntField * TableIDPRODUCER_REM_GUR_VIGR)=0;

   __property TFIBWideStringField * TableNAME_SPRODUCER = {read = get_TableNAME_SPRODUCER , write = set_TableNAME_SPRODUCER};
   virtual TFIBWideStringField * get_TableNAME_SPRODUCER(void)=0;
   virtual void set_TableNAME_SPRODUCER(TFIBWideStringField * TableNAME_SPRODUCER)=0;

   __property TFIBWideStringField * TableNAMEKLIENT = {read = get_TableNAMEKLIENT , write = set_TableNAMEKLIENT};
   virtual TFIBWideStringField * get_TableNAMEKLIENT(void)=0;
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)=0;

   __property TFIBWideStringField * TableNAME_USER = {read = get_TableNAME_USER , write = set_TableNAME_USER};
   virtual TFIBWideStringField * get_TableNAME_USER(void)=0;
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)=0;

   __property TFIBWideStringField * TableNAME_SINFBASE_OBMEN = {read = get_TableNAME_SINFBASE_OBMEN , write = set_TableNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_TableNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN)=0;

   __property TDateTime PosNach = {read = get_PosNach , write = set_PosNach};
   virtual TDateTime get_PosNach(void)=0;
   virtual void set_PosNach(TDateTime PosNach)=0;

   __property TDateTime PosCon = {read = get_PosCon , write = set_PosCon};
   virtual TDateTime get_PosCon(void)=0;
   virtual void set_PosCon(TDateTime PosCon)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property __int64 IdKlient = {read = get_IdKlient , write = set_IdKlient};
   virtual __int64 get_IdKlient(void)=0;
   virtual void set_IdKlient(__int64 IdKlient)=0;

   __property __int64 IdSklad = {read = get_IdSklad , write = set_IdSklad};
   virtual __int64 get_IdSklad(void)=0;
   virtual void set_IdSklad(__int64 IdSklad)=0;

   __property __int64 IdFirm = {read = get_IdFirm , write = set_IdFirm};
   virtual __int64 get_IdFirm(void)=0;
   virtual void set_IdFirm(__int64 IdFirm)=0;

   __property UnicodeString StringTypeDoc = {read = get_StringTypeDoc , write = set_StringTypeDoc};
   virtual UnicodeString get_StringTypeDoc(void)=0;
   virtual void set_StringTypeDoc(UnicodeString StringTypeDoc)=0;

   __property bool OtborVkl = {read = get_OtborVkl , write = set_OtborVkl};
   virtual bool get_OtborVkl(void)=0;
   virtual void set_OtborVkl(bool OtborVkl)=0;

   virtual void OpenTable()=0;
   virtual void UpdateTable(void)=0;
};
#define IID_IREM_DMGurVigrusok __uuidof(IREM_DMGurVigrusok)
#endif
