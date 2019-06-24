#ifndef UHOT_FormaElementaSprSostNomImplH
#define UHOT_FormaElementaSprSostNomImplH
#include "IHOT_FormaElementaSprSostNom.h"
#include "UHOT_FormaElementaSprSostNom.h"
//---------------------------------------------------------------
class __declspec(uuid("{DB6F419B-ADDA-4D23-B60E-D6F617CEA2B2}")) THOT_FormaElementaSprSostNomImpl : public IHOT_FormaElementaSprSostNom, IkanCallBack
{
public:
   THOT_FormaElementaSprSostNomImpl();
   ~THOT_FormaElementaSprSostNomImpl();
   THOT_FormaElementaSprSostNom * Object;
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

//IHOT_FormaElementaSprSostNom
   virtual IHOT_DMSprSostNom * get_DM(void);
   virtual void set_DM(IHOT_DMSprSostNom * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_THOT_FormaElementaSprSostNomImpl __uuidof(THOT_FormaElementaSprSostNomImpl)
#endif
