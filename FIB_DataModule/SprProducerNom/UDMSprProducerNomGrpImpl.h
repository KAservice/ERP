#ifndef UDMSprProducerNomGrpImplH
#define UDMSprProducerNomGrpImplH
#include "IDMSprProducerNomGrp.h"
#include "UDMSprProducerNomGrp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprProducerNomGrpImpl)) TDMSprProducerNomGrpImpl : public IDMSprProducerNomGrp
{
public:
   TDMSprProducerNomGrpImpl();
   ~TDMSprProducerNomGrpImpl();
   TDMSprProducerNomGrp * Object;
   int NumRefs;
   bool flDeleteObject;
   void DeleteImpl(void);

   //IUnknown
   virtual int kanQueryInterface(REFIID id_interface,void ** ppv);
   virtual int kanAddRef(void);
   virtual int kanRelease(void);

   //IMainInterface
   virtual int  get_CodeError(void);
   virtual void set_CodeError(int CodeError);
   virtual UnicodeString  get_TextError(void);
   virtual void set_TextError(UnicodeString  TextError);
   virtual int Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object);
   virtual int Done(void);

//IDMSprProducerNomGrp
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBLargeIntField * get_TableID_SPRNOMGRP(void);
   virtual void set_TableID_SPRNOMGRP(TFIBLargeIntField * TableID_SPRNOMGRP);

   virtual TFIBLargeIntField * get_TableIDBASE_SPRNOMGRP(void);
   virtual void set_TableIDBASE_SPRNOMGRP(TFIBLargeIntField * TableIDBASE_SPRNOMGRP);

   virtual TFIBWideStringField * get_TableGID_SPRNOMGRP(void);
   virtual void set_TableGID_SPRNOMGRP(TFIBWideStringField * TableGID_SPRNOMGRP);

   virtual TFIBLargeIntField * get_TableIDGRP_SPRNOMGRP(void);
   virtual void set_TableIDGRP_SPRNOMGRP(TFIBLargeIntField * TableIDGRP_SPRNOMGRP);

   virtual TFIBLargeIntField * get_TableIDPROD_SPRNOMGRP(void);
   virtual void set_TableIDPROD_SPRNOMGRP(TFIBLargeIntField * TableIDPROD_SPRNOMGRP);

   virtual TFIBWideStringField * get_TableNAME_SPRNOMGRP(void);
   virtual void set_TableNAME_SPRNOMGRP(TFIBWideStringField * TableNAME_SPRNOMGRP);

   virtual TFIBLargeIntField * get_ElementID_SPRNOMGRP(void);
   virtual void set_ElementID_SPRNOMGRP(TFIBLargeIntField * ElementID_SPRNOMGRP);

   virtual TFIBLargeIntField * get_ElementIDBASE_SPRNOMGRP(void);
   virtual void set_ElementIDBASE_SPRNOMGRP(TFIBLargeIntField * ElementIDBASE_SPRNOMGRP);

   virtual TFIBWideStringField * get_ElementGID_SPRNOMGRP(void);
   virtual void set_ElementGID_SPRNOMGRP(TFIBWideStringField * ElementGID_SPRNOMGRP);

   virtual TFIBLargeIntField * get_ElementIDGRP_SPRNOMGRP(void);
   virtual void set_ElementIDGRP_SPRNOMGRP(TFIBLargeIntField * ElementIDGRP_SPRNOMGRP);

   virtual TFIBLargeIntField * get_ElementIDPROD_SPRNOMGRP(void);
   virtual void set_ElementIDPROD_SPRNOMGRP(TFIBLargeIntField * ElementIDPROD_SPRNOMGRP);

   virtual TFIBWideStringField * get_ElementNAME_SPRNOMGRP(void);
   virtual void set_ElementNAME_SPRNOMGRP(TFIBWideStringField * ElementNAME_SPRNOMGRP);

   virtual __int64 get_IdProducer(void);
   virtual void set_IdProducer(__int64 IdProducer);

   virtual void OpenTable(__int64 id_producer);
   virtual int OpenElement(__int64 id);
   virtual bool NewElement(__int64 id_producer, __int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
};
#define CLSID_TDMSprProducerNomGrpImpl __uuidof(TDMSprProducerNomGrpImpl)
#endif
