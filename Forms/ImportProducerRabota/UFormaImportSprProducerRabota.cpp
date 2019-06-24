//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaImportSprProducerRabota.h"
#include "UDM.h"
#include "IREM_DMSprProducerRabota.h"
#include "IDMSprProducer.h"

#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IAsyncExternalEvent.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxSpinEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtonEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxGraphics"
#pragma link "cxPC"
#pragma link "cxSSheet"
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
#pragma link "cxGridBandedTableView"
#pragma link "cxCalc"
#pragma link "cxCheckBox"
#pragma link "cxLookAndFeels"
#pragma link "cxButtonEdit"
#pragma link "cxButtons"
#pragma link "cxCalc"
#pragma link "cxCheckBox"
#pragma link "cxClasses"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridBandedTableView"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMaskEdit"
#pragma link "cxPC"
#pragma link "cxSpinEdit"
#pragma link "cxSSheet"
#pragma link "cxStyles"
#pragma link "cxTextEdit"
#pragma link "cxMemo"
//----------------------------
#pragma link "cxExportC14"
#include "cxGridExportLink.hpp"
//--------------------------------

#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaImportSprProducerRabota::TFormaImportSprProducerRabota(TComponent* Owner)
	: TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
TypeEvent=0;
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportSprProducerRabota::FormCreate(TObject *Sender)
{
NameImportSetcxButtonEdit->Text="";
FileNamecxButtonEdit->Text="";

IdKlient=0;
NameKlientcxButtonEdit->Text="";

IdGrpNom=0;
NameGrpNomcxButtonEdit->Text="";

StartStringcxSpinEdit->Text="0";
NamecxSpinEdit->Text="0";


LabelError->Caption="";
NameProducercxButtonEdit->Text="";
KolErrorForStopcxSpinEdit->Text="0";

}
//-----------------------------------------------------------------------
bool TFormaImportSprProducerRabota::Init(void)
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

	//зарегистрируем свой IAsyncExternalEvent в главном модуле для получения событий
	if(InterfaceMainObject)
		{
		IAsyncExternalEvent * interf=0;
		InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
		if (interf)
			{
			interf->SetInterfaceForAsyncExternalEvent(InterfaceImpl);
			interf->kanRelease();
			}
		}
	}

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprImportSet.1",IID_IDMSprImportSet,
					 (void**)&DMSprImportSet);
DMSprImportSet->Init(InterfaceMainObject,InterfaceImpl);


IdInfBase=DM_Connection->UserInfoIDBASE_SUSER->AsInt64;
NameInfBasecxButtonEdit->Text=DM_Connection->UserInfoNAME_SINFBASE_OBMEN->AsString;
IdFirm=DM_Connection->UserInfoIDFIRM_USER->AsInt64;
NameFirmcxButtonEdit->Text=DM_Connection->UserInfoNAMEFIRM->AsString;
IdSklad=DM_Connection->UserInfoIDSKLAD_USER->AsInt64;
NameSkladcxButtonEdit->Text=DM_Connection->UserInfoNAMESKLAD->AsString;


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
int TFormaImportSprProducerRabota::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportSprProducerRabota::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprImportSet)FormaSpiskaSprImportSet->kanRelease();
if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(FormaSpiskaSprFirm)FormaSpiskaSprFirm->kanRelease();
if(FormaSpiskaSprSklad)FormaSpiskaSprSklad->kanRelease();
if(FormaSpiskaSprKlient)FormaSpiskaSprKlient->kanRelease();

if(SpisokProducer) SpisokProducer->kanRelease();

//получим ICallBack для передачи события в вызывающую форму
if(InterfaceOwnerObject)
	{
	IkanCallBack * i_callback=0;
	InterfaceOwnerObject->kanQueryInterface(IID_IkanCallBack,(void**)&i_callback);
	if (i_callback)
		{
		i_callback->kanExternalEvent(InterfaceImpl,ClsIdImpl,TypeEvent,NumberProcVibor);
		}
	i_callback->kanRelease();
	}

DMSprImportSet->kanRelease();
Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void TFormaImportSprProducerRabota::UpdateForm(void)
{


}
//---------------------------------------------------------------------------
int TFormaImportSprProducerRabota::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_ImportSet)
	{
	if (type_event==1)
		{
        EndViborImportSet();
		}
	FormaSpiskaSprImportSet=0;
	}

