#ifndef UREM_FormaZayavkaImplH
#define UREM_FormaZayavkaImplH
#include "IREM_FormaZayavka.h"
#include "UREM_FormaZayavka.h"
#include "IAsyncExternalEvent.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaZayavkaImpl)) TREM_FormaZayavkaImpl :
			 public IREM_FormaZayavka, IkanCallBack,IAsyncExternalEvent
{
public:
   TREM_FormaZayavkaImpl();
   ~TREM_FormaZayavkaImpl();
   TREM_FormaZayavka * Object;
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

//IREM_FormaZayavka
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMZayavka * get_DM(void);
   virtual void set_DM(IREM_DMZayavka * DM);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdZ(void);
   virtual void set_IdZ(__int64 IdZ);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaZayavkaImpl __uuidof(TREM_FormaZayavkaImpl)
#endif
