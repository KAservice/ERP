#ifndef UFormaViborSprEdImplH
#define UFormaViborSprEdImplH
#include "IFormaViborSprEd.h"
#include "UFormaViborSprEd.h"
//---------------------------------------------------------------
class __declspec(uuid("{529BCE43-0404-481D-897B-BEB5B33F4442}")) TFormaViborSprEdImpl : public IFormaViborSprEd
{
public:
   TFormaViborSprEdImpl();
   ~TFormaViborSprEdImpl();
   TFormaViborSprEd * Object;
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


//IFormaViborSprEd
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMSprEd * get_DM(void);
   virtual void set_DM(IDMSprEd * DM);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual void UpdateForm();
};
#define CLSID_TFormaViborSprEdImpl __uuidof(TFormaViborSprEdImpl)
#endif
