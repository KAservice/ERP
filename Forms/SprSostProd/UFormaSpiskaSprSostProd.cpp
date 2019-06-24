//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprSostProd.h"
#include "IFormaReportSostProd.h"
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
#pragma link "cxButtonEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprSostProd::TFormaSpiskaSprSostProd(TComponent* Owner)
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

bool TFormaSpiskaSprSostProd::Init(void)
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
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprSostProd.1",IID_IDMSprSostProd, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
//DM->OpenTable(IdNom);
Vibor=false;


//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;


LabelNom->Caption=NameNom;
LabelKolEd->Caption="На "+FloatToStrF(KolEdProd, ffFixed,10,3)
					+" "+NameEdProd
					+" КФ: "+KFEdProd;

result=true;
return result;
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprSostProd::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprSostProd::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprProduce)FormaSpiskaSprProduce->kanRelease();
if(FormaSpiskaSprLossFactor)FormaSpiskaSprLossFactor->kanRelease();


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
Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprSostProd::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_Nom)//Tovar)
        {
		if (type_event==1)
                {
				DM->Table->Edit();
				DM->TableIDKOMPL_SPROD->AsString=Nom->DM->TableIDNOM->AsString;
                DM->TableNAMENOM->AsString=Nom->DM->TableNAMENOM->AsString;
                DM->Table->Post();
				}
		Nom=0;
        }
if (number_procedure_end==ER_Ed)//ViborEdinica)
		{
		if (type_event==1)
                {
				DM->Table->Edit();
				DM->TableIDED_SPROD->AsInt64=FormaSpiskaSprEd->DM->ElementIDED->AsInt64;
				DM->TableNAMEED->AsString=FormaSpiskaSprEd->DM->ElementNAMEED->AsString;
				DM->TableKF_SPROD->AsFloat=FormaSpiskaSprEd->DM->ElementKFED->AsFloat;
				DM->Table->Post();
				}
		FormaSpiskaSprEd=0;
		}

if (number_procedure_end==ER_SezKf)//SezKF)
		{
		if (type_event==1)
				{
				DM->OpenTable(IdNom);
				}
		FormaSpiskaSprSezKFSProd=0;
		}

if (number_procedure_end==ER_Produce)
		{
		if (type_event==1)
				{
				EndViborProduce()  ;
				}
		FormaSpiskaSprProduce=0;
		}

if (number_procedure_end==ER_LossFactor)
		{
		if (type_event==1)
				{
				EndViborLossFactor()  ;
				}
		FormaSpiskaSprLossFactor=0;
		}


FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprSostProd::ToolButtonNewClick(TObject *Sender)
{
DM->NewElement(IdNomRest);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprSostProd::ToolButtonDeleteClick(TObject *Sender)
{
DM->DeleteElement();
}
//---------------------------------------------------------------------------


void  TFormaSpiskaSprSostProd::OpenFormSpiskaSprNom()
{
if (Nom==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&Nom);
		Nom->Init(InterfaceMainObject,InterfaceImpl);
		Nom->Vibor=true;
		Nom->UpdateForm();
		Nom->NumberProcVibor=ER_Nom;
        }
}
//----------------------------------------------------------------------------
void TFormaSpiskaSprSostProd::OpenFormSpiskaSprEd(void)
{
if (FormaSpiskaSprEd==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&FormaSpiskaSprEd);
		FormaSpiskaSprEd->Init(InterfaceMainObject,InterfaceImpl);
        FormaSpiskaSprEd->Vibor=true;
		FormaSpiskaSprEd->IdNom=DM->TableIDKOMPL_SPROD->AsInt64;
		FormaSpiskaSprEd->DM->OpenTable(DM->TableIDKOMPL_SPROD->AsInt64);
		//FormaSpiskaSprEd->LabelNom->Caption=DM->TableNAMENOM->AsString;
		//FormaSpiskaSprEd->HintLabel->Caption="Выберите единицу измерения ингридиента!";
		FormaSpiskaSprEd->NumberProcVibor=ER_Ed;
		}
}
//---------------------------------------------------------------------------




void __fastcall TFormaSpiskaSprSostProd::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprSostProd");	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprSostProd::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
        {
        Close();
        }
