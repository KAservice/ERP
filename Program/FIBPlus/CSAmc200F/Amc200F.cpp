//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "Amc200F.h"
#include "GlavForm.h"
#pragma package(smart_init)


void glSaveProtocol(String str);
//---------------------------------------------------------------------------

__fastcall amc200f::amc200f(bool CreateSuspended)
        : TThread(CreateSuspended)
{
OpenPort();
OperError=false;
B=new char[50];
A=new char[50];

//������� ������ ��� DCB
dcb=(DCB*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,sizeof(DCB));
dcb->DCBlength=sizeof(DCB);
commmtimeouts=new COMMTIMEOUTS;
PortOpen=false; //���� �� ������
ConnectkKKM=false;// ��� �� ����������

}

//--------------------------------------------------------------------------
void amc200f::OutputProtokol( unsigned char * buf, int len, bool wr)
{
String StrProt="";
for (int i=0;i<len;i++)
        {
        StrProt=StrProt+IntToHex(buf[i],2)+" ";
        }

if (wr==true){StrProt="������("+IntToStr(len)+"): "+StrProt;}
else {StrProt="������("+IntToStr(len)+"): "+StrProt;}
glSaveProtocol(StrProt);
}
//----------------------------------------------------------------------------
//������� ����
bool  amc200f::OpenPort(void)
{
bool res;
res=true;
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
//�������  ����
bool amc200f::ClosePort(void)
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
//������ ����������� �����
char __fastcall amc200f::KontrSumm1(char *Buffer,int Kol)     //��� ���� ������� � 1
{
int ks=0;

for (int i=0;i<Kol;i++)
        {
        ks=ks+Buffer[i];

        }
ks=0xff-ks;
return  ks;

}
//-----------------------------------------------------------------------------
//������ ����������� �����
char __fastcall amc200f::KontrSumm2(char *Buffer,int Kol)
{
int ks=0;

for (int i=0;i<Kol;i++)
        {
        ks=ks+Buffer[i];

        }

return  ks;

}
//-----------------------------------------------------------------------------
//��������� ������ Str ����� ��������� Symbol �� Len
String amc200f::DopStrL(String Str, String Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Symbol+Str;
        }
return Str;
}
//-----------------------------------------------------------------------------
// �������� ��� �������
char amc200f::AmcCodeSimbol(String StringSimbol)
{

char Res=32;

if (StringSimbol=='0'){Res=48;}
if (StringSimbol=='1'){Res=49;}
if (StringSimbol=='2'){Res=50;}
if (StringSimbol=='3'){Res=51;}
if (StringSimbol=='4'){Res=52;}
if (StringSimbol=='5'){Res=53;}
if (StringSimbol=='6'){Res=54;}
if (StringSimbol=='7'){Res=55;}
if (StringSimbol=='8'){Res=56;}
if (StringSimbol=='9'){Res=57;}

if (StringSimbol==' '){Res=32;}
if (StringSimbol=='!'){Res=33;}
if (StringSimbol=='"'){Res=34;}
if (StringSimbol=='#'){Res=35;}
if (StringSimbol=='$'){Res=36;}
if (StringSimbol=='%'){Res=37;}
if (StringSimbol=='&'){Res=38;}
//if (StringSimbol=='''){Res=39;}
//if (StringSimbol=='('){Res=40;}
//if (StringSimbol==')'){Res=41;}
if (StringSimbol=='*'){Res=42;}
if (StringSimbol=='+'){Res=43;}
if (StringSimbol==','){Res=44;}
if (StringSimbol=='-'){Res=45;}
if (StringSimbol=='.'){Res=46;}
if (StringSimbol=='/'){Res=47;}

if (StringSimbol=='{'){Res=123;}
if (StringSimbol=='|'){Res=124;}
if (StringSimbol=='}'){Res=125;}
if (StringSimbol=='~'){Res=126;}
if (StringSimbol=='*'){Res=127;}

if (StringSimbol=='�'){Res=192;}
if (StringSimbol=='�'){Res=193;}
if (StringSimbol=='�'){Res=194;}
if (StringSimbol=='�'){Res=195;}
if (StringSimbol=='�'){Res=196;}
if (StringSimbol=='�'){Res=197;}
if (StringSimbol=='�'){Res=198;}
if (StringSimbol=='�'){Res=199;}
if (StringSimbol=='�'){Res=200;}
if (StringSimbol=='�'){Res=201;}
if (StringSimbol=='�'){Res=202;}
if (StringSimbol=='�'){Res=203;}
if (StringSimbol=='�'){Res=204;}
if (StringSimbol=='�'){Res=205;}
if (StringSimbol=='�'){Res=206;}
if (StringSimbol=='�'){Res=207;}
if (StringSimbol=='�'){Res=208;}
if (StringSimbol=='�'){Res=209;}
if (StringSimbol=='�'){Res=210;}
if (StringSimbol=='�'){Res=211;}
if (StringSimbol=='�'){Res=212;}
if (StringSimbol=='�'){Res=213;}
if (StringSimbol=='�'){Res=214;}
if (StringSimbol=='�'){Res=215;}
if (StringSimbol=='�'){Res=216;}
if (StringSimbol=='�'){Res=217;}
if (StringSimbol=='�'){Res=218;}
if (StringSimbol=='�'){Res=219;}
if (StringSimbol=='�'){Res=220;}
if (StringSimbol=='�'){Res=221;}
if (StringSimbol=='�'){Res=222;}
if (StringSimbol=='�'){Res=223;}

if (StringSimbol=='�'){Res=224;}
if (StringSimbol=='�'){Res=225;}
if (StringSimbol=='�'){Res=226;}
if (StringSimbol=='�'){Res=227;}
if (StringSimbol=='�'){Res=228;}
if (StringSimbol=='�'){Res=229;}
if (StringSimbol=='�'){Res=230;}
if (StringSimbol=='�'){Res=231;}
if (StringSimbol=='�'){Res=232;}
if (StringSimbol=='�'){Res=233;}
if (StringSimbol=='�'){Res=234;}
if (StringSimbol=='�'){Res=235;}
if (StringSimbol=='�'){Res=236;}
if (StringSimbol=='�'){Res=237;}
if (StringSimbol=='�'){Res=238;}
if (StringSimbol=='�'){Res=239;}
if (StringSimbol=='�'){Res=240;}
if (StringSimbol=='�'){Res=241;}
if (StringSimbol=='�'){Res=242;}
if (StringSimbol=='�'){Res=243;}
if (StringSimbol=='�'){Res=244;}
if (StringSimbol=='�'){Res=245;}
if (StringSimbol=='�'){Res=246;}
if (StringSimbol=='�'){Res=247;}
if (StringSimbol=='�'){Res=248;}
if (StringSimbol=='�'){Res=249;}
if (StringSimbol=='�'){Res=250;}
if (StringSimbol=='�'){Res=251;}
if (StringSimbol=='�'){Res=252;}
if (StringSimbol=='�'){Res=253;}
if (StringSimbol=='�'){Res=254;}
if (StringSimbol=='�'){Res=255;}




return  Res;
}

