#ifndef UIDMSprProducerNomGrpH
#define UIDMSprProducerNomGrpH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprProducerNomGrp)) IDMSprProducerNomGrp : public IMainInterface
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

   __property TFIBLargeIntField * TableID_SPRNOMGRP = {read = get_TableID_SPRNOMGRP , write = set_TableID_SPRNOMGRP};
   virtual TFIBLargeIntField * get_TableID_SPRNOMGRP(void)=0;
   virtual void set_TableID_SPRNOMGRP(TFIBLargeIntField * TableID_SPRNOMGRP)=0;

   __property TFIBLargeIntField * TableIDBASE_SPRNOMGRP = {read = get_TableIDBASE_SPRNOMGRP , write = set_TableIDBASE_SPRNOMGRP};
   virtual TFIBLargeIntField * get_TableIDBASE_SPRNOMGRP(void)=0;
   virtual void set_TableIDBASE_SPRNOMGRP(TFIBLargeIntField * TableIDBASE_SPRNOMGRP)=0;

   __property TFIBWideStringField * TableGID_SPRNOMGRP = {read = get_TableGID_SPRNOMGRP , write = set_TableGID_SPRNOMGRP};
   virtual TFIBWideStringField * get_TableGID_SPRNOMGRP(void)=0;
   virtual void set_TableGID_SPRNOMGRP(TFIBWideStringField * TableGID_SPRNOMGRP)=0;

   __property TFIBLargeIntField * TableIDGRP_SPRNOMGRP = {read = get_TableIDGRP_SPRNOMGRP , write = set_TableIDGRP_SPRNOMGRP};
   virtual TFIBLargeIntField * get_TableIDGRP_SPRNOMGRP(void)=0;
   virtual void set_TableIDGRP_SPRNOMGRP(TFIBLargeIntField * TableIDGRP_SPRNOMGRP)=0;

   __property TFIBLargeIntField * TableIDPROD_SPRNOMGRP = {read = get_TableIDPROD_SPRNOMGRP , write = set_TableIDPROD_SPRNOMGRP};
   virtual TFIBLargeIntField * get_TableIDPROD_SPRNOMGRP(void)=0;
   virtual void set_TableIDPROD_SPRNOMGRP(TFIBLargeIntField * TableIDPROD_SPRNOMGRP)=0;

   __property TFIBWideStringField * TableNAME_SPRNOMGRP = {read = get_TableNAME_SPRNOMGRP , write = set_TableNAME_SPRNOMGRP};
   virtual TFIBWideStringField * get_TableNAME_SPRNOMGRP(void)=0;
   virtual void set_TableNAME_SPRNOMGRP(TFIBWideStringField * TableNAME_SPRNOMGRP)=0;

   __property TFIBLargeIntField * ElementID_SPRNOMGRP = {read = get_ElementID_SPRNOMGRP , write = set_ElementID_SPRNOMGRP};
   virtual TFIBLargeIntField * get_ElementID_SPRNOMGRP(void)=0;
   virtual void set_ElementID_SPRNOMGRP(TFIBLargeIntField * ElementID_SPRNOMGRP)=0;

   __property TFIBLargeIntField * ElementIDBASE_SPRNOMGRP = {read = get_ElementIDBASE_SPRNOMGRP , write = set_ElementIDBASE_SPRNOMGRP};
   virtual TFIBLargeIntField * get_ElementIDBASE_SPRNOMGRP(void)=0;
   virtual void set_ElementIDBASE_SPRNOMGRP(TFIBLargeIntField * ElementIDBASE_SPRNOMGRP)=0;

   __property TFIBWideStringField * ElementGID_SPRNOMGRP = {read = get_ElementGID_SPRNOMGRP , write = set_ElementGID_SPRNOMGRP};
   virtual TFIBWideStringField * get_ElementGID_SPRNOMGRP(void)=0;
   virtual void set_ElementGID_SPRNOMGRP(TFIBWideStringField * ElementGID_SPRNOMGRP)=0;

   __property TFIBLargeIntField * ElementIDGRP_SPRNOMGRP = {read = get_ElementIDGRP_SPRNOMGRP , write = set_ElementIDGRP_SPRNOMGRP};
   virtual TFIBLargeIntField * get_ElementIDGRP_SPRNOMGRP(void)=0;
   virtual void set_ElementIDGRP_SPRNOMGRP(TFIBLargeIntField * ElementIDGRP_SPRNOMGRP)=0;

   __property TFIBLargeIntField * ElementIDPROD_SPRNOMGRP = {read = get_ElementIDPROD_SPRNOMGRP , write = set_ElementIDPROD_SPRNOMGRP};
   virtual TFIBLargeIntField * get_ElementIDPROD_SPRNOMGRP(void)=0;
   virtual void set_ElementIDPROD_SPRNOMGRP(TFIBLargeIntField * ElementIDPROD_SPRNOMGRP)=0;

   __property TFIBWideStringField * ElementNAME_SPRNOMGRP = {read = get_ElementNAME_SPRNOMGRP , write = set_ElementNAME_SPRNOMGRP};
   virtual TFIBWideStringField * get_ElementNAME_SPRNOMGRP(void)=0;
   virtual void set_ElementNAME_SPRNOMGRP(TFIBWideStringField * ElementNAME_SPRNOMGRP)=0;

   __property __int64 IdProducer = {read = get_IdProducer , write = set_IdProducer};
   virtual __int64 get_IdProducer(void)=0;
   virtual void set_IdProducer(__int64 IdProducer)=0;

   virtual void OpenTable(__int64 id_producer)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual bool NewElement(__int64 id_producer, __int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
};
#define IID_IDMSprProducerNomGrp __uuidof(IDMSprProducerNomGrp)
#endif
