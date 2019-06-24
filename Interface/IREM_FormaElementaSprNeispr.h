#ifndef UIREM_FormaElementaSprNeisprH
#define UIREM_FormaElementaSprNeisprH
#include "IMainInterface.h"
#include "IREM_DMSprNeispr.h"
class __declspec(uuid("{C01981A3-4772-4983-B5B0-3310B6C6C413}")) IREM_FormaElementaSprNeispr : public IMainInterface
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

   __property IREM_DMSprNeispr * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprNeispr * get_DM(void)=0;
   virtual void set_DM(IREM_DMSprNeispr * DM)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IREM_FormaElementaSprNeispr __uuidof(IREM_FormaElementaSprNeispr)
#endif
