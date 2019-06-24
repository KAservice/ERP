#ifndef UIFormaElementaSprBrandH
#define UIFormaElementaSprBrandH
#include "IMainInterface.h"
#include "IDMSprBrand.h"
class __declspec(uuid("{7F85141D-9A3C-4EFC-BF8B-181D22249858}")) IFormaElementaSprBrand : public IMainInterface
{
public:
   __property IDMSprBrand * DM = {read = get_DM , write = set_DM};
   virtual IDMSprBrand * get_DM(void)=0;
   virtual void set_DM(IDMSprBrand * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;


};
#define IID_IFormaElementaSprBrand __uuidof(IFormaElementaSprBrand)
#endif
