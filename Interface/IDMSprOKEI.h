#ifndef UIDMSprOKEIH
#define UIDMSprOKEIH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>
class __declspec(uuid("{C44F5A59-C18F-49BC-8E21-6E583C10D9B9}")) IDMSprOKEI : public IMainInterface
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

   __property TFIBBCDField * TableIDOKEI = {read = get_TableIDOKEI , write = set_TableIDOKEI};
   virtual TFIBBCDField * get_TableIDOKEI(void)=0;
   virtual void set_TableIDOKEI(TFIBBCDField * TableIDOKEI)=0;

   __property TFIBBCDField * ElementIDOKEI = {read = get_ElementIDOKEI , write = set_ElementIDOKEI};
   virtual TFIBBCDField * get_ElementIDOKEI(void)=0;
   virtual void set_ElementIDOKEI(TFIBBCDField * ElementIDOKEI)=0;

   __property TFIBWideStringField * TableNAMEOKEI = {read = get_TableNAMEOKEI , write = set_TableNAMEOKEI};
   virtual TFIBWideStringField * get_TableNAMEOKEI(void)=0;
   virtual void set_TableNAMEOKEI(TFIBWideStringField * TableNAMEOKEI)=0;

   __property TFIBIntegerField * TableCODEOKEI = {read = get_TableCODEOKEI , write = set_TableCODEOKEI};
   virtual TFIBIntegerField * get_TableCODEOKEI(void)=0;
   virtual void set_TableCODEOKEI(TFIBIntegerField * TableCODEOKEI)=0;

   __property TFIBWideStringField * TableGID_SOKEI = {read = get_TableGID_SOKEI , write = set_TableGID_SOKEI};
   virtual TFIBWideStringField * get_TableGID_SOKEI(void)=0;
   virtual void set_TableGID_SOKEI(TFIBWideStringField * TableGID_SOKEI)=0;

   __property TFIBBCDField * TableIDBASE_SOKEI = {read = get_TableIDBASE_SOKEI , write = set_TableIDBASE_SOKEI};
   virtual TFIBBCDField * get_TableIDBASE_SOKEI(void)=0;
   virtual void set_TableIDBASE_SOKEI(TFIBBCDField * TableIDBASE_SOKEI)=0;

   __property TFIBWideStringField * ElementNAMEOKEI = {read = get_ElementNAMEOKEI , write = set_ElementNAMEOKEI};
   virtual TFIBWideStringField * get_ElementNAMEOKEI(void)=0;
   virtual void set_ElementNAMEOKEI(TFIBWideStringField * ElementNAMEOKEI)=0;

   __property TFIBIntegerField * ElementCODEOKEI = {read = get_ElementCODEOKEI , write = set_ElementCODEOKEI};
   virtual TFIBIntegerField * get_ElementCODEOKEI(void)=0;
   virtual void set_ElementCODEOKEI(TFIBIntegerField * ElementCODEOKEI)=0;

   __property TFIBWideStringField * ElementGID_SOKEI = {read = get_ElementGID_SOKEI , write = set_ElementGID_SOKEI};
   virtual TFIBWideStringField * get_ElementGID_SOKEI(void)=0;
   virtual void set_ElementGID_SOKEI(TFIBWideStringField * ElementGID_SOKEI)=0;

   virtual void OpenTable()=0;
   virtual int  OpenElement(__int64 Id)=0;
   virtual void NewElement()=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 Id)=0;
};
#define IID_IDMSprOKEI __uuidof(IDMSprOKEI)
#endif
