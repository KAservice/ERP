#ifndef UREM_FormaSpiskaSprHardwareImplH
#define UREM_FormaSpiskaSprHardwareImplH
#include "IREM_FormaSpiskaSprHardware.h"
#include "UREM_FormaSpiskaSprHardware.h"
#include "IAsyncExternalEvent.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaSpiskaSprHardwareImpl)) TREM_FormaSpiskaSprHardwareImpl :
					 public IREM_FormaSpiskaSprHardware, IkanCallBack,IAsyncExternalEvent
{
public:
   TREM_FormaSpiskaSprHardwareImpl();
   ~TREM_FormaSpiskaSprHardwareImpl();
   TREM_FormaSpiskaSprHardware * Object;
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

   //IAcyncExternalEvent
   virtual int AsyncExternalEvent(char * object, char* event, char* data);
   virtual int SetInterfaceForAsyncExternalEvent(IkanUnknown * i_act_form);

//IREM_FormaSpiskaSprHardware
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual UnicodeString get_TextMessage(void);
   virtual void set_TextMessage(UnicodeString TextMessage);

   virtual IREM_DMSprHardware* get_DM(void);
   virtual void set_DM(IREM_DMSprHardware* DM);

   virtual IREM_DMSprGrpHardware * get_DMGrp(void);
   virtual void set_DMGrp(IREM_DMSprGrpHardware * DMGrp);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdHardware(void);
   virtual void set_IdHardware(__int64 IdHardware);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual bool get_Podbor(void);
   virtual void set_Podbor(bool Podbor);

   virtual void UpdateForm(void);

   virtual UnicodeString get_SerNumber1(void);
   virtual void set_SerNumber1(UnicodeString SerNumber1);

   virtual UnicodeString get_SerNumber2(void);
   virtual void set_SerNumber2(UnicodeString SerNumber2);

};
#define CLSID_TREM_FormaSpiskaSprHardwareImpl __uuidof(TREM_FormaSpiskaSprHardwareImpl)
#endif
