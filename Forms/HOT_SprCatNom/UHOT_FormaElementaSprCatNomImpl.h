#ifndef UHOT_FormaElementaSprCatNomImplH
#define UHOT_FormaElementaSprCatNomImplH
#include "IHOT_FormaElementaSprCatNom.h"
#include "UHOT_FormaElementaSprCatNom.h"
//---------------------------------------------------------------
class __declspec(uuid("{7842EB0B-0D09-48ED-B79D-FB014C140BEC}")) THOT_FormaElementaSprCatNomImpl : public IHOT_FormaElementaSprCatNom
{
public:
   THOT_FormaElementaSprCatNomImpl();
   ~THOT_FormaElementaSprCatNomImpl();
   THOT_FormaElementaSprCatNom * Object;
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

//IHOT_FormaElementaSprCatNom
   virtual IHOT_DMSprCatNom * get_DM(void);
   virtual void set_DM(IHOT_DMSprCatNom * DM);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_THOT_FormaElementaSprCatNomImpl __uuidof(THOT_FormaElementaSprCatNomImpl)
#endif
