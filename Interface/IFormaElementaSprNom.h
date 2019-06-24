#ifndef UIFormaElementaSprNomH
#define UIFormaElementaSprNomH
#include "IMainInterface.h"
#include "IDMSprNom.h"
class __declspec(uuid("{2E8772C3-FFDC-492C-8411-7D81DDC54D53}"))IFormaElementaSprNom : public IMainInterface
{
public:
   __property IDMSprNom * DM = {read = get_DM , write = set_DM};
   virtual IDMSprNom * get_DM(void)=0;
   virtual void set_DM(IDMSprNom * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdTypePrice = {read = get_IdTypePrice , write = set_IdTypePrice};
   virtual __int64 get_IdTypePrice(void)=0;
   virtual void set_IdTypePrice(__int64 IdTypePrice)=0;

   __property __int64 IdFirm = {read = get_IdFirm , write = set_IdFirm};
   virtual __int64 get_IdFirm(void)=0;
   virtual void set_IdFirm(__int64 IdFirm)=0;

   virtual void UpdateForm(void)=0;

   __property __int64 IdGrpNom = {read = get_IdGrpNom , write = set_IdGrpNom};
   virtual __int64 get_IdGrpNom(void)=0;
   virtual void set_IdGrpNom(__int64 IdGrpNom)=0;

   __property UnicodeString NameGrpNom = {read = get_NameGrpNom , write = set_NameGrpNom};
   virtual UnicodeString get_NameGrpNom(void)=0;
   virtual void set_NameGrpNom(UnicodeString NameGrpNom)=0;
};
#define IID_IFormaElementaSprNom __uuidof(IFormaElementaSprNom)
#endif
