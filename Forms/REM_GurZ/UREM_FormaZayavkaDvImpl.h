#ifndef UREM_FormaZayavkaDvImplH
#define UREM_FormaZayavkaDvImplH
#include "IREM_FormaZayavkaDv.h"
#include "UREM_FormaZayavkaDv.h"
//---------------------------------------------------------------
class __declspec(uuid("{FC2DBF76-8616-4CD3-BA86-A9D22736AA2E}")) TREM_FormaZayavkaDvImpl : public IREM_FormaZayavkaDv, IkanCallBack
{
public:
   TREM_FormaZayavkaDvImpl();
   ~TREM_FormaZayavkaDvImpl();
   TREM_FormaZayavkaDv * Object;
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

//IREM_FormaZayavkaDv
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMZayavkaDv * get_DM(void);
   virtual void set_DM(IREM_DMZayavkaDv * DM);

   virtual __int64 get_IdZ(void);
   virtual void set_IdZ(__int64 IdZ);

   virtual UnicodeString get_TextMessage(void);
   virtual void set_TextMessage(UnicodeString TextMessage);

   virtual void UpdateForm();
};
#define CLSID_TREM_FormaZayavkaDvImpl __uuidof(TREM_FormaZayavkaDvImpl)
#endif