if (number_procedure_end==ER_InfBase)
	{
	if (type_event==1)
		{
		EndViborInfBase();
		}
	FormaSpiskaSprInfBase=0;
	}

if (number_procedure_end==ER_Firm)
	{
	if (type_event==1)
		{
        EndViborFirm();
		}
	FormaSpiskaSprFirm=0;
	}

if (number_procedure_end==ER_Sklad)
	{
	if (type_event==1)
		{
		EndViborSklad();
		}
	FormaSpiskaSprSklad=0;
	}

if (number_procedure_end==ER_Post)
	{
	if (type_event==1)
		{
		 EndViborKlient();
		}
	FormaSpiskaSprKlient=0;
	}









if (number_procedure_end==ER_ViborProducer)
		{
		if (type_event==1)
				{
				IdProducer=glStrToInt64(SpisokProducer->DM->TableID_SPRODUCER->AsString);
				NameProducercxButtonEdit->Text=SpisokProducer->DM->TableNAME_SPRODUCER->AsString;
				}
		SpisokProducer=0;
		}

FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------
void __fastcall TFormaImportSprProducerRabota::FileNamecxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
  if (OpenDialog1->Execute())
  {
    //NewSheet(OpenDialog->FileName);
	try {
		FileNamecxButtonEdit->Text=OpenDialog1->FileName;
		cxSpreadSheet1->LoadFromFile(OpenDialog1->FileName);
		cxSpreadSheet1->R1C1ReferenceStyle=true;
		}
	catch (Exception &err)
	  {
        Application->ShowException(&err);
		//ActiveMDIChild->Close();
	  }
  }	
}
//---------------------------------------------------------------------------
void TFormaImportSprProducerRabota::OpenFormSpiskaSprImportSet(void)
{

if (FormaSpiskaSprImportSet==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprImportSet.1",IID_IFormaSpiskaSprImportSet,
												(void**)&FormaSpiskaSprImportSet);
		FormaSpiskaSprImportSet->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprImportSet->Vibor=true;
		FormaSpiskaSprImportSet->DM->TypeObr=1;
		FormaSpiskaSprImportSet->NumberProcVibor=ER_ImportSet;
		FormaSpiskaSprImportSet->UpdateForm();
		}

}
//---------------------------------------------------------------------------
void __fastcall TFormaImportSprProducerRabota::EndViborImportSet(void)
{

	IdImportSet=FormaSpiskaSprImportSet->DM->TableID_SIMPORTSET->AsInt64;
	NameImportSetcxButtonEdit->Text=FormaSpiskaSprImportSet->DM->TableNAME_SIMPORTSET->AsString;
    UpdateSetup();


}
//---------------------------------------------------------------------------
void __fastcall TFormaImportSprProducerRabota::NameImportSetcxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprImportSet();
}
//---------------------------------------------------------------------------
void TFormaImportSprProducerRabota::UpdateSetup(void)
{
DMSprImportSet->OpenElement(IdImportSet);
StartStringcxSpinEdit->Text=DMSprImportSet->GetParameter("START_STRING");
ArtcxSpinEdit->Text=DMSprImportSet->GetParameter("ART");
NamecxSpinEdit->Text=DMSprImportSet->GetParameter("NAME");
NameEngcxSpinEdit->Text=DMSprImportSet->GetParameter("NAME_ENG");
KolErrorForStopcxSpinEdit->Text=DMSprImportSet->GetParameter("KOL_ERROR_FOR_STOP");
LevelStrcxSpinEdit->Text=DMSprImportSet->GetParameter("LEVEL_STR");


if (Trim(DMSprImportSet->GetParameter("TYPE_SEARCH"))!="")
	{
	TypeSearchcxComboBox->ItemIndex=StrToInt(DMSprImportSet->GetParameter("TYPE_SEARCH"));
	}
}
//----------------------------------------------------------------------------
void TFormaImportSprProducerRabota::SaveSetup(void)
{
if (IdImportSet==0)
	{
	ShowMessage("Выберите элемент справочника Настройки импорта");
	return;
	}
DMSprImportSet->Element->Edit();
UnicodeString str_param="";

str_param=str_param+"START_STRING="+StartStringcxSpinEdit->Text+";";
str_param=str_param+"ART="+ArtcxSpinEdit->Text+";";
str_param=str_param+"NAME="+NamecxSpinEdit->Text+";";
str_param=str_param+"KOL_ERROR_FOR_STOP="+KolErrorForStopcxSpinEdit->Text+";";
str_param=str_param+"NAME_ENG="+NameEngcxSpinEdit->Text+";";
str_param=str_param+"LEVEL_STR="+LevelStrcxSpinEdit->Text+";";
str_param=str_param+"TYPE_SEARCH="+TypeSearchcxComboBox->ItemIndex+";";



DMSprImportSet->ElementSTRPAR_SIMPORTSET->AsString=str_param;
DMSprImportSet->Element->Post();
if (DMSprImportSet->SaveElement()!=true)
	{
    ShowMessage("Ошибка: "+DMSprImportSet->TextError);  
	}
}
//----------------------------------------------------------------------------

