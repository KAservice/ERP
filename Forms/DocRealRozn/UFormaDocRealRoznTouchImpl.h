#ifndef UFormaDocRealRoznTouchImplH
#define UFormaDocRealRoznTouchImplH
#include "IFormaDocRealRoznTouch.h"
#include "UFormaDocRealRoznTouch.h"
//---------------------------------------------------------------
class __declspec(uuid("{A1A4C196-C1D9-46B4-99FD-3A8E89AEF6E1}"))TFormaDocRealRoznTouchImpl : public IFormaDocRealRoznTouch, IkanCallBack
{
public:
   TFormaDocRealRoznTouchImpl();
   ~TFormaDocRealRoznTouchImpl();
   TFormaDocRealRoznTouch * Object;
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

//IFormaDocRealRoznTouch
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual IDMDocRealRozn * get_DM(void);
   virtual void set_DM(IDMDocRealRozn * DM);

   virtual UnicodeString get_NameFirm(void);
   virtual void set_NameFirm(UnicodeString NameFirm);

   virtual UnicodeString get_NameSklad(void);
   virtual void set_NameSklad(UnicodeString NameSklad);

   virtual UnicodeString get_NameKlient(void);
   virtual void set_NameKlient(UnicodeString NameKlient);

   virtual UnicodeString get_NameDoc(void);
   virtual void set_NameDoc(UnicodeString NameDoc);

   virtual UnicodeString get_Prim(void);
   virtual void set_Prim(UnicodeString Prim);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaDocRealRoznTouchImpl __uuidof(TFormaDocRealRoznTouchImpl)
#endif
