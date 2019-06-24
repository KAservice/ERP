#ifndef UDMStSpr1ImplH
#define UDMStSpr1ImplH
#include "IDMStSpr1.h"
#include "UDMStSpr1.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMStSpr1Impl)) TDMStSpr1Impl : public IDMStSpr1
{
public:
   TDMStSpr1Impl();
   ~TDMStSpr1Impl();
   TDMStSpr1 * Object;
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

//IDMStSpr1
   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual bool CreateObject(UnicodeString name_object);
   virtual bool OpenTable(void);
};
#define CLSID_TDMStSpr1Impl __uuidof(TDMStSpr1Impl)
#endif
