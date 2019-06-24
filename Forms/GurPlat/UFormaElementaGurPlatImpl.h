#ifndef UFormaElementaGurPlatImplH
#define UFormaElementaGurPlatImplH
#include "IFormaElementaGurPlat.h"
#include "UFormaElementaGurPlat.h"
//---------------------------------------------------------------
class __declspec(uuid("{2EA78955-E3D2-4843-B6FC-C7FA5789C688}")) TFormaElementaGurPlatImpl : public IFormaElementaGurPlat, IkanCallBack
{
public:
   TFormaElementaGurPlatImpl();
   ~TFormaElementaGurPlatImpl();
   TFormaElementaGurPlat * Object;
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

//IFormaElementaGurPlat
   virtual IDMGurPlat * get_DM(void);
   virtual void set_DM(IDMGurPlat * DM);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaGurPlatImpl __uuidof(TFormaElementaGurPlatImpl)
#endif
