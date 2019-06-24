//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UScaleVP.h"
#include "UMainForm.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TScaleVP::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TScaleVP::TScaleVP(bool CreateSuspended)
	: TThread(CreateSuspended)
{

//параметры товара
NumberTovar=0;  		//номер товара 1-999
VidTovara=0;    		//вид товара 0,1
GroupCode=0;          //групповой код 0-99
CodeTovar=0;			//код товара 0-999999
Price=0;           //цена
Tara=0;            //тара
	//Date SrokGodn;          //срок годности
NameTovar="";   //наименование

	//формат этикетки
	VidLabel="";
	HeightLabel=0;

	//параметры этикетки
	NumberOtdelVes=0;
	NumberOtdelSht=0;
	TypeBarCode=0;
	CodeSert="";
	PrintDate=false;
	PrintPrice=false;
	PrintSert=false;
	ReklamaStr1="";
	ReklamaStr2="";
	NeZaprogStr1="";
	NeZaprogStr2="";

	Operation=No;

Run=false;
DopStrings=new TStringList();
KolDopString=0;

//выделим память для DCB
stDCB=(DCB*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,sizeof(DCB));
stDCB->DCBlength=sizeof(DCB);
stCommtimeouts=new COMMTIMEOUTS;
//memset(stOVR,0,sizeof(*stOVR));

Buf_1=new char[1];
Buf_3=new char[3];

Error=false;
TextError="Ошибок нет";
}
//---------------------------------------------------------------------------
__fastcall TScaleVP::~TScaleVP(void)
{
delete DopStrings;

delete stCommtimeouts;
//delete stDCB;
//delete stOVR;

delete Buf_1;
delete Buf_3;
}
//---------------------------------------------------------------------------
void __fastcall TScaleVP::Execute()
{
while (!Terminated)
	{
	if (Run==true)
		{
		switch (Operation)
			{
			case ZagrTovar_Operation :  //загрузка товаров
				{

				//загружаем товар в весы
				if (AddTovarInScale()==true)
					{
					if (AddDopStringInScale()==true)
						{

						}
					else
						{
						Error=true;
						TextError="Ошибка при загрузке дополнительных строктовара "+NameTovar+": "+TextError;
						}
					}
				else
					{
					Error=true;
					TextError="Ошибка при загрузке товара "+NameTovar+": "+TextError;
					}

				break;
				}
			case SetFormatLabel_Operation :  //запись формата этикетки
				{
				if  (SetFormatLabel()!=true)
					{
					Error=true;
					}

				break;
				}

			case SetParameterLabel_Operation :  //запись параметров этикетки
				{
				if (SetParameteLabel()!=true)
					{
					Error=true;
					}
				break;
				}
			}

		Synchronize(GenerateExternalEvent);
		}
	else
		{
		Sleep(1000);
		}


	}
}
//---------------------------------------------------------------------------
void __fastcall TScaleVP::GenerateExternalEvent(void)
{
MainForm->ObrabExternalEvent();
//устанавливаем новые параметры товара
//и снова повторяем процедуру загрузки в весы
}
//---------------------------------------------------------------------------
bool TScaleVP::AddTovarInScale(void)
{
bool result=false;


SetupComPort("M",50,0,2000,0,1000,false);
Buf_1[0]=SetNumber;
WriteBuffer(Buf_1,1);
ReadBuffer(Buf_1,1);

if (Buf_1[0]!=0x77)
	{
	result=false;
	TextError="Весы не отвечают на команду синхронизации!";
	return result;
	}

SetupComPort("S",50,0,2000,0,1000,false);
Buf_1[0]=0x05;
WriteBuffer(Buf_1,1);
ReadBuffer(Buf_1,1);

if (Buf_1[0]!=0x01)
	{
	result=false;
	TextError="Весы не готовы к приему данных!";
	return result;
	}


Buf_3[0]=*((char*)&NumberTovar);
Buf_3[1]=*((char*)&NumberTovar+1);
Buf_3[2]=0x21;

WriteBuffer(Buf_3,3);
Buf_1[0]=0x00;
ReadBuffer(Buf_1,1);

if (Buf_1[0]!=0x01)
	{
	result=false;
	TextError="Ошибка при передаче номера товара!";
	return result;
	}

//передаем товар
char * BufData=new char[61];
BufData[0]=VidTovara;
BufData[1]=GroupCode;
BufData[2]=*((char*)(&CodeTovar));
BufData[3]=*((char*)(&CodeTovar)+1);
BufData[4]=*((char*)(&CodeTovar)+2);

int price=Price*100;
BufData[5]=*((char*)(&price));
BufData[6]=*((char*)(&price)+1);
BufData[7]=*((char*)(&price)+2);
//тара
BufData[8]=0;
BufData[9]=0;
//срок годности
BufData[10]=0;
BufData[11]=0;
BufData[12]=0;

if (SrokGodn > EncodeDate(2000,1,1))
	{
	unsigned short Year;
	unsigned short Month;
	unsigned short Day;
	SrokGodn.DecodeDate(&Year,&Month,&Day);
	if (Year>2000)
		{
		BufData[10]=Year-2000;
		}
	else
		{
		BufData[10]=Year;
		}

	BufData[11]=Month;
	BufData[12]=Day; 
	}
//название товара 24 символа  2 строки

	for (int i=13;i<62;i++)
		{
		BufData[i]=0x20;
		}
//перенос по словам
//*********************************************************************

	TStringList * strings=new TStringList();

	NameTovar=WrapText(NameTovar,24);
	strings->Text=NameTovar;

	for (int i=0;i<strings->Count && i<2;i++)
		{
		AnsiString print_str=strings->Strings[i];
		int kol_simbol=0;
		kol_simbol=print_str.Length();
		for (int j=0;j<kol_simbol;j++)
			{
			if (j<=kol_simbol)
				{
				BufData[13+(24*i)+j]=ScaleCodeSimbol(print_str[j+1]);
				}
			}
		}
	delete strings;
// ***************************************************************************

WriteBuffer(BufData,61);
Buf_1[0]=0x00;
ReadBuffer(Buf_1,1);

if (Buf_1[0]!=0x10)
	{
	result=false;
	TextError="Ошибка при передаче параметров товара!";
	}
else
	{
	result=true;
	}
delete BufData;
return result;
}
//---------------------------------------------------------------------------
bool TScaleVP::AddDopStringInScale(void)
{
bool result=true;
if (KolDopString==0)
	{
	result=true;
	return result;
	}

char * BufData=new char[48];

	for (int i=0;i<DopStrings->Count && i<KolDopString;i++)
		{

		SetupComPort("M",50,0,2000,0,1000,false);
		Buf_1[0]=SetNumber;
		WriteBuffer(Buf_1,1);
		ReadBuffer(Buf_1,1);

		if (Buf_1[0]!=0x77)
			{
			result=false;
			TextError="Весы не отвечают на команду синхронизации!";
			return result;
			}

		SetupComPort("S",50,0,2000,0,1000,false);
		Buf_1[0]=0x05;
		WriteBuffer(Buf_1,1);
		ReadBuffer(Buf_1,1);

		if (Buf_1[0]!=0x01)
			{
			result=false;
			TextError="Весы не готовы к приему данных!";
			return result;
			}


		Buf_3[0]=*((char*)&NumberTovar);
		Buf_3[1]=*((char*)&NumberTovar+1);
		Buf_3[2]=i+1;   //номер строки

		WriteBuffer(Buf_3,3);
		Buf_1[0]=0x00;
		ReadBuffer(Buf_1,1);

		if (Buf_1[0]!=0x01)
			{
			result=false;
			TextError="Ошибка при передаче номера товара!";
			return result;
			}

		//доп строка 48 символов

		for (int j=0;j<48;j++)
			{
			BufData[j]=0x20;
			}



		AnsiString print_str=DopStrings->Strings[i];
		 if (print_str.Length()>48)
			{
			print_str.SetLength(48);
			}

		for (int j=0;j<print_str.Length();j++)
			{
			BufData[j]=ScaleCodeSimbol(print_str[j+1]);  
			}

		WriteBuffer(BufData,48);
		Buf_1[0]=0x00;
		ReadBuffer(Buf_1,1);

		if (Buf_1[0]!=0x10)
			{
			TextError="Ошибка при передаче дополнительных строк!";
			result=false;
			}

		}
delete BufData;
return result;
}
//---------------------------------------------------------------------------
bool TScaleVP::SetFormatLabel(void)
{
bool result=false;


SetupComPort("M",50,0,2000,0,1000,false);
Buf_1[0]=SetNumber;
WriteBuffer(Buf_1,1);
ReadBuffer(Buf_1,1);

if (Buf_1[0]!=0x77)
	{
	result=false;
	TextError="Весы не отвечают на команду синхронизации!";
	return result;
	}

SetupComPort("S",50,0,2000,0,1000,false);
Buf_1[0]=0x01;   //код операции
WriteBuffer(Buf_1,1);
ReadBuffer(Buf_1,1);

if (Buf_1[0]!=0x01)
	{
	result=false;
	TextError="Весы не готовы к приему данных!";
	return result;
	}



//передаем товар
char * BufData=new char[2];

if (VidLabel=="A")
	{
	BufData[0]=0x0;
	}

if (VidLabel=="B")
	{
	BufData[0]=0x1;
	}

if (VidLabel=="C")
	{
	BufData[0]=0x2;
	}

if (VidLabel=="D")
	{
	BufData[0]=0x3;
	}

BufData[1]=HeightLabel;


WriteBuffer(BufData,2);
Buf_1[0]=0x00;
ReadBuffer(Buf_1,1);

if (Buf_1[0]!=0x10)
	{
	result=false;
	TextError="Ошибка при передаче формата этикетки!";
	}
else
	{
	result=true;
	}
delete BufData;
return result;

}
//---------------------------------------------------------------------------
bool TScaleVP::SetParameteLabel(void)
{
bool result=false;


SetupComPort("M",50,0,2000,0,1000,false);
Buf_1[0]=SetNumber;
WriteBuffer(Buf_1,1);
ReadBuffer(Buf_1,1);

if (Buf_1[0]!=0x77)
	{
	result=false;
	TextError="Весы не отвечают на команду синхронизации!";
	return result;
	}

SetupComPort("S",50,0,2000,0,1000,false);
Buf_1[0]=0x0a;  //код операции
WriteBuffer(Buf_1,1);
ReadBuffer(Buf_1,1);

if (Buf_1[0]!=0x01)
	{
	result=false;
	TextError="Весы не готовы к приему данных!";
	return result;
	}

//передаем параметры
char * BufData=new char[106];
BufData[0]=NumberOtdelVes;
BufData[1]=NumberOtdelSht;
BufData[2]=TypeBarCode;
if (PrintDate==true)
	{
	BufData[3]=1;
	}
else
	{
	BufData[3]=0;
	}

if (PrintPrice==true)
	{
	BufData[4]=1;
	}
else
	{
	BufData[4]=0;
	}

if (PrintSert==true)
	{
	BufData[5]=1;
	}
else
	{
	BufData[5]=0;
	}

CodeSert.SetLength(4);

for (int j=1;j<CodeSert.Length();j++)
	{
	BufData[5+j]=ScaleCodeSimbol(CodeSert[j]);
	}
//9
//реклама 24 символа
//c 10 по 34

for (int j=10;j<106;j++)
	{
	BufData[j]=32;
	}

if (ReklamaStr1.Length()>24)
	{
	ReklamaStr1.SetLength(24);
	}
for (int j=0;j<ReklamaStr1.Length();j++)
	{
	BufData[10+j]=ScaleCodeSimbol(ReklamaStr1[j+1]);
	}

//реклама 24 символа
//c 35 по 59
if (ReklamaStr2.Length()>24)
	{
	ReklamaStr2.SetLength(24);
	}
for (int j=0;j<ReklamaStr2.Length();j++)
	{
	BufData[34+j]=ScaleCodeSimbol(ReklamaStr2[j+1]);
	}

//незапрогр. 24 символа
//c 60 по 84
if (NeZaprogStr1.Length()>24)
	{
	NeZaprogStr1.SetLength(24);
	}
for (int j=0;j<NeZaprogStr1.Length();j++)
	{
	BufData[58+j]=ScaleCodeSimbol(NeZaprogStr1[j+1]);
	}

//незапрогр. 24 символа
//c 60 по 84
if (NeZaprogStr2.Length()>24)
	{
	NeZaprogStr2.SetLength(24);
	}
for (int j=0;j<NeZaprogStr2.Length();j++)
	{
	BufData[82+j]=ScaleCodeSimbol(NeZaprogStr2[j+1]);
	}


WriteBuffer(BufData,106);
Buf_1[0]=0x00;
ReadBuffer(Buf_1,1);

if (Buf_1[0]!=0x10)
	{
	result=false;
	TextError="Ошибка при передаче параметров этикетки!";
	}
else
	{
	result=true;
	}
delete BufData;
return result;


}
//----------------------------------------------------------------------------






















