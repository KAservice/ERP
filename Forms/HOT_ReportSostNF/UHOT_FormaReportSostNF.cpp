//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UHOT_FormaReportSostNF.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "DateUtils.hpp"
#include "IHOT_FormaElementaTableSostNF.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
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
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall THOT_FormaReportSostNF::THOT_FormaReportSostNF(TComponent* Owner)
        : TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//---------------------------------------------------------------------------
bool THOT_FormaReportSostNF::Init(void)
{
bool result=false;



if (InterfaceMainObject>0)
	{
	//получим соединение
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//получим интерфейс COM системы для создания новых объектов
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}

pFIBTr->DefaultDatabase=DM_Connection->pFIBData;
SostNF->Database=DM_Connection->pFIBData;

PosConcxDateEdit->Date=Date()+EncodeTime(23,59,59,999);
PosNachcxDateEdit->Date=DM_Connection->GetPosNachReport();

NameObjectcxButtonEdit->Text="";
NameCatcxButtonEdit->Text="";
NameNomercxButtonEdit->Text="";
NameSostcxButtonEdit->Text="";


DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int THOT_FormaReportSostNF::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaReportSostNF::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(HOT_FormaSpiskaSprObject) HOT_FormaSpiskaSprObject->kanRelease();
if(HOT_FormaSpiskaSprCatNom) HOT_FormaSpiskaSprCatNom->kanRelease();
if(HOT_FormaSpiskaSprNF) HOT_FormaSpiskaSprNF->kanRelease();
if(HOT_FormaSpiskaSprSostNom) HOT_FormaSpiskaSprSostNom->kanRelease();


SostNF->Active=false;
Action=caFree;
 if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//----------------------------------------------------------------------------
int THOT_FormaReportSostNF::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_Object)
		{
		if (type_event==1)
				{
				EndViborObject();
				}
		HOT_FormaSpiskaSprObject=0;
		}

if (number_procedure_end==ER_CatNom)
		{
		if (type_event==1)
				{
				EndViborCatNom();
				}
		HOT_FormaSpiskaSprCatNom=0;
		}

if (number_procedure_end==ER_SprNF)
		{
		if (type_event==1)
				{
				EndViborNF();
				}
		HOT_FormaSpiskaSprNF=0;
		}

if (number_procedure_end==ER_SostNom)
		{
		if (type_event==1)
				{
				EndViborSostNom();
				}
		 HOT_FormaSpiskaSprSostNom=0;
		}

if (number_procedure_end==ER_ProsmotrSost)
		{
		if (type_event==1)
				{
				EndProsmotrSost();
				}
		HOT_FormaElementaTableSostNF=0;
		}

return -1;
}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaReportSostNF::ActionOpenHelpExecute(
      TObject *Sender)
{
Application->HelpJump("ReportSostNF");
}
//---------------------------------------------------------------------------



