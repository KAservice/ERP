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

   //����� ������� ��� ������ � ��-���� �������
   virtual bool OpenShift(void)=0;
   virtual bool CloseShift(void)=0;
   virtual bool InitDocument(int type_doc)=0;    //1 ������������ ���, 2 ���������� ���
   virtual bool CreateHeaderFiscalCheck(void)=0;
   virtual bool CreateFooterFiscalCheck(void)=0;
   virtual bool AddFiscalString(void)=0;


//��������� ����  //��������� 	Parameters
// ����������� long ��� �������
//1 - ������
//2 - ������� �������
//3 - ������
//4 - ������� ������� ������������ ������ ���� � �������� ����������.

   __property int PaymentType = {read = get_PaymentType , write = set_PaymentType};    virtual int get_PaymentType(void)=0;   virtual void set_PaymentType(int PaymentType)=0;


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

   __property int TaxVariant = {read = get_TaxVariant , write = set_TaxVariant};   virtual int get_TaxVariant(void)=0;    virtual void set_TaxVariant(int TaxVariant)=0;

//CustomerEmail ������������� string Email ����������
   __property UnicodeString CustomerEmail = {read = get_CustomerEmail , write = set_CustomerEmail};   virtual UnicodeString get_CustomerEmail(void)=0;   virtual void set_CustomerEmail(UnicodeString CustomerEmail)=0;

//CustomerPhone ������������� string ���������� ����� ����������
   __property UnicodeString CustomerPhone = {read = get_CustomerPhone , write = set_CustomerPhone};   virtual UnicodeString get_CustomerPhone(void)=0;   virtual void set_CustomerPhone(UnicodeString CustomerPhone  )=0;

//AgentCompensation ������������� double ������ �������������� ������
	__property double AgentCompensation = {read = get_AgentCompensation , write = set_AgentCompensation};   virtual double get_AgentCompensation(void)=0;    virtual void set_AgentCompensation(double AgentCompensation)=0;

//AgentPhone ������������� string ���������� ������� ������
	__property UnicodeString AgentPhone = {read = get_AgentPhone , write = set_AgentPhone};   virtual UnicodeString get_AgentPhone(void)=0;   virtual void set_AgentPhone(UnicodeString AgentPhone  )=0;

//SubagentPhone ������������� string ������� ���������� ���������
	__property UnicodeString SubagentPhone = {read = get_SubagentPhone , write = set_SubagentPhone};   virtual UnicodeString get_SubagentPhone(void)=0;   virtual void set_SubagentPhone(UnicodeString SubagentPhone  )=0;

//ReceivePaymentsOperatorPhone  ������������� string ������� ��������� �� ������ ��������
	__property UnicodeString ReceivePaymentsOperatorPhone = {read = get_ReceivePaymentsOperatorPhone , write = set_ReceivePaymentsOperatorPhone};   virtual UnicodeString get_ReceivePaymentsOperatorPhone(void)=0;   virtual void set_ReceivePaymentsOperatorPhone(UnicodeString ReceivePaymentsOperatorPhone  )=0;

//MoneyTransferOperatorPhone  ������������� string ������� ��������� �� �������� �������� �������
	__property UnicodeString MoneyTransferOperatorPhone = {read = get_MoneyTransferOperatorPhone , write = set_MoneyTransferOperatorPhone};   virtual UnicodeString get_MoneyTransferOperatorPhone(void)=0;   virtual void set_MoneyTransferOperatorPhone(UnicodeString MoneyTransferOperatorPhone  )=0;

//BankAgentPhone  ������������� string ������� ����������� ������
	__property UnicodeString BankAgentPhone = {read = get_BankAgentPhone , write = set_BankAgentPhone};   virtual UnicodeString get_BankAgentPhone(void)=0;   virtual void set_BankAgentPhone(UnicodeString BankAgentPhone  )=0;

