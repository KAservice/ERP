#ifndef UIART_FormaSpiskaSprNaborInfBlockSostavH
#define UIART_FormaSpiskaSprNaborInfBlockSostavH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IART_DMSprNaborInfBlockSostav.h"

class __declspec(uuid(Global_IID_IART_FormaSpiskaSprNaborInfBlockSostav)) IART_FormaSpiskaSprNaborInfBlockSostav : public IMainInterface
{
public:
   __property IART_DMSprNaborInfBlockSostav* DM = {read = get_DM , write = set_DM};
   virtual IART_DMSprNaborInfBlockSostav* get_DM(void)=0;
   virtual void set_DM(IART_DMSprNaborInfBlockSostav* DM)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property bool Podbor = {read = get_Podbor , write = set_Podbor};
   virtual bool get_Podbor(void)=0;
   virtual void set_Podbor(bool Podbor)=0;

   __property __int64 IdGroupElement = {read = get_IdGroupElement , write = set_IdGroupElement};
   virtual __int64 get_IdGroupElement(void)=0;
   virtual void set_IdGroupElement(__int64 IdGroupElement)=0;

   __property UnicodeString NameGroupElement = {read = get_NameGroupElement , write = set_NameGroupElement};
   virtual UnicodeString get_NameGroupElement(void)=0;
   virtual void set_NameGroupElement(UnicodeString NameGroupElement)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   __property __int64 ViborIdOsnElement = {read = get_ViborIdOsnElement , write = set_ViborIdOsnElement};
   virtual __int64 get_ViborIdOsnElement(void)=0;
   virtual void set_ViborIdOsnElement(__int64 ViborIdOsnElement)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   virtual void DeleteElement()=0;
   virtual void UpdateForm(void)=0;
};
#define IID_IART_FormaSpiskaSprNaborInfBlockSostav __uuidof(IART_FormaSpiskaSprNaborInfBlockSostav)
#endif
