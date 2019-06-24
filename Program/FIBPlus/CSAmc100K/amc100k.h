//---------------------------------------------------------------------------

#ifndef amc100kH
#define amc100kH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class amc100k : public TThread
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
        int Posilka (void);// �������
        void ClearBuffer(char * B);// �������� �����
        char AmcCodeSimbol(String StringSimbol);// �������� ��� �������


protected:
        void __fastcall Execute();


public:
        __fastcall amc100k(bool CreateSuspended); //����������� ������

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
                SbrosChekaEvent,IzmStatusKKMEvent} EventKKM;//������� �� ���
                
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
        bool OpenPort();
        bool ClosePort();
        

       void __fastcall GenerateExternalEvent(void);
};
//---------------------------------------------------------------------------
#endif
//extern HANDLE ZaprosOtKKM;
