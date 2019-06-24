//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaImportSprProducerNom.h"
#include "UDM.h"
#include "IDMSprImportNom.h"
#include "IDMSprProducerNom.h"
#include "IDMSprProducer.h"
#include "IDMDocPrihNakl.h"
#include "IFormaDocPrihNakl.h"
#include "IFormaDocRev.h"
#include "IDMSprGrpNom.h"
#include "IObjectBarCode.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IAsyncExternalEvent.h"
#include "IDMSprCountry.h"
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
__fastcall TFormaImportSprProducerNom::TFormaImportSprProducerNom(TComponent* Owner)
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
void __fastcall TFormaImportSprProducerNom::FormCreate(TObject *Sender)
{
NameImportSetcxButtonEdit->Text="";
FileNamecxButtonEdit->Text="";

IdKlient=0;
NameKlientcxButtonEdit->Text="";

IdGrpNom=0;
NameGrpNomcxButtonEdit->Text="";

StartStringcxSpinEdit->Text="0";
NameNomcxSpinEdit->Text="0";
CodeNomcxSpinEdit->Text="0";
KolcxSpinEdit->Text="0";
NameEdcxSpinEdit->Text="0";
BarCodecxSpinEdit->Text="0";
PricecxSpinEdit->Text="0";
SumcxSpinEdit->Text="0";
RoznPricecxSpinEdit->Text="0";
RoznSumcxSpinEdit->Text="0";
LabelError->Caption="";
NameProducercxButtonEdit->Text="";
KolErrorForStopcxSpinEdit->Text="0";


TypeNomcxSpinEdit->Text="0";
ModelcxSpinEdit->Text="0";
AnalogcxSpinEdit->Text="0";
FullNamecxSpinEdit->Text="0";
KrNamecxSpinEdit->Text="0";
DostupnocxSpinEdit->Text="0";

RepairCodecxSpinEdit->Text="0";
LocationcxSpinEdit->Text="0";
}
//-----------------------------------------------------------------------
bool TFormaImportSprProducerNom::Init(void)
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
int TFormaImportSprProducerNom::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportSprProducerNom::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprImportSet)FormaSpiskaSprImportSet->kanRelease();
if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(FormaSpiskaSprFirm)FormaSpiskaSprFirm->kanRelease();
if(FormaSpiskaSprSklad)FormaSpiskaSprSklad->kanRelease();
if(FormaSpiskaSprKlient)FormaSpiskaSprKlient->kanRelease();
if(FormaSpiskaSprNom)FormaSpiskaSprNom->kanRelease();
if(FormaSprNomFind)FormaSprNomFind->kanRelease();
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
void TFormaImportSprProducerNom::UpdateForm(void)
{


}
//---------------------------------------------------------------------------
int TFormaImportSprProducerNom::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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

if (number_procedure_end==ER_GrpNom)
	{
	if (type_event==1)
		{
		EndViborGrpNom();
		}
	FormaSpiskaSprGrpNom=0;
	}

if (number_procedure_end==ER_Nom)
	{
	if (type_event==1)
		{
		EndViborNom();
		}
	FormaSpiskaSprNom=0;
	}

if (number_procedure_end==ER_Ed)
	{
	if (type_event==1)
		{

		}
	}



