#ifndef UIREM_FormaSpiskaSprKKTDvH
#define UIREM_FormaSpiskaSprKKTDvH
#include "IMainInterface.h"
#include "IREM_DMSprKKTDv.h"
class __declspec(uuid("{B2113CEB-80D4-436A-9F1E-E7222ED8F427}")) IREM_FormaSpiskaSprKKTDv : public IMainInterface
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

   __property UnicodeString TextZayavka = {read = get_TextZayavka , write = set_TextZayavka};
   virtual UnicodeString get_TextZayavka(void)=0;
   virtual void set_TextZayavka(UnicodeString TextZayavka)=0;

   __property IREM_DMSprKKTDv * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprKKTDv * get_DM(void)=0;
   virtual void set_DM(IREM_DMSprKKTDv * DM)=0;

   __property __int64 IdOwner = {read = get_IdOwner , write = set_IdOwner};
   virtual __int64 get_IdOwner(void)=0;
   virtual void set_IdOwner(__int64 IdOwner)=0;

   virtual void UpdateForm()=0;
};
#define IID_IREM_FormaSpiskaSprKKTDv __uuidof(IREM_FormaSpiskaSprKKTDv)
#endif
