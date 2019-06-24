#ifndef UIHOT_FormaElementaSprObjectH
#define UIHOT_FormaElementaSprObjectH
#include "IMainInterface.h"
#include "IHOT_DMSprObject.h"
class __declspec(uuid("{CB306B1D-C3D6-47E8-B8B3-B90AB8A59440}")) IHOT_FormaElementaSprObject : public IMainInterface
{
public:
   __property IHOT_DMSprObject * DM = {read = get_DM , write = set_DM};
   virtual IHOT_DMSprObject * get_DM(void)=0;
   virtual void set_DM(IHOT_DMSprObject * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IHOT_FormaElementaSprObject __uuidof(IHOT_FormaElementaSprObject)
#endif
