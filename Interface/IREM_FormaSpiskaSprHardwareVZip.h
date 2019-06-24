#ifndef UIREM_FormaSpiskaSprHardwareVZipH
#define UIREM_FormaSpiskaSprHardwareVZipH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMSprHardwareVZip.h"
#include "IREM_DMSprGrpHardware.h"
class __declspec(uuid(Global_IID_IREM_FormaSpiskaSprHardwareVZip)) IREM_FormaSpiskaSprHardwareVZip : public IMainInterface
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

   __property UnicodeString TextMessage = {read = get_TextMessage , write = set_TextMessage};
   virtual UnicodeString get_TextMessage(void)=0;
   virtual void set_TextMessage(UnicodeString TextMessage)=0;

   __property IREM_DMSprHardwareVZip* DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprHardwareVZip* get_DM(void)=0;
   virtual void set_DM(IREM_DMSprHardwareVZip* DM)=0;

   __property IREM_DMSprGrpHardware * DMGrp = {read = get_DMGrp , write = set_DMGrp};
   virtual IREM_DMSprGrpHardware * get_DMGrp(void)=0;
   virtual void set_DMGrp(IREM_DMSprGrpHardware * DMGrp)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdHardware = {read = get_IdHardware , write = set_IdHardware};
   virtual __int64 get_IdHardware(void)=0;
   virtual void set_IdHardware(__int64 IdHardware)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property bool Podbor = {read = get_Podbor , write = set_Podbor};
   virtual bool get_Podbor(void)=0;
   virtual void set_Podbor(bool Podbor)=0;

   __property UnicodeString SerNumber1 = {read = get_SerNumber1 , write = set_SerNumber1};
   virtual UnicodeString get_SerNumber1(void)=0;
   virtual void set_SerNumber1(UnicodeString SerNumber1)=0;

   __property UnicodeString SerNumber2 = {read = get_SerNumber2 , write = set_SerNumber2};
   virtual UnicodeString get_SerNumber2(void)=0;
   virtual void set_SerNumber2(UnicodeString SerNumber2)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IREM_FormaSpiskaSprHardwareVZip __uuidof(IREM_FormaSpiskaSprHardwareVZip)
#endif
