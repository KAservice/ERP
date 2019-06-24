#ifndef UFormaDocPerImplH
#define UFormaDocPerImplH
#include "IFormaDocPer.h"
#include "UFormaDocPer.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaDocPerImpl))TFormaDocPerImpl : public IFormaDocPer, IkanCallBack
{
public:
   TFormaDocPerImpl();
   ~TFormaDocPerImpl();
   TFormaDocPer * Object;
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

//IFormaDocPer
   virtual IDMDocPer * get_DM(void);
   virtual void set_DM(IDMDocPer * DM);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_NoEdit(void);
   virtual void set_NoEdit(bool NoEdit);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual void UpdateForm(void);
   virtual void CreateDocNaOsnPrihNakl(__int64 id_doc_osn);
};
#define CLSID_TFormaDocPerImpl __uuidof(TFormaDocPerImpl)
#endif