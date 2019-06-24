#ifndef UHOT_FormaSpiskaSprNFImplH
#define UHOT_FormaSpiskaSprNFImplH
#include "IHOT_FormaSpiskaSprNF.h"
#include "UHOT_FormaSpiskaSprNF.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_THOT_FormaSpiskaSprNFImpl)) THOT_FormaSpiskaSprNFImpl : public IHOT_FormaSpiskaSprNF, IkanCallBack
{
public:
   THOT_FormaSpiskaSprNFImpl();
   ~THOT_FormaSpiskaSprNFImpl();
   THOT_FormaSpiskaSprNF * Object;
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

//IHOT_FormaSpiskaSprNF
   virtual IHOT_DMSprNF * get_DM(void);
   virtual void set_DM(IHOT_DMSprNF * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

};
#define CLSID_THOT_FormaSpiskaSprNFImpl __uuidof(THOT_FormaSpiskaSprNFImpl)
#endif