//-----------------------------------------------------------------------------
//��������� ���� ��� �����/������
void amc200f::SetupComPort(String Parity ,int RI,int RM, int RC, int WM, int WC, bool ClearBuffer)
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
//�������� �����
void amc200f::ClearBuffer(char * B)
{
for (int i=0;i<50;i++)
        {
        B[i]=0;

        }


}

//---------------------------------------------------------------------------
//������� ����//�������� ������
//******************************************************************************
void __stdcall ENDWrite(unsigned long ErrorCode,unsigned long BytesTransfered,OVERLAPPED *stOVR)
{

//ShowMessage("������� ��������� ���������� ������!");

}


//�������� ����� � ����
//******************************************************************************

void __fastcall amc200f::WriteBuffer(char  *B, int L)

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


//������� ������
//******************************************************************************
void __stdcall ENDRead(unsigned long ErrorCode,unsigned long BytesTransfered,OVERLAPPED *stOVR)
{

//ShowMessage("������� ��������� ���������� ������!");
//Form1->LabelMessage->Caption="�������  "+IntToStr(BytesTransfered)+" ����!";

}

//******************************************************************************
//��������� ������ �� �����
void __fastcall amc200f::ReadBuffer(char *B, int L)
{


OVERLAPPED stOVR;
memset(&stOVR,0,sizeof(stOVR));

ReadFileEx(ComHandle,B,L,&stOVR,ENDRead) ;
SleepEx( INFINITE, true);

}
//-----------------------------------------------------------------------------
//���������� ���
int amc200f::ConnectKKM(void)
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




