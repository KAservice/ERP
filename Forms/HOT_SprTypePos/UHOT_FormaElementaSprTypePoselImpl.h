#ifndef UHOT_FormaElementaSprTypePoselImplH
#define UHOT_FormaElementaSprTypePoselImplH
#include "IHOT_FormaElementaSprTypePosel.h"
#include "UHOT_FormaElementaSprTypePosel.h"
//---------------------------------------------------------------
class __declspec(uuid("{90078E81-55E3-4374-B850-5AB79F0A0653}")) THOT_FormaElementaSprTypePoselImpl : public IHOT_FormaElementaSprTypePosel, IkanCallBack
{
public:
   THOT_FormaElementaSprTypePoselImpl();
   ~THOT_FormaElementaSprTypePoselImpl();
   THOT_FormaElementaSprTypePosel * Object;
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

//IHOT_FormaElementaSprTypePosel
   virtual IHOT_DMSprTypePosel * get_DM(void);
   virtual void set_DM(IHOT_DMSprTypePosel * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_THOT_FormaElementaSprTypePoselImpl __uuidof(THOT_FormaElementaSprTypePoselImpl)
#endif
