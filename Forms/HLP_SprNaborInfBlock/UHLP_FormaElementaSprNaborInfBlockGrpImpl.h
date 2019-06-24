#ifndef UHLP_FormaElementaSprNaborInfBlockGrpImplH
#define UHLP_FormaElementaSprNaborInfBlockGrpImplH
#include "IHLP_FormaElementaSprNaborInfBlockGrp.h"
#include "UHLP_FormaElementaSprNaborInfBlockGrp.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_THLP_FormaElementaSprNaborInfBlockGrpImpl)) THLP_FormaElementaSprNaborInfBlockGrpImpl : public IHLP_FormaElementaSprNaborInfBlockGrp, IkanCallBack
{
public:
   THLP_FormaElementaSprNaborInfBlockGrpImpl();
   ~THLP_FormaElementaSprNaborInfBlockGrpImpl();
   THLP_FormaElementaSprNaborInfBlockGrp * Object;
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

//IHLP_FormaElementaSprNaborInfBlockGrp
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IHLP_DMSprNaborInfBlockGrp* get_DM(void);
   virtual void set_DM(IHLP_DMSprNaborInfBlockGrp* DM);

};
#define CLSID_THLP_FormaElementaSprNaborInfBlockGrpImpl __uuidof(THLP_FormaElementaSprNaborInfBlockGrpImpl)
#endif
