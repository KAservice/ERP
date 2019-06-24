//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaReportDiscountDocCheck.h"
#include "UReportDiscountDocCheck.h"
#include "IFormaReportGrid.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxCheckBox"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxGraphics"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtonEdit"
#pragma link "cxCalendar"
#pragma link "cxLabel"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaReportDiscountDocCheck::TFormaReportDiscountDocCheck(TComponent* Owner)
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
bool TFormaReportDiscountDocCheck::Init(void)
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

DateCon->Date=Date()+EncodeTime(23,59,59,999);
DateNach->Date=DM_Connection->GetPosNachReport();


NameFirmEdit->Text="";
NameSkladEdit->Text="";
NameGrpNomEdit->Text="";
NameNomEdit->Text="";
NameKlientcxButtonEdit->Text="";

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//---------------------------------------------------------------------------
int  TFormaReportDiscountDocCheck::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportDiscountDocCheck::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokSklad) SpisokSklad->kanRelease();
if(SpisokFirm)SpisokFirm->kanRelease();
if(SpisokGrpNom)SpisokGrpNom->kanRelease();
if(SpisokNom)SpisokNom->kanRelease();
if(SpisokKlient)SpisokKlient->kanRelease();
Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//----------------------------------------------------------------------------
void TFormaReportDiscountDocCheck::OpenFormSpiskaSprNom(void)
{
if (SpisokNom==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&SpisokNom);
		SpisokNom->Init(InterfaceMainObject,InterfaceImpl);
		SpisokNom->Vibor=true;
		SpisokNom->NumberProcVibor=ViborNom;
        SpisokNom->IdNom=IdNom;
        SpisokNom->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void TFormaReportDiscountDocCheck::OpenFormSpiskaSprFirm(void)
{
if (SpisokFirm==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&SpisokFirm);
	SpisokFirm->Init(InterfaceMainObject,InterfaceImpl);
	SpisokFirm->Vibor=true;
	SpisokFirm->NumberProcVibor=ViborFirm;
	}
}
//---------------------------------------------------------------------------
void TFormaReportDiscountDocCheck::OpenFormSpiskaSprGrpNom(void)
{
if (SpisokGrpNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprGrpNom.1",IID_IFormaSpiskaSprGrpNom,
													(void**)&SpisokGrpNom);
		SpisokGrpNom->Init(InterfaceMainObject,InterfaceImpl);
		SpisokGrpNom->Vibor=true;
		SpisokGrpNom->NumberProcVibor=ViborGrpNom;
        SpisokGrpNom->UpdateForm();
		}
}
//---------------------------------------------------------------------------
int TFormaReportDiscountDocCheck::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ViborSklad)
        {
		if (type_event==1)
                {
				IdSkl=glStrToInt64(SpisokSklad->DM->ElementIDSKLAD->AsString);
                NameSkladEdit->Text=SpisokSklad->DM->ElementNAMESKLAD->AsString;
                }
		SpisokSklad=0;
        }

if (number_procedure_end==ViborFirm)
		{
		if (type_event==1)
				{
				IdFirm=SpisokFirm->DM->TableIDFIRM->AsInt64;
				NameFirmEdit->Text=SpisokFirm->DM->TableNAMEFIRM->AsString;
				}
		SpisokFirm=0;
		}

if (number_procedure_end==ViborGrpNom)
        {
		if (type_event==1)
                {
				IdGrpNom=SpisokGrpNom->DMGrp->ElementIDGN->AsInt64;
                NameGrpNomEdit->Text=SpisokGrpNom->DMGrp->ElementNAMEGN->AsString;
                IdNom=0;
                NameNomEdit->Text="";
                }
        SpisokGrpNom=0;
        }


if (number_procedure_end==ViborNom)
		{
		if (type_event==1)
                {
				IdNom=glStrToInt64(SpisokNom->DM->TableIDNOM->AsString);
				NameNomEdit->Text=SpisokNom->DM->TableNAMENOM->AsString;
                IdGrpNom=0;
				NameGrpNomEdit->Text="";
                }
		SpisokNom=0;
		}

if (number_procedure_end==ViborKlient)
		{
		if (type_event==1)
                {
				EndViborKlient();
                }
		SpisokKlient=0;
		}

EditRekvisit=NO;
return -1;
}
//---------------------------------------------------------------------------
void TFormaReportDiscountDocCheck::OpenFormSpiskaSprSklad(void)
{
if (SpisokSklad==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&SpisokSklad);
		SpisokSklad->Init(InterfaceMainObject,InterfaceImpl);
		SpisokSklad->Vibor=true;
		SpisokSklad->NumberProcVibor=ViborSklad;
		}

}
//----------------------------------------------------------------------------












void __fastcall TFormaReportDiscountDocCheck::ActionOpenHelpExecute(
      TObject *Sender)
{
Application->HelpJump("ReportDiscountCheck");
}
//---------------------------------------------------------------------------


