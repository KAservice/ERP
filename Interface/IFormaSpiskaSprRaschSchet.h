#ifndef UIFormaSpiskaSprRaschSchetH
#define UIFormaSpiskaSprRaschSchetH
#include "IMainInterface.h"
#include "IDMSprRaschSchet.h"
class __declspec(uuid("{168BFBC6-3B4A-4F1F-A4D3-04257F2B5A96}")) IFormaSpiskaSprRaschSchet : public IMainInterface
{
public:
   __property IDMSprRaschSchet * DM = {read = get_DM , write = set_DM};
   virtual IDMSprRaschSchet * get_DM(void)=0;
   virtual void set_DM(IDMSprRaschSchet * DM)=0;

   __property __int64 IdKlient = {read = get_IdKlient , write = set_IdKlient};
   virtual __int64 get_IdKlient(void)=0;
   virtual void set_IdKlient(__int64 IdKlient)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;


};
#define IID_IFormaSpiskaSprRaschSchet __uuidof(IFormaSpiskaSprRaschSchet)
#endif
