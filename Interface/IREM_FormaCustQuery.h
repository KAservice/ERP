#ifndef UIREM_FormaCustQueryH
#define UIREM_FormaCustQueryH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMCustQuery.h"
class __declspec(uuid(Global_IID_IREM_FormaCustQuery)) IREM_FormaCustQuery : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IREM_DMCustQuery * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMCustQuery * get_DM(void)=0;
   virtual void set_DM(IREM_DMCustQuery * DM)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property __int64 IdCQ = {read = get_IdCQ , write = set_IdCQ};
   virtual __int64 get_IdCQ(void)=0;
   virtual void set_IdCQ(__int64 IdCQ)=0;

   __property __int64 IdCQT = {read = get_IdCQT , write = set_IdCQT};
   virtual __int64 get_IdCQT(void)=0;
   virtual void set_IdCQT(__int64 IdCQT)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IREM_FormaCustQuery __uuidof(IREM_FormaCustQuery)
#endif
