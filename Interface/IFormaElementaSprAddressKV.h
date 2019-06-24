#ifndef UIFormaElementaSprAddressKVH
#define UIFormaElementaSprAddressKVH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprAddressKV.h"
class __declspec(uuid(Global_IID_IFormaElementaSprAddressKV)) IFormaElementaSprAddressKV : public IMainInterface
{
public:
   __property IDMSprAddressKV * DM = {read = get_DM , write = set_DM};
   virtual IDMSprAddressKV * get_DM(void)=0;
   virtual void set_DM(IDMSprAddressKV * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprAddressKV __uuidof(IFormaElementaSprAddressKV)
#endif
