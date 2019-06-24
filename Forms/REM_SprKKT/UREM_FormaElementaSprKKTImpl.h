#ifndef UREM_FormaElementaSprKKTImplH
#define UREM_FormaElementaSprKKTImplH
#include "IREM_FormaElementaSprKKT.h"
#include "UREM_FormaElementaSprKKT.h"
//---------------------------------------------------------------
class __declspec(uuid("{0733D8FE-5C7A-4722-BE2B-52EF3AB06D6F}")) TREM_FormaElementaSprKKTImpl : public IREM_FormaElementaSprKKT, IkanCallBack
{
public:
   TREM_FormaElementaSprKKTImpl();
   ~TREM_FormaElementaSprKKTImpl();
   TREM_FormaElementaSprKKT * Object;
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

//IREM_FormaElementaSprKKT
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMSprKKT * get_DM(void);
   virtual void set_DM(IREM_DMSprKKT * DM);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaElementaSprKKTImpl __uuidof(TREM_FormaElementaSprKKTImpl)
#endif
