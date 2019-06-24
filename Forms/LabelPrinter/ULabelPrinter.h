//---------------------------------------------------------------------------

#ifndef ULabelPrinterH
#define ULabelPrinterH
//---------------------------------------------------------------------------
#include <vcl.h>

class TLabelPrinter
        {
private:

       HINSTANCE dllIn;

		typedef char * (__import  DllGetTextErrorType(void));
		DllGetTextErrorType * DllGetTextError;

		//��������� �������� � ��������
		typedef char * (__import   DllSetSetupType(char*));
        DllSetSetupType * DllSetSetup;

		typedef bool (__import  DllConnectType(int,   //����,  1,2,3,
												int));//�������� 57600,9600 � ��.
		DllConnectType * DllConnect;

		typedef void (__import  DllDisconnectType(void));
		DllDisconnectType * DllDisconnect;

		typedef bool (__import  DllPrintStringType(char*, 	//������,
													int,    //������ ������ 1,2,3,4
													int,    // �����, 0 �������, 1 ������, 2 ������, 3 ������ ������
													int,    //������������,  0 ���� 1 ����� 2 �����
													char * ,
													bool)); //������ �� ������
		DllPrintStringType * DllPrintString;

		typedef bool (__import  DllPrintBarCodeType(char* , //�����-���
														int ,  //������ �����
														int ,  //��� ����� ����
														int ,  //������ font ����� ����
														int ));//������
		DllPrintBarCodeType * DllPrintBarCode;
		
		typedef bool (__import  DllPrintLineType(void));
		DllPrintLineType * DllPrintLine;

		typedef bool (__import  DllOpenDocType(void));
		DllOpenDocType * DllOpenDoc;

		typedef bool (__import  DllCloseDocType(void));
		DllCloseDocType * DllCloseDoc;

		typedef bool (__import  DllGetSostPrinterType(void));
		DllGetSostPrinterType * DllGetSostPrinter;

		typedef bool (__import  DllProvVosmPrintType(void));
		DllProvVosmPrintType * DllProvVosmPrint;

 public:
		TLabelPrinter();
		~TLabelPrinter();

		bool Error;
		AnsiString TextError;
		AnsiString Modul;

        bool Init();

		bool Connect(int port,   //����,  1,2,3,
							int baud_rate);//�������� 57600,9600 � ��.
		void Disconnect(void);

		//��������� �������� � ��������
		void SetSetup(int height_label, int width_label);  //������ ��������


		bool PrintString(char* str, 	//������,
							int size_font,    //������ ������ 1,2,3,4
							int style_font,    // �����, 0 �������, 1 ������, 2 ������, 3 ������ ������
							int alignment,    //������������,  0 ���� 1 ����� 2 �����
							AnsiString name_font,
							bool word_wrap); //������ �� ������

		bool PrintBarCode(char* bar_code,
								int otstup,  //������ �����
								int type_barcode,  //��� ����� ����
								int size_font_bar_code,  //������ ����� ����
								int height_bar_code); //������ ��.
		bool PrintLine(void);
		bool OpenDoc(void);
		bool CloseDocType(void);
		bool GetSostPrinter(void);
		bool ProvVosmPrint(void);

        };
//---------------------------------------------------------------------------
#endif
