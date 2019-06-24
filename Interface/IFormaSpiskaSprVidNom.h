#ifndef UIFormaSpiskaSprVidNomH
#define UIFormaSpiskaSprVidNomH
#include "IMainInterface.h"
#include "IDMSprVidNom.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprVidNom))IFormaSpiskaSprVidNom : public IMainInterface
{
public:
   __property IDMSprVidNom * DM = {read = get_DM , write = set_DM};
   virtual IDMSprVidNom * get_DM(void)=0;
   virtual void set_DM(IDMSprVidNom * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;


   virtual void UpdateForm(void)=0;
};
#define IID_IFormaSpiskaSprVidNom __uuidof(IFormaSpiskaSprVidNom)
#endif
