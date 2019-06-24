#ifndef UFormaReportImplH
#define UFormaReportImplH
#include "UFormaReport.h"
#include "UGlobalConstant.h"
#include "IMainInterface.h"
//---------------------------------------------------------------
class __declspec(uuid("{E41B16A3-BE36-4706-A380-B003A20FE85F}")) TFormaReportImpl
					: public IMainInterface, IkanCallBack
{
public:
   TFormaReportImpl();
   ~TFormaReportImpl();
   TFormaReport * Object;
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

//IFormaReport
};
#define CLSID_TFormaReportImpl __uuidof(TFormaReportImpl)
#endif
