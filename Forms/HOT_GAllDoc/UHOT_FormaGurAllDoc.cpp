//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UHOT_FormaGurAllDoc.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IDMSetup.h"
#include "UFormIndicator.h"
#include "IHOT_FormaDocBron.h"
#include "IHOT_FormaDocRasm.h"
#include "IHOT_FormaDocReal.h"
#include "IHOT_FormaDocViezd.h"
#include "IHOT_FormaDocRaschet.h"
#include "IHOT_FormaDocOtmenaBron.h"
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
__fastcall THOT_FormaGurAllDoc::THOT_FormaGurAllDoc(TComponent* Owner)
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
bool THOT_FormaGurAllDoc::Init(void)
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


InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMGurAllDoc.1",IID_IHOT_DMGurAllDoc, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;

PosCon=Date()+EncodeTime(23,59,59,999);
PosNach=DM_Connection->GetPosNachGurnal();

DM->PosNach=PosNach;
DM->PosCon=PosCon;

IdKlient=0;
NameKlient="";
IdSklad=0;
NameSklad="";
IdFirm=0;
NameFirm="";
StringTypeDoc="''";

OtborPoKlientu=false;
OtborPoFirm=false;
OtborPoSklad=false;
OtborPoTypeDoc=false;

DM->OtborPoKlient=false;
DM->OtborPoFirm=false;
DM->OtborPoSklad=false;
DM->OtborPoTypeDoc=false;
DM->OpenTable();

StrOtborLabel->Caption="";

DM->Table->Last();
Vibor=false;
LabelInterval->Caption=DateTimeToStr(PosNach)+" - "+DateTimeToStr(PosCon);
if (DM_Connection->UserInfoNAME_USER->AsString!="SYSDBA")
		{
		 ToolButtonAllCancelDvReg->Visible=false;
		 ToolButtonDvRegDoc->Visible=false;
		 ToolButtonDelAllDoc->Visible=false;
		}

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int THOT_FormaGurAllDoc::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaGurAllDoc::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaViborPerioda)FormaViborPerioda->kanRelease();
if(FormaSetupOtbor)FormaSetupOtbor->kanRelease();


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
int THOT_FormaGurAllDoc::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ViborPerioda)
		{

		if (type_event==1)
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
				if(type_event==1)
                        {
                        IdKlient=FormaSetupOtbor->IdKlient;
                        NameKlient=FormaSetupOtbor->NameKlient;
                        IdSklad=FormaSetupOtbor->IdSklad;
                        NameSklad=FormaSetupOtbor->NameSklad;
						IdFirm=FormaSetupOtbor->IdFirm;
						NameFirm=FormaSetupOtbor->NameFirm;
						StringTypeDoc=FormaSetupOtbor->StringTypeDoc;
						NameTypeDoc=FormaSetupOtbor->NameTypeDoc;

						}
				FormaSetupOtbor=0;

				}

DM->UpdateTable();
return -1;
}
//--------------------------------------------------------------------------
void THOT_FormaGurAllDoc::OpenFormDoc()
{

if(DM->TableTDOC_HOT_GALLDOC->AsString=="BRON")
		{
		IHOT_FormaDocBron * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaDocBron.1",IID_IHOT_FormaDocBron,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->DM->OpenDoc(DM->TableID_HOT_GALLDOC->AsInt64);
		doc->UpdateForm();
		}

if(DM->TableTDOC_HOT_GALLDOC->AsString=="RASM")
		{
		IHOT_FormaDocRasm * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaDocRasm.1",IID_IHOT_FormaDocRasm,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->DM->OpenDoc(DM->TableID_HOT_GALLDOC->AsInt64);
		doc->UpdateForm();
		}

if(DM->TableTDOC_HOT_GALLDOC->AsString=="VIEZD")
		{
		IHOT_FormaDocViezd * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaDocViezd.1",IID_IHOT_FormaDocViezd,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->DM->OpenDoc(DM->TableID_HOT_GALLDOC->AsInt64);
		doc->UpdateForm();
		}

if(DM->TableTDOC_HOT_GALLDOC->AsString=="OTMBRON")
		{
		IHOT_FormaDocOtmenaBron * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaDocOtmenaBron.1",IID_IHOT_FormaDocOtmenaBron,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->DM->OpenDoc(DM->TableID_HOT_GALLDOC->AsInt64);
		doc->UpdateForm();
		}

if(DM->TableTDOC_HOT_GALLDOC->AsString=="REAL")
		{
		IHOT_FormaDocReal * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaDocReal.1",IID_IHOT_FormaDocReal,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->DM->OpenDoc(DM->TableID_HOT_GALLDOC->AsInt64);
		doc->UpdateForm();
		}

if(DM->TableTDOC_HOT_GALLDOC->AsString=="RASCHET")
		{
		IHOT_FormaDocRaschet * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaDocRaschet.1",IID_IHOT_FormaDocRaschet,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->DM->OpenDoc(DM->TableID_HOT_GALLDOC->AsInt64);
		doc->UpdateForm();
		}

}
//----------------------------------------------------------------------------

