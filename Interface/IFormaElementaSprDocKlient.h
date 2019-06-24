#ifndef UIFormaElementaSprDocKlientH
#define UIFormaElementaSprDocKlientH
#include "IMainInterface.h"
#include "IDMSprDocKlient.h"
class __declspec(uuid("{39D3A231-61A1-450D-9520-408BB425835F}"))IFormaElementaSprDocKlient : public IMainInterface
{
public:
   __property IDMSprDocKlient * DM = {read = get_DM , write = set_DM};
   virtual IDMSprDocKlient * get_DM(void)=0;
   virtual void set_DM(IDMSprDocKlient * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprDocKlient __uuidof(IFormaElementaSprDocKlient)
#endif
