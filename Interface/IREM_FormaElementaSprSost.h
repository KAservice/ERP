#ifndef UIREM_FormaElementaSprSostH
#define UIREM_FormaElementaSprSostH
#include "IMainInterface.h"
#include "IREM_DMSprSost.h"
class __declspec(uuid("{CE53CE79-21D7-4282-A953-199F3D1F72C3}"))IREM_FormaElementaSprSost : public IMainInterface
{
public:
   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IREM_DMSprSost * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprSost * get_DM(void)=0;
   virtual void set_DM(IREM_DMSprSost * DM)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IREM_FormaElementaSprSost __uuidof(IREM_FormaElementaSprSost)
#endif
