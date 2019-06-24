//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UHOT_FormaReportDvNomFonda.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxClasses"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "cxButtons"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxDropDownEdit"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "dxBkgnd"
#pragma link "dxPrnDev"
#pragma link "dxPrnPg"
#pragma link "dxPSCompsProvider"
#pragma link "dxPSCore"
#pragma link "dxPScxCommon"
#pragma link "dxPScxGrid6Lnk"
#pragma link "dxPSEdgePatterns"
#pragma link "dxPSEngn"
#pragma link "dxPSFillPatterns"
#pragma link "dxPSGlbl"
#pragma link "dxPSUtl"
#pragma link "dxWrap"
#pragma link "dxPSContainerLnk"
#pragma link "cxButtonEdit"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall THOT_FormaReportDvNomFonda::THOT_FormaReportDvNomFonda(TComponent* Owner)
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
bool THOT_FormaReportDvNomFonda::Init(void)
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

Table->Database=DM_Connection->pFIBData;
pFIBTr->DefaultDatabase=DM_Connection->pFIBData;

PosCon->Date=Date()+EncodeTime(23,59,59,999);
PosNach->Date=DM_Connection->GetPosNachReport();

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
int THOT_FormaReportDvNomFonda::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaReportDvNomFonda::FormClose(TObject *Sender,
      TCloseAction &Action)
{
 Action=caFree;
 if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int THOT_FormaReportDvNomFonda::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_Sost)
		{
		if (type_event==1)
				{
                EndViborSost();
				}
        HOT_FormaSpiskaSprSostNom=0;
		}

return -1;
}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaReportDvNomFonda::cxButtonUpdateClick(TObject *Sender)
{
Table->Active=false;
AnsiString zapros="select ";
zapros=zapros+" hot_sobject.name_hot_sobject, ";
zapros=zapros+"         hot_scatnom.name_hot_scatnom, ";
zapros=zapros+"         hot_snf.name_hot_snf, ";
zapros=zapros+"         sklient.nameklient,  ";
zapros=zapros+"         hot_sostnf.posnach_hot_sostnf, ";
zapros=zapros+"         hot_sostnf.poscon_hot_sostnf, ";
zapros=zapros+"         hot_ssostnom.name_hot_ssostnom, ";
zapros=zapros+"         hot_rgsostnf_dv.* ";
zapros=zapros+" from hot_rgsostnf_dv ";
zapros=zapros+" left outer join hot_sostnf on hot_rgsostnf_dv.idsost_hot_rgsostnf_dv=hot_sostnf.id_hot_sostnf ";
zapros=zapros+" left outer join hot_snf on hot_sostnf.idnomer_hot_sostnf=hot_snf.id_hot_snf ";
zapros=zapros+" left outer join hot_scatnom on hot_snf.idcat_hot_snf=hot_scatnom.id_hot_scatnom ";
zapros=zapros+" left outer join hot_sobject on hot_snf.idob_hot_snf=hot_sobject.id_hot_sobject  ";
zapros=zapros+" left outer join sklient on hot_sostnf.idguest_hot_sostnf=sklient.idklient";
zapros=zapros+" left outer join hot_ssostnom on hot_sostnf.idsost_hot_sostnf=hot_ssostnom.id_hot_ssostnom ";
zapros=zapros+" where hot_rgsostnf_dv.pos_hot_rgsostnf_dv between :PARAM_POSNACH and :PARAM_POSCON ";
if (IdSost!=0)
	{
	zapros=zapros+" and IDSOST_HOT_SOSTNF="+IntToStr(IdSost);
	}

zapros=zapros+" order by TDV_HOT_RGSOSTNF_DV ";

Table->SelectSQL->Clear();
Table->SelectSQL->Add(zapros);
Table->ParamByName("PARAM_POSNACH")->AsDateTime=PosNach->Date;
Table->ParamByName("PARAM_POSCON")->AsDateTime=PosCon->Date;
Table->Active=true;

cxGrid1Level1->Caption="Отчет о движении номерного фонда c " +DateTimeToStr(PosNach->Date)
   +"  по " +DateTimeToStr(PosCon->Date);
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaReportDvNomFonda::TableTDV_HOT_RGSOSTNF_DVGetText(
      TField *Sender, AnsiString &Text, bool DisplayText)
{
if (TableTDV_HOT_RGSOSTNF_DV->AsInteger==0)
	{
	Text="+";
	}
else
	{
	Text="-";
	}
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaReportDvNomFonda::cxButtonPrintClick(TObject *Sender)
{
dxComponentPrinter1->ReportLink[0]->Preview(true);    
}
//---------------------------------------------------------------------------
//выбор состояния
void THOT_FormaReportDvNomFonda::ViborSost(void)
{
if (HOT_FormaSpiskaSprSostNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprSostNom.1",IID_IHOT_FormaSpiskaSprSostNom,
													(void**)&HOT_FormaSpiskaSprSostNom);
		HOT_FormaSpiskaSprSostNom->Init(InterfaceMainObject,InterfaceImpl);
		HOT_FormaSpiskaSprSostNom->Vibor=true;
		HOT_FormaSpiskaSprSostNom->NumberProcVibor=ER_Sost;
		}
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaReportDvNomFonda::EndViborSost(void)
{

IdSost=HOT_FormaSpiskaSprSostNom->DM->TableID_HOT_SSOSTNOM->AsInt64;
NameSostcxButtonEdit->Text=HOT_FormaSpiskaSprSostNom->DM->TableNAME_HOT_SSOSTNOM->AsString;

}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaReportDvNomFonda::NameSostcxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborSost();
		}break;
	case 1:
		{
		IdSost=0;
		NameSostcxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