void __fastcall THOT_FormaGurAllDoc::FormResize(TObject *Sender)
{


StrOtborLabel->Left=cxGrid1->Left+cxGrid1->Width-StrOtborLabel->Width ;

}
//---------------------------------------------------------------------------


void __fastcall THOT_FormaGurAllDoc::ToolButtonDeleteClick(TObject *Sender)
{
DeleteDoc();
}
//---------------------------------------------------------------------------
void THOT_FormaGurAllDoc::DeleteDoc(void)
{

//******************************************************
if(DM->TableTDOC_HOT_GALLDOC->AsString=="BRON")
        {
		IHOT_DMDocBron * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMDocBron.1",IID_IHOT_DMDocBron,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(DM->TableID_HOT_GALLDOC->AsInt64);

		String V="Вы действительно хотите удалить документ Бронирование №"
		+doc->DocAllNUMBER_HOT_GALLDOC->AsString+" от "+doc->DocAllPOS_HOT_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

		if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)==glStrToInt64(doc->DocAllIDUSER_HOT_GALLDOC->AsString) ||
						   DM_Connection->UserInfoNAME_USER->AsString=="SYSDBA")
				{
				if (doc->DeleteDoc(glStrToInt64(DM->TableID_HOT_GALLDOC->AsString))==true)
						{
						DM->UpdateTable();
						}
				else
                        {
						ShowMessage("Не удалось удалить документ!");
                        }
                }
		else
				{
				ShowMessage("Нельзя удалять чужие документы!");
				}
		doc->kanRelease();
		return;
		}

//******************************************************
if(DM->TableTDOC_HOT_GALLDOC->AsString=="RASM")
        {
		IHOT_DMDocRasm * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMDocRasm.1",IID_IHOT_DMDocRasm,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_HOT_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ Размещение №"
		+doc->DocAllNUMBER_HOT_GALLDOC->AsString+" от "+doc->DocAllPOS_HOT_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

		if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)==glStrToInt64(doc->DocAllIDUSER_HOT_GALLDOC->AsString) ||
						   DM_Connection->UserInfoNAME_USER->AsString=="SYSDBA")
				{
				if (doc->DeleteDoc(glStrToInt64(DM->TableID_HOT_GALLDOC->AsString))==true)
						{
						DM->UpdateTable();
						}
				else
                        {
						ShowMessage("Не удалось удалить документ!");
                        }
                }
		else
				{
				ShowMessage("Нельзя удалять чужие документы!");
				}
		doc->kanRelease();
		return;
		}

//******************************************************
if(DM->TableTDOC_HOT_GALLDOC->AsString=="VIEZD")
        {
		IHOT_DMDocViezd * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMDocViezd.1",IID_IHOT_DMDocViezd,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_HOT_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ Выезд №"
		+doc->DocAllNUMBER_HOT_GALLDOC->AsString+" от "+doc->DocAllPOS_HOT_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

		if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)==glStrToInt64(doc->DocAllIDUSER_HOT_GALLDOC->AsString) ||
						   DM_Connection->UserInfoNAME_USER->AsString=="SYSDBA")
				{
				if (doc->DeleteDoc(glStrToInt64(DM->TableID_HOT_GALLDOC->AsString))==true)
						{
						DM->UpdateTable();
						}
				else
                        {
						ShowMessage("Не удалось удалить документ!");
                        }
                }
		else
				{
				ShowMessage("Нельзя удалять чужие документы!");
				}
		doc->kanRelease();
		return;
		}

//******************************************************


