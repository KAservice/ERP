//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "amc100k.h"
#include "GlavForm.h"
//#include "CashServer.h"
#pragma package(smart_init)

//---------------------------------------------------------------------------

__fastcall amc100k::amc100k(bool CreateSuspended)
        : TThread(CreateSuspended)
{
OpenPort();
OperError=false;
B=new char[30];
A=new char[30];

//выделим память для DCB
dcb=(DCB*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,sizeof(DCB));
dcb->DCBlength=sizeof(DCB);
commmtimeouts=new COMMTIMEOUTS;
PortOpen=false; //порт не открыт
ConnectkKKM=false;// ККМ не подключена

}
//----------------------------------------------------------------------------
//откроем порт
bool  amc100k::OpenPort()
{
bool res=true;
ComHandle=CreateFile(ComName.c_str(),GENERIC_READ|GENERIC_WRITE,0,NULL,
                                OPEN_EXISTING,FILE_FLAG_OVERLAPPED,NULL);

if (ComHandle==INVALID_HANDLE_VALUE)
        {
        OperError=true;
        res=false;
        PortOpen=false;
        }
else
        {
        OperError=false;
        res=true;
        PortOpen=true;
        }

return res;



}

//----------------------------------------------------------------------------
//закроем  порт
bool amc100k::ClosePort()
{
bool res=true;
if (CloseHandle(ComHandle)==true)
        {
         OperError=false;
         res=true;
         PortOpen=false;
        }
else
        {
         OperError=true;
         res=false;
        }
return res;

}
//---------------------------------------------------------------------------
//расчет контрольной суммы
char __fastcall amc100k::KontrSumm1(char *Buffer,int Kol)
{
int ks=0;

for (int i=0;i<Kol;i++)
        {
        ks=ks+Buffer[i];

        }
ks=0xff-ks;
return  ks;

}

