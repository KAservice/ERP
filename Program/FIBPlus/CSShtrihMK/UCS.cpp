//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UCS.h"
#include "UF.h"
#pragma package(smart_init)

const WORD CRC16[]={
0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7,//00
0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef, 
0x1231, 0x0210, 0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6,//10 
0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c, 0xf3ff, 0xe3de, 
0x2462, 0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485,//20 
0xa56a, 0xb54b, 0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d, 
0x3653, 0x2672, 0x1611, 0x0630, 0x76d7, 0x66f6, 0x5695, 0x46b4,//30 
0xb75b, 0xa77a, 0x9719, 0x8738, 0xf7df, 0xe7fe, 0xd79d, 0xc7bc, 
0x48c4, 0x58e5, 0x6886, 0x78a7, 0x0840, 0x1861, 0x2802, 0x3823,//40 
0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969, 0xa90a, 0xb92b, 
0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50, 0x3a33, 0x2a12,//50 
0xdbfd, 0xcbdc, 0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a, 
0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41,//60 
0xedae, 0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49, 
0x7e97, 0x6eb6, 0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70,//70 
0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78, 
0x9188, 0x81a9, 0xb1ca, 0xa1eb, 0xd10c, 0xc12d, 0xf14e, 0xe16f,//80 
0x1080, 0x00a1, 0x30c2, 0x20e3, 0x5004, 0x4025, 0x7046, 0x6067, 
0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c, 0xe37f, 0xf35e,//90 
0x02b1, 0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214, 0x6277, 0x7256, 
0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d,//A0 
0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405, 
0xa7db, 0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e, 0xc71d, 0xd73c,//B0 
0x26d3, 0x36f2, 0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634, 
0xd94c, 0xc96d, 0xf90e, 0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab,//C0 
0x5844, 0x4865, 0x7806, 0x6827, 0x18c0, 0x08e1, 0x3882, 0x28a3, 
0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a,//D0 
0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1, 0x1ad0, 0x2ab3, 0x3a92, 
0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b, 0x9de8, 0x8dc9,//E0 
0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1, 
0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8,//F0 
0x6e17, 0x7e36, 0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1, 0x1ef0 
};


//---------------------------------------------------------------------------



__fastcall TCS::TCS(bool CreateSuspended)
        : TThread(CreateSuspended)
{

InBuf=new unsigned char[100];

InPaket=new unsigned char[100];
InKadr=new unsigned char[100];

OutKadr=new  unsigned char[100];  ; //кадр для передачи ККМ без байт маскирования
OutPaket=new unsigned char[100];  //пакет для вывода в порт
C3=0x1;
C4=0x1;

Name="Пробный товар №123456789123456789";
Price=1.23;

}
//----------------------------------------------------------------------------
bool TCS::CheckCRC16(void )
{
bool Res=true;
WORD CRC;
UCHAR i,j;
UCHAR * pointer;
CRC=0;

//считаем длину
j=InKadr[6]+6;
pointer=InKadr+1;

while(j--)
        {
        i=*pointer;
        CRC=(CRC16[CRC>>8])^(CRC<<8)^((WORD) i);
        pointer++;
        }

unsigned char *KS0;
unsigned char *KS1;
KS0=(unsigned char *)&CRC;
KS1=(unsigned char *)&CRC+1;

if ((InKadr[InKadr[6]+7]==*KS0)&&(InKadr[InKadr[6]+7+1]==*KS1))
        {
        Res=true;
        }
else
        {
        Res=false;
        Stroka="Ошибка КС принятого кадра! КС кадра: "+IntToHex(*KS0,2)+" "+IntToHex(*KS1,2)+
                " Принято: "+IntToHex(InKadr[InKadr[6]+7],2)+" "+IntToHex(InKadr[InKadr[6]+7+1],2);
        Synchronize(Soobshenie);

        }


return Res;

}

