#ifndef UART_FormaElementaSprImageGrpImplH
#define UART_FormaElementaSprImageGrpImplH
#include "IART_FormaElementaSprImageGrp.h"
#include "UART_FormaElementaSprImageGrp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TART_FormaElementaSprImageGrpImpl)) TART_FormaElementaSprImageGrpImpl : public IART_FormaElementaSprImageGrp, IkanCallBack
{
public:
   TART_FormaElementaSprImageGrpImpl();
   ~TART_FormaElementaSprImageGrpImpl();
   TART_FormaElementaSprImageGrp * Object;
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

//IART_FormaElementaSprImageGrp
   virtual IART_DMSprImageGrp* get_DM(void);
   virtual void set_DM(IART_DMSprImageGrp* DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

};
#define CLSID_TART_FormaElementaSprImageGrpImpl __uuidof(TART_FormaElementaSprImageGrpImpl)
#endif
