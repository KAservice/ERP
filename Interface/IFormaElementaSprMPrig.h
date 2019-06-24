#ifndef UIFormaElementaSprMPrigH
#define UIFormaElementaSprMPrigH
#include "IMainInterface.h"
#include "IDMSprMPrig.h"
class __declspec(uuid("{AB787B8F-F151-4EF0-9E39-498E5183BA7C}")) IFormaElementaSprMPrig : public IMainInterface
{
public:
   __property IDMSprMPrig * DM = {read = get_DM , write = set_DM};
   virtual IDMSprMPrig * get_DM(void)=0;
   virtual void set_DM(IDMSprMPrig * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;


};
#define IID_IFormaElementaSprMPrig __uuidof(IFormaElementaSprMPrig)
#endif
