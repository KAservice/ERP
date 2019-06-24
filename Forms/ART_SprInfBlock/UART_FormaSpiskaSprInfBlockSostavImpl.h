#ifndef UART_FormaSpiskaSprInfBlockSostavImplH
#define UART_FormaSpiskaSprInfBlockSostavImplH
#include "IART_FormaSpiskaSprInfBlockSostav.h"
#include "UART_FormaSpiskaSprInfBlockSostav.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TART_FormaSpiskaSprInfBlockSostavImpl)) TART_FormaSpiskaSprInfBlockSostavImpl : public IART_FormaSpiskaSprInfBlockSostav, IkanCallBack
{
public:
   TART_FormaSpiskaSprInfBlockSostavImpl();
   ~TART_FormaSpiskaSprInfBlockSostavImpl();
   TART_FormaSpiskaSprInfBlockSostav * Object;
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

//IART_FormaSpiskaSprInfBlockSostav
   virtual IART_DMSprInfBlockSostav * get_DM(void);
   virtual void set_DM(IART_DMSprInfBlockSostav * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdPage(void);
   virtual void set_IdPage(__int64 IdPage);

   virtual UnicodeString get_HeaderText(void);
   virtual void set_HeaderText(UnicodeString HeaderText);

   virtual void UpdateForm();
};
#define CLSID_TART_FormaSpiskaSprInfBlockSostavImpl __uuidof(TART_FormaSpiskaSprInfBlockSostavImpl)
#endif
