#ifndef UREM_FormaSpiskaSprSostCustQueryImplH
#define UREM_FormaSpiskaSprSostCustQueryImplH
#include "IREM_FormaSpiskaSprSostCustQuery.h"
#include "UREM_FormaSpiskaSprSostCustQuery.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaSpiskaSprSostCustQueryImpl)) TREM_FormaSpiskaSprSostCustQueryImpl
			 : public IREM_FormaSpiskaSprSostCustQuery, IkanCallBack
{
public:
   TREM_FormaSpiskaSprSostCustQueryImpl();
   ~TREM_FormaSpiskaSprSostCustQueryImpl();
   TREM_FormaSpiskaSprSostCustQuery * Object;
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

//IREM_FormaSpiskaSprSostCustQuery
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual UnicodeString get_TextMessage(void);
   virtual void set_TextMessage(UnicodeString TextMessage);

   virtual IREM_DMSprSostCustQuery * get_DM(void);
   virtual void set_DM(IREM_DMSprSostCustQuery * DM);

};
#define CLSID_TREM_FormaSpiskaSprSostCustQueryImpl __uuidof(TREM_FormaSpiskaSprSostCustQueryImpl)
#endif
