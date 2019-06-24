#include "vcl.h"
#pragma hdrstop


#include "UkasMSKFRImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TkasMSKFRImpl::TkasMSKFRImpl()
{                                            
Object=new TkasMSKFR();
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TkasMSKFRImpl::~TkasMSKFRImpl()
{                                            

delete Object;

--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TkasMSKFRImpl::DeleteImpl(void)
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TkasMSKFRImpl::kanQueryInterface(REFIID id_interface, void ** ppv)
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
int TkasMSKFRImpl::kanAddRef(void)
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TkasMSKFRImpl::kanRelease(void)
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
int  TkasMSKFRImpl::get_CodeError(void)
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TkasMSKFRImpl::set_CodeError(int CodeError)
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TkasMSKFRImpl::get_TextError(void)
{                                                              
return Object->TextError;
}                                                              
//---------------------------------------------------------------
void TkasMSKFRImpl::set_TextError(UnicodeString  TextError)
{                                                              
}                                                              
//---------------------------------------------------------------
int TkasMSKFRImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TkasMSKFRImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TkasMSKFRImpl::Done(void)
{                                                              
return Object->Done();
}                                                              
//---------------------------------------------------------------

//IFiskReg

//----------------------------------------------------------------
int TkasMSKFRImpl::get_Number(void)
{
return Object->Number;
}
//---------------------------------------------------------------
void TkasMSKFRImpl::set_Number(int Number)
{
Object->Number=Number;
}
//---------------------------------------------------------------
AnsiString TkasMSKFRImpl::get_Modul(void)
{
return Object->Modul;
}
//---------------------------------------------------------------
void TkasMSKFRImpl::set_Modul(AnsiString Modul)
{
Object->Modul=Modul;
}
//---------------------------------------------------------------
UnicodeString TkasMSKFRImpl::get_Name(void)
{
return Object->Name;
}
//---------------------------------------------------------------
void TkasMSKFRImpl::set_Name(UnicodeString Name)
{
Object->Name=Name;
}
//---------------------------------------------------------------
bool TkasMSKFRImpl::get_Error(void)
{
return Object->Error;
}
//---------------------------------------------------------------
void TkasMSKFRImpl::set_Error(bool Error)
{
Object->Error=Error;
}

//---------------------------------------------------------------
UnicodeString TkasMSKFRImpl::get_TextErrorNoConnect(void)
{
return Object->TextErrorNoConnect;
}
//---------------------------------------------------------------
void TkasMSKFRImpl::set_TextErrorNoConnect(UnicodeString TextErrorNoConnect)
{
Object->TextErrorNoConnect=TextErrorNoConnect;
}
//---------------------------------------------------------------
bool TkasMSKFRImpl::get_ConnectFR(void)
{
return Object->ConnectFR;
}
//---------------------------------------------------------------
void TkasMSKFRImpl::set_ConnectFR(bool ConnectFR)
{
Object->ConnectFR=ConnectFR;
}
//---------------------------------------------------------------
int TkasMSKFRImpl::get_NumberCheck(void)
{
return Object->NumberCheck;
}
//---------------------------------------------------------------
void TkasMSKFRImpl::set_NumberCheck(int NumberCheck)
{
Object->NumberCheck=NumberCheck;
}
//---------------------------------------------------------------
int TkasMSKFRImpl::get_NumberKL(void)
{
return Object->NumberKL;
}
//---------------------------------------------------------------
void TkasMSKFRImpl::set_NumberKL(int NumberKL)
{
Object->NumberKL=NumberKL;
}
//---------------------------------------------------------------
UnicodeString TkasMSKFRImpl::get_SerialNumberKKM(void)
{
return Object->SerialNumberKKM;
}
//---------------------------------------------------------------
void TkasMSKFRImpl::set_SerialNumberKKM(UnicodeString SerialNumberKKM)
{
Object->SerialNumberKKM=SerialNumberKKM;
}
//---------------------------------------------------------------
UnicodeString TkasMSKFRImpl::get_RegNumberKKM(void)
{
return Object->RegNumberKKM;
}
//---------------------------------------------------------------
void TkasMSKFRImpl::set_RegNumberKKM(UnicodeString RegNumberKKM)
{
Object->RegNumberKKM=RegNumberKKM;
}
//---------------------------------------------------------------
UnicodeString TkasMSKFRImpl::get_ModelKKM(void)
{
return Object->ModelKKM;
}
//---------------------------------------------------------------
void TkasMSKFRImpl::set_ModelKKM(UnicodeString ModelKKM)
{
Object->ModelKKM=ModelKKM;
}
//---------------------------------------------------------------
bool TkasMSKFRImpl::InitDevice()
{

//return Object->InitDevice();
return true;
}
//---------------------------------------------------------------
bool TkasMSKFRImpl::Connect(int number_port, UnicodeString baud_rate,	UnicodeString password)
{
return Object->Connect(number_port,baud_rate,password);
}
//---------------------------------------------------------------
bool TkasMSKFRImpl::Disconnect(void)
{
return Object->Disconnect();
}
//---------------------------------------------------------------
bool TkasMSKFRImpl::PrintString(UnicodeString str,int size_font, int girn, int alignment, bool ch_lenta, bool kontr_lenta, bool word_wrap)
{
return Object->PrintString(str,size_font,girn,alignment,ch_lenta,kontr_lenta,word_wrap);
}
//---------------------------------------------------------------
bool TkasMSKFRImpl::PrintFiscalCheck(double sum, int department,double oplata_nal,double oplata_bank_card,double oplata_plat_card,double oplata_credit_card,int operation)
{
return Object->PrintFiscalCheck(sum,department,oplata_nal,oplata_bank_card,oplata_plat_card,oplata_credit_card,operation);
}
//---------------------------------------------------------------
bool TkasMSKFRImpl::PrintNoFiscalCheck(double sum,int department,double oplata_nal,double oplata_bank_card,double oplata_plat_card,double oplata_credit_card,int operation)
{
return Object->PrintNoFiscalCheck(sum,department,oplata_nal,oplata_bank_card,oplata_plat_card,oplata_credit_card,operation);
}
//---------------------------------------------------------------
bool TkasMSKFRImpl::PrintXReport(void)
{
return Object->PrintXReport();
}
//---------------------------------------------------------------
bool TkasMSKFRImpl::PrintZReport(void)
{
return Object->PrintZReport();
}
//---------------------------------------------------------------
bool TkasMSKFRImpl::PrintPoOtdelamReport(void)
{
return Object->PrintPoOtdelamReport();
}
//---------------------------------------------------------------
bool TkasMSKFRImpl::Cut(int TypeCut)
{
return Object->Cut(TypeCut);
}
//---------------------------------------------------------------
bool TkasMSKFRImpl::Vnesenie(double sum)
{
return Object->Vnesenie(sum);
}
//---------------------------------------------------------------
bool TkasMSKFRImpl::Snatie(double sum)
{
return Object->Snatie(sum);
}
//---------------------------------------------------------------
bool TkasMSKFRImpl::PrintLine(void)
{
return Object->PrintLine();
}
//---------------------------------------------------------------
bool TkasMSKFRImpl::OpenNoFiscalCheck(void)
{
return Object->OpenNoFiscalCheck();
}
//---------------------------------------------------------------
bool TkasMSKFRImpl::CloseNoFiscalCheck(void)
{
return Object->CloseNoFiscalCheck();
}
//---------------------------------------------------------------
bool TkasMSKFRImpl::GetSostKKM(void)
{
return Object->GetSostKKM();
}
//---------------------------------------------------------------
bool TkasMSKFRImpl::ProvVosmPrintCheck(void)
{
return Object->ProvVosmPrintCheck();
}
//---------------------------------------------------------------
TTime TkasMSKFRImpl::GetTime(void)
{
return Object->GetTime();
}
//---------------------------------------------------------------
TDate TkasMSKFRImpl::GetDate(void)
{
return Object->GetDate();
}
//---------------------------------------------------------------
bool TkasMSKFRImpl::SetTime(TTime time)
{
return Object->SetTime(time);
}
//---------------------------------------------------------------
bool TkasMSKFRImpl::SetDate(TDate date)
{
return Object->SetDate(date);
}
//---------------------------------------------------------------


















   //IFiskRegOnLine
bool TkasMSKFRImpl::OpenShift(void)
{
return Object->OpenShift();


}
//-----------------------------------------------------------------
bool TkasMSKFRImpl::CloseShift(void)
{

return Object->CloseShift();
}
//-----------------------------------------------------------------
bool TkasMSKFRImpl::InitDocument(int type_doc)

{

return Object->InitDocument(type_doc);
}
//------------------------------------------------------------------
bool TkasMSKFRImpl::CreateHeaderFiscalCheck(void)

{

return Object->CreateHeaderFiscalCheck();
}
//-----------------------------------------------------------------
bool TkasMSKFRImpl::CreateFooterFiscalCheck(void)

{

return Object->CreateFooterFiscalCheck();
}
//-----------------------------------------------------------------
 bool TkasMSKFRImpl::AddFiscalString(void)
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

int TkasMSKFRImpl::get_PaymentType(void)
{
return Object->PaymentType;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_PaymentType(int PaymentType)
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

int TkasMSKFRImpl::get_TaxVariant(void)
{
return Object->TaxVariant;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_TaxVariant(int TaxVariant)
{
Object->TaxVariant=TaxVariant;
}
//---------------------------------------------------------------

//CustomerEmail Необязательно string Email покупателя
UnicodeString TkasMSKFRImpl::get_CustomerEmail(void)
{
return Object->CustomerEmail;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_CustomerEmail(UnicodeString CustomerEmail)
{
Object->CustomerEmail=CustomerEmail;
}
//---------------------------------------------------------------

//CustomerPhone Необязательно string Телефонный номер покупателя
UnicodeString TkasMSKFRImpl::get_CustomerPhone(void)
{
return Object->CustomerPhone ;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_CustomerPhone(UnicodeString CustomerPhone  )
{
Object->CustomerPhone =CustomerPhone ;
}
//---------------------------------------------------------------

//AgentCompensation Необязательно double Размер вознаграждения агента
double TkasMSKFRImpl::get_AgentCompensation(void)
{
return Object->AgentCompensation;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_AgentCompensation(double AgentCompensation)
{
Object->AgentCompensation=AgentCompensation;
}
//---------------------------------------------------------------

//AgentPhone Необязательно string Контактный телефон агента
UnicodeString TkasMSKFRImpl::get_AgentPhone(void)
{
return Object->AgentPhone;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_AgentPhone(UnicodeString AgentPhone  )
{
Object->AgentPhone=AgentPhone;
}
//---------------------------------------------------------------

//SubagentPhone Необязательно string Телефон платежного субагента
UnicodeString TkasMSKFRImpl::get_SubagentPhone(void)
{
return Object->SubagentPhone;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_SubagentPhone(UnicodeString SubagentPhone  )
{
Object->SubagentPhone=SubagentPhone;
}
//---------------------------------------------------------------

//ReceivePaymentsOperatorPhone  Необязательно string Телефон оператора по приему платежей
UnicodeString TkasMSKFRImpl::get_ReceivePaymentsOperatorPhone(void)
{
return Object->ReceivePaymentsOperatorPhone;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_ReceivePaymentsOperatorPhone(UnicodeString ReceivePaymentsOperatorPhone  )
{
Object->ReceivePaymentsOperatorPhone=ReceivePaymentsOperatorPhone;
}
//---------------------------------------------------------------

//MoneyTransferOperatorPhone  Необязательно string Телефон оператора по переводу денежных средств
UnicodeString TkasMSKFRImpl::get_MoneyTransferOperatorPhone(void)
{
return Object->MoneyTransferOperatorPhone;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_MoneyTransferOperatorPhone(UnicodeString MoneyTransferOperatorPhone  )
{
Object->MoneyTransferOperatorPhone=MoneyTransferOperatorPhone;
}
//---------------------------------------------------------------

//BankAgentPhone  Необязательно string Телефон банковского агента
UnicodeString TkasMSKFRImpl::get_BankAgentPhone(void)
{
return Object->BankAgentPhone;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_BankAgentPhone(UnicodeString BankAgentPhone  )
{
Object->BankAgentPhone=BankAgentPhone;
}
//---------------------------------------------------------------

//BankSubagentPhone  Необязательно string Телефон банковского субагента
UnicodeString TkasMSKFRImpl::get_BankSubagentPhone(void)
{
return Object->BankSubagentPhone;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_BankSubagentPhone(UnicodeString BankSubagentPhone )
{
Object->BankSubagentPhone=BankSubagentPhone;
}
//---------------------------------------------------------------

//BankAgentOperation Необязательно string Операция банковского агента
UnicodeString TkasMSKFRImpl::get_BankAgentOperation(void)
{
return Object->BankAgentOperation;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_BankAgentOperation(UnicodeString BankAgentOperation)
{
Object->BankAgentOperation=BankAgentOperation;
}
//---------------------------------------------------------------


//BankSubagentOperation Необязательно string Операция банковского субагента
UnicodeString TkasMSKFRImpl::get_BankSubagentOperation(void)
{
return Object->BankSubagentOperation;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_BankSubagentOperation(UnicodeString BankSubagentOperation)
{
Object->BankSubagentOperation=BankSubagentOperation;
}
//---------------------------------------------------------------

//BankAgentCompensation  Необязательно double Размер вознаграждения банковского агента (субагента)
double TkasMSKFRImpl::get_BankAgentCompensation(void)
{
return Object->BankAgentCompensation;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_BankAgentCompensation(double BankAgentCompensation)
{
Object->BankAgentCompensation=BankAgentCompensation;
}
//---------------------------------------------------------------


//MoneyTransferOperatorName Необязательно string Наименование оператора по переводу денежных средств
UnicodeString TkasMSKFRImpl::get_MoneyTransferOperatorName(void)
{
return Object->MoneyTransferOperatorName;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_MoneyTransferOperatorName(UnicodeString MoneyTransferOperatorName)
{
Object->MoneyTransferOperatorName=MoneyTransferOperatorName;
}
//---------------------------------------------------------------


//MoneyTransferOperatorAddress  Необязательно string Адрес оператора по переводу денежных средств
UnicodeString TkasMSKFRImpl::get_MoneyTransferOperatorAddress(void)
{
return Object->MoneyTransferOperatorAddress;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_MoneyTransferOperatorAddress(UnicodeString MoneyTransferOperatorAddress)
{
Object->MoneyTransferOperatorAddress=MoneyTransferOperatorAddress;
}
//---------------------------------------------------------------

//MoneyTransferOperatorVATIN  Необязательно string ИНН оператора по переводу денежных
UnicodeString TkasMSKFRImpl::get_MoneyTransferOperatorVATIN(void)
{
return Object->MoneyTransferOperatorVATIN;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_MoneyTransferOperatorVATIN(UnicodeString MoneyTransferOperatorVATIN)
{
Object->MoneyTransferOperatorVATIN=MoneyTransferOperatorVATIN;
}
//---------------------------------------------------------------

 //ФОРМИРОВАНИЕ ТАБЛИЦЫ ЧЕКА
 //позиции чека, тип строки       1-фиск строка 2- текстовая строка 3-штрих код
int TkasMSKFRImpl::get_TypeFiscalString(void)
{
return Object->TypeFiscalString;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_TypeFiscalString(int TypeFiscalString)
{
Object->TypeFiscalString=TypeFiscalString;
}
//---------------------------------------------------------------

	//FiscalString  Регистрирует фискальную строку с переданными реквизитами.
	//Name Да string  Наименование товара
	//При печати длинных фискальных строк необходимо делать перенос на следующую строку.
UnicodeString TkasMSKFRImpl::get_NameNom(void)
{
return Object->NameNom;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_NameNom(UnicodeString NameNom)
{
Object->NameNom=NameNom;
}
//---------------------------------------------------------------

	 //Quantity Да double Количество товара
double TkasMSKFRImpl::get_Quantity(void)
{
return Object->Quantity;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_Quantity(double Quantity)
{
Object->Quantity=Quantity;
}
//---------------------------------------------------------------

	//Price Да double Цена единицы товара без учета скидок/наценок
double TkasMSKFRImpl::get_Price(void)
{
return Object->Price;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_Price(double Price)
{
Object->Price=Price;
}
//---------------------------------------------------------------

	//Amount Да double Конечная сумма по позиции чека (с учетом всех скидок/наценок)
double TkasMSKFRImpl::get_Amount(void)
{
return Object->Amount;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_Amount(double Amount)
{
Object->Amount=Amount;
}
//---------------------------------------------------------------

	//Department Нет long Отдел, по которому ведется продажа
int TkasMSKFRImpl::get_Department(void)
{
return Object->Department;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_Department(int Department)
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
int TkasMSKFRImpl::get_Tax(void)
{
return Object->Tax;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_Tax(int Tax)
{
Object->Tax=Tax;
}
//---------------------------------------------------------------


	//TextString  Печать текстовой строки.
	//Text Да string Строка с произвольным текстом
UnicodeString TkasMSKFRImpl::get_TextString(void)
{
return Object->TextString;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_TextString(UnicodeString TextString)
{
Object->TextString=TextString;
}
//---------------------------------------------------------------

	//Barcode   Печать штрихкода. Осуществляется с автоматическим размером с выравниванием по центру чека.
	//BarcodeType Да string Строка, определяющая тип штрихкода

UnicodeString TkasMSKFRImpl::get_BarcodeType(void)
{
return Object->BarcodeType;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_BarcodeType(UnicodeString BarcodeType)
{
Object->BarcodeType=BarcodeType;
}
//---------------------------------------------------------------
	//Тип штрихкода может иметь одно из следующих значений: EAN8, EAN13, CODE39, QR. В случае, если модель устройства не поддерживает печать штрихкода, выдается ошибка.

UnicodeString TkasMSKFRImpl::get_Barcode(void)
{
return Object->Barcode;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_Barcode(UnicodeString Barcode)
{
Object->Barcode=Barcode;
}
//---------------------------------------------------------------

 //Payments  Параметры закрытия чека. Сумма всех видов оплат должна быть больше суммы открытого чека.


//Cash Нет decimal Сумма наличной оплаты Параметры закрытия чека. Сумма всех видов оплат должна быть больше суммы открытого чека.
double TkasMSKFRImpl::get_Cash(void)
{
return Object->Cash;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_Cash(double Cash)
{
Object->Cash=Cash;
}
//---------------------------------------------------------------

//CashLessType1 Нет decimal Сумма электронной оплаты первого типа
double TkasMSKFRImpl::get_CashLessType1(void)
{
return Object->CashLessType1;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_CashLessType1(double CashLessType1)
{
Object->CashLessType1=CashLessType1;
}
//---------------------------------------------------------------

//CashLessType2 Нет decimal Сумма электронной оплаты второго типа
double TkasMSKFRImpl::get_CashLessType2(void)
{
return Object->CashLessType2;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_CashLessType2(double CashLessType2)
{
Object->CashLessType2=CashLessType2;
}
//---------------------------------------------------------------

//CashLessType3 Нет decimal Сумма электронной оплаты третьего типа
double TkasMSKFRImpl::get_CashLessType3(void)
{
return Object->CashLessType3;
}
//-----------------------------------------------------------------------------
void TkasMSKFRImpl::set_CashLessType3(double CashLessType3)
{
Object->CashLessType3=CashLessType3;
}
//---------------------------------------------------------------
UnicodeString TkasMSKFRImpl::GetParameters(void)
{
return Object->GetParameters();
}
//-----------------------------------------------------------------------
bool TkasMSKFRImpl::SetParameter(UnicodeString name_parameter, UnicodeString value_parameter)
{
return Object->SetParameter(name_parameter, value_parameter);
}
//--------------------------------------------------------------------
UnicodeString TkasMSKFRImpl::GetAdditionalActions(void)
{
return Object->GetAdditionalActions();
}
//-----------------------------------------------------------------
bool TkasMSKFRImpl::DoAdditionalAction(UnicodeString name_action)
{
return Object->DoAdditionalAction(name_action);
}
//-----------------------------------------------------------------
   //	Кассир (CashierName) STRING [IN] ФИО уполномоченного лица для проведения операции
UnicodeString TkasMSKFRImpl::get_CashierName(void)
{
return Object->CashierName;
}
//--------------------------------------------------------------------------
void TkasMSKFRImpl::set_CashierName(UnicodeString CashierName)
{
Object->CashierName=CashierName;
}
//--------------------------------------------------------------------------
//	Электронно (Electronically) BOOL (IN) Формирование чека в только электроном виде. Печать чека не осуществляется.
bool TkasMSKFRImpl::get_Electronically(void)
{
return Object->Electronically;
}
//--------------------------------------------------------------------------
void TkasMSKFRImpl::set_Electronically(bool Electronically)
{
Object->Electronically=Electronically;
}
//---------------------------------------------------------------------------
//	ФискальныйПризнак (FiscalSign) STRING [OUT] Фискальный признак
UnicodeString TkasMSKFRImpl::get_FiscalSign(void)
{
return Object->FiscalSign;
}
//---------------------------------------------------------------------------
void TkasMSKFRImpl::set_FiscalSign(UnicodeString FiscalSign)
{
Object->FiscalSign=FiscalSign;
}
//------------------------------------------------------------------------
//	AddressSiteInspections (АдресСайтаПроверки) STRING [OUT] Адрес сайта проверки
UnicodeString TkasMSKFRImpl::get_AddressSiteInspections(void)
{
return Object->AddressSiteInspections;
}
//----------------------------------------------------------------------
void TkasMSKFRImpl::set_AddressSiteInspections(UnicodeString AddressSiteInspections)
{
Object->AddressSiteInspections=AddressSiteInspections;
}
//-------------------------------------------------------------------------
UnicodeString TkasMSKFRImpl::GetMetodsList(void)
{
return Object->GetMetodsList();
}
//--------------------------------------------------------------------------
bool TkasMSKFRImpl::GetParameter(UnicodeString name_parameter, TkasVariant * value_parameter)
{
return Object->GetParameter(name_parameter, value_parameter);
}
//---------------------------------------------------------------------------
bool TkasMSKFRImpl::SetParameter(UnicodeString name_parameter, TkasVariant * value_parameter)
{
return Object->GetParameter(name_parameter,value_parameter);
}
//---------------------------------------------------------------------------
