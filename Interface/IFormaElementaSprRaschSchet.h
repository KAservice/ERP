#ifndef UIFormaElementaSprRaschSchetH
#define UIFormaElementaSprRaschSchetH
#include "IMainInterface.h"
#include "IDMSprRaschSchet.h"
class __declspec(uuid("{05A40473-8367-46FD-AECC-3BCE0E9D7886}")) IFormaElementaSprRaschSchet : public IMainInterface
{
public:
   __property IDMSprRaschSchet * DM = {read = get_DM , write = set_DM};
   virtual IDMSprRaschSchet * get_DM(void)=0;
   virtual void set_DM(IDMSprRaschSchet * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;



};
#define IID_IFormaElementaSprRaschSchet __uuidof(IFormaElementaSprRaschSchet)
#endif
