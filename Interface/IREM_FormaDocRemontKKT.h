#ifndef UIREM_FormaDocRemontKKTH
#define UIREM_FormaDocRemontKKTH
#include "IMainInterface.h"
#include "IREM_DMDocRemontKKT.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IREM_FormaDocRemontKKT)) IREM_FormaDocRemontKKT : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IREM_DMDocRemontKKT * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMDocRemontKKT * get_DM(void)=0;
   virtual void set_DM(IREM_DMDocRemontKKT * DM)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property __int64 VibTovarId = {read = get_VibTovarId , write = set_VibTovarId};
   virtual __int64 get_VibTovarId(void)=0;
   virtual void set_VibTovarId(__int64 VibTovarId)=0;

   __property __int64 VibTovarIdGrp = {read = get_VibTovarIdGrp , write = set_VibTovarIdGrp};
   virtual __int64 get_VibTovarIdGrp(void)=0;
   virtual void set_VibTovarIdGrp(__int64 VibTovarIdGrp)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IREM_FormaDocRemontKKT __uuidof(IREM_FormaDocRemontKKT)
#endif
