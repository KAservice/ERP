//---------------------------------------------------------------------------


#pragma hdrstop

#include "U1COnLineFRImpl.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
T1COnLineFRImpl::T1COnLineFRImpl()
{
Object=new T1COnLineFR();
NumRefs=0;
++NumObject;
flDeleteObject=true;
}
//---------------------------------------------------------------
T1COnLineFRImpl::~T1COnLineFRImpl()
{

delete Object;

--NumObject;
}
//---------------------------------------------------------------
void T1COnLineFRImpl::DeleteImpl(void)
{
flDeleteObject=false;
delete this;
}
//---------------------------------------------------------------
int T1COnLineFRImpl::kanQueryInterface(REFIID id_interface, void ** ppv)
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
int T1COnLineFRImpl::kanAddRef(void)
{
return (++NumRefs);
}
//---------------------------------------------------------------
int T1COnLineFRImpl::kanRelease(void)
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
int  T1COnLineFRImpl::get_CodeError(void)
{
return Object->CodeError;
}
//---------------------------------------------------------------
void T1COnLineFRImpl::set_CodeError(int CodeError)
{
}
//---------------------------------------------------------------
UnicodeString  T1COnLineFRImpl::get_TextError(void)
{
return Object->TextError;
}
//---------------------------------------------------------------
void T1COnLineFRImpl::set_TextError(UnicodeString  TextError)
{
}
//---------------------------------------------------------------
int T1COnLineFRImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_T1COnLineFRImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int T1COnLineFRImpl::Done(void)
{
return Object->Done();
}
//---------------------------------------------------------------

//IFiskReg

//----------------------------------------------------------------
int T1COnLineFRImpl::get_Number(void)
{
return Object->Number;
}
//---------------------------------------------------------------
void T1COnLineFRImpl::set_Number(int Number)
{
Object->Number=Number;
}
//---------------------------------------------------------------
AnsiString T1COnLineFRImpl::get_Modul(void)
{
return Object->Modul;
}
//---------------------------------------------------------------
void T1COnLineFRImpl::set_Modul(AnsiString Modul)
{
Object->Modul=Modul;
}
//---------------------------------------------------------------
UnicodeString T1COnLineFRImpl::get_Name(void)
{
return Object->Name;
}
//---------------------------------------------------------------
void T1COnLineFRImpl::set_Name(UnicodeString Name)
{
Object->Name=Name;
}
//---------------------------------------------------------------
bool T1COnLineFRImpl::get_Error(void)
{
return Object->Error;
}
//---------------------------------------------------------------
void T1COnLineFRImpl::set_Error(bool Error)
{
Object->Error=Error;
}

