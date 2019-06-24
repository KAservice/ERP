#ifndef UHOT_DMSprObjectImplH
#define UHOT_DMSprObjectImplH
#include "IHOT_DMSprObject.h"
#include "UHOT_DMSprObject.h"
//---------------------------------------------------------------
class __declspec(uuid("{C610E978-9D16-41CE-89A9-99FCD9F5D1A7}")) THOT_DMSprObjectImpl : public IHOT_DMSprObject
{
public:
   THOT_DMSprObjectImpl();
   ~THOT_DMSprObjectImpl();
   THOT_DMSprObject * Object;
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

//IHOT_DMSprObject
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

   virtual TFIBBCDField * get_TableID_HOT_SOBJECT(void);
   virtual void set_TableID_HOT_SOBJECT(TFIBBCDField * TableID_HOT_SOBJECT);

   virtual TFIBBCDField * get_TableIDSKL_HOT_SOBJECT(void);
   virtual void set_TableIDSKL_HOT_SOBJECT(TFIBBCDField * TableIDSKL_HOT_SOBJECT);

   virtual TFIBBCDField * get_ElementID_HOT_SOBJECT(void);
   virtual void set_ElementID_HOT_SOBJECT(TFIBBCDField * ElementID_HOT_SOBJECT);

   virtual TFIBBCDField * get_ElementIDSKL_HOT_SOBJECT(void);
   virtual void set_ElementIDSKL_HOT_SOBJECT(TFIBBCDField * ElementIDSKL_HOT_SOBJECT);

   virtual TFIBWideStringField * get_ElementNAME_HOT_SOBJECT(void);
   virtual void set_ElementNAME_HOT_SOBJECT(TFIBWideStringField * ElementNAME_HOT_SOBJECT);

   virtual TFIBWideStringField * get_ElementNAMESKLAD(void);
   virtual void set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD);

   virtual TFIBWideStringField * get_TableNAME_HOT_SOBJECT(void);
   virtual void set_TableNAME_HOT_SOBJECT(TFIBWideStringField * TableNAME_HOT_SOBJECT);

   virtual TFIBWideStringField * get_TableNAMESKLAD(void);
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 Id);
   virtual bool NewElement(void);
   virtual bool SaveElement(void);
   virtual void CloseElement(void);
   virtual bool DeleteElement(__int64 Id);
   virtual int GetIndexElementaPoID(__int64 id);
};
#define CLSID_THOT_DMSprObjectImpl __uuidof(THOT_DMSprObjectImpl)
#endif
