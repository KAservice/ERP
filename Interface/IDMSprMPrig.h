#ifndef UIDMSprMPrigH
#define UIDMSprMPrigH
#include "IMainInterface.h"
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{4ED640A4-6E43-44B7-A13F-D724E8888301}")) IDMSprMPrig : public IMainInterface
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

   __property TFIBBCDField * TableID_MPRIG = {read = get_TableID_MPRIG , write = set_TableID_MPRIG};
   virtual TFIBBCDField * get_TableID_MPRIG(void)=0;
   virtual void set_TableID_MPRIG(TFIBBCDField * TableID_MPRIG)=0;

   __property TFIBBCDField * TableIDSKLAD_MPRIG = {read = get_TableIDSKLAD_MPRIG , write = set_TableIDSKLAD_MPRIG};
   virtual TFIBBCDField * get_TableIDSKLAD_MPRIG(void)=0;
   virtual void set_TableIDSKLAD_MPRIG(TFIBBCDField * TableIDSKLAD_MPRIG)=0;

   __property TFIBBCDField * TableIDOBORUD_MPRIG = {read = get_TableIDOBORUD_MPRIG , write = set_TableIDOBORUD_MPRIG};
   virtual TFIBBCDField * get_TableIDOBORUD_MPRIG(void)=0;
   virtual void set_TableIDOBORUD_MPRIG(TFIBBCDField * TableIDOBORUD_MPRIG)=0;

   __property TFIBBCDField * ElementID_MPRIG = {read = get_ElementID_MPRIG , write = set_ElementID_MPRIG};
   virtual TFIBBCDField * get_ElementID_MPRIG(void)=0;
   virtual void set_ElementID_MPRIG(TFIBBCDField * ElementID_MPRIG)=0;

   __property TFIBBCDField * ElementIDSKLAD_MPRIG = {read = get_ElementIDSKLAD_MPRIG , write = set_ElementIDSKLAD_MPRIG};
   virtual TFIBBCDField * get_ElementIDSKLAD_MPRIG(void)=0;
   virtual void set_ElementIDSKLAD_MPRIG(TFIBBCDField * ElementIDSKLAD_MPRIG)=0;

   __property TFIBBCDField * ElementIDOBORUD_MPRIG = {read = get_ElementIDOBORUD_MPRIG , write = set_ElementIDOBORUD_MPRIG};
   virtual TFIBBCDField * get_ElementIDOBORUD_MPRIG(void)=0;
   virtual void set_ElementIDOBORUD_MPRIG(TFIBBCDField * ElementIDOBORUD_MPRIG)=0;

   __property TFIBBCDField * TableIDBASE_SMPRIG = {read = get_TableIDBASE_SMPRIG , write = set_TableIDBASE_SMPRIG};
   virtual TFIBBCDField * get_TableIDBASE_SMPRIG(void)=0;
   virtual void set_TableIDBASE_SMPRIG(TFIBBCDField * TableIDBASE_SMPRIG)=0;

   __property TFIBBCDField * ElementIDBASE_SMPRIG = {read = get_ElementIDBASE_SMPRIG , write = set_ElementIDBASE_SMPRIG};
   virtual TFIBBCDField * get_ElementIDBASE_SMPRIG(void)=0;
   virtual void set_ElementIDBASE_SMPRIG(TFIBBCDField * ElementIDBASE_SMPRIG)=0;

   __property TFIBWideStringField * TableNAME_MPRIG = {read = get_TableNAME_MPRIG , write = set_TableNAME_MPRIG};
   virtual TFIBWideStringField * get_TableNAME_MPRIG(void)=0;
   virtual void set_TableNAME_MPRIG(TFIBWideStringField * TableNAME_MPRIG)=0;

   __property TFIBWideStringField * TableGID_SMPRIG = {read = get_TableGID_SMPRIG , write = set_TableGID_SMPRIG};
   virtual TFIBWideStringField * get_TableGID_SMPRIG(void)=0;
   virtual void set_TableGID_SMPRIG(TFIBWideStringField * TableGID_SMPRIG)=0;

   __property TFIBWideStringField * TableNAMESKLAD = {read = get_TableNAMESKLAD , write = set_TableNAMESKLAD};
   virtual TFIBWideStringField * get_TableNAMESKLAD(void)=0;
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)=0;

   __property TFIBWideStringField * TableNAME_OBORUD = {read = get_TableNAME_OBORUD , write = set_TableNAME_OBORUD};
   virtual TFIBWideStringField * get_TableNAME_OBORUD(void)=0;
   virtual void set_TableNAME_OBORUD(TFIBWideStringField * TableNAME_OBORUD)=0;

   __property TFIBWideStringField * ElementNAME_MPRIG = {read = get_ElementNAME_MPRIG , write = set_ElementNAME_MPRIG};
   virtual TFIBWideStringField * get_ElementNAME_MPRIG(void)=0;
   virtual void set_ElementNAME_MPRIG(TFIBWideStringField * ElementNAME_MPRIG)=0;

   __property TFIBWideStringField * ElementGID_SMPRIG = {read = get_ElementGID_SMPRIG , write = set_ElementGID_SMPRIG};
   virtual TFIBWideStringField * get_ElementGID_SMPRIG(void)=0;
   virtual void set_ElementGID_SMPRIG(TFIBWideStringField * ElementGID_SMPRIG)=0;

   __property TFIBWideStringField * ElementNAMESKLAD = {read = get_ElementNAMESKLAD , write = set_ElementNAMESKLAD};
   virtual TFIBWideStringField * get_ElementNAMESKLAD(void)=0;
   virtual void set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD)=0;

   __property TFIBWideStringField * ElementNAME_OBORUD = {read = get_ElementNAME_OBORUD , write = set_ElementNAME_OBORUD};
   virtual TFIBWideStringField * get_ElementNAME_OBORUD(void)=0;
   virtual void set_ElementNAME_OBORUD(TFIBWideStringField * ElementNAME_OBORUD)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual void NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 Id)=0;
};
#define IID_IDMSprMPrig __uuidof(IDMSprMPrig)
#endif
