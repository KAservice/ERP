#ifndef UREM_FormaElementaSprGrpModelImplH
#define UREM_FormaElementaSprGrpModelImplH
#include "IREM_FormaElementaSprGrpModel.h"
#include "UREM_FormaElementaSprGrpModel.h"
//---------------------------------------------------------------
class __declspec(uuid("{8ECA53FE-989B-4EA0-BDA1-5D3FA69D0A65}"))TREM_FormaElementaSprGrpModelImpl : public IREM_FormaElementaSprGrpModel, IkanCallBack
{
public:
   TREM_FormaElementaSprGrpModelImpl();
   ~TREM_FormaElementaSprGrpModelImpl();
   TREM_FormaElementaSprGrpModel * Object;
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

//IREM_FormaElementaSprGrpModel
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMSprGrpModel* get_DM(void);
   virtual void set_DM(IREM_DMSprGrpModel* DM);

};
#define CLSID_TREM_FormaElementaSprGrpModelImpl __uuidof(TREM_FormaElementaSprGrpModelImpl)
#endif
