//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaPodboraNom.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxButtonEdit"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCalc"
#pragma link "cxDropDownEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaPodboraNom::TFormaPodboraNom(TComponent* Owner)
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
bool TFormaPodboraNom::Init(void)
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
IdNom=0;
Price=0;
PriceBasEd=0;
Kol=0;
Summa=0;
IdEd=0;
NameEd="";
KFEd=0;
NameNom="";
UpdateForm();

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
int TFormaPodboraNom::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaPodboraNom::UpdateForm(void)
{
NameNomLabel->Caption=NameNom;

NameEdEdit->Text=NameEd;
KolEdit->Text=FloatToStr(Kol);
PriceEdit->Text=FloatToStr(Price);
SummaEdit->Text=FloatToStr(Summa);
LabelKF->Caption="КФ:"+FloatToStrF(KFEd,ffFixed,14,3);

}
//---------------------------------------------------------------------------
void __fastcall TFormaPodboraNom::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(Ed)Ed->kanRelease();
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

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void TFormaPodboraNom:: OpenFormSpiskaSprEd(void)
{
if (Ed==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&Ed);
		Ed->Init(InterfaceMainObject,InterfaceImpl);
		Ed->Vibor=true;
        Ed->IdNom=IdNom;
        Ed->DM->OpenTable(IdNom);
//        Ed->LabelNom->Caption="Единицы номенклатуры: "+NameNom;
//		Ed->HintLabel->Caption="Выберите единицу номенклатуры ";

		Ed->NumberProcVibor=1;
		Visible=false;
		}
}
//-------------------------------------------------------------------------------
int TFormaPodboraNom::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==1)
		{
		if (type_event==1)
				{
				IdEd=Ed->DM->ElementIDED->AsInt64;
				NameEd=Ed->DM->Element->FieldByName("NAMEED")->AsString;
				KFEd=Ed->DM->ElementKFED->AsFloat;
				Kol=1;
				Price=PriceBasEd*KFEd;
				Summa=Price*Kol;
				UpdateForm();
				}
		Ed=0;
		}

Visible=true;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------













void __fastcall TFormaPodboraNom::NameEdEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprEd();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaPodboraNom::NameEdEditKeyPress(TObject *Sender, char &Key)
{
if (Key==VK_RETURN)
		{
		OpenFormSpiskaSprEd();
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaPodboraNom::KolEditKeyPress(TObject *Sender, char &Key)
{
if (Key==VK_RETURN)
		{
		Kol=StrToFloat(KolEdit->Text);
		Summa=Kol*Price;
		UpdateForm();
		PriceEdit->SetFocus();
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaPodboraNom::KolEditExit(TObject *Sender)
{
        Kol=StrToFloat(KolEdit->Text);
        Summa=Kol*Price;
        UpdateForm();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaPodboraNom::PriceEditKeyPress(TObject *Sender, char &Key)
{
if (Key==VK_RETURN)
		{
		Price=StrToFloat(PriceEdit->Text);
		Summa=Kol*Price;
		UpdateForm();
		SummaEdit->SetFocus();
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaPodboraNom::PriceEditExit(TObject *Sender)
{
		Price=StrToFloat(PriceEdit->Text);
		Summa=Kol*Price;
		UpdateForm();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaPodboraNom::SummaEditKeyPress(TObject *Sender, char &Key)
{
if (Key==VK_RETURN)
		{
		Summa=StrToFloat(SummaEdit->Text);
		if (Kol!=0)
				{
				Price=Summa/Kol;
				}
		UpdateForm();
		TypeEvent=1;
		Close();
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaPodboraNom::SummaEditExit(TObject *Sender)
{
		Summa=StrToFloat(SummaEdit->Text);
		if (Kol!=0)
				{
				Price=Summa/Kol;
				}
		UpdateForm();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaPodboraNom::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaPodboraNom::ActionOKExecute(TObject *Sender)
{
TypeEvent=1;
Close();
}
//---------------------------------------------------------------------------

