//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaDocIsmPrice.h"
#include "IDMSprPrice.h"

#include "IDMSprFirm.h"
#include "IDMRegGoods.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IDMQueryRead.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtonEdit"
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
#pragma link "cxCalc"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxLabel"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxCheckBox"
#pragma link "cxLookAndFeels"
#pragma link "cxButtonEdit"
#pragma link "cxButtons"
#pragma link "cxCalc"
#pragma link "cxCalendar"
#pragma link "cxClasses"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMaskEdit"
#pragma link "cxStyles"
#pragma link "cxTextEdit"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaDocIsmPrice::TFormaDocIsmPrice(TComponent* Owner)
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
bool TFormaDocIsmPrice::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMDocIsmPrice.1",IID_IDMDocIsmPrice, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи

//flObrabatChangeTypePrice=false;

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

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;
DBTextFNameUser->DataSource=DM->DataSourceDocAll;

NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;

NameProjectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameBusinessOpercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PrefiksNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;


DescrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NameInvcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;

ActionOperation=aoNO;

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm, (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaDocIsmPriceImpl),false);
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
//--------------------------------------------------------------------------
int TFormaDocIsmPrice::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaDocIsmPrice::UpdateForm(void)
{

Prosmotr=DM->Prosmotr;
NoEdit=DM->NoEdit;
if (Prosmotr==true)
        {
		ProsmotrLabel->Visible=true;
		cxGrid1DBTableView1->OptionsData->Editing=false;
		ProsmotrTextLabel->Caption=DM->ProsmotrText;
        }
else
        {
		ProsmotrLabel->Visible=false;
		cxGrid1DBTableView1->OptionsData->Editing=true;
		ProsmotrTextLabel->Caption="";
        }

//if (NoEdit==true)
//		{
//		//ProsmotrLabel->Visible=true;
//		cxGrid1DBTableView1->OptionsData->Editing=false;
//		}
//else
//		{
//		//ProsmotrLabel->Visible=false;
//		cxGrid1DBTableView1->OptionsData->Editing=true;
//		}

//flObrabatChangeTypePrice=false;
TypePriceComboBox->ItemIndex=DMSprTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDNEWTPRICE_DISMPRICE->AsString));
//flObrabatChangeTypePrice=true;
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocIsmPrice::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokFirm)SpisokFirm->kanRelease();
if(SpisokSklad)SpisokSklad->kanRelease();
if(SpisokNom)SpisokNom->kanRelease();
if(SpisokEd)SpisokEd->kanRelease();
if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();

if(SpisokBusinessOper)SpisokBusinessOper->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();
if(FormaViborGrpNomSpr)FormaViborGrpNomSpr->kanRelease();

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


DM->kanRelease();
DMSprTypePrice->kanRelease();
DMTableExtPrintForm->kanRelease();

Action=caFree;


if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}

}
//---------------------------------------------------------------------------

int TFormaDocIsmPrice::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_InfBase)
		{
		if (type_event==1)    //выбор сделан
			{
            EndViborInfBase();
			}
		FormaSpiskaSprInfBase=0;
		}


if (number_procedure_end==ER_Firm)
		{
		if (type_event==1)    //выбор сделан
			{
            EndViborFirm();
			}
		SpisokFirm=0;
		}

if (number_procedure_end==ER_Sklad)
		{
		if (type_event==1)    //выбор сделан
			{
			EndViborSklad()  ;
			}
		SpisokSklad=0;
		}

if (number_procedure_end==ER_Nom)
		{
		if (type_event==1)    //выбор сделан
			{
			EndViborNom();
			}
		SpisokNom=0;
		}

if (number_procedure_end==ER_NomSoSklada)
		{
		if (type_event==1)    //выбор сделан
			{
			EndViborNomSoSklada();
			}
		SpisokNom=0;
		}


if (number_procedure_end==ER_Ed)
		{
		if (type_event==1)    //выбор сделан
			{
			EndViborEd();
			}
		SpisokEd=0;
		}

