#ifndef UREM_FormaElementaSprModel2GrpImplH
#define UREM_FormaElementaSprModel2GrpImplH
#include "IREM_FormaElementaSprModel2Grp.h"
#include "UREM_FormaElementaSprModel2Grp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaElementaSprModel2GrpImpl)) TREM_FormaElementaSprModel2GrpImpl : public IREM_FormaElementaSprModel2Grp, IkanCallBack
{
public:
   TREM_FormaElementaSprModel2GrpImpl();
   ~TREM_FormaElementaSprModel2GrpImpl();
   TREM_FormaElementaSprModel2Grp * Object;
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

//IREM_FormaElementaSprModel2Grp
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMSprModel2Grp* get_DM(void);
   virtual void set_DM(IREM_DMSprModel2Grp* DM);

};
#define CLSID_TREM_FormaElementaSprModel2GrpImpl __uuidof(TREM_FormaElementaSprModel2GrpImpl)
#endif
