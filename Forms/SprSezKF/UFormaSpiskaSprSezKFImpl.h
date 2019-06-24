#ifndef UFormaSpiskaSprSezKFImplH
#define UFormaSpiskaSprSezKFImplH
#include "IFormaSpiskaSprSezKF.h"
#include "UFormaSpiskaSprSezKF.h"
//---------------------------------------------------------------
class __declspec(uuid("{A8CDE8A4-6D1F-4DF7-88B7-35BF241C7282}")) TFormaSpiskaSprSezKFImpl : public IFormaSpiskaSprSezKF, IkanCallBack
{
public:
   TFormaSpiskaSprSezKFImpl();
   ~TFormaSpiskaSprSezKFImpl();
   TFormaSpiskaSprSezKF * Object;
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

//IFormaSpiskaSprSezKF
   virtual IDMSprSezKF * get_DM(void);
   virtual void set_DM(IDMSprSezKF * DM);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void DeleteElement();
};
#define CLSID_TFormaSpiskaSprSezKFImpl __uuidof(TFormaSpiskaSprSezKFImpl)
#endif
