#ifndef UIFormaDocRKOH
#define UIFormaDocRKOH
#include "IMainInterface.h"
#include "IDMDocRKO.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaDocRKO)) IFormaDocRKO : public IMainInterface
{
public:
   __property IDMDocRKO * DM = {read = get_DM , write = set_DM};
   virtual IDMDocRKO * get_DM(void)=0;
   virtual void set_DM(IDMDocRKO * DM)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaDocRKO __uuidof(IFormaDocRKO)
#endif
