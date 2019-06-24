#ifndef UIFormaInputDiscountCardH
#define UIFormaInputDiscountCardH
#include "IMainInterface.h"
class __declspec(uuid("{FBC96A44-F764-4040-B816-B649D99044BE}")) IFormaInputDiscountCard : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property UnicodeString InputText = {read = get_InputText , write = set_InputText};
   virtual UnicodeString get_InputText(void)=0;
   virtual void set_InputText(UnicodeString InputText)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

};
#define IID_IFormaInputDiscountCard __uuidof(IFormaInputDiscountCard)
#endif
