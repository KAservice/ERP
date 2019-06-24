#ifndef UIDMSprTypeNomH
#define UIDMSprTypeNomH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprTypeNom)) IDMSprTypeNom : public IMainInterface
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

   __property TFIBLargeIntField * TableID_STNOM = {read = get_TableID_STNOM , write = set_TableID_STNOM};
   virtual TFIBLargeIntField * get_TableID_STNOM(void)=0;
   virtual void set_TableID_STNOM(TFIBLargeIntField * TableID_STNOM)=0;

   __property TFIBLargeIntField * TableIDBASE_STNOM = {read = get_TableIDBASE_STNOM , write = set_TableIDBASE_STNOM};
   virtual TFIBLargeIntField * get_TableIDBASE_STNOM(void)=0;
   virtual void set_TableIDBASE_STNOM(TFIBLargeIntField * TableIDBASE_STNOM)=0;

   __property TFIBWideStringField * TableNAME_STNOM = {read = get_TableNAME_STNOM , write = set_TableNAME_STNOM};
   virtual TFIBWideStringField * get_TableNAME_STNOM(void)=0;
   virtual void set_TableNAME_STNOM(TFIBWideStringField * TableNAME_STNOM)=0;

   __property TFIBLargeIntField * ElementID_STNOM = {read = get_ElementID_STNOM , write = set_ElementID_STNOM};
   virtual TFIBLargeIntField * get_ElementID_STNOM(void)=0;
   virtual void set_ElementID_STNOM(TFIBLargeIntField * ElementID_STNOM)=0;

   __property TFIBLargeIntField * ElementIDBASE_STNOM = {read = get_ElementIDBASE_STNOM , write = set_ElementIDBASE_STNOM};
   virtual TFIBLargeIntField * get_ElementIDBASE_STNOM(void)=0;
   virtual void set_ElementIDBASE_STNOM(TFIBLargeIntField * ElementIDBASE_STNOM)=0;

   __property TFIBWideStringField * ElementNAME_STNOM = {read = get_ElementNAME_STNOM , write = set_ElementNAME_STNOM};
   virtual TFIBWideStringField * get_ElementNAME_STNOM(void)=0;
   virtual void set_ElementNAME_STNOM(TFIBWideStringField * ElementNAME_STNOM)=0;

   virtual bool OpenTable(void)=0;
   virtual bool  OpenElement(__int64 id)=0;
   virtual bool NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void CloseElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual __int64 GetIdElementPoName(UnicodeString   name)=0;
   virtual int GetIndexInTablePoId(__int64 id_element)=0;
   virtual __int64 GetIdElementPoGid(UnicodeString gid)=0;
   virtual UnicodeString GetGidElementPoId(__int64 id)=0;
};
#define IID_IDMSprTypeNom __uuidof(IDMSprTypeNom)
#endif
