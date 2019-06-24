#ifndef UIFormaElementaSprKlientH
#define UIFormaElementaSprKlientH
#include "IMainInterface.h"
#include "IDMSprKlient.h"
class __declspec(uuid("{96C36600-9261-4E20-B61D-781C928264E0}"))IFormaElementaSprKlient : public IMainInterface
{
public:
   __property IDMSprKlient * DM = {read = get_DM , write = set_DM};
   virtual IDMSprKlient * get_DM(void)=0;
   virtual void set_DM(IDMSprKlient * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprKlient __uuidof(IFormaElementaSprKlient)
#endif
