#ifndef UIFormaSpiskaSprVidKlientH
#define UIFormaSpiskaSprVidKlientH
#include "IMainInterface.h"
#include "IDMSprVidKlient.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprVidKlient))IFormaSpiskaSprVidKlient : public IMainInterface
{
public:
   __property IDMSprVidKlient * DM = {read = get_DM , write = set_DM};
   virtual IDMSprVidKlient * get_DM(void)=0;
   virtual void set_DM(IDMSprVidKlient * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;


   virtual void UpdateForm(void)=0;
};
#define IID_IFormaSpiskaSprVidKlient __uuidof(IFormaSpiskaSprVidKlient)
#endif
