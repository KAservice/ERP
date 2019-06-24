#ifndef UREM_FormaDocVosvratHWImplH
#define UREM_FormaDocVosvratHWImplH
#include "IREM_FormaDocVosvratHW.h"
#include "UREM_FormaDocVosvratHW.h"
#include "UGlobalConstant.h"
#include "IAsyncExternalEvent.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaDocVosvratHWImpl)) TREM_FormaDocVosvratHWImpl : public IREM_FormaDocVosvratHW,
						 IkanCallBack  ,IAsyncExternalEvent
{
public:
   TREM_FormaDocVosvratHWImpl();
   ~TREM_FormaDocVosvratHWImpl();
   TREM_FormaDocVosvratHW * Object;
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


//IREM_FormaDocVosvratHW
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMDocVosvratHW * get_DM(void);
   virtual void set_DM(IREM_DMDocVosvratHW * DM);

   virtual bool get_NewElement(void);
   virtual void set_NewElement(bool NewElement);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaDocVosvratHWImpl __uuidof(TREM_FormaDocVosvratHWImpl)
#endif
