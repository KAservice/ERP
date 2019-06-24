//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UTComPort.h"



#pragma package(smart_init)
extern void __fastcall ReadShtrihCodEvent(void);
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TComPort::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TComPort::TComPort(bool CreateSuspended)
        : TThread(CreateSuspended)
{

InBuf=new unsigned char[20];
InPaket=new unsigned char[20];
}
//---------------------------------------------------------------------------
void __fastcall TComPort::Execute()
{
OVERLAPPED OVR;
unsigned long real_byte;
unsigned long OVRByte;
DWORD Mask, Signaled;
int input_byte;


COMSTAT SostPorta;
SostPorta.cbInQue=0;
unsigned long  Err;


memset(&OVR,0,sizeof(OVR));

OVR.hEvent=CreateEvent(NULL,true,false,NULL);


if (SetCommMask(ComHandle,EV_RXCHAR)==0)
        {
       // StrErr="ошибка установки маски   ";

		}

for (int i=0;i<20;i++){InBuf[i]=0;}
PurgeComm(ComHandle,PURGE_TXCLEAR|PURGE_RXCLEAR);
KolByteInPaket=0;
for (int i=0;i<20;i++){InPaket[i]=0;}
while (!Terminated)
        {
        WaitCommEvent(ComHandle,&Mask,&OVR);
        Signaled=WaitForSingleObject(OVR.hEvent,INFINITE);

        if (Signaled!=WAIT_OBJECT_0){continue;}

		if (ClearCommError(ComHandle,&Err,&SostPorta)==true){input_byte=SostPorta.cbInQue;}
		if (input_byte<=0){continue;}

		for (int i=0;i<20;i++){InBuf[i]=0;}

		if (input_byte>20)
			{
			input_byte=20;
			}

		ReadFile(ComHandle,InBuf,input_byte,&real_byte,&OVR);
		GetOverlappedResult(ComHandle,&OVR,&OVRByte,false);
		KolByteInBuf=OVRByte;


        for (int i=0;i<KolByteInBuf;i++)
                {
				if (InBuf[i]==0x0d)
                        {
						Synchronize(GenerateEvent);
						PurgeComm(ComHandle,PURGE_TXCLEAR|PURGE_RXCLEAR);
                        }
                else
						{
						if (InBuf[i]=='0' ||  InBuf[i]=='1' || InBuf[i]=='2' ||	 InBuf[i]=='3' || InBuf[i]=='4' ||
								InBuf[i]=='5' || InBuf[i]=='6' ||  InBuf[i]=='7' ||  InBuf[i]=='8' || InBuf[i]=='9' )
							{
							if (KolByteInPaket < 13)
								{
								InPaket[KolByteInPaket]=InBuf[i];
								KolByteInPaket=KolByteInPaket+1;
								}
							else
								{
//								Synchronize(GenerateEvent);
//								PurgeComm(ComHandle,PURGE_TXCLEAR|PURGE_RXCLEAR);
								}
							}
                        }
				}


		}
}
//---------------------------------------------------------------------------
void __fastcall TComPort::GenerateEvent()
{
InPaket[KolByteInPaket+1]=0x0;
ReadShtrihCodEvent();
PurgeComm(ComHandle,PURGE_TXCLEAR|PURGE_RXCLEAR);
for (int j=0;j<20;j++)
        {
        InPaket[j]=0;
        }    //очищ€ем массив пакета
KolByteInPaket=0;
}
//----------------------------------------------------------------------------
bool TComPort::OpenPort(int number_port, char * baud_rate)
{
bool result=false;
AnsiString  name_port="COM"+IntToStr(number_port);
ComHandle=CreateFile(name_port.c_str(),GENERIC_READ|GENERIC_WRITE,0,NULL,
                                OPEN_EXISTING,FILE_FLAG_OVERLAPPED,NULL);

//выделим пам€ть дл€ DCB
DCB *dcb;
dcb=(DCB*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,sizeof(DCB));
dcb->DCBlength=sizeof(DCB);
COMMTIMEOUTS *CTO;
CTO=new COMMTIMEOUTS;

AnsiString Str="baud="+AnsiString(baud_rate)+" data=8 stop=1 parity=N";

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
result=true;
return result;
}
//----------------------------------------------------------------------------
bool TComPort::ClosePort(void)
{
bool result=true;
CloseHandle(ComHandle);
return result;
}
//----------------------------------------------------------------------------
