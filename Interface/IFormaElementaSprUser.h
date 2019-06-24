#ifndef UIFormaElementaSprUserH
#define UIFormaElementaSprUserH
#include "IMainInterface.h"
#include "IDMSprUser.h"
class __declspec(uuid("{754D0A60-FDB9-4F18-B0BF-F12195FF6CB4}")) IFormaElementaSprUser : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMSprUser * DM = {read = get_DM , write = set_DM};
   virtual IDMSprUser * get_DM(void)=0;
   virtual void set_DM(IDMSprUser * DM)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprUser __uuidof(IFormaElementaSprUser)
#endif
