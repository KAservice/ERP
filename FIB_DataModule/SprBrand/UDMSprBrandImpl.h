#ifndef UDMSprBrandImplH
#define UDMSprBrandImplH
#include "IDMSprBrand.h"
#include "UDMSprBrand.h"
//---------------------------------------------------------------
class __declspec(uuid("{EBFAA833-FF68-4464-8EE2-AE5BB365E6C3}")) TDMSprBrandImpl : public IDMSprBrand
{
public:
   TDMSprBrandImpl();
   ~TDMSprBrandImpl();
   TDMSprBrand * Object;
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

//IDMSprBrand
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

   virtual TFIBBCDField * get_TableID_SBRAND(void);
   virtual void set_TableID_SBRAND(TFIBBCDField * TableID_SBRAND);

   virtual TFIBBCDField * get_TableIDBASE_SBRAND(void);
   virtual void set_TableIDBASE_SBRAND(TFIBBCDField * TableIDBASE_SBRAND);

   virtual TFIBBCDField * get_ElementID_SBRAND(void);
   virtual void set_ElementID_SBRAND(TFIBBCDField * ElementID_SBRAND);

   virtual TFIBBCDField * get_ElementIDBASE_SBRAND(void);
   virtual void set_ElementIDBASE_SBRAND(TFIBBCDField * ElementIDBASE_SBRAND);

   virtual TFIBWideStringField * get_TableNAME_SBRAND(void);
   virtual void set_TableNAME_SBRAND(TFIBWideStringField * TableNAME_SBRAND);

   virtual TFIBWideStringField * get_ElementNAME_SBRAND(void);
   virtual void set_ElementNAME_SBRAND(TFIBWideStringField * ElementNAME_SBRAND);


   virtual bool get_Error(void);
   virtual void set_Error(bool Error);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual void CloseElement(void);
   virtual bool DeleteElement(__int64 id);
};
#define CLSID_TDMSprBrandImpl __uuidof(TDMSprBrandImpl)
#endif
