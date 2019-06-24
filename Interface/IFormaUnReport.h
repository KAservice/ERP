#ifndef UIFormaUnReportH
#define UIFormaUnReportH
#include "UGlobalConstant.h"
#include "IkasDM.h"
#include "IkasForm.h"
class __declspec(uuid(Global_IID_IFormaUnReport)) IFormaUnReport : public IkasForm
{
public:
   __property IkasDM * DM = {read = get_DM , write = set_DM};
   virtual IkasDM * get_DM(void)=0;
   virtual void set_DM(IkasDM * DM)=0;

   __property __int64 IdHw = {read = get_IdHw , write = set_IdHw};
   virtual __int64 get_IdHw(void)=0;
   virtual void set_IdHw(__int64 IdHw)=0;

   __property UnicodeString NameHardware = {read = get_NameHardware , write = set_NameHardware};
   virtual UnicodeString get_NameHardware(void)=0;
   virtual void set_NameHardware(UnicodeString NameHardware)=0;

};
#define IID_IFormaUnReport __uuidof(IFormaUnReport)
#endif
