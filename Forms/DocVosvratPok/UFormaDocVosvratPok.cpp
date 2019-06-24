//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop


#include "UFormaDocVosvratPok.h"
#include "IDMSprPrice.h"
#include "IDMSprOborud.h"
#include "IFiskReg.h"
#include "IFormaDocRKORozn.h"
#include "IFormaDocRKO.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IDMQueryRead.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtonEdit"
#pragma link "cxCalc"
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
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxContainer"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCalendar"
#pragma link "cxLabel"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaDocVosvratPok::TFormaDocVosvratPok(TComponent* Owner)
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
bool TFormaDocVosvratPok::Init(void)
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


InterfaceGlobalCom->kanCreateObject("Oberon.DMDocVosvratPok.1",IID_IDMDocVosvratPok,
							(void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;
DBTextFNameUser->DataSource=DM->DataSourceDocAll;

NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameDogcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameProjectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameBusinessOpercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PrefiksNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;

DescrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;

KlientNameStrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
KlientAdrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
KlientPhonecxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
PassportcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
PrichinacxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NumDocKlientcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
PosDocKlientcxDBDateEdit->DataBinding->DataSource=DM->DataSourceDoc;
NumDocSalecxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
PosDocSalecxDBDateEdit->DataBinding->DataSource=DM->DataSourceDoc;


DocOsncxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocOsn;

Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи
VibTovarId=0;
VibTovarIdGrp=0;
ActionOperation=aoNO;

flObrabatChangeTypePrice=false;
flObrabatChangeRoznTypePrice=false;
flObrabatChangeOperation=false;

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice, (void**)&DMSprTypePrice);
DMSprTypePrice->Init(InterfaceMainObject,InterfaceImpl);

DMSprTypePrice->OpenTable();
TypePriceComboBox->Properties->Items->Clear();
TypePriceComboBox->Properties->Items->Add("Не задан");
DMSprTypePrice->Table->First();
while (!DMSprTypePrice->Table->Eof)
        {
		TypePriceComboBox->Properties->Items->Add(DMSprTypePrice->TableNAME_TPRICE->AsString);
        DMSprTypePrice->Table->Next();
        }

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice,
									 (void**)&DMSprRTypePrice);
DMSprRTypePrice->Init(InterfaceMainObject,InterfaceImpl);

