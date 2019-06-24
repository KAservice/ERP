#ifndef UREM_FormaElementaSprTrebRabotImplH
#define UREM_FormaElementaSprTrebRabotImplH
#include "IREM_FormaElementaSprTrebRabot.h"
#include "UREM_FormaElementaSprTrebRabot.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaElementaSprTrebRabotImpl)) TREM_FormaElementaSprTrebRabotImpl : public IREM_FormaElementaSprTrebRabot, IkanCallBack
{
public:
   TREM_FormaElementaSprTrebRabotImpl();
   ~TREM_FormaElementaSprTrebRabotImpl();
   TREM_FormaElementaSprTrebRabot * Object;
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

//IREM_FormaElementaSprTrebRabot
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMSprTrebRabot * get_DM(void);
   virtual void set_DM(IREM_DMSprTrebRabot * DM);

   virtual UnicodeString get_TextMessage(void);
   virtual void set_TextMessage(UnicodeString TextMessage);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaElementaSprTrebRabotImpl __uuidof(TREM_FormaElementaSprTrebRabotImpl)
#endif
