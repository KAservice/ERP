#ifndef UIDMSprFactorValueH
#define UIDMSprFactorValueH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprFactorValue)) IDMSprFactorValue : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

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

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

   __property TpFIBDataSet * FactorList = {read = get_FactorList , write = set_FactorList};
   virtual TpFIBDataSet * get_FactorList(void)=0;
   virtual void set_FactorList(TpFIBDataSet * FactorList)=0;

   __property TDataSource * DataSourceFactorList = {read = get_DataSourceFactorList , write = set_DataSourceFactorList};
   virtual TDataSource * get_DataSourceFactorList(void)=0;
   virtual void set_DataSourceFactorList(TDataSource * DataSourceFactorList)=0;

   __property TFIBLargeIntField * FactorListID_SFACTOR = {read = get_FactorListID_SFACTOR , write = set_FactorListID_SFACTOR};
   virtual TFIBLargeIntField * get_FactorListID_SFACTOR(void)=0;
   virtual void set_FactorListID_SFACTOR(TFIBLargeIntField * FactorListID_SFACTOR)=0;

   __property TFIBWideStringField * FactorListNAME_SFACTOR = {read = get_FactorListNAME_SFACTOR , write = set_FactorListNAME_SFACTOR};
   virtual TFIBWideStringField * get_FactorListNAME_SFACTOR(void)=0;
   virtual void set_FactorListNAME_SFACTOR(TFIBWideStringField * FactorListNAME_SFACTOR)=0;

   __property TFIBLargeIntField * TableID_SFACTOR_VAL = {read = get_TableID_SFACTOR_VAL , write = set_TableID_SFACTOR_VAL};
   virtual TFIBLargeIntField * get_TableID_SFACTOR_VAL(void)=0;
   virtual void set_TableID_SFACTOR_VAL(TFIBLargeIntField * TableID_SFACTOR_VAL)=0;

   __property TFIBWideStringField * TableGID_SFACTOR_VAL = {read = get_TableGID_SFACTOR_VAL , write = set_TableGID_SFACTOR_VAL};
   virtual TFIBWideStringField * get_TableGID_SFACTOR_VAL(void)=0;
   virtual void set_TableGID_SFACTOR_VAL(TFIBWideStringField * TableGID_SFACTOR_VAL)=0;

   __property TFIBLargeIntField * TableIDBASE_SFACTOR_VAL = {read = get_TableIDBASE_SFACTOR_VAL , write = set_TableIDBASE_SFACTOR_VAL};
   virtual TFIBLargeIntField * get_TableIDBASE_SFACTOR_VAL(void)=0;
   virtual void set_TableIDBASE_SFACTOR_VAL(TFIBLargeIntField * TableIDBASE_SFACTOR_VAL)=0;

   __property TFIBLargeIntField * TableIDPRODUCE_SFACTOR_VAL = {read = get_TableIDPRODUCE_SFACTOR_VAL , write = set_TableIDPRODUCE_SFACTOR_VAL};
   virtual TFIBLargeIntField * get_TableIDPRODUCE_SFACTOR_VAL(void)=0;
   virtual void set_TableIDPRODUCE_SFACTOR_VAL(TFIBLargeIntField * TableIDPRODUCE_SFACTOR_VAL)=0;

   __property TFIBLargeIntField * TableIDFACTOR_SFACTOR_VAL = {read = get_TableIDFACTOR_SFACTOR_VAL , write = set_TableIDFACTOR_SFACTOR_VAL};
   virtual TFIBLargeIntField * get_TableIDFACTOR_SFACTOR_VAL(void)=0;
   virtual void set_TableIDFACTOR_SFACTOR_VAL(TFIBLargeIntField * TableIDFACTOR_SFACTOR_VAL)=0;

   __property TFIBBCDField * TableVALUE_SFACTOR_VAL = {read = get_TableVALUE_SFACTOR_VAL , write = set_TableVALUE_SFACTOR_VAL};
   virtual TFIBBCDField * get_TableVALUE_SFACTOR_VAL(void)=0;
   virtual void set_TableVALUE_SFACTOR_VAL(TFIBBCDField * TableVALUE_SFACTOR_VAL)=0;

   __property TFIBLargeIntField * ElementID_SFACTOR_VAL = {read = get_ElementID_SFACTOR_VAL , write = set_ElementID_SFACTOR_VAL};
   virtual TFIBLargeIntField * get_ElementID_SFACTOR_VAL(void)=0;
   virtual void set_ElementID_SFACTOR_VAL(TFIBLargeIntField * ElementID_SFACTOR_VAL)=0;

   __property TFIBWideStringField * ElementGID_SFACTOR_VAL = {read = get_ElementGID_SFACTOR_VAL , write = set_ElementGID_SFACTOR_VAL};
   virtual TFIBWideStringField * get_ElementGID_SFACTOR_VAL(void)=0;
   virtual void set_ElementGID_SFACTOR_VAL(TFIBWideStringField * ElementGID_SFACTOR_VAL)=0;

   __property TFIBLargeIntField * ElementIDBASE_SFACTOR_VAL = {read = get_ElementIDBASE_SFACTOR_VAL , write = set_ElementIDBASE_SFACTOR_VAL};
   virtual TFIBLargeIntField * get_ElementIDBASE_SFACTOR_VAL(void)=0;
   virtual void set_ElementIDBASE_SFACTOR_VAL(TFIBLargeIntField * ElementIDBASE_SFACTOR_VAL)=0;

   __property TFIBLargeIntField * ElementIDPRODUCE_SFACTOR_VAL = {read = get_ElementIDPRODUCE_SFACTOR_VAL , write = set_ElementIDPRODUCE_SFACTOR_VAL};
   virtual TFIBLargeIntField * get_ElementIDPRODUCE_SFACTOR_VAL(void)=0;
   virtual void set_ElementIDPRODUCE_SFACTOR_VAL(TFIBLargeIntField * ElementIDPRODUCE_SFACTOR_VAL)=0;

   __property TFIBLargeIntField * ElementIDFACTOR_SFACTOR_VAL = {read = get_ElementIDFACTOR_SFACTOR_VAL , write = set_ElementIDFACTOR_SFACTOR_VAL};
   virtual TFIBLargeIntField * get_ElementIDFACTOR_SFACTOR_VAL(void)=0;
   virtual void set_ElementIDFACTOR_SFACTOR_VAL(TFIBLargeIntField * ElementIDFACTOR_SFACTOR_VAL)=0;

   __property TFIBBCDField * ElementVALUE_SFACTOR_VAL = {read = get_ElementVALUE_SFACTOR_VAL , write = set_ElementVALUE_SFACTOR_VAL};
   virtual TFIBBCDField * get_ElementVALUE_SFACTOR_VAL(void)=0;
   virtual void set_ElementVALUE_SFACTOR_VAL(TFIBBCDField * ElementVALUE_SFACTOR_VAL)=0;

   __property __int64 IdFactor = {read = get_IdFactor , write = set_IdFactor};
   virtual __int64 get_IdFactor(void)=0;
   virtual void set_IdFactor(__int64 IdFactor)=0;

   __property __int64 IdProduce = {read = get_IdProduce , write = set_IdProduce};
   virtual __int64 get_IdProduce(void)=0;
   virtual void set_IdProduce(__int64 IdProduce)=0;

   virtual bool OpenTable(__int64 id_produce)=0;
   virtual bool SaveIsmen(void)=0;
   virtual void CancelIsmen(void)=0;
   virtual bool OpenElement(__int64 Id)=0;
   virtual bool NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 Id)=0;
   virtual __int64 FindElement(__int64 id_factor, __int64 id_produce)=0;
   virtual bool UpdateSpisokFactors(void)=0;
};
#define IID_IDMSprFactorValue __uuidof(IDMSprFactorValue)
#endif
