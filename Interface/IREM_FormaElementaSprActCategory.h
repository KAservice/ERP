#ifndef UIREM_FormaElementaSprActCategoryH
#define UIREM_FormaElementaSprActCategoryH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMSprActCategory.h"
class __declspec(uuid(Global_IID_IREM_FormaElementaSprActCategory)) IREM_FormaElementaSprActCategory : public IMainInterface
{
public:
   __property IREM_DMSprActCategory * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprActCategory * get_DM(void)=0;
   virtual void set_DM(IREM_DMSprActCategory * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

};
#define IID_IREM_FormaElementaSprActCategory __uuidof(IREM_FormaElementaSprActCategory)
#endif
