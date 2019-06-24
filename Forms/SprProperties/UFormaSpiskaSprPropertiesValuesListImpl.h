#ifndef UFormaSpiskaSprPropertiesValuesListImplH
#define UFormaSpiskaSprPropertiesValuesListImplH
#include "IFormaSpiskaSprPropertiesValuesList.h"
#include "UFormaSpiskaSprPropertiesValuesList.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSpiskaSprPropertiesValuesListImpl)) TFormaSpiskaSprPropertiesValuesListImpl : public IFormaSpiskaSprPropertiesValuesList, IkanCallBack
{
public:
   TFormaSpiskaSprPropertiesValuesListImpl();
   ~TFormaSpiskaSprPropertiesValuesListImpl();
   TFormaSpiskaSprPropertiesValuesList * Object;
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

//IFormaSpiskaSprPropertiesValuesList
   virtual IDMSprPropertiesValuesList * get_DM(void);
   virtual void set_DM(IDMSprPropertiesValuesList * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdProp(void);
   virtual void set_IdProp(__int64 IdProp);

   virtual UnicodeString get_HeaderText(void);
   virtual void set_HeaderText(UnicodeString HeaderText);

   virtual void UpdateForm();
};
#define CLSID_TFormaSpiskaSprPropertiesValuesListImpl __uuidof(TFormaSpiskaSprPropertiesValuesListImpl)
#endif
