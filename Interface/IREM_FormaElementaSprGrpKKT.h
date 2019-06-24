#ifndef UIREM_FormaElementaSprGrpKKTH
#define UIREM_FormaElementaSprGrpKKTH
#include "IMainInterface.h"
#include "IREM_DMSprGrpKKT.h"
class __declspec(uuid("{1B7CF0DA-F17A-42F4-8F6D-AE90560CD90C}")) IREM_FormaElementaSprGrpKKT : public IMainInterface
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

   __property IREM_DMSprGrpKKT * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprGrpKKT * get_DM(void)=0;
   virtual void set_DM(IREM_DMSprGrpKKT * DM)=0;

};
#define IID_IREM_FormaElementaSprGrpKKT __uuidof(IREM_FormaElementaSprGrpKKT)
#endif
