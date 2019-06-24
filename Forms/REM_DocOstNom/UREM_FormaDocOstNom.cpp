//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop



#include "UREM_FormaDocOstNom.h"

#include "IFormaElementaSprNom.h"
#include "IFormaElementaSprEd.h"
#include "IREM_FormaElementaSprHardware.h"

#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IAsyncExternalEvent.h"
#include "IObjectBarCode.h"
#include "IDMDocOstNom.h"
#include "IREM_DMSprGrpModel.h"
#include "IREM_DMSprModel.h"
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
#pragma link "cxCheckBox"
#pragma link "cxContainer"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCalendar"
#pragma link "cxLabel"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxPC"
#pragma link "cxGridBandedTableView"
#pragma link "cxGridDBBandedTableView"
#pragma link "cxLookAndFeels"
#pragma link "cxDBLabel"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TREM_FormaDocOstNom::TREM_FormaDocOstNom(TComponent* Owner)
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
bool TREM_FormaDocOstNom::Init(void)
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
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocOstNom,IID_IREM_DMDocOstNom, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;
DBTextFNameUser->DataSource=DM->DataSourceDocAll;

NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameProjectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameBusinessOpercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
cxDBLabelIDDoc->DataBinding->DataSource=DM->DataSourceDocAll;

PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;



Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи
VibTovarId=0;
VibTovarIdGrp=0;
ActionOperation=aoNO;

flObrabatChangeTypePrice=false;
flObrabatChangeRoznTypePrice=false;

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice,
			 (void**)&DMSprTypePrice);
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
//розничный тип цен

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice,
					(void**)&DMSprTypeRPrice);
DMSprTypeRPrice->Init(InterfaceMainObject,InterfaceImpl);
DMSprTypeRPrice->OpenTable();
TypeRPriceComboBox->Properties->Items->Clear();
TypeRPriceComboBox->Properties->Items->Add("Не задан");
DMSprTypeRPrice->Table->First();
while (!DMSprTypeRPrice->Table->Eof)
		{
		TypeRPriceComboBox->Properties->Items->Add(DMSprTypeRPrice->TableNAME_TPRICE->AsString);
		DMSprTypeRPrice->Table->Next();
		}


//заполним список внешних модулей

InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
						 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaDocOstNomImpl),false);
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

//----------------------------------------------------------------------------
void TREM_FormaDocOstNom::UpdateForm(void)
{

Prosmotr=DM->Prosmotr;
if (Prosmotr==true)
        {
        ProsmotrLabel->Visible=true;
        }
else
        {
        ProsmotrLabel->Visible=false;
		}

flObrabatChangeTypePrice=false;
flObrabatChangeRoznTypePrice=false;
TypePriceComboBox->ItemIndex=DMSprTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDTPRICE_REM_DOSN->AsString));
TypeRPriceComboBox->ItemIndex=DMSprTypeRPrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDRTPRICE_REM_DOSN->AsString));
flObrabatChangeTypePrice=true;
flObrabatChangeRoznTypePrice=true;

}
//---------------------------------------------------------------------------
int TREM_FormaDocOstNom::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaDocOstNom::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(Ed)Ed->kanRelease();
if(Nom)Nom->kanRelease();
if(Firma)Firma->kanRelease();
if(Sklad)Sklad->kanRelease();
if(SpisokBusinessOper)SpisokBusinessOper->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();
if(FormaSpiskaSprHardware)FormaSpiskaSprHardware->kanRelease();
if(SpisokObject)SpisokObject->kanRelease();
if(FormaSpiskaSprStorageLocation)FormaSpiskaSprStorageLocation->kanRelease();

//получим ICallBack для передачи события в вызывающую форму
if(InterfaceOwnerObject)
	{
	IkanCallBack * i_callback=0;
	InterfaceOwnerObject->kanQueryInterface(IID_IkanCallBack,(void**)&i_callback);
	if (i_callback)
		{
		i_callback->kanExternalEvent(InterfaceImpl,ClsIdImpl,TypeEvent,NumberProcVibor);
		i_callback->kanRelease(); i_callback=0;
		}

	}



