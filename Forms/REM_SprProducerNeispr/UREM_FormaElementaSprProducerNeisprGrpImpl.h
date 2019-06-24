#ifndef UREM_FormaElementaSprProducerNeisprGrpImplH
#define UREM_FormaElementaSprProducerNeisprGrpImplH
#include "IREM_FormaElementaSprProducerNeisprGrp.h"
#include "UREM_FormaElementaSprProducerNeisprGrp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaElementaSprProducerNeisprGrpImpl)) TREM_FormaElementaSprProducerNeisprGrpImpl : public IREM_FormaElementaSprProducerNeisprGrp, IkanCallBack
{
public:
   TREM_FormaElementaSprProducerNeisprGrpImpl();
   ~TREM_FormaElementaSprProducerNeisprGrpImpl();
   TREM_FormaElementaSprProducerNeisprGrp * Object;
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

//IREM_FormaElementaSprProducerNeisprGrp
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMSprProducerNeisprGrp* get_DM(void);
   virtual void set_DM(IREM_DMSprProducerNeisprGrp* DM);

};
#define CLSID_TREM_FormaElementaSprProducerNeisprGrpImpl __uuidof(TREM_FormaElementaSprProducerNeisprGrpImpl)
#endif
