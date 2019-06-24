//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaImportDocPrihNakl.h"
#include "UDM.h"
#include "IDMSprImportNom.h"
#include "IDMSprNom.h"
#include "IDMDocPrihNakl.h"
#include "IFormaDocPrihNakl.h"
#include "IFormaDocRegOtchetPost.h"
#include "IREM_FormaDocRegOtchetPost.h"
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
#include "IFormaDocReal.h"
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
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaImportDocPrihNakl::TFormaImportDocPrihNakl(TComponent* Owner)
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
void __fastcall TFormaImportDocPrihNakl::FormCreate(TObject *Sender)
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
}
//-----------------------------------------------------------------------
bool TFormaImportDocPrihNakl::Init(void)
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
int TFormaImportDocPrihNakl::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportDocPrihNakl::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprImportSet)FormaSpiskaSprImportSet->kanRelease();
if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(FormaSpiskaSprFirm)FormaSpiskaSprFirm->kanRelease();
if(FormaSpiskaSprSklad)FormaSpiskaSprSklad->kanRelease();
if(FormaSpiskaSprKlient)FormaSpiskaSprKlient->kanRelease();
if(FormaSpiskaSprNom)FormaSpiskaSprNom->kanRelease();
if(FormaSprNomFind)FormaSprNomFind->kanRelease();
if (FormaGurAllDoc) FormaGurAllDoc->kanRelease();

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
void TFormaImportDocPrihNakl::UpdateForm(void)
{


}
//---------------------------------------------------------------------------
int TFormaImportDocPrihNakl::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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


	if (number_procedure_end==ER_GurAllDoc)
		{
		if (type_event==1)
				{
				 EndViborDocGurAllDoc();
				}
		FormaGurAllDoc=0;
		}

FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------
void __fastcall TFormaImportDocPrihNakl::FileNamecxButtonEditPropertiesButtonClick(
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
void TFormaImportDocPrihNakl::OpenFormSpiskaSprImportSet(void)
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
void __fastcall TFormaImportDocPrihNakl::EndViborImportSet(void)
{

	IdImportSet=FormaSpiskaSprImportSet->DM->TableID_SIMPORTSET->AsInt64;
	NameImportSetcxButtonEdit->Text=FormaSpiskaSprImportSet->DM->TableNAME_SIMPORTSET->AsString;
    UpdateSetup();


}
//---------------------------------------------------------------------------
void __fastcall TFormaImportDocPrihNakl::NameImportSetcxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprImportSet();
}
//---------------------------------------------------------------------------
void TFormaImportDocPrihNakl::UpdateSetup(void)
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

if (Trim(DMSprImportSet->GetParameter("TYPE_SEARCH"))!="")
	{
	TypeSearchcxComboBox->ItemIndex=StrToInt(DMSprImportSet->GetParameter("TYPE_SEARCH"));
	}
}
//----------------------------------------------------------------------------
void TFormaImportDocPrihNakl::SaveSetup(void)
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

DMSprImportSet->ElementSTRPAR_SIMPORTSET->AsString=str_param;
DMSprImportSet->Element->Post();
if (DMSprImportSet->SaveElement()!=true)
	{
    ShowMessage("Ошибка: "+DMSprImportSet->TextError);  
	}
}
//----------------------------------------------------------------------------

