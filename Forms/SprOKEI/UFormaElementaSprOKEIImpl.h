#ifndef UFormaElementaSprOKEIImplH
#define UFormaElementaSprOKEIImplH
#include "IFormaElementaSprOKEI.h"
#include "UFormaElementaSprOKEI.h"
//---------------------------------------------------------------
class __declspec(uuid("{39EE328B-4A27-4631-973E-14A0C43DFE5F}"))TFormaElementaSprOKEIImpl : public IFormaElementaSprOKEI, IkanCallBack
{
public:
   TFormaElementaSprOKEIImpl();
   ~TFormaElementaSprOKEIImpl();
   TFormaElementaSprOKEI * Object;
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

//IFormaElementaSprOKEI
   virtual IDMSprOKEI * get_DM(void);
   virtual void set_DM(IDMSprOKEI * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

};
#define CLSID_TFormaElementaSprOKEIImpl __uuidof(TFormaElementaSprOKEIImpl)
#endif
