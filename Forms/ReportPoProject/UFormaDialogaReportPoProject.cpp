//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaDialogaReportPoProject.h"
#include "IDMSprPrice.h"
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
#pragma link "cxButtonEdit"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCheckBox"
#pragma link "cxGraphics"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLabel"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaDialogaReportPoProject::TFormaDialogaReportPoProject(TComponent* Owner)
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
void __fastcall TFormaDialogaReportPoProject::FormCreate(TObject *Sender)
{


NameFirmEdit->Text="";
NameSkladEdit->Text="";
NameGrpNomEdit->Text="";
NameNomEdit->Text="";
NameProjectcxButtonEdit->Text="";

}
//-----------------------------------------------------------------------
bool TFormaDialogaReportPoProject::Init(void)
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
int TFormaDialogaReportPoProject::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void __fastcall TFormaDialogaReportPoProject::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokSklad) SpisokSklad->kanRelease();
if(SpisokFirm)SpisokFirm->kanRelease();
if(SpisokGrpNom)SpisokGrpNom->kanRelease();
if(SpisokNom)SpisokNom->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();


Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//----------------------------------------------------------------------------
void TFormaDialogaReportPoProject::OpenFormSpiskaSprNom(void)
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
void TFormaDialogaReportPoProject::OpenFormSpiskaSprFirm(void)
{
if (SpisokFirm==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&SpisokFirm);
		SpisokFirm->Init(InterfaceMainObject,InterfaceImpl);
		SpisokFirm->Vibor=true;
		SpisokFirm->NumberProcVibor=ViborFirm;
		}
}
//---------------------------------------------------------------------------
void TFormaDialogaReportPoProject::OpenFormSpiskaSprGrpNom(void)
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
int TFormaDialogaReportPoProject::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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

if (number_procedure_end==ViborProject)
        {
		if (type_event==1)
                {
				EndViborProject();
                }
        SpisokProject=0;
		}

EditRekvisit=NO;


	FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//---------------------------------------------------------------------------
void TFormaDialogaReportPoProject::OpenFormSpiskaSprSklad(void)
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

AnsiString TFormaDialogaReportPoProject::GetTextQuery(void)
{
AnsiString zapros="";
zapros=zapros+"select  sfirm.namefirm, sfirm.idfirm,";
zapros=zapros+" ssklad.namesklad, ssklad.idsklad,";
zapros=zapros+" sgrpnom.namegn, sgrpnom.idgn,";
zapros=zapros+" NAMENOM, IDNOM, TNOM,";
zapros=zapros+" NAMEED,";
zapros=zapros+" SUM(SUMREAL_RGREAL_DV)  AS SUMREAL,";
zapros=zapros+" SUM(SEBREAL_RGREAL_DV)  AS SEBREAL,";
zapros=zapros+" SUM(RESREAL_RGREAL_DV)  AS RESREAL,";
zapros=zapros+" SUM(KOL_RGREAL_DV)  AS KOLREAL,";
zapros=zapros+" SUM(KOLOTR_RGREAL_DV)  AS KOLOTRREAL";
zapros=zapros+" from  RGREAL_DV";
zapros=zapros+" left outer join sfirm on rgreal_dv.idfirm_rgreal_dv=sfirm.idfirm";
zapros=zapros+" left outer join ssklad on rgreal_dv.idsklad_rgreal_dv=ssklad.idsklad";
zapros=zapros+" left outer join SNOM on IDNOM_RGREAL_DV=IDNOM";
zapros=zapros+" left outer join SGRPNOM on IDGRPNOM=IDGN";
zapros=zapros+" left outer join SED on IDBASEDNOM=IDED";

zapros=zapros+" where (POSDOC_RGREAL_DV  between :PARAM_POSNACH and :PARAM_POSCON)";

        if (IdFirm!=0)
                {
                zapros=zapros+" and  IDFIRM_RGREAL_DV="+IntToStr(IdFirm);
                }

        if (IdSkl!=0)
                {
                zapros=zapros+" and  IDSKLAD_RGREAL_DV="+IntToStr(IdSkl);
                }

        if (IdGrpNom!=0)
                {
                zapros=zapros+" and  sgrpnom.idgn="+IntToStr(IdGrpNom);;
                }

        if (IdNom!=0)
                {
                zapros=zapros+" and  IDNOM_RGREAL_DV="+IntToStr(IdNom);
                }

        if (OnlyCheckBox->Checked==true)
                {
                zapros=zapros+" and  TNOM="+IntToStr(TypeNomComboBox->ItemIndex);
                }

        if (OnlyOperationCheckBox->Checked==true)
                {
                zapros=zapros+" and  OPER_RGREAL_DV="+IntToStr(OperationComboBox->ItemIndex);
                }

zapros=zapros+" group by sfirm.namefirm, sfirm.idfirm,";
zapros=zapros+" ssklad.namesklad, ssklad.idsklad,";
zapros=zapros+" sgrpnom.namegn, sgrpnom.idgn,";
zapros=zapros+" NAMENOM, IDNOM, TNOM,";
zapros=zapros+" NAMEED";

return zapros;
}

