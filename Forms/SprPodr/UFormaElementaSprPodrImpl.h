#ifndef UFormaElementaSprPodrImplH
#define UFormaElementaSprPodrImplH
#include "IFormaElementaSprPodr.h"
#include "UFormaElementaSprPodr.h"
//---------------------------------------------------------------
class __declspec(uuid("{B26BF76A-1384-4FDC-82B5-FE43733BDAF7}")) TFormaElementaSprPodrImpl : public IFormaElementaSprPodr, IkanCallBack
{
public:
   TFormaElementaSprPodrImpl();
   ~TFormaElementaSprPodrImpl();
   TFormaElementaSprPodr * Object;
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

//IFormaElementaSprPodr
   virtual IDMSprPodr * get_DM(void);
   virtual void set_DM(IDMSprPodr * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

};
#define CLSID_TFormaElementaSprPodrImpl __uuidof(TFormaElementaSprPodrImpl)
#endif
