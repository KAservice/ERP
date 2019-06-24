#ifndef UFormaSpiskaSprModImplH
#define UFormaSpiskaSprModImplH
#include "IFormaSpiskaSprMod.h"
#include "UFormaSpiskaSprMod.h"
//---------------------------------------------------------------
class __declspec(uuid("{C88F45E7-1D61-4F58-8983-EE2EEC6FFF4A}"))TFormaSpiskaSprModImpl : public IFormaSpiskaSprMod, IkanCallBack
{
public:
   TFormaSpiskaSprModImpl();
   ~TFormaSpiskaSprModImpl();
   TFormaSpiskaSprMod * Object;
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

//IFormaSpiskaSprMod
   virtual IDMSprMod * get_DM(void);
   virtual void set_DM(IDMSprMod * DM);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void DeleteElement();
};
#define CLSID_TFormaSpiskaSprModImpl __uuidof(TFormaSpiskaSprModImpl)
#endif
