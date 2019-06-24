#ifndef UHOT_DMSprCelPriesdaImplH
#define UHOT_DMSprCelPriesdaImplH
#include "IHOT_DMSprCelPriesda.h"
#include "UHOT_DMSprCelPriesda.h"
//---------------------------------------------------------------
class __declspec(uuid("{E27EBB2E-B8AB-4B65-95C2-823F90D9CFD4}")) THOT_DMSprCelPriesdaImpl : public IHOT_DMSprCelPriesda
{
public:
   THOT_DMSprCelPriesdaImpl();
   ~THOT_DMSprCelPriesdaImpl();
   THOT_DMSprCelPriesda * Object;
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

//IHOT_DMSprCelPriesda
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

   virtual TFIBBCDField * get_ElementID_HOT_SCELPR(void);
   virtual void set_ElementID_HOT_SCELPR(TFIBBCDField * ElementID_HOT_SCELPR);

   virtual TFIBBCDField * get_TableID_HOT_SCELPR(void);
   virtual void set_TableID_HOT_SCELPR(TFIBBCDField * TableID_HOT_SCELPR);

   virtual TFIBWideStringField * get_ElementNAME_HOT_SCELPR(void);
   virtual void set_ElementNAME_HOT_SCELPR(TFIBWideStringField * ElementNAME_HOT_SCELPR);

   virtual TFIBWideStringField * get_TableNAME_HOT_SCELPR(void);
   virtual void set_TableNAME_HOT_SCELPR(TFIBWideStringField * TableNAME_HOT_SCELPR);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 Id);
   virtual bool NewElement(void);
   virtual bool SaveElement(void);
   virtual bool SaveIsmen(void);
   virtual bool CancelIsmen(void);
   virtual void CloseElement(void);
   virtual bool DeleteElement(__int64 Id);
   virtual int GetIndexElementaPoID(__int64 id);
};
#define CLSID_THOT_DMSprCelPriesdaImpl __uuidof(THOT_DMSprCelPriesdaImpl)
#endif
