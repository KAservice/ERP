#ifndef UIREM_FormaElementaSprTypeRemontH
#define UIREM_FormaElementaSprTypeRemontH
#include "IMainInterface.h"
#include "IREM_DMSprTypeRemont.h"
class __declspec(uuid("{D52E7DC9-2F83-4968-A655-239FCCD5CA57}")) IREM_FormaElementaSprTypeRemont : public IMainInterface
{
public:
   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IREM_DMSprTypeRemont * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprTypeRemont * get_DM(void)=0;
   virtual void set_DM(IREM_DMSprTypeRemont * DM)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IREM_FormaElementaSprTypeRemont __uuidof(IREM_FormaElementaSprTypeRemont)
#endif
