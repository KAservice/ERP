#ifndef UFormaGurPlatImplH
#define UFormaGurPlatImplH
#include "IFormaGurPlat.h"
#include "UFormaGurPlat.h"

//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaGurPlatImpl)) TFormaGurPlatImpl : public IFormaGurPlat, IkanCallBack
{
public:
   TFormaGurPlatImpl();
   ~TFormaGurPlatImpl();
   TFormaGurPlat * Object;
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

//IFormaGurPlat
   virtual IDMGurPlat * get_DM(void);
   virtual void set_DM(IDMGurPlat * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdPlat(void);
   virtual void set_IdPlat(__int64 IdPlat);

   virtual TDateTime get_PosNach(void);
   virtual void set_PosNach(TDateTime PosNach);

   virtual TDateTime get_PosCon(void);
   virtual void set_PosCon(TDateTime PosCon);

   virtual bool get_NoOnlyOut(void);
   virtual void set_NoOnlyOut(bool NoOnlyOut);

   virtual AnsiString get_CodeTel(void);
   virtual void set_CodeTel(AnsiString CodeTel);

};
#define CLSID_TFormaGurPlatImpl __uuidof(TFormaGurPlatImpl)
#endif
