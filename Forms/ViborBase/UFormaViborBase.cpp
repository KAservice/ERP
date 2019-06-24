//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UFormaViborBase.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxListBox"
#pragma link "cxTextEdit"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaViborBase::TFormaViborBase(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TFormaViborBase::FormCreate(TObject *Sender)
{
OutReady=true;
ListBox1->Clear();
AnsiString FileIni=Application->ExeName;
FileIni=FileIni.SetLength(FileIni.Length()-4)+".ini";
Ini=new TIniFile(FileIni);
NumberARM=0;
UpdateSpisok();
}
//----------------------------------------------------------------------
void __fastcall TFormaViborBase::EndEditParameterBase(TObject *Sender)
{
///
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
void TFormaViborBase::UpdateSpisok()
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
	User->Text=Ini->ReadString("Base"+IntToStr(ListBox1->ItemIndex+1),"NameUser","");
	Password->Text=Ini->ReadString("Base"+IntToStr(ListBox1->ItemIndex+1),"PasswordUser","");
	}
}

//-------------------------------------------------------------------


void __fastcall TFormaViborBase::FormClose(TObject *Sender, TCloseAction &Action)
{
delete Ini;
Action=caFree;        
}
//---------------------------------------------------------------------------

void TFormaViborBase::ZapuskProgramm(void)
{
OutReady=true;
CloseForm=false;
NameUser=User->Text;
PasswordUser=Password->Text; 
NumberARM=Ini->ReadInteger("Base"+IntToStr(ListBox1->ItemIndex+1),"ARM",0) ;
ConnectString=Ini->ReadString("Base"+IntToStr(ListBox1->ItemIndex+1),"ConnectString","");
if(FOnCloseForm) FOnCloseForm(this);
if (CloseForm==true)
        {
        Close();
        }
}
//--------------------------------------------------------------------------
void __fastcall TFormaViborBase::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("CreateConnect");		
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborBase::ListBox1Click(TObject *Sender)
{
if(ListBox1->ItemIndex<0)
		{

		}
else
		{
        TekBase=ListBox1->ItemIndex+1;
		LabelFileName->Caption=
				Ini->ReadString("Base"+IntToStr(ListBox1->ItemIndex+1),"ConnectString","");
		User->Text=Ini->ReadString("Base"+IntToStr(ListBox1->ItemIndex+1),"NameUser","");
		Password->Text=Ini->ReadString("Base"+IntToStr(ListBox1->ItemIndex+1),"PasswordUser","");
		OldNameUser=User->Text;
		}	
}
//---------------------------------------------------------------------------


void __fastcall TFormaViborBase::UserKeyPress(TObject *Sender, char &Key)
{
if (Key==VK_RETURN) Password->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborBase::PasswordKeyPress(TObject *Sender, char &Key)
{
if (Key==VK_RETURN) ZapuskProgramm();	
}
//---------------------------------------------------------------------------
void TFormaViborBase::SaveNameUser(void)
{

	Ini->WriteString("Base"+IntToStr(TekBase),
								"NameUser",
								NameUser);

}
//----------------------------------------------------------------------------
void TFormaViborBase::ClearNameUser(void)
{

	Ini->WriteString("Base"+IntToStr(TekBase),
								"NameUser",
								"");

}
//----------------------------------------------------------------------------
void __fastcall TFormaViborBase::ActionAddExecute(TObject *Sender)
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

void __fastcall TFormaViborBase::ActionEditExecute(TObject *Sender)
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

void __fastcall TFormaViborBase::ActionDeleteExecute(TObject *Sender)
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

void __fastcall TFormaViborBase::ActionOKExecute(TObject *Sender)
{
ZapuskProgramm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborBase::ActionCloseExecute(TObject *Sender)
{
OutReady=false;
try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}
}
//---------------------------------------------------------------------------