//---------------------------------------------------------------------------
void TCS::DelSimbolMask(void)
{


//кадр принят полностью
//необходимо убрать символы маскирования
KolByteInKadr=0;
for (int j=0;j<100;j++){InKadr[j]=0;}    //очищяем массив кадра

for (int k=0;k<KolByteInPaket;k++)
        {
        if (InPaket[k]==0x7d)
                {


                if (InPaket[k+1]==0x9e)
                        {
                        InKadr[KolByteInKadr]=0x7e;
                        k++;
                        KolByteInKadr=KolByteInKadr+1;
                        }

                if (InPaket[k+1]==0x9D)
                        {
                        InKadr[KolByteInKadr]=0x7d;
                        k++;
                        KolByteInKadr=KolByteInKadr+1;
                        }

                }
        else
                {
                InKadr[KolByteInKadr]=InPaket[k];
                KolByteInKadr=KolByteInKadr+1;
                }
        }





}



//---------------------------------------------------------------------------
void TCS::AddKontrSumm()
{

WORD CRC;
UCHAR i,j;
UCHAR * pointer;
CRC=0;

//считаем длину
j=OutKadr[6]+6;
pointer=OutKadr+1;

while(j--)
        {
        i=*pointer;
        CRC=(CRC16[CRC>>8])^(CRC<<8)^((WORD) i);
        pointer++;
        }

unsigned char *KS0;
unsigned char *KS1;
KS0=(unsigned char *)&CRC;
KS1=(unsigned char *)&CRC+1;

OutKadr[KolByteOutKadr]=*KS0;
OutKadr[KolByteOutKadr+1]=*KS1;
KolByteOutKadr=KolByteOutKadr+2;
}

//---------------------------------------------------------------------------

void TCS::AddSimbolMask(void)
{

for (int j=0;j<100;j++){OutPaket[j]=0;}    //очищяем массив пакета
KolByteOutPaket=1;
OutPaket[0]=0x7e;

for (int k=1;k<KolByteOutKadr;k++)
        {

        switch (OutKadr[k])
                {

                case 0x7e :
                        {
                        OutPaket[KolByteOutPaket]=0x7d;
                        KolByteOutPaket=KolByteOutPaket+1;

                        OutPaket[KolByteOutPaket]=0x9e;
                        KolByteOutPaket=KolByteOutPaket+1;

                        } break;

                case 0x7d :
                        {
                        OutPaket[KolByteOutPaket]=0x7d;
                        KolByteOutPaket=KolByteOutPaket+1;
                        OutPaket[KolByteOutPaket]=0x9d;
                        KolByteOutPaket=KolByteOutPaket+1;
                        }break;
                default :
                        {
                        OutPaket[KolByteOutPaket]=OutKadr[k];
                        KolByteOutPaket=KolByteOutPaket+1;
                        } break;

                }

        }



//Stroka="Kadr: ";
//for (int i=0;i<KolByteOutKadr;i++){Stroka=Stroka+" "+IntToHex(OutKadr[i],2);}
//Synchronize(Soobshenie);

//Stroka="Paket: ";
//for (int i=0;i<KolByteOutPaket;i++){Stroka=Stroka+" "+IntToHex(OutPaket[i],2);}
//Synchronize(Soobshenie);

}
//-----------------------------------------------------------------------------------
void TCS::OpenPort()
{
ComHandle=CreateFile(NamePort.c_str(),GENERIC_READ|GENERIC_WRITE,0,NULL,
                                OPEN_EXISTING,FILE_FLAG_OVERLAPPED,NULL);

//выделим память для DCB
DCB *dcb;
dcb=(DCB*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,sizeof(DCB));
dcb->DCBlength=sizeof(DCB);
COMMTIMEOUTS *CTO;
CTO=new COMMTIMEOUTS;

String Str="baud=4800 data=8 stop=1 parity=N";

BuildCommDCB( Str.c_str(),dcb);
dcb->XoffLim=1024;
dcb->XonLim=1024;
dcb->fRtsControl=RTS_CONTROL_HANDSHAKE;
dcb->fTXContinueOnXoff=true;
//dcb->EvtChar=0x7e;



CTO->ReadIntervalTimeout=100;
CTO->ReadTotalTimeoutMultiplier=100;
CTO->ReadTotalTimeoutConstant=100;
CTO->WriteTotalTimeoutMultiplier=100;
CTO->WriteTotalTimeoutConstant=100;

SetCommTimeouts(ComHandle,CTO);
SetCommState(ComHandle,dcb);

PurgeComm(ComHandle,PURGE_TXCLEAR|PURGE_RXCLEAR);

}
//----------------------------------------------------------------------------

