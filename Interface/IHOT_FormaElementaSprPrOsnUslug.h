#ifndef UIHOT_FormaElementaSprPrOsnUslugH
#define UIHOT_FormaElementaSprPrOsnUslugH
#include "IMainInterface.h"
#include "IHOT_DMSprPrOsnUslug.h"
class __declspec(uuid("{60BA550D-E974-4194-8BCE-E16DAFD66387}")) IHOT_FormaElementaSprPrOsnUslug : public IMainInterface
{
public:
   __property IHOT_DMSprPrOsnUslug * DM = {read = get_DM , write = set_DM};
   virtual IHOT_DMSprPrOsnUslug * get_DM(void)=0;
   virtual void set_DM(IHOT_DMSprPrOsnUslug * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IHOT_FormaElementaSprPrOsnUslug __uuidof(IHOT_FormaElementaSprPrOsnUslug)
#endif
