#ifndef UREM_FormaSpiskaSprActCategoryImplH
#define UREM_FormaSpiskaSprActCategoryImplH
#include "IREM_FormaSpiskaSprActCategory.h"
#include "UREM_FormaSpiskaSprActCategory.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaSpiskaSprActCategoryImpl)) TREM_FormaSpiskaSprActCategoryImpl : public IREM_FormaSpiskaSprActCategory, IkanCallBack
{
public:
   TREM_FormaSpiskaSprActCategoryImpl();
   ~TREM_FormaSpiskaSprActCategoryImpl();
   TREM_FormaSpiskaSprActCategory * Object;
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

//IREM_FormaSpiskaSprActCategory
   virtual IREM_DMSprActCategory * get_DM(void);
   virtual void set_DM(IREM_DMSprActCategory * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

};
#define CLSID_TREM_FormaSpiskaSprActCategoryImpl __uuidof(TREM_FormaSpiskaSprActCategoryImpl)
#endif
