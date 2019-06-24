#ifndef UIFormaSpiskaSprPropertiesValuesListH
#define UIFormaSpiskaSprPropertiesValuesListH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprPropertiesValuesList.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprPropertiesValuesList)) IFormaSpiskaSprPropertiesValuesList : public IMainInterface
{
public:
   __property IDMSprPropertiesValuesList * DM = {read = get_DM , write = set_DM};
   virtual IDMSprPropertiesValuesList * get_DM(void)=0;
   virtual void set_DM(IDMSprPropertiesValuesList * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdProp = {read = get_IdProp , write = set_IdProp};
   virtual __int64 get_IdProp(void)=0;
   virtual void set_IdProp(__int64 IdProp)=0;

   __property UnicodeString HeaderText = {read = get_HeaderText , write = set_HeaderText};
   virtual UnicodeString get_HeaderText(void)=0;
   virtual void set_HeaderText(UnicodeString HeaderText)=0;

   virtual void UpdateForm()=0;
};
#define IID_IFormaSpiskaSprPropertiesValuesList __uuidof(IFormaSpiskaSprPropertiesValuesList)
#endif
