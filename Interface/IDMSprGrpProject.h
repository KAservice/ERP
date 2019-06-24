#ifndef UIDMSprGrpProjectH
#define UIDMSprGrpProjectH
#include "IMainInterface.h"
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{97F877F2-B7D3-4CA2-97DB-727650F26627}")) IDMSprGrpProject : public IMainInterface
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

   __property TFIBBCDField * TableID_SGRPPROJECT = {read = get_TableID_SGRPPROJECT , write = set_TableID_SGRPPROJECT};
   virtual TFIBBCDField * get_TableID_SGRPPROJECT(void)=0;
   virtual void set_TableID_SGRPPROJECT(TFIBBCDField * TableID_SGRPPROJECT)=0;

   __property TFIBBCDField * TableIDGRP_SGRPPROJECT = {read = get_TableIDGRP_SGRPPROJECT , write = set_TableIDGRP_SGRPPROJECT};
   virtual TFIBBCDField * get_TableIDGRP_SGRPPROJECT(void)=0;
   virtual void set_TableIDGRP_SGRPPROJECT(TFIBBCDField * TableIDGRP_SGRPPROJECT)=0;

   __property TFIBBCDField * ElementID_SGRPPROJECT = {read = get_ElementID_SGRPPROJECT , write = set_ElementID_SGRPPROJECT};
   virtual TFIBBCDField * get_ElementID_SGRPPROJECT(void)=0;
   virtual void set_ElementID_SGRPPROJECT(TFIBBCDField * ElementID_SGRPPROJECT)=0;

   __property TFIBBCDField * ElementIDGRP_SGRPPROJECT = {read = get_ElementIDGRP_SGRPPROJECT , write = set_ElementIDGRP_SGRPPROJECT};
   virtual TFIBBCDField * get_ElementIDGRP_SGRPPROJECT(void)=0;
   virtual void set_ElementIDGRP_SGRPPROJECT(TFIBBCDField * ElementIDGRP_SGRPPROJECT)=0;

   __property TFIBWideStringField * TableNAME_SGRPPROJECT = {read = get_TableNAME_SGRPPROJECT , write = set_TableNAME_SGRPPROJECT};
   virtual TFIBWideStringField * get_TableNAME_SGRPPROJECT(void)=0;
   virtual void set_TableNAME_SGRPPROJECT(TFIBWideStringField * TableNAME_SGRPPROJECT)=0;

   __property TFIBWideStringField * ElementNAME_SGRPPROJECT = {read = get_ElementNAME_SGRPPROJECT , write = set_ElementNAME_SGRPPROJECT};
   virtual TFIBWideStringField * get_ElementNAME_SGRPPROJECT(void)=0;
   virtual void set_ElementNAME_SGRPPROJECT(TFIBWideStringField * ElementNAME_SGRPPROJECT)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement(__int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual __int64 FindPoName(AnsiString name)=0;
};
#define IID_IDMSprGrpProject __uuidof(IDMSprGrpProject)
#endif
