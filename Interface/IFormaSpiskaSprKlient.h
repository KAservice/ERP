#ifndef UIFormaSpiskaSprKlientH
#define UIFormaSpiskaSprKlientH
#include "IMainInterface.h"
#include "IDMSprKlient.h"
#include "IDMSprGrpKlient.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprKlient)) IFormaSpiskaSprKlient : public IMainInterface
{
public:
   __property IDMSprKlient* DM = {read = get_DM , write = set_DM};
   virtual IDMSprKlient* get_DM(void)=0;
   virtual void set_DM(IDMSprKlient* DM)=0;

   __property IDMSprGrpKlient * DMGrp = {read = get_DMGrp , write = set_DMGrp};
   virtual IDMSprGrpKlient * get_DMGrp(void)=0;
   virtual void set_DMGrp(IDMSprGrpKlient * DMGrp)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdKlient = {read = get_IdKlient , write = set_IdKlient};
   virtual __int64 get_IdKlient(void)=0;
   virtual void set_IdKlient(__int64 IdKlient)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaSpiskaSprKlient __uuidof(IFormaSpiskaSprKlient)
#endif
