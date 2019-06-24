#ifndef UIFormaElementaSprGrpUserH
#define UIFormaElementaSprGrpUserH
#include "IMainInterface.h"
#include "IDMSprGrpUser.h"
class __declspec(uuid("{9A1A0E7A-84FE-4BBA-BBBB-885EBBD33493}")) IFormaElementaSprGrpUser : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMSprGrpUser* DM = {read = get_DM , write = set_DM};
   virtual IDMSprGrpUser* get_DM(void)=0;
   virtual void set_DM(IDMSprGrpUser* DM)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprGrpUser __uuidof(IFormaElementaSprGrpUser)
#endif