DMSprTypePrice->kanRelease();
DMSprTypeRPrice->kanRelease();
DMTableExtPrintForm->kanRelease();
DM->kanRelease();

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}

}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaDocOstNom::FormActivate(TObject *Sender)
{
//зарегистрируем свой IAsyncExternalEvent в главном модуле для получения событий
if(InterfaceMainObject > 0)
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

void __fastcall TREM_FormaDocOstNom::FormDeactivate(TObject *Sender)
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
void __fastcall TREM_FormaDocOstNom::ReadShtrihCodEvent(int number, UnicodeString sh)
{
//


}
//---------------------------------------------------------------
int TREM_FormaDocOstNom::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_Nom)
        {
		if (type_event==1)
                {
                if (ActionOperation==aoAddNewString)
                        {
                        DM->AddDocNewString();
                        }
                DM->DocT->Edit();
				DM->DocTIDNOM_REM_DOSNT->AsString=Nom->DM->ElementIDNOM->AsString;
                DM->DocTNAMENOM->AsString=Nom->DM->ElementNAMENOM->AsString;
				if (DM->DocTKOL_REM_DOSNT->AsFloat > 0.001)  //задано количество
					{ //не изменяем
					}
				else
					{
					DM->DocTKOL_REM_DOSNT->AsFloat=1;
					}

				DM->DocTIDED_REM_DOSNT->AsString=Nom->DM->ElementIDOSNEDNOM->AsString;
                DM->DocTNAMEED->AsString=Nom->DM->OsnEdNAMEED->AsString;
				DM->DocTKF_REM_DOSNT->AsFloat=Nom->DM->OsnEdKFED->AsFloat;


				DM->DocTPRICE_REM_DOSNT->AsFloat=Nom->DM->ElementZNACH_PRICE->AsFloat
														*DM->DocTKF_REM_DOSNT->AsFloat;

					IDMSprPrice * DMSprPrice;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
									(void**)&DMSprPrice);
					DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDRTPRICE_REM_DOSN->AsString),
											 glStrToInt64(DM->DocTIDNOM_REM_DOSNT->AsString));
						DM->DocTRPRICE_REM_DOSNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_REM_DOSNT->AsFloat;
					DMSprPrice->kanRelease();

				DM->DocTIDMHRAN_REM_DOSNT->AsString=Nom->DM->TableOUT_IDMHRAN->AsString;
				DM->DocTNAME_SMHRAN->AsString=Nom->DM->TableOUT_NAME_MHRAN->AsString;
				DM->DocTIDTNOM_REM_DOSNT->AsString=Nom->DM->TableIDTNOM->AsString;
			   //	DM->DocTNAME_STNOM->AsString=Nom->DM->TableNAME_STNOM->AsString;



				DM->DocT->Post();
                //DBGrid1->SelectedField=DM->DocTKOLPRNT;
				VibTovarId=glStrToInt64(Nom->DM->ElementIDNOM->AsString);
				VibTovarIdGrp=glStrToInt64(Nom->DM->ElementIDGRPNOM->AsString);
                }
		Nom=0;
		}

if (number_procedure_end==ER_PodborNom)//==PodborNom)
		{

        }

if (number_procedure_end==ER_Ed)//==Edinica)
        {
		if (type_event==1)
                {
                DM->DocT->Edit();
				DM->DocTIDED_REM_DOSNT->AsString=Ed->DM->ElementIDED->AsString;
                DM->DocTNAMEED->AsString=Ed->DM->Element->FieldByName("NAMEED")->AsString;
				DM->DocTKF_REM_DOSNT->AsFloat=Ed->DM->ElementKFED->AsFloat;

					IDMSprPrice * DMSprPrice;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
									(void**)&DMSprPrice);
					DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						DMSprPrice->FindElement(glStrToInt64(DM->DocIDTPRICE_REM_DOSN->AsString),
											 glStrToInt64(DM->DocTIDNOM_REM_DOSNT->AsString));
						DM->DocTPRICE_REM_DOSNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_REM_DOSNT->AsFloat;
					DMSprPrice->kanRelease();

                DM->DocT->Post();
                }
		Ed=0;
        }

if (number_procedure_end==ER_Firm)//==FirmaRekvisit)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDFIRM_REM_GALLDOC->AsString=Firma->DM->ElementIDFIRM->AsString;
                DM->DocAllNAMEFIRM->AsString=Firma->DM->Element->FieldByName("NAMEFIRM")->AsString;
                DM->DocAll->Post();
                }
		Firma=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