void TCS::ClosePort()
{

CloseHandle(ComHandle);

}

//---------------------------------------------------------------------------
void __fastcall TCS::Execute()
{
OVERLAPPED OVR;
unsigned long RealByte;
unsigned long OVRByte;
DWORD Mask, Signaled;
int InputByte;


COMSTAT SostPorta;
SostPorta.cbInQue=0;
unsigned long  Err;


memset(&OVR,0,sizeof(OVR));

OVR.hEvent=CreateEvent(NULL,true,false,NULL);


if (SetCommMask(ComHandle,EV_RXCHAR)==0)
        {
       // StrErr="ошибка установки маски   ";

        }

while (!Terminated)
        {

        WaitCommEvent(ComHandle,&Mask,&OVR);
        Signaled=WaitForSingleObject(OVR.hEvent,INFINITE);

        if (Signaled!=WAIT_OBJECT_0){continue;}

        //GetOverlappedResult(ComHandle,&OVR,&OVRByte,false);


        if (ClearCommError(ComHandle,&Err,&SostPorta)==true){InputByte=SostPorta.cbInQue;}
        if (InputByte<=0){continue;}

        for (int i=0;i<100;i++){InBuf[i]=0;}
        ReadFile(ComHandle,InBuf,InputByte,&RealByte,&OVR);
        KolByteInBuf=RealByte;
        WaitForSingleObject(OVR.hEvent,INFINITE);

        for (int i=0;i<KolByteInBuf;i++)
                {
                if (InBuf[i]==0x7e)
                        {
                        for (int j=0;j<100;j++){InPaket[j]=0;InKadr[j]=0;}    //очищяем массив пакета , кадра

                        KolByteInPaket=0;
                        KolByteMask=0;
                        }

                InPaket[KolByteInPaket]=InBuf[i];
                KolByteInPaket=KolByteInPaket+1;
                }

         if (KolByteInPaket>6)
                {
                //количество байт в пакете >=6

                DelSimbolMask();

                if(KolByteInKadr>=InKadr[6]+2+7)
                        {
                        if (CheckCRC16()==true)
                                {
                                ObrabotatKomandu();
                                }
                        else
                                {
                                Stroka="Ошибка контрольной суммы!";Synchronize(Soobshenie);


                                Stroka="Paket: ";
                                for (int i=0;i<KolByteInPaket;i++){Stroka=Stroka+" "+IntToHex(InPaket[i],2);}
                                Synchronize(Soobshenie);

                                Stroka="Kadr: ";
                                for (int i=0;i<KolByteInKadr;i++){Stroka=Stroka+" "+IntToHex(InKadr[i],2);}
                                Synchronize(Soobshenie);

                               }
                        }

                }
         else
                {


                }
        }

}







//---------------------------------------------------------------------------
void TCS::WritePaket(void)
{
OVERLAPPED WrOVR;
unsigned long RealWrite;

memset(&WrOVR,0,sizeof(WrOVR));
WrOVR.hEvent=CreateEvent(NULL,true,false,NULL);

WriteFile(ComHandle,OutPaket,KolByteOutPaket,&RealWrite,&WrOVR);
WaitForSingleObject(WrOVR.hEvent,INFINITE);

}



//----------------------------------------------------------------------------
void __fastcall TCS::UpdateForm()
{

F->RE->Lines->Add(Stroka);
Stroka=" ";
}


//----------------------------------------------------------------------------
void __fastcall TCS::Soobshenie()
{

F->RE->Lines->Add(Stroka);
Stroka=" ";
}


