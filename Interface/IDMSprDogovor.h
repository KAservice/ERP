#ifndef UIDMSprDogovorH
#define UIDMSprDogovorH
#include "IMainInterface.h"
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{F5AAE2F8-8AC0-4D79-AE95-B5828F022322}")) IDMSprDogovor : public IMainInterface
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

   __property TFIBDateField * TableDO_SDOG = {read = get_TableDO_SDOG , write = set_TableDO_SDOG};
   virtual TFIBDateField * get_TableDO_SDOG(void)=0;
   virtual void set_TableDO_SDOG(TFIBDateField * TableDO_SDOG)=0;

   __property TFIBIntegerField * TableWAYPAY_SDOG = {read = get_TableWAYPAY_SDOG , write = set_TableWAYPAY_SDOG};
   virtual TFIBIntegerField * get_TableWAYPAY_SDOG(void)=0;
   virtual void set_TableWAYPAY_SDOG(TFIBIntegerField * TableWAYPAY_SDOG)=0;

   __property TFIBBCDField * TableMAXSUMCREDIT_SDOG = {read = get_TableMAXSUMCREDIT_SDOG , write = set_TableMAXSUMCREDIT_SDOG};
   virtual TFIBBCDField * get_TableMAXSUMCREDIT_SDOG(void)=0;
   virtual void set_TableMAXSUMCREDIT_SDOG(TFIBBCDField * TableMAXSUMCREDIT_SDOG)=0;

   __property TFIBIntegerField * TableSROK_SDOG = {read = get_TableSROK_SDOG , write = set_TableSROK_SDOG};
   virtual TFIBIntegerField * get_TableSROK_SDOG(void)=0;
   virtual void set_TableSROK_SDOG(TFIBIntegerField * TableSROK_SDOG)=0;

   __property TFIBDateField * TableDATE_SDOG = {read = get_TableDATE_SDOG , write = set_TableDATE_SDOG};
   virtual TFIBDateField * get_TableDATE_SDOG(void)=0;
   virtual void set_TableDATE_SDOG(TFIBDateField * TableDATE_SDOG)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBDateField * ElementDO_SDOG = {read = get_ElementDO_SDOG , write = set_ElementDO_SDOG};
   virtual TFIBDateField * get_ElementDO_SDOG(void)=0;
   virtual void set_ElementDO_SDOG(TFIBDateField * ElementDO_SDOG)=0;

   __property TFIBIntegerField * ElementWAYPAY_SDOG = {read = get_ElementWAYPAY_SDOG , write = set_ElementWAYPAY_SDOG};
   virtual TFIBIntegerField * get_ElementWAYPAY_SDOG(void)=0;
   virtual void set_ElementWAYPAY_SDOG(TFIBIntegerField * ElementWAYPAY_SDOG)=0;

   __property TFIBBCDField * ElementMAXSUMCREDIT_SDOG = {read = get_ElementMAXSUMCREDIT_SDOG , write = set_ElementMAXSUMCREDIT_SDOG};
   virtual TFIBBCDField * get_ElementMAXSUMCREDIT_SDOG(void)=0;
   virtual void set_ElementMAXSUMCREDIT_SDOG(TFIBBCDField * ElementMAXSUMCREDIT_SDOG)=0;

   __property TFIBIntegerField * ElementSROK_SDOG = {read = get_ElementSROK_SDOG , write = set_ElementSROK_SDOG};
   virtual TFIBIntegerField * get_ElementSROK_SDOG(void)=0;
   virtual void set_ElementSROK_SDOG(TFIBIntegerField * ElementSROK_SDOG)=0;

   __property TFIBDateField * ElementDATE_SDOG = {read = get_ElementDATE_SDOG , write = set_ElementDATE_SDOG};
   virtual TFIBDateField * get_ElementDATE_SDOG(void)=0;
   virtual void set_ElementDATE_SDOG(TFIBDateField * ElementDATE_SDOG)=0;

   __property TFIBBCDField * TableID_SDOG = {read = get_TableID_SDOG , write = set_TableID_SDOG};
   virtual TFIBBCDField * get_TableID_SDOG(void)=0;
   virtual void set_TableID_SDOG(TFIBBCDField * TableID_SDOG)=0;

   __property TFIBBCDField * TableIDKLIENT_SDOG = {read = get_TableIDKLIENT_SDOG , write = set_TableIDKLIENT_SDOG};
   virtual TFIBBCDField * get_TableIDKLIENT_SDOG(void)=0;
   virtual void set_TableIDKLIENT_SDOG(TFIBBCDField * TableIDKLIENT_SDOG)=0;

   __property TFIBBCDField * TableIDTPRICE_SDOG = {read = get_TableIDTPRICE_SDOG , write = set_TableIDTPRICE_SDOG};
   virtual TFIBBCDField * get_TableIDTPRICE_SDOG(void)=0;
   virtual void set_TableIDTPRICE_SDOG(TFIBBCDField * TableIDTPRICE_SDOG)=0;

   __property TFIBBCDField * ElementID_SDOG = {read = get_ElementID_SDOG , write = set_ElementID_SDOG};
   virtual TFIBBCDField * get_ElementID_SDOG(void)=0;
   virtual void set_ElementID_SDOG(TFIBBCDField * ElementID_SDOG)=0;

   __property TFIBBCDField * ElementIDKLIENT_SDOG = {read = get_ElementIDKLIENT_SDOG , write = set_ElementIDKLIENT_SDOG};
   virtual TFIBBCDField * get_ElementIDKLIENT_SDOG(void)=0;
   virtual void set_ElementIDKLIENT_SDOG(TFIBBCDField * ElementIDKLIENT_SDOG)=0;

   __property TFIBBCDField * ElementIDTPRICE_SDOG = {read = get_ElementIDTPRICE_SDOG , write = set_ElementIDTPRICE_SDOG};
   virtual TFIBBCDField * get_ElementIDTPRICE_SDOG(void)=0;
   virtual void set_ElementIDTPRICE_SDOG(TFIBBCDField * ElementIDTPRICE_SDOG)=0;

   __property TFIBWideStringField * TableNAME_SDOG = {read = get_TableNAME_SDOG , write = set_TableNAME_SDOG};
   virtual TFIBWideStringField * get_TableNAME_SDOG(void)=0;
   virtual void set_TableNAME_SDOG(TFIBWideStringField * TableNAME_SDOG)=0;

   __property TFIBWideStringField * TableGID_SDOG = {read = get_TableGID_SDOG , write = set_TableGID_SDOG};
   virtual TFIBWideStringField * get_TableGID_SDOG(void)=0;
   virtual void set_TableGID_SDOG(TFIBWideStringField * TableGID_SDOG)=0;

   __property TFIBWideStringField * TableNUMBER_SDOG = {read = get_TableNUMBER_SDOG , write = set_TableNUMBER_SDOG};
   virtual TFIBWideStringField * get_TableNUMBER_SDOG(void)=0;
   virtual void set_TableNUMBER_SDOG(TFIBWideStringField * TableNUMBER_SDOG)=0;

   __property TFIBWideStringField * ElementNAME_SDOG = {read = get_ElementNAME_SDOG , write = set_ElementNAME_SDOG};
   virtual TFIBWideStringField * get_ElementNAME_SDOG(void)=0;
   virtual void set_ElementNAME_SDOG(TFIBWideStringField * ElementNAME_SDOG)=0;

   __property TFIBWideStringField * ElementGID_SDOG = {read = get_ElementGID_SDOG , write = set_ElementGID_SDOG};
   virtual TFIBWideStringField * get_ElementGID_SDOG(void)=0;
   virtual void set_ElementGID_SDOG(TFIBWideStringField * ElementGID_SDOG)=0;

   __property TFIBWideStringField * ElementNUMBER_SDOG = {read = get_ElementNUMBER_SDOG , write = set_ElementNUMBER_SDOG};
   virtual TFIBWideStringField * get_ElementNUMBER_SDOG(void)=0;
   virtual void set_ElementNUMBER_SDOG(TFIBWideStringField * ElementNUMBER_SDOG)=0;

   __property __int64 IdKlient = {read = get_IdKlient , write = set_IdKlient};
   virtual __int64 get_IdKlient(void)=0;
   virtual void set_IdKlient(__int64 IdKlient)=0;

   __property bool flSaveElement = {read = get_flSaveElement , write = set_flSaveElement};
   virtual bool get_flSaveElement(void)=0;
   virtual void set_flSaveElement(bool flSaveElement)=0;

   virtual void OpenTable(__int64 IdKl)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual void NewElement(__int64 IdKl)=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 Id)=0;
};
#define IID_IDMSprDogovor __uuidof(IDMSprDogovor)
#endif
