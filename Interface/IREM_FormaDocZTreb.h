#ifndef UIREM_FormaDocZTrebH
#define UIREM_FormaDocZTrebH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMDocZTreb.h"
class __declspec(uuid(Global_IID_IREM_FormaDocZTreb)) IREM_FormaDocZTreb : public IMainInterface
{
public:
   __property IREM_DMDocZTreb * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMDocZTreb * get_DM(void)=0;
   virtual void set_DM(IREM_DMDocZTreb * DM)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property bool OutReady = {read = get_OutReady , write = set_OutReady};
   virtual bool get_OutReady(void)=0;
   virtual void set_OutReady(bool OutReady)=0;

   __property __int64 VibTovarId = {read = get_VibTovarId , write = set_VibTovarId};
   virtual __int64 get_VibTovarId(void)=0;
   virtual void set_VibTovarId(__int64 VibTovarId)=0;

   __property __int64 VibTovarIdGrp = {read = get_VibTovarIdGrp , write = set_VibTovarIdGrp};
   virtual __int64 get_VibTovarIdGrp(void)=0;
   virtual void set_VibTovarIdGrp(__int64 VibTovarIdGrp)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IREM_FormaDocZTreb __uuidof(IREM_FormaDocZTreb)
#endif