//---------------------------------------------------------------------------
//генерировать внешнее событие
void __fastcall TCS::GenerateExternalEvent(void)
{
F->ObrabExternalEvent();
}
//----------------------------------------------------------------------------
//обработать команду
void TCS::ObrabotatKomandu()
{

switch (InKadr[7])
{

        case 0x80 :
                {
                SvobProd();

                } break;

        case 0x87 :
                {
                SvobOplata();
                }break;
        case 0x90 :
                {
                SakrCheck();
                }break;
        case 0x81 :
                {
                ProdPoKodu();
                }break;
        case 0x91 :
                {
                AnnCheck();
                }break;
        case 0x92 :
                {
                Podtver();
                }break;
        default :
                {

                } break;

}




}
// ----------------------------------------------------------------------------
//свободная продажа
void TCS::SvobProd(void)
{

//--------------
C1=InKadr[4];
C2=InKadr[5];


//тип операции
if (InKadr[8]==1){TypeOperation=Prod;}
if (InKadr[8]==2){TypeOperation=Pokupka;}
if (InKadr[8]==3){TypeOperation=VosvratProd;}
if (InKadr[8]==4){TypeOperation=VosvratPokupki;}

//вид операции
if (InKadr[9]==0){Operation=Oper;}
if (InKadr[9]==1){Operation=Storno;}

//количество
long int  intKol=0;
unsigned char   *lpCharKol=0;

lpCharKol=(unsigned char *)&intKol;

*lpCharKol=InKadr[10];
*(lpCharKol+1)=InKadr[11];
*(lpCharKol+2)=InKadr[12];
*(lpCharKol+3)=InKadr[13];
//*(lpCharKol+4)=InKadr[14];
Kol=((double)intKol)/1000;



//цена
long int  intPrice=0;
unsigned char   *lpCharPrice=0;

lpCharPrice=(unsigned char *)&intPrice;

*lpCharPrice=InKadr[15];
*(lpCharPrice+1)=InKadr[16];
*(lpCharPrice+2)=InKadr[17];
*(lpCharPrice+3)=InKadr[18];
//*(lpCharPrice+4)=InKadr[19];
Price=((double) intPrice)/100;


//отдел
Otdel=InKadr[20];


//оператор
NumberOperator=InKadr[21];


 // ***************************
ExternalEvent=SvobProdEvent;
Synchronize(GenerateExternalEvent);
 //***************************


///подготовим ответ
for (int j=0;j<100;j++){OutPaket[j]=0;OutKadr[j]=0;}
KolByteOutKadr=0;
KolByteOutPaket=0;

OutKadr[0]=0x7e;        //стартовый буфер
OutKadr[1]=0x02;        //адрес ккм
OutKadr[2]=0x01;        //адрес сервера
OutKadr[3]=0x01;        //ответ
OutKadr[4]=C3=C1;       //счетчик команд
OutKadr[5]=C4=C4+1;     //счетчик ответов
OutKadr[6]=2;           //длина собщения
OutKadr[7]=0x80;        //ответ
OutKadr[8]=0;           //0
KolByteOutKadr=9;

AddKontrSumm();
AddSimbolMask();
WritePaket();
}
//-----------------------------------------------------------------------------
//продажа по коду
void TCS::ProdPoKodu(void)
{

//--------------
C1=InKadr[4];
C2=InKadr[5];


//тип операции
if (InKadr[8]==1){TypeOperation=Prod;}
if (InKadr[8]==2){TypeOperation=Pokupka;}
if (InKadr[8]==3){TypeOperation=VosvratProd;}
if (InKadr[8]==4){TypeOperation=VosvratPokupki;}

//вид операции
if (InKadr[9]==0){Operation=Oper;}
if (InKadr[9]==1){Operation=Storno;}

//количество
long int  intKol=0;
unsigned char   *lpCharKol=0;

lpCharKol=(unsigned char *)&intKol;

*lpCharKol=InKadr[10];
*(lpCharKol+1)=InKadr[11];
*(lpCharKol+2)=InKadr[12];
*(lpCharKol+3)=InKadr[13];
*(lpCharKol+4)=InKadr[14];
Kol=((double)intKol)/1000;



//код
long int  intCode=0;
unsigned char   *lpCharCode=0;

lpCharCode=(unsigned char *)&intCode;

*lpCharCode=InKadr[15];
*(lpCharCode+1)=InKadr[16];
*(lpCharCode+2)=InKadr[17];
*(lpCharCode+3)=InKadr[18];
*(lpCharCode+4)=InKadr[19];
Code= intCode;


//оператор
NumberOperator=InKadr[20];


 // ***************************
ExternalEvent=ProdPoCoduEvent;
Synchronize(GenerateExternalEvent);

//***************************




///подготовим ответ
for (int j=0;j<100;j++){OutPaket[j]=0;OutKadr[j]=0;}
KolByteOutKadr=0;
KolByteOutPaket=0;

OutKadr[0]=0x7e;        //стартовый буфер
OutKadr[1]=0x02;        //адрес ккм
OutKadr[2]=0x01;        //адрес сервера
OutKadr[3]=0x01;        //ответ
OutKadr[4]=C3=C1;       //счетчик команд
OutKadr[5]=C4=C4+1;     //счетчик ответов
OutKadr[6]=52;           //длина собщения
OutKadr[7]=0x81;        //ответ
OutKadr[8]=0;           //0 код ошибки

//  наименование товара 40 байт

unsigned char *charName=new unsigned char [40];

for (int i=0;i< 40;i++)
        {
         charName[i]=0x20; //символ пробела
        }

strcpy(charName,Name.c_str());


for (int i=9;i<49;i++)
       {
       OutKadr[i]=0x20;
       }


for (int i=9;i<49;i++)
       {
       OutKadr[i]=charName[i-9];
       //ShowMessage("Элемент № "+ IntToStr(i-8)+ "="+IntToHex(11616,8));
        }

delete [] charName;

//цена товара 5 байт
//цена товара

long int intPrice=StrToInt(FloatToStr(Price*100));

//Stroka=" Цена - "+FloatToStr(Price)+" "+IntToStr(intPrice);

///Synchronize(Soobshenie);

long int *lpPrice=&intPrice;



OutKadr[49]=*((unsigned char*)lpPrice);
OutKadr[50]=*((unsigned char*)lpPrice+1);
OutKadr[51]=*((unsigned char*)lpPrice+2);
OutKadr[52]=*((unsigned char*)lpPrice+3);
OutKadr[53]=0;//*(unsigned char*)(lpPrice+4);



//отдел 1 байт

OutKadr[54]=Otdel;

//налогвые группы   0в 4 байтах
OutKadr[55]=0;
OutKadr[56]=0;
OutKadr[57]=0;
OutKadr[58]=0;



KolByteOutKadr=59;       //


AddKontrSumm();
AddSimbolMask();
WritePaket();

}
// ----------------------------------------------------------------------------
//свободная оплата
void TCS::SvobOplata(void)
{

//--------------
C1=InKadr[4];
C2=InKadr[5];


//тип оплаты
if (InKadr[8]==1){TypeOplat=Nal;}
if (InKadr[8]==2){TypeOplat=Opl2;}
if (InKadr[8]==3){TypeOplat=Opl3;}


//тип открытого чека
if (InKadr[9]==1){TypeOperation=Prod;}
if (InKadr[9]==2){TypeOperation=Pokupka;}
if (InKadr[9]==3){TypeOperation=VosvratProd;}
if (InKadr[9]==4){TypeOperation=VosvratPokupki;}

//вид операции
if (InKadr[10]==0){Operation=Oper;}
if (InKadr[10]==1){Operation=Storno;}


//сумма
long int  intSumma=0;
unsigned char   *lpCharSumma=0;

lpCharSumma=(unsigned char *)&intSumma;

*lpCharSumma=InKadr[11];
*(lpCharSumma+1)=InKadr[12];
*(lpCharSumma+2)=InKadr[13];
*(lpCharSumma+3)=InKadr[14];
//*(lpCharSumma+4)=InKadr[15];
SummaOplat=((double) intSumma)/100;



//оператор
NumberOperator=InKadr[16];

 // ***************************
ExternalEvent=SvobOplataEvent;
Synchronize(GenerateExternalEvent);
 //***************************

///подготовим ответ

for (int j=0;j<100;j++){OutPaket[j]=0;OutKadr[j]=0;}
KolByteOutKadr=0;
KolByteOutPaket=0;

OutKadr[0]=0x7e;        //стартовый буфер
OutKadr[1]=0x02;        //адрес ккм
OutKadr[2]=0x01;        //адрес сервера
OutKadr[3]=0x01;        //ответ
OutKadr[4]=C3=C1;       //счетчик команд
OutKadr[5]=C4=C4+1;     //счетчик ответов
OutKadr[6]=2;           //длина собщения
OutKadr[7]=0x80;        //ответ
OutKadr[8]=0;           //0
KolByteOutKadr=9;

AddKontrSumm();
AddSimbolMask();
WritePaket();


}



