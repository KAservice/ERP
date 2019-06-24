//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UScale.h"
#include "UMainForm.h"

#include "UDMSprVesNomForScale.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall Scale::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TScale::TScale(bool CreateSuspended)
	: TThread(CreateSuspended)
{

}
//---------------------------------------------------------------------------
void __fastcall TScale::Execute()
{ 
TextMessage="Формирование файла";
EventScale=MessageEvent;
Synchronize(GenerateExternalEvent);

CreateFile();
AddCRC16();

TextMessage="Передача UDP пакета";
EventScale=MessageEvent;
Synchronize(GenerateExternalEvent);

DMSock=new TDMSocketVPM(Application);
DMSock->FOnCloseForm=EndSocketOperation;
DMSock->IP=IP;
DMSock->Port=Port;

DMSock->SendUDPPaket();
Sleep(10000);


TextMessage="Установка соединения с весами";
EventScale=MessageEvent;
Synchronize(GenerateExternalEvent);
DMSock->Connect();


}
//---------------------------------------------------------------------------
//генерировать внешнее событие
void __fastcall TScale::GenerateExternalEvent(void)
{
MainForm->ObrabExternalEvent();
}
//----------------------------------------------------------------------------
void TScale::CreateFile(void)
{

TextMessage="Формирование файла";
EventScale=MessageEvent;
Synchronize(GenerateExternalEvent);



TFileStream * file=new TFileStream ("Message.dat",fmCreate);

unsigned char * paket=new unsigned char [13];

paket[0]=0xf8;
paket[1]=0x55;
paket[2]=0xce;
paket[3]=0x00;   //  длина
paket[4]=0x00;   //  сообщения    размер файла - 7
paket[5]=0x82;   //  команда
paket[6]=0x01;   //  тип файла
paket[7]=0x01;   //  число
paket[8]=0x00;   //  записей
paket[9]=0x01;   //  номер
paket[10]=0x00;  //  записи
paket[11]=0x00;  //  длина
paket[12]=0x00;  //  всех записей    размер файла - 15

file->Write(paket,13);

delete paket;
delete file;

TDMSprVesNomForScale * DMSprVesNomForScale=new TDMSprVesNomForScale(Application);
DMSprVesNomForScale->OpenTable(IdScale);

MaxProgressBar=DMSprVesNomForScale->Table->RecordCount;
EventScale=FirstEvent;
Synchronize(GenerateExternalEvent);

while (!DMSprVesNomForScale->Table->Eof)
	{
	AddRecordTovar(DMSprVesNomForScale->TableCODE_SVESNOM->AsInteger,      //PLU
							0,                          //статус PLU
							1,        //номер этикетки
							1, //номер штрих кода
							22,   //префикс штрихкода
							DMSprVesNomForScale->TableZNACH_PRICE->AsFloat,   //цена
							0,
							DMSprVesNomForScale->TableCODENOM->AsInteger, //код товара единицы измерения
							0,       //срок реализации
							0,       //срок годности
							"    ",  //код сертификации
							0,      //номер основной группы
							1,     //номер шрифта
							DMSprVesNomForScale->TableNAMENOM->AsString);
	EventScale=NextEvent;
	Synchronize(GenerateExternalEvent);
	DMSprVesNomForScale->Table->Next();
	}


delete DMSprVesNomForScale;


}
//-----------------------------------------------------------------------------
void TScale::AddRecordTovar(int plu,
							int status_plu,
							int number_etiketki,
							int number_shtrih_coda,
							int prefiks_shtrih_coda,
							double price,
							double massa_tary,
							int code_tovar,
							TDateTime date_real,
							int srok_godn,
							AnsiString code_sertif,
							int number_osn_group,
							int number_font_name_tovar,
							AnsiString name_tovar)
{
int len_name_tovar=name_tovar.Length();

unsigned char * mas_name_tovar=new unsigned char [len_name_tovar];
//  наименование товара 40 байт

strcpy(mas_name_tovar,name_tovar.c_str());

for (int i = 0; i < len_name_tovar; i++)
	{
	mas_name_tovar[i]=name_tovar[i+1];
	}

//mas_name_tovar[0]=0xd2;
//mas_name_tovar[1]=0xee;
//mas_name_tovar[2]=0xe2;
//mas_name_tovar[3]=0xe0;
//mas_name_tovar[4]=0xf0;
//mas_name_tovar[5]=0x20;
//mas_name_tovar[6]=0x31;

int len_texts=len_name_tovar+9;
unsigned char * texts=new unsigned char [len_name_tovar+9];    //7

texts[0]=number_font_name_tovar;
texts[1]=len_name_tovar;

for (int i = 0; i < len_name_tovar; i++)
	{
	texts[i+2]=mas_name_tovar[i];
	}

texts[(len_texts)-7]=0x0d;
texts[(len_texts)-6]=0x0;
texts[(len_texts)-5]=0x0;
texts[(len_texts)-4]=0x0d;
texts[(len_texts)-3]=0x0;
texts[(len_texts)-2]=0x0;
texts[(len_texts)-1]=0x0d;


delete mas_name_tovar;


int len_data=len_texts+44;
unsigned char * data=new unsigned char [len_data];


data[0]=*((unsigned char*)&plu);   //  plu номер записи
data[1]=*((unsigned char*)&plu+1);   //
data[2]=*((unsigned char*)&plu+2);   //
data[3]=*((unsigned char*)&plu+3);     //

int len_record_data=(len_data)-6;

data[4]=*((char*)&len_record_data); //  длина записи
data[5]=*((char*)&len_record_data+1);   //  с суммой всех байт (последний символ)

data[6]=*((char*)&status_plu);    // статус PLU
data[7]=*((char*)&status_plu+1);    //

data[8]=number_etiketki;  //номер этикетки
data[9]=number_shtrih_coda;  //номер штрих-кода
data[10]=prefiks_shtrih_coda;  //префикс штрих-кода

int price_kop=price*100;

data[11]=*((char*)&price_kop);   //  цена в копейках
data[12]=*((char*)&price_kop+1);   //
data[13]=*((char*)&price_kop+2);   //
data[14]=*((char*)&price_kop+3);     //

int massa_gramm=massa_tary*1000;

data[15]=*((char*)&massa_gramm);   //  вес тары в граммах
data[16]=*((char*)&massa_gramm+1);   //
data[17]=*((char*)&massa_gramm+2);   //
data[18]=*((char*)&massa_gramm+3);     //

data[19]=*((char*)&code_tovar);   //  код товара
data[20]=*((char*)&code_tovar+1);   //
data[21]=*((char*)&code_tovar+2);   //
data[22]=*((char*)&code_tovar+3);     //

data[23]=0x08;   //  дата реализации
data[24]=0x0a;   //
data[25]=0x17;   //
data[26]=0x0b;     //
data[27]=0x20;   //
data[28]=0x29;     //

data[29]=0;   //  срок годности
data[30]=0;   //
data[31]=0;   //
data[32]=0;     //
data[33]=0;   //
data[34]=0;     //

if (code_sertif=="")
	{
	data[35]=0x20;   //  код органа сертификации
	data[36]=0x20;     //
	data[37]=0x20;   //
	data[38]=0x20;     //
	}
else
	{
	data[35]=code_sertif[1];   //  код органа сертификации
	data[36]=code_sertif[2];     //
	data[37]=code_sertif[3];   //
	data[38]=code_sertif[4];     //
	}

data[39]=*((char*)&number_osn_group);   //
data[40]=*((char*)&number_osn_group+1);

data[41]=0;   //   зарезервировано
data[42]=0;   //


for (int i = 0; i < (len_texts); i++)
	{
	data[i+43]=texts[i];
	}

delete texts;

char sum=0;

for (int i = 0; i < (len_data)-1; i++)
	{
	sum=sum+data[i];
	}

data[(len_data)-1]=sum;



//AnsiString s="";
//for (int i = 0; i < len_paket; i++)
//	{
//	s=s+" "+IntToHex(paket[i],2);
//	}
//ShowMessage(s);


TFileStream * file=new TFileStream ("Message.dat",fmOpenReadWrite);
file->Position=file->Size;
file->Write(data,len_data);


delete data;
delete file;
}
//------------------------------------------------------------------------
void TScale::AddCRC16(void)
{
TFileStream * file=new TFileStream ("Message.dat",fmOpenReadWrite);
file->Position=file->Size;

unsigned char * a=new unsigned char [2];

//добавим в конец файла место для контрольной суммы
a[0]=0x00;
a[1]=0x00;
file->Write(a,2);


//длина сообщения
int len_message=file->Size-7;
a[0]=*((char*)&len_message);    //
a[1]=*((char*)&len_message+1);    //

file->Position=3;
file->Write(a,2);

//длина всех записей
int len_records=file->Size-15;
a[0]=*((char*)&len_records);    //
a[1]=*((char*)&len_records+1);    //

file->Position=11;
file->Write(a,2);

unsigned char * message=new unsigned char [file->Size];
file->Read(message,file->Size);
int ks=CRC16(message,message[3]+message[4]*256);
delete message;

a[0]=*((char*)&ks);   //
a[1]=*((char*)&ks+1); //
file->Position=file->Size-2;
file->Write(a,2);

delete a;
delete file;

}
//----------------------------------------------------------------
void TScale::SendMessageVPM(void)
{


}
//---------------------------------------------------------------------------

void __fastcall TScale::EndSocketOperation(TObject *Sender)
{
if (DMSock->EventSocket==DMSock->ConnectEvent)
	{
	TextMessage="Передача файла";
	EventScale=MessageEvent;
	Synchronize(GenerateExternalEvent);
	DMSock->SendFile();
	}

if (DMSock->EventSocket==DMSock->EndObmenEvent)
	{
	EventScale=EndObmenEvent;
	Synchronize(GenerateExternalEvent);
	}

}

//----------------------------------------------------------------------------
WORD TScale::CRC16(BYTE *buf, WORD len)
{
	WORD bits, k, crc=0;
	WORD accumulator, temp;

	for( k = 0; k<len; k++ )
	{
		accumulator = 0;
		temp = (crc>>8)<<8;
		for( bits = 0; bits < 8; bits++ )
		{
			if( (temp ^ accumulator) & 0x8000 )
				accumulator = (accumulator << 1) ^ 0x1021;
			else
				accumulator <<= 1;
			temp <<= 1;
		}
		crc = accumulator^(crc<<8)^(buf[k+5]&0xff);
	}
//	ShowMessage(IntToHex(crc,8));
	return crc;
}                          

//-----------------------------------------------------------------------------
