#ifndef UIREM_FormaDocProverkaH
#define UIREM_FormaDocProverkaH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMDocProverka.h"
class __declspec(uuid(Global_IID_IREM_FormaDocProverka)) IREM_FormaDocProverka : public IMainInterface
{
public:
   __property IREM_DMDocProverka * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMDocProverka * get_DM(void)=0;
   virtual void set_DM(IREM_DMDocProverka * DM)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property bool OutReady = {read = get_OutReady , write = set_OutReady};
   virtual bool get_OutReady(void)=0;
   virtual void set_OutReady(bool OutReady)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IREM_FormaDocProverka __uuidof(IREM_FormaDocProverka)
#endif
