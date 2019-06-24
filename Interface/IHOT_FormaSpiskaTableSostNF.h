#ifndef UIHOT_FormaSpiskaTableSostNFH
#define UIHOT_FormaSpiskaTableSostNFH
#include "IMainInterface.h"
#include "IHOT_DMTableSostNF.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IHOT_FormaTableSostNF)) IHOT_FormaSpiskaTableSostNF : public IMainInterface
{
public:
   __property IHOT_DMTableSostNF * DM = {read = get_DM , write = set_DM};
   virtual IHOT_DMTableSostNF * get_DM(void)=0;
   virtual void set_DM(IHOT_DMTableSostNF * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IHOT_FormaSpiskaTableSostNF __uuidof(IHOT_FormaSpiskaTableSostNF)
#endif
