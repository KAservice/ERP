#ifndef UREM_FormaElementaSprProducerConditionGrpImplH
#define UREM_FormaElementaSprProducerConditionGrpImplH
#include "IREM_FormaElementaSprProducerConditionGrp.h"
#include "UREM_FormaElementaSprProducerConditionGrp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaElementaSprProducerConditionGrpImpl)) TREM_FormaElementaSprProducerConditionGrpImpl : public IREM_FormaElementaSprProducerConditionGrp, IkanCallBack
{
public:
   TREM_FormaElementaSprProducerConditionGrpImpl();
   ~TREM_FormaElementaSprProducerConditionGrpImpl();
   TREM_FormaElementaSprProducerConditionGrp * Object;
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

//IREM_FormaElementaSprProducerConditionGrp
   virtual IREM_DMSprProducerConditionGrp* get_DM(void);
   virtual void set_DM(IREM_DMSprProducerConditionGrp* DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

};
#define CLSID_TREM_FormaElementaSprProducerConditionGrpImpl __uuidof(TREM_FormaElementaSprProducerConditionGrpImpl)
#endif