//расчет контрольной суммы
char __fastcall amc100k::KontrSumm2(char *Buffer,int Kol)
{
int ks=0;

for (int i=0;i<Kol;i++)
        {
        ks=ks+Buffer[i];

        }

return  ks;

}
//-----------------------------------------------------------------------------
// получить код символа
char amc100k::AmcCodeSimbol(String StringSimbol)
{

char Res=32;

if (StringSimbol=='0'){return Res=48;}
if (StringSimbol=='1'){return Res=49;}
if (StringSimbol=='2'){return Res=50;}
if (StringSimbol=='3'){return Res=51;}
if (StringSimbol=='4'){return Res=52;}
if (StringSimbol=='5'){return Res=53;}
if (StringSimbol=='6'){return Res=54;}
if (StringSimbol=='7'){return Res=55;}
if (StringSimbol=='8'){return Res=56;}
if (StringSimbol=='9'){return Res=57;}

if (StringSimbol==' '){return Res=32;}
if (StringSimbol=='!'){return Res=33;}
if (StringSimbol=='"'){return Res=34;}
if (StringSimbol=='#'){return Res=35;}
if (StringSimbol=='$'){return Res=36;}
if (StringSimbol=='%'){return Res=37;}
if (StringSimbol=='&'){return Res=38;}
//if (StringSimbol=='''){Res=39;}
//if (StringSimbol=='('){Res=40;}
//if (StringSimbol==')'){Res=41;}
if (StringSimbol=='*'){return Res=42;}
if (StringSimbol=='+'){return Res=43;}
if (StringSimbol==','){return Res=44;}
if (StringSimbol=='-'){return Res=45;}
if (StringSimbol=='.'){return Res=46;}
if (StringSimbol=='/'){return Res=47;}

if (StringSimbol=='{'){return Res=123;}
if (StringSimbol=='|'){return Res=124;}
if (StringSimbol=='}'){return Res=125;}
if (StringSimbol=='~'){return Res=126;}
if (StringSimbol=='*'){return Res=127;}

if (StringSimbol=='А'){return Res=192;}
if (StringSimbol=='Б'){return Res=193;}
if (StringSimbol=='В'){return Res=194;}
if (StringSimbol=='Г'){return Res=195;}
if (StringSimbol=='Д'){return Res=196;}
if (StringSimbol=='Е'){return Res=197;}
if (StringSimbol=='Ж'){return Res=198;}
if (StringSimbol=='З'){return Res=199;}
if (StringSimbol=='И'){return Res=200;}
if (StringSimbol=='Й'){return Res=201;}
if (StringSimbol=='К'){return Res=202;}
if (StringSimbol=='Л'){return Res=203;}
if (StringSimbol=='М'){return Res=204;}
if (StringSimbol=='Н'){return Res=205;}
if (StringSimbol=='О'){return Res=206;}
if (StringSimbol=='П'){return Res=207;}
if (StringSimbol=='Р'){return Res=208;}
if (StringSimbol=='С'){return Res=209;}
if (StringSimbol=='Т'){return Res=210;}
if (StringSimbol=='У'){return Res=211;}
if (StringSimbol=='Ф'){return Res=212;}
if (StringSimbol=='Х'){return Res=213;}
if (StringSimbol=='Ц'){return Res=214;}
if (StringSimbol=='Ч'){return Res=215;}
if (StringSimbol=='Ш'){return Res=216;}
if (StringSimbol=='Щ'){return Res=217;}
if (StringSimbol=='Ъ'){return Res=218;}
if (StringSimbol=='Ы'){return Res=219;}
if (StringSimbol=='Ь'){return Res=220;}
if (StringSimbol=='Э'){return Res=221;}
if (StringSimbol=='Ю'){return Res=222;}
if (StringSimbol=='Я'){return Res=223;}

if (StringSimbol=='а'){return Res=224;}
if (StringSimbol=='б'){return Res=225;}
if (StringSimbol=='в'){return Res=226;}
if (StringSimbol=='г'){return Res=227;}
if (StringSimbol=='д'){return Res=228;}
if (StringSimbol=='е'){return Res=229;}
if (StringSimbol=='ж'){return Res=230;}
if (StringSimbol=='з'){return Res=231;}
if (StringSimbol=='и'){return Res=232;}
if (StringSimbol=='й'){return Res=233;}
if (StringSimbol=='к'){return Res=234;}
if (StringSimbol=='л'){return Res=235;}
if (StringSimbol=='м'){return Res=236;}
if (StringSimbol=='н'){return Res=237;}
if (StringSimbol=='о'){return Res=238;}
if (StringSimbol=='п'){return Res=239;}
if (StringSimbol=='р'){return Res=240;}
if (StringSimbol=='с'){return Res=241;}
if (StringSimbol=='т'){return Res=242;}
if (StringSimbol=='у'){return Res=243;}
if (StringSimbol=='ф'){return Res=244;}
if (StringSimbol=='х'){return Res=245;}
if (StringSimbol=='ц'){return Res=246;}
if (StringSimbol=='ч'){return Res=247;}
if (StringSimbol=='ш'){return Res=248;}
if (StringSimbol=='щ'){return Res=249;}
if (StringSimbol=='ъ'){return Res=250;}
if (StringSimbol=='ы'){return Res=251;}
if (StringSimbol=='ь'){return Res=252;}
if (StringSimbol=='э'){return Res=253;}
if (StringSimbol=='ю'){return Res=254;}
if (StringSimbol=='я'){return Res=255;}




if (StringSimbol=='A'){return Res=65;}
if (StringSimbol=='B'){return Res=66;}
if (StringSimbol=='C'){return Res=67;}
if (StringSimbol=='D'){return Res=68;}
if (StringSimbol=='E'){return Res=69;}
if (StringSimbol=='F'){return Res=70;}
if (StringSimbol=='G'){return Res=71;}
if (StringSimbol=='H'){return Res=72;}
if (StringSimbol=='I'){return Res=73;}
if (StringSimbol=='J'){return Res=74;}
if (StringSimbol=='K'){return Res=75;}
if (StringSimbol=='L'){return Res=76;}
if (StringSimbol=='M'){return Res=77;}
if (StringSimbol=='N'){return Res=78;}
if (StringSimbol=='O'){return Res=79;}
if (StringSimbol=='P'){return Res=80;}
if (StringSimbol=='Q'){return Res=81;}
if (StringSimbol=='R'){return Res=82;}
if (StringSimbol=='S'){return Res=83;}
if (StringSimbol=='T'){return Res=84;}
if (StringSimbol=='U'){return Res=85;}
if (StringSimbol=='V'){return Res=86;}
if (StringSimbol=='W'){return Res=87;}
if (StringSimbol=='X'){return Res=88;}
if (StringSimbol=='Y'){return Res=89;}
if (StringSimbol=='Z'){return Res=90;}

if (StringSimbol=='a'){return Res=97;}
if (StringSimbol=='b'){return Res=98;}
if (StringSimbol=='c'){return Res=99;}
if (StringSimbol=='d'){return Res=100;}
if (StringSimbol=='e'){return Res=101;}
if (StringSimbol=='f'){return Res=102;}

if (StringSimbol=='g'){return Res=103;}
if (StringSimbol=='h'){return Res=104;}
if (StringSimbol=='i'){return Res=105;}
if (StringSimbol=='j'){return Res=106;}
if (StringSimbol=='k'){return Res=107;}
if (StringSimbol=='l'){return Res=108;}
if (StringSimbol=='m'){return Res=109;}
if (StringSimbol=='n'){return Res=110;}
if (StringSimbol=='o'){return Res=111;}
if (StringSimbol=='p'){return Res=112;}
if (StringSimbol=='q'){return Res=113;}
if (StringSimbol=='r'){return Res=114;}
if (StringSimbol=='s'){return Res=115;}
if (StringSimbol=='t'){return Res=116;}
if (StringSimbol=='u'){return Res=117;}
if (StringSimbol=='v'){return Res=118;}
if (StringSimbol=='w'){return Res=119;}
if (StringSimbol=='x'){return Res=120;}
if (StringSimbol=='y'){return Res=121;}
if (StringSimbol=='z'){return Res=122;}

return Res;


}

