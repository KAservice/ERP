//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UMainForm.h"

#include "UDM.h"
#include "UDMSprARM.h"
#include "UDMSprOborud.h"
#include "UDMSprUser.h"

#include "UAbout.h"

#include "UDMSetup.h"
#include "math.h"
#include "UDMSprTypePrice.h"
#include "UFormaSetupScale.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;


TDMSprARM *glARM;
TDMSprUser *glUser;
//----------- фискальный регистратор -----
AnsiString BaseVersion;
AnsiString ProgramVersion;
extern AnsiString GetVersionProgramFile(void);
TDM *DM;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
NameFileIni=ExtractFileDir(Application->ExeName)+"\\SetupScale.ini";


ProgramVersion="3.0";
DM=new TDM(Application);
glUser=new TDMSprUser(Application);
//glUser=new TDMSprUser(Application);
glARM=new TDMSprARM(Application);
FormaViborBase=new TFormaViborBase(Application);
DMSprScale=new TDMSprScale (Application);
LabelNameScale->Caption="";

DMSprVesNomForScale=new TDMSprVesNomForScale(Application);
LabelNameTypePrice->Caption="Тип цен: не задан";
DMSprOborud=new TDMSprOborud(Application);
DMQueryVesNom=new TDMQueryRead(Application);

