#ifndef UIFormaSpiskaSprOKEIH
#define UIFormaSpiskaSprOKEIH
#include "IMainInterface.h"
#include "IDMSprOKEI.h"
class __declspec(uuid("{F76563DE-AEAC-46AC-83B7-0BC6994FEF23}"))IFormaSpiskaSprOKEI : public IMainInterface
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

   virtual void OpenFormElement()=0;
   virtual void OpenFormNewElement()=0;
   virtual void DeleteElement()=0;
};
#define IID_IFormaSpiskaSprOKEI __uuidof(IFormaSpiskaSprOKEI)
#endif