if(DM->TableTDOC_HOT_GALLDOC->AsString=="OTMBRON")
        {
		IHOT_DMDocOtmenaBron * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMDocOtmenaBron.1",IID_IHOT_DMDocOtmenaBron,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_HOT_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ Отмена брони №"
		+doc->DocAllNUMBER_HOT_GALLDOC->AsString+" от "+doc->DocAllPOS_HOT_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

		if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)==glStrToInt64(doc->DocAllIDUSER_HOT_GALLDOC->AsString) ||
						   DM_Connection->UserInfoNAME_USER->AsString=="SYSDBA")
				{
				if (doc->DeleteDoc(glStrToInt64(DM->TableID_HOT_GALLDOC->AsString))==true)
						{
						DM->UpdateTable();
						}
				else
                        {
						ShowMessage("Не удалось удалить документ!");
                        }
                }
		else
				{
				ShowMessage("Нельзя удалять чужие документы!");
				}
		doc->kanRelease();
		return;
		}

//******************************************************
if(DM->TableTDOC_HOT_GALLDOC->AsString=="REAL")
        {
		IHOT_DMDocReal * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMDocReal.1",IID_IHOT_DMDocReal,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_HOT_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ Реализация (гост.) №"
		+doc->DocAllNUMBER_HOT_GALLDOC->AsString+" от "+doc->DocAllPOS_HOT_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

		if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)==glStrToInt64(doc->DocAllIDUSER_HOT_GALLDOC->AsString) ||
						   DM_Connection->UserInfoNAME_USER->AsString=="SYSDBA")
				{
				if (doc->DeleteDoc(glStrToInt64(DM->TableID_HOT_GALLDOC->AsString))==true)
						{
						DM->UpdateTable();
						}
				else
                        {
						ShowMessage("Не удалось удалить документ!");
                        }
                }
		else
				{
				ShowMessage("Нельзя удалять чужие документы!");
				}
		doc->kanRelease();
		return;
		}


//******************************************************
if(DM->TableTDOC_HOT_GALLDOC->AsString=="RASCHET")
        {
		IHOT_DMDocRaschet * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMDocRaschet.1",IID_IHOT_DMDocRaschet,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_HOT_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ Расчет №"
		+doc->DocAllNUMBER_HOT_GALLDOC->AsString+" от "+doc->DocAllPOS_HOT_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

		if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)==glStrToInt64(doc->DocAllIDUSER_HOT_GALLDOC->AsString) ||
						   DM_Connection->UserInfoNAME_USER->AsString=="SYSDBA")
				{
				if (doc->DeleteDoc(glStrToInt64(DM->TableID_HOT_GALLDOC->AsString))==true)
						{
						DM->UpdateTable();
						}
				else
                        {
						ShowMessage("Не удалось удалить документ!");
                        }
                }
		else
				{
				ShowMessage("Нельзя удалять чужие документы!");
				}
		doc->kanRelease();
		return;
		}





}

//----------------------------------------------------------------------------
void __fastcall THOT_FormaGurAllDoc::ToolButtonOpenDvDocClick(TObject *Sender)
{

//TReportDvRegDoc * report=new TReportDvRegDoc();
//if (!report) return;
//report->IdDoc=DM->TableIDDOC->AsInteger;
//report->CreateReport();
//delete report;

}

//---------------------------------------------------------------------------
void __fastcall THOT_FormaGurAllDoc::ToolButton3Click(TObject *Sender)
{
if (DM->CancelDvRegDoc(Trim(DM->TableTDOC_HOT_GALLDOC->AsString),
		 glStrToInt64(DM->TableID_HOT_GALLDOC->AsString))==true)
		 {

		 }
else
	{
	ShowMessage("Не удалось отменить проведение документа! Ошибка"+DM->TextError);

	}
DM->UpdateTable();
}
//-----------------------------------------------------------------------------
void __fastcall THOT_FormaGurAllDoc::ToolButtonViborPeriodaClick(
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
		}
}
//---------------------------------------------------------------------------


