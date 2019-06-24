//---------------------------------------------------------------------------

#ifndef UDisplayPokH
#define UDisplayPokH
//---------------------------------------------------------------------------
#include <vcl.h>
#include "GlobalInterface.h"
class TDisplayPok
        {
private:

       HINSTANCE dllIn;

		typedef WideString (__import  DllGetTextErrorType(void));
		DllGetTextErrorType * DllGetTextError;

		typedef bool (__import  DllConnectType(int,   //порт,  1,2,3,
												int));//скорость 57600,9600 и др.
		DllConnectType * DllConnect;

		typedef void (__import  DllDisconnectType(void));
		DllDisconnectType * DllDisconnect;

		typedef bool (__import  DllShowString1Type(WideString, 	//строка,
													int,    //размер шрифта 1,2,3,4
													int,    // стиль, 0 обычный, 1 курсив, 2 жирный, 3 жирный курсив
													int    //выравнивание,  0 лево 1 центр 2 право
													));
		DllShowString1Type * DllShowString1;
		typedef bool (__import  DllShowString2Type(WideString, 	//строка,
													int,    //размер шрифта 1,2,3,4
													int,    // стиль, 0 обычный, 1 курсив, 2 жирный, 3 жирный курсив
													int    //выравнивание,  0 лево 1 центр 2 право
													));

		DllShowString2Type * DllShowString2;

		typedef bool (__import  DllShowTextType(WideString, 	//строка,
													int,    //размер шрифта 1,2,3,4
													int,    // стиль, 0 обычный, 1 курсив, 2 жирный, 3 жирный курсив
													int,    //выравнивание,  0 лево 1 центр 2 право
													bool)); //пернос по словам

		DllShowTextType * DllShowText;



 public:
		TDisplayPok();
		~TDisplayPok();

		bool Error;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации


		//IMainInterface
		int CodeError;
		UnicodeString TextError;

		int Init();
		int Done();

		//текущий интерфейс
		AnsiString Modul;

        bool InitDevice();

		bool Connect(int port,   //порт,  1,2,3,
							int baud_rate);//скорость 57600,9600 и др.
		void Disconnect(void);


		bool ShowString1(UnicodeString str, 	//строка,
							int size_font,    //размер шрифта 1,2,3,4
							int style_font,    // стиль, 0 обычный, 1 курсив, 2 жирный, 3 жирный курсив
							int alignment    //выравнивание,  0 лево 1 центр 2 право
							);

		bool ShowString2(UnicodeString str, 	//строка,
							int size_font,    //размер шрифта 1,2,3,4
							int style_font,    // стиль, 0 обычный, 1 курсив, 2 жирный, 3 жирный курсив
							int alignment    //выравнивание,  0 лево 1 центр 2 право
							);

		bool ShowText(UnicodeString str, 	//строка,
							int size_font,    //размер шрифта 1,2,3,4
							int style_font,    // стиль, 0 обычный, 1 курсив, 2 жирный, 3 жирный курсив
							int alignment,    //выравнивание,  0 лево 1 центр 2 право
							bool word_wrap); //пернос по словам
        };
//---------------------------------------------------------------------------
#endif
