#ifndef UIDMGurPlatH
#define UIDMGurPlatH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMGurPlat)) IDMGurPlat : public IMainInterface
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

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TpFIBDataSet * IBQ = {read = get_IBQ , write = set_IBQ};
   virtual TpFIBDataSet * get_IBQ(void)=0;
   virtual void set_IBQ(TpFIBDataSet * IBQ)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TpFIBDataSet * GurPlat = {read = get_GurPlat , write = set_GurPlat};
   virtual TpFIBDataSet * get_GurPlat(void)=0;
   virtual void set_GurPlat(TpFIBDataSet * GurPlat)=0;

   __property TFIBLargeIntField * TableID_GURNALPLAT = {read = get_TableID_GURNALPLAT , write = set_TableID_GURNALPLAT};
   virtual TFIBLargeIntField * get_TableID_GURNALPLAT(void)=0;
   virtual void set_TableID_GURNALPLAT(TFIBLargeIntField * TableID_GURNALPLAT)=0;

   __property TFIBWideStringField * TableGID_GURNALPLAT = {read = get_TableGID_GURNALPLAT , write = set_TableGID_GURNALPLAT};
   virtual TFIBWideStringField * get_TableGID_GURNALPLAT(void)=0;
   virtual void set_TableGID_GURNALPLAT(TFIBWideStringField * TableGID_GURNALPLAT)=0;

   __property TFIBWideStringField * TableCODE_GURNALPLAT = {read = get_TableCODE_GURNALPLAT , write = set_TableCODE_GURNALPLAT};
   virtual TFIBWideStringField * get_TableCODE_GURNALPLAT(void)=0;
   virtual void set_TableCODE_GURNALPLAT(TFIBWideStringField * TableCODE_GURNALPLAT)=0;

   __property TFIBWideStringField * TableNUMTEL_GURNALPLAT = {read = get_TableNUMTEL_GURNALPLAT , write = set_TableNUMTEL_GURNALPLAT};
   virtual TFIBWideStringField * get_TableNUMTEL_GURNALPLAT(void)=0;
   virtual void set_TableNUMTEL_GURNALPLAT(TFIBWideStringField * TableNUMTEL_GURNALPLAT)=0;

   __property TFIBIntegerField * TableNUMKV_GURNALPLAT = {read = get_TableNUMKV_GURNALPLAT , write = set_TableNUMKV_GURNALPLAT};
   virtual TFIBIntegerField * get_TableNUMKV_GURNALPLAT(void)=0;
   virtual void set_TableNUMKV_GURNALPLAT(TFIBIntegerField * TableNUMKV_GURNALPLAT)=0;

   __property TFIBDateTimeField * TablePOS_GURNALPLAT = {read = get_TablePOS_GURNALPLAT , write = set_TablePOS_GURNALPLAT};
   virtual TFIBDateTimeField * get_TablePOS_GURNALPLAT(void)=0;
   virtual void set_TablePOS_GURNALPLAT(TFIBDateTimeField * TablePOS_GURNALPLAT)=0;

   __property TFIBLargeIntField * TableIDUSER_GURNALPLAT = {read = get_TableIDUSER_GURNALPLAT , write = set_TableIDUSER_GURNALPLAT};
   virtual TFIBLargeIntField * get_TableIDUSER_GURNALPLAT(void)=0;
   virtual void set_TableIDUSER_GURNALPLAT(TFIBLargeIntField * TableIDUSER_GURNALPLAT)=0;

   __property TFIBBCDField * TableSUM_GURNALPLAT = {read = get_TableSUM_GURNALPLAT , write = set_TableSUM_GURNALPLAT};
   virtual TFIBBCDField * get_TableSUM_GURNALPLAT(void)=0;
   virtual void set_TableSUM_GURNALPLAT(TFIBBCDField * TableSUM_GURNALPLAT)=0;

   __property TFIBSmallIntField * TableOUT_GURNALPLAT = {read = get_TableOUT_GURNALPLAT , write = set_TableOUT_GURNALPLAT};
   virtual TFIBSmallIntField * get_TableOUT_GURNALPLAT(void)=0;
   virtual void set_TableOUT_GURNALPLAT(TFIBSmallIntField * TableOUT_GURNALPLAT)=0;

   __property TFIBWideStringField * TableCODOPER_GURNALPLAT = {read = get_TableCODOPER_GURNALPLAT , write = set_TableCODOPER_GURNALPLAT};
   virtual TFIBWideStringField * get_TableCODOPER_GURNALPLAT(void)=0;
   virtual void set_TableCODOPER_GURNALPLAT(TFIBWideStringField * TableCODOPER_GURNALPLAT)=0;

   __property TFIBBCDField * TableSUMKL_GURNALPLAT = {read = get_TableSUMKL_GURNALPLAT , write = set_TableSUMKL_GURNALPLAT};
   virtual TFIBBCDField * get_TableSUMKL_GURNALPLAT(void)=0;
   virtual void set_TableSUMKL_GURNALPLAT(TFIBBCDField * TableSUMKL_GURNALPLAT)=0;

   __property TFIBBCDField * TablePROCENT_COMMISSION_GURNALPLAT = {read = get_TablePROCENT_COMMISSION_GURNALPLAT , write = set_TablePROCENT_COMMISSION_GURNALPLAT};
   virtual TFIBBCDField * get_TablePROCENT_COMMISSION_GURNALPLAT(void)=0;
   virtual void set_TablePROCENT_COMMISSION_GURNALPLAT(TFIBBCDField * TablePROCENT_COMMISSION_GURNALPLAT)=0;

   __property TFIBLargeIntField * TableIDKLIENT_GURNALPLAT = {read = get_TableIDKLIENT_GURNALPLAT , write = set_TableIDKLIENT_GURNALPLAT};
   virtual TFIBLargeIntField * get_TableIDKLIENT_GURNALPLAT(void)=0;
   virtual void set_TableIDKLIENT_GURNALPLAT(TFIBLargeIntField * TableIDKLIENT_GURNALPLAT)=0;

   __property TFIBLargeIntField * TableIDBASE_GURNALPLAT = {read = get_TableIDBASE_GURNALPLAT , write = set_TableIDBASE_GURNALPLAT};
   virtual TFIBLargeIntField * get_TableIDBASE_GURNALPLAT(void)=0;
   virtual void set_TableIDBASE_GURNALPLAT(TFIBLargeIntField * TableIDBASE_GURNALPLAT)=0;

   __property TFIBLargeIntField * TableIDOPERATOR_GURNALPLAT = {read = get_TableIDOPERATOR_GURNALPLAT , write = set_TableIDOPERATOR_GURNALPLAT};
   virtual TFIBLargeIntField * get_TableIDOPERATOR_GURNALPLAT(void)=0;
   virtual void set_TableIDOPERATOR_GURNALPLAT(TFIBLargeIntField * TableIDOPERATOR_GURNALPLAT)=0;

   __property TFIBLargeIntField * TableIDCODETEL_GURNALPLAT = {read = get_TableIDCODETEL_GURNALPLAT , write = set_TableIDCODETEL_GURNALPLAT};
   virtual TFIBLargeIntField * get_TableIDCODETEL_GURNALPLAT(void)=0;
   virtual void set_TableIDCODETEL_GURNALPLAT(TFIBLargeIntField * TableIDCODETEL_GURNALPLAT)=0;

   __property TFIBWideStringField * TableNAME_USER = {read = get_TableNAME_USER , write = set_TableNAME_USER};
   virtual TFIBWideStringField * get_TableNAME_USER(void)=0;
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)=0;

   __property TFIBWideStringField * TableNAMEKLIENT = {read = get_TableNAMEKLIENT , write = set_TableNAMEKLIENT};
   virtual TFIBWideStringField * get_TableNAMEKLIENT(void)=0;
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)=0;

   __property TFIBWideStringField * TableNAME_CODETEL = {read = get_TableNAME_CODETEL , write = set_TableNAME_CODETEL};
   virtual TFIBWideStringField * get_TableNAME_CODETEL(void)=0;
   virtual void set_TableNAME_CODETEL(TFIBWideStringField * TableNAME_CODETEL)=0;

   __property TFIBWideStringField * TableCODOPER_CODETEL = {read = get_TableCODOPER_CODETEL , write = set_TableCODOPER_CODETEL};
   virtual TFIBWideStringField * get_TableCODOPER_CODETEL(void)=0;
   virtual void set_TableCODOPER_CODETEL(TFIBWideStringField * TableCODOPER_CODETEL)=0;

   __property TFIBLargeIntField * GurPlatID_GURNALPLAT = {read = get_GurPlatID_GURNALPLAT , write = set_GurPlatID_GURNALPLAT};
   virtual TFIBLargeIntField * get_GurPlatID_GURNALPLAT(void)=0;
   virtual void set_GurPlatID_GURNALPLAT(TFIBLargeIntField * GurPlatID_GURNALPLAT)=0;

   __property TFIBLargeIntField * ElementID_GURNALPLAT = {read = get_ElementID_GURNALPLAT , write = set_ElementID_GURNALPLAT};
   virtual TFIBLargeIntField * get_ElementID_GURNALPLAT(void)=0;
   virtual void set_ElementID_GURNALPLAT(TFIBLargeIntField * ElementID_GURNALPLAT)=0;

   __property TFIBWideStringField * ElementGID_GURNALPLAT = {read = get_ElementGID_GURNALPLAT , write = set_ElementGID_GURNALPLAT};
   virtual TFIBWideStringField * get_ElementGID_GURNALPLAT(void)=0;
   virtual void set_ElementGID_GURNALPLAT(TFIBWideStringField * ElementGID_GURNALPLAT)=0;

   __property TFIBWideStringField * ElementCODE_GURNALPLAT = {read = get_ElementCODE_GURNALPLAT , write = set_ElementCODE_GURNALPLAT};
   virtual TFIBWideStringField * get_ElementCODE_GURNALPLAT(void)=0;
   virtual void set_ElementCODE_GURNALPLAT(TFIBWideStringField * ElementCODE_GURNALPLAT)=0;

   __property TFIBWideStringField * ElementNUMTEL_GURNALPLAT = {read = get_ElementNUMTEL_GURNALPLAT , write = set_ElementNUMTEL_GURNALPLAT};
   virtual TFIBWideStringField * get_ElementNUMTEL_GURNALPLAT(void)=0;
   virtual void set_ElementNUMTEL_GURNALPLAT(TFIBWideStringField * ElementNUMTEL_GURNALPLAT)=0;

   __property TFIBIntegerField * ElementNUMKV_GURNALPLAT = {read = get_ElementNUMKV_GURNALPLAT , write = set_ElementNUMKV_GURNALPLAT};
   virtual TFIBIntegerField * get_ElementNUMKV_GURNALPLAT(void)=0;
   virtual void set_ElementNUMKV_GURNALPLAT(TFIBIntegerField * ElementNUMKV_GURNALPLAT)=0;

   __property TFIBDateTimeField * ElementPOS_GURNALPLAT = {read = get_ElementPOS_GURNALPLAT , write = set_ElementPOS_GURNALPLAT};
   virtual TFIBDateTimeField * get_ElementPOS_GURNALPLAT(void)=0;
   virtual void set_ElementPOS_GURNALPLAT(TFIBDateTimeField * ElementPOS_GURNALPLAT)=0;

   __property TFIBLargeIntField * ElementIDUSER_GURNALPLAT = {read = get_ElementIDUSER_GURNALPLAT , write = set_ElementIDUSER_GURNALPLAT};
   virtual TFIBLargeIntField * get_ElementIDUSER_GURNALPLAT(void)=0;
   virtual void set_ElementIDUSER_GURNALPLAT(TFIBLargeIntField * ElementIDUSER_GURNALPLAT)=0;

   __property TFIBBCDField * ElementSUM_GURNALPLAT = {read = get_ElementSUM_GURNALPLAT , write = set_ElementSUM_GURNALPLAT};
   virtual TFIBBCDField * get_ElementSUM_GURNALPLAT(void)=0;
   virtual void set_ElementSUM_GURNALPLAT(TFIBBCDField * ElementSUM_GURNALPLAT)=0;

   __property TFIBSmallIntField * ElementOUT_GURNALPLAT = {read = get_ElementOUT_GURNALPLAT , write = set_ElementOUT_GURNALPLAT};
   virtual TFIBSmallIntField * get_ElementOUT_GURNALPLAT(void)=0;
   virtual void set_ElementOUT_GURNALPLAT(TFIBSmallIntField * ElementOUT_GURNALPLAT)=0;

   __property TFIBWideStringField * ElementCODOPER_GURNALPLAT = {read = get_ElementCODOPER_GURNALPLAT , write = set_ElementCODOPER_GURNALPLAT};
   virtual TFIBWideStringField * get_ElementCODOPER_GURNALPLAT(void)=0;
   virtual void set_ElementCODOPER_GURNALPLAT(TFIBWideStringField * ElementCODOPER_GURNALPLAT)=0;

   __property TFIBBCDField * ElementSUMKL_GURNALPLAT = {read = get_ElementSUMKL_GURNALPLAT , write = set_ElementSUMKL_GURNALPLAT};
   virtual TFIBBCDField * get_ElementSUMKL_GURNALPLAT(void)=0;
   virtual void set_ElementSUMKL_GURNALPLAT(TFIBBCDField * ElementSUMKL_GURNALPLAT)=0;

   __property TFIBBCDField * ElementPROCENT_COMMISSION_GURNALPLAT = {read = get_ElementPROCENT_COMMISSION_GURNALPLAT , write = set_ElementPROCENT_COMMISSION_GURNALPLAT};
   virtual TFIBBCDField * get_ElementPROCENT_COMMISSION_GURNALPLAT(void)=0;
   virtual void set_ElementPROCENT_COMMISSION_GURNALPLAT(TFIBBCDField * ElementPROCENT_COMMISSION_GURNALPLAT)=0;

   __property TFIBLargeIntField * ElementIDKLIENT_GURNALPLAT = {read = get_ElementIDKLIENT_GURNALPLAT , write = set_ElementIDKLIENT_GURNALPLAT};
   virtual TFIBLargeIntField * get_ElementIDKLIENT_GURNALPLAT(void)=0;
   virtual void set_ElementIDKLIENT_GURNALPLAT(TFIBLargeIntField * ElementIDKLIENT_GURNALPLAT)=0;

   __property TFIBLargeIntField * ElementIDBASE_GURNALPLAT = {read = get_ElementIDBASE_GURNALPLAT , write = set_ElementIDBASE_GURNALPLAT};
   virtual TFIBLargeIntField * get_ElementIDBASE_GURNALPLAT(void)=0;
   virtual void set_ElementIDBASE_GURNALPLAT(TFIBLargeIntField * ElementIDBASE_GURNALPLAT)=0;

   __property TFIBLargeIntField * ElementIDOPERATOR_GURNALPLAT = {read = get_ElementIDOPERATOR_GURNALPLAT , write = set_ElementIDOPERATOR_GURNALPLAT};
   virtual TFIBLargeIntField * get_ElementIDOPERATOR_GURNALPLAT(void)=0;
   virtual void set_ElementIDOPERATOR_GURNALPLAT(TFIBLargeIntField * ElementIDOPERATOR_GURNALPLAT)=0;

   __property TFIBLargeIntField * ElementIDCODETEL_GURNALPLAT = {read = get_ElementIDCODETEL_GURNALPLAT , write = set_ElementIDCODETEL_GURNALPLAT};
   virtual TFIBLargeIntField * get_ElementIDCODETEL_GURNALPLAT(void)=0;
   virtual void set_ElementIDCODETEL_GURNALPLAT(TFIBLargeIntField * ElementIDCODETEL_GURNALPLAT)=0;

   __property TFIBWideStringField * ElementNAME_USER = {read = get_ElementNAME_USER , write = set_ElementNAME_USER};
   virtual TFIBWideStringField * get_ElementNAME_USER(void)=0;
   virtual void set_ElementNAME_USER(TFIBWideStringField * ElementNAME_USER)=0;

   __property TFIBWideStringField * ElementNAMEKLIENT = {read = get_ElementNAMEKLIENT , write = set_ElementNAMEKLIENT};
   virtual TFIBWideStringField * get_ElementNAMEKLIENT(void)=0;
   virtual void set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)=0;

   __property TFIBWideStringField * ElementNAME_CODETEL = {read = get_ElementNAME_CODETEL , write = set_ElementNAME_CODETEL};
   virtual TFIBWideStringField * get_ElementNAME_CODETEL(void)=0;
   virtual void set_ElementNAME_CODETEL(TFIBWideStringField * ElementNAME_CODETEL)=0;

   __property TFIBWideStringField * ElementCODOPER_CODETEL = {read = get_ElementCODOPER_CODETEL , write = set_ElementCODOPER_CODETEL};
   virtual TFIBWideStringField * get_ElementCODOPER_CODETEL(void)=0;
   virtual void set_ElementCODOPER_CODETEL(TFIBWideStringField * ElementCODOPER_CODETEL)=0;

   __property bool NoOnlyOut = {read = get_NoOnlyOut , write = set_NoOnlyOut};
   virtual bool get_NoOnlyOut(void)=0;
   virtual void set_NoOnlyOut(bool NoOnlyOut)=0;

   __property AnsiString CodeTel = {read = get_CodeTel , write = set_CodeTel};
   virtual AnsiString get_CodeTel(void)=0;
   virtual void set_CodeTel(AnsiString CodeTel)=0;

   __property __int64 IdPlat = {read = get_IdPlat , write = set_IdPlat};
   virtual __int64 get_IdPlat(void)=0;
   virtual void set_IdPlat(__int64 IdPlat)=0;

   __property TDateTime PosNach = {read = get_PosNach , write = set_PosNach};
   virtual TDateTime get_PosNach(void)=0;
   virtual void set_PosNach(TDateTime PosNach)=0;

   __property TDateTime PosCon = {read = get_PosCon , write = set_PosCon};
   virtual TDateTime get_PosCon(void)=0;
   virtual void set_PosCon(TDateTime PosCon)=0;

   virtual void OpenTable()=0;
   virtual void UpdateTable(void)=0;
   virtual void  NewElement(void)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void  SaveElement()=0;
   virtual void DeleteElement(__int64 id)=0;
   virtual void DeleteAllElement(bool NoDeleteEndRecord)=0;
   virtual bool AddPlat(AnsiString cod, AnsiString number, double sum, int number_kv, AnsiString code_operator, double procent_commission, double sum_klient, __int64 id_klient, __int64 id_spr_code_tel)=0;
   virtual bool CheckPlat(AnsiString cod,AnsiString number,double sum,int number_kv, __int64 id_spr_code_tel)=0;
   virtual int GetNumberKv(AnsiString cod)=0;
};
#define IID_IDMGurPlat __uuidof(IDMGurPlat)
#endif