void __fastcall TFormaReportDiscountDocCheck::cxButtonCreateClick(
      TObject *Sender)
{
TReportDiscountDocCheck * report=new TReportDiscountDocCheck();
report->DM_Connection=DM_Connection;
report->InterfaceGlobalCom=InterfaceGlobalCom;
report->InterfaceMainObject=InterfaceMainObject;

report->Init();
report->PosNach=DateNach->Date;
report->PosCon=DateCon->Date;
report->IdFirm=IdFirm;
report->IdSklad=IdSkl;
report->IdGrp=IdGrpNom;
report->IdNom=IdNom;
if (OnlyCheckBox->Checked==true)
	{
	report->OnlyType=true;
	report->TypeNom=TypeNomComboBox->ItemIndex;
	}
else
	{
	report->OnlyType=false;
	}

if (DocCheckBox->Checked==true)
	{
	report->AddDoc=true;
	}
else
	{
	report->AddDoc=false;
	}
report->CreateReport();
delete report;	
}
//---------------------------------------------------------------------------





void __fastcall TFormaReportDiscountDocCheck::NameNomEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprNom();
		}break;
	case 1:
		{
		IdNom=0;
		NameNomEdit->Text="";
		}break;
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportDiscountDocCheck::NameGrpNomEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprGrpNom();
		}break;
	case 1:
		{
		IdGrpNom=0;
		NameGrpNomEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportDiscountDocCheck::NameSkladEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprSklad();
		}break;
	case 1:
		{
		IdSkl=0;
		NameSkladEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportDiscountDocCheck::NameFirmEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprFirm();
		}break;
	case 1:
		{
		IdFirm=0;
		NameFirmEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------
void TFormaReportDiscountDocCheck::OpenFormSpiskaSprKlient(void)
{
if (SpisokKlient==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&SpisokKlient);
		SpisokKlient->Init(InterfaceMainObject,InterfaceImpl);
        SpisokKlient->Vibor=true;
		SpisokKlient->NumberProcVibor=ViborKlient;
		SpisokKlient->UpdateForm();
		}
}
//-----------------------------------------------------------------------------
void __fastcall TFormaReportDiscountDocCheck::EndViborKlient(void)
{

				IdKlient=SpisokKlient->DM->TableIDKLIENT->AsInt64;
				NameKlientcxButtonEdit->Text=SpisokKlient->DM->TableNAMEKLIENT->AsString;


}
//----------------------------------------------------------------------------
void __fastcall TFormaReportDiscountDocCheck::NameKlientcxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprKlient();
		}break;
	case 1:
		{
		IdKlient=0;
		NameKlientcxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportDiscountDocCheck::cxButtonCreateReportGridClick(
      TObject *Sender)
{
IFormaReportGrid * f;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaReportGrid.1",IID_IFormaReportGrid,
													(void**)&f);
f->Init(InterfaceMainObject,InterfaceImpl);
f->SetCaptionReport("Отчет по диск. картам с "+
			DateTimeToStr(DateNach->Date)+" по "+DateTimeToStr(DateCon->Date));

//AnsiString zapros="";
//
//zapros=zapros+"select  ";
//zapros=zapros+"	sfirm.namefirm,   ";
//zapros=zapros+" ssklad.namesklad,  ";
//zapros=zapros+" sklient.nameklient, ";
//zapros=zapros+" sdiscount_card.name_sdiscount_card, ";
//zapros=zapros+" sgrpnom.namegn, ";
//zapros=zapros+" snom.namenom,  ";
//zapros=zapros+" sed.nameed,    ";
//zapros=zapros+" SUM(dchkt.kolchkt * dchkt.kfchkt) as KOL,  ";
//zapros=zapros+" SUM(dchkt.sumchkt) as SUMREAL,    ";
//zapros=zapros+"	SUM(dchkt.skchkt) as SKIDKA          ";
//
//zapros=zapros+"from dchk                             ";
//zapros=zapros+"    left outer join galldoc on  galldoc .iddoc=dchk.iddocchk        ";
//zapros=zapros+"    left outer join dchkt on  dchkt.iddocchkt=dchk.iddocchk         ";
//
//zapros=zapros+"    left outer join sfirm on sfirm.idfirm=galldoc.idfirmdoc         ";
//zapros=zapros+"    left outer join ssklad on ssklad.idsklad=galldoc.idskldoc       ";
//zapros=zapros+"    left outer join sklient on sklient.idklient=galldoc.idkldoc     ";
//zapros=zapros+"    left outer join sdiscount_card on sdiscount_card.id_sdiscount_card=dchk.iddcardchk  ";
//
//zapros=zapros+"    left outer join snom on dchkt.idnomchkt=snom.idnom              ";
//zapros=zapros+"    left outer join sed on sed.ided=snom.idbasednom                 ";
//zapros=zapros+"    left outer join sgrpnom on sgrpnom.idgn=snom.idgrpnom           ";
//
//zapros=zapros+" where dchk.iddcardchk>0     ";


AnsiString zapros=" select";
zapros=zapros+" sfirm.namefirm, ";
zapros=zapros+" ssklad.namesklad, ";
zapros=zapros+" sklient.nameklient, ";
zapros=zapros+" sdiscount_card.name_sdiscount_card, ";
zapros=zapros+" sgrpnom.namegn, ";
zapros=zapros+" snom.namenom,  ";
zapros=zapros+" sed.nameed,";
zapros=zapros+" sum(dchkt.kolchkt * dchkt.kfchkt) as KOL,";
zapros=zapros+" sum(dchkt.sumchkt) as SUMREAL,";
zapros=zapros+" sum(dchkt.skchkt) as SKIDKA";
zapros=zapros+" from dchkt";
zapros=zapros+" left outer join galldoc on dchkt.iddocchkt=galldoc.iddoc";
zapros=zapros+" left outer join dchk on  dchk.iddocchk=dchkt.iddocchkt         ";
zapros=zapros+" left outer join sfirm on galldoc.idfirmdoc=sfirm.idfirm";
zapros=zapros+" left outer join ssklad on galldoc.idskldoc=ssklad.idsklad";
zapros=zapros+" left outer join sklient on sklient.idklient=galldoc.idkldoc     ";
zapros=zapros+" left outer join sdiscount_card on sdiscount_card.id_sdiscount_card=dchk.iddcardchk  ";
zapros=zapros+" left outer join snom on dchkt.idnomchkt=snom.idnom";
zapros=zapros+" left outer join sgrpnom on snom.idgrpnom=sgrpnom.idgn";
zapros=zapros+" left outer join sed on snom.idbasednom=sed.ided";
zapros=zapros+" where dchkt.skchkt!=0 and dchk.operchk=0 ";


zapros=zapros+" and galldoc.posdoc between '"+DateTimeToStr(DateNach->Date)+"' and '"+DateTimeToStr(DateCon->Date)+"'";

        if (IdFirm!=0)
				{
				zapros=zapros+"  and galldoc.idfirmdoc="+IntToStr(IdFirm);
				}

		if (IdSkl!=0)
                {
				zapros=zapros+" and galldoc.idskldoc="+IntToStr(IdSkl);
				}

		if (IdKlient!=0)
				{
				zapros=zapros+" and galldoc.idkldoc="+IntToStr(IdKlient);
				}

        if (IdGrpNom!=0)
				{
				zapros=zapros+" and sgrpnom.idgn="+IntToStr(IdGrpNom);;
				}

		if (IdNom!=0)
				{
				zapros=zapros+" and snom.idnom="+IntToStr(IdNom);
				}

		if (OnlyCheckBox->Checked==true)
				{
				zapros=zapros+" and snom.tnom="+IntToStr(TypeNomComboBox->ItemIndex);
				}


zapros=zapros+"  group by                                   ";
zapros=zapros+"  sfirm.namefirm,                            ";
zapros=zapros+"  ssklad.namesklad,                          ";
zapros=zapros+"  sklient.nameklient,                        ";
zapros=zapros+"  sdiscount_card.name_sdiscount_card,        ";
zapros=zapros+"  sgrpnom.namegn,                            ";
zapros=zapros+"  snom.namenom,                              ";
zapros=zapros+"  sed.nameed                                 ";


f->SetTextQuery(zapros);

f->AddColumn("NAMEFIRM","Фирма",200,0,false,"",false,"");
f->AddColumn("NAMESKLAD","Склад",200,1,false,"",false,"");
f->AddColumn("NAMEKLIENT","Клиент",200,2,false,"",false,"");
f->AddColumn("NAME_SDISCOUNT_CARD","Карта",200,3,false,"",false,"");
f->AddColumn("NAMEGN","Группа",200,4,false,"",false,"");
f->AddColumn("NAMENOM","Номенклатура",200,-1,false,"",false,"");
f->AddColumn("KOL","Кол.",50,-1,false,"",false,"");
f->AddColumn("NAMEED","Единица",50,-1,false,"",false,"");
f->AddColumn("SUMREAL","Сумма реал.",50,-1,true,"$,0.00",true,"$,0.00");
f->AddColumn("SKIDKA","Скидка",50,-1,true,"$,0.00",true,"$,0.00");

f->CreateSeries("KOL", "Кол.");
f->CreateSeries("SUMREAL", "Сум. реал.");
f->CreateSeries("SKIDKA", "Скидка");
f->AddDataGroups("NAMEFIRM","Фирма");
f->AddDataGroups("NAMESKLAD","Склад");
f->AddDataGroups("NAMEKLIENT","Клиент");
f->AddDataGroups("NAMEGN","Группа");
f->AddDataGroups("NAMENOM","Номенклатура");

f->OpenReport();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportDiscountDocCheck::ActionCloseExecute(TObject *Sender)

{
Close();
}
//---------------------------------------------------------------------------

