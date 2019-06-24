#ifndef UIFormaElementaSprPropertiesNaborH
#define UIFormaElementaSprPropertiesNaborH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprPropertiesNabor.h"
class __declspec(uuid(Global_IID_IFormaElementaSprPropertiesNabor)) IFormaElementaSprPropertiesNabor : public IMainInterface
{
public:
   __property IDMSprPropertiesNabor * DM = {read = get_DM , write = set_DM};
   virtual IDMSprPropertiesNabor * get_DM(void)=0;
   virtual void set_DM(IDMSprPropertiesNabor * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdGrpElement = {read = get_IdGrpElement , write = set_IdGrpElement};
   virtual __int64 get_IdGrpElement(void)=0;
   virtual void set_IdGrpElement(__int64 IdGrpElement)=0;

   __property UnicodeString NameGrp = {read = get_NameGrp , write = set_NameGrp};
   virtual UnicodeString get_NameGrp(void)=0;
   virtual void set_NameGrp(UnicodeString NameGrp)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprPropertiesNabor __uuidof(IFormaElementaSprPropertiesNabor)
#endif
