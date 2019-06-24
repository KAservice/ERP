#ifndef UFormaElementaSprImportEdImplH
#define UFormaElementaSprImportEdImplH
#include "IFormaElementaSprImportEd.h"
#include "UFormaElementaSprImportEd.h"
//---------------------------------------------------------------
class __declspec(uuid("{20CE2C36-F4EC-4059-8032-8CC1CDA8B219}")) TFormaElementaSprImportEdImpl : public IFormaElementaSprImportEd, IkanCallBack
{
public:
   TFormaElementaSprImportEdImpl();
   ~TFormaElementaSprImportEdImpl();
   TFormaElementaSprImportEd * Object;
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

//IFormaElementaSprImportEd
   virtual IDMSprImportEd * get_DM(void);
   virtual void set_DM(IDMSprImportEd * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaSprImportEdImpl __uuidof(TFormaElementaSprImportEdImpl)
#endif
