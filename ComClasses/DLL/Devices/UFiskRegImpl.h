#ifndef UFiskRegImplH
#define UFiskRegImplH
#include "IFiskReg.h"
#include "IAsyncExternalEvent.h"
#include "UFiskReg.h"
//---------------------------------------------------------------
class __declspec(uuid("{09B0B000-1347-406E-A285-5E428A665D97}")) TFiskRegImpl : public IFiskReg
{
public:
   TFiskRegImpl();
   ~TFiskRegImpl();
   TFiskReg * Object;
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


      //����� ������� ��� ������ � ��-���� �������
   virtual bool OpenShift(void);
   virtual bool CloseShift(void);
   virtual bool InitDocument(int type_doc);
   virtual bool CreateHeaderFiscalCheck(void);
   virtual bool CreateFooterFiscalCheck(void);
   virtual bool AddFiscalString(void);



//��������� ����  //��������� 	Parameters
// ����������� long ��� �������
//1 - ������
//2 - ������� �������
//3 - ������
//4 - ������� ������� ������������ ������ ���� � �������� ����������.

   virtual int get_PaymentType(void);
   virtual void set_PaymentType(int PaymentType);


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

   virtual int get_TaxVariant(void);
   virtual void set_TaxVariant(int TaxVariant);

//CustomerEmail ������������� string Email ����������
   virtual UnicodeString get_CustomerEmail(void);
   virtual void set_CustomerEmail(UnicodeString CustomerEmail);

//CustomerPhone ������������� string ���������� ����� ����������
   virtual UnicodeString get_CustomerPhone(void);
   virtual void set_CustomerPhone(UnicodeString CustomerPhone  );

//AgentCompensation ������������� double ������ �������������� ������
	virtual double get_AgentCompensation(void);
	virtual void set_AgentCompensation(double AgentCompensation);

//AgentPhone ������������� string ���������� ������� ������
	virtual UnicodeString get_AgentPhone(void);
	virtual void set_AgentPhone(UnicodeString AgentPhone  );

//SubagentPhone ������������� string ������� ���������� ���������
	virtual UnicodeString get_SubagentPhone(void);
	virtual void set_SubagentPhone(UnicodeString SubagentPhone  );

//ReceivePaymentsOperatorPhone  ������������� string ������� ��������� �� ������ ��������
	virtual UnicodeString get_ReceivePaymentsOperatorPhone(void);
	virtual void set_ReceivePaymentsOperatorPhone(UnicodeString ReceivePaymentsOperatorPhone  );

//MoneyTransferOperatorPhone  ������������� string ������� ��������� �� �������� �������� �������
	virtual UnicodeString get_MoneyTransferOperatorPhone(void);
	virtual void set_MoneyTransferOperatorPhone(UnicodeString MoneyTransferOperatorPhone  );

//BankAgentPhone  ������������� string ������� ����������� ������
	virtual UnicodeString get_BankAgentPhone(void);
	virtual void set_BankAgentPhone(UnicodeString BankAgentPhone  );

//BankSubagentPhone  ������������� string ������� ����������� ���������
	virtual UnicodeString get_BankSubagentPhone(void);
	virtual void set_BankSubagentPhone(UnicodeString BankSubagentPhone );

//BankAgentOperation ������������� string �������� ����������� ������
	virtual UnicodeString get_BankAgentOperation(void);
	virtual void set_BankAgentOperation(UnicodeString BankAgentOperation);


//BankSubagentOperation ������������� string �������� ����������� ���������
	virtual UnicodeString get_BankSubagentOperation(void);
	virtual void set_BankSubagentOperation(UnicodeString BankSubagentOperation);

//BankAgentCompensation  ������������� double ������ �������������� ����������� ������ (���������)
	virtual double get_BankAgentCompensation(void);
	virtual void set_BankAgentCompensation(double BankAgentCompensation);


//MoneyTransferOperatorName ������������� string ������������ ��������� �� �������� �������� �������
	virtual UnicodeString get_MoneyTransferOperatorName(void);
	virtual void set_MoneyTransferOperatorName(UnicodeString MoneyTransferOperatorName);


//MoneyTransferOperatorAddress  ������������� string ����� ��������� �� �������� �������� �������
	virtual UnicodeString get_MoneyTransferOperatorAddress(void);
	virtual void set_MoneyTransferOperatorAddress(UnicodeString MoneyTransferOperatorAddress);

//MoneyTransferOperatorVATIN  ������������� string ��� ��������� �� �������� ��������
	virtual UnicodeString get_MoneyTransferOperatorVATIN(void);
	virtual void set_MoneyTransferOperatorVATIN(UnicodeString MoneyTransferOperatorVATIN);