if (number_procedure_end==ER_NomFind)
	{
	if (type_event==1)
		{
		EndViborNomFind();
		}
	FormaSprNomFind=0;
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
void __fastcall TFormaImportSprProducerNom::FileNamecxButtonEditPropertiesButtonClick(
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
void TFormaImportSprProducerNom::OpenFormSpiskaSprImportSet(void)
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
void __fastcall TFormaImportSprProducerNom::EndViborImportSet(void)
{

	IdImportSet=FormaSpiskaSprImportSet->DM->TableID_SIMPORTSET->AsInt64;
	NameImportSetcxButtonEdit->Text=FormaSpiskaSprImportSet->DM->TableNAME_SIMPORTSET->AsString;
    UpdateSetup();


}
//---------------------------------------------------------------------------
void __fastcall TFormaImportSprProducerNom::NameImportSetcxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprImportSet();
}
//---------------------------------------------------------------------------
void TFormaImportSprProducerNom::UpdateSetup(void)
{
DMSprImportSet->OpenElement(IdImportSet);
StartStringcxSpinEdit->Text=DMSprImportSet->GetParameter("START_STRING");
CodeNomcxSpinEdit->Text=DMSprImportSet->GetParameter("CODE_NOM");
ArtNomcxSpinEdit->Text=DMSprImportSet->GetParameter("ART_NOM");
NameNomcxSpinEdit->Text=DMSprImportSet->GetParameter("NAME_NOM");
KolcxSpinEdit->Text=DMSprImportSet->GetParameter("KOL");
NameEdcxSpinEdit->Text=DMSprImportSet->GetParameter("NAME_ED");
BarCodecxSpinEdit->Text=DMSprImportSet->GetParameter("BAR_CODE");
PricecxSpinEdit->Text=DMSprImportSet->GetParameter("PRICE");
SumcxSpinEdit->Text=DMSprImportSet->GetParameter("SUM");
RoznPricecxSpinEdit->Text=DMSprImportSet->GetParameter("ROZN_PRICE");
RoznSumcxSpinEdit->Text=DMSprImportSet->GetParameter("ROZN_SUM");
CountrycxSpinEdit->Text=DMSprImportSet->GetParameter("COUNTRY");
GTDcxSpinEdit->Text=DMSprImportSet->GetParameter("GTD");
KolErrorForStopcxSpinEdit->Text=DMSprImportSet->GetParameter("KOL_ERROR_FOR_STOP");


TypeNomcxSpinEdit->Text=DMSprImportSet->GetParameter("TYPE_NOM");
ModelcxSpinEdit->Text=DMSprImportSet->GetParameter("MODEL");
AnalogcxSpinEdit->Text=DMSprImportSet->GetParameter("ANALOG");
FullNamecxSpinEdit->Text=DMSprImportSet->GetParameter("FULL_NAME");
KrNamecxSpinEdit->Text=DMSprImportSet->GetParameter("KR_NAME");
DostupnocxSpinEdit->Text=DMSprImportSet->GetParameter("DOSTUPNO");

RepairCodecxSpinEdit->Text=DMSprImportSet->GetParameter("REP_CODE");
LocationcxSpinEdit->Text=DMSprImportSet->GetParameter("LOCATION");


if (DMSprImportSet->GetParameter("EXTERNAL_CODE")!="")
	{
	if (DMSprImportSet->GetParameter("EXTERNAL_CODE")=="1")
		{
		ExternalCodcxCheckBox->Checked=true;
		}
	else
		{
		ExternalCodcxCheckBox->Checked=false;
		}
	}

if (DMSprImportSet->GetParameter("EXTERNAL_BARCODE")!="")
	{
	if (DMSprImportSet->GetParameter("EXTERNAL_BARCODE")=="1")
		{
		ExternalBarCodecxCheckBox->Checked=true;
		}
	else
		{
		ExternalBarCodecxCheckBox->Checked=false;
		}
	}

if (DMSprImportSet->GetParameter("ZAMENA")!="")
	{
	if (DMSprImportSet->GetParameter("ZAMENA")=="1")
		{
		ZamenacxCheckBox->Checked=true;
		}
	else
		{
		ZamenacxCheckBox->Checked=false;
		}
	}

if (Trim(DMSprImportSet->GetParameter("TYPE_SEARCH"))!="")
	{
	TypeSearchcxComboBox->ItemIndex=StrToInt(DMSprImportSet->GetParameter("TYPE_SEARCH"));
	}
}
//----------------------------------------------------------------------------
void TFormaImportSprProducerNom::SaveSetup(void)
{
if (IdImportSet==0)
	{
	ShowMessage("Выберите элемент справочника Настройки импорта");
	return;
	}
DMSprImportSet->Element->Edit();
UnicodeString str_param="";

str_param=str_param+"START_STRING="+StartStringcxSpinEdit->Text+";";
str_param=str_param+"CODE_NOM="+CodeNomcxSpinEdit->Text+";";
str_param=str_param+"ART_NOM="+ArtNomcxSpinEdit->Text+";";
str_param=str_param+"NAME_NOM="+NameNomcxSpinEdit->Text+";";
str_param=str_param+"KOL="+KolcxSpinEdit->Text+";";
str_param=str_param+"NAME_ED="+NameEdcxSpinEdit->Text+";";
str_param=str_param+"BAR_CODE="+BarCodecxSpinEdit->Text+";";
str_param=str_param+"PRICE="+PricecxSpinEdit->Text+";";
str_param=str_param+"SUM="+SumcxSpinEdit->Text+";";
str_param=str_param+"ROZN_PRICE="+RoznPricecxSpinEdit->Text+";";
str_param=str_param+"ROZN_SUM="+RoznSumcxSpinEdit->Text+";";
str_param=str_param+"COUNTRY="+CountrycxSpinEdit->Text+";";
str_param=str_param+"GTD="+GTDcxSpinEdit->Text+";";
str_param=str_param+"KOL_ERROR_FOR_STOP="+KolErrorForStopcxSpinEdit->Text+";";

str_param=str_param+"TYPE_NOM="+TypeNomcxSpinEdit->Text+";";
str_param=str_param+"MODEL="+ModelcxSpinEdit->Text+";";
str_param=str_param+"ANALOG="+AnalogcxSpinEdit->Text+";";
str_param=str_param+"FULL_NAME="+FullNamecxSpinEdit->Text+";";
str_param=str_param+"KR_NAME="+KrNamecxSpinEdit->Text+";";
str_param=str_param+"REP_CODE="+RepairCodecxSpinEdit->Text+";";
str_param=str_param+"LOCATION="+LocationcxSpinEdit->Text+";";
str_param=str_param+"DOSTUPNO="+DostupnocxSpinEdit->Text+";";
str_param=str_param+"TYPE_SEARCH="+TypeSearchcxComboBox->ItemIndex+";";


if (ExternalCodcxCheckBox->Checked==true)
	{
	str_param=str_param+"EXTERNAL_CODE=1;";
	}
else
	{
	str_param=str_param+"EXTERNAL_CODE=0;";
	}

if (ExternalBarCodecxCheckBox->Checked==true)
	{
	str_param=str_param+"EXTERNAL_BARCODE=1;";
	}
else
	{
	str_param=str_param+"EXTERNAL_BARCODE=0;";
	}

if (ZamenacxCheckBox->Checked==true)
	{
	str_param=str_param+"ZAMENA=1;";
	}
else
	{
	str_param=str_param+"ZAMENA=0;";
	}

DMSprImportSet->ElementSTRPAR_SIMPORTSET->AsString=str_param;
DMSprImportSet->Element->Post();
if (DMSprImportSet->SaveElement()!=true)
	{
    ShowMessage("Ошибка: "+DMSprImportSet->TextError);  
	}
}
//----------------------------------------------------------------------------

void __fastcall TFormaImportSprProducerNom::cxButtonSaveParamsClick(
      TObject *Sender)
{
SaveSetup();
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportSprProducerNom::cxButtonImportClick(TObject *Sender)
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
int num_name_nom=StrToInt(NameNomcxSpinEdit->Text);
AnsiString name_nom="";
//код номенклатуры
int num_code=StrToInt(CodeNomcxSpinEdit->Text);
AnsiString code="";
int num_art_nom=StrToInt(ArtNomcxSpinEdit->Text);
AnsiString art_nom="";
//количество
int num_kol=StrToInt(KolcxSpinEdit->Text);
double kol=0;
//единица
int num_name_ed=StrToInt(NameEdcxSpinEdit->Text);
AnsiString name_ed="";
//штрих код
int num_bar_code=StrToInt(BarCodecxSpinEdit->Text);
AnsiString bar_code="";
//цена
int num_price=StrToInt(PricecxSpinEdit->Text);
double price=0;
//сумма
int num_sum=StrToInt(SumcxSpinEdit->Text);
double sum=0;
//розничная цена
int num_rozn_price=StrToInt(RoznPricecxSpinEdit->Text);
double rozn_price=0;
//розничная сумма
int num_rozn_sum=StrToInt(RoznSumcxSpinEdit->Text);
double rozn_sum=0;
//розничная сумма
int num_country=StrToInt(CountrycxSpinEdit->Text);
UnicodeString country=" ";
//ГТД
int num_gtd=StrToInt(GTDcxSpinEdit->Text);
UnicodeString gtd=" ";

//количество ошибок
int kol_error_for_stop=StrToInt(KolErrorForStopcxSpinEdit->Text);
int kol_error = 0;

//тип номенклатуры
int num_type_nom=StrToInt(TypeNomcxSpinEdit->Text);
UnicodeString type_nom=" ";

//модель
int num_model=StrToInt(ModelcxSpinEdit->Text);
UnicodeString model=" ";
UnicodeString model_old=" ";
//аналог
int num_analog=StrToInt(AnalogcxSpinEdit->Text);
UnicodeString analog=" ";

//полное наименование
int num_full_name=StrToInt(FullNamecxSpinEdit->Text);
UnicodeString full_name=" ";

//краткое наименование
int num_kr_name=StrToInt(KrNamecxSpinEdit->Text);
UnicodeString kr_name=" ";

//rep_code
int num_rep_code=StrToInt(RepairCodecxSpinEdit->Text);
UnicodeString rep_code=" ";


//location
int num_location=StrToInt(LocationcxSpinEdit->Text);
UnicodeString location=" ";

//доступно
int num_dostupno=StrToInt(DostupnocxSpinEdit->Text);
UnicodeString dostupno=" ";



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
	if (num_name_nom!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_name_nom-1,number_string_excel-1);
		name_nom=Trim(cell->Text);
		delete cell;
		if (name_nom.Length() > 200)
			{
			name_nom=name_nom.SetLength(200);
			}
		}
	else {name_nom="";}
	//код номенклатуры
	if (num_code!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_code-1,number_string_excel-1);
		code=cell->Text;
		delete cell;
		}
	else {code="";}
	//артикул номенклатуры
	if (num_art_nom!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_art_nom-1,number_string_excel-1);
		art_nom=cell->Text;
		delete cell;
		}
	else {art_nom="";}

	//количество
	if (num_kol!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_kol-1,number_string_excel-1);
		UnicodeString str_kol="";
		str_kol=Trim(cell->Text);
		if (str_kol=="")
			{
			kol=0;
			dostupno="N";
			}
		else
			{
			kol=StrToFloat(str_kol);
			if (kol > 0.001)
				{
				dostupno="Y";
				}
			else
				{
                dostupno="N";
				}
			}

		delete cell;
		}
	else
		{
		kol=0;
		dostupno="N";
		}





	//единица
	if (num_name_ed!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_name_ed-1,number_string_excel-1);
		name_ed=cell->Text;
		delete cell;
		}
	else {name_ed="шт.";}
	if (num_bar_code!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_bar_code-1,number_string_excel-1);
		bar_code=Trim(cell->Text);
		delete cell;
		}
	else {bar_code="";}


	//цена
	if (num_price!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_price-1,number_string_excel-1);
		UnicodeString str_price=cell->Text;
		delete cell;

		if (str_price=="")
			{
            price=0;
			}
		else
			{

		str_price=glDelSymbolOfDoubleValue(str_price);
		if (ZamenacxCheckBox->Checked==true)
			{
			price=glStringToFloatComma(str_price);
			}
		else
			{
			price=StrToFloat(str_price);
			}
			}
		}
	else
		{
		price=0;
//		if (num_sum!=0)
//			{
//			cell = cxSpreadSheet1->Sheet->GetCellObject(num_sum-1,number_string_excel-1);
//			if (kol > 0.001)
//				{
//				price=StrToFloat(cell->Text)/kol;
//				}
//			delete cell;
//			}
		}
	//сумма
	if (num_sum!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_sum-1,number_string_excel-1);
		sum=StrToFloat(cell->Text);
		delete cell;
		}
	else
		{
		sum=price*kol;
		}
	//розничная цена
	if (num_rozn_price!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_rozn_price-1,number_string_excel-1);
		rozn_price=StrToFloat(cell->Text);
		delete cell;
		}
	else {rozn_price=0;}
	//розничная сумма
	if (num_rozn_sum!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_rozn_sum-1,number_string_excel-1);
		rozn_sum=StrToFloat(cell->Text);
		delete cell;
		}
	else
		{
		rozn_sum=rozn_price*kol;
		}
	//страна
	if (num_country!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_country-1,number_string_excel-1);
		country=cell->Text;
		delete cell;
		}
	else {country="";}
	//ГТД
	if (num_gtd!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_gtd-1,number_string_excel-1);
		gtd=cell->Text;
		delete cell;
		}
	else {gtd="";}



	//тип номенклатуры
	if (num_type_nom!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_type_nom-1,number_string_excel-1);
		type_nom=cell->Text;
		delete cell;
		}
	else {type_nom="";}
	//модель
	if (num_model!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_model-1,number_string_excel-1);
		model=cell->Text;
		delete cell;
		if (model!="")
			{
			model_old=model;
			}
		else
			{
            model=model_old;
			}
		}
	else {model="";}

	//аналог
	if (num_analog!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_analog-1,number_string_excel-1);
		analog=cell->Text;
		delete cell;
		}
	else {analog="";}
	//полное наименование
	if (num_full_name!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_full_name-1,number_string_excel-1);
		full_name=cell->Text;
		delete cell;
		}
	else {full_name="";}
	//кр наименование

	if (num_kr_name!=0)
		{
		kr_name="";
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_kr_name-1,number_string_excel-1);
		kr_name=cell->Text;
		delete cell;
		}
	else {kr_name="";}


		//rep_code

	if (num_rep_code!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_rep_code-1,number_string_excel-1);
		rep_code=cell->Text;
		delete cell;
		}
	else {rep_code="";}

		//location

	if (num_location!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_location-1,number_string_excel-1);
		location=cell->Text;
		delete cell;
		}
	else {location="";}

	//доступно
	if (num_dostupno!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_dostupno-1,number_string_excel-1);
		dostupno=cell->Text;
		delete cell;
		if ( dostupno == "+" || dostupno == "++" || dostupno == "+++" || dostupno == "++++" || dostupno == "+++++")
			{
			dostupno="Y";
			}

		if ( dostupno == "-" || dostupno == "--" || dostupno == "---" || dostupno == "----" || dostupno == "-----")
			{
			dostupno="N";
			}

		}
	else {



			dostupno="";

			//количество
			if (num_kol!=0)
				{
				cell = cxSpreadSheet1->Sheet->GetCellObject(num_kol-1,number_string_excel-1);
				UnicodeString str_kol="";
				str_kol=cell->Text;
				if (str_kol=="")
					{
					kol=0;
					dostupno="N";
					}
				else
					{
					kol=StrToFloat(str_kol);
					if (kol > 0.001)
						{
						dostupno="Y";
						}
					else
						{
						dostupno="N";
						}
					}

				delete cell;
				}
			else
				{
				kol=0;
				dostupno="N";
				}



		}


	dc->AppendRecord();
	dc->Values[number_string_table][cxGrid1BandedTableView1IDNOM->Index] = "";
	dc->Values[number_string_table][cxGrid1BandedTableView1CODENOM->Index] = code;
	dc->Values[number_string_table][cxGrid1BandedTableView1ARTNOM->Index] = art_nom;
	dc->Values[number_string_table][cxGrid1BandedTableView1NAMENOMPOST->Index] = name_nom;
   //	dc->Values[number_string_table][cxGrid1BandedTableView1NAMENOM->Index] = "";
	dc->Values[number_string_table][cxGrid1BandedTableView1KOL->Index] = kol;
	dc->Values[number_string_table][cxGrid1BandedTableView1NAMEED->Index] = name_ed;
	dc->Values[number_string_table][cxGrid1BandedTableView1BARCODE->Index] = bar_code;
	dc->Values[number_string_table][cxGrid1BandedTableView1PRICE->Index] = price;
	dc->Values[number_string_table][cxGrid1BandedTableView1SUM->Index] = sum;
	dc->Values[number_string_table][cxGrid1BandedTableView1ROZNPRICE->Index] = rozn_price;
	dc->Values[number_string_table][cxGrid1BandedTableView1ROZNSUM->Index] = rozn_sum;
	dc->Values[number_string_table][cxGrid1BandedTableView1COUNTRY->Index] = country;
	dc->Values[number_string_table][cxGrid1BandedTableView1GTD->Index] = gtd;


	dc->Values[number_string_table][cxGrid1BandedTableView1TNOM->Index] = type_nom;
	dc->Values[number_string_table][cxGrid1BandedTableView1MODEL->Index] = model;
	dc->Values[number_string_table][cxGrid1BandedTableView1ANALOG->Index] = analog;
	dc->Values[number_string_table][cxGrid1BandedTableView1FULLNAME->Index] = full_name;
	dc->Values[number_string_table][cxGrid1BandedTableView1KRNAME->Index] = kr_name;
	dc->Values[number_string_table][cxGrid1BandedTableView1REP_CODE->Index] = rep_code;
	dc->Values[number_string_table][cxGrid1BandedTableView1LOCATION->Index] = location;
	dc->Values[number_string_table][cxGrid1BandedTableView1DOSTUPNO->Index] = dostupno;

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
void TFormaImportSprProducerNom::ViborInfBase(void)
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
void __fastcall TFormaImportSprProducerNom::EndViborInfBase(void)
{

	IdInfBase=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsInt64;
	NameInfBasecxButtonEdit->Text=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;



}
//---------------------------------------------------------------------------
//выбор фирмы
void TFormaImportSprProducerNom::ViborFirm(void)
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
void __fastcall TFormaImportSprProducerNom::EndViborFirm(void)
{

	IdFirm=FormaSpiskaSprFirm->DM->ElementIDFIRM->AsInt64;
	NameFirmcxButtonEdit->Text=FormaSpiskaSprFirm->DM->ElementNAMEFIRM->AsString;



}
//----------------------------------------------------------------------------
//выбор склада
void TFormaImportSprProducerNom::ViborSklad(void)
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
void __fastcall TFormaImportSprProducerNom::EndViborSklad(void)
{
	IdSklad=glStrToInt64(FormaSpiskaSprSklad->DM->ElementIDSKLAD->AsString);
	NameSkladcxButtonEdit->Text=FormaSpiskaSprSklad->DM->ElementNAMESKLAD->AsString;


}
//-----------------------------------------------------------------------------
//выбор поставщика
void TFormaImportSprProducerNom::ViborKlient(void)
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
void __fastcall TFormaImportSprProducerNom::EndViborKlient(void)
{

	IdKlient=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsInt64;
	NameKlientcxButtonEdit->Text=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;



}
//-----------------------------------------------------------------------------
//выбор группы номенклатуры

