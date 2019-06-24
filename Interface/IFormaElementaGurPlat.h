#ifndef UIFormaElementaGurPlatH
#define UIFormaElementaGurPlatH
#include "IMainInterface.h"
#include "IDMGurPlat.h"
class __declspec(uuid("{1E06CED8-A29D-4DDC-A8DF-9C8EF4BD9421}"))IFormaElementaGurPlat
					: public IMainInterface
{
public:
   __property IDMGurPlat * DM = {read = get_DM , write = set_DM};
   virtual IDMGurPlat * get_DM(void)=0;
   virtual void set_DM(IDMGurPlat * DM)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaGurPlat __uuidof(IFormaElementaGurPlat)
#endif
