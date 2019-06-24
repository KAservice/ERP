#ifndef UIFormaElementaSprDogovorH
#define UIFormaElementaSprDogovorH
#include "IMainInterface.h"
#include "IDMSprDogovor.h"
class __declspec(uuid("{2BA3EAFF-3150-4174-A1D1-0EE61D9664CE}")) IFormaElementaSprDogovor : public IMainInterface
{
public:
   __property IDMSprDogovor * DM = {read = get_DM , write = set_DM};
   virtual IDMSprDogovor * get_DM(void)=0;
   virtual void set_DM(IDMSprDogovor * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprDogovor __uuidof(IFormaElementaSprDogovor)
#endif
