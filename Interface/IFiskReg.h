#ifndef UIFiskRegH
#define UIFiskRegH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "UkasVariant.h"
class __declspec(uuid(Global_IID_IFiskReg)) IFiskReg : public IMainInterface
{
public:
   __property int Number = {read = get_Number , write = set_Number};
   virtual int get_Number(void)=0;
   virtual void set_Number(int Number)=0;

   __property AnsiString Modul = {read = get_Modul , write = set_Modul};
   virtual AnsiString get_Modul(void)=0;
   virtual void set_Modul(AnsiString Modul)=0;

   __property UnicodeString Name = {read = get_Name , write = set_Name};
   virtual UnicodeString get_Name(void)=0;
   virtual void set_Name(UnicodeString Name)=0;

   __property bool Error = {read = get_Error , write = set_Error};
   virtual bool get_Error(void)=0;
   virtual void set_Error(bool Error)=0;

   __property UnicodeString TextErrorNoConnect = {read = get_TextErrorNoConnect , write = set_TextErrorNoConnect};
   virtual UnicodeString get_TextErrorNoConnect(void)=0;
   virtual void set_TextErrorNoConnect(UnicodeString TextErrorNoConnect)=0;

   __property bool ConnectFR = {read = get_ConnectFR , write = set_ConnectFR};
   virtual bool get_ConnectFR(void)=0;
   virtual void set_ConnectFR(bool ConnectFR)=0;

   __property int NumberCheck = {read = get_NumberCheck , write = set_NumberCheck};
   virtual int get_NumberCheck(void)=0;
   virtual void set_NumberCheck(int NumberCheck)=0;

   __property int NumberKL = {read = get_NumberKL , write = set_NumberKL};
   virtual int get_NumberKL(void)=0;
   virtual void set_NumberKL(int NumberKL)=0;

   __property UnicodeString SerialNumberKKM = {read = get_SerialNumberKKM , write = set_SerialNumberKKM};
   virtual UnicodeString get_SerialNumberKKM(void)=0;
   virtual void set_SerialNumberKKM(UnicodeString SerialNumberKKM)=0;

   __property UnicodeString RegNumberKKM = {read = get_RegNumberKKM , write = set_RegNumberKKM};
   virtual UnicodeString get_RegNumberKKM(void)=0;
   virtual void set_RegNumberKKM(UnicodeString RegNumberKKM)=0;

   __property UnicodeString ModelKKM = {read = get_ModelKKM , write = set_ModelKKM};
   virtual UnicodeString get_ModelKKM(void)=0;
   virtual void set_ModelKKM(UnicodeString ModelKKM)=0;

   virtual bool InitDevice()=0;
   virtual bool Connect(int number_port, UnicodeString baud_rate,	UnicodeString password)=0;
   virtual bool Disconnect(void)=0;
   virtual bool GetSostKKM(void)=0;
   virtual bool ProvVosmPrintCheck(void)=0;

   virtual bool PrintString(UnicodeString str,int size_font, int girn, int alignment, bool ch_lenta, bool kontr_lenta, bool word_wrap)=0;
   virtual bool PrintFiscalCheck(double sum, int department,double oplata_nal,double oplata_bank_card,double oplata_plat_card,double oplata_credit_card,int operation)=0;
   virtual bool PrintNoFiscalCheck(double sum,int department,double oplata_nal,double oplata_bank_card,double oplata_plat_card,double oplata_credit_card,int operation)=0;
   virtual bool PrintXReport(void)=0;
   virtual bool PrintZReport(void)=0;
   virtual bool PrintPoOtdelamReport(void)=0;
   virtual bool Cut(int TypeCut)=0;
   virtual bool Vnesenie(double sum)=0;
   virtual bool Snatie(double sum)=0;
   virtual bool PrintLine(void)=0;
   virtual bool OpenNoFiscalCheck(void)=0;
   virtual bool CloseNoFiscalCheck(void)=0;

   virtual TTime GetTime(void)=0;
   virtual TDate GetDate(void)=0;
   virtual bool SetTime(TTime time)=0;
   virtual bool SetDate(TDate date)=0;

