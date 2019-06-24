#ifndef UFormaSprNomFindImplH
#define UFormaSprNomFindImplH
#include "IFormaSprNomFind.h"
#include "UFormaSprNomFind.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSprNomFindImpl)) TFormaSprNomFindImpl : public IFormaSprNomFind, IkanCallBack
{
public:
   TFormaSprNomFindImpl();
   ~TFormaSprNomFindImpl();
   TFormaSprNomFind * Object;
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

//IFormaSprNomFind
   virtual IDMSprNomFind* get_DM(void);
   virtual void set_DM(IDMSprNomFind* DM);

   virtual IDMSprGrpNom * get_DMGrp(void);
   virtual void set_DMGrp(IDMSprGrpNom * DMGrp);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual UnicodeString get_NameNom(void);
   virtual void set_NameNom(UnicodeString NameNom);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaSprNomFindImpl __uuidof(TFormaSprNomFindImpl)
#endif
