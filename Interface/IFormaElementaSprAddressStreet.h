#ifndef UIFormaElementaSprAddressStreetH
#define UIFormaElementaSprAddressStreetH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprAddressStreet.h"
class __declspec(uuid(Global_IID_IFormaElementaSprAddressStreet)) IFormaElementaSprAddressStreet : public IMainInterface
{
public:
   __property IDMSprAddressStreet * DM = {read = get_DM , write = set_DM};
   virtual IDMSprAddressStreet * get_DM(void)=0;
   virtual void set_DM(IDMSprAddressStreet * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprAddressStreet __uuidof(IFormaElementaSprAddressStreet)
#endif
