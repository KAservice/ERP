#ifndef UREM_FormaElementaSprNeisprImplH
#define UREM_FormaElementaSprNeisprImplH
#include "IREM_FormaElementaSprNeispr.h"
#include "UREM_FormaElementaSprNeispr.h"
//---------------------------------------------------------------
class __declspec(uuid("{DDAF114F-8E10-480A-8E13-647990714D9E}")) TREM_FormaElementaSprNeisprImpl : public IREM_FormaElementaSprNeispr, IkanCallBack
{
public:
   TREM_FormaElementaSprNeisprImpl();
   ~TREM_FormaElementaSprNeisprImpl();
   TREM_FormaElementaSprNeispr * Object;
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

//IREM_FormaElementaSprNeispr
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual UnicodeString get_TextMessage(void);
   virtual void set_TextMessage(UnicodeString TextMessage);

   virtual IREM_DMSprNeispr * get_DM(void);
   virtual void set_DM(IREM_DMSprNeispr * DM);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaElementaSprNeisprImpl __uuidof(TREM_FormaElementaSprNeisprImpl)
#endif
