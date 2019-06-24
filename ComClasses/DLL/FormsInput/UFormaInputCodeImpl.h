#ifndef UFormaInputCodeImplH
#define UFormaInputCodeImplH
#include "IFormaInputCode.h"
#include "UFormaInputCode.h"
//---------------------------------------------------------------
class __declspec(uuid("{FE7C3B5E-211E-40A1-AFCB-4DFCFA74C687}")) TFormaInputCodeImpl : public IFormaInputCode
{
public:
   TFormaInputCodeImpl();
   ~TFormaInputCodeImpl();
   TFormaInputCode * Object;
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

//IFormaInputCode
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual int get_Code(void);
   virtual void set_Code(int Code);

   virtual float get_Kol(void);
   virtual void set_Kol(float Kol);

};
#define CLSID_TFormaInputCodeImpl __uuidof(TFormaInputCodeImpl)
#endif
