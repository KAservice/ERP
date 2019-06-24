#ifndef UIDMSprLossFactorH
#define UIDMSprLossFactorH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprLossFactor)) IDMSprLossFactor : public IMainInterface
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

   __property TFIBLargeIntField * TableID_SLOSS_FACTOR = {read = get_TableID_SLOSS_FACTOR , write = set_TableID_SLOSS_FACTOR};
   virtual TFIBLargeIntField * get_TableID_SLOSS_FACTOR(void)=0;
   virtual void set_TableID_SLOSS_FACTOR(TFIBLargeIntField * TableID_SLOSS_FACTOR)=0;

   __property TFIBWideStringField * TableGID_SLOSS_FACTOR = {read = get_TableGID_SLOSS_FACTOR , write = set_TableGID_SLOSS_FACTOR};
   virtual TFIBWideStringField * get_TableGID_SLOSS_FACTOR(void)=0;
   virtual void set_TableGID_SLOSS_FACTOR(TFIBWideStringField * TableGID_SLOSS_FACTOR)=0;

   __property TFIBLargeIntField * TableIDBASE_SLOSS_FACTOR = {read = get_TableIDBASE_SLOSS_FACTOR , write = set_TableIDBASE_SLOSS_FACTOR};
   virtual TFIBLargeIntField * get_TableIDBASE_SLOSS_FACTOR(void)=0;
   virtual void set_TableIDBASE_SLOSS_FACTOR(TFIBLargeIntField * TableIDBASE_SLOSS_FACTOR)=0;

   __property TFIBWideStringField * TableNAME_SLOSS_FACTOR = {read = get_TableNAME_SLOSS_FACTOR , write = set_TableNAME_SLOSS_FACTOR};
   virtual TFIBWideStringField * get_TableNAME_SLOSS_FACTOR(void)=0;
   virtual void set_TableNAME_SLOSS_FACTOR(TFIBWideStringField * TableNAME_SLOSS_FACTOR)=0;

   __property TFIBWideStringField * TableCOMMENT_SLOSS_FACTOR = {read = get_TableCOMMENT_SLOSS_FACTOR , write = set_TableCOMMENT_SLOSS_FACTOR};
   virtual TFIBWideStringField * get_TableCOMMENT_SLOSS_FACTOR(void)=0;
   virtual void set_TableCOMMENT_SLOSS_FACTOR(TFIBWideStringField * TableCOMMENT_SLOSS_FACTOR)=0;

   __property TFIBBCDField * TableENCEN_SLOSS_FACTOR = {read = get_TableENCEN_SLOSS_FACTOR , write = set_TableENCEN_SLOSS_FACTOR};
   virtual TFIBBCDField * get_TableENCEN_SLOSS_FACTOR(void)=0;
   virtual void set_TableENCEN_SLOSS_FACTOR(TFIBBCDField * TableENCEN_SLOSS_FACTOR)=0;

   __property TFIBBCDField * TableBELKI_SLOSS_FACTOR = {read = get_TableBELKI_SLOSS_FACTOR , write = set_TableBELKI_SLOSS_FACTOR};
   virtual TFIBBCDField * get_TableBELKI_SLOSS_FACTOR(void)=0;
   virtual void set_TableBELKI_SLOSS_FACTOR(TFIBBCDField * TableBELKI_SLOSS_FACTOR)=0;

   __property TFIBBCDField * TableGIRI_SLOSS_FACTOR = {read = get_TableGIRI_SLOSS_FACTOR , write = set_TableGIRI_SLOSS_FACTOR};
   virtual TFIBBCDField * get_TableGIRI_SLOSS_FACTOR(void)=0;
   virtual void set_TableGIRI_SLOSS_FACTOR(TFIBBCDField * TableGIRI_SLOSS_FACTOR)=0;

   __property TFIBBCDField * TableUGL_SLOSS_FACTOR = {read = get_TableUGL_SLOSS_FACTOR , write = set_TableUGL_SLOSS_FACTOR};
   virtual TFIBBCDField * get_TableUGL_SLOSS_FACTOR(void)=0;
   virtual void set_TableUGL_SLOSS_FACTOR(TFIBBCDField * TableUGL_SLOSS_FACTOR)=0;

   __property TFIBWideStringField * TableCODE_SLOSS_FACTOR = {read = get_TableCODE_SLOSS_FACTOR , write = set_TableCODE_SLOSS_FACTOR};
   virtual TFIBWideStringField * get_TableCODE_SLOSS_FACTOR(void)=0;
   virtual void set_TableCODE_SLOSS_FACTOR(TFIBWideStringField * TableCODE_SLOSS_FACTOR)=0;

   __property TFIBLargeIntField * TableIDGRP_SLOSS_FACTOR = {read = get_TableIDGRP_SLOSS_FACTOR , write = set_TableIDGRP_SLOSS_FACTOR};
   virtual TFIBLargeIntField * get_TableIDGRP_SLOSS_FACTOR(void)=0;
   virtual void set_TableIDGRP_SLOSS_FACTOR(TFIBLargeIntField * TableIDGRP_SLOSS_FACTOR)=0;

   __property TFIBLargeIntField * ElementID_SLOSS_FACTOR = {read = get_ElementID_SLOSS_FACTOR , write = set_ElementID_SLOSS_FACTOR};
   virtual TFIBLargeIntField * get_ElementID_SLOSS_FACTOR(void)=0;
   virtual void set_ElementID_SLOSS_FACTOR(TFIBLargeIntField * ElementID_SLOSS_FACTOR)=0;

   __property TFIBWideStringField * ElementGID_SLOSS_FACTOR = {read = get_ElementGID_SLOSS_FACTOR , write = set_ElementGID_SLOSS_FACTOR};
   virtual TFIBWideStringField * get_ElementGID_SLOSS_FACTOR(void)=0;
   virtual void set_ElementGID_SLOSS_FACTOR(TFIBWideStringField * ElementGID_SLOSS_FACTOR)=0;

   __property TFIBLargeIntField * ElementIDBASE_SLOSS_FACTOR = {read = get_ElementIDBASE_SLOSS_FACTOR , write = set_ElementIDBASE_SLOSS_FACTOR};
   virtual TFIBLargeIntField * get_ElementIDBASE_SLOSS_FACTOR(void)=0;
   virtual void set_ElementIDBASE_SLOSS_FACTOR(TFIBLargeIntField * ElementIDBASE_SLOSS_FACTOR)=0;

   __property TFIBWideStringField * ElementNAME_SLOSS_FACTOR = {read = get_ElementNAME_SLOSS_FACTOR , write = set_ElementNAME_SLOSS_FACTOR};
   virtual TFIBWideStringField * get_ElementNAME_SLOSS_FACTOR(void)=0;
   virtual void set_ElementNAME_SLOSS_FACTOR(TFIBWideStringField * ElementNAME_SLOSS_FACTOR)=0;

   __property TFIBWideStringField * ElementCOMMENT_SLOSS_FACTOR = {read = get_ElementCOMMENT_SLOSS_FACTOR , write = set_ElementCOMMENT_SLOSS_FACTOR};
   virtual TFIBWideStringField * get_ElementCOMMENT_SLOSS_FACTOR(void)=0;
   virtual void set_ElementCOMMENT_SLOSS_FACTOR(TFIBWideStringField * ElementCOMMENT_SLOSS_FACTOR)=0;

   __property TFIBBCDField * ElementENCEN_SLOSS_FACTOR = {read = get_ElementENCEN_SLOSS_FACTOR , write = set_ElementENCEN_SLOSS_FACTOR};
   virtual TFIBBCDField * get_ElementENCEN_SLOSS_FACTOR(void)=0;
   virtual void set_ElementENCEN_SLOSS_FACTOR(TFIBBCDField * ElementENCEN_SLOSS_FACTOR)=0;

   __property TFIBBCDField * ElementBELKI_SLOSS_FACTOR = {read = get_ElementBELKI_SLOSS_FACTOR , write = set_ElementBELKI_SLOSS_FACTOR};
   virtual TFIBBCDField * get_ElementBELKI_SLOSS_FACTOR(void)=0;
   virtual void set_ElementBELKI_SLOSS_FACTOR(TFIBBCDField * ElementBELKI_SLOSS_FACTOR)=0;

   __property TFIBBCDField * ElementGIRI_SLOSS_FACTOR = {read = get_ElementGIRI_SLOSS_FACTOR , write = set_ElementGIRI_SLOSS_FACTOR};
   virtual TFIBBCDField * get_ElementGIRI_SLOSS_FACTOR(void)=0;
   virtual void set_ElementGIRI_SLOSS_FACTOR(TFIBBCDField * ElementGIRI_SLOSS_FACTOR)=0;

   __property TFIBBCDField * ElementUGL_SLOSS_FACTOR = {read = get_ElementUGL_SLOSS_FACTOR , write = set_ElementUGL_SLOSS_FACTOR};
   virtual TFIBBCDField * get_ElementUGL_SLOSS_FACTOR(void)=0;
   virtual void set_ElementUGL_SLOSS_FACTOR(TFIBBCDField * ElementUGL_SLOSS_FACTOR)=0;

   __property TFIBWideStringField * ElementCODE_SLOSS_FACTOR = {read = get_ElementCODE_SLOSS_FACTOR , write = set_ElementCODE_SLOSS_FACTOR};
   virtual TFIBWideStringField * get_ElementCODE_SLOSS_FACTOR(void)=0;
   virtual void set_ElementCODE_SLOSS_FACTOR(TFIBWideStringField * ElementCODE_SLOSS_FACTOR)=0;

   __property TFIBLargeIntField * ElementIDGRP_SLOSS_FACTOR = {read = get_ElementIDGRP_SLOSS_FACTOR , write = set_ElementIDGRP_SLOSS_FACTOR};
   virtual TFIBLargeIntField * get_ElementIDGRP_SLOSS_FACTOR(void)=0;
   virtual void set_ElementIDGRP_SLOSS_FACTOR(TFIBLargeIntField * ElementIDGRP_SLOSS_FACTOR)=0;

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
#define IID_IDMSprLossFactor __uuidof(IDMSprLossFactor)
#endif
