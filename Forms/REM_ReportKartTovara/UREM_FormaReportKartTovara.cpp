//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UREM_FormaReportKartTovara.h"
#include "IDMSprPrice.h"
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
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtonEdit"
#pragma link "cxCheckBox"
#pragma link "cxCalendar"
#pragma link "cxLookAndFeels"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxFilter"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxDBLabel"
#pragma link "cxLabel"
#pragma resource "*.dfm"

extern UnicodeString glGetNameDocRemont(UnicodeString str_code_doc);
//---------------------------------------------------------------------------
__fastcall TREM_FormaReportKartTovara::TREM_FormaReportKartTovara(TComponent* Owner)
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
void __fastcall TREM_FormaReportKartTovara::FormCreate(TObject *Sender)
{
//
}
//-----------------------------------------------------------------------
bool TREM_FormaReportKartTovara::Init(void)
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

pFIBDataSet->Database=DM_Connection->pFIBData;
pFIBTransaction->DefaultDatabase=DM_Connection->pFIBData;

OstNaNach->Database=DM_Connection->pFIBData;
OstNaCon->Database=DM_Connection->pFIBData;

DateCon->Date=Date()+EncodeTime(23,59,59,999);
DateNach->Date=DM_Connection->GetPosNachReport();

NameFirmEdit->Text="";
NameSkladEdit->Text="";
NameGrpNomEdit->Text="";
NameNomEdit->Text="";


OstNaNachcxLabel->Caption="";
OstNaConcxLabel->Caption="";

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TSR_FormaOstatkiTovarovImpl),false);
DMTableExtPrintForm->Table->First();
while (!DMTableExtPrintForm->Table->Eof)
		{
		TMenuItem *menu=new TMenuItem(PopupMenuExtModule);
		menu->Caption=DMTableExtPrintForm->TableNAME_EXTPRINT_FORM->AsString;
		menu->OnClick = PopupMenuExtModuleClick;
		PopupMenuExtModule->Items->Add(menu);
		//static_cast<TPopupMenu*>(Sender)->Items->Add(Item);
		DMTableExtPrintForm->Table->Next();
		}



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
int  TREM_FormaReportKartTovara::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaReportKartTovara::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokSklad) SpisokSklad->kanRelease();
if(SpisokFirm) SpisokFirm->kanRelease();
if(SpisokGrpNom) SpisokGrpNom->kanRelease();
if(SpisokNom) SpisokNom->kanRelease();

pFIBDataSet->Active=false;
OstNaNach->Active=false;
OstNaCon->Active=false;

Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//----------------------------------------------------------------------------


void TREM_FormaReportKartTovara::UpdateForm(void)
{
TDateTime PosNull=EncodeDate(2000,1,1);
if (PosStart > PosNull)
	{
	DateNach->Date=PosStart;
	}

if (PosEnd > PosNull)
	{
	DateCon->Date=PosEnd;
	}


NameFirmEdit->Text=NameFirm;
NameSkladEdit->Text=NameSklad;
NameNomEdit->Text=NameNom;

}
//----------------------------------------------------------------------------
void TREM_FormaReportKartTovara::OpenFormSpiskaSprNom(void)
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
void TREM_FormaReportKartTovara::OpenFormSpiskaSprFirm(void)
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
void TREM_FormaReportKartTovara::OpenFormSpiskaSprGrpNom(void)
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
int TREM_FormaReportKartTovara::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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


EditRekvisit=NO;
return -1;
}
//---------------------------------------------------------------------------
void TREM_FormaReportKartTovara::OpenFormSpiskaSprSklad(void)
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



//----------------------------------------------------------------------------






