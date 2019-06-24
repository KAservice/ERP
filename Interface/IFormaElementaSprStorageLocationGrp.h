#ifndef UIFormaElementaSprStorageLocationGrpH
#define UIFormaElementaSprStorageLocationGrpH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprStorageLocationGrp.h"
class __declspec(uuid(Global_IID_IFormaElementaSprStorageLocationGrp)) IFormaElementaSprStorageLocationGrp : public IMainInterface
{
public:
   __property IDMSprStorageLocationGrp* DM = {read = get_DM , write = set_DM};
   virtual IDMSprStorageLocationGrp* get_DM(void)=0;
   virtual void set_DM(IDMSprStorageLocationGrp* DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

};
#define IID_IFormaElementaSprStorageLocationGrp __uuidof(IFormaElementaSprStorageLocationGrp)
#endif
