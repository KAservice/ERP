//---------------------------------------------------------------------------

#ifndef Amc200FH
#define Amc200FH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class amc200f : public TThread
{            
private:
        HANDLE ComHandle;
        DCB *dcb;
        COMMTIMEOUTS *commmtimeouts;
        void OprositPort();
         char * A;
         char * B;

        char charSetNumber;
        void __fastcall WriteBuffer(char  *B, int L);
        void __fastcall ReadBuffer(char *B, int L);
        char __fastcall KontrSumm2(char *Buffer,int Kol);
        char __fastcall KontrSumm1(char *Buffer,int Kol);
        void SetupComPort(String Parity ,int RI,int RM, int RC, int WM, int WC,bool ClearBuffer);
        int ConnectKKM(void);
        int DisconnectKKM(void);
        bool PortOpen;
        void OtvetNaScanPaket(void);//����� �� ���� �����
        void OtvetNaZaprosPoCodu(void); //����� �� ������ �� ���� ��� �����.
        void OtvetNaZaprosPoCoduKol(void);  //����� �� ������ �� ���� � �����.
        void OtvetNaDobavleniePokupki(void); //����� �� ���������� ������� � ���
        void OtvetNaDobavlenieSvobSumm(void);//����� �� ���������� ��������� �����
        void OtvetNaZakrCheka(void); //����� �� �������� ����
        void OtvetNaSbrosCheka(void);//����� �� ����� ����
        void ObrabUnknownEvent(void); //����� �� ����������� �������
        int Posilka (void);// �������
        void ClearBuffer(char * B);// �������� �����
        char AmcCodeSimbol(String StringSimbol);// �������� ��� �������


protected:
        void __fastcall Execute();


public:
        __fastcall amc200f(bool CreateSuspended); //����������� ������

        //*********************************************************************
        //�������� ������
        bool OprosActive; //��������� �����
        String ComName; // ������������ �����
        bool OperError;// ������ ��������
        enum    {
                ConnectEvent,ErrorConnectEvent,
                DisconnectEvent,ErrorDisconnectEvent,PaketOtKKMEvent,
                ErrorObmenEvent,ZaprosPoCoduEvent,ZaprosPoCoduKolEvent,
                DobavleniePokupkiEvent,DobavlenieSvobSummEvent,ZakrChekaEvent,
                SbrosChekaEvent,IzmStatusKKMEvent,UnknownEvent} EventKKM;//������� �� ���
                
        bool   ConnectkKKM;// ��� ����������
        bool EnableOtvet; //����� �������� ���
        bool EstSvazKKM;//���� ����� � ���

        int intSetNumber;
        String TextError; //��������� ��������� ��� �����

        //��������� ������ � ����
        //�����

        int NumberKl;//����� ��
        int NumberCheck; //����� ����
        enum {Prod, Vosvrat} CheckOperation;// �������� ����, ������� ��������

        //�������
        int NumberPokupki;
        int Otdel;// �����
        int TovGrp;//�������� ������
        double CodeTovar; //��� ������
        String ShCodeTovar; //����� ��� ������
        String NameTovar;// �������� ������
        double PriceTovar;//���� ������
        double KolTovar;  //���������� ������
        double SummaPokupki;//����� �������

         //������
         int KolPokupok;   //���������� ������� � ����
         enum {Nal,BesNal} Oplata; //��� ������
         double SummaCheck;     //����� ���� ��� ����������
         double RealSummaCheck;  //�������� ����� ���� � ������������
         int Procent;         //������� ����������
         enum {No,Skidka,Nadbavka} Nachislenie;   //��� ����������

        //*********************************************************************
        //������ ������
        bool OpenPort(void);
        bool ClosePort(void);
        

       void __fastcall GenerateExternalEvent(void);

       String DopStrL(String Str, String Symbol, int Len);

       void OutputProtokol( unsigned char * buf, int len, bool wr);
};
//---------------------------------------------------------------------------
#endif
//extern HANDLE ZaprosOtKKM;
