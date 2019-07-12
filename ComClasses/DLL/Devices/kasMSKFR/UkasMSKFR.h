//---------------------------------------------------------------------------

#ifndef UkasMSKFRH
#define UkasMSKFRH
#include <vcl.h>
#include "GlobalInterface.h"
#include "MercFPrtX_TLB.h"
#include "UkasVariant.h"
class TkasMSKFR
		{
private:

IMercuryFPrt *Merc;
Variant  FR;
UnicodeString DopStrL(UnicodeString Str, UnicodeString Symbol, int Len);
UnicodeString DopStrR(UnicodeString Str, UnicodeString Symbol, int Len);
void OpenDrawer(void);
int CompareDoubleValue(double v1, double v2, int pogr);

		bool PrintFiscalCheckSale(double sum,
														int department,
														double oplata_nal,
														double oplata_bank_card,
														double oplata_plat_card,
														double oplata_credit_card,
														int operation);    //0 ������� 1 �������

		bool PrintFiscalCheckReturnSale(double sum,
														int department,
														double oplata_nal,
														double oplata_bank_card,
														double oplata_plat_card,
														double oplata_credit_card,
														int operation);    //0 ������� 1 �������


		int KolSymbolSize1;
		int KolSymbolSize1Girn;
		int KolSymbolSize2;
		int KolSymbolSize2Girn;
		int KolSymbolSize3;
		int KolSymbolSize3Girn;
		int KolSymbolSize4;
		int KolSymbolSize4Girn;
 public:
		TkasMSKFR();
        ~TkasMSKFR();

		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //��������� ������ ����������
		GUID ClsIdImpl;				 //GUID ������ ����������



bool NoPrint;
bool UseJournalRibbon;
bool UseReceiptRibbon;
bool OpenNoFiscalDoc;


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


		bool Connect(int number_port,
						UnicodeString baud_rate,
						UnicodeString password);

		bool Disconnect(void);

		bool GetSostKKM(void);
		bool ProvVosmPrintCheck(void);


		bool PrintString(UnicodeString str,
                                int size_font,       //1234
                                int girn,            //1-������ 0 �������
                                int alignment,      //0 ���� 1 ����� 2 �����
                                bool ch_lenta,       //�� ������� �����
								bool kontr_lenta,   //�� ����������� �����
								bool word_wrap);


        bool PrintFiscalCheck(double sum,
                                int department,
                                double oplata_nal,
								double oplata_bank_card,
								double oplata_plat_card,
								double oplata_credit_card,
								int operation);    //0 ������� 1 �������







		bool PrintNoFiscalCheck(double sum,
                                int department,
								double oplata_nal,
								double oplata_bank_card,
								double oplata_plat_card,
								double oplata_credit_card,
                                int operation);    //0 ������� 1 �������

        bool PrintXReport(void);
        bool PrintZReport(void);
        bool PrintPoOtdelamReport(void);

        bool Cut(int TypeCut);
		bool Vnesenie(double sum);
        bool Snatie(double sum);

        bool PrintLine(void);

        bool OpenNoFiscalCheck(void);
        bool CloseNoFiscalCheck(void);


        //��������� ��� � ����
                int NumberCheck;
                int NumberKL;
				UnicodeString SerialNumberKKM;
				UnicodeString RegNumberKKM;
				UnicodeString ModelKKM;

		//����� � ����
		TTime GetTime(void);
		TDate GetDate(void);
		bool SetTime(TTime time);
		bool SetDate(TDate date);





   //����� ������� ��� ������ � ��-���� �������
   bool OpenShift(void);
   bool CloseShift(void);
   bool InitDocument(int type_doc);
   bool CreateHeaderFiscalCheck(void);
   bool CreateFooterFiscalCheck(void);
   bool AddFiscalString(void);



//��������� ����  //��������� 	Parameters
// ����������� long ��� �������
//1 - ������
//2 - ������� �������
//3 - ������
//4 - ������� �������
//������������ ������ ���� � �������� ����������.

	int PaymentType;


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

	int TaxVariant;

//CustomerEmail ������������� string Email ����������
	UnicodeString CustomerEmail;

//CustomerPhone ������������� string ���������� ����� ����������
	UnicodeString CustomerPhone;

//AgentCompensation ������������� double ������ �������������� ������
	double AgentCompensation;

//AgentPhone ������������� string ���������� ������� ������
	UnicodeString AgentPhone;

//SubagentPhone ������������� string ������� ���������� ���������
	UnicodeString SubagentPhone;

//ReceivePaymentsOperatorPhone  ������������� string ������� ��������� �� ������ ��������
	UnicodeString ReceivePaymentsOperatorPhone;

//MoneyTransferOperatorPhone  ������������� string ������� ��������� �� �������� �������� �������
	UnicodeString MoneyTransferOperatorPhone;

//BankAgentPhone  ������������� string ������� ����������� ������
	UnicodeString BankAgentPhone;

//BankSubagentPhone  ������������� string ������� ����������� ���������
	UnicodeString BankSubagentPhone;

//BankAgentOperation ������������� string �������� ����������� ������
	UnicodeString BankAgentOperation;


//BankSubagentOperation ������������� string �������� ����������� ���������
	UnicodeString BankSubagentOperation;

//BankAgentCompensation  ������������� double ������ �������������� ����������� ������ (���������)
	double BankAgentCompensation ;


//MoneyTransferOperatorName ������������� string ������������ ��������� �� �������� �������� �������
	UnicodeString MoneyTransferOperatorName ;


//MoneyTransferOperatorAddress  ������������� string ����� ��������� �� �������� �������� �������
	UnicodeString MoneyTransferOperatorAddress ;

//MoneyTransferOperatorVATIN  ������������� string ��� ��������� �� �������� ��������
	UnicodeString MoneyTransferOperatorVATIN ;

 //������������ ������� ����
 //������� ����, ��� ������       1-���� ������ 2- ��������� ������ 3-����� ���
	int TypeFiscalString;

	//FiscalString  ������������ ���������� ������ � ����������� �����������.
	//Name �� string  ������������ ������
	//��� ������ ������� ���������� ����� ���������� ������ ������� �� ��������� ������.
	UnicodeString NameNom;

	 //Quantity �� double ���������� ������
	double Quantity;

	//Price �� double ���� ������� ������ ��� ����� ������/�������
	double Price;

	//Amount �� double �������� ����� �� ������� ���� (� ������ ���� ������/�������)
	double Amount;


				//PriceWithDiscount �� double ���� ������� ������ � ������ ������/�������
	double PriceWithDiscount;


	//Amount �� double �������� ����� �� ������� ���� � ������ ���� ������/�������
	double SumWithDiscount;

   //SignMethodCalculation ��� long ������� ������� �������.
//			1 ���������� ������
//			2 ���������� ���������
//			3 �����
//			4 ������ ������
//			5 ��������� ������ � ������
//			6 �������� � ������
//			7 ������ �������
	int SignMethodCalculation;



	//Department ��� long �����, �� �������� ������� �������
	int Department;

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
	int Tax;


	//TextString  ������ ��������� ������.
	//Text �� string ������ � ������������ �������
	UnicodeString TextString;

	//Barcode   ������ ���������. �������������� � �������������� �������� � ������������� �� ������ ����.
	//BarcodeType �� string ������, ������������ ��� ���������

	UnicodeString BarcodeType ;
	//��� ��������� ����� ����� ���� �� ��������� ��������: EAN8, EAN13, CODE39, QR. � ������, ���� ������ ���������� �� ������������ ������ ���������, �������� ������.

	UnicodeString Barcode;

 //Payments  ��������� �������� ����. ����� ���� ����� ����� ������ ���� ������ ����� ��������� ����.


//Cash ��� decimal ����� �������� ������ ��������� �������� ����. ����� ���� ����� ����� ������ ���� ������ ����� ��������� ����.
	double Cash;

//CashLessType1 ��� decimal ����� ����������� ������ ������� ����
	double CashLessType1;

//CashLessType2 ��� decimal ����� ����������� ������ ������� ����
	double CashLessType2;

//CashLessType3 ��� decimal ����� ����������� ������ �������� ����
	double CashLessType3 ;


 	//ElectronicPayment �� decimal ����� ������������ ����������
	double ElectronicPayment;
//AdvancePayment  �� decimal ����� ����������� (������� ������)
	double AdvancePayment;
//Credit �� decimal ����� ����������� (� ������)
	double Credit;
//CashProvision �� decimal ����� ��������� ���������������
	double CashProvision;



	UnicodeString GetParameters(void);
	bool SetParameter(UnicodeString name_parameter, UnicodeString value_parameter);


   UnicodeString GetAdditionalActions(void);
   bool DoAdditionalAction(UnicodeString name_action);


      //	������ (CashierName) STRING [IN] ��� ��������������� ���� ��� ���������� ��������
UnicodeString CashierName;
//	���������� (Electronically) BOOL (IN) ������������ ���� � ������ ���������� ����. ������ ���� �� ��������������.
bool Electronically;
//	����������������� (FiscalSign) STRING [OUT] ���������� �������
UnicodeString FiscalSign;
//	AddressSiteInspections (������������������) STRING [OUT] ����� ����� ��������
UnicodeString AddressSiteInspections;

UnicodeString GetMetodsList(void);

	bool GetParameter(UnicodeString name_parameter, TkasVariant * value_parameter);
	bool SetParameter(UnicodeString name_parameter, TkasVariant * value_parameter);






	//**********************************************************************
//**********************************************************************
//***********************************************************************************

bool RunCommand(UnicodeString command_name, UnicodeString xml_doc, int type_doc);
					//���� type = 0 �� �� ���������� xml_doc, � ���������� �������������� ��������� ����

UnicodeString ReturnXmlResultLastMethod(void);

//��������� ��� ���������� ������
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

	//������������ xml �����
void AddStringXml(UnicodeString str_xml);    //������ ������� ������
void AddAttribyteXml(UnicodeString attribyte, UnicodeString value, int type_value);  //��� ��� ��������������, �������� ��� �������� ������� � ������
void AddElementXml(UnicodeString element, UnicodeString value, int type_value);

void AddStringForPrintXml(UnicodeString element, UnicodeString attribyte, UnicodeString value,
								int size_font, int girn, int alignment, bool word_wrap);   //������ xml ��� ������ ����� �������������



};
//---------------------------------------------------------------------------
#endif
