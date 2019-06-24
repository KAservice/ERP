#ifndef UFormaSpiskaSprNomImageImplH
#define UFormaSpiskaSprNomImageImplH
#include "IFormaSpiskaSprNomImage.h"
#include "UFormaSpiskaSprNomImage.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSpiskaSprNomImageImpl)) TFormaSpiskaSprNomImageImpl : public IFormaSpiskaSprNomImage, IkanCallBack
{
public:
   TFormaSpiskaSprNomImageImpl();
   ~TFormaSpiskaSprNomImageImpl();
   TFormaSpiskaSprNomImage * Object;
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

//IFormaSpiskaSprNomImage
   virtual IDMSprNomImage * get_DM(void);
   virtual void set_DM(IDMSprNomImage * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual UnicodeString get_HeaderText(void);
   virtual void set_HeaderText(UnicodeString HeaderText);

   virtual void UpdateForm();
};
#define CLSID_TFormaSpiskaSprNomImageImpl __uuidof(TFormaSpiskaSprNomImageImpl)
#endif
