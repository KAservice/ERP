#ifndef UREM_FormaGurZAktPrImplH
#define UREM_FormaGurZAktPrImplH
#include "IREM_FormaGurZAktPr.h"
#include "UREM_FormaGurZAktPr.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaGurZAktPrImpl)) TREM_FormaGurZAktPrImpl : public IREM_FormaGurZAktPr, IkanCallBack
{
public:
   TREM_FormaGurZAktPrImpl();
   ~TREM_FormaGurZAktPrImpl();
   TREM_FormaGurZAktPr * Object;
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

//IREM_FormaGurZAktPr
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IREM_DMGurZAktPr * get_DM(void);
   virtual void set_DM(IREM_DMGurZAktPr * DM);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual TDateTime get_PosNach(void);
   virtual void set_PosNach(TDateTime PosNach);

   virtual TDateTime get_PosCon(void);
   virtual void set_PosCon(TDateTime PosCon);

   virtual __int64 get_IdVibHardware(void);
   virtual void set_IdVibHardware(__int64 IdVibHardware);

   virtual __int64 get_IdVibZayavka(void);
   virtual void set_IdVibZayavka(__int64 IdVibZayavka);

   virtual void UpdateForm(void);
   virtual void OpenTable(void);
};
#define CLSID_TREM_FormaGurZAktPrImpl __uuidof(TREM_FormaGurZAktPrImpl)
#endif
