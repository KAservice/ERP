#ifndef UIFormaElementaSprCountryH
#define UIFormaElementaSprCountryH
#include "IMainInterface.h"
#include "IDMSprCountry.h"
class __declspec(uuid("{C943019F-8224-49E4-A399-49A44E4DC255}")) IFormaElementaSprCountry : public IMainInterface
{
public:
   __property IDMSprCountry * DM = {read = get_DM , write = set_DM};
   virtual IDMSprCountry * get_DM(void)=0;
   virtual void set_DM(IDMSprCountry * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;


};
#define IID_IFormaElementaSprCountry __uuidof(IFormaElementaSprCountry)
#endif