NumberLabel=1;
NumberBarCode=1;
PrefiksBarCode=0;
CodeSertif="";
NumberOsnGrp=0;
NumberFont=5;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
delete glARM;
delete DMSprOborud;
delete DMSprScale;
delete DMSprVesNomForScale;
delete DMQueryVesNom;
delete glUser;
delete DM;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormShow(TObject *Sender)
{
FormaViborBase->FOnCloseForm=EndViborBase;
FormaViborBase->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::EndViborBase(TObject *Sender)
{

if (FormaViborBase->OutReady==true)
        {
        DM->ConnectString=FormaViborBase->ConnectString;
		DM->PasswordUser=FormaViborBase->PasswordUser;
		DM->NameUser=FormaViborBase->NameUser;

        if(DM->GlobConnect()==true)
                {
				if (glUser->FindPoName(FormaViborBase->NameUser)==1)
						{
						}
				else
						{
						ShowMessage("Не найден пользователь в справочнике пользователей! Необходимо завершить работу!");
						}

				Visible=true;
				FormaViborBase->CloseForm=true;
				
				if (glARM->FindPoCodu(FormaViborBase->NumberARM)<1)
					{
					ShowMessage("Не найдены настройки рабочего места с номером "+IntToStr(FormaViborBase->NumberARM));
					}
				StatusBar->Panels->Items[0]->Text=FormaViborBase->NameUser;
				//StatusBar->Panels->Items[1]->Text=gl_prefiks_ib;
				StatusBar->Panels->Items[2]->Text=DM->ConnectString;
				StatusBar->Panels->Items[3]->Text=BaseVersion;
				StatusBar->Panels->Items[4]->Text=ProgramVersion;

				//получим список весов
				GetSpisokScale();

				}
        else
				{
				UnicodeString s="Ошибка при подключении к базе данных: "+DM->TextError;
				Application->MessageBox(s.c_str(),
				L"Ошибка при подключении к базе данных!", MB_OK + MB_ICONEXCLAMATION);
				FormaViborBase->CloseForm=false;
				}

		}
else
		{
		//закрываем программу
		Close();

		}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MaimMenuAboutClick(TObject *Sender)
{
ShowAbout();
}
//---------------------------------------------------------------------------

void TMainForm::GetSpisokScale(void)
{

//PopupMenuSprScale->Items->Clear();
//DMSprScale->OpenTable();
//
//TMenuItem *menu;
//DMSprScale->Table->First();
//while ( !DMSprScale->Table->Eof)
//		{
//		menu=new TMenuItem(PopupMenuSprScale);
//		menu->Caption=DMSprScale->TableNAME_SSCALE->AsString;
//		menu->OnClick = PopupMenuSprScaleClick;
//		menu->Tag=DMSprScale->Table->RecNo;
//		PopupMenuSprScale->Items->Add(menu);
//		DMSprScale->Table->Next();
//		}

PopupMenuSprScale->Items->Clear();
DMSprOborud->OpenTable(glARM->ElementID_SARM->AsInt64) ;

TMenuItem *menu;
DMSprOborud->Table->First();
while ( !DMSprOborud->Table->Eof)
		{
		menu=new TMenuItem(PopupMenuSprScale);
		menu->Caption=DMSprOborud->TableNAME_OBORUD->AsString;
		menu->OnClick = PopupMenuSprScaleClick;
		menu->Tag=DMSprOborud->Table->RecNo;
		PopupMenuSprScale->Items->Add(menu);
		DMSprOborud->Table->Next();
		}
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::PopupMenuSprScaleClick(TObject *Sender)
{
int i = ((TMenuItem*)Sender)->Tag; //

DMSprOborud->Table->First();
DMSprOborud->Table->MoveBy(i-1);

AnsiString param=DMSprOborud->GetParameterPoTable("ID_SCALE");
IdOborud=DMSprOborud->TableID_OBORUD->AsInt64;

if(param=="")
	{
	ShowMessage("Не задано значение ID_SCALE в справочнике Оборудование");
	return;
	}

IdScale=StrToInt64(param);
LabelNameScale->Caption="Весы: "+((TMenuItem*)Sender)->Caption; //

//получить параметры весов

LabelIP->Caption="IP=";
LabelPort->Caption="Port=";
IP="";
Port=0;

TIniFile * ini=new TIniFile(NameFileIni);
IP=ini->ReadString(IntToStr(IdOborud),"IP","");

if (ini->ReadString(IntToStr(IdOborud),"Port","")=="")
	{
	Port=0;
	}
else
	{
	Port=StrToInt(ini->ReadString(IntToStr(IdOborud),"Port",""));
	}
delete ini;


if (glARM->ElementIDTPRICEPOD->AsString=="")
	{
	LabelNameTypePrice->Caption="Тип цен: не задан";
	ShowMessage("Задайте в справочнике АРМ тип цен (подразделение) номенклатуры для загрузки!");
	}
else
	{
	TDMSprTypePrice * tp=new TDMSprTypePrice(Application);
	tp->OpenElement(glARM->ElementIDTPRICEPOD->AsInt64);
	LabelNameTypePrice->Caption="Тип цен:"+tp->ElementNAME_TPRICE->AsString;
	delete tp;
	}

if (IP=="")
	{
	LabelIP->Caption="IP=не задан. (Форма Настройки)";
	}
else
	{
	LabelIP->Caption="IP="+IP;
	}

if (Port==0)
	{
	LabelPort->Caption="Port=не задан (Форма Настройки) По умолчанию 5001";
	}
else
	{
	LabelPort->Caption="Port="+IntToStr(Port);
	}



}
//---------------------------------------------------------------------------
void TMainForm::CreateFileMessage(void)
{
MessageLabel->Caption="Формирование файла";

GetParameterScale(IdOborud);

TFileStream * file=new TFileStream ("Message.dat",fmCreate);
delete file;


DMQueryVesNom->pFIBQ->Close();
AnsiString zapros="";
zapros=zapros+" select SVESNOM.*,";
zapros=zapros+" CODENOM, NAMENOM, NAMEED, DESCR_SNOM, GODEN_DO_SNOM,";
zapros=zapros+" ZNACH_PRICE,";
zapros=zapros+" CODE_SED";
zapros=zapros+" from SVESNOM";
zapros=zapros+" left outer join SNOM on IDNOM_SVESNOM=IDNOM";
zapros=zapros+" left outer join SPRICE on IDNOM_PRICE=IDNOM_SVESNOM  ";
zapros=zapros+"        AND IDTYPE_PRICE="+glARM->ElementIDTPRICEPOD->AsString;
zapros=zapros+"        AND IDED_SPRICE=IDBASEDNOM";
zapros=zapros+" left outer join SED on  IDBASEDNOM=IDED";
zapros=zapros+" where";
zapros=zapros+" IDSCALE_SVESNOM="+IntToStr(IdScale);
zapros=zapros+" order by NAMENOM";


DMQueryVesNom->pFIBQ->SQL->Clear();
DMQueryVesNom->pFIBQ->SQL->Add(zapros);
DMQueryVesNom->pFIBQ->ExecQuery();


while (!DMQueryVesNom->pFIBQ->Eof)
	{
	AddRecordTovar(DMQueryVesNom->pFIBQ->FieldByName("CODE_SVESNOM")->AsInteger,      //PLU
							0,                          //статус PLU
							NumberLabel,        //номер этикетки
							NumberBarCode, //номер штрих кода
							PrefiksBarCode,   //префикс штрихкода
							DMQueryVesNom->pFIBQ->FieldByName("ZNACH_PRICE")->AsFloat,   //цена
							0,        //масса тары
							DMQueryVesNom->pFIBQ->FieldByName("CODENOM")->AsInteger, //код товара
							DMQueryVesNom->pFIBQ->FieldByName("GODEN_DO_SNOM")->AsDateTime,       //срок реализации
							0,       //срок годности  в минутах
							CodeSertif,  //код сертификации
							NumberOsnGrp,      //номер основной группы
							NumberFont,     //номер шрифта
							DMQueryVesNom->pFIBQ->FieldByName("NAMENOM")->AsString);

	DMQueryVesNom->pFIBQ->Next();
	}


MessageLabel->Caption="Файл сформирован";
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void TMainForm::AddRecordTovar(int plu,
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

unsigned char * mas_name_tovar=new unsigned char [100];         //len_name_tovar
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
unsigned char * texts=new  unsigned char [100];    //7     len_name_tovar+9

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
unsigned char * data=new unsigned char [150];          //len_data


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

data[23]=StrToInt(FormatDateTime("y",date_real));   //  дата реализации  ГГ
data[24]=StrToInt(FormatDateTime("m",date_real));   //                   ММ
data[25]=StrToInt(FormatDateTime("d",date_real));   //                   ДД
data[26]=StrToInt(FormatDateTime("h",date_real));     //                 ЧЧ
data[27]=StrToInt(FormatDateTime("n",date_real));   //                   ММ
data[28]=StrToInt(FormatDateTime("s",date_real));     //                 СС

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

//----------------------------------------------------------------
WORD TMainForm::CRC16(BYTE *buf, WORD len)
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
void TMainForm::SendUDPPaket(void)
{
MessageLabel->Caption="Посылаем UDP пакет";
char * A=new char[8];
A[0]=0xf8;
A[1]=0x55;
A[2]=0xce;

A[3]=0x01;
A[4]=0x00;

A[5]=0x00;
A[6]=0x00;
A[7]=0x00;

UdpSocket->RemoteHost=IP;
UdpSocket->RemotePort=Port;
UdpSocket->SendBuf(A,8,0);

delete A;
MessageLabel->Caption="Пакет UDP послан";
}
//----------------------------------------------------------------------------
void TMainForm::Connect(void)
{
MessageLabel->Caption="Устанавливаем сединение с весами." ;
ClientSocket->Address=IP;
ClientSocket->Port=Port;
ClientSocket->Active=true;
}

//-----------------------------------------------------------------------------
void __fastcall TMainForm::ClientSocketConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
MessageLabel->Caption="Установлено сединение. Посылаем файл" ;

//определим количество записей
TFileStream * file=new TFileStream ("Message.dat",fmOpenRead);
KolRecord=floor(file->Size/1024+1);
delete file;

ProgressBar1->Max=KolRecord;
SendBlok(1);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ClientSocketRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
int len=Socket->ReceiveLength();
int num_tec_record=0;
unsigned char * A=new unsigned char[len];

Socket->ReceiveBuf(A,len);


//AnsiString s="";
//for (int i = 0; i < len; i++)
//	{
//	s=s+" "+IntToHex(A[i],2);
//	}
//
//
//
//ShowMessage("Ответ: "+s);


if (A[5]==0x42)
	{  //запись принята успешно
	num_tec_record=A[9]+A[10]*256;
	if (num_tec_record>=KolRecord) //все передали
		{
		 MessageLabel->Caption="Передача завершена!";
		 ClientSocket->Active=false;
		 ProgressBar1->StepIt();
		}
	else
		{
		SendBlok(num_tec_record+1);
		ProgressBar1->StepIt();
		}
	}
else
	{
	MessageLabel->Caption="Ошибка передачи! Запись №" +IntToStr(num_tec_record);
	}

delete A;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ToolButtonDisconnectClick(TObject *Sender)
{
ClientSocket->Active=false;
}
//---------------------------------------------------------------------------
void TMainForm::SendBlok(int number_blok)
{
TFileStream * file=new TFileStream ("Message.dat",fmOpenRead);
int len_blok=0;
if (file->Size<1024)  //1 запись
	{
	len_blok=file->Size;
	}
else
	{ //несколько записей
	if (number_blok==KolRecord)  //последняя запись
		{
		len_blok=number_blok*1024-file->Size;
		}
	else
		{
        len_blok=1024;
        }
    }

unsigned char * blok=new unsigned char [1200];       //len_blok

int len_paket=len_blok+15;
unsigned char * paket=new unsigned char [1200];         //

int len_mes=len_paket-7;

paket[0]=0xf8;
paket[1]=0x55;
paket[2]=0xce;
paket[3]=*((char*)&len_mes);   //  длина
paket[4]=*((char*)&len_mes+1);   //  сообщения    размер файла - 7
paket[5]=0x82;   //  команда
paket[6]=0x01;   //  тип файла
paket[7]=*((char*)&KolRecord);   //  число
paket[8]=*((char*)&KolRecord+1);   //  записей
paket[9]=*((char*)&number_blok);   //  номер
paket[10]=*((char*)&number_blok+1);  //  записи
paket[11]=*((char*)&len_blok);  //  длина
paket[12]=*((char*)&len_blok+1);  //  всех записей    размер файла - 15

file->Position=1024*(number_blok-1);
file->Read(blok,len_blok);
delete file;

for (int i=0; i < len_blok; i++)
	{
	paket[i+13]=blok[i];
	}


delete blok;

int ks=CRC16(paket,paket[3]+paket[4]*256);
paket[len_paket-2]=*((char*)&ks);
paket[len_paket-1]=*((char*)&ks+1);


ClientSocket->Socket->SendBuf(paket, len_paket);

delete paket;
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::ClientSocketError(TObject *Sender,
	  TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
MessageLabel->Caption="Ошибка загрузки!";
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::ToolButtonZagrusitScaleClick(TObject *Sender)
{
ZagrusitScale();
}
//---------------------------------------------------------------------------
void TMainForm::ZagrusitScale(void)
{
//создать файл
CreateFileMessage();

//отправить UDP пакет
SendUDPPaket();
Sleep(1000);
UdpSocket->Active=false;
//устанавливаем соединение
Connect();
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::ScaleMainMenuClick(TObject *Sender)
{
ZagrusitScale();
}
//---------------------------------------------------------------------------
void TMainForm::ShowAbout(void)
{
TFormAbout * form=new TFormAbout(Application);
if (!form) return;
//настройка формы
form->NameProgramLabel->Caption="Панель управления весами ВПМ (Масса-К) ";
form->VerProgLabel->Caption="Версия программы: "+ProgramVersion;
form->VerBaseLabel->Caption="Версия базы: "+BaseVersion;
//получим версию файла
//form->VerFileLabel->Caption="Версия файла: "+GetVersionProgramFile();
//регистрационный номер
form->RegNumberLabel->Caption=""; //"Регистрационный номер: "+IntToStr(glRegNumber)
//	+" ("+IntToHex(glRegNumber, 8)+")";
//TDMSetup * DMSetup=new TDMSetup(Application);
//DMSetup->OpenElement(15);
form->GrPosledLabel->Caption="";//"Граница последовательности: "
//				+DMSetup->ElementVALUE_SETUP->AsString;
//delete DMSetup;
//if (glDemo==true)
//	{
//	form->DemoLabel->Visible=true;
//	}
//else
//	{
	form->DemoLabel->Visible=false;
//	}
form->UpdateForm();
form->ShowModal();


}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ToolButtonOpenAboutClick(TObject *Sender)
{
ShowAbout();	
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ToolButtonSetupScaleClick(TObject *Sender)
{
Application->CreateForm(__classid(TFormSetupScale), &FormSetupScale);
FormSetupScale->IdScale=IdScale;
FormSetupScale->IdOborud=IdOborud;
FormSetupScale->NameScale=LabelNameScale->Caption;
FormSetupScale->UpdateForm();
FormSetupScale->Show();	
}
//---------------------------------------------------------------------------
void TMainForm::GetParameterScale(int id_oborud)
{

TIniFile * ini=new TIniFile(NameFileIni);


if (ini->ReadString(IntToStr(id_oborud),"NumberLabel","")=="")
	{
	NumberLabel=0;
	}
else
	{
	NumberLabel=StrToInt(ini->ReadString(IntToStr(id_oborud),"NumberLabel",""));
	}

if (ini->ReadString(IntToStr(id_oborud),"NumberBarCode","")=="")
	{
	NumberBarCode=0;
	}
else
	{
	NumberBarCode=StrToInt(ini->ReadString(IntToStr(id_oborud),"NumberBarCode",""));
	}

if (ini->ReadString(IntToStr(id_oborud),"PrefiksBarCode","")=="")
	{
	PrefiksBarCode=0;
	}
else
	{
	PrefiksBarCode=StrToInt(ini->ReadString(IntToStr(id_oborud),"PrefiksBarCode",""));
	}

CodeSertif=ini->ReadString(IntToStr(id_oborud),"CodeSert","");

if (ini->ReadString(IntToStr(id_oborud),"NumberOsnGrp","")=="")
	{
	NumberOsnGrp=0;
	}
else
	{
	NumberOsnGrp=StrToInt(ini->ReadString(IntToStr(id_oborud),"NumberOsnGrp",""));
	}

if (ini->ReadString(IntToStr(id_oborud),"NumberFont","")=="")
	{
	NumberFont=0;
	}
else
	{
	NumberFont=StrToInt(ini->ReadString(IntToStr(id_oborud),"NumberFont",""));
	}

delete ini;

}
//-----------------------------------------------------------------------------