DMSprRTypePrice->OpenTable();
TypeRPriceComboBox->Properties->Items->Clear();
TypeRPriceComboBox->Properties->Items->Add("Не задан");
DMSprRTypePrice->Table->First();
while (!DMSprRTypePrice->Table->Eof)
        {
		TypeRPriceComboBox->Properties->Items->Add(DMSprRTypePrice->TableNAME_TPRICE->AsString);
		DMSprRTypePrice->Table->Next();
		}

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaDocVosvratPokImpl),false);
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
DM_Connection->GetPrivForm(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TFormaDocVosvratPok::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void TFormaDocVosvratPok::UpdateForm(void)
{

Prosmotr=DM->Prosmotr;
if (Prosmotr==true)
		{
		ProsmotrLabel->Visible=true;
		cxGrid1DBTableView1->OptionsData->Editing=false;
        }
else
        {
		ProsmotrLabel->Visible=false;
		cxGrid1DBTableView1->OptionsData->Editing=true;
		}

flObrabatChangeTypePrice=false;
flObrabatChangeRoznTypePrice=false;
flObrabatChangeOperation=false;
TypePriceComboBox->ItemIndex=DMSprTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDTPRICE_DVPOK->AsString));
TypeRPriceComboBox->ItemIndex=DMSprRTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDRTPRICE_DVPOK->AsString));
OperComboBox->ItemIndex=DM->DocOPER_DVPOK->AsInteger;
flObrabatChangeTypePrice=true;
flObrabatChangeRoznTypePrice=true;
flObrabatChangeOperation=true;
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocVosvratPok::FormClose(TObject *Sender,
      TCloseAction &Action)
{
flObrabatChangeTypePrice=false;
flObrabatChangeRoznTypePrice=false;
flObrabatChangeOperation=false;

if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(Ed)Ed->kanRelease();
if(Nom)Nom->kanRelease();
if(Firma)Firma->kanRelease();
if(Sklad)Sklad->kanRelease();
if(Klient)Klient->kanRelease();
if(SpisokBusinessOper)SpisokBusinessOper->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();
if(FormaGurAllDoc)FormaGurAllDoc->kanRelease();

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

DMTableExtPrintForm->kanRelease();
DM->kanRelease();
DMSprTypePrice->kanRelease();
DMSprRTypePrice->kanRelease();

Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}

}
//---------------------------------------------------------------------------
void __fastcall TFormaDocVosvratPok::FormActivate(TObject *Sender)
{
//if (glScaner) glScaner->ReadSh=ReadShtrihCodEvent;
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPok::FormDeactivate(TObject *Sender)
{
//if(glScaner) glScaner->ReadSh=0;
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocVosvratPok::ReadShtrihCodEvent(int number, UnicodeString sh)
{
AnsiString s=sh;
//надо учитывать что считан может быть и весовой код
IDMSprNom * DMSprNom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&DMSprNom);
DMSprNom->Init(InterfaceMainObject,InterfaceImpl);
int id_nom=DMSprNom->FindPoShtrihCodu(s);

if (id_nom!=0)
        {
		DMSprNom->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_DVPOK->AsString);
        DMSprNom->OpenElement(id_nom);
        DM->AddDocNewString();

        DM->DocT->Edit();
		DM->DocTIDNOM_DVPOKT->AsString=DMSprNom->ElementIDNOM->AsString;
		DM->DocTNAMENOM->AsString=DMSprNom->ElementNAMENOM->AsString;
		DM->DocTKOL_DVPOKT->AsInteger=1;
		DM->DocTIDED_DVPOKT->AsString=DMSprNom->ElementIDOSNEDNOM->AsString;
        DM->DocTNAMEED->AsString=DMSprNom->OsnEdNAMEED->AsString;
		DM->DocTKF_DVPOKT->AsFloat=DMSprNom->OsnEdKFED->AsFloat;
		//DM->DocTPRICE_DVPOKT->AsFloat=DMSprNom->ElementZNACH_PRICE->AsFloat
		//						*DM->DocTKF_DVPOKT->AsFloat;
        DM->DocT->Post();

		cxGrid1->SetFocus();
		//DBGrid1->SelectedField=DM->DocTKOL_DVPOKT;

        }
else
        {
        ShowMessage("Товар со штрих кодом "+s+" не найден!");
        return;
        }

DMSprNom->kanRelease();

UpdateForm();


}
//---------------------------------------------------------------
int TFormaDocVosvratPok::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==Tovar)
        {
		if (type_event==1)
                {
                if (ActionOperation==aoAddNewString)
						{
                        DM->AddDocNewString();
                        }
                DM->DocT->Edit();
				DM->DocTIDNOM_DVPOKT->AsString=Nom->DM->ElementIDNOM->AsString;
				DM->DocTNAMENOM->AsString=Nom->DM->ElementNAMENOM->AsString;
				DM->DocTKOL_DVPOKT->AsInteger=1;
				DM->DocTIDED_DVPOKT->AsString=Nom->DM->ElementIDOSNEDNOM->AsString;
                DM->DocTNAMEED->AsString=Nom->DM->OsnEdNAMEED->AsString;
				DM->DocTKF_DVPOKT->AsFloat=Nom->DM->OsnEdKFED->AsFloat;
			   //	DM->DocTPRICE_DVPOKT->AsFloat=Nom->DM->ElementZNACH_PRICE->AsFloat;
                DM->DocT->Post();
				//DBGrid1->SelectedField=DM->DocTKOL_DVPOKT;
				VibTovarId=glStrToInt64(Nom->DM->ElementIDNOM->AsString);
				VibTovarIdGrp=glStrToInt64(Nom->DM->ElementIDGRPNOM->AsString);
                }
		Nom=0;
		cxGrid1->SetFocus();
		cxGrid1DBTableView1KOL_DVPOKT->Selected=true;
        }

