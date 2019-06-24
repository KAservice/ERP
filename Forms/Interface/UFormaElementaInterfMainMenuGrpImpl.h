#ifndef UFormaElementaInterfMainMenuGrpImplH
#define UFormaElementaInterfMainMenuGrpImplH
#include "IFormaElementaInterfMainMenuGrp.h"
#include "UFormaElementaInterfMainMenuGrp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaElementaInterfMainMenuGrpImpl)) TFormaElementaInterfMainMenuGrpImpl : public IFormaElementaInterfMainMenuGrp, IkanCallBack
{
public:
   TFormaElementaInterfMainMenuGrpImpl();
   ~TFormaElementaInterfMainMenuGrpImpl();
   TFormaElementaInterfMainMenuGrp * Object;
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

//IFormaElementaInterfMainMenuGrp
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMInterfMainMenuGrp* get_DM(void);
   virtual void set_DM(IDMInterfMainMenuGrp* DM);

};
#define CLSID_TFormaElementaInterfMainMenuGrpImpl __uuidof(TFormaElementaInterfMainMenuGrpImpl)
#endif
