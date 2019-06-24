#ifndef UIFormaElementaSprPropertiesNaborSostavH
#define UIFormaElementaSprPropertiesNaborSostavH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprPropertiesNaborSostav.h"
class __declspec(uuid(Global_IID_IFormaElementaSprPropertiesNaborSostav)) IFormaElementaSprPropertiesNaborSostav : public IMainInterface
{
public:
   __property IDMSprPropertiesNaborSostav * DM = {read = get_DM , write = set_DM};
   virtual IDMSprPropertiesNaborSostav * get_DM(void)=0;
   virtual void set_DM(IDMSprPropertiesNaborSostav * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprPropertiesNaborSostav __uuidof(IFormaElementaSprPropertiesNaborSostav)
#endif