if (number_procedure_end==PodborNom)
        {
		if (type_event==1)
                {
                DM->IsmSum=false;
                DM->AddDocNewString();
                DM->DocT->Edit();
				DM->DocTIDNOM_DVPOKT->AsString=Nom->DM->ElementIDNOM->AsString;
                DM->DocTNAMENOM->AsString=Nom->DM->ElementNAMENOM->AsString;
				DM->DocTKOL_DVPOKT->AsFloat=Nom->FormaPodboraNom->Kol;
			  //	DM->DocTPRICE_DVPOKT->AsFloat=Nom->FormaPodboraNom->Price;

				DM->DocTIDED_DVPOKT->AsString=Nom->FormaPodboraNom->IdEd;
                DM->DocTNAMEED->AsString=Nom->FormaPodboraNom->NameEd;
				DM->DocTKF_DVPOKT->AsFloat=Nom->FormaPodboraNom->KFEd;

				DM->DocTSUM_DVPOKT->AsFloat=Nom->FormaPodboraNom->Summa;

                DM->DocT->Post();
			   //	DBGrid1->SelectedField=DM->DocTKOL_DVPOKT;
				VibTovarId=glStrToInt64(Nom->DM->ElementIDNOM->AsString);
                VibTovarIdGrp=glStrToInt64(Nom->DM->ElementIDGRPNOM->AsString);
                DM->IsmSum=true;
                }
        else
                {
                Nom=0;
				EditRekvisit=NO;
                ActionOperation=aoNO;
                }
        }


if (number_procedure_end==Edinica)
        {
		if (type_event==1)
				{
                DM->DocT->Edit();
				DM->DocTIDED_DVPOKT->AsString=Ed->DM->ElementIDED->AsString;
				DM->DocTNAMEED->AsString=Ed->DM->Element->FieldByName("NAMEED")->AsString;
				DM->DocTKF_DVPOKT->AsFloat=Ed->DM->ElementKFED->AsFloat;
                DM->DocT->Post();
                }
		Ed=0;
		cxGrid1->SetFocus();
		cxGrid1DBTableView1PRICE_DVPOKT->Selected=true;
        }

if (number_procedure_end==FirmaRekvisit)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDFIRMDOC->AsString=Firma->DM->ElementIDFIRM->AsString;
				DM->DocAllNAMEFIRM->AsString=Firma->DM->Element->FieldByName("NAMEFIRM")->AsString;
                DM->DocAll->Post();
                }
		Firma=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