void __fastcall TFormaImportDocPrihNakl::cxButtonSaveParamsClick(
      TObject *Sender)
{
SaveSetup();
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportDocPrihNakl::cxButtonImportClick(TObject *Sender)
{
if (StartStringcxSpinEdit->Text=="" ||
			StartStringcxSpinEdit->Text=="0")
	{
	ShowMessage("Необходимо задать настройки импорта!");
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
		kol=StrToFloat(cell->Text);
		delete cell;
		}
	else {kol=0;}
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
		price=StrToFloat(cell->Text);
		delete cell;
		}
	else
		{
		price=0;
		if (num_sum!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_sum-1,number_string_excel-1);
			if (kol > 0.001)
				{
				price=StrToFloat(cell->Text)/kol;
				}
			delete cell;
			}
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

	//попытаемся найти такой товар в базе
	dc->AppendRecord();
	dc->Values[number_string_table][cxGrid1BandedTableView1IDNOM->Index] = "";
	dc->Values[number_string_table][1] = code;
	dc->Values[number_string_table][2] = art_nom;
	dc->Values[number_string_table][3] = name_nom;
	dc->Values[number_string_table][4] = "";
	dc->Values[number_string_table][5] = kol;
	dc->Values[number_string_table][6] = name_ed;
	dc->Values[number_string_table][7] = bar_code;
	dc->Values[number_string_table][8] = price;
	dc->Values[number_string_table][9] = sum;
	dc->Values[number_string_table][10] = rozn_price;
	dc->Values[number_string_table][11] = rozn_sum;
	dc->Values[number_string_table][cxGrid1BandedTableView1COUNTRY->Index] = country;
	dc->Values[number_string_table][cxGrid1BandedTableView1GTD->Index] = gtd;

	number_string_table++;
	number_string_excel++;
	}
catch(Exception &exception)
	{
	error=true;
	LabelError->Caption="Ошибка в строке:"+IntToStr(number_string_excel)+" "+exception.Message;
	}

if (error==false)
	{//повторяем процедуру
    goto loop;
	}

dc->EndUpdate();

}
//---------------------------------------------------------------------------
//выбор информационной базы
void TFormaImportDocPrihNakl::ViborInfBase(void)
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
void __fastcall TFormaImportDocPrihNakl::EndViborInfBase(void)
{

	IdInfBase=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsInt64;
	NameInfBasecxButtonEdit->Text=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;



}
//---------------------------------------------------------------------------
//выбор фирмы
void TFormaImportDocPrihNakl::ViborFirm(void)
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
void __fastcall TFormaImportDocPrihNakl::EndViborFirm(void)
{

	IdFirm=FormaSpiskaSprFirm->DM->ElementIDFIRM->AsInt64;
	NameFirmcxButtonEdit->Text=FormaSpiskaSprFirm->DM->ElementNAMEFIRM->AsString;



}
//----------------------------------------------------------------------------
//выбор склада
void TFormaImportDocPrihNakl::ViborSklad(void)
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
void __fastcall TFormaImportDocPrihNakl::EndViborSklad(void)
{
	IdSklad=glStrToInt64(FormaSpiskaSprSklad->DM->ElementIDSKLAD->AsString);
	NameSkladcxButtonEdit->Text=FormaSpiskaSprSklad->DM->ElementNAMESKLAD->AsString;


}
//-----------------------------------------------------------------------------
//выбор поставщика
void TFormaImportDocPrihNakl::ViborKlient(void)
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
void __fastcall TFormaImportDocPrihNakl::EndViborKlient(void)
{

	IdKlient=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsInt64;
	NameKlientcxButtonEdit->Text=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;



}
//-----------------------------------------------------------------------------
//выбор группы номенклатуры

