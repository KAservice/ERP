//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaSetupObmen.h"
#include "UkanIniFile.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtonEdit"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGroupBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxMaskEdit"
#pragma link "cxRadioGroup"
#pragma link "cxTextEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma link "cxPC"
#pragma link "cxLabel"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaSetupObmen::TFormaSetupObmen(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaSetupObmen::FormCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TFormaSetupObmen::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FOnCloseForm) FOnCloseForm(this);
Action=caFree;
}
//---------------------------------------------------------------------------
void TFormaSetupObmen::UpdateForm(void)
{
NameUserEdit->Text="EXTUSER";
UnicodeString catalog=ExtractFilePath(Application->ExeName);
UnicodeString file_ini=catalog+GC_FileNameIni;
TkanIniFile * ini=new TkanIniFile(file_ini);



//NameUserEdit->Text=ini->ReadString("User","NameUser","");

PasswordUserEdit->Text=ini->ReadString(IntToStr(IdBaseForObmen),"UserPassword","");

ConnectStringcxButtonEdit->Text=ini->ReadString(IntToStr(IdBaseForObmen),"InfBaseConnectString","");

NameBaseForObmenEdit->Text=ini->ReadString(IntToStr(IdBaseForObmen),GC_NameIniParameter_NameBaseForObmen,"");
IdBaseForObmenEdit->Text=ini->ReadString(IntToStr(IdBaseForObmen),GC_NameIniParameter_IdBaseForObmen,"");


if (ini->ReadString(IntToStr(IdBaseForObmen),GC_NameIniParameter_TypeObmen,"")=="1")
		{
		CatalogObmenacxRadioButton->Checked=true;
		}
	else
		{
		MAPIcxRadioButton->Checked=true;
		}


if (ini->ReadString(IntToStr(IdBaseForObmen), "AutoObmenRun","")=="1")
		{
		AutoObmenCheckBox->Checked=true;
        }
else
        {
		AutoObmenCheckBox->Checked=false;
		}

IntervalEdit->Text=ini->ReadString(IntToStr(IdBaseForObmen), "AutoObmenInterval", "0");
IntervalObmenaAfterErrorEdit->Text=ini->ReadString(IntToStr(IdBaseForObmen), "AutoObmenIntervalAfterError", "0");


CatalogObmenacxButtonEdit->Text=ini->ReadString(IntToStr(IdBaseForObmen), "CatalogObmenaPatch", "");

//настройки MAPI
EMailcxTextEdit->Text=ini->ReadString(IntToStr(IdBaseForObmen), GC_NameIniParameter_EMail, "");


delete ini;

}
//----------------------------------------------------------------------------
void __fastcall TFormaSetupObmen::ButtonSaveClick(TObject *Sender)
{
UnicodeString catalog=ExtractFilePath(Application->ExeName);
UnicodeString file_ini=catalog+GC_FileNameIni;
TkanIniFile * ini=new TkanIniFile(file_ini);

ini->WriteString(IdBaseForObmenEdit->Text,"UserNameUser",NameUserEdit->Text);
ini->WriteString(IdBaseForObmenEdit->Text,"UserPassword",PasswordUserEdit->Text);

ini->WriteString(IdBaseForObmenEdit->Text,"InfBaseConnectString",ConnectStringcxButtonEdit->Text);

ini->WriteString(IdBaseForObmenEdit->Text,GC_NameIniParameter_NameBaseForObmen,NameBaseForObmenEdit->Text);
ini->WriteString(IdBaseForObmenEdit->Text,GC_NameIniParameter_IdBaseForObmen,IdBaseForObmenEdit->Text);



if (MAPIcxRadioButton->Checked==true)
		{
		ini->WriteString(IdBaseForObmenEdit->Text,GC_NameIniParameter_TypeObmen,"2");
		}
else
		{
		ini->WriteString(IdBaseForObmenEdit->Text,GC_NameIniParameter_TypeObmen,"1");
		}



if (AutoObmenCheckBox->Checked==true)
        {
		ini->WriteString(IdBaseForObmenEdit->Text, "AutoObmenRun","1");
        }
else
        {
		ini->WriteString(IdBaseForObmenEdit->Text, "AutoObmenRun","0");
		}

ini->WriteString(IdBaseForObmenEdit->Text,"AutoObmenInterval",IntervalEdit->Text);
ini->WriteString(IdBaseForObmenEdit->Text,"AutoObmenIntervalAfterError",IntervalObmenaAfterErrorEdit->Text);


ini->WriteString(IdBaseForObmenEdit->Text,"CatalogObmenaPatch",CatalogObmenacxButtonEdit->Text);


//настройки MAPI
ini->WriteString(IdBaseForObmenEdit->Text,GC_NameIniParameter_EMail,EMailcxTextEdit->Text);


delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFormaSetupObmen::ButtonCloseClick(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------


void __fastcall TFormaSetupObmen::ConnectStringcxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if(OpenDialog1->Execute())
		{
		ConnectStringcxButtonEdit->Text=OpenDialog1->FileName;
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSetupObmen::CatalogObmenacxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if(OpenDialog1->Execute())
		{
		CatalogObmenacxButtonEdit->Text=ExtractFilePath(OpenDialog1->FileName);
		}
}
//---------------------------------------------------------------------------

