#ifndef UFormaSpiskaSprBusinessOperImplH
#define UFormaSpiskaSprBusinessOperImplH
#include "IFormaSpiskaSprBusinessOper.h"
#include "UFormaSpiskaSprBusinessOper.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSpiskaSprBusinessOperImpl)) TFormaSpiskaSprBusinessOperImpl : public IFormaSpiskaSprBusinessOper, IkanCallBack
{
public:
   TFormaSpiskaSprBusinessOperImpl();
   ~TFormaSpiskaSprBusinessOperImpl();
   TFormaSpiskaSprBusinessOper * Object;
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

//IFormaSpiskaSprBusinessOper
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMSprBusinessOper* get_DM(void);
   virtual void set_DM(IDMSprBusinessOper* DM);

   virtual IDMSprGrpBusinessOper * get_DMGrp(void);
   virtual void set_DMGrp(IDMSprGrpBusinessOper * DMGrp);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual bool get_Podbor(void);
   virtual void set_Podbor(bool Podbor);

   virtual UnicodeString get_HeaderText(void);
   virtual void set_HeaderText(UnicodeString HeaderText);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaSpiskaSprBusinessOperImpl __uuidof(TFormaSpiskaSprBusinessOperImpl)
#endif
