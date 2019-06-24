#ifndef UART_FormaElementaSprNaborInfBlockSostavGrpImplH
#define UART_FormaElementaSprNaborInfBlockSostavGrpImplH
#include "IART_FormaElementaSprNaborInfBlockSostavGrp.h"
#include "UART_FormaElementaSprNaborInfBlockSostavGrp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TART_FormaElementaSprNaborInfBlockSostavGrpImpl)) TART_FormaElementaSprNaborInfBlockSostavGrpImpl : public IART_FormaElementaSprNaborInfBlockSostavGrp, IkanCallBack
{
public:
   TART_FormaElementaSprNaborInfBlockSostavGrpImpl();
   ~TART_FormaElementaSprNaborInfBlockSostavGrpImpl();
   TART_FormaElementaSprNaborInfBlockSostavGrp * Object;
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

//IART_FormaElementaSprNaborInfBlockSostavGrp
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IART_DMSprNaborInfBlockSostavGrp* get_DM(void);
   virtual void set_DM(IART_DMSprNaborInfBlockSostavGrp* DM);

};
#define CLSID_TART_FormaElementaSprNaborInfBlockSostavGrpImpl __uuidof(TART_FormaElementaSprNaborInfBlockSostavGrpImpl)
#endif
