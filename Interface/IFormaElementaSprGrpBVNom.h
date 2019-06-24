#ifndef UIFormaElementaSprGrpBVNomH
#define UIFormaElementaSprGrpBVNomH
#include "IMainInterface.h"
#include "IDMSprGrpBVNom.h"
class __declspec(uuid("{56B43F49-AAB0-49BD-A4F9-87945499C749}")) IFormaElementaSprGrpBVNom : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMSprGrpBVNom* DM = {read = get_DM , write = set_DM};
   virtual IDMSprGrpBVNom* get_DM(void)=0;
   virtual void set_DM(IDMSprGrpBVNom* DM)=0;

};
#define IID_IFormaElementaSprGrpBVNom __uuidof(IFormaElementaSprGrpBVNom)
#endif