// ----------------------------------------------------------------------------
//закрытие чека
void TCS::SakrCheck(void)
{

//--------------
C1=InKadr[4];
C2=InKadr[5];

//оператор
NumberOperator=InKadr[8];



//тип операции
if (InKadr[9]==1){TypeOperation=Prod;}
if (InKadr[9]==2){TypeOperation=Pokupka;}
if (InKadr[9]==3){TypeOperation=VosvratProd;}
if (InKadr[9]==4){TypeOperation=VosvratPokupki;}

//дата
int Date1,Date2,Date3;
WORD Time1,Time2,Time3;
Date1=InKadr[10];
Date2=InKadr[11];
Date3=InKadr[12];
DateCheck=EncodeDate(Date3,Date2,Date1);


//время
Time1=InKadr[13];
Time2=InKadr[14];
Time3=InKadr[15];
TimeCheck=EncodeTime(Time1,Time2,Time3,0);


//номер документа
int  intNumberDoc=0;
unsigned char   *lpNumberDoc=0;

lpNumberDoc=(unsigned char *)&intNumberDoc;

*lpNumberDoc=InKadr[16];
*(lpNumberDoc+1)=InKadr[17];

NumberDoc=intNumberDoc;


//номер документа
int  intNumberCheck=0;
unsigned char   *lpNumberCheck;

lpNumberCheck=(unsigned char *)&intNumberCheck;

*lpNumberCheck=InKadr[18];
*(lpNumberCheck+1)=InKadr[19];

NumberCheck=intNumberCheck;

// ***************************
ExternalEvent=SakrCheckEvent;
Synchronize(GenerateExternalEvent);
 //***************************
///подготовим ответ
for (int j=0;j<100;j++){OutPaket[j]=0;OutKadr[j]=0;}
KolByteOutKadr=0;
KolByteOutPaket=0;

OutKadr[0]=0x7e;        //стартовый буфер
OutKadr[1]=0x02;        //адрес ккм
OutKadr[2]=0x01;        //адрес сервера
OutKadr[3]=0x01;        //ответ
OutKadr[4]=C3=C1;       //счетчик команд
OutKadr[5]=C4=C4+1;     //счетчик ответов
OutKadr[6]=22;           //длина собщения
OutKadr[7]=0x90;        //ответ

OutKadr[8]=0x0;
OutKadr[9]=0x0;
OutKadr[10]=0x0;
OutKadr[11]=0x0;
OutKadr[12]=0x0;

OutKadr[13]=0x0;
OutKadr[14]=0x0;
OutKadr[15]=0x0;
OutKadr[16]=0x0;
OutKadr[17]=0x0;

OutKadr[18]=0x0;
OutKadr[19]=0x0;
OutKadr[20]=0x0;
OutKadr[21]=0x0;
OutKadr[22]=0x0;

OutKadr[23]=0x0;
OutKadr[24]=0x0;
OutKadr[25]=0x0;
OutKadr[26]=0x0;
OutKadr[27]=0x0;


OutKadr[28]=0;           //0
KolByteOutKadr=29;
AddKontrSumm();
AddSimbolMask();
WritePaket();
}

