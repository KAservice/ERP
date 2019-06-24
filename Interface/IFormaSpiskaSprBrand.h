#ifndef UIFormaSpiskaSprBrandH
#define UIFormaSpiskaSprBrandH
#include "IMainInterface.h"
#include "IDMSprBrand.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprBrand)) IFormaSpiskaSprBrand : public IMainInterface
{
public:
   __property IDMSprBrand * DM = {read = get_DM , write = set_DM};
   virtual IDMSprBrand * get_DM(void)=0;
   virtual void set_DM(IDMSprBrand * DM)=0;

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
#define IID_IFormaSpiskaSprBrand __uuidof(IFormaSpiskaSprBrand)
#endif
