#ifndef UREM_FormaSpiskaSprKKTDvImplH
#define UREM_FormaSpiskaSprKKTDvImplH
#include "IREM_FormaSpiskaSprKKTDv.h"
#include "UREM_FormaSpiskaSprKKTDv.h"
//---------------------------------------------------------------
class __declspec(uuid("{A896C076-96EB-4BF2-90AE-E06DFEF7C675}")) TREM_FormaSpiskaSprKKTDvImpl : public IREM_FormaSpiskaSprKKTDv, IkanCallBack
{
public:
   TREM_FormaSpiskaSprKKTDvImpl();
   ~TREM_FormaSpiskaSprKKTDvImpl();
   TREM_FormaSpiskaSprKKTDv * Object;
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

//IREM_FormaSpiskaSprKKTDv
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual UnicodeString get_TextMessage(void);
   virtual void set_TextMessage(UnicodeString TextMessage);

   virtual UnicodeString get_TextZayavka(void);
   virtual void set_TextZayavka(UnicodeString TextZayavka);

   virtual IREM_DMSprKKTDv * get_DM(void);
   virtual void set_DM(IREM_DMSprKKTDv * DM);

   virtual __int64 get_IdOwner(void);
   virtual void set_IdOwner(__int64 IdOwner);

   virtual void UpdateForm();
};
#define CLSID_TREM_FormaSpiskaSprKKTDvImpl __uuidof(TREM_FormaSpiskaSprKKTDvImpl)
#endif
