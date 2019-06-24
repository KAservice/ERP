#ifndef UIFormaElementaSprGrpNomH
#define UIFormaElementaSprGrpNomH
#include "IMainInterface.h"
#include "IDMSprGrpNom.h"
class __declspec(uuid("{EC6C21C4-F4BD-426F-B01A-36821FFE6CB7}")) IFormaElementaSprGrpNom : public IMainInterface
{
public:
   __property IDMSprGrpNom* DM = {read = get_DM , write = set_DM};
   virtual IDMSprGrpNom* get_DM(void)=0;
   virtual void set_DM(IDMSprGrpNom* DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;


};
#define IID_IFormaElementaSprGrpNom __uuidof(IFormaElementaSprGrpNom)
#endif
