#ifndef UIREM_FormaZayavkaDvH
#define UIREM_FormaZayavkaDvH
#include "IMainInterface.h"
#include "IREM_DMZayavkaDv.h"
class __declspec(uuid("{37DF2939-1600-4B5A-8B51-9C08C35A5063}")) IREM_FormaZayavkaDv : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IREM_DMZayavkaDv * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMZayavkaDv * get_DM(void)=0;
   virtual void set_DM(IREM_DMZayavkaDv * DM)=0;

   __property __int64 IdZ = {read = get_IdZ , write = set_IdZ};
   virtual __int64 get_IdZ(void)=0;
   virtual void set_IdZ(__int64 IdZ)=0;

   __property UnicodeString TextMessage = {read = get_TextMessage , write = set_TextMessage};
   virtual UnicodeString get_TextMessage(void)=0;
   virtual void set_TextMessage(UnicodeString TextMessage)=0;

   virtual void UpdateForm()=0;
};
#define IID_IREM_FormaZayavkaDv __uuidof(IREM_FormaZayavkaDv)
#endif
