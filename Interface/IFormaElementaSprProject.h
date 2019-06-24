#ifndef UIFormaElementaSprProjectH
#define UIFormaElementaSprProjectH
#include "IMainInterface.h"
#include "IDMSprProject.h"
class __declspec(uuid("{BC8E3CDF-4C4B-493C-A088-9F901115551E}"))IFormaElementaSprProject : public IMainInterface
{
public:
   __property IDMSprProject* DM = {read = get_DM , write = set_DM};
   virtual IDMSprProject* get_DM(void)=0;
   virtual void set_DM(IDMSprProject* DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprProject __uuidof(IFormaElementaSprProject)
#endif
