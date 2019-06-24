#ifndef UIFormaSpiskaSprNumTelH
#define UIFormaSpiskaSprNumTelH
#include "IMainInterface.h"
#include "IDMSprNumTel.h"
class __declspec(uuid("{0D09ACF6-921F-47DD-9D7B-354110B9B840}"))IFormaSpiskaSprNumTel : public IMainInterface
{
public:
   __property IDMSprNumTel * DM = {read = get_DM , write = set_DM};
   virtual IDMSprNumTel * get_DM(void)=0;
   virtual void set_DM(IDMSprNumTel * DM)=0;

   __property __int64 IdKlient = {read = get_IdKlient , write = set_IdKlient};
   virtual __int64 get_IdKlient(void)=0;
   virtual void set_IdKlient(__int64 IdKlient)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void OpenFormElement()=0;
   virtual void OpenFormNewElement()=0;
   virtual void DeleteElement()=0;
   virtual void UpdateForm()=0;
};
#define IID_IFormaSpiskaSprNumTel __uuidof(IFormaSpiskaSprNumTel)
#endif
