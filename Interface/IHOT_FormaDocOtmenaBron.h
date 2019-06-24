#ifndef UIHOT_FormaDocOtmenaBronH
#define UIHOT_FormaDocOtmenaBronH
#include "IMainInterface.h"
#include "IHOT_DMDocOtmenaBron.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IHOT_FormaDocOtmenaBron))IHOT_FormaDocOtmenaBron : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IHOT_DMDocOtmenaBron * DM = {read = get_DM , write = set_DM};
   virtual IHOT_DMDocOtmenaBron * get_DM(void)=0;
   virtual void set_DM(IHOT_DMDocOtmenaBron * DM)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IHOT_FormaDocOtmenaBron __uuidof(IHOT_FormaDocOtmenaBron)
#endif
