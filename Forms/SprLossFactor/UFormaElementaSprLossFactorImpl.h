#ifndef UFormaElementaSprLossFactorImplH
#define UFormaElementaSprLossFactorImplH
#include "IFormaElementaSprLossFactor.h"
#include "UFormaElementaSprLossFactor.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaElementaSprLossFactorImpl)) TFormaElementaSprLossFactorImpl : public IFormaElementaSprLossFactor, IkanCallBack
{
public:
   TFormaElementaSprLossFactorImpl();
   ~TFormaElementaSprLossFactorImpl();
   TFormaElementaSprLossFactor * Object;
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

//IFormaElementaSprLossFactor
   virtual IDMSprLossFactor * get_DM(void);
   virtual void set_DM(IDMSprLossFactor * DM);

   virtual IDMSprLossFactorValue * get_DMSprLossFactorValue(void);
   virtual void set_DMSprLossFactorValue(IDMSprLossFactorValue * DMSprLossFactorValue);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual UnicodeString get_NameGrp(void);
   virtual void set_NameGrp(UnicodeString NameGrp);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaSprLossFactorImpl __uuidof(TFormaElementaSprLossFactorImpl)
#endif