void __fastcall THOT_FormaGurAllDoc::ToolButtonOpenDocClick(TObject *Sender)
{
OpenFormDoc();        
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaGurAllDoc::ToolButtonAllCancelDvRegClick(
      TObject *Sender)
{
        String V="Вы действительно хотите отменить проведение всех документов?";
        String Z="Подтверждение отмены проведения";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }

DM->Table->Last();
TFormIndicator * FormIndicator=new TFormIndicator(Application);
FormIndicator->Max=DM->Table->RecordCount;
FormIndicator->Step=1;
FormIndicator->LabelInfo->Caption="Проведение документов...";
FormIndicator->Start();
FormIndicator->Show();

DM->DataSourceTable->Enabled=false;

DM->Table->First();

while(!DM->Table->Eof)
        {

        try
                {
				if (DM->CancelDvRegDoc(Trim(DM->TableTDOC_HOT_GALLDOC->AsString), glStrToInt64(DM->TableID_HOT_GALLDOC->AsString))!=true)
                        {

                        V="Не удалось отменить проведение документа "+
								glGetNameDocHotel(DM->TableTDOC_HOT_GALLDOC->AsString)+
								"  №"+DM->TableNUMBER_HOT_GALLDOC->AsString+
								" от "+DM->TablePOS_HOT_GALLDOC->AsString +" Продолжить?";
                        Z="Ошибка отмены проведения документа!";
                        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                                {
                                 break;
                                }
                        }
                }
        catch (Exception &exception)
                {

                V="Ошибка при  отмене проведения документа \n"+
				glGetNameDoc(DM->TableTDOC_HOT_GALLDOC->AsString)+"  №"+DM->TableNUMBER_HOT_GALLDOC->AsString+
                " от "+DM->TablePOS_HOT_GALLDOC->AsString+
                "  "+exception.Message +" Продолжить?";
                Z="Ошибка отмены проведения документа!";
                if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                        {
                        break;
                        }

                }
        FormIndicator->StepIt();
        DM->Table->Next();
        }
DM->DataSourceTable->Enabled=true;


IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceImpl);
DMSetup->OpenElement(15);
if (DMSetup->ElementVALUE_SETUP->AsString=="")
        {
        }
else
        {

				if (DMSetup->GetKolProvDoc(DMSetup->ElementVALUE_SETUP->AsDateTime)==0)
                        {
                        DMSetup->Element->Edit();
                        DMSetup->ElementVALUE_SETUP->AsString="";
                        DMSetup->Element->Post();
                        DMSetup->SaveElement();
                        }
        }

DMSetup->kanRelease();
DM->UpdateTable();
delete FormIndicator;
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaGurAllDoc::ToolButtonDvRegDocClick(TObject *Sender)
{
        String V="Вы действительно хотите провести все документы?";
        String Z="Подтверждение  проведения документов";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }

DM->Table->First();
//проверим будет ли восстановлена последовательность
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,InterfaceImpl);
DMSetup->OpenElement(104);
if (DMSetup->ElementVALUE_SETUP->AsString=="")
        {
        }
else
        {
        if (DM->PosNach > DMSetup->ElementVALUE_SETUP->AsDateTime)
                {

                        V= "Граница последовательности меньше позиции начала  журнала! \n";
                        V=V+"Последовательность восстановлена не будет! Продолжить? ";
                        Z="Проведение документов";
                        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                                {
								DMSetup->kanRelease(); return;
                                }
                }
        }
//int kol_prov_doc=DMSetup->GetKolProvDoc(DM->TablePOSDOC->AsDateTime) ;
if (DMSetup->GetKolProvDocHotel(DM->PosNach)!=0)
        {
        V="Существуют более поздние проведенные документы! Последовательность восстановлена не будет! Продолжить? \n";
        Z="Проведение документов";
		DM->IBQ->Close();
		DM->IBQ->SelectSQL->Clear();
		DM->IBQ->SelectSQL->Add("select TDOC_HOT_GALLDOC, NUMBER_HOT_GALLDOC, POS_HOT_GALLDOC from HOT_GALLDOC where PR_HOT_GALLDOC>0  AND POS_HOT_GALLDOC>:PARAM_POSDOC");
        DM->IBQ->ParamByName("PARAM_POSDOC")->AsDateTime=DM->PosNach;
        DM->IBQ->Active=true;
        int kol=0;

        DM->IBQ->First();
        while(!DM->IBQ->Eof && kol<3)
                {
				V=V+glGetNameDocHotel(Trim(DM->IBQ->FieldByName("TDOC_HOT_GALLDOC")->AsString))
						+" №"+DM->IBQ->FieldByName("NUMBER_HOT_GALLDOC")->AsString
                        +" от "+DM->IBQ->FieldByName("POS_HOT_GALLDOC")->AsString+"\n";
                DM->IBQ->Next(); kol++;
				}
        DM->IBQ->Active=false;
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                delete DMSetup; return;
                }
		}
else  //будет восстановлена последовательность
	{ 
	DMSetup->OpenElement(104);
	if (DMSetup->ElementVALUE_SETUP->AsString=="")
        {
        }
	else
        {

				if (DMSetup->GetKolProvDocHotel(DMSetup->ElementVALUE_SETUP->AsDateTime)==0)
                        {
                        DMSetup->Element->Edit();
                        DMSetup->ElementVALUE_SETUP->AsString="";
                        DMSetup->Element->Post();
                        DMSetup->SaveElement();
                        }
		}
	}