void __fastcall TFormaImportSprProducerRabota::cxButtonSaveParamsClick(
      TObject *Sender)
{
SaveSetup();
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportSprProducerRabota::cxButtonImportClick(TObject *Sender)
{
if (StartStringcxSpinEdit->Text=="" ||
			StartStringcxSpinEdit->Text=="0")
	{
	ShowMessage("Необходимо задать настройки импорта!");
	return;
	}

int number_last_string=StrToInt(NumLastStringcxSpinEdit->Text);

if (number_last_string == 0)
	{
	ShowMessage("Необходимо задать номер последней строки!");
	return;
	}


//необходимо обязательно задать поставщика
//так как по нему определяются коды и наименования
int number_string_excel=StrToInt(StartStringcxSpinEdit->Text);
int number_string_table=0;
//номенклатура
int num_name=StrToInt(NamecxSpinEdit->Text);
UnicodeString name=""; //номенклатура
int num_name_eng=StrToInt(NameEngcxSpinEdit->Text);
UnicodeString name_eng="";
//артикул
int num_art=StrToInt(ArtcxSpinEdit->Text);
UnicodeString art="";

int num_level_str=StrToInt(LevelStrcxSpinEdit->Text);
AnsiString level_str="";

//количество ошибок
int kol_error_for_stop=StrToInt(KolErrorForStopcxSpinEdit->Text);
int kol_error = 0;

TcxSSCellObject *cell;
TcxCustomDataController *dc = cxGrid1BandedTableView1->DataController;

while (dc->RowCount>0)
	{
	dc->DeleteRecord(0);
	}

dc->BeginUpdate();
bool error=false;

loop :
try
	{
	//наименование номенклатуры
	if (num_name!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_name-1,number_string_excel-1);
		name=Trim(cell->Text);
		delete cell;
		if (name.Length() > 200)
			{
			name=name.SetLength(200);
			}
		}
	else {name="";}

	//наименование номенклатуры  eng
	if (num_name_eng!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_name_eng-1,number_string_excel-1);
		name_eng=Trim(cell->Text);
		delete cell;
		if (name_eng.Length() > 200)
			{
			name_eng=name_eng.SetLength(200);
			}
		}
	else {name_eng="";}

	//артикул номенклатуры
	if (num_art!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_art-1,number_string_excel-1);
		art=cell->Text;
		delete cell;
		}
	else {art="";}

		//уровень
	if (num_level_str!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_level_str-1,number_string_excel-1);
		level_str=cell->Text;
		delete cell;
		}
	else {level_str="";}

	if (cxCheckBoxVidelyatCod->Checked==true)
		{
		UnicodeString in_name=name;
		VidelitCodIsNameRus(&name, &art, in_name);
		}

	dc->AppendRecord();
	dc->Values[number_string_table][cxGrid1BandedTableView1ID_REM_SPRRABOTA->Index] = "";
	dc->Values[number_string_table][cxGrid1BandedTableView1ART->Index] = art;
	dc->Values[number_string_table][cxGrid1BandedTableView1NAME->Index] = name;
	dc->Values[number_string_table][cxGrid1BandedTableView1NAME_ENG->Index] = name_eng;
	dc->Values[number_string_table][cxGrid1BandedTableView1LEVEL_STR->Index] = level_str;
	number_string_table++;
	number_string_excel++;
	kol_error=0;
	}
