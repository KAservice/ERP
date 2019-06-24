#ifndef UIFormaSpiskaSprNomH
#define UIFormaSpiskaSprNomH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IFormaPodboraNom.h"
#include "IDMSprNom.h"
#include "IDMSprGrpNom.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprNom)) IFormaSpiskaSprNom : public IMainInterface
{
public:
   __property IFormaPodboraNom * FormaPodboraNom = {read = get_FormaPodboraNom , write = set_FormaPodboraNom};
   virtual IFormaPodboraNom * get_FormaPodboraNom(void)=0;
   virtual void set_FormaPodboraNom(IFormaPodboraNom * FormaPodboraNom)=0;

   __property IDMSprNom* DM = {read = get_DM , write = set_DM};
   virtual IDMSprNom* get_DM(void)=0;
   virtual void set_DM(IDMSprNom* DM)=0;

   __property IDMSprGrpNom * DMGrp = {read = get_DMGrp , write = set_DMGrp};
   virtual IDMSprGrpNom * get_DMGrp(void)=0;
   virtual void set_DMGrp(IDMSprGrpNom * DMGrp)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

   __property __int64 IdFirm = {read = get_IdFirm , write = set_IdFirm};
   virtual __int64 get_IdFirm(void)=0;
   virtual void set_IdFirm(__int64 IdFirm)=0;

   __property UnicodeString NameFirm = {read = get_NameFirm , write = set_NameFirm};
   virtual UnicodeString get_NameFirm(void)=0;
   virtual void set_NameFirm(UnicodeString NameFirm)=0;

   __property __int64 IdSklad = {read = get_IdSklad , write = set_IdSklad};
   virtual __int64 get_IdSklad(void)=0;
   virtual void set_IdSklad(__int64 IdSklad)=0;

   __property UnicodeString NameSklad = {read = get_NameSklad , write = set_NameSklad};
   virtual UnicodeString get_NameSklad(void)=0;
   virtual void set_NameSklad(UnicodeString NameSklad)=0;

   __property __int64 IdInetCatalog = {read = get_IdInetCatalog , write = set_IdInetCatalog};
   virtual __int64 get_IdInetCatalog(void)=0;
   virtual void set_IdInetCatalog(__int64 IdInetCatalog)=0;

   __property UnicodeString NameInetCatalog = {read = get_NameInetCatalog , write = set_NameInetCatalog};
   virtual UnicodeString get_NameInetCatalog(void)=0;
   virtual void set_NameInetCatalog(UnicodeString NameInetCatalog)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property bool Podbor = {read = get_Podbor , write = set_Podbor};
   virtual bool get_Podbor(void)=0;
   virtual void set_Podbor(bool Podbor)=0;

   __property __int64 IdTypePrice = {read = get_IdTypePrice , write = set_IdTypePrice};
   virtual __int64 get_IdTypePrice(void)=0;
   virtual void set_IdTypePrice(__int64 IdTypePrice)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaSpiskaSprNom __uuidof(IFormaSpiskaSprNom)
#endif