//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//откроем порт
bool  TScaleVP::OpenPort(int port, int baud_rate)
{
bool result=false;
BaudRate=baud_rate;


AnsiString com_name="COM"+IntToStr(port);

ComHandle=CreateFile(com_name.c_str(),GENERIC_READ|GENERIC_WRITE,0,NULL,
                                OPEN_EXISTING,FILE_FLAG_OVERLAPPED,NULL);

if (ComHandle==INVALID_HANDLE_VALUE)
        {
		result=false;
		TextError="Не удалось открыть порт!";
		}
else
        {
		result=true;
		}

SetupComPort("N",50,0,2000,0,1000,true);







return result;
}
//----------------------------------------------------------------------------
//закроем  порт
bool TScaleVP::ClosePort()
{
bool result=true;
CloseHandle(ComHandle);

return result;

}
//--------------------------------------------------------------------------------
//настороим порт для ввода/вывода
void TScaleVP::SetupComPort(AnsiString parity ,int ri,int rm, int rc, int wm, int wc, bool clear_buffer)
{ 
AnsiString str="baud=";
str=str+IntToStr(BaudRate)+" data=8 stop=1 parity="+parity;

BuildCommDCB( str.c_str(),stDCB);
stDCB->XoffLim=1024;
stDCB->XonLim=1024;
//stDCB->fRtsControl=RTS_CONTROL_HANDSHAKE;
//stDCB->fTXContinueOnXoff=true;
stDCB->XonChar=0x11;
stDCB->XoffChar=0x13;
stCommtimeouts->ReadIntervalTimeout=ri;
stCommtimeouts->ReadTotalTimeoutMultiplier=rm;
stCommtimeouts->ReadTotalTimeoutConstant=rc;
stCommtimeouts->WriteTotalTimeoutMultiplier=wm;
stCommtimeouts->WriteTotalTimeoutConstant=wc;

SetCommTimeouts(ComHandle,stCommtimeouts);
SetCommState(ComHandle,stDCB);

if (clear_buffer==true)
        {
        PurgeComm(ComHandle,PURGE_TXCLEAR|PURGE_RXCLEAR);
        }
}
//---------------------------------------------------------------------------
//переданы данные
//-----------------------------------------------------------------------------
void __stdcall ENDWrite(unsigned long ErrorCode,unsigned long BytesTransfered,OVERLAPPED *stOVR)
{
//ShowMessage("Вызвана процедура завершения записи!");

}
//----------------------------------------------------------------------------
//записать буфер в порт
void __fastcall TScaleVP::WriteBuffer(char  *buf, int len)
{
OVERLAPPED stOVR;
memset(&stOVR,0,sizeof(stOVR));
WriteFileEx(ComHandle,buf,len,&stOVR,ENDWrite);
SleepEx( INFINITE, true);
}

