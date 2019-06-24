#ifndef UREM_FormaElementaSprProducerDefectImplH
#define UREM_FormaElementaSprProducerDefectImplH
#include "IREM_FormaElementaSprProducerDefect.h"
#include "UREM_FormaElementaSprProducerDefect.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaElementaSprProducerDefectImpl)) TREM_FormaElementaSprProducerDefectImpl : public IREM_FormaElementaSprProducerDefect, IkanCallBack
{
public:
   TREM_FormaElementaSprProducerDefectImpl();
   ~TREM_FormaElementaSprProducerDefectImpl();
   TREM_FormaElementaSprProducerDefect * Object;
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

//IREM_FormaElementaSprProducerDefect
   virtual IREM_DMSprProducerDefect* get_DM(void);
   virtual void set_DM(IREM_DMSprProducerDefect* DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual UnicodeString get_NameGroupElement(void);
   virtual void set_NameGroupElement(UnicodeString NameGroupElement);

   virtual __int64 get_IdGroupElement(void);
   virtual void set_IdGroupElement(__int64 IdGroupElement);

   virtual UnicodeString get_NameGroup(void);
   virtual void set_NameGroup(UnicodeString NameGroup);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaElementaSprProducerDefectImpl __uuidof(TREM_FormaElementaSprProducerDefectImpl)
#endif
