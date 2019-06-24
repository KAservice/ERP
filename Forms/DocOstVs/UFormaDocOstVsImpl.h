#ifndef UFormaDocOstVsImplH
#define UFormaDocOstVsImplH
#include "IFormaDocOstVs.h"
#include "UFormaDocOstVs.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaDocOstVsImpl)) TFormaDocOstVsImpl : public IFormaDocOstVs, IkanCallBack
{
public:
   TFormaDocOstVsImpl();
   ~TFormaDocOstVsImpl();
   TFormaDocOstVs * Object;
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

//IFormaDocOstVs
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMDocOstVs * get_DM(void);
   virtual void set_DM(IDMDocOstVs * DM);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaDocOstVsImpl __uuidof(TFormaDocOstVsImpl)
#endif
