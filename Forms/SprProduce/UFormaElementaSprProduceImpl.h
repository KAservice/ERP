#ifndef UFormaElementaSprProduceImplH
#define UFormaElementaSprProduceImplH
#include "IFormaElementaSprProduce.h"
#include "UFormaElementaSprProduce.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaElementaSprProduceImpl)) TFormaElementaSprProduceImpl : public IFormaElementaSprProduce, IkanCallBack
{
public:
   TFormaElementaSprProduceImpl();
   ~TFormaElementaSprProduceImpl();
   TFormaElementaSprProduce * Object;
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

//IFormaElementaSprProduce
   virtual IDMSprProduce * get_DM(void);
   virtual void set_DM(IDMSprProduce * DM);

   virtual IDMSprFactorValue * get_DMSprFactorValue(void);
   virtual void set_DMSprFactorValue(IDMSprFactorValue * DMSprFactorValue);

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
#define CLSID_TFormaElementaSprProduceImpl __uuidof(TFormaElementaSprProduceImpl)
#endif
