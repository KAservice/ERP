#ifndef UREM_FormaElementaSprModelImplH
#define UREM_FormaElementaSprModelImplH
#include "IREM_FormaElementaSprModel.h"
#include "UREM_FormaElementaSprModel.h"
//---------------------------------------------------------------
class __declspec(uuid("{2CF99DFA-D45D-4F74-A5B4-F15B2A1D2073}"))TREM_FormaElementaSprModelImpl : public IREM_FormaElementaSprModel, IkanCallBack
{
public:
   TREM_FormaElementaSprModelImpl();
   ~TREM_FormaElementaSprModelImpl();
   TREM_FormaElementaSprModel * Object;
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

//IREM_FormaElementaSprModel
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMSprModel * get_DM(void);
   virtual void set_DM(IREM_DMSprModel * DM);

   virtual bool get_SaveElement(void);
   virtual void set_SaveElement(bool SaveElement);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaElementaSprModelImpl __uuidof(TREM_FormaElementaSprModelImpl)
#endif
