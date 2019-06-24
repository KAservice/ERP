#ifndef UIHOT_FormaElementaSprCatNomH
#define UIHOT_FormaElementaSprCatNomH
#include "IMainInterface.h"
#include "IHOT_DMSprCatNom.h"
class __declspec(uuid("{1C4A17B9-A071-47E7-8645-C82517EC2D03}")) IHOT_FormaElementaSprCatNom : public IMainInterface
{
public:
   __property IHOT_DMSprCatNom * DM = {read = get_DM , write = set_DM};
   virtual IHOT_DMSprCatNom * get_DM(void)=0;
   virtual void set_DM(IHOT_DMSprCatNom * DM)=0;

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
#define IID_IHOT_FormaElementaSprCatNom __uuidof(IHOT_FormaElementaSprCatNom)
#endif
