#ifndef UIFormaDocRevH
#define UIFormaDocRevH
#include "IMainInterface.h"
#include "IDMDocRev.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaDocRev)) IFormaDocRev : public IMainInterface
{
public:
   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property bool ObjectSave = {read = get_ObjectSave , write = set_ObjectSave};
   virtual bool get_ObjectSave(void)=0;
   virtual void set_ObjectSave(bool ObjectSave)=0;

   __property bool NoEdit = {read = get_NoEdit , write = set_NoEdit};
   virtual bool get_NoEdit(void)=0;
   virtual void set_NoEdit(bool NoEdit)=0;

   __property IDMDocRev * DM = {read = get_DM , write = set_DM};
   virtual IDMDocRev * get_DM(void)=0;
   virtual void set_DM(IDMDocRev * DM)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaDocRev __uuidof(IFormaDocRev)
#endif
