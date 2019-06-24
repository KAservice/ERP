#ifndef UREM_FormaElementaSprGrpNeisprImplH
#define UREM_FormaElementaSprGrpNeisprImplH
#include "IREM_FormaElementaSprGrpNeispr.h"
#include "UREM_FormaElementaSprGrpNeispr.h"
//---------------------------------------------------------------
class __declspec(uuid("{2E8DF91E-F8E1-4CD8-B5C5-EA8F05FE556D}")) TREM_FormaElementaSprGrpNeisprImpl : public IREM_FormaElementaSprGrpNeispr, IkanCallBack
{
public:
   TREM_FormaElementaSprGrpNeisprImpl();
   ~TREM_FormaElementaSprGrpNeisprImpl();
   TREM_FormaElementaSprGrpNeispr * Object;
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

//IREM_FormaElementaSprGrpNeispr
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMSprGrpNeispr* get_DM(void);
   virtual void set_DM(IREM_DMSprGrpNeispr* DM);

};
#define CLSID_TREM_FormaElementaSprGrpNeisprImpl __uuidof(TREM_FormaElementaSprGrpNeisprImpl)
#endif