if (number_procedure_end==ER_Sklad)//==SkladRekvisit)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDSKLAD_REM_GALLDOC->AsString=Sklad->DM->ElementIDSKLAD->AsString;
                DM->DocAllNAMESKLAD->AsString=Sklad->DM->Element->FieldByName("NAMESKLAD")->AsString;
				DM->DocAll->Post();
				UpdateForm();
                }
		Sklad=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }


if (number_procedure_end==ER_InfBase)//==ViborInfBase)
		{
		if (type_event==1)
				{
                DM->DocAll->Edit();
				DM->DocAllIDBASE_REM_GALLDOC->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsString;
                DM->DocAllNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
                DM->DocAll->Post();
                }
		FormaSpiskaSprInfBase=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}


if (number_procedure_end==ER_Part)
		{

		}


if (number_procedure_end==ER_GrpNom)
		{

		}

//редактирование параметров номенклатуры
if (number_procedure_end==ER_ElementNom)
		{
		if (type_event==1)
				{

				}

		}

//редактирование параметров единицы
if (number_procedure_end==ER_ElementEd)
		{
		if (type_event==1)
				{

				}

		}

//редактирование параметров оборудования
if (number_procedure_end==ER_ElementHW)
		{
		if (type_event==1)
				{

				}

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

if (number_procedure_end==ER_Hardware)
		{
		if (type_event==1)
				{
				EndViborHardware();
				}
		FormaSpiskaSprHardware=0;
		}

if (number_procedure_end==ER_ViborStorageLocation)
		{
		if (type_event==1)
				{
				EndViborStorageLocation()  ;
                }
		FormaSpiskaSprStorageLocation=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

return -1;
}
//----------------------------------------------------------------------------
void  TREM_FormaDocOstNom::OpenFSSprNom()
{
if(Prosmotr==true) return;
if (Nom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&Nom);
		Nom->Init(InterfaceMainObject,InterfaceImpl);
        Nom->Vibor=true;
		Nom->DM->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_REM_DOSN->AsString);
//        Nom->SpisokTypePrice->ItemIndex=Nom->DM->GetIndexTypePrice()-1;
//		Nom->HintLabel->Caption="Выберите номенклатуру для документа Приходная накладная №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		Nom->IdNom=glStrToInt64(DM->DocTIDNOM_REM_DOSNT->AsString);
		Nom->UpdateForm();
		Nom->NumberProcVibor=ER_Nom;
        }
}
//----------------------------------------------------------------------------
void TREM_FormaDocOstNom:: OpenFSSprEd()
{
if(Prosmotr==true) return;
if (Ed==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&Ed);
		Ed->Init(InterfaceMainObject,InterfaceImpl);
		Ed->Vibor=true;
		Ed->IdNom=glStrToInt64(DM->DocTIDNOM_REM_DOSNT->AsString);
		Ed->DM->OpenTable(glStrToInt64(DM->DocTIDNOM_REM_DOSNT->AsString));
//        Ed->LabelNom->Caption="Единицы номенклатуры: "+DM->DocTNAMENOM->AsString;
//		Ed->HintLabel->Caption="Выберите единицу номенклатуры для документа Приходная накладная №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		Ed->NumberProcVibor=ER_Ed;

        }
}

//----------------------------------------------------------------------------






void    TREM_FormaDocOstNom::OpenFormSpiskaSprFirm(void)
{
if(Prosmotr==true) return;
if (Firma==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&Firma);
		Firma->Init(InterfaceMainObject,InterfaceImpl);
        Firma->Vibor=true;
        Firma->DM->OpenTable();
//        Firma->HintLabel->Caption="Выберите фирму для документа Приходная накладная №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		Firma->NumberProcVibor=ER_Firm;
        }

}
//---------------------------------------------------------------------------
void  TREM_FormaDocOstNom::OpenFormSpiskaSprSklad(void)
{
if(Prosmotr==true) return;
if (Sklad==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&Sklad);
		Sklad->Init(InterfaceMainObject,InterfaceImpl);
		Sklad->Vibor=true;
		Sklad->DM->OpenTable();
//        Sklad->HintLabel->Caption="Выберите склад для документа Приходная накладная №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		Sklad->NumberProcVibor=ER_Sklad;

        }

}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOstNom::AddNewStringClick(TObject *Sender)
{
if(Prosmotr==true) return;
DM->AddDocNewString();
OpenFSSprNom();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOstNom::DeleteStringClick(TObject *Sender)
{
DM->DeleteStringDoc();        
}

//---------------------------------------------------------------------------

void TREM_FormaDocOstNom::OpenFormSpiskaSprInfBase(void)
{
if (Prosmotr==true) return;
if (DM->DocAllIDBASE_REM_GALLDOC->ReadOnly==true) return;
if (FormaSpiskaSprInfBase==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInfBase.1",IID_IFormaSpiskaSprInfBase,
													(void**)&FormaSpiskaSprInfBase);
		FormaSpiskaSprInfBase->Init(InterfaceMainObject,InterfaceImpl);
        FormaSpiskaSprInfBase->Vibor=true;
		FormaSpiskaSprInfBase->DM->OpenTable();
		FormaSpiskaSprInfBase->NumberProcVibor=ER_InfBase;
        }
}
//---------------------------------------------------------------------




