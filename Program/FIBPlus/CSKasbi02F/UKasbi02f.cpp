//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "UKasbi02f.h"
#include "MainForm.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void glSaveProtocol(String str);


//-------------------------------------------------------------------------
__fastcall TKkm::TKkm(bool CreateSuspended)
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
KolPaketError=0;
}
//----------------------------------------------------------------------------
//������� ����
bool  TKkm::OpenPort()
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
//--------------------------------------------------------------------------
void TKkm::OutputProtokol( unsigned char * buf, int len, bool wr)
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
//�������  ����
bool TKkm::ClosePort()
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
char __fastcall TKkm::KontrSumm1(unsigned char *Buffer,int Kol)     //��� ���� ������� � 1
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
char __fastcall TKkm::KontrSumm2(unsigned char *Buffer,int Kol)
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
String TKkm::DopStrL(String Str, String Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Symbol+Str;
        }
return Str;
}
//-----------------------------------------------------------------------------
// �������� ��� �������
unsigned char TKkm::KasbiCodeSimbol(String StringSimbol)
{

char Res=32;

if (StringSimbol=='0'){Res=0x30;}
if (StringSimbol=='1'){Res=0x31;}
if (StringSimbol=='2'){Res=0x32;}
if (StringSimbol=='3'){Res=0x33;}
if (StringSimbol=='4'){Res=0x34;}
if (StringSimbol=='5'){Res=0x35;}
if (StringSimbol=='6'){Res=0x36;}
if (StringSimbol=='7'){Res=0x37;}
if (StringSimbol=='8'){Res=0x38;}
if (StringSimbol=='9'){Res=0x39;}

if (StringSimbol==' '){Res=0x20;}
if (StringSimbol=='!'){Res=0x21;}
if (StringSimbol=='"'){Res=0x22;}
if (StringSimbol=='#'){Res=0x23;}
if (StringSimbol=='$'){Res=0x24;}
if (StringSimbol=='%'){Res=0x25;}
if (StringSimbol=='&'){Res=0x28;}
//if (StringSimbol=='''){Res=39;}
//if (StringSimbol=='('){Res=40;}
//if (StringSimbol==')'){Res=41;}
if (StringSimbol=='*'){Res=0x2a;}
if (StringSimbol=='+'){Res=0x2b;}
if (StringSimbol==','){Res=0x2c;}
if (StringSimbol=='-'){Res=0x2d;}
if (StringSimbol=='.'){Res=0x2e;}
if (StringSimbol=='/'){Res=0x2f;}

if (StringSimbol=='{'){Res=0x7b;}
if (StringSimbol=='|'){Res=0x7c;}
if (StringSimbol=='}'){Res=0x7d;}
if (StringSimbol=='~'){Res=0x7e;}
if (StringSimbol=='*'){Res=0x7f;}

if (StringSimbol=='�'){Res=0x80;}
if (StringSimbol=='�'){Res=0x81;}
if (StringSimbol=='�'){Res=0x82;}
if (StringSimbol=='�'){Res=0x83;}
if (StringSimbol=='�'){Res=0x84;}
if (StringSimbol=='�'){Res=0x85;}
if (StringSimbol=='�'){Res=0x86;}
if (StringSimbol=='�'){Res=0x87;}
if (StringSimbol=='�'){Res=0x88;}
if (StringSimbol=='�'){Res=0x89;}
if (StringSimbol=='�'){Res=0x8a;}
if (StringSimbol=='�'){Res=0x8b;}
if (StringSimbol=='�'){Res=0x8c;}
if (StringSimbol=='�'){Res=0x8d;}
if (StringSimbol=='�'){Res=0x8e;}
if (StringSimbol=='�'){Res=0x8f;}
if (StringSimbol=='�'){Res=0x90;}
if (StringSimbol=='�'){Res=0x91;}
if (StringSimbol=='�'){Res=0x92;}
if (StringSimbol=='�'){Res=0x93;}
if (StringSimbol=='�'){Res=0x94;}
if (StringSimbol=='�'){Res=0x95;}
if (StringSimbol=='�'){Res=0x96;}
if (StringSimbol=='�'){Res=0x97;}
if (StringSimbol=='�'){Res=0x98;}
if (StringSimbol=='�'){Res=0x99;}
if (StringSimbol=='�'){Res=0x9a;}
if (StringSimbol=='�'){Res=0x9b;}
if (StringSimbol=='�'){Res=0x9c;}
if (StringSimbol=='�'){Res=0x9d;}
if (StringSimbol=='�'){Res=0x9e;}
if (StringSimbol=='�'){Res=0x9f;}

if (StringSimbol=='�'){Res=0xa0;}
if (StringSimbol=='�'){Res=0xa1;}
if (StringSimbol=='�'){Res=0xa2;}
if (StringSimbol=='�'){Res=0xa3;}
if (StringSimbol=='�'){Res=0xa4;}
if (StringSimbol=='�'){Res=0xa5;}
if (StringSimbol=='�'){Res=0xa6;}
if (StringSimbol=='�'){Res=0xa7;}
if (StringSimbol=='�'){Res=0xa8;}
if (StringSimbol=='�'){Res=0xa9;}
if (StringSimbol=='�'){Res=0xaa;}
if (StringSimbol=='�'){Res=0xab;}
if (StringSimbol=='�'){Res=0xac;}
if (StringSimbol=='�'){Res=0xad;}
if (StringSimbol=='�'){Res=0xae;}
if (StringSimbol=='�'){Res=0xaf;}
if (StringSimbol=='�'){Res=0xe0;}
if (StringSimbol=='�'){Res=0xe1;}
if (StringSimbol=='�'){Res=0xe2;}
if (StringSimbol=='�'){Res=0xe3;}
if (StringSimbol=='�'){Res=0xe4;}
if (StringSimbol=='�'){Res=0xe5;}
if (StringSimbol=='�'){Res=0xe6;}
if (StringSimbol=='�'){Res=0xe7;}
if (StringSimbol=='�'){Res=0xe8;}
if (StringSimbol=='�'){Res=0xe9;}
if (StringSimbol=='�'){Res=0xea;}
if (StringSimbol=='�'){Res=0xeb;}
if (StringSimbol=='�'){Res=0xec;}
if (StringSimbol=='�'){Res=0xed;}
if (StringSimbol=='�'){Res=0xee;}
if (StringSimbol=='�'){Res=0xef;}

return  Res;
}

