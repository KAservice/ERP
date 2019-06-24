#ifndef UIREM_FormaSpiskaSprDefectModelNeisprH
#define UIREM_FormaSpiskaSprDefectModelNeisprH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMSprDefectModelNeispr.h"
class __declspec(uuid(Global_IID_IREM_FormaSpiskaSprDefectModelNeispr)) IREM_FormaSpiskaSprDefectModelNeispr : public IMainInterface
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

   __property IREM_DMSprDefectModelNeispr * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprDefectModelNeispr * get_DM(void)=0;
   virtual void set_DM(IREM_DMSprDefectModelNeispr * DM)=0;

   __property __int64 IdModelNeispr = {read = get_IdModelNeispr , write = set_IdModelNeispr};
   virtual __int64 get_IdModelNeispr(void)=0;
   virtual void set_IdModelNeispr(__int64 IdModelNeispr)=0;

   __property UnicodeString TextMessage = {read = get_TextMessage , write = set_TextMessage};
   virtual UnicodeString get_TextMessage(void)=0;
   virtual void set_TextMessage(UnicodeString TextMessage)=0;

   virtual void UpdateForm()=0;
};
#define IID_IREM_FormaSpiskaSprDefectModelNeispr __uuidof(IREM_FormaSpiskaSprDefectModelNeispr)
#endif
