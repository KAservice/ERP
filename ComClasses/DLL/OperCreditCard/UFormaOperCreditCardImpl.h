#ifndef UFormaOperCreditCardImplH
#define UFormaOperCreditCardImplH
#include "IMainInterface.h"
#include "IAsyncExternalEvent.h"
#include "UFormaOperCreditCard.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaOperCreditCardImpl)) TFormaOperCreditCardImpl
					 : public IMainInterface, IkanCallBack ,IAsyncExternalEvent
{
public:
   TFormaOperCreditCardImpl();
   ~TFormaOperCreditCardImpl();
   TFormaOperCreditCard * Object;
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
//IFormaOperCreditCard
};
#define CLSID_TFormaOperCreditCardImpl __uuidof(TFormaOperCreditCardImpl)
#endif
