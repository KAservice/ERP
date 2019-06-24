#ifndef UFormaElementaExtModuleGrpImplH
#define UFormaElementaExtModuleGrpImplH
#include "IFormaElementaExtModuleGrp.h"
#include "UFormaElementaExtModuleGrp.h"
//---------------------------------------------------------------
class __declspec(uuid("{5101B31E-FF2F-4C61-8D2A-C7C62BCE86F0}")) TFormaElementaExtModuleGrpImpl : public IFormaElementaExtModuleGrp, IkanCallBack
{
public:
   TFormaElementaExtModuleGrpImpl();
   ~TFormaElementaExtModuleGrpImpl();
   TFormaElementaExtModuleGrp * Object;
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

//IFormaElementaExtModuleGrp
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMExtModuleGrp* get_DM(void);
   virtual void set_DM(IDMExtModuleGrp* DM);

};
#define CLSID_TFormaElementaExtModuleGrpImpl __uuidof(TFormaElementaExtModuleGrpImpl)
#endif
