//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UREM_FormaStandartReport.h"
#include "IDMSprPrice.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IFormaDocReal.h"
#include "IDMQueryRead.h"
#include "IFormaDocOtchetPost.h"
#include "IFormaDocSpisNom.h"
#include "IDMSetup.h"
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
#pragma link "cxDBEdit"
#pragma link "cxLabel"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaStandartReport::TREM_FormaStandartReport(TComponent* Owner)
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
void __fastcall TREM_FormaStandartReport::FormCreate(TObject *Sender)
{
//
}
//-----------------------------------------------------------------------
bool TREM_FormaStandartReport::Init(void)
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
NameUsercxButtonEdit->Text="";
NameTypePricecxButtonEdit->Text="";
NameTypeNachislcxButtonEdit->Text="";
NameKlientcxButtonEdit->Text="";
NameProducercxButtonEdit->Text="";
NameBusinessOpercxButtonEdit->Text="";
NameProjectcxButtonEdit->Text="";


NameBrandcxButtonEdit->Text="";
NameModelcxButtonEdit->Text="";
NameProducerModelcxButtonEdit->Text="";
NameTypUselcxButtonEdit->Text="";
NameTypeRemontcxButtonEdit->Text="";

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaStandartReportImpl),false);
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
int  TREM_FormaStandartReport::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaStandartReport::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokSklad) SpisokSklad->kanRelease();
if(SpisokFirm) SpisokFirm->kanRelease();
if(SpisokGrpNom) SpisokGrpNom->kanRelease();
if(SpisokNom) SpisokNom->kanRelease();
if(SpisokUser) SpisokUser->kanRelease();
if(SpisokTypePrice) SpisokTypePrice->kanRelease();
if(SpisokTypeNachisl) SpisokTypeNachisl->kanRelease();
if(SpisokKlient) SpisokKlient->kanRelease();
if(SpisokProducer) SpisokProducer->kanRelease();
if(SpisokBusinessOper)SpisokBusinessOper->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();
if (FormaGurAllDoc)	FormaGurAllDoc->kanRelease();

if (REM_FormaSpiskaSprProducerModel)	REM_FormaSpiskaSprProducerModel->kanRelease();
if (REM_FormaSpiskaSprModel)	REM_FormaSpiskaSprModel->kanRelease();
if (REM_FormaSpiskaSprTypUslov)	REM_FormaSpiskaSprTypUslov->kanRelease();
if (FormaSpiskaSprBrand) FormaSpiskaSprBrand->kanRelease();
if (REM_FormaSpiskaSprTypeRemont) REM_FormaSpiskaSprTypeRemont->kanRelease();
if (FormaSpiskaTableExtPrintForm) FormaSpiskaTableExtPrintForm->kanRelease();

Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//----------------------------------------------------------------------------
void TREM_FormaStandartReport::OpenFormSpiskaSprNom(void)
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
void TREM_FormaStandartReport::OpenFormSpiskaSprFirm(void)
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
void TREM_FormaStandartReport::OpenFormSpiskaSprGrpNom(void)
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
int TREM_FormaStandartReport::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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

if (number_procedure_end==ViborUser)
		{
		if (type_event==1)
				{
				IdUser=glStrToInt64(SpisokUser->DM->TableID_USER->AsString);
				NameUsercxButtonEdit->Text=SpisokUser->DM->TableNAME_USER->AsString;
				}
		SpisokUser=0;
		}


if (number_procedure_end==ViborTypePrice)
		{
		if (type_event==1)
				{
				IdTypePrice=glStrToInt64(SpisokTypePrice->DM->TableID_TPRICE->AsString);
				NameTypePricecxButtonEdit->Text=SpisokTypePrice->DM->TableNAME_TPRICE->AsString;
				}
		SpisokTypePrice=0;
		}

if (number_procedure_end==ViborTypeNachisl)
		{
		if (type_event==1)
				{
				IdTypeNachisl=glStrToInt64(SpisokTypeNachisl->DM->TableID_STNACHISL->AsString);
				NameTypeNachislcxButtonEdit->Text=SpisokTypeNachisl->DM->TableNAME_STNACHISL->AsString;
				}
		SpisokTypeNachisl=0;
		}


if (number_procedure_end==ViborKlient)
		{
		if (type_event==1)
				{
				IdKlient=glStrToInt64(SpisokKlient->DM->TableIDKLIENT->AsString);
				NameKlientcxButtonEdit->Text=SpisokKlient->DM->TableNAMEKLIENT->AsString;
				}
		SpisokKlient=0;
		}

if (number_procedure_end==ViborProducer)
		{
		if (type_event==1)
				{
				IdProducer=glStrToInt64(SpisokProducer->DM->TableID_SPRODUCER->AsString);
				NameProducercxButtonEdit->Text=SpisokProducer->DM->TableNAME_SPRODUCER->AsString;
				}
		SpisokProducer=0;
		}


if (number_procedure_end==ER_Project)
		{
		if (type_event==1)
				{
				EndViborProject()  ;
				}
		SpisokProject=0;
		}