//BankSubagentPhone  ������������� string ������� ����������� ���������
	__property UnicodeString BankSubagentPhone = {read = get_BankSubagentPhone , write = set_BankSubagentPhone};   virtual UnicodeString get_BankSubagentPhone(void)=0;   virtual void set_BankSubagentPhone(UnicodeString BankSubagentPhone )=0;

//BankAgentOperation ������������� string �������� ����������� ������
	__property UnicodeString BankAgentOperation = {read = get_BankAgentOperation , write = set_BankAgentOperation};   virtual UnicodeString get_BankAgentOperation(void)=0;   virtual void set_BankAgentOperation(UnicodeString BankAgentOperation)=0;


//BankSubagentOperation ������������� string �������� ����������� ���������
	__property UnicodeString BankSubagentOperation = {read = get_BankSubagentOperation , write = set_BankSubagentOperation};   virtual UnicodeString get_BankSubagentOperation(void)=0;   virtual void set_BankSubagentOperation(UnicodeString BankSubagentOperation)=0;

//BankAgentCompensation  ������������� double ������ �������������� ����������� ������ (���������)
	__property double BankAgentCompensation = {read = get_BankAgentCompensation , write = set_BankAgentCompensation};   virtual double get_BankAgentCompensation(void)=0;   virtual void set_BankAgentCompensation(double BankAgentCompensation)=0;


//MoneyTransferOperatorName ������������� string ������������ ��������� �� �������� �������� �������
	__property UnicodeString MoneyTransferOperatorName = {read = get_MoneyTransferOperatorName , write = set_MoneyTransferOperatorName};   virtual UnicodeString get_MoneyTransferOperatorName(void)=0;   virtual void set_MoneyTransferOperatorName(UnicodeString MoneyTransferOperatorName)=0;


//MoneyTransferOperatorAddress  ������������� string ����� ��������� �� �������� �������� �������
	__property UnicodeString MoneyTransferOperatorAddress = {read = get_MoneyTransferOperatorAddress , write = set_MoneyTransferOperatorAddress};   virtual UnicodeString get_MoneyTransferOperatorAddress(void)=0;   virtual void set_MoneyTransferOperatorAddress(UnicodeString MoneyTransferOperatorAddress)=0;

//MoneyTransferOperatorVATIN  ������������� string ��� ��������� �� �������� ��������
	__property UnicodeString MoneyTransferOperatorVATIN = {read = get_MoneyTransferOperatorVATIN , write = MoneyTransferOperatorVATIN};   virtual UnicodeString get_MoneyTransferOperatorVATIN(void)=0;   virtual void set_MoneyTransferOperatorVATIN(UnicodeString MoneyTransferOperatorVATIN)=0;

 //������������ ������� ����
 //������� ����, ��� ������       1-���� ������ 2- ��������� ������ 3-����� ���
	 __property int TypeFiscalString = {read = get_TypeFiscalString , write = set_TypeFiscalString};   virtual int get_TypeFiscalString(void)=0;    virtual void set_TypeFiscalString(int TypeFiscalString)=0;

	//FiscalString  ������������ ���������� ������ � ����������� �����������.
	//Name �� string  ������������ ������
	//��� ������ ������� ���������� ����� ���������� ������ ������� �� ��������� ������.
	 __property UnicodeString NameNom = {read = get_NameNom , write = set_NameNom};   virtual UnicodeString get_NameNom(void)=0;   virtual void set_NameNom(UnicodeString NameNom)=0;

	 //Quantity �� double ���������� ������
	 __property double Quantity = {read = get_Quantity , write = set_Quantity};   virtual double get_Quantity(void)=0;   virtual void set_Quantity(double Quantity)=0;

	//Price �� double ���� ������� ������ ��� ����� ������/�������       !!!old version �� ������������
	__property double Price = {read = get_Price , write = set_Price};   virtual double get_Price(void)=0;   virtual void set_Price(double Price)=0;

		//Amount �� double �������� ����� �� ������� ���� � ������ ���� ������/�������    !!!old version  �� ������������
	__property double Amount = {read = get_Amount , write = set_Amount};   virtual double get_Amount(void)=0;   virtual void set_Amount(double Amount)=0;


	//PriceWithDiscount �� double ���� ������� ������ � ������ ������/�������
	__property double PriceWithDiscount = {read = get_PriceWithDiscount , write = set_PriceWithDiscount};   virtual double get_PriceWithDiscount(void)=0;   virtual void set_PriceWithDiscount(double PriceWithDiscount)=0;

	//SumWithDiscount �� double �������� ����� �� ������� ���� � ������ ���� ������/�������
	__property double SumWithDiscount = {read = get_SumWithDiscount , write = set_SumWithDiscount};   virtual double get_SumWithDiscount(void)=0;   virtual void set_SumWithDiscount(double SumWithDiscount)=0;

   //SignMethodCalculation ��� long ������� ������� �������.
