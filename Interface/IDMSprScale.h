#ifndef UIDMSprScaleH
#define UIDMSprScaleH
#include "IMainInterface.h"
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{22888ED4-F732-4DFD-9FB6-A65AF3A03D6B}")) IDMSprScale : public IMainInterface
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

   __property TFIBBCDField * ElementID_SSCALE = {read = get_ElementID_SSCALE , write = set_ElementID_SSCALE};
   virtual TFIBBCDField * get_ElementID_SSCALE(void)=0;
   virtual void set_ElementID_SSCALE(TFIBBCDField * ElementID_SSCALE)=0;

   __property TFIBBCDField * TableID_SSCALE = {read = get_TableID_SSCALE , write = set_TableID_SSCALE};
   virtual TFIBBCDField * get_TableID_SSCALE(void)=0;
   virtual void set_TableID_SSCALE(TFIBBCDField * TableID_SSCALE)=0;

   __property TFIBWideStringField * TableGID_SSCALE = {read = get_TableGID_SSCALE , write = set_TableGID_SSCALE};
   virtual TFIBWideStringField * get_TableGID_SSCALE(void)=0;
   virtual void set_TableGID_SSCALE(TFIBWideStringField * TableGID_SSCALE)=0;

   __property TFIBWideStringField * TableNAME_SSCALE = {read = get_TableNAME_SSCALE , write = set_TableNAME_SSCALE};
   virtual TFIBWideStringField * get_TableNAME_SSCALE(void)=0;
   virtual void set_TableNAME_SSCALE(TFIBWideStringField * TableNAME_SSCALE)=0;

   __property TFIBWideStringField * ElementGID_SSCALE = {read = get_ElementGID_SSCALE , write = set_ElementGID_SSCALE};
   virtual TFIBWideStringField * get_ElementGID_SSCALE(void)=0;
   virtual void set_ElementGID_SSCALE(TFIBWideStringField * ElementGID_SSCALE)=0;

   __property TFIBWideStringField * ElementNAME_SSCALE = {read = get_ElementNAME_SSCALE , write = set_ElementNAME_SSCALE};
   virtual TFIBWideStringField * get_ElementNAME_SSCALE(void)=0;
   virtual void set_ElementNAME_SSCALE(TFIBWideStringField * ElementNAME_SSCALE)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 id)=0;
   virtual __int64 GetIDElement(String gid)=0;
};
#define IID_IDMSprScale __uuidof(IDMSprScale)
#endif