//-----------------------------------------------------------------------------
//настороим порт для ввода/вывода
void amc100k::SetupComPort(String Parity ,int RI,int RM, int RC, int WM, int WC, bool ClearBuffer)
{

String Str="baud=9600 data=8 stop=1 parity="+Parity;

BuildCommDCB( Str.c_str(),dcb);
dcb->XoffLim=1;
dcb->XonLim=1;
dcb->fRtsControl=RTS_CONTROL_HANDSHAKE;
dcb->fTXContinueOnXoff=true;
commmtimeouts->ReadIntervalTimeout=RI;
commmtimeouts->ReadTotalTimeoutMultiplier=RM;
commmtimeouts->ReadTotalTimeoutConstant=RC;
commmtimeouts->WriteTotalTimeoutMultiplier=WM;
commmtimeouts->WriteTotalTimeoutConstant=WC;

SetCommTimeouts(ComHandle,commmtimeouts);
SetCommState(ComHandle,dcb);

if (ClearBuffer==true)
        {
        PurgeComm(ComHandle,PURGE_TXCLEAR|PURGE_RXCLEAR);
        }
}
//---------------------------------------------------------------------------
//очистить буфер
void amc100k::ClearBuffer(char * B)
{
for (int i=0;i<30;i++)
        {
        B[i]=0;

        }


}

//---------------------------------------------------------------------------
//закрыть порт//переданы данные
//******************************************************************************
void __stdcall ENDWrite(unsigned long ErrorCode,unsigned long BytesTransfered,OVERLAPPED *stOVR)
{

//ShowMessage("Вызвана процедура завершения записи!");

}


//записать буфер в порт
//******************************************************************************

void __fastcall amc100k::WriteBuffer(char  *B, int L)

{


DWORD RealWrite;
String StrB="";
OVERLAPPED stOVR;
memset(&stOVR,0,sizeof(stOVR));

if (WriteFileEx(ComHandle,B,L,&stOVR,ENDWrite)==true)
        {


        }
else
        {
        
        }
SleepEx( INFINITE, true);

}


//приняты данные
//******************************************************************************
void __stdcall ENDRead(unsigned long ErrorCode,unsigned long BytesTransfered,OVERLAPPED *stOVR)
{

//ShowMessage("Вызвана процедура завершения чтения!");
//Form1->LabelMessage->Caption="Принято  "+IntToStr(BytesTransfered)+" байт!";

}

//******************************************************************************
//прочитать данные из порта
void __fastcall amc100k::ReadBuffer(char *B, int L)
{


OVERLAPPED stOVR;
memset(&stOVR,0,sizeof(stOVR));

ReadFileEx(ComHandle,B,L,&stOVR,ENDRead) ;
SleepEx( INFINITE, true);

}
//-----------------------------------------------------------------------------
//подключить ККМ
int amc100k::ConnectKKM(void)
{
int Res=1;
A[0]=charSetNumber;
SetupComPort("M",10,20,10,1,100,true);
WriteBuffer(A,1);
ReadBuffer(B,1);
if (B[0]!=charSetNumber)     //error
        {
         Res=0;
         return Res;
        }

SetupComPort("S",10,20,10,1,100,true);
A[0]=0x04;
A[1]=0x14;
A[2]=0xfc;
A[3]=0xff;
A[4]=0x01;
A[5]=0xeb;
WriteBuffer(A,6);
ReadBuffer(B,1);
ReadBuffer(B,3);

if (Posilka()==0)     //error
        {
         Res=0;
        }


SetupComPort("S",10,20,10,1,100,true);
A[0]=0x04;
A[1]=0x14;
A[2]=0xfd;
A[3]=0xff;
A[4]=0x01;
A[5]=0xea;
WriteBuffer(A,6);
ReadBuffer(B,1);
ReadBuffer(B,3);

if (Posilka()==0)     //error
        {
         Res=0;
        }


SetupComPort("S",10,20,10,1,100,true);
A[0]=0x02;
A[1]=0x0a;
A[2]=0x00;
A[3]=0xf3;
WriteBuffer(A,4);
ReadBuffer(B,1);

if (Posilka()==0)     //error
        {
         Res=0;
        }


SetupComPort("S",10,20,10,1,100,true);
A[0]=0x02;
A[1]=0x12;
A[2]=0x01;
A[3]=0xea;
WriteBuffer(A,4);
ReadBuffer(B,1);

if (Posilka()==0)     //error
        {
         Res=0;
        }


SetupComPort("S",10,20,10,1,100,true);
A[0]=0x01;
A[1]=0x0e;
A[2]=0xf0;
WriteBuffer(A,3);
ReadBuffer(B,1);
ReadBuffer(B,5);

if (Posilka()==0)     //error
        {
         Res=0;
        }


SetupComPort("S",10,20,10,1,100,true);
A[0]=0x04;
A[1]=0x14;
A[2]=0xfc;
A[3]=0xff;
A[4]=0x01;
A[5]=0xeb;
WriteBuffer(A,6);
ReadBuffer(B,1);
ReadBuffer(B,3);

if (Posilka()==0)     //error
        {
         Res=0;
        }


SetupComPort("S",10,20,10,1,100,true);
A[0]=0x04;
A[1]=0x14;
A[2]=0xfd;
A[3]=0xff;
A[4]=0x01;
A[5]=0xea;
WriteBuffer(A,6);
ReadBuffer(B,1);
ReadBuffer(B,3);

if (Posilka()==0)     //error
        {
         Res=0;
        }

SetupComPort("S",10,20,10,1,100,true);
A[0]=0x04;
A[1]=0x06;
A[2]=0x24;
A[3]=0x58;
A[4]=0x01;
A[5]=0x78;
WriteBuffer(A,6);
ReadBuffer(B,1);
ReadBuffer(B,3);

return Res;


}

