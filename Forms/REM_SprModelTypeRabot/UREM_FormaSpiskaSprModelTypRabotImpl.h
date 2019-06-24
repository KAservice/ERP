#ifndef UREM_FormaSpiskaSprModelTypRabotImplH
#define UREM_FormaSpiskaSprModelTypRabotImplH
#include "IREM_FormaSpiskaSprModelTypRabot.h"
#include "UREM_FormaSpiskaSprModelTypRabot.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaSpiskaSprModelTypRabotImpl)) TREM_FormaSpiskaSprModelTypRabotImpl : public IREM_FormaSpiskaSprModelTypRabot, IkanCallBack
{
public:
   TREM_FormaSpiskaSprModelTypRabotImpl();
   ~TREM_FormaSpiskaSprModelTypRabotImpl();
   TREM_FormaSpiskaSprModelTypRabot * Object;
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

//IREM_FormaSpiskaSprModelTypRabot
   virtual IREM_DMSprModelTypRabot * get_DM(void);
   virtual void set_DM(IREM_DMSprModelTypRabot * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdOwner(void);
   virtual void set_IdOwner(__int64 IdOwner);

   virtual UnicodeString get_HeaderText(void);
   virtual void set_HeaderText(UnicodeString HeaderText);

   virtual void UpdateForm();
};
#define CLSID_TREM_FormaSpiskaSprModelTypRabotImpl __uuidof(TREM_FormaSpiskaSprModelTypRabotImpl)
#endif
