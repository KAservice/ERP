#ifndef UREM_FormaSpiskaSprProducerModelPropertiesValueImplH
#define UREM_FormaSpiskaSprProducerModelPropertiesValueImplH
#include "IREM_FormaSpiskaSprProducerModelPropertiesValue.h"
#include "UREM_FormaSpiskaSprProducerModelPropertiesValue.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaSpiskaSprProducerModelPropertiesValueImpl)) TREM_FormaSpiskaSprProducerModelPropertiesValueImpl : public IREM_FormaSpiskaSprProducerModelPropertiesValue, IkanCallBack
{
public:
   TREM_FormaSpiskaSprProducerModelPropertiesValueImpl();
   ~TREM_FormaSpiskaSprProducerModelPropertiesValueImpl();
   TREM_FormaSpiskaSprProducerModelPropertiesValue * Object;
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

//IREM_FormaSpiskaSprProducerModelPropertiesValue
   virtual IREM_DMSprProducerModelPropertiesValue * get_DM(void);
   virtual void set_DM(IREM_DMSprProducerModelPropertiesValue * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdOwner(void);
   virtual void set_IdOwner(__int64 IdOwner);

   virtual UnicodeString get_HeaderText(void);
   virtual void set_HeaderText(UnicodeString HeaderText);

   virtual void UpdateForm();
};
#define CLSID_TREM_FormaSpiskaSprProducerModelPropertiesValueImpl __uuidof(TREM_FormaSpiskaSprProducerModelPropertiesValueImpl)
#endif