catch(Exception &exception)
	{
	if (kol_error >= kol_error_for_stop)
		{
		error=true;
		LabelError->Caption="Ошибка в строке:"+IntToStr(number_string_excel)+" "+exception.Message;
		}
	else
		{
		kol_error++;
		number_string_excel++;
		}
	}

if (number_string_excel == number_last_string+1)
	{
    error=true;
	}


if (error==false)
	{//повторяем процедуру
    goto loop;
	}

dc->EndUpdate();

}
//---------------------------------------------------------------------------
//выбор информационной базы
void TFormaImportSprProducerRabota::ViborInfBase(void)
{
if (FormaSpiskaSprInfBase==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInfBase.1",IID_IFormaSpiskaSprInfBase,
													(void**)&FormaSpiskaSprInfBase);
		FormaSpiskaSprInfBase->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprInfBase->Vibor=true;
		FormaSpiskaSprInfBase->DM->OpenTable();
		FormaSpiskaSprInfBase->NumberProcVibor=ER_InfBase;
		} 
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportSprProducerRabota::EndViborInfBase(void)
{

	IdInfBase=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsInt64;
	NameInfBasecxButtonEdit->Text=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;



}
//---------------------------------------------------------------------------
//выбор фирмы
void TFormaImportSprProducerRabota::ViborFirm(void)
{
if (FormaSpiskaSprFirm==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&FormaSpiskaSprFirm);
		FormaSpiskaSprFirm->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprFirm->Vibor=true;
		FormaSpiskaSprFirm->DM->OpenTable();
		FormaSpiskaSprFirm->NumberProcVibor=ER_Firm;
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaImportSprProducerRabota::EndViborFirm(void)
{

	IdFirm=FormaSpiskaSprFirm->DM->ElementIDFIRM->AsInt64;
	NameFirmcxButtonEdit->Text=FormaSpiskaSprFirm->DM->ElementNAMEFIRM->AsString;



}
//----------------------------------------------------------------------------
//выбор склада
void TFormaImportSprProducerRabota::ViborSklad(void)
{
if (FormaSpiskaSprSklad==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&FormaSpiskaSprSklad);
		FormaSpiskaSprSklad->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprSklad->Vibor=true;
		FormaSpiskaSprSklad->DM->OpenTable();
		FormaSpiskaSprSklad->NumberProcVibor=ER_Sklad;
		}
}
//-----------------------------------------------------------------------------
void __fastcall TFormaImportSprProducerRabota::EndViborSklad(void)
{
	IdSklad=glStrToInt64(FormaSpiskaSprSklad->DM->ElementIDSKLAD->AsString);
	NameSkladcxButtonEdit->Text=FormaSpiskaSprSklad->DM->ElementNAMESKLAD->AsString;


}
//-----------------------------------------------------------------------------
//выбор поставщика
void TFormaImportSprProducerRabota::ViborKlient(void)
{
if (FormaSpiskaSprKlient==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
		FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprKlient->Vibor=true;
		FormaSpiskaSprKlient->UpdateForm();
		FormaSpiskaSprKlient->NumberProcVibor=ER_Post;
		}
}
//-----------------------------------------------------------------------------
void __fastcall TFormaImportSprProducerRabota::EndViborKlient(void)
{

	IdKlient=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsInt64;
	NameKlientcxButtonEdit->Text=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;



}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void __fastcall TFormaImportSprProducerRabota::NameInfBasecxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborInfBase();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportSprProducerRabota::NameFirmcxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborFirm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportSprProducerRabota::NameSkladcxButtonEditPropertiesButtonClick(
	  TObject *Sender, int AButtonIndex)
{
ViborSklad();
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportSprProducerRabota::NameKlientcxButtonEditPropertiesButtonClick(
	  TObject *Sender, int AButtonIndex)
{
ViborKlient();
}
//---------------------------------------------------------------------------



void __fastcall TFormaImportSprProducerRabota::cxButtonUpdateSprClick(TObject *Sender)
{

if (IdProducer==0)
	{
	ShowMessage("Необходимо выбрать Производителя!");
	return;
	}

int kol_record=0;
int kol_record_all=0;

AnsiString text_error="";

IREM_DMSprProducerRabota *dm_producer_rabota;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprProducerRabota ,IID_IREM_DMSprProducerRabota,
													(void**)&dm_producer_rabota);
		dm_producer_rabota->Init(InterfaceMainObject,InterfaceImpl);



//		TDateTime pos_update=Now();






//__int64 id_grp=0;
__int64 id_producer_rabota=0;


	ProgressBar1->Max=KolRecordUpdate;
	ProgressBar1->Step=1;

try
	{

	TcxCustomDataController *dc_upd = cxGridBandedTableView2->DataController;
	dc_upd->GotoFirst();
	for (int i=0; i<dc_upd->RowCount; i++)
		{

		kol_record++;
		kol_record_all++;
//		if (kol_record==500)
//			{
//			ShowMessage("Обработано 500 записей. Всего: "+IntToStr(kol_record_all));
//			kol_record=0;
//			}


		int type_update=0;
		type_update=dc_upd->Values[i][TableUpdateTypeUpdate->Index];

		if (type_update == 1) //вставка
			{
			dm_producer_rabota->NewElement(IdProducer,0);
			}

		if (type_update == 2)   //обновление
			{
			id_producer_rabota=dc_upd->Values[i][TableUpdateID_REM_SPRRABOTA->Index];
			dm_producer_rabota->OpenElement(id_producer_rabota);
			}


		dm_producer_rabota->Element->Edit();

			if (StrToInt(NamecxSpinEdit->Text) > 0)
				{
				UnicodeString name=Trim(dc_upd->Values[i][TableUpdateNAME->Index]);
				if (name.Length() > 200) { name = name.SetLength(200);}
				dm_producer_rabota->ElementNAME_REM_SPRRABOTA->AsString=name;
				}

			if (StrToInt(NameEngcxSpinEdit->Text) > 0)
				{
				UnicodeString name=Trim(dc_upd->Values[i][TableUpdateNAME_ENG->Index]);
				if (name.Length() > 200) { name = name.SetLength(200);}
				dm_producer_rabota->ElementNAME_ENG_REM_SPRRABOTA->AsString=name;
				}

			if (StrToInt(ArtcxSpinEdit->Text) > 0    || cxCheckBoxVidelyatCod->Checked==true)
				{
				UnicodeString artikul = Trim(dc_upd->Values[i][TableUpdateART->Index]);
				if (artikul.Length() > 40) {artikul = artikul.SetLength(40);}
				dm_producer_rabota->ElementCODE_REM_SPRRABOTA->AsString=artikul;
				}

			if (StrToInt(LevelStrcxSpinEdit->Text) > 0)
				{
				UnicodeString level_str = Trim(dc_upd->Values[i][TableUpdateLEVEL_STR->Index]);
				if (level_str.Length() > 40) {level_str = level_str.SetLength(40);}
				dm_producer_rabota->ElementLEVEL_STR_REM_SPRRABOTA->AsString=level_str;
				}

		dm_producer_rabota->Element->Post();




				if (dm_producer_rabota->SaveElement()==false)
					{
					text_error="Ошибка при записи новой номенклатуры: "+dm_producer_rabota->TextError+"\n";
					text_error=text_error+" Номенклатура: "+dc_upd->Values[i][TableUpdateNAME->Index];
					throw Exception(text_error,0);
					}


		ProgressBar1->StepIt();
		}


	}
catch(Exception &exception)
		{
		ShowMessage(exception.Message);
		}


dm_producer_rabota->kanRelease();

}
//---------------------------------------------------------------------------



