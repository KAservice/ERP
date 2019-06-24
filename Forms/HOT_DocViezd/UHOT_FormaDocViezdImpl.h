#ifndef UHOT_FormaDocViezdImplH
#define UHOT_FormaDocViezdImplH
#include "IHOT_FormaDocViezd.h"
#include "UHOT_FormaDocViezd.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_THOT_FormaDocViesdImpl)) THOT_FormaDocViezdImpl : public IHOT_FormaDocViezd, IkanCallBack
{
public:
   THOT_FormaDocViezdImpl();
   ~THOT_FormaDocViezdImpl();
   THOT_FormaDocViezd * Object;
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

//IHOT_FormaDocViezd
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IHOT_DMDocViezd * get_DM(void);
   virtual void set_DM(IHOT_DMDocViezd * DM);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual void UpdateForm(void);
};
#define CLSID_THOT_FormaDocViezdImpl __uuidof(THOT_FormaDocViezdImpl)
#endif