   //новые функции для работы с он-лайн кассами
   virtual bool OpenShift(void)=0;
   virtual bool CloseShift(void)=0;
   virtual bool InitDocument(int type_doc)=0;    //1 нефискальный чек, 2 фискальный чек
   virtual bool CreateHeaderFiscalCheck(void)=0;
   virtual bool CreateFooterFiscalCheck(void)=0;
   virtual bool AddFiscalString(void)=0;


//параметры чека  //заголовок 	Parameters
// Обязательно long Тип расчета
//1 - Приход
//2 - Возврат прихода
//3 - Расход
//4 - Возврат расхода Формирование нового чека с заданным атрибутами.

   __property int PaymentType = {read = get_PaymentType , write = set_PaymentType};    virtual int get_PaymentType(void)=0;   virtual void set_PaymentType(int PaymentType)=0;


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

   __property int TaxVariant = {read = get_TaxVariant , write = set_TaxVariant};   virtual int get_TaxVariant(void)=0;    virtual void set_TaxVariant(int TaxVariant)=0;

//CustomerEmail Необязательно string Email покупателя
   __property UnicodeString CustomerEmail = {read = get_CustomerEmail , write = set_CustomerEmail};   virtual UnicodeString get_CustomerEmail(void)=0;   virtual void set_CustomerEmail(UnicodeString CustomerEmail)=0;

//CustomerPhone Необязательно string Телефонный номер покупателя
   __property UnicodeString CustomerPhone = {read = get_CustomerPhone , write = set_CustomerPhone};   virtual UnicodeString get_CustomerPhone(void)=0;   virtual void set_CustomerPhone(UnicodeString CustomerPhone  )=0;

//AgentCompensation Необязательно double Размер вознаграждения агента
	__property double AgentCompensation = {read = get_AgentCompensation , write = set_AgentCompensation};   virtual double get_AgentCompensation(void)=0;    virtual void set_AgentCompensation(double AgentCompensation)=0;

//AgentPhone Необязательно string Контактный телефон агента
	__property UnicodeString AgentPhone = {read = get_AgentPhone , write = set_AgentPhone};   virtual UnicodeString get_AgentPhone(void)=0;   virtual void set_AgentPhone(UnicodeString AgentPhone  )=0;

//SubagentPhone Необязательно string Телефон платежного субагента
	__property UnicodeString SubagentPhone = {read = get_SubagentPhone , write = set_SubagentPhone};   virtual UnicodeString get_SubagentPhone(void)=0;   virtual void set_SubagentPhone(UnicodeString SubagentPhone  )=0;

//ReceivePaymentsOperatorPhone  Необязательно string Телефон оператора по приему платежей
	__property UnicodeString ReceivePaymentsOperatorPhone = {read = get_ReceivePaymentsOperatorPhone , write = set_ReceivePaymentsOperatorPhone};   virtual UnicodeString get_ReceivePaymentsOperatorPhone(void)=0;   virtual void set_ReceivePaymentsOperatorPhone(UnicodeString ReceivePaymentsOperatorPhone  )=0;

//MoneyTransferOperatorPhone  Необязательно string Телефон оператора по переводу денежных средств
	__property UnicodeString MoneyTransferOperatorPhone = {read = get_MoneyTransferOperatorPhone , write = set_MoneyTransferOperatorPhone};   virtual UnicodeString get_MoneyTransferOperatorPhone(void)=0;   virtual void set_MoneyTransferOperatorPhone(UnicodeString MoneyTransferOperatorPhone  )=0;

//BankAgentPhone  Необязательно string Телефон банковского агента
	__property UnicodeString BankAgentPhone = {read = get_BankAgentPhone , write = set_BankAgentPhone};   virtual UnicodeString get_BankAgentPhone(void)=0;   virtual void set_BankAgentPhone(UnicodeString BankAgentPhone  )=0;

//BankSubagentPhone  Необязательно string Телефон банковского субагента
	__property UnicodeString BankSubagentPhone = {read = get_BankSubagentPhone , write = set_BankSubagentPhone};   virtual UnicodeString get_BankSubagentPhone(void)=0;   virtual void set_BankSubagentPhone(UnicodeString BankSubagentPhone )=0;

//BankAgentOperation Необязательно string Операция банковского агента
	__property UnicodeString BankAgentOperation = {read = get_BankAgentOperation , write = set_BankAgentOperation};   virtual UnicodeString get_BankAgentOperation(void)=0;   virtual void set_BankAgentOperation(UnicodeString BankAgentOperation)=0;


//BankSubagentOperation Необязательно string Операция банковского субагента
	__property UnicodeString BankSubagentOperation = {read = get_BankSubagentOperation , write = set_BankSubagentOperation};   virtual UnicodeString get_BankSubagentOperation(void)=0;   virtual void set_BankSubagentOperation(UnicodeString BankSubagentOperation)=0;

//BankAgentCompensation  Необязательно double Размер вознаграждения банковского агента (субагента)
	__property double BankAgentCompensation = {read = get_BankAgentCompensation , write = set_BankAgentCompensation};   virtual double get_BankAgentCompensation(void)=0;   virtual void set_BankAgentCompensation(double BankAgentCompensation)=0;


//MoneyTransferOperatorName Необязательно string Наименование оператора по переводу денежных средств
	__property UnicodeString MoneyTransferOperatorName = {read = get_MoneyTransferOperatorName , write = set_MoneyTransferOperatorName};   virtual UnicodeString get_MoneyTransferOperatorName(void)=0;   virtual void set_MoneyTransferOperatorName(UnicodeString MoneyTransferOperatorName)=0;


//MoneyTransferOperatorAddress  Необязательно string Адрес оператора по переводу денежных средств
	__property UnicodeString MoneyTransferOperatorAddress = {read = get_MoneyTransferOperatorAddress , write = set_MoneyTransferOperatorAddress};   virtual UnicodeString get_MoneyTransferOperatorAddress(void)=0;   virtual void set_MoneyTransferOperatorAddress(UnicodeString MoneyTransferOperatorAddress)=0;

//MoneyTransferOperatorVATIN  Необязательно string ИНН оператора по переводу денежных
	__property UnicodeString MoneyTransferOperatorVATIN = {read = get_MoneyTransferOperatorVATIN , write = MoneyTransferOperatorVATIN};   virtual UnicodeString get_MoneyTransferOperatorVATIN(void)=0;   virtual void set_MoneyTransferOperatorVATIN(UnicodeString MoneyTransferOperatorVATIN)=0;

