#ifndef UART_FormaSpiskaSprNaborInfBlockImplH
#define UART_FormaSpiskaSprNaborInfBlockImplH
#include "IART_FormaSpiskaSprNaborInfBlock.h"
#include "UART_FormaSpiskaSprNaborInfBlock.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TART_FormaSpiskaSprNaborInfBlockImpl)) TART_FormaSpiskaSprNaborInfBlockImpl : public IART_FormaSpiskaSprNaborInfBlock, IkanCallBack
{
public:
   TART_FormaSpiskaSprNaborInfBlockImpl();
   ~TART_FormaSpiskaSprNaborInfBlockImpl();
   TART_FormaSpiskaSprNaborInfBlock * Object;
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

//IART_FormaSpiskaSprNaborInfBlock
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IART_DMSprNaborInfBlock* get_DM(void);
   virtual void set_DM(IART_DMSprNaborInfBlock* DM);

   virtual IART_DMSprNaborInfBlockGrp * get_DMGrp(void);
   virtual void set_DMGrp(IART_DMSprNaborInfBlockGrp * DMGrp);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual UnicodeString get_TextMessage(void);
   virtual void set_TextMessage(UnicodeString TextMessage);

   virtual void UpdateForm(void);
};
#define CLSID_TART_FormaSpiskaSprNaborInfBlockImpl __uuidof(TART_FormaSpiskaSprNaborInfBlockImpl)
#endif
