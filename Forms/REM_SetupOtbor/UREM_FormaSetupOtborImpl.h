#ifndef UREM_FormaSetupOtborImplH
#define UREM_FormaSetupOtborImplH
#include "IREM_FormaSetupOtbor.h"
#include "UREM_FormaSetupOtbor.h"
//---------------------------------------------------------------
class __declspec(uuid("{4337621F-2C68-460F-9AD9-AC403AFA63CC}")) TREM_FormaSetupOtborImpl : public IREM_FormaSetupOtbor, IkanCallBack
{
public:
   TREM_FormaSetupOtborImpl();
   ~TREM_FormaSetupOtborImpl();
   TREM_FormaSetupOtbor * Object;
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

//IREM_FormaSetupOtbor
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual int get_IdKlient(void);
   virtual void set_IdKlient(int IdKlient);

   virtual UnicodeString get_NameKlient(void);
   virtual void set_NameKlient(UnicodeString NameKlient);

   virtual int get_IdSklad(void);
   virtual void set_IdSklad(int IdSklad);

   virtual UnicodeString get_NameSklad(void);
   virtual void set_NameSklad(UnicodeString NameSklad);

   virtual int get_IdFirm(void);
   virtual void set_IdFirm(int IdFirm);

   virtual UnicodeString get_NameFirm(void);
   virtual void set_NameFirm(UnicodeString NameFirm);

   virtual UnicodeString get_StringTypeDoc(void);
   virtual void set_StringTypeDoc(UnicodeString StringTypeDoc);

   virtual UnicodeString get_NameTypeDoc(void);
   virtual void set_NameTypeDoc(UnicodeString NameTypeDoc);

   virtual UnicodeString get_StringFullTypeDoc(void);
   virtual void set_StringFullTypeDoc(UnicodeString StringFullTypeDoc);

   virtual bool get_OtborPoKlient(void);
   virtual void set_OtborPoKlient(bool OtborPoKlient);

   virtual bool get_OtborPoFirm(void);
   virtual void set_OtborPoFirm(bool OtborPoFirm);

   virtual bool get_OtborPoSklad(void);
   virtual void set_OtborPoSklad(bool OtborPoSklad);

   virtual bool get_OtborPoTypeDoc(void);
   virtual void set_OtborPoTypeDoc(bool OtborPoTypeDoc);

};
#define CLSID_TREM_FormaSetupOtborImpl __uuidof(TREM_FormaSetupOtborImpl)
#endif
