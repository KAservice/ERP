#ifndef UIFormaElementaSprKlientDopFisLH
#define UIFormaElementaSprKlientDopFisLH
#include "IMainInterface.h"
#include "IDMSprKlientDopFisL.h"
class __declspec(uuid("{070E3966-B7D4-4FA1-88C4-5039F5B36484}"))IFormaElementaSprKlientDopFisL : public IMainInterface
{
public:
   __property IDMSprKlientDopFisL * DM = {read = get_DM , write = set_DM};
   virtual IDMSprKlientDopFisL * get_DM(void)=0;
   virtual void set_DM(IDMSprKlientDopFisL * DM)=0;

   __property UnicodeString NameKlient = {read = get_NameKlient , write = set_NameKlient};
   virtual UnicodeString get_NameKlient(void)=0;
   virtual void set_NameKlient(UnicodeString NameKlient)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprKlientDopFisL __uuidof(IFormaElementaSprKlientDopFisL)
#endif