//-----------------------------------------------------------------------------
//отключить ККМ
int amc100k::DisconnectKKM(void)
{
int Res=1;
if (Posilka()==0)     //error
        {
         Res=0;
        }

SetupComPort("S",10,20,10,1,100,true);
A[0]=0x02;
A[1]=0x12;
A[2]=0x00;
A[3]=0xeb;
WriteBuffer(A,4);
ReadBuffer(B,1);
ConnectkKKM=false;
return Res;
}
//---------------------------------------------------------------------------
void __fastcall amc100k::Execute()
{

while (!Terminated)
        {
        Sleep(1000);
        if (Terminated){continue;}
        try {
                if (PortOpen==false)
                        {
                        if (OpenPort()==false)
                                {
                                ConnectkKKM=false;
                                EventKKM=ErrorObmenEvent;
                                TextError="Не удалось открыть порт!";
                                Synchronize(GenerateExternalEvent);
                                }
                        }
                //получим сетевой номер ККМ
                charSetNumber=*((char *)&intSetNumber);

                if (ConnectKKM()==1 && PortOpen==true)    //подключим ККМ
                        {

                                ConnectkKKM=true;
                                EventKKM=ConnectEvent;
                                Synchronize(GenerateExternalEvent);
                                }
                else    {  //ошибка подключения
                        if (EventKKM!=ErrorConnectEvent)  //
                                {
                                ConnectkKKM=false;
                                EventKKM=ErrorConnectEvent;
                                Synchronize(GenerateExternalEvent);
                                }
                        }

                while ((ConnectkKKM==true)&&(!Terminated) )
                        {
                        OprositPort();
                        Sleep(100);
                         }

                if (ConnectkKKM==true)      //если ккм подключена то отключим
                        {
                        DisconnectKKM();
                        EventKKM=DisconnectEvent;
                        Synchronize(GenerateExternalEvent);
                        }

                if (PortOpen==true)    //если порт открыт то закроем
                        {
                        if (ClosePort()==false)
                                {
                                EventKKM=ErrorObmenEvent;
                                TextError="Не удалось закрыть порт!";
                                Synchronize(GenerateExternalEvent);
                                }
                        }
                }
        catch (...)
                {
                if (ConnectkKKM==true)      //если ккм подключена то отключим
                        {
                        DisconnectKKM();
                        EventKKM=DisconnectEvent;
                        Synchronize(GenerateExternalEvent);
                        }

                if (PortOpen==true)    //если порт открыт то закроем
                        {
                        if (ClosePort()==false)
                                {
                                EventKKM=ErrorObmenEvent;
                                TextError="Не удалось закрыть порт!";
                                Synchronize(GenerateExternalEvent);
                                }
                        }

                }
        }
}
//-----------------------------------------------------------------------------
// посылка для проверки связи с ККМ
int amc100k::Posilka(void)
{
int Res=1;
int i=50;
int j=3;
B[0]=0;
A[0]=charSetNumber;

M1:
                SetupComPort("M",100,200,100,100,100,true);
                WriteBuffer(A,1);
                ReadBuffer(B,1);
//подготовим событие об изменении статуса ККМ
if (B[0]==0)
        {   //нет связи с ккм
        if (EstSvazKKM==true)
                {

                EstSvazKKM=false;
                EventKKM=IzmStatusKKMEvent;
                TextError="ККМ не отвечает!Принято "+IntToHex(B[0],2) ;
                Synchronize(GenerateExternalEvent);


                }

        if (j>=0)
                {
                j=j-1;
                Sleep(100);
                goto M1;

                }
        else
                {
                Res=0;
                ConnectkKKM=false;
                return Res;
                }

        }

else
        {
        //проверим полученный символ
        if (B[0]!=A[0])
                {
                if (i>=0)
                        {
                        i=i-1;
                        Sleep(100);
                        goto M1;

                        }
                else
                        {
                        Res=0;
                        ConnectkKKM=false;
                        }
                }


        if (EstSvazKKM==false)
                {
                EstSvazKKM=true;
                EventKKM=IzmStatusKKMEvent;
                TextError="Установлена связь с ККМ!Принято "+IntToHex(B[0],2);
                Synchronize(GenerateExternalEvent);
                }
        }

return Res;

}

