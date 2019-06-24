#ifndef UIFormaElementaSprKKMH
#define UIFormaElementaSprKKMH
#include "IMainInterface.h"
#include "IDMSprKKM.h"
class __declspec(uuid("{8AB43F62-8D1A-4FB4-9BDC-D1E3CA4D32C2}"))IFormaElementaSprKKM : public IMainInterface
{
public:
   __property IDMSprKKM * DM = {read = get_DM , write = set_DM};
   virtual IDMSprKKM * get_DM(void)=0;
   virtual void set_DM(IDMSprKKM * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprKKM __uuidof(IFormaElementaSprKKM)
#endif
