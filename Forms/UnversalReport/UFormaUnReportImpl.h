#ifndef UFormaUnReportImplH
#define UFormaUnReportImplH
#include "IFormaUnReport.h"
#include "UFormaUnReport.h"
#include "UGlobalConstant.h"
#include "IkasForm.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaUnReportImpl)) TFormaUnReportImpl : public IFormaUnReport, IkanCallBack
{
public:
   TFormaUnReportImpl();
   ~TFormaUnReportImpl();
   TFormaUnReport * Object;
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


	//IFormaUnReport
   virtual IkasDM * get_DM(void);
   virtual void set_DM(IkasDM * DM);

   virtual __int64 get_IdHw(void);
   virtual void set_IdHw(__int64 IdHw);

   virtual UnicodeString get_NameHardware(void);
   virtual void set_NameHardware(UnicodeString NameHardware);

};
#define CLSID_TFormaUnReportImpl __uuidof(TFormaUnReportImpl)
#endif