//-----------------------------------------------------------------------------
//опросить порт ККМ
void  amc100k::OprositPort()
{
if (Posilka()==0)     //error
        {

        }

A[0]=0x01;
A[1]=0x0e;
A[2]=0xf0;
SetupComPort("S" ,100,200,200,100,100,true);
WriteBuffer(A,3);
ClearBuffer(B);
ReadBuffer(B,1);
ClearBuffer(B);
ReadBuffer(B,2);

if ((B[0]==0x03) && (B[1]==0x00))    //скан пакет
        {
        OtvetNaScanPaket();
        }

if ((B[0]==0x10) && (B[1]==0x02))     //запрос по коду без колич.
        {
        OtvetNaZaprosPoCodu();
        }

if ((B[0]==0x15) && (B[1]==0x02))     //запрос по коду c колич.
        {
        OtvetNaZaprosPoCoduKol();
        }


if ((B[0]==0x0a) && (B[1]==0x07))   //добавлеие покупки в чек
        {
        OtvetNaDobavleniePokupki();
        }

if ((B[0]==0x0a) && (B[1]==0x06))   //добавлеие свободной суммы в чек
        {
        OtvetNaDobavlenieSvobSumm();
        }


if ((B[0]==0x13) && (B[1]==0x01))    //закрытие чека
        {
        OtvetNaZakrCheka();
        }

if ((B[0]==0x13) && (B[1]==0x05))    //сброс чека
        {
        OtvetNaSbrosCheka();
        }

}
//-----------------------------------------------------------------------------
//ответ на скан пакет
void  amc100k::OtvetNaScanPaket(void)
{

ReadBuffer(B,3);

//EventKKM=PaketOtKKMEvent;
//SetEvent(FormGl->ZaprosOtKKM);
//WaitForSingleObject(FormGl->OtvetCashServera,INFINITE);
//ResetEvent(FormGl->OtvetCashServera);


 //////
}
//-----------------------------------------------------------------------------
// //ответ на запрос по коду без колич.
void amc100k::OtvetNaZaprosPoCodu(void)
{

//SetupComPort("S" ,100,200,200,100,100,false );
ClearBuffer(B);

ReadBuffer(B,16);


char Sum=0;
Sum=(KontrSumm1(B,15)-0x10-0x02);
if (Sum==B[15])     //проверим контрольную сумму
        {


        //номер чека
        int Num=0;
        char *lpNum;
        lpNum=(char*)&Num;
         *(lpNum)=B[0];
         *(lpNum+1)=B[1];
         NumberCheck=Num+1;

        //признак возврата
        if (B[2]==0x21){CheckOperation=Vosvrat;}
        else {CheckOperation=Prod;}

        //код товара
        String strCode="";
        for (int i=3;i<15;i++)
        {
        strCode=strCode+FloatToStr(StrToFloat(IntToHex(B[i]-0x30,2)));
        }
        CodeTovar=StrToFloat(strCode);

         //обнулим параметры товара

        NameTovar="";// название товара
        PriceTovar=0;//цена товара
        KolTovar=1;  //количество товара


        EventKKM=ZaprosPoCoduEvent;
        Synchronize(GenerateExternalEvent);
        }
else
        {
        TextError="Неправильный запрос по коду! Контрольная сумма: "+IntToHex(Sum,2);
        EventKKM=ErrorObmenEvent;
        Synchronize(GenerateExternalEvent);
        return;
        }


if (Posilka()==0)     //error
        {

        }

SetupComPort("S" ,10,20,10,1,100,true);
A[0]=0x04;
A[1]=0x06;
A[2]=0x20;
A[3]=0x4b;
A[4]=0x02;
A[5]=0x88;


int i=10;
M1:
                WriteBuffer(A,6);
                ReadBuffer(B,1);

if (B[0]!=A[5])
        {
        if (i>=0)
                {
                i=i-1;
                Sleep(100);
                goto M1;

                }
        }

ReadBuffer(B,4);

if (Posilka()==0)     //error
        {

        }

SetupComPort("S" ,10,20,10,1,100,true);
A[0]=0x04;
A[1]=0x06;
A[2]=0x99;
A[3]=0x4a;
A[4]=0x01;
A[5]=0x11;

int j=10;
M2:
                SetupComPort("S" ,10,20,250,10,100,true);
                WriteBuffer(A,6);
                ReadBuffer(B,1);

if (B[0]!=A[5])
        {
        if (j>=0)
                {
                j=j-1;
                Sleep(100);
                goto M2;

                }
        }

ReadBuffer(B,4);




if (Posilka()==0)     //error
        {

        }
//-------------------------------
///проверим можно ли отвечать
if (EnableOtvet==false)
        {
        A[0]=0x01;
        A[1]=0x0f;
        A[2]=0xef;
        SetupComPort("S" ,10,20,250,10,100,true);
        WriteBuffer(A,3);
        ReadBuffer(B,1);
        return;
        }
//--------------------------------
//название товара
SetupComPort("S" ,10,20,10,1,100,true);
A[0]=0x18;
A[1]=0x10;

for (int i=1;i<19;i++)
        {

        A[i+1]=32;

        }
int KolSimbol=0;
KolSimbol=NameTovar.Length();
for (int i=1;i<19;i++)
        {
        if (i<=KolSimbol)
                {
                A[i+1]=AmcCodeSimbol(NameTovar[i]);
                }
        }
//цена товара
String StrPriceTovar=FloatToStr(PriceTovar*100);
int intPriceTovar=StrToInt(StrPriceTovar);
int *lpPriceTovar=&intPriceTovar;

//ShowMessage("Цена:"+FloatToStr(PriceTovar)+", "+IntToStr(intPriceTovar));

A[20]=*((char*)lpPriceTovar+3);
A[21]=*((char*)lpPriceTovar+2);
A[22]=*((char*)lpPriceTovar+1);
A[23]=*(char*)lpPriceTovar;

//-----------
A[24]=0x31;
A[25]=KontrSumm1(A,25);


WriteBuffer(A,26);
ReadBuffer(B,1);




//
}

