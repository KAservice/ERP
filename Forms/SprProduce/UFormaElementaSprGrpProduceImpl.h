#ifndef UFormaElementaSprGrpProduceImplH
#define UFormaElementaSprGrpProduceImplH
#include "IFormaElementaSprGrpProduce.h"
#include "UFormaElementaSprGrpProduce.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaElementaSprGrpProduceImpl)) TFormaElementaSprGrpProduceImpl : public IFormaElementaSprGrpProduce, IkanCallBack
{
public:
   TFormaElementaSprGrpProduceImpl();
   ~TFormaElementaSprGrpProduceImpl();
   TFormaElementaSprGrpProduce * Object;
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

//IFormaElementaSprGrpProduce
   virtual IDMSprGrpProduce* get_DM(void);
   virtual void set_DM(IDMSprGrpProduce* DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

};
#define CLSID_TFormaElementaSprGrpProduceImpl __uuidof(TFormaElementaSprGrpProduceImpl)
#endif
