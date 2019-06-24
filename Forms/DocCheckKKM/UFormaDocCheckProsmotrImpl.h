#ifndef UFormaDocCheckProsmotrImplH
#define UFormaDocCheckProsmotrImplH
#include "IFormaDocCheckProsmotr.h"
#include "UFormaDocCheckProsmotr.h"
//---------------------------------------------------------------
class __declspec(uuid("{D68981BF-873B-4A4D-AB45-9D3A2181ACF2}")) TFormaDocCheckProsmotrImpl : public IFormaDocCheckProsmotr, IkanCallBack
{
public:
   TFormaDocCheckProsmotrImpl();
   ~TFormaDocCheckProsmotrImpl();
   TFormaDocCheckProsmotr * Object;
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

//IFormaDocCheckProsmotr
   virtual IDMDocCheck * get_DM(void);
   virtual void set_DM(IDMDocCheck * DM);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaDocCheckProsmotrImpl __uuidof(TFormaDocCheckProsmotrImpl)
#endif
