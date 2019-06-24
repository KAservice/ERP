//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UHOT_FormaReportSostNF2.h"
#include "UHOT_ReportSostNF.h"
#include "DateUtils.hpp"
#include "UDMSprUser.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "cxButtonEdit"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtons"
#pragma link "cxCalendar"
#pragma link "cxDropDownEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxGridBandedTableView"
#pragma resource "*.dfm"
extern TDMSprUser * glUser;
//---------------------------------------------------------------------------
__fastcall THOT_FormaReportSostNF2::THOT_FormaReportSostNF2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaReportSostNF2::FormCreate(TObject *Sender)
{
PosConcxDateEdit->Date=Date()+EncodeTime(23,59,59,999);
PosNachcxDateEdit->Date=glUser->GetPosNachReport();

NameObjectcxButtonEdit->Text="";
NameCatcxButtonEdit->Text="";
NameNomercxButtonEdit->Text="";
NameSostcxButtonEdit->Text="";

}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaReportSostNF2::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(HOT_FormaSpiskaSprObject) HOT_FormaSpiskaSprObject->Close();
if(HOT_FormaSpiskaSprCatNom) HOT_FormaSpiskaSprCatNom->Close();
if(HOT_FormaSpiskaSprNF) HOT_FormaSpiskaSprNF->Close();
if(HOT_FormaSpiskaSprSostNom) HOT_FormaSpiskaSprSostNom->Close();


SostNF->Active=false;
Action=caFree;
}

//----------------------------------------------------------------------------

void __fastcall THOT_FormaReportSostNF2::ActionOpenHelpExecute(
      TObject *Sender)
{
Application->HelpJump("ReportSostNF");
}
//---------------------------------------------------------------------------



