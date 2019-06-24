#ifndef UDMSprProducerEdImplH
#define UDMSprProducerEdImplH
#include "IDMSprProducerEd.h"
#include "UDMSprProducerEd.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprProducerEdImpl)) TDMSprProducerEdImpl : public IDMSprProducerEd
{
public:
   TDMSprProducerEdImpl();
   ~TDMSprProducerEdImpl();
   TDMSprProducerEd * Object;
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

//IDMSprProducerEd
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

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBLargeIntField * get_TableID_SPRED(void);
   virtual void set_TableID_SPRED(TFIBLargeIntField * TableID_SPRED);

   virtual TFIBLargeIntField * get_TableIDBASE_SPRED(void);
   virtual void set_TableIDBASE_SPRED(TFIBLargeIntField * TableIDBASE_SPRED);

   virtual TFIBWideStringField * get_TableGID_SPRED(void);
   virtual void set_TableGID_SPRED(TFIBWideStringField * TableGID_SPRED);

   virtual TFIBLargeIntField * get_TableIDPRNOM_SPRED(void);
   virtual void set_TableIDPRNOM_SPRED(TFIBLargeIntField * TableIDPRNOM_SPRED);

   virtual TFIBIntegerField * get_TableCODE_SPRED(void);
   virtual void set_TableCODE_SPRED(TFIBIntegerField * TableCODE_SPRED);

   virtual TFIBWideStringField * get_TableBARCODE_SPRED(void);
   virtual void set_TableBARCODE_SPRED(TFIBWideStringField * TableBARCODE_SPRED);

   virtual TFIBBCDField * get_TableKF_SPRED(void);
   virtual void set_TableKF_SPRED(TFIBBCDField * TableKF_SPRED);

   virtual TFIBWideStringField * get_TableNAME_SPRED(void);
   virtual void set_TableNAME_SPRED(TFIBWideStringField * TableNAME_SPRED);

   virtual TFIBLargeIntField * get_ElementID_SPRED(void);
   virtual void set_ElementID_SPRED(TFIBLargeIntField * ElementID_SPRED);

   virtual TFIBLargeIntField * get_ElementIDBASE_SPRED(void);
   virtual void set_ElementIDBASE_SPRED(TFIBLargeIntField * ElementIDBASE_SPRED);

   virtual TFIBWideStringField * get_ElementGID_SPRED(void);
   virtual void set_ElementGID_SPRED(TFIBWideStringField * ElementGID_SPRED);

   virtual TFIBLargeIntField * get_ElementIDPRNOM_SPRED(void);
   virtual void set_ElementIDPRNOM_SPRED(TFIBLargeIntField * ElementIDPRNOM_SPRED);

   virtual TFIBIntegerField * get_ElementCODE_SPRED(void);
   virtual void set_ElementCODE_SPRED(TFIBIntegerField * ElementCODE_SPRED);

   virtual TFIBWideStringField * get_ElementBARCODE_SPRED(void);
   virtual void set_ElementBARCODE_SPRED(TFIBWideStringField * ElementBARCODE_SPRED);

   virtual TFIBBCDField * get_ElementKF_SPRED(void);
   virtual void set_ElementKF_SPRED(TFIBBCDField * ElementKF_SPRED);

   virtual TFIBWideStringField * get_ElementNAME_SPRED(void);
   virtual void set_ElementNAME_SPRED(TFIBWideStringField * ElementNAME_SPRED);

   virtual void OpenTable(__int64 id_producer_nom);
   virtual int OpenElement(__int64 id);
   virtual bool NewElement(__int64 id_producer_nom);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 num);
};
#define CLSID_TDMSprProducerEdImpl __uuidof(TDMSprProducerEdImpl)
#endif
