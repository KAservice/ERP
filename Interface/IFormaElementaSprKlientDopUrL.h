#ifndef UIFormaElementaSprKlientDopUrLH
#define UIFormaElementaSprKlientDopUrLH
#include "IMainInterface.h"
#include "IDMSprKlientDopUrL.h"
class __declspec(uuid("{8B268902-238B-4D3D-8ABF-1B4404FA9E9C}")) IFormaElementaSprKlientDopUrL : public IMainInterface
{
public:
   __property IDMSprKlientDopUrL * DM = {read = get_DM , write = set_DM};
   virtual IDMSprKlientDopUrL * get_DM(void)=0;
   virtual void set_DM(IDMSprKlientDopUrL * DM)=0;

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
#define IID_IFormaElementaSprKlientDopUrL __uuidof(IFormaElementaSprKlientDopUrL)
#endif