void __fastcall THOT_FormaReportSostNF::cxButtonCreateReportClick(
	  TObject *Sender)
{

TDate tek_date=PosNachcxDateEdit->Date;

//удалим все строки
TcxCustomDataController *dc = cxGrid1BandedTableView1->DataController;
dc->BeginUpdate();

cxGrid1BandedTableView1->ClearItems();


	for (int i=dc->RecordCount;i>0;i--)
		{
		dc->DeleteRecord(i-1);
		}
dc->EndUpdate();

dc->BeginUpdate();

	TcxGridBandedColumn* GridColumn;
//
	GridColumn = cxGrid1BandedTableView1->CreateColumn();
	GridColumn->Caption = "Категория";
	GridColumn->DataBinding->ValueTypeClass = __classid(TcxStringValueType);
	GridColumn->Position->BandIndex=0;
	GridColumn->Width = 150;
//
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
		id_tec_nomer=glStrToInt64(SostNFID_HOT_SNF->AsString);
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
void THOT_FormaReportSostNF::OutputSost(int tec_column_left_margin, int num_first_row)
{
TcxCustomDataController *dc = cxGrid1BandedTableView1->DataController;
int num_first_col=GetPosStart()+tec_column_left_margin;
int num_end_col=GetPosFinish()+tec_column_left_margin;

int tec_row=num_first_row;
int nado_row=SostNFKOLM_HOT_SOSTNF->AsInteger;


while (tec_row<dc->RecordCount)     //проходим по существующим строкам
	{
	if(nado_row > 0 )
		{
		AnsiString val="";
		if (dc->Values[tec_row][num_first_col].IsNull()==false)
			{
			val=VarAsType(dc->Values[tec_row][num_first_col],varString);
			}

		if (val=="")  //если не занято
			{
			OutputRect(tec_row,num_first_col, num_end_col);
			nado_row--;
			}
		}
	tec_row++;
	}


while(nado_row>0)    //существующих не занятых строк не хватило
	{
	dc->AppendRecord();
	tec_column_left_margin=0;
	dc->Values[tec_row][tec_column_left_margin] = SostNFNAME_HOT_SCATNOM->AsString;
	tec_column_left_margin++;
	dc->Values[tec_row][tec_column_left_margin] = SostNFNAME_HOT_SNF->AsString;
	tec_column_left_margin++;
	OutputRect(tec_row,num_first_col, num_end_col);
	nado_row--;
	tec_row++;
	}

}
//---------------------------------------------------------------------------
void THOT_FormaReportSostNF::OutputRect(int row, int first_col, int end_col)
{
TcxCustomDataController *dc = cxGrid1BandedTableView1->DataController;
		int tec_col=first_col;
		while(tec_col<=end_col)
			{
			try
				{
				dc->Values[row][tec_col] =SostNFCOLOR_HOT_SSOSTNOM->AsString+"|"+SostNF->RecNo;
				}
			catch (...)
				{
                ShowMessage("Ошибка при выводе в ячейку! Строка: "+IntToStr(row)+" Колонка: "+IntToStr(tec_col));

				}
			tec_col++;
			}

}
//----------------------------------------------------------------------------
int THOT_FormaReportSostNF::GetPosStart(void)
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
int THOT_FormaReportSostNF::GetPosFinish(void)
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

//выбор объекта
void THOT_FormaReportSostNF::ViborObject(void)
{
if (HOT_FormaSpiskaSprObject>0) return;

InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprObject.1",IID_IHOT_FormaSpiskaSprObject,
													(void**)&HOT_FormaSpiskaSprObject);
HOT_FormaSpiskaSprObject->Init(InterfaceMainObject,InterfaceImpl);
//настройка формы
HOT_FormaSpiskaSprObject->Vibor=true;
HOT_FormaSpiskaSprObject->NumberProcVibor=ER_Object;
}
//-----------------------------------------------------------------------------
void __fastcall THOT_FormaReportSostNF::EndViborObject(void)
{

	IdObject=HOT_FormaSpiskaSprObject->DM->TableID_HOT_SOBJECT->AsInt64;
	NameObjectcxButtonEdit->Text=HOT_FormaSpiskaSprObject->DM->TableNAME_HOT_SOBJECT->AsString;


HOT_FormaSpiskaSprObject=0;
}
//----------------------------------------------------------------------------
//выбор категории номера
void THOT_FormaReportSostNF::ViborCatNom(void)
{
if (HOT_FormaSpiskaSprCatNom>0) return;

InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprCatNom.1",IID_IHOT_FormaSpiskaSprCatNom,
													(void**)&HOT_FormaSpiskaSprCatNom);
HOT_FormaSpiskaSprCatNom->Init(InterfaceMainObject,InterfaceImpl);
//настройка формы
HOT_FormaSpiskaSprCatNom->Vibor=true;
HOT_FormaSpiskaSprCatNom->NumberProcVibor=ER_CatNom;

}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaReportSostNF::EndViborCatNom(void)
{

	IdCat=HOT_FormaSpiskaSprCatNom->DM->TableID_HOT_SCATNOM->AsInt64;
	NameCatcxButtonEdit->Text=HOT_FormaSpiskaSprCatNom->DM->TableNAME_HOT_SCATNOM->AsString;


HOT_FormaSpiskaSprCatNom=0;

}
//----------------------------------------------------------------------------

//выбор номера
//----------------------------------------------------------------------------
void THOT_FormaReportSostNF::ViborNF(void)
{
if (HOT_FormaSpiskaSprNF>0) return;

InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprNF.1",IID_IHOT_FormaSpiskaSprNF,
													(void**)&HOT_FormaSpiskaSprNF);
HOT_FormaSpiskaSprNF->Init(InterfaceMainObject,InterfaceImpl);
//настройка формы
HOT_FormaSpiskaSprNF->Vibor=true;
HOT_FormaSpiskaSprNF->NumberProcVibor=ER_SprNF;

}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaReportSostNF::EndViborNF(void)
{

	IdNomer=HOT_FormaSpiskaSprNF->DM->TableID_HOT_SNF->AsInt64;
	NameNomercxButtonEdit->Text=HOT_FormaSpiskaSprNF->DM->TableNAME_HOT_SNF->AsString;


HOT_FormaSpiskaSprNF=0;

}
//----------------------------------------------------------------------------
//выбор состояния номера
void THOT_FormaReportSostNF::ViborSostNom(void)
{
if (HOT_FormaSpiskaSprSostNom>0) return;

InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprSostNom.1",IID_IHOT_FormaSpiskaSprSostNom,
													(void**)&HOT_FormaSpiskaSprSostNom);
