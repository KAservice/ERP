#ifndef UFormaGurRoznDocImplH
#define UFormaGurRoznDocImplH
#include "IFormaGurRoznDoc.h"
#include "UFormaGurRoznDoc.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaGurRoznDocImpl))TFormaGurRoznDocImpl : public IFormaGurRoznDoc, IkanCallBack
{
public:
   TFormaGurRoznDocImpl();
   ~TFormaGurRoznDocImpl();
   TFormaGurRoznDoc * Object;
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

//IFormaGurRoznDoc
   virtual IDMGurRoznDoc * get_DM(void);
   virtual void set_DM(IDMGurRoznDoc * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

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

   virtual UnicodeString get_StringTypeDoc(void);
   virtual void set_StringTypeDoc(UnicodeString StringTypeDoc);

   virtual UnicodeString get_NameTypeDoc(void);
   virtual void set_NameTypeDoc(UnicodeString NameTypeDoc);

   virtual UnicodeString get_StringFullTypeDoc(void);
   virtual void set_StringFullTypeDoc(UnicodeString StringFullTypeDoc);

   virtual bool get_OtborPoKlientu(void);
   virtual void set_OtborPoKlientu(bool OtborPoKlientu);

   virtual bool get_OtborPoTypeDoc(void);
   virtual void set_OtborPoTypeDoc(bool OtborPoTypeDoc);

};
#define CLSID_TFormaGurRoznDocImpl __uuidof(TFormaGurRoznDocImpl)
#endif