if (number_procedure_end==SkladRekvisit)
        {
		if (type_event==1)
				{
                DM->DocAll->Edit();
				DM->DocAllIDSKLDOC->AsString=Sklad->DM->ElementIDSKLAD->AsString;
				DM->DocAllNAMESKLAD->AsString=Sklad->DM->Element->FieldByName("NAMESKLAD")->AsString;
                DM->DocAll->Post();
                }
		Sklad=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

if (number_procedure_end==KlientRekvisit)
        {
		if (type_event==1)
				{
                DM->DocAll->Edit();
				DM->DocAllIDKLDOC->AsString=Klient->DM->ElementIDKLIENT->AsString;
				DM->DocAllNAMEKLIENT->AsString=Klient->DM->Element->FieldByName("NAMEKLIENT")->AsString;
                DM->DocAll->Post();
                }
		Klient=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

if (number_procedure_end==ViborInfBase)
        {
		if (type_event==1)
				{
                DM->DocAll->Edit();
				DM->DocAllIDBASE_GALLDOC->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsString;
                DM->DocAllNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
                DM->DocAll->Post();
                }
		FormaSpiskaSprInfBase=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

if (number_procedure_end==ViborDogovor)
        {
		if(type_event==1)
				{
                DM->DocAll->Edit();
				DM->DocAllIDDOGDOC->AsString=FormaSpiskaSprDogovor->DM->TableID_SDOG->AsString;
                DM->DocAllNAME_SDOG->AsString=FormaSpiskaSprDogovor->DM->TableNAME_SDOG->AsString;
                DM->DocAll->Post();
                }
		FormaSpiskaSprDogovor=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
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

if (number_procedure_end==ER_ViborDocOsn)
		{
		if (type_event==1)
				{
				EndViborDocOsn()  ;
				}
		FormaGurAllDoc=0;
		}

if (number_procedure_end!=PodborNom)
        {
        ActionOperation=aoNO;
		}
return -1;
}
//---------------------------------------------------------------------------

//----------------------------------------------------------------------------
void  TFormaDocVosvratPok::OpenFSSprNom()
{
if(Prosmotr==true) return;
if (Nom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&Nom);
		Nom->Init(InterfaceMainObject,InterfaceImpl);
		Nom->Vibor=true;
		Nom->NumberProcVibor=Tovar;
		Nom->DM->IdTypePrice=glStrToInt64(DM->DocIDRTPRICE_DVPOK->AsString);
//        Nom->SpisokTypePrice->ItemIndex=Nom->DM->GetIndexTypePrice()-1;
//		Nom->HintLabel->Caption="Выберите номенклатуру для документа Возврат от покупателя №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		Nom->IdNom=glStrToInt64(DM->DocTIDNOM_DVPOKT->AsString);
		Nom->UpdateForm();
        }
}
//----------------------------------------------------------------------------
void TFormaDocVosvratPok:: OpenFSSprEd()
{
if(Prosmotr==true) return;
if (Ed==NULL)
        {

		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&Ed);
		Ed->Init(InterfaceMainObject,InterfaceImpl);
		Ed->Vibor=true;
		Ed->NumberProcVibor=Edinica;
		Ed->IdNom=glStrToInt64(DM->DocTIDNOM_DVPOKT->AsString);
		Ed->DM->OpenTable(DM->DocTIDNOM_DVPOKT->AsInteger);
//        Ed->LabelNom->Caption="Единицы номенклатуры: "+DM->DocTNAMENOM->AsString;
//		Ed->HintLabel->Caption="Выберите единицу номенклатуры для документа Приходная накладная №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;


        }
}

//----------------------------------------------------------------------------





void    TFormaDocVosvratPok::OpenFormSpiskaSprFirm(void)
{
if(Prosmotr==true) return;
if (Firma==NULL)
        {

		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&Firma);
		Firma->Init(InterfaceMainObject,InterfaceImpl);
		Firma->Vibor=true;
		Firma->NumberProcVibor=FirmaRekvisit;
		Firma->DM->OpenTable();
//		Firma->HintLabel->Caption="Выберите фирму для документа Возврат от покупателя №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
        }

}
//---------------------------------------------------------------------------
void  TFormaDocVosvratPok::OpenFormSpiskaSprSklad(void)
{
if(Prosmotr==true) return;
if (Sklad==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&Sklad);
		Sklad->Init(InterfaceMainObject,InterfaceImpl);
		Sklad->Vibor=true;
		Sklad->NumberProcVibor=SkladRekvisit;
        Sklad->DM->OpenTable();
//		Sklad->HintLabel->Caption="Выберите склад для документа Возврат от покупателя №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;


        }

}
//---------------------------------------------------------------------------
void  TFormaDocVosvratPok::OpenFormSpiskaSprKlient(void)
{
if(Prosmotr==true) return;
if (Klient==NULL)
		{

		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&Klient);
		Klient->Init(InterfaceMainObject,InterfaceImpl);
		Klient->Vibor=true;
		Klient->NumberProcVibor=KlientRekvisit;
//		Klient->HintLabel->Caption="Выберите поставщика для документа Возврат от покупателя №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		Klient->IdKlient=glStrToInt64(DM->DocAllIDKLDOC->AsString);
		Klient->UpdateForm();
		}


}
//-----------------------------------------------------------------------------





//---------------------------------------------------------------------------
void TFormaDocVosvratPok::OpenPrintForm(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;


//шапка
PrintForm->SS->EndUpdate();
OutputZagolovokReport(PrintForm);

//таблица

DM->DocT->First();
while(!DM->DocT->Eof)
        {

        OutputString(PrintForm);numRow++; porNumStr++;

        DM->DocT->Next();
        }

OutputPodavalReport(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();
}
//---------------------------------------------------------------------------
void TFormaDocVosvratPok::OutputZagolovokReport(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numRow=1;
numCol=2;


prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
prForm->SS->RowsAutoHeight=true;
        TcxSSHeader *cHeader;

        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 10;
        cHeader->Size[2] = 40;
        cHeader->Size[3] = 300;
        cHeader->Size[4] = 60;
        cHeader->Size[5] = 80;
        cHeader->Size[6] = 60;
        cHeader->Size[7] = 70;
		cHeader->Size[8] = 80;
IDMSprFirm *dm_firm;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&dm_firm);
		dm_firm->Init(InterfaceMainObject,InterfaceImpl);
dm_firm->OpenElement(glStrToInt64(DM->DocAllIDFIRMDOC->AsString));
cell = prForm->SS->ActiveSheet->GetCellObject(2, 1);
cell->Text=dm_firm->ElementFNAMEFIRM->AsString
		+", ИНН "+dm_firm->ElementINNFIRM->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Адрес: "+dm_firm->ElementPADRFIRM->AsString;
delete cell;
numRow++;

dm_firm->kanRelease();



cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Склад: "+DM->DocAllNAMESKLAD->AsString;
delete cell;
numRow++; numRow++;


cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="Возврат от покупателя №"+DM->DocAllNUMDOC->AsString+" от "
                +DateToStr(DM->DocAllPOSDOC->AsDateTime);
delete cell;
numRow++; numRow++;

IDMSprKlient * dm_klient;
		InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
													(void**)&dm_klient);
		dm_klient->Init(InterfaceMainObject,InterfaceImpl);
