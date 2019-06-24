#ifndef UFormaSpiskaSprProjectImplH
#define UFormaSpiskaSprProjectImplH
#include "IFormaSpiskaSprProject.h"
#include "UFormaSpiskaSprProject.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSpiskaSprProjectImpl))TFormaSpiskaSprProjectImpl : public IFormaSpiskaSprProject, IkanCallBack
{
public:
   TFormaSpiskaSprProjectImpl();
   ~TFormaSpiskaSprProjectImpl();
   TFormaSpiskaSprProject * Object;
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

//IFormaSpiskaSprProject
   virtual IDMSprProject* get_DM(void);
   virtual void set_DM(IDMSprProject* DM);

   virtual IDMSprGrpProject * get_DMGrp(void);
   virtual void set_DMGrp(IDMSprGrpProject * DMGrp);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdProject(void);
   virtual void set_IdProject(__int64 IdProject);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual bool get_Podbor(void);
   virtual void set_Podbor(bool Podbor);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);


   virtual void UpdateForm(void);
};
#define CLSID_TFormaSpiskaSprProjectImpl __uuidof(TFormaSpiskaSprProjectImpl)
#endif
