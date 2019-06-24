#ifndef UFormaElementaSprInvImplH
#define UFormaElementaSprInvImplH
#include "IFormaElementaSprInv.h"
#include "UFormaElementaSprInv.h"
//---------------------------------------------------------------
class __declspec(uuid("{AB8708A1-1C7F-4FDB-852D-DE7234DE91C4}"))TFormaElementaSprInvImpl : public IFormaElementaSprInv, IkanCallBack
{
public:
   TFormaElementaSprInvImpl();
   ~TFormaElementaSprInvImpl();
   TFormaElementaSprInv * Object;
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

//IFormaElementaSprInv
   virtual IDMSprInv * get_DM(void);
   virtual void set_DM(IDMSprInv * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaSprInvImpl __uuidof(TFormaElementaSprInvImpl)
#endif
