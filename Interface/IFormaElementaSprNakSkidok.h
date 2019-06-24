#ifndef UIFormaElementaSprNakSkidokH
#define UIFormaElementaSprNakSkidokH
#include "IMainInterface.h"
#include "IDMSprNakSkidok.h"
class __declspec(uuid("{B0C35C82-C5E6-464A-A976-BDC8292BF854}")) IFormaElementaSprNakSkidok : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMSprNakSkidok * DM = {read = get_DM , write = set_DM};
   virtual IDMSprNakSkidok * get_DM(void)=0;
   virtual void set_DM(IDMSprNakSkidok * DM)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprNakSkidok __uuidof(IFormaElementaSprNakSkidok)
#endif
