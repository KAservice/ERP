#ifndef UIDMSprTypePriceH
#define UIDMSprTypePriceH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{55B1FB0D-4987-49F2-B442-E4DA0D23FF4B}"))IDMSprTypePrice : public IMainInterface
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

   __property TFIBBCDField * TableID_TPRICE = {read = get_TableID_TPRICE , write = set_TableID_TPRICE};
   virtual TFIBBCDField * get_TableID_TPRICE(void)=0;
   virtual void set_TableID_TPRICE(TFIBBCDField * TableID_TPRICE)=0;

   __property TFIBBCDField * ElementID_TPRICE = {read = get_ElementID_TPRICE , write = set_ElementID_TPRICE};
   virtual TFIBBCDField * get_ElementID_TPRICE(void)=0;
   virtual void set_ElementID_TPRICE(TFIBBCDField * ElementID_TPRICE)=0;

   __property TFIBWideStringField * TableNAME_TPRICE = {read = get_TableNAME_TPRICE , write = set_TableNAME_TPRICE};
   virtual TFIBWideStringField * get_TableNAME_TPRICE(void)=0;
   virtual void set_TableNAME_TPRICE(TFIBWideStringField * TableNAME_TPRICE)=0;

   __property TFIBWideStringField * TableGID_STPRICE = {read = get_TableGID_STPRICE , write = set_TableGID_STPRICE};
   virtual TFIBWideStringField * get_TableGID_STPRICE(void)=0;
   virtual void set_TableGID_STPRICE(TFIBWideStringField * TableGID_STPRICE)=0;

   __property TFIBWideStringField * ElementNAME_TPRICE = {read = get_ElementNAME_TPRICE , write = set_ElementNAME_TPRICE};
   virtual TFIBWideStringField * get_ElementNAME_TPRICE(void)=0;
   virtual void set_ElementNAME_TPRICE(TFIBWideStringField * ElementNAME_TPRICE)=0;

   __property TFIBWideStringField * ElementGID_STPRICE = {read = get_ElementGID_STPRICE , write = set_ElementGID_STPRICE};
   virtual TFIBWideStringField * get_ElementGID_STPRICE(void)=0;
   virtual void set_ElementGID_STPRICE(TFIBWideStringField * ElementGID_STPRICE)=0;

   virtual void OpenTable()=0;
   virtual int  OpenElement(__int64 Id)=0;
   virtual void NewElement()=0;
   virtual bool SaveElement(void)=0;
   virtual void CloseElement(void)=0;
   virtual void DeleteElement(__int64 Id)=0;
   virtual __int64 GetIDTypePrice(String   name)=0;
   virtual int GetIndexTypePricePoId(__int64 id_type_price)=0;
   virtual __int64 GetIDElement(String gid)=0;
   virtual AnsiString GetGIDElement(__int64 id)=0;
};
#define IID_IDMSprTypePrice __uuidof(IDMSprTypePrice)
#endif
