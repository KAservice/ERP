#ifndef UIREM_FormaElementaSprTypDefectGrpH
#define UIREM_FormaElementaSprTypDefectGrpH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMSprGrpTypDefect.h"
class __declspec(uuid(Global_IID_IREM_FormaElementaSprTypDefectGrp)) IREM_FormaElementaSprTypDefectGrp : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IREM_DMSprGrpTypDefect* DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprGrpTypDefect* get_DM(void)=0;
   virtual void set_DM(IREM_DMSprGrpTypDefect* DM)=0;

};
#define IID_IREM_FormaElementaSprTypDefectGrp __uuidof(IREM_FormaElementaSprTypDefectGrp)
#endif
