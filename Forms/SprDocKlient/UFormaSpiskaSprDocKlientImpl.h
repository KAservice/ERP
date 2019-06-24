#ifndef UFormaSpiskaSprDocKlientImplH
#define UFormaSpiskaSprDocKlientImplH
#include "IFormaSpiskaSprDocKlient.h"
#include "UFormaSpiskaSprDocKlient.h"
//---------------------------------------------------------------
class __declspec(uuid("{352DBA96-5507-42B4-B2F0-6A1D633A4EB4}")) TFormaSpiskaSprDocKlientImpl : public IFormaSpiskaSprDocKlient, IkanCallBack
{
public:
   TFormaSpiskaSprDocKlientImpl();
   ~TFormaSpiskaSprDocKlientImpl();
   TFormaSpiskaSprDocKlient * Object;
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

//IFormaSpiskaSprDocKlient
   virtual IDMSprDocKlient * get_DM(void);
   virtual void set_DM(IDMSprDocKlient * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdKlient(void);
   virtual void set_IdKlient(__int64 IdKlient);

   virtual void OpenFormElement();
   virtual void OpenFormNewElement();
   virtual void DeleteElement();
   virtual void UpdateForm();
};
#define CLSID_TFormaSpiskaSprDocKlientImpl __uuidof(TFormaSpiskaSprDocKlientImpl)
#endif
