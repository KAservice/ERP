#ifndef UFormaSpiskaSprImportEdImplH
#define UFormaSpiskaSprImportEdImplH
#include "IFormaSpiskaSprImportEd.h"
#include "UFormaSpiskaSprImportEd.h"
//---------------------------------------------------------------
class __declspec(uuid("{703B400C-FF0C-4FB5-99AE-8FE44758FA94}"))TFormaSpiskaSprImportEdImpl : public IFormaSpiskaSprImportEd, IkanCallBack
{
public:
   TFormaSpiskaSprImportEdImpl();
   ~TFormaSpiskaSprImportEdImpl();
   TFormaSpiskaSprImportEd * Object;
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

//IFormaSpiskaSprImportEd
   virtual IDMSprImportEd * get_DM(void);
   virtual void set_DM(IDMSprImportEd * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdEd(void);
   virtual void set_IdEd(__int64 IdEd);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual void UpdateForm();
};
#define CLSID_TFormaSpiskaSprImportEdImpl __uuidof(TFormaSpiskaSprImportEdImpl)
#endif