 //������������ ������� ����
 //������� ����, ��� ������       1-���� ������ 2- ��������� ������ 3-����� ���
	 virtual int get_TypeFiscalString(void);
	 virtual void set_TypeFiscalString(int TypeFiscalString);

	//FiscalString  ������������ ���������� ������ � ����������� �����������.
	//Name �� string  ������������ ������
	//��� ������ ������� ���������� ����� ���������� ������ ������� �� ��������� ������.
	 virtual UnicodeString get_NameNom(void);
	 virtual void set_NameNom(UnicodeString NameNom);

	 //Quantity �� double ���������� ������
	 virtual double get_Quantity(void);
	 virtual void set_Quantity(double Quantity);

	//Price �� double ���� ������� ������ ��� ����� ������/�������
	virtual double get_Price(void);
	virtual void set_Price(double Price);

	//Amount �� double �������� ����� �� ������� ���� (� ������ ���� ������/�������)
	virtual double get_Amount(void);
	virtual void set_Amount(double Amount);

	//Department ��� long �����, �� �������� ������� �������
	virtual int get_Department(void);
	virtual void set_Department(int Department);

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
	virtual int get_Tax(void);
	virtual void set_Tax(int Tax);


	//TextString  ������ ��������� ������.
	//Text �� string ������ � ������������ �������
	virtual UnicodeString get_TextString(void);
	virtual void set_TextString(UnicodeString TextString);

	//Barcode   ������ ���������. �������������� � �������������� �������� � ������������� �� ������ ����.
	//BarcodeType �� string ������, ������������ ��� ���������

	virtual UnicodeString get_BarcodeType(void);
	virtual void set_BarcodeType(UnicodeString BarcodeType);
	//��� ��������� ����� ����� ���� �� ��������� ��������: EAN8, EAN13, CODE39, QR. � ������, ���� ������ ���������� �� ������������ ������ ���������, �������� ������.

	virtual UnicodeString get_Barcode(void);
	virtual void set_Barcode(UnicodeString Barcode);

 //Payments  ��������� �������� ����. ����� ���� ����� ����� ������ ���� ������ ����� ��������� ����.


//Cash ��� decimal ����� �������� ������ ��������� �������� ����. ����� ���� ����� ����� ������ ���� ������ ����� ��������� ����.
	virtual double get_Cash(void);
	virtual void set_Cash(double Cash);

//CashLessType1 ��� decimal ����� ����������� ������ ������� ����
	 virtual double get_CashLessType1(void);
	 virtual void set_CashLessType1(double CashLessType1);

//CashLessType2 ��� decimal ����� ����������� ������ ������� ����
	virtual double get_CashLessType2(void);
	virtual void set_CashLessType2(double CashLessType2);

//CashLessType3 ��� decimal ����� ����������� ������ �������� ����
	virtual double get_CashLessType3(void);
	virtual void set_CashLessType3(double CashLessType3);

	virtual UnicodeString GetParameters(void);
	virtual bool SetParameter(UnicodeString name_parameter, UnicodeString value_parameter);


   virtual UnicodeString GetAdditionalActions(void);
   virtual bool DoAdditionalAction(UnicodeString name_action);


      //	������ (CashierName) STRING [IN] ��� ��������������� ���� ��� ���������� ��������
virtual UnicodeString get_CashierName(void);
virtual void set_CashierName(UnicodeString CashierName);
//	���������� (Electronically) BOOL (IN) ������������ ���� � ������ ���������� ����. ������ ���� �� ��������������.
virtual bool get_Electronically(void);
virtual void set_Electronically(bool Electronically);
//	����������������� (FiscalSign) STRING [OUT] ���������� �������
virtual UnicodeString get_FiscalSign(void);
virtual void set_FiscalSign(UnicodeString FiscalSign);
//	AddressSiteInspections (������������������) STRING [OUT] ����� ����� ��������
virtual UnicodeString get_AddressSiteInspections(void);
virtual void set_AddressSiteInspections(UnicodeString AddressSiteInspections);


virtual UnicodeString GetMetodsList(void);

	virtual bool GetParameter(UnicodeString name_parameter, TkasVariant * value_parameter);
	virtual bool SetParameter(UnicodeString name_parameter, TkasVariant * value_parameter);

};
#define CLSID_TFiskRegImpl __uuidof(TFiskRegImpl)
#endif