if (number_procedure_end==ER_BusinessOper)
		{
		if (type_event==1)
				{
				EndViborBusinessOper()  ;
				}
		SpisokBusinessOper=0;
		}


	if (number_procedure_end == ER_ViborDocReal) {
		if (type_event == 1) {
			EndViborDocReal();
		}
		FormaGurAllDoc = 0;
	}

	if (number_procedure_end == ER_ViborOtchetPost)
	{
		if (type_event == 1) {
			EndViborDocOtchetPost();
		}
		FormaGurAllDoc = 0;
	}

	if (number_procedure_end == ER_ViborModel)
	{
		if (type_event == 1) {
			EventEndEditModel();
		}
		REM_FormaSpiskaSprModel = 0;
	}

	if (number_procedure_end == ER_ViborProducerModel)
	{
		if (type_event == 1) {
			EventEndEditProducerModel();
		}
		REM_FormaSpiskaSprProducerModel = 0;
	}

	if (number_procedure_end == ER_ViborTypUsla)
	{
		if (type_event == 1) {
			EventEndEditTypUslov();
		}
		REM_FormaSpiskaSprTypUslov = 0;
	}

	if (number_procedure_end == ER_ViborBrand)
	{
		if (type_event == 1) {
			EventEndEditBrand();
		}
		FormaSpiskaSprBrand = 0;
	}

	if (number_procedure_end == ER_ViborTypeRemont)
	{
		if (type_event == 1) {
			EventEndEditTypeRemont();
		}
		REM_FormaSpiskaSprTypeRemont = 0;
	}

	if (number_procedure_end == ER_ViborExtPrintForm)
	{
		if (type_event == 1) {
			EventEndViborExtPrintForm();
		}
		FormaSpiskaTableExtPrintForm = 0;
	}

EditRekvisit=NO;
return -1;
}
//---------------------------------------------------------------------------
void TREM_FormaStandartReport::OpenFormSpiskaSprSklad(void)
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






