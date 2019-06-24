#ifndef UIFormaElementaSprARMH
#define UIFormaElementaSprARMH
#include "IMainInterface.h"
#include "IDMSprARM.h"
class __declspec(uuid("{D24EB7CB-E18C-4ED1-A204-F60F016AA216}")) IFormaElementaSprARM : public IMainInterface
{
public:
   __property IDMSprARM * DM = {read = get_DM , write = set_DM};
   virtual IDMSprARM * get_DM(void)=0;
   virtual void set_DM(IDMSprARM * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;


   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprARM __uuidof(IFormaElementaSprARM)
#endif
