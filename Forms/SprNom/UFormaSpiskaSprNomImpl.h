#ifndef UFormaSpiskaSprNomImplH
#define UFormaSpiskaSprNomImplH
#include "IFormaSpiskaSprNom.h"
#include "UFormaSpiskaSprNom.h"
#include "UGlobalConstant.h"
#include "IAsyncExternalEvent.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSpiskaSprNomImpl)) TFormaSpiskaSprNomImpl : public IFormaSpiskaSprNom,
										IkanCallBack,IAsyncExternalEvent
{
public:
   TFormaSpiskaSprNomImpl();
   ~TFormaSpiskaSprNomImpl();
   TFormaSpiskaSprNom * Object;
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

   //IAcyncExternalEvent
   virtual int AsyncExternalEvent(char * object, char* event, char* data);
   virtual int SetInterfaceForAsyncExternalEvent(IkanUnknown * i_act_form);


//IFormaSpiskaSprNom
   virtual IFormaPodboraNom * get_FormaPodboraNom(void);
   virtual void set_FormaPodboraNom(IFormaPodboraNom * FormaPodboraNom);

   virtual IDMSprNom* get_DM(void);
   virtual void set_DM(IDMSprNom* DM);

   virtual IDMSprGrpNom * get_DMGrp(void);
   virtual void set_DMGrp(IDMSprGrpNom * DMGrp);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual __int64 get_IdFirm(void);
   virtual void set_IdFirm(__int64 IdFirm);

   virtual UnicodeString get_NameFirm(void);
   virtual void set_NameFirm(UnicodeString NameFirm);

   virtual __int64 get_IdSklad(void);
   virtual void set_IdSklad(__int64 IdSklad);

   virtual UnicodeString get_NameSklad(void);
   virtual void set_NameSklad(UnicodeString NameSklad);

   virtual __int64 get_IdInetCatalog(void);
   virtual void set_IdInetCatalog(__int64 IdInetCatalog);

   virtual UnicodeString get_NameInetCatalog(void);
   virtual void set_NameInetCatalog(UnicodeString NameInetCatalog);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual bool get_Podbor(void);
   virtual void set_Podbor(bool Podbor);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual void UpdateForm(void);

};
#define CLSID_TFormaSpiskaSprNomImpl __uuidof(TFormaSpiskaSprNomImpl)
#endif
