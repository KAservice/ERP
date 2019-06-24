#ifndef UFormaElementaSprOborudImplH
#define UFormaElementaSprOborudImplH
#include "IFormaElementaSprOborud.h"
#include "UFormaElementaSprOborud.h"
//---------------------------------------------------------------
class __declspec(uuid("{48A80CC1-46D2-4587-95DC-8D04DBFA4F3A}"))TFormaElementaSprOborudImpl : public IFormaElementaSprOborud, IkanCallBack
{
public:
   TFormaElementaSprOborudImpl();
   ~TFormaElementaSprOborudImpl();
   TFormaElementaSprOborud * Object;
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

//IFormaElementaSprOborud
   virtual IDMSprOborud * get_DM(void);
   virtual void set_DM(IDMSprOborud * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);


   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaSprOborudImpl __uuidof(TFormaElementaSprOborudImpl)
#endif
