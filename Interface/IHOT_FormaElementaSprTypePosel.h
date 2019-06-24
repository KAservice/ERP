#ifndef UIHOT_FormaElementaSprTypePoselH
#define UIHOT_FormaElementaSprTypePoselH
#include "IMainInterface.h"
#include "IHOT_DMSprTypePosel.h"
class __declspec(uuid("{C00C2EC5-3699-4F59-9514-406F945495D3}"))IHOT_FormaElementaSprTypePosel : public IMainInterface
{
public:
   __property IHOT_DMSprTypePosel * DM = {read = get_DM , write = set_DM};
   virtual IHOT_DMSprTypePosel * get_DM(void)=0;
   virtual void set_DM(IHOT_DMSprTypePosel * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IHOT_FormaElementaSprTypePosel __uuidof(IHOT_FormaElementaSprTypePosel)
#endif
