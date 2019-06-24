#ifndef UIFormaInputCodeH
#define UIFormaInputCodeH
#include "IMainInterface.h"
class __declspec(uuid("{51901008-9C9B-40E9-81A0-DA3AD0A41C81}")) IFormaInputCode : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property int Code = {read = get_Code , write = set_Code};
   virtual int get_Code(void)=0;
   virtual void set_Code(int Code)=0;

   __property float Kol = {read = get_Kol , write = set_Kol};
   virtual float get_Kol(void)=0;
   virtual void set_Kol(float Kol)=0;

};
#define IID_IFormaInputCode __uuidof(IFormaInputCode)
#endif
