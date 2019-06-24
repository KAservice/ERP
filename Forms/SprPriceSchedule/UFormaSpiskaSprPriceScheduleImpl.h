#ifndef UFormaSpiskaSprPriceScheduleImplH
#define UFormaSpiskaSprPriceScheduleImplH
#include "IFormaSpiskaSprPriceSchedule.h"
#include "UFormaSpiskaSprPriceSchedule.h"
//---------------------------------------------------------------
class __declspec(uuid("{98715250-97E4-47AA-BA15-0E74ED8DBADD}"))TFormaSpiskaSprPriceScheduleImpl : public IFormaSpiskaSprPriceSchedule, IkanCallBack
{
public:
   TFormaSpiskaSprPriceScheduleImpl();
   ~TFormaSpiskaSprPriceScheduleImpl();
   TFormaSpiskaSprPriceSchedule * Object;
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

//IFormaSpiskaSprPriceSchedule
   virtual IDMSprPriceSchedule * get_DM(void);
   virtual void set_DM(IDMSprPriceSchedule * DM);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual UnicodeString get_HeaderText(void);
   virtual void set_HeaderText(UnicodeString HeaderText);

   virtual void UpdateForm(void);

};
#define CLSID_TFormaSpiskaSprPriceScheduleImpl __uuidof(TFormaSpiskaSprPriceScheduleImpl)
#endif
