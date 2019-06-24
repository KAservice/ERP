#ifndef UREM_FormaElementaSprTypeRemontImplH
#define UREM_FormaElementaSprTypeRemontImplH
#include "IREM_FormaElementaSprTypeRemont.h"
#include "UREM_FormaElementaSprTypeRemont.h"
//---------------------------------------------------------------
class __declspec(uuid("{2F51B358-3B11-449C-988F-D51B69DF245E}"))TREM_FormaElementaSprTypeRemontImpl : public IREM_FormaElementaSprTypeRemont, IkanCallBack
{
public:
   TREM_FormaElementaSprTypeRemontImpl();
   ~TREM_FormaElementaSprTypeRemontImpl();
   TREM_FormaElementaSprTypeRemont * Object;
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

//IREM_FormaElementaSprTypeRemont
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMSprTypeRemont * get_DM(void);
   virtual void set_DM(IREM_DMSprTypeRemont * DM);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaElementaSprTypeRemontImpl __uuidof(TREM_FormaElementaSprTypeRemontImpl)
#endif
