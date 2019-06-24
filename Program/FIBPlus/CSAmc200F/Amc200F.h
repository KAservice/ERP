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
        void OtvetNaScanPaket(void);//ответ на скан пакет
        void OtvetNaZaprosPoCodu(void); //ответ на запрос по коду без колич.
        void OtvetNaZaprosPoCoduKol(void);  //ответ на запрос по коду с колич.
        void OtvetNaDobavleniePokupki(void); //ответ на добавление покупки в чек
        void OtvetNaDobavlenieSvobSumm(void);//ответ на добавление свободной суммы
        void OtvetNaZakrCheka(void); //ответ на закрытие чека
        void OtvetNaSbrosCheka(void);//ответ на сброс чека
        void ObrabUnknownEvent(void); //ответ на неизвестное событие
        int Posilka (void);// посылка
        void ClearBuffer(char * B);// очистить буфер
        char AmcCodeSimbol(String StringSimbol);// получить код символа


protected:
        void __fastcall Execute();


public:
        __fastcall amc200f(bool CreateSuspended); //конструктор класса

        //*********************************************************************
        //свойства класса
        bool OprosActive; //выполнять опрос
        String ComName; // наименование порта
        bool OperError;// ошибка операции
        enum    {
                ConnectEvent,ErrorConnectEvent,
                DisconnectEvent,ErrorDisconnectEvent,PaketOtKKMEvent,
                ErrorObmenEvent,ZaprosPoCoduEvent,ZaprosPoCoduKolEvent,
                DobavleniePokupkiEvent,DobavlenieSvobSummEvent,ZakrChekaEvent,
                SbrosChekaEvent,IzmStatusKKMEvent,UnknownEvent} EventKKM;//событие от ККМ
                
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
        bool OpenPort(void);
        bool ClosePort(void);
        

       void __fastcall GenerateExternalEvent(void);

       String DopStrL(String Str, String Symbol, int Len);

       void OutputProtokol( unsigned char * buf, int len, bool wr);
};
//---------------------------------------------------------------------------
#endif
//extern HANDLE ZaprosOtKKM;