//---------------------------------------------------------------
UnicodeString T1COnLineFRImpl::get_TextErrorNoConnect(void)
{
return Object->TextErrorNoConnect;
}
//---------------------------------------------------------------
void T1COnLineFRImpl::set_TextErrorNoConnect(UnicodeString TextErrorNoConnect)
{
Object->TextErrorNoConnect=TextErrorNoConnect;
}
//---------------------------------------------------------------
bool T1COnLineFRImpl::get_ConnectFR(void)
{
return Object->ConnectFR;
}
//---------------------------------------------------------------
void T1COnLineFRImpl::set_ConnectFR(bool ConnectFR)
{
Object->ConnectFR=ConnectFR;
}
//---------------------------------------------------------------
int T1COnLineFRImpl::get_NumberCheck(void)
{
return Object->NumberCheck;
}
//---------------------------------------------------------------
void T1COnLineFRImpl::set_NumberCheck(int NumberCheck)
{
Object->NumberCheck=NumberCheck;
}
//---------------------------------------------------------------
int T1COnLineFRImpl::get_NumberKL(void)
{
return Object->NumberKL;
}
//---------------------------------------------------------------
void T1COnLineFRImpl::set_NumberKL(int NumberKL)
{
Object->NumberKL=NumberKL;
}
//---------------------------------------------------------------
UnicodeString T1COnLineFRImpl::get_SerialNumberKKM(void)
{
return Object->SerialNumberKKM;
}
//---------------------------------------------------------------
void T1COnLineFRImpl::set_SerialNumberKKM(UnicodeString SerialNumberKKM)
{
Object->SerialNumberKKM=SerialNumberKKM;
}
//---------------------------------------------------------------
UnicodeString T1COnLineFRImpl::get_RegNumberKKM(void)
{
return Object->RegNumberKKM;
}
//---------------------------------------------------------------
void T1COnLineFRImpl::set_RegNumberKKM(UnicodeString RegNumberKKM)
{
Object->RegNumberKKM=RegNumberKKM;
}
//---------------------------------------------------------------
UnicodeString T1COnLineFRImpl::get_ModelKKM(void)
{
return Object->ModelKKM;
}
//---------------------------------------------------------------
void T1COnLineFRImpl::set_ModelKKM(UnicodeString ModelKKM)
{
Object->ModelKKM=ModelKKM;
}
//---------------------------------------------------------------
bool T1COnLineFRImpl::InitDevice()
{

//return Object->InitDevice();
return true;
}
//---------------------------------------------------------------
bool T1COnLineFRImpl::Connect(int number_port, UnicodeString baud_rate,	UnicodeString password)
{
return Object->Connect(number_port,baud_rate,password);
}
//---------------------------------------------------------------
bool T1COnLineFRImpl::Disconnect(void)
{
return Object->Disconnect();
}
//---------------------------------------------------------------
bool T1COnLineFRImpl::PrintString(UnicodeString str,int size_font, int girn, int alignment, bool ch_lenta, bool kontr_lenta, bool word_wrap)
{
return Object->PrintString(str,size_font,girn,alignment,ch_lenta,kontr_lenta,word_wrap);
}
//---------------------------------------------------------------
bool T1COnLineFRImpl::PrintFiscalCheck(double sum, int department,double oplata_nal,double oplata_bank_card,double oplata_plat_card,double oplata_credit_card,int operation)
{
return Object->PrintFiscalCheck(sum,department,oplata_nal,oplata_bank_card,oplata_plat_card,oplata_credit_card,operation);
}
//---------------------------------------------------------------
bool T1COnLineFRImpl::PrintNoFiscalCheck(double sum,int department,double oplata_nal,double oplata_bank_card,double oplata_plat_card,double oplata_credit_card,int operation)
{
return Object->PrintNoFiscalCheck(sum,department,oplata_nal,oplata_bank_card,oplata_plat_card,oplata_credit_card,operation);
}
//---------------------------------------------------------------
bool T1COnLineFRImpl::PrintXReport(void)
{
return Object->PrintXReport();
}
//---------------------------------------------------------------
bool T1COnLineFRImpl::PrintZReport(void)
{
return Object->PrintZReport();
}
//---------------------------------------------------------------
bool T1COnLineFRImpl::PrintPoOtdelamReport(void)
{
return Object->PrintPoOtdelamReport();
}
//---------------------------------------------------------------
bool T1COnLineFRImpl::Cut(int TypeCut)
{
return Object->Cut(TypeCut);
}
//---------------------------------------------------------------
bool T1COnLineFRImpl::Vnesenie(double sum)
{
return Object->Vnesenie(sum);
}
//---------------------------------------------------------------
bool T1COnLineFRImpl::Snatie(double sum)
{
return Object->Snatie(sum);
}
//---------------------------------------------------------------
bool T1COnLineFRImpl::PrintLine(void)
{
return Object->PrintLine();
}
//---------------------------------------------------------------
bool T1COnLineFRImpl::OpenNoFiscalCheck(void)
{
return Object->OpenNoFiscalCheck();
}
//---------------------------------------------------------------
bool T1COnLineFRImpl::CloseNoFiscalCheck(void)
{
return Object->CloseNoFiscalCheck();
}
//---------------------------------------------------------------
bool T1COnLineFRImpl::GetSostKKM(void)
{
return Object->GetSostKKM();
}
//---------------------------------------------------------------
bool T1COnLineFRImpl::ProvVosmPrintCheck(void)
{
return Object->ProvVosmPrintCheck();
}
//---------------------------------------------------------------
TTime T1COnLineFRImpl::GetTime(void)
{
return Object->GetTime();
}
//---------------------------------------------------------------
TDate T1COnLineFRImpl::GetDate(void)
{
return Object->GetDate();
}
//---------------------------------------------------------------
bool T1COnLineFRImpl::SetTime(TTime time)
{
return Object->SetTime(time);
}
//---------------------------------------------------------------
bool T1COnLineFRImpl::SetDate(TDate date)
{
return Object->SetDate(date);
}
//---------------------------------------------------------------
   //IFiskRegOnLine
