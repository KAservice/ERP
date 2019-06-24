#ifndef UFormaSpiskaSprOborudImplH
#define UFormaSpiskaSprOborudImplH
#include "IFormaSpiskaSprOborud.h"
#include "UFormaSpiskaSprOborud.h"
//---------------------------------------------------------------
class __declspec(uuid("{7E725397-0517-4DEC-858E-E7F68A149C0E}"))TFormaSpiskaSprOborudImpl : public IFormaSpiskaSprOborud, IkanCallBack
{
public:
   TFormaSpiskaSprOborudImpl();
   ~TFormaSpiskaSprOborudImpl();
   TFormaSpiskaSprOborud * Object;
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

//IFormaSpiskaSprOborud
   virtual IDMSprOborud * get_DM(void);
   virtual void set_DM(IDMSprOborud * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdKKM(void);
   virtual void set_IdKKM(__int64 IdKKM);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaSpiskaSprOborudImpl __uuidof(TFormaSpiskaSprOborudImpl)
#endif
