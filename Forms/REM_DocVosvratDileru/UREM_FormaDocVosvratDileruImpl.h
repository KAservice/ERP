#ifndef UREM_FormaDocVosvratDileruImplH
#define UREM_FormaDocVosvratDileruImplH
#include "IREM_FormaDocVosvratDileru.h"
#include "UREM_FormaDocVosvratDileru.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaDocVosvratDileruImpl)) TREM_FormaDocVosvratDileruImpl : public IREM_FormaDocVosvratDileru, IkanCallBack
{
public:
   TREM_FormaDocVosvratDileruImpl();
   ~TREM_FormaDocVosvratDileruImpl();
   TREM_FormaDocVosvratDileru * Object;
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

//IREM_FormaDocVosvratDileru
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMDocVosvratDileru * get_DM(void);
   virtual void set_DM(IREM_DMDocVosvratDileru * DM);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaDocVosvratDileruImpl __uuidof(TREM_FormaDocVosvratDileruImpl)
#endif
