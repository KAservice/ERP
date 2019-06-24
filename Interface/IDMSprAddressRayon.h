#ifndef UIDMSprAddressRayonH
#define UIDMSprAddressRayonH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprAddressRayon)) IDMSprAddressRayon : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

   __property TFIBLargeIntField * TableID_SADR_RAYON = {read = get_TableID_SADR_RAYON , write = set_TableID_SADR_RAYON};
   virtual TFIBLargeIntField * get_TableID_SADR_RAYON(void)=0;
   virtual void set_TableID_SADR_RAYON(TFIBLargeIntField * TableID_SADR_RAYON)=0;

   __property TFIBLargeIntField * TableIDBASE_SADR_RAYON = {read = get_TableIDBASE_SADR_RAYON , write = set_TableIDBASE_SADR_RAYON};
   virtual TFIBLargeIntField * get_TableIDBASE_SADR_RAYON(void)=0;
   virtual void set_TableIDBASE_SADR_RAYON(TFIBLargeIntField * TableIDBASE_SADR_RAYON)=0;

   __property TFIBLargeIntField * TableIDREGION_SADR_RAYON = {read = get_TableIDREGION_SADR_RAYON , write = set_TableIDREGION_SADR_RAYON};
   virtual TFIBLargeIntField * get_TableIDREGION_SADR_RAYON(void)=0;
   virtual void set_TableIDREGION_SADR_RAYON(TFIBLargeIntField * TableIDREGION_SADR_RAYON)=0;

   __property TFIBWideStringField * TableNAME_SADR_RAYON = {read = get_TableNAME_SADR_RAYON , write = set_TableNAME_SADR_RAYON};
   virtual TFIBWideStringField * get_TableNAME_SADR_RAYON(void)=0;
   virtual void set_TableNAME_SADR_RAYON(TFIBWideStringField * TableNAME_SADR_RAYON)=0;

   __property TFIBLargeIntField * ElementID_SADR_RAYON = {read = get_ElementID_SADR_RAYON , write = set_ElementID_SADR_RAYON};
   virtual TFIBLargeIntField * get_ElementID_SADR_RAYON(void)=0;
   virtual void set_ElementID_SADR_RAYON(TFIBLargeIntField * ElementID_SADR_RAYON)=0;

   __property TFIBLargeIntField * ElementIDBASE_SADR_RAYON = {read = get_ElementIDBASE_SADR_RAYON , write = set_ElementIDBASE_SADR_RAYON};
   virtual TFIBLargeIntField * get_ElementIDBASE_SADR_RAYON(void)=0;
   virtual void set_ElementIDBASE_SADR_RAYON(TFIBLargeIntField * ElementIDBASE_SADR_RAYON)=0;

   __property TFIBLargeIntField * ElementIDREGION_SADR_RAYON = {read = get_ElementIDREGION_SADR_RAYON , write = set_ElementIDREGION_SADR_RAYON};
   virtual TFIBLargeIntField * get_ElementIDREGION_SADR_RAYON(void)=0;
   virtual void set_ElementIDREGION_SADR_RAYON(TFIBLargeIntField * ElementIDREGION_SADR_RAYON)=0;

   __property TFIBWideStringField * ElementNAME_SADR_RAYON = {read = get_ElementNAME_SADR_RAYON , write = set_ElementNAME_SADR_RAYON};
   virtual TFIBWideStringField * get_ElementNAME_SADR_RAYON(void)=0;
   virtual void set_ElementNAME_SADR_RAYON(TFIBWideStringField * ElementNAME_SADR_RAYON)=0;

   __property TFIBLargeIntField * ElementID_SADR_REGION = {read = get_ElementID_SADR_REGION , write = set_ElementID_SADR_REGION};
   virtual TFIBLargeIntField * get_ElementID_SADR_REGION(void)=0;
   virtual void set_ElementID_SADR_REGION(TFIBLargeIntField * ElementID_SADR_REGION)=0;

   __property TFIBLargeIntField * ElementIDBASE_SADR_REGION = {read = get_ElementIDBASE_SADR_REGION , write = set_ElementIDBASE_SADR_REGION};
   virtual TFIBLargeIntField * get_ElementIDBASE_SADR_REGION(void)=0;
   virtual void set_ElementIDBASE_SADR_REGION(TFIBLargeIntField * ElementIDBASE_SADR_REGION)=0;

   __property TFIBWideStringField * ElementNAME_SADR_REGION = {read = get_ElementNAME_SADR_REGION , write = set_ElementNAME_SADR_REGION};
   virtual TFIBWideStringField * get_ElementNAME_SADR_REGION(void)=0;
   virtual void set_ElementNAME_SADR_REGION(TFIBWideStringField * ElementNAME_SADR_REGION)=0;

   __property TFIBWideStringField * ElementCODE_SADR_REGION = {read = get_ElementCODE_SADR_REGION , write = set_ElementCODE_SADR_REGION};
   virtual TFIBWideStringField * get_ElementCODE_SADR_REGION(void)=0;
   virtual void set_ElementCODE_SADR_REGION(TFIBWideStringField * ElementCODE_SADR_REGION)=0;

   __property __int64 IdOwner = {read = get_IdOwner , write = set_IdOwner};
   virtual __int64 get_IdOwner(void)=0;
   virtual void set_IdOwner(__int64 IdOwner)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   virtual void OpenTable(__int64 id_owner)=0;
   virtual bool NewElement(__int64 id_owner)=0;
   virtual int OpenElement(__int64 id )=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
};
#define IID_IDMSprAddressRayon __uuidof(IDMSprAddressRayon)
#endif
