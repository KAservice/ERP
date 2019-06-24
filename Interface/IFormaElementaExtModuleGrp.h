#ifndef UIFormaElementaExtModuleGrpH
#define UIFormaElementaExtModuleGrpH
#include "IMainInterface.h"
#include "IDMExtModuleGrp.h"
class __declspec(uuid("{C91DDE9E-C164-43E0-8DFD-8C26E5DEFEBE}")) IFormaElementaExtModuleGrp : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMExtModuleGrp* DM = {read = get_DM , write = set_DM};
   virtual IDMExtModuleGrp* get_DM(void)=0;
   virtual void set_DM(IDMExtModuleGrp* DM)=0;

};
#define IID_IFormaElementaExtModuleGrp __uuidof(IFormaElementaExtModuleGrp)
#endif