DMSetup->kanRelease();

DM->Table->Last();
TFormIndicator * FormIndicator=new TFormIndicator(Application);
FormIndicator->Max=DM->Table->RecordCount;
FormIndicator->Step=1;
FormIndicator->Caption="Проведение документов...";
FormIndicator->Start();
FormIndicator->Show();

DM->DataSourceTable->Enabled=false;

DM->Table->First();
while(!DM->Table->Eof)
        {
		try
                {
				if (DM->DvRegDoc(Trim(DM->TableTDOC_HOT_GALLDOC->AsString), glStrToInt64(DM->TableID_HOT_GALLDOC->AsString))!=true)
                        {

                        V="Не удалось провести документ "+
								glGetNameDocHotel(DM->TableTDOC_HOT_GALLDOC->AsString)+
								"  №"+DM->TableNUMBER_HOT_GALLDOC->AsString+
								" от "+DM->TablePOS_HOT_GALLDOC->AsString +" Продолжить?";
                        Z="Ошибка проведения документа!";
                        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                                {
                                 break;
                                }
                        }
                }
        catch (Exception &exception)
                {

                V="Ошибка при  проведении документа \n"+
				glGetNameDocHotel(DM->TableTDOC_HOT_GALLDOC->AsString)+"  №"+DM->TableNUMBER_HOT_GALLDOC->AsString+
                " от "+DM->TablePOS_HOT_GALLDOC->AsString+
                "  "+exception.Message +" Продолжить?";
                Z="Ошибка проведения документа!";
                if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                        {
                        break;
                        }

                }
        FormIndicator->StepIt();
        DM->Table->Next();
        }
        
DM->DataSourceTable->Enabled=true;
DM->UpdateTable();
delete FormIndicator;
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaGurAllDoc::ToolButtonDelAllDocClick(TObject *Sender)
{
        String V="Вы действительно хотите удалить все документы?";
        String Z="Подтверждение удаления";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }

DM->Table->First();
while (!DM->Table->Eof)
        {
        DeleteAllDoc();
        DM->Table->Next();
        }

DM->UpdateTable();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void THOT_FormaGurAllDoc::DeleteAllDoc(void)
{
//if(DM->TableTDOC->AsString=="PRN")  //приход. накл.
//		{
//		TDMDocPrihNakl * PN=new TDMDocPrihNakl(Application);
//		if (!PN) return;
//		//настройка формы
//		PN->OpenDoc(DM->TableIDDOC->AsInteger);
//		PN->DeleteDoc(DM->TableIDDOC->AsInteger);
//		delete PN;
//		}

}
//--------------------------------------------------------------------------------

void __fastcall THOT_FormaGurAllDoc::ToolButtonOtborClick(TObject *Sender)
{

AnsiString s="";
if (ToolButtonOtbor->Down==true)  // включить отбор
        {
        DM->OtborVkl=true;

                        if (IdKlient>0) s=s+" Контрагент: "+NameKlient;
                        if (IdFirm>0) s=s+" Фирма: "+NameFirm;
                        if (IdSklad>0) s=s+" Склад: "+NameSklad;
                        if (StringTypeDoc!="") s=s+" Тип документов : "+NameTypeDoc;
                        StrOtborLabel->Caption=s;
        }
else
        {
        DM->OtborVkl=false;
        StrOtborLabel->Caption=s;
        }

DM->IdKlient=IdKlient;
DM->IdSklad=IdSklad;
DM->IdFirm=IdFirm;
DM->StringTypeDoc=StringTypeDoc;

DM->OtborPoKlient=OtborPoKlientu;
DM->OtborPoFirm=OtborPoFirm;
DM->OtborPoSklad=OtborPoSklad;
DM->OtborPoTypeDoc=OtborPoTypeDoc;
DM->UpdateTable();


}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaGurAllDoc::ToolButtonParamOtborClick(TObject *Sender)
{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSetupOtbor.1",IID_IFormaSetupOtbor,
													(void**)&FormaSetupOtbor);
		FormaSetupOtbor->Init(InterfaceMainObject,InterfaceImpl);
        if (!FormaSetupOtbor ) return;
		FormaSetupOtbor->NumberProcVibor=SetupOtborRekv;
}
//---------------------------------------------------------------------------



