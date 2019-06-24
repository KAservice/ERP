#ifndef UDMSprVidDiscountCardImplH
#define UDMSprVidDiscountCardImplH
#include "IDMSprVidDiscountCard.h"
#include "UDMSprVidDiscountCard.h"
//---------------------------------------------------------------
class __declspec(uuid("{D1220169-EA10-443A-B135-262E6AFF70B4}")) TDMSprVidDiscountCardImpl : public IDMSprVidDiscountCard
{
public:
   TDMSprVidDiscountCardImpl();
   ~TDMSprVidDiscountCardImpl();
   TDMSprVidDiscountCard * Object;
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

//IDMSprVidDiscountCard
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

   virtual TFIBBCDField * get_TableID_SVID_DCARD(void);
   virtual void set_TableID_SVID_DCARD(TFIBBCDField * TableID_SVID_DCARD);

   virtual TFIBBCDField * get_ElementID_SVID_DCARD(void);
   virtual void set_ElementID_SVID_DCARD(TFIBBCDField * ElementID_SVID_DCARD);

   virtual TFIBWideStringField * get_TableGID_SVID_DCARD(void);
   virtual void set_TableGID_SVID_DCARD(TFIBWideStringField * TableGID_SVID_DCARD);

   virtual TFIBWideStringField * get_TableNAME_SVID_DCARD(void);
   virtual void set_TableNAME_SVID_DCARD(TFIBWideStringField * TableNAME_SVID_DCARD);

   virtual TFIBWideStringField * get_ElementGID_SVID_DCARD(void);
   virtual void set_ElementGID_SVID_DCARD(TFIBWideStringField * ElementGID_SVID_DCARD);

   virtual TFIBWideStringField * get_ElementNAME_SVID_DCARD(void);
   virtual void set_ElementNAME_SVID_DCARD(TFIBWideStringField * ElementNAME_SVID_DCARD);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 Id);
   virtual bool NewElement(void);
   virtual bool SaveElement(void);
   virtual void CloseElement(void);
   virtual bool DeleteElement(__int64 Id);
   virtual __int64 GetIDElement(String gid);
   virtual AnsiString GetGIDElement(__int64 id);
   virtual int GetIndexElementaPoID(__int64 id);
};
#define CLSID_TDMSprVidDiscountCardImpl __uuidof(TDMSprVidDiscountCardImpl)
#endif