if (number_procedure_end==ER_Inv)
		{
		if (type_event==1)    //выбор сделан
			{
			EndViborInv();
			}
		FormaSpiskaSprInv=0;
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

if (number_procedure_end==ER_ViborGrpNom)
		{
		if (type_event==1)
				{
				EndViborGrpNom();
				}
		FormaViborGrpNomSpr=0;
		}

FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------
void TFormaDocIsmPrice::OpenFormSpiskaSprInfBase(void)
{
if (Prosmotr==true)
	{
	ShowMessage("Документ открыт только для просмотра!");
	return;
	}
if (DM->DocAllIDBASE_GALLDOC->ReadOnly==true) return;
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
//-----------------------------------------------------------------------------
void __fastcall TFormaDocIsmPrice::EndViborInfBase(void)
{


                DM->DocAll->Edit();
				DM->DocAllIDBASE_GALLDOC->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsString;
                DM->DocAllNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
                DM->DocAll->Post();


}
//---------------------------------------------------------------------------
void TFormaDocIsmPrice::OpenFormSpiskaSprFirm(void)
{
if (Prosmotr==true)
	{
	ShowMessage("Документ открыт только для просмотра!");
	return;
	}
if (SpisokFirm==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&SpisokFirm);
		SpisokFirm->Init(InterfaceMainObject,InterfaceImpl);
		SpisokFirm->Vibor=true;
		SpisokFirm->NumberProcVibor=ER_Firm;
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocIsmPrice::EndViborFirm(void)
{


				DM->DocAll->Edit();
				DM->DocAllIDFIRMDOC->AsString=SpisokFirm->DM->ElementIDFIRM->AsString;
				DM->DocAllNAMEFIRM->AsString=SpisokFirm->DM->ElementNAMEFIRM->AsString;
				DM->DocAll->Post();




}
//---------------------------------------------------------------------------
void TFormaDocIsmPrice::OpenFormSpiskaSprSklad(void)
{
if (Prosmotr==true)
	{
	ShowMessage("Документ открыт только для просмотра!");
	return;
	}
if (SpisokSklad==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&SpisokSklad);
		SpisokSklad->Init(InterfaceMainObject,InterfaceImpl);
		SpisokSklad->Vibor=true;
		SpisokSklad->NumberProcVibor=ER_Sklad;
		}
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocIsmPrice::EndViborSklad(void)
{


				DM->DocAll->Edit();
				DM->DocAllIDSKLDOC->AsString=SpisokSklad->DM->ElementIDSKLAD->AsString;
				DM->DocAllNAMESKLAD->AsString=SpisokSklad->DM->ElementNAMESKLAD->AsString;
				DM->DocAll->Post();

}
//----------------------------------------------------------------------------
void TFormaDocIsmPrice::OpenFormSpiskaSprNom(void)
{
if (Prosmotr==true)
	{
	ShowMessage("Документ открыт только для просмотра!");
	return;
	}
if (SpisokNom==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&SpisokNom);
		SpisokNom->Init(InterfaceMainObject,InterfaceImpl);
		SpisokNom->Vibor=true;
		SpisokNom->DM->IdTypePrice=glStrToInt64(DM->DocIDNEWTPRICE_DISMPRICE->AsString);
		SpisokNom->IdNom=glStrToInt64(DM->DocTIDNOM_DISMPRICET->AsString);
		SpisokNom->UpdateForm();
		SpisokNom->NumberProcVibor=ER_Nom;
		}
}
//-----------------------------------------------------------------------------
void __fastcall TFormaDocIsmPrice::EndViborNom(void)
{

				if (ActionOperation==aoAddNewString)
					{
					DM->AddDocNewString();
					}

					DM->DocT->Edit();
					DM->DocTIDNOM_DISMPRICET->AsString=SpisokNom->DM->ElementIDNOM->AsString;
					DM->DocTNAMENOM->AsString=SpisokNom->DM->ElementNAMENOM->AsString;
					DM->DocTTNOM->AsInteger=SpisokNom->DM->ElementTNOM->AsInteger;

					DM->DocTIDED_DISMPRICET->AsString=SpisokNom->DM->ElementIDBASEDNOM->AsString;
					DM->DocTNAMEED->AsString=SpisokNom->DM->BasEdNAMEED->AsString;

					DM->DocTKF_DISMPRICET->AsFloat=SpisokNom->DM->OsnEdKFED->AsFloat;
					DM->DocTKOL_DISMPRICET->AsFloat=1;

					IDMSprPrice * DMSprPrice;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
					DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
					DMSprPrice->FindElement(glStrToInt64(DM->DocIDNEWTPRICE_DISMPRICE->AsString),
											 glStrToInt64(DM->DocTIDNOM_DISMPRICET->AsString));
					DM->DocTOLDPRICE_DISMPRICET->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_DISMPRICET->AsFloat;
					DMSprPrice->kanRelease();

					DM->DocT->Post();

		cxGrid1->SetFocus();
		cxGrid1DBTableView1KOL_DISMPRICET->Selected=true;
}
//----------------------------------------------------------------------------
void TFormaDocIsmPrice::ViborNomSoSklada(void)
{
if (Prosmotr==true)
	{
	ShowMessage("Документ открыт только для просмотра!");
	return;
	}
if (SpisokNom==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&SpisokNom);
		SpisokNom->Init(InterfaceMainObject,InterfaceImpl);
		SpisokNom->Vibor=true;
		SpisokNom->DM->IdTypePrice=glStrToInt64(DM->DocIDNEWTPRICE_DISMPRICE->AsString);
		SpisokNom->IdNom=glStrToInt64(DM->DocTIDNOM_DISMPRICET->AsString);
		SpisokNom->UpdateForm();
		SpisokNom->NumberProcVibor=ER_NomSoSklada;
		}
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocIsmPrice::EndViborNomSoSklada(void)
{



		IDMRegGoods * reg;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMRegGoods.1",IID_IDMRegGoods,
													(void**)&reg);
		reg->Init(InterfaceMainObject,InterfaceImpl);
						reg->GetOstatokPoPrice(glStrToInt64(DM->DocAllIDFIRMDOC->AsString),
									glStrToInt64(DM->DocAllIDSKLDOC->AsString),
									glStrToInt64(SpisokNom->DM->ElementIDNOM->AsString));
						reg->TableOst->First();
						while(!reg->TableOst->Eof)
							{
							DM->DocT->Append();
							DM->DocT->Edit();
							DM->DocTIDNOM_DISMPRICET->AsString=SpisokNom->DM->ElementIDNOM->AsString;
							DM->DocTNAMENOM->AsString=SpisokNom->DM->ElementNAMENOM->AsString;
							DM->DocTTNOM->AsInteger=SpisokNom->DM->ElementTNOM->AsInteger;

							DM->DocTIDED_DISMPRICET->AsString=SpisokNom->DM->ElementIDBASEDNOM->AsString;
							DM->DocTNAMEED->AsString=SpisokNom->DM->BasEdNAMEED->AsString;

							DM->DocTKF_DISMPRICET->AsFloat=SpisokNom->DM->OsnEdKFED->AsFloat;
							DM->DocTKOL_DISMPRICET->AsFloat=reg->TableOst->FieldByName("KOLOST")->AsFloat;
							DM->DocTOLDPRICE_DISMPRICET->AsFloat=reg->TableOst->FieldByName("RPRICE_RGGOODS")->AsFloat;
							DM->DocT->Post();
							reg->TableOst->Next();
							}
						reg->kanRelease();

		SpisokNom=0;
		cxGrid1->SetFocus();
		cxGrid1DBTableView1KOL_DISMPRICET->Selected=true; 

}
//-----------------------------------------------------------------------------
void TFormaDocIsmPrice::OpenFormSpiskaSprEd(void)
{
if (Prosmotr==true)
	{
	ShowMessage("Документ открыт только для просмотра!");
	return;
	}
if (SpisokEd==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&SpisokEd);
		SpisokEd->Init(InterfaceMainObject,InterfaceImpl);
        SpisokEd->Vibor=true;
		SpisokEd->DM->OpenTable(glStrToInt64(DM->DocTIDNOM_DISMPRICET->AsString));
		SpisokEd->NumberProcVibor=ER_Ed;
		}   
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocIsmPrice::EndViborEd(void)
{


				DM->DocT->Edit();
				DM->DocTIDED_DISMPRICET->AsString=SpisokEd->DM->ElementIDED->AsString;
				DM->DocTNAMEED->AsString=SpisokEd->DM->ElementNAMEED->AsString;
				DM->DocTKF_DISMPRICET->AsFloat=SpisokEd->DM->ElementKFED->AsFloat;
					IDMSprPrice * DMSprPrice;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
					DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						DMSprPrice->FindElement(glStrToInt64(DM->DocIDNEWTPRICE_DISMPRICE->AsString),
											 glStrToInt64(DM->DocTIDNOM_DISMPRICET->AsString));
						DM->DocTNEWPRICE_DISMPRICET->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_DISMPRICET->AsFloat;
				DMSprPrice->kanRelease();

				DM->DocT->Post();

		cxGrid1->SetFocus();
		cxGrid1DBTableView1OLDPRICE_DISMPRICET->Selected=true;

}
//*****************************************************************************
//---------------------------------------------------------------------------
//--------------------------------------------------------------------------
//---------------------------------------------------------------------

void __fastcall TFormaDocIsmPrice::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocIsmPrice");
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocIsmPrice::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{


ActionOperation=aoNO;
OpenFormSpiskaSprNom();


}
//---------------------------------------------------------------------------

void __fastcall TFormaDocIsmPrice::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{


OpenFormSpiskaSprEd();


}
//---------------------------------------------------------------------------

void __fastcall TFormaDocIsmPrice::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{

OpenFormSpiskaSprSklad();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocIsmPrice::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{

OpenFormSpiskaSprFirm();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocIsmPrice::NameInfBasecxDBButtonEditPropertiesButtonClick(
	  TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprInfBase();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocIsmPrice::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocIsmPrice::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocIsmPrice::DescrcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocIsmPrice::TypePriceComboBoxPropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
//if (flObrabatChangeTypePrice==false)return;

FindNextControl(ActiveControl,true,true,false)->SetFocus();

 if (Prosmotr==true)
		{
		UpdateForm();
		 return;
		}

if (NoEdit==true)
		{
        UpdateForm();
		 return;
        }

if ( TypePriceComboBox->ItemIndex!=0)
		{
        DMSprTypePrice->Table->First();
		DMSprTypePrice->Table->MoveBy(TypePriceComboBox->ItemIndex-1);
		DM->Doc->Edit();
		DM->DocIDNEWTPRICE_DISMPRICE->AsString=DMSprTypePrice->TableID_TPRICE->AsString;
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
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDNEWTPRICE_DISMPRICE->AsString),
											 glStrToInt64(DM->DocTIDNOM_DISMPRICET->AsString));
						DM->DocTNEWPRICE_DISMPRICET->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_DISMPRICET->AsFloat;
                        DM->DocT->Post();
						DM->DocT->Next();
						}
				DMSprPrice->kanRelease();
				}
		}	
}
//---------------------------------------------------------------------------
//Action
//---------------------------------------------------------------------------
void __fastcall TFormaDocIsmPrice::ActionAddNomExecute(TObject *Sender)
{
ActionOperation=aoAddNewString;
OpenFormSpiskaSprNom();
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocIsmPrice::ActionAddNomSoSkladaExecute(TObject *Sender)
{
ActionOperation=aoAddNewString;
ViborNomSoSklada();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocIsmPrice::ActionDeleteRecordExecute(TObject *Sender)
{
DM->DeleteStringDoc();
}
//---------------------------------------------------------------------------
//кнопки
//---------------------------------------------------------------------------
//Записать
//Провести
//ОК
//Закрыть
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaDocIsmPrice::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaDocIsmPrice::RunExternalModule(__int64 id_module, int type_module)
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
//-----------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TFormaDocIsmPrice::OpenPrintForm(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;
SumKol=0;
SumOld=0;
SumNew=0;
SumIsm=0;

//шапка
PrintForm->SS->BeginUpdate();
OutputZagolovokReport(PrintForm);

//таблица

DM->DocT->First();
while(!DM->DocT->Eof)
        {
		SumKol=SumKol+DM->DocTKOL_DISMPRICET->AsFloat;
		SumOld=SumOld+DM->DocTOLDSUM->AsFloat;
		SumNew=SumNew+DM->DocTNEWSUM->AsFloat;
		SumIsm=SumIsm+DM->DocTSUMISM->AsFloat;
        OutputString(PrintForm);numRow++; porNumStr++;

        DM->DocT->Next();
        }

OutputPodavalReport(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();
}
//---------------------------------------------------------------------------
void TFormaDocIsmPrice::OutputZagolovokReport(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numRow=1;
numCol=2;


prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
prForm->SS->RowsAutoHeight=true;
        TcxSSHeader *cHeader;

        cHeader = prForm->SS->ActiveSheet->Cols;
		cHeader->Size[0] = 5;
		cHeader->Size[1] = 5;
        cHeader->Size[2] = 40;
		cHeader->Size[3] = 180;
		cHeader->Size[4] = 60;
		cHeader->Size[5] = 60;
		cHeader->Size[6] = 60;
		cHeader->Size[7] = 60;
		cHeader->Size[8] = 60;
		cHeader->Size[9] = 60;
		cHeader->Size[10] = 60;
		cHeader->Size[11] = 60;

IDMSprFirm *spr_firm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&spr_firm);
spr_firm->Init(InterfaceMainObject,InterfaceImpl);
spr_firm->OpenElement(glStrToInt64(DM->DocAllIDFIRMDOC->AsString));

cell = prForm->SS->ActiveSheet->GetCellObject(2, 1);
cell->Text=spr_firm->ElementFNAMEFIRM->AsString
		+", ИНН "+spr_firm->ElementINNFIRM->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Адрес: "+spr_firm->ElementPADRFIRM->AsString;
delete cell;
numRow++;

spr_firm->kanRelease();

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Склад: "+DM->DocAllNAMESKLAD->AsString;
delete cell;
numRow++; numRow++;


cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="Переоценка №"+DM->DocAllNUMDOC->AsString+" от "
                +DateToStr(DM->DocAllPOSDOC->AsDateTime);
delete cell;
numRow++; numRow++;



cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Основание: "+DM->DocDESCR_DISMPRICE->AsString;
delete cell;
numRow++;
numRow++;

//заголовок таблицы
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="№";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
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
cell->Style->Font->Size = 8;
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
cell->Style->Font->Size = 8;
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
cell->Style->Font->Size = 8;
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
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Старая цена";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Новая цена";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Сумма по старой цене";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Сумма по новой цене";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Сумма изменения";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
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
void TFormaDocIsmPrice::OutputString(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=2;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IntToStr(porNumStr);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
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
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTKOL_DISMPRICET->AsFloat,ffFixed,15,3);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTNAMEED->AsString;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTKF_DISMPRICET->AsFloat,ffFixed,10,3);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTOLDPRICE_DISMPRICET->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTNEWPRICE_DISMPRICET->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTOLDSUM->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTNEWSUM->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTSUMISM->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
}


