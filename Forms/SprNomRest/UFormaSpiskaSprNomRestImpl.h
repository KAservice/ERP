#ifndef UFormaSpiskaSprNomRestImplH
#define UFormaSpiskaSprNomRestImplH
#include "IFormaSpiskaSprNomRest.h"
#include "UFormaSpiskaSprNomRest.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSpiskaSprNomRestImpl)) TFormaSpiskaSprNomRestImpl : public IFormaSpiskaSprNomRest, IkanCallBack
{
public:
   TFormaSpiskaSprNomRestImpl();
   ~TFormaSpiskaSprNomRestImpl();
   TFormaSpiskaSprNomRest * Object;
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

//IFormaSpiskaSprNomRest
   virtual IDMSprNomRest * get_DM(void);
   virtual void set_DM(IDMSprNomRest * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual UnicodeString get_NameNom(void);
   virtual void set_NameNom(UnicodeString NameNom);

   virtual void UpdateForm();
};
#define CLSID_TFormaSpiskaSprNomRestImpl __uuidof(TFormaSpiskaSprNomRestImpl)
#endif
