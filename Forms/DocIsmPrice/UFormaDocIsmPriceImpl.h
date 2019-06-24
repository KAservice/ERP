#ifndef UFormaDocIsmPriceImplH
#define UFormaDocIsmPriceImplH
#include "IFormaDocIsmPrice.h"
#include "UFormaDocIsmPrice.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaDocIsmPriceImpl))TFormaDocIsmPriceImpl : public IFormaDocIsmPrice, IkanCallBack
{
public:
   TFormaDocIsmPriceImpl();
   ~TFormaDocIsmPriceImpl();
   TFormaDocIsmPrice * Object;
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

//IFormaDocIsmPrice
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMDocIsmPrice * get_DM(void);
   virtual void set_DM(IDMDocIsmPrice * DM);

   virtual bool get_NewElement(void);
   virtual void set_NewElement(bool NewElement);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_NoEdit(void);
   virtual void set_NoEdit(bool NoEdit);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaDocIsmPriceImpl __uuidof(TFormaDocIsmPriceImpl)
#endif
