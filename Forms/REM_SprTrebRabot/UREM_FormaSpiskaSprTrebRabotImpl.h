#ifndef UREM_FormaSpiskaSprTrebRabotImplH
#define UREM_FormaSpiskaSprTrebRabotImplH
#include "IREM_FormaSpiskaSprTrebRabot.h"
#include "UREM_FormaSpiskaSprTrebRabot.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaSpiskaSprTrebRabotImpl)) TREM_FormaSpiskaSprTrebRabotImpl : public IREM_FormaSpiskaSprTrebRabot, IkanCallBack
{
public:
   TREM_FormaSpiskaSprTrebRabotImpl();
   ~TREM_FormaSpiskaSprTrebRabotImpl();
   TREM_FormaSpiskaSprTrebRabot * Object;
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

//IREM_FormaSpiskaSprTrebRabot
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMSprTrebRabot * get_DM(void);
   virtual void set_DM(IREM_DMSprTrebRabot * DM);

   virtual __int64 get_IdDefectModelNeispr(void);
   virtual void set_IdDefectModelNeispr(__int64 IdDefectModelNeispr);

   virtual UnicodeString get_TextMessage(void);
   virtual void set_TextMessage(UnicodeString TextMessage);

   virtual void UpdateForm();
};
#define CLSID_TREM_FormaSpiskaSprTrebRabotImpl __uuidof(TREM_FormaSpiskaSprTrebRabotImpl)
#endif
