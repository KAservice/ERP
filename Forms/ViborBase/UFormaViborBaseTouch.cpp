//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaViborBaseTouch.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaViborBaseTouch::TFormaViborBaseTouch(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TFormaViborBaseTouch::FormCreate(TObject *Sender)
{
OutReady=true;
CodeEdit->Text="";
PasswordEdit->Text="";
ListBox1->Clear();
AnsiString FileIni=Application->ExeName;
FileIni=FileIni.SetLength(FileIni.Length()-4)+".ini";
Ini=new TIniFile(FileIni);
NumberARM=0;
UpdateSpisok();
}
//----------------------------------------------------------------------
void __fastcall TFormaViborBaseTouch::EndEditParameterBase(TObject *Sender)
{
/////
if (FormaEditBase->OutReady==true)
        {
        //необходимо сохранить параметры базы
        Ini->WriteString("Base"+IntToStr(TekBase),
                                "Name",
                                FormaEditBase->NameBase->Text);
        Ini->WriteString("Base"+IntToStr(TekBase),
                                "ConnectString",
                                FormaEditBase->ConnectString->Text);
        Ini->WriteString("Base"+IntToStr(TekBase),
                                "ARM",
                                FormaEditBase->NumberARM->Text);
        }
UpdateSpisok();
IdDochForm=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborBaseTouch::ButtonCancelClick(TObject *Sender)
{
OutReady=false;

Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborBaseTouch::ButtonAddClick(TObject *Sender)
{
if  (IdDochForm==NULL)
		{
		FormaEditBase=new TFormaEditBase(Application);
		FormaEditBase->FOnCloseForm=EndEditParameterBase;
		IdDochForm=FormaEditBase->Handle;
		TekBase=AllKolBase+1;
		}
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborBaseTouch::ButtonOKClick(TObject *Sender)
{
ZapuskProgramm();
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborBaseTouch::ButtonRenameClick(TObject *Sender)
{
if(ListBox1->ItemIndex<0)
        {

        }
else
        {
        if  (IdDochForm==NULL)
                {
                FormaEditBase=new TFormaEditBase(Application);
                FormaEditBase->FOnCloseForm=EndEditParameterBase;
                IdDochForm=FormaEditBase->Handle;
                TekBase=ListBox1->ItemIndex+1;
                FormaEditBase->NameBase->Text=
                     Ini->ReadString("Base"+IntToStr(TekBase),"Name","");
                FormaEditBase->ConnectString->Text=
                     Ini->ReadString("Base"+IntToStr(TekBase),"ConnectString","");
                FormaEditBase->NumberARM->Text=
                     Ini->ReadString("Base"+IntToStr(TekBase),"ARM","");

                }
        }
}
//---------------------------------------------------------------------------
void TFormaViborBaseTouch::UpdateSpisok()
{
ListBox1->Clear();
AnsiString NameBase;
try
        {
        bool Povtor=true;
        AllKolBase=0;
        while (Povtor==true)
                {
                NameBase=Ini->ReadString("Base"+IntToStr(AllKolBase+1),"Name","");
                if (NameBase=="")
                        {
                        Povtor=false;
                        }
                else
                        {
                        ListBox1->Items->Add(NameBase);
                        AllKolBase++;
                        }
                }
        }
catch (...)
        {


		}
if (ListBox1->Items->Count>0)
	{
	ListBox1->ItemIndex=0;
	LabelFileName->Caption=
				Ini->ReadString("Base"+IntToStr(ListBox1->ItemIndex+1),"ConnectString","");
	}

}

//-------------------------------------------------------------------
void __fastcall TFormaViborBaseTouch::ListBox1Click(TObject *Sender)
{
if(ListBox1->ItemIndex<0)
        {

        }
else
        {

		LabelFileName->Caption=
				Ini->ReadString("Base"+IntToStr(ListBox1->ItemIndex+1),"ConnectString","");

        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborBaseTouch::ButtonDelClick(TObject *Sender)
{ 
int DelBase=ListBox1->ItemIndex+1;
AnsiString NameBase;
        bool Povtor=true;
        AllKolBase=DelBase;
        while (Povtor==true)
                {
                NameBase=Ini->ReadString("Base"+IntToStr(AllKolBase+1),"Name","");
                if (NameBase=="")
                        {
                        Ini->EraseSection("Base"+IntToStr(AllKolBase));
                        Povtor=false;
                        }
                else
                        { 
                        Ini->WriteString("Base"+IntToStr(AllKolBase),
                                "Name",
                                Ini->ReadString("Base"+IntToStr(AllKolBase+1),"Name",""));
                        Ini->WriteString("Base"+IntToStr(AllKolBase),
                                "ConnectString",
                                Ini->ReadString("Base"+IntToStr(AllKolBase+1),"ConnectString",""));
                        Ini->WriteString("Base"+IntToStr(AllKolBase),
                                "ARM",
                                Ini->ReadString("Base"+IntToStr(AllKolBase+1),"ARM",""));
                        AllKolBase++;
                        }
                }

UpdateSpisok();
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborBaseTouch::FormClose(TObject *Sender, TCloseAction &Action)
{
//try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}
delete Ini;
Action=caFree;
}
//---------------------------------------------------------------------------

void TFormaViborBaseTouch::ZapuskProgramm(void)
{
if (ListBox1->Items->Count<0)
	{
	ShowMessage("Необходимо выбрать информационную базу!");
	return;
	}
OutReady=true;
CloseForm=false;
CodeUser=StrToInt(CodeEdit->Text);
PasswordUser=PasswordEdit->Text; 
NumberARM=Ini->ReadInteger("Base"+IntToStr(ListBox1->ItemIndex+1),"ARM",0) ;
ConnectString=Ini->ReadString("Base"+IntToStr(ListBox1->ItemIndex+1),"ConnectString","");
if(FOnCloseForm) FOnCloseForm(this);
if (CloseForm==true)
        {
        Close();
        }
}
//--------------------------------------------------------------------------
void __fastcall TFormaViborBaseTouch::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("Общее описание/Создание подключения");		
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborBaseTouch::EndInputCodeUser(TObject *Sender)
{
if (Kalkulator->OutReady==true)
	{
	CodeEdit->Text=FloatToStr(Kalkulator->Result);
	}
Kalkulator=0;
}
//----------------------------------------------------------------------------
void __fastcall TFormaViborBaseTouch::EndInputPasswordUser(TObject *Sender)
{
if (Kalkulator->OutReady==true)
	{
	PasswordEdit->Text=FloatToStr(Kalkulator->Result);
	}
Kalkulator=0;
}
//----------------------------------------------------------------------------


void __fastcall TFormaViborBaseTouch::BitBtnInputCodeClick(TObject *Sender)
{
if (Kalkulator==0)
		{
		Kalkulator=new TKalkulator(Application);
		if (!Kalkulator) return;
		Kalkulator->FOnCloseForm=EndInputCodeUser;
		Kalkulator->ShowModal();
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborBaseTouch::BitBtnInputPasswordClick(TObject *Sender)
{
if (Kalkulator==0)
		{
		Kalkulator=new TKalkulator(Application);
		if (!Kalkulator) return;
		Kalkulator->Tablo->PasswordChar='*';
		Kalkulator->FOnCloseForm=EndInputPasswordUser;
		Kalkulator->ShowModal();
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborBaseTouch::ButtonUpClick(TObject *Sender)
{
if (ListBox1->ItemIndex==-1)
	{ //не выбран ни один элемент
	if (ListBox1->Items->Count>0)
		{
		ListBox1->ItemIndex=0;
		}
	}
else
	{
	if (ListBox1->ItemIndex==ListBox1->Items->Count-1)
		{//последний элемент
		}
	else
		{
		ListBox1->ItemIndex=ListBox1->ItemIndex+1;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborBaseTouch::ButtonDownClick(TObject *Sender)
{
if (ListBox1->ItemIndex==-1)
	{ //не выбран ни один элемент
	if (ListBox1->Items->Count>0)
		{
		ListBox1->ItemIndex=ListBox1->Items->Count-1;
		}
	}
else
	{
	if (ListBox1->ItemIndex==0)
		{//первый элемент
		}
	else
		{
		ListBox1->ItemIndex=ListBox1->ItemIndex-1;
		}
	}
}
//---------------------------------------------------------------------------