void __fastcall TREM_FormaReportKartTovara::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaReportKartTovara::NameNomEditPropertiesButtonClick(
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

void __fastcall TREM_FormaReportKartTovara::NameGrpNomEditPropertiesButtonClick(
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

void __fastcall TREM_FormaReportKartTovara::NameSkladEditPropertiesButtonClick(
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

void __fastcall TREM_FormaReportKartTovara::NameFirmEditPropertiesButtonClick(
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

//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TREM_FormaReportKartTovara::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaReportKartTovara::RunExternalModule(__int64 id_module, int type_module)
{
IFormaRunExternalModule * module;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaRunExternalModule.1",IID_IFormaRunExternalModule,
													(void**)&module);
module->Init(InterfaceMainObject,InterfaceImpl);
module->IdModule=id_module;
module->TypeTable=1;

module->ClearModule();
module->LoadModule();


//добавляем текущий модуль
//TScriptDMDocRealRozn * scr_doc;
if (type_module==1 || type_module==2)
	{
//	//надо добавить класс TScriptDMDocRealRozn
//	//методы для работы с документом
//	module->AddClassesInScript_DMDocRealRozn();
//	module->ScriptDMDocRealRozn->DM=DM;
//	module->fsScript1->AddObject("TecDMDocRealRozn",module->ScriptDMDocRealRozn);
	}


	module->SetInt64Variables("glIdFirm", IdFirm);
	module->SetInt64Variables("glIdSklad", IdSkl);
	module->SetInt64Variables("glIdGrpNom", IdGrpNom);
	module->SetInt64Variables("glIdNom", IdNom);
	module->SetDateTimeVariables("glPosBegin", DateNach->Date);
	module->SetDateTimeVariables("glPosEnd", DateCon->Date);


module->ExecuteModule();

}
//-----------------------------------------------------------------------------
void __fastcall TREM_FormaReportKartTovara::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaReportKartTovara::cxButtonUpdateClick(TObject *Sender)
{
pFIBDataSet->Active=false;
pFIBDataSet->ParamByName("PARAM_POS_START")->AsDateTime = DateNach->Date;
pFIBDataSet->ParamByName("PARAM_POS_END")->AsDateTime = DateCon->Date;
pFIBDataSet->ParamByName("PARAM_IDFIRM")->AsString = IdFirm;
pFIBDataSet->ParamByName("PARAM_IDSKLAD")->AsString = IdSkl;
pFIBDataSet->ParamByName("PARAM_IDNOM")->AsString = IdNom;


pFIBDataSet->Active=true;


OstNaNach->Active=false;
OstNaNach->ParamByName("PARAM_POS")->AsDateTime = DateNach->Date;
OstNaNach->ParamByName("PARAM_IDFIRM")->AsString = IdFirm;
OstNaNach->ParamByName("PARAM_IDSKLAD")->AsString = IdSkl;
OstNaNach->ParamByName("PARAM_IDNOM")->AsString = IdNom;
//pFIBDataSet->ParamByName("PARAM_IDTNOM")->AsString = 0;
OstNaNach->Active=true;
OstNaNachcxLabel->Caption=OstNaNachOUT_KOL->AsString;
OstNaNach->Active=false;


OstNaCon->Active=false;
OstNaCon->ParamByName("PARAM_POS")->AsDateTime = DateCon->Date;
OstNaCon->ParamByName("PARAM_IDFIRM")->AsString = IdFirm;
OstNaCon->ParamByName("PARAM_IDSKLAD")->AsString = IdSkl;
OstNaCon->ParamByName("PARAM_IDNOM")->AsString = IdNom;
//pFIBDataSet->ParamByName("PARAM_IDTNOM")->AsString = 0;
OstNaCon->Active=true;
OstNaConcxLabel->Caption=OstNaConOUT_KOL->AsString;
OstNaCon->Active=false;
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaReportKartTovara::pFIBDataSetOUT_TDOCGetText(TField *Sender,
		  UnicodeString &Text, bool DisplayText)
{
Text = glGetNameDocRemont(pFIBDataSetOUT_TDOC->AsString);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaReportKartTovara::OstNaNachOUT_KOLGetText(TField *Sender,
          UnicodeString &Text, bool DisplayText)
{
Text = "Остаток на начало: "+ OstNaNachOUT_KOL->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaReportKartTovara::OstNaConOUT_KOLGetText(TField *Sender,
          UnicodeString &Text, bool DisplayText)
{
Text = "Остаток на конец: "+ OstNaConOUT_KOL->AsString;
}
//---------------------------------------------------------------------------

