#ifndef UDMDataSetImplH
#define UDMDataSetImplH
#include "IDMDataSet.h"
#include "UDMDataSet.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMDataSetImpl)) TDMDataSetImpl : public IDMDataSet
{
public:
   TDMDataSetImpl();
   ~TDMDataSetImpl();
   TDMDataSet * Object;
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

//IDMDataSet
   virtual TpFIBTransaction * get_Transaction(void);
   virtual void set_Transaction(TpFIBTransaction * Transaction);

   virtual TpFIBDataSet * get_DataSet(void);
   virtual void set_DataSet(TpFIBDataSet * DataSet);

   virtual TDataSource * get_DataSource(void);
   virtual void set_DataSource(TDataSource * DataSource);

};
#define CLSID_TDMDataSetImpl __uuidof(TDMDataSetImpl)
#endif
