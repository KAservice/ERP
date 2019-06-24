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
        void OtvetNaScanPaket(void);//ответ на скан пакет
        void OtvetNaZaprosPoCodu(void); //ответ на запрос по коду без колич.
        void OtvetNaZaprosPoShtrihCodu(void);  //ответ на запрос по штрих коду .
        void OtvetNaDobavleniePokupki(void); //ответ на добавление покупки в чек
        void OtvetNaDobavlenieSvobSumm(void);//ответ на добавление свободной суммы
        void OtvetNaZakrCheka(void); //ответ на закрытие чека
        void OtvetNaSbrosCheka(void);//ответ на сброс чека
        void OtvetNaUdaleniePokupki(void);
        void ObrabUnknownEvent(void); //ответ на неизвестное событие
        void ClearBuffer(unsigned char * B);// очистить буфер
        unsigned char KasbiCodeSimbol(String StringSimbol);// получить код символа


protected:
        void __fastcall Execute();


public:
        __fastcall TKkm(bool CreateSuspended); //конструктор класса

        //*********************************************************************
        //свойства класса
        bool OprosActive; //выполнять опрос
        String ComName; // наименование порта
        bool OperError;// ошибка операции
        enum    {
                ConnectEvent,ErrorConnectEvent,
                DisconnectEvent,ErrorDisconnectEvent,PaketOtKKMEvent,
                ErrorObmenEvent,ZaprosPoCoduEvent,ZaprosPoShtrihCoduEvent,
                DobavleniePokupkiEvent,DobavlenieSvobSummEvent,ZakrChekaEvent,
                SbrosChekaEvent,UdaleniePokupkiEvent,IzmStatusKKMEvent,UnknownEvent} EventKKM;//событие от ККМ
                
        bool   ConnectkKKM;// ККМ подключена
        bool EnableOtvet; //можно ответить ККМ
        bool EstSvazKKM;//есть связь с ккм

        int intSetNumber;
        String TextError; //текстовое сообщение для формы

        //параметры товара и чека
        //шапка

        int NumberKl;//номер КЛ
        int NumberCheck; //номер чека
        enum {Prod, Vosvrat} CheckOperation;// операция чека, признак возврата

        //таблица
        int NumberPokupki;
        int Otdel;// отдел
        int TovGrp;//товарная группа
        double CodeTovar; //код товара
        String ShCodeTovar; //штрих код товара
        String NameTovar;// название товара
        double PriceTovar;//цена товара
        double KolTovar;  //количество товара
        double SummaPokupki;//сумма покупки

         //подвал
         int KolPokupok;   //количество покупок в чеке
         enum {Nal,BesNal} Oplata; //тип оплаты
         double SummaCheck;     //сумма чека без начислений
         double RealSummaCheck;  //реальная сумма чека с начислениями
         int Procent;         //процент начисления
         enum {No,Skidka,Nadbavka} Nachislenie;   //тип начисления

        //*********************************************************************
        //методы класса
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