void TFormaImportSprProducerNom::ViborGrpNom(void)
{
if (FormaSpiskaSprGrpNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprGrpNom.1",IID_IFormaSpiskaSprGrpNom,
													(void**)&FormaSpiskaSprGrpNom);
		FormaSpiskaSprGrpNom->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprGrpNom->Vibor=true;
		FormaSpiskaSprGrpNom->UpdateForm();
		FormaSpiskaSprGrpNom->NumberProcVibor=ER_GrpNom;
		}

}
//---------------------------------------------------------------------------
void __fastcall TFormaImportSprProducerNom::EndViborGrpNom(void)
{

	IdGrpNom=FormaSpiskaSprGrpNom->DMGrp->ElementIDGN->AsInt64;
	NameGrpNomcxButtonEdit->Text=FormaSpiskaSprGrpNom->DMGrp->ElementNAMEGN->AsString;

}
//-----------------------------------------------------------------------------
void __fastcall TFormaImportSprProducerNom::NameInfBasecxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborInfBase();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportSprProducerNom::NameFirmcxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborFirm();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportSprProducerNom::NameSkladcxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborSklad();
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportSprProducerNom::NameKlientcxButtonEditPropertiesButtonClick(
	  TObject *Sender, int AButtonIndex)
{
ViborKlient();
}
//---------------------------------------------------------------------------
////выбор номенклатуры
void TFormaImportSprProducerNom::ViborNom(void)
{
TcxCustomDataController *dc = cxGrid1BandedTableView1->DataController;

if (FormaSpiskaSprNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&FormaSpiskaSprNom);
		FormaSpiskaSprNom->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprNom->Vibor=true;
//		FormaSpiskaSprNom->DM->IdTypePrice=DM->DocIDRTPRICE_DVIPPROD->AsInt64;
//		FormaSpiskaSprNom->SpisokTypePrice->ItemIndex=FormaSpiskaSprNom->DM->GetIndexTypePrice()-1;
		FormaSpiskaSprNom->IdNom=glStrToInt64(dc->Values[dc->FocusedRowIndex][0]);

		FormaSpiskaSprNom->UpdateForm();
		FormaSpiskaSprNom->NumberProcVibor=ER_Nom;
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaImportSprProducerNom::EndViborNom(void)
{
TcxCustomDataController *dc = cxGrid1BandedTableView1->DataController;
int row=cxGrid1BandedTableView1->Controller->FocusedRowIndex;

	dc->Values[row][cxGrid1BandedTableView1IDNOM->Index] =
							FormaSpiskaSprNom->DM->ElementIDNOM->AsString;;
   //	dc->Values[row][cxGrid1BandedTableView1NAMENOM->Index] =
	//						FormaSpiskaSprNom->DM->ElementNAMENOM->AsString;


}
//----------------------------------------------------------------------------
//выбор единицы
void TFormaImportSprProducerNom::ViborEd(void)
{
//if(Prosmotr==true) return;
//if (FormaSpiskaSprEd==NULL)
//		{
//		FormaSpiskaSprEd=new TFormaSpiskaSprEd(Application);
//		if (!FormaSpiskaSprEd) return;
//		FormaSpiskaSprEd->Vibor=true;
//		FormaSpiskaSprEd->IdNom=DM->DocTIDNOM_DVIPPRODT->AsInt64;
//		FormaSpiskaSprEd->DM->OpenTable(DM->DocTIDNOM_DVIPPRODT->AsInt64);
//		FormaSpiskaSprEd->LabelNom->Caption="Единицы номенклатуры: "+DM->DocTNAMENOM->AsString;
//		FormaSpiskaSprEd->HintLabel->Caption="Выберите единицу номенклатуры для документа Выпуск продукции №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
//		FormaSpiskaSprEd->FOnCloseForm=EndViborEd;
//		FormaSpiskaSprEd->Show();
//		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaImportSprProducerNom::EndViborEd(void)
{
//
//if (FormaSpiskaSprEd->OutReady==true)
//	{
//	DM->DocT->Edit();
//	DM->DocTIDED_DVIPPRODT->AsInt64=FormaSpiskaSprEd->DM->ElementIDED->AsInt64;
//	DM->DocTNAMEED->AsString=FormaSpiskaSprEd->DM->ElementNAMEED->AsString;
//	DM->DocTKF_DVIPPRODT->AsFloat=FormaSpiskaSprEd->DM->ElementKFED->AsFloat;
//
//				if (DM->SkladRozn==true)
//					{
//					TDMSprPrice * DMSprPrice=new TDMSprPrice(Application);
//						DMSprPrice->FindElement( DM->DocIDRTPRICE_DVIPPROD->AsInt64,
//											 DM->DocTIDNOM_DVIPPRODT->AsInt64);
//						DM->DocTRPRICE_DVIPPRODT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
//														DM->DocTKF_DVIPPRODT->AsFloat;
//					delete DMSprPrice;
//					}
//				else
//					{
//					DM->DocTRPRICE_DVIPPRODT->AsFloat=0;
//					}
//
//	DM->DocT->Post();
//	}
//	FormaSpiskaSprEd=0;
//	cxGrid1->SetFocus();
//	cxGrid1DBTableView1RPRICE_DVIPPRODT->Selected=true;
}

//-------------------------------------------------------------------------
void __fastcall TFormaImportSprProducerNom::cxGrid1BandedTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{

switch (AButtonIndex)
	{
	case 0:
		{
		ViborNom();
		}break;
	case 1:
		{
		ViborNomFind();
		}break;
	case 2:
		{
		TcxCustomDataController *dc = cxGrid1BandedTableView1->DataController;
		int row=cxGrid1BandedTableView1->Controller->FocusedRowIndex;

		dc->Values[row][cxGrid1BandedTableView1IDNOM->Index] ="";
		//dc->Values[row][cxGrid1BandedTableView1NAMENOM->Index] ="";

		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportSprProducerNom::cxButtonSynhroClick(TObject *Sender)
{
if (IdProducer==0)
	{
	ShowMessage("Необходимо выбрать Производителя!");
	return;
	}



AnsiString text_error="";

IDMSprProducerNom *dm_producer_nom;
		InterfaceGlobalCom->kanCreateObject(ProgId_DMSprProducerNom ,IID_IDMSprProducerNom,
													(void**)&dm_producer_nom);
		dm_producer_nom->Init(InterfaceMainObject,InterfaceImpl);



__int64 id_grp=0;
__int64 id_producer_nom=0;



try
	{

	TcxCustomDataController *dc = cxGrid1BandedTableView1->DataController;
	dc->GotoFirst();
	for (int i=0; i<dc->RowCount; i++)
		{

		if(TypeSearchcxComboBox->ItemIndex == 3 )
			{  //поиск по артикулу
			UnicodeString artikul=Trim(dc->Values[i][2]);
			id_producer_nom=dm_producer_nom->FindPoArtikulu(IdProducer,"",artikul);
			}


		if(id_producer_nom==0) //создаем новую номенклатуру
			{

			}
		else
			{
			dm_producer_nom->OpenElement(id_producer_nom);
			dc->Values[i][cxGrid1BandedTableView1PRICE->Index]=dm_producer_nom->ElementPRICE_ZAKUP_SPRNOM->AsFloat;
			dc->Values[i][cxGrid1BandedTableView1SUM->Index]=dm_producer_nom->ElementPRICE_ZAKUP_SPRNOM->AsFloat
												* dc->Values[i][cxGrid1BandedTableView1KOL->Index];
			}

		}
	}
catch(Exception &exception)
		{
		ShowMessage(exception.Message);
		}


dm_producer_nom->kanRelease();


}
//---------------------------------------------------------------------------

void __fastcall TFormaImportSprProducerNom::cxButtonUpdateSprClick(TObject *Sender)
{

if (IdProducer==0)
	{
	ShowMessage("Необходимо выбрать Производителя!");
	return;
	}

int kol_record=0;
int kol_record_all=0;

AnsiString text_error="";

IDMSprProducerNom *dm_producer_nom;
		InterfaceGlobalCom->kanCreateObject(ProgId_DMSprProducerNom ,IID_IDMSprProducerNom,
													(void**)&dm_producer_nom);
		dm_producer_nom->Init(InterfaceMainObject,InterfaceImpl);



		TDateTime pos_update=Now();






__int64 id_grp=0;
__int64 id_producer_nom=0;


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
			dm_producer_nom->NewElement(IdProducer,0);
			}

		if (type_update == 2)   //обновление
			{
			id_producer_nom=dc_upd->Values[i][TableUpdateID_SPRNOM->Index];
			dm_producer_nom->OpenElement(id_producer_nom);
			}


		dm_producer_nom->Element->Edit();
			dm_producer_nom->ElementTYPE_SPRNOM->AsInteger=0;
            dm_producer_nom->ElementISM_SPRNOM->AsDateTime=pos_update;
			//dm_producer_nom->ElementCODE_SPRNOM->AsString=dc_upd->Values[i][TableUpdateCODE_SPRNOM->Index];

			if (StrToInt(NameNomcxSpinEdit->Text) > 0)
				{
				dm_producer_nom->ElementNAME_SPRNOM->AsString=dc_upd->Values[i][TableUpdateNAME_SPRNOM->Index];
				}
			dm_producer_nom->ElementFNAME_SPRNOM->AsString=dc_upd->Values[i][TableUpdateNAME_SPRNOM->Index];

			UnicodeString kr_name=dc_upd->Values[i][TableUpdateNAME_SPRNOM->Index];
			if (kr_name.Length() > 40)
				{
				dm_producer_nom->ElementKRNAME_SPRNOM->AsString=Trim(kr_name.SetLength(40));
				}
			else
				{
				dm_producer_nom->ElementKRNAME_SPRNOM->AsString=Trim(kr_name);
				}

			if (StrToInt(RepairCodecxSpinEdit->Text) > 0)
				{
				UnicodeString rep_code=dc_upd->Values[i][TableUpdateREPAIRCODE_SPRNOM->Index];
				if (rep_code.Length() > 10)
					{
					dm_producer_nom->ElementREPAIRCODE_SPRNOM->AsString=Trim(rep_code.SetLength(10));
					}
				else
					{
					dm_producer_nom->ElementREPAIRCODE_SPRNOM->AsString=Trim(rep_code);
					}
				}

			if (StrToInt(LocationcxSpinEdit->Text) > 0)
				{
				UnicodeString location=dc_upd->Values[i][TableUpdateLOCATION_SPRNOM->Index];
				if (location.Length()>10)
					{
					dm_producer_nom->ElementLOCATION_SPRNOM->AsString=Trim(location.SetLength(10));
					}
				else
					{
					dm_producer_nom->ElementLOCATION_SPRNOM->AsString=Trim(location);
					}
				}

				UnicodeString artikul = Trim(dc_upd->Values[i][TableUpdateART_SPRNOM->Index]);

				if (artikul.Length() > 40)
					{
					artikul = artikul.SetLength(40);
					}


			dm_producer_nom->ElementART_SPRNOM->AsString=artikul;

			dm_producer_nom->ElementPRICE_ZAKUP_SPRNOM->AsFloat=dc_upd->Values[i][TableUpdatePRICE_ZAKUP_SPRNOM->Index];
			dm_producer_nom->ElementPRICE_SPRNOM->AsFloat=dc_upd->Values[i][TableUpdatePRICE_SPRNOM->Index];

			//модель
			UnicodeString model=dc_upd->Values[i][TableUpdateMODEL_STR_SPRNOM->Index];
			dm_producer_nom->ElementMODEL_STR_SPRNOM->AsString=model;

			//аналог
			UnicodeString analog = dc_upd->Values[i][TableUpdateCODE_ANALOG_STR_SPRNOM->Index];
			dm_producer_nom->ElementCODE_ANALOG_STR_SPRNOM->AsString=analog;


			dm_producer_nom->ElementFL_DOSTUPNO_SPRNOM->AsInteger=dc_upd->Values[i][TableUpdateFL_DOSTUPNO_SPRNOM->Index];

		dm_producer_nom->Element->Post();




				if (dm_producer_nom->SaveElement()==false)
					{
					text_error="Ошибка при записи новой номенклатуры: "+dm_producer_nom->TextError+"\n";
					text_error=text_error+" Номенклатура: "+dc_upd->Values[i][TableUpdateNAME_SPRNOM->Index];
					throw Exception(text_error,0);
					}


		ProgressBar1->StepIt();
		}


	}
catch(Exception &exception)
		{
		ShowMessage(exception.Message);
		}

		IDMSprProducer *dm_producer;
		InterfaceGlobalCom->kanCreateObject(ProgId_DMSprProducer ,IID_IDMSprProducer,
													(void**)&dm_producer);
		dm_producer->Init(InterfaceMainObject,InterfaceImpl);

		dm_producer->OpenElement(IdProducer);

		dm_producer->Element->Edit();
		dm_producer->ElementPOSZAGRNOM_SPRODUCER->AsDateTime=pos_update;
		dm_producer->Element->Post();
		dm_producer->SaveElement();
		dm_producer->kanRelease();

dm_producer_nom->kanRelease();

}
//---------------------------------------------------------------------------

void __fastcall TFormaImportSprProducerNom::ExternalCodcxCheckBoxPropertiesValidate(
	  TObject *Sender, Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
ShowMessage("Внимание! При установленном флаге новым номенклатурам будет присвоен код из документа.");
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportSprProducerNom::ExternalBarCodecxCheckBoxPropertiesValidate(
	  TObject *Sender, Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
ShowMessage("Внимание! При установленном флаге новым единицам будет присвоен штрих код из документа.");
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportSprProducerNom::NameGrpNomcxButtonEditPropertiesButtonClick(
	  TObject *Sender, int AButtonIndex)
{
ViborGrpNom();
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportSprProducerNom::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("ImportDocInExcel");
}
//---------------------------------------------------------------------------


void __fastcall TFormaImportSprProducerNom::ReadShtrihCodEvent(int number, UnicodeString sh)
{
TcxCustomDataController *dc = cxGrid1BandedTableView1->DataController;
int row=cxGrid1BandedTableView1->Controller->FocusedRowIndex;

AnsiString s=sh;

IObjectBarCode * ob_bar;
		InterfaceGlobalCom->kanCreateObject("Oberon.ObjectBarCode.1",IID_IObjectBarCode,
													(void**)&ob_bar);
		ob_bar->Init(InterfaceMainObject,InterfaceImpl);
IDMSprNom * dm_nom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&dm_nom);
		dm_nom->Init(InterfaceMainObject,InterfaceImpl);
IDMSprEd * dm_ed;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprEd.1",IID_IDMSprEd,
													(void**)&dm_ed);
		dm_ed->Init(InterfaceMainObject,InterfaceImpl);

ob_bar->SprNom=dm_nom;
ob_bar->SprEd=dm_ed;
ob_bar->ObrabotatShtrihCod(sh);

if (ob_bar->OutReady==true)
	{
	dc->Values[row][cxGrid1BandedTableView1IDNOM->Index] =
							dm_nom->ElementIDNOM->AsString;
	//dc->Values[row][cxGrid1BandedTableView1NAMENOM->Index] =
	//						dm_nom->ElementNAMENOM->AsString;
	}
else
	{
	ShowMessage(ob_bar->TextError);
	}
ob_bar->kanRelease();
dm_nom->kanRelease();
dm_ed->kanRelease();
}
//---------------------------------------------------------------------------


void __fastcall TFormaImportSprProducerNom::cxButtonDelStringClick(TObject *Sender)
{
//удалим текущую строку

TcxCustomDataController *dc = cxGrid1BandedTableView1->DataController;
dc->DeleteFocused();
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportSprProducerNom::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------


void __fastcall TFormaImportSprProducerNom::FormActivate(TObject *Sender)
{
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
//---------------------------------------------------------------------------

void __fastcall TFormaImportSprProducerNom::FormDeactivate(TObject *Sender)
{
//зарегистрируем свой IAsyncExternalEvent в главном модуле для получения событий

if(InterfaceMainObject)
	{
	IAsyncExternalEvent * interf=0;
	InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
	if (interf)
		{
		interf->SetInterfaceForAsyncExternalEvent(0);
		interf->kanRelease();
		}
	}
}
//---------------------------------------------------------------------------
////выбор номенклатуры
void TFormaImportSprProducerNom::ViborNomFind(void)
{
TcxCustomDataController *dc = cxGrid1BandedTableView1->DataController;

if (FormaSprNomFind==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSprNomFind,IID_IFormaSprNomFind,
													(void**)&FormaSprNomFind);
		FormaSprNomFind->Init(InterfaceMainObject,InterfaceImpl);
		FormaSprNomFind->Vibor=true;
//		FormaSpiskaSprNom->DM->IdTypePrice=DM->DocIDRTPRICE_DVIPPROD->AsInt64;
//		FormaSpiskaSprNom->SpisokTypePrice->ItemIndex=FormaSpiskaSprNom->DM->GetIndexTypePrice()-1;
		FormaSprNomFind->IdNom=glStrToInt64(dc->Values[dc->FocusedRowIndex][0]);
		FormaSprNomFind->NameNom=dc->Values[dc->FocusedRowIndex][cxGrid1BandedTableView1NAMENOMPOST->Index] ;
		FormaSprNomFind->UpdateForm();
		FormaSprNomFind->NumberProcVibor=ER_NomFind;
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaImportSprProducerNom::EndViborNomFind(void)
{
TcxCustomDataController *dc = cxGrid1BandedTableView1->DataController;
int row=cxGrid1BandedTableView1->Controller->FocusedRowIndex;

	dc->Values[row][cxGrid1BandedTableView1IDNOM->Index] =
							FormaSprNomFind->DM->TableIDNOM->AsString;;
  //	dc->Values[row][cxGrid1BandedTableView1NAMENOM->Index] =
  //							FormaSprNomFind->DM->TableNAMENOM->AsString;
	dc->Values[row][cxGrid1BandedTableView1CODENOM->Index] =
							FormaSprNomFind->DM->TableCODENOM->AsString;
	dc->Values[row][cxGrid1BandedTableView1ARTNOM->Index] =
							FormaSprNomFind->DM->TableARTNOM->AsString;
	dc->Values[row][cxGrid1BandedTableView1BARCODE->Index] =
							FormaSprNomFind->DM->TableSHED->AsString;


}
//----------------------------------------------------------------------------


void __fastcall TFormaImportSprProducerNom::ToolButtonNoAddNomInSprClick(TObject *Sender)

{

if (IdKlient==0)
	{
	ShowMessage("Необходимо выбрать поставщика!");
	return;
	}

AnsiString text_error="";
IDMSprGrpNom *dm_grp_nom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprGrpNom.1",IID_IDMSprGrpNom,
													(void**)&dm_grp_nom);
		dm_grp_nom->Init(InterfaceMainObject,InterfaceImpl);
IDMSprNom *dm_nom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&dm_nom);
		dm_nom->Init(InterfaceMainObject,InterfaceImpl);
IDMSprEd * dm_spr_ed;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprEd.1",IID_IDMSprEd,
													(void**)&dm_spr_ed);
		dm_spr_ed->Init(InterfaceMainObject,InterfaceImpl);
IDMSprImportNom * dm_import_nom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprImportNom.1",IID_IDMSprImportNom,
													(void**)&dm_import_nom);
		dm_import_nom->Init(InterfaceMainObject,InterfaceImpl);


__int64 id_grp=0;
//проверим есть ли группа куда добавлять товары
if (IdGrpNom==0)
	{
	id_grp=dm_grp_nom->FindPoName(Trim(NameKlientcxButtonEdit->Text));
	if (id_grp==0)
		{
		dm_grp_nom->NewElement(0);
		dm_grp_nom->ElementNAMEGN->AsString=Trim(NameKlientcxButtonEdit->Text);
		dm_grp_nom->SaveElement();
		id_grp=dm_grp_nom->ElementIDGN->AsInt64;
		}
	}
else
	{
	id_grp=IdGrpNom;
	}



try
	{
	TcxCustomDataController *dc = cxGrid1BandedTableView1->DataController;
	dc->GotoFirst();
	for (int i=0; i<dc->RowCount; i++)
		{
		AnsiString code=dc->Values[i][1];
		__int64 id_nom=glStrToInt64(dc->Values[i][0]);

		if(id_nom==0) //создаем новую номенклатуру
			{
			//в данном случае не создаем новую номенклатуру
			//переходим к следующей строке
			continue;
			}
		else
			{
			dm_nom->OpenElement(id_nom);
			}


		//может быть номенклатура указана вручную
		//так как такой товар уже есть в базе
		//искать надо не по клиенту, а по номенклатуре
		//? или по клиенту, чтобы исправить номенклатуру
		__int64 id_import=0;

		if (TypeSearchcxComboBox->ItemIndex==1)
			{
			if (StrToInt(CodeNomcxSpinEdit->Text)!=0)
				{ //ищем по коду
				id_import=dm_import_nom->FindElementPoCodu(IdKlient,dc->Values[i][cxGrid1BandedTableView1CODENOM->Index]);
				}
			}

		if (TypeSearchcxComboBox->ItemIndex==2)
			{
			if(StrToInt(NameNomcxSpinEdit->Text)!=0)
				{//ищем по наименованию
				id_import=dm_import_nom->FindElementPoName(IdKlient,dc->Values[i][cxGrid1BandedTableView1NAMENOMPOST->Index]);
				}
			}

		//по артикулу
		if (TypeSearchcxComboBox->ItemIndex==3)
			{
			if(StrToInt(ArtNomcxSpinEdit->Text)!=0)
				{//ищем по артикулу
				id_import=dm_import_nom->FindElementPoArtikulu(IdKlient,dc->Values[i][cxGrid1BandedTableView1ARTNOM->Index]);
				}
			}



		if (id_import==0)
			{
			dm_import_nom->NewElement(id_nom);
			dm_import_nom->Element->Edit();
			dm_import_nom->ElementNAME_SIMPORTNOM->AsString=dc->Values[i][cxGrid1BandedTableView1NAMENOMPOST->Index];
			dm_import_nom->ElementCODE_SIMPORTNOM->AsString=dc->Values[i][cxGrid1BandedTableView1CODENOM->Index];
			dm_import_nom->ElementART_SIMPORTNOM->AsString=dc->Values[i][cxGrid1BandedTableView1ARTNOM->Index];
			dm_import_nom->ElementIDKLIENT_SIMPORTNOM->AsString=IdKlient;
			dm_import_nom->Element->Post();
			if (dm_import_nom->SaveElement()==false)
				{
				text_error="Ошибка при записи справочника Импорт номенклатуры: "+dm_import_nom->TextError;
				text_error=text_error+" Номенклатура: "+dc->Values[i][cxGrid1BandedTableView1NAMENOMPOST->Index];
				throw Exception(text_error,0);
				}
			}
		else //исправляем параметры поиска  в справочнике Импорт номенклатуры
			{
			dm_import_nom->OpenElement(id_import);
			bool update=false;
			AnsiString name=dc->Values[i][cxGrid1BandedTableView1NAMENOMPOST->Index];
			AnsiString code=dc->Values[i][cxGrid1BandedTableView1CODENOM->Index];
			if (Trim(dm_import_nom->ElementNAME_SIMPORTNOM->AsString)!=Trim(name) ||
				dm_import_nom->ElementCODE_SIMPORTNOM->AsString!=Trim(code) ||
				dm_import_nom->ElementIDNOM_SIMPORTNOM->AsInt64!=id_nom)
				{
				update=true;
				}

			if (update==true)
				{
				dm_import_nom->Element->Edit();
				dm_import_nom->ElementNAME_SIMPORTNOM->AsString=dc->Values[i][cxGrid1BandedTableView1NAMENOMPOST->Index];
				dm_import_nom->ElementCODE_SIMPORTNOM->AsString=dc->Values[i][cxGrid1BandedTableView1CODENOM->Index];
				dm_import_nom->ElementART_SIMPORTNOM->AsString=dc->Values[i][cxGrid1BandedTableView1ARTNOM->Index];
				dm_import_nom->ElementIDKLIENT_SIMPORTNOM->AsString=IdKlient;
				dm_import_nom->Element->Post();
				if (dm_import_nom->SaveElement()==false)
					{
					text_error="Ошибка при записи справочника Импорт номенклатуры "+dm_import_nom->TextError;
					text_error=text_error+" Номенклатура: "+dc->Values[i][cxGrid1BandedTableView1NAMENOMPOST->Index];
					throw Exception(text_error,0);
					}
				}
			}
		}
	}
catch(Exception &exception)
		{
		ShowMessage(exception.Message);
		}


dm_import_nom->kanRelease();
dm_spr_ed->kanRelease();
dm_nom->kanRelease();
dm_grp_nom->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportSprProducerNom::ToolButtonAddNewNomClick(TObject *Sender)

{


if (IdKlient==0)
	{
	ShowMessage("Необходимо выбрать поставщика!");
	return;
	}

AnsiString text_error="";
IDMSprGrpNom *dm_grp_nom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprGrpNom.1",IID_IDMSprGrpNom,
													(void**)&dm_grp_nom);
		dm_grp_nom->Init(InterfaceMainObject,InterfaceImpl);
IDMSprNom *dm_nom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&dm_nom);
		dm_nom->Init(InterfaceMainObject,InterfaceImpl);
IDMSprEd * dm_spr_ed;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprEd.1",IID_IDMSprEd,
													(void**)&dm_spr_ed);
		dm_spr_ed->Init(InterfaceMainObject,InterfaceImpl);
