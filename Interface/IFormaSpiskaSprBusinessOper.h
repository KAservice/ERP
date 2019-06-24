#ifndef UIFormaSpiskaSprBusinessOperH
#define UIFormaSpiskaSprBusinessOperH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprBusinessOper.h"
#include "IDMSprGrpBusinessOper.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprBusinessOper)) IFormaSpiskaSprBusinessOper : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMSprBusinessOper* DM = {read = get_DM , write = set_DM};
   virtual IDMSprBusinessOper* get_DM(void)=0;
   virtual void set_DM(IDMSprBusinessOper* DM)=0;

   __property IDMSprGrpBusinessOper * DMGrp = {read = get_DMGrp , write = set_DMGrp};
   virtual IDMSprGrpBusinessOper * get_DMGrp(void)=0;
   virtual void set_DMGrp(IDMSprGrpBusinessOper * DMGrp)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property bool Podbor = {read = get_Podbor , write = set_Podbor};
   virtual bool get_Podbor(void)=0;
   virtual void set_Podbor(bool Podbor)=0;

   __property UnicodeString HeaderText = {read = get_HeaderText , write = set_HeaderText};
   virtual UnicodeString get_HeaderText(void)=0;
   virtual void set_HeaderText(UnicodeString HeaderText)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaSpiskaSprBusinessOper __uuidof(IFormaSpiskaSprBusinessOper)
#endif
