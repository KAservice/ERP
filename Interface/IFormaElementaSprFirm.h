#ifndef UIFormaElementaSprFirmH
#define UIFormaElementaSprFirmH
#include "IMainInterface.h"
#include "IDMSprFirm.h"
class __declspec(uuid("{57718B0A-9F60-4BF9-B97A-4F90473D7CA3}")) IFormaElementaSprFirm : public IMainInterface
{
public:
   __property IDMSprFirm * DM = {read = get_DM , write = set_DM};
   virtual IDMSprFirm * get_DM(void)=0;
   virtual void set_DM(IDMSprFirm * DM)=0;

   __property __int64 IdFirm = {read = get_IdFirm , write = set_IdFirm};
   virtual __int64 get_IdFirm(void)=0;
   virtual void set_IdFirm(__int64 IdFirm)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprFirm __uuidof(IFormaElementaSprFirm)
#endif
