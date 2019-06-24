#ifndef UIFormaSpiskaSprNomInetCatalogH
#define UIFormaSpiskaSprNomInetCatalogH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprNomInetCatalog.h"

class __declspec(uuid(Global_IID_IFormaSpiskaSprNomInetCatalog)) IFormaSpiskaSprNomInetCatalog : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMSprNomInetCatalog* DM = {read = get_DM , write = set_DM};
   virtual IDMSprNomInetCatalog* get_DM(void)=0;
   virtual void set_DM(IDMSprNomInetCatalog* DM)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdInetCatalog = {read = get_IdInetCatalog , write = set_IdInetCatalog};
   virtual __int64 get_IdInetCatalog(void)=0;
   virtual void set_IdInetCatalog(__int64 IdInetCatalog)=0;

   __property __int64 ViborIdNom = {read = get_ViborIdNom , write = set_ViborIdNom};
   virtual __int64 get_ViborIdNom(void)=0;
   virtual void set_ViborIdNom(__int64 ViborIdNom)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   virtual void DeleteElement()=0;
   virtual void UpdateForm(void)=0;
};
#define IID_IFormaSpiskaSprNomInetCatalog __uuidof(IFormaSpiskaSprNomInetCatalog)
#endif
