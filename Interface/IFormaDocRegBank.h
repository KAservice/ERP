#ifndef UIFormaDocRegBankH
#define UIFormaDocRegBankH
#include "IMainInterface.h"
#include "IDMDocRegBank.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaDocRegBank)) IFormaDocRegBank : public IMainInterface
{
public:
   __property IDMDocRegBank * DM = {read = get_DM , write = set_DM};
   virtual IDMDocRegBank * get_DM(void)=0;
   virtual void set_DM(IDMDocRegBank * DM)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaDocRegBank __uuidof(IFormaDocRegBank)
#endif
