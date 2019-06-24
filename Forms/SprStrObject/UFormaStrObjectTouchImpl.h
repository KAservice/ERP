#ifndef UFormaStrObjectTouchImplH
#define UFormaStrObjectTouchImplH
#include "IMainInterface.h"
#include "UFormaStrObjectTouch.h"
//---------------------------------------------------------------
class __declspec(uuid("{8ED209C9-28BA-499E-BCF0-46A0D98150B4}"))TFormaStrObjectTouchImpl
			: public IMainInterface, IkanCallBack
{
public:
   TFormaStrObjectTouchImpl();
   ~TFormaStrObjectTouchImpl();
   TFormaStrObjectTouch * Object;
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

//IFormaStrObjectTouch
};
#define CLSID_TFormaStrObjectTouchImpl __uuidof(TFormaStrObjectTouchImpl)
#endif