void TFormaImportDocPrihNakl::ViborGrpNom(void)
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
void __fastcall TFormaImportDocPrihNakl::EndViborGrpNom(void)
{

	IdGrpNom=FormaSpiskaSprGrpNom->DMGrp->ElementIDGN->AsInt64;
	NameGrpNomcxButtonEdit->Text=FormaSpiskaSprGrpNom->DMGrp->ElementNAMEGN->AsString;

}
//-----------------------------------------------------------------------------
void __fastcall TFormaImportDocPrihNakl::NameInfBasecxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborInfBase();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportDocPrihNakl::NameFirmcxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborFirm();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportDocPrihNakl::NameSkladcxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborSklad();
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportDocPrihNakl::NameKlientcxButtonEditPropertiesButtonClick(
	  TObject *Sender, int AButtonIndex)
{
ViborKlient();
}
//---------------------------------------------------------------------------
////выбор номенклатуры
void TFormaImportDocPrihNakl::ViborNom(void)
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
void __fastcall TFormaImportDocPrihNakl::EndViborNom(void)
{
TcxCustomDataController *dc = cxGrid1BandedTableView1->DataController;
int row=cxGrid1BandedTableView1->Controller->FocusedRowIndex;

	dc->Values[row][cxGrid1BandedTableView1IDNOM->Index] =
							FormaSpiskaSprNom->DM->ElementIDNOM->AsString;;
	dc->Values[row][cxGrid1BandedTableView1NAMENOM->Index] =
							FormaSpiskaSprNom->DM->ElementNAMENOM->AsString;


}
//----------------------------------------------------------------------------
//выбор единицы
void TFormaImportDocPrihNakl::ViborEd(void)
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
void __fastcall TFormaImportDocPrihNakl::EndViborEd(void)
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
void __fastcall TFormaImportDocPrihNakl::cxGrid1BandedTableView1NAMENOMPropertiesButtonClick(
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
		dc->Values[row][cxGrid1BandedTableView1NAMENOM->Index] ="";

		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportDocPrihNakl::cxButtonSynhroClick(TObject *Sender)
{
if (IdKlient==0)
	{
	ShowMessage("Необходимо выбрать поставщика!");
	return;
	}

if (TypeSearchcxComboBox->ItemIndex==0)
		{
		ShowMessage("Необходимо задать тип поиска номенклатуры!");
		return;
		}

TcxCustomDataController *dc = cxGrid1BandedTableView1->DataController;

dc->GotoFirst();
//while(!dc->IsEOF())
for (int i=0; i<dc->RowCount; i++)
	{
	AnsiString code=dc->Values[i][cxGrid1BandedTableView1CODENOM->Index];
		IDMSprImportNom * dm_import_nom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprImportNom.1",IID_IDMSprImportNom,
													(void**)&dm_import_nom);
		dm_import_nom->Init(InterfaceMainObject,InterfaceImpl);
	__int64 id_nom=0;

	if (TypeSearchcxComboBox->ItemIndex==1)
		{
		if (StrToInt(CodeNomcxSpinEdit->Text)!=0)
			{ //ищем по коду
			id_nom=dm_import_nom->FindNomPoCodu(IdKlient,code);
			}
		}

	if (TypeSearchcxComboBox->ItemIndex==2)
		{
		if(StrToInt(NameNomcxSpinEdit->Text)!=0)
			{//ищем по наименованию
			UnicodeString name_n=dc->Values[i][cxGrid1BandedTableView1NAMENOMPOST->Index];

			//name_n="Мобильный телефон Explay B200 Чёрный";
			//ShowMessage("Длина-"+IntToStr(name_n.Length())+" "+name_n );
			id_nom=dm_import_nom->FindNomPoName(IdKlient,name_n);
			}
		}

	//по артикулу
	if (TypeSearchcxComboBox->ItemIndex==3)
		{
		if(StrToInt(ArtNomcxSpinEdit->Text)!=0)
			{//ищем по артикулу
			id_nom=dm_import_nom->FindNomPoArtikulu(IdKlient,dc->Values[i][cxGrid1BandedTableView1ARTNOM->Index]);
			}
		}


	if(id_nom!=0)
		{
		dc->Values[i][cxGrid1BandedTableView1IDNOM->Index]=IntToStr(id_nom);
		IDMSprNom * dm_nom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&dm_nom);
		dm_nom->Init(InterfaceMainObject,InterfaceImpl);
		dm_nom->OpenElement(id_nom);
		dc->Values[i][cxGrid1BandedTableView1NAMENOM->Index]=dm_nom->ElementNAMENOM->AsString;
		dm_nom->kanRelease();
		}

	dm_import_nom->kanRelease();
	//dc->GotoNext();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportDocPrihNakl::cxButtonCreateDocClick(TObject *Sender)
{
if (IdInfBase==0)
	{
	ShowMessage("Необходимо выбрать информационную базу!");
	return;
	}

if (IdFirm==0)
	{
	ShowMessage("Необходимо выбрать фирму!");
	return;
	}

if (IdSklad==0)
	{
	ShowMessage("Необходимо выбрать склад!");
	return;
	}

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

IFormaDocPrihNakl * doc;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocPrihNakl.1",IID_IFormaDocPrihNakl,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceImpl);

try
	{
	doc->DM->NewDoc();
	doc->DM->DocAll->Edit();
	if (IdInfBase!=0)
		{
		doc->DM->DocAllIDBASE_GALLDOC->AsString=IdInfBase;
		doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=NameInfBasecxButtonEdit->Text;
		}
	if (IdFirm!=0)
		{
		doc->DM->DocAllIDFIRMDOC->AsString=IdFirm;
		doc->DM->DocAllNAMEFIRM->AsString=NameFirmcxButtonEdit->Text;
		}
	if (IdSklad!=0)
		{
		doc->DM->DocAllIDSKLDOC->AsString=IdSklad;
		doc->DM->DocAllNAMESKLAD->AsString=NameSkladcxButtonEdit->Text;
		}
	if (IdKlient!=0)
		{
		doc->DM->DocAllIDKLDOC->AsString=IdKlient;
		doc->DM->DocAllNAMEKLIENT->AsString=NameKlientcxButtonEdit->Text;
		}
	doc->DM->DocAll->Post();

	doc->UpdateForm();

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
				id_country = dm_spr_country->GetIdPoName(Trim(name_country));


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

		//используем только базовую единицу
		//новую не добавляем т.к. нет значения КФ
		doc->DM->DocT->Append();
		doc->DM->DocT->Edit();
		doc->DM->DocTIDNOMPRNT->AsString=id_nom;
		doc->DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
		doc->DM->DocTIDEDPRNT->AsString=dm_nom->ElementIDBASEDNOM->AsString;
		doc->DM->DocTNAMEED->AsString=dm_nom->BasEdNAMEED->AsString;
		doc->DM->DocTKOLPRNT->AsFloat=dc->Values[i][cxGrid1BandedTableView1KOL->Index];
		doc->DM->DocTKFPRNT->AsFloat=1;
		doc->DM->DocTPRICEPRNT->AsFloat=dc->Values[i][cxGrid1BandedTableView1PRICE->Index];
		doc->DM->DocTSUMPRNT->AsFloat=dc->Values[i][cxGrid1BandedTableView1SUM->Index];
		doc->DM->DocTRPRICE_DPRNT->AsFloat=dc->Values[i][cxGrid1BandedTableView1ROZNPRICE->Index];
		doc->DM->DocTRSUM_DPRNT->AsFloat=dc->Values[i][cxGrid1BandedTableView1ROZNSUM->Index];
		doc->DM->DocTGTDPART->AsString=Trim(dc->Values[i][cxGrid1BandedTableView1GTD->Index]);
		doc->DM->DocT->Post();
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

void __fastcall TFormaImportDocPrihNakl::ExternalCodcxCheckBoxPropertiesValidate(
	  TObject *Sender, Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
ShowMessage("Внимание! При установленном флаге новым номенклатурам будет присвоен код из документа.");
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportDocPrihNakl::ExternalBarCodecxCheckBoxPropertiesValidate(
	  TObject *Sender, Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
ShowMessage("Внимание! При установленном флаге новым единицам будет присвоен штрих код из документа.");
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportDocPrihNakl::NameGrpNomcxButtonEditPropertiesButtonClick(
	  TObject *Sender, int AButtonIndex)
{
ViborGrpNom();
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportDocPrihNakl::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("ImportDocInExcel");
}
//---------------------------------------------------------------------------


void __fastcall TFormaImportDocPrihNakl::ReadShtrihCodEvent(int number, UnicodeString sh)
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
	dc->Values[row][cxGrid1BandedTableView1NAMENOM->Index] =
							dm_nom->ElementNAMENOM->AsString;
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


void __fastcall TFormaImportDocPrihNakl::cxButtonDelStringClick(TObject *Sender)
{
//удалим текущую строку

TcxCustomDataController *dc = cxGrid1BandedTableView1->DataController;
dc->DeleteFocused();
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportDocPrihNakl::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaImportDocPrihNakl::cxButtonCreateDocRevClick(TObject *Sender)

{
if (IdInfBase==0)
	{
	ShowMessage("Необходимо выбрать информационную базу!");
	return;
	}

if (IdFirm==0)
	{
	ShowMessage("Необходимо выбрать фирму!");
	return;
	}

if (IdSklad==0)
	{
	ShowMessage("Необходимо выбрать склад!");
	return;
	}

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

IFormaDocRev * doc;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRev.1",IID_IFormaDocRev,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceImpl);

try
	{
	doc->DM->NewDoc();
	doc->DM->DocAll->Edit();
	if (IdInfBase!=0)
		{
		doc->DM->DocAllIDBASE_GALLDOC->AsString=IdInfBase;
		doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=NameInfBasecxButtonEdit->Text;
		}
	if (IdFirm!=0)
		{
		doc->DM->DocAllIDFIRMDOC->AsString=IdFirm;
		doc->DM->DocAllNAMEFIRM->AsString=NameFirmcxButtonEdit->Text;
		}
	if (IdSklad!=0)
		{
		doc->DM->DocAllIDSKLDOC->AsString=IdSklad;
		doc->DM->DocAllNAMESKLAD->AsString=NameSkladcxButtonEdit->Text;
		}

	doc->DM->DocAll->Post();

	doc->UpdateForm();

	TcxCustomDataController *dc = cxGrid1BandedTableView1->DataController;
	dc->GotoFirst();
	for (int i=0; i<dc->RowCount; i++)
		{
		AnsiString code=dc->Values[i][cxGrid1BandedTableView1CODENOM->Index];
		__int64 id_nom=glStrToInt64(dc->Values[i][cxGrid1BandedTableView1IDNOM->Index]);

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
			if (IdFirm!=0)
				{
				dm_nom->ElementIDFIRMNOM->AsString=IdFirm;
				}

			if (ExternalCodcxCheckBox->Checked==true)
				{
				dm_nom->ElementCODENOM->AsInteger=StrToInt(dc->Values[i][cxGrid1BandedTableView1CODENOM->Index]);
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
				text_error=text_error+" Номенклатура: "+dc->Values[i][cxGrid1BandedTableView1NAMENOMPOST->Index];
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

		//используем только базовую единицу
		//новую не добавляем т.к. нет значения КФ
		doc->DM->DocT->Append();
		doc->DM->DocT->Edit();
		doc->DM->DocTIDNOM_DREVT->AsString=id_nom;
		doc->DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
		doc->DM->DocTIDED_DREVT->AsString=dm_nom->ElementIDBASEDNOM->AsString;
		doc->DM->DocTNAMEED->AsString=dm_nom->BasEdNAMEED->AsString;
		doc->DM->DocTKOL_DREVT->AsFloat=dc->Values[i][cxGrid1BandedTableView1KOL->Index];
		doc->DM->DocTKF_DREVT->AsFloat=1;
		doc->DM->DocTRPRICE_DREVT->AsFloat=dc->Values[i][cxGrid1BandedTableView1ROZNPRICE->Index];
		doc->DM->DocTRSUM_DREVT->AsFloat=dc->Values[i][cxGrid1BandedTableView1ROZNSUM->Index];
		doc->DM->DocT->Post();
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

void __fastcall TFormaImportDocPrihNakl::FormActivate(TObject *Sender)
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

void __fastcall TFormaImportDocPrihNakl::FormDeactivate(TObject *Sender)
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
void TFormaImportDocPrihNakl::ViborNomFind(void)
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
void __fastcall TFormaImportDocPrihNakl::EndViborNomFind(void)
{
TcxCustomDataController *dc = cxGrid1BandedTableView1->DataController;
int row=cxGrid1BandedTableView1->Controller->FocusedRowIndex;

	dc->Values[row][cxGrid1BandedTableView1IDNOM->Index] =
							FormaSprNomFind->DM->TableIDNOM->AsString;;
	dc->Values[row][cxGrid1BandedTableView1NAMENOM->Index] =
							FormaSprNomFind->DM->TableNAMENOM->AsString;
	dc->Values[row][cxGrid1BandedTableView1CODENOM->Index] =
							FormaSprNomFind->DM->TableCODENOM->AsString;
	dc->Values[row][cxGrid1BandedTableView1ARTNOM->Index] =
							FormaSprNomFind->DM->TableARTNOM->AsString;
	dc->Values[row][cxGrid1BandedTableView1BARCODE->Index] =
							FormaSprNomFind->DM->TableSHED->AsString;


}
//----------------------------------------------------------------------------


void __fastcall TFormaImportDocPrihNakl::ToolButtonNoAddNomInSprClick(TObject *Sender)

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

void __fastcall TFormaImportDocPrihNakl::ToolButtonAddNewNomClick(TObject *Sender)

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
void __fastcall TFormaImportDocPrihNakl::cxButtonCreateDocRegOtchetPostClick(TObject *Sender)

{
if (IdInfBase==0)
	{
	ShowMessage("Необходимо выбрать информационную базу!");
	return;
	}

if (IdFirm==0)
	{
	ShowMessage("Необходимо выбрать фирму!");
	return;
	}

if (IdSklad==0)
	{
	ShowMessage("Необходимо выбрать склад!");
	return;
	}

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

IFormaDocRegOtchetPost * doc;
InterfaceGlobalCom->kanCreateObject(ProgId_FormaDocRegOtchetPost,IID_IFormaDocRegOtchetPost,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceImpl);

try
	{
	doc->DM->NewDoc();
	doc->DM->DocAll->Edit();
	if (IdInfBase!=0)
		{
		doc->DM->DocAllIDBASE_GALLDOC->AsString=IdInfBase;
		doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=NameInfBasecxButtonEdit->Text;
		}

	doc->DM->DocAll->Post();

	doc->UpdateForm();

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
				id_country = dm_spr_country->GetIdPoName(Trim(name_country));


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

		//используем только базовую единицу
		//новую не добавляем т.к. нет значения КФ
		doc->DM->DocT->Append();
		doc->DM->DocT->Edit();
		if (IdFirm!=0)
			{
			doc->DM->DocTIDFIRM_DRG_OTCHPOSTT->AsString=IdFirm;
			doc->DM->DocTNAMEFIRM->AsString=NameFirmcxButtonEdit->Text;
			}
		if (IdSklad!=0)
			{
			doc->DM->DocTIDSKLAD_DRG_OTCHPOSTT->AsString=IdSklad;
			doc->DM->DocTNAMESKLAD->AsString=NameSkladcxButtonEdit->Text;
			}
		if (IdKlient!=0)
			{
			doc->DM->DocTIDPOST_DRG_OTCHPOSTT->AsString=IdKlient;
			doc->DM->DocTNAMEKLIENT->AsString=NameKlientcxButtonEdit->Text;
			}
		doc->DM->DocTIDNOM_DRG_OTCHPOSTT->AsString=id_nom;
		doc->DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
		doc->DM->DocTKOL_DRG_OTCHPOSTT->AsFloat=dc->Values[i][cxGrid1BandedTableView1KOL->Index];
		doc->DM->DocTSUM_DRG_OTCHPOSTT->AsFloat=dc->Values[i][cxGrid1BandedTableView1SUM->Index];
		doc->DM->DocT->Post();
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

void __fastcall TFormaImportDocPrihNakl::cxButton1Click(TObject *Sender)
{
ZapolnitREM_FormaDocRegOtchetPost();

}
//---------------------------------------------------------------------------

//выбор документа из полного журнала
void TFormaImportDocPrihNakl::ViborDocGurAllDoc(void)
{
if (FormaGurAllDoc==0)
	{
	InterfaceGlobalCom->kanCreateObject(ProgId_FormaGurAllDoc,IID_IFormaGurAllDoc,
													(void**)&FormaGurAllDoc);
	FormaGurAllDoc->Init(InterfaceMainObject,InterfaceImpl);
	FormaGurAllDoc->NumberProcVibor=ER_GurAllDoc;
	FormaGurAllDoc->Vibor=true;
	}

}
//----------------------------------------------------------------------------
void TFormaImportDocPrihNakl::EndViborDocGurAllDoc(void)
{

	   VibDocId=glStrToInt64(FormaGurAllDoc->DM->TableIDDOC->AsString);
	   VibDoccxButtonEdit->Text=glGetNameDoc(FormaGurAllDoc->DM->TableTDOC->AsString)+" №"+
							FormaGurAllDoc->DM->TablePREFIKS_NUM_GALLDOC->AsString+FormaGurAllDoc->DM->TableNUMDOC->AsString+
							" от "+FormaGurAllDoc->DM->TablePOSDOC->AsString;


}
//----------------------------------------------------------------------------
void __fastcall TFormaImportDocPrihNakl::ToolButtonZapolnitRealClick(TObject *Sender)

{
ZapolnitFormaDocReal();
}
//---------------------------------------------------------------------------
void TFormaImportDocPrihNakl::ZapolnitREM_FormaDocRegOtchetPost(void)
{
if (IdInfBase==0)
	{
	ShowMessage("Необходимо выбрать информационную базу!");
	return;
	}

if (IdFirm==0)
	{
	ShowMessage("Необходимо выбрать фирму!");
	return;
	}

if (IdSklad==0)
	{
	ShowMessage("Необходимо выбрать склад!");
	return;
	}

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

IREM_FormaDocRegOtchetPost * doc;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocRegOtchetPost,IID_IREM_FormaDocRegOtchetPost,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceImpl);

try
	{
	doc->DM->NewDoc();
	doc->DM->DocAll->Edit();
	if (IdInfBase!=0)
		{
		doc->DM->DocAllIDBASE_REM_GALLDOC->AsString=IdInfBase;
		doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=NameInfBasecxButtonEdit->Text;
		}

	doc->DM->DocAll->Post();

	doc->UpdateForm();

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
				id_country = dm_spr_country->GetIdPoName(Trim(name_country));


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

		//используем только базовую единицу
		//новую не добавляем т.к. нет значения КФ
		doc->DM->DocT->Append();
		doc->DM->DocT->Edit();
		if (IdFirm!=0)
			{
			doc->DM->DocTIDFIRM_REM_DRG_OTCHPOSTT->AsString=IdFirm;
			doc->DM->DocTNAMEFIRM->AsString=NameFirmcxButtonEdit->Text;
			}
		if (IdSklad!=0)
			{
			doc->DM->DocTIDSKLAD_REM_DRG_OTCHPOSTT->AsString=IdSklad;
			doc->DM->DocTNAMESKLAD->AsString=NameSkladcxButtonEdit->Text;
			}
		if (IdKlient!=0)
			{
			doc->DM->DocTIDPOST_REM_DRG_OTCHPOSTT->AsString=IdKlient;
			doc->DM->DocTNAMEKLIENT->AsString=NameKlientcxButtonEdit->Text;
			}
		doc->DM->DocTIDNOM_REM_DRG_OTCHPOSTT->AsString=id_nom;
		doc->DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
		doc->DM->DocTKOL_REM_DRG_OTCHPOSTT->AsFloat=dc->Values[i][cxGrid1BandedTableView1KOL->Index];
		doc->DM->DocTSUM_REM_DRG_OTCHPOSTT->AsFloat=dc->Values[i][cxGrid1BandedTableView1SUM->Index];
		doc->DM->DocT->Post();
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
//-------------------------------------------------------------------------
void TFormaImportDocPrihNakl::ZapolnitFormaDocReal(void)
{
if (VibDocId==0)
	{
	ShowMessage("Необходимо выбрать документ, который заполнять!");
	return;
	}



AnsiString text_error="";

IFormaDocReal * doc;
InterfaceGlobalCom->kanCreateObject(ProgId_FormaDocReal,IID_IFormaDocReal,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceImpl);


doc->DM->OpenDoc(VibDocId);


if (glStrToInt64(doc->DM->DocAllIDDOC->AsString) != VibDocId &&  glStrToInt64(doc->DM->DocAllIDDOC->AsString) > 0)
	{
	ShowMessage("Не удалось открыть выбранный документ!");
	return;
	}


	IDMSprNom *dm_nom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&dm_nom);
		dm_nom->Init(InterfaceMainObject,InterfaceImpl);

try
	{

	TcxCustomDataController *dc = cxGrid1BandedTableView1->DataController;
	dc->GotoFirst();
	for (int i=0; i<dc->RowCount; i++)
		{
		AnsiString code=dc->Values[i][1];
		__int64 id_nom=glStrToInt64(dc->Values[i][0]);

		if (id_nom>0 && Trim(dc->Values[i][cxGrid1BandedTableView1ARTNOM->Index]) !="")
			{
			dm_nom->OpenElement(id_nom);

			bool est=false;

			doc->DM->DocT->First();
			while(!doc->DM->DocT->Eof)
				{
				if (glStrToInt64(doc->DM->DocTIDNOMREAT->AsString) == id_nom)
					{
					est=true;

					double sum_str= doc->DM->DocTSUMREAT->AsFloat;
					double kol=dc->Values[i][cxGrid1BandedTableView1KOL->Index];
					if (kol==0) kol=1;

					doc->DM->DocT->Edit();
					doc->DM->DocTKOLREAT->AsFloat= doc->DM->DocTKOLREAT->AsFloat+kol;
					doc->DM->DocTSUMREAT->AsFloat=sum_str+dc->Values[i][cxGrid1BandedTableView1SUM->Index];
					doc->DM->DocT->Post();

					doc->DM->DocT->Edit();
					doc->DM->DocTPRICEREAT->AsFloat= doc->DM->DocTSUMREAT->AsFloat / doc->DM->DocTKOLREAT->AsFloat;
					doc->DM->DocT->Post();

					doc->DM->DocT->Edit();
					doc->DM->DocTSUMREAT->AsFloat=sum_str+dc->Values[i][cxGrid1BandedTableView1SUM->Index];
					doc->DM->DocT->Post();

					break;
					}


				doc->DM->DocT->Next();
				}
			if (est==false)
				{
					doc->DM->DocT->Append();
					doc->DM->DocT->Edit();
					doc->DM->DocTIDNOMREAT->AsString=id_nom;
					doc->DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
					doc->DM->DocTIDEDREAT->AsString=dm_nom->ElementIDBASEDNOM->AsString;
					doc->DM->DocTNAMEED->AsString=dm_nom->BasEdNAMEED->AsString;
					double kol=dc->Values[i][cxGrid1BandedTableView1KOL->Index];
					if (kol==0) kol=1;
					doc->DM->DocTKOLREAT->AsFloat=kol;
					doc->DM->DocTKFREAT->AsFloat=1;
					doc->DM->DocTPRICEREAT->AsFloat=dc->Values[i][cxGrid1BandedTableView1PRICE->Index];
					doc->DM->DocTSUMREAT->AsFloat=dc->Values[i][cxGrid1BandedTableView1SUM->Index];
					doc->DM->DocT->Post();
				}
			}
		}
	}
catch(Exception &exception)
		{
		ShowMessage(exception.Message);
		}


dm_nom->kanRelease();


}
//-----------------------------------------------------------------------------
void __fastcall TFormaImportDocPrihNakl::VibDoccxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborDocGurAllDoc();
}
//---------------------------------------------------------------------------

