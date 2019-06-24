#ifndef UIFormaElementaSprOborudH
#define UIFormaElementaSprOborudH
#include "IMainInterface.h"
#include "IDMSprOborud.h"
class __declspec(uuid("{7FF2F5D0-AA73-4FE7-BA87-924DB41280F9}")) IFormaElementaSprOborud : public IMainInterface
{
public:
   __property IDMSprOborud * DM = {read = get_DM , write = set_DM};
   virtual IDMSprOborud * get_DM(void)=0;
   virtual void set_DM(IDMSprOborud * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprOborud __uuidof(IFormaElementaSprOborud)
#endif
