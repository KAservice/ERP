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

		//настройка принтера и этикеток
		typedef char * (__import   DllSetSetupType(char*));
        DllSetSetupType * DllSetSetup;

		typedef bool (__import  DllConnectType(int,   //порт,  1,2,3,
												int));//скорость 57600,9600 и др.
		DllConnectType * DllConnect;

		typedef void (__import  DllDisconnectType(void));
		DllDisconnectType * DllDisconnect;

		typedef bool (__import  DllPrintStringType(char*, 	//строка,
													int,    //размер шрифта 1,2,3,4
													int,    // стиль, 0 обычный, 1 курсив, 2 жирный, 3 жирный курсив
													int,    //выравнивание,  0 лево 1 центр 2 право
													char * ,
													bool)); //пернос по словам
		DllPrintStringType * DllPrintString;

		typedef bool (__import  DllPrintBarCodeType(char* , //штрих-код
														int ,  //отступ слева
														int ,  //тип штрих кода
														int ,  //размер font штрих кода
														int ));//высота
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

		bool Connect(int port,   //порт,  1,2,3,
							int baud_rate);//скорость 57600,9600 и др.
		void Disconnect(void);

		//настройка принтера и этикеток
		void SetSetup(int height_label, int width_label);  //размер этикетки


		bool PrintString(char* str, 	//строка,
							int size_font,    //размер шрифта 1,2,3,4
							int style_font,    // стиль, 0 обычный, 1 курсив, 2 жирный, 3 жирный курсив
							int alignment,    //выравнивание,  0 лево 1 центр 2 право
							AnsiString name_font,
							bool word_wrap); //пернос по словам

		bool PrintBarCode(char* bar_code,
								int otstup,  //отступ слева
								int type_barcode,  //тип штрих кода
								int size_font_bar_code,  //размер штрих кода
								int height_bar_code); //высота мм.
		bool PrintLine(void);
		bool OpenDoc(void);
		bool CloseDocType(void);
		bool GetSostPrinter(void);
		bool ProvVosmPrint(void);

        };
//---------------------------------------------------------------------------
#endif
