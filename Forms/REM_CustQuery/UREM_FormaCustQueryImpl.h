#ifndef UREM_FormaCustQueryImplH
#define UREM_FormaCustQueryImplH
#include "IREM_FormaCustQuery.h"
#include "UREM_FormaCustQuery.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaCustQueryImpl)) TREM_FormaCustQueryImpl : public IREM_FormaCustQuery, IkanCallBack
{
public:
   TREM_FormaCustQueryImpl();
   ~TREM_FormaCustQueryImpl();
   TREM_FormaCustQuery * Object;
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

//IREM_FormaCustQuery
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMCustQuery * get_DM(void);
   virtual void set_DM(IREM_DMCustQuery * DM);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdCQ(void);
   virtual void set_IdCQ(__int64 IdCQ);

   virtual __int64 get_IdCQT(void);
   virtual void set_IdCQT(__int64 IdCQT);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaCustQueryImpl __uuidof(TREM_FormaCustQueryImpl)
#endif
