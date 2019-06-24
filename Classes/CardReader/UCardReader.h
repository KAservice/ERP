//---------------------------------------------------------------------------

#ifndef UCardReaderH
#define UCardReaderH
#include <vcl.h>

class TCardReader
{
private:

       HINSTANCE dllIn;

		typedef WideString (__import  DllReadTrack1Type(void));  //
		typedef WideString (__import  DllReadTrack2Type(void));  //
		typedef WideString (__import  DllReadTrack3Type(void));  //
		typedef bool (__import  DllConnectType(WideString,WideString)); //число
		typedef void (__import  DllDisconnectType(void));
		typedef WideString (__import  DllGetTextErrorType(void));


		typedef __fastcall void (__closure * TEventReadTrackType)( void);
		typedef void (__import  DllSetLpType(TEventReadTrackType));


 public:
		TCardReader();
		~TCardReader();
		bool Init();
		AnsiString Modul;
		UnicodeString TextError;

		DllReadTrack1Type * DllReadTrack1;
		DllReadTrack2Type * DllReadTrack2;
		DllReadTrack3Type * DllReadTrack3;

		DllConnectType * DllConnect;
		DllDisconnectType * DllDisconnect;
		DllGetTextErrorType * DllGetTextError;
		DllSetLpType * DllSetLp;



        ///вызывается из библиотеки когда она считала карту
        void __fastcall ReadTrackEvent(void);





		bool  Connect(UnicodeString port ,UnicodeString baud_rate);
		void Disconnect(void);
		UnicodeString GetTextError(void);

		//внешнее событие для внешних форм, генерируем когда считан код
		TEventReadTrackType ReadTrackExternalEvent;
        UnicodeString Track1, Track2, Track3;
};
#endif
