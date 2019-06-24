#ifndef UFormaElementaSprGrpKlientImplH
#define UFormaElementaSprGrpKlientImplH
#include "IFormaElementaSprGrpKlient.h"
#include "UFormaElementaSprGrpKlient.h"
//---------------------------------------------------------------
class __declspec(uuid("{5ABF1BAE-B305-402D-B9DE-C5FF9FA435FD}")) TFormaElementaSprGrpKlientImpl : public IFormaElementaSprGrpKlient, IkanCallBack
{
public:
   TFormaElementaSprGrpKlientImpl();
   ~TFormaElementaSprGrpKlientImpl();
   TFormaElementaSprGrpKlient * Object;
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

//IFormaElementaSprGrpKlient
   virtual IDMSprGrpKlient* get_DM(void);
   virtual void set_DM(IDMSprGrpKlient* DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

};
#define CLSID_TFormaElementaSprGrpKlientImpl __uuidof(TFormaElementaSprGrpKlientImpl)
#endif
