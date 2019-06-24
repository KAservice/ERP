#ifndef UREM_FormaElementaSprProducerModelPropertiesValueImplH
#define UREM_FormaElementaSprProducerModelPropertiesValueImplH
#include "IREM_FormaElementaSprProducerModelPropertiesValue.h"
#include "UREM_FormaElementaSprProducerModelPropertiesValue.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaElementaSprProducerModelPropertiesValueImpl)) TREM_FormaElementaSprProducerModelPropertiesValueImpl : public IREM_FormaElementaSprProducerModelPropertiesValue, IkanCallBack
{
public:
   TREM_FormaElementaSprProducerModelPropertiesValueImpl();
   ~TREM_FormaElementaSprProducerModelPropertiesValueImpl();
   TREM_FormaElementaSprProducerModelPropertiesValue * Object;
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

//IREM_FormaElementaSprProducerModelPropertiesValue
   virtual IREM_DMSprProducerModelPropertiesValue * get_DM(void);
   virtual void set_DM(IREM_DMSprProducerModelPropertiesValue * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaElementaSprProducerModelPropertiesValueImpl __uuidof(TREM_FormaElementaSprProducerModelPropertiesValueImpl)
#endif
