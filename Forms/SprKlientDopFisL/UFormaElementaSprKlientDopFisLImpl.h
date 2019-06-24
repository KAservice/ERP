#ifndef UFormaElementaSprKlientDopFisLImplH
#define UFormaElementaSprKlientDopFisLImplH
#include "IFormaElementaSprKlientDopFisL.h"
#include "UFormaElementaSprKlientDopFisL.h"
//---------------------------------------------------------------
class __declspec(uuid("{57832B3F-CCAC-46DC-B5F8-E56810E104CD}")) TFormaElementaSprKlientDopFisLImpl : public IFormaElementaSprKlientDopFisL, IkanCallBack
{
public:
   TFormaElementaSprKlientDopFisLImpl();
   ~TFormaElementaSprKlientDopFisLImpl();
   TFormaElementaSprKlientDopFisL * Object;
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

//IFormaElementaSprKlientDopFisL
   virtual IDMSprKlientDopFisL * get_DM(void);
   virtual void set_DM(IDMSprKlientDopFisL * DM);

   virtual UnicodeString get_NameKlient(void);
   virtual void set_NameKlient(UnicodeString NameKlient);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaSprKlientDopFisLImpl __uuidof(TFormaElementaSprKlientDopFisLImpl)
#endif
