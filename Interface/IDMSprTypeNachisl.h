#ifndef UIDMSprTypeNachislH
#define UIDMSprTypeNachislH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprTypeNachisl)) IDMSprTypeNachisl : public IMainInterface
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

   __property TFIBBCDField * TableID_STNACHISL = {read = get_TableID_STNACHISL , write = set_TableID_STNACHISL};
   virtual TFIBBCDField * get_TableID_STNACHISL(void)=0;
   virtual void set_TableID_STNACHISL(TFIBBCDField * TableID_STNACHISL)=0;

   __property TFIBBCDField * TableIDBASE_STNACHISL = {read = get_TableIDBASE_STNACHISL , write = set_TableIDBASE_STNACHISL};
   virtual TFIBBCDField * get_TableIDBASE_STNACHISL(void)=0;
   virtual void set_TableIDBASE_STNACHISL(TFIBBCDField * TableIDBASE_STNACHISL)=0;

   __property TFIBWideStringField * TableNAME_STNACHISL = {read = get_TableNAME_STNACHISL , write = set_TableNAME_STNACHISL};
   virtual TFIBWideStringField * get_TableNAME_STNACHISL(void)=0;
   virtual void set_TableNAME_STNACHISL(TFIBWideStringField * TableNAME_STNACHISL)=0;

   __property TFIBWideStringField * TableGID_STNACHISL = {read = get_TableGID_STNACHISL , write = set_TableGID_STNACHISL};
   virtual TFIBWideStringField * get_TableGID_STNACHISL(void)=0;
   virtual void set_TableGID_STNACHISL(TFIBWideStringField * TableGID_STNACHISL)=0;

   __property TFIBBCDField * ElementID_STNACHISL = {read = get_ElementID_STNACHISL , write = set_ElementID_STNACHISL};
   virtual TFIBBCDField * get_ElementID_STNACHISL(void)=0;
   virtual void set_ElementID_STNACHISL(TFIBBCDField * ElementID_STNACHISL)=0;

   __property TFIBBCDField * ElementIDBASE_STNACHISL = {read = get_ElementIDBASE_STNACHISL , write = set_ElementIDBASE_STNACHISL};
   virtual TFIBBCDField * get_ElementIDBASE_STNACHISL(void)=0;
   virtual void set_ElementIDBASE_STNACHISL(TFIBBCDField * ElementIDBASE_STNACHISL)=0;

   __property TFIBWideStringField * ElementNAME_STNACHISL = {read = get_ElementNAME_STNACHISL , write = set_ElementNAME_STNACHISL};
   virtual TFIBWideStringField * get_ElementNAME_STNACHISL(void)=0;
   virtual void set_ElementNAME_STNACHISL(TFIBWideStringField * ElementNAME_STNACHISL)=0;

   __property TFIBWideStringField * ElementGID_STNACHISL = {read = get_ElementGID_STNACHISL , write = set_ElementGID_STNACHISL};
   virtual TFIBWideStringField * get_ElementGID_STNACHISL(void)=0;
   virtual void set_ElementGID_STNACHISL(TFIBWideStringField * ElementGID_STNACHISL)=0;

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
#define IID_IDMSprTypeNachisl __uuidof(IDMSprTypeNachisl)
#endif