void __fastcall TREM_FormaDocOstNom::NumberDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOstNom::FDateDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOstNom::PrimKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocOstNom::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if(Prosmotr==true) return;

		OpenFSSprNom();


}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOstNom::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if(Prosmotr==true) return;

		OpenFSSprEd();


}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOstNom::TypeRPriceComboBoxPropertiesChange(
      TObject *Sender)
{
if(flObrabatChangeRoznTypePrice==false) return;
FindNextControl(ActiveControl,true,true,false)->SetFocus();

 if (Prosmotr==true)
		{
		UpdateForm();
		 return;
		}

 if ( TypeRPriceComboBox->ItemIndex!=0)
		{
		DMSprTypeRPrice->Table->First();
		DMSprTypeRPrice->Table->MoveBy(TypeRPriceComboBox->ItemIndex-1);
		DM->Doc->Edit();
		DM->DocIDRTPRICE_REM_DOSN->AsString=DMSprTypeRPrice->TableID_TPRICE->AsString;
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
				IDMSprPrice *DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
				DM->DocT->First();
				while(!DM->DocT->Eof)
						{
						DM->DocT->Edit();
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDRTPRICE_REM_DOSN->AsString),
											 glStrToInt64(DM->DocTIDNOM_REM_DOSNT->AsString));
						DM->DocTRPRICE_REM_DOSNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_REM_DOSNT->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				DMSprPrice->kanRelease();
				}
		}	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOstNom::TypePriceComboBoxPropertiesChange(
      TObject *Sender)
{
if (flObrabatChangeTypePrice==false) return;
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
		DM->DocIDTPRICE_REM_DOSN->AsString=DMSprTypePrice->TableID_TPRICE->AsString;
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
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDTPRICE_REM_DOSN->AsString),
											 glStrToInt64(DM->DocTIDNOM_REM_DOSNT->AsString));
						DM->DocTPRICE_REM_DOSNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_REM_DOSNT->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				DMSprPrice->kanRelease();
				}
		}
}
//---------------------------------------------------------------------------




void __fastcall TREM_FormaDocOstNom::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprFirm();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOstNom::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprInfBase();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOstNom::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprSklad();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------




void TREM_FormaDocOstNom::BeforeSaveDoc(void)
{
if (DM->DocAllPOS_REM_GALLDOC->AsDateTime > Date())
	{
	UnicodeString V="Может быть нарушена последовательность проведения документов! Изменить время документа на текущее?";
	UnicodeString Z="Внимание!";
	if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
		{
		DM->DocAll->Edit();
		DM->DocAllPOS_REM_GALLDOC->AsDateTime=Now();
		DM->DocAll->Post();
		}
	}

}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaDocOstNom::ActionAddStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
ActionOperation=aoAddNewString;
OpenFSSprNom();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOstNom::ActionDeleteStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
DM->DeleteStringDoc();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOstNom::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOstNom::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocOstNom::IsmPriceCheckBoxKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocOstNom::PrimcxDBTextEditKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------





