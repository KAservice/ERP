#ifndef UFormaElementaSprGrpVesNomImplH
#define UFormaElementaSprGrpVesNomImplH
#include "IFormaElementaSprGrpVesNom.h"
#include "UFormaElementaSprGrpVesNom.h"
//---------------------------------------------------------------
class __declspec(uuid("{23223776-7092-4A4F-AF58-2962B5163063}")) TFormaElementaSprGrpVesNomImpl : public IFormaElementaSprGrpVesNom, IkanCallBack
{
public:
   TFormaElementaSprGrpVesNomImpl();
   ~TFormaElementaSprGrpVesNomImpl();
   TFormaElementaSprGrpVesNom * Object;
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

//IFormaElementaSprGrpVesNom
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMSprGrpVesNom* get_DM(void);
   virtual void set_DM(IDMSprGrpVesNom* DM);

};
#define CLSID_TFormaElementaSprGrpVesNomImpl __uuidof(TFormaElementaSprGrpVesNomImpl)
#endif
