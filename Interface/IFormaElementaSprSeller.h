#ifndef UIFormaElementaSprSellerH
#define UIFormaElementaSprSellerH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprSeller.h"
class __declspec(uuid(Global_IID_IFormaElementaSprSeller)) IFormaElementaSprSeller : public IMainInterface
{
public:
   __property IDMSprSeller * DM = {read = get_DM , write = set_DM};
   virtual IDMSprSeller * get_DM(void)=0;
   virtual void set_DM(IDMSprSeller * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

};
#define IID_IFormaElementaSprSeller __uuidof(IFormaElementaSprSeller)
#endif
