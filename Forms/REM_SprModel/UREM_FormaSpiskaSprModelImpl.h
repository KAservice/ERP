#ifndef UREM_FormaSpiskaSprModelImplH
#define UREM_FormaSpiskaSprModelImplH
#include "IREM_FormaSpiskaSprModel.h"
#include "UREM_FormaSpiskaSprModel.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaSpiskaSprModelImpl)) TREM_FormaSpiskaSprModelImpl : public IREM_FormaSpiskaSprModel, IkanCallBack
{
public:
   TREM_FormaSpiskaSprModelImpl();
   ~TREM_FormaSpiskaSprModelImpl();
   TREM_FormaSpiskaSprModel * Object;
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

//IREM_FormaSpiskaSprModel
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMSprModel* get_DM(void);
   virtual void set_DM(IREM_DMSprModel* DM);

   virtual IREM_DMSprGrpModel * get_DMGrp(void);
   virtual void set_DMGrp(IREM_DMSprGrpModel * DMGrp);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdModel(void);
   virtual void set_IdModel(__int64 IdModel);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual UnicodeString get_TextMessage(void);
   virtual void set_TextMessage(UnicodeString TextMessage);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaSpiskaSprModelImpl __uuidof(TREM_FormaSpiskaSprModelImpl)
#endif
