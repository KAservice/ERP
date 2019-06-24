#ifndef UIFormaElementaSprAddressRayonH
#define UIFormaElementaSprAddressRayonH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprAddressRayon.h"
class __declspec(uuid(Global_IID_IFormaElementaSprAddressRayon)) IFormaElementaSprAddressRayon : public IMainInterface
{
public:
   __property IDMSprAddressRayon * DM = {read = get_DM , write = set_DM};
   virtual IDMSprAddressRayon * get_DM(void)=0;
   virtual void set_DM(IDMSprAddressRayon * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprAddressRayon __uuidof(IFormaElementaSprAddressRayon)
#endif
