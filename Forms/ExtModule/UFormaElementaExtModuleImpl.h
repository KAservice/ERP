#ifndef UFormaElementaExtModuleImplH
#define UFormaElementaExtModuleImplH
#include "IFormaElementaExtModule.h"
#include "UFormaElementaExtModule.h"
//---------------------------------------------------------------
class __declspec(uuid("{8D7D25D7-3709-466B-B5F1-BBDBC644985A}")) TFormaElementaExtModuleImpl : public IFormaElementaExtModule, IkanCallBack
{
public:
   TFormaElementaExtModuleImpl();
   ~TFormaElementaExtModuleImpl();
   TFormaElementaExtModule * Object;
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

   //IkanCallBack  
   virtual int kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end);

//IFormaElementaExtModule
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMExtModule* get_DM(void);
   virtual void set_DM(IDMExtModule* DM);

   virtual IDMExtModulePriv * get_DMPriv(void);
   virtual void set_DMPriv(IDMExtModulePriv * DMPriv);

   virtual __int64 get_IdModule(void);
   virtual void set_IdModule(__int64 IdModule);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaExtModuleImpl __uuidof(TFormaElementaExtModuleImpl)
#endif