void __fastcall TFormaImportSprProducerRabota::cxButtonDelStringClick(TObject *Sender)
{
//удалим текущую строку

TcxCustomDataController *dc = cxGrid1BandedTableView1->DataController;
dc->DeleteFocused();
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportSprProducerRabota::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

////---------------------------------------------------------------------------
void __fastcall TFormaImportSprProducerRabota::NameProducercxButtonEditPropertiesButtonClick(TObject *Sender,
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
void TFormaImportSprProducerRabota::OpenFormSpiskaSprProducer(void)
{
if (SpisokProducer==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprProducer,IID_IFormaSpiskaSprProducer,
													(void**)&SpisokProducer);
		SpisokProducer->Init(InterfaceMainObject,InterfaceImpl);
		SpisokProducer->Vibor=true;
		SpisokProducer->NumberProcVibor=ER_ViborProducer;
		//SpisokProducer->IdProducer=IdProducer;
		//SpisokProducer->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaImportSprProducerRabota::ToolButtonSaveExcelClick(TObject *Sender)

{
	if (SaveDialog1->Execute())
		{
		ExportGridToExcel(SaveDialog1->FileName, cxGrid1, true, true,true, "xls");
		}
}
//---------------------------------------------------------------------------


void __fastcall TFormaImportSprProducerRabota::cxButtonProveritClick(TObject *Sender)

{
if (IdProducer==0)
	{
	ShowMessage("Необходимо выбрать Производителя!");
	return;
	}



TcxCustomDataController *dc_upd = cxGridBandedTableView2->DataController;

while (dc_upd->RowCount>0)
	{
	dc_upd->DeleteRecord(0);
	}

	ProgressBar1->Max=StrToInt(NumLastStringcxSpinEdit->Text);
	ProgressBar1->Step=1;

AnsiString text_error="";
int number_string_table_upd=0;
int kol_record=0;
int kol_record_all=0;

IREM_DMSprProducerRabota *dm_producer_rabota;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprProducerRabota ,IID_IREM_DMSprProducerRabota,
													(void**)&dm_producer_rabota);
		dm_producer_rabota->Init(InterfaceMainObject,InterfaceImpl);



//__int64 id_grp=0;
__int64 id_producer_rabota=0;


//__int64 ID_REM_SPRNEISPR = 0;
UnicodeString ART="";
UnicodeString NAME="";
UnicodeString NAME_ENG="";
UnicodeString LEVEL_STR="";

try
	{

	TcxCustomDataController *dc = cxGrid1BandedTableView1->DataController;
	dc->GotoFirst();
	for (int i=0; i<dc->RowCount; i++)
		{
		kol_record++;
		kol_record_all++;
//		if (kol_record==500)
//			{
//			ShowMessage("Обработано 500 записей. Всего: "+IntToStr(kol_record_all));
//			kol_record=0;
//			}
		if (i>2)
			{
			LabelInfo->Caption="Обрабатываем строку: "+IntToStr(kol_record_all)+" "+dc->Values[i][cxGrid1BandedTableView1NAME->Index]
											+" артикул "+dc->Values[i][cxGrid1BandedTableView1ART->Index]
											+" предыдущая строка "+dc->Values[i-1][cxGrid1BandedTableView1NAME->Index]
											+" артикул "+dc->Values[i-1][cxGrid1BandedTableView1ART->Index];
			}
		else
			{
			LabelInfo->Caption="Обрабатываем строку: "+IntToStr(kol_record_all)+" "+dc->Values[i][cxGrid1BandedTableView1NAME->Index]
											+" артикул "+dc->Values[i][cxGrid1BandedTableView1ART->Index];
			}

		UnicodeString artikul = Trim(dc->Values[i][cxGrid1BandedTableView1ART->Index]);
		UnicodeString name = Trim(dc->Values[i][cxGrid1BandedTableView1NAME->Index]);
		UnicodeString name_eng = Trim(dc->Values[i][cxGrid1BandedTableView1NAME_ENG->Index]);
		UnicodeString level_str = Trim(dc->Values[i][cxGrid1BandedTableView1LEVEL_STR->Index]);


		if (artikul.Length() > 40)
			{
			artikul = artikul.SetLength(40);
			}


		if(TypeSearchcxComboBox->ItemIndex == 2 )
			{  //поиск по артикулу
			id_producer_rabota= dm_producer_rabota->FindPoCodu(IdProducer,artikul);
			}

		if(TypeSearchcxComboBox->ItemIndex == 1 )            //1 поиск по наименованию
			{
			id_producer_rabota= dm_producer_rabota->FindPoName(IdProducer,name);
			}

		if(TypeSearchcxComboBox->ItemIndex == 3 )            //3 по англ наименованию
			{
			id_producer_rabota= dm_producer_rabota->FindPoNameEng(IdProducer,name_eng);
			}





		if(id_producer_rabota==0) //создаем новую номенклатуру
			{
			//*********************************************************************************
			dc_upd->AppendRecord();
			dc_upd->Values[number_string_table_upd][TableUpdateTypeUpdate->Index] = 1;
			dc_upd->Values[number_string_table_upd][TableUpdateID_REM_SPRRABOTA->Index] = "";
			dc_upd->Values[number_string_table_upd][TableUpdateART->Index] = dc->Values[i][cxGrid1BandedTableView1ART->Index];
			dc_upd->Values[number_string_table_upd][TableUpdateNAME->Index] = dc->Values[i][cxGrid1BandedTableView1NAME->Index];
			dc_upd->Values[number_string_table_upd][TableUpdateNAME_ENG->Index] = dc->Values[i][cxGrid1BandedTableView1NAME_ENG->Index];
			dc_upd->Values[number_string_table_upd][TableUpdateLEVEL_STR->Index] = dc->Values[i][cxGrid1BandedTableView1LEVEL_STR->Index];

			//**********************************************************************************
            number_string_table_upd++;
			}
		else
			{  //найдена
			bool fl_save=false;

			//ID_REM_SPRNEISPR = 0;
			ART=dc->Values[i][cxGrid1BandedTableView1ART->Index];      //найдена ведь
			NAME=dc->Values[i][cxGrid1BandedTableView1NAME->Index];
			NAME_ENG=dc->Values[i][cxGrid1BandedTableView1NAME_ENG->Index];
			LEVEL_STR=dc->Values[i][cxGrid1BandedTableView1LEVEL_STR->Index];



			dm_producer_rabota->OpenElement(id_producer_rabota);


			if (StrToInt(NamecxSpinEdit->Text) !=0)
				{
				if (dm_producer_rabota->ElementNAME_REM_SPRRABOTA->AsString
								!= NAME )
					{
					fl_save=true;
					}
				}

			if (StrToInt(NameEngcxSpinEdit->Text) !=0)
				{
				if (dm_producer_rabota->ElementNAME_ENG_REM_SPRRABOTA->AsString
								!= NAME_ENG )
					{
					fl_save=true;
					}
				}

			if (StrToInt(ArtcxSpinEdit->Text) !=0)
				{
				if (dm_producer_rabota->ElementCODE_REM_SPRRABOTA->AsString
								!= ART )
					{
					fl_save=true;
					}
				}

			if (StrToInt(LevelStrcxSpinEdit->Text) !=0)
				{
				if (dm_producer_rabota->ElementLEVEL_STR_REM_SPRRABOTA->AsString
								!= LEVEL_STR )
					{
					fl_save=true;
					}
				}


			if (fl_save == true)
				{   //добавляем запись в таблицу изменений

			//*********************************************************************************

			dc_upd->AppendRecord();
			dc_upd->Values[number_string_table_upd][TableUpdateTypeUpdate->Index] = 2;
			dc_upd->Values[number_string_table_upd][TableUpdateID_REM_SPRRABOTA->Index] = dm_producer_rabota->ElementID_REM_SPRRABOTA->AsString;
			dc_upd->Values[number_string_table_upd][TableUpdateART->Index] = ART;
			dc_upd->Values[number_string_table_upd][TableUpdateNAME->Index] = NAME;
			dc_upd->Values[number_string_table_upd][TableUpdateNAME_ENG->Index] = NAME_ENG;
			dc_upd->Values[number_string_table_upd][TableUpdateLEVEL_STR->Index] = LEVEL_STR;
				number_string_table_upd++;
				}


			}
		ProgressBar1->StepIt();
		}
	}
catch(Exception &exception)
		{
		ShowMessage(exception.Message);
		}


dm_producer_rabota->kanRelease();

KolRecordUpdate=number_string_table_upd;
}
//---------------------------------------------------------------------------
void TFormaImportSprProducerRabota::VidelitCodIsNameRus(UnicodeString * out_name, UnicodeString * out_code, UnicodeString in_name)
{

bool fl_code=true;
*out_code="";
*out_name="";

for (int i=1;i<=in_name.Length();i++)
	{

	if (fl_code==true)
		{
		*out_code=*out_code+in_name[i];
		}
	else
		{
		*out_name=*out_name+in_name[i];
		}

	if (in_name[i]==' ')
		{
        fl_code=false;
		}
	}

}
//-----------------------------------------------------------------------------