 //ФОРМИРОВАНИЕ ТАБЛИЦЫ ЧЕКА
 //позиции чека, тип строки       1-фиск строка 2- текстовая строка 3-штрих код
	 __property int TypeFiscalString = {read = get_TypeFiscalString , write = set_TypeFiscalString};   virtual int get_TypeFiscalString(void)=0;    virtual void set_TypeFiscalString(int TypeFiscalString)=0;

	//FiscalString  Регистрирует фискальную строку с переданными реквизитами.
	//Name Да string  Наименование товара
	//При печати длинных фискальных строк необходимо делать перенос на следующую строку.
	 __property UnicodeString NameNom = {read = get_NameNom , write = set_NameNom};   virtual UnicodeString get_NameNom(void)=0;   virtual void set_NameNom(UnicodeString NameNom)=0;

	 //Quantity Да double Количество товара
	 __property double Quantity = {read = get_Quantity , write = set_Quantity};   virtual double get_Quantity(void)=0;   virtual void set_Quantity(double Quantity)=0;

	//Price Да double Цена единицы товара без учета скидок/наценок       !!!old version не используется
	__property double Price = {read = get_Price , write = set_Price};   virtual double get_Price(void)=0;   virtual void set_Price(double Price)=0;

		//Amount Да double Конечная сумма по позиции чека с учетом всех скидок/наценок    !!!old version  не используется
	__property double Amount = {read = get_Amount , write = set_Amount};   virtual double get_Amount(void)=0;   virtual void set_Amount(double Amount)=0;


	//PriceWithDiscount Да double Цена единицы товара с учетом скидок/наценок
	__property double PriceWithDiscount = {read = get_PriceWithDiscount , write = set_PriceWithDiscount};   virtual double get_PriceWithDiscount(void)=0;   virtual void set_PriceWithDiscount(double PriceWithDiscount)=0;

	//SumWithDiscount Да double Конечная сумма по позиции чека с учетом всех скидок/наценок
	__property double SumWithDiscount = {read = get_SumWithDiscount , write = set_SumWithDiscount};   virtual double get_SumWithDiscount(void)=0;   virtual void set_SumWithDiscount(double SumWithDiscount)=0;