return Res;


}

//-----------------------------------------------------------------------------
//��������� ���
int amc200f::DisconnectKKM(void)
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
void __fastcall amc200f::Execute()
{

while (!Terminated)
        {
        Sleep(1000);
        if (Terminated){continue;}
        try     {
                  if (PortOpen==false)
                        {
                        if (OpenPort()==false)
                                {
                               ConnectkKKM=false;
                                EventKKM=ErrorObmenEvent;
                                TextError="�� ������� ������� ����!";
                                Synchronize(GenerateExternalEvent);
                                }
                        }
                //������� ������� ����� ���
                charSetNumber=255-(intSetNumber/10)*16-(intSetNumber-(intSetNumber/10)*10);

                if (ConnectKKM()==1 && PortOpen==true)    //��������� ���
                        {

                                ConnectkKKM=true;
                                EventKKM=ConnectEvent;
                                Synchronize(GenerateExternalEvent);
                                }
                else    {  //������ �����������
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

                if (ConnectkKKM==true)      //���� ��� ���������� �� ��������
                        {
                        DisconnectKKM();
                        EventKKM=DisconnectEvent;
                        Synchronize(GenerateExternalEvent);
                        }

                if (PortOpen==true)    //���� ���� ������ �� �������
                        {
                        if (ClosePort()==false)
                                {
                                EventKKM=ErrorObmenEvent;
                                TextError="�� ������� ������� ����!";
                                Synchronize(GenerateExternalEvent);
                                }
                        }
                }
        catch (...)
                {
                if (ConnectkKKM==true)      //���� ��� ���������� �� ��������
                        {
                        DisconnectKKM();
                        EventKKM=DisconnectEvent;
                        Synchronize(GenerateExternalEvent);
                        }

                if (PortOpen==true)    //���� ���� ������ �� �������
                        {
                        if (ClosePort()==false)
                                {
                                EventKKM=ErrorObmenEvent;
                                TextError="�� ������� ������� ����!";
                                Synchronize(GenerateExternalEvent);
                                }
                        }

                }
        }
}
//-----------------------------------------------------------------------------
// ������� ��� �������� ����� � ���
int amc200f::Posilka(void)
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
//���������� ������� �� ��������� ������� ���
if (B[0]==0)
        {   //��� ����� � ���
        if (EstSvazKKM==true)
                {

                EstSvazKKM=false;
                EventKKM=IzmStatusKKMEvent;
                TextError="��� �� ��������!������� "+IntToHex(B[0],2) ;
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
        //�������� ���������� ������
        if (B[0]!=A[0])
                {
                if (i>=0)
                        {
                        if (B[0]!=0x65)
                                {
                                i=i-1;
                                }
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
                TextError="����������� ����� � ���!������� "+IntToHex(B[0],2);
                Synchronize(GenerateExternalEvent);
                }
        }

return Res;

}

//-----------------------------------------------------------------------------
//�������� ���� ���
void  amc200f::OprositPort()
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

bool Obrab=false;

if ((B[0]==0x03) && (B[1]==0x00))    //���� �����
        {
        OtvetNaScanPaket();
        Obrab=true;
        }

if ((B[0]==0x10) && (B[1]==0x02))     //������ �� ���� ��� �����.
        {
        OtvetNaZaprosPoCodu();
        Obrab=true;
        }

if ((B[0]==0x1a) && (B[1]==0x02))     //������ �� ���� c �����.
        {
        OtvetNaZaprosPoCoduKol();
        Obrab=true;
        }


if ((B[0]==0x15) && (B[1]==0x07))   //���������� ������� � ���
        {
        OtvetNaDobavleniePokupki();
        Obrab=true;
        }

if ((B[0]==0x15) && (B[1]==0x06))   //��������� ��������� ����� � ���
        {
        OtvetNaDobavlenieSvobSumm();
        Obrab=true;
        }


if ((B[0]==0x10) && (B[1]==0x01))    //�������� ����
        {
        OtvetNaZakrCheka();
        Obrab=true;
        }

if ((B[0]==0x10) && (B[1]==0x05))    //����� ����
        {
        OtvetNaSbrosCheka();
        Obrab=true;
        }


if ((B[0]!=0)||(B[1]!=0))      //����������� �������
        {
        if(Obrab==false)
                {
                ObrabUnknownEvent();
                }
        }

}
//-----------------------------------------------------------------------------
//����� �� ���� �����
void  amc200f::OtvetNaScanPaket(void)
{

ReadBuffer(B,3);
}
//-----------------------------------------------------------------------------
// //����� �� ������ �� ���� ��� �����.
void amc200f::OtvetNaZaprosPoCodu(void)
{
OutputProtokol( B, 2, false);
glSaveProtocol("������ �� ����");
//SetupComPort("S" ,100,200,200,100,100,false );
ClearBuffer(B);

ReadBuffer(B,16);OutputProtokol( B, 16, false);


char Sum=0;
Sum=(KontrSumm1(B,15)-0x10-0x02);
if (Sum==B[15])     //�������� ����������� �����
        {


        //����� ����
        int Num=0;
        char *lpNum;
        lpNum=(char*)&Num;
         *(lpNum)=B[0];
         *(lpNum+1)=B[1];
         NumberCheck=Num+1;

        //������� ��������
        if (B[2]==0x02){CheckOperation=Vosvrat;}
        else {CheckOperation=Prod;}

        //��� ������
        String strCode="";
        for (int i=3;i<15;i++)
        {
        if (B[i]!=0x20)
                {
                strCode=strCode+FloatToStr(StrToFloat(IntToHex(B[i]-0x30,2)));
                }
        }
        CodeTovar=StrToFloat(strCode);

         //������� ��������� ������

        NameTovar="";// �������� ������
        PriceTovar=0;//���� ������
        KolTovar=1;  //���������� �����

        //������� ����� ��
        //--------------------------------
         if (Posilka()==0)     //error
                {

                }

        A[0]=0x04;
        A[1]=0x06;
        A[2]=0xb8;
        A[3]=0x19;
        A[4]=0x02;
        A[5]=0x22;
        SetupComPort("S" ,100,200,200,100,100,false );
        WriteBuffer(A,6); OutputProtokol( A, 6, true);
        ClearBuffer(B);
        ReadBuffer(B,5);  OutputProtokol( B, 5, false);
        //����� ��
        int Kl=0;
        char *lpKl;
        lpKl=(char*)&Kl;
         *(lpKl)=B[3];
         *(lpKl+1)=B[2];
         NumberKl=Kl;
        //-------------------------------------------------

        EventKKM=ZaprosPoCoduEvent;
        Synchronize(GenerateExternalEvent);
        }
else
        {
        TextError="������������ ������ �� ����! ����������� �����: "+IntToHex(Sum,2);
        EventKKM=ErrorObmenEvent;
        Synchronize(GenerateExternalEvent);
        return;
        }


if (Posilka()==0)     //error
        {

        }

//SetupComPort("S" ,10,20,10,1,100,true);
//A[0]=0x04;
//A[1]=0x06;
//A[2]=0x28;
//A[3]=0x2b;
//A[4]=0x01;
//A[5]=0xa1;


//int i=10;
//M1:
//                WriteBuffer(A,6);
//                ReadBuffer(B,1);

//if (B[0]!=A[5])
//        {
//        if (i>=0)
//                {
//                i=i-1;
//                Sleep(100);
//                goto M1;
//
//                }
///        }

//ReadBuffer(B,4);

//if (Posilka()==0)     //error
//        {

//        }

//SetupComPort("S" ,10,20,10,1,100,true);
//A[0]=0x04;
//A[1]=0x06;
//A[2]=0x99;
//A[3]=0x4a;
//A[4]=0x01;
//A[5]=0x11;

//int j=10;
//M2:
//                SetupComPort("S" ,10,20,250,10,100,true);
//                WriteBuffer(A,6);
//                ReadBuffer(B,1);

//if (B[0]!=A[5])
//        {
//        if (j>=0)
//                {
//                j=j-1;
//                Sleep(100);
//                goto M2;

//                }
//        }

//ReadBuffer(B,4);




if (Posilka()==0)     //error
        {

        }
//-------------------------------
///�������� ����� �� ��������
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
//�������� ������
SetupComPort("S" ,10,20,10,1,100,true);
A[0]=0x1d;
A[1]=0x10;

for (int i=2;i<20;i++)
        {

        A[i]=32;

        }
int KolSimbol=0;
KolSimbol=NameTovar.Length();
for (int i=1;i<17;i++)
        {
        if (i<=KolSimbol)
                {
                A[i+1]=AmcCodeSimbol(NameTovar[i]);
                }
        }
//���� ������
String StrPriceTovar=FloatToStr(PriceTovar*100);
StrPriceTovar=DopStrL(StrPriceTovar,"0",8);

for (int i=1; i<9;i++)
        {
        A[17+i]=StrToInt(StrPriceTovar[i])+48;
        }


//---------------------
A[26]=0x30;
A[27]=0x31;
A[28]=0x30;
A[29]=0x30;
A[30]=KontrSumm1(A,30);


WriteBuffer(A,31); OutputProtokol( A, 31, true);
ReadBuffer(B,1);   OutputProtokol( B, 1, false);




//
}

//-----------------------------------------------------------------------------
//����� �� ������ �� ���� � �����.
void amc200f::OtvetNaZaprosPoCoduKol(void)
{
KolTovar=0;
int KolRasr=0;
OutputProtokol( B, 2, false);
glSaveProtocol("������ �� ���� � �����������");
//SetupComPort("S" ,100,200,200,100,100,false );
ClearBuffer(B);

ReadBuffer(B,26); OutputProtokol( B,26, false);



char Sum=0;
Sum=(KontrSumm1(B,25)-0x1a-0x02);
if (Sum==B[25])     //�������� ����������� �����
        {


        //����� ����
        int Num=0;
        char *lpNum;
        lpNum=(char*)&Num;
         *(lpNum)=B[0];
         *(lpNum+1)=B[1];
         NumberCheck=Num+1;

        //������� ��������
        if (B[2]==0x00){CheckOperation=Prod;}
        else {CheckOperation=Vosvrat;}

        //��� ������
        String strCode="";
        for (int i=3;i<15;i++)
        {
        if (B[i]!=0x20)
                {

                strCode=strCode+FloatToStr(StrToFloat(IntToHex(B[i]-0x30,2)));

                }
        }


        CodeTovar=StrToFloat(strCode);


        //���������� ������
        String strKol="";
        int Mn;
        for (int i=15;i<22;i++)
        {
        if (B[i]!=0x20)
                {
                if (B[21]==0x2c){Mn=1000;}
                if (B[i]!=0x2c)
                        {
                        strKol=strKol+FloatToStr(StrToFloat(IntToHex(B[i]-0x30,2)));
                        }
                }
        }

        //ShowMessage(" ���������� "+strKol);

        for (int i=22;i<25;i++)
        {
        if (B[i]!=0x20)
                {
                if (B[22]==0x2c){Mn=100;}

                if (B[i]!=0x2c)
                        {
                        strKol=strKol+FloatToStr(StrToFloat(IntToHex(B[i]-0x30,2)));
                        }
                }
        }

        KolTovar=(StrToFloat(strKol))/Mn;

         //������� ��������� ������

        NameTovar="";// �������� ������
        PriceTovar=0;//���� ������


        //������� ����� ��
        //--------------------------------
         if (Posilka()==0)     //error
                {

                }

        A[0]=0x04;
        A[1]=0x06;
        A[2]=0xb8;
        A[3]=0x19;
        A[4]=0x02;
        A[5]=0x22;
        SetupComPort("S" ,100,200,200,100,100,false );
        WriteBuffer(A,6); OutputProtokol( A, 6, true);
        ClearBuffer(B);
        ReadBuffer(B,5);  OutputProtokol( B, 5, false);
        //����� ��
        int Kl=0;
        char *lpKl;
        lpKl=(char*)&Kl;
         *(lpKl)=B[3];
         *(lpKl+1)=B[2];
         NumberKl=Kl;
        //-------------------------------------------------


        EventKKM=ZaprosPoCoduEvent;
        Synchronize(GenerateExternalEvent);
        }
else
        {
        TextError="������������ ������ �� ���� c �����������! ����������� �����: "+IntToHex(Sum,2);
        EventKKM=ErrorObmenEvent;
        Synchronize(GenerateExternalEvent);
        return;
        }


if (Posilka()==0)     //error
        {

        }

//SetupComPort("S" ,10,20,10,1,100,true);
//A[0]=0x04;
//A[1]=0x06;
//A[2]=0x20;
//A[3]=0x4b;
//A[4]=0x02;
//A[5]=0x88;


//int i=10;
//M1:
//                WriteBuffer(A,6);
//                ReadBuffer(B,1);

//if (B[0]!=A[5])
//        {
//        if (i>=0)
//                {
//                i=i-1;
//                Sleep(100);
//                goto M1;

//                }
//        }

//ReadBuffer(B,4);

//if (Posilka()==0)     //error
//        {

//        }

//SetupComPort("S" ,10,20,10,1,100,true);
//A[0]=0x04;
//A[1]=0x06;
//A[2]=0x99;
//A[3]=0x4a;
//A[4]=0x01;
//A[5]=0x11;

//int j=10;
//M2:
//                SetupComPort("S" ,10,20,250,10,100,true);
//                WriteBuffer(A,6);
//                ReadBuffer(B,1);

//if (B[0]!=A[5])
//        {
//        if (j>=0)
//                {
//                j=j-1;
//                Sleep(100);
//                goto M2;

///                }
//        }

//ReadBuffer(B,4);



if (Posilka()==0)     //error
        {

        }
//-------------------------------
///�������� ����� �� ��������
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
//�������� ������
SetupComPort("S" ,10,20,10,1,100,true);
A[0]=0x1d;
A[1]=0x10;

for (int i=2;i<20;i++)
        {

        A[i]=32;

        }
int KolSimbol=0;
KolSimbol=NameTovar.Length();
for (int i=1;i<17;i++)
        {
        if (i<=KolSimbol)
                {
                A[i+1]=AmcCodeSimbol(NameTovar[i]);
                }
        }
//���� ������
String StrPriceTovar=FloatToStr(PriceTovar*100);
StrPriceTovar=DopStrL(StrPriceTovar,"0",8);

for (int i=1; i<9;i++)
        {
        A[17+i]=StrToInt(StrPriceTovar[i])+48;
        }


//---------------------
A[26]=0x30;
A[27]=0x31;
A[28]=0x30;
A[29]=0x30;
A[30]=KontrSumm1(A,30);


WriteBuffer(A,31);    OutputProtokol( A, 31, true);

ReadBuffer(B,1);     OutputProtokol( B, 1, false);


//
}
//-----------------------------------------------------------------------------
//����� �� ���������� ������� � ���
void amc200f::OtvetNaDobavleniePokupki(void)
{
OutputProtokol( B, 2, false);
glSaveProtocol("���������� �������");
ReadBuffer(B,21);OutputProtokol( B, 21, false);


char Sum=0;
Sum=(KontrSumm1(B,20)-0x15-0x07);
if (Sum==B[20])     //�������� ����������� �����
        {

        NumberPokupki=B[0];
        Otdel=B[1];
        TovGrp=B[2];

        //������� ��������
        if(B[3]==0){CheckOperation=Prod;}
        if(B[3]==0x01){CheckOperation=Vosvrat;}

        //����� �������

        String Sum;
        for (int i=11;i<17;i++)
                {
                if (B[i]!=0x20)
                        {
                        Sum=Sum+IntToStr((B[i]-0x30));
                        }
                }

        Sum=Sum+IntToStr((B[18]-0x30))+IntToStr((B[18]-0x30));

        SummaPokupki=(double)(StrToFloat(Sum))/100;

        EventKKM=DobavleniePokupkiEvent;
        Synchronize(GenerateExternalEvent);
        }
else
        {
        TextError="������ ��� ���������� �������! ����������� �����: "+IntToHex(Sum,2);
        EventKKM=ErrorObmenEvent;
        Synchronize(GenerateExternalEvent);
        return;
        }

if (Posilka()==0)     //error
        {

        }

//SetupComPort("S" ,100,200,10,1,100,true);
//A[0]=0x04;
//A[1]=0x06;
//A[2]=0x20;
//A[3]=0x4b;
//A[4]=0x02;
//A[5]=0x88;
//WriteBuffer(A,6);
//SetupComPort("S" ,100,200,250,10,100,true);
//ReadBuffer(B,1);
//ReadBuffer(B,4);




if (Posilka()==0)     //error
        {

        }

SetupComPort("S" ,100,200,10,10,100,true);
A[0]=0x01;
A[1]=0x0f;
A[2]=0xef;

WriteBuffer(A,3);   OutputProtokol( A, 3, true);
ReadBuffer(B,1);OutputProtokol( B, 1, false);





}

//-----------------------------------------------------------------------------
//����� �� ���������� ��������� ����� � ���
void amc200f::OtvetNaDobavlenieSvobSumm(void)
{
OutputProtokol( B, 2, false);
glSaveProtocol("���������� ��������� �����");
ReadBuffer(B,21); OutputProtokol( B, 21, false);

char Sum=0;
Sum=(KontrSumm1(B,20)-0x15-0x06);
if (Sum==B[20])     //�������� ����������� �����
        {
        CodeTovar=0;

        NumberPokupki=B[0];
        Otdel=B[1];
        TovGrp=B[2];

        //������� ��������
        if(B[3]==0){CheckOperation=Prod;}
        if(B[3]==0x01){CheckOperation=Vosvrat;}

        //����� �������

        String Sum;
        for (int i=11;i<17;i++)
                {
                if (B[i]!=0x20)
                        {
                        Sum=Sum+IntToStr((B[i]-0x30));
                        }
                }

        Sum=Sum+IntToStr((B[18]-0x30))+IntToStr((B[18]-0x30));

        SummaPokupki=(double)(StrToFloat(Sum))/100;


        CodeTovar=0; //��� ������
        ShCodeTovar=""; //����� ��� ������
        NameTovar="��������� �����";// �������� ������
        PriceTovar=SummaPokupki;//���� ������
        KolTovar=1;  //���������� ������
        
        //������� ����� ��
        //--------------------------------
         if (Posilka()==0)     //error
                {

                }

        A[0]=0x04;
        A[1]=0x06;
        A[2]=0xb8;
        A[3]=0x19;
        A[4]=0x02;
        A[5]=0x22;
        SetupComPort("S" ,100,200,200,100,100,false );
        WriteBuffer(A,6); OutputProtokol( A, 6, true);
        ClearBuffer(B);
        ReadBuffer(B,5);  OutputProtokol( B, 5, false);
        //����� ��
        int Kl=0;
        char *lpKl;
        lpKl=(char*)&Kl;
         *(lpKl)=B[3];
         *(lpKl+1)=B[2];
         NumberKl=Kl;
        //-------------------------------------------------




        EventKKM=DobavlenieSvobSummEvent;
        Synchronize(GenerateExternalEvent);
        }
else
        {
        TextError="������ ��� ���������� �������! ����������� �����: "+IntToHex(Sum,2);
        EventKKM=ErrorObmenEvent;
        Synchronize(GenerateExternalEvent);
        return;
        }

if (Posilka()==0)     //error
        {

        }

//SetupComPort("S" ,100,200,10,1,100,true);
//A[0]=0x04;
//A[1]=0x06;
//A[2]=0x20;
//A[3]=0x4b;
//A[4]=0x02;
//A[5]=0x88;
//WriteBuffer(A,6);
//ReadBuffer(B,1);
//ReadBuffer(B,4);




if (Posilka()==0)     //error
        {

        }

SetupComPort("S" ,100,200,10,10,100,true);
A[0]=0x01;
A[1]=0x0f;
A[2]=0xef;

WriteBuffer(A,3);OutputProtokol( A, 3, true);
ReadBuffer(B,1); OutputProtokol( B, 1, false);





}
//-----------------------------------------------------------------------------
//����� �� �������� ����
void amc200f::OtvetNaZakrCheka(void)
{
OutputProtokol( B, 2, false);
glSaveProtocol("�������� ����");
ReadBuffer(B,16); OutputProtokol( B, 16, false);

char Sum=0;
Sum=(KontrSumm1(B,15)-0x10-0x01);
if (Sum==B[15])    //�������� ����������� �����
        {
        //����� ����
        int Num=0;
        char *lpNum;
        lpNum=(char*)&Num;
         *(lpNum)=B[0];
         *(lpNum+1)=B[1];
         NumberCheck=Num+1;

        //��������
      //  if(B[4]==0){CheckOperation=Prod;}
      //  if(B[4]==0x01){CheckOperation=Vosvrat;}

        //������
     //   if(B[5]==0){Oplata=Nal;}
     //   if(B[5]==0x01){Oplata=BesNal;}

        //����������
        if(B[3]==0){Nachislenie=No;}
        else
                {
                if(B[3]<0x08){Nachislenie=Nadbavka;}
                if(B[3]>0x08){Nachislenie=Skidka;}
                }


        //�������
    //    int Pr=0;
   //     char *lpPr;
   //     lpPr=(char*)&Pr;
   //      *(lpPr)=B[7];
   //      Procent=Pr;

        //���������� �������
        int KolPok=0;
    ////    char *lpKolPok;
    //    lpKolPok=(char*)&KolPok;
    //     *(lpKolPok)=B[9];
         KolPokupok=KolPok;

        //����� ��� ����������
                //����� �������
        unsigned char ucSum;
        String Sum;

        for( int i=7;i<13;i++)
                {
                ucSum=B[i];
                Sum=Sum+IntToHex(ucSum,2);
                }

        ucSum=B[13];
        String S=IntToHex(ucSum,2);
        Sum=Sum+S[1];

        ucSum=B[14];
        Sum=Sum+IntToHex(ucSum,2);

        RealSummaCheck=SummaCheck=(StrToFloat(Sum))/100;


        }
else
        {
        TextError="������ ��� �������� ����! ����������� �����: "+IntToHex(Sum,2);
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

WriteBuffer(A,3);OutputProtokol( A, 3,true);
ReadBuffer(B,1);OutputProtokol( B, 1, false);

if (Posilka()==0)     //error
        {

        }

EventKKM=ZakrChekaEvent;
Synchronize(GenerateExternalEvent);

}
//------------------------------------------------------------------------------
//����� �� ����� ����
void amc200f::OtvetNaSbrosCheka(void)
{
OutputProtokol( B, 2, false);
glSaveProtocol("����� ����");
ReadBuffer(B,16); OutputProtokol( B, 16, false);

char Sum=0;
Sum=(KontrSumm1(B,15)-0x10-0x05);
if (Sum==B[15])    //�������� ����������� �����
        {
        //����� ����
        int Num=0;
        char *lpNum;
        lpNum=(char*)&Num;
         *(lpNum)=B[0];
         *(lpNum+1)=B[1];
         NumberCheck=Num;

        //����� ��
        int Kl=0;
    //    char *lpKl;
    //    lpKl=(char*)&Kl;
    //     *(lpKl)=B[2];
   //      *(lpKl+1)=B[3];
         NumberKl=Kl;


        //����������


        //�������

         Procent=0;

        //���������� �������

         KolPokupok=0;

        //����� ��� ����������
                //����� �������

         SummaCheck=0;
        //����� � ������������

         RealSummaCheck=0;


        }
else
        {
        TextError="������ ��� ������ ����! ����������� �����: "+IntToHex(Sum,2);
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

WriteBuffer(A,3); OutputProtokol( A, 3, true);
ReadBuffer(B,1); OutputProtokol( B, 1, false);


if (Posilka()==0)     //error
        {

        }

EventKKM=SbrosChekaEvent;
Synchronize(GenerateExternalEvent);
}
//----------------------------------------------------------------------------
void amc200f::ObrabUnknownEvent(void)
{
EventKKM=UnknownEvent;
OutputProtokol( B, 50, false);
glSaveProtocol("����������� �������");
Synchronize(GenerateExternalEvent);
}
//-----------------------------------------------------------------------------
//������������ ������� �������
void __fastcall amc200f::GenerateExternalEvent(void)
{
FormGl->ObrabExternalEvent();
}
//----------------------------------------------------------------------------
