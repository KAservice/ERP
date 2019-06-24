#ifndef UREM_FormaDocKM1ImplH
#define UREM_FormaDocKM1ImplH
#include "IREM_FormaDocKM1.h"
#include "UREM_FormaDocKM1.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaDocKM1Impl)) TREM_FormaDocKM1Impl : public IREM_FormaDocKM1, IkanCallBack
{
public:
   TREM_FormaDocKM1Impl();
   ~TREM_FormaDocKM1Impl();
   TREM_FormaDocKM1 * Object;
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

//IREM_FormaDocKM1
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMDocKM1 * get_DM(void);
   virtual void set_DM(IREM_DMDocKM1 * DM);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual __int64 get_VibTovarId(void);
   virtual void set_VibTovarId(__int64 VibTovarId);

   virtual __int64 get_VibTovarIdGrp(void);
   virtual void set_VibTovarIdGrp(__int64 VibTovarIdGrp);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaDocKM1Impl __uuidof(TREM_FormaDocKM1Impl)
#endif
