#ifndef UIREM_FormaElementaSprKKTH
#define UIREM_FormaElementaSprKKTH
#include "IMainInterface.h"
#include "IREM_DMSprKKT.h"
class __declspec(uuid("{A7E01ABD-CE21-42B3-8BC0-802C8B4D2939}")) IREM_FormaElementaSprKKT : public IMainInterface
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

   __property IREM_DMSprKKT * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprKKT * get_DM(void)=0;
   virtual void set_DM(IREM_DMSprKKT * DM)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IREM_FormaElementaSprKKT __uuidof(IREM_FormaElementaSprKKT)
#endif
