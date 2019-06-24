#ifndef UREM_FormaSpiskaSprProducerModelInfBlockImplH
#define UREM_FormaSpiskaSprProducerModelInfBlockImplH
#include "IREM_FormaSpiskaSprProducerModelInfBlock.h"
#include "UREM_FormaSpiskaSprProducerModelInfBlock.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaSpiskaSprProducerModelInfBlockImpl)) TREM_FormaSpiskaSprProducerModelInfBlockImpl : public IREM_FormaSpiskaSprProducerModelInfBlock, IkanCallBack
{
public:
   TREM_FormaSpiskaSprProducerModelInfBlockImpl();
   ~TREM_FormaSpiskaSprProducerModelInfBlockImpl();
   TREM_FormaSpiskaSprProducerModelInfBlock * Object;
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

//IREM_FormaSpiskaSprProducerModelInfBlock
   virtual IREM_DMSprProducerModelInfBlock * get_DM(void);
   virtual void set_DM(IREM_DMSprProducerModelInfBlock * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdOwner(void);
   virtual void set_IdOwner(__int64 IdOwner);

   virtual UnicodeString get_HeaderText(void);
   virtual void set_HeaderText(UnicodeString HeaderText);

   virtual void UpdateForm();
};
#define CLSID_TREM_FormaSpiskaSprProducerModelInfBlockImpl __uuidof(TREM_FormaSpiskaSprProducerModelInfBlockImpl)
#endif
