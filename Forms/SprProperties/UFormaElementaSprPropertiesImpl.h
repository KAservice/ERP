#ifndef UFormaElementaSprPropertiesImplH
#define UFormaElementaSprPropertiesImplH
#include "IFormaElementaSprProperties.h"
#include "UFormaElementaSprProperties.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaElementaSprPropertiesImpl)) TFormaElementaSprPropertiesImpl : public IFormaElementaSprProperties, IkanCallBack
{
public:
   TFormaElementaSprPropertiesImpl();
   ~TFormaElementaSprPropertiesImpl();
   TFormaElementaSprProperties * Object;
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

//IFormaElementaSprProperties
   virtual IDMSprProperties * get_DM(void);
   virtual void set_DM(IDMSprProperties * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdGrpProp(void);
   virtual void set_IdGrpProp(__int64 IdGrpProp);

   virtual UnicodeString get_NameGrp(void);
   virtual void set_NameGrp(UnicodeString NameGrp);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaSprPropertiesImpl __uuidof(TFormaElementaSprPropertiesImpl)
#endif
