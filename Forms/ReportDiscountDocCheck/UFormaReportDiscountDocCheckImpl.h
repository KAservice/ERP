#ifndef UFormaReportDiscountDocCheckImplH
#define UFormaReportDiscountDocCheckImplH
#include "IMainInterface.h"
#include "UFormaReportDiscountDocCheck.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaReportDiscountDocCheckImpl))TFormaReportDiscountDocCheckImpl
			: public IMainInterface, IkanCallBack
{
public:
   TFormaReportDiscountDocCheckImpl();
   ~TFormaReportDiscountDocCheckImpl();
   TFormaReportDiscountDocCheck * Object;
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

//IFormaReportDiscountDocCheck
};
#define CLSID_TFormaReportDiscountDocCheckImpl __uuidof(TFormaReportDiscountDocCheckImpl)
#endif
