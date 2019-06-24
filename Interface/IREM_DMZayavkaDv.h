#ifndef UIREM_DMZayavkaDvH
#define UIREM_DMZayavkaDvH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMZayavkaDv)) IREM_DMZayavkaDv : public IMainInterface
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

   __property TFIBLargeIntField * TableID_REM_Z_DV = {read = get_TableID_REM_Z_DV , write = set_TableID_REM_Z_DV};
   virtual TFIBLargeIntField * get_TableID_REM_Z_DV(void)=0;
   virtual void set_TableID_REM_Z_DV(TFIBLargeIntField * TableID_REM_Z_DV)=0;

   __property TFIBWideStringField * TableGID_REM_Z_DV = {read = get_TableGID_REM_Z_DV , write = set_TableGID_REM_Z_DV};
   virtual TFIBWideStringField * get_TableGID_REM_Z_DV(void)=0;
   virtual void set_TableGID_REM_Z_DV(TFIBWideStringField * TableGID_REM_Z_DV)=0;

   __property TFIBDateTimeField * TablePOS_REM_Z_DV = {read = get_TablePOS_REM_Z_DV , write = set_TablePOS_REM_Z_DV};
   virtual TFIBDateTimeField * get_TablePOS_REM_Z_DV(void)=0;
   virtual void set_TablePOS_REM_Z_DV(TFIBDateTimeField * TablePOS_REM_Z_DV)=0;

   __property TFIBLargeIntField * TableIDZ_REM_Z_DV = {read = get_TableIDZ_REM_Z_DV , write = set_TableIDZ_REM_Z_DV};
   virtual TFIBLargeIntField * get_TableIDZ_REM_Z_DV(void)=0;
   virtual void set_TableIDZ_REM_Z_DV(TFIBLargeIntField * TableIDZ_REM_Z_DV)=0;

   __property TFIBSmallIntField * TableOPER_REM_Z_DV = {read = get_TableOPER_REM_Z_DV , write = set_TableOPER_REM_Z_DV};
   virtual TFIBSmallIntField * get_TableOPER_REM_Z_DV(void)=0;
   virtual void set_TableOPER_REM_Z_DV(TFIBSmallIntField * TableOPER_REM_Z_DV)=0;

   __property TFIBLargeIntField * TableIDSOST_REM_Z_DV = {read = get_TableIDSOST_REM_Z_DV , write = set_TableIDSOST_REM_Z_DV};
   virtual TFIBLargeIntField * get_TableIDSOST_REM_Z_DV(void)=0;
   virtual void set_TableIDSOST_REM_Z_DV(TFIBLargeIntField * TableIDSOST_REM_Z_DV)=0;

   __property TFIBLargeIntField * TableIDTREMONT_REM_Z_DV = {read = get_TableIDTREMONT_REM_Z_DV , write = set_TableIDTREMONT_REM_Z_DV};
   virtual TFIBLargeIntField * get_TableIDTREMONT_REM_Z_DV(void)=0;
   virtual void set_TableIDTREMONT_REM_Z_DV(TFIBLargeIntField * TableIDTREMONT_REM_Z_DV)=0;

   __property TFIBLargeIntField * TableIDUSER_REM_Z_DV = {read = get_TableIDUSER_REM_Z_DV , write = set_TableIDUSER_REM_Z_DV};
   virtual TFIBLargeIntField * get_TableIDUSER_REM_Z_DV(void)=0;
   virtual void set_TableIDUSER_REM_Z_DV(TFIBLargeIntField * TableIDUSER_REM_Z_DV)=0;

   __property TFIBBCDField * TableSUM_REM_Z_DV = {read = get_TableSUM_REM_Z_DV , write = set_TableSUM_REM_Z_DV};
   virtual TFIBBCDField * get_TableSUM_REM_Z_DV(void)=0;
   virtual void set_TableSUM_REM_Z_DV(TFIBBCDField * TableSUM_REM_Z_DV)=0;

   __property TFIBDateField * TableSROK_REM_Z_DV = {read = get_TableSROK_REM_Z_DV , write = set_TableSROK_REM_Z_DV};
   virtual TFIBDateField * get_TableSROK_REM_Z_DV(void)=0;
   virtual void set_TableSROK_REM_Z_DV(TFIBDateField * TableSROK_REM_Z_DV)=0;

   __property TFIBSmallIntField * TableOUT_REM_Z_DV = {read = get_TableOUT_REM_Z_DV , write = set_TableOUT_REM_Z_DV};
   virtual TFIBSmallIntField * get_TableOUT_REM_Z_DV(void)=0;
   virtual void set_TableOUT_REM_Z_DV(TFIBSmallIntField * TableOUT_REM_Z_DV)=0;

   __property TFIBLargeIntField * TableIDTECSKL_REM_Z_DV = {read = get_TableIDTECSKL_REM_Z_DV , write = set_TableIDTECSKL_REM_Z_DV};
   virtual TFIBLargeIntField * get_TableIDTECSKL_REM_Z_DV(void)=0;
   virtual void set_TableIDTECSKL_REM_Z_DV(TFIBLargeIntField * TableIDTECSKL_REM_Z_DV)=0;

   __property TFIBLargeIntField * TableIDBASE_REM_Z_DV = {read = get_TableIDBASE_REM_Z_DV , write = set_TableIDBASE_REM_Z_DV};
   virtual TFIBLargeIntField * get_TableIDBASE_REM_Z_DV(void)=0;
   virtual void set_TableIDBASE_REM_Z_DV(TFIBLargeIntField * TableIDBASE_REM_Z_DV)=0;

   __property TFIBWideStringField * TableNAME_STREMONT = {read = get_TableNAME_STREMONT , write = set_TableNAME_STREMONT};
   virtual TFIBWideStringField * get_TableNAME_STREMONT(void)=0;
   virtual void set_TableNAME_STREMONT(TFIBWideStringField * TableNAME_STREMONT)=0;

   __property TFIBWideStringField * TableNAME_REMSSOST = {read = get_TableNAME_REMSSOST , write = set_TableNAME_REMSSOST};
   virtual TFIBWideStringField * get_TableNAME_REMSSOST(void)=0;
   virtual void set_TableNAME_REMSSOST(TFIBWideStringField * TableNAME_REMSSOST)=0;

   __property TFIBWideStringField * TableNAME_SKLAD_TEC = {read = get_TableNAME_SKLAD_TEC , write = set_TableNAME_SKLAD_TEC};
   virtual TFIBWideStringField * get_TableNAME_SKLAD_TEC(void)=0;
   virtual void set_TableNAME_SKLAD_TEC(TFIBWideStringField * TableNAME_SKLAD_TEC)=0;

   __property TFIBWideStringField * TableNAME_USER = {read = get_TableNAME_USER , write = set_TableNAME_USER};
   virtual TFIBWideStringField * get_TableNAME_USER(void)=0;
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)=0;

   __property TFIBLargeIntField * ElementID_REM_Z_DV = {read = get_ElementID_REM_Z_DV , write = set_ElementID_REM_Z_DV};
   virtual TFIBLargeIntField * get_ElementID_REM_Z_DV(void)=0;
   virtual void set_ElementID_REM_Z_DV(TFIBLargeIntField * ElementID_REM_Z_DV)=0;

   __property TFIBWideStringField * ElementGID_REM_Z_DV = {read = get_ElementGID_REM_Z_DV , write = set_ElementGID_REM_Z_DV};
   virtual TFIBWideStringField * get_ElementGID_REM_Z_DV(void)=0;
   virtual void set_ElementGID_REM_Z_DV(TFIBWideStringField * ElementGID_REM_Z_DV)=0;

   __property TFIBDateTimeField * ElementPOS_REM_Z_DV = {read = get_ElementPOS_REM_Z_DV , write = set_ElementPOS_REM_Z_DV};
   virtual TFIBDateTimeField * get_ElementPOS_REM_Z_DV(void)=0;
   virtual void set_ElementPOS_REM_Z_DV(TFIBDateTimeField * ElementPOS_REM_Z_DV)=0;

   __property TFIBLargeIntField * ElementIDZ_REM_Z_DV = {read = get_ElementIDZ_REM_Z_DV , write = set_ElementIDZ_REM_Z_DV};
   virtual TFIBLargeIntField * get_ElementIDZ_REM_Z_DV(void)=0;
   virtual void set_ElementIDZ_REM_Z_DV(TFIBLargeIntField * ElementIDZ_REM_Z_DV)=0;

   __property TFIBSmallIntField * ElementOPER_REM_Z_DV = {read = get_ElementOPER_REM_Z_DV , write = set_ElementOPER_REM_Z_DV};
   virtual TFIBSmallIntField * get_ElementOPER_REM_Z_DV(void)=0;
   virtual void set_ElementOPER_REM_Z_DV(TFIBSmallIntField * ElementOPER_REM_Z_DV)=0;

   __property TFIBLargeIntField * ElementIDSOST_REM_Z_DV = {read = get_ElementIDSOST_REM_Z_DV , write = set_ElementIDSOST_REM_Z_DV};
   virtual TFIBLargeIntField * get_ElementIDSOST_REM_Z_DV(void)=0;
   virtual void set_ElementIDSOST_REM_Z_DV(TFIBLargeIntField * ElementIDSOST_REM_Z_DV)=0;

   __property TFIBLargeIntField * ElementIDTREMONT_REM_Z_DV = {read = get_ElementIDTREMONT_REM_Z_DV , write = set_ElementIDTREMONT_REM_Z_DV};
   virtual TFIBLargeIntField * get_ElementIDTREMONT_REM_Z_DV(void)=0;
   virtual void set_ElementIDTREMONT_REM_Z_DV(TFIBLargeIntField * ElementIDTREMONT_REM_Z_DV)=0;

   __property TFIBLargeIntField * ElementIDUSER_REM_Z_DV = {read = get_ElementIDUSER_REM_Z_DV , write = set_ElementIDUSER_REM_Z_DV};
   virtual TFIBLargeIntField * get_ElementIDUSER_REM_Z_DV(void)=0;
   virtual void set_ElementIDUSER_REM_Z_DV(TFIBLargeIntField * ElementIDUSER_REM_Z_DV)=0;

   __property TFIBBCDField * ElementSUM_REM_Z_DV = {read = get_ElementSUM_REM_Z_DV , write = set_ElementSUM_REM_Z_DV};
   virtual TFIBBCDField * get_ElementSUM_REM_Z_DV(void)=0;
   virtual void set_ElementSUM_REM_Z_DV(TFIBBCDField * ElementSUM_REM_Z_DV)=0;

   __property TFIBDateField * ElementSROK_REM_Z_DV = {read = get_ElementSROK_REM_Z_DV , write = set_ElementSROK_REM_Z_DV};
   virtual TFIBDateField * get_ElementSROK_REM_Z_DV(void)=0;
   virtual void set_ElementSROK_REM_Z_DV(TFIBDateField * ElementSROK_REM_Z_DV)=0;

   __property TFIBSmallIntField * ElementOUT_REM_Z_DV = {read = get_ElementOUT_REM_Z_DV , write = set_ElementOUT_REM_Z_DV};
   virtual TFIBSmallIntField * get_ElementOUT_REM_Z_DV(void)=0;
   virtual void set_ElementOUT_REM_Z_DV(TFIBSmallIntField * ElementOUT_REM_Z_DV)=0;

   __property TFIBLargeIntField * ElementIDTECSKL_REM_Z_DV = {read = get_ElementIDTECSKL_REM_Z_DV , write = set_ElementIDTECSKL_REM_Z_DV};
   virtual TFIBLargeIntField * get_ElementIDTECSKL_REM_Z_DV(void)=0;
   virtual void set_ElementIDTECSKL_REM_Z_DV(TFIBLargeIntField * ElementIDTECSKL_REM_Z_DV)=0;

   __property TFIBLargeIntField * ElementIDBASE_REM_Z_DV = {read = get_ElementIDBASE_REM_Z_DV , write = set_ElementIDBASE_REM_Z_DV};
   virtual TFIBLargeIntField * get_ElementIDBASE_REM_Z_DV(void)=0;
   virtual void set_ElementIDBASE_REM_Z_DV(TFIBLargeIntField * ElementIDBASE_REM_Z_DV)=0;

   __property TFIBWideStringField * ElementNAME_STREMONT = {read = get_ElementNAME_STREMONT , write = set_ElementNAME_STREMONT};
   virtual TFIBWideStringField * get_ElementNAME_STREMONT(void)=0;
   virtual void set_ElementNAME_STREMONT(TFIBWideStringField * ElementNAME_STREMONT)=0;

   __property TFIBWideStringField * ElementNAME_REMSSOST = {read = get_ElementNAME_REMSSOST , write = set_ElementNAME_REMSSOST};
   virtual TFIBWideStringField * get_ElementNAME_REMSSOST(void)=0;
   virtual void set_ElementNAME_REMSSOST(TFIBWideStringField * ElementNAME_REMSSOST)=0;

   __property TFIBWideStringField * ElementNAME_SKLAD_TEC = {read = get_ElementNAME_SKLAD_TEC , write = set_ElementNAME_SKLAD_TEC};
   virtual TFIBWideStringField * get_ElementNAME_SKLAD_TEC(void)=0;
   virtual void set_ElementNAME_SKLAD_TEC(TFIBWideStringField * ElementNAME_SKLAD_TEC)=0;

   __property TFIBWideStringField * ElementNAME_USER = {read = get_ElementNAME_USER , write = set_ElementNAME_USER};
   virtual TFIBWideStringField * get_ElementNAME_USER(void)=0;
   virtual void set_ElementNAME_USER(TFIBWideStringField * ElementNAME_USER)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property __int64 IdZ = {read = get_IdZ , write = set_IdZ};
   virtual __int64 get_IdZ(void)=0;
   virtual void set_IdZ(__int64 IdZ)=0;

   __property __int64 IdBaseZayavki = {read = get_IdBaseZayavki , write = set_IdBaseZayavki};
   virtual __int64 get_IdBaseZayavki(void)=0;
   virtual void set_IdBaseZayavki(__int64 IdBaseZayavki)=0;

   virtual void OpenTable(__int64 id_z)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual bool NewElement(__int64 id_z)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual __int64 GetIDElement(UnicodeString gid)=0;
   virtual UnicodeString GetGIDElement(__int64 id)=0;
   virtual bool AddRecordDv(TDateTime pos,	__int64 id_z,int oper,	__int64 id_sost,__int64 id_type_remont,	__int64 id_user,__int64 id_tec_sklad,double sum,TDate date,int out)=0;
};
#define IID_IREM_DMZayavkaDv __uuidof(IREM_DMZayavkaDv)
#endif
