#ifndef UIFormaElementaSprPropertiesValuesListH
#define UIFormaElementaSprPropertiesValuesListH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprPropertiesValuesList.h"
class __declspec(uuid(Global_IID_IFormaElementaSprPropertiesValuesList)) IFormaElementaSprPropertiesValuesList : public IMainInterface
{
public:
   __property IDMSprPropertiesValuesList * DM = {read = get_DM , write = set_DM};
   virtual IDMSprPropertiesValuesList * get_DM(void)=0;
   virtual void set_DM(IDMSprPropertiesValuesList * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprPropertiesValuesList __uuidof(IFormaElementaSprPropertiesValuesList)
#endif
