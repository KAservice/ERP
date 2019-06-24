//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaGurLog.h"
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
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaGurLog::TFormaGurLog(TComponent* Owner)
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
bool TFormaGurLog::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMGurLog.1",IID_IDMGurLog, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;

PosCon=Date()+EncodeTime(23,59,59,999);
PosNach=DM_Connection->GetPosNachGurnal();

DM->PosNach=PosNach;
DM->PosCon=PosCon;


DM->OpenTable();

StrOtborLabel->Caption="";



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
int TFormaGurLog::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaGurLog::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaViborPerioda)FormaViborPerioda->kanRelease();
//if(FormaSetupOtbor)FormaSetupOtbor->Close();


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
int TFormaGurLog::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{


		if (number_procedure_end==ViborPerioda)
                {
				if(type_event==1)
                        {
						PosNach=FormaViborPerioda->PosNach;
						PosCon=FormaViborPerioda->PosCon;
                        DM->PosNach=PosNach;
                        DM->PosCon=PosCon;
                        LabelInterval->Caption=DateTimeToStr(PosNach)+" - "+DateTimeToStr(PosCon);
                        }
                FormaViborPerioda=0;

                }

		if (number_procedure_end==SetupOtborRekv)
                {
//                if(FormaSetupOtbor->OutReady==true)
//						{
//						IdKlient=FormaSetupOtbor->IdKlient;
//						NameKlient=FormaSetupOtbor->NameKlient;
//						IdSklad=FormaSetupOtbor->IdSklad;
//						NameSklad=FormaSetupOtbor->NameSklad;
//						IdFirm=FormaSetupOtbor->IdFirm;
//						NameFirm=FormaSetupOtbor->NameFirm;
//						StringTypeDoc=FormaSetupOtbor->StringTypeDoc;
//						NameTypeDoc=FormaSetupOtbor->NameTypeDoc;
//
//						}
//				FormaSetupOtbor=0;

				}

		ViborRekv=NO;


DM->UpdateTable();
return -1;
}

//----------------------------------------------------------------------------

void __fastcall TFormaGurLog::ToolButtonViborPeriodaClick(
      TObject *Sender)
{
if (FormaViborPerioda==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaViborPerioda.1",IID_IFormaViborPerioda,
													(void**)&FormaViborPerioda);
		FormaViborPerioda->Init(InterfaceMainObject,InterfaceImpl);
		FormaViborPerioda->NumberProcVibor=ViborPerioda;
		FormaViborPerioda->PosNach=PosNach;
		FormaViborPerioda->PosCon=PosCon;
//        FormaViborPerioda->Time1->Time=FormaViborPerioda->DateTimePicker1->Time;
//		FormaViborPerioda->Time2->Time=FormaViborPerioda->DateTimePicker2->Time;
		}
}
//--------------------------------------------------------------------------------

void __fastcall TFormaGurLog::ToolButtonOtborClick(TObject *Sender)
{

//AnsiString s="";
//if (ToolButtonOtbor->Down==true)  // включить отбор
//        {
//		DM->OtborVkl=true;
//
//						if (IdKlient>0) s=s+" Контрагент: "+NameKlient;
//                        if (IdFirm>0) s=s+" Фирма: "+NameFirm;
//						if (IdSklad>0) s=s+" Склад: "+NameSklad;
//                        if (StringTypeDoc!="") s=s+" Тип документов : "+NameTypeDoc;
//						StrOtborLabel->Caption=s;
//        }
//else
//		{
//		DM->OtborVkl=false;
//		StrOtborLabel->Caption=s;
//		}
//
//DM->IdKlient=IdKlient;
//DM->IdSklad=IdSklad;
//DM->IdFirm=IdFirm;
//DM->StringTypeDoc=StringTypeDoc;
//
//DM->OtborPoKlient=OtborPoKlientu;
//DM->OtborPoFirm=OtborPoFirm;
//DM->OtborPoSklad=OtborPoSklad;
//DM->OtborPoTypeDoc=OtborPoTypeDoc;
//DM->UpdateTable();


}
//---------------------------------------------------------------------------

void __fastcall TFormaGurLog::ToolButtonParamOtborClick(TObject *Sender)
{
//		FormaSetupOtbor =new TFormaSetupOtbor (Application);
//		if (!FormaSetupOtbor ) return;
//		//FormaSetupOtbor->IdRodForm=Handle;
//		IdDochForm=FormaSetupOtbor ->Handle;
//		ViborRekv=SetupOtborRekv;
//		FormaSetupOtbor->FOnCloseForm=EndEdit;
//		FormaSetupOtbor->Show();
}
//---------------------------------------------------------------------------



void __fastcall TFormaGurLog::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("GurLog");
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurLog::ToolButtonRefreshClick(TObject *Sender)
{
DM->UpdateTable();
}
//---------------------------------------------------------------------------

