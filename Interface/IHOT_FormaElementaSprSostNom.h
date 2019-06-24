#ifndef UIHOT_FormaElementaSprSostNomH
#define UIHOT_FormaElementaSprSostNomH
#include "IMainInterface.h"
#include "IHOT_DMSprSostNom.h"
class __declspec(uuid("{54F81148-C293-41F2-B771-E50E59CE5287}")) IHOT_FormaElementaSprSostNom : public IMainInterface
{
public:
   __property IHOT_DMSprSostNom * DM = {read = get_DM , write = set_DM};
   virtual IHOT_DMSprSostNom * get_DM(void)=0;
   virtual void set_DM(IHOT_DMSprSostNom * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IHOT_FormaElementaSprSostNom __uuidof(IHOT_FormaElementaSprSostNom)
#endif
