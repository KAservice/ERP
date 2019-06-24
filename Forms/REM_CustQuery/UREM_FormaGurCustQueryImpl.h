#ifndef UREM_FormaGurCustQueryImplH
#define UREM_FormaGurCustQueryImplH
#include "IREM_FormaGurCustQuery.h"
#include "UREM_FormaGurCustQuery.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaGurCustQueryImpl)) TREM_FormaGurCustQueryImpl : public IREM_FormaGurCustQuery, IkanCallBack
{
public:
   TREM_FormaGurCustQueryImpl();
   ~TREM_FormaGurCustQueryImpl();
   TREM_FormaGurCustQuery * Object;
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

//IREM_FormaGurCustQuery
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMGurCustQuery * get_DM(void);
   virtual void set_DM(IREM_DMGurCustQuery * DM);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual TDateTime get_PosNach(void);
   virtual void set_PosNach(TDateTime PosNach);

   virtual TDateTime get_PosCon(void);
   virtual void set_PosCon(TDateTime PosCon);

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

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaGurCustQueryImpl __uuidof(TREM_FormaGurCustQueryImpl)
#endif
