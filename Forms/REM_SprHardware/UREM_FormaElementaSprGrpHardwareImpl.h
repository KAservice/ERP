#ifndef UREM_FormaElementaSprGrpHardwareImplH
#define UREM_FormaElementaSprGrpHardwareImplH
#include "IREM_FormaElementaSprGrpHardware.h"
#include "UREM_FormaElementaSprGrpHardware.h"
//---------------------------------------------------------------
class __declspec(uuid("{13BAB23A-E1E4-4092-893F-6EBBA06F19B0}"))TREM_FormaElementaSprGrpHardwareImpl : public IREM_FormaElementaSprGrpHardware, IkanCallBack
{
public:
   TREM_FormaElementaSprGrpHardwareImpl();
   ~TREM_FormaElementaSprGrpHardwareImpl();
   TREM_FormaElementaSprGrpHardware * Object;
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

//IREM_FormaElementaSprGrpHardware
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMSprGrpHardware * get_DM(void);
   virtual void set_DM(IREM_DMSprGrpHardware * DM);

};
#define CLSID_TREM_FormaElementaSprGrpHardwareImpl __uuidof(TREM_FormaElementaSprGrpHardwareImpl)
#endif
