#ifndef UFormaSpiskaSprProducerNomImplH
#define UFormaSpiskaSprProducerNomImplH
#include "IFormaSpiskaSprProducerNom.h"
#include "UFormaSpiskaSprProducerNom.h"
#include "UGlobalConstant.h"
#include "IAsyncExternalEvent.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSpiskaSprProducerNomImpl)) TFormaSpiskaSprProducerNomImpl
				 : public IFormaSpiskaSprProducerNom, IkanCallBack ,IAsyncExternalEvent
{
public:
   TFormaSpiskaSprProducerNomImpl();
   ~TFormaSpiskaSprProducerNomImpl();
   TFormaSpiskaSprProducerNom * Object;
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
   //IAcyncExternalEvent
   virtual int AsyncExternalEvent(char * object, char* event, char* data);
   virtual int SetInterfaceForAsyncExternalEvent(IkanUnknown * i_act_form);

//IFormaSpiskaSprProducerNom
   virtual IDMSprProducerNom* get_DM(void);
   virtual void set_DM(IDMSprProducerNom* DM);

   virtual IDMSprProducerNomGrp * get_DMGrp(void);
   virtual void set_DMGrp(IDMSprProducerNomGrp * DMGrp);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual __int64 get_IdGroupElement(void);
   virtual void set_IdGroupElement(__int64 IdGroupElement);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual bool get_Podbor(void);
   virtual void set_Podbor(bool Podbor);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual void UpdateForm(void);
   virtual void ReadShtrihCodEvent(int number, UnicodeString sh);
};
#define CLSID_TFormaSpiskaSprProducerNomImpl __uuidof(TFormaSpiskaSprProducerNomImpl)
#endif
