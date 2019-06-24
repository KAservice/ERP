#ifndef UIFormaSpiskaSprProgramModuleH
#define UIFormaSpiskaSprProgramModuleH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprProgramModule.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprProgramModule)) IFormaSpiskaSprProgramModule : public IMainInterface
{
public:
   __property IDMSprProgramModule * DM = {read = get_DM , write = set_DM};
   virtual IDMSprProgramModule * get_DM(void)=0;
   virtual void set_DM(IDMSprProgramModule * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void OpenFormElement()=0;
   virtual void OpenFormNewElement()=0;
   virtual void DeleteElement()=0;
};
#define IID_IFormaSpiskaSprProgramModule __uuidof(IFormaSpiskaSprProgramModule)
#endif
