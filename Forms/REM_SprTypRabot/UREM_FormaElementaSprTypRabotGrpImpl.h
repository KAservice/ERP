#ifndef UREM_FormaElementaSprTypRabotGrpImplH
#define UREM_FormaElementaSprTypRabotGrpImplH
#include "IREM_FormaElementaSprTypRabotGrp.h"
#include "UREM_FormaElementaSprTypRabotGrp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaElementaSprTypRabotGrpImpl)) TREM_FormaElementaSprTypRabotGrpImpl : public IREM_FormaElementaSprTypRabotGrp, IkanCallBack
{
public:
   TREM_FormaElementaSprTypRabotGrpImpl();
   ~TREM_FormaElementaSprTypRabotGrpImpl();
   TREM_FormaElementaSprTypRabotGrp * Object;
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

//IREM_FormaElementaSprTypRabotGrp
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMSprGrpTypRabot* get_DM(void);
   virtual void set_DM(IREM_DMSprGrpTypRabot* DM);

};
#define CLSID_TREM_FormaElementaSprTypRabotGrpImpl __uuidof(TREM_FormaElementaSprTypRabotGrpImpl)
#endif
