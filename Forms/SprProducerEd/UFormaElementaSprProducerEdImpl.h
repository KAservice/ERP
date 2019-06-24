#ifndef UFormaElementaSprProducerEdImplH
#define UFormaElementaSprProducerEdImplH
#include "IFormaElementaSprProducerEd.h"
#include "UFormaElementaSprProducerEd.h"
#include "UGlobalConstant.h"
#include "IAsyncExternalEvent.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaElementaSprProducerEdImpl)) TFormaElementaSprProducerEdImpl
: public IFormaElementaSprProducerEd, IkanCallBack,IAsyncExternalEvent
{
public:
   TFormaElementaSprProducerEdImpl();
   ~TFormaElementaSprProducerEdImpl();
   TFormaElementaSprProducerEd * Object;
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

//IFormaElementaSprProducerEd
   virtual IDMSprProducerEd * get_DM(void);
   virtual void set_DM(IDMSprProducerEd * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaSprProducerEdImpl __uuidof(TFormaElementaSprProducerEdImpl)
#endif
