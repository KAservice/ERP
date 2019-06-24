#ifndef UIFormaDocRasborkaKomplH
#define UIFormaDocRasborkaKomplH
#include "IMainInterface.h"
#include "IDMDocRasborkaKompl.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaDocRasborkaKompl)) IFormaDocRasborkaKompl : public IMainInterface
{
public:
   __property IDMDocRasborkaKompl * DM = {read = get_DM , write = set_DM};
   virtual IDMDocRasborkaKompl * get_DM(void)=0;
   virtual void set_DM(IDMDocRasborkaKompl * DM)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 VibTovarId = {read = get_VibTovarId , write = set_VibTovarId};
   virtual __int64 get_VibTovarId(void)=0;
   virtual void set_VibTovarId(__int64 VibTovarId)=0;

   __property __int64 VibTovarIdGrp = {read = get_VibTovarIdGrp , write = set_VibTovarIdGrp};
   virtual __int64 get_VibTovarIdGrp(void)=0;
   virtual void set_VibTovarIdGrp(__int64 VibTovarIdGrp)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaDocRasborkaKompl __uuidof(IFormaDocRasborkaKompl)
#endif
