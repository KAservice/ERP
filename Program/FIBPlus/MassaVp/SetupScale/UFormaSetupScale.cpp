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

VidLabelComboBox->Text=ini->ReadString(IntToStr(IdScale),"VidLabel","");
HeightLabelMaskEdit->Text=ini->ReadString(IntToStr(IdScale),"HeightLabel","");

NumberOtdelVesMaskEdit->Text=ini->ReadString(IntToStr(IdScale),"NumOtdelVes","");
NumberOtdelShtMaskEdit->Text=ini->ReadString(IntToStr(IdScale),"NumOtdelSht","");

TypeSHComboBox->Text=ini->ReadString(IntToStr(IdScale),"TypeSh","");
CodeSertMaskEdit->Text=ini->ReadString(IntToStr(IdScale),"CodeSert","");

if (ini->ReadString(IntToStr(IdScale),"TypeSrokGodn","")!="")
	{
	TypeSrokGodncxComboBox->ItemIndex=StrToInt(ini->ReadString(IntToStr(IdScale),"TypeSrokGodn",""));
	}
else
	{
	TypeSrokGodncxComboBox->ItemIndex=0;
	}
	
KolDopStringMaskEdit->Text=ini->ReadString(IntToStr(IdScale), "KolDopString", "");

ReklamaStr1Edit->Text=ini->ReadString(IntToStr(IdScale), "ReklamaStr1", "");
ReklamaStr2Edit->Text=ini->ReadString(IntToStr(IdScale), "ReklamaStr2", "");
NeZaprogStr1Edit->Text=ini->ReadString(IntToStr(IdScale), "NeZaprogStr1", "");
NeZaprogStr2Edit->Text=ini->ReadString(IntToStr(IdScale), "NeZaprogStr2", "");

if (ini->ReadString(IntToStr(IdScale), "PrintDate","")=="YES")
		{
		CheckBoxPrintDate->State=cbChecked;
		}
else
		{
		CheckBoxPrintDate->State=cbUnchecked;
		}

if (ini->ReadString(IntToStr(IdScale), "PrintPrice","")=="YES")
		{
		CheckBoxPrintPrice->State=cbChecked;
		}
else
		{
		CheckBoxPrintPrice->State=cbUnchecked;
		}

if (ini->ReadString(IntToStr(IdScale), "PrintZnakSert","")=="YES")
		{
		CheckBoxPrintZnakSert->State=cbChecked;
		}
else
		{
		CheckBoxPrintZnakSert->State=cbUnchecked;
		}

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

ini->WriteString(IntToStr(IdScale), "Name", NameScale);
ini->WriteString(IntToStr(IdScale), "VidLabel", VidLabelComboBox->Text);
ini->WriteString(IntToStr(IdScale), "HeightLabel",HeightLabelMaskEdit->Text);

ini->WriteString(IntToStr(IdScale),"NumOtdelVes",NumberOtdelVesMaskEdit->Text);
ini->WriteString(IntToStr(IdScale),"NumOtdelSht",NumberOtdelShtMaskEdit->Text);

ini->WriteString(IntToStr(IdScale),"TypeSh",TypeSHComboBox->Text);
ini->WriteString(IntToStr(IdScale),"CodeSert",CodeSertMaskEdit->Text);
ini->WriteString(IntToStr(IdScale),"TypeSrokGodn",TypeSrokGodncxComboBox->ItemIndex);

ini->WriteString(IntToStr(IdScale),"KolDopString",KolDopStringMaskEdit->Text);

ini->WriteString(IntToStr(IdScale),"ReklamaStr1",ReklamaStr1Edit->Text);
ini->WriteString(IntToStr(IdScale),"ReklamaStr2",ReklamaStr2Edit->Text);

ini->WriteString(IntToStr(IdScale),"NeZaprogStr1",NeZaprogStr1Edit->Text);
ini->WriteString(IntToStr(IdScale),"NeZaprogStr2",NeZaprogStr2Edit->Text);

if (CheckBoxPrintDate->Checked==true)
        {
		ini->WriteString(IntToStr(IdScale), "PrintDate","YES");
		}
else
		{
		ini->WriteString(IntToStr(IdScale), "PrintDate","NO");
		}

if (CheckBoxPrintPrice->Checked==true)
        {
		ini->WriteString(IntToStr(IdScale), "PrintPrice","YES");
		}
else
		{
		ini->WriteString(IntToStr(IdScale), "PrintPrice","NO");
		}

if (CheckBoxPrintZnakSert->Checked==true)
        {
		ini->WriteString(IntToStr(IdScale), "PrintZnakSert","YES");
		}
else
		{
		ini->WriteString(IntToStr(IdScale), "PrintZnakSert","NO");
		}
delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFormSetupScale::ButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------

