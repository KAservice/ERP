#ifndef UIFormaElementaSprEdH
#define UIFormaElementaSprEdH
#include "IMainInterface.h"
#include "IDMSprEd.h"
class __declspec(uuid("{EA29EC3B-8EDB-4783-ACF1-3A75173585BB}"))IFormaElementaSprEd : public IMainInterface
{
public:
   __property IDMSprEd * DM = {read = get_DM , write = set_DM};
   virtual IDMSprEd * get_DM(void)=0;
   virtual void set_DM(IDMSprEd * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprEd __uuidof(IFormaElementaSprEd)
#endif
