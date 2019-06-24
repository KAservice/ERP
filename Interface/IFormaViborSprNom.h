#ifndef UIFormaViborSprNomH
#define UIFormaViborSprNomH
#include "IMainInterface.h"
#include "IDMSprNom.h"
#include "IDMSprGrpNom.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaViborSprNom)) IFormaViborSprNom : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMSprNom* DM = {read = get_DM , write = set_DM};
   virtual IDMSprNom* get_DM(void)=0;
   virtual void set_DM(IDMSprNom* DM)=0;

   __property IDMSprGrpNom * DMGrp = {read = get_DMGrp , write = set_DMGrp};
   virtual IDMSprGrpNom * get_DMGrp(void)=0;
   virtual void set_DMGrp(IDMSprGrpNom * DMGrp)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property bool FlagOstatok = {read = get_FlagOstatok , write = set_FlagOstatok};
   virtual bool get_FlagOstatok(void)=0;
   virtual void set_FlagOstatok(bool FlagOstatok)=0;

   virtual void UpdateForm(void)=0;
   virtual void LoadFormSetup()=0;
   virtual void SaveFormSetup()=0;
};
#define IID_IFormaViborSprNom __uuidof(IFormaViborSprNom)
#endif