HOT_FormaSpiskaSprSostNom->Init(InterfaceMainObject,InterfaceImpl);
if (!HOT_FormaSpiskaSprSostNom) return;
//настройка формы
HOT_FormaSpiskaSprSostNom->Vibor=true;
HOT_FormaSpiskaSprSostNom->NumberProcVibor=ER_SostNom;


}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaReportSostNF::EndViborSostNom(void)
{

	IdSost=HOT_FormaSpiskaSprSostNom->DM->TableID_HOT_SSOSTNOM->AsInt64;
	NameSostcxButtonEdit->Text=HOT_FormaSpiskaSprSostNom->DM->TableNAME_HOT_SSOSTNOM->AsString;


HOT_FormaSpiskaSprSostNom=0;

}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaReportSostNF::NameObjectcxButtonEditPropertiesButtonClick(
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

void __fastcall THOT_FormaReportSostNF::NameCatcxButtonEditPropertiesButtonClick(
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

void __fastcall THOT_FormaReportSostNF::NameNomercxButtonEditPropertiesButtonClick(
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

void __fastcall THOT_FormaReportSostNF::NameSostcxButtonEditPropertiesButtonClick(
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


AnsiString THOT_FormaReportSostNF::GetTextQuery(void)
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
"        hot_rgsostnf.id_hot_rgsostnf,      "
"		 hot_ssostnom.color_hot_ssostnom    "
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
    result=result + " where "+conditions;
	}

result=result+" order by hot_scatnom.name_hot_scatnom, hot_snf.name_hot_snf, hot_sostnf.posnach_hot_sostnf   " ;

return result;
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaReportSostNF::cxGrid1BandedTableView1DblClick(
      TObject *Sender)
{
TcxCustomDataController *dc = cxGrid1BandedTableView1->DataController;

int col=cxGrid1BandedTableView1->Controller->FocusedColumnIndex;
int row=cxGrid1BandedTableView1->Controller->FocusedRowIndex;


AnsiString val="";
AnsiString num_str="";

if (dc->Values[row][col].IsNull()==false)
	{
	val=VarAsType(dc->Values[row][col],varString);
	int pos=val.AnsiPos("|");
	if (pos>0)
		{
		num_str=val.SubString(pos+1, val.Length()-pos);
		}
	}

if (num_str=="") return;

SostNF->First();
SostNF->MoveBy(StrToInt(num_str)-1);

__int64 id_sost=glStrToInt64(SostNF->FieldByName("ID_HOT_SOSTNF")->AsString);

if (HOT_FormaElementaTableSostNF==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaElTableSostNF.1",IID_IHOT_FormaElementaTableSostNF,
													(void**)&HOT_FormaElementaTableSostNF);
	HOT_FormaElementaTableSostNF->Init(InterfaceMainObject,InterfaceImpl);
	HOT_FormaElementaTableSostNF->DM->OpenElement(id_sost);
	HOT_FormaElementaTableSostNF->NumberProcVibor=ER_ProsmotrSost;
	HOT_FormaElementaTableSostNF->UpdateForm();
	}

}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaReportSostNF::EndProsmotrSost(void)
{
HOT_FormaElementaTableSostNF=0;
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaReportSostNF::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaReportSostNF::cxGrid1BandedTableView1CustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone)
{
AnsiString ATextToDraw;
if (dynamic_cast<TcxGridTableDataCellViewInfo *>(AViewInfo) != NULL)
	{
	ATextToDraw =AViewInfo->GridRecord->DisplayTexts[AViewInfo->Item->Index];
	}
else
	{
	ATextToDraw = VarAsType(AViewInfo->Item->Caption, varString);
	}

if (ATextToDraw!="" && AViewInfo->Item->Index>1)
	{
	AnsiString color=ATextToDraw.SetLength(ATextToDraw.AnsiPos("|")-1);
	if (color != "" )
		{
		if (StrToInt(color)>0)
			{
			TRect ARec = AViewInfo->Bounds;
			ACanvas->Canvas->Brush->Color = StrToInt(color);
			ACanvas->Canvas->FillRect(ARec);
			//ACanvas->Canvas->Draw((ARec.Left+ARec.Right-ABitmap->Width)/2,ARec.Top,ABitmap);
			ADone = true;
			}
		}
	}
}
//---------------------------------------------------------------------------

