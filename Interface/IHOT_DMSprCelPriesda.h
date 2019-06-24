#ifndef UIHOT_DMSprCelPriesdaH
#define UIHOT_DMSprCelPriesdaH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{C0C50745-060C-4AB4-B348-F8BCA1A2E6BC}")) IHOT_DMSprCelPriesda : public IMainInterface
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

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBBCDField * ElementID_HOT_SCELPR = {read = get_ElementID_HOT_SCELPR , write = set_ElementID_HOT_SCELPR};
   virtual TFIBBCDField * get_ElementID_HOT_SCELPR(void)=0;
   virtual void set_ElementID_HOT_SCELPR(TFIBBCDField * ElementID_HOT_SCELPR)=0;

   __property TFIBBCDField * TableID_HOT_SCELPR = {read = get_TableID_HOT_SCELPR , write = set_TableID_HOT_SCELPR};
   virtual TFIBBCDField * get_TableID_HOT_SCELPR(void)=0;
   virtual void set_TableID_HOT_SCELPR(TFIBBCDField * TableID_HOT_SCELPR)=0;

   __property TFIBWideStringField * ElementNAME_HOT_SCELPR = {read = get_ElementNAME_HOT_SCELPR , write = set_ElementNAME_HOT_SCELPR};
   virtual TFIBWideStringField * get_ElementNAME_HOT_SCELPR(void)=0;
   virtual void set_ElementNAME_HOT_SCELPR(TFIBWideStringField * ElementNAME_HOT_SCELPR)=0;

   __property TFIBWideStringField * TableNAME_HOT_SCELPR = {read = get_TableNAME_HOT_SCELPR , write = set_TableNAME_HOT_SCELPR};
   virtual TFIBWideStringField * get_TableNAME_HOT_SCELPR(void)=0;
   virtual void set_TableNAME_HOT_SCELPR(TFIBWideStringField * TableNAME_HOT_SCELPR)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual bool NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual bool SaveIsmen(void)=0;
   virtual bool CancelIsmen(void)=0;
   virtual void CloseElement(void)=0;
   virtual bool DeleteElement(__int64 Id)=0;
   virtual int GetIndexElementaPoID(__int64 id)=0;
};
#define IID_IHOT_DMSprCelPriesda __uuidof(IHOT_DMSprCelPriesda)
#endif
