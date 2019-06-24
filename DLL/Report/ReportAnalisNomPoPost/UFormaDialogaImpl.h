#ifndef UFormaDialogaImplH
#define UFormaDialogaImplH
#include "IMainInterface.h"
#include "UFormaDialoga.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid("{D610BD8F-04AE-4F97-834F-F7A3CF457FE1}")) TFormaDialogaImpl
				: public IMainInterface, IkanCallBack
{
public:
   TFormaDialogaImpl();
   ~TFormaDialogaImpl();
   TFormaDialoga * Object;
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

//IFormaDialoga
};
#define CLSID_TFormaDialogaImpl __uuidof(TFormaDialogaImpl)
#endif
