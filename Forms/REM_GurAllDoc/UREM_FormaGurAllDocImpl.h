#ifndef UREM_FormaGurAllDocImplH
#define UREM_FormaGurAllDocImplH
#include "IREM_FormaGurAllDoc.h"
#include "UREM_FormaGurAllDoc.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaGurAllDocImpl)) TREM_FormaGurAllDocImpl : public IREM_FormaGurAllDoc, IkanCallBack
{
public:
   TREM_FormaGurAllDocImpl();
   ~TREM_FormaGurAllDocImpl();
   TREM_FormaGurAllDoc * Object;
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

//IREM_FormaGurAllDoc
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMGurAllDoc * get_DM(void);
   virtual void set_DM(IREM_DMGurAllDoc * DM);

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

   virtual __int64 get_IdVibHardware(void);
   virtual void set_IdVibHardware(__int64 IdVibHardware);

   virtual __int64 get_IdVibZayavka(void);
   virtual void set_IdVibZayavka(__int64 IdVibZayavka);

   virtual UnicodeString get_Zayavka_NameKlient(void);
   virtual void set_Zayavka_NameKlient(UnicodeString Zayavka_NameKlient);

   virtual UnicodeString get_Zayavka_NameModel(void);
   virtual void set_Zayavka_NameModel(UnicodeString Zayavka_NameModel);

   virtual UnicodeString get_Zayavka_SerNum(void);
   virtual void set_Zayavka_SerNum(UnicodeString Zayavka_SerNum);

   virtual UnicodeString get_Zayavka_SerNum2(void);
   virtual void set_Zayavka_SerNum2(UnicodeString Zayavka_SerNum2);

   virtual UnicodeString get_Zayavka_Name(void);
   virtual void set_Zayavka_Name(UnicodeString Zayavka_Name);

   virtual UnicodeString get_Hardware_NameModel(void);
   virtual void set_Hardware_NameModel(UnicodeString Hardware_NameModel);

   virtual UnicodeString get_Hardware_SerNum(void);
   virtual void set_Hardware_SerNum(UnicodeString Hardware_SerNum);

   virtual UnicodeString get_Hardware_SerNum2(void);
   virtual void set_Hardware_SerNum2(UnicodeString Hardware_SerNum2);

   virtual UnicodeString get_Hardware_Name(void);
   virtual void set_Hardware_Name(UnicodeString Hardware_Name);

   virtual void UpdateForm(void);
   virtual void OpenTable(void);
};
#define CLSID_TREM_FormaGurAllDocImpl __uuidof(TREM_FormaGurAllDocImpl)
#endif
