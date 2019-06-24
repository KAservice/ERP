//---------------------------------------------------------------------------

#ifndef UkasVikiImplH
#define UkasVikiImplH
//---------------------------------------------------------------------------
#include "IFiskReg.h"
#include "UkasVikiFR.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TkasVikiFRImpl)) TkasVikiFRImpl : public IFiskReg
{
public:
   TkasVikiFRImpl();
   ~TkasVikiFRImpl();
   TkasVikiFR * Object;
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

//IFiskReg
   virtual int get_Number(void);
   virtual void set_Number(int Number);

   virtual AnsiString get_Modul(void);
   virtual void set_Modul(AnsiString Modul);

   virtual UnicodeString get_Name(void);
   virtual void set_Name(UnicodeString Name);

   virtual bool get_Error(void);
   virtual void set_Error(bool Error);


   virtual UnicodeString get_TextErrorNoConnect(void);
   virtual void set_TextErrorNoConnect(UnicodeString TextErrorNoConnect);

   virtual bool get_ConnectFR(void);
   virtual void set_ConnectFR(bool ConnectFR);

   virtual int get_NumberCheck(void);
   virtual void set_NumberCheck(int NumberCheck);

   virtual int get_NumberKL(void);
   virtual void set_NumberKL(int NumberKL);

   virtual UnicodeString get_SerialNumberKKM(void);
   virtual void set_SerialNumberKKM(UnicodeString SerialNumberKKM);

   virtual UnicodeString get_RegNumberKKM(void);
   virtual void set_RegNumberKKM(UnicodeString RegNumberKKM);

   virtual UnicodeString get_ModelKKM(void);
   virtual void set_ModelKKM(UnicodeString ModelKKM);

   virtual bool InitDevice();
   virtual bool Connect(int number_port, UnicodeString baud_rate,	UnicodeString password);
   virtual bool Disconnect(void);
   virtual bool PrintString(UnicodeString str,int size_font, int girn, int alignment, bool ch_lenta, bool kontr_lenta, bool word_wrap);
   virtual bool PrintFiscalCheck(double sum, int department,double oplata_nal,double oplata_bank_card,double oplata_plat_card,double oplata_credit_card,int operation);
   virtual bool PrintNoFiscalCheck(double sum,int department,double oplata_nal,double oplata_bank_card,double oplata_plat_card,double oplata_credit_card,int operation);
   virtual bool PrintXReport(void);
   virtual bool PrintZReport(void);
   virtual bool PrintPoOtdelamReport(void);
   virtual bool Cut(int TypeCut);
   virtual bool Vnesenie(double sum);
   virtual bool Snatie(double sum);
   virtual bool PrintLine(void);
   virtual bool OpenNoFiscalCheck(void);
   virtual bool CloseNoFiscalCheck(void);
   virtual bool GetSostKKM(void);
   virtual bool ProvVosmPrintCheck(void);
   virtual TTime GetTime(void);
   virtual TDate GetDate(void);
   virtual bool SetTime(TTime time);
   virtual bool SetDate(TDate date);


};
#define CLSID_TkasVikiFRImpl __uuidof(TkasVikiFRImpl)
#endif
