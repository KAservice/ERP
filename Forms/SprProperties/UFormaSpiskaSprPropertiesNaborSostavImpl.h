#ifndef UFormaSpiskaSprPropertiesNaborSostavImplH
#define UFormaSpiskaSprPropertiesNaborSostavImplH
#include "IFormaSpiskaSprPropertiesNaborSostav.h"
#include "UFormaSpiskaSprPropertiesNaborSostav.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSpiskaSprPropertiesNaborSostavImpl)) TFormaSpiskaSprPropertiesNaborSostavImpl : public IFormaSpiskaSprPropertiesNaborSostav, IkanCallBack
{
public:
   TFormaSpiskaSprPropertiesNaborSostavImpl();
   ~TFormaSpiskaSprPropertiesNaborSostavImpl();
   TFormaSpiskaSprPropertiesNaborSostav * Object;
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

//IFormaSpiskaSprPropertiesNaborSostav
   virtual IDMSprPropertiesNaborSostav * get_DM(void);
   virtual void set_DM(IDMSprPropertiesNaborSostav * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdNabor(void);
   virtual void set_IdNabor(__int64 IdNabor);

   virtual UnicodeString get_HeaderText(void);
   virtual void set_HeaderText(UnicodeString HeaderText);

   virtual void UpdateForm();
};
#define CLSID_TFormaSpiskaSprPropertiesNaborSostavImpl __uuidof(TFormaSpiskaSprPropertiesNaborSostavImpl)
#endif
