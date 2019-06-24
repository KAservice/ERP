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
        void OtvetNaScanPaket(void);//ответ на скан пакет
        void OtvetNaZaprosPoCodu(void); //ответ на запрос по коду без колич.
        void OtvetNaZaprosPoCoduKol(void);  //ответ на запрос по коду с колич.
        void OtvetNaDobavleniePokupki(void); //ответ на добавление покупки в чек
        void OtvetNaDobavlenieSvobSumm(void);//ответ на добавление свободной суммы
        void OtvetNaZakrCheka(void); //ответ на закрытие чека
        void OtvetNaSbrosCheka(void);//ответ на сброс чека
        int Posilka (void);// посылка
        void ClearBuffer(char * B);// очистить буфер
        char AmcCodeSimbol(String StringSimbol);// получить код символа


protected:
        void __fastcall Execute();


public:
        __fastcall amc100k(bool CreateSuspended); //конструктор класса

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
                SbrosChekaEvent,IzmStatusKKMEvent} EventKKM;//событие от ККМ
                
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
};
//---------------------------------------------------------------------------
#endif
//extern HANDLE ZaprosOtKKM;