void __fastcall TREM_FormaStandartReport::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaStandartReport::NameNomEditPropertiesButtonClick(
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

void __fastcall TREM_FormaStandartReport::NameGrpNomEditPropertiesButtonClick(
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

void __fastcall TREM_FormaStandartReport::NameSkladEditPropertiesButtonClick(
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

void __fastcall TREM_FormaStandartReport::NameFirmEditPropertiesButtonClick(
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
void __fastcall TREM_FormaStandartReport::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaStandartReport::RunExternalModule(__int64 id_module, int type_module)
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
	module->SetInt64Variables("glIdUser", IdUser);
	module->SetInt64Variables("glIdTypePrice", IdTypePrice);
	module->SetInt64Variables("glIdTypeNachisl", IdTypeNachisl);
	module->SetInt64Variables("glIdKlient", IdKlient);
	module->SetInt64Variables("glIdProducer", IdProducer);
	module->SetInt64Variables("glIdBusinessOper", IdBusinessOper);
	module->SetInt64Variables("glIdProject", IdProject);
	module->SetDateTimeVariables("glPosBegin", DateNach->Date);
	module->SetDateTimeVariables("glPosEnd", DateCon->Date);

	module->SetInt64Variables("glIdModel", IdModel);
	module->SetInt64Variables("glIdProducerModel", IdProducerModel);
	module->SetInt64Variables("glIdBrand", IdBrand);
	module->SetInt64Variables("glIdTypUsla", IdTypUsla);
	module->SetInt64Variables("glIdTypeRemont", IdTypeRemont);
	
module->ExecuteModule();

}
//-----------------------------------------------------------------------------
void __fastcall TREM_FormaStandartReport::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void TREM_FormaStandartReport::OpenFormSpiskaSprUser(void)
{
if (SpisokUser==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprUser,IID_IFormaSpiskaSprUser,
													(void**)&SpisokUser);
		SpisokUser->Init(InterfaceMainObject,InterfaceImpl);
		SpisokUser->Vibor=true;
		SpisokUser->NumberProcVibor=ViborUser;
		SpisokUser->IdUser=IdUser;
		SpisokUser->UpdateForm();
		}
}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaStandartReport::NameUsercxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprUser();
		}break;
	case 1:
		{
		IdNom=0;
		NameUsercxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------
void TREM_FormaStandartReport::OpenFormSpiskaSprTypePrice(void)
{
if (SpisokTypePrice==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprTypePrice,IID_IFormaSpiskaSprTypePrice,
													(void**)&SpisokTypePrice);
		SpisokTypePrice->Init(InterfaceMainObject,InterfaceImpl);
		SpisokTypePrice->Vibor=true;
		SpisokTypePrice->NumberProcVibor=ViborTypePrice;
		//SpisokTypePrice->IdTypePrice=IdTypePrice;
		//SpisokTypePrice->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void TREM_FormaStandartReport::OpenFormSpiskaSprTypeNachisl(void)
{
if (SpisokTypeNachisl==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprTypeNachisl,IID_IFormaSpiskaSprTypeNachisl,
													(void**)&SpisokTypeNachisl);
		SpisokTypeNachisl->Init(InterfaceMainObject,InterfaceImpl);
		SpisokTypeNachisl->Vibor=true;
		SpisokTypeNachisl->NumberProcVibor=ViborTypeNachisl;
		//SpisokTypeNachisl->IdTypeNachisl=IdTypeNachisl;
		SpisokTypeNachisl->UpdateForm();
		}
}
//------------------------------------------------------------------------------
void TREM_FormaStandartReport::OpenFormSpiskaSprKlient(void)
{
if (SpisokKlient==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprKlient,IID_IFormaSpiskaSprKlient,
													(void**)&SpisokKlient);
		SpisokKlient->Init(InterfaceMainObject,InterfaceImpl);
		SpisokKlient->Vibor=true;
		SpisokKlient->NumberProcVibor=ViborKlient;
		SpisokKlient->IdKlient=IdKlient;
		SpisokKlient->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void TREM_FormaStandartReport::OpenFormSpiskaSprProducer(void)
{
if (SpisokProducer==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprProducer,IID_IFormaSpiskaSprProducer,
													(void**)&SpisokProducer);
		SpisokProducer->Init(InterfaceMainObject,InterfaceImpl);
		SpisokProducer->Vibor=true;
		SpisokProducer->NumberProcVibor=ViborProducer;
		//SpisokProducer->IdProducer=IdProducer;
		//SpisokProducer->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaStandartReport::NameTypePricecxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprTypePrice();
		}break;
	case 1:
		{
		IdTypePrice=0;
		NameTypePricecxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaStandartReport::NameTypeNachislcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprTypeNachisl();
		}break;
	case 1:
		{
		IdTypeNachisl=0;
		NameTypeNachislcxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaStandartReport::NameKlientcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprKlient();
		}break;
	case 1:
		{
		IdNom=0;
		NameKlientcxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaStandartReport::NameProducercxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprProducer();
		}break;
	case 1:
		{
		IdProducer=0;
		NameProducercxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------
void TREM_FormaStandartReport::OpenFormSpiskaSprProject(void)
{

if (SpisokProject==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprProject.1",IID_IFormaSpiskaSprProject,
													(void**)&SpisokProject);
		SpisokProject->Init(InterfaceMainObject,InterfaceImpl);
		SpisokProject->NumberProcVibor=ER_Project;
		SpisokProject->Vibor=true;
		SpisokProject->UpdateForm();

		}
}
//----------------------------------------------------------------------------
void  TREM_FormaStandartReport::EndViborProject(void)
{

IdProject=glStrToInt64(SpisokProject->DM->TableID_SPROJECT->AsString);
NameProjectcxButtonEdit->Text=SpisokProject->DM->TableNAME_SPROJECT->AsString;

}
//----------------------------------------------------------------------------
void TREM_FormaStandartReport::OpenFormSpiskaSprBusinessOper(void)
{

if (SpisokBusinessOper==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprBusinessOper,IID_IFormaSpiskaSprBusinessOper,
													(void**)&SpisokBusinessOper);
		SpisokBusinessOper->Init(InterfaceMainObject,InterfaceImpl);
		SpisokBusinessOper->NumberProcVibor=ER_BusinessOper;
		SpisokBusinessOper->Vibor=true;
		SpisokBusinessOper->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void TREM_FormaStandartReport::EndViborBusinessOper(void)
{

IdBusinessOper=glStrToInt64(SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString);
NameBusinessOpercxButtonEdit->Text=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaStandartReport::NameBusinessOpercxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprBusinessOper();
		}break;
	case 1:
		{
		IdBusinessOper=0;
		NameBusinessOpercxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaStandartReport::NameProjectcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
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
// ---------------------------------------------------------------------------
void TREM_FormaStandartReport::ViborDocReal(void)
{


	if (FormaGurAllDoc == NULL)
	{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaGurAllDoc.1",
			IID_IFormaGurAllDoc, (void**) & FormaGurAllDoc);
		FormaGurAllDoc->Init(InterfaceMainObject, InterfaceImpl);
		FormaGurAllDoc->Vibor = true;
		FormaGurAllDoc->NumberProcVibor = ER_ViborDocReal;
	}
}

// ----------------------------------------------------------------------------
void TREM_FormaStandartReport::EndViborDocReal(void)
{

	if (FormaGurAllDoc->DM->TableTDOC->AsString == "REA")
		{
		__int64 id_doc = glStrToInt64(FormaGurAllDoc->DM->TableIDDOC->AsString);
		if (id_doc > 0)
			{
			IFormaDocReal * doc;
			InterfaceGlobalCom->kanCreateObject(ProgId_FormaDocReal,
								IID_IFormaDocReal, (void**) & doc);
			doc->Init(InterfaceMainObject, InterfaceImpl);
			doc->DM->OpenDoc(id_doc);
			doc->UpdateForm();

			IDMQueryRead * dm_query;
			InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
									 (void**)&dm_query);
			dm_query->Init(InterfaceMainObject,InterfaceImpl);

			UnicodeString zapros="select                                                   \
									rem_gur_zaktpr_sum_za_period.*,                        \
									snom.artnom,                                           \
									snom.codenom,                                          \
									snom.namenom,                                          \
									snom.idbasednom,                                       \
									sed.nameed,                                              \
									sed.shed                                               \
								from  rem_gur_zaktpr_sum_za_period(:PARAM_IDPRODUCER, :PARAM_POS_START, :PARAM_POS_END) \
																														\
								left outer join snom on snom.idnom=rem_gur_zaktpr_sum_za_period.out_idnom               \
								left outer join sed on sed.ided=snom.idbasednom                                         \
								order by snom.tnom, snom.namenom    ";
			dm_query->pFIBQ->SQL->Clear();
			dm_query->pFIBQ->SQL->Add(zapros);

			dm_query->pFIBQ->ParamByName("PARAM_IDPRODUCER")->AsString=IdProducer;
			dm_query->pFIBQ->ParamByName("PARAM_POS_START")->AsDateTime=DateNach->Date;
			dm_query->pFIBQ->ParamByName("PARAM_POS_END")->AsDateTime=DateCon->Date;

			dm_query->pFIBQ->ExecQuery();

			while (!dm_query->pFIBQ->Eof)
				{
				doc->DM->AddDocNewString();
				doc->DM->DocT->Edit();
				doc->DM->DocTIDNOMREAT->AsString=dm_query->pFIBQ->FieldByName("OUT_IDNOM")->AsString;
				doc->DM->DocTIDEDREAT->AsString=dm_query->pFIBQ->FieldByName("IDBASEDNOM")->AsString;
				doc->DM->DocTARTNOM->AsString=dm_query->pFIBQ->FieldByName("ARTNOM")->AsString;
				doc->DM->DocTCODENOM->AsString=dm_query->pFIBQ->FieldByName("CODENOM")->AsString;
				doc->DM->DocTNAMENOM->AsString=dm_query->pFIBQ->FieldByName("NAMENOM")->AsString;
				doc->DM->DocTNAMEED->AsString=dm_query->pFIBQ->FieldByName("NAMEED")->AsString;
				doc->DM->DocTSHED->AsString=dm_query->pFIBQ->FieldByName("SHED")->AsString;
				doc->DM->DocTKOLREAT->AsFloat=dm_query->pFIBQ->FieldByName("OUT_KOL")->AsFloat;
                doc->DM->DocTKFREAT->AsFloat=1;

				if (dm_query->pFIBQ->FieldByName("OUT_KOL")->AsFloat > 0)
					{
					doc->DM->DocTPRICEREAT->AsFloat=dm_query->pFIBQ->FieldByName("OUT_SUM")->AsFloat/dm_query->pFIBQ->FieldByName("OUT_KOL")->AsFloat;
					}
                doc->DM->DocT->Post();
				dm_query->pFIBQ->Next();
				}



            dm_query->kanRelease();


			}


		}
	else
		{
		ShowMessage("Добавляем только в реализацию!");

		}

}
// ----------------------------------------------------------------------------


void __fastcall TREM_FormaStandartReport::cxButton2Click(TObject *Sender)
{
ViborDocReal();
}
//---------------------------------------------------------------------------
void TREM_FormaStandartReport::ViborDocOtchetPost(void)
{


	if (FormaGurAllDoc == NULL)
	{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaGurAllDoc.1",
			IID_IFormaGurAllDoc, (void**) & FormaGurAllDoc);
		FormaGurAllDoc->Init(InterfaceMainObject, InterfaceImpl);
		FormaGurAllDoc->Vibor = true;
		FormaGurAllDoc->NumberProcVibor = ER_ViborOtchetPost;
	}
}

// ----------------------------------------------------------------------------
void TREM_FormaStandartReport::EndViborDocOtchetPost(void)
{

	if (FormaGurAllDoc->DM->TableTDOC->AsString == "OTCHPOST")
		{
		__int64 id_doc = glStrToInt64(FormaGurAllDoc->DM->TableIDDOC->AsString);
		if (id_doc > 0)
			{
			IFormaDocOtchetPost * doc;
			InterfaceGlobalCom->kanCreateObject(ProgId_FormaDocOtchetPost,
								IID_IFormaDocOtchetPost, (void**) & doc);
			doc->Init(InterfaceMainObject, InterfaceImpl);
			doc->DM->OpenDoc(id_doc);
			doc->UpdateForm();

			IDMQueryRead * dm_query;
			InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
									 (void**)&dm_query);
			dm_query->Init(InterfaceMainObject,InterfaceImpl);

			UnicodeString zapros="select                                                   \
									rem_gur_zaktpr_sum_za_period.*,                        \
									snom.artnom,                                           \
									snom.codenom,                                          \
									snom.namenom,                                          \
									snom.idbasednom,                                       \
									sed.nameed,                                              \
									sed.shed                                               \
								from  rem_gur_zaktpr_sum_za_period(:PARAM_IDPRODUCER, :PARAM_POS_START, :PARAM_POS_END) \
																														\
								left outer join snom on snom.idnom=rem_gur_zaktpr_sum_za_period.out_idnom               \
								left outer join sed on sed.ided=snom.idbasednom                                         \
								order by snom.tnom, snom.namenom    ";
			dm_query->pFIBQ->SQL->Clear();
			dm_query->pFIBQ->SQL->Add(zapros);

			dm_query->pFIBQ->ParamByName("PARAM_IDPRODUCER")->AsString=IdProducer;
			dm_query->pFIBQ->ParamByName("PARAM_POS_START")->AsDateTime=DateNach->Date;
			dm_query->pFIBQ->ParamByName("PARAM_POS_END")->AsDateTime=DateCon->Date;

			dm_query->pFIBQ->ExecQuery();

			while (!dm_query->pFIBQ->Eof)
				{
				doc->DM->AddDocNewString();
				doc->DM->DocT->Edit();
				doc->DM->DocTIDNOM_DOTCHPOSTT->AsString=dm_query->pFIBQ->FieldByName("OUT_IDNOM")->AsString;
				doc->DM->DocTIDED_DOTCHPOSTT->AsString=dm_query->pFIBQ->FieldByName("IDBASEDNOM")->AsString;
				doc->DM->DocTARTNOM->AsString=dm_query->pFIBQ->FieldByName("ARTNOM")->AsString;
				doc->DM->DocTCODENOM->AsString=dm_query->pFIBQ->FieldByName("CODENOM")->AsString;
				doc->DM->DocTNAMENOM->AsString=dm_query->pFIBQ->FieldByName("NAMENOM")->AsString;
				doc->DM->DocTNAMEED->AsString=dm_query->pFIBQ->FieldByName("NAMEED")->AsString;
				doc->DM->DocTSHED->AsString=dm_query->pFIBQ->FieldByName("SHED")->AsString;
				doc->DM->DocTKOL_DOTCHPOSTT->AsFloat=dm_query->pFIBQ->FieldByName("OUT_KOL")->AsFloat;
				doc->DM->DocTKF_DOTCHPOSTT->AsFloat=1;

				if (dm_query->pFIBQ->FieldByName("OUT_KOL")->AsFloat > 0)
					{
					doc->DM->DocTPRICE_DOTCHPOSTT->AsFloat=dm_query->pFIBQ->FieldByName("OUT_SUM")->AsFloat/dm_query->pFIBQ->FieldByName("OUT_KOL")->AsFloat;
					}
                doc->DM->DocT->Post();
				dm_query->pFIBQ->Next();
				}



            dm_query->kanRelease();


			}


		}
	else
		{
		ShowMessage("Добавляем только в Отчет поставщику!");

		}

}
// ----------------------------------------------------------------------------
void __fastcall TREM_FormaStandartReport::cxButtonZapolnitOtchetPostClick(TObject *Sender)
{
ViborDocOtchetPost();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaStandartReport::cxButtonCreateAktSpisNomClick(TObject *Sender)

{

			IFormaDocSpisNom * doc;
			InterfaceGlobalCom->kanCreateObject(ProgId_FormaDocSpisNom,
								IID_IFormaDocSpisNom, (void**) & doc);
			doc->Init(InterfaceMainObject, InterfaceImpl);
			doc->DM->NewDoc();
			doc->UpdateForm();

			IDMQueryRead * dm_query;
			InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
									 (void**)&dm_query);
			dm_query->Init(InterfaceMainObject,InterfaceImpl);

			UnicodeString zapros="select                                                                                              \
									rem_rggoods_dv.idnom_rem_rggoods_dv,                                                              \
									snom.artnom,                                                                                      \
									snom.codenom,                                                                                     \
									snom.namenom,                                                                                     \
									snom.idbasednom,                                                                                  \
									sed.nameed,                                                                                       \
									sed.shed,                                                                                         \
									sum(rem_rggoods_dv.kol_rem_rggoods_dv) as kol_dv                                                           \
																																	  \
								from  rem_rggoods_dv                                                                                  \
																																	  \
								left outer join snom on snom.idnom=rem_rggoods_dv.idnom_rem_rggoods_dv                                \
								left outer join sed on sed.ided=snom.idbasednom                                                       \
																																	  \
								where rem_rggoods_dv.idfirm_rem_rggoods_dv=:PARAM_IDFIRM                                              \
										and rem_rggoods_dv.idsklad_rem_rggoods_dv=:PARAM_IDSKLAD                                      \
										and rem_rggoods_dv.idbusinop_rem_rggoods_dv=:PARAM_IDOPER                                     \
										and (rem_rggoods_dv.posdoc_rem_rggoods_dv between :PARAM_POS_START and :PARAM_POS_END)        \
																																	  \
								group by                                                                                              \
																																	  \
									rem_rggoods_dv.idnom_rem_rggoods_dv,                                                              \
									snom.artnom,                                                                                      \
									snom.codenom,                                                                                     \
									snom.namenom,                                                                                     \
									snom.idbasednom,                                                                                  \
									sed.nameed,                                                                                       \
									sed.shed                                                                                          \
								order by snom.namenom  ";
			dm_query->pFIBQ->SQL->Clear();
			dm_query->pFIBQ->SQL->Add(zapros);

			dm_query->pFIBQ->ParamByName("PARAM_IDFIRM")->AsString=IdFirm;
			dm_query->pFIBQ->ParamByName("PARAM_IDSKLAD")->AsString=IdSkl;
			dm_query->pFIBQ->ParamByName("PARAM_IDOPER")->AsString=IdBusinessOper;
			dm_query->pFIBQ->ParamByName("PARAM_POS_START")->AsDateTime=DateNach->Date;
			dm_query->pFIBQ->ParamByName("PARAM_POS_END")->AsDateTime=DateCon->Date;

			dm_query->pFIBQ->ExecQuery();

			while (!dm_query->pFIBQ->Eof)
				{
				doc->DM->AddDocNewString();
				doc->DM->DocT->Edit();
				doc->DM->DocTIDNOMSPNT->AsString=dm_query->pFIBQ->FieldByName("idnom_rem_rggoods_dv")->AsString;
				doc->DM->DocTIDEDSPNT->AsString=dm_query->pFIBQ->FieldByName("IDBASEDNOM")->AsString;
				doc->DM->DocTARTNOM->AsString=dm_query->pFIBQ->FieldByName("ARTNOM")->AsString;
				doc->DM->DocTCODENOM->AsString=dm_query->pFIBQ->FieldByName("CODENOM")->AsString;
				doc->DM->DocTNAMENOM->AsString=dm_query->pFIBQ->FieldByName("NAMENOM")->AsString;
				doc->DM->DocTNAMEED->AsString=dm_query->pFIBQ->FieldByName("NAMEED")->AsString;
				doc->DM->DocTSHED->AsString=dm_query->pFIBQ->FieldByName("SHED")->AsString;
				doc->DM->DocTKOLSPNT->AsFloat=dm_query->pFIBQ->FieldByName("KOL_DV")->AsFloat;
				doc->DM->DocTKFSPNT->AsFloat=1;

                doc->DM->DocT->Post();
				dm_query->pFIBQ->Next();
				}



            dm_query->kanRelease();


}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaStandartReport::cxButtonProvGarTalonClick(TObject *Sender)
{

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
UnicodeString catalog_name="";
DMSetup->OpenElement(330);
catalog_name=DMSetup->ElementVALUE_SETUP->AsString;
DMSetup->kanRelease();


			IDMQueryRead * dm_query;
			InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
									 (void**)&dm_query);
			dm_query->Init(InterfaceMainObject,InterfaceImpl);

			UnicodeString zapros="select rem_galldoc.prefiks_num_rem_galldoc,                \
									rem_galldoc.num_rem_galldoc,                             \
									rem_galldoc.pos_rem_galldoc,                             \
									rem_dzaktpr.numgartalon_rem_dzaktpr,                     \
									rem_z.sernum_rem_z,                                      \
									rem_z.sernum2_rem_z,                                     \
									rem_dzaktpr.sernum3_rem_dzaktpr,                         \
									rem_sprmodel.name_rem_sprmodel                           \
							from rem_dzaktpr                                                  \
							left outer join rem_galldoc on  rem_galldoc.id_rem_galldoc=rem_dzaktpr.iddoc_rem_dzaktpr                     \
							left outer join rem_z on  rem_z.id_rem_z=rem_dzaktpr.idz_rem_dzaktpr                                         \
							left outer join rem_sprmodel  on  rem_sprmodel.id_rem_sprmodel=rem_dzaktpr.idprmodel_rem_dzaktpr             \
							where                                                                                                        \
									rem_dzaktpr.idpr_rem_dzaktpr =:PARAM_IDPRODUCER                                                      \
									and rem_galldoc.pos_rem_galldoc between :PARAM_POS_NACH and :PARAM_POS_CON   ";
			dm_query->pFIBQ->SQL->Clear();
			dm_query->pFIBQ->SQL->Add(zapros);

			dm_query->pFIBQ->ParamByName("PARAM_IDPRODUCER")->AsString=IdProducer;
			dm_query->pFIBQ->ParamByName("PARAM_POS_NACH")->AsDateTime=DateNach->Date;
			dm_query->pFIBQ->ParamByName("PARAM_POS_CON")->AsDateTime=DateCon->Date;

			dm_query->pFIBQ->ExecQuery();
			int kol=0;
			while (!dm_query->pFIBQ->Eof)
				{
				kol++;
				WORD Year;
				WORD Month;
				WORD Day;
				DecodeDate(dm_query->pFIBQ->FieldByName("pos_rem_galldoc")->AsDateTime,Year,Month,Day);
				UnicodeString file_name=catalog_name+"\\"+Trim(NameProducercxButtonEdit->Text)         // Производитель
									+"\\"+IntToStr(Month)+"_"+IntToStr(Year)
									+"\\"+Trim(dm_query->pFIBQ->FieldByName("numgartalon_rem_dzaktpr")->AsString)
									+".jpg";                                                  //месяц


				if (FileExists(file_name)==true)
					{
					}
				else
					{
					 UnicodeString s="";
					 s="Нет файла "+file_name
					 +"\n Акт "+dm_query->pFIBQ->FieldByName("prefiks_num_rem_galldoc")->AsString
//									//+file_name
//                                    //+" Изделие "

									+" "+dm_query->pFIBQ->FieldByName("num_rem_galldoc")->AsString
									+" от "+dm_query->pFIBQ->FieldByName("pos_rem_galldoc")->AsString
									+", гар. талон: "+dm_query->pFIBQ->FieldByName("numgartalon_rem_dzaktpr")->AsString
									+", номер "+dm_query->pFIBQ->FieldByName("sernum_rem_z")->AsString
									+", номер2 "+dm_query->pFIBQ->FieldByName("sernum2_rem_z")->AsString
									+", номер3 "+dm_query->pFIBQ->FieldByName("sernum3_rem_dzaktpr")->AsString
									+", модель: "+dm_query->pFIBQ->FieldByName("name_rem_sprmodel")->AsString;

					ShowMessage(s);

					}


				dm_query->pFIBQ->Next();

				}



dm_query->kanRelease();


ShowMessage("Всего документов: "+IntToStr(kol));
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaStandartReport::cxButtonProvAktPoTalonamClick(TObject *Sender)

{

UnicodeString name_catalog="";

if (OpenDialog1->Execute())
  {
  name_catalog=ExtractFileDir(OpenDialog1->FileName);
  }


			IDMQueryRead * dm_query;
			InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
									 (void**)&dm_query);
			dm_query->Init(InterfaceMainObject,InterfaceImpl);

			UnicodeString zapros="select rem_galldoc.id_rem_galldoc                                                                     \
										from rem_dzaktpr                                                                                 \
										left outer join rem_galldoc on  rem_galldoc.id_rem_galldoc=rem_dzaktpr.iddoc_rem_dzaktpr        \
										where                                                                                           \
												rem_dzaktpr.idpr_rem_dzaktpr =:PARAM_IDPRODUCER                                         \
												and rem_galldoc.pos_rem_galldoc between :PARAM_POS_NACH and :PARAM_POS_CON              \
												and rem_dzaktpr.numgartalon_rem_dzaktpr=:PARAM_NUM_GAR_TALON  ";
			dm_query->pFIBQ->SQL->Clear();
			dm_query->pFIBQ->SQL->Add(zapros);



TSearchRec F;
int ires=FindFirst(name_catalog+"\\*.*",faAnyFile|faDirectory,F);
int kol=0;
while (!ires)
	{
	 if (F.Attr &faDirectory)
		{//каталог

		}
	 else
		{//файл
		kol++;
		UnicodeString file_name=" "; file_name=F.Name;
		UnicodeString num_gar_talon=" "; num_gar_talon=ExtractFileName(file_name);
		num_gar_talon=Trim(num_gar_talon.Delete(num_gar_talon.Length()-3,4));

			dm_query->pFIBQ->ParamByName("PARAM_IDPRODUCER")->AsString=IdProducer;
			dm_query->pFIBQ->ParamByName("PARAM_POS_NACH")->AsDateTime=DateNach->Date;
			dm_query->pFIBQ->ParamByName("PARAM_POS_CON")->AsDateTime=DateCon->Date;
			dm_query->pFIBQ->ParamByName("PARAM_NUM_GAR_TALON")->AsString=num_gar_talon;
			dm_query->pFIBQ->ExecQuery();

				if (dm_query->pFIBQ->RecordCount > 0)
					{
					}
				else
					{
					 UnicodeString s="";
					 s="Нет акта для талона "+num_gar_talon+", файл "+file_name;


					ShowMessage(s);

					}




		}
	ires=FindNext(F);
	}
FindClose(F);


dm_query->kanRelease();
ShowMessage("Всего файлов: "+IntToStr(kol));
}
//---------------------------------------------------------------------------
void TREM_FormaStandartReport::ViborModel(void)
{

if (REM_FormaSpiskaSprModel==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprModel,IID_IREM_FormaSpiskaSprModel,
													(void**)&REM_FormaSpiskaSprModel);
		REM_FormaSpiskaSprModel->Init(InterfaceMainObject,InterfaceImpl);
		REM_FormaSpiskaSprModel->NumberProcVibor=ER_ViborModel;
		REM_FormaSpiskaSprModel->Vibor=true;
		REM_FormaSpiskaSprModel->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void TREM_FormaStandartReport::EventEndEditModel(void)
{

IdModel=glStrToInt64(REM_FormaSpiskaSprModel->DM->TableID_REM_SMODEL->AsString);
NameModelcxButtonEdit->Text=REM_FormaSpiskaSprModel->DM->TableNAME_REM_SMODEL->AsString;
}
//-----------------------------------------------------------------------------
void TREM_FormaStandartReport::ViborProducerModel(void)
{

if (REM_FormaSpiskaSprProducerModel==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprProducerModel,IID_IREM_FormaSpiskaSprProducerModel,
													(void**)&REM_FormaSpiskaSprProducerModel);
		REM_FormaSpiskaSprProducerModel->Init(InterfaceMainObject,InterfaceImpl);
		REM_FormaSpiskaSprProducerModel->NumberProcVibor=ER_ViborProducerModel;
		REM_FormaSpiskaSprProducerModel->flVibor=true;
		REM_FormaSpiskaSprProducerModel->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void TREM_FormaStandartReport::EventEndEditProducerModel(void)
{

IdProducerModel=glStrToInt64(REM_FormaSpiskaSprProducerModel->DM->TableID_REM_SPRMODEL->AsString);
NameProducerModelcxButtonEdit->Text=REM_FormaSpiskaSprProducerModel->DM->TableNAME_REM_SPRMODEL->AsString;
}
//-----------------------------------------------------------------------------
void TREM_FormaStandartReport::ViborTypUsla(void)
{

if (REM_FormaSpiskaSprTypUslov==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprTypUslov,IID_IREM_FormaSpiskaSprTypUslov,
													(void**)&REM_FormaSpiskaSprTypUslov);
		REM_FormaSpiskaSprTypUslov->Init(InterfaceMainObject,InterfaceImpl);
		REM_FormaSpiskaSprTypUslov->NumberProcVibor=ER_ViborTypUsla;
		REM_FormaSpiskaSprTypUslov->flVibor=true;
		REM_FormaSpiskaSprTypUslov->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void TREM_FormaStandartReport::EventEndEditTypUslov(void)
{

IdTypUsla=glStrToInt64(REM_FormaSpiskaSprTypUslov->DM->TableID_REM_STYPUSLOV->AsString);
NameTypUselcxButtonEdit->Text=REM_FormaSpiskaSprTypUslov->DM->TableNAME_REM_STYPUSLOV->AsString;
}
//-----------------------------------------------------------------------------
void TREM_FormaStandartReport::ViborBrand(void)
{

if (FormaSpiskaSprBrand==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprBrand,IID_IFormaSpiskaSprBrand,
													(void**)&FormaSpiskaSprBrand);
		FormaSpiskaSprBrand->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprBrand->NumberProcVibor=ER_ViborBrand;
		FormaSpiskaSprBrand->Vibor=true;
		FormaSpiskaSprBrand->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void TREM_FormaStandartReport::EventEndEditBrand(void)
{

IdBrand=glStrToInt64(FormaSpiskaSprBrand->DM->TableID_SBRAND->AsString);
NameBrandcxButtonEdit->Text=FormaSpiskaSprBrand->DM->TableNAME_SBRAND->AsString;
}
//-----------------------------------------------------------------------------
void __fastcall TREM_FormaStandartReport::NameBrandcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborBrand();
		}break;
	case 1:
		{
		IdBrand=0;
		NameBrandcxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaStandartReport::NameModelcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborModel();
		}break;
	case 1:
		{
		IdModel=0;
		NameModelcxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaStandartReport::NameProducerModelcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborProducerModel();
		}break;
	case 1:
		{
		IdProducerModel=0;
		NameProducerModelcxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaStandartReport::NameTypUselcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborTypUsla();
		}break;
	case 1:
		{
		IdTypUsla=0;
		NameTypUselcxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------
void TREM_FormaStandartReport::EventEndEditTypeRemont(void)
{
IdTypeRemont=glStrToInt64(REM_FormaSpiskaSprTypeRemont->DM->TableID_STREMONT->AsString);
NameTypeRemontcxButtonEdit->Text=REM_FormaSpiskaSprTypeRemont->DM->TableNAME_STREMONT->AsString;

}
//--------------------------------------------------------------------------
void TREM_FormaStandartReport::ViborTypeRemont(void)
{
if (REM_FormaSpiskaSprTypeRemont==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprTypeRemont,IID_IREM_FormaSpiskaSprTypeRemont,
													(void**)&REM_FormaSpiskaSprTypeRemont);
		REM_FormaSpiskaSprTypeRemont->Init(InterfaceMainObject,InterfaceImpl);
		REM_FormaSpiskaSprTypeRemont->NumberProcVibor=ER_ViborTypeRemont;
		REM_FormaSpiskaSprTypeRemont->Vibor=true;
		//REM_FormaSpiskaSprTypeRemont->UpdateForm();
		}

}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaStandartReport::NameTypeRemontcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborTypeRemont();
		}break;
	case 1:
		{
		IdTypeRemont=0;
		NameTypeRemontcxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------
void TREM_FormaStandartReport::EventEndViborExtPrintForm(void)
{
RunExternalModule(glStrToInt64(FormaSpiskaTableExtPrintForm->DM->TableID_EXTPRINT_FORM->AsString),
					FormaSpiskaTableExtPrintForm->DM->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);

}
//----------------------------------------------------------------------------
void TREM_FormaStandartReport::ViborExtPrintForm(void)
{


if (FormaSpiskaTableExtPrintForm==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaTableExtPrintForm,IID_IFormaSpiskaTableExtPrintForm,
													(void**)&FormaSpiskaTableExtPrintForm);
		FormaSpiskaTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaTableExtPrintForm->NumberProcVibor=ER_ViborExtPrintForm;
		FormaSpiskaTableExtPrintForm->Vibor=true;
		FormaSpiskaTableExtPrintForm->DM->OpenTable(StringToGUID(Global_CLSID_TREM_FormaStandartReportImpl),false);
		//REM_FormaSpiskaSprTypeRemont->UpdateForm();
		}
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaStandartReport::cxButtonViborExtPrintFormClick(TObject *Sender)

{
ViborExtPrintForm();
}
//---------------------------------------------------------------------------

