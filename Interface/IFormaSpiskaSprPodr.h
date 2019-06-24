#ifndef UIFormaSpiskaSprPodrH
#define UIFormaSpiskaSprPodrH
#include "IMainInterface.h"
#include "IDMSprPodr.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprPodr)) IFormaSpiskaSprPodr : public IMainInterface
{
public:
   __property IDMSprPodr * DM = {read = get_DM , write = set_DM};
   virtual IDMSprPodr * get_DM(void)=0;
   virtual void set_DM(IDMSprPodr * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

};
#define IID_IFormaSpiskaSprPodr __uuidof(IFormaSpiskaSprPodr)
#endif