IDMSprImportNom * dm_import_nom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprImportNom.1",IID_IDMSprImportNom,
													(void**)&dm_import_nom);
		dm_import_nom->Init(InterfaceMainObject,InterfaceImpl);


__int64 id_grp=0;
//проверим есть ли группа куда добавлять товары
if (IdGrpNom==0)
	{
	id_grp=dm_grp_nom->FindPoName(Trim(NameKlientcxButtonEdit->Text));
	if (id_grp==0)
		{
		dm_grp_nom->NewElement(0);
		dm_grp_nom->ElementNAMEGN->AsString=Trim(NameKlientcxButtonEdit->Text);
		dm_grp_nom->SaveElement();
		id_grp=dm_grp_nom->ElementIDGN->AsInt64;
		}
	}
else
	{
	id_grp=IdGrpNom;
	}


try
	{


	TcxCustomDataController *dc = cxGrid1BandedTableView1->DataController;
	dc->GotoFirst();
	for (int i=0; i<dc->RowCount; i++)
		{
		AnsiString code=dc->Values[i][1];
		__int64 id_nom=glStrToInt64(dc->Values[i][0]);

		if(id_nom==0) //создаем новую номенклатуру
			{
			dm_nom->NewElement(id_grp);
			dm_nom->Element->Edit();
			dm_nom->ElementTNOM->AsInteger=0;
			dm_nom->ElementNAMENOM->AsString=dc->Values[i][cxGrid1BandedTableView1NAMENOMPOST->Index];
			UnicodeString   kr_name=dc->Values[i][cxGrid1BandedTableView1NAMENOMPOST->Index];
			dm_nom->ElementKRNAMENOM->AsString=kr_name.SetLength(40);
			dm_nom->ElementFNAMENOM->AsString=dc->Values[i][cxGrid1BandedTableView1NAMENOMPOST->Index];
			dm_nom->ElementARTNOM->AsString=dc->Values[i][cxGrid1BandedTableView1ARTNOM->Index];

			//определим страну  и вставим в новую номенклатуру
			//новую страну не добавляем чтобы не было повторяющихся строк
			//или вообще не учитываем страну
			//будем задавать вручную т. к. много различных написаний страны
			__int64 id_country=0;
			UnicodeString name_country="";
			name_country=Trim(dc->Values[i][cxGrid1BandedTableView1COUNTRY->Index]);
			if (name_country!="")
				{
				IDMSprCountry * dm_spr_country;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprCountry.1",IID_IDMSprCountry,
													(void**)&dm_spr_country);
				dm_spr_country->Init(InterfaceMainObject,InterfaceImpl);
				id_country = dm_spr_country->GetIdPoName(dc->Values[i][cxGrid1BandedTableView1COUNTRY->Index]);


				if (id_country ==0)
					{
					dm_spr_country->NewElement();
					dm_spr_country->Element->Edit();
					dm_spr_country->ElementNAME_SCOUNTRY->AsString=name_country;
					dm_spr_country->Element->Post();
					dm_spr_country->SaveElement();
					id_country=glStrToInt64(dm_spr_country->ElementID_SCOUNTRY->AsString);
					}

				dm_spr_country->kanRelease();
				}

			if (id_country !=0)
				{
				dm_nom->ElementIDCOUNTRYNOM->AsString=id_country;
				}

			if (IdFirm!=0)
				{
				dm_nom->ElementIDFIRMNOM->AsString=IdFirm;
				}

			if (ExternalCodcxCheckBox->Checked==true)
				{
				dm_nom->ElementCODENOM->AsInteger=StrToInt(dc->Values[i][1]);
				}
			dm_nom->Element->Post();
			if (dm_nom->SaveElement()==false)
				{
				text_error="Ошибка при записи новой номенклатуры: "+dm_nom->TextError+"\n";
				text_error=text_error+" Номенклатура: "+dc->Values[i][cxGrid1BandedTableView1NAMENOMPOST->Index];
				throw Exception(text_error,0);
				}

			if (glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString)==0)
				{
				dm_spr_ed->NewElement(glStrToInt64(dm_nom->ElementIDNOM->AsString));
				}
			else
				{
                dm_spr_ed->OpenElement(glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString));
				}
			dm_spr_ed->Element->Edit();
			if (ExternalBarCodecxCheckBox->Checked==true)
				{
				dm_spr_ed->ElementSHED->AsString=dc->Values[i][cxGrid1BandedTableView1BARCODE->Index];
				}

			dm_spr_ed->ElementNAMEED->AsString=dc->Values[i][cxGrid1BandedTableView1NAMEED->Index];
            dm_spr_ed->Element->Post();
			if (dm_spr_ed->SaveElement()==false)
				{
				text_error="Ошибка при записи новой единицы измерения: "+dm_spr_ed->TextError;
				text_error=text_error+" Номенклатура: "+dc->Values[i][2];
				throw Exception(text_error,0);
				}
			dm_nom->Element->Edit();
			if (glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString)==0)
				{
				dm_nom->ElementIDBASEDNOM->AsString=dm_spr_ed->ElementIDED->AsString;
				}
			dm_nom->ElementIDOSNEDNOM->AsString=glStrToInt64(dm_spr_ed->ElementIDED->AsString);
			dm_nom->Element->Post();
			if (dm_nom->SaveElement()==false)
				{
				text_error="Ошибка при записи новой номенклатуры после указания базовой единицы: "+dm_nom->TextError;
				text_error=text_error+" Номенклатура: "+dc->Values[i][cxGrid1BandedTableView1NAMENOMPOST->Index];
				throw Exception(text_error,0);
				}
			id_nom=glStrToInt64(dm_nom->ElementIDNOM->AsString);
			}
		else
			{
			dm_nom->OpenElement(id_nom);
			}


		//может быть номенклатура указана вручную
		//так как такой товар уже есть в базе
		//искать надо не по клиенту, а по номенклатуре
		//? или по клиенту, чтобы исправить номенклатуру
		__int64 id_import=0;

		if (TypeSearchcxComboBox->ItemIndex==1)
			{
			if (StrToInt(CodeNomcxSpinEdit->Text)!=0)
				{ //ищем по коду
				id_import=dm_import_nom->FindElementPoCodu(IdKlient,dc->Values[i][cxGrid1BandedTableView1CODENOM->Index]);
				}
			}

		if (TypeSearchcxComboBox->ItemIndex==2)
			{
			if(StrToInt(NameNomcxSpinEdit->Text)!=0)
				{//ищем по наименованию
				id_import=dm_import_nom->FindElementPoName(IdKlient,dc->Values[i][cxGrid1BandedTableView1NAMENOMPOST->Index]);
				}
			}

		//по артикулу
		if (TypeSearchcxComboBox->ItemIndex==3)
			{
			if(StrToInt(ArtNomcxSpinEdit->Text)!=0)
				{//ищем по артикулу
				id_import=dm_import_nom->FindElementPoArtikulu(IdKlient,dc->Values[i][cxGrid1BandedTableView1ARTNOM->Index]);
				}
			}



		if (id_import==0)
			{
			dm_import_nom->NewElement(id_nom);
			dm_import_nom->Element->Edit();
			dm_import_nom->ElementNAME_SIMPORTNOM->AsString=dc->Values[i][cxGrid1BandedTableView1NAMENOMPOST->Index];
			dm_import_nom->ElementCODE_SIMPORTNOM->AsString=dc->Values[i][cxGrid1BandedTableView1CODENOM->Index];
			dm_import_nom->ElementART_SIMPORTNOM->AsString=dc->Values[i][cxGrid1BandedTableView1ARTNOM->Index];
			dm_import_nom->ElementIDKLIENT_SIMPORTNOM->AsString=IdKlient;
			dm_import_nom->Element->Post();
			if (dm_import_nom->SaveElement()==false)
				{
				text_error="Ошибка при записи справочника Импорт номенклатуры: "+dm_import_nom->TextError;
				text_error=text_error+" Номенклатура: "+dc->Values[i][cxGrid1BandedTableView1NAMENOMPOST->Index];
				throw Exception(text_error,0);
				}
			}
		else //исправляем параметры поиска  в справочнике Импорт номенклатуры
			{
			dm_import_nom->OpenElement(id_import);
			bool update=false;
			AnsiString name=dc->Values[i][cxGrid1BandedTableView1NAMENOMPOST->Index];
			AnsiString code=dc->Values[i][cxGrid1BandedTableView1CODENOM->Index];
			if (Trim(dm_import_nom->ElementNAME_SIMPORTNOM->AsString)!=Trim(name) ||
				dm_import_nom->ElementCODE_SIMPORTNOM->AsString!=Trim(code) ||
				dm_import_nom->ElementIDNOM_SIMPORTNOM->AsInt64!=id_nom)
				{
				update=true;
				}

			if (update==true)
				{
				dm_import_nom->Element->Edit();
				dm_import_nom->ElementNAME_SIMPORTNOM->AsString=dc->Values[i][cxGrid1BandedTableView1NAMENOMPOST->Index];
				dm_import_nom->ElementCODE_SIMPORTNOM->AsString=dc->Values[i][cxGrid1BandedTableView1CODENOM->Index];
				dm_import_nom->ElementART_SIMPORTNOM->AsString=dc->Values[i][cxGrid1BandedTableView1ARTNOM->Index];
				dm_import_nom->ElementIDKLIENT_SIMPORTNOM->AsString=IdKlient;
				dm_import_nom->Element->Post();
				if (dm_import_nom->SaveElement()==false)
					{
					text_error="Ошибка при записи справочника Импорт номенклатуры "+dm_import_nom->TextError;
					text_error=text_error+" Номенклатура: "+dc->Values[i][cxGrid1BandedTableView1NAMENOMPOST->Index];
					throw Exception(text_error,0);
					}
				}
			}
		}
	}
