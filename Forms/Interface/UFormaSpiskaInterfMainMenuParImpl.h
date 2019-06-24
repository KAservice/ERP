#ifndef UFormaSpiskaInterfMainMenuParImplH
#define UFormaSpiskaInterfMainMenuParImplH
#include "IFormaSpiskaInterfMainMenuPar.h"
#include "UFormaSpiskaInterfMainMenuPar.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSpiskaInterfMainMenuParImpl)) TFormaSpiskaInterfMainMenuParImpl : public IFormaSpiskaInterfMainMenuPar, IkanCallBack
{
public:
   TFormaSpiskaInterfMainMenuParImpl();
   ~TFormaSpiskaInterfMainMenuParImpl();
   TFormaSpiskaInterfMainMenuPar * Object;
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

//IFormaSpiskaInterfMainMenuPar
   virtual IDMInterfMainMenuPar* get_DM(void);
   virtual void set_DM(IDMInterfMainMenuPar* DM);

   virtual __int64 get_IdOwner(void);
   virtual void set_IdOwner(__int64 IdOwner);

   virtual UnicodeString get_TextHeader(void);
   virtual void set_TextHeader(UnicodeString TextHeader);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void UpdateForm(void);
   virtual void DeleteElement();
};
#define CLSID_TFormaSpiskaInterfMainMenuParImpl __uuidof(TFormaSpiskaInterfMainMenuParImpl)
#endif
