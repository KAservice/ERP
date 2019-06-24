#ifndef UFormaElementaSprUserImplH
#define UFormaElementaSprUserImplH
#include "IFormaElementaSprUser.h"
#include "UFormaElementaSprUser.h"
//---------------------------------------------------------------
class __declspec(uuid("{987E4C4D-2ED2-4F75-9F3B-213926D3AC86}")) TFormaElementaSprUserImpl : public IFormaElementaSprUser, IkanCallBack
{
public:
   TFormaElementaSprUserImpl();
   ~TFormaElementaSprUserImpl();
   TFormaElementaSprUser * Object;
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

//IFormaElementaSprUser
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMSprUser * get_DM(void);
   virtual void set_DM(IDMSprUser * DM);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaSprUserImpl __uuidof(TFormaElementaSprUserImpl)
#endif
