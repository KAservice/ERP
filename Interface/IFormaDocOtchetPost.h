#ifndef UIFormaDocOtchetPostH
#define UIFormaDocOtchetPostH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMDocOtchetPost.h"
class __declspec(uuid(Global_IID_IFormaDocOtchetPost)) IFormaDocOtchetPost : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMDocOtchetPost * DM = {read = get_DM , write = set_DM};
   virtual IDMDocOtchetPost * get_DM(void)=0;
   virtual void set_DM(IDMDocOtchetPost * DM)=0;

   __property bool ObjectSave = {read = get_ObjectSave , write = set_ObjectSave};
   virtual bool get_ObjectSave(void)=0;
   virtual void set_ObjectSave(bool ObjectSave)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdElementaMaster = {read = get_IdElementaMaster , write = set_IdElementaMaster};
   virtual __int64 get_IdElementaMaster(void)=0;
   virtual void set_IdElementaMaster(__int64 IdElementaMaster)=0;

   __property __int64 VibTovarId = {read = get_VibTovarId , write = set_VibTovarId};
   virtual __int64 get_VibTovarId(void)=0;
   virtual void set_VibTovarId(__int64 VibTovarId)=0;

   __property __int64 VibTovarIdGrp = {read = get_VibTovarIdGrp , write = set_VibTovarIdGrp};
   virtual __int64 get_VibTovarIdGrp(void)=0;
   virtual void set_VibTovarIdGrp(__int64 VibTovarIdGrp)=0;

   virtual void UpdateForm(void)=0;
   virtual void ReadShtrihCodEvent(int number, UnicodeString sh)=0;
};
#define IID_IFormaDocOtchetPost __uuidof(IFormaDocOtchetPost)
#endif
