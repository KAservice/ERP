#ifndef UIFormaElementaSprImportNomH
#define UIFormaElementaSprImportNomH
#include "IMainInterface.h"
#include "IDMSprImportNom.h"
class __declspec(uuid("{33BDF159-5914-4E15-AB86-09549C75AD3F}")) IFormaElementaSprImportNom : public IMainInterface
{
public:
   __property IDMSprImportNom * DM = {read = get_DM , write = set_DM};
   virtual IDMSprImportNom * get_DM(void)=0;
   virtual void set_DM(IDMSprImportNom * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;


   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprImportNom __uuidof(IFormaElementaSprImportNom)
#endif
