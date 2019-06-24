#ifndef UIFormaElementaSprGrpVesNomH
#define UIFormaElementaSprGrpVesNomH
#include "IMainInterface.h"
#include "IDMSprGrpVesNom.h"
class __declspec(uuid("{EFBF4CE1-F397-4D1B-B53C-CE31C7CE3864}")) IFormaElementaSprGrpVesNom : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMSprGrpVesNom* DM = {read = get_DM , write = set_DM};
   virtual IDMSprGrpVesNom* get_DM(void)=0;
   virtual void set_DM(IDMSprGrpVesNom* DM)=0;

};
#define IID_IFormaElementaSprGrpVesNom __uuidof(IFormaElementaSprGrpVesNom)
#endif