   //SignMethodCalculation Нет long Признак способа расчета.
//			1 Предоплата полная
//			2 Предоплата частичная
//			3 Аванс
//			4 Полный расчет
//			5 Частичный расчет и кредит
//			6 Передача в кредит
//			7 Оплата кредита
	__property int SignMethodCalculation = {read = get_SignMethodCalculation , write = set_SignMethodCalculation};   virtual int get_SignMethodCalculation(void)=0;   virtual void set_SignMethodCalculation(int SignMethodCalculation)=0;


	//Department Нет long Отдел, по которому ведется продажа
	__property int Department = {read = get_Department , write = set_Department};   virtual int get_Department(void)=0;    virtual void set_Department(int Department)=0;

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
	__property int Tax = {read = get_Tax , write = set_Tax};   virtual int get_Tax(void)=0;    virtual void set_Tax(int Tax)=0;


	//TextString  Печать текстовой строки.
	//Text Да string Строка с произвольным текстом
	__property UnicodeString TextString = {read = get_TextString , write = set_TextString};   virtual UnicodeString get_TextString(void)=0;   virtual void set_TextString(UnicodeString TextString)=0;

	//Barcode   Печать штрихкода. Осуществляется с автоматическим размером с выравниванием по центру чека.
	//BarcodeType Да string Строка, определяющая тип штрихкода

	__property UnicodeString BarcodeType = {read = get_BarcodeType , write = set_BarcodeType};   virtual UnicodeString get_BarcodeType(void)=0;   virtual void set_BarcodeType(UnicodeString BarcodeType)=0;
	//Тип штрихкода может иметь одно из следующих значений: EAN8, EAN13, CODE39, QR. В случае, если модель устройства не поддерживает печать штрихкода, выдается ошибка.

	__property UnicodeString Barcode = {read = get_Barcode , write = set_Barcode};   virtual UnicodeString get_Barcode(void)=0;   virtual void set_Barcode(UnicodeString Barcode)=0;

 //Payments  Параметры закрытия чека. Сумма всех видов оплат должна быть больше суммы открытого чека.


//Cash Нет decimal Сумма наличной оплаты Параметры закрытия чека. Сумма всех видов оплат должна быть больше суммы открытого чека.
	__property double Cash = {read = get_Cash , write = set_Cash};   virtual double get_Cash(void)=0;   virtual void set_Cash(double Cash)=0;

//CashLessType1 Нет decimal Сумма электронной оплаты первого типа
	 __property double CashLessType1 = {read = get_CashLessType1 , write = set_CashLessType1};   virtual double get_CashLessType1(void)=0;   virtual void set_CashLessType1(double CashLessType1)=0;

//CashLessType2 Нет decimal Сумма электронной оплаты второго типа
	__property double CashLessType2 = {read = get_CashLessType2 , write = set_CashLessType2};   virtual double get_CashLessType2(void)=0;   virtual void set_CashLessType2(double CashLessType2)=0;

//CashLessType3 Нет decimal Сумма электронной оплаты третьего типа
	__property double CashLessType3 = {read = get_CashLessType3 , write = set_CashLessType3};   virtual double get_CashLessType3(void)=0;   virtual void set_CashLessType3(double CashLessType3)=0;



//ElectronicPayment Да decimal Сумма безналичными средствами
	__property double ElectronicPayment = {read = get_ElectronicPayment , write = set_ElectronicPayment};   virtual double get_ElectronicPayment(void)=0;   virtual void set_ElectronicPayment(double ElectronicPayment)=0;
//AdvancePayment  Да decimal Сумма предоплатой (зачетом аванса)
	__property double AdvancePayment = {read = get_AdvancePayment , write = set_AdvancePayment};   virtual double get_AdvancePayment(void)=0;   virtual void set_AdvancePayment(double AdvancePayment)=0;
//Credit Да decimal Сумма постоплатой (в кредит)
	__property double Credit = {read = get_Credit , write = set_Credit};   virtual double get_Credit(void)=0;   virtual void set_Credit(double Credit)=0;
//CashProvision Да decimal Сумма встречным предоставлением
	__property double CashProvision = {read = get_CashProvision , write = set_CashProvision};   virtual double get_CashProvision(void)=0;   virtual void set_CashProvision(double CashProvision)=0;














	virtual UnicodeString GetParameters(void)=0;
	virtual bool SetParameter(UnicodeString name_parameter, UnicodeString value_parameter)=0;


