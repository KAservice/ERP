#ifndef UIFormaElementaSprPropertiesGrpH
#define UIFormaElementaSprPropertiesGrpH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprPropertiesGrp.h"
class __declspec(uuid(Global_IID_IFormaElementaSprPropertiesGrp)) IFormaElementaSprPropertiesGrp : public IMainInterface
{
public:
   __property IDMSprPropertiesGrp* DM = {read = get_DM , write = set_DM};
   virtual IDMSprPropertiesGrp* get_DM(void)=0;
   virtual void set_DM(IDMSprPropertiesGrp* DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

};
#define IID_IFormaElementaSprPropertiesGrp __uuidof(IFormaElementaSprPropertiesGrp)
#endif
