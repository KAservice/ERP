#ifndef UFormaElementaSprEdImplH
#define UFormaElementaSprEdImplH
#include "IFormaElementaSprEd.h"
#include "UFormaElementaSprEd.h"
#include "IAsyncExternalEvent.h"

//---------------------------------------------------------------
class __declspec(uuid("{64399679-5677-4CE8-BB2B-F66E7498E409}")) TFormaElementaSprEdImpl
					: public IFormaElementaSprEd, IkanCallBack,IAsyncExternalEvent
{
public:
   TFormaElementaSprEdImpl();
   ~TFormaElementaSprEdImpl();
   TFormaElementaSprEd * Object;
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

   //IAcyncExternalEvent
   virtual int AsyncExternalEvent(char * object, char* event, char* data);
   virtual int SetInterfaceForAsyncExternalEvent(IkanUnknown * i_act_form);

//IFormaElementaSprEd
   virtual IDMSprEd * get_DM(void);
   virtual void set_DM(IDMSprEd * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaSprEdImpl __uuidof(TFormaElementaSprEdImpl)
#endif
