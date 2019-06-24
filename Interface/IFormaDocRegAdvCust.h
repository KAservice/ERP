#ifndef UIFormaDocRegAdvCustH
#define UIFormaDocRegAdvCustH
#include "IMainInterface.h"
#include "IDMDocRegAdvCust.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaDocRegAdvCust)) IFormaDocRegAdvCust : public IMainInterface
{
public:
   __property IDMDocRegAdvCust * DM = {read = get_DM , write = set_DM};
   virtual IDMDocRegAdvCust * get_DM(void)=0;
   virtual void set_DM(IDMDocRegAdvCust * DM)=0;

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
#define IID_IFormaDocRegAdvCust __uuidof(IFormaDocRegAdvCust)
#endif
