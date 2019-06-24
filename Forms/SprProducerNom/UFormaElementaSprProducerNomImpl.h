#ifndef UFormaElementaSprProducerNomImplH
#define UFormaElementaSprProducerNomImplH
#include "IFormaElementaSprProducerNom.h"
#include "UFormaElementaSprProducerNom.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaElementaSprProducerNomImpl)) TFormaElementaSprProducerNomImpl : public IFormaElementaSprProducerNom, IkanCallBack
{
public:
   TFormaElementaSprProducerNomImpl();
   ~TFormaElementaSprProducerNomImpl();
   TFormaElementaSprProducerNom * Object;
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

//IFormaElementaSprProducerNom
   virtual IDMSprProducerNom * get_DM(void);
   virtual void set_DM(IDMSprProducerNom * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdProducerTypePrice(void);
   virtual void set_IdProducerTypePrice(__int64 IdProducerTypePrice);

   virtual __int64 get_IdGrpNom(void);
   virtual void set_IdGrpNom(__int64 IdGrpNom);

   virtual UnicodeString get_NameGrpNom(void);
   virtual void set_NameGrpNom(UnicodeString NameGrpNom);

   virtual __int64 get_IdProducer(void);
   virtual void set_IdProducer(__int64 IdProducer);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaSprProducerNomImpl __uuidof(TFormaElementaSprProducerNomImpl)
#endif
