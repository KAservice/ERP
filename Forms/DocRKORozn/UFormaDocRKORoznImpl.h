#ifndef UFormaDocRKORoznImplH
#define UFormaDocRKORoznImplH
#include "IFormaDocRKORozn.h"
#include "UFormaDocRKORozn.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaDocRKORoznImpl)) TFormaDocRKORoznImpl : public IFormaDocRKORozn, IkanCallBack
{
public:
   TFormaDocRKORoznImpl();
   ~TFormaDocRKORoznImpl();
   TFormaDocRKORozn * Object;
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

//IFormaDocRKORozn
   virtual IDMDocRKORozn * get_DM(void);
   virtual void set_DM(IDMDocRKORozn * DM);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaDocRKORoznImpl __uuidof(TFormaDocRKORoznImpl)
#endif
