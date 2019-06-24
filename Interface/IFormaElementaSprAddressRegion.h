#ifndef UIFormaElementaSprAddressRegionH
#define UIFormaElementaSprAddressRegionH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprAddressRegion.h"
class __declspec(uuid(Global_IID_IFormaElementaSprAddressRegion)) IFormaElementaSprAddressRegion : public IMainInterface
{
public:
   __property IDMSprAddressRegion * DM = {read = get_DM , write = set_DM};
   virtual IDMSprAddressRegion * get_DM(void)=0;
   virtual void set_DM(IDMSprAddressRegion * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprAddressRegion __uuidof(IFormaElementaSprAddressRegion)
#endif
