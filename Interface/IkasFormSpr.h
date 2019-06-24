#ifndef IkasFormSprInterfaceH
#define IkasFormSprInterfaceH

#include <IkasForm.h>
#include <IkasDMSpr.h>



class __declspec(uuid("{5FB1BE96-48A7-4E7A-99E8-1BCA03B1DCDE}")) IkasFormSpr : public IkasForm
{
public:


	__property __int64 IdGroupEl1 = {read = get_IdGroupEl1 , write = set_IdGroupEl1};   virtual __int64 get_IdGroupEl1(void)=0;   virtual void set_IdGroupEl1(__int64 IdGroupEl1)=0;
	__property UnicodeString NameGroupEl1 = {read = get_NameGroupEl1 , write = set_NameGroupEl1};   virtual UnicodeString get_NameGroupEl1(void)=0;   virtual void set_NameGroupEl1(UnicodeString NameGroupEl1)=0;

	__property __int64 IdGroupEl2 = {read = get_IdGroupEl2 , write = set_IdGroupEl2};   virtual __int64 get_IdGroupEl2(void)=0;   virtual void set_IdGroupEl2(__int64 IdGroupEl2)=0;
	__property UnicodeString NameGroupEl2 = {read = get_NameGroupEl2 , write = set_NameGroupEl2};   virtual UnicodeString get_NameGroupEl2(void)=0;   virtual void set_NameGroupEl2(UnicodeString NameGroupEl2)=0;

	__property __int64 IdOwner = {read = get_IdOwner , write = set_IdOwner};   virtual __int64 get_IdOwner(void)=0;   virtual void set_IdOwner(__int64 IdOwner)=0;
	__property UnicodeString NameOwner = {read = get_NameOwner , write = set_NameOwner};   virtual UnicodeString get_NameOwner(void)=0;   virtual void set_NameOwner(UnicodeString NameOwner)=0;

	__property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};   virtual __int64 get_IdGrp(void)=0;   virtual void set_IdGrp(__int64 IdGrp)=0;
	__property UnicodeString NameGrp = {read = get_NameGrp , write = set_NameGrp};   virtual UnicodeString get_NameGrp(void)=0;   virtual void set_NameGrp(UnicodeString NameGrp)=0;

	__property __int64 IdEl = {read = get_IdEl , write = set_IdEl};   virtual __int64 get_IdEl(void)=0;   virtual void set_IdEl(__int64 IdEl)=0;
	__property UnicodeString NameEl = {read = get_NameEl , write = set_NameEl};   virtual UnicodeString get_NameEl(void)=0;   virtual void set_NameEl(UnicodeString IdEl)=0;

	__property bool All = {read = get_All , write = set_All};   virtual bool get_All(void)=0;   virtual void set_All(bool All)=0;


	__property IkasDMSpr * DM = {read = get_DM , write = set_DM};   virtual IkasDMSpr * get_DM(void)=0;   virtual void set_DM(IkasDMSpr * DM)=0;

};
#define IID_IkasFormSpr __uuidof(IkasFormSpr)







#endif