//-----------------------------------------------------------------------------
//ответ на запрос по коду с колич.
void amc100k::OtvetNaZaprosPoCoduKol(void)
{
KolTovar=0;
int KolRasr=0;

//SetupComPort("S" ,100,200,200,100,100,false );
ClearBuffer(B);

ReadBuffer(B,21);


char Sum=0;
Sum=(KontrSumm1(B,20)-0x15-0x02);
if (Sum==B[20])     //проверим контрольную сумму
        {


        //номер чека
        int Num=0;
        char *lpNum;
        lpNum=(char*)&Num;
         *(lpNum)=B[0];
         *(lpNum+1)=B[1];
         NumberCheck=Num+1;

        //признак возврата
        if (B[2]==0x21){CheckOperation=Vosvrat;}
        else {CheckOperation=Prod;}

        //код товара
        String strCode="";
        for (int i=3;i<15;i++)
        {
        strCode=strCode+FloatToStr(StrToFloat(IntToHex(B[i]-0x30,2)));
        }
        CodeTovar=StrToFloat(strCode);

        //количество товара
        int KolT;
        char *lpKolT=0;
        lpKolT=(char*)&KolT;

         *(lpKolT+3)=B[15];
         *(lpKolT+2)=B[16];
         *(lpKolT+1)=B[17];
         *(lpKolT)=B[18];

         if (B[19]==0x02){KolTovar=(double)(KolT)/100;KolRasr=2;}
         if (B[19]==0x03){KolTovar=(double)(KolT)/1000;KolRasr=3;}

         //обнулим параметры товара

        NameTovar="";// название товара
        PriceTovar=0;//цена товара



        EventKKM=ZaprosPoCoduEvent;
        Synchronize(GenerateExternalEvent);
        }
else
        {
        TextError="Неправильный запрос по коду c количеством! Контрольная сумма: "+IntToHex(Sum,2);
        EventKKM=ErrorObmenEvent;
        Synchronize(GenerateExternalEvent);
        return;
        }


if (Posilka()==0)     //error
        {

        }

SetupComPort("S" ,10,20,10,1,100,true);
A[0]=0x04;
A[1]=0x06;
A[2]=0x20;
A[3]=0x4b;
A[4]=0x02;
A[5]=0x88;


int i=10;
M1:
                WriteBuffer(A,6);
                ReadBuffer(B,1);

if (B[0]!=A[5])
        {
        if (i>=0)
                {
                i=i-1;
                Sleep(100);
                goto M1;

                }
        }

ReadBuffer(B,4);

if (Posilka()==0)     //error
        {

        }

SetupComPort("S" ,10,20,10,1,100,true);
A[0]=0x04;
A[1]=0x06;
A[2]=0x99;
A[3]=0x4a;
A[4]=0x01;
A[5]=0x11;

int j=10;
M2:
                SetupComPort("S" ,10,20,250,10,100,true);
                WriteBuffer(A,6);
                ReadBuffer(B,1);

if (B[0]!=A[5])
        {
        if (j>=0)
                {
                j=j-1;
                Sleep(100);
                goto M2;

                }
        }

ReadBuffer(B,4);




if (Posilka()==0)     //error
        {

        }

//-------------------------------
///проверим можно ли отвечать
if (EnableOtvet==false)
        {
        A[0]=0x01;
        A[1]=0x0f;
        A[2]=0xef;
        SetupComPort("S" ,10,20,250,10,100,true);
        WriteBuffer(A,3);
        ReadBuffer(B,1);
        return;
        }
//--------------------------------

//название товара
SetupComPort("S" ,10,20,10,1,100,true);
A[0]=0x1d;
A[1]=0x13;

for (int i=1;i<19;i++)
        {

        A[i+1]=32;

        }
int KolSimbol=0;
KolSimbol=NameTovar.Length();
for (int i=1;i<19;i++)
        {
        if (i<=KolSimbol)
                {
                A[i+1]=AmcCodeSimbol(NameTovar[i]);
                }
        }
//цена товара
String StrPriceTovar=FloatToStr(PriceTovar*100);
int intPriceTovar=StrToInt(StrPriceTovar);
int *lpPriceTovar=&intPriceTovar;
A[20]=*((char*)lpPriceTovar+3);
A[21]=*((char*)lpPriceTovar+2);
A[22]=*((char*)lpPriceTovar+1);
A[23]=*(char*)lpPriceTovar;

//-----------
A[24]=0x31;

//количество товара
int intKolTov=0;

if (KolRasr==2){intKolTov=(int)(KolTovar*100);}
if (KolRasr==3){intKolTov=(int)(KolTovar*1000);}


int *lpKolTov=&intKolTov;
A[25]=*((char*)lpKolTov+3);
A[26]=*((char*)lpKolTov+2);
A[27]=*((char*)lpKolTov+1);
A[28]=*(char*)lpKolTov;

//--------------------
if (KolRasr==2){A[29]=0x02;}
if (KolRasr==3){A[29]=0x03;}


A[30]=KontrSumm1(A,30);


WriteBuffer(A,31);
ReadBuffer(B,1);


//
}
//-----------------------------------------------------------------------------
//ответ на добавление покупки в чек
void amc100k::OtvetNaDobavleniePokupki(void)
{

ReadBuffer(B,10);

char Sum=0;
Sum=(KontrSumm1(B,9)-0x0a-0x07);
if (Sum==B[9])     //проверим контрольную сумму
        {


        //номер чека
        int Num=0;
        char *lpNum;
        lpNum=(char*)&Num;
         *(lpNum)=B[0];
         *(lpNum+1)=B[1];
         NumberCheck=Num+1;

        //номер покупки
        int Pok=0;
        char *lpPok;
        lpPok=(char*)&Pok;
         *(lpPok)=B[2];
         NumberPokupki=Pok;

        //отдел
        int Ot=0;
        char *lpOt;
        lpOt=(char*)&Ot;
         *(lpOt)=B[3];
         Otdel=Ot;

        //признак возврата
        if(B[4]==0){CheckOperation=Prod;}
        if(B[4]==0x01){CheckOperation=Vosvrat;}

        //сумма покупки
        int Sum;
        char *lpSum=0;
        lpSum=(char*)&Sum;

         *(lpSum+3)=B[5];
         *(lpSum+2)=B[6];
         *(lpSum+1)=B[7];
         *(lpSum)=B[8];
         SummaPokupki=(double)(Sum)/100;

        EventKKM=DobavleniePokupkiEvent;
        Synchronize(GenerateExternalEvent);
        }
else
        {
        TextError="Ошибка при добавлении покупки! Контрольная сумма: "+IntToHex(Sum,2);
        EventKKM=ErrorObmenEvent;
        Synchronize(GenerateExternalEvent);
        return;
        }

if (Posilka()==0)     //error
        {

        }

SetupComPort("S" ,100,200,10,1,100,true);
A[0]=0x04;
A[1]=0x06;
A[2]=0x20;
A[3]=0x4b;
A[4]=0x02;
A[5]=0x88;
WriteBuffer(A,6);
//SetupComPort("S" ,100,200,250,10,100,true);
ReadBuffer(B,1);
ReadBuffer(B,4);




if (Posilka()==0)     //error
        {

        }

SetupComPort("S" ,100,200,10,10,100,true);
A[0]=0x01;
A[1]=0x0f;
A[2]=0xef;

WriteBuffer(A,3);
ReadBuffer(B,1);




}

