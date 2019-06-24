#ifndef UIREM_FormaCustQueryDvH
#define UIREM_FormaCustQueryDvH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMCustQueryDv.h"
class __declspec(uuid(Global_IID_IREM_FormaCustQueryDv)) IREM_FormaCustQueryDv : public IMainInterface
{
public:
   __property IREM_DMCustQueryDv * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMCustQueryDv * get_DM(void)=0;
   virtual void set_DM(IREM_DMCustQueryDv * DM)=0;

   __property __int64 IdCQT = {read = get_IdCQT , write = set_IdCQT};
   virtual __int64 get_IdCQT(void)=0;
   virtual void set_IdCQT(__int64 IdCQT)=0;

   __property UnicodeString TextMessage = {read = get_TextMessage , write = set_TextMessage};
   virtual UnicodeString get_TextMessage(void)=0;
   virtual void set_TextMessage(UnicodeString TextMessage)=0;

   virtual void UpdateForm()=0;
};
#define IID_IREM_FormaCustQueryDv __uuidof(IREM_FormaCustQueryDv)
#endif
