//---------------------------------------------------------------------------

#ifndef UCSH
#define UCSH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TCS : public TThread
{            
private:




protected:
        void __fastcall Execute();
public:
        __fastcall TCS(bool CreateSuspended);
        void OpenPort(void);
        void ClosePort(void);
        HANDLE ComHandle;
        void __fastcall UpdateForm(void);
        void __fastcall Soobshenie(void);
        void __fastcall GenerateExternalEvent(void);

        String Stroka;

        //������ ������ �� ���  -------------------------------------------------
        unsigned char *InBuf;      //����� ���������� �� �����
        int KolByteInBuf; //���������� ����������� ����
        int KolByteMask;   //���������� ���� 7D � ����������� ������
        unsigned char *InPaket;     //��������� ����� � ������� ������������
        int KolByteInPaket; //���������� ���� � ������

        unsigned char * InKadr;      //�������� ���� ��� ������ ������������
        int KolByteInKadr;  //���������� ���� � �����


        void DelSimbolMask(void);
        bool CheckCRC16(void );

        //������ ������ � ���   --------------------------------------------------
        unsigned char  *OutKadr; //���� ��� �������� ��� ��� ���� ������������
        int KolByteOutKadr;
        unsigned char *OutPaket;  //����� ��� ������ � ����
        int KolByteOutPaket;


        void AddKontrSumm(void);
        void AddSimbolMask(void);
        void WritePaket(void);




        void ObrabotatKomandu(void);

        unsigned char C1;
        unsigned char C2;
        unsigned char C3;
        unsigned char C4;



        void SvobProd(void);
        void ProdPoKodu(void);
        void SvobOplata(void);
        void SakrCheck(void);
        void AnnCheck(void);
        void Podtver(void);



        enum {Prod, Pokupka, VosvratProd, VosvratPokupki} TypeOperation;//��� ��������
        enum {Oper,Storno} Operation ;//��������
        double Kol;
        double Price;
        int Otdel;
        int NumberOperator;
        enum {Nal,Opl2,Opl3} TypeOplat;
        double SummaOplat;

        long int Code;
        TDate  DateCheck;
        TTime  TimeCheck;

        int NumberCheck;
        int NumberDoc;

        String Name;

        enum {SvobProdEvent,ProdPoCoduEvent,SvobOplataEvent,SakrCheckEvent,
                AnnCheckEvent,PodtverEvent} ExternalEvent;

        String NamePort;
};
//---------------------------------------------------------------------------
#endif
