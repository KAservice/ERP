#ifndef UREM_FormaElementaSprKomplModelImplH
#define UREM_FormaElementaSprKomplModelImplH
#include "IREM_FormaElementaSprKomplModel.h"
#include "UREM_FormaElementaSprKomplModel.h"
//---------------------------------------------------------------
class __declspec(uuid("{ACBBE169-A906-438B-BEEF-E39491278957}")) TREM_FormaElementaSprKomplModelImpl : public IREM_FormaElementaSprKomplModel, IkanCallBack
{
public:
   TREM_FormaElementaSprKomplModelImpl();
   ~TREM_FormaElementaSprKomplModelImpl();
   TREM_FormaElementaSprKomplModel * Object;
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

//IREM_FormaElementaSprKomplModel
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMSprKomplModel * get_DM(void);
   virtual void set_DM(IREM_DMSprKomplModel * DM);

   virtual UnicodeString get_TextMessage(void);
   virtual void set_TextMessage(UnicodeString TextMessage);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaElementaSprKomplModelImpl __uuidof(TREM_FormaElementaSprKomplModelImpl)
#endif