dm_klient->OpenElement(glStrToInt64(DM->DocAllIDKLDOC->AsString));

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Покупатель: "+dm_klient->ElementFNAME->AsString+", ИНН "+dm_klient->ElementINNKLIENT->AsString;
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Адрес: "+dm_klient->ElementADRKLIENT->AsString;
delete cell;
numRow++;

dm_klient->kanRelease();
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Основание: "+DM->DocDESCR_DVPOK->AsString;
delete cell;
numRow++;
numRow++;

//заголовок таблицы
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="№";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Наименование";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Кол-во";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Единица";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="К";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Цена";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Сумма";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;
}
//------------------------------------------------------------------------------
void TFormaDocVosvratPok::OutputString(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=2;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IntToStr(porNumStr);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTNAMENOM->AsString;
//cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTKOL_DVPOKT->AsString;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTNAMEED->AsString;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTKF_DVPOKT->AsFloat,ffFixed,10,3);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTRPRICE_DVPOKT->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTRSUM_DVPOKT->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
}


//------------------------------------------------------------------------------
void TFormaDocVosvratPok::OutputPodavalReport(TSheetEditor *prForm)
{
numRow++;
numCol=8;
TcxSSCellObject *cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="Всего: "+FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffFixed,10,2);
delete cell;
 numRow++;
numCol=8;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="Сумма НДС: 0.00 ";
delete cell;
numRow++;

numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haLEFT;
cell->Text="Всего наименований "+IntToStr(DM->DocT->RecordCount)+
                " на сумму "+FloatToStrF(DM->DocAllSUMDOC->AsFloat, ffFixed,10,2);
delete cell;
numRow++;

numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="("+glCurrencyPropis(DM->DocAllSUMDOC->AsFloat)+" )";
delete cell;
numRow++;

for (int i=2;i<=8;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(i, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        }
numRow++;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Сдал  __________________________ ";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="Принял  __________________________ ";
delete cell;
}
//---------------------------------------------------------------
//----------------------------------------------------------------------------


void __fastcall TFormaDocVosvratPok::ToolButtonPodborClick(TObject *Sender)
{
if(Prosmotr==true) return;
if (Nom==NULL)
        {

		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&Nom);
		Nom->Init(InterfaceMainObject,InterfaceImpl);
        Nom->Vibor=true;
		Nom->Podbor=true;
		Nom->NumberProcVibor=PodborNom;
		Nom->DM->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_DVPOK->AsString);
//		Nom->SpisokTypePrice->ItemIndex=Nom->DM->GetIndexTypePrice()-1;
//		Nom->HintLabel->Caption="Выберите номенклатуру для документа Приходная накладная №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
        Nom->UpdateForm();
        }
}
//---------------------------------------------------------------------------

void TFormaDocVosvratPok::OpenFormSpiskaSprInfBase(void)
{
if (Prosmotr==true) return;
if (DM->DocAllIDBASE_GALLDOC->ReadOnly==true) return;
if (FormaSpiskaSprInfBase==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInfBase.1",IID_IFormaSpiskaSprInfBase,
													(void**)&FormaSpiskaSprInfBase);
		FormaSpiskaSprInfBase->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprInfBase->Vibor=true;
		FormaSpiskaSprInfBase->NumberProcVibor=ViborInfBase;
		FormaSpiskaSprInfBase->DM->OpenTable();
        }
}
//---------------------------------------------------------------------



void __fastcall TFormaDocVosvratPok::NumberDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPok::FDateDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPok::DescrDBEditKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocVosvratPok::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocVosvratPok");
}
//---------------------------------------------------------------------------





void __fastcall TFormaDocVosvratPok::ToolButton5Click(TObject *Sender)
{
DM->DocT->Post();	
}
//---------------------------------------------------------------------------


