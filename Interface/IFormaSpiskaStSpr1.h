#ifndef UIFormaSpiskaStSpr1H
#define UIFormaSpiskaStSpr1H
#include "IMainInterface.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaSpiskaStSpr1)) IFormaSpiskaStSpr1 : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual bool CreateObject(UnicodeString name_object)=0;
};
#define IID_IFormaSpiskaStSpr1 __uuidof(IFormaSpiskaStSpr1)
#endif