catch(Exception &exception)
		{
		ShowMessage(exception.Message);
		}


dm_import_nom->kanRelease();
dm_spr_ed->kanRelease();
dm_nom->kanRelease();
dm_grp_nom->kanRelease();
}
//---------------------------------------------------------------------------
//UnicodeString	TFormaImportDocPrihNakl::FormatTxtString(UnicodeString s)
//{
//UnicodeString result="";
//AnsiString ansi_str=Trim(s);
//result=ansi_str;
//char * p=s.t_str();
//
//UnicodeString bin_str="";
//
//ShowMessage(s.Length());
//
//for (int i=0;i<10;i++)
//	{
//	//bin_str=bin_str+" "+
//	//ShowMessage(IntToHex(p[i],8));
//	}
//
//ShowMessage(s+" "+bin_str);
//return result;
//}
////---------------------------------------------------------------------------
void __fastcall TFormaImportSprProducerNom::NameProducercxButtonEditPropertiesButtonClick(TObject *Sender,
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
void TFormaImportSprProducerNom::OpenFormSpiskaSprProducer(void)
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
void __fastcall TFormaImportSprProducerNom::ToolButtonSaveExcelClick(TObject *Sender)

{
	if (SaveDialog1->Execute())
		{
		ExportGridToExcel(SaveDialog1->FileName, cxGrid1, true, true,true, "xls");
		}
}
//---------------------------------------------------------------------------
double TFormaImportSprProducerNom::GetRoznPrice(double price)
{
double result=0;

if (price < 0.01 )
	{
	result=0;
	}
else if (price >= 0.01  && price < 10)
	{
	result = 30;
	}
else if (price >= 10  && price < 30)
	{
	result = 60;
	}
else if (price >= 30  && price < 60)
	{
	result = 100;
	}
else if ( price >= 60 && price < 200)
	{
	result = glRoundValue(price*2, -1);
	}
else if ( price >= 200 && price < 400)
	{
	result = glRoundValue(price*1.7, -1);
	}
else if ( price >= 400 && price < 2000 )
	{
	result = glRoundValue(price*1.5, -1);
	}
else
	{
    result = glRoundValue(price*1.3, -1);
	}

return result;
}
//--------------------------------------------------------------------------

void __fastcall TFormaImportSprProducerNom::cxButtonProveritClick(TObject *Sender)

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

IDMSprProducerNom *dm_producer_nom;
		InterfaceGlobalCom->kanCreateObject(ProgId_DMSprProducerNom ,IID_IDMSprProducerNom,
													(void**)&dm_producer_nom);
		dm_producer_nom->Init(InterfaceMainObject,InterfaceImpl);



__int64 id_grp=0;
__int64 id_producer_nom=0;


__int64 ID_SPRNOM = 0;
int CODE_SPRNOM = 0;
UnicodeString ART_SPRNOM="";
UnicodeString NAME_SPRNOM="";

double PRICE_ZAKUP_SPRNOM=0;
double PRICE_SPRNOM=0;
UnicodeString MODEL_STR_SPRNOM="";
UnicodeString CODE_ANALOG_STR_SPRNOM="";
int FL_DOSTUPNO_SPRNOM=0;

UnicodeString REPAIRCODE_SPRNOM="";
UnicodeString LOCATION_SPRNOM="";


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
			LabelInfo->Caption="Обрабатываем строку: "+IntToStr(kol_record_all)+" "+dc->Values[i][cxGrid1BandedTableView1NAMENOMPOST->Index]
											+" артикул "+dc->Values[i][cxGrid1BandedTableView1ARTNOM->Index]
											+" предыдущая строка "+dc->Values[i-1][cxGrid1BandedTableView1NAMENOMPOST->Index]
											+" артикул "+dc->Values[i-1][cxGrid1BandedTableView1ARTNOM->Index];
			}
		else
			{
			LabelInfo->Caption="Обрабатываем строку: "+IntToStr(kol_record_all)+" "+dc->Values[i][cxGrid1BandedTableView1NAMENOMPOST->Index]
											+" артикул "+dc->Values[i][cxGrid1BandedTableView1ARTNOM->Index];
			}

		UnicodeString artikul = Trim(dc->Values[i][cxGrid1BandedTableView1ARTNOM->Index]);

		if (artikul.Length() > 40)
			{
			artikul = artikul.SetLength(40);
			}

		if (artikul == "")       //не задан артикул нет смысла искать
			{
			 ProgressBar1->StepIt();
			 continue;
			}

		if(TypeSearchcxComboBox->ItemIndex == 3 )
			{  //поиск по артикулу

			UnicodeString model = "";
			id_producer_nom = dm_producer_nom->FindPoArtikulu(IdProducer,model,artikul);
			}

		if(TypeSearchcxComboBox->ItemIndex == 4 )
			{  //поиск по артикулу   и модели
			UnicodeString model = Trim(dc->Values[i][cxGrid1BandedTableView1MODEL->Index]);
			id_producer_nom = dm_producer_nom->FindPoArtikulu(IdProducer,model,artikul);
			}

		if(id_producer_nom==0) //создаем новую номенклатуру
			{
			//*********************************************************************************
			dc_upd->AppendRecord();
			dc_upd->Values[number_string_table_upd][TableUpdateTypeUpdate->Index] = 1;
			dc_upd->Values[number_string_table_upd][TableUpdateID_SPRNOM->Index] = "";
			dc_upd->Values[number_string_table_upd][TableUpdateCODE_SPRNOM->Index] = dc->Values[i][cxGrid1BandedTableView1CODENOM->Index];
			dc_upd->Values[number_string_table_upd][TableUpdateART_SPRNOM->Index] = dc->Values[i][cxGrid1BandedTableView1ARTNOM->Index];
			dc_upd->Values[number_string_table_upd][TableUpdateNAME_SPRNOM->Index] = dc->Values[i][cxGrid1BandedTableView1NAMENOMPOST->Index];

			double price=dc->Values[i][cxGrid1BandedTableView1PRICE->Index];

			dc_upd->Values[number_string_table_upd][TableUpdatePRICE_ZAKUP_SPRNOM->Index] = dc->Values[i][cxGrid1BandedTableView1PRICE->Index];
			dc_upd->Values[number_string_table_upd][TableUpdatePRICE_SPRNOM->Index] = GetRoznPrice(price);


			dc_upd->Values[number_string_table_upd][TableUpdateMODEL_STR_SPRNOM->Index] = dc->Values[i][cxGrid1BandedTableView1MODEL->Index];
			dc_upd->Values[number_string_table_upd][TableUpdateCODE_ANALOG_STR_SPRNOM->Index] = dc->Values[i][cxGrid1BandedTableView1ANALOG->Index];
			dc_upd->Values[number_string_table_upd][TableUpdateFNAME_SPRNOM->Index] = dc->Values[i][cxGrid1BandedTableView1FULLNAME->Index];
			dc_upd->Values[number_string_table_upd][TableUpdateKRNAME_SPRNOM->Index] = dc->Values[i][cxGrid1BandedTableView1KRNAME->Index];
			dc_upd->Values[number_string_table_upd][TableUpdateREPAIRCODE_SPRNOM->Index] = dc->Values[i][cxGrid1BandedTableView1REP_CODE->Index];
			dc_upd->Values[number_string_table_upd][TableUpdateLOCATION_SPRNOM->Index] = dc->Values[i][cxGrid1BandedTableView1LOCATION->Index];
			float kol=0;

			//доступность
			UnicodeString dostupno=dc->Values[i][cxGrid1BandedTableView1DOSTUPNO->Index];
			int int_dostupno=0;
			if (dostupno == "Y")
				{
				int_dostupno = 1;
				}
			if (dostupno == "N")
				{
				int_dostupno = 0;
				}




			dc_upd->Values[number_string_table_upd][TableUpdateFL_DOSTUPNO_SPRNOM->Index]= int_dostupno;

			//**********************************************************************************
            number_string_table_upd++;
			}
		else
			{  //найдена
			bool fl_save=false;

			ID_SPRNOM = 0;
			CODE_SPRNOM = 0;
			ART_SPRNOM=dc->Values[i][cxGrid1BandedTableView1ARTNOM->Index];      //найдена ведь
			NAME_SPRNOM=dc->Values[i][cxGrid1BandedTableView1NAMENOMPOST->Index];

			PRICE_ZAKUP_SPRNOM=dc->Values[i][cxGrid1BandedTableView1PRICE->Index];
			PRICE_SPRNOM=GetRoznPrice(PRICE_ZAKUP_SPRNOM);

			MODEL_STR_SPRNOM=dc->Values[i][cxGrid1BandedTableView1MODEL->Index];   //найдена ведь
			CODE_ANALOG_STR_SPRNOM=dc->Values[i][cxGrid1BandedTableView1ANALOG->Index];

			REPAIRCODE_SPRNOM=dc->Values[i][cxGrid1BandedTableView1REP_CODE->Index];
			LOCATION_SPRNOM=dc->Values[i][cxGrid1BandedTableView1LOCATION->Index];

			//доступность
			UnicodeString dostupno=dc->Values[i][cxGrid1BandedTableView1DOSTUPNO->Index];
			int int_dostupno=0;
			if (dostupno == "Y")
				{
				FL_DOSTUPNO_SPRNOM = 1;
				}
			if (dostupno == "N")
				{
				FL_DOSTUPNO_SPRNOM = 0;
				}


			dm_producer_nom->OpenElement(id_producer_nom);



			if (dm_producer_nom->ElementNAME_SPRNOM->AsString
							!= NAME_SPRNOM )
				{
				fl_save=true;
				}

			int res=glCompareDoubleValue(dm_producer_nom->ElementPRICE_ZAKUP_SPRNOM->AsFloat,PRICE_ZAKUP_SPRNOM,3);
			if (res !=0)
				{
				fl_save=true;
				}

			res=glCompareDoubleValue(dm_producer_nom->ElementPRICE_SPRNOM->AsFloat,PRICE_SPRNOM,3);
			if (res !=0)
				{
				fl_save=true;
				}


			if (dm_producer_nom->ElementFL_DOSTUPNO_SPRNOM->AsInteger != FL_DOSTUPNO_SPRNOM)
				{
				fl_save=true;
				}


			if ( dm_producer_nom->ElementCODE_ANALOG_STR_SPRNOM->AsString !=  CODE_ANALOG_STR_SPRNOM)
				{
				fl_save=true;
				}



			if (fl_save == true)
				{   //добавляем запись в таблицу изменений

			//*********************************************************************************

			dc_upd->AppendRecord();
			dc_upd->Values[number_string_table_upd][TableUpdateTypeUpdate->Index] = 2;
			dc_upd->Values[number_string_table_upd][TableUpdateID_SPRNOM->Index] = dm_producer_nom->ElementID_SPRNOM->AsString;
			dc_upd->Values[number_string_table_upd][TableUpdateCODE_SPRNOM->Index] = CODE_SPRNOM;
			dc_upd->Values[number_string_table_upd][TableUpdateART_SPRNOM->Index] = ART_SPRNOM;
			dc_upd->Values[number_string_table_upd][TableUpdateNAME_SPRNOM->Index] = NAME_SPRNOM;
			dc_upd->Values[number_string_table_upd][TableUpdatePRICE_ZAKUP_SPRNOM->Index] = PRICE_ZAKUP_SPRNOM;
			dc_upd->Values[number_string_table_upd][TableUpdatePRICE_SPRNOM->Index] = PRICE_SPRNOM;
			dc_upd->Values[number_string_table_upd][TableUpdateMODEL_STR_SPRNOM->Index] = MODEL_STR_SPRNOM;
			dc_upd->Values[number_string_table_upd][TableUpdateCODE_ANALOG_STR_SPRNOM->Index] = CODE_ANALOG_STR_SPRNOM;
			dc_upd->Values[number_string_table_upd][TableUpdateFL_DOSTUPNO_SPRNOM->Index]= FL_DOSTUPNO_SPRNOM;

			dc_upd->Values[number_string_table_upd][TableUpdateREPAIRCODE_SPRNOM->Index] = REPAIRCODE_SPRNOM;
			dc_upd->Values[number_string_table_upd][TableUpdateLOCATION_SPRNOM->Index] = LOCATION_SPRNOM;
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


dm_producer_nom->kanRelease();

KolRecordUpdate=number_string_table_upd;
}
//---------------------------------------------------------------------------

