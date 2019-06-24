#ifndef UFormaReportOCBRegVSRaschImplH
#define UFormaReportOCBRegVSRaschImplH
#include "IMainInterface.h"
#include "UFormaReportOCBRegVSRasch.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaReportOCBRegVSRaschImpl))TFormaReportOCBRegVSRaschImpl
					: public IMainInterface, IkanCallBack
{
public:
   TFormaReportOCBRegVSRaschImpl();
   ~TFormaReportOCBRegVSRaschImpl();
   TFormaReportOCBRegVSRasch * Object;
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

//IFormaReportOCBRegVSRasch
};
#define CLSID_TFormaReportOCBRegVSRaschImpl __uuidof(TFormaReportOCBRegVSRaschImpl)
#endif
