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
		char *InBuf;      //����� ���������� �� �����
        int KolByteInBuf; //���������� ����������� ����
		char *InPaket;     //��������� ����� � ������� ������������
        int KolByteInPaket; //���������� ���� � ������
        AnsiString TextError;


};
//---------------------------------------------------------------------------
#endif
