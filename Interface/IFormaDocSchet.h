#ifndef UIFormaDocSchetH
#define UIFormaDocSchetH
#include "IMainInterface.h"
#include "IDMDocSchet.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaDocSchet)) IFormaDocSchet : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMDocSchet * DM = {read = get_DM , write = set_DM};
   virtual IDMDocSchet * get_DM(void)=0;
   virtual void set_DM(IDMDocSchet * DM)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaDocSchet __uuidof(IFormaDocSchet)
#endif
