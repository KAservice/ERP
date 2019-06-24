#ifndef UIFormaElementaSprAddressStroenH
#define UIFormaElementaSprAddressStroenH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprAddressStroen.h"
class __declspec(uuid(Global_IID_IFormaElementaSprAddressStroen)) IFormaElementaSprAddressStroen : public IMainInterface
{
public:
   __property IDMSprAddressStroen * DM = {read = get_DM , write = set_DM};
   virtual IDMSprAddressStroen * get_DM(void)=0;
   virtual void set_DM(IDMSprAddressStroen * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprAddressStroen __uuidof(IFormaElementaSprAddressStroen)
#endif