void __fastcall THOT_FormaReportSostNF2::cxButtonCreateReportClick(
	  TObject *Sender)
{

TDate tek_date=PosNachcxDateEdit->Date;

cxGrid1BandedTableView1->ClearItems();

//удалим все строки
TcxCustomDataController *dc = cxGrid1BandedTableView1->DataController;
dc->BeginUpdate();

	for (int i=dc->RecordCount;i>0;i--)
		{
		dc->DeleteRecord(i-1);
		}



	TcxGridBandedColumn* GridColumn;

	GridColumn = cxGrid1BandedTableView1->CreateColumn();
	GridColumn->Caption = "Категория";
	GridColumn->DataBinding->ValueTypeClass = __classid(TcxStringValueType);
	GridColumn->Position->BandIndex=0;
	GridColumn->Width = 150;

	GridColumn = cxGrid1BandedTableView1->CreateColumn();
	GridColumn->Caption = "Номер";
	GridColumn->DataBinding->ValueTypeClass = __classid(TcxStringValueType);
	GridColumn->Position->BandIndex=0;
	GridColumn->Width = 60;

int max_kol_col=0;

while(tek_date<=PosConcxDateEdit->Date)
	{ 
	TcxGridBandedColumn* GridColumn;
	GridColumn = cxGrid1BandedTableView1->CreateColumn();
	GridColumn->Caption = DateToStr(tek_date);
	GridColumn->DataBinding->ValueTypeClass = __classid(TcxStringValueType);
	GridColumn->Position->BandIndex=1;
	GridColumn->Width = 20;


	GridColumn = cxGrid1BandedTableView1->CreateColumn();
	GridColumn->Caption = "";
	GridColumn->DataBinding->ValueTypeClass = __classid(TcxStringValueType);
	GridColumn->Position->BandIndex=1;
	GridColumn->Width = 20;


	GridColumn = cxGrid1BandedTableView1->CreateColumn();
	GridColumn->Caption = "";
	GridColumn->DataBinding->ValueTypeClass = __classid(TcxStringValueType);
	GridColumn->Position->BandIndex=1;
	GridColumn->Width = 20;


	GridColumn = cxGrid1BandedTableView1->CreateColumn();
	GridColumn->Caption = "";
	GridColumn->DataBinding->ValueTypeClass = __classid(TcxStringValueType);
	GridColumn->Position->BandIndex=1;
	GridColumn->Width = 20;

	tek_date++;
	max_kol_col++;
	}

//ShowMessage("Добавлено колонок без учета левого поля "+IntToStr(max_kol_col));

SostNF->Active=false;
SostNF->SelectSQL->Clear();
SostNF->SelectSQL->Add(GetTextQuery());
SostNF->ParamByName("PARAM_POSNACH")->AsDateTime=PosNachcxDateEdit->Date;
SostNF->ParamByName("PARAM_POSCON")->AsDateTime=PosConcxDateEdit->Date;
SostNF->Active=true;

SostNF->First();

__int64 id_tec_nomer=-1; 
int tec_column_left_margin=0;
int num_first_row;

while(!SostNF->Eof)
	{
	if (id_tec_nomer!=glStrToInt64(SostNFID_HOT_SNF->AsString))
		{ //начинаем обрабатывать новый номер
		num_first_row=dc->RecordCount;  //слежующая строка
		//количество мест в номере
		for (int i=1;i<=SostNFKOLM_HOT_SNF->AsInteger;i++)
			{
			dc->AppendRecord();
			tec_column_left_margin=0;
			dc->Values[num_first_row+i-1][tec_column_left_margin] = SostNFNAME_HOT_SCATNOM->AsString;
			tec_column_left_margin++;
			dc->Values[num_first_row+i-1][tec_column_left_margin] = SostNFNAME_HOT_SNF->AsString;
			tec_column_left_margin++;
			}
		OutputSost(tec_column_left_margin,num_first_row);
		}
	else
		{
		OutputSost(tec_column_left_margin,num_first_row);
		}

	SostNF->Next();
	}

dc->EndUpdate();

}
//---------------------------------------------------------------------------
void THOT_FormaReportSostNF2::OutputSost(int tec_column_left_margin, int num_first_row)
{
TcxCustomDataController *dc = cxGrid1BandedTableView1->DataController;
int num_first_col=GetPosStart()+tec_column_left_margin;
int num_end_col=GetPosFinish()+tec_column_left_margin;

		int num_tec_col=num_first_col;
		while(num_tec_col<=num_end_col)
			{
			for (int i=1;i<=SostNFKOLM_HOT_SOSTNF->AsInteger;i++)
				{
				if((num_first_row+i)>(dc->RecordCount))
					{
					dc->AppendRecord();
					tec_column_left_margin=0;
					dc->Values[num_first_row+i-1][tec_column_left_margin] = SostNFNAME_HOT_SCATNOM->AsString;
					tec_column_left_margin++;
					dc->Values[num_first_row+i-1][tec_column_left_margin] = SostNFNAME_HOT_SNF->AsString;
					tec_column_left_margin++;
					}
				try
					{
					if (num_tec_col>=(cxGrid1BandedTableView1->ColumnCount-tec_column_left_margin)-1)
						{
						TcxGridBandedColumn* GridColumn;
						GridColumn = cxGrid1BandedTableView1->CreateColumn();
//						GridColumn->Caption = DateToStr(tek_date);
						GridColumn->DataBinding->ValueTypeClass = __classid(TcxStringValueType);
						GridColumn->Position->BandIndex=1;
						GridColumn->Width = 20;
						}

					dc->Values[num_first_row+i-1][num_tec_col] =SostNF->RecNo;
					}
				catch (...)
					{
					ShowMessage("Ошибка строка "+IntToStr(num_first_row+i)+" колонка "+IntToStr(num_tec_col));
					}
				}
			num_tec_col++;
			}
}
//---------------------------------------------------------------------------
int THOT_FormaReportSostNF2::GetPosStart(void)
{
int result=0;
		//определяем позицию начала

		if (SostNFPOSNACH_HOT_SOSTNF->AsDateTime>PosNachcxDateEdit->Date)
			{
			result=(SostNFPOSNACH_HOT_SOSTNF->AsDateTime-PosNachcxDateEdit->Date);
			result=result*4;

			unsigned short year,month,day,hour,min,sec,msec;
			DecodeDateTime(SostNFPOSNACH_HOT_SOSTNF->AsDateTime,year,month,day,hour,min,sec,msec);

			if ( EncodeDateTime(year,month,day,0,0,0,0)<SostNFPOSNACH_HOT_SOSTNF->AsDateTime &&
					SostNFPOSNACH_HOT_SOSTNF->AsDateTime<=EncodeDateTime(year,month,day,6,0,0,0))
				{
				result=result;
				}

			if ( EncodeDateTime(year,month,day,6,0,0,0)<SostNFPOSNACH_HOT_SOSTNF->AsDateTime &&
					SostNFPOSNACH_HOT_SOSTNF->AsDateTime<=EncodeDateTime(year,month,day,12,0,0,0))
				{
				result=result+1;
				}

			if ( EncodeDateTime(year,month,day,12,0,0,0)<SostNFPOSNACH_HOT_SOSTNF->AsDateTime  &&
					SostNFPOSNACH_HOT_SOSTNF->AsDateTime<=EncodeDateTime(year,month,day,18,0,0,0))
				{
				result=result+2;
				}
			if ( EncodeDateTime(year,month,day,18,0,0,0)<SostNFPOSNACH_HOT_SOSTNF->AsDateTime &&
					SostNFPOSNACH_HOT_SOSTNF->AsDateTime<=EncodeDateTime(year,month,day,23,59,59,999))
				{
				result=result+3;
				}

			}
		else
			{
			result=0;
			}


return result;
}
//----------------------------------------------------------------------------
int THOT_FormaReportSostNF2::GetPosFinish(void)
{
int result=0;
		//определяем позицию конца

		if (SostNFPOSCON_HOT_SOSTNF->AsDateTime<=PosConcxDateEdit->Date)
			{
			result=SostNFPOSCON_HOT_SOSTNF->AsDateTime-PosNachcxDateEdit->Date;
			result=result*4;
			WORD year,month,day,hour,min,sec,msec;
			DecodeDateTime(SostNFPOSCON_HOT_SOSTNF->AsDateTime,year,month,day,hour,min,sec,msec);

			if ( EncodeDateTime(year,month,day,0,0,0,0)<SostNFPOSCON_HOT_SOSTNF->AsDateTime &&
					SostNFPOSCON_HOT_SOSTNF->AsDateTime<=EncodeDateTime(year,month,day,6,0,0,0))
				{
				result=result;
				}

			if ( EncodeDateTime(year,month,day,6,0,0,0)<SostNFPOSCON_HOT_SOSTNF->AsDateTime &&
					SostNFPOSCON_HOT_SOSTNF->AsDateTime<=EncodeDateTime(year,month,day,12,0,0,0))
				{
				result=result+1;
				}

			if ( EncodeDateTime(year,month,day,12,0,0,0)<SostNFPOSCON_HOT_SOSTNF->AsDateTime  &&
					SostNFPOSCON_HOT_SOSTNF->AsDateTime<=EncodeDateTime(year,month,day,18,0,0,0))
				{
				result=result+2;
				}
			if ( EncodeDateTime(year,month,day,18,0,0,0)<SostNFPOSCON_HOT_SOSTNF->AsDateTime &&
					SostNFPOSCON_HOT_SOSTNF->AsDateTime<=EncodeDateTime(year,month,day,23,59,59,999))
				{
				result=result+3;
				}


			}
		else
			{
			result=(PosConcxDateEdit->Date-PosNachcxDateEdit->Date);
			result=result*4+3;
			}


return result;
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaReportSostNF2::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------
//выбор объекта
void THOT_FormaReportSostNF2::ViborObject(void)
{
if (HOT_FormaSpiskaSprObject>0) return;

HOT_FormaSpiskaSprObject=new THOT_FormaSpiskaSprObject(Application);
if (!HOT_FormaSpiskaSprObject) return;
//настройка формы
HOT_FormaSpiskaSprObject->Vibor=true;
HOT_FormaSpiskaSprObject->FOnCloseForm=EndViborObject;
HOT_FormaSpiskaSprObject->Show();
}
//-----------------------------------------------------------------------------
void __fastcall THOT_FormaReportSostNF2::EndViborObject(TObject *Sender)
{
if  (HOT_FormaSpiskaSprObject->OutReady==true)
	{
	IdObject=HOT_FormaSpiskaSprObject->DM->TableID_HOT_SOBJECT->AsInt64;
	NameObjectcxButtonEdit->Text=HOT_FormaSpiskaSprObject->DM->TableNAME_HOT_SOBJECT->AsString;
	}

HOT_FormaSpiskaSprObject=0;
}
//----------------------------------------------------------------------------
//выбор категории номера
void THOT_FormaReportSostNF2::ViborCatNom(void)
{
if (HOT_FormaSpiskaSprCatNom>0) return;

HOT_FormaSpiskaSprCatNom=new THOT_FormaSpiskaSprCatNom(Application);
if (!HOT_FormaSpiskaSprCatNom) return;
//настройка формы
HOT_FormaSpiskaSprCatNom->Vibor=true;
HOT_FormaSpiskaSprCatNom->FOnCloseForm=EndViborCatNom;
HOT_FormaSpiskaSprCatNom->Show();

}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaReportSostNF2::EndViborCatNom(TObject *Sender)
{
if  (HOT_FormaSpiskaSprCatNom->OutReady==true)
	{
	IdCat=HOT_FormaSpiskaSprCatNom->DM->TableID_HOT_SCATNOM->AsInt64;
	NameCatcxButtonEdit->Text=HOT_FormaSpiskaSprCatNom->DM->TableNAME_HOT_SCATNOM->AsString;
	}

HOT_FormaSpiskaSprCatNom=0;

}
//----------------------------------------------------------------------------

//выбор номера
//----------------------------------------------------------------------------
void THOT_FormaReportSostNF2::ViborNF(void)
{
if (HOT_FormaSpiskaSprNF>0) return;

HOT_FormaSpiskaSprNF=new THOT_FormaSpiskaSprNF(Application);
if (!HOT_FormaSpiskaSprNF) return;
//настройка формы
HOT_FormaSpiskaSprNF->Vibor=true;
HOT_FormaSpiskaSprNF->FOnCloseForm=EndViborNF;
HOT_FormaSpiskaSprNF->Show();

}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaReportSostNF2::EndViborNF(TObject *Sender)
{
if  (HOT_FormaSpiskaSprNF->OutReady==true)
	{
	IdNomer=HOT_FormaSpiskaSprNF->DM->TableID_HOT_SNF->AsInt64;
	NameNomercxButtonEdit->Text=HOT_FormaSpiskaSprNF->DM->TableNAME_HOT_SNF->AsString;
	}

HOT_FormaSpiskaSprNF=0;

}
//----------------------------------------------------------------------------
//выбор состояния номера
void THOT_FormaReportSostNF2::ViborSostNom(void)
{
if (HOT_FormaSpiskaSprSostNom>0) return;

HOT_FormaSpiskaSprSostNom=new THOT_FormaSpiskaSprSostNom(Application);
if (!HOT_FormaSpiskaSprSostNom) return;
//настройка формы
HOT_FormaSpiskaSprSostNom->Vibor=true;
HOT_FormaSpiskaSprSostNom->FOnCloseForm=EndViborSostNom;
HOT_FormaSpiskaSprSostNom->Show();

}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaReportSostNF2::EndViborSostNom(TObject *Sender)
{
if  (HOT_FormaSpiskaSprSostNom->OutReady==true)
	{
	IdSost=HOT_FormaSpiskaSprSostNom->DM->TableID_HOT_SSOSTNOM->AsInt64;
	NameSostcxButtonEdit->Text=HOT_FormaSpiskaSprSostNom->DM->TableNAME_HOT_SSOSTNOM->AsString;
	}

HOT_FormaSpiskaSprSostNom=0;

}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaReportSostNF2::NameObjectcxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (AButtonIndex==0)
	{
	ViborObject();
	}

if (AButtonIndex==1)
	{
	IdObject=0;
	NameObjectcxButtonEdit->Text="";
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaReportSostNF2::NameCatcxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (AButtonIndex==0)
	{
	ViborCatNom();
	}

if (AButtonIndex==1)
	{
	IdCat=0;
	NameCatcxButtonEdit->Text="";
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaReportSostNF2::NameNomercxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (AButtonIndex==0)
	{
	ViborNF();
	}

if (AButtonIndex==1)
	{
	IdNomer=0;
	NameNomercxButtonEdit->Text="";
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaReportSostNF2::NameSostcxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (AButtonIndex==0)
	{
	ViborSostNom();
	}

if (AButtonIndex==1)
	{
	IdSost=0;
	NameSostcxButtonEdit->Text="";
	}
}
//---------------------------------------------------------------------------


void __fastcall THOT_FormaReportSostNF2::cxGrid1BandedTableView1CustomDrawCell(
      TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
      TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone)
{
//AnsiString ATextToDraw;
//if (dynamic_cast<TcxGridTableDataCellViewInfo *>(AViewInfo) != NULL)
//	{
//	ATextToDraw = AViewInfo->GridRecord->DisplayTexts[AViewInfo->Item->Index];
//	}
//else
//	{
//	ATextToDraw = VarAsType(AViewInfo->Item->Caption, varString);
//	}
//
//if (ATextToDraw!="" && AViewInfo->Item->Index>=2)
//	{
//	if (StrToInt(ATextToDraw)>0)
//		{
//		TRect ARec = AViewInfo->Bounds;
//		ACanvas->Canvas->Brush->Color = clBlue;
//		ACanvas->Canvas->FillRect(ARec);
//		//ACanvas->Canvas->Draw((ARec.Left+ARec.Right-ABitmap->Width)/2,ARec.Top,ABitmap);
//		ADone = true;
//		}
//	}
}
//---------------------------------------------------------------------------
AnsiString THOT_FormaReportSostNF2::GetTextQuery(void)
{

AnsiString result=" select hot_sostnf.id_hot_sostnf, "
"        hot_scatnom.id_hot_scatnom,        "
"        hot_scatnom.name_hot_scatnom,      "
"        hot_snf.id_hot_snf,                "
"        hot_snf.name_hot_snf,              "
"        hot_snf.kolm_hot_snf,              "
"        hot_ssostnom.id_hot_ssostnom,      "
"        hot_sostnf.posnach_hot_sostnf,     "
"        hot_sostnf.poscon_hot_sostnf,      "
"        hot_sostnf.kolm_hot_sostnf,        "
"        hot_ssostnom.name_hot_ssostnom,    "
"        hot_rgsostnf.id_hot_rgsostnf       "
" from hot_rgsostnf                         "

"   left outer join hot_sostnf on           "
"   (hot_rgsostnf.idsost_hot_rgsostnf = hot_sostnf.id_hot_sostnf)  and  "
"            ( (hot_sostnf.posnach_hot_sostnf between :param_posnach and :param_poscon)  or "
"            (hot_sostnf.poscon_hot_sostnf between :param_posnach and :param_poscon)   or    "
"            (:param_posnach between hot_sostnf.posnach_hot_sostnf and hot_sostnf.poscon_hot_sostnf) or "
"            (:param_poscon between hot_sostnf.posnach_hot_sostnf and hot_sostnf.poscon_hot_sostnf)  )  "

"   right outer join hot_snf on (hot_snf.id_hot_snf = hot_sostnf.idnomer_hot_sostnf) and           "
"            (  hot_snf.posin_hot_snf between :PARAM_POSNACH and :PARAM_POSCON or                  "
"			hot_snf.posout_hot_snf between :PARAM_POSNACH and :PARAM_POSCON or                     "
"            :PARAM_POSNACH between  hot_snf.posin_hot_snf and  hot_snf.posout_hot_snf or          "
"            :PARAM_POSCON between  hot_snf.posin_hot_snf and  hot_snf.posout_hot_snf   )          "

"   left outer join hot_ssostnom on (hot_sostnf.idsost_hot_sostnf = hot_ssostnom.id_hot_ssostnom)  "
"   left outer join hot_scatnom on (hot_snf.idcat_hot_snf = hot_scatnom.id_hot_scatnom)            "
"   left outer join hot_sobject on (hot_snf.idob_hot_snf=hot_sobject.id_hot_sobject)               "   ;

AnsiString conditions="";

if (IdObject>0)
	{
	conditions=conditions+" (hot_sobject.id_hot_sobject="+IdObject+")";
	}

if (IdCat>0)
	{
	if (conditions=="")
		{
		conditions=conditions+" (hot_scatnom.id_hot_scatnom="+IdCat+")";
		}
	else
		{
		conditions=conditions+" and (hot_scatnom.id_hot_scatnom="+IdCat+")";
		}
	}

if (IdNomer>0)
	{
	if (conditions=="")
		{
		conditions=conditions+" (hot_snf.id_hot_snf="+IdNomer+")";
		}
	else
		{
		conditions=conditions+" and (hot_snf.id_hot_snf="+IdNomer+")";
		}
	}

if (conditions!="")
	{
    result=" where "+conditions;
	}

result=result+" order by hot_scatnom.name_hot_scatnom, hot_snf.name_hot_snf   " ;

return result;
}
//---------------------------------------------------------------------------
