//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaSetupScale.h"
#include "inifiles.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLabel"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
TFormSetupScale *FormSetupScale;
//---------------------------------------------------------------------------
__fastcall TFormSetupScale::TFormSetupScale(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormSetupScale::FormCreate(TObject *Sender)
{
///
}
//---------------------------------------------------------------------------
void  TFormSetupScale::UpdateForm(void)
{
LabelNameScale->Caption=NameScale;
AnsiString file_ini=ExtractFileDir(Application->ExeName)+"\\SetupScale.ini";

TIniFile * ini=new TIniFile(file_ini);

IPEdit->Text=ini->ReadString(IntToStr(IdOborud),"IP","");
PortEdit->Text=ini->ReadString(IntToStr(IdOborud),"Port","");
PrefiksBarCodeEdit->Text=ini->ReadString(IntToStr(IdOborud),"PrefiksBarCode","");
CodeSertMaskEdit->Text=ini->ReadString(IntToStr(IdOborud),"CodeSert","");
NumberLabelComboBox->Text=ini->ReadString(IntToStr(IdOborud),"NumberLabel","");
NumberOsnGrpComboBox->Text=ini->ReadString(IntToStr(IdOborud),"NumberOsnGrp","");
NumberBarCodeComboBox->Text=ini->ReadString(IntToStr(IdOborud),"NumberBarCode","");
NumberFontComboBox->Text=ini->ReadString(IntToStr(IdOborud),"NumberFont","");


delete ini;
}
//-----------------------------------------------------------------------------
void __fastcall TFormSetupScale::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;	
}
//---------------------------------------------------------------------------

void __fastcall TFormSetupScale::ButtonSaveClick(TObject *Sender)
{
AnsiString file_ini=ExtractFileDir(Application->ExeName)+"\\SetupScale.ini";

TIniFile * ini=new TIniFile(file_ini);

ini->WriteString(IntToStr(IdOborud), "Name", NameScale);
ini->WriteString(IntToStr(IdOborud), "IP", IPEdit->Text);
ini->WriteString(IntToStr(IdOborud), "Port",PortEdit->Text);

ini->WriteString(IntToStr(IdOborud),"PrefiksBarCode",PrefiksBarCodeEdit->Text);
ini->WriteString(IntToStr(IdOborud),"CodeSert",CodeSertMaskEdit->Text);

ini->WriteString(IntToStr(IdOborud),"NumberLabel",NumberLabelComboBox->Text);

ini->WriteString(IntToStr(IdOborud),"NumberOsnGrp",NumberOsnGrpComboBox->Text);

ini->WriteString(IntToStr(IdOborud),"NumberBarCode",NumberBarCodeComboBox->Text);

ini->WriteString(IntToStr(IdOborud),"NumberFont",NumberFontComboBox->Text);



delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFormSetupScale::ButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------


