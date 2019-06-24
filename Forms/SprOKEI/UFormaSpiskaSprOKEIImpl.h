#ifndef UFormaSpiskaSprOKEIImplH
#define UFormaSpiskaSprOKEIImplH
#include "IFormaSpiskaSprOKEI.h"
#include "UFormaSpiskaSprOKEI.h"
//---------------------------------------------------------------
class __declspec(uuid("{DADCAB4A-CEA4-460C-9E3D-4690D3093C1E}"))TFormaSpiskaSprOKEIImpl : public IFormaSpiskaSprOKEI, IkanCallBack
{
public:
   TFormaSpiskaSprOKEIImpl();
   ~TFormaSpiskaSprOKEIImpl();
   TFormaSpiskaSprOKEI * Object;
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

//IFormaSpiskaSprOKEI
   virtual IDMSprOKEI * get_DM(void);
   virtual void set_DM(IDMSprOKEI * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void OpenFormElement();
   virtual void OpenFormNewElement();
   virtual void DeleteElement();
};
#define CLSID_TFormaSpiskaSprOKEIImpl __uuidof(TFormaSpiskaSprOKEIImpl)
#endif
