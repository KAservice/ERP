//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UMainForm.h"

#include "UDM.h"
#include "UDMSprARM.h"

#include "UDMSprUser.h"
#include "UAbout.h" 
#include "UDMSetup.h"
#include "UFormaSetupScale.h"
#include "inifiles.hpp"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;


TDMSprARM *glARM;
TDMSprUser *glUser;
AnsiString BaseVersion;
AnsiString ProgramVersion;
TDM *DM;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
ProgramVersion="3.0";
DM=new TDM(Application);
glARM=new TDMSprARM(Application);
glARM->DM_Connection=DM;
glARM->Init();
glUser=new TDMSprUser(Application);
glUser->DM_Connection=DM;
glUser->Init();
FormaViborBase=new TFormaViborBase(Application);
DMSprScale=new TDMSprScale (Application);
DMSprScale->DM_Connection=DM;
DMSprScale->Init();
LabelNameScale->Caption="";

DMSprVesNomForScale=new TDMSprVesNomForScale(Application);
//DMSprVesNomForScale->DM_Connection=DM;
//DMSprVesNomForScale->Init();
DMQueryVesNom=new TDMQueryRead(Application);
DMQueryVesNom->DM_Connection=DM;
DMQueryVesNom->Init();

ScaleVP=new TScaleVP(true);
//ScaleVP->DM_Connection=DM;
//ScaleVP->Init();
Operation=No;


LabelPort->Caption="";
LabelSetNumber->Caption="";
LabelBaudRate->Caption="";
LabelKol->Caption="";
LabelNameScale->Caption="Выберите весы...";

