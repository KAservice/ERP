#ifndef UDMSprProducerTypePriceImplH
#define UDMSprProducerTypePriceImplH
#include "IDMSprProducerTypePrice.h"
#include "UDMSprProducerTypePrice.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprProducerTypePriceImpl)) TDMSprProducerTypePriceImpl : public IDMSprProducerTypePrice
{
public:
   TDMSprProducerTypePriceImpl();
   ~TDMSprProducerTypePriceImpl();
   TDMSprProducerTypePrice * Object;
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

//IDMSprProducerTypePrice
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

   virtual TFIBLargeIntField * get_TableID_SPRTYPE_PRICE(void);
   virtual void set_TableID_SPRTYPE_PRICE(TFIBLargeIntField * TableID_SPRTYPE_PRICE);

   virtual TFIBLargeIntField * get_TableIDBASE_SPRTYPE_PRICE(void);
   virtual void set_TableIDBASE_SPRTYPE_PRICE(TFIBLargeIntField * TableIDBASE_SPRTYPE_PRICE);

   virtual TFIBWideStringField * get_TableGID_SPRTYPE_PRICE(void);
   virtual void set_TableGID_SPRTYPE_PRICE(TFIBWideStringField * TableGID_SPRTYPE_PRICE);

   virtual TFIBWideStringField * get_TableNAME_SPRTYPE_PRICE(void);
   virtual void set_TableNAME_SPRTYPE_PRICE(TFIBWideStringField * TableNAME_SPRTYPE_PRICE);

   virtual TFIBLargeIntField * get_ElementID_SPRTYPE_PRICE(void);
   virtual void set_ElementID_SPRTYPE_PRICE(TFIBLargeIntField * ElementID_SPRTYPE_PRICE);

   virtual TFIBLargeIntField * get_ElementIDBASE_SPRTYPE_PRICE(void);
   virtual void set_ElementIDBASE_SPRTYPE_PRICE(TFIBLargeIntField * ElementIDBASE_SPRTYPE_PRICE);

   virtual TFIBWideStringField * get_ElementGID_SPRTYPE_PRICE(void);
   virtual void set_ElementGID_SPRTYPE_PRICE(TFIBWideStringField * ElementGID_SPRTYPE_PRICE);

   virtual TFIBWideStringField * get_ElementNAME_SPRTYPE_PRICE(void);
   virtual void set_ElementNAME_SPRTYPE_PRICE(TFIBWideStringField * ElementNAME_SPRTYPE_PRICE);

   virtual bool OpenTable();
   virtual bool  OpenElement(__int64 id);
   virtual bool NewElement();
   virtual bool SaveElement(void);
   virtual void CloseElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 GetIdElementPoName(UnicodeString   name);
   virtual int GetIndexInTablePoId(__int64 id_element);
   virtual __int64 GetIdElementPoGid(UnicodeString gid);
   virtual UnicodeString GetGidElementPoId(__int64 id);
};
#define CLSID_TDMSprProducerTypePriceImpl __uuidof(TDMSprProducerTypePriceImpl)
#endif
