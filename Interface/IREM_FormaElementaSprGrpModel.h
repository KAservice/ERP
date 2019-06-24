#ifndef UIREM_FormaElementaSprGrpModelH
#define UIREM_FormaElementaSprGrpModelH
#include "IMainInterface.h"
#include "IREM_DMSprGrpModel.h"
class __declspec(uuid("{F6DC541D-8E88-4847-B366-6EC7E2BDE4C2}"))IREM_FormaElementaSprGrpModel : public IMainInterface
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

   __property IREM_DMSprGrpModel* DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprGrpModel* get_DM(void)=0;
   virtual void set_DM(IREM_DMSprGrpModel* DM)=0;

};
#define IID_IREM_FormaElementaSprGrpModel __uuidof(IREM_FormaElementaSprGrpModel)
#endif
