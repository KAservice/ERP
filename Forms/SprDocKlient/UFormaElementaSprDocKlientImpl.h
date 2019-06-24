#ifndef UFormaElementaSprDocKlientImplH
#define UFormaElementaSprDocKlientImplH
#include "IFormaElementaSprDocKlient.h"
#include "UFormaElementaSprDocKlient.h"
//---------------------------------------------------------------
class __declspec(uuid("{A16B686E-4AF6-4A40-8AC6-39126AC577C0}")) TFormaElementaSprDocKlientImpl : public IFormaElementaSprDocKlient, IkanCallBack
{
public:
   TFormaElementaSprDocKlientImpl();
   ~TFormaElementaSprDocKlientImpl();
   TFormaElementaSprDocKlient * Object;
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

//IFormaElementaSprDocKlient
   virtual IDMSprDocKlient * get_DM(void);
   virtual void set_DM(IDMSprDocKlient * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaElementaSprDocKlientImpl __uuidof(TFormaElementaSprDocKlientImpl)
#endif
