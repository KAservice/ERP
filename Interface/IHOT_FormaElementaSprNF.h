#ifndef UIHOT_FormaElementaSprNFH
#define UIHOT_FormaElementaSprNFH
#include "IMainInterface.h"
#include "IHOT_DMSprNF.h"
class __declspec(uuid("{4CF21FD1-B45D-4295-B2BB-08E1E2FC717A}")) IHOT_FormaElementaSprNF : public IMainInterface
{
public:
   __property IHOT_DMSprNF * DM = {read = get_DM , write = set_DM};
   virtual IHOT_DMSprNF * get_DM(void)=0;
   virtual void set_DM(IHOT_DMSprNF * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IHOT_FormaElementaSprNF __uuidof(IHOT_FormaElementaSprNF)
#endif
