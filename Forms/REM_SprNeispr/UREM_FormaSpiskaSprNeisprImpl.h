#ifndef UREM_FormaSpiskaSprNeisprImplH
#define UREM_FormaSpiskaSprNeisprImplH
#include "IREM_FormaSpiskaSprNeispr.h"
#include "UREM_FormaSpiskaSprNeispr.h"

//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaSpiskaSprNeisprImpl)) TREM_FormaSpiskaSprNeisprImpl : public IREM_FormaSpiskaSprNeispr, IkanCallBack
{
public:
   TREM_FormaSpiskaSprNeisprImpl();
   ~TREM_FormaSpiskaSprNeisprImpl();
   TREM_FormaSpiskaSprNeispr * Object;
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

//IREM_FormaSpiskaSprNeispr
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual UnicodeString get_TextMessage(void);
   virtual void set_TextMessage(UnicodeString TextMessage);

   virtual IREM_DMSprNeispr* get_DM(void);
   virtual void set_DM(IREM_DMSprNeispr* DM);

   virtual IREM_DMSprGrpNeispr * get_DMGrp(void);
   virtual void set_DMGrp(IREM_DMSprGrpNeispr * DMGrp);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdNeispr(void);
   virtual void set_IdNeispr(__int64 IdNeispr);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual bool get_Podbor(void);
   virtual void set_Podbor(bool Podbor);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaSpiskaSprNeisprImpl __uuidof(TREM_FormaSpiskaSprNeisprImpl)
#endif
