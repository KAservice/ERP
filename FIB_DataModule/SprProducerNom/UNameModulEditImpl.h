#ifndef UNameModulEditImplH
#define UNameModulEditImplH
#include "INameModulEdit.h"
#include "UNameModulEdit.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TNameModulEditImpl)) TNameModulEditImpl : public INameModulEdit
{
public:
   TNameModulEditImpl();
   ~TNameModulEditImpl();
   TNameModulEdit * Object;
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

//INameModulEdit
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TpFIBDataSet * get_SpTPrice(void);
   virtual void set_SpTPrice(TpFIBDataSet * SpTPrice);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TFIBLargeIntField * get_ElementID_SPRNOM(void);
   virtual void set_ElementID_SPRNOM(TFIBLargeIntField * ElementID_SPRNOM);

   virtual TFIBLargeIntField * get_ElementIDBASE_SPRNOM(void);
   virtual void set_ElementIDBASE_SPRNOM(TFIBLargeIntField * ElementIDBASE_SPRNOM);

   virtual TFIBWideStringField * get_ElementGID_SPRNOM(void);
   virtual void set_ElementGID_SPRNOM(TFIBWideStringField * ElementGID_SPRNOM);

   virtual TFIBLargeIntField * get_ElementIDPROD_SPRNOM(void);
   virtual void set_ElementIDPROD_SPRNOM(TFIBLargeIntField * ElementIDPROD_SPRNOM);

   virtual TFIBLargeIntField * get_ElementIDGRP_SPRNOM(void);
   virtual void set_ElementIDGRP_SPRNOM(TFIBLargeIntField * ElementIDGRP_SPRNOM);

   virtual TFIBIntegerField * get_ElementCODE_SPRNOM(void);
   virtual void set_ElementCODE_SPRNOM(TFIBIntegerField * ElementCODE_SPRNOM);

   virtual TFIBWideStringField * get_ElementART_SPRNOM(void);
   virtual void set_ElementART_SPRNOM(TFIBWideStringField * ElementART_SPRNOM);

   virtual TFIBWideStringField * get_ElementNAME_SPRNOM(void);
   virtual void set_ElementNAME_SPRNOM(TFIBWideStringField * ElementNAME_SPRNOM);

   virtual TFIBWideStringField * get_ElementKRNAME_SPRNOM(void);
   virtual void set_ElementKRNAME_SPRNOM(TFIBWideStringField * ElementKRNAME_SPRNOM);

   virtual TFIBWideStringField * get_ElementFNAME_SPRNOM(void);
   virtual void set_ElementFNAME_SPRNOM(TFIBWideStringField * ElementFNAME_SPRNOM);

   virtual TFIBIntegerField * get_ElementTYPE_SPRNOM(void);
   virtual void set_ElementTYPE_SPRNOM(TFIBIntegerField * ElementTYPE_SPRNOM);

   virtual TFIBLargeIntField * get_ElementIDBASED_SPRNOM(void);
   virtual void set_ElementIDBASED_SPRNOM(TFIBLargeIntField * ElementIDBASED_SPRNOM);

   virtual TFIBLargeIntField * get_TableID_SPRNOM(void);
   virtual void set_TableID_SPRNOM(TFIBLargeIntField * TableID_SPRNOM);

   virtual TFIBLargeIntField * get_TableIDGRP_SPRNOM(void);
   virtual void set_TableIDGRP_SPRNOM(TFIBLargeIntField * TableIDGRP_SPRNOM);

   virtual TFIBLargeIntField * get_TableIDPROD_SPRNOM(void);
   virtual void set_TableIDPROD_SPRNOM(TFIBLargeIntField * TableIDPROD_SPRNOM);

   virtual TFIBIntegerField * get_TableCODE_SPRNOM(void);
   virtual void set_TableCODE_SPRNOM(TFIBIntegerField * TableCODE_SPRNOM);

   virtual TFIBWideStringField * get_TableART_SPRNOM(void);
   virtual void set_TableART_SPRNOM(TFIBWideStringField * TableART_SPRNOM);

   virtual TFIBWideStringField * get_TableNAME_SPRNOM(void);
   virtual void set_TableNAME_SPRNOM(TFIBWideStringField * TableNAME_SPRNOM);

   virtual TFIBWideStringField * get_TableNAME_SPRED(void);
   virtual void set_TableNAME_SPRED(TFIBWideStringField * TableNAME_SPRED);

   virtual TFIBWideStringField * get_TableBARCODE_SPRED(void);
   virtual void set_TableBARCODE_SPRED(TFIBWideStringField * TableBARCODE_SPRED);

   virtual TFIBBCDField * get_TableVALUE_SPRPRICE(void);
   virtual void set_TableVALUE_SPRPRICE(TFIBBCDField * TableVALUE_SPRPRICE);

   virtual TFIBLargeIntField * get_SpTPriceID_SPRTYPE_PRICE(void);
   virtual void set_SpTPriceID_SPRTYPE_PRICE(TFIBLargeIntField * SpTPriceID_SPRTYPE_PRICE);

   virtual TFIBWideStringField * get_SpTPriceNAME_SPRTYPE_PRICE(void);
   virtual void set_SpTPriceNAME_SPRTYPE_PRICE(TFIBWideStringField * SpTPriceNAME_SPRTYPE_PRICE);

   virtual __int64 get_IdProducer(void);
   virtual void set_IdProducer(__int64 IdProducer);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual __int64 get_IdProducerTypePrice(void);
   virtual void set_IdProducerTypePrice(__int64 IdProducerTypePrice);

   virtual void OpenTable(__int64 id_producer, __int64 id_grp, __int64 id_producer_type_price, bool all);
   virtual bool NewElement(__int64 id_producer, __int64 id_grp);
   virtual bool OpenElement(__int64 id);
   virtual bool DeleteElement(__int64 id);
   virtual bool SaveElement(void);
   virtual void ChancheGrp(__int64 id_new_grp,__int64 id_producer_nom);
};
#define CLSID_TNameModulEditImpl __uuidof(TNameModulEditImpl)
#endif
