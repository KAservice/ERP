#ifndef UFormaElementaSprFirmImplH
#define UFormaElementaSprFirmImplH
#include "IFormaElementaSprFirm.h"
#include "UFormaElementaSprFirm.h"
//---------------------------------------------------------------
class __declspec(uuid("{CBCCB4EA-2686-4E96-B861-A1E1F99745D0}")) TFormaElementaSprFirmImpl : public IFormaElementaSprFirm, IkanCallBack
{
public:
   TFormaElementaSprFirmImpl();
   ~TFormaElementaSprFirmImpl();
   TFormaElementaSprFirm * Object;
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

//IFormaElementaSprFirm
   virtual IDMSprFirm * get_DM(void);
   virtual void set_DM(IDMSprFirm * DM);

   virtual __int64 get_IdFirm(void);
   virtual void set_IdFirm(__int64 IdFirm);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaSprFirmImpl __uuidof(TFormaElementaSprFirmImpl)
#endif