//-----------------------------------------------------------------------------
void __fastcall TFormaDialogaReportPoProject::ActionOpenHelpExecute(
      TObject *Sender)
{
Application->HelpJump("ReportPoProject");
}
//---------------------------------------------------------------------------


void __fastcall TFormaDialogaReportPoProject::NameFirmEditPropertiesButtonClick(
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

void __fastcall TFormaDialogaReportPoProject::NameSkladEditPropertiesButtonClick(
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


void __fastcall TFormaDialogaReportPoProject::NameGrpNomEditPropertiesButtonClick(
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

void __fastcall TFormaDialogaReportPoProject::NameNomEditPropertiesButtonClick(
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




void TFormaDialogaReportPoProject::OpenFormSpiskaSprProject(void)
{
if (SpisokProject==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprProject.1",IID_IFormaSpiskaSprProject,
													(void**)&SpisokProject);
		SpisokProject->Init(InterfaceMainObject,InterfaceImpl);
		SpisokProject->Vibor=true;
		SpisokProject->UpdateForm();
		SpisokProject->NumberProcVibor=ViborSklad;
		}

}
//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportPoProject::EndViborProject(void)
{

IdProject=SpisokProject->DM->TableID_SPROJECT->AsInt64;
NameProjectcxButtonEdit->Text=SpisokProject->DM->TableNAME_SPROJECT->AsString;


FindNextControl(ActiveControl,true,true,false)->SetFocus();

}
//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportPoProject::NameProjectcxButtonEditPropertiesButtonClick(
	  TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprProject();
		}break;
	case 1:
		{
		IdProject=0;
		NameProjectcxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportPoProject::DateNachKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportPoProject::DateConKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDialogaReportPoProject::OnlyCheckBoxKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportPoProject::OnlyOperationCheckBoxKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportPoProject::DocCheckBoxKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDialogaReportPoProject::TypeNomComboBoxPropertiesChange(
      TObject *Sender)
{
FindNextControl(ActiveControl,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportPoProject::OperationComboBoxPropertiesChange(
      TObject *Sender)
{
FindNextControl(ActiveControl,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportPoProject::TypePriceComboBoxPropertiesChange(
      TObject *Sender)
{
FindNextControl(ActiveControl,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportPoProject::cxCheckBoxVisibleOtrOstKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportPoProject::cxButtonCreateReportClick(
      TObject *Sender)
{
IFormaReportGrid * f;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaReportGrid.1",IID_IFormaReportGrid,
													(void**)&f);
f->Init(InterfaceMainObject,InterfaceImpl);

AnsiString zapros="select  sfirm.namefirm, sfirm.idfirm, ";
zapros=zapros+" ssklad.namesklad, ssklad.idsklad,";
zapros=zapros+" sproject.name_sproject,";
zapros=zapros+" sgrpnom.namegn, sgrpnom.idgn,";
zapros=zapros+" NAMENOM, IDNOM, TNOM,";
zapros=zapros+" NAMEED,";
zapros=zapros+" SUM(SUMREAL_RGREAL_DV)  AS SUMREAL,";
zapros=zapros+" SUM(SEBREAL_RGREAL_DV)  AS SEBREAL,";
zapros=zapros+" SUM(RESREAL_RGREAL_DV)  AS RESREAL,";
zapros=zapros+" SUM(KOL_RGREAL_DV)  AS KOLREAL,";
zapros=zapros+" SUM(KOLOTR_RGREAL_DV)  AS KOLOTRREAL ";
//zapros=zapros+" (SUM(SUMREAL_RGREAL_DV)/SUM(SEBREAL_RGREAL_DV+0.0001)-1)*100 AS NACENKA  ";
zapros=zapros+" from  RGREAL_DV ";

zapros=zapros+" left outer join sfirm on rgreal_dv.idfirm_rgreal_dv=sfirm.idfirm ";
zapros=zapros+" left outer join ssklad on rgreal_dv.idsklad_rgreal_dv=ssklad.idsklad ";
zapros=zapros+" left outer join galldoc on galldoc.iddoc=rgreal_dv.iddoc_rgreal_dv ";
zapros=zapros+" left outer join sproject on sproject.id_sproject=galldoc.idproject_galldoc ";
zapros=zapros+" left outer join SNOM on IDNOM_RGREAL_DV=IDNOM ";
zapros=zapros+" left outer join SGRPNOM on IDGRPNOM=IDGN ";
zapros=zapros+" left outer join SED on IDBASEDNOM=IDED ";

zapros=zapros+" where POSDOC_RGREAL_DV  between '"+DateTimeToStr(DateNach->Date)+"' and '"+DateTimeToStr(DateCon->Date)+"'";

        if (IdFirm!=0)
                {
                zapros=zapros+" and  IDFIRM_RGREAL_DV="+IntToStr(IdFirm);
                }

        if (IdSkl!=0)
                {
                zapros=zapros+" and  IDSKLAD_RGREAL_DV="+IntToStr(IdSkl);
				}

        if (IdProject!=0)
                {
                zapros=zapros+" and  IDPROJECT_GALLDOC="+IntToStr(IdProject);
				}

        if (IdGrpNom!=0)
                {
                zapros=zapros+" and  sgrpnom.idgn="+IntToStr(IdGrpNom);;
                }

		if (IdNom!=0)
				{
				zapros=zapros+" and  IDNOM_RGREAL_DV="+IntToStr(IdNom);
				}

		if (OnlyCheckBox->Checked==true)
                {
                zapros=zapros+" and  TNOM="+IntToStr(TypeNomComboBox->ItemIndex);
                }

		if (OnlyOperationCheckBox->Checked==true)
				{
				zapros=zapros+" and  OPER_RGREAL_DV="+IntToStr(OperationComboBox->ItemIndex);
				}


zapros=zapros+" group by sfirm.namefirm, sfirm.idfirm,";
zapros=zapros+" ssklad.namesklad, ssklad.idsklad, ";
zapros=zapros+" sproject.name_sproject, ";
zapros=zapros+" sgrpnom.namegn, sgrpnom.idgn, ";
zapros=zapros+" NAMENOM, IDNOM, TNOM, ";
zapros=zapros+" NAMEED ";

f->SetTextQuery(zapros);

f->AddColumn("NAMEFIRM","Фирма",200,0,false,"",false,"");
f->AddColumn("NAMESKLAD","Склад",200,1,false,"",false,"");
f->AddColumn("NAME_SPROJECT","Проект",200,2,false,"",false,"");
f->AddColumn("NAMEGN","Группа",200,3,false,"",false,"");
f->AddColumn("NAMENOM","Номенклатура",200,-1,false,"",false,"");
f->AddColumn("KOLREAL","Кол.",50,-1,false,"",false,"");
f->AddColumn("NAMEED","Единица",50,-1,false,"",false,"");
f->AddColumn("SUMREAL","Сумма реал.",50,-1,true,"$,0.00",true,"$,0.00");
f->AddColumn("SEBREAL","Себестоимость",50,-1,true,"$,0.00",true,"$,0.00");
f->AddColumn("RESREAL","Сумма дохода",50,-1,true,"$,0.00",true,"$,0.00");
//f->AddColumn("NACENKA","Наценка (%)",50,-1,false,"$,0.00",false,"$,0.00");

f->CreateSeries("SUMREAL", "Сум. реал.");
f->CreateSeries("SEBREAL", "Себест.");
f->CreateSeries("RESREAL", "Доход");
f->AddDataGroups("NAMEFIRM","Фирма");
f->AddDataGroups("NAMESKLAD","Склад");
f->AddDataGroups("NAME_SPROJECT","Проект");
f->AddDataGroups("NAMEGN","Группа");
f->AddDataGroups("NAMENOM","Номенклатура");

f->OpenReport();
	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportPoProject::NameProjectcxButtonEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------




void __fastcall TFormaDialogaReportPoProject::ActionCloseExecute(TObject *Sender)

{
Close();
}
//---------------------------------------------------------------------------

