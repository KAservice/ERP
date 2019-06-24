#ifndef UART_FormaSpiskaSprNaborInfBlockSostavImplH
#define UART_FormaSpiskaSprNaborInfBlockSostavImplH
#include "IART_FormaSpiskaSprNaborInfBlockSostav.h"
#include "UART_FormaSpiskaSprNaborInfBlockSostav.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TART_FormaSpiskaSprNaborInfBlockSostavImpl)) TART_FormaSpiskaSprNaborInfBlockSostavImpl : public IART_FormaSpiskaSprNaborInfBlockSostav, IkanCallBack
{
public:
   TART_FormaSpiskaSprNaborInfBlockSostavImpl();
   ~TART_FormaSpiskaSprNaborInfBlockSostavImpl();
   TART_FormaSpiskaSprNaborInfBlockSostav * Object;
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

//IART_FormaSpiskaSprNaborInfBlockSostav
   virtual IART_DMSprNaborInfBlockSostav* get_DM(void);
   virtual void set_DM(IART_DMSprNaborInfBlockSostav* DM);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual bool get_Podbor(void);
   virtual void set_Podbor(bool Podbor);

   virtual __int64 get_IdGroupElement(void);
   virtual void set_IdGroupElement(__int64 IdGroupElement);

   virtual UnicodeString get_NameGroupElement(void);
   virtual void set_NameGroupElement(UnicodeString NameGroupElement);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual __int64 get_ViborIdOsnElement(void);
   virtual void set_ViborIdOsnElement(__int64 ViborIdOsnElement);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual void DeleteElement();
   virtual void UpdateForm(void);
};
#define CLSID_TART_FormaSpiskaSprNaborInfBlockSostavImpl __uuidof(TART_FormaSpiskaSprNaborInfBlockSostavImpl)
#endif