DMSprOborud=new TDMSprOborud(Application);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
delete ScaleVP;


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
//------------------------------------------------------------------------------
void __fastcall TMainForm::OpenAboutMainMenuClick(TObject *Sender)
{
ShowAbout();
}
//---------------------------------------------------------------------------
void TMainForm::GetSpisokScale(void)
{

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
//-----------------------------------------------------------------------------
void __fastcall TMainForm::PopupMenuSprScaleClick(TObject *Sender)
{
int i = ((TMenuItem*)Sender)->Tag; //

DMSprOborud->Table->First();
DMSprOborud->Table->MoveBy(i-1);

AnsiString param=DMSprOborud->GetParameterPoTable("ID_SCALE");

if(param=="")
	{
	ShowMessage("Не задано значение ID_SCALE в справочнике Оборудование");
	return;
	}

IdScale=StrToInt64(param);
LabelNameScale->Caption="Весы: "+((TMenuItem*)Sender)->Caption; //

LabelPort->Caption="Port=";
SetNumber=0;
Port=0;
BaudRate=0;

  //получаем параметры весов
			if (DMSprOborud->GetParameterPoTable("SET_NUMBER")!="")
				{
				SetNumber=StrToInt(DMSprOborud->GetParameterPoTable("SET_NUMBER"));
				}
			if (DMSprOborud->TableCOMNAME_OBORUD->AsString!="")
				{
				Port=StrToInt(DMSprOborud->TableCOMNAME_OBORUD->AsString);
				}
				
			if (DMSprOborud->TableBAUDRATE_OBORUD->AsString!="")
				{
				BaudRate=StrToInt(DMSprOborud->TableBAUDRATE_OBORUD->AsString);
				}

				DMQueryVesNom->pFIBQ->Close();
				AnsiString zapros="";
				zapros=zapros+" select COUNT(*)";
				zapros=zapros+" from SVESNOM";
				zapros=zapros+" where";
				zapros=zapros+" IDSCALE_SVESNOM="+IntToStr(IdScale);

				DMQueryVesNom->pFIBQ->SQL->Clear();
				DMQueryVesNom->pFIBQ->SQL->Add(zapros);
				DMQueryVesNom->pFIBQ->ExecQuery();
				LabelKol->Caption="Количество товаров: "+DMQueryVesNom->pFIBQ->FieldByName("COUNT")->AsString;
				ProgressBar1->Max=DMQueryVesNom->pFIBQ->FieldByName("COUNT")->AsInteger;
				DMQueryVesNom->pFIBQ->Close();

LabelPort->Caption="COM: "+IntToStr(Port);
LabelSetNumber->Caption="Сетевой номер: "+IntToStr(SetNumber);
LabelBaudRate->Caption="Скорость: "+IntToStr(BaudRate);
}
//---------------------------------------------------------------------------
void TMainForm::ZagrusitScale(void)
{

if (glARM->ElementIDTPRICEPOD->AsString=="")
	{
	ShowMessage("Задайте в справочнике АРМ тип цен (подразделение) номенклатуры для загрузки!");
	return;
	}

Operation=ZagrTovar_Operation;
ScaleVP->Operation=ScaleVP->ZagrTovar_Operation;
ScaleVP->Error=false;
ScaleVP->TextError="Ошибок нет";
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


if (DMQueryVesNom->pFIBQ->RecordCount>0)
	{
	KolZagrTov=0;
	AddTovar();
	//задаем параметры весов
	ScaleVP->SetNumber=SetNumber;
	ScaleVP->Run=true;
	ScaleVP->OpenPort(Port,BaudRate);
	ScaleVP->Resume();
	}
else
	{
	ShowMessage("Нет товаров для загрузки!");
	}


//количество дополнительных строк	
AnsiString file_ini=ExtractFileDir(Application->ExeName)+"\\SetupScale.ini";
TIniFile * ini=new TIniFile(file_ini);
if (ini->ReadString(IntToStr(IdScale),"KolDopString","")!="")
	{
	ScaleVP->KolDopString=StrToInt(ini->ReadString(IntToStr(IdScale),"KolDopString",""));
	}
delete ini;

}
//--------------------------------------------------------------------------
void __fastcall TMainForm::ObrabExternalEvent(void)
{
if (ScaleVP->Error==true)
	{   //ошибка загрузки
	switch (Operation)
		{
		case ZagrTovar_Operation :  //загрузка товаров
				{
					ScaleVP->ClosePort();
					ScaleVP->Run=false;
					//ScaleVP->Suspend();
					DMQueryVesNom->pFIBQ->Close();
					ShowMessage(ScaleVP->TextError);
				break;
				 }
		case SetFormatLabel_Operation :  //запись формата этикетки
				{
				ScaleVP->ClosePort();
				ScaleVP->Operation=ScaleVP->No;
				ScaleVP->Run=false;
				//ScaleVP->Suspend();
				ShowMessage(ScaleVP->TextError);
				break;
				}

		case SetParameterLabel_Operation :  //запись параметров этикетки
				{
				ScaleVP->ClosePort();
				ScaleVP->Operation=ScaleVP->No;
				ScaleVP->Run=false;
				//ScaleVP->Suspend();
				ShowMessage(ScaleVP->TextError);
				break;
				}
		}
	}
else
	{  //ошибок нет
	switch (Operation)
		{

		case ZagrTovar_Operation :  //загрузка товаров
				{

				if (!DMQueryVesNom->pFIBQ->Eof)
					{ //устанавливаем параметры товара и загружаем в весы
					AddTovar();
					DMQueryVesNom->pFIBQ->Next();
					ProgressBar1->StepIt();
					KolZagrTov++;
					//ScaleVP->Execute();
					}
				else
					{
					ScaleVP->ClosePort();
					ScaleVP->Run=false;
					//ScaleVP->Suspend();
					DMQueryVesNom->pFIBQ->Close();
					//KolZagrTov++;
					ShowMessage("Загружено товаров:"+IntToStr(KolZagrTov));
					}
				break;
				 }
		case SetFormatLabel_Operation :  //запись формата этикетки
				{
				ScaleVP->ClosePort();
				ScaleVP->Operation=ScaleVP->No;
				ScaleVP->Run=false;
				//ScaleVP->Suspend();
				ShowMessage("Формат этикетки установлен!");
				break;
				}

		case SetParameterLabel_Operation :  //запись параметров этикетки
				{
				ScaleVP->ClosePort();
				ScaleVP->Operation=ScaleVP->No;
				ScaleVP->Run=false;
				//ScaleVP->Suspend();
				ShowMessage("Параметры этикетки установлены!");
				break;
				}

		}
	}
}
//--------------------------------------------------------------------------
void TMainForm::AddTovar(void)
{
//ShowMessage(DMQueryVesNom->pFIBQ->FieldByName("NAMENOM")->AsString+
//			"PLU "+DMQueryVesNom->pFIBQ->FieldByName("CODE_SVESNOM")->AsInteger +
//			"Код "+DMQueryVesNom->pFIBQ->FieldByName("CODENOM")->AsInteger
//			);

//	//параметры товара
//	int NumberTovar;  		//номер товара 1-999
//	int VidTovara;    		//вид товара 0,1
//	int GroupCode;          //групповой код 0-99
//	int CodeTovar;			//код товара 0-999999
//	double Price;           //цена
//	double Tara;            //тара
//	TDate SrokGodn;          //срок годности
//	AnsiString NameTovar;   //наименование
	
ScaleVP->NumberTovar=DMQueryVesNom->pFIBQ->FieldByName("CODE_SVESNOM")->AsInteger;
ScaleVP->VidTovara=0;
ScaleVP->GroupCode=0;
ScaleVP->CodeTovar=DMQueryVesNom->pFIBQ->FieldByName("CODENOM")->AsInteger;
ScaleVP->Price=DMQueryVesNom->pFIBQ->FieldByName("ZNACH_PRICE")->AsFloat;
ScaleVP->Tara=0;
ScaleVP->SrokGodn=DMQueryVesNom->pFIBQ->FieldByName("GODEN_DO_SNOM")->AsDate;
ScaleVP->NameTovar=DMQueryVesNom->pFIBQ->FieldByName("NAMENOM")->AsString;
ScaleVP->DopStrings->Text=DMQueryVesNom->pFIBQ->FieldByName("DESCR_SNOM")->AsString;
}
//--------------------------------------------------------------------------
void __fastcall TMainForm::ZagrScaleMainMenuClick(TObject *Sender)
{
ZagrusitScale();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ToolButtonSetupScaleClick(TObject *Sender)
{
Application->CreateForm(__classid(TFormSetupScale), &FormSetupScale);
FormSetupScale->IdScale=IdScale;
FormSetupScale->NameScale=LabelNameScale->Caption;
FormSetupScale->UpdateForm();
FormSetupScale->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ToolButtonZagrusitScaleClick(TObject *Sender)
{
ZagrusitScale();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ToolButtonSetFormatLabelClick(TObject *Sender)
{

bool error=false;

String V="При изменении формата этикетки будет очищена информация о товарах! Продолжить?" ;
String Z="Подтверждение изменения формата этикетки";
if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
	{
	return;
	}



Operation=SetFormatLabel_Operation;

	//задаем параметры весов
	ScaleVP->SetNumber=SetNumber;

	//задаем формат этикетки
	//формат этикетки


AnsiString file_ini=ExtractFileDir(Application->ExeName)+"\\SetupScale.ini";

TIniFile * ini=new TIniFile(file_ini);

ScaleVP->VidLabel=ini->ReadString(IntToStr(IdScale),"VidLabel","");
ScaleVP->Error=false;
ScaleVP->TextError="Ошибок нет";
if (ini->ReadString(IntToStr(IdScale),"HeightLabel","")!="")
	{
	ScaleVP->HeightLabel=StrToInt(ini->ReadString(IntToStr(IdScale),"HeightLabel",""));
	}
else
	{
    ShowMessage("Не задана высота этикетки!");
	error=true;
	}


delete ini;




if (error==false)
	{
	ScaleVP->OpenPort(Port,BaudRate);
	ScaleVP->Operation=ScaleVP->SetFormatLabel_Operation;
	ScaleVP->Run=true;
	ScaleVP->Resume();
	}
else
	{
	ShowMessage("Ошибка в формате этикетки!");
	}

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ToolButtonSetParameterLabelClick(TObject *Sender)
{
bool error=false;

Operation=SetParameterLabel_Operation;


	//задаем параметры весов


	//задаем параметры этикетки
AnsiString file_ini=ExtractFileDir(Application->ExeName)+"\\SetupScale.ini";

TIniFile * ini=new TIniFile(file_ini);

//параметры этикетки
if (ini->ReadString(IntToStr(IdScale),"NumOtdelVes","")=="")
	{
	error=true;
	}
else
	{
	ScaleVP->NumberOtdelVes=StrToInt(ini->ReadString(IntToStr(IdScale),"NumOtdelVes",""));
	}

if (ini->ReadString(IntToStr(IdScale),"NumOtdelSht","")=="")
	{
	error=true;
	}
else
	{
	ScaleVP->NumberOtdelSht=StrToInt(ini->ReadString(IntToStr(IdScale),"NumOtdelSht",""));
	}

if (ini->ReadString(IntToStr(IdScale),"TypeSh","")=="")
	{
	error=true;
	}
else
	{
	ScaleVP->TypeBarCode=StrToInt(ini->ReadString(IntToStr(IdScale),"TypeSh",""));
	}

if (ini->ReadString(IntToStr(IdScale), "PrintDate","")=="YES")
		{
		ScaleVP->PrintDate=true;
		}
else
		{
		ScaleVP->PrintDate=false;
		}

if (ini->ReadString(IntToStr(IdScale), "PrintPrice","")=="YES")
		{
		ScaleVP->PrintPrice=true;
		}
else
		{
		ScaleVP->PrintPrice=false;
		}

if (ini->ReadString(IntToStr(IdScale), "PrintZnakSert","")=="YES")
		{
		ScaleVP->PrintSert=true;
		}
else
		{
		ScaleVP->PrintSert=false;
		}

ScaleVP->ReklamaStr1=ini->ReadString(IntToStr(IdScale), "ReklamaStr1", "");
ScaleVP->ReklamaStr2=ini->ReadString(IntToStr(IdScale), "ReklamaStr2", "");
ScaleVP->NeZaprogStr1=ini->ReadString(IntToStr(IdScale), "NeZaprogStr1", "");
ScaleVP->NeZaprogStr2=ini->ReadString(IntToStr(IdScale), "NeZaprogStr2", "");

delete ini;



if (error==true)
	{
	ShowMessage("Ошибка в параметрах этикетки!");
	}
else
	{
	ScaleVP->Error=false;
	ScaleVP->TextError="Ошибок нет";
	ScaleVP->SetNumber=SetNumber;
	ScaleVP->OpenPort(Port,BaudRate);
	ScaleVP->Operation=ScaleVP->SetParameterLabel_Operation;
	ScaleVP->Run=true;
	ScaleVP->Resume();
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ToolButtonOpenAboutClick(TObject *Sender)
{
ShowAbout();
}
//---------------------------------------------------------------------------
void TMainForm::ShowAbout(void)
{
TFormAbout * form=new TFormAbout(Application);
if (!form) return;
//настройка формы
form->NameProgramLabel->Caption="Панель управления весами ВП (Масса-К) ";
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
//----------------------------------------------------------------------------


void __fastcall TMainForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
		UnicodeString V="Вы хотите завершить работу с программой?";
        UnicodeString Z="Завершение работы";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
                {
                }
        else
                {
                CanClose=false;
				}	
}
//---------------------------------------------------------------------------


