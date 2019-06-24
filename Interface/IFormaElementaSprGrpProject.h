#ifndef UIFormaElementaSprGrpProjectH
#define UIFormaElementaSprGrpProjectH
#include "IMainInterface.h"
#include "IDMSprGrpProject.h"
class __declspec(uuid("{A9D26ADD-FCAB-4B5C-BE77-03EDA2004CFE}"))IFormaElementaSprGrpProject : public IMainInterface
{
public:
   __property IDMSprGrpProject* DM = {read = get_DM , write = set_DM};
   virtual IDMSprGrpProject* get_DM(void)=0;
   virtual void set_DM(IDMSprGrpProject* DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;


};
#define IID_IFormaElementaSprGrpProject __uuidof(IFormaElementaSprGrpProject)
#endif