//-----------------------------------------------------------------------------
//��������� ���� ��� �����/������
void TKkm::SetupComPort(String Parity ,int RI,int RM, int RC, int WM, int WC, bool ClearBuffer)
{

String Str="baud=9600 data=8 stop=1 parity="+Parity;

BuildCommDCB( Str.c_str(),dcb);
dcb->XoffLim=512;
dcb->XonLim=2048;
//dcb->fRtsControl=RTS_CONTROL_HANDSHAKE;
//dcb->fTXContinueOnXoff=true;
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
void TKkm::ClearBuffer(unsigned char * B)
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

void __fastcall TKkm::WriteBuffer(unsigned char  *B, int L)

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
void __fastcall TKkm::ReadBuffer(unsigned char *B, int L)
{
for (int i=0;i<L;i++)
        {
        B[i]=0;

        }

OVERLAPPED stOVR;
memset(&stOVR,0,sizeof(stOVR));

ReadFileEx(ComHandle,B,L,&stOVR,ENDRead) ;
SleepEx( INFINITE, true);

}
//-----------------------------------------------------------------------------
//���������� ���
int TKkm::ConnectKKM(void)
{
int Res=0;

SetupComPort("N",1000,20,10,2000,1,true);

A[0]=0x2d;
A[1]=0x00;
A[2]=0x00;
A[3]=0x01;
A[4]=0x00;
A[5]=0x00;
A[6]=charSetNumber1;
A[7]=charSetNumber2;
A[8]=charSetNumber3;
A[9]=charSetNumber4;
A[10]=KontrSumm1(A,10);

WriteBuffer(A,11); //OutputProtokol( A, 11, true);
ReadBuffer(B,11); //OutputProtokol( B, 11, false);



if(B[10]==KontrSumm1(B,10))
        {
        ReadBuffer(B,2); //OutputProtokol( B, 2, false);
        Res=1;
        }
else
        {
         Res=0;
        }

return Res;


}

//-----------------------------------------------------------------------------
//��������� ���
int TKkm::DisconnectKKM(void)
{
int Res=1;

ConnectkKKM=false;
return Res;
}
//---------------------------------------------------------------------------
void __fastcall TKkm::Execute()
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
                        
                String strSetNumber=IntToStr(intSetNumber) ;
                charSetNumber1=StrToInt(strSetNumber[1])*16+StrToInt(strSetNumber[2]);
                charSetNumber2=StrToInt(strSetNumber[3])*16+StrToInt(strSetNumber[4]);
                charSetNumber3=StrToInt(strSetNumber[5])*16+StrToInt(strSetNumber[6]);
                charSetNumber4=StrToInt(strSetNumber[7])*16+StrToInt(strSetNumber[8]);

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
                        ClearBuffer(B);
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
//�������� ���� ���
void  TKkm::OprositPort()
{
SetupComPort("N",1000,20,10,2000,1,true);

A[0]=0x2d;
A[1]=0x00;
A[2]=0x00;
A[3]=0x01;
A[4]=0x00;
A[5]=0x00;
A[6]=charSetNumber1;
A[7]=charSetNumber2;
A[8]=charSetNumber3;
A[9]=charSetNumber4;
A[10]=KontrSumm1(A,10);

WriteBuffer(A,11);
ReadBuffer(B,11);

if(B[10]!=KontrSumm1(B,10))   //������� ������������ �����
        {
        KolPaketError++;
        if (KolPaketError>150)
                {
                glSaveProtocol("������� 150 ������������ �������");
                OutputProtokol( B,11, false);
                EstSvazKKM=false;
                ConnectkKKM=false;
                EventKKM=IzmStatusKKMEvent;
                TextError="��� �� ��������!������� "+IntToHex(B[0],2) ;
                Synchronize(GenerateExternalEvent);
                KolPaketError=0;
                }
        return;
        }

EstSvazKKM=true;

bool Obrab=false;


if ((B[0]==0x27))     //������ �� ����
        {
        OtvetNaZaprosPoCodu();
        Obrab=true;
        }

if ((B[0]==0x28))     //������ �� ����� ����
        {
        OtvetNaZaprosPoShtrihCodu();
        Obrab=true;
        }


if ((B[0]==0x3c))   //���������� ������� � ���
        {
        OtvetNaDobavleniePokupki();
        Obrab=true;
        }

//if ((B[0]==0x15) && (B[1]==0x06))   //��������� ��������� ����� � ���
//        {
//        OtvetNaDobavlenieSvobSumm();
///        Obrab=true;
//        }


if ((B[0]==0x3f) )    //�������� ����
        {
        OtvetNaZakrCheka();
        Obrab=true;
        }

if (B[0]==0x42)    //����� ����
        {
       OtvetNaSbrosCheka();
       Obrab=true;
        }

if ((B[0]==0x41))    //�������� �������
        {
        OtvetNaUdaleniePokupki();
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
void  TKkm::OtvetNaScanPaket(void)
{

ReadBuffer(B,2);
}
//-----------------------------------------------------------------------------
// //����� �� ������ �� ����
void TKkm::OtvetNaZaprosPoCodu(void)
{

if (B[4]==0 && B[5]==0) //���� �����
        {
        ReadBuffer(B,2);
        return;
        }
        
glSaveProtocol("������ �� ����");
OutputProtokol( B,11, false);

char Sum=0;
Sum=(KontrSumm1(B,10));
if (Sum!=B[10])     //�������� ����������� �����
        {
        TextError="������������ ������ �� ����! ����������� �����: "+IntToHex(Sum,2);
        glSaveProtocol(TextError);
        OutputProtokol( B,11, false);
        EventKKM=ErrorObmenEvent;
        Synchronize(GenerateExternalEvent);
        return;
        }

        //��� ������
        int Cod=0;
        char *lpCod;
        lpCod=(char*)&Cod;
         *(lpCod)=B[5];
         *(lpCod+1)=B[4];
         CodeTovar=Cod;

         //������� ��������� ������

        NameTovar="";// �������� ������
        PriceTovar=0;//���� ������
        KolTovar=1;  //���������� ������


        EventKKM=ZaprosPoCoduEvent;
        Synchronize(GenerateExternalEvent);


//-------------------------------
///�������� ����� �� ��������
if (EnableOtvet==false)
        {
        SetupComPort("N",1000,20,10,2000,1,true);

        A[0]=0x14;
        A[1]=0x01;
        A[2]=0x00;
        A[3]=0x00;
        A[4]=0x00;
        A[5]=0x00;
        A[6]=charSetNumber1;
        A[7]=charSetNumber2;
        A[8]=charSetNumber3;
        A[9]=charSetNumber4;
        A[10]=KontrSumm1(A,10);

        WriteBuffer(A,11); OutputProtokol( A, 11, true);
        ReadBuffer(B,11);  OutputProtokol( B, 11, false);
        return;
        }



        SetupComPort("N",1000,20,10,2000,1,true);

        A[0]=0x14;
        A[1]=0x01;
        A[2]=0x00;
        A[3]=0x25;
//��� ������
        A[4]=B[4];
        A[5]=B[5];
        A[6]=charSetNumber1;
        A[7]=charSetNumber2;
        A[8]=charSetNumber3;
        A[9]=charSetNumber4;
        A[10]=KontrSumm1(A,10);

        WriteBuffer(A,11); OutputProtokol( A, 11, true);

//--------------------------------
//  ������������ ������ 15 ����
for (int i=0;i<15;i++)
        {
        A[i]=0x20; //������ �������
        }

int KolSimbol=0;
KolSimbol=NameTovar.Length();
for (int i=0;i<15;i++)
        {
        if (i<KolSimbol)
                {
                A[i]=KasbiCodeSimbol(NameTovar[i+1]);
                }
        }

//����� ��� ������
ShCodeTovar=DopStrL(ShCodeTovar, "0", 13);
for (int i=15;i<28;i++)
        {
        A[i]=StrToInt(ShCodeTovar[i-14]);
        }

//���� ������
int intPriceTovar=PriceTovar*100;
String StrPriceTovar=DopStrL(IntToStr(intPriceTovar),"0",7);

for (int i=28; i<35;i++)
        {
        A[i]=StrToInt(StrPriceTovar[i-27]);
        }
//�����
A[35]=0x01;

//������� �������
A[36]=0x01;
A[37]=KontrSumm2(A,37);


WriteBuffer(A,38);    OutputProtokol( A, 38, true);
ReadBuffer(B,11);     OutputProtokol( B, 11, false);




//
}

//-----------------------------------------------------------------------------
//����� �� ������ �� ����� ����
void TKkm::OtvetNaZaprosPoShtrihCodu(void)
{
glSaveProtocol("������ �� ����� ����");
OutputProtokol( B,11, false);

int kolByte=B[3];
ReadBuffer(B,kolByte+1);  OutputProtokol( B, kolByte+1, false);
char Sum=0;
Sum=(KontrSumm2(B,kolByte));
if (Sum!=B[kolByte])     //�������� ����������� �����
        {
        TextError="������������ ������ �� ����� ����! ����������� �����: "+IntToHex(Sum,2);
        glSaveProtocol(TextError);
        EventKKM=ErrorObmenEvent;
        Synchronize(GenerateExternalEvent);
        return;
        }


        
        //����� ��� ������
        ShCodeTovar="";
        for (int i=2;i<kolByte;i++)
        {
        if (B[i]!=0x20)
                {
                ShCodeTovar=ShCodeTovar+FloatToStr(StrToFloat(IntToHex(B[i]-0x30,2)));
                }
        }

         //������� ��������� ������

        NameTovar="";// �������� ������
        PriceTovar=0;//���� ������
        KolTovar=1;  //���������� ������


        EventKKM=ZaprosPoShtrihCoduEvent;
        Synchronize(GenerateExternalEvent);


//-------------------------------
///�������� ����� �� ��������
if (EnableOtvet==false)
        {
        SetupComPort("N",1000,20,10,2000,1,true);

        A[0]=0x14;
        A[1]=0x01;
        A[2]=0x00;
        A[3]=0x00;
        A[4]=0x00;
        A[5]=0x00;
        A[6]=charSetNumber1;
        A[7]=charSetNumber2;
        A[8]=charSetNumber3;
        A[9]=charSetNumber4;
        A[10]=KontrSumm1(A,10);

        WriteBuffer(A,11);     OutputProtokol( A, 11, true);
        ReadBuffer(B,11);
        return;
        }



        SetupComPort("N",1000,20,10,2000,1,true);

        A[0]=0x14;
        A[1]=0x01;
        A[2]=0x00;
        A[3]=0x25;
//��� ������
        A[4]=B[4];
        A[5]=B[5];
        A[6]=charSetNumber1;
        A[7]=charSetNumber2;
        A[8]=charSetNumber3;
        A[9]=charSetNumber4;
        A[10]=KontrSumm1(A,10);

        WriteBuffer(A,11);    OutputProtokol( A, 11, true);

//--------------------------------
//  ������������ ������ 15 ����
for (int i=0;i<15;i++)
        {
        A[i]=0x20; //������ �������
        }

int KolSimbol=0;
KolSimbol=NameTovar.Length();
for (int i=0;i<15;i++)
        {
        if (i<KolSimbol)
                {
                A[i]=KasbiCodeSimbol(NameTovar[i+1]);
                }
        }

//����� ��� ������
ShCodeTovar=DopStrL(ShCodeTovar, "0", 13);
for (int i=15;i<28;i++)
        {
        A[i]=StrToInt(ShCodeTovar[i-14]);
        }

//���� ������
int intPriceTovar=PriceTovar*100;
String StrPriceTovar=DopStrL(IntToStr(intPriceTovar),"0",7);

for (int i=28; i<35;i++)
        {
        A[i]=StrToInt(StrPriceTovar[i-27]);
        }
//�����
A[35]=0x01;

//������� �������
A[36]=0x01;
A[37]=KontrSumm2(A,37);


WriteBuffer(A,38);      OutputProtokol( A, 38, true);
ReadBuffer(B,11);       OutputProtokol( B,11, false);





//
}
//-----------------------------------------------------------------------------
//����� �� ���������� ������� � ���
void TKkm::OtvetNaDobavleniePokupki(void)
{
glSaveProtocol("���������� �������");
OutputProtokol( B,11, false);
ReadBuffer(B,20);  OutputProtokol( B,20, false);

char Sum=0;
Sum=KontrSumm2(B,19);
if (Sum!=B[19])     //�������� ����������� �����
        {
        TextError="������ ��� ���������� �������! ����������� �����: "+IntToHex(Sum,2);
        glSaveProtocol(TextError);
        EventKKM=ErrorObmenEvent;
        Synchronize(GenerateExternalEvent);
        return;
        }
        //����������
        int intKol=0;
        *(char*)&intKol=B[4];
        *(((char*)&intKol)+1)=B[3];
        KolTovar=intKol;
        KolTovar=KolTovar/1000;

        //����� ��� ������
        ShCodeTovar="";
        for (int i=5;i<18;i++)
        {
        if (B[i]!=0x20)
                {
                ShCodeTovar=ShCodeTovar+IntToStr(StrToInt(IntToHex(B[i],2)));
                }
        }
 //*****************************************************
        EventKKM=DobavleniePokupkiEvent;
        Synchronize(GenerateExternalEvent);
 //******************************************************

        A[0]=0x3d;
        A[1]=0x00;
        A[2]=0x00;
        A[3]=0x00;
//��� ������
        //CodeTovar=1;
        int intCod=CodeTovar;
        A[5]=*(char*)&intCod;
        A[4]=*(((char*)&intCod)+1);
        A[6]=charSetNumber1;
        A[7]=charSetNumber2;
        A[8]=charSetNumber3;
        A[9]=charSetNumber4;
        A[10]=KontrSumm1(A,10);

        WriteBuffer(A,11);    OutputProtokol( A, 11, true);
        ReadBuffer(B,11);     OutputProtokol( B,11, false);

}

//-----------------------------------------------------------------------------
//����� �� ���������� ��������� ����� � ���
void TKkm::OtvetNaDobavlenieSvobSumm(void)
{
glSaveProtocol("���������� ��������� �����");
OutputProtokol( B,11, false);
ReadBuffer(B,21);    OutputProtokol( B,21, false);

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






SetupComPort("S" ,100,200,10,10,100,true);
A[0]=0x01;
A[1]=0x0f;
A[2]=0xef;

WriteBuffer(A,3);       OutputProtokol( A, 3, true);
ReadBuffer(B,1);        OutputProtokol( B,1, false);




}
//-----------------------------------------------------------------------------
//����� �� �������� ����
void TKkm::OtvetNaZakrCheka(void)
{
glSaveProtocol("�������� ����");
OutputProtokol( B,11, false);

         //����� ����
        int intNum=0;
        *(((char*)&intNum)+1)=B[4];
        *(char*)&intNum=B[5];
        NumberCheck=intNum;

ReadBuffer(B,18);    OutputProtokol( B,18, false);

char Sum=0;
Sum=(KontrSumm2(B,17));
if (Sum!=B[17])    //�������� ����������� �����
        {
        TextError="������ ��� �������� ����! ����������� �����: "+IntToHex(Sum,2);
        glSaveProtocol(TextError);
        EventKKM=ErrorObmenEvent;
        Synchronize(GenerateExternalEvent);
        return;
        }

        //����� �����
        int intNumKL=0;
        *(((char*)&intNumKL)+1)=B[0];
        *(char*)&intNumKL=B[1];
        NumberKl=intNumKL+1;

        //��� ������


        //����� ����
        String SumCheck;
        for (int i=10;i<17;i++)
                {

                SumCheck=SumCheck+IntToStr((B[i]));

                }
        RealSummaCheck=StrToFloat(SumCheck)/100;


        A[0]=0x3f;
        A[1]=0x00;
        A[2]=0x00;
        A[3]=0x00;

        //����� ����
        intNum=NumberCheck;
        A[4]=*(((char*)&intNum)+1);
        A[5]=*(char*)&intNum;

        A[6]=charSetNumber1;
        A[7]=charSetNumber2;
        A[8]=charSetNumber3;
        A[9]=charSetNumber4;
        A[10]=KontrSumm1(A,10);

        WriteBuffer(A,11);     OutputProtokol( A, 11, true);

        ReadBuffer(B,11);     OutputProtokol( B,11, false);


        int KolPovt=200;

while( KolPovt>0 && KontrSumm1(B,10)!=B[10])
        {
//if (KontrSumm1(B,10)!=B[10])    //�������� ����������� �����
//        {
        SetupComPort("N",1000,20,0,2000,0,true);
        WriteBuffer(A,11);     OutputProtokol( A, 11, true);
        ReadBuffer(B,11);     OutputProtokol( B,11, false);
        //return;
        KolPovt=KolPovt-1;
        }
if (KolPovt==0) {return;}


EventKKM=ZakrChekaEvent;
Synchronize(GenerateExternalEvent);



}
//------------------------------------------------------------------------------
//����� �� ����� ����
void TKkm::OtvetNaUdaleniePokupki(void)
{
glSaveProtocol("�������� �������");
OutputProtokol( B,11, false);
int kolByte=B[3];
ReadBuffer(B,kolByte+1);     OutputProtokol( B,kolByte+1, false);
char Sum=0;
Sum=(KontrSumm2(B,kolByte));
if (Sum!=B[kolByte])     //�������� ����������� �����
        {
        TextError="������������ ����� ��� �������� �������! ����������� �����: "+IntToHex(Sum,2);
        glSaveProtocol(TextError);
        EventKKM=ErrorObmenEvent;
        Synchronize(GenerateExternalEvent);
        return;
        }

        A[0]=0x3e;
        A[1]=0x00;
        A[2]=0x00;
        A[3]=0x00;
        A[4]=0x00;
        A[5]=0x00;

        A[6]=charSetNumber1;
        A[7]=charSetNumber2;
        A[8]=charSetNumber3;
        A[9]=charSetNumber4;
        A[10]=KontrSumm1(A,10);

        WriteBuffer(A,11);     OutputProtokol( A, 11, true);

        ReadBuffer(B,11);     OutputProtokol( B,11, false);

        int j=5;
        while (KontrSumm1(B,10)!=B[10] && j>0 )
                {
                SetupComPort("N",1000,20,10,2000,1,true);
                WriteBuffer(A,11);     OutputProtokol( A, 11, true);
                ReadBuffer(B,11);     OutputProtokol( B,11, false);
                j--;
                }
if (j>0)
        {
        EventKKM=UdaleniePokupkiEvent;
        Synchronize(GenerateExternalEvent);
        }

}
//----------------------------------------------------------------------------
void TKkm::OtvetNaSbrosCheka(void)//����� �� ����� ����
{
glSaveProtocol("����� ����");
OutputProtokol( B,11, false);

        A[0]=0x3e;
        A[1]=0x00;
        A[2]=0x00;
        A[3]=0x00;
        A[4]=0x00;
        A[5]=0x00;

        A[6]=charSetNumber1;
        A[7]=charSetNumber2;
        A[8]=charSetNumber3;
        A[9]=charSetNumber4;
        A[10]=KontrSumm1(A,10);

        WriteBuffer(A,11);    OutputProtokol( A, 11, true);

        ReadBuffer(B,11);     OutputProtokol( B,11, false);

if (KontrSumm1(B,10)!=B[10])    //�������� ����������� �����
        {
        TextError="������ ��� ������ ����! ";
        glSaveProtocol(TextError);
        return;
        }

EventKKM=SbrosChekaEvent;
Synchronize(GenerateExternalEvent);

}
//----------------------------------------------------------------------------
void TKkm::ObrabUnknownEvent(void)
{
glSaveProtocol("����������� �������");
TextError="";
for (int i=0;i<50;i++)
        {
        TextError=TextError+IntToHex(B[i],2);
        glSaveProtocol(TextError);
        }
EventKKM=UnknownEvent;
Synchronize(GenerateExternalEvent);
}
//-----------------------------------------------------------------------------
//������������ ������� �������
void __fastcall TKkm::GenerateExternalEvent(void)
{
MainForm->ObrabExternalEvent();
}
//----------------------------------------------------------------------------
