#ifndef UIREM_DMCustQueryDvH
#define UIREM_DMCustQueryDvH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMCustQueryDv)) IREM_DMCustQueryDv : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBLargeIntField * TableID_REM_CQUERYT_DV = {read = get_TableID_REM_CQUERYT_DV , write = set_TableID_REM_CQUERYT_DV};
   virtual TFIBLargeIntField * get_TableID_REM_CQUERYT_DV(void)=0;
   virtual void set_TableID_REM_CQUERYT_DV(TFIBLargeIntField * TableID_REM_CQUERYT_DV)=0;

   __property TFIBWideStringField * TableGID_REM_CQUERYT_DV = {read = get_TableGID_REM_CQUERYT_DV , write = set_TableGID_REM_CQUERYT_DV};
   virtual TFIBWideStringField * get_TableGID_REM_CQUERYT_DV(void)=0;
   virtual void set_TableGID_REM_CQUERYT_DV(TFIBWideStringField * TableGID_REM_CQUERYT_DV)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_CQUERYT_DV = {read = get_TableIDBASE_REM_CQUERYT_DV , write = set_TableIDBASE_REM_CQUERYT_DV};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_CQUERYT_DV(void)=0;
   virtual void set_TableIDBASE_REM_CQUERYT_DV(TFIBLargeIntField * TableIDBASE_REM_CQUERYT_DV)=0;

   __property TFIBLargeIntField * TableIDCQT_REM_CQUERYT_DV = {read = get_TableIDCQT_REM_CQUERYT_DV , write = set_TableIDCQT_REM_CQUERYT_DV};
   virtual TFIBLargeIntField * get_TableIDCQT_REM_CQUERYT_DV(void)=0;
   virtual void set_TableIDCQT_REM_CQUERYT_DV(TFIBLargeIntField * TableIDCQT_REM_CQUERYT_DV)=0;

   __property TFIBLargeIntField * TableIDUSER_REM_CQUERYT_DV = {read = get_TableIDUSER_REM_CQUERYT_DV , write = set_TableIDUSER_REM_CQUERYT_DV};
   virtual TFIBLargeIntField * get_TableIDUSER_REM_CQUERYT_DV(void)=0;
   virtual void set_TableIDUSER_REM_CQUERYT_DV(TFIBLargeIntField * TableIDUSER_REM_CQUERYT_DV)=0;

   __property TFIBLargeIntField * TableIDSOST_REM_CQUERYT_DV = {read = get_TableIDSOST_REM_CQUERYT_DV , write = set_TableIDSOST_REM_CQUERYT_DV};
   virtual TFIBLargeIntField * get_TableIDSOST_REM_CQUERYT_DV(void)=0;
   virtual void set_TableIDSOST_REM_CQUERYT_DV(TFIBLargeIntField * TableIDSOST_REM_CQUERYT_DV)=0;

   __property TFIBDateTimeField * TablePOS_REM_CQUERYT_DV = {read = get_TablePOS_REM_CQUERYT_DV , write = set_TablePOS_REM_CQUERYT_DV};
   virtual TFIBDateTimeField * get_TablePOS_REM_CQUERYT_DV(void)=0;
   virtual void set_TablePOS_REM_CQUERYT_DV(TFIBDateTimeField * TablePOS_REM_CQUERYT_DV)=0;

   __property TFIBWideStringField * TableNAME_REM_SSOST_CQUERY = {read = get_TableNAME_REM_SSOST_CQUERY , write = set_TableNAME_REM_SSOST_CQUERY};
   virtual TFIBWideStringField * get_TableNAME_REM_SSOST_CQUERY(void)=0;
   virtual void set_TableNAME_REM_SSOST_CQUERY(TFIBWideStringField * TableNAME_REM_SSOST_CQUERY)=0;

   __property TFIBWideStringField * TableNAME_USER = {read = get_TableNAME_USER , write = set_TableNAME_USER};
   virtual TFIBWideStringField * get_TableNAME_USER(void)=0;
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)=0;

   __property TFIBLargeIntField * ElementID_REM_CQUERYT_DV = {read = get_ElementID_REM_CQUERYT_DV , write = set_ElementID_REM_CQUERYT_DV};
   virtual TFIBLargeIntField * get_ElementID_REM_CQUERYT_DV(void)=0;
   virtual void set_ElementID_REM_CQUERYT_DV(TFIBLargeIntField * ElementID_REM_CQUERYT_DV)=0;

   __property TFIBWideStringField * ElementGID_REM_CQUERYT_DV = {read = get_ElementGID_REM_CQUERYT_DV , write = set_ElementGID_REM_CQUERYT_DV};
   virtual TFIBWideStringField * get_ElementGID_REM_CQUERYT_DV(void)=0;
   virtual void set_ElementGID_REM_CQUERYT_DV(TFIBWideStringField * ElementGID_REM_CQUERYT_DV)=0;

   __property TFIBLargeIntField * ElementIDBASE_REM_CQUERYT_DV = {read = get_ElementIDBASE_REM_CQUERYT_DV , write = set_ElementIDBASE_REM_CQUERYT_DV};
   virtual TFIBLargeIntField * get_ElementIDBASE_REM_CQUERYT_DV(void)=0;
   virtual void set_ElementIDBASE_REM_CQUERYT_DV(TFIBLargeIntField * ElementIDBASE_REM_CQUERYT_DV)=0;

   __property TFIBLargeIntField * ElementIDCQT_REM_CQUERYT_DV = {read = get_ElementIDCQT_REM_CQUERYT_DV , write = set_ElementIDCQT_REM_CQUERYT_DV};
   virtual TFIBLargeIntField * get_ElementIDCQT_REM_CQUERYT_DV(void)=0;
   virtual void set_ElementIDCQT_REM_CQUERYT_DV(TFIBLargeIntField * ElementIDCQT_REM_CQUERYT_DV)=0;

   __property TFIBLargeIntField * ElementIDUSER_REM_CQUERYT_DV = {read = get_ElementIDUSER_REM_CQUERYT_DV , write = set_ElementIDUSER_REM_CQUERYT_DV};
   virtual TFIBLargeIntField * get_ElementIDUSER_REM_CQUERYT_DV(void)=0;
   virtual void set_ElementIDUSER_REM_CQUERYT_DV(TFIBLargeIntField * ElementIDUSER_REM_CQUERYT_DV)=0;

   __property TFIBLargeIntField * ElementIDSOST_REM_CQUERYT_DV = {read = get_ElementIDSOST_REM_CQUERYT_DV , write = set_ElementIDSOST_REM_CQUERYT_DV};
   virtual TFIBLargeIntField * get_ElementIDSOST_REM_CQUERYT_DV(void)=0;
   virtual void set_ElementIDSOST_REM_CQUERYT_DV(TFIBLargeIntField * ElementIDSOST_REM_CQUERYT_DV)=0;

   __property TFIBDateTimeField * ElementPOS_REM_CQUERYT_DV = {read = get_ElementPOS_REM_CQUERYT_DV , write = set_ElementPOS_REM_CQUERYT_DV};
   virtual TFIBDateTimeField * get_ElementPOS_REM_CQUERYT_DV(void)=0;
   virtual void set_ElementPOS_REM_CQUERYT_DV(TFIBDateTimeField * ElementPOS_REM_CQUERYT_DV)=0;

   __property TFIBWideStringField * ElementNAME_REM_SSOST_CQUERY = {read = get_ElementNAME_REM_SSOST_CQUERY , write = set_ElementNAME_REM_SSOST_CQUERY};
   virtual TFIBWideStringField * get_ElementNAME_REM_SSOST_CQUERY(void)=0;
   virtual void set_ElementNAME_REM_SSOST_CQUERY(TFIBWideStringField * ElementNAME_REM_SSOST_CQUERY)=0;

   __property TFIBWideStringField * ElementNAME_USER = {read = get_ElementNAME_USER , write = set_ElementNAME_USER};
   virtual TFIBWideStringField * get_ElementNAME_USER(void)=0;
   virtual void set_ElementNAME_USER(TFIBWideStringField * ElementNAME_USER)=0;

   __property TFIBSmallIntField * TableRUN_REM_CQUERY_DV = {read = get_TableRUN_REM_CQUERY_DV , write = set_TableRUN_REM_CQUERY_DV};
   virtual TFIBSmallIntField * get_TableRUN_REM_CQUERY_DV(void)=0;
   virtual void set_TableRUN_REM_CQUERY_DV(TFIBSmallIntField * TableRUN_REM_CQUERY_DV)=0;

   __property TFIBSmallIntField * TableACT_REM_CQUERY_DV = {read = get_TableACT_REM_CQUERY_DV , write = set_TableACT_REM_CQUERY_DV};
   virtual TFIBSmallIntField * get_TableACT_REM_CQUERY_DV(void)=0;
   virtual void set_TableACT_REM_CQUERY_DV(TFIBSmallIntField * TableACT_REM_CQUERY_DV)=0;

   __property TFIBSmallIntField * ElementRUN_REM_CQUERY_DV = {read = get_ElementRUN_REM_CQUERY_DV , write = set_ElementRUN_REM_CQUERY_DV};
   virtual TFIBSmallIntField * get_ElementRUN_REM_CQUERY_DV(void)=0;
   virtual void set_ElementRUN_REM_CQUERY_DV(TFIBSmallIntField * ElementRUN_REM_CQUERY_DV)=0;

   __property TFIBSmallIntField * ElementACT_REM_CQUERY_DV = {read = get_ElementACT_REM_CQUERY_DV , write = set_ElementACT_REM_CQUERY_DV};
   virtual TFIBSmallIntField * get_ElementACT_REM_CQUERY_DV(void)=0;
   virtual void set_ElementACT_REM_CQUERY_DV(TFIBSmallIntField * ElementACT_REM_CQUERY_DV)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property __int64 IdCustQueryT = {read = get_IdCustQueryT , write = set_IdCustQueryT};
   virtual __int64 get_IdCustQueryT(void)=0;
   virtual void set_IdCustQueryT(__int64 IdCustQueryT)=0;

   virtual void OpenTable(__int64 id_cqt)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual bool NewElement(__int64 id_cqt)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual __int64 GetIDElement(UnicodeString gid)=0;
   virtual UnicodeString GetGIDElement(__int64 id)=0;
   virtual bool AddRecordDv(TDateTime pos,	__int64 id_cqt,	__int64 id_sost,__int64 id_user,int act,int run)=0;
};
#define IID_IREM_DMCustQueryDv __uuidof(IREM_DMCustQueryDv)
#endif
