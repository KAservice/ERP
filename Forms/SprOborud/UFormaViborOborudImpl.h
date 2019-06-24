#ifndef UFormaViborOborudImplH
#define UFormaViborOborudImplH
#include "IFormaViborOborud.h"
#include "UFormaViborOborud.h"
//---------------------------------------------------------------
class __declspec(uuid("{E481C721-71F0-42DD-B29A-BF22FE7252F6}")) TFormaViborOborudImpl : public IFormaViborOborud, IkanCallBack
{
public:
   TFormaViborOborudImpl();
   ~TFormaViborOborudImpl();
   TFormaViborOborud * Object;
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

//IFormaViborOborud
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMSprOborud * get_DM(void);
   virtual void set_DM(IDMSprOborud * DM);

   virtual __int64 get_IdArm(void);
   virtual void set_IdArm(__int64 IdArm);

   virtual AnsiString get_TypeOborud(void);
   virtual void set_TypeOborud(AnsiString TypeOborud);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaViborOborudImpl __uuidof(TFormaViborOborudImpl)
#endif
