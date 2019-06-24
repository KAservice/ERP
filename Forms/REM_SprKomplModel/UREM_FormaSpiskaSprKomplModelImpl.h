#ifndef UREM_FormaSpiskaSprKomplModelImplH
#define UREM_FormaSpiskaSprKomplModelImplH
#include "IREM_FormaSpiskaSprKomplModel.h"
#include "UREM_FormaSpiskaSprKomplModel.h"
//---------------------------------------------------------------
class __declspec(uuid("{21F53C5A-9FAF-4600-9AA4-A8C97EAE5815}")) TREM_FormaSpiskaSprKomplModelImpl : public IREM_FormaSpiskaSprKomplModel, IkanCallBack
{
public:
   TREM_FormaSpiskaSprKomplModelImpl();
   ~TREM_FormaSpiskaSprKomplModelImpl();
   TREM_FormaSpiskaSprKomplModel * Object;
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

//IREM_FormaSpiskaSprKomplModel
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMSprKomplModel * get_DM(void);
   virtual void set_DM(IREM_DMSprKomplModel * DM);

   virtual __int64 get_IdModel(void);
   virtual void set_IdModel(__int64 IdModel);

   virtual UnicodeString get_TextMessage(void);
   virtual void set_TextMessage(UnicodeString TextMessage);

   virtual void UpdateForm();
};
#define CLSID_TREM_FormaSpiskaSprKomplModelImpl __uuidof(TREM_FormaSpiskaSprKomplModelImpl)
#endif
