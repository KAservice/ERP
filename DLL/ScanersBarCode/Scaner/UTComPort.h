//---------------------------------------------------------------------------

#ifndef UTComPortH
#define UTComPortH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TComPort : public TThread
{            
private:
protected:
        void __fastcall Execute();
public:
        __fastcall TComPort(bool CreateSuspended);

        void __fastcall GenerateEvent();
        bool OpenPort(int number_port, char * baud_rate);
        bool ClosePort(void);

        HANDLE ComHandle;
		char *InBuf;      //буфер прочитаный из порта
        int KolByteInBuf; //количество прочитанных байт
		char *InPaket;     //суммарный пакет с байтами маскирования
        int KolByteInPaket; //количество байт в пакете
        AnsiString TextError;


};
//---------------------------------------------------------------------------
#endif
