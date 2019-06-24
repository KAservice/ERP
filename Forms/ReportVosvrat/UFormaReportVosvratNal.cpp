//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaReportVosvratNal.h"



//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtonEdit"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxLabel"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxPC"
#pragma link "cxStyles"
#pragma link "cxGridBandedTableView"
#pragma link "cxGridDBBandedTableView"
#pragma resource "*.dfm"
extern String CurrencyPropis(double Value);
//---------------------------------------------------------------------------
__fastcall TFormaReportVosvratNal::TFormaReportVosvratNal(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportVosvratNal::FormCreate(TObject *Sender)
{
PosConcxDateEdit->Date=Date();
PosNachcxDateEdit->Date=PosConcxDateEdit->Date-DayOf(PosConcxDateEdit->Date)+1;
PosConcxDateEdit->Date=Date()+EncodeTime(23,59,59,999);

IdKassa=0;
DM=new TDMReportVosvrat(Application);
NameKassacxButtonEdit->Text="";
NameFirmcxButtonEdit->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportVosvratNal::FormClose(TObject *Sender,
      TCloseAction &Action)
{
delete DM;
Action=caFree;
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportVosvratNal::cxButtonCreateClick(TObject *Sender)
{
DM->OpenReportNal(IdFirm, IdKassa, PosNachcxDateEdit->Date, PosConcxDateEdit->Date);
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportVosvratNal::cxButtonCloseClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
	   //выбор кассы

void TFormaReportVosvratNal::ViborKassa(void)
{
if (FormaSpiskaSprKKM==0)
	{
	FormaSpiskaSprKKM=new TFormaSpiskaSprKKM(Application);
	FormaSpiskaSprKKM->Vibor=true;
	FormaSpiskaSprKKM->FOnCloseForm=EndViborKassa; 
	}

}
//-----------------------------------------------------------------------------
void __fastcall TFormaReportVosvratNal::EndViborKassa(TObject *Sender)
{
if (FormaSpiskaSprKKM->OutReady==true)
	{
	IdKassa=FormaSpiskaSprKKM->DM->TableIDKKM->AsInt64;
	NameKassacxButtonEdit->Text=FormaSpiskaSprKKM->DM->TableNAMEKKM->AsString;
	}
FormaSpiskaSprKKM=0;

}
//----------------------------------------------------------------------------


void __fastcall TFormaReportVosvratNal::NameKassacxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborKassa();
		}break;
	case 1:
		{
		IdKassa=0;
		NameKassacxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------
	   //выбор фирмы

void TFormaReportVosvratNal::ViborFirm(void)
{
if (FormaSpiskaSprFirm==0)
	{
	FormaSpiskaSprFirm=new TFormaSpiskaSprFirm(Application);
	FormaSpiskaSprFirm->Vibor=true;
	FormaSpiskaSprFirm->FOnCloseForm=EndViborFirm;  
	}

}
//-----------------------------------------------------------------------------
void __fastcall TFormaReportVosvratNal::EndViborFirm(TObject *Sender)
{
if (FormaSpiskaSprFirm->OutReady==true)
	{
	IdFirm=FormaSpiskaSprFirm->DM->TableIDFIRM->AsInt64;
	NameFirmcxButtonEdit->Text=FormaSpiskaSprFirm->DM->TableNAMEFIRM->AsString; 
	}
FormaSpiskaSprFirm=0;

}
//----------------------------------------------------------------------------
void __fastcall TFormaReportVosvratNal::NameFirmcxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborFirm();
		}break;
	case 1:
		{
		IdFirm=0;
		NameFirmcxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------
void TFormaReportVosvratNal::PrintKM3()
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

x=1;
y=1;
PorNumberStr=1;
SumReport=0;

PrintForm->SS->BeginUpdate();
//шапка
OutputZagolovokKM3(PrintForm);

//таблица

DM->ReportNal->First();
while(!DM->ReportNal->Eof)
        {

		OutputStringKM3(PrintForm);

        DM->ReportNal->Next();
        }

OutputPodavalKM3(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();

}
//----------------------------------------------------------------------------
void __fastcall TFormaReportVosvratNal::cxButtonPrintKM3Click(TObject *Sender)
{
PrintKM3();	
}
//---------------------------------------------------------------------------
void TFormaReportVosvratNal::OutputZagolovokKM3(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
TRect rect;
TDMSprFirm *dm_spr_firm=new TDMSprFirm(Application);
dm_spr_firm->OpenElement(IdFirm);

prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
//prForm->SS->RowsAutoHeight=true;

        TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
		cHeader->Size[1] = 50;
		cHeader->Size[2] = 50;
		cHeader->Size[3] = 30;
		cHeader->Size[4] = 20;
		cHeader->Size[5] = 20;
		cHeader->Size[6] = 20;
		cHeader->Size[7] = 15;
		cHeader->Size[8] = 15;
		cHeader->Size[9] = 15;
		cHeader->Size[10] = 15;
		cHeader->Size[11] = 15;
		cHeader->Size[12] = 15;
		cHeader->Size[13] = 15;
		cHeader->Size[14] = 15;
		cHeader->Size[15] = 20;
		cHeader->Size[16] = 30;
		cHeader->Size[17] = 30;
		cHeader->Size[18] = 40;
		cHeader->Size[19] = 20;
		cHeader->Size[20] = 15;
		cHeader->Size[21] = 15;
		cHeader->Size[22] = 15;
		cHeader->Size[23] = 15;
		cHeader->Size[24] = 15;
		cHeader->Size[25] = 20;
		cHeader->Size[26] = 20;
		cHeader->Size[27] = 20;
		cHeader->Size[28] = 20;
		cHeader->Size[29] = 20;
		cHeader->Size[30] = 20;
		cHeader->Size[31] = 5;

x=30;
y=0;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "Унифицированная форма № КМ-3";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
prForm->SS->ActiveSheet->Rows->Size[y]=15;
y++;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "Утверждена постановлением Госкомстата";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
prForm->SS->ActiveSheet->Rows->Size[y]=15;
y++;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "России от 25.12.98 №132";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
prForm->SS->ActiveSheet->Rows->Size[y]=15;
y++;

x=24;
rect.Left = x;
rect.Top = y;
rect.Right = x+6;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "Код";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
y++;

x=23;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "Форма по ОКУД ";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+6;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "0330103";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
delete cell;
y++;

x=1;
rect.Left = x;
rect.Top = y;
rect.Right = x+18;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text = dm_spr_firm->ElementFNAMEFIRM->AsString;
delete cell;


for (int i=0;i<19;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

x=23;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "по ОКПО ";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+6;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = dm_spr_firm->ElementOKPOSFIRM->AsString;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
delete cell;
y++;


x=1;
rect.Left = x;
rect.Top = y;
rect.Right = x+19;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text = dm_spr_firm->ElementTELFIRM->AsString;
delete cell;


for (int i=0;i<20;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

x=23;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "ИНН ";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+6;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = dm_spr_firm->ElementINNFIRM->AsString;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
delete cell;
y++;

x=1;
rect.Left = x;
rect.Top = y;
rect.Right = x+22;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

for (int i=0;i<23;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

x=24;

rect.Left = x;
rect.Top = y;
rect.Right = x+6;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
delete cell;
y++;


x=8;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "(структурное подразделение)";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
delete cell;


x=23;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "Вид деятельности по ОКДП ";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haRIGHT;
delete cell;

x=24;
rect.Left = x;
rect.Top = y;
rect.Right = x+6;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
delete cell;
y++;



x=1;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "Контрольно-";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
delete cell;
x++;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+12;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = DM->ReportNalMODEL_DRKOROZN->AsString;
cell->Style->HorzTextAlign = haCENTER;
delete cell;

for (int i=0;i<13;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

x=17;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = " номер ";
cell->Style->HorzTextAlign = haRIGHT;
delete cell;

x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+5;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = " производителя ";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;

for (int i=0;i<6;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

rect.Left = x;
rect.Top = y;
rect.Right = x+6;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = DM->ReportNalSAVNUM_DRKOROZN->AsString;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
delete cell;
y++;



x=1;
rect.Left = x;
rect.Top = y;
rect.Right = x+1;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "кассовая машина";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
delete cell;

x=5;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "(модель(класс,тип,марка))";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haLEFT;
delete cell;



x=17;

x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+5;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = " регистрационный ";
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;

for (int i=0;i<6;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

rect.Left = x;
rect.Top = y;
rect.Right = x+6;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = DM->ReportNalREGNUM_DRKOROZN->AsString;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
delete cell;
y++;



x=1;
rect.Left = x;
rect.Top = y;
rect.Right = x+2;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "Прикладная программа";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 8;
delete cell;

x=4;


rect.Left = x;
rect.Top = y;
rect.Right = x+19;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

for (int i=0;i<20;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

rect.Left = x;
rect.Top = y;
rect.Right = x+6;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
delete cell;
y++;

x=23;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "Кассир";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
delete cell;

x++;

rect.Left = x;
rect.Top = y;
rect.Right = x+6;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
delete cell;
y++;


x=23;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "Вид операции";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
delete cell;

x++;

rect.Left = x;
rect.Top = y;
rect.Right = x+6;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
y++;
prForm->SS->ActiveSheet->Rows->Size[y]=10;
y++;

x=9;
rect.Left = x;
rect.Top = y;
rect.Right = x+6;
rect.Bottom = y+1;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Номер документа";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->WordBreak = true;
delete cell;
x++;

for (int i=0;i<6;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	delete cell;
	x++;
	}

rect.Left = x;
rect.Top = y;
rect.Right = x+2;
rect.Bottom = y+1;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Дата составления";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->WordBreak = true;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
x=24;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="УТВЕРЖДАЮ";
delete cell;

y++;

x=9;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
delete cell;
x=15;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
x=18;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
x=24;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Руководитель";
delete cell;

y++;

x=8;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="АКТ";
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+6;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
delete cell;

for (int i=0;i<7;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
	cell->Style->Borders->Edges [eTop]->Style=lsMedium;
	cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
	delete cell;
	x++;
	}

x=16;
rect.Left = x;
rect.Top = y;
rect.Right = x+2;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text=DateToStr(PosNachcxDateEdit->Date);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
delete cell;
x++;
x++;
x++;
x++;
x++;
rect.Left = x;
rect.Top = y;
rect.Right = x+7;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

for (int i=0;i<7;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

y++;
x=1;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="О ВОЗВРАТЕ ДЕНЕЖНЫХ СУММ ПОКУПАТЕЛЯМ (КЛИЕНТАМ)";
delete cell;
x=20;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;x++;

for (int i=0;i<6;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

y++;

x=2;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text=" ПО НЕИСПОЛЬЗОВАННЫМ КАССОВЫМ ЧЕКАМ";
delete cell;
x=20;
rect.Left = x;
rect.Top = y;
rect.Right = x+3;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text=" (подпись)";
cell->Style->VertTextAlign = vaTOP;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
delete cell;
x=25;
rect.Left = x;
rect.Top = y;
rect.Right = x+5;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text=" (расшифровка подписи)";
cell->Style->VertTextAlign = vaTOP;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
delete cell;

y++;
x=2;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text=" (в том числе по ошибочно пробитым кассовым чекам)";
delete cell;
x=21;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text=" \"";
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text=" \"";
delete cell;
x++;
for (int i=0;i<3;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text=" г. ";
delete cell;


y++;
prForm->SS->ActiveSheet->Rows->Size[y]=10;
y++;

x=2;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text=" Настоящий акт составлен комиссией, которая установила: ";
delete cell;

y++;
prForm->SS->ActiveSheet->Rows->Size[y]=10;
y++;

x=1;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->WordBreak = true;
cell->Text=" Номер по поряд- ку ";
cell->Style->Font->Size = 8;
delete cell;
x++;

rect.Left = x;
rect.Top = y;
rect.Right = x+5;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->WordBreak = true;
cell->Text=" Наименование отдела, секции ";
cell->Style->Font->Size = 8;
delete cell;
x++;
for (int i=0;i<5;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

rect.Left = x;
rect.Top = y;
rect.Right = x+3;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->WordBreak = true;
cell->Text=" Код бригады ";
cell->Style->Font->Size = 8;
delete cell;
x++;
for (int i=0;i<3;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

rect.Left = x;
rect.Top = y;
rect.Right = x+4;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->WordBreak = true;
cell->Text=" Номер чека ";
cell->Style->Font->Size = 8;
delete cell;
x++;
for (int i=0;i<4;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

rect.Left = x;
rect.Top = y;
rect.Right = x+5;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->WordBreak = true;
cell->Text=" Сумма чека, руб. коп. ";
cell->Style->Font->Size = 8;
delete cell;
x++;
for (int i=0;i<5;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

rect.Left = x;
rect.Top = y;
rect.Right = x+7;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->WordBreak = true;
cell->Text=" Должность, фамилия, и., о. лица, разрешившего возврат денег по чеку ";
cell->Style->Font->Size = 8;
delete cell;
x++;
for (int i=0;i<6;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	delete cell;


prForm->SS->ActiveSheet->Rows->Size[y]=60;

y++;

x=1;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=" 1 ";
delete cell;
x++;

rect.Left = x;
rect.Top = y;
rect.Right = x+5;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=" 2";
delete cell;
x++;
for (int i=0;i<5;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

rect.Left = x;
rect.Top = y;
rect.Right = x+3;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
cell->Text=" 3 ";
delete cell;
x++;
for (int i=0;i<3;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
	delete cell;
	x++;
	}

rect.Left = x;
rect.Top = y;
rect.Right = x+4;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
cell->Text=" 4 ";
delete cell;
x++;
for (int i=0;i<4;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
	delete cell;
	x++;
	}

rect.Left = x;
rect.Top = y;
rect.Right = x+5;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
cell->Text=" 5 ";
delete cell;
x++;
for (int i=0;i<5;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
	delete cell;
	x++;
	}

rect.Left = x;
rect.Top = y;
rect.Right = x+7;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=" 6 ";
delete cell;
x++;
for (int i=0;i<6;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	delete cell;

y++;




delete dm_spr_firm;
}
//----------------------------------------------------------------------------
void TFormaReportVosvratNal::OutputStringKM3(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
TRect rect;

x=1;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=IntToStr(PorNumberStr);
delete cell;
x++;

rect.Left = x;
rect.Top = y;
rect.Right = x+5;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
for (int i=0;i<5;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

rect.Left = x;
rect.Top = y;
rect.Right = x+3;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
for (int i=0;i<3;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

rect.Left = x;
rect.Top = y;
rect.Right = x+4;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=DM->ReportNalNCHECK_DRKOROZN->AsString;
delete cell;
x++;
for (int i=0;i<4;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

rect.Left = x;
rect.Top = y;
rect.Right = x+5;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=FloatToStrF(DM->ReportNalSUMDOC->AsFloat,ffFixed,15,2);
delete cell;
x++;
for (int i=0;i<5;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

rect.Left = x;
rect.Top = y;
rect.Right = x+7;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
for (int i=0;i<6;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	delete cell;

y++;
PorNumberStr++;
SumReport=SumReport+DM->ReportNalSUMDOC->AsFloat;
}
//-----------------------------------------------------------------------------
void TFormaReportVosvratNal::OutputPodavalKM3(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
TRect rect;
x=1;
for (int i=0;i<7;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	delete cell;
	x++;
	}

for (int i=0;i<15;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eTop]->Style=lsMedium;
	delete cell;
	x++;
	}

for (int i=0;i<7;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	delete cell;
	x++;
	}

x=16;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->HorzTextAlign = haRIGHT;
cell->Text=" Итого ";
delete cell;
x++;

rect.Left = x;
rect.Top = y;
rect.Right = x+5;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=FloatToStrF(SumReport,ffFixed,15,2);
delete cell;

for (int i=0;i<5;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

y++;
prForm->SS->ActiveSheet->Rows->Size[y]=10;
y++;
x=1;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="      Выдано покупателям (клиентам) по возвращенным ими кассовым чекам (по ошибочно пробитым";
delete cell;
y++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="чекам) согласно акту на сумму: ";
delete cell;
y++;

rect.Left = x;
rect.Top = y;
rect.Right = x+29;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="   "+CurrencyPropis(SumReport);
cell->Style->WordBreak = true;
cell->Style->VertTextAlign = vaTOP;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
delete cell;

prForm->SS->ActiveSheet->Rows->Size[y]=30;

y++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="   На указанную сумму следует уменьшить выручку кассы";
delete cell;
y++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="   Перечисленные возвращенные покупателями (клиентами) чеки (ошибочно пробитые чеки)";
delete cell;
y++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="погашены и прилагаются к акту. Приложение _____________________________";
delete cell;
y++;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text=" Члены комиссии: ";
delete cell;

y++;
x=1;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Заведующий отделом (секцией)";
delete cell;

x=7;
for (int i=0;i<8;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}
x++;
for (int i=0;i<15;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

y++;

x=9;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->VertTextAlign = vaCENTER;
cell->Text=" (подпись) ";
cell->Style->Font->Size = 8;
delete cell;
x=20;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->VertTextAlign = vaCENTER;
cell->Text=" (расшифровка подписи) ";
cell->Style->Font->Size = 8;
delete cell;

y++;

x=1;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Старший кассир";
delete cell;

x=7;
for (int i=0;i<8;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}
x++;
for (int i=0;i<15;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

y++;

x=9;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->VertTextAlign = vaCENTER;
cell->Text=" (подпись) ";
cell->Style->Font->Size = 8;
delete cell;
x=20;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->VertTextAlign = vaCENTER;
cell->Text=" (расшифровка подписи) ";
cell->Style->Font->Size = 8;
delete cell;

y++;

x=1;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Кассир - операционист";
delete cell;

x=7;
for (int i=0;i<8;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}
x++;
for (int i=0;i<15;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

y++;

x=9;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->VertTextAlign = vaCENTER;
cell->Text=" (подпись) ";
cell->Style->Font->Size = 8;
delete cell;
x=20;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->VertTextAlign = vaCENTER;
cell->Text=" (расшифровка подписи) ";
cell->Style->Font->Size = 8;
delete cell;

y++;

x=1;
for (int i=0;i<5;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

x=7;
for (int i=0;i<8;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}
x++;
for (int i=0;i<15;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

y++;

x=2;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->VertTextAlign = vaCENTER;
cell->Text=" (должность) ";
cell->Style->Font->Size = 8;
delete cell;

x=9;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->VertTextAlign = vaCENTER;
cell->Text=" (подпись) ";
cell->Style->Font->Size = 8;
delete cell;
x=20;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->VertTextAlign = vaCENTER;
cell->Text=" (расшифровка подписи) ";
cell->Style->Font->Size = 8;
delete cell;

y++;

x=1;
for (int i=0;i<5;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

x=7;
for (int i=0;i<8;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}
x++;
for (int i=0;i<15;i++)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	}

y++;

x=2;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->VertTextAlign = vaCENTER;
cell->Text=" (должность) ";
cell->Style->Font->Size = 8;
delete cell;

x=9;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->VertTextAlign = vaCENTER;
cell->Text=" (подпись) ";
cell->Style->Font->Size = 8;
delete cell;
x=20;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->VertTextAlign = vaCENTER;
cell->Text=" (расшифровка подписи) ";
cell->Style->Font->Size = 8;
delete cell;
}
//----------------------------------------------------------------------------
