#ifndef UFormaElementaSprAddressNasPunktImplH
#define UFormaElementaSprAddressNasPunktImplH
#include "IFormaElementaSprAddressNasPunkt.h"
#include "UFormaElementaSprAddressNasPunkt.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaElementaSprAddressNasPunktImpl)) TFormaElementaSprAddressNasPunktImpl : public IFormaElementaSprAddressNasPunkt, IkanCallBack
{
public:
   TFormaElementaSprAddressNasPunktImpl();
   ~TFormaElementaSprAddressNasPunktImpl();
   TFormaElementaSprAddressNasPunkt * Object;
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

//IFormaElementaSprAddressNasPunkt
   virtual IDMSprAddressNasPunkt * get_DM(void);
   virtual void set_DM(IDMSprAddressNasPunkt * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaSprAddressNasPunktImpl __uuidof(TFormaElementaSprAddressNasPunktImpl)
#endif
