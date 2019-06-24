#ifndef UFormaElementaSprProjectImplH
#define UFormaElementaSprProjectImplH
#include "IFormaElementaSprProject.h"
#include "UFormaElementaSprProject.h"
//---------------------------------------------------------------
class __declspec(uuid("{02436C33-C1B0-42AC-874A-C68D3CEA45A8}"))TFormaElementaSprProjectImpl : public IFormaElementaSprProject, IkanCallBack
{
public:
   TFormaElementaSprProjectImpl();
   ~TFormaElementaSprProjectImpl();
   TFormaElementaSprProject * Object;
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

//IFormaElementaSprProject
   virtual IDMSprProject* get_DM(void);
   virtual void set_DM(IDMSprProject* DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaSprProjectImpl __uuidof(TFormaElementaSprProjectImpl)
#endif