//			1 ���������� ������
//			2 ���������� ���������
//			3 �����
//			4 ������ ������
//			5 ��������� ������ � ������
//			6 �������� � ������
//			7 ������ �������
	__property int SignMethodCalculation = {read = get_SignMethodCalculation , write = set_SignMethodCalculation};   virtual int get_SignMethodCalculation(void)=0;   virtual void set_SignMethodCalculation(int SignMethodCalculation)=0;


	//Department ��� long �����, �� �������� ������� �������
	__property int Department = {read = get_Department , write = set_Department};   virtual int get_Department(void)=0;    virtual void set_Department(int Department)=0;

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
	__property int Tax = {read = get_Tax , write = set_Tax};   virtual int get_Tax(void)=0;    virtual void set_Tax(int Tax)=0;


	//TextString  ������ ��������� ������.
	//Text �� string ������ � ������������ �������
	__property UnicodeString TextString = {read = get_TextString , write = set_TextString};   virtual UnicodeString get_TextString(void)=0;   virtual void set_TextString(UnicodeString TextString)=0;

	//Barcode   ������ ���������. �������������� � �������������� �������� � ������������� �� ������ ����.
	//BarcodeType �� string ������, ������������ ��� ���������

	__property UnicodeString BarcodeType = {read = get_BarcodeType , write = set_BarcodeType};   virtual UnicodeString get_BarcodeType(void)=0;   virtual void set_BarcodeType(UnicodeString BarcodeType)=0;
	//��� ��������� ����� ����� ���� �� ��������� ��������: EAN8, EAN13, CODE39, QR. � ������, ���� ������ ���������� �� ������������ ������ ���������, �������� ������.

	__property UnicodeString Barcode = {read = get_Barcode , write = set_Barcode};   virtual UnicodeString get_Barcode(void)=0;   virtual void set_Barcode(UnicodeString Barcode)=0;

 //Payments  ��������� �������� ����. ����� ���� ����� ����� ������ ���� ������ ����� ��������� ����.


//Cash ��� decimal ����� �������� ������ ��������� �������� ����. ����� ���� ����� ����� ������ ���� ������ ����� ��������� ����.
	__property double Cash = {read = get_Cash , write = set_Cash};   virtual double get_Cash(void)=0;   virtual void set_Cash(double Cash)=0;

//CashLessType1 ��� decimal ����� ����������� ������ ������� ����
	 __property double CashLessType1 = {read = get_CashLessType1 , write = set_CashLessType1};   virtual double get_CashLessType1(void)=0;   virtual void set_CashLessType1(double CashLessType1)=0;

//CashLessType2 ��� decimal ����� ����������� ������ ������� ����
	__property double CashLessType2 = {read = get_CashLessType2 , write = set_CashLessType2};   virtual double get_CashLessType2(void)=0;   virtual void set_CashLessType2(double CashLessType2)=0;

//CashLessType3 ��� decimal ����� ����������� ������ �������� ����
	__property double CashLessType3 = {read = get_CashLessType3 , write = set_CashLessType3};   virtual double get_CashLessType3(void)=0;   virtual void set_CashLessType3(double CashLessType3)=0;



