#ifndef UIDMSprInvH
#define UIDMSprInvH
#include "IMainInterface.h"
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{9139034F-723F-40EB-B4CF-51E5D2A75B60}")) IDMSprInv : public IMainInterface
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

   __property TFIBDateField * TableDATE_SINV = {read = get_TableDATE_SINV , write = set_TableDATE_SINV};
   virtual TFIBDateField * get_TableDATE_SINV(void)=0;
   virtual void set_TableDATE_SINV(TFIBDateField * TableDATE_SINV)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBDateField * ElementDATE_SINV = {read = get_ElementDATE_SINV , write = set_ElementDATE_SINV};
   virtual TFIBDateField * get_ElementDATE_SINV(void)=0;
   virtual void set_ElementDATE_SINV(TFIBDateField * ElementDATE_SINV)=0;

   __property TFIBBCDField * TableID_SINV = {read = get_TableID_SINV , write = set_TableID_SINV};
   virtual TFIBBCDField * get_TableID_SINV(void)=0;
   virtual void set_TableID_SINV(TFIBBCDField * TableID_SINV)=0;

   __property TFIBBCDField * ElementID_SINV = {read = get_ElementID_SINV , write = set_ElementID_SINV};
   virtual TFIBBCDField * get_ElementID_SINV(void)=0;
   virtual void set_ElementID_SINV(TFIBBCDField * ElementID_SINV)=0;

   __property TFIBWideStringField * TableGID_SINV = {read = get_TableGID_SINV , write = set_TableGID_SINV};
   virtual TFIBWideStringField * get_TableGID_SINV(void)=0;
   virtual void set_TableGID_SINV(TFIBWideStringField * TableGID_SINV)=0;

   __property TFIBWideStringField * TableNAME_SINV = {read = get_TableNAME_SINV , write = set_TableNAME_SINV};
   virtual TFIBWideStringField * get_TableNAME_SINV(void)=0;
   virtual void set_TableNAME_SINV(TFIBWideStringField * TableNAME_SINV)=0;

   __property TFIBWideStringField * ElementGID_SINV = {read = get_ElementGID_SINV , write = set_ElementGID_SINV};
   virtual TFIBWideStringField * get_ElementGID_SINV(void)=0;
   virtual void set_ElementGID_SINV(TFIBWideStringField * ElementGID_SINV)=0;

   __property TFIBWideStringField * ElementNAME_SINV = {read = get_ElementNAME_SINV , write = set_ElementNAME_SINV};
   virtual TFIBWideStringField * get_ElementNAME_SINV(void)=0;
   virtual void set_ElementNAME_SINV(TFIBWideStringField * ElementNAME_SINV)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual void NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void CloseElement(void)=0;
   virtual void DeleteElement(__int64 Id)=0;
   virtual __int64 GetIDElement(String gid)=0;
   virtual AnsiString GetGIDElement(__int64 id)=0;
};
#define IID_IDMSprInv __uuidof(IDMSprInv)
#endif
