#ifndef UFormaSpiskaSprRaschSchetImplH
#define UFormaSpiskaSprRaschSchetImplH
#include "IFormaSpiskaSprRaschSchet.h"
#include "UFormaSpiskaSprRaschSchet.h"
//---------------------------------------------------------------
class __declspec(uuid("{59BA1EA4-62D4-4EA0-A4AC-A667A63EA7B6}"))TFormaSpiskaSprRaschSchetImpl : public IFormaSpiskaSprRaschSchet, IkanCallBack
{
public:
   TFormaSpiskaSprRaschSchetImpl();
   ~TFormaSpiskaSprRaschSchetImpl();
   TFormaSpiskaSprRaschSchet * Object;
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

//IFormaSpiskaSprRaschSchet
   virtual IDMSprRaschSchet * get_DM(void);
   virtual void set_DM(IDMSprRaschSchet * DM);

   virtual __int64 get_IdKlient(void);
   virtual void set_IdKlient(__int64 IdKlient);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);


};
#define CLSID_TFormaSpiskaSprRaschSchetImpl __uuidof(TFormaSpiskaSprRaschSchetImpl)
#endif