bool T1COnLineFRImpl::OpenShift(void)
{
return Object->OpenShift();


}
//-----------------------------------------------------------------
bool T1COnLineFRImpl::CloseShift(void)
{

return Object->CloseShift();
}
//-----------------------------------------------------------------
bool T1COnLineFRImpl::InitCheck(void)

{

return Object->InitCheck();
}
//------------------------------------------------------------------
bool T1COnLineFRImpl::CreateHeaderFiscalCheck(void)

{

return Object->CreateHeaderFiscalCheck();
}
//-----------------------------------------------------------------
bool T1COnLineFRImpl::CreateFooterFiscalCheck(void)

{

return Object->CreateFooterFiscalCheck();
}
//-----------------------------------------------------------------
 bool T1COnLineFRImpl::AddFiscalString(void)
{

return Object->AddFiscalString();
}
//-----------------------------------------------------------------



//��������� ����  //��������� 	Parameters
// ����������� long ��� �������
//1 - ������
//2 - ������� �������
//3 - ������
//4 - ������� ������� ������������ ������ ���� � �������� ����������.

int T1COnLineFRImpl::get_PaymentType(void)
{
return Object->PaymentType;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_PaymentType(int PaymentType)
{
Object->PaymentType=PaymentType;
}
//---------------------------------------------------------------


//��� ������������ ���� ��� ������ ���������, ��� ������������ ��� ������� ��������������� �������� ��� ������� ������������������ ��.
/// TaxVariant ����������� long ��� ������� ���������������. ���� ������� ��������������� ��������� � ������� "������� ���������������".
//������� ���������������
//��� ��������
//0  �����
//1  ���������� �����
//2  ���������� ����� ����� ������
//3  ������ ����� �� ��������� �����
//4  ������ �������������������� �����
//5  ��������� ������� ���������������

int T1COnLineFRImpl::get_TaxVariant(void)
{
return Object->TaxVariant;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_TaxVariant(int TaxVariant)
{
Object->TaxVariant=TaxVariant;
}
//---------------------------------------------------------------

//CustomerEmail ������������� string Email ����������
UnicodeString T1COnLineFRImpl::get_CustomerEmail(void)
{
return Object->CustomerEmail;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_CustomerEmail(UnicodeString CustomerEmail)
{
Object->CustomerEmail=CustomerEmail;
}
//---------------------------------------------------------------

//CustomerPhone ������������� string ���������� ����� ����������
UnicodeString T1COnLineFRImpl::get_CustomerPhone(void)
{
return Object->CustomerPhone ;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_CustomerPhone(UnicodeString CustomerPhone  )
{
Object->CustomerPhone =CustomerPhone ;
}
//---------------------------------------------------------------

//AgentCompensation ������������� double ������ �������������� ������
double T1COnLineFRImpl::get_AgentCompensation(void)
{
return Object->AgentCompensation;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_AgentCompensation(double AgentCompensation)
{
Object->AgentCompensation=AgentCompensation;
}
//---------------------------------------------------------------

//AgentPhone ������������� string ���������� ������� ������
UnicodeString T1COnLineFRImpl::get_AgentPhone(void)
{
return Object->AgentPhone;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_AgentPhone(UnicodeString AgentPhone  )
{
Object->AgentPhone=AgentPhone;
}
//---------------------------------------------------------------

//SubagentPhone ������������� string ������� ���������� ���������
UnicodeString T1COnLineFRImpl::get_SubagentPhone(void)
{
return Object->SubagentPhone;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_SubagentPhone(UnicodeString SubagentPhone  )
{
Object->SubagentPhone=SubagentPhone;
}
//---------------------------------------------------------------

//ReceivePaymentsOperatorPhone  ������������� string ������� ��������� �� ������ ��������
UnicodeString T1COnLineFRImpl::get_ReceivePaymentsOperatorPhone(void)
{
return Object->ReceivePaymentsOperatorPhone;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_ReceivePaymentsOperatorPhone(UnicodeString ReceivePaymentsOperatorPhone  )
{
Object->ReceivePaymentsOperatorPhone=ReceivePaymentsOperatorPhone;
}
//---------------------------------------------------------------

//MoneyTransferOperatorPhone  ������������� string ������� ��������� �� �������� �������� �������
UnicodeString T1COnLineFRImpl::get_MoneyTransferOperatorPhone(void)
{
return Object->MoneyTransferOperatorPhone;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_MoneyTransferOperatorPhone(UnicodeString MoneyTransferOperatorPhone  )
{
Object->MoneyTransferOperatorPhone=MoneyTransferOperatorPhone;
}
//---------------------------------------------------------------

//BankAgentPhone  ������������� string ������� ����������� ������
UnicodeString T1COnLineFRImpl::get_BankAgentPhone(void)
{
return Object->BankAgentPhone;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_BankAgentPhone(UnicodeString BankAgentPhone  )
{
Object->BankAgentPhone=BankAgentPhone;
}
//---------------------------------------------------------------

//BankSubagentPhone  ������������� string ������� ����������� ���������
UnicodeString T1COnLineFRImpl::get_BankSubagentPhone(void)
{
return Object->BankSubagentPhone;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_BankSubagentPhone(UnicodeString BankSubagentPhone )
{
Object->BankSubagentPhone=BankSubagentPhone;
}
//---------------------------------------------------------------

//BankAgentOperation ������������� string �������� ����������� ������
UnicodeString T1COnLineFRImpl::get_BankAgentOperation(void)
{
return Object->BankAgentOperation;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_BankAgentOperation(UnicodeString BankAgentOperation)
{
Object->BankAgentOperation=BankAgentOperation;
}
//---------------------------------------------------------------


//BankSubagentOperation ������������� string �������� ����������� ���������
UnicodeString T1COnLineFRImpl::get_BankSubagentOperation(void)
{
return Object->BankSubagentOperation;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_BankSubagentOperation(UnicodeString BankSubagentOperation)
{
Object->BankSubagentOperation=BankSubagentOperation;
}
//---------------------------------------------------------------

//BankAgentCompensation  ������������� double ������ �������������� ����������� ������ (���������)
double T1COnLineFRImpl::get_BankAgentCompensation(void)
{
return Object->BankAgentCompensation;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_BankAgentCompensation(double BankAgentCompensation)
{
Object->BankAgentCompensation=BankAgentCompensation;
}
//---------------------------------------------------------------


//MoneyTransferOperatorName ������������� string ������������ ��������� �� �������� �������� �������
UnicodeString T1COnLineFRImpl::get_MoneyTransferOperatorName(void)
{
return Object->MoneyTransferOperatorName;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_MoneyTransferOperatorName(UnicodeString MoneyTransferOperatorName)
{
Object->MoneyTransferOperatorName=MoneyTransferOperatorName;
}
//---------------------------------------------------------------


//MoneyTransferOperatorAddress  ������������� string ����� ��������� �� �������� �������� �������
UnicodeString T1COnLineFRImpl::get_MoneyTransferOperatorAddress(void)
{
return Object->MoneyTransferOperatorAddress;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_MoneyTransferOperatorAddress(UnicodeString MoneyTransferOperatorAddress)
{
Object->MoneyTransferOperatorAddress=MoneyTransferOperatorAddress;
}
//---------------------------------------------------------------

//MoneyTransferOperatorVATIN  ������������� string ��� ��������� �� �������� ��������
UnicodeString T1COnLineFRImpl::get_MoneyTransferOperatorVATIN(void)
{
return Object->MoneyTransferOperatorVATIN;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_MoneyTransferOperatorVATIN(UnicodeString MoneyTransferOperatorVATIN)
{
Object->MoneyTransferOperatorVATIN=MoneyTransferOperatorVATIN;
}
//---------------------------------------------------------------

 //������������ ������� ����
 //������� ����, ��� ������       1-���� ������ 2- ��������� ������ 3-����� ���
int T1COnLineFRImpl::get_TypeFiscalString(void)
{
return Object->TypeFiscalString;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_TypeFiscalString(int TypeFiscalString)
{
Object->TypeFiscalString=TypeFiscalString;
}
//---------------------------------------------------------------

	//FiscalString  ������������ ���������� ������ � ����������� �����������.
	//Name �� string  ������������ ������
	//��� ������ ������� ���������� ����� ���������� ������ ������� �� ��������� ������.
UnicodeString T1COnLineFRImpl::get_NameNom(void)
{
return Object->NameNom;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_NameNom(UnicodeString NameNom)
{
Object->NameNom=NameNom;
}
//---------------------------------------------------------------

	 //Quantity �� double ���������� ������
double T1COnLineFRImpl::get_Quantity(void)
{
return Object->Quantity;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_Quantity(double Quantity)
{
Object->Quantity=Quantity;
}
//---------------------------------------------------------------

	//Price �� double ���� ������� ������ ��� ����� ������/�������
double T1COnLineFRImpl::get_Price(void)
{
return Object->Price;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_Price(double Price)
{
Object->Price=Price;
}
//---------------------------------------------------------------

	//Amount �� double �������� ����� �� ������� ���� (� ������ ���� ������/�������)
double T1COnLineFRImpl::get_Amount(void)
{
return Object->Amount;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_Amount(double Amount)
{
Object->Amount=Amount;
}
//---------------------------------------------------------------

	//Department ��� long �����, �� �������� ������� �������
int T1COnLineFRImpl::get_Department(void)
{
return Object->Department;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_Department(int Department)
{
Object->Department=Department;
}
//---------------------------------------------------------------

	//Tax �� string ������ ���. ������ ��������:
					  //	"18" - ��� 18
					  //	"10" - ��� 10
					  //	"0" - ��� 0
					  //	"none" - ��� ���


					  	//case 0:    //�� �����
						//case 1:    //��� ���
						//case 2:    //0%
						//case 3:    //10%
						//case 4:    //18%
int T1COnLineFRImpl::get_Tax(void)
{
return Object->Tax;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_Tax(int Tax)
{
Object->Tax=Tax;
}
//---------------------------------------------------------------


	//TextString  ������ ��������� ������.
	//Text �� string ������ � ������������ �������
UnicodeString T1COnLineFRImpl::get_TextString(void)
{
return Object->TextString;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_TextString(UnicodeString TextString)
{
Object->TextString=TextString;
}
//---------------------------------------------------------------

	//Barcode   ������ ���������. �������������� � �������������� �������� � ������������� �� ������ ����.
	//BarcodeType �� string ������, ������������ ��� ���������

UnicodeString T1COnLineFRImpl::get_BarcodeType(void)
{
return Object->BarcodeType;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_BarcodeType(UnicodeString BarcodeType)
{
Object->BarcodeType=BarcodeType;
}
//---------------------------------------------------------------
	//��� ��������� ����� ����� ���� �� ��������� ��������: EAN8, EAN13, CODE39, QR. � ������, ���� ������ ���������� �� ������������ ������ ���������, �������� ������.

UnicodeString T1COnLineFRImpl::get_Barcode(void)
{
return Object->Barcode;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_Barcode(UnicodeString Barcode)
{
Object->Barcode=Barcode;
}
//---------------------------------------------------------------

 //Payments  ��������� �������� ����. ����� ���� ����� ����� ������ ���� ������ ����� ��������� ����.


//Cash ��� decimal ����� �������� ������ ��������� �������� ����. ����� ���� ����� ����� ������ ���� ������ ����� ��������� ����.
double T1COnLineFRImpl::get_Cash(void)
{
return Object->Cash;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_Cash(double Cash)
{
Object->Cash=Cash;
}
//---------------------------------------------------------------

//CashLessType1 ��� decimal ����� ����������� ������ ������� ����
double T1COnLineFRImpl::get_CashLessType1(void)
{
return Object->CashLessType1;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_CashLessType1(double CashLessType1)
{
Object->CashLessType1=CashLessType1;
}
//---------------------------------------------------------------

//CashLessType2 ��� decimal ����� ����������� ������ ������� ����
double T1COnLineFRImpl::get_CashLessType2(void)
{
return Object->CashLessType2;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_CashLessType2(double CashLessType2)
{
Object->CashLessType2=CashLessType2;
}
//---------------------------------------------------------------

//CashLessType3 ��� decimal ����� ����������� ������ �������� ����
double T1COnLineFRImpl::get_CashLessType3(void)
{
return Object->CashLessType3;
}
//-----------------------------------------------------------------------------
void T1COnLineFRImpl::set_CashLessType3(double CashLessType3)
{
Object->CashLessType3=CashLessType3;
}
//---------------------------------------------------------------
UnicodeString T1COnLineFRImpl::GetParameters(void)
{
return Object->GetParameters();
}
//-------------------------------------------------------------
bool T1COnLineFRImpl::SetParameter(UnicodeString name_parameter, UnicodeString value_parameter)
{

return Object->SetParameter(name_parameter, value_parameter);
}
//-----------------------------------------------------------
UnicodeString T1COnLineFRImpl::GetAdditionalActions(void)
{
return Object->GetAdditionalActions();
}
//-----------------------------------------------------------------
bool T1COnLineFRImpl::DoAdditionalAction(UnicodeString name_action)
{
return Object->DoAdditionalAction(name_action);
}
//--------------------------------------------------------------------
   //	������ (CashierName) STRING [IN] ��� ��������������� ���� ��� ���������� ��������
UnicodeString T1COnLineFRImpl::get_CashierName(void)
{
return Object->CashierName;
}
//--------------------------------------------------------------------------
void T1COnLineFRImpl::set_CashierName(UnicodeString CashierName)
{
Object->CashierName=CashierName;
}
//--------------------------------------------------------------------------
//	���������� (Electronically) BOOL (IN) ������������ ���� � ������ ���������� ����. ������ ���� �� ��������������.
bool T1COnLineFRImpl::get_Electronically(void)
{
return Object->Electronically;
}
//--------------------------------------------------------------------------
void T1COnLineFRImpl::set_Electronically(bool Electronically)
{
Object->Electronically=Electronically;
}
//---------------------------------------------------------------------------
//	����������������� (FiscalSign) STRING [OUT] ���������� �������
UnicodeString T1COnLineFRImpl::get_FiscalSign(void)
{
return Object->FiscalSign;
}
//---------------------------------------------------------------------------
void T1COnLineFRImpl::set_FiscalSign(UnicodeString FiscalSign)
{
Object->FiscalSign=FiscalSign;
}
//------------------------------------------------------------------------
//	AddressSiteInspections (������������������) STRING [OUT] ����� ����� ��������
UnicodeString T1COnLineFRImpl::get_AddressSiteInspections(void)
{
return Object->AddressSiteInspections;
}
//----------------------------------------------------------------------
void T1COnLineFRImpl::set_AddressSiteInspections(UnicodeString AddressSiteInspections)
{
Object->AddressSiteInspections=AddressSiteInspections;
}
//-------------------------------------------------------------------------
