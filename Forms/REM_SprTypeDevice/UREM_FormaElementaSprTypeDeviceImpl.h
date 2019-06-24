#ifndef UREM_FormaElementaSprTypeDeviceImplH
#define UREM_FormaElementaSprTypeDeviceImplH
#include "IREM_FormaElementaSprTypeDevice.h"
#include "UREM_FormaElementaSprTypeDevice.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaElementaSprTypeDeviceImpl)) TREM_FormaElementaSprTypeDeviceImpl : public IREM_FormaElementaSprTypeDevice, IkanCallBack
{
public:
   TREM_FormaElementaSprTypeDeviceImpl();
   ~TREM_FormaElementaSprTypeDeviceImpl();
   TREM_FormaElementaSprTypeDevice * Object;
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

//IREM_FormaElementaSprTypeDevice
   virtual IREM_DMSprTypeDevice * get_DM(void);
   virtual void set_DM(IREM_DMSprTypeDevice * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaElementaSprTypeDeviceImpl __uuidof(TREM_FormaElementaSprTypeDeviceImpl)
#endif
