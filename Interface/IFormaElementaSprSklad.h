#ifndef UIFormaElementaSprSkladH
#define UIFormaElementaSprSkladH
#include "IMainInterface.h"
#include "IDMSprSklad.h"
class __declspec(uuid("{F909223F-F187-4EE7-834F-1D06F0976CA4}")) IFormaElementaSprSklad : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMSprSklad * DM = {read = get_DM , write = set_DM};
   virtual IDMSprSklad * get_DM(void)=0;
   virtual void set_DM(IDMSprSklad * DM)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprSklad __uuidof(IFormaElementaSprSklad)
#endif
