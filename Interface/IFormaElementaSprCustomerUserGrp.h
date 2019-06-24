#ifndef UIFormaElementaSprCustomerUserGrpH
#define UIFormaElementaSprCustomerUserGrpH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprCustomerUserGrp.h"
class __declspec(uuid(Global_IID_IFormaElementaSprCustomerUserGrp)) IFormaElementaSprCustomerUserGrp : public IMainInterface
{
public:
   __property IDMSprCustomerUserGrp* DM = {read = get_DM , write = set_DM};
   virtual IDMSprCustomerUserGrp* get_DM(void)=0;
   virtual void set_DM(IDMSprCustomerUserGrp* DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property UnicodeString NameGrp = {read = get_NameGrp , write = set_NameGrp};
   virtual UnicodeString get_NameGrp(void)=0;
   virtual void set_NameGrp(UnicodeString NameGrp)=0;

   __property __int64 IdAccount = {read = get_IdAccount , write = set_IdAccount};
   virtual __int64 get_IdAccount(void)=0;
   virtual void set_IdAccount(__int64 IdAccount)=0;

   __property UnicodeString NameAccount = {read = get_NameAccount , write = set_NameAccount};
   virtual UnicodeString get_NameAccount(void)=0;
   virtual void set_NameAccount(UnicodeString NameAccount)=0;

};
#define IID_IFormaElementaSprCustomerUserGrp __uuidof(IFormaElementaSprCustomerUserGrp)
#endif
