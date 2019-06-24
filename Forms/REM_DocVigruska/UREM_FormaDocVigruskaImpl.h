#ifndef UREM_FormaDocVigruskaImplH
#define UREM_FormaDocVigruskaImplH
#include "IREM_FormaDocVigruska.h"
#include "UREM_FormaDocVigruska.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaDocVigruskaImpl)) TREM_FormaDocVigruskaImpl : public IREM_FormaDocVigruska, IkanCallBack
{
public:
   TREM_FormaDocVigruskaImpl();
   ~TREM_FormaDocVigruskaImpl();
   TREM_FormaDocVigruska * Object;
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

//IREM_FormaDocVigruska
   virtual IREM_DMDocVigruska * get_DM(void);
   virtual void set_DM(IREM_DMDocVigruska * DM);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual bool get_OutReady(void);
   virtual void set_OutReady(bool OutReady);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaDocVigruskaImpl __uuidof(TREM_FormaDocVigruskaImpl)
#endif
