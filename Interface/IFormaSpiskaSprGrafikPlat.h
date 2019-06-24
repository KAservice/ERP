#ifndef UIFormaSpiskaSprGrafikPlatH
#define UIFormaSpiskaSprGrafikPlatH
#include "IMainInterface.h"
#include "IDMSprGrafikPlat.h"
class __declspec(uuid("{A246B40D-D09C-4CA3-BC8E-44D528B193F9}")) IFormaSpiskaSprGrafikPlat : public IMainInterface
{
public:
   __property IDMSprGrafikPlat * DM = {read = get_DM , write = set_DM};
   virtual IDMSprGrafikPlat * get_DM(void)=0;
   virtual void set_DM(IDMSprGrafikPlat * DM)=0;

   __property __int64 IdDogovor = {read = get_IdDogovor , write = set_IdDogovor};
   virtual __int64 get_IdDogovor(void)=0;
   virtual void set_IdDogovor(__int64 IdDogovor)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void DeleteElement()=0;
};
#define IID_IFormaSpiskaSprGrafikPlat __uuidof(IFormaSpiskaSprGrafikPlat)
#endif
