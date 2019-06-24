#ifndef UIREM_DMSprKKTDvH
#define UIREM_DMSprKKTDvH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{CE5D23E2-4EAA-4038-8F49-3613091A8E09}"))IREM_DMSprKKTDv : public IMainInterface
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

   __property TFIBLargeIntField * TableID_REM_SKKT_DV = {read = get_TableID_REM_SKKT_DV , write = set_TableID_REM_SKKT_DV};
   virtual TFIBLargeIntField * get_TableID_REM_SKKT_DV(void)=0;
   virtual void set_TableID_REM_SKKT_DV(TFIBLargeIntField * TableID_REM_SKKT_DV)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_SKKT_DV = {read = get_TableIDBASE_REM_SKKT_DV , write = set_TableIDBASE_REM_SKKT_DV};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_SKKT_DV(void)=0;
   virtual void set_TableIDBASE_REM_SKKT_DV(TFIBLargeIntField * TableIDBASE_REM_SKKT_DV)=0;

   __property TFIBLargeIntField * TableIDKKT_REM_SKKT_DV = {read = get_TableIDKKT_REM_SKKT_DV , write = set_TableIDKKT_REM_SKKT_DV};
   virtual TFIBLargeIntField * get_TableIDKKT_REM_SKKT_DV(void)=0;
   virtual void set_TableIDKKT_REM_SKKT_DV(TFIBLargeIntField * TableIDKKT_REM_SKKT_DV)=0;

   __property TFIBDateTimeField * TablePOS_REM_SKKT_DV = {read = get_TablePOS_REM_SKKT_DV , write = set_TablePOS_REM_SKKT_DV};
   virtual TFIBDateTimeField * get_TablePOS_REM_SKKT_DV(void)=0;
   virtual void set_TablePOS_REM_SKKT_DV(TFIBDateTimeField * TablePOS_REM_SKKT_DV)=0;

   __property TFIBLargeIntField * TableIDKLIENT_REM_SKKT_DV = {read = get_TableIDKLIENT_REM_SKKT_DV , write = set_TableIDKLIENT_REM_SKKT_DV};
   virtual TFIBLargeIntField * get_TableIDKLIENT_REM_SKKT_DV(void)=0;
   virtual void set_TableIDKLIENT_REM_SKKT_DV(TFIBLargeIntField * TableIDKLIENT_REM_SKKT_DV)=0;

   __property TFIBWideStringField * TableMESTOUST_REM_SKKT_DV = {read = get_TableMESTOUST_REM_SKKT_DV , write = set_TableMESTOUST_REM_SKKT_DV};
   virtual TFIBWideStringField * get_TableMESTOUST_REM_SKKT_DV(void)=0;
   virtual void set_TableMESTOUST_REM_SKKT_DV(TFIBWideStringField * TableMESTOUST_REM_SKKT_DV)=0;

   __property TFIBWideStringField * TableREGNUM_REM_SKKT_DV = {read = get_TableREGNUM_REM_SKKT_DV , write = set_TableREGNUM_REM_SKKT_DV};
   virtual TFIBWideStringField * get_TableREGNUM_REM_SKKT_DV(void)=0;
   virtual void set_TableREGNUM_REM_SKKT_DV(TFIBWideStringField * TableREGNUM_REM_SKKT_DV)=0;

   __property TFIBWideStringField * TableCBKGR_REM_SKKT_DV = {read = get_TableCBKGR_REM_SKKT_DV , write = set_TableCBKGR_REM_SKKT_DV};
   virtual TFIBWideStringField * get_TableCBKGR_REM_SKKT_DV(void)=0;
   virtual void set_TableCBKGR_REM_SKKT_DV(TFIBWideStringField * TableCBKGR_REM_SKKT_DV)=0;

   __property TFIBWideStringField * TableCBKCO_REM_SKKT_DV = {read = get_TableCBKCO_REM_SKKT_DV , write = set_TableCBKCO_REM_SKKT_DV};
   virtual TFIBWideStringField * get_TableCBKCO_REM_SKKT_DV(void)=0;
   virtual void set_TableCBKCO_REM_SKKT_DV(TFIBWideStringField * TableCBKCO_REM_SKKT_DV)=0;

   __property TFIBWideStringField * TableNUMCONTRACT_REM_SKKT_DV = {read = get_TableNUMCONTRACT_REM_SKKT_DV , write = set_TableNUMCONTRACT_REM_SKKT_DV};
   virtual TFIBWideStringField * get_TableNUMCONTRACT_REM_SKKT_DV(void)=0;
   virtual void set_TableNUMCONTRACT_REM_SKKT_DV(TFIBWideStringField * TableNUMCONTRACT_REM_SKKT_DV)=0;

   __property TFIBDateField * TableDATECONTRACT_REM_SKKT_DV = {read = get_TableDATECONTRACT_REM_SKKT_DV , write = set_TableDATECONTRACT_REM_SKKT_DV};
   virtual TFIBDateField * get_TableDATECONTRACT_REM_SKKT_DV(void)=0;
   virtual void set_TableDATECONTRACT_REM_SKKT_DV(TFIBDateField * TableDATECONTRACT_REM_SKKT_DV)=0;

   __property TFIBBCDField * TableSUMCONTRACT_REM_SKKT_DV = {read = get_TableSUMCONTRACT_REM_SKKT_DV , write = set_TableSUMCONTRACT_REM_SKKT_DV};
   virtual TFIBBCDField * get_TableSUMCONTRACT_REM_SKKT_DV(void)=0;
   virtual void set_TableSUMCONTRACT_REM_SKKT_DV(TFIBBCDField * TableSUMCONTRACT_REM_SKKT_DV)=0;

   __property TFIBWideStringField * TableEKLZ_SERNUM_REM_SKKT_DV = {read = get_TableEKLZ_SERNUM_REM_SKKT_DV , write = set_TableEKLZ_SERNUM_REM_SKKT_DV};
   virtual TFIBWideStringField * get_TableEKLZ_SERNUM_REM_SKKT_DV(void)=0;
   virtual void set_TableEKLZ_SERNUM_REM_SKKT_DV(TFIBWideStringField * TableEKLZ_SERNUM_REM_SKKT_DV)=0;

   __property TFIBWideStringField * TableEKLZ_REGNUM_REM_SKKT_DV = {read = get_TableEKLZ_REGNUM_REM_SKKT_DV , write = set_TableEKLZ_REGNUM_REM_SKKT_DV};
   virtual TFIBWideStringField * get_TableEKLZ_REGNUM_REM_SKKT_DV(void)=0;
   virtual void set_TableEKLZ_REGNUM_REM_SKKT_DV(TFIBWideStringField * TableEKLZ_REGNUM_REM_SKKT_DV)=0;

   __property TFIBDateField * TableEKLZ_ACT_REM_SKKT_DV = {read = get_TableEKLZ_ACT_REM_SKKT_DV , write = set_TableEKLZ_ACT_REM_SKKT_DV};
   virtual TFIBDateField * get_TableEKLZ_ACT_REM_SKKT_DV(void)=0;
   virtual void set_TableEKLZ_ACT_REM_SKKT_DV(TFIBDateField * TableEKLZ_ACT_REM_SKKT_DV)=0;

   __property TFIBLargeIntField * TableIDUSER_REM_SKKT_DV = {read = get_TableIDUSER_REM_SKKT_DV , write = set_TableIDUSER_REM_SKKT_DV};
   virtual TFIBLargeIntField * get_TableIDUSER_REM_SKKT_DV(void)=0;
   virtual void set_TableIDUSER_REM_SKKT_DV(TFIBLargeIntField * TableIDUSER_REM_SKKT_DV)=0;

   __property TFIBWideStringField * TableNAMEKLIENT = {read = get_TableNAMEKLIENT , write = set_TableNAMEKLIENT};
   virtual TFIBWideStringField * get_TableNAMEKLIENT(void)=0;
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)=0;

   __property TFIBWideStringField * TableNAME_USER = {read = get_TableNAME_USER , write = set_TableNAME_USER};
   virtual TFIBWideStringField * get_TableNAME_USER(void)=0;
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)=0;

   __property TFIBLargeIntField * ElementID_REM_SKKT_DV = {read = get_ElementID_REM_SKKT_DV , write = set_ElementID_REM_SKKT_DV};
   virtual TFIBLargeIntField * get_ElementID_REM_SKKT_DV(void)=0;
   virtual void set_ElementID_REM_SKKT_DV(TFIBLargeIntField * ElementID_REM_SKKT_DV)=0;

   __property TFIBLargeIntField * ElementIDBASE_REM_SKKT_DV = {read = get_ElementIDBASE_REM_SKKT_DV , write = set_ElementIDBASE_REM_SKKT_DV};
   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SKKT_DV(void)=0;
   virtual void set_ElementIDBASE_REM_SKKT_DV(TFIBLargeIntField * ElementIDBASE_REM_SKKT_DV)=0;

   __property TFIBLargeIntField * ElementIDKKT_REM_SKKT_DV = {read = get_ElementIDKKT_REM_SKKT_DV , write = set_ElementIDKKT_REM_SKKT_DV};
   virtual TFIBLargeIntField * get_ElementIDKKT_REM_SKKT_DV(void)=0;
   virtual void set_ElementIDKKT_REM_SKKT_DV(TFIBLargeIntField * ElementIDKKT_REM_SKKT_DV)=0;

   __property TFIBDateTimeField * ElementPOS_REM_SKKT_DV = {read = get_ElementPOS_REM_SKKT_DV , write = set_ElementPOS_REM_SKKT_DV};
   virtual TFIBDateTimeField * get_ElementPOS_REM_SKKT_DV(void)=0;
   virtual void set_ElementPOS_REM_SKKT_DV(TFIBDateTimeField * ElementPOS_REM_SKKT_DV)=0;

   __property TFIBLargeIntField * ElementIDKLIENT_REM_SKKT_DV = {read = get_ElementIDKLIENT_REM_SKKT_DV , write = set_ElementIDKLIENT_REM_SKKT_DV};
   virtual TFIBLargeIntField * get_ElementIDKLIENT_REM_SKKT_DV(void)=0;
   virtual void set_ElementIDKLIENT_REM_SKKT_DV(TFIBLargeIntField * ElementIDKLIENT_REM_SKKT_DV)=0;

   __property TFIBWideStringField * ElementMESTOUST_REM_SKKT_DV = {read = get_ElementMESTOUST_REM_SKKT_DV , write = set_ElementMESTOUST_REM_SKKT_DV};
   virtual TFIBWideStringField * get_ElementMESTOUST_REM_SKKT_DV(void)=0;
   virtual void set_ElementMESTOUST_REM_SKKT_DV(TFIBWideStringField * ElementMESTOUST_REM_SKKT_DV)=0;

   __property TFIBWideStringField * ElementREGNUM_REM_SKKT_DV = {read = get_ElementREGNUM_REM_SKKT_DV , write = set_ElementREGNUM_REM_SKKT_DV};
   virtual TFIBWideStringField * get_ElementREGNUM_REM_SKKT_DV(void)=0;
   virtual void set_ElementREGNUM_REM_SKKT_DV(TFIBWideStringField * ElementREGNUM_REM_SKKT_DV)=0;

   __property TFIBWideStringField * ElementCBKGR_REM_SKKT_DV = {read = get_ElementCBKGR_REM_SKKT_DV , write = set_ElementCBKGR_REM_SKKT_DV};
   virtual TFIBWideStringField * get_ElementCBKGR_REM_SKKT_DV(void)=0;
   virtual void set_ElementCBKGR_REM_SKKT_DV(TFIBWideStringField * ElementCBKGR_REM_SKKT_DV)=0;

   __property TFIBWideStringField * ElementCBKCO_REM_SKKT_DV = {read = get_ElementCBKCO_REM_SKKT_DV , write = set_ElementCBKCO_REM_SKKT_DV};
   virtual TFIBWideStringField * get_ElementCBKCO_REM_SKKT_DV(void)=0;
   virtual void set_ElementCBKCO_REM_SKKT_DV(TFIBWideStringField * ElementCBKCO_REM_SKKT_DV)=0;

   __property TFIBWideStringField * ElementNUMCONTRACT_REM_SKKT_DV = {read = get_ElementNUMCONTRACT_REM_SKKT_DV , write = set_ElementNUMCONTRACT_REM_SKKT_DV};
   virtual TFIBWideStringField * get_ElementNUMCONTRACT_REM_SKKT_DV(void)=0;
   virtual void set_ElementNUMCONTRACT_REM_SKKT_DV(TFIBWideStringField * ElementNUMCONTRACT_REM_SKKT_DV)=0;

   __property TFIBDateField * ElementDATECONTRACT_REM_SKKT_DV = {read = get_ElementDATECONTRACT_REM_SKKT_DV , write = set_ElementDATECONTRACT_REM_SKKT_DV};
   virtual TFIBDateField * get_ElementDATECONTRACT_REM_SKKT_DV(void)=0;
   virtual void set_ElementDATECONTRACT_REM_SKKT_DV(TFIBDateField * ElementDATECONTRACT_REM_SKKT_DV)=0;

   __property TFIBBCDField * ElementSUMCONTRACT_REM_SKKT_DV = {read = get_ElementSUMCONTRACT_REM_SKKT_DV , write = set_ElementSUMCONTRACT_REM_SKKT_DV};
   virtual TFIBBCDField * get_ElementSUMCONTRACT_REM_SKKT_DV(void)=0;
   virtual void set_ElementSUMCONTRACT_REM_SKKT_DV(TFIBBCDField * ElementSUMCONTRACT_REM_SKKT_DV)=0;

   __property TFIBWideStringField * ElementEKLZ_SERNUM_REM_SKKT_DV = {read = get_ElementEKLZ_SERNUM_REM_SKKT_DV , write = set_ElementEKLZ_SERNUM_REM_SKKT_DV};
   virtual TFIBWideStringField * get_ElementEKLZ_SERNUM_REM_SKKT_DV(void)=0;
   virtual void set_ElementEKLZ_SERNUM_REM_SKKT_DV(TFIBWideStringField * ElementEKLZ_SERNUM_REM_SKKT_DV)=0;

   __property TFIBWideStringField * ElementEKLZ_REGNUM_REM_SKKT_DV = {read = get_ElementEKLZ_REGNUM_REM_SKKT_DV , write = set_ElementEKLZ_REGNUM_REM_SKKT_DV};
   virtual TFIBWideStringField * get_ElementEKLZ_REGNUM_REM_SKKT_DV(void)=0;
   virtual void set_ElementEKLZ_REGNUM_REM_SKKT_DV(TFIBWideStringField * ElementEKLZ_REGNUM_REM_SKKT_DV)=0;

   __property TFIBDateField * ElementEKLZ_ACT_REM_SKKT_DV = {read = get_ElementEKLZ_ACT_REM_SKKT_DV , write = set_ElementEKLZ_ACT_REM_SKKT_DV};
   virtual TFIBDateField * get_ElementEKLZ_ACT_REM_SKKT_DV(void)=0;
   virtual void set_ElementEKLZ_ACT_REM_SKKT_DV(TFIBDateField * ElementEKLZ_ACT_REM_SKKT_DV)=0;

   __property TFIBLargeIntField * ElementIDUSER_REM_SKKT_DV = {read = get_ElementIDUSER_REM_SKKT_DV , write = set_ElementIDUSER_REM_SKKT_DV};
   virtual TFIBLargeIntField * get_ElementIDUSER_REM_SKKT_DV(void)=0;
   virtual void set_ElementIDUSER_REM_SKKT_DV(TFIBLargeIntField * ElementIDUSER_REM_SKKT_DV)=0;

   __property TFIBWideStringField * ElementNAMEKLIENT = {read = get_ElementNAMEKLIENT , write = set_ElementNAMEKLIENT};
   virtual TFIBWideStringField * get_ElementNAMEKLIENT(void)=0;
   virtual void set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)=0;

   __property TFIBWideStringField * ElementNAME_USER = {read = get_ElementNAME_USER , write = set_ElementNAME_USER};
   virtual TFIBWideStringField * get_ElementNAME_USER(void)=0;
   virtual void set_ElementNAME_USER(TFIBWideStringField * ElementNAME_USER)=0;

   __property __int64 IdOwner = {read = get_IdOwner , write = set_IdOwner};
   virtual __int64 get_IdOwner(void)=0;
   virtual void set_IdOwner(__int64 IdOwner)=0;

   virtual void OpenTable(__int64 id_owner)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual bool NewElement(__int64 id_owner)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual bool AddRecordDv(TDateTime pos,__int64 id_owner,__int64 id_klient,UnicodeString mesto_ust,UnicodeString reg_num,UnicodeString svk_gr,UnicodeString svk_so,UnicodeString num_contract,TDate date_contract,double sum_contract,UnicodeString eklz_ser_num,UnicodeString eklz_reg_num,TDate eklz_act,__int64 id_user)=0;
};
#define IID_IREM_DMSprKKTDv __uuidof(IREM_DMSprKKTDv)
#endif
