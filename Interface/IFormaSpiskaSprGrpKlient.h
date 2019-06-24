#ifndef UIFormaSpiskaSprGrpKlientH
#define UIFormaSpiskaSprGrpKlientH
#include "IMainInterface.h"
#include "IDMSprGrpKlient.h"
class __declspec(uuid("{E6ED94E5-413C-4F2F-8530-0AA378EEAAB3}")) IFormaSpiskaSprGrpKlient : public IMainInterface
{
public:
   __property IDMSprGrpKlient * DM = {read = get_DM , write = set_DM};
   virtual IDMSprGrpKlient * get_DM(void)=0;
   virtual void set_DM(IDMSprGrpKlient * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

};
#define IID_IFormaSpiskaSprGrpKlient __uuidof(IFormaSpiskaSprGrpKlient)
#endif
