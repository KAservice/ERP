#ifndef UFormaSpiskaExtModuleImplH
#define UFormaSpiskaExtModuleImplH
#include "IFormaSpiskaExtModule.h"
#include "UFormaSpiskaExtModule.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSpiskaExtModuleImpl)) TFormaSpiskaExtModuleImpl : public IFormaSpiskaExtModule, IkanCallBack
{
public:
   TFormaSpiskaExtModuleImpl();
   ~TFormaSpiskaExtModuleImpl();
   TFormaSpiskaExtModule * Object;
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

//IFormaSpiskaExtModule
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMExtModule* get_DM(void);
   virtual void set_DM(IDMExtModule* DM);

   virtual IDMExtModuleGrp * get_DMGrp(void);
   virtual void set_DMGrp(IDMExtModuleGrp * DMGrp);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdExtModule(void);
   virtual void set_IdExtModule(__int64 IdExtModule);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual void UpdateForm(void);
   virtual void RunExternalModule(void);
};
#define CLSID_TFormaSpiskaExtModuleImpl __uuidof(TFormaSpiskaExtModuleImpl)
#endif
