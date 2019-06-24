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



//параметры чека  //заголовок 	Parameters
// Обязательно long Тип расчета
//1 - Приход
//2 - Возврат прихода
//3 - Расход
//4 - Возврат расхода Формирование нового чека с заданным атрибутами.

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


//При формирование чека ККТ должен проверять, что передаваемый код системы налогообложения доступен для данного фискализированного ФН.
/// TaxVariant Обязательно long Код системы налогообложения. Коды системы налогообложения приведены в таблице "Системы налогообложения".
//Системы налогообложения
//Код Описание
//0  Общая
//1  Упрощенная Доход
//2  Упрощенная Доход минус Расход
//3  Единый налог на вмененный доход
//4  Единый сельскохозяйственный налог
//5  Патентная система налогообложения

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

//CustomerEmail Необязательно string Email покупателя
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

//CustomerPhone Необязательно string Телефонный номер покупателя
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

//AgentCompensation Необязательно double Размер вознаграждения агента
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

//AgentPhone Необязательно string Контактный телефон агента
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

//SubagentPhone Необязательно string Телефон платежного субагента
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

//ReceivePaymentsOperatorPhone  Необязательно string Телефон оператора по приему платежей
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

//MoneyTransferOperatorPhone  Необязательно string Телефон оператора по переводу денежных средств
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

//BankAgentPhone  Необязательно string Телефон банковского агента
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

//BankSubagentPhone  Необязательно string Телефон банковского субагента
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

//BankAgentOperation Необязательно string Операция банковского агента
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


//BankSubagentOperation Необязательно string Операция банковского субагента
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

//BankAgentCompensation  Необязательно double Размер вознаграждения банковского агента (субагента)
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


//MoneyTransferOperatorName Необязательно string Наименование оператора по переводу денежных средств
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


//MoneyTransferOperatorAddress  Необязательно string Адрес оператора по переводу денежных средств
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

//MoneyTransferOperatorVATIN  Необязательно string ИНН оператора по переводу денежных
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

 //ФОРМИРОВАНИЕ ТАБЛИЦЫ ЧЕКА
 //позиции чека, тип строки       1-фиск строка 2- текстовая строка 3-штрих код
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

	//FiscalString  Регистрирует фискальную строку с переданными реквизитами.
	//Name Да string  Наименование товара
	//При печати длинных фискальных строк необходимо делать перенос на следующую строку.
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

	 //Quantity Да double Количество товара
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

	//Price Да double Цена единицы товара без учета скидок/наценок
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

	//Amount Да double Конечная сумма по позиции чека (с учетом всех скидок/наценок)
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

	//Department Нет long Отдел, по которому ведется продажа
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

	//Tax Да string Ставка НДС. Список значений:
					  //	"18" - НДС 18
					  //	"10" - НДС 10
					  //	"0" - НДС 0
					  //	"none" - БЕЗ НДС


					  	//case 0:    //не задан
						//case 1:    //без ндс
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


	//TextString  Печать текстовой строки.
	//Text Да string Строка с произвольным текстом
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

	//Barcode   Печать штрихкода. Осуществляется с автоматическим размером с выравниванием по центру чека.
	//BarcodeType Да string Строка, определяющая тип штрихкода

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
	//Тип штрихкода может иметь одно из следующих значений: EAN8, EAN13, CODE39, QR. В случае, если модель устройства не поддерживает печать штрихкода, выдается ошибка.

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

 //Payments  Параметры закрытия чека. Сумма всех видов оплат должна быть больше суммы открытого чека.


//Cash Нет decimal Сумма наличной оплаты Параметры закрытия чека. Сумма всех видов оплат должна быть больше суммы открытого чека.
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

//CashLessType1 Нет decimal Сумма электронной оплаты первого типа
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

//CashLessType2 Нет decimal Сумма электронной оплаты второго типа
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

//CashLessType3 Нет decimal Сумма электронной оплаты третьего типа
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
   //	Кассир (CashierName) STRING [IN] ФИО уполномоченного лица для проведения операции
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
//	Электронно (Electronically) BOOL (IN) Формирование чека в только электроном виде. Печать чека не осуществляется.
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
//	ФискальныйПризнак (FiscalSign) STRING [OUT] Фискальный признак
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
//	AddressSiteInspections (АдресСайтаПроверки) STRING [OUT] Адрес сайта проверки
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
