#ifndef UREM_FormaElementaSprModelInfBlockImplH
#define UREM_FormaElementaSprModelInfBlockImplH
#include "IREM_FormaElementaSprModelInfBlock.h"
#include "UREM_FormaElementaSprModelInfBlock.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaElementaSprModelInfBlockImpl)) TREM_FormaElementaSprModelInfBlockImpl : public IREM_FormaElementaSprModelInfBlock, IkanCallBack
{
public:
   TREM_FormaElementaSprModelInfBlockImpl();
   ~TREM_FormaElementaSprModelInfBlockImpl();
   TREM_FormaElementaSprModelInfBlock * Object;
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

//IREM_FormaElementaSprModelInfBlock
   virtual IREM_DMSprModelInfBlock * get_DM(void);
   virtual void set_DM(IREM_DMSprModelInfBlock * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaElementaSprModelInfBlockImpl __uuidof(TREM_FormaElementaSprModelInfBlockImpl)
#endif
