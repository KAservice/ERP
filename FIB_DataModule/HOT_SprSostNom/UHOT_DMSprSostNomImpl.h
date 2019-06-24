#ifndef UHOT_DMSprSostNomImplH
#define UHOT_DMSprSostNomImplH
#include "IHOT_DMSprSostNom.h"
#include "UHOT_DMSprSostNom.h"
//---------------------------------------------------------------
class __declspec(uuid("{2F0989F1-635C-44D5-8FF0-BE272E600E0E}")) THOT_DMSprSostNomImpl : public IHOT_DMSprSostNom
{
public:
   THOT_DMSprSostNomImpl();
   ~THOT_DMSprSostNomImpl();
   THOT_DMSprSostNom * Object;
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

//IHOT_DMSprSostNom
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBSmallIntField * get_TableFLBRON_HOT_SSOSTNOM(void);
   virtual void set_TableFLBRON_HOT_SSOSTNOM(TFIBSmallIntField * TableFLBRON_HOT_SSOSTNOM);

   virtual TFIBSmallIntField * get_TableFLRASM_HOT_SSOSTNOM(void);
   virtual void set_TableFLRASM_HOT_SSOSTNOM(TFIBSmallIntField * TableFLRASM_HOT_SSOSTNOM);

   virtual TFIBSmallIntField * get_ElementFLBRON_HOT_SSOSTNOM(void);
   virtual void set_ElementFLBRON_HOT_SSOSTNOM(TFIBSmallIntField * ElementFLBRON_HOT_SSOSTNOM);

   virtual TFIBSmallIntField * get_ElementFLRASM_HOT_SSOSTNOM(void);
   virtual void set_ElementFLRASM_HOT_SSOSTNOM(TFIBSmallIntField * ElementFLRASM_HOT_SSOSTNOM);

   virtual TFIBBCDField * get_TableID_HOT_SSOSTNOM(void);
   virtual void set_TableID_HOT_SSOSTNOM(TFIBBCDField * TableID_HOT_SSOSTNOM);

   virtual TFIBBCDField * get_ElementID_HOT_SSOSTNOM(void);
   virtual void set_ElementID_HOT_SSOSTNOM(TFIBBCDField * ElementID_HOT_SSOSTNOM);

   virtual TFIBIntegerField * get_ElementCOLOR_HOT_SSOSTNOM(void);
   virtual void set_ElementCOLOR_HOT_SSOSTNOM(TFIBIntegerField * ElementCOLOR_HOT_SSOSTNOM);

   virtual TFIBWideStringField * get_TableNAME_HOT_SSOSTNOM(void);
   virtual void set_TableNAME_HOT_SSOSTNOM(TFIBWideStringField * TableNAME_HOT_SSOSTNOM);

   virtual TFIBWideStringField * get_ElementNAME_HOT_SSOSTNOM(void);
   virtual void set_ElementNAME_HOT_SSOSTNOM(TFIBWideStringField * ElementNAME_HOT_SSOSTNOM);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 Id);
   virtual bool NewElement(void);
   virtual bool SaveElement(void);
   virtual void CloseElement(void);
   virtual bool DeleteElement(__int64 Id);
   virtual int GetIndexElementaPoID(__int64 id);
};
#define CLSID_THOT_DMSprSostNomImpl __uuidof(THOT_DMSprSostNomImpl)
#endif
