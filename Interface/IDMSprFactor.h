#ifndef UIDMSprFactorH
#define UIDMSprFactorH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprFactor)) IDMSprFactor : public IMainInterface
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

   __property TFIBLargeIntField * TableID_SFACTOR = {read = get_TableID_SFACTOR , write = set_TableID_SFACTOR};
   virtual TFIBLargeIntField * get_TableID_SFACTOR(void)=0;
   virtual void set_TableID_SFACTOR(TFIBLargeIntField * TableID_SFACTOR)=0;

   __property TFIBWideStringField * TableGID_SFACTOR = {read = get_TableGID_SFACTOR , write = set_TableGID_SFACTOR};
   virtual TFIBWideStringField * get_TableGID_SFACTOR(void)=0;
   virtual void set_TableGID_SFACTOR(TFIBWideStringField * TableGID_SFACTOR)=0;

   __property TFIBLargeIntField * TableIDBASE_SFACTOR = {read = get_TableIDBASE_SFACTOR , write = set_TableIDBASE_SFACTOR};
   virtual TFIBLargeIntField * get_TableIDBASE_SFACTOR(void)=0;
   virtual void set_TableIDBASE_SFACTOR(TFIBLargeIntField * TableIDBASE_SFACTOR)=0;

   __property TFIBWideStringField * TableNAME_SFACTOR = {read = get_TableNAME_SFACTOR , write = set_TableNAME_SFACTOR};
   virtual TFIBWideStringField * get_TableNAME_SFACTOR(void)=0;
   virtual void set_TableNAME_SFACTOR(TFIBWideStringField * TableNAME_SFACTOR)=0;

   __property TFIBIntegerField * TableINDEX_SFACTOR = {read = get_TableINDEX_SFACTOR , write = set_TableINDEX_SFACTOR};
   virtual TFIBIntegerField * get_TableINDEX_SFACTOR(void)=0;
   virtual void set_TableINDEX_SFACTOR(TFIBIntegerField * TableINDEX_SFACTOR)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBLargeIntField * ElementID_SFACTOR = {read = get_ElementID_SFACTOR , write = set_ElementID_SFACTOR};
   virtual TFIBLargeIntField * get_ElementID_SFACTOR(void)=0;
   virtual void set_ElementID_SFACTOR(TFIBLargeIntField * ElementID_SFACTOR)=0;

   __property TFIBWideStringField * ElementGID_SFACTOR = {read = get_ElementGID_SFACTOR , write = set_ElementGID_SFACTOR};
   virtual TFIBWideStringField * get_ElementGID_SFACTOR(void)=0;
   virtual void set_ElementGID_SFACTOR(TFIBWideStringField * ElementGID_SFACTOR)=0;

   __property TFIBLargeIntField * ElementIDBASE_SFACTOR = {read = get_ElementIDBASE_SFACTOR , write = set_ElementIDBASE_SFACTOR};
   virtual TFIBLargeIntField * get_ElementIDBASE_SFACTOR(void)=0;
   virtual void set_ElementIDBASE_SFACTOR(TFIBLargeIntField * ElementIDBASE_SFACTOR)=0;

   __property TFIBWideStringField * ElementNAME_SFACTOR = {read = get_ElementNAME_SFACTOR , write = set_ElementNAME_SFACTOR};
   virtual TFIBWideStringField * get_ElementNAME_SFACTOR(void)=0;
   virtual void set_ElementNAME_SFACTOR(TFIBWideStringField * ElementNAME_SFACTOR)=0;

   __property TFIBIntegerField * ElementINDEX_SFACTOR = {read = get_ElementINDEX_SFACTOR , write = set_ElementINDEX_SFACTOR};
   virtual TFIBIntegerField * get_ElementINDEX_SFACTOR(void)=0;
   virtual void set_ElementINDEX_SFACTOR(TFIBIntegerField * ElementINDEX_SFACTOR)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void CloseElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual bool SaveIsmen()=0;
   virtual bool CancelIsmen()=0;
   virtual __int64 GetIDElement(UnicodeString gid)=0;
   virtual UnicodeString GetGIDElement(__int64 id)=0;
   virtual int GetIndexElementaPoID(__int64 id)=0;
};
#define IID_IDMSprFactor __uuidof(IDMSprFactor)
#endif
