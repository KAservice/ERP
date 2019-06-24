#ifndef UFormaDocRevImplH
#define UFormaDocRevImplH
#include "IFormaDocRev.h"
#include "UFormaDocRev.h"
#include "IAsyncExternalEvent.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaDocRevImpl)) TFormaDocRevImpl
			: public IFormaDocRev, IkanCallBack, IAsyncExternalEvent
{
public:
   TFormaDocRevImpl();
   ~TFormaDocRevImpl();
   TFormaDocRev * Object;
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

      //IAcyncExternalEvent
   virtual int AsyncExternalEvent(char * object, char* event, char* data);
   virtual int SetInterfaceForAsyncExternalEvent(IkanUnknown * i_act_form);

//IFormaDocRev
   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual bool get_ObjectSave(void);
   virtual void set_ObjectSave(bool ObjectSave);

   virtual bool get_NoEdit(void);
   virtual void set_NoEdit(bool NoEdit);

   virtual IDMDocRev * get_DM(void);
   virtual void set_DM(IDMDocRev * DM);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaDocRevImpl __uuidof(TFormaDocRevImpl)
#endif
