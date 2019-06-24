#ifndef UART_FormaElementaSprInfBlockImplH
#define UART_FormaElementaSprInfBlockImplH
#include "IART_FormaElementaSprInfBlock.h"
#include "UART_FormaElementaSprInfBlock.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TART_FormaElementaSprInfBlockImpl)) TART_FormaElementaSprInfBlockImpl : public IART_FormaElementaSprInfBlock, IkanCallBack
{
public:
   TART_FormaElementaSprInfBlockImpl();
   ~TART_FormaElementaSprInfBlockImpl();
   TART_FormaElementaSprInfBlock * Object;
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

//IART_FormaElementaSprInfBlock
   virtual IART_DMSprInfBlock * get_DM(void);
   virtual void set_DM(IART_DMSprInfBlock * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdGrpPage(void);
   virtual void set_IdGrpPage(__int64 IdGrpPage);

   virtual UnicodeString get_NameGrp(void);
   virtual void set_NameGrp(UnicodeString NameGrp);

   virtual void UpdateForm(void);
};
#define CLSID_TART_FormaElementaSprInfBlockImpl __uuidof(TART_FormaElementaSprInfBlockImpl)
#endif
