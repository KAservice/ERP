#ifndef UIFormaElementaSprStrObjectH
#define UIFormaElementaSprStrObjectH
#include "IMainInterface.h"
#include "IDMSprStrObject.h"
class __declspec(uuid("{ED08A965-6F05-4655-B50F-F90F79D6AF8D}"))IFormaElementaSprStrObject : public IMainInterface
{
public:
   __property IDMSprStrObject* DM = {read = get_DM , write = set_DM};
   virtual IDMSprStrObject* get_DM(void)=0;
   virtual void set_DM(IDMSprStrObject* DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;


};
#define IID_IFormaElementaSprStrObject __uuidof(IFormaElementaSprStrObject)
#endif
