#ifndef UFormaViborBVNomImplH
#define UFormaViborBVNomImplH
#include "IFormaViborBVNom.h"
#include "UFormaViborBVNom.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaViborSprBVNomImpl)) TFormaViborBVNomImpl : public IFormaViborBVNom
{
public:
   TFormaViborBVNomImpl();
   ~TFormaViborBVNomImpl();
   TFormaViborBVNom * Object;
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

//IFormaViborBVNom
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMSprBVNom* get_DM(void);
   virtual void set_DM(IDMSprBVNom* DM);

   virtual IDMSprGrpBVNom * get_DMGrp(void);
   virtual void set_DMGrp(IDMSprGrpBVNom * DMGrp);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdPod(void);
   virtual void set_IdPod(__int64 IdPod);

   virtual __int64 get_ViborIdNom(void);
   virtual void set_ViborIdNom(__int64 ViborIdNom);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaViborBVNomImpl __uuidof(TFormaViborBVNomImpl)
#endif
