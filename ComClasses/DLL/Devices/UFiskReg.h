//---------------------------------------------------------------------------

#ifndef UFiskRegH
#define UFiskRegH
#include <vcl.h>
#include "GlobalInterface.h"
#include "UkasVariant.h"
class TFiskReg
        {
private:

       HINSTANCE dllIn;

		typedef WideString (__import  DllGetTextErrorType(void));
		typedef bool (__import  DllConnectType(int,WideString,WideString));
        typedef void (__import  DllDisconnectType(void));
		typedef bool (__import  DllPrintStringType(WideString,int,int,int,bool,bool, bool));
		typedef bool (__import  DllPrintFiscalCheckType(double,int,double,double,double,double,int));
		typedef bool (__import  DllPrintNoFiscalCheckType(double,int,double,double,double,double,int));
		typedef bool (__import  DllPrintXReportType(void));
        typedef bool (__import  DllPrintZReportType(void));
        typedef bool (__import  DllPrintPoOtdelamReportType(void));
        typedef bool (__import  DllCutType(int));
        typedef bool (__import  DllVnesenieType(double));
        typedef bool (__import  DllSnatieType(double));
        typedef bool (__import  DllPrintLineType(void));

        typedef bool (__import  DllOpenNoFiscalCheckType(void));
        typedef bool (__import  DllCloseNoFiscalCheckType(void));

        typedef bool (__import  DllGetSostKKMType(void));
        typedef bool (__import  DllProvVosmPrintCheckType(void));

        typedef int (__import  DllGetNumberCheckType(void));
        typedef int (__import  DllGetNumberKLType(void));
		typedef WideString (__import  DllGetSerialNumberKKMType(void));
		typedef WideString (__import  DllGetRegNumberKKMType(void));
		typedef WideString (__import  DllGetModelKKMType(void));


		typedef bool (__import  DllSetTimeKKMType(WideString));
		typedef bool (__import  DllSetDateKKMType(WideString));
		typedef WideString (__import  DllGetTimeKKMType(void));
		typedef WideString (__import  DllGetDateKKMType(void));

        DllGetTextErrorType * DllGetTextError;
        DllConnectType * DllConnect;
        DllDisconnectType * DllDisconnect;
        DllPrintStringType * DllPrintString;
        DllPrintFiscalCheckType * DllPrintFiscalCheck;
        DllPrintNoFiscalCheckType * DllPrintNoFiscalCheck;
        DllPrintXReportType * DllPrintXReport;
        DllPrintZReportType * DllPrintZReport;
        DllPrintPoOtdelamReportType * DllPrintPoOtdelamReport;
        DllCutType * DllCut;
        DllVnesenieType * DllVnesenie;
        DllSnatieType * DllSnatie;
        DllPrintLineType * DllPrintLine;

        DllOpenNoFiscalCheckType * DllOpenNoFiscalCheck;
        DllCloseNoFiscalCheckType * DllCloseNoFiscalCheck;

        DllGetSostKKMType * DllGetSostKKM;
        DllProvVosmPrintCheckType * DllProvVosmPrintCheck;

        DllGetNumberCheckType * DllGetNumberCheck;
        DllGetNumberKLType * DllGetNumberKL;
		DllGetSerialNumberKKMType * DllGetSerialNumberKKM;
		DllGetRegNumberKKMType * DllGetRegNumberKKM;
		DllGetModelKKMType * DllGetModelKKM;

		DllGetTimeKKMType * DllGetTimeKKM;
		DllGetDateKKMType * DllGetDateKKM;
		DllSetTimeKKMType * DllSetTimeKKM;
		DllSetDateKKMType * DllSetDateKKM;
 public:
        TFiskReg();
        ~TFiskReg();

		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации




        int Number;
		AnsiString Modul;
		UnicodeString Name;
		bool Error;
		int CodeError;
		UnicodeString TextError;
		UnicodeString TextErrorNoConnect;
		bool ConnectFR;

		int Init();
		int Done();
		bool InitDevice();

		bool Connect(int number_port,
						UnicodeString baud_rate,
						UnicodeString password);

        bool Disconnect(void);

		bool PrintString(UnicodeString str,
                                int size_font,       //1234
                                int girn,            //1-жирный 0 обычный
                                int alignment,      //0 лево 1 центр 2 право
                                bool ch_lenta,       //на чековой ленте
								bool kontr_lenta,   //на контрольной ленте
								bool word_wrap);


        bool PrintFiscalCheck(double sum,
                                int department,
                                double oplata_nal,
								double oplata_bank_card,
								double oplata_plat_card,
								double oplata_credit_card,
                                int operation);    //0 продажа 1 возврат

        bool PrintNoFiscalCheck(double sum,
                                int department,
								double oplata_nal,
								double oplata_bank_card,
								double oplata_plat_card,
								double oplata_credit_card,
                                int operation);    //0 продажа 1 возврат

        bool PrintXReport(void);
        bool PrintZReport(void);
        bool PrintPoOtdelamReport(void);

        bool Cut(int TypeCut);
        bool Vnesenie(float sum);
        bool Snatie(float sum);

        bool PrintLine(void);

        bool OpenNoFiscalCheck(void);
        bool CloseNoFiscalCheck(void);

        bool GetSostKKM(void);
        bool ProvVosmPrintCheck(void);

        //параметры ККМ и чека
                int NumberCheck;
                int NumberKL;
				UnicodeString SerialNumberKKM;
				UnicodeString RegNumberKKM;
				UnicodeString ModelKKM;

		//время и дата
		TTime GetTime(void);
		TDate GetDate(void);
		bool SetTime(TTime time);
		bool SetDate(TDate date);





   //новые функции для работы с он-лайн кассами
   bool OpenShift(void);
   bool CloseShift(void);
   bool InitDocument(int type_doc);
   bool CreateHeaderFiscalCheck(void);
   bool CreateFooterFiscalCheck(void);
   bool AddFiscalString(void);



//параметры чека  //заголовок 	Parameters
// Обязательно long Тип расчета
//1 - Приход
//2 - Возврат прихода
//3 - Расход
//4 - Возврат расхода
//Формирование нового чека с заданным атрибутами.

	int PaymentType;


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

	int TaxVariant;

//CustomerEmail Необязательно string Email покупателя
	UnicodeString CustomerEmail;

//CustomerPhone Необязательно string Телефонный номер покупателя
	UnicodeString CustomerPhone;

//AgentCompensation Необязательно double Размер вознаграждения агента
	double AgentCompensation;

//AgentPhone Необязательно string Контактный телефон агента
	UnicodeString AgentPhone;

//SubagentPhone Необязательно string Телефон платежного субагента
	UnicodeString SubagentPhone;

//ReceivePaymentsOperatorPhone  Необязательно string Телефон оператора по приему платежей
	UnicodeString ReceivePaymentsOperatorPhone;

//MoneyTransferOperatorPhone  Необязательно string Телефон оператора по переводу денежных средств
	UnicodeString MoneyTransferOperatorPhone;

//BankAgentPhone  Необязательно string Телефон банковского агента
	UnicodeString BankAgentPhone;

//BankSubagentPhone  Необязательно string Телефон банковского субагента
	UnicodeString BankSubagentPhone;

//BankAgentOperation Необязательно string Операция банковского агента
	UnicodeString BankAgentOperation;


//BankSubagentOperation Необязательно string Операция банковского субагента
	UnicodeString BankSubagentOperation;

//BankAgentCompensation  Необязательно double Размер вознаграждения банковского агента (субагента)
	double BankAgentCompensation ;


//MoneyTransferOperatorName Необязательно string Наименование оператора по переводу денежных средств
	UnicodeString MoneyTransferOperatorName ;


//MoneyTransferOperatorAddress  Необязательно string Адрес оператора по переводу денежных средств
	UnicodeString MoneyTransferOperatorAddress ;

//MoneyTransferOperatorVATIN  Необязательно string ИНН оператора по переводу денежных
	UnicodeString MoneyTransferOperatorVATIN ;

 //ФОРМИРОВАНИЕ ТАБЛИЦЫ ЧЕКА
 //позиции чека, тип строки       1-фиск строка 2- текстовая строка 3-штрих код
	int TypeFiscalString;

	//FiscalString  Регистрирует фискальную строку с переданными реквизитами.
	//Name Да string  Наименование товара
	//При печати длинных фискальных строк необходимо делать перенос на следующую строку.
	UnicodeString NameNom;

	 //Quantity Да double Количество товара
	double Quantity;

	//Price Да double Цена единицы товара без учета скидок/наценок
	double Price;

	//Amount Да double Конечная сумма по позиции чека (с учетом всех скидок/наценок)
	double Amount;




			//PriceWithDiscount Да double Цена единицы товара с учетом скидок/наценок
	double PriceWithDiscount;


	//Amount Да double Конечная сумма по позиции чека с учетом всех скидок/наценок
	double SumWithDiscount;

   //SignMethodCalculation Нет long Признак способа расчета.
//			1 Предоплата полная
//			2 Предоплата частичная
//			3 Аванс
//			4 Полный расчет
//			5 Частичный расчет и кредит
//			6 Передача в кредит
//			7 Оплата кредита
	int SignMethodCalculation;

	//Department Нет long Отдел, по которому ведется продажа
	int Department;

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
	int Tax;


	//TextString  Печать текстовой строки.
	//Text Да string Строка с произвольным текстом
	UnicodeString TextString;

	//Barcode   Печать штрихкода. Осуществляется с автоматическим размером с выравниванием по центру чека.
	//BarcodeType Да string Строка, определяющая тип штрихкода

	UnicodeString BarcodeType ;
	//Тип штрихкода может иметь одно из следующих значений: EAN8, EAN13, CODE39, QR. В случае, если модель устройства не поддерживает печать штрихкода, выдается ошибка.

	UnicodeString Barcode;

 //Payments  Параметры закрытия чека. Сумма всех видов оплат должна быть больше суммы открытого чека.


//Cash Нет decimal Сумма наличной оплаты Параметры закрытия чека. Сумма всех видов оплат должна быть больше суммы открытого чека.
	double Cash;

//CashLessType1 Нет decimal Сумма электронной оплаты первого типа
	double CashLessType1;

//CashLessType2 Нет decimal Сумма электронной оплаты второго типа
	double CashLessType2;

//CashLessType3 Нет decimal Сумма электронной оплаты третьего типа
	double CashLessType3 ;

	//ElectronicPayment Да decimal Сумма безналичными средствами
	double ElectronicPayment;
//AdvancePayment  Да decimal Сумма предоплатой (зачетом аванса)
	double AdvancePayment;
//Credit Да decimal Сумма постоплатой (в кредит)
	double Credit;
//CashProvision Да decimal Сумма встречным предоставлением
	double CashProvision;

	UnicodeString GetParameters(void);
	bool SetParameter(UnicodeString name_parameter, UnicodeString value_parameter);


   UnicodeString GetAdditionalActions(void);
   bool DoAdditionalAction(UnicodeString name_action);

      //	Кассир (CashierName) STRING [IN] ФИО уполномоченного лица для проведения операции
UnicodeString CashierName;
//	Электронно (Electronically) BOOL (IN) Формирование чека в только электроном виде. Печать чека не осуществляется.
bool Electronically;
//	ФискальныйПризнак (FiscalSign) STRING [OUT] Фискальный признак
UnicodeString FiscalSign;
//	AddressSiteInspections (АдресСайтаПроверки) STRING [OUT] Адрес сайта проверки
UnicodeString AddressSiteInspections;


UnicodeString GetMetodsList(void);

bool GetParameter(UnicodeString name_parameter, TkasVariant * value_parameter);
bool SetParameter(UnicodeString name_parameter, TkasVariant * value_parameter);




//**********************************************************************
//**********************************************************************
//***********************************************************************************

bool RunCommand(UnicodeString command_name, UnicodeString xml_doc, int type_doc);
					//если type = 0 то не используем xml_doc, а используем сформированный построчно файл

UnicodeString ReturnXmlResultLastMethod(void);

	//параметры для выполнения метода
bool SetStringParameter(UnicodeString param_name, int number, UnicodeString value);
UnicodeString GetStringParameter(UnicodeString param_name, int number);

bool SetIntegerParameter(UnicodeString param_name, int number, int value);
int GetIntegerParameter(UnicodeString param_name, int number);

bool SetDoubleParameter(UnicodeString param_name, int number, double value);
double GetDoubleParameter(UnicodeString param_name, int number);

bool SetBooleanParameter(UnicodeString param_name, int number, bool value);
bool GetBooleanParameter(UnicodeString param_name, int number);

bool SetDateTimeParameter(UnicodeString param_name, int number, TDateTime value);
TDateTime GetDateTimeParameter(UnicodeString param_name, int number);

	//формирование xml файла
void AddStringXml(UnicodeString str_xml);    //просто готовая строка
void AddAttribyteXml(UnicodeString attribyte, UnicodeString value, int type_value);  //тип для форматирования, например для удаления запятых в числах
void AddElementXml(UnicodeString element, UnicodeString value, int type_value);

void AddStringForPrintXml(UnicodeString element, UnicodeString attribyte, UnicodeString value,
								int size_font, int girn, int alignment, bool word_wrap);   //строка xml для печати будет формироваться



};
//---------------------------------------------------------------------------
#endif
