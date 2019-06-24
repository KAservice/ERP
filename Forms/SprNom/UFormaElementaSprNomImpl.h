#ifndef UFormaElementaSprNomImplH
#define UFormaElementaSprNomImplH
#include "IFormaElementaSprNom.h"
#include "UFormaElementaSprNom.h"
//---------------------------------------------------------------
class __declspec(uuid("{1617783B-3B99-4723-825B-B556552D498E}")) TFormaElementaSprNomImpl : public IFormaElementaSprNom, IkanCallBack
{
public:
   TFormaElementaSprNomImpl();
   ~TFormaElementaSprNomImpl();
   TFormaElementaSprNom * Object;
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

//IFormaElementaSprNom
   virtual IDMSprNom * get_DM(void);
   virtual void set_DM(IDMSprNom * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual __int64 get_IdFirm(void);
   virtual void set_IdFirm(__int64 IdFirm);

   virtual void UpdateForm(void);

   virtual __int64 get_IdGrpNom(void);
   virtual void set_IdGrpNom(__int64 IdGrpNom);

   virtual UnicodeString get_NameGrpNom(void);
   virtual void set_NameGrpNom(UnicodeString NameGrpNom);
};
#define CLSID_TFormaElementaSprNomImpl __uuidof(TFormaElementaSprNomImpl)
#endif
