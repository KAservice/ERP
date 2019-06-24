//---------------------------------------------------------------------------

#ifndef UKasbi02fH
#define UKasbi02fH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TKkm : public TThread
{            
private:
        HANDLE ComHandle;
        DCB *dcb;
        COMMTIMEOUTS *commmtimeouts;
        void OprositPort();
        unsigned char * A;
        char * B;


        unsigned char charSetNumber1;
        unsigned char charSetNumber2;
        unsigned char charSetNumber3;
        unsigned char charSetNumber4;

        void __fastcall WriteBuffer(unsigned char  *B, int L);
        void __fastcall ReadBuffer(unsigned char *B, int L);
        char __fastcall KontrSumm2(unsigned char *Buffer,int Kol);
        char __fastcall KontrSumm1(unsigned char *Buffer,int Kol);
        void SetupComPort(String Parity ,int RI,int RM, int RC, int WM, int WC,bool ClearBuffer);
        int ConnectKKM(void);
        int DisconnectKKM(void);
        bool PortOpen;
        void OtvetNaScanPaket(void);//����� �� ���� �����
        void OtvetNaZaprosPoCodu(void); //����� �� ������ �� ���� ��� �����.
        void OtvetNaZaprosPoShtrihCodu(void);  //����� �� ������ �� ����� ���� .
        void OtvetNaDobavleniePokupki(void); //����� �� ���������� ������� � ���
        void OtvetNaDobavlenieSvobSumm(void);//����� �� ���������� ��������� �����
        void OtvetNaZakrCheka(void); //����� �� �������� ����
        void OtvetNaSbrosCheka(void);//����� �� ����� ����
        void OtvetNaUdaleniePokupki(void);
        void ObrabUnknownEvent(void); //����� �� ����������� �������
        void ClearBuffer(unsigned char * B);// �������� �����
        unsigned char KasbiCodeSimbol(String StringSimbol);// �������� ��� �������


protected:
        void __fastcall Execute();


public:
        __fastcall TKkm(bool CreateSuspended); //����������� ������

        //*********************************************************************
        //�������� ������
        bool OprosActive; //��������� �����
        String ComName; // ������������ �����
        bool OperError;// ������ ��������
        enum    {
                ConnectEvent,ErrorConnectEvent,
                DisconnectEvent,ErrorDisconnectEvent,PaketOtKKMEvent,
                ErrorObmenEvent,ZaprosPoCoduEvent,ZaprosPoShtrihCoduEvent,
                DobavleniePokupkiEvent,DobavlenieSvobSummEvent,ZakrChekaEvent,
                SbrosChekaEvent,UdaleniePokupkiEvent,IzmStatusKKMEvent,UnknownEvent} EventKKM;//������� �� ���
                
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
        bool OpenPort();
        bool ClosePort();
        

       void __fastcall GenerateExternalEvent(void);

       String DopStrL(String Str, String Symbol, int Len);
       int KolPaketError;

       void TKkm::OutputProtokol( unsigned char * buf, int len, bool wr);

};
//---------------------------------------------------------------------------
#endif
//extern HANDLE ZaprosOtKKM;
