#ifndef UREM_FormaElementaSprModelPropertiesValueImplH
#define UREM_FormaElementaSprModelPropertiesValueImplH
#include "IREM_FormaElementaSprModelPropertiesValue.h"
#include "UREM_FormaElementaSprModelPropertiesValue.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaElementaSprModelPropertiesValueImpl)) TREM_FormaElementaSprModelPropertiesValueImpl : public IREM_FormaElementaSprModelPropertiesValue, IkanCallBack
{
public:
   TREM_FormaElementaSprModelPropertiesValueImpl();
   ~TREM_FormaElementaSprModelPropertiesValueImpl();
   TREM_FormaElementaSprModelPropertiesValue * Object;
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

//IREM_FormaElementaSprModelPropertiesValue
   virtual IREM_DMSprModelPropertiesValue * get_DM(void);
   virtual void set_DM(IREM_DMSprModelPropertiesValue * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaElementaSprModelPropertiesValueImpl __uuidof(TREM_FormaElementaSprModelPropertiesValueImpl)
#endif
