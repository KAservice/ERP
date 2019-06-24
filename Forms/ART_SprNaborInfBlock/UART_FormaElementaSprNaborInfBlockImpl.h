#ifndef UART_FormaElementaSprNaborInfBlockImplH
#define UART_FormaElementaSprNaborInfBlockImplH
#include "IART_FormaElementaSprNaborInfBlock.h"
#include "UART_FormaElementaSprNaborInfBlock.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TART_FormaElementaSprNaborInfBlockImpl)) TART_FormaElementaSprNaborInfBlockImpl : public IART_FormaElementaSprNaborInfBlock, IkanCallBack
{
public:
   TART_FormaElementaSprNaborInfBlockImpl();
   ~TART_FormaElementaSprNaborInfBlockImpl();
   TART_FormaElementaSprNaborInfBlock * Object;
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

//IART_FormaElementaSprNaborInfBlock
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IART_DMSprNaborInfBlock * get_DM(void);
   virtual void set_DM(IART_DMSprNaborInfBlock * DM);

   virtual bool get_SaveElement(void);
   virtual void set_SaveElement(bool SaveElement);

   virtual void UpdateForm(void);
};
#define CLSID_TART_FormaElementaSprNaborInfBlockImpl __uuidof(TART_FormaElementaSprNaborInfBlockImpl)
#endif
