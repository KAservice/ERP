#ifndef UART_FormaElementaSprInfBlockGrpImplH
#define UART_FormaElementaSprInfBlockGrpImplH
#include "IART_FormaElementaSprInfBlockGrp.h"
#include "UART_FormaElementaSprInfBlockGrp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TART_FormaElementaSprInfBlockGrpImpl)) TART_FormaElementaSprInfBlockGrpImpl : public IART_FormaElementaSprInfBlockGrp, IkanCallBack
{
public:
   TART_FormaElementaSprInfBlockGrpImpl();
   ~TART_FormaElementaSprInfBlockGrpImpl();
   TART_FormaElementaSprInfBlockGrp * Object;
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

//IART_FormaElementaSprInfBlockGrp
   virtual IART_DMSprInfBlockGrp* get_DM(void);
   virtual void set_DM(IART_DMSprInfBlockGrp* DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

};
#define CLSID_TART_FormaElementaSprInfBlockGrpImpl __uuidof(TART_FormaElementaSprInfBlockGrpImpl)
#endif
