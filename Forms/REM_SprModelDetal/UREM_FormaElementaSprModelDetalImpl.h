#ifndef UREM_FormaElementaSprModelDetalImplH
#define UREM_FormaElementaSprModelDetalImplH
#include "IREM_FormaElementaSprModelDetal.h"
#include "UREM_FormaElementaSprModelDetal.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaElementaSprModelDetalImpl)) TREM_FormaElementaSprModelDetalImpl : public IREM_FormaElementaSprModelDetal, IkanCallBack
{
public:
   TREM_FormaElementaSprModelDetalImpl();
   ~TREM_FormaElementaSprModelDetalImpl();
   TREM_FormaElementaSprModelDetal * Object;
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

//IREM_FormaElementaSprModelDetal
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMSprModelDetal * get_DM(void);
   virtual void set_DM(IREM_DMSprModelDetal * DM);

   virtual UnicodeString get_TextMessage(void);
   virtual void set_TextMessage(UnicodeString TextMessage);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaElementaSprModelDetalImpl __uuidof(TREM_FormaElementaSprModelDetalImpl)
#endif
