#ifndef UIFormaSpiskaSprPropertiesNaborSostavH
#define UIFormaSpiskaSprPropertiesNaborSostavH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprPropertiesNaborSostav.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprPropertiesNaborSostav)) IFormaSpiskaSprPropertiesNaborSostav : public IMainInterface
{
public:
   __property IDMSprPropertiesNaborSostav * DM = {read = get_DM , write = set_DM};
   virtual IDMSprPropertiesNaborSostav * get_DM(void)=0;
   virtual void set_DM(IDMSprPropertiesNaborSostav * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdNabor = {read = get_IdNabor , write = set_IdNabor};
   virtual __int64 get_IdNabor(void)=0;
   virtual void set_IdNabor(__int64 IdNabor)=0;

   __property UnicodeString HeaderText = {read = get_HeaderText , write = set_HeaderText};
   virtual UnicodeString get_HeaderText(void)=0;
   virtual void set_HeaderText(UnicodeString HeaderText)=0;

   virtual void UpdateForm()=0;
};
#define IID_IFormaSpiskaSprPropertiesNaborSostav __uuidof(IFormaSpiskaSprPropertiesNaborSostav)
#endif