//ElectronicPayment �� decimal ����� ������������ ����������
	__property double ElectronicPayment = {read = get_ElectronicPayment , write = set_ElectronicPayment};   virtual double get_ElectronicPayment(void)=0;   virtual void set_ElectronicPayment(double ElectronicPayment)=0;
//AdvancePayment  �� decimal ����� ����������� (������� ������)
	__property double AdvancePayment = {read = get_AdvancePayment , write = set_AdvancePayment};   virtual double get_AdvancePayment(void)=0;   virtual void set_AdvancePayment(double AdvancePayment)=0;
//Credit �� decimal ����� ����������� (� ������)
	__property double Credit = {read = get_Credit , write = set_Credit};   virtual double get_Credit(void)=0;   virtual void set_Credit(double Credit)=0;
//CashProvision �� decimal ����� ��������� ���������������
	__property double CashProvision = {read = get_CashProvision , write = set_CashProvision};   virtual double get_CashProvision(void)=0;   virtual void set_CashProvision(double CashProvision)=0;














	virtual UnicodeString GetParameters(void)=0;
	virtual bool SetParameter(UnicodeString name_parameter, UnicodeString value_parameter)=0;


   virtual UnicodeString GetAdditionalActions(void)=0;
   virtual bool DoAdditionalAction(UnicodeString name_action)=0;


//	������ (CashierName) STRING [IN] ��� ��������������� ���� ��� ���������� ��������
__property UnicodeString CashierName = {read = get_CashierName , write = set_CashierName};   virtual UnicodeString get_CashierName(void)=0;   virtual void set_CashierName(UnicodeString CashierName)=0;
//	���������� (Electronically) BOOL (IN) ������������ ���� � ������ ���������� ����. ������ ���� �� ��������������.
__property bool Electronically = {read = get_Electronically , write = set_Electronically};   virtual bool get_Electronically(void)=0;   virtual void set_Electronically(bool Electronically)=0;
//	����������������� (FiscalSign) STRING [OUT] ���������� �������
__property UnicodeString FiscalSign = {read = get_FiscalSign , write = set_FiscalSign};   virtual UnicodeString get_FiscalSign(void)=0;   virtual void set_FiscalSign(UnicodeString FiscalSign)=0;
//	AddressSiteInspections (������������������) STRING [OUT] ����� ����� ��������
__property UnicodeString AddressSiteInspections = {read = get_AddressSiteInspections , write = set_AddressSiteInspections};   virtual UnicodeString get_AddressSiteInspections(void)=0;   virtual void set_AddressSiteInspections(UnicodeString AddressSiteInspections)=0;

	virtual UnicodeString GetMetodsList(void)=0;

	virtual bool GetParameter(UnicodeString name_parameter, TkasVariant * value_parameter)=0;
	virtual bool SetParameter(UnicodeString name_parameter, TkasVariant * value_parameter)=0;

//***********************************************************************************

	virtual bool RunCommand(UnicodeString command_name, UnicodeString xml_doc, int type_doc)=0;
                    //���� type = 0 �� �� ���������� xml_doc, � ���������� �������������� ��������� ����

	virtual UnicodeString ReturnXmlResultLastMethod(void)=0;

	//��������� ��� ���������� ������
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

	//������������ xml �����
	virtual void AddStringXml(UnicodeString str_xml)=0;    //������ ������� ������
	virtual void AddAttribyteXml(UnicodeString attribyte, UnicodeString value, int type_value)=0;  //��� ��� ��������������, �������� ��� �������� ������� � ������
	virtual void AddElementXml(UnicodeString element, UnicodeString value, int type_value)=0;

	virtual void AddStringForPrintXml(UnicodeString element, UnicodeString attribyte, UnicodeString value,
								int size_font,  //1234
								int style,    //1-������ 0 �������   2 ������ 3 ������ ������
								int alignment,  //0 ���� 1 ����� 2 �����
								bool word_wrap)=0;   //������ xml ��� ������ ����� �������������



};
#define IID_IFiskReg __uuidof(IFiskReg)
#endif
