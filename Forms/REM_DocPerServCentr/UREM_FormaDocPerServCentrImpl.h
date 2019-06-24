#ifndef UREM_FormaDocPerServCentrImplH
#define UREM_FormaDocPerServCentrImplH
#include "IREM_FormaDocPerServCentr.h"
#include "UREM_FormaDocPerServCentr.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaDocPerServCentrImpl)) TREM_FormaDocPerServCentrImpl : public IREM_FormaDocPerServCentr, IkanCallBack
{
public:
   TREM_FormaDocPerServCentrImpl();
   ~TREM_FormaDocPerServCentrImpl();
   TREM_FormaDocPerServCentr * Object;
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

//IREM_FormaDocPerServCentr
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMDocPerServCentr * get_DM(void);
   virtual void set_DM(IREM_DMDocPerServCentr * DM);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaDocPerServCentrImpl __uuidof(TREM_FormaDocPerServCentrImpl)
#endif