void __fastcall TREM_FormaDocOstNom::NumDocPostcxDBTextEditKeyPress(
      TObject *Sender, char &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOstNom::PosDocPostcxDBDateEditKeyPress(
      TObject *Sender, char &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TREM_FormaDocOstNom::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaDocOstNom::RunExternalModule(__int64 id_module, int type_module)
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
module->SetInt64Variables("glIdDoc", glStrToInt64(DM->DocAllID_REM_GALLDOC->AsString));
	
module->ExecuteModule();

}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocOstNom::ActionCloseExecute(TObject *Sender)
{
		DM->DocAll->CancelUpdates();
		DM->Doc->CancelUpdates();
		DM->DocT->CancelUpdates();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOstNom::ActionOKExecute(TObject *Sender)
{
if(Prosmotr==true) return;
BeforeSaveDoc();
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

void __fastcall TREM_FormaDocOstNom::ActionDvRegExecute(TObject *Sender)
{
if(Prosmotr==true) return;

BeforeSaveDoc();

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

void __fastcall TREM_FormaDocOstNom::ActionSaveExecute(TObject *Sender)
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


void __fastcall TREM_FormaDocOstNom::ActionEditNomExecute(TObject *Sender)
{
		IFormaElementaSprNom * FormaElementa;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprNom.1",IID_IFormaElementaSprNom,
										 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementa->DM->OpenElement(glStrToInt64(DM->DocTIDNOM_REM_DOSNT->AsString));
		FormaElementa->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_REM_DOSN->AsString);
		FormaElementa->IdFirm=glStrToInt64(DM->DocAllIDFIRM_REM_GALLDOC->AsString);
		FormaElementa->NumberProcVibor=ER_ElementNom;
		//FormaElementa->IdGrpNom=IdGrp;
		FormaElementa->NameGrpNom="";
		FormaElementa->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOstNom::ActionEditEdExecute(TObject *Sender)
{
IFormaElementaSprEd * FormaElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprEd.1",IID_IFormaElementaSprEd,
						 (void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->OpenElement(glStrToInt64(DM->DocTIDED_REM_DOSNT->AsString));
FormaElementa->UpdateForm();
FormaElementa->NumberProcVibor=ER_ElementEd;
}
//---------------------------------------------------------------------------

void TREM_FormaDocOstNom::OpenFormSpiskaSprProject(void)
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
void __fastcall TREM_FormaDocOstNom::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_REM_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void TREM_FormaDocOstNom::OpenFormSpiskaSprBusinessOper(void)
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
void __fastcall TREM_FormaDocOstNom::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_REM_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocOstNom::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
		DM->DocAllIDBUSINOP_REM_GALLDOC->Clear();
		DM->DocAll->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOstNom::NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
		DM->DocAllIDPROJECT_REM_GALLDOC->Clear();
		DM->DocAll->Post();
		}break;
	}
}
//---------------------------------------------------------------------------
void TREM_FormaDocOstNom::ViborHardware(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprHardware==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprHardware.1",IID_IREM_FormaSpiskaSprHardware,
													(void**)&FormaSpiskaSprHardware);
		FormaSpiskaSprHardware->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprHardware) return;
		FormaSpiskaSprHardware->Vibor=true;
		FormaSpiskaSprHardware->NumberProcVibor=ER_Hardware;
		FormaSpiskaSprHardware->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void TREM_FormaDocOstNom::EndViborHardware(void)
{

	DM->DocT->Edit();
	DM->DocTIDHW_REM_DOSNT->AsString=FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString;
	DM->DocTNAME_REM_SHARDWARE->AsString=FormaSpiskaSprHardware->DM->TableNAME_REM_SHARDWARE->AsString;
	DM->DocT->Post();

FormaSpiskaSprHardware=0;

}
//----------------------------------------------------------------------------





void __fastcall TREM_FormaDocOstNom::cxGrid1DBTableView1NAME_REM_SHARDWAREPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborHardware();
}

//----------------------------------------------------------------------------


