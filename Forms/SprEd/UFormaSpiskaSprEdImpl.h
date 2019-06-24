#ifndef UFormaSpiskaSprEdImplH
#define UFormaSpiskaSprEdImplH
#include "IFormaSpiskaSprEd.h"
#include "UFormaSpiskaSprEd.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSpiskaSprEdImpl)) TFormaSpiskaSprEdImpl : public IFormaSpiskaSprEd, IkanCallBack
{
public:
   TFormaSpiskaSprEdImpl();
   ~TFormaSpiskaSprEdImpl();
   TFormaSpiskaSprEd * Object;
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

//IFormaSpiskaSprEd
   virtual IDMSprEd * get_DM(void);
   virtual void set_DM(IDMSprEd * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);


   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual __int64 get_IdFirm(void);
   virtual void set_IdFirm(__int64 IdFirm);

   virtual UnicodeString get_HeaderText(void);
   virtual void set_HeaderText(UnicodeString HeaderText);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaSpiskaSprEdImpl __uuidof(TFormaSpiskaSprEdImpl)
#endif
