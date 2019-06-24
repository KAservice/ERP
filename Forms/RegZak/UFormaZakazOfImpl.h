#ifndef UFormaZakazOfImplH
#define UFormaZakazOfImplH
#include "IFormaZakazOf.h"
#include "UFormaZakazOf.h"
#include "IAsyncExternalEvent.h"
//---------------------------------------------------------------
class __declspec(uuid("{F7AEA6F6-9988-44B6-BBBC-6A20B28AA926}")) TFormaZakazOfImpl :
 public IFormaZakazOf, IkanCallBack,IAsyncExternalEvent
{
public:
   TFormaZakazOfImpl();
   ~TFormaZakazOfImpl();
   TFormaZakazOf * Object;
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


//IFormaZakazOf
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMRegZak * get_DM(void);
   virtual void set_DM(IDMRegZak * DM);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual __int64 get_IdPod(void);
   virtual void set_IdPod(__int64 IdPod);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_ObjectSave(void);
   virtual void set_ObjectSave(bool ObjectSave);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual UnicodeString get_NameTypePrice(void);
   virtual void set_NameTypePrice(UnicodeString NameTypePrice);

   virtual UnicodeString get_NameObjectZakaza(void);
   virtual void set_NameObjectZakaza(UnicodeString NameObjectZakaza);

   virtual void ObnovitForm(void);
   virtual void UpdateForm(void);
   virtual void OpenZakaz(void);
};
#define CLSID_TFormaZakazOfImpl __uuidof(TFormaZakazOfImpl)
#endif
