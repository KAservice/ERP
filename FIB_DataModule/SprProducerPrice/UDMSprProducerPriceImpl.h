#ifndef UDMSprProducerPriceImplH
#define UDMSprProducerPriceImplH
#include "IDMSprProducerPrice.h"
#include "UDMSprProducerPrice.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprProducerPriceImpl)) TDMSprProducerPriceImpl : public IDMSprProducerPrice
{
public:
   TDMSprProducerPriceImpl();
   ~TDMSprProducerPriceImpl();
   TDMSprProducerPrice * Object;
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

//IDMSprProducerPrice
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_TPrice(void);
   virtual void set_TPrice(TpFIBDataSet * TPrice);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBLargeIntField * get_TPriceID_SPRTYPE_PRICE(void);
   virtual void set_TPriceID_SPRTYPE_PRICE(TFIBLargeIntField * TPriceID_SPRTYPE_PRICE);

   virtual TFIBWideStringField * get_TPriceNAME_SPRTYPE_PRICE(void);
   virtual void set_TPriceNAME_SPRTYPE_PRICE(TFIBWideStringField * TPriceNAME_SPRTYPE_PRICE);

   virtual TFIBLargeIntField * get_TableID_SPRPRICE(void);
   virtual void set_TableID_SPRPRICE(TFIBLargeIntField * TableID_SPRPRICE);

   virtual TFIBLargeIntField * get_TableIDBASE_SPRPRICE(void);
   virtual void set_TableIDBASE_SPRPRICE(TFIBLargeIntField * TableIDBASE_SPRPRICE);

   virtual TFIBWideStringField * get_TableGID_SPRPRICE(void);
   virtual void set_TableGID_SPRPRICE(TFIBWideStringField * TableGID_SPRPRICE);

   virtual TFIBLargeIntField * get_TableIDPRNOM_SPRPRICE(void);
   virtual void set_TableIDPRNOM_SPRPRICE(TFIBLargeIntField * TableIDPRNOM_SPRPRICE);

   virtual TFIBLargeIntField * get_TableIDPRTPRICE_SPRPRICE(void);
   virtual void set_TableIDPRTPRICE_SPRPRICE(TFIBLargeIntField * TableIDPRTPRICE_SPRPRICE);

   virtual TFIBBCDField * get_TableVALUE_SPRPRICE(void);
   virtual void set_TableVALUE_SPRPRICE(TFIBBCDField * TableVALUE_SPRPRICE);

   virtual TFIBWideStringField * get_TableNAME_SPRTYPE_PRICE(void);
   virtual void set_TableNAME_SPRTYPE_PRICE(TFIBWideStringField * TableNAME_SPRTYPE_PRICE);

   virtual TFIBBCDField * get_ElementID_SPRPRICE(void);
   virtual void set_ElementID_SPRPRICE(TFIBBCDField * ElementID_SPRPRICE);

   virtual TFIBBCDField * get_ElementIDBASE_SPRPRICE(void);
   virtual void set_ElementIDBASE_SPRPRICE(TFIBBCDField * ElementIDBASE_SPRPRICE);

   virtual TFIBWideStringField * get_ElementGID_SPRPRICE(void);
   virtual void set_ElementGID_SPRPRICE(TFIBWideStringField * ElementGID_SPRPRICE);

   virtual TFIBBCDField * get_ElementIDPRNOM_SPRPRICE(void);
   virtual void set_ElementIDPRNOM_SPRPRICE(TFIBBCDField * ElementIDPRNOM_SPRPRICE);

   virtual TFIBBCDField * get_ElementIDPRTPRICE_SPRPRICE(void);
   virtual void set_ElementIDPRTPRICE_SPRPRICE(TFIBBCDField * ElementIDPRTPRICE_SPRPRICE);

   virtual TFIBBCDField * get_ElementVALUE_SPRPRICE(void);
   virtual void set_ElementVALUE_SPRPRICE(TFIBBCDField * ElementVALUE_SPRPRICE);

   virtual __int64 get_IdProducerNom(void);
   virtual void set_IdProducerNom(__int64 IdProducerNom);

   virtual __int64 get_IdProducerTypePrice(void);
   virtual void set_IdProducerTypePrice(__int64 IdProducerTypePrice);

   virtual void OpenTable(__int64 id_producer_nom);
   virtual bool SaveIsmen(void);
   virtual void CancelIsmen(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 FindElement(__int64 id_producer_type_price, __int64 id_producer_nom);
};
#define CLSID_TDMSprProducerPriceImpl __uuidof(TDMSprProducerPriceImpl)
#endif
