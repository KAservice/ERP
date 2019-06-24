#ifndef UIDMSetupH
#define UIDMSetupH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IDMSetup))IDMSetup : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TpFIBQuery * pFIBQKolPrDoc = {read = get_pFIBQKolPrDoc , write = set_pFIBQKolPrDoc};
   virtual TpFIBQuery * get_pFIBQKolPrDoc(void)=0;
   virtual void set_pFIBQKolPrDoc(TpFIBQuery * pFIBQKolPrDoc)=0;

   __property TFIBBCDField * ElementID_SETUP = {read = get_ElementID_SETUP , write = set_ElementID_SETUP};
   virtual TFIBBCDField * get_ElementID_SETUP(void)=0;
   virtual void set_ElementID_SETUP(TFIBBCDField * ElementID_SETUP)=0;

   __property TFIBBCDField * TableID_SETUP = {read = get_TableID_SETUP , write = set_TableID_SETUP};
   virtual TFIBBCDField * get_TableID_SETUP(void)=0;
   virtual void set_TableID_SETUP(TFIBBCDField * TableID_SETUP)=0;

   __property TFIBDateTimeField * TableVALUE_TIMESTAMP_SETUP = {read = get_TableVALUE_TIMESTAMP_SETUP , write = set_TableVALUE_TIMESTAMP_SETUP};
   virtual TFIBDateTimeField * get_TableVALUE_TIMESTAMP_SETUP(void)=0;
   virtual void set_TableVALUE_TIMESTAMP_SETUP(TFIBDateTimeField * TableVALUE_TIMESTAMP_SETUP)=0;

   __property TFIBDateTimeField * ElementVALUE_TIMESTAMP_SETUP = {read = get_ElementVALUE_TIMESTAMP_SETUP , write = set_ElementVALUE_TIMESTAMP_SETUP};
   virtual TFIBDateTimeField * get_ElementVALUE_TIMESTAMP_SETUP(void)=0;
   virtual void set_ElementVALUE_TIMESTAMP_SETUP(TFIBDateTimeField * ElementVALUE_TIMESTAMP_SETUP)=0;

   __property TFIBSmallIntField * TableTYPE_VALUE_SETUP = {read = get_TableTYPE_VALUE_SETUP , write = set_TableTYPE_VALUE_SETUP};
   virtual TFIBSmallIntField * get_TableTYPE_VALUE_SETUP(void)=0;
   virtual void set_TableTYPE_VALUE_SETUP(TFIBSmallIntField * TableTYPE_VALUE_SETUP)=0;

   __property TFIBSmallIntField * ElementTYPE_VALUE_SETUP = {read = get_ElementTYPE_VALUE_SETUP , write = set_ElementTYPE_VALUE_SETUP};
   virtual TFIBSmallIntField * get_ElementTYPE_VALUE_SETUP(void)=0;
   virtual void set_ElementTYPE_VALUE_SETUP(TFIBSmallIntField * ElementTYPE_VALUE_SETUP)=0;

   __property TFIBWideStringField * TableDESCRIPTION_SETUP = {read = get_TableDESCRIPTION_SETUP , write = set_TableDESCRIPTION_SETUP};
   virtual TFIBWideStringField * get_TableDESCRIPTION_SETUP(void)=0;
   virtual void set_TableDESCRIPTION_SETUP(TFIBWideStringField * TableDESCRIPTION_SETUP)=0;

   __property TFIBWideStringField * TableVALUE_SETUP = {read = get_TableVALUE_SETUP , write = set_TableVALUE_SETUP};
   virtual TFIBWideStringField * get_TableVALUE_SETUP(void)=0;
   virtual void set_TableVALUE_SETUP(TFIBWideStringField * TableVALUE_SETUP)=0;

   __property TFIBWideStringField * TableGID_SETUP = {read = get_TableGID_SETUP , write = set_TableGID_SETUP};
   virtual TFIBWideStringField * get_TableGID_SETUP(void)=0;
   virtual void set_TableGID_SETUP(TFIBWideStringField * TableGID_SETUP)=0;

   __property TFIBWideStringField * ElementDESCRIPTION_SETUP = {read = get_ElementDESCRIPTION_SETUP , write = set_ElementDESCRIPTION_SETUP};
   virtual TFIBWideStringField * get_ElementDESCRIPTION_SETUP(void)=0;
   virtual void set_ElementDESCRIPTION_SETUP(TFIBWideStringField * ElementDESCRIPTION_SETUP)=0;

   __property TFIBWideStringField * ElementVALUE_SETUP = {read = get_ElementVALUE_SETUP , write = set_ElementVALUE_SETUP};
   virtual TFIBWideStringField * get_ElementVALUE_SETUP(void)=0;
   virtual void set_ElementVALUE_SETUP(TFIBWideStringField * ElementVALUE_SETUP)=0;

   __property TFIBWideStringField * ElementGID_SETUP = {read = get_ElementGID_SETUP , write = set_ElementGID_SETUP};
   virtual TFIBWideStringField * get_ElementGID_SETUP(void)=0;
   virtual void set_ElementGID_SETUP(TFIBWideStringField * ElementGID_SETUP)=0;

   virtual void OpenTable(void)=0;
   virtual void SaveIsmen()=0;
   virtual void CancelIsmen()=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual void NewElement(void)=0;
   virtual void SaveElement(void)=0;
   virtual void DeleteElement(__int64 Id)=0;
   virtual void ProveritPosled( TDateTime  posDoc)=0;
   virtual int  GetKolProvDoc( TDateTime  posDoc)=0;
   virtual bool ProveritPosZapretaRed( TDateTime  posDoc)=0;
   virtual void ProveritPosledHotel( TDateTime  posDoc)=0;
   virtual int  GetKolProvDocHotel( TDateTime  posDoc)=0;
   virtual bool ProveritPosZapretaRedHotel( TDateTime  posDoc)=0;
   virtual void ProveritPosledRemont( TDateTime  posDoc)=0;
   virtual int  GetKolProvDocRemont( TDateTime  posDoc)=0;
   virtual bool ProveritPosZapretaRedRemont( TDateTime  posDoc)=0;
};
#define IID_IDMSetup __uuidof(IDMSetup)
#endif
