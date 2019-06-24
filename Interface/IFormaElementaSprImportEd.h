#ifndef UIFormaElementaSprImportEdH
#define UIFormaElementaSprImportEdH
#include "IMainInterface.h"
#include "IDMSprImportEd.h"
class __declspec(uuid("{54AB63DC-04E2-4930-BBE7-1A36B9159AF2}")) IFormaElementaSprImportEd : public IMainInterface
{
public:
   __property IDMSprImportEd * DM = {read = get_DM , write = set_DM};
   virtual IDMSprImportEd * get_DM(void)=0;
   virtual void set_DM(IDMSprImportEd * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprImportEd __uuidof(IFormaElementaSprImportEd)
#endif
