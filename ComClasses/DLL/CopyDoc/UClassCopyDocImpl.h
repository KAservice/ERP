#ifndef UClassCopyDocImplH
#define UClassCopyDocImplH
#include "IClassCopyDoc.h"
#include "UClassCopyDoc.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TClassCopyDocImpl)) TClassCopyDocImpl : public IClassCopyDoc
{
public:
   TClassCopyDocImpl();
   ~TClassCopyDocImpl();
   TClassCopyDoc * Object;
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

//IClassCopyDoc
   virtual bool CreateNewCopyDoc(__int64 id_doc, UnicodeString type_doc, UnicodeString type_new_doc, bool fl_save_doc, bool fl_open_form_doc, int param1, int param2, int param3);
   virtual __int64 CreateNewDocNaOsn(__int64 id_doc, UnicodeString type_doc, UnicodeString type_new_doc,bool fl_save_doc, bool fl_open_form_doc,int param1, int param2, int param3);
};
#define CLSID_TClassCopyDocImpl __uuidof(TClassCopyDocImpl)
#endif