   virtual UnicodeString GetAdditionalActions(void)=0;
   virtual bool DoAdditionalAction(UnicodeString name_action)=0;


//	Кассир (CashierName) STRING [IN] ФИО уполномоченного лица для проведения операции
__property UnicodeString CashierName = {read = get_CashierName , write = set_CashierName};   virtual UnicodeString get_CashierName(void)=0;   virtual void set_CashierName(UnicodeString CashierName)=0;
//	Электронно (Electronically) BOOL (IN) Формирование чека в только электроном виде. Печать чека не осуществляется.
__property bool Electronically = {read = get_Electronically , write = set_Electronically};   virtual bool get_Electronically(void)=0;   virtual void set_Electronically(bool Electronically)=0;
//	ФискальныйПризнак (FiscalSign) STRING [OUT] Фискальный признак
__property UnicodeString FiscalSign = {read = get_FiscalSign , write = set_FiscalSign};   virtual UnicodeString get_FiscalSign(void)=0;   virtual void set_FiscalSign(UnicodeString FiscalSign)=0;
//	AddressSiteInspections (АдресСайтаПроверки) STRING [OUT] Адрес сайта проверки
__property UnicodeString AddressSiteInspections = {read = get_AddressSiteInspections , write = set_AddressSiteInspections};   virtual UnicodeString get_AddressSiteInspections(void)=0;   virtual void set_AddressSiteInspections(UnicodeString AddressSiteInspections)=0;

	virtual UnicodeString GetMetodsList(void)=0;

	virtual bool GetParameter(UnicodeString name_parameter, TkasVariant * value_parameter)=0;
	virtual bool SetParameter(UnicodeString name_parameter, TkasVariant * value_parameter)=0;

//***********************************************************************************

	virtual bool RunCommand(UnicodeString command_name, UnicodeString xml_doc, int type_doc)=0;
                    //если type = 0 то не используем xml_doc, а используем сформированный построчно файл

	virtual UnicodeString ReturnXmlResultLastMethod(void)=0;

	//параметры для выполнения метода
	virtual bool SetStringParameter(UnicodeString param_name, int number, UnicodeString value)=0;
	virtual UnicodeString GetStringParameter(UnicodeString param_name, int number)=0;

	virtual bool SetIntegerParameter(UnicodeString param_name, int number, int value)=0;
	virtual int GetIntegerParameter(UnicodeString param_name, int number)=0;

	virtual bool SetDoubleParameter(UnicodeString param_name, int number, double value)=0;
	virtual double GetDoubleParameter(UnicodeString param_name, int number)=0;

	virtual bool SetBooleanParameter(UnicodeString param_name, int number, bool value)=0;
	virtual bool GetBooleanParameter(UnicodeString param_name, int number)=0;

	virtual bool SetDateTimeParameter(UnicodeString param_name, int number, TDateTime value)=0;
	virtual TDateTime GetDateTimeParameter(UnicodeString param_name, int number)=0;

	virtual bool SetXmlParameter(UnicodeString param_name, int number, UnicodeString xml_value, int type_source_xml)=0;
	virtual UnicodeString GetXmlParameter(UnicodeString param_name, int number, int type_source_xml)=0;

	virtual bool SetIdDeviceParameter(UnicodeString param_name, int number, UnicodeString id_device, int type_source_id_device)=0;
	virtual UnicodeString GetIDDeviceParameter(UnicodeString param_name, int number, int type_source_id_device)=0;

	//формирование xml файла
	virtual void AddStringXml(UnicodeString str_xml)=0;    //просто готовая строка
	virtual void AddAttribyteXml(UnicodeString attribyte, UnicodeString value, int type_value)=0;  //тип для форматирования, например для удаления запятых в числах
	virtual void AddElementXml(UnicodeString element, UnicodeString value, int type_value)=0;

	virtual void AddStringForPrintXml(UnicodeString element, UnicodeString attribyte, UnicodeString value,
								int size_font,  //1234
								int style,    //1-жирный 0 обычный   2 курсив 3 жирный курсив
								int alignment,  //0 лево 1 центр 2 право
								bool word_wrap)=0;   //строка xml для печати будет формироваться



};
#define IID_IFiskReg __uuidof(IFiskReg)
#endif
