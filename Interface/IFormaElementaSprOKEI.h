#ifndef UIFormaElementaSprOKEIH
#define UIFormaElementaSprOKEIH
#include "IMainInterface.h"
#include "IDMSprOKEI.h"
class __declspec(uuid("{F81AC188-54CE-4DD5-8A35-3CEF7A12A1E2}"))IFormaElementaSprOKEI : public IMainInterface
{
public:
   __property IDMSprOKEI * DM = {read = get_DM , write = set_DM};
   virtual IDMSprOKEI * get_DM(void)=0;
   virtual void set_DM(IDMSprOKEI * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

};
#define IID_IFormaElementaSprOKEI __uuidof(IFormaElementaSprOKEI)
#endif
