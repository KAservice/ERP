#ifndef UHOT_FormaSpiskaSprObjectImplH
#define UHOT_FormaSpiskaSprObjectImplH
#include "IHOT_FormaSpiskaSprObject.h"
#include "UHOT_FormaSpiskaSprObject.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_THOT_FormaSpiskaSprObjectImpl)) THOT_FormaSpiskaSprObjectImpl : public IHOT_FormaSpiskaSprObject, IkanCallBack
{
public:
   THOT_FormaSpiskaSprObjectImpl();
   ~THOT_FormaSpiskaSprObjectImpl();
   THOT_FormaSpiskaSprObject * Object;
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

//IHOT_FormaSpiskaSprObject
   virtual IHOT_DMSprObject * get_DM(void);
   virtual void set_DM(IHOT_DMSprObject * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

};
#define CLSID_THOT_FormaSpiskaSprObjectImpl __uuidof(THOT_FormaSpiskaSprObjectImpl)
#endif
