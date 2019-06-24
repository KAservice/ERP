#ifndef UREM_FormaElementaSprGrpKKTImplH
#define UREM_FormaElementaSprGrpKKTImplH
#include "IREM_FormaElementaSprGrpKKT.h"
#include "UREM_FormaElementaSprGrpKKT.h"
//---------------------------------------------------------------
class __declspec(uuid("{952A73D5-52AB-4C8D-BDA1-7C11C3C22994}")) TREM_FormaElementaSprGrpKKTImpl : public IREM_FormaElementaSprGrpKKT, IkanCallBack
{
public:
   TREM_FormaElementaSprGrpKKTImpl();
   ~TREM_FormaElementaSprGrpKKTImpl();
   TREM_FormaElementaSprGrpKKT * Object;
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

//IREM_FormaElementaSprGrpKKT
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual UnicodeString get_TextMessage(void);
   virtual void set_TextMessage(UnicodeString TextMessage);

   virtual IREM_DMSprGrpKKT * get_DM(void);
   virtual void set_DM(IREM_DMSprGrpKKT * DM);

};
#define CLSID_TREM_FormaElementaSprGrpKKTImpl __uuidof(TREM_FormaElementaSprGrpKKTImpl)
#endif