//----------------------------------------------------------------------------
void __stdcall ENDRead(unsigned long ErrorCode,unsigned long BytesTransfered,OVERLAPPED *stOVR)
{
//ShowMessage("Вызвана процедура завершения чтения!");
//Form1->LabelMessage->Caption="Принято  "+IntToStr(BytesTransfered)+" байт!";
}
//-----------------------------------------------------------------------------
//прочитать данные из порта
void __fastcall TScaleVP::ReadBuffer(char *buf, int len)
{
OVERLAPPED stOVR;
memset(&stOVR,0,sizeof(stOVR));
ReadFileEx(ComHandle,buf,len,&stOVR,ENDRead) ;
SleepEx( INFINITE, true);
}
//приняты данные
//-----------------------------------------------------------------------------
// получить код символа
char TScaleVP::ScaleCodeSimbol(AnsiString StringSimbol)
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

if (StringSimbol=='А'){return Res=128;}
if (StringSimbol=='Б'){return Res=129;}
if (StringSimbol=='В'){return Res=130;}
if (StringSimbol=='Г'){return Res=131;}
if (StringSimbol=='Д'){return Res=132;}
if (StringSimbol=='Е'){return Res=133;}
if (StringSimbol=='Ж'){return Res=134;}
if (StringSimbol=='З'){return Res=135;}
if (StringSimbol=='И'){return Res=136;}
if (StringSimbol=='Й'){return Res=137;}
if (StringSimbol=='К'){return Res=138;}
if (StringSimbol=='Л'){return Res=139;}
if (StringSimbol=='М'){return Res=140;}
if (StringSimbol=='Н'){return Res=141;}
if (StringSimbol=='О'){return Res=142;}
if (StringSimbol=='П'){return Res=143;}
if (StringSimbol=='Р'){return Res=144;}
if (StringSimbol=='С'){return Res=145;}
if (StringSimbol=='Т'){return Res=146;}
if (StringSimbol=='У'){return Res=147;}
if (StringSimbol=='Ф'){return Res=148;}
if (StringSimbol=='Х'){return Res=149;}
if (StringSimbol=='Ц'){return Res=150;}
if (StringSimbol=='Ч'){return Res=151;}
if (StringSimbol=='Ш'){return Res=152;}
if (StringSimbol=='Щ'){return Res=153;}
if (StringSimbol=='Ъ'){return Res=154;}
if (StringSimbol=='Ы'){return Res=155;}
if (StringSimbol=='Ь'){return Res=156;}
if (StringSimbol=='Э'){return Res=157;}
if (StringSimbol=='Ю'){return Res=158;}
if (StringSimbol=='Я'){return Res=159;}

