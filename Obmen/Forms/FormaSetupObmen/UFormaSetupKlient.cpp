//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaSetupKlient.h"
#include "inifiles.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaSetupKlient::TFormaSetupKlient(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaSetupKlient::FormCreate(TObject *Sender)
{
AnsiString file_ini=Application->ExeName;
file_ini=file_ini.SetLength(file_ini.Length()-4)+".ini";
TIniFile * ini=new TIniFile(file_ini);

IPAdressEdit->Text=ini->ReadString("Server","IPAddress","");
PortEdit->Text=ini->ReadString("Server","Port","");

NameUserEdit->Text=ini->ReadString("User","NameUser","");
PasswordUserEdit->Text=ini->ReadString("User","Password","");

ConnectStringEdit->Text=ini->ReadString("InfBase","ConnectString","");

NameBaseForObmenEdit->Text=ini->ReadString("InfBaseForObmen","NameBase","");
IdBaseForObmenEdit->Text=ini->ReadString("InfBaseForObmen","IDBase","");

PatchArhEdit->Text=ini->ReadString("Arhivator", "Patch", "");
PatchUnArhEdit->Text=ini->ReadString("Arhivator", "PatchUnArh", "");

if (ini->ReadString("End", "ViklPC","")=="OK")
        {
        ViklPCCheckBox->State=cbChecked;
        }
else
        {
        ViklPCCheckBox->State=cbUnchecked;
		}

if (ini->ReadString("AutoObmen", "Run","")=="1")
        {
		AutoObmenCheckBox->State=cbChecked;
        }
else
        {
		AutoObmenCheckBox->State=cbUnchecked;
		}

IntervalEdit->Text=ini->ReadString("AutoObmen", "Interval", "0");
IntervalObmenaAfterErrorEdit->Text=ini->ReadString("AutoObmen", "IntervalAfterError", "0");

delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSetupKlient::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FOnCloseForm) FOnCloseForm(this);
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSetupKlient::ButtonViborFileArhClick(TObject *Sender)
{
if(OpenDialog1->Execute())
        {
        PatchArhEdit->Text=OpenDialog1->FileName;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaSetupKlient::ButtonSaveClick(TObject *Sender)
{
AnsiString file_ini=Application->ExeName;
file_ini=file_ini.SetLength(file_ini.Length()-4)+".ini";
TIniFile * ini=new TIniFile(file_ini);

ini->WriteString("Arhivator", "Patch", PatchArhEdit->Text);
ini->WriteString("Arhivator", "PatchUnArh", PatchUnArhEdit->Text);

ini->WriteString("Server","IPAddress",IPAdressEdit->Text);
ini->WriteString("Server","Port",PortEdit->Text);

ini->WriteString("User","NameUser",NameUserEdit->Text);
ini->WriteString("User","Password",PasswordUserEdit->Text);

ini->WriteString("InfBase","ConnectString",ConnectStringEdit->Text);

ini->WriteString("InfBaseForObmen","NameBase",NameBaseForObmenEdit->Text);
ini->WriteString("InfBaseForObmen","IDBase",IdBaseForObmenEdit->Text);



if (ViklPCCheckBox->Checked==true)
        {
		ini->WriteString("End", "ViklPC","OK");
        }
else
        {
        ini->WriteString("End", "ViklPC","NO");
		}

if (AutoObmenCheckBox->Checked==true)
        {
		ini->WriteString("AutoObmen", "Run","1");
        }
else
        {
		ini->WriteString("AutoObmen", "Run","0");
		}

ini->WriteString("AutoObmen","Interval",IntervalEdit->Text);
ini->WriteString("AutoObmen","IntervalAfterError",IntervalObmenaAfterErrorEdit->Text);
		

delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFormaSetupKlient::ButtonCloseClick(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSetupKlient::Button1Click(TObject *Sender)
{
if(OpenDialog1->Execute())
        {
        PatchUnArhEdit->Text=OpenDialog1->FileName;
        }
}
//---------------------------------------------------------------------------




