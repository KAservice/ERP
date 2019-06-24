#ifndef UFormaExportDocImplH
#define UFormaExportDocImplH
#include "UFormaExportDoc.h"
#include "IMainInterface.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaExportDocImpl)) TFormaExportDocImpl : public IMainInterface
{
public:
   TFormaExportDocImpl();
   ~TFormaExportDocImpl();
   TFormaExportDoc * Object;
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

//IFormaExportDoc
};
#define CLSID_TFormaExportDocImpl __uuidof(TFormaExportDocImpl)
#endif
