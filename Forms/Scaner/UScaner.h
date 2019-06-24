//---------------------------------------------------------------------------

#ifndef UScanerH
#define UScanerH
#include <vcl.h>
class TScaner
{
private:

       HINSTANCE dllIn;

		typedef WideString (__import  DllReadShtrihCodType(void));  //читает ШК из DLL
		typedef bool (__import  DllConnectType(WideString,WideString));
		typedef void (__import  DllDisconnectType(void));
		typedef WideString (__import  DllGetTextErrorType(void));


		typedef __fastcall void (__closure * TEventReadShType)( void);
		typedef void (__import  DllSetLpType(TEventReadShType));


 public:
        TScaner();
        ~TScaner();
        bool Init();
        int Number;
        AnsiString Modul;
		UnicodeString NameScaner;
		bool ConnectScaner;
		UnicodeString TextError;

        typedef __fastcall void (__closure * TReadShType)( int num, UnicodeString sh);
        TReadShType ReadSh;


        void __fastcall ReadShtrihCodEvent(void);

		DllReadShtrihCodType * DllReadShtrihCod;
		DllConnectType * DllConnect;
		DllDisconnectType * DllDisconnect;
		DllGetTextErrorType * DllGetTextError;
		DllSetLpType * DllSetLp;

		UnicodeString ReadShtrihCod(void);  //читает ШК из DLL
		bool  Connect(UnicodeString port ,UnicodeString baud_rate);
		void Disconnect(void);
		UnicodeString GetTextError(void);

};
//---------------------------------------------------------------------------
#endif
