#ifndef UIFormaElementaXSetupObmenH
#define UIFormaElementaXSetupObmenH
#include "IMainInterface.h"
#include "IDMXSetupObmen.h"
class __declspec(uuid("{188655C0-0C4D-46B8-BA5D-A3035660D792}")) IFormaElementaXSetupObmen : public IMainInterface
{
public:
   __property IDMXSetupObmen * DM = {read = get_DM , write = set_DM};
   virtual IDMXSetupObmen * get_DM(void)=0;
   virtual void set_DM(IDMXSetupObmen * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaXSetupObmen __uuidof(IFormaElementaXSetupObmen)
#endif
