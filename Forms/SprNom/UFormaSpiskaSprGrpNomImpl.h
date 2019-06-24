#ifndef UFormaSpiskaSprGrpNomImplH
#define UFormaSpiskaSprGrpNomImplH
#include "IFormaSpiskaSprGrpNom.h"
#include "UFormaSpiskaSprGrpNom.h"
//---------------------------------------------------------------
class __declspec(uuid("{ECB28F31-29BC-4F70-AA66-3C82163DC588}"))TFormaSpiskaSprGrpNomImpl : public IFormaSpiskaSprGrpNom, IkanCallBack
{
public:
   TFormaSpiskaSprGrpNomImpl();
   ~TFormaSpiskaSprGrpNomImpl();
   TFormaSpiskaSprGrpNom * Object;
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

//IFormaSpiskaSprGrpNom
   virtual IDMSprGrpNom * get_DMGrp(void);
   virtual void set_DMGrp(IDMSprGrpNom * DMGrp);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateDerevo(void);
   virtual void UpdateForm(void);
};
#define CLSID_TFormaSpiskaSprGrpNomImpl __uuidof(TFormaSpiskaSprGrpNomImpl)
#endif
