#ifndef UFormaElementaSprSkladImplH
#define UFormaElementaSprSkladImplH
#include "IFormaElementaSprSklad.h"
#include "UFormaElementaSprSklad.h"
//---------------------------------------------------------------
class __declspec(uuid("{55B6738D-0D0B-41CF-9A0A-71E5F68F7039}")) TFormaElementaSprSkladImpl : public IFormaElementaSprSklad, IkanCallBack
{
public:
   TFormaElementaSprSkladImpl();
   ~TFormaElementaSprSkladImpl();
   TFormaElementaSprSklad * Object;
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

//IFormaElementaSprSklad
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMSprSklad * get_DM(void);
   virtual void set_DM(IDMSprSklad * DM);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaSprSkladImpl __uuidof(TFormaElementaSprSkladImpl)
#endif
