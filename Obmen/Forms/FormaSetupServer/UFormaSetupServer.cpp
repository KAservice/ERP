//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaSetupServer.h"
#include "UkanIniFile.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaSetupServer::TFormaSetupServer(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaSetupServer::FormCreate(TObject *Sender)
{
UnicodeString file_ini=Application->ExeName;
file_ini=file_ini.SetLength(file_ini.Length()-4)+".ini";
TkanIniFile * ini=new TkanIniFile(file_ini);


PortEdit->Text=ini->ReadString("Server","Port","");

NameUserEdit->Text=ini->ReadString("User","NameUser","");
PasswordUserEdit->Text=ini->ReadString("User","Password","");

ConnectStringEdit->Text=ini->ReadString("InfBase","ConnectString","");

NameBaseForObmenEdit->Text=ini->ReadString("InfBaseForObmen","NameBase","");
IdBaseForObmenEdit->Text=ini->ReadString("InfBaseForObmen","IDBase","");

PatchArhEdit->Text=ini->ReadString("Arhivator", "Patch", "");
PatchUnArhEdit->Text=ini->ReadString("Arhivator", "PatchUnArh", "");

delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSetupServer::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FOnCloseForm) FOnCloseForm(this);
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSetupServer::ButtonViborFileArhClick(TObject *Sender)
{
if(OpenDialog1->Execute())
        {
        PatchArhEdit->Text=OpenDialog1->FileName;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaSetupServer::ButtonSaveClick(TObject *Sender)
{
UnicodeString file_ini=Application->ExeName;
file_ini=file_ini.SetLength(file_ini.Length()-4)+".ini";
TkanIniFile * ini=new TkanIniFile(file_ini);

ini->WriteString("Arhivator", "Patch", PatchArhEdit->Text);
ini->WriteString("Arhivator", "PatchUnArh", PatchUnArhEdit->Text);

ini->WriteString("Server","Port",PortEdit->Text);

ini->WriteString("User","NameUser",NameUserEdit->Text);
ini->WriteString("User","Password",PasswordUserEdit->Text);

ini->WriteString("InfBase","ConnectString",ConnectStringEdit->Text);

ini->WriteString("InfBaseForObmen","NameBase",NameBaseForObmenEdit->Text);
ini->WriteString("InfBaseForObmen","IDBase",IdBaseForObmenEdit->Text);


delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFormaSetupServer::ButtonCloseClick(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSetupServer::Button1Click(TObject *Sender)
{
if(OpenDialog1->Execute())
        {
        PatchUnArhEdit->Text=OpenDialog1->FileName;
        }
}
//---------------------------------------------------------------------------


