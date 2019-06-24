#ifndef UREM_FormaElementaSprProducerModelInfBlockImplH
#define UREM_FormaElementaSprProducerModelInfBlockImplH
#include "IREM_FormaElementaSprProducerModelInfBlock.h"
#include "UREM_FormaElementaSprProducerModelInfBlock.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaElementaSprProducerModelInfBlockImpl)) TREM_FormaElementaSprProducerModelInfBlockImpl : public IREM_FormaElementaSprProducerModelInfBlock, IkanCallBack
{
public:
   TREM_FormaElementaSprProducerModelInfBlockImpl();
   ~TREM_FormaElementaSprProducerModelInfBlockImpl();
   TREM_FormaElementaSprProducerModelInfBlock * Object;
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

//IREM_FormaElementaSprProducerModelInfBlock
   virtual IREM_DMSprProducerModelInfBlock * get_DM(void);
   virtual void set_DM(IREM_DMSprProducerModelInfBlock * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaElementaSprProducerModelInfBlockImpl __uuidof(TREM_FormaElementaSprProducerModelInfBlockImpl)
#endif
