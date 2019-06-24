//---------------------------------------------------------------------------


#pragma hdrstop

#include "UkasVikiImpl.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TkasVikiFRImpl::TkasVikiFRImpl()
{
Object=new TkasVikiFR();
NumRefs=0;
++NumObject;
flDeleteObject=true;
}
//---------------------------------------------------------------
TkasVikiFRImpl::~TkasVikiFRImpl()
{

delete Object;

--NumObject;
}
//---------------------------------------------------------------
void TkasVikiFRImpl::DeleteImpl(void)
{
flDeleteObject=false;
delete this;
}
//---------------------------------------------------------------
int TkasVikiFRImpl::kanQueryInterface(REFIID id_interface, void ** ppv)
 {
int result=0;
if (id_interface==IID_IkanUnknown)
   {
   *ppv=static_cast<IkanUnknown*> (this);
   result=-1;
   }
else if (id_interface==IID_IMainInterface)
   {
   *ppv=static_cast<IMainInterface*> (this);
   result=-1;
   }
else if (id_interface==IID_IFiskReg)
   {
   *ppv=static_cast<IFiskReg*> (this);
   result=-1;
   }
else
   {
   *ppv=NULL;
   result=1;
   return result;
   }
kanAddRef();
return result;
}
//---------------------------------------------------------------
int TkasVikiFRImpl::kanAddRef(void)
{
return (++NumRefs);
}
//---------------------------------------------------------------
int TkasVikiFRImpl::kanRelease(void)
{
if (--NumRefs==0)
   {
   delete this;
   return 0;
   }
return NumRefs;
}
//---------------------------------------------------------------

//IMainInterface

//---------------------------------------------------------------
int  TkasVikiFRImpl::get_CodeError(void)
{
return Object->CodeError;
}
//---------------------------------------------------------------
void TkasVikiFRImpl::set_CodeError(int CodeError)
{
}
//---------------------------------------------------------------
UnicodeString  TkasVikiFRImpl::get_TextError(void)
{
return Object->TextError;
}
//---------------------------------------------------------------
void TkasVikiFRImpl::set_TextError(UnicodeString  TextError)
{
}
//---------------------------------------------------------------
int TkasVikiFRImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TkasVikiFRImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TkasVikiFRImpl::Done(void)
{
return Object->Done();
}
//---------------------------------------------------------------

//IFiskReg

//----------------------------------------------------------------
int TkasVikiFRImpl::get_Number(void)
{
return Object->Number;
}
//---------------------------------------------------------------
void TkasVikiFRImpl::set_Number(int Number)
{
Object->Number=Number;
}
//---------------------------------------------------------------
AnsiString TkasVikiFRImpl::get_Modul(void)
{
return Object->Modul;
}
//---------------------------------------------------------------
void TkasVikiFRImpl::set_Modul(AnsiString Modul)
{
Object->Modul=Modul;
}
//---------------------------------------------------------------
UnicodeString TkasVikiFRImpl::get_Name(void)
{
return Object->Name;
}
//---------------------------------------------------------------
void TkasVikiFRImpl::set_Name(UnicodeString Name)
{
Object->Name=Name;
}
//---------------------------------------------------------------
bool TkasVikiFRImpl::get_Error(void)
{
return Object->Error;
}
//---------------------------------------------------------------
void TkasVikiFRImpl::set_Error(bool Error)
{
Object->Error=Error;
}

