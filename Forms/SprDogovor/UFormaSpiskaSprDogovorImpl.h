#ifndef UFormaSpiskaSprDogovorImplH
#define UFormaSpiskaSprDogovorImplH
#include "IFormaSpiskaSprDogovor.h"
#include "UFormaSpiskaSprDogovor.h"
//---------------------------------------------------------------
class __declspec(uuid("{D05FCC28-40CE-439D-BD8A-844B1BD8B17D}")) TFormaSpiskaSprDogovorImpl : public IFormaSpiskaSprDogovor, IkanCallBack
{
public:
   TFormaSpiskaSprDogovorImpl();
   ~TFormaSpiskaSprDogovorImpl();
   TFormaSpiskaSprDogovor * Object;
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

//IFormaSpiskaSprDogovor
   virtual IDMSprDogovor * get_DM(void);
   virtual void set_DM(IDMSprDogovor * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdKlient(void);
   virtual void set_IdKlient(__int64 IdKlient);

   virtual void UpdateForm();
};
#define CLSID_TFormaSpiskaSprDogovorImpl __uuidof(TFormaSpiskaSprDogovorImpl)
#endif
