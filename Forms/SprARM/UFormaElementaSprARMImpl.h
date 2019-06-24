#ifndef UFormaElementaSprARMImplH
#define UFormaElementaSprARMImplH
#include "IFormaElementaSprARM.h"
#include "UFormaElementaSprARM.h"
//---------------------------------------------------------------
class __declspec(uuid("{36DE9715-85C8-45BA-B144-520BAD8DEC61}")) TFormaElementaSprARMImpl : public IFormaElementaSprARM, IkanCallBack
{
public:
   TFormaElementaSprARMImpl();
   ~TFormaElementaSprARMImpl();
   TFormaElementaSprARM * Object;
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

//IFormaElementaSprARM
   virtual IDMSprARM * get_DM(void);
   virtual void set_DM(IDMSprARM * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);


   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaSprARMImpl __uuidof(TFormaElementaSprARMImpl)
#endif
