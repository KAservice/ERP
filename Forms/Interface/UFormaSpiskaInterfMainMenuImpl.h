#ifndef UFormaSpiskaInterfMainMenuImplH
#define UFormaSpiskaInterfMainMenuImplH
#include "IFormaSpiskaInterfMainMenu.h"
#include "UFormaSpiskaInterfMainMenu.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSpiskaInterfMainMenuImpl))TFormaSpiskaInterfMainMenuImpl : public IFormaSpiskaInterfMainMenu, IkanCallBack
{
public:
   TFormaSpiskaInterfMainMenuImpl();
   ~TFormaSpiskaInterfMainMenuImpl();
   TFormaSpiskaInterfMainMenu * Object;
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

//IFormaSpiskaInterfMainMenu
   virtual IDMInterfMainMenu * get_DM(void);
   virtual void set_DM(IDMInterfMainMenu * DM);

   virtual IDMInterfMainMenuGrp * get_DMGrp(void);
   virtual void set_DMGrp(IDMInterfMainMenuGrp * DMGrp);

   virtual __int64 get_IdGrpUser(void);
   virtual void set_IdGrpUser(__int64 IdGrpUser);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual int get_NumApplication(void);
   virtual void set_NumApplication(int NumApplication);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaSpiskaInterfMainMenuImpl __uuidof(TFormaSpiskaInterfMainMenuImpl)
#endif
