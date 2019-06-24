#ifndef UIFormaSpiskaSprVesNomH
#define UIFormaSpiskaSprVesNomH
#include "IMainInterface.h"
#include "IDMSprVesNom.h"
#include "IDMSprGrpVesNom.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprVesNom)) IFormaSpiskaSprVesNom : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMSprVesNom* DM = {read = get_DM , write = set_DM};
   virtual IDMSprVesNom* get_DM(void)=0;
   virtual void set_DM(IDMSprVesNom* DM)=0;

   __property IDMSprGrpVesNom* DMGrp = {read = get_DMGrp , write = set_DMGrp};
   virtual IDMSprGrpVesNom* get_DMGrp(void)=0;
   virtual void set_DMGrp(IDMSprGrpVesNom* DMGrp)=0;

   __property __int64 IdScale = {read = get_IdScale , write = set_IdScale};
   virtual __int64 get_IdScale(void)=0;
   virtual void set_IdScale(__int64 IdScale)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdTypePrice = {read = get_IdTypePrice , write = set_IdTypePrice};
   virtual __int64 get_IdTypePrice(void)=0;
   virtual void set_IdTypePrice(__int64 IdTypePrice)=0;

   __property __int64 IdVesNom = {read = get_IdVesNom , write = set_IdVesNom};
   virtual __int64 get_IdVesNom(void)=0;
   virtual void set_IdVesNom(__int64 IdVesNom)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property bool Podbor = {read = get_Podbor , write = set_Podbor};
   virtual bool get_Podbor(void)=0;
   virtual void set_Podbor(bool Podbor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaSpiskaSprVesNom __uuidof(IFormaSpiskaSprVesNom)
#endif
