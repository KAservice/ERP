#ifndef UFormaPodboraNomImplH
#define UFormaPodboraNomImplH
#include "IFormaPodboraNom.h"
#include "UFormaPodboraNom.h"
//---------------------------------------------------------------
class __declspec(uuid("{820CF147-5592-4CC5-A1DA-EB89DB35449A}")) TFormaPodboraNomImpl : public IFormaPodboraNom, IkanCallBack
{
public:
   TFormaPodboraNomImpl();
   ~TFormaPodboraNomImpl();
   TFormaPodboraNom * Object;
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

//IFormaPodboraNom
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual double get_Price(void);
   virtual void set_Price(double Price);

   virtual double get_PriceBasEd(void);
   virtual void set_PriceBasEd(double PriceBasEd);

   virtual double get_Kol(void);
   virtual void set_Kol(double Kol);

   virtual double get_Summa(void);
   virtual void set_Summa(double Summa);

   virtual int get_IdEd(void);
   virtual void set_IdEd(int IdEd);

   virtual UnicodeString get_NameEd(void);
   virtual void set_NameEd(UnicodeString NameEd);

   virtual UnicodeString get_NameNom(void);
   virtual void set_NameNom(UnicodeString NameNom);

   virtual double get_KFEd(void);
   virtual void set_KFEd(double KFEd);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaPodboraNomImpl __uuidof(TFormaPodboraNomImpl)
#endif
