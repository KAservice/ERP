#ifndef UREM_FormaElementaSprTypUslovImplH
#define UREM_FormaElementaSprTypUslovImplH
#include "IREM_FormaElementaSprTypUslov.h"
#include "UREM_FormaElementaSprTypUslov.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaElementaSprTypUslovImpl)) TREM_FormaElementaSprTypUslovImpl : public IREM_FormaElementaSprTypUslov, IkanCallBack
{
public:
   TREM_FormaElementaSprTypUslovImpl();
   ~TREM_FormaElementaSprTypUslovImpl();
   TREM_FormaElementaSprTypUslov * Object;
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

//IREM_FormaElementaSprTypUslov
   virtual IREM_DMSprTypUslov* get_DM(void);
   virtual void set_DM(IREM_DMSprTypUslov* DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual UnicodeString get_NameGroup(void);
   virtual void set_NameGroup(UnicodeString NameGroup);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaElementaSprTypUslovImpl __uuidof(TREM_FormaElementaSprTypUslovImpl)
#endif
