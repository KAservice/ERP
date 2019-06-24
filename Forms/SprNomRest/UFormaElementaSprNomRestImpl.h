#ifndef UFormaElementaSprNomRestImplH
#define UFormaElementaSprNomRestImplH
#include "IFormaElementaSprNomRest.h"
#include "UFormaElementaSprNomRest.h"
//---------------------------------------------------------------
class __declspec(uuid("{135CBEE5-A9FF-4CD2-9F21-1DC27D5E9A83}")) TFormaElementaSprNomRestImpl : public IFormaElementaSprNomRest, IkanCallBack
{
public:
   TFormaElementaSprNomRestImpl();
   ~TFormaElementaSprNomRestImpl();
   TFormaElementaSprNomRest * Object;
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

//IFormaElementaSprNomRest
   virtual IDMSprNomRest * get_DM(void);
   virtual void set_DM(IDMSprNomRest * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual UnicodeString get_NameNom(void);
   virtual void set_NameNom(UnicodeString NameNom);

   virtual __int64 get_Id(void);
   virtual void set_Id(__int64 Id);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaSprNomRestImpl __uuidof(TFormaElementaSprNomRestImpl)
#endif
