#ifndef UDMSprTypePriceImplH
#define UDMSprTypePriceImplH
#include "IDMSprTypePrice.h"
#include "UDMSprTypePrice.h"
//---------------------------------------------------------------
class __declspec(uuid("{2EB4AEF3-FACD-4BCB-8E8D-38888DADC5F8}"))TDMSprTypePriceImpl : public IDMSprTypePrice
{
public:
   TDMSprTypePriceImpl();
   ~TDMSprTypePriceImpl();
   TDMSprTypePrice * Object;
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

//IDMSprTypePrice
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

   virtual TFIBBCDField * get_TableID_TPRICE(void);
   virtual void set_TableID_TPRICE(TFIBBCDField * TableID_TPRICE);

   virtual TFIBBCDField * get_ElementID_TPRICE(void);
   virtual void set_ElementID_TPRICE(TFIBBCDField * ElementID_TPRICE);

   virtual TFIBWideStringField * get_TableNAME_TPRICE(void);
   virtual void set_TableNAME_TPRICE(TFIBWideStringField * TableNAME_TPRICE);

   virtual TFIBWideStringField * get_TableGID_STPRICE(void);
   virtual void set_TableGID_STPRICE(TFIBWideStringField * TableGID_STPRICE);

   virtual TFIBWideStringField * get_ElementNAME_TPRICE(void);
   virtual void set_ElementNAME_TPRICE(TFIBWideStringField * ElementNAME_TPRICE);

   virtual TFIBWideStringField * get_ElementGID_STPRICE(void);
   virtual void set_ElementGID_STPRICE(TFIBWideStringField * ElementGID_STPRICE);

   virtual void OpenTable();
   virtual int  OpenElement(__int64 Id);
   virtual void NewElement();
   virtual bool SaveElement(void);
   virtual void CloseElement(void);
   virtual void DeleteElement(__int64 Id);
   virtual __int64 GetIDTypePrice(String   name);
   virtual int GetIndexTypePricePoId(__int64 id_type_price);
   virtual __int64 GetIDElement(String gid);
   virtual AnsiString GetGIDElement(__int64 id);
};
#define CLSID_TDMSprTypePriceImpl __uuidof(TDMSprTypePriceImpl)
#endif
