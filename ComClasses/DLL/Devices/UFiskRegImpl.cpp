#include "vcl.h"
#pragma hdrstop


#include "UFiskRegImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFiskRegImpl::TFiskRegImpl()           
{                                            
Object=new TFiskReg();
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFiskRegImpl::~TFiskRegImpl()          
{                                            

delete Object;

--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFiskRegImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFiskRegImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
int TFiskRegImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFiskRegImpl::kanRelease(void)                                  
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
int  TFiskRegImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFiskRegImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFiskRegImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFiskRegImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TFiskRegImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TFiskRegImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TFiskRegImpl::Done(void)                                
{                                                              
return Object->Done();
}                                                              
//---------------------------------------------------------------

//IFiskReg

//----------------------------------------------------------------
int TFiskRegImpl::get_Number(void)
{
return Object->Number;
}
//---------------------------------------------------------------
void TFiskRegImpl::set_Number(int Number)
{
Object->Number=Number;
}
//---------------------------------------------------------------
AnsiString TFiskRegImpl::get_Modul(void)
{
return Object->Modul;
}
//---------------------------------------------------------------
void TFiskRegImpl::set_Modul(AnsiString Modul)
{
Object->Modul=Modul;
}
//---------------------------------------------------------------
UnicodeString TFiskRegImpl::get_Name(void)
{
return Object->Name;
}
//---------------------------------------------------------------
void TFiskRegImpl::set_Name(UnicodeString Name)
{
Object->Name=Name;
}
//---------------------------------------------------------------
bool TFiskRegImpl::get_Error(void)
{
return Object->Error;
}
//---------------------------------------------------------------
void TFiskRegImpl::set_Error(bool Error)
{
Object->Error=Error;
}

//---------------------------------------------------------------
UnicodeString TFiskRegImpl::get_TextErrorNoConnect(void)
{
return Object->TextErrorNoConnect;
}
//---------------------------------------------------------------
void TFiskRegImpl::set_TextErrorNoConnect(UnicodeString TextErrorNoConnect)
{
Object->TextErrorNoConnect=TextErrorNoConnect;
}
//---------------------------------------------------------------
bool TFiskRegImpl::get_ConnectFR(void)
{
return Object->ConnectFR;
}
//---------------------------------------------------------------
void TFiskRegImpl::set_ConnectFR(bool ConnectFR)
{
Object->ConnectFR=ConnectFR;
}
//---------------------------------------------------------------
int TFiskRegImpl::get_NumberCheck(void)
{
return Object->NumberCheck;
}
//---------------------------------------------------------------
void TFiskRegImpl::set_NumberCheck(int NumberCheck)
{
Object->NumberCheck=NumberCheck;
}
//---------------------------------------------------------------
int TFiskRegImpl::get_NumberKL(void)
{
return Object->NumberKL;
}
//---------------------------------------------------------------
void TFiskRegImpl::set_NumberKL(int NumberKL)
{
Object->NumberKL=NumberKL;
}
//---------------------------------------------------------------
UnicodeString TFiskRegImpl::get_SerialNumberKKM(void)
{
return Object->SerialNumberKKM;
}
//---------------------------------------------------------------
void TFiskRegImpl::set_SerialNumberKKM(UnicodeString SerialNumberKKM)
{
Object->SerialNumberKKM=SerialNumberKKM;
}
//---------------------------------------------------------------
UnicodeString TFiskRegImpl::get_RegNumberKKM(void)
{
return Object->RegNumberKKM;
}
//---------------------------------------------------------------
void TFiskRegImpl::set_RegNumberKKM(UnicodeString RegNumberKKM)
{
Object->RegNumberKKM=RegNumberKKM;
}
//---------------------------------------------------------------
UnicodeString TFiskRegImpl::get_ModelKKM(void)
{
return Object->ModelKKM;
}
//---------------------------------------------------------------
void TFiskRegImpl::set_ModelKKM(UnicodeString ModelKKM)
{
Object->ModelKKM=ModelKKM;
}
//---------------------------------------------------------------
bool TFiskRegImpl::InitDevice()
{

return Object->InitDevice();
}
//---------------------------------------------------------------
bool TFiskRegImpl::Connect(int number_port, UnicodeString baud_rate,	UnicodeString password)
{
return Object->Connect(number_port,baud_rate,password);
}
//---------------------------------------------------------------
bool TFiskRegImpl::Disconnect(void)
{
return Object->Disconnect();
}
//---------------------------------------------------------------
bool TFiskRegImpl::PrintString(UnicodeString str,int size_font, int girn, int alignment, bool ch_lenta, bool kontr_lenta, bool word_wrap)
{
return Object->PrintString(str,size_font,girn,alignment,ch_lenta,kontr_lenta,word_wrap);
}
//---------------------------------------------------------------
bool TFiskRegImpl::PrintFiscalCheck(double sum, int department,double oplata_nal,double oplata_bank_card,double oplata_plat_card,double oplata_credit_card,int operation)
{
return Object->PrintFiscalCheck(sum,department,oplata_nal,oplata_bank_card,oplata_plat_card,oplata_credit_card,operation);
}
//---------------------------------------------------------------
bool TFiskRegImpl::PrintNoFiscalCheck(double sum,int department,double oplata_nal,double oplata_bank_card,double oplata_plat_card,double oplata_credit_card,int operation)
{
return Object->PrintNoFiscalCheck(sum,department,oplata_nal,oplata_bank_card,oplata_plat_card,oplata_credit_card,operation);
}
//---------------------------------------------------------------
bool TFiskRegImpl::PrintXReport(void)
{
return Object->PrintXReport();
}
//---------------------------------------------------------------
bool TFiskRegImpl::PrintZReport(void)
{
return Object->PrintZReport();
}
//---------------------------------------------------------------
bool TFiskRegImpl::PrintPoOtdelamReport(void)
{
return Object->PrintPoOtdelamReport();
}
//---------------------------------------------------------------
bool TFiskRegImpl::Cut(int TypeCut)
{
return Object->Cut(TypeCut);
}
//---------------------------------------------------------------
bool TFiskRegImpl::Vnesenie(double sum)
{
return Object->Vnesenie(sum);
}
//---------------------------------------------------------------
bool TFiskRegImpl::Snatie(double sum)
{
return Object->Snatie(sum);
}
//---------------------------------------------------------------
bool TFiskRegImpl::PrintLine(void)
{
return Object->PrintLine();
}
//---------------------------------------------------------------
bool TFiskRegImpl::OpenNoFiscalCheck(void)
{
return Object->OpenNoFiscalCheck();
}
//---------------------------------------------------------------
bool TFiskRegImpl::CloseNoFiscalCheck(void)
{
return Object->CloseNoFiscalCheck();
}
//---------------------------------------------------------------
bool TFiskRegImpl::GetSostKKM(void)
{
return Object->GetSostKKM();
}
//---------------------------------------------------------------
bool TFiskRegImpl::ProvVosmPrintCheck(void)
{
return Object->ProvVosmPrintCheck();
}
//---------------------------------------------------------------
TTime TFiskRegImpl::GetTime(void)
{
return Object->GetTime();
}
//---------------------------------------------------------------
TDate TFiskRegImpl::GetDate(void)
{
return Object->GetDate();
}
//---------------------------------------------------------------
bool TFiskRegImpl::SetTime(TTime time)
{
return Object->SetTime(time);
}
//---------------------------------------------------------------
bool TFiskRegImpl::SetDate(TDate date)
{
return Object->SetDate(date);
}
//---------------------------------------------------------------



   //IFiskRegOnLine
bool TFiskRegImpl::OpenShift(void)
{
return Object->OpenShift();


}
//-----------------------------------------------------------------
bool TFiskRegImpl::CloseShift(void)
{

return Object->CloseShift();
}
//-----------------------------------------------------------------
bool TFiskRegImpl::InitDocument(int type_doc)

{

return Object->InitDocument(type_doc);
}
//------------------------------------------------------------------
bool TFiskRegImpl::CreateHeaderFiscalCheck(void)

{

return Object->CreateHeaderFiscalCheck();
}
//-----------------------------------------------------------------
bool TFiskRegImpl::CreateFooterFiscalCheck(void)

{

return Object->CreateFooterFiscalCheck();
}
//-----------------------------------------------------------------
 bool TFiskRegImpl::AddFiscalString(void)
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

int TFiskRegImpl::get_PaymentType(void)
{
return Object->PaymentType;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_PaymentType(int PaymentType)
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

int TFiskRegImpl::get_TaxVariant(void)
{
return Object->TaxVariant;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_TaxVariant(int TaxVariant)
{
Object->TaxVariant=TaxVariant;
}
//---------------------------------------------------------------

//CustomerEmail Необязательно string Email покупателя
UnicodeString TFiskRegImpl::get_CustomerEmail(void)
{
return Object->CustomerEmail;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_CustomerEmail(UnicodeString CustomerEmail)
{
Object->CustomerEmail=CustomerEmail;
}
//---------------------------------------------------------------

//CustomerPhone Необязательно string Телефонный номер покупателя
UnicodeString TFiskRegImpl::get_CustomerPhone(void)
{
return Object->CustomerPhone ;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_CustomerPhone(UnicodeString CustomerPhone  )
{
Object->CustomerPhone =CustomerPhone ;
}
//---------------------------------------------------------------

//AgentCompensation Необязательно double Размер вознаграждения агента
double TFiskRegImpl::get_AgentCompensation(void)
{
return Object->AgentCompensation;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_AgentCompensation(double AgentCompensation)
{
Object->AgentCompensation=AgentCompensation;
}
//---------------------------------------------------------------

//AgentPhone Необязательно string Контактный телефон агента
UnicodeString TFiskRegImpl::get_AgentPhone(void)
{
return Object->AgentPhone;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_AgentPhone(UnicodeString AgentPhone  )
{
Object->AgentPhone=AgentPhone;
}
//---------------------------------------------------------------

//SubagentPhone Необязательно string Телефон платежного субагента
UnicodeString TFiskRegImpl::get_SubagentPhone(void)
{
return Object->SubagentPhone;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_SubagentPhone(UnicodeString SubagentPhone  )
{
Object->SubagentPhone=SubagentPhone;
}
//---------------------------------------------------------------

//ReceivePaymentsOperatorPhone  Необязательно string Телефон оператора по приему платежей
UnicodeString TFiskRegImpl::get_ReceivePaymentsOperatorPhone(void)
{
return Object->ReceivePaymentsOperatorPhone;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_ReceivePaymentsOperatorPhone(UnicodeString ReceivePaymentsOperatorPhone  )
{
Object->ReceivePaymentsOperatorPhone=ReceivePaymentsOperatorPhone;
}
//---------------------------------------------------------------

//MoneyTransferOperatorPhone  Необязательно string Телефон оператора по переводу денежных средств
UnicodeString TFiskRegImpl::get_MoneyTransferOperatorPhone(void)
{
return Object->MoneyTransferOperatorPhone;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_MoneyTransferOperatorPhone(UnicodeString MoneyTransferOperatorPhone  )
{
Object->MoneyTransferOperatorPhone=MoneyTransferOperatorPhone;
}
//---------------------------------------------------------------

//BankAgentPhone  Необязательно string Телефон банковского агента
UnicodeString TFiskRegImpl::get_BankAgentPhone(void)
{
return Object->BankAgentPhone;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_BankAgentPhone(UnicodeString BankAgentPhone  )
{
Object->BankAgentPhone=BankAgentPhone;
}
//---------------------------------------------------------------

//BankSubagentPhone  Необязательно string Телефон банковского субагента
UnicodeString TFiskRegImpl::get_BankSubagentPhone(void)
{
return Object->BankSubagentPhone;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_BankSubagentPhone(UnicodeString BankSubagentPhone )
{
Object->BankSubagentPhone=BankSubagentPhone;
}
//---------------------------------------------------------------

//BankAgentOperation Необязательно string Операция банковского агента
UnicodeString TFiskRegImpl::get_BankAgentOperation(void)
{
return Object->BankAgentOperation;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_BankAgentOperation(UnicodeString BankAgentOperation)
{
Object->BankAgentOperation=BankAgentOperation;
}
//---------------------------------------------------------------


//BankSubagentOperation Необязательно string Операция банковского субагента
UnicodeString TFiskRegImpl::get_BankSubagentOperation(void)
{
return Object->BankSubagentOperation;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_BankSubagentOperation(UnicodeString BankSubagentOperation)
{
Object->BankSubagentOperation=BankSubagentOperation;
}
//---------------------------------------------------------------

//BankAgentCompensation  Необязательно double Размер вознаграждения банковского агента (субагента)
double TFiskRegImpl::get_BankAgentCompensation(void)
{
return Object->BankAgentCompensation;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_BankAgentCompensation(double BankAgentCompensation)
{
Object->BankAgentCompensation=BankAgentCompensation;
}
//---------------------------------------------------------------


//MoneyTransferOperatorName Необязательно string Наименование оператора по переводу денежных средств
UnicodeString TFiskRegImpl::get_MoneyTransferOperatorName(void)
{
return Object->MoneyTransferOperatorName;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_MoneyTransferOperatorName(UnicodeString MoneyTransferOperatorName)
{
Object->MoneyTransferOperatorName=MoneyTransferOperatorName;
}
//---------------------------------------------------------------


//MoneyTransferOperatorAddress  Необязательно string Адрес оператора по переводу денежных средств
UnicodeString TFiskRegImpl::get_MoneyTransferOperatorAddress(void)
{
return Object->MoneyTransferOperatorAddress;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_MoneyTransferOperatorAddress(UnicodeString MoneyTransferOperatorAddress)
{
Object->MoneyTransferOperatorAddress=MoneyTransferOperatorAddress;
}
//---------------------------------------------------------------

//MoneyTransferOperatorVATIN  Необязательно string ИНН оператора по переводу денежных
UnicodeString TFiskRegImpl::get_MoneyTransferOperatorVATIN(void)
{
return Object->MoneyTransferOperatorVATIN;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_MoneyTransferOperatorVATIN(UnicodeString MoneyTransferOperatorVATIN)
{
Object->MoneyTransferOperatorVATIN=MoneyTransferOperatorVATIN;
}
//---------------------------------------------------------------

 //ФОРМИРОВАНИЕ ТАБЛИЦЫ ЧЕКА
 //позиции чека, тип строки       1-фиск строка 2- текстовая строка 3-штрих код
int TFiskRegImpl::get_TypeFiscalString(void)
{
return Object->TypeFiscalString;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_TypeFiscalString(int TypeFiscalString)
{
Object->TypeFiscalString=TypeFiscalString;
}
//---------------------------------------------------------------

	//FiscalString  Регистрирует фискальную строку с переданными реквизитами.
	//Name Да string  Наименование товара
	//При печати длинных фискальных строк необходимо делать перенос на следующую строку.
UnicodeString TFiskRegImpl::get_NameNom(void)
{
return Object->NameNom;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_NameNom(UnicodeString NameNom)
{
Object->NameNom=NameNom;
}
//---------------------------------------------------------------

	 //Quantity Да double Количество товара
double TFiskRegImpl::get_Quantity(void)
{
return Object->Quantity;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_Quantity(double Quantity)
{
Object->Quantity=Quantity;
}
//---------------------------------------------------------------

	//Price Да double Цена единицы товара без учета скидок/наценок
double TFiskRegImpl::get_Price(void)
{
return Object->Price;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_Price(double Price)
{
Object->Price=Price;
}
//---------------------------------------------------------------

	//Amount Да double Конечная сумма по позиции чека (с учетом всех скидок/наценок)
double TFiskRegImpl::get_Amount(void)
{
return Object->Amount;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_Amount(double Amount)
{
Object->Amount=Amount;
}
//---------------------------------------------------------------

	//Department Нет long Отдел, по которому ведется продажа
int TFiskRegImpl::get_Department(void)
{
return Object->Department;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_Department(int Department)
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
int TFiskRegImpl::get_Tax(void)
{
return Object->Tax;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_Tax(int Tax)
{
Object->Tax=Tax;
}
//---------------------------------------------------------------


	//TextString  Печать текстовой строки.
	//Text Да string Строка с произвольным текстом
UnicodeString TFiskRegImpl::get_TextString(void)
{
return Object->TextString;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_TextString(UnicodeString TextString)
{
Object->TextString=TextString;
}
//---------------------------------------------------------------

	//Barcode   Печать штрихкода. Осуществляется с автоматическим размером с выравниванием по центру чека.
	//BarcodeType Да string Строка, определяющая тип штрихкода

UnicodeString TFiskRegImpl::get_BarcodeType(void)
{
return Object->BarcodeType;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_BarcodeType(UnicodeString BarcodeType)
{
Object->BarcodeType=BarcodeType;
}
//---------------------------------------------------------------
	//Тип штрихкода может иметь одно из следующих значений: EAN8, EAN13, CODE39, QR. В случае, если модель устройства не поддерживает печать штрихкода, выдается ошибка.

UnicodeString TFiskRegImpl::get_Barcode(void)
{
return Object->Barcode;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_Barcode(UnicodeString Barcode)
{
Object->Barcode=Barcode;
}
//---------------------------------------------------------------

 //Payments  Параметры закрытия чека. Сумма всех видов оплат должна быть больше суммы открытого чека.


//Cash Нет decimal Сумма наличной оплаты Параметры закрытия чека. Сумма всех видов оплат должна быть больше суммы открытого чека.
double TFiskRegImpl::get_Cash(void)
{
return Object->Cash;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_Cash(double Cash)
{
Object->Cash=Cash;
}
//---------------------------------------------------------------

//CashLessType1 Нет decimal Сумма электронной оплаты первого типа
double TFiskRegImpl::get_CashLessType1(void)
{
return Object->CashLessType1;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_CashLessType1(double CashLessType1)
{
Object->CashLessType1=CashLessType1;
}
//---------------------------------------------------------------

//CashLessType2 Нет decimal Сумма электронной оплаты второго типа
double TFiskRegImpl::get_CashLessType2(void)
{
return Object->CashLessType2;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_CashLessType2(double CashLessType2)
{
Object->CashLessType2=CashLessType2;
}
//---------------------------------------------------------------

//CashLessType3 Нет decimal Сумма электронной оплаты третьего типа
double TFiskRegImpl::get_CashLessType3(void)
{
return Object->CashLessType3;
}
//-----------------------------------------------------------------------------
void TFiskRegImpl::set_CashLessType3(double CashLessType3)
{
Object->CashLessType3=CashLessType3;
}
//---------------------------------------------------------------
UnicodeString TFiskRegImpl::GetParameters(void)
{
return Object->GetParameters();
}
//---------------------------------------------------------------
bool TFiskRegImpl::SetParameter(UnicodeString name_parameter, UnicodeString value_parameter)
{
return Object->SetParameter(name_parameter,value_parameter);
}
//---------------------------------------------------------------


UnicodeString TFiskRegImpl::GetAdditionalActions(void)
{
return Object->GetAdditionalActions();
}
//---------------------------------------------------------------
bool TFiskRegImpl::DoAdditionalAction(UnicodeString name_action)
{
return Object->DoAdditionalAction(name_action);
}
//---------------------------------------------------------------
   //	Кассир (CashierName) STRING [IN] ФИО уполномоченного лица для проведения операции
UnicodeString TFiskRegImpl::get_CashierName(void)
{
return Object->CashierName;
}
//--------------------------------------------------------------------------
void TFiskRegImpl::set_CashierName(UnicodeString CashierName)
{
Object->CashierName=CashierName;
}
//--------------------------------------------------------------------------
//	Электронно (Electronically) BOOL (IN) Формирование чека в только электроном виде. Печать чека не осуществляется.
bool TFiskRegImpl::get_Electronically(void)
{
return Object->Electronically;
}
//--------------------------------------------------------------------------
void TFiskRegImpl::set_Electronically(bool Electronically)
{
Object->Electronically=Electronically;
}
//---------------------------------------------------------------------------
//	ФискальныйПризнак (FiscalSign) STRING [OUT] Фискальный признак
UnicodeString TFiskRegImpl::get_FiscalSign(void)
{
return Object->FiscalSign;
}
//---------------------------------------------------------------------------
void TFiskRegImpl::set_FiscalSign(UnicodeString FiscalSign)
{
Object->FiscalSign=FiscalSign;
}
//------------------------------------------------------------------------
//	AddressSiteInspections (АдресСайтаПроверки) STRING [OUT] Адрес сайта проверки
UnicodeString TFiskRegImpl::get_AddressSiteInspections(void)
{
return Object->AddressSiteInspections;
}
//----------------------------------------------------------------------
void TFiskRegImpl::set_AddressSiteInspections(UnicodeString AddressSiteInspections)
{
Object->AddressSiteInspections=AddressSiteInspections;
}
//-------------------------------------------------------------------------
UnicodeString TFiskRegImpl::GetMetodsList(void)
{
return Object->GetMetodsList();
}
//--------------------------------------------------------------------------
//---------------------------------------------------------------------------
bool TFiskRegImpl::GetParameter(UnicodeString name_parameter, TkasVariant * value_parameter)
{
return Object->GetParameter(name_parameter, value_parameter);
}
//---------------------------------------------------------------------------
bool TFiskRegImpl::SetParameter(UnicodeString name_parameter, TkasVariant * value_parameter)
{
return Object->GetParameter(name_parameter,value_parameter);
}
//---------------------------------------------------------------------------
