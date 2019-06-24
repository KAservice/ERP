#ifndef UFormaElementaObjectBaseGrpImplH
#define UFormaElementaObjectBaseGrpImplH
#include "IFormaElementaObjectBaseGrp.h"
#include "UFormaElementaObjectBaseGrp.h"
//---------------------------------------------------------------
class __declspec(uuid("{8C12F1B6-3290-4138-A070-31DDA29D3359}")) TFormaElementaObjectBaseGrpImpl : public IFormaElementaObjectBaseGrp, IkanCallBack
{
public:
   TFormaElementaObjectBaseGrpImpl();
   ~TFormaElementaObjectBaseGrpImpl();
   TFormaElementaObjectBaseGrp * Object;
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

//IFormaElementaObjectBaseGrp
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMObjectBaseGrp* get_DM(void);
   virtual void set_DM(IDMObjectBaseGrp* DM);

};
#define CLSID_TFormaElementaObjectBaseGrpImpl __uuidof(TFormaElementaObjectBaseGrpImpl)
#endif
