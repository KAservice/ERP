#ifndef UIFormaElementaSprProgramModuleH
#define UIFormaElementaSprProgramModuleH
#include "IMainInterface.h"
#include "IDMSprProgramModule.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaElementaSprProgramModule))IFormaElementaSprProgramModule : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMSprProgramModule * DM = {read = get_DM , write = set_DM};
   virtual IDMSprProgramModule * get_DM(void)=0;
   virtual void set_DM(IDMSprProgramModule * DM)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprProgramModule __uuidof(IFormaElementaSprProgramModule)
#endif
