//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaDialoga.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "UDM.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "pFIBDatabase"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxGraphics"
#pragma link "cxLookupEdit"
#pragma link "FIBDataSet"
#pragma link "pFIBDataSet"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaDialoga::TFormaDialoga(TComponent* Owner)
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
bool TFormaDialoga::Init(void)
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


//Устанвливаем DataBase
pFIBTransaction1->DefaultDatabase=DM_Connection->pFIBData;
SpisokGrpKlient->Database=DM_Connection->pFIBData;
SpisokKlient->Database=DM_Connection->pFIBData;



//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;





PosNachcxDateEdit->Date=Date()-DayOf(Date())+1;
PosConcxDateEdit->Date=Date()+EncodeTime(23,59,59,999);


UpdateForm();

return result;
}

//---------------------------------------------------------------------------
int TFormaDialoga::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialoga::FormClose(TObject *Sender, TCloseAction &Action)
{
SpisokGrpKlient->Active=false;
SpisokKlient->Active=false;
if(FormaReport)FormaReport->Close();
Action=caFree;


if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TFormaDialoga::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{



return -1;
}
//-----------------------------------------------------------------------------
void TFormaDialoga::UpdateForm(void)
{
SpisokGrpKlient->Active=true;


}
//-----------------------------------------------------------------------------
void __fastcall TFormaDialoga::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialoga::cxButtonRunClick(TObject *Sender)
{
if (FormaReport==0)
	{
	SpisokKlient->First();
	SpisokKlient->MoveBy(NameKlientcxLookupComboBox->ItemIndex);

	FormaReport=new TFormaReport(Application);

	FormaReport->PosNach=PosNachcxDateEdit->Date;
	FormaReport->PosCon=PosConcxDateEdit->Date;
	FormaReport->IdKlient=StrToInt64(SpisokKlientIDKLIENT->AsString);
	FormaReport->NameKlient=SpisokKlientNAMEKLIENT->AsString;
	FormaReport->FOnCloseForm=EventCloseFormReport;

	    //Database
	FormaReport->ReportDataSet->Database=DM_Connection->pFIBData;
	FormaReport->pFIBTransaction1->DefaultDatabase=DM_Connection->pFIBData;

	FormaReport->DM_Connection=DM_Connection;


	FormaReport->UpdateForm();
	FormaReport->Show();
	}
//ShowMessage(SpisokGrpNomIDGN->AsString);
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialoga::EventCloseFormReport(TObject *Sender)
{

FormaReport=0;

}
//----------------------------------------------------------------------------


void __fastcall TFormaDialoga::cxLookupComboBox1PropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
SpisokGrpKlient->First();
SpisokGrpKlient->MoveBy(cxLookupComboBox1->ItemIndex);

SpisokKlient->Active=false;
SpisokKlient->ParamByName("PARAM_IDGRP")->AsString=
		SpisokGrpKlientIDGRPKL->AsString;
SpisokKlient->Active=true;
}
//---------------------------------------------------------------------------

