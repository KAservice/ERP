#ifndef UREM_FormaSpiskaSprModelDetalImplH
#define UREM_FormaSpiskaSprModelDetalImplH
#include "IREM_FormaSpiskaSprModelDetal.h"
#include "UREM_FormaSpiskaSprModelDetal.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaSpiskaSprModelDetalImpl)) TREM_FormaSpiskaSprModelDetalImpl : public IREM_FormaSpiskaSprModelDetal, IkanCallBack
{
public:
   TREM_FormaSpiskaSprModelDetalImpl();
   ~TREM_FormaSpiskaSprModelDetalImpl();
   TREM_FormaSpiskaSprModelDetal * Object;
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

//IREM_FormaSpiskaSprModelDetal
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMSprModelDetal * get_DM(void);
   virtual void set_DM(IREM_DMSprModelDetal * DM);

   virtual __int64 get_IdModel(void);
   virtual void set_IdModel(__int64 IdModel);

   virtual UnicodeString get_TextMessage(void);
   virtual void set_TextMessage(UnicodeString TextMessage);

   virtual void UpdateForm();
};
#define CLSID_TREM_FormaSpiskaSprModelDetalImpl __uuidof(TREM_FormaSpiskaSprModelDetalImpl)
#endif
