#ifndef UFormaSpiskaSprInfBaseImplH
#define UFormaSpiskaSprInfBaseImplH
#include "IFormaSpiskaSprInfBase.h"
#include "UFormaSpiskaSprInfBase.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSpiskaSprInfBaseImpl)) TFormaSpiskaSprInfBaseImpl : public IFormaSpiskaSprInfBase, IkanCallBack
{
public:
   TFormaSpiskaSprInfBaseImpl();
   ~TFormaSpiskaSprInfBaseImpl();
   TFormaSpiskaSprInfBase * Object;
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

//IFormaSpiskaSprInfBase
   virtual IDMSprInfBase * get_DM(void);
   virtual void set_DM(IDMSprInfBase * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void OpenFormElement();
   virtual void OpenFormNewElement();
   virtual void DeleteElement();
};
#define CLSID_TFormaSpiskaSprInfBaseImpl __uuidof(TFormaSpiskaSprInfBaseImpl)
#endif
