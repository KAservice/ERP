#ifndef UIFormaSpiskaSprCountryH
#define UIFormaSpiskaSprCountryH
#include "IMainInterface.h"
#include "IDMSprCountry.h"
class __declspec(uuid("{4979C12D-AF93-4C70-AA01-94C97884ED0D}")) IFormaSpiskaSprCountry : public IMainInterface
{
public:
   __property IDMSprCountry * DM = {read = get_DM , write = set_DM};
   virtual IDMSprCountry * get_DM(void)=0;
   virtual void set_DM(IDMSprCountry * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;


   virtual void OpenFormElement(void)=0;
   virtual void OpenFormNewElement(void)=0;
   virtual void DeleteElement(void)=0;
   virtual void UpdateForm(void)=0;
};
#define IID_IFormaSpiskaSprCountry __uuidof(IFormaSpiskaSprCountry)
#endif
