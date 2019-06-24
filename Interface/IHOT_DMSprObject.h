#ifndef UIHOT_DMSprObjectH
#define UIHOT_DMSprObjectH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{55C5AE24-CE02-4648-A1CA-8799BE4FA8B1}")) IHOT_DMSprObject : public IMainInterface
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

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBBCDField * TableID_HOT_SOBJECT = {read = get_TableID_HOT_SOBJECT , write = set_TableID_HOT_SOBJECT};
   virtual TFIBBCDField * get_TableID_HOT_SOBJECT(void)=0;
   virtual void set_TableID_HOT_SOBJECT(TFIBBCDField * TableID_HOT_SOBJECT)=0;

   __property TFIBBCDField * TableIDSKL_HOT_SOBJECT = {read = get_TableIDSKL_HOT_SOBJECT , write = set_TableIDSKL_HOT_SOBJECT};
   virtual TFIBBCDField * get_TableIDSKL_HOT_SOBJECT(void)=0;
   virtual void set_TableIDSKL_HOT_SOBJECT(TFIBBCDField * TableIDSKL_HOT_SOBJECT)=0;

   __property TFIBBCDField * ElementID_HOT_SOBJECT = {read = get_ElementID_HOT_SOBJECT , write = set_ElementID_HOT_SOBJECT};
   virtual TFIBBCDField * get_ElementID_HOT_SOBJECT(void)=0;
   virtual void set_ElementID_HOT_SOBJECT(TFIBBCDField * ElementID_HOT_SOBJECT)=0;

   __property TFIBBCDField * ElementIDSKL_HOT_SOBJECT = {read = get_ElementIDSKL_HOT_SOBJECT , write = set_ElementIDSKL_HOT_SOBJECT};
   virtual TFIBBCDField * get_ElementIDSKL_HOT_SOBJECT(void)=0;
   virtual void set_ElementIDSKL_HOT_SOBJECT(TFIBBCDField * ElementIDSKL_HOT_SOBJECT)=0;

   __property TFIBWideStringField * ElementNAME_HOT_SOBJECT = {read = get_ElementNAME_HOT_SOBJECT , write = set_ElementNAME_HOT_SOBJECT};
   virtual TFIBWideStringField * get_ElementNAME_HOT_SOBJECT(void)=0;
   virtual void set_ElementNAME_HOT_SOBJECT(TFIBWideStringField * ElementNAME_HOT_SOBJECT)=0;

   __property TFIBWideStringField * ElementNAMESKLAD = {read = get_ElementNAMESKLAD , write = set_ElementNAMESKLAD};
   virtual TFIBWideStringField * get_ElementNAMESKLAD(void)=0;
   virtual void set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD)=0;

   __property TFIBWideStringField * TableNAME_HOT_SOBJECT = {read = get_TableNAME_HOT_SOBJECT , write = set_TableNAME_HOT_SOBJECT};
   virtual TFIBWideStringField * get_TableNAME_HOT_SOBJECT(void)=0;
   virtual void set_TableNAME_HOT_SOBJECT(TFIBWideStringField * TableNAME_HOT_SOBJECT)=0;

   __property TFIBWideStringField * TableNAMESKLAD = {read = get_TableNAMESKLAD , write = set_TableNAMESKLAD};
   virtual TFIBWideStringField * get_TableNAMESKLAD(void)=0;
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual bool NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void CloseElement(void)=0;
   virtual bool DeleteElement(__int64 Id)=0;
   virtual int GetIndexElementaPoID(__int64 id)=0;
};
#define IID_IHOT_DMSprObject __uuidof(IHOT_DMSprObject)
#endif
