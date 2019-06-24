#ifndef UFormaSpiskaSprOborudParamImplH
#define UFormaSpiskaSprOborudParamImplH
#include "UFormaSpiskaSprOborudParam.h"
#include "UGlobalConstant.h"
#include "IkasFormSpr.h"

//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSpiskaSprOborudParamImpl)) TFormaSpiskaSprOborudParamImpl : public IkasFormSpr, IkanCallBack
{
public:
   TFormaSpiskaSprOborudParamImpl();
   ~TFormaSpiskaSprOborudParamImpl();
   TFormaSpiskaSprOborudParam * Object;
   int NumRefs;
   bool flDeleteObject;
   void DeleteImpl(void);

   //IUnknown
   virtual int kanQueryInterface(REFIID id_interface,void ** ppv);
   virtual int kanAddRef(void);
   virtual int kanRelease(void);

   //IMainInterface
   virtual int  get_CodeError(void);
   virtual void set_CodeError(int CodeError);
   virtual UnicodeString  get_TextError(void);
   virtual void set_TextError(UnicodeString  TextError);
   virtual int Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object);
   virtual int Done(void);

   //IkanCallBack
   virtual int kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end);

   //IkasForm
	virtual void UpdateForm(void);
	virtual bool get_Vibor(void);
	virtual void set_Vibor(bool Vibor);  //форма открыта для выбора
	virtual int get_NumberProcVibor(void);
	virtual void set_NumberProcVibor(int NumberProcVibor);  //какую процедуру использовать для обработки выбора во внешней форме



   //IkasFormSpr
	__property __int64 IdGroupEl1 = {read = get_IdGroupEl1 , write = set_IdGroupEl1};   virtual __int64 get_IdGroupEl1(void);   virtual void set_IdGroupEl1(__int64 IdGroupEl1);
	__property UnicodeString NameGroupEl1 = {read = get_NameGroupEl1 , write = set_NameGroupEl1};   virtual UnicodeString get_NameGroupEl1(void);   virtual void set_NameGroupEl1(UnicodeString NameGroupEl1);

	__property __int64 IdGroupEl2 = {read = get_IdGroupEl2 , write = set_IdGroupEl2};   virtual __int64 get_IdGroupEl2(void);   virtual void set_IdGroupEl2(__int64 IdGroupEl2);
	__property UnicodeString NameGroupEl2 = {read = get_NameGroupEl2 , write = set_NameGroupEl2};   virtual UnicodeString get_NameGroupEl2(void);   virtual void set_NameGroupEl2(UnicodeString NameGroupEl2);

	__property __int64 IdOwner = {read = get_IdOwner , write = set_IdOwner};   virtual __int64 get_IdOwner(void);   virtual void set_IdOwner(__int64 IdOwner);
	__property UnicodeString NameOwner = {read = get_NameOwner , write = set_NameOwner};   virtual UnicodeString get_NameOwner(void);   virtual void set_NameOwner(UnicodeString NameOwner);

	__property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};   virtual __int64 get_IdGrp(void);   virtual void set_IdGrp(__int64 IdGrp);
	__property UnicodeString NameGrp = {read = get_NameGrp , write = set_NameGrp};   virtual UnicodeString get_NameGrp(void);   virtual void set_NameGrp(UnicodeString NameGrp);

	__property __int64 IdEl = {read = get_IdEl , write = set_IdEl};   virtual __int64 get_IdEl(void);   virtual void set_IdEl(__int64 IdEl);
	__property UnicodeString NameEl = {read = get_NameEl , write = set_NameEl};   virtual UnicodeString get_NameEl(void);   virtual void set_NameEl(UnicodeString IdEl);

	__property bool All = {read = get_All , write = set_All};   virtual bool get_All(void);   virtual void set_All(bool All);


	__property IkasDMSpr * DM = {read = get_DM , write = set_DM};   virtual IkasDMSpr * get_DM(void);   virtual void set_DM(IkasDMSpr * DM);


};
#define CLSID_TFormaSpiskaSprOborudParamImpl __uuidof(TFormaSpiskaSprOborudParamImpl)
#endif
