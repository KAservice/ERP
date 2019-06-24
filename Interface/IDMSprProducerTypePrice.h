#ifndef UIDMSprProducerTypePriceH
#define UIDMSprProducerTypePriceH
#include "IMainInterface.h"
#include "UGlobalConstant.h"   #include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprProducerTypePrice)) IDMSprProducerTypePrice : public IMainInterface
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

   __property TFIBLargeIntField * TableID_SPRTYPE_PRICE = {read = get_TableID_SPRTYPE_PRICE , write = set_TableID_SPRTYPE_PRICE};
   virtual TFIBLargeIntField * get_TableID_SPRTYPE_PRICE(void)=0;
   virtual void set_TableID_SPRTYPE_PRICE(TFIBLargeIntField * TableID_SPRTYPE_PRICE)=0;

   __property TFIBLargeIntField * TableIDBASE_SPRTYPE_PRICE = {read = get_TableIDBASE_SPRTYPE_PRICE , write = set_TableIDBASE_SPRTYPE_PRICE};
   virtual TFIBLargeIntField * get_TableIDBASE_SPRTYPE_PRICE(void)=0;
   virtual void set_TableIDBASE_SPRTYPE_PRICE(TFIBLargeIntField * TableIDBASE_SPRTYPE_PRICE)=0;

   __property TFIBWideStringField * TableGID_SPRTYPE_PRICE = {read = get_TableGID_SPRTYPE_PRICE , write = set_TableGID_SPRTYPE_PRICE};
   virtual TFIBWideStringField * get_TableGID_SPRTYPE_PRICE(void)=0;
   virtual void set_TableGID_SPRTYPE_PRICE(TFIBWideStringField * TableGID_SPRTYPE_PRICE)=0;

   __property TFIBWideStringField * TableNAME_SPRTYPE_PRICE = {read = get_TableNAME_SPRTYPE_PRICE , write = set_TableNAME_SPRTYPE_PRICE};
   virtual TFIBWideStringField * get_TableNAME_SPRTYPE_PRICE(void)=0;
   virtual void set_TableNAME_SPRTYPE_PRICE(TFIBWideStringField * TableNAME_SPRTYPE_PRICE)=0;

   __property TFIBLargeIntField * ElementID_SPRTYPE_PRICE = {read = get_ElementID_SPRTYPE_PRICE , write = set_ElementID_SPRTYPE_PRICE};
   virtual TFIBLargeIntField * get_ElementID_SPRTYPE_PRICE(void)=0;
   virtual void set_ElementID_SPRTYPE_PRICE(TFIBLargeIntField * ElementID_SPRTYPE_PRICE)=0;

   __property TFIBLargeIntField * ElementIDBASE_SPRTYPE_PRICE = {read = get_ElementIDBASE_SPRTYPE_PRICE , write = set_ElementIDBASE_SPRTYPE_PRICE};
   virtual TFIBLargeIntField * get_ElementIDBASE_SPRTYPE_PRICE(void)=0;
   virtual void set_ElementIDBASE_SPRTYPE_PRICE(TFIBLargeIntField * ElementIDBASE_SPRTYPE_PRICE)=0;

   __property TFIBWideStringField * ElementGID_SPRTYPE_PRICE = {read = get_ElementGID_SPRTYPE_PRICE , write = set_ElementGID_SPRTYPE_PRICE};
   virtual TFIBWideStringField * get_ElementGID_SPRTYPE_PRICE(void)=0;
   virtual void set_ElementGID_SPRTYPE_PRICE(TFIBWideStringField * ElementGID_SPRTYPE_PRICE)=0;

   __property TFIBWideStringField * ElementNAME_SPRTYPE_PRICE = {read = get_ElementNAME_SPRTYPE_PRICE , write = set_ElementNAME_SPRTYPE_PRICE};
   virtual TFIBWideStringField * get_ElementNAME_SPRTYPE_PRICE(void)=0;
   virtual void set_ElementNAME_SPRTYPE_PRICE(TFIBWideStringField * ElementNAME_SPRTYPE_PRICE)=0;

   virtual bool OpenTable()=0;
   virtual bool  OpenElement(__int64 id)=0;
   virtual bool NewElement()=0;
   virtual bool SaveElement(void)=0;
   virtual void CloseElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual __int64 GetIdElementPoName(UnicodeString   name)=0;
   virtual int GetIndexInTablePoId(__int64 id_element)=0;
   virtual __int64 GetIdElementPoGid(UnicodeString gid)=0;
   virtual UnicodeString GetGidElementPoId(__int64 id)=0;
};
#define IID_IDMSprProducerTypePrice __uuidof(IDMSprProducerTypePrice)
#endif
