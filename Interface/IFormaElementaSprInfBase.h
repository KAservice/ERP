#ifndef UIFormaElementaSprInfBaseH
#define UIFormaElementaSprInfBaseH
#include "IMainInterface.h"
#include "IDMSprInfBase.h"
class __declspec(uuid("{1B88B7D5-CF54-457A-94D3-AB75CA591683}")) IFormaElementaSprInfBase : public IMainInterface
{
public:
   __property IDMSprInfBase * DM = {read = get_DM , write = set_DM};
   virtual IDMSprInfBase * get_DM(void)=0;
   virtual void set_DM(IDMSprInfBase * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprInfBase __uuidof(IFormaElementaSprInfBase)
#endif
