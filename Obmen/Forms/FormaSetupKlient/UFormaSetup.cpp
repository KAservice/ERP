//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaSetup.h"
#include "UMainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaSetup::TFormaSetup(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaSetup::FormCreate(TObject *Sender)
{
IPAdressEdit->Text=MainForm->Ini->ReadString("Server","IPAddress","");
PortEdit->Text=MainForm->Ini->ReadString("Server","Port","");
PrefiksEdit->Text=MainForm->Ini->ReadString("Server","Prefiks","");

NameUserEdit->Text=MainForm->Ini->ReadString("User","NameUser","");
PasswordUserEdit->Text=MainForm->Ini->ReadString("User","Password","");

ConnectStringEdit->Text=MainForm->Ini->ReadString("InfBase","ConnectString","");

PatchArhEdit->Text=MainForm->Ini->ReadString("Arhivator", "Patch", "");
PatchUnArhEdit->Text=MainForm->Ini->ReadString("Arhivator", "PatchUnArh", "");

CatalogObmenaEdit->Text=MainForm->Ini->ReadString("CatalogObmena", "Patch",ExtractFileDir(Application->ExeName));
if (MainForm->Ini->ReadString("End", "ViklPC","")=="OK")
        {
        ViklPCCheckBox->State=cbChecked;
        }
else
        {
        ViklPCCheckBox->State=cbUnchecked;
		}


}
//---------------------------------------------------------------------------
void __fastcall TFormaSetup::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FOnCloseForm) FOnCloseForm(this);
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSetup::ButtonViborFileArhClick(TObject *Sender)
{
if(OpenDialog1->Execute())
        {
        PatchArhEdit->Text=OpenDialog1->FileName;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaSetup::ButtonSaveClick(TObject *Sender)
{
MainForm->Ini->WriteString("Arhivator", "Patch", PatchArhEdit->Text);
MainForm->Ini->WriteString("Arhivator", "PatchUnArh", PatchUnArhEdit->Text);

MainForm->Ini->WriteString("Server","IPAddress",IPAdressEdit->Text);
MainForm->Ini->WriteString("Server","Port",PortEdit->Text);
MainForm->Ini->WriteString("Server","Prefiks",PrefiksEdit->Text);

MainForm->Ini->WriteString("User","NameUser",NameUserEdit->Text);
MainForm->Ini->WriteString("User","Password",PasswordUserEdit->Text);

MainForm->Ini->WriteString("InfBase","ConnectString",ConnectStringEdit->Text);

MainForm->Ini->WriteString("Arhivator", "Patch",PatchArhEdit->Text);

MainForm->Ini->WriteString("CatalogObmena", "Patch",CatalogObmenaEdit->Text);

if (ViklPCCheckBox->Checked==true)
        {
        MainForm->Ini->WriteString("End", "ViklPC","OK");
        }
else
        {
        MainForm->Ini->WriteString("End", "ViklPC","NO");
		}

}
//---------------------------------------------------------------------------

void __fastcall TFormaSetup::ButtonCloseClick(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSetup::Button1Click(TObject *Sender)
{
if(OpenDialog1->Execute())
        {
        PatchUnArhEdit->Text=OpenDialog1->FileName;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaSetup::ButtonViborCatalogObmenaClick(TObject *Sender)
{
if(OpenDialog1->Execute())
        {
        CatalogObmenaEdit->Text=ExtractFileDir(OpenDialog1->FileName);
        }
}
//---------------------------------------------------------------------------