void __fastcall THOT_FormaGurAllDoc::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("Hotel/Gur/HOT_GurAllDoc");
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaGurAllDoc::ToolButtonRefreshClick(TObject *Sender)
{
DM->UpdateTable();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void THOT_FormaGurAllDoc::OpenPrintForm(void)
{
ISheetEditor *  PrintForm;
InterfaceGlobalCom->kanCreateObject("Oberon.SheetEditor.1", IID_ISheetEditor,
																	(void**)&PrintForm);


numRow=1;
numCol=1;
porNumStr=1;


//шапка
PrintForm->BeginUpdate();
OutputZagolovokReport(PrintForm);

//таблица
SumReport=0;
DM->Table->First();
while(!DM->Table->Eof)
        {

        OutputString(PrintForm);numRow++; porNumStr++;
        SumReport=SumReport+DM->TableSUM_HOT_GALLDOC->AsFloat;
        DM->Table->Next();
        }

OutputPodavalReport(PrintForm);
PrintForm->EndUpdate();

}
//---------------------------------------------------------------------------
void THOT_FormaGurAllDoc::OutputZagolovokReport(ISheetEditor *prForm)
{

prForm->SetColumnWidth(0,20);
prForm->SetColumnWidth(1,30);
prForm->SetColumnWidth(2,120);
prForm->SetColumnWidth(3,80);
prForm->SetColumnWidth(4,80);
prForm->SetColumnWidth(5,50);
prForm->SetColumnWidth(6,100);
prForm->SetColumnWidth(7,100);
prForm->SetColumnWidth(8,80);
prForm->SetColumnWidth(9,100);
prForm->DefaultFontSize=8;


numRow=1;
numCol=2;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Реестр документов с "+DateTimeToStr(PosNach)+" по "
				+DateTimeToStr(PosCon));
prForm->TecCell_SetFontSize(16);
prForm->TecCell_DeleteObject();
numRow++; numRow++;


//заголовок таблицы
numCol=1;
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("№");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Дата");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Фирма");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Документ");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Номер");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Склад");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Клиент");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Сумма");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Автор");
prForm->TecCell_SetFontSize(10);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
numRow++;
}
//------------------------------------------------------------------------------
void THOT_FormaGurAllDoc::OutputString(ISheetEditor *prForm)
{
numCol=1;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(porNumStr);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(DM->TablePOS_HOT_GALLDOC->AsString);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(DM->TableNAMEFIRM->AsString);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(glGetNameDocHotel(DM->TableTDOC_HOT_GALLDOC->AsString));
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(DM->TableNUMBER_HOT_GALLDOC->AsString);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
//cell->Text=DM->TableNAMESKLAD->AsString;
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(DM->TableNAMEKLIENT->AsString);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(FloatToStrF(DM->TableSUM_HOT_GALLDOC->AsFloat,ffFixed,10,2));
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(DM->TableNAME_USER->AsString);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
}


//------------------------------------------------------------------------------
void THOT_FormaGurAllDoc::OutputPodavalReport(ISheetEditor *prForm)
{
//
numRow++;
numCol=1;
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Всего документов :"+IntToStr(porNumStr-1)+" на сумму "
				+FloatToStr(SumReport)+"руб.");
prForm->TecCell_DeleteObject();


}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaGurAllDoc::ToolButton5Click(TObject *Sender)
{
OpenPrintForm();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaGurAllDoc::cxGrid1DBTableView1DblClick(TObject *Sender)
{
OpenFormDoc();
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaGurAllDoc::cxGrid1DBTableView1PR_HOT_GALLDOCCustomDrawCell(
      TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
      TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone)
{
AnsiString ATextToDraw;
if (dynamic_cast<TcxGridTableDataCellViewInfo *>(AViewInfo) != NULL)
	{
	ATextToDraw = AViewInfo->GridRecord->DisplayTexts[AViewInfo->Item->Index];
	}
else
	{
	ATextToDraw = VarAsType(AViewInfo->Item->Caption, varString);
	}

TRect ARec = AViewInfo->Bounds;
Graphics::TBitmap *ABitmap = new Graphics::TBitmap();
if (ATextToDraw==1)
	{
	ToolBar1->Images->GetBitmap(16,ABitmap);
	}
else
	{
	ToolBar1->Images->GetBitmap(17,ABitmap);
	}
ACanvas->Canvas->FillRect(ARec);
ACanvas->Canvas->Draw((ARec.Left+ARec.Right-ABitmap->Width)/2,ARec.Top,ABitmap);
ABitmap->Free();
ADone = true;
}
//---------------------------------------------------------------------------



