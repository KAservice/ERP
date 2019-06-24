#ifndef UIKalkulatorH
#define UIKalkulatorH
#include "IMainInterface.h"
class __declspec(uuid("{804D65E7-4370-4D15-9C02-1CF83F843DC4}")) IKalkulator : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property double Result = {read = get_Result , write = set_Result};
   virtual double get_Result(void)=0;
   virtual void set_Result(double Result)=0;

};
#define IID_IKalkulator __uuidof(IKalkulator)
#endif
