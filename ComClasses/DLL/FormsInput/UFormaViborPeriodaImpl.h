#ifndef UFormaViborPeriodaImplH
#define UFormaViborPeriodaImplH
#include "IFormaViborPerioda.h"
#include "UFormaViborPerioda.h"
//---------------------------------------------------------------
class __declspec(uuid("{05AC521E-4347-429F-A62E-0F509A682184}")) TFormaViborPeriodaImpl : public IFormaViborPerioda
{
public:
   TFormaViborPeriodaImpl();
   ~TFormaViborPeriodaImpl();
   TFormaViborPerioda * Object;
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

//IFormaViborPerioda
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual TDateTime get_PosNach(void);
   virtual void set_PosNach(TDateTime PosNach);

   virtual TDateTime get_PosCon(void);
   virtual void set_PosCon(TDateTime PosCon);

};
#define CLSID_TFormaViborPeriodaImpl __uuidof(TFormaViborPeriodaImpl)
#endif
