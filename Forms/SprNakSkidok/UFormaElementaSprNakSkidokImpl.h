#ifndef UFormaElementaSprNakSkidokImplH
#define UFormaElementaSprNakSkidokImplH
#include "IFormaElementaSprNakSkidok.h"
#include "UFormaElementaSprNakSkidok.h"
//---------------------------------------------------------------
class __declspec(uuid("{4F15BDF2-3F79-46D9-8547-316D7C9D7441}")) TFormaElementaSprNakSkidokImpl : public IFormaElementaSprNakSkidok, IkanCallBack
{
public:
   TFormaElementaSprNakSkidokImpl();
   ~TFormaElementaSprNakSkidokImpl();
   TFormaElementaSprNakSkidok * Object;
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

//IFormaElementaSprNakSkidok
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMSprNakSkidok * get_DM(void);
   virtual void set_DM(IDMSprNakSkidok * DM);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaSprNakSkidokImpl __uuidof(TFormaElementaSprNakSkidokImpl)
#endif
