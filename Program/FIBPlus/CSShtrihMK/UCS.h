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

        //чтение данных из ККМ  -------------------------------------------------
        unsigned char *InBuf;      //буфер прочитаный из порта
        int KolByteInBuf; //количество прочитанных байт
        int KolByteMask;   //количество байт 7D в прочитанном буфере
        unsigned char *InPaket;     //суммарный пакет с байтами маскирования
        int KolByteInPaket; //количество байт в пакете

        unsigned char * InKadr;      //приемный кадр без байтов маскирования
        int KolByteInKadr;  //количество байт в кадре


        void DelSimbolMask(void);
        bool CheckCRC16(void );

        //запись данных в ККМ   --------------------------------------------------
        unsigned char  *OutKadr; //кадр для передачи ККМ без байт маскирования
        int KolByteOutKadr;
        unsigned char *OutPaket;  //пакет для вывода в порт
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



        enum {Prod, Pokupka, VosvratProd, VosvratPokupki} TypeOperation;//тип операции
        enum {Oper,Storno} Operation ;//операция
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
