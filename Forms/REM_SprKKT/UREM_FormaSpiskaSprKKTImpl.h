#ifndef UREM_FormaSpiskaSprKKTImplH
#define UREM_FormaSpiskaSprKKTImplH
#include "IREM_FormaSpiskaSprKKT.h"
#include "UREM_FormaSpiskaSprKKT.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaSpiskaSprKKTImpl)) TREM_FormaSpiskaSprKKTImpl : public IREM_FormaSpiskaSprKKT, IkanCallBack
{
public:
   TREM_FormaSpiskaSprKKTImpl();
   ~TREM_FormaSpiskaSprKKTImpl();
   TREM_FormaSpiskaSprKKT * Object;
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

//IREM_FormaSpiskaSprKKT
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMSprKKT* get_DM(void);
   virtual void set_DM(IREM_DMSprKKT* DM);

   virtual IREM_DMSprGrpKKT * get_DMGrp(void);
   virtual void set_DMGrp(IREM_DMSprGrpKKT * DMGrp);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual bool get_Podbor(void);
   virtual void set_Podbor(bool Podbor);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaSpiskaSprKKTImpl __uuidof(TREM_FormaSpiskaSprKKTImpl)
#endif
