#ifndef UIFormaElementaObjectBaseGrpH
#define UIFormaElementaObjectBaseGrpH
#include "IMainInterface.h"
#include "IDMObjectBaseGrp.h"
class __declspec(uuid("{485BC038-39AC-436E-A133-2FFCDB60FC01}")) IFormaElementaObjectBaseGrp : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMObjectBaseGrp* DM = {read = get_DM , write = set_DM};
   virtual IDMObjectBaseGrp* get_DM(void)=0;
   virtual void set_DM(IDMObjectBaseGrp* DM)=0;

};
#define IID_IFormaElementaObjectBaseGrp __uuidof(IFormaElementaObjectBaseGrp)
#endif
