#ifndef UFormaDocCheckTouchImplH
#define UFormaDocCheckTouchImplH
#include "IFormaDocCheckTouch.h"
#include "UFormaDocCheckTouch.h"
#include "IAsyncExternalEvent.h"
//---------------------------------------------------------------
class __declspec(uuid("{4F5BAC9A-69B1-4E3B-A6E7-3F895FD8FFC7}")) TFormaDocCheckTouchImpl :
					 public IFormaDocCheckTouch, IkanCallBack,IAsyncExternalEvent
{
public:
   TFormaDocCheckTouchImpl();
   ~TFormaDocCheckTouchImpl();
   TFormaDocCheckTouch * Object;
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

//IFormaDocCheckTouch
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMDocCheck * get_DM(void);
   virtual void set_DM(IDMDocCheck * DM);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual __int64 get_IdARM(void);
   virtual void set_IdARM(__int64 IdARM);

   virtual bool get_CheckSave(void);
   virtual void set_CheckSave(bool CheckSave);

   virtual bool get_CheckPrint(void);
   virtual void set_CheckPrint(bool CheckPrint);

   virtual bool get_CheckCreate(void);
   virtual void set_CheckCreate(bool CheckCreate);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaDocCheckTouchImpl __uuidof(TFormaDocCheckTouchImpl)
#endif
