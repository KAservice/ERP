#ifndef UIFormaSpiskaSprGrpNomH
#define UIFormaSpiskaSprGrpNomH
#include "IMainInterface.h"
#include "IDMSprGrpNom.h"
class __declspec(uuid("{CD5FB70F-4B4E-4E4D-84D9-FFC2EA53E8A1}")) IFormaSpiskaSprGrpNom : public IMainInterface
{
public:
   __property IDMSprGrpNom * DMGrp = {read = get_DMGrp , write = set_DMGrp};
   virtual IDMSprGrpNom * get_DMGrp(void)=0;
   virtual void set_DMGrp(IDMSprGrpNom * DMGrp)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateDerevo(void)=0;
   virtual void UpdateForm(void)=0;
};
#define IID_IFormaSpiskaSprGrpNom __uuidof(IFormaSpiskaSprGrpNom)
#endif
