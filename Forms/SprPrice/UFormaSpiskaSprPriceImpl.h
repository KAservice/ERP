#ifndef UFormaSpiskaSprPriceImplH
#define UFormaSpiskaSprPriceImplH
#include "IFormaSpiskaSprPrice.h"
#include "UFormaSpiskaSprPrice.h"
//---------------------------------------------------------------
class __declspec(uuid("{22DFFE06-89F3-49C5-9633-D87C59BF0F2A}"))TFormaSpiskaSprPriceImpl : public IFormaSpiskaSprPrice, IkanCallBack
{
public:
   TFormaSpiskaSprPriceImpl();
   ~TFormaSpiskaSprPriceImpl();
   TFormaSpiskaSprPrice * Object;
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

//IFormaSpiskaSprPrice
   virtual IDMSprPrice * get_DM(void);
   virtual void set_DM(IDMSprPrice * DM);

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
#define CLSID_TFormaSpiskaSprPriceImpl __uuidof(TFormaSpiskaSprPriceImpl)
#endif
