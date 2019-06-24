#ifndef UART_FormaSpiskaSprImageImplH
#define UART_FormaSpiskaSprImageImplH
#include "IART_FormaSpiskaSprImage.h"
#include "UART_FormaSpiskaSprImage.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TART_FormaSpiskaSprImageImpl)) TART_FormaSpiskaSprImageImpl : public IART_FormaSpiskaSprImage, IkanCallBack
{
public:
   TART_FormaSpiskaSprImageImpl();
   ~TART_FormaSpiskaSprImageImpl();
   TART_FormaSpiskaSprImage * Object;
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

//IART_FormaSpiskaSprImage
   virtual IART_DMSprImage* get_DM(void);
   virtual void set_DM(IART_DMSprImage* DM);

   virtual IART_DMSprImageGrp * get_DMGrp(void);
   virtual void set_DMGrp(IART_DMSprImageGrp * DMGrp);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdGrpElement(void);
   virtual void set_IdGrpElement(__int64 IdGrpElement);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual void UpdateForm(void);
};
#define CLSID_TART_FormaSpiskaSprImageImpl __uuidof(TART_FormaSpiskaSprImageImpl)
#endif
