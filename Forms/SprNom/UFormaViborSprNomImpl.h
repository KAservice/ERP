#ifndef UFormaViborSprNomImplH
#define UFormaViborSprNomImplH
#include "IFormaViborSprNom.h"
#include "UFormaViborSprNom.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaViborSprNomImpl)) TFormaViborSprNomImpl : public IFormaViborSprNom
{
public:
   TFormaViborSprNomImpl();
   ~TFormaViborSprNomImpl();
   TFormaViborSprNom * Object;
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

//IFormaViborSprNom
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMSprNom* get_DM(void);
   virtual void set_DM(IDMSprNom* DM);

   virtual IDMSprGrpNom * get_DMGrp(void);
   virtual void set_DMGrp(IDMSprGrpNom * DMGrp);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual bool get_FlagOstatok(void);
   virtual void set_FlagOstatok(bool FlagOstatok);

   virtual void UpdateForm(void);
   virtual void LoadFormSetup();
   virtual void SaveFormSetup();
};
#define CLSID_TFormaViborSprNomImpl __uuidof(TFormaViborSprNomImpl)
#endif
