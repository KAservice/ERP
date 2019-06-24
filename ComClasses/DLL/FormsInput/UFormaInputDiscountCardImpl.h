#ifndef UFormaInputDiscountCardImplH
#define UFormaInputDiscountCardImplH
#include "IFormaInputDiscountCard.h"
#include "IAsyncExternalEvent.h"
#include "UFormaInputDiscountCard.h"
//---------------------------------------------------------------
class __declspec(uuid("{CEBFE43E-DAA3-4F61-9B0D-C51E816B25B0}"))TFormaInputDiscountCardImpl
					: public IFormaInputDiscountCard, IAsyncExternalEvent
{
public:
   TFormaInputDiscountCardImpl();
   ~TFormaInputDiscountCardImpl();
   TFormaInputDiscountCard * Object;
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

//IFormaInputDiscountCard
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual UnicodeString get_InputText(void);
   virtual void set_InputText(UnicodeString InputText);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   //IAcyncExternalEvent
   virtual int AsyncExternalEvent(char * object, char* event, char* data);
   virtual int SetInterfaceForAsyncExternalEvent(IkanUnknown * i_act_form);
};
#define CLSID_TFormaInputDiscountCardImpl __uuidof(TFormaInputDiscountCardImpl)
#endif