//------------------------------------------------------------------------------
void TFormaDocIsmPrice::OutputPodavalReport(TSheetEditor *prForm)
{

TcxSSCellObject *cell;

numCol=2;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text=IntToStr(porNumStr);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text=DM->DocTNAMENOM->AsString;
//cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(SumKol,ffFixed,15,3);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text=DM->DocTNAMEED->AsString;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text=FloatToStrF(DM->DocTKF_DISMPRICET->AsFloat,ffFixed,10,3);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTOLDPRICE_DISMPRICET->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTNEWPRICE_DISMPRICET->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(SumOld,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(SumNew,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(SumIsm,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;


numRow++;
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haLEFT;
cell->Text="Всего наименований "+IntToStr(DM->DocT->RecordCount);
delete cell;
numRow++;


for (int i=2;i<=11;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(i, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        }
numRow++;
numRow++;

numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Отв. лицо  __________________________ ";
delete cell;
numRow++;
numRow++;
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->HorzTextAlign = haRIGHT;
cell->Text="Отв. лицо  __________________________ ";
delete cell;
}
//---------------------------------------------------------------

void __fastcall TFormaDocIsmPrice::ToolButtonUpdatePriceInSprClick(TObject *Sender)
{
IDMSprPrice * dm_price;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
dm_price->Init(InterfaceMainObject,InterfaceImpl);
IDMSprNom * dm_nom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&dm_nom);
dm_nom->Init(InterfaceMainObject,InterfaceImpl);
//изменим цены в справочнике

	DM->DocT->First();
	while (!DM->DocT->Eof)
		{
		__int64 id_bas_ed=dm_nom->GetIdBasEd(glStrToInt64(DM->DocTIDNOM_DISMPRICET->AsString));
		
				if (glStrToInt64(DM->DocIDNEWTPRICE_DISMPRICE->AsString)!=0 && DM->DocTNEWPRICE_DISMPRICET->AsFloat!=0)
					{
					//изменим розничную цену в справочнике
					__int64 id_price=dm_price->FindElementPoEd(glStrToInt64(DM->DocIDNEWTPRICE_DISMPRICE->AsString),
								glStrToInt64(DM->DocTIDNOM_DISMPRICET->AsString), id_bas_ed);
					if (id_price==0)
						{
						dm_price->IdBasEd=id_bas_ed;
						dm_price->IdNom=glStrToInt64(DM->DocTIDNOM_DISMPRICET->AsString);
						dm_price->IdTypePrice=glStrToInt64(DM->DocIDNEWTPRICE_DISMPRICE->AsString);
						dm_price->NewElement();
						}
					else
						{
                        dm_price->OpenElement(id_price);
						}

					dm_price->Element->Edit();
					dm_price->ElementZNACH_PRICE->AsFloat=DM->DocTNEWPRICE_DISMPRICET->AsFloat/DM->DocTKF_DISMPRICET->AsFloat;
					dm_price->Element->Post();
					dm_price->SaveElement();
					}
		DM->DocT->Next();
		}
dm_nom->kanRelease();
dm_price->kanRelease();

ShowMessage("Цены обновлены!");	
}
//---------------------------------------------------------------------------
void TFormaDocIsmPrice::OpenFormSpiskaSprInv(void)
{
if (Prosmotr==true)
	{
	ShowMessage("Документ открыт только для просмотра!");
	return;
	}
if (FormaSpiskaSprInv==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInv.1",IID_IFormaSpiskaSprInv,
													(void**)&FormaSpiskaSprInv);
		FormaSpiskaSprInv->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprInv->Vibor=true;
		FormaSpiskaSprInv->NumberProcVibor=ER_Inv;
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocIsmPrice::EndViborInv(void)
{


	DM->Doc->Edit();
	DM->DocIDINV_DISMPRICE->AsString=FormaSpiskaSprInv->DM->TableID_SINV->AsString;
	DM->DocNAME_SINV->AsString=FormaSpiskaSprInv->DM->TableNAME_SINV->AsString;
	DM->Doc->Post();




}
//-----------------------------------------------------------------------------

void __fastcall TFormaDocIsmPrice::NameInvcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (AButtonIndex==0)
	{
	OpenFormSpiskaSprInv();
	}

if (AButtonIndex==1)
	{
	DM->Doc->Edit();
	DM->DocIDINV_DISMPRICE->Clear();
	DM->DocNAME_SINV->AsString="";
	DM->Doc->Post();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocIsmPrice::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocIsmPrice::ActionOKExecute(TObject *Sender)
{
if (Prosmotr==true)
	{
	ShowMessage("Документ открыт только для просмотра!");
	return;
	}


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

void __fastcall TFormaDocIsmPrice::ActionSaveExecute(TObject *Sender)
{
if (Prosmotr==true)
	{
	ShowMessage("Документ открыт только для просмотра!");
	return;
	}


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

void __fastcall TFormaDocIsmPrice::ActionDvRegExecute(TObject *Sender)
{
if (Prosmotr==true)
	{
	ShowMessage("Документ открыт только для просмотра!");
	return;
	}




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

void __fastcall TFormaDocIsmPrice::ActionPrintExecute(TObject *Sender)
{
OpenPrintForm();
}
//---------------------------------------------------------------------------
void TFormaDocIsmPrice::OpenFormSpiskaSprProject(void)
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
void __fastcall TFormaDocIsmPrice::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void TFormaDocIsmPrice::OpenFormSpiskaSprBusinessOper(void)
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
void __fastcall TFormaDocIsmPrice::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------

void __fastcall TFormaDocIsmPrice::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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

void __fastcall TFormaDocIsmPrice::NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
void TFormaDocIsmPrice::EndViborGrpNom(void)
{

__int64 id_grp = glStrToInt64(FormaViborGrpNomSpr->DMGrp->ElementIDGN->AsString);
UnicodeString name_grp = FormaViborGrpNomSpr->DMGrp->ElementNAMEGN->AsString;

UnicodeString zapros="select IDNOM, CODENOM, NAMENOM, IDED, NAMEED, KFED,rggoods.rprice_rggoods, sum(rggoods.kol_rggoods) as KOL    \
						from rggoods                                                                  \
						left outer join SNOM on IDNOM=rggoods.idnom_rggoods                           \
						left outer join sed on sed.ided=snom.idbasednom                               \
						where rggoods.idsklad_rggoods=:PARAM_IDSKLAD                                  \
										and rggoods.idfirm_rggoods=:PARAM_IDFIRM                              \
										and snom.idgrpnom=:PARAM_IDGRP                                        \
						group by IDNOM, CODENOM, NAMENOM, IDED, NAMEED, KFED, rggoods.rprice_rggoods                          \
						order by NAMENOM";

IDMQueryRead * DMQueryRead;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&DMQueryRead);
DMQueryRead->Init(InterfaceMainObject,0);
DMQueryRead->pFIBQ->Close();
DMQueryRead->pFIBQ->SQL->Clear();
DMQueryRead->pFIBQ->SQL->Add(zapros);
DMQueryRead->pFIBQ->ParamByName("PARAM_IDSKLAD")->AsString=DM->DocAllIDSKLDOC->AsString;
DMQueryRead->pFIBQ->ParamByName("PARAM_IDFIRM")->AsString=DM->DocAllIDFIRMDOC->AsString;
DMQueryRead->pFIBQ->ParamByName("PARAM_IDGRP")->AsString=id_grp;
DMQueryRead->pFIBQ->ExecQuery();

while(!DMQueryRead->pFIBQ->Eof)
	{
	DM->AddDocNewString();
	DM->DocT->Edit();

	DM->DocTIDNOM_DISMPRICET->AsString=DMQueryRead->pFIBQ->FieldByName("IDNOM")->AsString;
	//DM->DocTCODENOM->AsInteger=DMQueryRead->pFIBQ->FieldByName("CODENOM")->AsInteger;
	DM->DocTNAMENOM->AsString=DMQueryRead->pFIBQ->FieldByName("NAMENOM")->AsString;

	DM->DocTIDED_DISMPRICET->AsString=DMQueryRead->pFIBQ->FieldByName("IDED")->AsString;
	DM->DocTNAMEED->AsString=DMQueryRead->pFIBQ->FieldByName("NAMEED")->AsString;
	DM->DocTKF_DISMPRICET->AsFloat=DMQueryRead->pFIBQ->FieldByName("KFED")->AsFloat;
	DM->DocTKOL_DISMPRICET->AsFloat=DMQueryRead->pFIBQ->FieldByName("KOL")->AsFloat;
	DM->DocTOLDPRICE_DISMPRICET->AsFloat=DMQueryRead->pFIBQ->FieldByName("rprice_rggoods")->AsFloat;

    DM->DocT->Post();
	DMQueryRead->pFIBQ->Next();
	}


DMQueryRead->kanRelease();
}
//-------------------------------------------------------------------------
void TFormaDocIsmPrice::OpenFormViborGrpNom(void)
{
if (FormaViborGrpNomSpr==0)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprGrpNom.1",IID_IFormaSpiskaSprGrpNom,
													(void**)&FormaViborGrpNomSpr);
		FormaViborGrpNomSpr->Init(InterfaceMainObject,InterfaceImpl);
		FormaViborGrpNomSpr->Vibor=true;
		FormaViborGrpNomSpr->NumberProcVibor=ER_ViborGrpNom;
        FormaViborGrpNomSpr->UpdateForm();
        }

}
//-----------------------------------------------------------------------------
void __fastcall TFormaDocIsmPrice::ToolButtonAddOstatkiPoGrpClick(TObject *Sender)

{
OpenFormViborGrpNom();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocIsmPrice::ToolButtonAddAllOstatkiClick(TObject *Sender)
{
UnicodeString zapros="select IDNOM, CODENOM, NAMENOM, IDED, NAMEED, KFED,rggoods.rprice_rggoods, sum(rggoods.kol_rggoods) as KOL    \
						from rggoods                                                                  \
						left outer join SNOM on IDNOM=rggoods.idnom_rggoods                           \
						left outer join sed on sed.ided=snom.idbasednom                               \
						where rggoods.idsklad_rggoods=:PARAM_IDSKLAD                                  \
										and rggoods.idfirm_rggoods=:PARAM_IDFIRM                              \
						group by IDNOM, CODENOM, NAMENOM, IDED, NAMEED, KFED, rggoods.rprice_rggoods                          \
						order by NAMENOM";

IDMQueryRead * DMQueryRead;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&DMQueryRead);
DMQueryRead->Init(InterfaceMainObject,0);
DMQueryRead->pFIBQ->Close();
DMQueryRead->pFIBQ->SQL->Clear();
DMQueryRead->pFIBQ->SQL->Add(zapros);
DMQueryRead->pFIBQ->ParamByName("PARAM_IDSKLAD")->AsString=DM->DocAllIDSKLDOC->AsString;
DMQueryRead->pFIBQ->ParamByName("PARAM_IDFIRM")->AsString=DM->DocAllIDFIRMDOC->AsString;
DMQueryRead->pFIBQ->ExecQuery();

while(!DMQueryRead->pFIBQ->Eof)
	{
	DM->AddDocNewString();
	DM->DocT->Edit();

	DM->DocTIDNOM_DISMPRICET->AsString=DMQueryRead->pFIBQ->FieldByName("IDNOM")->AsString;
	//DM->DocTCODENOM->AsInteger=DMQueryRead->pFIBQ->FieldByName("CODENOM")->AsInteger;
	DM->DocTNAMENOM->AsString=DMQueryRead->pFIBQ->FieldByName("NAMENOM")->AsString;

	DM->DocTIDED_DISMPRICET->AsString=DMQueryRead->pFIBQ->FieldByName("IDED")->AsString;
	DM->DocTNAMEED->AsString=DMQueryRead->pFIBQ->FieldByName("NAMEED")->AsString;
	DM->DocTKF_DISMPRICET->AsFloat=DMQueryRead->pFIBQ->FieldByName("KFED")->AsFloat;
	DM->DocTKOL_DISMPRICET->AsFloat=DMQueryRead->pFIBQ->FieldByName("KOL")->AsFloat;
	DM->DocTOLDPRICE_DISMPRICET->AsFloat=DMQueryRead->pFIBQ->FieldByName("rprice_rggoods")->AsFloat;

    DM->DocT->Post();
	DMQueryRead->pFIBQ->Next();
	}


DMQueryRead->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocIsmPrice::cxGrid1DBTableView1NAC_NEW_DISMPRICETPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
double procent=(double)VarAsType(DisplayValue,varDouble);
DM->DocT->Edit();
DM->DocTNEWPRICE_DISMPRICET->AsFloat=DM->DocTSEB_PRICE_DISMPRICET->AsFloat*((100+procent)/100);
DM->DocT->Post();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocIsmPrice::ToolButtonAddSebestClick(TObject *Sender)
{
UnicodeString zapros="select sum(rgostnom.sumostnom) as sebest,    \
							sum(rgostnom.kolostnom) as kolost      \
						from rgostnom                                \
						where rgostnom.idfirmostnom=:PARAM_IDFIRM    \
								and  rgostnom.idsklostnom=:PARAM_IDSKLAD \
								and rgostnom.idnomostnom=:PARAM_IDNOM";

IDMQueryRead * DMQueryRead;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&DMQueryRead);
DMQueryRead->Init(InterfaceMainObject,0);
DMQueryRead->pFIBQ->Close();
DMQueryRead->pFIBQ->SQL->Clear();
DMQueryRead->pFIBQ->SQL->Add(zapros);



DM->DocT->First();

while(!DM->DocT->Eof)
	{
	DMQueryRead->pFIBQ->Close();
	DMQueryRead->pFIBQ->ParamByName("PARAM_IDFIRM")->AsString=DM->DocAllIDFIRMDOC->AsString;
	DMQueryRead->pFIBQ->ParamByName("PARAM_IDSKLAD")->AsString=DM->DocAllIDSKLDOC->AsString;
	DMQueryRead->pFIBQ->ParamByName("PARAM_IDNOM")->AsString=DM->DocTIDNOM_DISMPRICET->AsString;
	DMQueryRead->pFIBQ->ExecQuery();
	DM->DocT->Edit();
	if (DMQueryRead->pFIBQ->FieldByName("KOLOST")->AsFloat > 0.001)
		{
		DM->DocTSEB_PRICE_DISMPRICET->AsFloat=DMQueryRead->pFIBQ->FieldByName("sebest")->AsFloat
										/DMQueryRead->pFIBQ->FieldByName("KOLOST")->AsFloat;
		}
	else
		{
		DM->DocTSEB_PRICE_DISMPRICET->AsFloat=0;
		}
	DM->DocT->Post();
	DM->DocT->Next();
	}

DMQueryRead->kanRelease();
}
//---------------------------------------------------------------------------



