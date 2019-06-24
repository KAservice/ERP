#ifndef UFormaSpiskaSprGrpKlientImplH
#define UFormaSpiskaSprGrpKlientImplH
#include "IFormaSpiskaSprGrpKlient.h"
#include "UFormaSpiskaSprGrpKlient.h"
//---------------------------------------------------------------
class __declspec(uuid("{372EBF8E-79A9-4CCA-9966-3DDC8892EA22}")) TFormaSpiskaSprGrpKlientImpl : public IFormaSpiskaSprGrpKlient, IkanCallBack
{
public:
   TFormaSpiskaSprGrpKlientImpl();
   ~TFormaSpiskaSprGrpKlientImpl();
   TFormaSpiskaSprGrpKlient * Object;
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

//IFormaSpiskaSprGrpKlient
   virtual IDMSprGrpKlient * get_DM(void);
   virtual void set_DM(IDMSprGrpKlient * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

};
#define CLSID_TFormaSpiskaSprGrpKlientImpl __uuidof(TFormaSpiskaSprGrpKlientImpl)
#endif
