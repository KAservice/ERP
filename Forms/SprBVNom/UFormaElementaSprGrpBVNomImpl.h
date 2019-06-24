#ifndef UFormaElementaSprGrpBVNomImplH
#define UFormaElementaSprGrpBVNomImplH
#include "IFormaElementaSprGrpBVNom.h"
#include "UFormaElementaSprGrpBVNom.h"
//---------------------------------------------------------------
class __declspec(uuid("{E0531318-E007-4D7F-8830-647F731D8B9B}")) TFormaElementaSprGrpBVNomImpl : public IFormaElementaSprGrpBVNom, IkanCallBack
{
public:
   TFormaElementaSprGrpBVNomImpl();
   ~TFormaElementaSprGrpBVNomImpl();
   TFormaElementaSprGrpBVNom * Object;
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

//IFormaElementaSprGrpBVNom
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMSprGrpBVNom* get_DM(void);
   virtual void set_DM(IDMSprGrpBVNom* DM);

};
#define CLSID_TFormaElementaSprGrpBVNomImpl __uuidof(TFormaElementaSprGrpBVNomImpl)
#endif
