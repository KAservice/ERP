#ifndef UFormaSpiskaSprNacenkaImplH
#define UFormaSpiskaSprNacenkaImplH
#include "IFormaSpiskaSprNacenka.h"
#include "UFormaSpiskaSprNacenka.h"
//---------------------------------------------------------------
class __declspec(uuid("{FA4C2FF5-FC71-47E6-B64A-A285F0F7B0AA}")) TFormaSpiskaSprNacenkaImpl : public IFormaSpiskaSprNacenka, IkanCallBack
{
public:
   TFormaSpiskaSprNacenkaImpl();
   ~TFormaSpiskaSprNacenkaImpl();
   TFormaSpiskaSprNacenka * Object;
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

//IFormaSpiskaSprNacenka
   virtual IDMSprNacenka * get_DM(void);
   virtual void set_DM(IDMSprNacenka * DM);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);


};
#define CLSID_TFormaSpiskaSprNacenkaImpl __uuidof(TFormaSpiskaSprNacenkaImpl)
#endif