if (StringSimbol=='а'){return Res=160;}
if (StringSimbol=='б'){return Res=161;}
if (StringSimbol=='в'){return Res=162;}
if (StringSimbol=='г'){return Res=163;}
if (StringSimbol=='д'){return Res=164;}
if (StringSimbol=='е'){return Res=165;}
if (StringSimbol=='ж'){return Res=166;}
if (StringSimbol=='з'){return Res=167;}
if (StringSimbol=='и'){return Res=168;}
if (StringSimbol=='й'){return Res=169;}
if (StringSimbol=='к'){return Res=170;}
if (StringSimbol=='л'){return Res=171;}
if (StringSimbol=='м'){return Res=172;}
if (StringSimbol=='н'){return Res=173;}
if (StringSimbol=='о'){return Res=174;}
if (StringSimbol=='п'){return Res=175;}
if (StringSimbol=='р'){return Res=224;}
if (StringSimbol=='с'){return Res=225;}
if (StringSimbol=='т'){return Res=226;}
if (StringSimbol=='у'){return Res=227;}
if (StringSimbol=='ф'){return Res=228;}
if (StringSimbol=='х'){return Res=229;}
if (StringSimbol=='ц'){return Res=230;}
if (StringSimbol=='ч'){return Res=231;}
if (StringSimbol=='ш'){return Res=232;}
if (StringSimbol=='щ'){return Res=233;}
if (StringSimbol=='ъ'){return Res=234;}
if (StringSimbol=='ы'){return Res=235;}
if (StringSimbol=='ь'){return Res=236;}
if (StringSimbol=='э'){return Res=237;}
if (StringSimbol=='ю'){return Res=238;}
if (StringSimbol=='я'){return Res=239;}




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
//---------------------------------------------------------------------------

