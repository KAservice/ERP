//---------------------------------------------------------------------------

#ifndef UScanerH
#define UScanerH
#include <vcl.h>
#include "IAsyncExternalEvent.h"
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



        typedef __fastcall void (__closure * TReadShType)( int num, UnicodeString sh);
        TReadShType ReadSh;


        void __fastcall ReadShtrihCodEvent(void);

		DllReadShtrihCodType * DllReadShtrihCod;
		DllConnectType * DllConnect;
		DllDisconnectType * DllDisconnect;
		DllGetTextErrorType * DllGetTextError;
		DllSetLpType * DllSetLp;
 public:
        TScaner();
		~TScaner();

		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

		IAsyncExternalEvent * InterfaceAsyncMainObject;

		UnicodeString TextError;
		int CodeError;

		int Init();
		int Done();



        bool InitDevice();
        int Number;
        AnsiString Modul;
		UnicodeString NameScaner;
		bool ConnectScaner;




		UnicodeString ReadShtrihCod(void);  //читает ШК из DLL
		bool  Connect(UnicodeString port ,UnicodeString baud_rate);
		void Disconnect(void);
		UnicodeString GetTextError(void);

};
//---------------------------------------------------------------------------
#endif
