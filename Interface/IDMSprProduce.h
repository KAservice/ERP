#ifndef UIDMSprProduceH
#define UIDMSprProduceH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprProduce)) IDMSprProduce : public IMainInterface
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

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

   __property TFIBLargeIntField * ElementID_SPRODUCE = {read = get_ElementID_SPRODUCE , write = set_ElementID_SPRODUCE};
   virtual TFIBLargeIntField * get_ElementID_SPRODUCE(void)=0;
   virtual void set_ElementID_SPRODUCE(TFIBLargeIntField * ElementID_SPRODUCE)=0;

   __property TFIBWideStringField * ElementGID_SPRODUCE = {read = get_ElementGID_SPRODUCE , write = set_ElementGID_SPRODUCE};
   virtual TFIBWideStringField * get_ElementGID_SPRODUCE(void)=0;
   virtual void set_ElementGID_SPRODUCE(TFIBWideStringField * ElementGID_SPRODUCE)=0;

   __property TFIBLargeIntField * ElementIDBASE_SPRODUCE = {read = get_ElementIDBASE_SPRODUCE , write = set_ElementIDBASE_SPRODUCE};
   virtual TFIBLargeIntField * get_ElementIDBASE_SPRODUCE(void)=0;
   virtual void set_ElementIDBASE_SPRODUCE(TFIBLargeIntField * ElementIDBASE_SPRODUCE)=0;

   __property TFIBLargeIntField * ElementIDGRP_SPRODUCE = {read = get_ElementIDGRP_SPRODUCE , write = set_ElementIDGRP_SPRODUCE};
   virtual TFIBLargeIntField * get_ElementIDGRP_SPRODUCE(void)=0;
   virtual void set_ElementIDGRP_SPRODUCE(TFIBLargeIntField * ElementIDGRP_SPRODUCE)=0;

   __property TFIBWideStringField * ElementNAME_SPRODUCE = {read = get_ElementNAME_SPRODUCE , write = set_ElementNAME_SPRODUCE};
   virtual TFIBWideStringField * get_ElementNAME_SPRODUCE(void)=0;
   virtual void set_ElementNAME_SPRODUCE(TFIBWideStringField * ElementNAME_SPRODUCE)=0;

   __property TFIBWideStringField * ElementCODE_SPRODUCE = {read = get_ElementCODE_SPRODUCE , write = set_ElementCODE_SPRODUCE};
   virtual TFIBWideStringField * get_ElementCODE_SPRODUCE(void)=0;
   virtual void set_ElementCODE_SPRODUCE(TFIBWideStringField * ElementCODE_SPRODUCE)=0;

   __property TFIBBCDField * ElementBELKI_SPRODUCE = {read = get_ElementBELKI_SPRODUCE , write = set_ElementBELKI_SPRODUCE};
   virtual TFIBBCDField * get_ElementBELKI_SPRODUCE(void)=0;
   virtual void set_ElementBELKI_SPRODUCE(TFIBBCDField * ElementBELKI_SPRODUCE)=0;

   __property TFIBBCDField * ElementGIRI_SPRODUCE = {read = get_ElementGIRI_SPRODUCE , write = set_ElementGIRI_SPRODUCE};
   virtual TFIBBCDField * get_ElementGIRI_SPRODUCE(void)=0;
   virtual void set_ElementGIRI_SPRODUCE(TFIBBCDField * ElementGIRI_SPRODUCE)=0;

   __property TFIBBCDField * ElementUGL_SPRODUCE = {read = get_ElementUGL_SPRODUCE , write = set_ElementUGL_SPRODUCE};
   virtual TFIBBCDField * get_ElementUGL_SPRODUCE(void)=0;
   virtual void set_ElementUGL_SPRODUCE(TFIBBCDField * ElementUGL_SPRODUCE)=0;

   __property TFIBWideStringField * ElementCOMMENT_SPRODUCE = {read = get_ElementCOMMENT_SPRODUCE , write = set_ElementCOMMENT_SPRODUCE};
   virtual TFIBWideStringField * get_ElementCOMMENT_SPRODUCE(void)=0;
   virtual void set_ElementCOMMENT_SPRODUCE(TFIBWideStringField * ElementCOMMENT_SPRODUCE)=0;

   __property TFIBLargeIntField * TableID_SPRODUCE = {read = get_TableID_SPRODUCE , write = set_TableID_SPRODUCE};
   virtual TFIBLargeIntField * get_TableID_SPRODUCE(void)=0;
   virtual void set_TableID_SPRODUCE(TFIBLargeIntField * TableID_SPRODUCE)=0;

   __property TFIBWideStringField * TableGID_SPRODUCE = {read = get_TableGID_SPRODUCE , write = set_TableGID_SPRODUCE};
   virtual TFIBWideStringField * get_TableGID_SPRODUCE(void)=0;
   virtual void set_TableGID_SPRODUCE(TFIBWideStringField * TableGID_SPRODUCE)=0;

   __property TFIBLargeIntField * TableIDBASE_SPRODUCE = {read = get_TableIDBASE_SPRODUCE , write = set_TableIDBASE_SPRODUCE};
   virtual TFIBLargeIntField * get_TableIDBASE_SPRODUCE(void)=0;
   virtual void set_TableIDBASE_SPRODUCE(TFIBLargeIntField * TableIDBASE_SPRODUCE)=0;

   __property TFIBLargeIntField * TableIDGRP_SPRODUCE = {read = get_TableIDGRP_SPRODUCE , write = set_TableIDGRP_SPRODUCE};
   virtual TFIBLargeIntField * get_TableIDGRP_SPRODUCE(void)=0;
   virtual void set_TableIDGRP_SPRODUCE(TFIBLargeIntField * TableIDGRP_SPRODUCE)=0;

   __property TFIBWideStringField * TableNAME_SPRODUCE = {read = get_TableNAME_SPRODUCE , write = set_TableNAME_SPRODUCE};
   virtual TFIBWideStringField * get_TableNAME_SPRODUCE(void)=0;
   virtual void set_TableNAME_SPRODUCE(TFIBWideStringField * TableNAME_SPRODUCE)=0;

   __property TFIBWideStringField * TableCODE_SPRODUCE = {read = get_TableCODE_SPRODUCE , write = set_TableCODE_SPRODUCE};
   virtual TFIBWideStringField * get_TableCODE_SPRODUCE(void)=0;
   virtual void set_TableCODE_SPRODUCE(TFIBWideStringField * TableCODE_SPRODUCE)=0;

   __property TFIBBCDField * TableBELKI_SPRODUCE = {read = get_TableBELKI_SPRODUCE , write = set_TableBELKI_SPRODUCE};
   virtual TFIBBCDField * get_TableBELKI_SPRODUCE(void)=0;
   virtual void set_TableBELKI_SPRODUCE(TFIBBCDField * TableBELKI_SPRODUCE)=0;

   __property TFIBBCDField * TableGIRI_SPRODUCE = {read = get_TableGIRI_SPRODUCE , write = set_TableGIRI_SPRODUCE};
   virtual TFIBBCDField * get_TableGIRI_SPRODUCE(void)=0;
   virtual void set_TableGIRI_SPRODUCE(TFIBBCDField * TableGIRI_SPRODUCE)=0;

   __property TFIBBCDField * TableUGL_SPRODUCE = {read = get_TableUGL_SPRODUCE , write = set_TableUGL_SPRODUCE};
   virtual TFIBBCDField * get_TableUGL_SPRODUCE(void)=0;
   virtual void set_TableUGL_SPRODUCE(TFIBBCDField * TableUGL_SPRODUCE)=0;

   __property TFIBWideStringField * TableCOMMENT_SPRODUCE = {read = get_TableCOMMENT_SPRODUCE , write = set_TableCOMMENT_SPRODUCE};
   virtual TFIBWideStringField * get_TableCOMMENT_SPRODUCE(void)=0;
   virtual void set_TableCOMMENT_SPRODUCE(TFIBWideStringField * TableCOMMENT_SPRODUCE)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   virtual bool OpenTable(__int64 id_grp, bool all)=0;
   virtual UnicodeString GetTextQuery(__int64 id_grp, bool all)=0;
   virtual bool OpenElement(__int64 id )=0;
   virtual bool NewElement(__int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual bool ChancheGrp(__int64 id_new_grp,__int64 id_el)=0;
   virtual __int64 FindPoName(UnicodeString name)=0;
   virtual __int64 GetIDElement(UnicodeString gid)=0;
   virtual UnicodeString GetGIDElement(__int64 id)=0;
   virtual __int64 GetIdGrp(__int64 id_el)=0;
};
#define IID_IDMSprProduce __uuidof(IDMSprProduce)
#endif