//---------------------------------------------------------------
UnicodeString TkasVikiFRImpl::get_TextErrorNoConnect(void)
{
return Object->TextErrorNoConnect;
}
//---------------------------------------------------------------
void TkasVikiFRImpl::set_TextErrorNoConnect(UnicodeString TextErrorNoConnect)
{
Object->TextErrorNoConnect=TextErrorNoConnect;
}
//---------------------------------------------------------------
bool TkasVikiFRImpl::get_ConnectFR(void)
{
return Object->ConnectFR;
}
//---------------------------------------------------------------
void TkasVikiFRImpl::set_ConnectFR(bool ConnectFR)
{
Object->ConnectFR=ConnectFR;
}
//---------------------------------------------------------------
int TkasVikiFRImpl::get_NumberCheck(void)
{
return Object->NumberCheck;
}
//---------------------------------------------------------------
void TkasVikiFRImpl::set_NumberCheck(int NumberCheck)
{
Object->NumberCheck=NumberCheck;
}
//---------------------------------------------------------------
int TkasVikiFRImpl::get_NumberKL(void)
{
return Object->NumberKL;
}
//---------------------------------------------------------------
void TkasVikiFRImpl::set_NumberKL(int NumberKL)
{
Object->NumberKL=NumberKL;
}
//---------------------------------------------------------------
UnicodeString TkasVikiFRImpl::get_SerialNumberKKM(void)
{
return Object->SerialNumberKKM;
}
//---------------------------------------------------------------
void TkasVikiFRImpl::set_SerialNumberKKM(UnicodeString SerialNumberKKM)
{
Object->SerialNumberKKM=SerialNumberKKM;
}
//---------------------------------------------------------------
UnicodeString TkasVikiFRImpl::get_RegNumberKKM(void)
{
return Object->RegNumberKKM;
}
//---------------------------------------------------------------
void TkasVikiFRImpl::set_RegNumberKKM(UnicodeString RegNumberKKM)
{
Object->RegNumberKKM=RegNumberKKM;
}
//---------------------------------------------------------------
UnicodeString TkasVikiFRImpl::get_ModelKKM(void)
{
return Object->ModelKKM;
}
//---------------------------------------------------------------
void TkasVikiFRImpl::set_ModelKKM(UnicodeString ModelKKM)
{
Object->ModelKKM=ModelKKM;
}
//---------------------------------------------------------------
bool TkasVikiFRImpl::InitDevice()
{

//return Object->InitDevice();
return true;
}
//---------------------------------------------------------------
bool TkasVikiFRImpl::Connect(int number_port, UnicodeString baud_rate,	UnicodeString password)
{
return Object->Connect(number_port,baud_rate,password);
}
//---------------------------------------------------------------
bool TkasVikiFRImpl::Disconnect(void)
{
return Object->Disconnect();
}
//---------------------------------------------------------------
bool TkasVikiFRImpl::PrintString(UnicodeString str,int size_font, int girn, int alignment, bool ch_lenta, bool kontr_lenta, bool word_wrap)
{
return Object->PrintString(str,size_font,girn,alignment,ch_lenta,kontr_lenta,word_wrap);
}
//---------------------------------------------------------------
bool TkasVikiFRImpl::PrintFiscalCheck(double sum, int department,double oplata_nal,double oplata_bank_card,double oplata_plat_card,double oplata_credit_card,int operation)
{
return Object->PrintFiscalCheck(sum,department,oplata_nal,oplata_bank_card,oplata_plat_card,oplata_credit_card,operation);
}
//---------------------------------------------------------------
bool TkasVikiFRImpl::PrintNoFiscalCheck(double sum,int department,double oplata_nal,double oplata_bank_card,double oplata_plat_card,double oplata_credit_card,int operation)
{
return Object->PrintNoFiscalCheck(sum,department,oplata_nal,oplata_bank_card,oplata_plat_card,oplata_credit_card,operation);
}
//---------------------------------------------------------------
bool TkasVikiFRImpl::PrintXReport(void)
{
return Object->PrintXReport();
}
//---------------------------------------------------------------
bool TkasVikiFRImpl::PrintZReport(void)
{
return Object->PrintZReport();
}
//---------------------------------------------------------------
bool TkasVikiFRImpl::PrintPoOtdelamReport(void)
{
return Object->PrintPoOtdelamReport();
}
//---------------------------------------------------------------
bool TkasVikiFRImpl::Cut(int TypeCut)
{
return Object->Cut(TypeCut);
}
//---------------------------------------------------------------
bool TkasVikiFRImpl::Vnesenie(double sum)
{
return Object->Vnesenie(sum);
}
//---------------------------------------------------------------
bool TkasVikiFRImpl::Snatie(double sum)
{
return Object->Snatie(sum);
}
//---------------------------------------------------------------
bool TkasVikiFRImpl::PrintLine(void)
{
return Object->PrintLine();
}
//---------------------------------------------------------------
bool TkasVikiFRImpl::OpenNoFiscalCheck(void)
{
return Object->OpenNoFiscalCheck();
}
//---------------------------------------------------------------
bool TkasVikiFRImpl::CloseNoFiscalCheck(void)
{
return Object->CloseNoFiscalCheck();
}
//---------------------------------------------------------------
bool TkasVikiFRImpl::GetSostKKM(void)
{
return Object->GetSostKKM();
}
//---------------------------------------------------------------
bool TkasVikiFRImpl::ProvVosmPrintCheck(void)
{
return Object->ProvVosmPrintCheck();
}
//---------------------------------------------------------------
TTime TkasVikiFRImpl::GetTime(void)
{
return Object->GetTime();
}
//---------------------------------------------------------------
TDate TkasVikiFRImpl::GetDate(void)
{
return Object->GetDate();
}
//---------------------------------------------------------------
bool TkasVikiFRImpl::SetTime(TTime time)
{
return Object->SetTime(time);
}
//---------------------------------------------------------------
bool TkasVikiFRImpl::SetDate(TDate date)
{
return Object->SetDate(date);
}
//---------------------------------------------------------------