#ifndef UIDMSprProducerEdH
#define UIDMSprProducerEdH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprProducerEd)) IDMSprProducerEd : public IMainInterface
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

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBLargeIntField * TableID_SPRED = {read = get_TableID_SPRED , write = set_TableID_SPRED};
   virtual TFIBLargeIntField * get_TableID_SPRED(void)=0;
   virtual void set_TableID_SPRED(TFIBLargeIntField * TableID_SPRED)=0;

   __property TFIBLargeIntField * TableIDBASE_SPRED = {read = get_TableIDBASE_SPRED , write = set_TableIDBASE_SPRED};
   virtual TFIBLargeIntField * get_TableIDBASE_SPRED(void)=0;
   virtual void set_TableIDBASE_SPRED(TFIBLargeIntField * TableIDBASE_SPRED)=0;

   __property TFIBWideStringField * TableGID_SPRED = {read = get_TableGID_SPRED , write = set_TableGID_SPRED};
   virtual TFIBWideStringField * get_TableGID_SPRED(void)=0;
   virtual void set_TableGID_SPRED(TFIBWideStringField * TableGID_SPRED)=0;

   __property TFIBLargeIntField * TableIDPRNOM_SPRED = {read = get_TableIDPRNOM_SPRED , write = set_TableIDPRNOM_SPRED};
   virtual TFIBLargeIntField * get_TableIDPRNOM_SPRED(void)=0;
   virtual void set_TableIDPRNOM_SPRED(TFIBLargeIntField * TableIDPRNOM_SPRED)=0;

   __property TFIBIntegerField * TableCODE_SPRED = {read = get_TableCODE_SPRED , write = set_TableCODE_SPRED};
   virtual TFIBIntegerField * get_TableCODE_SPRED(void)=0;
   virtual void set_TableCODE_SPRED(TFIBIntegerField * TableCODE_SPRED)=0;

   __property TFIBWideStringField * TableBARCODE_SPRED = {read = get_TableBARCODE_SPRED , write = set_TableBARCODE_SPRED};
   virtual TFIBWideStringField * get_TableBARCODE_SPRED(void)=0;
   virtual void set_TableBARCODE_SPRED(TFIBWideStringField * TableBARCODE_SPRED)=0;

   __property TFIBBCDField * TableKF_SPRED = {read = get_TableKF_SPRED , write = set_TableKF_SPRED};
   virtual TFIBBCDField * get_TableKF_SPRED(void)=0;
   virtual void set_TableKF_SPRED(TFIBBCDField * TableKF_SPRED)=0;

   __property TFIBWideStringField * TableNAME_SPRED = {read = get_TableNAME_SPRED , write = set_TableNAME_SPRED};
   virtual TFIBWideStringField * get_TableNAME_SPRED(void)=0;
   virtual void set_TableNAME_SPRED(TFIBWideStringField * TableNAME_SPRED)=0;

   __property TFIBLargeIntField * ElementID_SPRED = {read = get_ElementID_SPRED , write = set_ElementID_SPRED};
   virtual TFIBLargeIntField * get_ElementID_SPRED(void)=0;
   virtual void set_ElementID_SPRED(TFIBLargeIntField * ElementID_SPRED)=0;

   __property TFIBLargeIntField * ElementIDBASE_SPRED = {read = get_ElementIDBASE_SPRED , write = set_ElementIDBASE_SPRED};
   virtual TFIBLargeIntField * get_ElementIDBASE_SPRED(void)=0;
   virtual void set_ElementIDBASE_SPRED(TFIBLargeIntField * ElementIDBASE_SPRED)=0;

   __property TFIBWideStringField * ElementGID_SPRED = {read = get_ElementGID_SPRED , write = set_ElementGID_SPRED};
   virtual TFIBWideStringField * get_ElementGID_SPRED(void)=0;
   virtual void set_ElementGID_SPRED(TFIBWideStringField * ElementGID_SPRED)=0;

   __property TFIBLargeIntField * ElementIDPRNOM_SPRED = {read = get_ElementIDPRNOM_SPRED , write = set_ElementIDPRNOM_SPRED};
   virtual TFIBLargeIntField * get_ElementIDPRNOM_SPRED(void)=0;
   virtual void set_ElementIDPRNOM_SPRED(TFIBLargeIntField * ElementIDPRNOM_SPRED)=0;

   __property TFIBIntegerField * ElementCODE_SPRED = {read = get_ElementCODE_SPRED , write = set_ElementCODE_SPRED};
   virtual TFIBIntegerField * get_ElementCODE_SPRED(void)=0;
   virtual void set_ElementCODE_SPRED(TFIBIntegerField * ElementCODE_SPRED)=0;

   __property TFIBWideStringField * ElementBARCODE_SPRED = {read = get_ElementBARCODE_SPRED , write = set_ElementBARCODE_SPRED};
   virtual TFIBWideStringField * get_ElementBARCODE_SPRED(void)=0;
   virtual void set_ElementBARCODE_SPRED(TFIBWideStringField * ElementBARCODE_SPRED)=0;

   __property TFIBBCDField * ElementKF_SPRED = {read = get_ElementKF_SPRED , write = set_ElementKF_SPRED};
   virtual TFIBBCDField * get_ElementKF_SPRED(void)=0;
   virtual void set_ElementKF_SPRED(TFIBBCDField * ElementKF_SPRED)=0;

   __property TFIBWideStringField * ElementNAME_SPRED = {read = get_ElementNAME_SPRED , write = set_ElementNAME_SPRED};
   virtual TFIBWideStringField * get_ElementNAME_SPRED(void)=0;
   virtual void set_ElementNAME_SPRED(TFIBWideStringField * ElementNAME_SPRED)=0;

   virtual void OpenTable(__int64 id_producer_nom)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual bool NewElement(__int64 id_producer_nom)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 num)=0;
};
#define IID_IDMSprProducerEd __uuidof(IDMSprProducerEd)
#endif
