#ifndef UIFormaElementaInterfMainMenuGrpH
#define UIFormaElementaInterfMainMenuGrpH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMInterfMainMenuGrp.h"
class __declspec(uuid(Global_IID_IFormaElementaInterfMainMenuGrp)) IFormaElementaInterfMainMenuGrp : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMInterfMainMenuGrp* DM = {read = get_DM , write = set_DM};
   virtual IDMInterfMainMenuGrp* get_DM(void)=0;
   virtual void set_DM(IDMInterfMainMenuGrp* DM)=0;

};
#define IID_IFormaElementaInterfMainMenuGrp __uuidof(IFormaElementaInterfMainMenuGrp)
#endif
