#ifndef UFormaGurAllDocImplH
#define UFormaGurAllDocImplH
#include "IFormaGurAllDoc.h"
#include "UFormaGurAllDoc.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaGurAllDocImpl)) TFormaGurAllDocImpl : public IFormaGurAllDoc, IkanCallBack
{
public:
   TFormaGurAllDocImpl();
   ~TFormaGurAllDocImpl();
   TFormaGurAllDoc * Object;
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

//IFormaGurAllDoc
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMGurAllDoc * get_DM(void);
   virtual void set_DM(IDMGurAllDoc * DM);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual TDateTime get_PosNach(void);
   virtual void set_PosNach(TDateTime PosNach);

   virtual TDateTime get_PosCon(void);
   virtual void set_PosCon(TDateTime PosCon);

   virtual __int64 get_IdKlient(void);
   virtual void set_IdKlient(__int64 IdKlient);

   virtual UnicodeString get_NameKlient(void);
   virtual void set_NameKlient(UnicodeString NameKlient);

   virtual __int64 get_IdSklad(void);
   virtual void set_IdSklad(__int64 IdSklad);

   virtual UnicodeString get_NameSklad(void);
   virtual void set_NameSklad(UnicodeString NameSklad);

   virtual __int64 get_IdFirm(void);
   virtual void set_IdFirm(__int64 IdFirm);

   virtual UnicodeString get_NameFirm(void);
   virtual void set_NameFirm(UnicodeString NameFirm);

   virtual UnicodeString get_StringTypeDoc(void);
   virtual void set_StringTypeDoc(UnicodeString StringTypeDoc);

   virtual UnicodeString get_NameTypeDoc(void);
   virtual void set_NameTypeDoc(UnicodeString NameTypeDoc);

   virtual bool get_OtborPoKlientu(void);
   virtual void set_OtborPoKlientu(bool OtborPoKlientu);

   virtual bool get_OtborPoFirm(void);
   virtual void set_OtborPoFirm(bool OtborPoFirm);

   virtual bool get_OtborPoSklad(void);
   virtual void set_OtborPoSklad(bool OtborPoSklad);

   virtual bool get_OtborPoTypeDoc(void);
   virtual void set_OtborPoTypeDoc(bool OtborPoTypeDoc);

   virtual bool get_NoCheck(void);
   virtual void set_NoCheck(bool NoCheck);

   virtual void OpenFormDoc();
   virtual void DeleteDoc(void);
   virtual void DeleteAllDoc(void);
   virtual void UpdateForm(void);
};
#define CLSID_TFormaGurAllDocImpl __uuidof(TFormaGurAllDocImpl)
#endif