void __fastcall TREM_FormaDocOstNom::ToolButtonAddSprHWClick(TObject *Sender)
{
	IDMSprNom * nom;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&nom);
	nom->Init(InterfaceMainObject,InterfaceImpl);

	IREM_DMSprModel * dm_model;
	InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprModel,IID_IREM_DMSprModel,
													(void**)&dm_model);
	dm_model->Init(InterfaceMainObject,InterfaceImpl);

	//получим группу куда будем добавлять новые элементы
	__int64 id_grp_hw=0;

	IREM_DMSprGrpHardware * grp_hw;
	InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMSprGrpHardware.1",IID_IREM_DMSprGrpHardware,
													(void**)&grp_hw);
	grp_hw->Init(InterfaceMainObject,InterfaceImpl);

	id_grp_hw=grp_hw->FindPoName("Ввод остатков");
	if (id_grp_hw==0)
		{//создаем новую группу
		grp_hw->NewElement(0);
		grp_hw->Element->Edit();
		grp_hw->ElementNAME_REM_SGRP_HARDWARE->AsString="Ввод остатков";
		grp_hw->Element->Post();
		if (grp_hw->SaveElement()==false)
			{
			ShowMessage("Ошибка при создании группы оборудования: "+grp_hw->TextError);
			return;
			}
		id_grp_hw=glStrToInt64(grp_hw->ElementID_REM_SGRP_HARDWARE->AsString);
		}

	grp_hw->kanRelease();


	//получим группу моделей куда будем добавлять новые модели
	__int64 id_grp_model=0;

	IREM_DMSprGrpModel * grp_model;
	InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprGrpModel,IID_IREM_DMSprGrpModel,
													(void**)&grp_model);
	grp_model->Init(InterfaceMainObject,InterfaceImpl);

	id_grp_model=grp_model->FindPoName("Ввод остатков");
	if (id_grp_model==0)
		{//создаем новую группу
		grp_model->NewElement(0);
		grp_model->Element->Edit();
		grp_model->ElementNAME_REM_SGRPMODEL->AsString="Ввод остатков";
		grp_model->Element->Post();
		id_grp_model=glStrToInt64(grp_model->ElementID_REM_SGRPMODEL->AsString);

		if (grp_model->SaveElement()==false)
			{
			ShowMessage("Ошибка при создании группы оборудования: "+grp_model->TextError);
			return;
			}
		}


	grp_model->kanRelease();

	//

	IREM_DMSprHardware * dm_hw;
	InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMSprHardware.1",IID_IREM_DMSprHardware,
													(void**)&dm_hw);
	dm_hw->Init(InterfaceMainObject,InterfaceImpl);


	DM->DocT->First();
	while(!DM->DocT->Eof)
		{
		nom->OpenElement(glStrToInt64(DM->DocTIDNOM_REM_DOSNT->AsString));

		if (nom->ElementFL_ADD_IN_SOBORUD_SNOM->AsInteger == 1
						&& glStrToInt64(DM->DocTIDHW_REM_DOSNT->AsString)==0)
			{  //учет по серийным номерам
			   //для начала получим модель
			__int64 id_model=0;
			id_model=dm_model->FindPoNom(glStrToInt64(DM->DocTIDNOM_REM_DOSNT->AsString));
			if (id_model==0)
				{
				dm_model->NewElement(id_grp_model);
				dm_model->Element->Edit();
				dm_model->ElementNAME_REM_SMODEL->AsString=DM->DocTNAMENOM->AsString;
				dm_model->ElementIDNOM_REM_SMODEL->AsString=DM->DocTIDNOM_REM_DOSNT->AsString;
				dm_model->Element->Post();
				id_model=glStrToInt64(dm_model->ElementID_REM_SMODEL->AsString);
				dm_model->SaveElement();

				}


			DM->DocT->Edit();
			dm_hw->NewElement(id_grp_hw);
			dm_hw->Element->Edit();
			dm_hw->ElementNAME_REM_SHARDWARE->AsString=
					DM->DocTNAMENOM->AsString;
			dm_hw->ElementPOSDOC_DOCPOST->AsDateTime=DM->DocAllPOS_REM_GALLDOC->AsDateTime;
			dm_hw->ElementIDMODEL_REM_SHARDWARE->AsString=id_model;
            dm_hw->ElementIDDOCPOST_REM_SHARDWARE->AsString=DM->DocAllIDEXTDOC_REM_GALLDOC->AsString;
			dm_hw->Element->Post();
			dm_hw->SaveElement();

			DM->DocTIDHW_REM_DOSNT->AsString=dm_hw->ElementID_REM_SHARDWARE->AsString;
			DM->DocTNAME_REM_SHARDWARE->AsString=dm_hw->ElementNAME_REM_SHARDWARE->AsString;
			DM->DocTCODE_REM_SHARDWARE->AsString=dm_hw->ElementCODE_REM_SHARDWARE->AsString;
			DM->DocTSERNUM_REM_SHARDWARE->AsString=dm_hw->ElementSERNUM_REM_SHARDWARE->AsString;

            DM->DocT->Post();
			}

		DM->DocT->Next();
		}

    dm_hw->kanRelease();
	nom->kanRelease();
	dm_model->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOstNom::ActionEditOborudExecute(TObject *Sender)
{
		IREM_FormaElementaSprHardware * FormaElementa;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaElSprHardware.1",IID_IREM_FormaElementaSprHardware,
										 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementa->DM->OpenElement(glStrToInt64(DM->DocTIDHW_REM_DOSNT->AsString));
		FormaElementa->NumberProcVibor=ER_ElementHW;
		FormaElementa->UpdateForm();
}
//---------------------------------------------------------------------------
//----------------------------------------------------------------------------
void TREM_FormaDocOstNom::OpenFormSpiskaSprObject(void)
{
if (Prosmotr==true) return;
if (SpisokObject==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprObject,IID_IFormaSpiskaSprObject,
													(void**)&SpisokObject);
		SpisokObject->Init(InterfaceMainObject,InterfaceImpl);
		SpisokObject->NumberProcVibor=ER_Object;
		SpisokObject->Vibor=true;
		//SpisokObject->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocOstNom::EndViborObject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDOBJECT_REM_GALLDOC->AsString=SpisokObject->DM->TableID_SOBJECT->AsString;
	DM->DocAllNAME_SOBJECT->AsString=SpisokObject->DM->TableNAME_SOBJECT->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
void  TREM_FormaDocOstNom::ViborStorageLocation(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprStorageLocation==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprStorageLocation,IID_IFormaSpiskaSprStorageLocation,
													(void**)&FormaSpiskaSprStorageLocation);
		FormaSpiskaSprStorageLocation->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprStorageLocation->Vibor=true;
		FormaSpiskaSprStorageLocation->IdGroupElement=glStrToInt64(DM->DocAllIDSKLAD_REM_GALLDOC->AsString);
		FormaSpiskaSprStorageLocation->IdElement=glStrToInt64(DM->DocTIDMHRAN_REM_DOSNT->AsString);
		FormaSpiskaSprStorageLocation->UpdateForm();
//        Sklad->HintLabel->Caption="Выберите склад для документа Приходная накладная №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		FormaSpiskaSprStorageLocation->NumberProcVibor=ER_ViborStorageLocation;

        }

}
//---------------------------------------------------------------------------
void TREM_FormaDocOstNom::EndViborStorageLocation(void)
{

DM->DocT->Edit();

DM->DocTIDMHRAN_REM_DOSNT->AsString=FormaSpiskaSprStorageLocation->DM->TableID_SMHRAN->AsString;
DM->DocTNAME_SMHRAN->AsString=FormaSpiskaSprStorageLocation->DM->TableNAME_SMHRAN->AsString;

DM->DocT->Post();

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocOstNom::cxGrid1DBTableView1NAME_SMHRANPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborStorageLocation();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocT->Edit();
		DM->DocTIDMHRAN_REM_DOSNT->Clear();
		DM->DocTNAME_SMHRAN->AsString="";
		DM->DocT->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOstNom::ToolButtonSetDvRegAllClick(TObject *Sender)
{
DM->DocT->First();

while (!DM->DocT->Eof)
	{
	DM->DocT->Edit();
	DM->DocTDVREG_REM_DOSNT->AsInteger=1;
	DM->DocT->Post();
	DM->DocT->Next();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOstNom::ToolButtonDelDvRegAllClick(TObject *Sender)
{
DM->DocT->First();

while (!DM->DocT->Eof)
	{
	DM->DocT->Edit();
	DM->DocTDVREG_REM_DOSNT->AsInteger=0;
	DM->DocT->Post();
	DM->DocT->Next();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOstNom::ToolButtonSetMestoHranClick(TObject *Sender)

{
__int64 id_mhran=0;
UnicodeString name_mhran="";

id_mhran=glStrToInt64(DM->DocTIDMHRAN_REM_DOSNT->AsString);
name_mhran=DM->DocTNAME_SMHRAN->AsString;
DM->DocT->Next();
while(!DM->DocT->Eof)
		{
		DM->DocT->Edit();
		DM->DocTIDMHRAN_REM_DOSNT->AsString=id_mhran;
		DM->DocTNAME_SMHRAN->AsString=name_mhran;
		DM->DocT->Post();
		DM->DocT->Next();
		}
}
//---------------------------------------------------------------------------