void TFormaDocVosvratPok::OpenFormSpiskaSprDogovor(void)
{
if (DM->DocAllIDKLDOC->AsInteger==0)
        {
        ShowMessage("Выберите контрагента!");
        return;
        }

if (FormaSpiskaSprDogovor==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprDogovor.1",IID_IFormaSpiskaSprDogovor,
													(void**)&FormaSpiskaSprDogovor);
		FormaSpiskaSprDogovor->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprDogovor->IdKlient=glStrToInt64(DM->DocAllIDKLDOC->AsString);
        FormaSpiskaSprDogovor->Vibor=true;
		FormaSpiskaSprDogovor->DM->OpenTable(glStrToInt64(DM->DocAllIDKLDOC->AsString));
//		FormaSpiskaSprDogovor->LabelKlient->Caption="Контрагент: "+DM->DocAllNAMEKLIENT->AsString;
		FormaSpiskaSprDogovor->NumberProcVibor=ViborDogovor;
        }
}
//-----------------------------------------------------------------------------



void __fastcall TFormaDocVosvratPok::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if(Prosmotr==true) return;

        OpenFSSprNom();
        EditRekvisit=Tovar;

}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPok::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
	  TObject *Sender, int AButtonIndex)
{
if(Prosmotr==true) return;

		OpenFSSprEd();
		EditRekvisit=Edinica;

}
//---------------------------------------------------------------------------
//-----------------------------------------------------------------------------






