#ifndef UDMSprAddressNasPunktImplH
#define UDMSprAddressNasPunktImplH
#include "IDMSprAddressNasPunkt.h"
#include "UDMSprAddressNasPunkt.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprAddressNasPunktImpl)) TDMSprAddressNasPunktImpl : public IDMSprAddressNasPunkt
{
public:
   TDMSprAddressNasPunktImpl();
   ~TDMSprAddressNasPunktImpl();
   TDMSprAddressNasPunkt * Object;
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

//IDMSprAddressNasPunkt
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TFIBLargeIntField * get_TableID_SADR_NASPUNKT(void);
   virtual void set_TableID_SADR_NASPUNKT(TFIBLargeIntField * TableID_SADR_NASPUNKT);

   virtual TFIBLargeIntField * get_TableIDBASE_SADR_NASPUNKT(void);
   virtual void set_TableIDBASE_SADR_NASPUNKT(TFIBLargeIntField * TableIDBASE_SADR_NASPUNKT);

   virtual TFIBLargeIntField * get_TableIDRAYON_SADR_NASPUNKT(void);
   virtual void set_TableIDRAYON_SADR_NASPUNKT(TFIBLargeIntField * TableIDRAYON_SADR_NASPUNKT);

   virtual TFIBWideStringField * get_TableNAME_SADR_NASPUNKT(void);
   virtual void set_TableNAME_SADR_NASPUNKT(TFIBWideStringField * TableNAME_SADR_NASPUNKT);

   virtual TFIBIntegerField * get_TableFL_GOROD_SADR_NASPUNKT(void);
   virtual void set_TableFL_GOROD_SADR_NASPUNKT(TFIBIntegerField * TableFL_GOROD_SADR_NASPUNKT);

   virtual TFIBLargeIntField * get_ElementID_SADR_NASPUNKT(void);
   virtual void set_ElementID_SADR_NASPUNKT(TFIBLargeIntField * ElementID_SADR_NASPUNKT);

   virtual TFIBLargeIntField * get_ElementIDBASE_SADR_NASPUNKT(void);
   virtual void set_ElementIDBASE_SADR_NASPUNKT(TFIBLargeIntField * ElementIDBASE_SADR_NASPUNKT);

   virtual TFIBLargeIntField * get_ElementIDRAYON_SADR_NASPUNKT(void);
   virtual void set_ElementIDRAYON_SADR_NASPUNKT(TFIBLargeIntField * ElementIDRAYON_SADR_NASPUNKT);

   virtual TFIBWideStringField * get_ElementNAME_SADR_NASPUNKT(void);
   virtual void set_ElementNAME_SADR_NASPUNKT(TFIBWideStringField * ElementNAME_SADR_NASPUNKT);

   virtual TFIBIntegerField * get_ElementFL_GOROD_SADR_NASPUNKT(void);
   virtual void set_ElementFL_GOROD_SADR_NASPUNKT(TFIBIntegerField * ElementFL_GOROD_SADR_NASPUNKT);

   virtual TFIBLargeIntField * get_ElementID_SADR_RAYON(void);
   virtual void set_ElementID_SADR_RAYON(TFIBLargeIntField * ElementID_SADR_RAYON);

   virtual TFIBLargeIntField * get_ElementIDBASE_SADR_RAYON(void);
   virtual void set_ElementIDBASE_SADR_RAYON(TFIBLargeIntField * ElementIDBASE_SADR_RAYON);

   virtual TFIBLargeIntField * get_ElementIDREGION_SADR_RAYON(void);
   virtual void set_ElementIDREGION_SADR_RAYON(TFIBLargeIntField * ElementIDREGION_SADR_RAYON);

   virtual TFIBWideStringField * get_ElementNAME_SADR_RAYON(void);
   virtual void set_ElementNAME_SADR_RAYON(TFIBWideStringField * ElementNAME_SADR_RAYON);

   virtual TFIBLargeIntField * get_ElementID_SADR_REGION(void);
   virtual void set_ElementID_SADR_REGION(TFIBLargeIntField * ElementID_SADR_REGION);

   virtual TFIBLargeIntField * get_ElementIDBASE_SADR_REGION(void);
   virtual void set_ElementIDBASE_SADR_REGION(TFIBLargeIntField * ElementIDBASE_SADR_REGION);

   virtual TFIBWideStringField * get_ElementNAME_SADR_REGION(void);
   virtual void set_ElementNAME_SADR_REGION(TFIBWideStringField * ElementNAME_SADR_REGION);

   virtual TFIBWideStringField * get_ElementCODE_SADR_REGION(void);
   virtual void set_ElementCODE_SADR_REGION(TFIBWideStringField * ElementCODE_SADR_REGION);

   virtual __int64 get_IdOwner(void);
   virtual void set_IdOwner(__int64 IdOwner);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual void OpenTable(__int64 id_owner);
   virtual bool NewElement(__int64 id_owner);
   virtual int OpenElement(__int64 id );
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
};
#define CLSID_TDMSprAddressNasPunktImpl __uuidof(TDMSprAddressNasPunktImpl)
#endif
