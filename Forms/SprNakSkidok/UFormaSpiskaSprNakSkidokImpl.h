#ifndef UFormaSpiskaSprNakSkidokImplH
#define UFormaSpiskaSprNakSkidokImplH
#include "IFormaSpiskaSprNakSkidok.h"
#include "UFormaSpiskaSprNakSkidok.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSpiskaSprNakSkidokImpl)) TFormaSpiskaSprNakSkidokImpl : public IFormaSpiskaSprNakSkidok, IkanCallBack
{
public:
   TFormaSpiskaSprNakSkidokImpl();
   ~TFormaSpiskaSprNakSkidokImpl();
   TFormaSpiskaSprNakSkidok * Object;
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

//IFormaSpiskaSprNakSkidok
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMSprNakSkidok * get_DM(void);
   virtual void set_DM(IDMSprNakSkidok * DM);

   virtual void UpdateForm();
};
#define CLSID_TFormaSpiskaSprNakSkidokImpl __uuidof(TFormaSpiskaSprNakSkidokImpl)
#endif