void __fastcall TFormaDocVosvratPok::OperComboBoxPropertiesChange(
      TObject *Sender)
{
if (flObrabatChangeOperation==false) return;
DM->Doc->Edit();
DM->DocOPER_DVPOK->AsInteger=OperComboBox->ItemIndex;
DM->Doc->Post();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPok::TypePriceComboBoxPropertiesChange(
      TObject *Sender)
{
if(flObrabatChangeTypePrice==false) return;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
 if (Prosmotr==true)
		{
		UpdateForm();
		 return;
		}

if ( TypePriceComboBox->ItemIndex!=0)
		{
		DMSprTypePrice->Table->First();
		DMSprTypePrice->Table->MoveBy(TypePriceComboBox->ItemIndex-1);
		DM->Doc->Edit();
		DM->DocIDTPRICE_DVPOK->AsString=DMSprTypePrice->TableID_TPRICE->AsString;
		DM->Doc->Post();
		}
else
	{
	ShowMessage("Тип цен должен быть задан обязательно!");
	UpdateForm();
	return;
	}

//проверим есть ли строки
if(DM->DocT->RecordCount>0)
        {
		String V="В табличной части документа есть строки. Пересчитать цены?";
		String Z="Пересчитать цены?";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
				{
				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
				DM->DocT->First();
				while(!DM->DocT->Eof)
						{
						DM->DocT->Edit();
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDTPRICE_DVPOK->AsString),
											 glStrToInt64(DM->DocTIDNOM_DVPOKT->AsString));
						DM->DocTPRICE_DVPOKT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_DVPOKT->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				DMSprPrice->kanRelease();
				}
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPok::TypeRPriceComboBoxPropertiesChange(
      TObject *Sender)
{
if(flObrabatChangeRoznTypePrice==false) return;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
 if (Prosmotr==true)
		{
        UpdateForm();
		 return;
		}

if ( TypePriceComboBox->ItemIndex!=0)
		{
		DMSprRTypePrice->Table->First();
		DMSprRTypePrice->Table->MoveBy(TypeRPriceComboBox->ItemIndex-1);
		DM->Doc->Edit();
		DM->DocIDRTPRICE_DVPOK->AsString=DMSprRTypePrice->TableID_TPRICE->AsString;
		DM->Doc->Post();
		}
else
	{
	ShowMessage("Тип цен должен быть задан обязательно!");
	UpdateForm();
	return;
	}

//проверим есть ли строки
if(DM->DocT->RecordCount>0)
		{
		String V="В табличной части документа есть строки. Пересчитать цены?";
		String Z="Пересчитать цены?";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
				{
				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
				DM->DocT->First();
				while(!DM->DocT->Eof)
						{
						DM->DocT->Edit();
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDRTPRICE_DVPOK->AsString),
											 glStrToInt64(DM->DocTIDNOM_DVPOKT->AsString));
						DM->DocTRPRICE_DVPOKT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_DVPOKT->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				DMSprPrice->kanRelease();
				}
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPok::NameDogcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprDogovor();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPok::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprKlient();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocVosvratPok::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprSklad();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPok::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprFirm();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocVosvratPok::NmaeInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprInfBase();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------
void TFormaDocVosvratPok::CreateDocRashodNal(void)
{
IFormaDocRKORozn * forma_doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRKORozn.1",IID_IFormaDocRKORozn,
													(void**)&forma_doc);
		forma_doc->Init(InterfaceMainObject,InterfaceImpl);
if (!forma_doc) return;
forma_doc->DM->NewDoc();

forma_doc->DM->DocAll->Edit();
if(glStrToInt64(DM->DocAllIDFIRMDOC->AsString)!=0)
	{
	forma_doc->DM->DocAllIDFIRMDOC->AsString=DM->DocAllIDFIRMDOC->AsString;
	forma_doc->DM->DocAllNAMEFIRM->AsString=DM->DocAllNAMEFIRM->AsString;
	}
if(glStrToInt64(DM->DocAllIDKLDOC->AsString)!=0)
	{
	forma_doc->DM->DocAllIDKLDOC->AsString=DM->DocAllIDKLDOC->AsString;
	forma_doc->DM->DocAllNAMEKLIENT->AsString=DM->DocAllNAMEKLIENT->AsString;
	}
if(glStrToInt64(DM->DocAllIDDOGDOC->AsString)!=0)
	{
	forma_doc->DM->DocAllIDDOGDOC->AsString=DM->DocAllIDDOGDOC->AsString;
	forma_doc->DM->DocAllNAME_SDOG->AsString=DM->DocAllNAME_SDOG->AsString;
	}
forma_doc->DM->DocAllSUMDOC->AsFloat=DM->DocAllSUMDOC->AsFloat;
forma_doc->DM->DocAllIDDOCOSNDOC->AsString=DM->DocAllIDDOC->AsString;

forma_doc->DM->DocAll->Post();

forma_doc->DM->Doc->Edit();
forma_doc->DM->DocOSN_DRKOROZN->AsString="Возврат покупателя №"+
				DM->DocAllNUMDOC->AsString+" от "+
				DM->DocAllPOSDOC->AsString;

forma_doc->DM->Doc->Post();
forma_doc->UpdateForm();
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocVosvratPok::cxButtonCreateRKORoznClick(TObject *Sender)
{
CreateDocRashodNal();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPok::ActionAddStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
ActionOperation=aoAddNewString;
OpenFSSprNom();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPok::ActionDeleteStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
DM->DeleteStringDoc();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPok::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPok::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------



void __fastcall TFormaDocVosvratPok::OperComboBoxKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPok::DescrcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaDocVosvratPok::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaDocVosvratPok::RunExternalModule(__int64 id_module, int type_module)
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
//
//	//надо добавить класс TScriptDMDocRealRozn
//	//методы для работы с документом
//	scr_doc=new TScriptDMDocRealRozn();
//	scr_doc->AddClassesInScript(module);
//	//надо добавить текущий DM
//	scr_doc->DM=DM;
//	module->fsScript1->AddObject("TecDMDocRealRozn",scr_doc);
	}


//надо добавить переменные модуля, как минимум  IDDOC
module->SetInt64Variables("glIdDoc", glStrToInt64(DM->DocAllIDDOC->AsString));

module->ExecuteModule();

}
//---------------------------------------------------------------------------
void __fastcall TFormaDocVosvratPok::ActionCloseExecute(TObject *Sender)
{
		DM->DocAll->CancelUpdates();
		DM->Doc->CancelUpdates();
		DM->DocT->CancelUpdates();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPok::ActionOKExecute(TObject *Sender)
{
if(Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		if (DM->DvRegDoc()==true)
				{
				Close();
				}
		else
			{
			ShowMessage("Ошибка при проведении документа: "+DM->TextError);
			}
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPok::ActionDvRegExecute(TObject *Sender)
{
if(Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		if (DM->DvRegDoc()==true)
				{

				}
		else
			{
			ShowMessage("Ошибка при проведении документа: "+DM->TextError);
			}
		UpdateForm();
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPok::ActionSaveExecute(TObject *Sender)
{
if(Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		UpdateForm();
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPok::ActionPrintExecute(TObject *Sender)
{
OpenPrintForm() ;
}
//---------------------------------------------------------------------------
void TFormaDocVosvratPok::OpenFormSpiskaSprProject(void)
{
if (Prosmotr==true) return;
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
void __fastcall TFormaDocVosvratPok::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void TFormaDocVosvratPok::OpenFormSpiskaSprBusinessOper(void)
{
if (Prosmotr==true) return;
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
void __fastcall TFormaDocVosvratPok::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------
void __fastcall TFormaDocVosvratPok::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocAll->Edit();
		DM->DocAllIDBUSINOP_GALLDOC->Clear();
		DM->DocAll->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPok::NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocAll->Edit();
		DM->DocAllIDPROJECT_GALLDOC->Clear();
		DM->DocAll->Post();
		}break;
	}
}
//---------------------------------------------------------------------------
void TFormaDocVosvratPok::ViborDocOsn(void)
{

if (Prosmotr==true) return;
if (FormaGurAllDoc==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaGurAllDoc.1",IID_IFormaGurAllDoc,
													(void**)&FormaGurAllDoc);
		FormaGurAllDoc->Init(InterfaceMainObject,InterfaceImpl);
		FormaGurAllDoc->Vibor=true;
		FormaGurAllDoc->NumberProcVibor=ER_ViborDocOsn;
		}
}
//----------------------------------------------------------------------------
void TFormaDocVosvratPok::EndViborDocOsn(void)
{


				DM->DocAll->Edit();
				DM->DocAllIDDOCOSNDOC->AsString=FormaGurAllDoc->DM->TableIDDOC->AsString;
				DM->DocAll->Post();
				DM->OpenDocOsn();



}
//----------------------------------------------------------------------------
void __fastcall TFormaDocVosvratPok::DocOsncxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborDocOsn();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocAll->Edit();
		DM->DocAllIDDOCOSNDOC->Clear();
		DM->DocAll->Post();
		DM->OpenDocOsn();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPok::ToolButtonCreateDocRKOClick(TObject *Sender)

{
DM->SaveDoc();
//проверим а нет ли уже счета
IDMQueryRead * DMQueryRead;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&DMQueryRead);
DMQueryRead->Init(InterfaceMainObject,0);
DMQueryRead->pFIBQ->Close();
DMQueryRead->pFIBQ->SQL->Clear();
DMQueryRead->pFIBQ->SQL->Add("select IDDOC from GALLDOC where TDOC='RKO'");
DMQueryRead->pFIBQ->SQL->Add(" and galldoc.iddocosndoc='"+DM->DocAllIDDOC->AsString+"'");
DMQueryRead->pFIBQ->ExecQuery();

IFormaDocRKO* doc;
InterfaceGlobalCom->kanCreateObject(ProgId_FormaDocRKO,IID_IFormaDocRKO,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceImpl);
if (!doc) return;

if (DMQueryRead->pFIBQ->RecordCount!=0)
        {
		 //откроем документ
		doc->DM->OpenDoc(DMQueryRead->pFIBQ->FieldByName("IDDOC")->AsInt64);
		}
else
		{
//создадим документ
doc->DM->NewDoc();
doc->DM->DocAll->Edit();

doc->DM->DocAllIDDOCOSNDOC->AsString=DM->DocAllIDDOC->AsString;

doc->DM->DocAllIDBASE_GALLDOC->AsString=DM->DocAllIDBASE_GALLDOC->AsString;
doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=DM->DocAllNAME_SINFBASE_OBMEN->AsString;
doc->DM->DocAllIDFIRMDOC->AsString=DM->DocAllIDFIRMDOC->AsString;
doc->DM->DocAllNAMEFIRM->AsString=DM->DocAllNAMEFIRM->AsString;
doc->DM->DocAllIDKLDOC->AsString=DM->DocAllIDKLDOC->AsString;
doc->DM->DocAllNAMEKLIENT->AsString=DM->DocAllNAMEKLIENT->AsString;

doc->DM->DocAllSUMDOC->AsFloat=DM->DocAllSUMDOC->AsFloat;
doc->DM->DocAll->Post();

doc->DM->Doc->Edit();

doc->DM->DocVIDATRKO->AsString=DM->DocKLIENT_NAME_DVPOK->AsString;
doc->DM->DocOSNRKO->AsString="Возрат покупателя №"+DM->DocAllNUMDOC->AsString+
						" от "+ DM->DocAllPOSDOC->AsString;

doc->DM->DocDOCPOLRKO->AsString=DM->DocKLIENT_PASSPORT_DVPOK->AsString;
doc->DM->Doc->Post();
		}
doc->UpdateForm();

DMQueryRead->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocVosvratPok::PrefiksNumcxDBTextEditKeyDown(TObject *Sender,
          WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