//-----------------------------------------------------------------------------
//аннулирование чека
void TCS::AnnCheck(void)
{

//--------------
C1=InKadr[4];
C2=InKadr[5];

//оператор
NumberOperator=InKadr[8];



//тип операции
if (InKadr[9]==1){TypeOperation=Prod;Stroka=Stroka+" Продажа. ";}
if (InKadr[9]==2){TypeOperation=Pokupka;Stroka=Stroka+" Покупка. ";}
if (InKadr[9]==3){TypeOperation=VosvratProd;Stroka=Stroka+" Возврат продажи. ";}
if (InKadr[9]==4){TypeOperation=VosvratPokupki;Stroka=Stroka+" Возврат покупки. ";}

//дата
WORD Date1,Date2,Date3;
WORD Time1,Time2,Time3;
Date1=InKadr[10];
Date2=InKadr[11];
Date3=InKadr[12];
DateCheck=EncodeDate(Date3,Date2,Date1);



//время
Time1=InKadr[13];
Time2=InKadr[14];
Time3=InKadr[15];
TimeCheck=EncodeTime(Time1,Time2,Time3,0);




//номер документа
int  intNumberDoc=0;
unsigned char   *lpNumberDoc=0;

lpNumberDoc=(unsigned char *)&intNumberDoc;

*lpNumberDoc=InKadr[16];
*(lpNumberDoc+1)=InKadr[17];

NumberDoc=intNumberDoc;


//номер документа
int  intNumberCheck=0;
unsigned char   *lpNumberCheck;

lpNumberCheck=(unsigned char *)&intNumberCheck;

*lpNumberCheck=InKadr[18];
*(lpNumberCheck+1)=InKadr[19];

NumberCheck=intNumberCheck;



 // ***************************
ExternalEvent=AnnCheckEvent;
Synchronize(GenerateExternalEvent);
 //***************************
///подготовим ответ
for (int j=0;j<100;j++){OutPaket[j]=0;OutKadr[j]=0;}
KolByteOutKadr=0;
KolByteOutPaket=0;

OutKadr[0]=0x7e;        //стартовый буфер
OutKadr[1]=0x02;        //адрес ккм
OutKadr[2]=0x01;        //адрес сервера
OutKadr[3]=0x01;        //ответ
OutKadr[4]=C3=C1;       //счетчик команд
OutKadr[5]=C4=C4+1;     //счетчик ответов
OutKadr[6]=3;           //длина собщения
OutKadr[7]=0x89;        //код ответа

OutKadr[8]=0x0;
OutKadr[9]=0x0;
OutKadr[10]=0x0;
KolByteOutKadr=10;


AddKontrSumm();
AddSimbolMask();
WritePaket();



}


//-----------------------------------------------------------------------------
//потверждение
void TCS::Podtver(void)
{

//--------------
C1=InKadr[4];
C2=InKadr[5];

 // ***************************
ExternalEvent=PodtverEvent;
Synchronize(GenerateExternalEvent);
 //***************************
///подготовим ответ
for (int j=0;j<100;j++){OutPaket[j]=0;OutKadr[j]=0;}
KolByteOutKadr=0;
KolByteOutPaket=0;

OutKadr[0]=0x7e;        //стартовый буфер
OutKadr[1]=0x02;        //адрес ккм
OutKadr[2]=0x01;        //адрес сервера
OutKadr[3]=0x01;        //ответ
OutKadr[4]=C3=C1;       //счетчик команд
OutKadr[5]=C4=C4+1;     //счетчик ответов
OutKadr[6]=2;           //длина собщения
OutKadr[7]=0x92;        //код ответа

OutKadr[8]=0x0;
KolByteOutKadr=9;


AddKontrSumm();
AddSimbolMask();
WritePaket();



}
