#ifndef UIDMSprNomAnalogH
#define UIDMSprNomAnalogH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprNomAnalog)) IDMSprNomAnalog : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TDataSource * DataSourcePodr = {read = get_DataSourcePodr , write = set_DataSourcePodr};
   virtual TDataSource * get_DataSourcePodr(void)=0;
   virtual void set_DataSourcePodr(TDataSource * DataSourcePodr)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TFIBLargeIntField * TableID_SNOM_ANALOG = {read = get_TableID_SNOM_ANALOG , write = set_TableID_SNOM_ANALOG};
   virtual TFIBLargeIntField * get_TableID_SNOM_ANALOG(void)=0;
   virtual void set_TableID_SNOM_ANALOG(TFIBLargeIntField * TableID_SNOM_ANALOG)=0;

   __property TFIBLargeIntField * TableIDBASE_SNOM_ANALOG = {read = get_TableIDBASE_SNOM_ANALOG , write = set_TableIDBASE_SNOM_ANALOG};
   virtual TFIBLargeIntField * get_TableIDBASE_SNOM_ANALOG(void)=0;
   virtual void set_TableIDBASE_SNOM_ANALOG(TFIBLargeIntField * TableIDBASE_SNOM_ANALOG)=0;

   __property TFIBWideStringField * TableGID_SNOM_ANALOG = {read = get_TableGID_SNOM_ANALOG , write = set_TableGID_SNOM_ANALOG};
   virtual TFIBWideStringField * get_TableGID_SNOM_ANALOG(void)=0;
   virtual void set_TableGID_SNOM_ANALOG(TFIBWideStringField * TableGID_SNOM_ANALOG)=0;

   __property TFIBLargeIntField * TableIDNOM_SNOM_ANALOG = {read = get_TableIDNOM_SNOM_ANALOG , write = set_TableIDNOM_SNOM_ANALOG};
   virtual TFIBLargeIntField * get_TableIDNOM_SNOM_ANALOG(void)=0;
   virtual void set_TableIDNOM_SNOM_ANALOG(TFIBLargeIntField * TableIDNOM_SNOM_ANALOG)=0;

   __property TFIBLargeIntField * TableIDNOMANALOG_SNOM_ANALOG = {read = get_TableIDNOMANALOG_SNOM_ANALOG , write = set_TableIDNOMANALOG_SNOM_ANALOG};
   virtual TFIBLargeIntField * get_TableIDNOMANALOG_SNOM_ANALOG(void)=0;
   virtual void set_TableIDNOMANALOG_SNOM_ANALOG(TFIBLargeIntField * TableIDNOMANALOG_SNOM_ANALOG)=0;

   __property TFIBLargeIntField * TableIDTYPEANALOG_SNOM_ANALOG = {read = get_TableIDTYPEANALOG_SNOM_ANALOG , write = set_TableIDTYPEANALOG_SNOM_ANALOG};
   virtual TFIBLargeIntField * get_TableIDTYPEANALOG_SNOM_ANALOG(void)=0;
   virtual void set_TableIDTYPEANALOG_SNOM_ANALOG(TFIBLargeIntField * TableIDTYPEANALOG_SNOM_ANALOG)=0;

   __property TFIBWideStringField * TableNAME_STYPE_ANALOG = {read = get_TableNAME_STYPE_ANALOG , write = set_TableNAME_STYPE_ANALOG};
   virtual TFIBWideStringField * get_TableNAME_STYPE_ANALOG(void)=0;
   virtual void set_TableNAME_STYPE_ANALOG(TFIBWideStringField * TableNAME_STYPE_ANALOG)=0;

   __property TFIBWideStringField * TableNAMENOM = {read = get_TableNAMENOM , write = set_TableNAMENOM};
   virtual TFIBWideStringField * get_TableNAMENOM(void)=0;
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)=0;

   __property TFIBWideStringField * TableARTNOM = {read = get_TableARTNOM , write = set_TableARTNOM};
   virtual TFIBWideStringField * get_TableARTNOM(void)=0;
   virtual void set_TableARTNOM(TFIBWideStringField * TableARTNOM)=0;

   __property TFIBIntegerField * TableCODENOM = {read = get_TableCODENOM , write = set_TableCODENOM};
   virtual TFIBIntegerField * get_TableCODENOM(void)=0;
   virtual void set_TableCODENOM(TFIBIntegerField * TableCODENOM)=0;

   __property TFIBWideStringField * TableNAMEED = {read = get_TableNAMEED , write = set_TableNAMEED};
   virtual TFIBWideStringField * get_TableNAMEED(void)=0;
   virtual void set_TableNAMEED(TFIBWideStringField * TableNAMEED)=0;

   __property TFIBWideStringField * TableSHED = {read = get_TableSHED , write = set_TableSHED};
   virtual TFIBWideStringField * get_TableSHED(void)=0;
   virtual void set_TableSHED(TFIBWideStringField * TableSHED)=0;

   __property TFIBBCDField * TableZNACH_PRICE = {read = get_TableZNACH_PRICE , write = set_TableZNACH_PRICE};
   virtual TFIBBCDField * get_TableZNACH_PRICE(void)=0;
   virtual void set_TableZNACH_PRICE(TFIBBCDField * TableZNACH_PRICE)=0;

   __property TFIBLargeIntField * ElementID_SNOM_ANALOG = {read = get_ElementID_SNOM_ANALOG , write = set_ElementID_SNOM_ANALOG};
   virtual TFIBLargeIntField * get_ElementID_SNOM_ANALOG(void)=0;
   virtual void set_ElementID_SNOM_ANALOG(TFIBLargeIntField * ElementID_SNOM_ANALOG)=0;

   __property TFIBLargeIntField * ElementIDBASE_SNOM_ANALOG = {read = get_ElementIDBASE_SNOM_ANALOG , write = set_ElementIDBASE_SNOM_ANALOG};
   virtual TFIBLargeIntField * get_ElementIDBASE_SNOM_ANALOG(void)=0;
   virtual void set_ElementIDBASE_SNOM_ANALOG(TFIBLargeIntField * ElementIDBASE_SNOM_ANALOG)=0;

   __property TFIBWideStringField * ElementGID_SNOM_ANALOG = {read = get_ElementGID_SNOM_ANALOG , write = set_ElementGID_SNOM_ANALOG};
   virtual TFIBWideStringField * get_ElementGID_SNOM_ANALOG(void)=0;
   virtual void set_ElementGID_SNOM_ANALOG(TFIBWideStringField * ElementGID_SNOM_ANALOG)=0;

   __property TFIBLargeIntField * ElementIDNOM_SNOM_ANALOG = {read = get_ElementIDNOM_SNOM_ANALOG , write = set_ElementIDNOM_SNOM_ANALOG};
   virtual TFIBLargeIntField * get_ElementIDNOM_SNOM_ANALOG(void)=0;
   virtual void set_ElementIDNOM_SNOM_ANALOG(TFIBLargeIntField * ElementIDNOM_SNOM_ANALOG)=0;

   __property TFIBLargeIntField * ElementIDNOMANALOG_SNOM_ANALOG = {read = get_ElementIDNOMANALOG_SNOM_ANALOG , write = set_ElementIDNOMANALOG_SNOM_ANALOG};
   virtual TFIBLargeIntField * get_ElementIDNOMANALOG_SNOM_ANALOG(void)=0;
   virtual void set_ElementIDNOMANALOG_SNOM_ANALOG(TFIBLargeIntField * ElementIDNOMANALOG_SNOM_ANALOG)=0;

   __property TFIBLargeIntField * ElementIDTYPEANALOG_SNOM_ANALOG = {read = get_ElementIDTYPEANALOG_SNOM_ANALOG , write = set_ElementIDTYPEANALOG_SNOM_ANALOG};
   virtual TFIBLargeIntField * get_ElementIDTYPEANALOG_SNOM_ANALOG(void)=0;
   virtual void set_ElementIDTYPEANALOG_SNOM_ANALOG(TFIBLargeIntField * ElementIDTYPEANALOG_SNOM_ANALOG)=0;

   __property TFIBWideStringField * ElementNAME_STYPE_ANALOG = {read = get_ElementNAME_STYPE_ANALOG , write = set_ElementNAME_STYPE_ANALOG};
   virtual TFIBWideStringField * get_ElementNAME_STYPE_ANALOG(void)=0;
   virtual void set_ElementNAME_STYPE_ANALOG(TFIBWideStringField * ElementNAME_STYPE_ANALOG)=0;

   __property TFIBWideStringField * ElementNAMENOM = {read = get_ElementNAMENOM , write = set_ElementNAMENOM};
   virtual TFIBWideStringField * get_ElementNAMENOM(void)=0;
   virtual void set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM)=0;

   __property TFIBWideStringField * ElementARTNOM = {read = get_ElementARTNOM , write = set_ElementARTNOM};
   virtual TFIBWideStringField * get_ElementARTNOM(void)=0;
   virtual void set_ElementARTNOM(TFIBWideStringField * ElementARTNOM)=0;

   __property TFIBIntegerField * ElementCODENOM = {read = get_ElementCODENOM , write = set_ElementCODENOM};
   virtual TFIBIntegerField * get_ElementCODENOM(void)=0;
   virtual void set_ElementCODENOM(TFIBIntegerField * ElementCODENOM)=0;

   __property TFIBWideStringField * ElementNAMEED = {read = get_ElementNAMEED , write = set_ElementNAMEED};
   virtual TFIBWideStringField * get_ElementNAMEED(void)=0;
   virtual void set_ElementNAMEED(TFIBWideStringField * ElementNAMEED)=0;

   __property TFIBWideStringField * ElementSHED = {read = get_ElementSHED , write = set_ElementSHED};
   virtual TFIBWideStringField * get_ElementSHED(void)=0;
   virtual void set_ElementSHED(TFIBWideStringField * ElementSHED)=0;

   __property TpFIBDataSet * SpisokTypeAnalog = {read = get_SpisokTypeAnalog , write = set_SpisokTypeAnalog};
   virtual TpFIBDataSet * get_SpisokTypeAnalog(void)=0;
   virtual void set_SpisokTypeAnalog(TpFIBDataSet * SpisokTypeAnalog)=0;

   __property TDataSource * DataSourceSpisokTypeAnalog = {read = get_DataSourceSpisokTypeAnalog , write = set_DataSourceSpisokTypeAnalog};
   virtual TDataSource * get_DataSourceSpisokTypeAnalog(void)=0;
   virtual void set_DataSourceSpisokTypeAnalog(TDataSource * DataSourceSpisokTypeAnalog)=0;

   __property TFIBWideStringField * SpisokTypeAnalogNAME_STYPE_ANALOG = {read = get_SpisokTypeAnalogNAME_STYPE_ANALOG , write = set_SpisokTypeAnalogNAME_STYPE_ANALOG};
   virtual TFIBWideStringField * get_SpisokTypeAnalogNAME_STYPE_ANALOG(void)=0;
   virtual void set_SpisokTypeAnalogNAME_STYPE_ANALOG(TFIBWideStringField * SpisokTypeAnalogNAME_STYPE_ANALOG)=0;

   __property TFIBLargeIntField * SpisokTypeAnalogID_STYPE_ANALOG = {read = get_SpisokTypeAnalogID_STYPE_ANALOG , write = set_SpisokTypeAnalogID_STYPE_ANALOG};
   virtual TFIBLargeIntField * get_SpisokTypeAnalogID_STYPE_ANALOG(void)=0;
   virtual void set_SpisokTypeAnalogID_STYPE_ANALOG(TFIBLargeIntField * SpisokTypeAnalogID_STYPE_ANALOG)=0;

   __property TStringField * TableNAME_TYPE_ANALOG_LOOKUP = {read = get_TableNAME_TYPE_ANALOG_LOOKUP , write = set_TableNAME_TYPE_ANALOG_LOOKUP};
   virtual TStringField * get_TableNAME_TYPE_ANALOG_LOOKUP(void)=0;
   virtual void set_TableNAME_TYPE_ANALOG_LOOKUP(TStringField * TableNAME_TYPE_ANALOG_LOOKUP)=0;

   __property __int64 IdRodElement = {read = get_IdRodElement , write = set_IdRodElement};
   virtual __int64 get_IdRodElement(void)=0;
   virtual void set_IdRodElement(__int64 IdRodElement)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   __property __int64 IdTypePrice = {read = get_IdTypePrice , write = set_IdTypePrice};
   virtual __int64 get_IdTypePrice(void)=0;
   virtual void set_IdTypePrice(__int64 IdTypePrice)=0;

   virtual bool NewElement(__int64 id_rod_element)=0;
   virtual bool InsertElement(__int64 id_rod_element, __int64 id_nom)=0;
   virtual bool OpenElement(__int64 id)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual bool SaveElement(void)=0;
   virtual bool OpenTable(__int64 id_rod_element, __int64 id_type_price)=0;
   virtual bool TableSaveIsmen(void)=0;
   virtual bool TableCancelIsmen(void)=0;
   virtual bool TableNewElement(__int64 id_rod_element)=0;
   virtual bool TableAppend(void)=0;
   virtual bool TableDelete(void)=0;
   virtual bool TableEdit(void)=0;
   virtual bool TablePost(void)=0;
};
#define IID_IDMSprNomAnalog __uuidof(IDMSprNomAnalog)
#endif
