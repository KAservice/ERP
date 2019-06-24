#ifndef UREM_FormaSpiskaSprTypeDeviceImplH
#define UREM_FormaSpiskaSprTypeDeviceImplH
#include "IREM_FormaSpiskaSprTypeDevice.h"
#include "UREM_FormaSpiskaSprTypeDevice.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaSpiskaSprTypeDeviceImpl)) TREM_FormaSpiskaSprTypeDeviceImpl : public IREM_FormaSpiskaSprTypeDevice, IkanCallBack
{
public:
   TREM_FormaSpiskaSprTypeDeviceImpl();
   ~TREM_FormaSpiskaSprTypeDeviceImpl();
   TREM_FormaSpiskaSprTypeDevice * Object;
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

//IREM_FormaSpiskaSprTypeDevice
   virtual IREM_DMSprTypeDevice * get_DM(void);
   virtual void set_DM(IREM_DMSprTypeDevice * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual UnicodeString get_TextHeader(void);
   virtual void set_TextHeader(UnicodeString TextHeader);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaSpiskaSprTypeDeviceImpl __uuidof(TREM_FormaSpiskaSprTypeDeviceImpl)
#endif