else
        {
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprSostProd::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{

OpenFormSpiskaSprNom();

}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprSostProd::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{

OpenFormSpiskaSprEd();

}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprSostProd::cxButtonSezKFClick(TObject *Sender)
{
if (FormaSpiskaSprSezKFSProd==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSezKFSProd.1",IID_IFormaSpiskaSprSezKFSProd,
													(void**)&FormaSpiskaSprSezKFSProd);
		FormaSpiskaSprSezKFSProd->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprSezKFSProd->Vibor=false;
		FormaSpiskaSprSezKFSProd->IdSProd=DM->TableID_SPROD->AsInt64;
		FormaSpiskaSprSezKFSProd->DM->OpenTable(DM->TableID_SPROD->AsInt64);
//		FormaSpiskaSprSezKFSProd->LabelNom->Caption="Сезонные К: "+DM->TableNAMENOM->AsString
//								+"\n для "+ LabelNom->Caption;
		FormaSpiskaSprSezKFSProd->NumberProcVibor=ER_SezKf;


		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprSostProd::cxButtonReportClick(TObject *Sender)
{
IFormaReportSostProd * Rep;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaReportSostProd.1",IID_IFormaReportSostProd,
													(void**)&Rep);
Rep->Init(InterfaceMainObject,InterfaceImpl);
Rep->IdNom=IdNom;
Rep->IdNomRest=DM->IdNomRest;
Rep->NameNom=LabelNom->Caption;
Rep->NameTypePrice=LabelNom->Caption;
Rep->UpdateForm();
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaSprSostProd::cxGrid1DBTableView1KeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
		{
if (Vibor==true)
        {
        Close();
        }
else
        {
		}
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprSostProd::ActionCloseExecute(TObject *Sender)
{
DM->CancelIsmen();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprSostProd::ActionOKExecute(TObject *Sender)
{
DM->SaveIsmen();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprSostProd::ActionSaveExecute(TObject *Sender)
{
DM->SaveIsmen();
DM->OpenTable(IdNomRest);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TFormaSpiskaSprSostProd::OpenFormaSpiskaSprProduce(void)
{
if (FormaSpiskaSprProduce==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprProduce,IID_IFormaSpiskaSprProduce,
													(void**)&FormaSpiskaSprProduce);
		FormaSpiskaSprProduce->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprProduce->Vibor=true;
		FormaSpiskaSprProduce->UpdateForm();
		FormaSpiskaSprProduce->NumberProcVibor=ER_Produce;
		}

}
//---------------------------------------------------------------------------
void TFormaSpiskaSprSostProd::OpenFormaSpiskaSprLossFactor(void)
{
if (FormaSpiskaSprLossFactor==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprLossFactor,IID_IFormaSpiskaSprLossFactor,
													(void**)&FormaSpiskaSprLossFactor);
		FormaSpiskaSprLossFactor->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprLossFactor->Vibor=true;
		FormaSpiskaSprLossFactor->UpdateForm();
		FormaSpiskaSprLossFactor->NumberProcVibor=ER_LossFactor;
		}

}
//---------------------------------------------------------------------------
void TFormaSpiskaSprSostProd::EndViborProduce(void)
{
DM->Table->Edit();
DM->TableIDPRODUCE_SSPROD->AsInt64=
						glStrToInt64(FormaSpiskaSprProduce->DM->ElementID_SPRODUCE->AsString);
DM->TableNAME_SPRODUCE->AsString=FormaSpiskaSprProduce->DM->ElementNAME_SPRODUCE->AsString;
DM->Table->Post();

}
//---------------------------------------------------------------------------
void TFormaSpiskaSprSostProd::EndViborLossFactor(void)
{
DM->Table->Edit();
DM->TableIDLOSTFACTOR_SSPROD->AsInt64=
						glStrToInt64(FormaSpiskaSprLossFactor->DM->ElementID_SLOSS_FACTOR->AsString);
DM->TableNAME_SLOSS_FACTOR->AsString=FormaSpiskaSprLossFactor->DM->ElementNAME_SLOSS_FACTOR->AsString;
DM->Table->Post();

}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprSostProd::cxGrid1DBTableView1NAME_SPRODUCEPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
OpenFormaSpiskaSprProduce();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprSostProd::cxGrid1DBTableView1NAME_SLOSS_FACTORPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
OpenFormaSpiskaSprLossFactor();
}
//---------------------------------------------------------------------------

