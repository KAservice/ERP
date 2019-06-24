#ifndef UIREM_FormaElementaSprModel2GrpH
#define UIREM_FormaElementaSprModel2GrpH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMSprModel2Grp.h"
class __declspec(uuid(Global_IID_IREM_FormaElementaSprModel2Grp)) IREM_FormaElementaSprModel2Grp : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IREM_DMSprModel2Grp* DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprModel2Grp* get_DM(void)=0;
   virtual void set_DM(IREM_DMSprModel2Grp* DM)=0;

};
#define IID_IREM_FormaElementaSprModel2Grp __uuidof(IREM_FormaElementaSprModel2Grp)
#endif
