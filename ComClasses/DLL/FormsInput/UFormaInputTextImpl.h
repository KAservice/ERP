#ifndef UFormaInputTextImplH
#define UFormaInputTextImplH
#include "IFormaInputText.h"
#include "UFormaInputText.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaInputTextImpl)) TFormaInputTextImpl : public IFormaInputText
{
public:
   TFormaInputTextImpl();
   ~TFormaInputTextImpl();
   TFormaInputText * Object;
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


//IFormaInputText
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual UnicodeString get_InputText(void);
   virtual void set_InputText(UnicodeString InputText);

   virtual UnicodeString get_TextMessage(void);
   virtual void set_TextMessage(UnicodeString TextMessage);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaInputTextImpl __uuidof(TFormaInputTextImpl)
#endif
