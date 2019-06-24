#ifndef UIFormaSpiskaSprInvH
#define UIFormaSpiskaSprInvH
#include "IMainInterface.h"
#include "IDMSprInv.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprInv)) IFormaSpiskaSprInv : public IMainInterface
{
public:
   __property IDMSprInv * DM = {read = get_DM , write = set_DM};
   virtual IDMSprInv * get_DM(void)=0;
   virtual void set_DM(IDMSprInv * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;


   virtual void OpenFormElement()=0;
   virtual void OpenFormNewElement()=0;
   virtual void DeleteElement()=0;
   virtual void UpdateForm(void)=0;
};
#define IID_IFormaSpiskaSprInv __uuidof(IFormaSpiskaSprInv)
#endif
