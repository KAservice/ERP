#ifndef UIHOT_FormaSpiskaSprNFH
#define UIHOT_FormaSpiskaSprNFH
#include "IMainInterface.h"
#include "IHOT_DMSprNF.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IHOT_FormaSpiskaSprNF))IHOT_FormaSpiskaSprNF : public IMainInterface
{
public:
   __property IHOT_DMSprNF * DM = {read = get_DM , write = set_DM};
   virtual IHOT_DMSprNF * get_DM(void)=0;
   virtual void set_DM(IHOT_DMSprNF * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

};
#define IID_IHOT_FormaSpiskaSprNF __uuidof(IHOT_FormaSpiskaSprNF)
#endif