//-----------------------------------------------------------------------------
//ответ на добавление свободной суммы в чек
void amc100k::OtvetNaDobavlenieSvobSumm(void)
{

ReadBuffer(B,10);

char Sum=0;
Sum=(KontrSumm1(B,9)-0x0a-0x06);
if (Sum==B[9])     //проверим контрольную сумму
        {
        CodeTovar=0;

        //номер чека
        int Num=0;
        char *lpNum;
        lpNum=(char*)&Num;
         *(lpNum)=B[0];
         *(lpNum+1)=B[1];
         NumberCheck=Num+1;

        //номер покупки
        int Pok=0;
        char *lpPok;
        lpPok=(char*)&Pok;
         *(lpPok)=B[2];
         NumberPokupki=Pok;

        //отдел
        int Ot=0;
        char *lpOt;
        lpOt=(char*)&Ot;
         *(lpOt)=B[3];
         Otdel=Ot;

        //признак возврата
        if(B[4]==0){CheckOperation=Prod;}
        if(B[4]==0x01){CheckOperation=Vosvrat;}

        //сумма покупки
        int Sum;
        char *lpSum=0;
        lpSum=(char*)&Sum;

         *(lpSum+3)=B[5];
         *(lpSum+2)=B[6];
         *(lpSum+1)=B[7];
         *(lpSum)=B[8];
         SummaPokupki=(double)(Sum)/100;

        CodeTovar=0; //код товара
        ShCodeTovar=""; //штрих код товара
        NameTovar="Свободная сумма";// название товара
        PriceTovar=SummaPokupki;//цена товара
        KolTovar=1;  //количество товара





        EventKKM=DobavlenieSvobSummEvent;
        Synchronize(GenerateExternalEvent);
        }
else
        {
        TextError="Ошибка при добавлении покупки! Контрольная сумма: "+IntToHex(Sum,2);
        EventKKM=ErrorObmenEvent;
        Synchronize(GenerateExternalEvent);
        return;
        }

if (Posilka()==0)     //error
        {

        }

SetupComPort("S" ,100,200,10,1,100,true);
A[0]=0x04;
A[1]=0x06;
A[2]=0x20;
A[3]=0x4b;
A[4]=0x02;
A[5]=0x88;
WriteBuffer(A,6);
//SetupComPort("S" ,100,200,250,10,100,true);
ReadBuffer(B,1);
ReadBuffer(B,4);




if (Posilka()==0)     //error
        {

        }

SetupComPort("S" ,100,200,10,10,100,true);
A[0]=0x01;
A[1]=0x0f;
A[2]=0xef;

WriteBuffer(A,3);
ReadBuffer(B,1);




}
//-----------------------------------------------------------------------------
//ответ на закрытие чека
void amc100k::OtvetNaZakrCheka(void)
{
ReadBuffer(B,19);
char Sum=0;
Sum=(KontrSumm1(B,18)-0x13-0x01);
if (Sum==B[18])    //проверим контрольную сумму
        {
        //номер чека
        int Num=0;
        char *lpNum;
        lpNum=(char*)&Num;
         *(lpNum)=B[0];
         *(lpNum+1)=B[1];
         NumberCheck=Num;

        //номер кл
        int Kl=0;
        char *lpKl;
        lpKl=(char*)&Kl;
         *(lpKl)=B[2];
         *(lpKl+1)=B[3];
         NumberKl=Kl;

        //операция
        if(B[4]==0){CheckOperation=Prod;}
        if(B[4]==0x01){CheckOperation=Vosvrat;}

        //оплата
        if(B[5]==0){Oplata=Nal;}
        if(B[5]==0x01){Oplata=BesNal;}

        //начисление
        if(B[6]==0){Nachislenie=No;}
        if(B[6]==0x01){Nachislenie=Nadbavka;}
        if(B[6]==0x02){Nachislenie=Skidka;}

        //процент
        int Pr=0;
        char *lpPr;
        lpPr=(char*)&Pr;
         *(lpPr)=B[7];
         Procent=Pr;

        //количество покупок
        int KolPok=0;
        char *lpKolPok;
        lpKolPok=(char*)&KolPok;
         *(lpKolPok)=B[9];
         KolPokupok=KolPok;

        //сумма без начислений
                //сумма покупки
        int Sum;
        char *lpSum=0;
        lpSum=(char*)&Sum;

         *(lpSum+3)=B[10];
         *(lpSum+2)=B[11];
         *(lpSum+1)=B[12];
         *(lpSum)=B[13];
         SummaCheck=(double)(Sum)/100;
        //сумма с начислениями
        int RSum;
        char *lpRSum=0;
        lpRSum=(char*)&RSum;

         *(lpRSum+3)=B[14];
         *(lpRSum+2)=B[15];
         *(lpRSum+1)=B[16];
         *(lpRSum)=B[17];
         RealSummaCheck=(double)(RSum)/100;


        }
else
        {
        TextError="Ошибка при закрытии чека! Контрольная сумма: "+IntToHex(Sum,2);
        EventKKM=ErrorObmenEvent;
        Synchronize(GenerateExternalEvent);
        return;
        }



if (Posilka()==0)     //error
        {

        }

SetupComPort("S" ,10,20,10,10,100,true);
A[0]=0x01;
A[1]=0x0f;
A[2]=0xef;

WriteBuffer(A,3);
ReadBuffer(B,1);

if (Posilka()==0)     //error
        {

        }

EventKKM=ZakrChekaEvent;
Synchronize(GenerateExternalEvent);

}
//------------------------------------------------------------------------------
//ответ на сброс чека
void amc100k::OtvetNaSbrosCheka(void)
{

ReadBuffer(B,19);
char Sum=0;
Sum=(KontrSumm1(B,18)-0x13-0x05);
if (Sum==B[18])    //проверим контрольную сумму
        {
        //номер чека
        int Num=0;
        char *lpNum;
        lpNum=(char*)&Num;
         *(lpNum)=B[0];
         *(lpNum+1)=B[1];
         NumberCheck=Num;

        //номер кл
        int Kl=0;
        char *lpKl;
        lpKl=(char*)&Kl;
         *(lpKl)=B[2];
         *(lpKl+1)=B[3];
         NumberKl=Kl;


        //начисление


        //процент

         Procent=0;

        //количество покупок

         KolPokupok=0;

        //сумма без начислений
                //сумма покупки

         SummaCheck=0;
        //сумма с начислениями

         RealSummaCheck=0;


        }
else
        {
        TextError="Ошибка при сбросе чека! Контрольная сумма: "+IntToHex(Sum,2);
        EventKKM=ErrorObmenEvent;
        Synchronize(GenerateExternalEvent);
        return;
        }



if (Posilka()==0)     //error
        {

        }

SetupComPort("S" ,10,20,10,10,100,true);
A[0]=0x01;
A[1]=0x0f;
A[2]=0xef;

WriteBuffer(A,3);
ReadBuffer(B,1);

if (Posilka()==0)     //error
        {

        }

EventKKM=SbrosChekaEvent;
Synchronize(GenerateExternalEvent);
}
//-----------------------------------------------------------------------------
//генерировать внешнее событие
void __fastcall amc100k::GenerateExternalEvent(void)
{
FormGl->ObrabExternalEvent();
}
//----------------------------------------------------------------------------
