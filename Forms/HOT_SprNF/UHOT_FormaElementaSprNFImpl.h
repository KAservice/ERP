#ifndef UHOT_FormaElementaSprNFImplH
#define UHOT_FormaElementaSprNFImplH
#include "IHOT_FormaElementaSprNF.h"
#include "UHOT_FormaElementaSprNF.h"
//---------------------------------------------------------------
class __declspec(uuid("{25EAE761-0E3D-4264-9A81-082C814C00E1}")) THOT_FormaElementaSprNFImpl : public IHOT_FormaElementaSprNF, IkanCallBack
{
public:
   THOT_FormaElementaSprNFImpl();
   ~THOT_FormaElementaSprNFImpl();
   THOT_FormaElementaSprNF * Object;
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

//IHOT_FormaElementaSprNF
   virtual IHOT_DMSprNF * get_DM(void);
   virtual void set_DM(IHOT_DMSprNF * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_THOT_FormaElementaSprNFImpl __uuidof(THOT_FormaElementaSprNFImpl)
#endif
