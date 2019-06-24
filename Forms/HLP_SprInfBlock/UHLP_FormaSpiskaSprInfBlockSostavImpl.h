#ifndef UHLP_FormaSpiskaSprInfBlockSostavImplH
#define UHLP_FormaSpiskaSprInfBlockSostavImplH
#include "IHLP_FormaSpiskaSprInfBlockSostav.h"
#include "UHLP_FormaSpiskaSprInfBlockSostav.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_THLP_FormaSpiskaSprInfBlockSostavImpl)) THLP_FormaSpiskaSprInfBlockSostavImpl : public IHLP_FormaSpiskaSprInfBlockSostav, IkanCallBack
{
public:
   THLP_FormaSpiskaSprInfBlockSostavImpl();
   ~THLP_FormaSpiskaSprInfBlockSostavImpl();
   THLP_FormaSpiskaSprInfBlockSostav * Object;
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

//IHLP_FormaSpiskaSprInfBlockSostav
   virtual IHLP_DMSprInfBlockSostav * get_DM(void);
   virtual void set_DM(IHLP_DMSprInfBlockSostav * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdPage(void);
   virtual void set_IdPage(__int64 IdPage);

   virtual UnicodeString get_HeaderText(void);
   virtual void set_HeaderText(UnicodeString HeaderText);

   virtual void UpdateForm();
};
#define CLSID_THLP_FormaSpiskaSprInfBlockSostavImpl __uuidof(THLP_FormaSpiskaSprInfBlockSostavImpl)
#endif
