//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop


//----------------------------------------------------------------------------
#include "UREM_FormaGurAllDoc.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IDMSetup.h"
#include "IREM_FormaDocRemont.h"
#include "IREM_FormaDocRemontHW.h"
#include "IREM_FormaDocRemontKKT.h"
#include "IREM_DMDocRemont.h"
#include "IREM_DMDocRemontHW.h"
#include "IREM_DMDocRemontKKT.h"
#include "IREM_FormaDocKM1.h"
#include "IREM_FormaDocKM2.h"
#include "IREM_DMDocKM1.h"
#include "IREM_DMDocKM2.h"
#include "IREM_DMDocSetServKKT.h"
#include "IREM_FormaDocSetServKKT.h"
#include "IREM_DMDocSetServHW.h"
#include "IREM_FormaDocSetServHW.h"
#include "IREM_FormaDocPrihNakl.h"
#include "IREM_FormaDocReal.h"
#include "IREM_FormaDocOstNom.h"
#include "IREM_FormaDocSborkaKompl.h"

#include "IREM_FormaDocPostOtDilera.h"
#include "IREM_FormaDocVosvratDileru.h"
#include "IREM_FormaDocPerServCentr.h"
#include "IREM_FormaDocVosvratIsSC.h"

#include "IREM_FormaDocVosvratPok.h"
#include "IREM_FormaDocAkt.h"
#include "IREM_FormaDocPer.h"

#include "IREM_FormaDocZPost.h"
#include "IREM_FormaDocZVid.h"
#include "IREM_FormaDocZPer.h"
#include "IREM_FormaDocZStart.h"
#include "IREM_FormaDocZEnd.h"
#include "IREM_FormaDocZOper.h"
#include "IREM_FormaDocZTreb.h"
#include "IREM_FormaDocZAktPr.h"
#include "IREM_FormaDocZVosvrZap.h"

#include "IREM_FormaDocSpisNom.h"
#include "IREM_DMZayavka.h"


#include "IREM_FormaDocRegOtchetPost.h"

#include "IREM_FormaDocVidachaHW.h"
#include "IREM_FormaDocVosvratHW.h"

#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IFormaRunExternalModule.h"
#include "IClassCopyDoc.h"

#include "IREM_FormaDocVigruska.h"
#include "IREM_FormaDocProverka.h"
#include "IDMQueryRead.h"
#include "IREM_FormaDocZakazPost.h"
#include "IREM_FormaDocOtprPost.h"


#include "IREM_FormaDocVZipPer.h"
#include "IREM_FormaDocVZipVosvratPost.h"
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
#pragma link "cxButtonEdit"
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxLabel"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaGurAllDoc::TREM_FormaGurAllDoc(TComponent* Owner)
		: TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
TypeEvent=0;


		NameHardwarecxButtonEdit->Text="";
		SerNumHwcxLabel->Caption="";
		SerNum2HwcxLabel->Caption="";
		NameModelHwcxLabel->Caption="";


		NameZayavkacxButtonEdit->Text="";
		NameKlientcxLabel->Caption="";
		NameModelcxLabel->Caption="";
		SerNumcxLabel->Caption="";
		SerNum2cxLabel->Caption="";

		NoUpdateTable=false;
}
//---------------------------------------------------------------------------
bool TREM_FormaGurAllDoc::Init(void)
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


InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMGurAllDoc.1",IID_IREM_DMGurAllDoc, (void**)&DM);
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

//DM->OtborPoKlient=false;
//DM->OtborPoFirm=false;
//DM->OtborPoSklad=false;
//DM->OtborPoTypeDoc=false;
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

Vibor=false;

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaGurAllDocImpl),false);
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

DM_Connection->GetPrivForm(GCPRIV_FormaDocCheck);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_FormaGurAllDoc::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TREM_FormaGurAllDoc::UpdateForm(void)
{


		NameHardwarecxButtonEdit->Text=Hardware_Name;
		SerNumHwcxLabel->Caption=Hardware_SerNum;
		SerNum2HwcxLabel->Caption=Hardware_SerNum2;
		NameModelHwcxLabel->Caption=Hardware_NameModel;


		NameZayavkacxButtonEdit->Text=Zayavka_Name;
		NameKlientcxLabel->Caption=Zayavka_NameKlient;
		NameModelcxLabel->Caption=Zayavka_NameModel;
		SerNumcxLabel->Caption=Zayavka_SerNum;
		SerNum2cxLabel->Caption=Zayavka_SerNum2;

		DM->PosNach=PosNach;
		DM->PosCon=PosCon;
		LabelInterval->Caption=DateTimeToStr(PosNach)+" - "+DateTimeToStr(PosCon);


}
//---------------------------------------------------------------------------
void TREM_FormaGurAllDoc::OpenTable(void)
{

}
//----------------------------------------------------------------------------
void TREM_FormaGurAllDoc::UpdateTableAfterCloseDoc(void)
{
if (NoUpdateTable==false)
	{
	if (DM_Connection->UserInfoREOPEN_GUR_SUSER->AsInteger==1)
		{
		if (IdVibHardware==0 && IdVibZayavka==0)
			{
			DM->UpdateTable();
			}

		if (IdVibZayavka!=0)
			{
			DM->OpenTableOnlyZayavka(IdVibZayavka);
			}

		if (IdVibHardware!=0)
			{
			DM->OpenTableOnlyHardware(IdVibHardware);
			}

		}
	}
}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
if(FormaViborPerioda)FormaViborPerioda->kanRelease();
if(FormaSetupOtbor)FormaSetupOtbor->kanRelease();
if(FormaSpiskaSprHardware)FormaSpiskaSprHardware->kanRelease();
if(FormaGurZ)FormaGurZ->kanRelease();
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
DM->kanRelease();
Action=caFree;


if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TREM_FormaGurAllDoc::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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

if (number_procedure_end==ER_GurAllDoc)
		{
		if (type_event==1)
				{
				 EndViborDocGurAllDoc();
				}
		FormaGurAllDoc=0;
		}

if (number_procedure_end==ER_ViborHardware)
		{
		if (type_event==1)
				{
				EndViborHardware();
				}
		FormaSpiskaSprHardware=0;
		}

if (number_procedure_end==ER_Zayavka)
		{
		if (type_event==1)
				{
				EndViborRemZ();
				}
		FormaGurZ=0;
		}






if (DM_Connection->UserInfoREOPEN_GUR_SUSER->AsInteger==1)
	{
	if (IdVibHardware==0 && IdVibZayavka==0)
		{
		DM->UpdateTable();
		}
	}

return -1;
}
//--------------------------------------------------------------------------
void TREM_FormaGurAllDoc::OpenFormDoc()
{

if(DM->TableTDOC_REM_GALLDOC->AsString=="REMONT")
		{
		IREM_FormaDocRemont * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaDocRemont.1",IID_IREM_FormaDocRemont,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="REMONTHW")
		{
		IREM_FormaDocRemontHW * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaDocRemontHW.1",IID_IREM_FormaDocRemontHW,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="REMONTKKT")
		{
		IREM_FormaDocRemontKKT * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaDocRemontKKT.1",IID_IREM_FormaDocRemontKKT,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="KM1")
		{
		IREM_FormaDocKM1 * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaDocKM1.1",IID_IREM_FormaDocKM1,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="KM2")
		{
		IREM_FormaDocKM2 * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaDocKM2.1",IID_IREM_FormaDocKM2,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();

		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="SETSERVKKT")
		{
		IREM_FormaDocSetServKKT * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaDocSetServKKT.1",IID_IREM_FormaDocSetServKKT,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="SETSERVHW")
		{
		IREM_FormaDocSetServHW * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaDocSetServHW.1",IID_IREM_FormaDocSetServHW,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="REMPRN")
		{
		IREM_FormaDocPrihNakl * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocPrihNakl,IID_IREM_FormaDocPrihNakl,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="REMREAL")
		{
		IREM_FormaDocReal * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocReal,IID_IREM_FormaDocReal,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="REMOSN")
		{
		IREM_FormaDocOstNom * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocOstNom,IID_IREM_FormaDocOstNom,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="REMSBKOMPL")
		{
		IREM_FormaDocSborkaKompl * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocSborkaKompl,IID_IREM_FormaDocSborkaKompl,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="POSTOTDIL")
		{
		IREM_FormaDocPostOtDilera * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocPostOtDilera,IID_IREM_FormaDocPostOtDilera,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="VOSDILERU")
		{
		IREM_FormaDocVosvratDileru * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocVosvratDileru,IID_IREM_FormaDocVosvratDileru,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}



if(DM->TableTDOC_REM_GALLDOC->AsString=="PERSC")
		{
		IREM_FormaDocPerServCentr * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocPerServCentr,IID_IREM_FormaDocPerServCentr,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="VOSVISSC")
		{
		IREM_FormaDocVosvratIsSC * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocVosvratIsSC,IID_IREM_FormaDocVosvratIsSC,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="REMVPOK")
		{
		IREM_FormaDocVosvratPok * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocVosvratPok,IID_IREM_FormaDocVosvratPok,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="REMAKT")
		{
		IREM_FormaDocAkt * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocAkt,IID_IREM_FormaDocAkt,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="REMPER")
		{
		IREM_FormaDocPer * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocPer,IID_IREM_FormaDocPer,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}


if(DM->TableTDOC_REM_GALLDOC->AsString=="REMZPOST")
		{
		IREM_FormaDocZPost * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZPost,IID_IREM_FormaDocZPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="REMZVID")
		{
		IREM_FormaDocZVid * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZVid,IID_IREM_FormaDocZVid,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="REMZPER")
		{
		IREM_FormaDocZPer * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZPer,IID_IREM_FormaDocZPer,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="REMZSTART")
		{
		IREM_FormaDocZStart * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZStart,IID_IREM_FormaDocZStart,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="REMZEND")
		{
		IREM_FormaDocZEnd * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZEnd,IID_IREM_FormaDocZEnd,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="REMZOPER")
		{
		IREM_FormaDocZOper * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZOper,IID_IREM_FormaDocZOper,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}


if(DM->TableTDOC_REM_GALLDOC->AsString=="REMZTREB")
		{
		IREM_FormaDocZTreb * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZTreb,IID_IREM_FormaDocZTreb,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="REMZAKTPR")
		{
		IREM_FormaDocZAktPr * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZAktPr,IID_IREM_FormaDocZAktPr,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="REMZVZAP")
		{
		IREM_FormaDocZVosvrZap * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZVosvrZap,IID_IREM_FormaDocZVosvrZap,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}


if(DM->TableTDOC_REM_GALLDOC->AsString=="REMSPN")
		{
		IREM_FormaDocSpisNom * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocSpisNom,IID_IREM_FormaDocSpisNom,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}


if(DM->TableTDOC_REM_GALLDOC->AsString=="REM_RGOTCHPOST")
		{
		IREM_FormaDocRegOtchetPost * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocRegOtchetPost,IID_IREM_FormaDocRegOtchetPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="REM_VIDACHA_HW")
		{
		IREM_FormaDocVidachaHW * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocVidachaHW,IID_IREM_FormaDocVidachaHW,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="REM_VOSVRAT_HW")
		{
		IREM_FormaDocVosvratHW * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocVosvratHW,IID_IREM_FormaDocVosvratHW,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="REM_ZAKPOST")
		{
		IREM_FormaDocZakazPost * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZakazPost,IID_IREM_FormaDocZakazPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="REM_OTPRPOST")
		{
		IREM_FormaDocOtprPost * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocOtprPost,IID_IREM_FormaDocOtprPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="REM_VZPER")
		{
		IREM_FormaDocVZipPer * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocVZipPer,IID_IREM_FormaDocVZipPer,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}

if(DM->TableTDOC_REM_GALLDOC->AsString=="REM_VZVPO")
		{
		IREM_FormaDocVZipVosvratPost * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocVZipVosvratPost,IID_IREM_FormaDocVZipVosvratPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
		doc->UpdateForm();
		}
}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::FormResize(TObject *Sender)
{


StrOtborLabel->Left=cxGrid1->Left+cxGrid1->Width-StrOtborLabel->Width ;

}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaGurAllDoc::ToolButtonDeleteClick(TObject *Sender)
{
DeleteDoc();
}
//---------------------------------------------------------------------------
void TREM_FormaGurAllDoc::DeleteDoc(void)
{

////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REMONT")
		{
		IREM_DMDocRemont * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMDocRemont.1",IID_IREM_DMDocRemont,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ Ремонт №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}

////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REMONTHW")
		{
		IREM_DMDocRemontHW * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMDocRemontHW.1",IID_IREM_DMDocRemontHW,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ Ремонт оборудования №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}



////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REMONTKKT")
		{
		IREM_DMDocRemontKKT * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMDocRemontKKT.1",IID_IREM_DMDocRemontKKT,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ Ремонт ККТ №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}

////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="KM1")
		{
		IREM_DMDocKM1 * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMDocKM1.1",IID_IREM_DMDocKM1,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ акт КМ 1 №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}

////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="KM1")
		{
		IREM_DMDocKM2 * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMDocKM2.1",IID_IREM_DMDocKM2,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ акт КМ 2 №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}


////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="SETSERVKKT")
		{
		IREM_DMDocSetServKKT * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMDocSetServKKT.1",IID_IREM_DMDocSetServKKT,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ Cервис ККТ №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}


////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="SETSERVHW")
		{
		IREM_DMDocSetServHW * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMDocSetServHW.1",IID_IREM_DMDocSetServHW,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ Cервис оборудования №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}


////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REMPRN")
		{
		IREM_DMDocPrihNakl * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocPrihNakl,IID_IREM_DMDocPrihNakl,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ Приходная накладная (ремонт) №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}
////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REMREAL")
		{
		IREM_DMDocReal * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocReal,IID_IREM_DMDocReal,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ Реализация (ремонт) №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}

////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REMOSN")
		{
		IREM_DMDocOstNom * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocOstNom,IID_IREM_DMDocOstNom,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ Ввод остатков (ремонт) №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}

////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REMSBKOMPL")
		{
		IREM_DMDocSborkaKompl * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocSborkaKompl,IID_IREM_DMDocSborkaKompl,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ Сборка комплекта (ремонт) №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}




////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="POSTOTDIL")
		{
		IREM_DMDocPostOtDilera * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocPostOtDilera,IID_IREM_DMDocPostOtDilera,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ Поступление от дилера (ремонт) №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}

////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="VOSDILERU")
		{
		IREM_DMDocVosvratDileru * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocVosvratDileru,IID_IREM_DMDocVosvratDileru,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ Возврат дилеру №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}



////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="PERSC")
		{
		IREM_DMDocPerServCentr * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocPerServCentr,IID_IREM_DMDocPerServCentr,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ Передача в СЦ №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}

////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="VOSVISSC")
		{
		IREM_DMDocVosvratIsSC * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocVosvratIsSC,IID_IREM_DMDocVosvratIsSC,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ Возврат из СЦ №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}


		////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REMVPOK")
		{
		IREM_DMDocVosvratPok * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocVosvratPok,IID_IREM_DMDocVosvratPok,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ Возврат покупателя №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}


		////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REMAKT")
		{
		IREM_DMDocAkt * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocAkt,IID_IREM_DMDocAkt,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ Акт №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}


		////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REMPER")
		{
		IREM_DMDocPer * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocPer,IID_IREM_DMDocPer,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ Перемещение №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}



		////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REMZPOST")
		{
		IREM_DMDocZPost * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZPost,IID_IREM_DMDocZPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ "+
					glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString)+" №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}


		////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REMZVID")
		{
		IREM_DMDocZVid * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZVid,IID_IREM_DMDocZVid,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ "+
					glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString)+" №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}


		////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REMZPER")
		{
		IREM_DMDocZPer * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZPer,IID_IREM_DMDocZPer,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ "+
					glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString)+" №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}

		////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REMZSTART")
		{
		IREM_DMDocZStart * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZStart,IID_IREM_DMDocZStart,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ "+
					glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString)+" №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}

		////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REMZEND")
		{
		IREM_DMDocZEnd * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZEnd,IID_IREM_DMDocZEnd,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ "+
					glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString)+" №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}

		////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REMZOPER")
		{
		IREM_DMDocZOper * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZOper,IID_IREM_DMDocZOper,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ "+
					glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString)+" №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}


		////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REMZTREB")
		{
		IREM_DMDocZTreb * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZTreb,IID_IREM_DMDocZTreb,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ "+
					glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString)+" №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}

		////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REMZAKTPR")
		{
		IREM_DMDocZAktPr * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZAktPr,IID_IREM_DMDocZAktPr,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ "+
					glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString)+" №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}


		////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REMZVZAP")
		{
		IREM_DMDocZVosvrZap * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZVosvrZap,IID_IREM_DMDocZVosvrZap,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ "+
					glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString)+" №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}


				////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REMSPN")
		{
		IREM_DMDocSpisNom * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocSpisNom,IID_IREM_DMDocSpisNom,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));

		String V="Вы действительно хотите удалить документ "+
					glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString)+" №"
		+doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}







				////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REM_RGOTCHPOST")
		{


		String V="Вы действительно хотите удалить документ "+
					glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString)+" №"
		+DM->TableNUM_REM_GALLDOC->AsString+" от "+DM->TablePOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

		IREM_DMDocRegOtchetPost * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocRegOtchetPost,IID_IREM_DMDocRegOtchetPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));


				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}

				////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REM_VIDACHA_HW")
		{


		String V="Вы действительно хотите удалить документ "+
					glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString)+" №"
		+DM->TableNUM_REM_GALLDOC->AsString+" от "+DM->TablePOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

		IREM_DMDocVidachaHW * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocVidachaHW,IID_IREM_DMDocVidachaHW,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));


				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}

				////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REM_VOSVRAT_HW")
		{


		String V="Вы действительно хотите удалить документ "+
					glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString)+" №"
		+DM->TableNUM_REM_GALLDOC->AsString+" от "+DM->TablePOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

		IREM_DMDocVidachaHW * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocVosvratHW,IID_IREM_DMDocVosvratHW,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));


				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}

				////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REM_ZAKPOST")
		{


		String V="Вы действительно хотите удалить документ "+
					glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString)+" №"
		+DM->TableNUM_REM_GALLDOC->AsString+" от "+DM->TablePOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

		IREM_DMDocZakazPost * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZakazPost,IID_IREM_DMDocZakazPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));


				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}


				////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REM_OTPRPOST")
		{


		String V="Вы действительно хотите удалить документ "+
					glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString)+" №"
		+DM->TableNUM_REM_GALLDOC->AsString+" от "+DM->TablePOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

		IREM_DMDocOtprPost * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocOtprPost,IID_IREM_DMDocOtprPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));


				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}


				////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REM_VZPER")
		{


		String V="Вы действительно хотите удалить документ "+
					glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString)+" №"
		+DM->TableNUM_REM_GALLDOC->AsString+" от "+DM->TablePOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

		IREM_DMDocVZipPer * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocVZipPer,IID_IREM_DMDocVZipPer,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));


				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}



				////******************************************************
if(DM->TableTDOC_REM_GALLDOC->AsString=="REM_VZVPO")
		{


		String V="Вы действительно хотите удалить документ "+
					glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString)+" №"
		+DM->TableNUM_REM_GALLDOC->AsString+" от "+DM->TablePOS_REM_GALLDOC->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

		IREM_DMDocVZipVosvratPost * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocVZipVosvratPost,IID_IREM_DMDocVZipVosvratPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));


				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
						{
						UpdateTableAfterCloseDoc();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;
		}

}

//----------------------------------------------------------------------------
void __fastcall TREM_FormaGurAllDoc::ToolButtonOpenDvDocClick(TObject *Sender)
{

//TReportDvRegDoc * report=new TReportDvRegDoc();
//if (!report) return;
//report->IdDoc=DM->TableIDDOC->AsInt64;
//report->CreateReport();
//delete report;

}

//---------------------------------------------------------------------------
void __fastcall TREM_FormaGurAllDoc::ToolButton3Click(TObject *Sender)
{
if (DM->CancelDvRegDoc(Trim(DM->TableTDOC_REM_GALLDOC->AsString), glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
	{
	DM->UpdateTable();
	}
else
	{
    ShowMessage("Не удалось отменить проведение документа. Ошибка: "+DM->TextError);
	}

}
//-----------------------------------------------------------------------------
void __fastcall TREM_FormaGurAllDoc::ToolButtonViborPeriodaClick(
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


void __fastcall TREM_FormaGurAllDoc::ToolButtonOpenDocClick(TObject *Sender)
{
OpenFormDoc();        
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::ToolButtonAllCancelDvRegClick(
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
				if (DM->CancelDvRegDoc(Trim(DM->TableTDOC_REM_GALLDOC->AsString), glStrToInt64(DM->TableID_REM_GALLDOC->AsString))!=true)
                        {

                        V="Не удалось отменить проведение документа "+
								glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString)+
								"  №"+DM->TableNUM_REM_GALLDOC->AsString+
								" от "+DM->TablePOS_REM_GALLDOC->AsString +" Продолжить?";
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
				glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString)+"  №"+DM->TableNUM_REM_GALLDOC->AsString+
				" от "+DM->TablePOS_REM_GALLDOC->AsString+
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
DMSetup->OpenElement(315);
if (DMSetup->ElementVALUE_TIMESTAMP_SETUP->AsFloat==0)
        {
        }
else
        {

				if (DMSetup->GetKolProvDocRemont(DMSetup->ElementVALUE_TIMESTAMP_SETUP->AsFloat)==0)
                        {
                        DMSetup->Element->Edit();
						DMSetup->ElementVALUE_TIMESTAMP_SETUP->AsDateTime=0;
                        DMSetup->Element->Post();
                        DMSetup->SaveElement();
                        }
        }

DMSetup->kanRelease();
DM->UpdateTable();
delete FormIndicator;
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::ToolButtonDvRegDocClick(TObject *Sender)
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
DMSetup->OpenElement(315);
if (DMSetup->ElementVALUE_TIMESTAMP_SETUP->AsFloat==0)
        {
        }
else
        {
		if (DM->PosNach > DMSetup->ElementVALUE_TIMESTAMP_SETUP->AsDateTime)
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
if (DMSetup->GetKolProvDocRemont(DM->PosNach)!=0)
        {
        V="Существуют более поздние проведенные документы! Последовательность восстановлена не будет! Продолжить? \n";
        Z="Проведение документов";
		DM->IBQ->Close();
		DM->IBQ->SelectSQL->Clear();
		DM->IBQ->SelectSQL->Add("select TDOC_REM_GALLDOC, NUM_REM_GALLDOC, POS_REM_GALLDOC from REM_GALLDOC where PR_REM_GALLDOC>0  AND POS_REM_GALLDOC>:PARAM_POSDOC");
		DM->IBQ->ParamByName("PARAM_POSDOC")->AsDateTime=DM->PosNach;
		DM->IBQ->Active=true;
        int kol=0;

        DM->IBQ->First();
        while(!DM->IBQ->Eof && kol<3)
                {
				V=V+glGetNameDocRemont(Trim(DM->IBQ->FieldByName("TDOC_REM_GALLDOC")->AsString))
						+" №"+DM->IBQ->FieldByName("NUM_REM_GALLDOC")->AsString
                        +" от "+DM->IBQ->FieldByName("POS_REM_GALLDOC")->AsString+"\n";
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
	DMSetup->OpenElement(315);
	if (DMSetup->ElementVALUE_TIMESTAMP_SETUP->AsFloat==0)
        {
        }
	else
        {

				if (DMSetup->GetKolProvDoc(DMSetup->ElementVALUE_TIMESTAMP_SETUP->AsDateTime)==0)
                        {
                        DMSetup->Element->Edit();
                        DMSetup->ElementVALUE_TIMESTAMP_SETUP->AsString="";
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
				if (DM->DvRegDoc(Trim(DM->TableTDOC_REM_GALLDOC->AsString), glStrToInt64(DM->TableID_REM_GALLDOC->AsString))!=true)
                        {

                        V="Не удалось провести документ "+
								glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString)+
								"  №"+DM->TableNUM_REM_GALLDOC->AsString+
								" от "+DM->TablePOS_REM_GALLDOC->AsString +" Продолжить?";
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
				glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString)+"  №"+DM->TableNUM_REM_GALLDOC->AsString+
                " от "+DM->TablePOS_REM_GALLDOC->AsString+
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

void __fastcall TREM_FormaGurAllDoc::ToolButtonDelAllDocClick(TObject *Sender)
{
		String V="Вы действительно хотите удалить все документы?";
        String Z="Подтверждение удаления";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }
NoUpdateTable=true;

DM->Table->First();
while (!DM->Table->Eof)
        {
		DeleteDoc();
        DM->Table->Next();
        }


NoUpdateTable=false;

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TREM_FormaGurAllDoc::DeleteAllDoc(void)
{
//if(DM->TableTDOC->AsString=="PRN")  //приход. накл.
//		{
//		TDMDocPrihNakl * PN=new TDMDocPrihNakl(Application);
//		if (!PN) return;
//		//настройка формы
//		PN->OpenDoc(DM->TableIDDOC->AsInt64);
//		PN->DeleteDoc(DM->TableIDDOC->AsInt64);
//		delete PN;
//		}
//
//if(DM->TableTDOC->AsString=="CHK")   //чек ккм
//		{
//		TDMDocCheck * Check=new TDMDocCheck(Application);
//		if (!Check) return;
//		//настройка формы
//		Check->OpenDoc(DM->TableIDDOC->AsInt64);
//		Check->DeleteDoc(DM->TableIDDOC->AsInt64);
//		delete Check;
//		}


}
//--------------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::ToolButtonOtborClick(TObject *Sender)
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

//DM->OtborPoKlient=OtborPoKlientu;
//DM->OtborPoFirm=OtborPoFirm;
//DM->OtborPoSklad=OtborPoSklad;
//DM->OtborPoTypeDoc=OtborPoTypeDoc;
DM->UpdateTable();


}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::ToolButtonParamOtborClick(TObject *Sender)
{

		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSetupOtbor.1",IID_IREM_FormaSetupOtbor,
													(void**)&FormaSetupOtbor);
		FormaSetupOtbor->Init(InterfaceMainObject,InterfaceImpl);
        if (!FormaSetupOtbor ) return;
		//FormaSetupOtbor->IdRodForm=Handle;
        FormaSetupOtbor->NumberProcVibor=SetupOtborRekv;

}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaGurAllDoc::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("REM_GurAllDoc");	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::ToolButtonRefreshClick(TObject *Sender)
{
DM->UpdateTable();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void TREM_FormaGurAllDoc::OpenPrintForm(void)
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
        SumReport=SumReport+DM->TableSUM_REM_GALLDOC->AsFloat;
        DM->Table->Next();
        }

OutputPodavalReport(PrintForm);
PrintForm->EndUpdate();

}
//---------------------------------------------------------------------------
void TREM_FormaGurAllDoc::OutputZagolovokReport(ISheetEditor *prForm)
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
void TREM_FormaGurAllDoc::OutputString(ISheetEditor *prForm)
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
prForm->TecCell_SetText(DM->TablePOS_REM_GALLDOC->AsString);
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
prForm->TecCell_SetText(glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString));
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(DM->TableNUM_REM_GALLDOC->AsString);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(DM->TableNAMESKLAD->AsString);
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
prForm->TecCell_SetText(FloatToStrF(DM->TableSUM_REM_GALLDOC->AsFloat,ffFixed,10,2));
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
void TREM_FormaGurAllDoc::OutputPodavalReport(ISheetEditor *prForm)
{
numRow++;
numCol=1;
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText("Всего документов :"+IntToStr(porNumStr-1)+" на сумму "
				+FloatToStr(SumReport)+"руб.");
prForm->TecCell_DeleteObject();


}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaGurAllDoc::ToolButton5Click(TObject *Sender)
{
OpenPrintForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::cxGrid1DBTableView1DblClick(TObject *Sender)
{
if (Vibor==true)
	{
	TypeEvent=1;
	Close();
	}
else
	{
	OpenFormDoc();
	}
}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaGurAllDoc::cxGrid1DBTableView1PRDOCCustomDrawCell(
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

void __fastcall TREM_FormaGurAllDoc::cxGrid1DBTableView1KeyPress(TObject *Sender,
      char &Key)
{
if (Key==VK_RETURN)
		{
		if (Vibor==true)
			{
			TypeEvent=1;
			Close();
			}
		else
			{
			OpenFormDoc();
			}
		}
}
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TREM_FormaGurAllDoc::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaGurAllDoc::RunExternalModule(__int64 id_module, int type_module)
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
module->SetInt64Variables("glIdDoc", glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
module->SetDateTimeVariables("glPosBegin", PosNach);
  module->SetDateTimeVariables("glPosEnd", PosCon);

module->ExecuteModule();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaGurAllDoc::NewDocPrihNaklClick(TObject *Sender)
{
		IREM_FormaDocPrihNakl * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocPrihNakl,IID_IREM_FormaDocPrihNakl,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::NewDocRealClick(TObject *Sender)
{
		IREM_FormaDocReal * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocReal,IID_IREM_FormaDocReal,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::NewDocOstNomClick(TObject *Sender)
{
		IREM_FormaDocOstNom * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocOstNom,IID_IREM_FormaDocOstNom,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::NewDocSborkaKomplClick(TObject *Sender)
{
		IREM_FormaDocSborkaKompl * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocSborkaKompl,IID_IREM_FormaDocSborkaKompl,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::NewDocPostOtDileraClick(TObject *Sender)
{
		IREM_FormaDocPostOtDilera * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocPostOtDilera,IID_IREM_FormaDocPostOtDilera,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::NewDocVosvratDileruClick(TObject *Sender)
{
		IREM_FormaDocVosvratDileru * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocVosvratDileru,IID_IREM_FormaDocVosvratDileru,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::NewDocPerServCentrClick(TObject *Sender)
{
		IREM_FormaDocPerServCentr * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocPerServCentr,IID_IREM_FormaDocPerServCentr,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::NewDocVosvrstIsSCClick(TObject *Sender)
{
		IREM_FormaDocVosvratIsSC * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocVosvratIsSC,IID_IREM_FormaDocVosvratIsSC,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::NewDocVosvratPokClick(TObject *Sender)
{
		IREM_FormaDocVosvratPok * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocVosvratPok,IID_IREM_FormaDocVosvratPok,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::CreateNewDocAktPopupMenuClick(TObject *Sender)

{
		IREM_FormaDocAkt * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocAkt,IID_IREM_FormaDocAkt,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::CreateNewDocPerPopupMenuClick(TObject *Sender)

{
		IREM_FormaDocPer * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocPer,IID_IREM_FormaDocPer,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::PMCopyDocPerClick(TObject *Sender)
{
		IClassCopyDoc * cl_copy;
		InterfaceGlobalCom->kanCreateObject(ProgId_ClassCopyDoc,IID_IClassCopyDoc,
													(void**)&cl_copy);
		cl_copy->Init(InterfaceMainObject,InterfaceImpl);


		if (cl_copy->CreateNewCopyDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString),
								DM->TableTDOC_REM_GALLDOC->AsString,
								"REMPER",
								false, //сохранять документ
								true,  //открыть форму
								0,0,0)==true)
			{

			}
		else
			{
            ShowMessage(cl_copy->TextError);
			}


		cl_copy->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::CreateNewDocSpisNomPopupMenuClick(TObject *Sender)

{
		IREM_FormaDocSpisNom * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocSpisNom,IID_IREM_FormaDocSpisNom,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::PopupMenuCreateNaOsnDocPerClick(TObject *Sender)

{
TypeDoc="REMPER";
ViborDocGurAllDoc();
}
//---------------------------------------------------------------------------
//выбор документа из полного журнала
void TREM_FormaGurAllDoc::ViborDocGurAllDoc(void)
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
void __fastcall TREM_FormaGurAllDoc::EndViborDocGurAllDoc(void)
{

		IClassCopyDoc * cl_copy;
		InterfaceGlobalCom->kanCreateObject(ProgId_ClassCopyDoc,IID_IClassCopyDoc,
													(void**)&cl_copy);
		cl_copy->Init(InterfaceMainObject,InterfaceImpl);


		__int64 result=0;


		result=cl_copy->CreateNewDocNaOsn(glStrToInt64(FormaGurAllDoc->DM->TableIDDOC->AsString),
								FormaGurAllDoc->DM->TableTDOC->AsString,
								TypeDoc,  //тип нового документа
								false, //сохранять документ
								true,  //открыть форму
								0,0,0);


		if( result <= 0)
			{
			ShowMessage(cl_copy->TextError);
			}


		cl_copy->kanRelease();

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaGurAllDoc::PopupMenuCreateNaOsnDocOstNomClick(TObject *Sender)

{
TypeDoc="REMOSN";
ViborDocGurAllDoc();
}
//---------------------------------------------------------------------------
void TREM_FormaGurAllDoc::ViborHardware(void)
{

if (FormaSpiskaSprHardware==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprHardware.1",IID_IREM_FormaSpiskaSprHardware,
													(void**)&FormaSpiskaSprHardware);
		FormaSpiskaSprHardware->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprHardware) return;
		FormaSpiskaSprHardware->Vibor=true;
		FormaSpiskaSprHardware->NumberProcVibor=ER_ViborHardware;
		FormaSpiskaSprHardware->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaGurAllDoc::EndViborHardware(void)
{

IREM_DMSprHardware * spr_hw;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprHardware,IID_IREM_DMSprHardware,
													(void**)&spr_hw);
spr_hw->Init(InterfaceMainObject,InterfaceImpl);
spr_hw->OpenElement(glStrToInt64(FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString));


IdVibHardware=glStrToInt64(FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString);
NameHardwarecxButtonEdit->Text=FormaSpiskaSprHardware->DM->TableNAME_REM_SHARDWARE->AsString;


SerNumHwcxLabel->Caption=FormaSpiskaSprHardware->DM->TableSERNUM_REM_SHARDWARE->AsString;
SerNum2HwcxLabel->Caption=spr_hw->ElementSERNUM2_REM_SHARDWARE->AsString;
NameModelHwcxLabel->Caption=spr_hw->ElementNAME_REM_SMODEL->AsString;



spr_hw->kanRelease();
FormaSpiskaSprHardware=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();


}
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
//выбор заявки
void TREM_FormaGurAllDoc::ViborRemZ(void)
{

if (FormaGurZ==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaGurZ,IID_IREM_FormaGurZ,
													(void**)&FormaGurZ);
		FormaGurZ->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaGurZ) return;
		FormaGurZ->Vibor=true;
		FormaGurZ->NumberProcVibor=ER_Zayavka;
		}

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaGurAllDoc::EndViborRemZ(void)
{

IREM_DMZayavka *dm_z;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMZayavka,IID_IREM_DMZayavka, (void**)&dm_z);
dm_z->Init(InterfaceMainObject,InterfaceImpl);
dm_z->OpenDoc(glStrToInt64(FormaGurZ->DM->TableID_REM_Z->AsString));

IdVibZayavka=glStrToInt64(FormaGurZ->DM->TableID_REM_Z->AsString);
NameZayavkacxButtonEdit->Text=FormaGurZ->DM->TableNAME_REM_Z->AsString;

NameKlientcxLabel->Caption=FormaGurZ->DM->TableKLIENT_NAME_REM_Z->AsString;
NameModelcxLabel->Caption=FormaGurZ->DM->TableMODEL_REM_Z->AsString;
SerNumcxLabel->Caption=FormaGurZ->DM->TableSERNUM_REM_Z->AsString;
SerNum2cxLabel->Caption=FormaGurZ->DM->TableSERNUM2_REM_Z->AsString;
//	DM->DocNUM_REM_Z->AsString=FormaGurZ->DM->TableNUM_REM_Z->AsString;
//	DM->DocPOS_REM_Z->AsString=FormaGurZ->DM->TablePOS_REM_Z->AsString;
//
//	if (glStrToInt64(FormaGurZ->DM->TableIDKLIENT_REM_Z->AsString) > 0)
//		{
//		DM->DocIDKLIENT_REM_CQUERY->AsString=FormaGurZ->DM->TableIDKLIENT_REM_Z->AsString;
//		DM->DocNAMEKLIENT->AsString=FormaGurZ->DM->TableNAMEKLIENT->AsString;
//		}
//
//	DM->DocNAME_MODEL_REM_CQUERY->AsString=FormaGurZ->DM->TableMODEL_REM_Z->AsString;
//
//	if (DM->DocKLIENT_NAME_REM_CQUERY->AsString=="")
//		{
//		DM->DocKLIENT_NAME_REM_CQUERY->AsString=FormaGurZ->DM->TableKLIENT_NAME_REM_Z->AsString;
//		}
//	if (DM->DocKLIENT_ADR_REM_CQUERY->AsString=="")
//		{
//		DM->DocKLIENT_ADR_REM_CQUERY->AsString=dm_z->GurZKLIENT_ADR_REM_Z->AsString;
//		}
//
//	if (DM->DocKLIENT_PHONE_REM_CQUERY->AsString=="")
//		{
//		DM->DocKLIENT_PHONE_REM_CQUERY->AsString=dm_z->GurZKLIENT_PHONE_REM_Z->AsString;
//		}

dm_z->kanRelease();

FormaGurZ=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();


}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaGurAllDoc::NameZayavkacxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{


switch (AButtonIndex)
	{
	case 0:
		{
		ViborRemZ();
		}break;
	case 1:
		{
		IdVibZayavka=0;
		NameZayavkacxButtonEdit->Text="";
		NameKlientcxLabel->Caption="";
		NameModelcxLabel->Caption="";
		SerNumcxLabel->Caption="";
		SerNum2cxLabel->Caption="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::NameHardwarecxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{

switch (AButtonIndex)
	{
	case 0:
		{
		ViborHardware();
		}break;
	case 1:
		{
		IdVibHardware=0;
		NameHardwarecxButtonEdit->Text="";
		SerNumHwcxLabel->Caption="";
		SerNum2HwcxLabel->Caption="";
		NameModelHwcxLabel->Caption="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::cxButtonOtborPoZayavkaClick(TObject *Sender)

{
DM->OpenTableOnlyZayavka(IdVibZayavka);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::cxButtonOtborPoHardwareClick(TObject *Sender)

{
DM->OpenTableOnlyHardware(IdVibHardware);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::CreateNewDocRegOtchetPostPopupMenuClick(TObject *Sender)

{
		IREM_FormaDocRegOtchetPost * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocRegOtchetPost,IID_IREM_FormaDocRegOtchetPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::PMCopyAktInAktClick(TObject *Sender)
{
		IClassCopyDoc * cl_copy;
		InterfaceGlobalCom->kanCreateObject(ProgId_ClassCopyDoc,IID_IClassCopyDoc,
													(void**)&cl_copy);
		cl_copy->Init(InterfaceMainObject,InterfaceImpl);


		if (cl_copy->CreateNewCopyDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString),
								DM->TableTDOC_REM_GALLDOC->AsString,
								"REMAKT",
								false, //сохранять документ
								true,  //открыть форму
								0,0,0)==true)
			{

			}
		else
			{
            ShowMessage(cl_copy->TextError);
			}


		cl_copy->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::CreateNewDocVidachaHWPopupMenuClick(TObject *Sender)

{
		IREM_FormaDocVidachaHW * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocVidachaHW,IID_IREM_FormaDocVidachaHW,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::CreateNewDocVosvratHWPopupMenuClick(TObject *Sender)

{
		IREM_FormaDocVosvratHW * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocVosvratHW,IID_IREM_FormaDocVosvratHW,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaGurAllDoc::cxGrid1DBTableView1IDDOC_REM_GUR_VIGRTCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone)
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

if (glStrToInt64(ATextToDraw) > 0) //есть запрос
	{
	ToolBar1->Images->GetBitmap(70,ABitmap);
	}
else
	{
	//ToolBar1->Images->GetBitmap(17,ABitmap);
	}

ACanvas->Canvas->FillRect(ARec);
ACanvas->Canvas->Draw((ARec.Left+ARec.Right-ABitmap->Width)/2,ARec.Top,ABitmap);
ABitmap->Free();
ADone = true;
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::ToolButtonCreateDocProverkaClick(TObject *Sender)

{

//сначала надо попытаться найти старую проверку
IDMQueryRead * dm_qr;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&dm_qr);
dm_qr->Init(InterfaceMainObject,0);
dm_qr->pFIBQ->Close();
dm_qr->pFIBQ->SQL->Clear();

UnicodeString zapros=
"select rem_gur_prov.id_rem_gur_prov                                   \
			from rem_gur_prov                                          \
			where rem_gur_prov.iddoc_rem_gur_prov=:PARAM_IDDOC ";

dm_qr->pFIBQ->SQL->Add(zapros);
dm_qr->pFIBQ->ParamByName("PARAM_IDDOC")->AsString=DM->TableID_REM_GALLDOC->AsString;
dm_qr->pFIBQ->ExecQuery();
__int64 id_prov=0;
id_prov=glStrToInt64(dm_qr->pFIBQ->FieldByName("id_rem_gur_prov")->AsString);
dm_qr->pFIBQ->Close();
dm_qr->kanRelease();





		IREM_FormaDocProverka * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocProverka,IID_IREM_FormaDocProverka,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
	   if (id_prov == 0)
		{
			if (doc->DM->NewDoc() !=true)
				{
				ShowMessage("Ошибка при создании документа " + doc->DM->TextError);
				doc->kanRelease();
				}
			else
				{
				doc->DM->DocAll->Edit();
				doc->DM->DocAllIDDOC_REM_GUR_PROV->AsString=DM->TableID_REM_GALLDOC->AsString;
				doc->DM->DocAllIDBASE_REM_GUR_PROV->AsString=DM->TableIDBASE_REM_GALLDOC->AsString;
				doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=DM->TableNAME_SINFBASE_OBMEN->AsString;
				doc->DM->DocAllNAMEFIRM->AsString=DM->TableNAMEFIRM->AsString;
				doc->DM->DocAllNAMESKLAD->AsString=DM->TableNAMESKLAD->AsString;
				doc->DM->DocAllNAMEKLIENT->AsString=DM->TableNAMEKLIENT->AsString;
				doc->DM->DocAllPREFIKS_NUM_REM_GALLDOC->AsString=DM->TablePREFIKS_NUM_REM_GALLDOC->AsString;
				doc->DM->DocAllNUM_REM_GALLDOC->AsString=DM->TableNUM_REM_GALLDOC->AsString;
				doc->DM->DocAllPOS_REM_GALLDOC->AsString=DM->TablePOS_REM_GALLDOC->AsString;
				doc->DM->DocAll->Post();
				doc->UpdateForm();
				}
		}
	else
		{
			if (doc->DM->OpenDoc(id_prov) == true)
				{
                 doc->UpdateForm();
				}
			else
				{
				ShowMessage("Ошибка при открытии документа " + doc->DM->TextError);
				doc->kanRelease();
				}

		}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::cxGrid1DBTableView1RES_REM_GUR_PROVCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone)
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

if (ATextToDraw==1) //ОК
	{
	ToolBar1->Images->GetBitmap(74,ABitmap);
	}
else if (ATextToDraw==2)  //ошибка
	{
	ToolBar1->Images->GetBitmap(78,ABitmap);
	}
else
	{

	}

ACanvas->Canvas->FillRect(ARec);
ACanvas->Canvas->Draw((ARec.Left+ARec.Right-ABitmap->Width)/2,ARec.Top,ABitmap);
ABitmap->Free();
ADone = true;
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::CreateDocZakazPostClick(TObject *Sender)
{
		IREM_FormaDocZakazPost * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZakazPost,IID_IREM_FormaDocZakazPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaGurAllDoc::ToolButtonCreateDocVigrClick(TObject *Sender)

{
//сначала надо попытаться найти старую проверку
IDMQueryRead * dm_qr;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&dm_qr);
dm_qr->Init(InterfaceMainObject,0);
dm_qr->pFIBQ->Close();
dm_qr->pFIBQ->SQL->Clear();

UnicodeString zapros=
"select rem_gur_vigrt.iddoc_rem_gur_vigrt                              \
			from rem_gur_vigrt                                         \
			where rem_gur_vigrt.iddocvigr_rem_gur_vigrt=:PARAM_IDDOC ";

dm_qr->pFIBQ->SQL->Add(zapros);
dm_qr->pFIBQ->ParamByName("PARAM_IDDOC")->AsString=DM->TableID_REM_GALLDOC->AsString;
dm_qr->pFIBQ->ExecQuery();
__int64 id_vigr=0;
id_vigr=glStrToInt64(dm_qr->pFIBQ->FieldByName("iddoc_rem_gur_vigrt")->AsString);
dm_qr->pFIBQ->Close();
dm_qr->kanRelease();





		IREM_FormaDocVigruska * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocVigruska,IID_IREM_FormaDocVigruska,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
	   if (id_vigr == 0)
		{
			if (doc->DM->NewDoc() !=true)
				{
				ShowMessage("Ошибка при создании документа " + doc->DM->TextError);
				doc->kanRelease();
				}
			else
				{
				doc->DM->DocAll->Edit();
				doc->DM->DocAllIDBASE_REM_GUR_VIGR->AsString=DM->TableIDBASE_REM_GALLDOC->AsString;
				doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=DM->TableNAME_SINFBASE_OBMEN->AsString;
				doc->DM->DocAll->Post();

				doc->DM->DocT->Append();
				doc->DM->DocT->Edit();
				doc->DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString=DM->TableID_REM_GALLDOC->AsString;

				doc->DM->DocTNAMEFIRM->AsString=DM->TableNAMEFIRM->AsString;
				doc->DM->DocTNAMESKLAD->AsString=DM->TableNAMESKLAD->AsString;
				doc->DM->DocTNAMEKLIENT->AsString=DM->TableNAMEKLIENT->AsString;
				doc->DM->DocTPREFIKS_NUM_REM_GALLDOC->AsString=DM->TablePREFIKS_NUM_REM_GALLDOC->AsString;
				doc->DM->DocTNUM_REM_GALLDOC->AsString=DM->TableNUM_REM_GALLDOC->AsString;
				doc->DM->DocTPOS_REM_GALLDOC->AsString=DM->TablePOS_REM_GALLDOC->AsString;

				doc->DM->DocT->Post();
				doc->UpdateForm();
				}
		}
	else
		{
			if (doc->DM->OpenDoc(id_vigr) == true)
				{
                 doc->UpdateForm();
				}
			else
				{
				ShowMessage("Ошибка при открытии документа " + doc->DM->TextError);
				doc->kanRelease();
				}

		}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::N1Click(TObject *Sender)
{
		IREM_FormaDocVZipPer * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocVZipPer,IID_IREM_FormaDocVZipPer,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::N2Click(TObject *Sender)
{
		IREM_FormaDocVZipVosvratPost * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocVZipVosvratPost,IID_IREM_FormaDocVZipVosvratPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurAllDoc::ToolButtonZapolnPoNZClick(TObject *Sender)
{
DM->Table->Active=false;                                                                                                             \
UnicodeString zapros="select rem_gall_get_tbl_po_z_neprobit.*,                                                                       \
			 NAMEFIRM, NAMESKLAD, NAMEKLIENT, NAME_USER,                                                                             \
			 sinfbase_obmen.name_sinfbase_obmen,                                                                                     \
			rem_gur_prov.id_rem_gur_prov,                                                                                            \
			rem_gur_prov.res_rem_gur_prov,                                                                                           \
			rem_gur_vigrt.iddoc_rem_gur_vigrt                                                                                         \
			from rem_gall_get_tbl_po_z_neprobit(0,:PARAM_POSNACH,:PARAM_POSCON)                                                         \
			left outer join rem_z on rem_z.id_rem_z = rem_gall_get_tbl_po_z_neprobit.out_idz                                         \
			left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=rem_gall_get_tbl_po_z_neprobit.IDBASE_REM_GALLDOC                    \
			LEFT OUTER JOIN SFIRM ON IDFIRM_REM_GALLDOC = IDFIRM                                                                     \
			left outer join SSKLAD on IDSKLAD_REM_GALLDOC = IDSKLAD                                                                  \
			left outer join SKLIENT on IDKLIENT_REM_GALLDOC =IDKLIENT                                                                \
			left outer join SUSER on  rem_gall_get_tbl_po_z_neprobit.IDUSER_REM_GALLDOC = SUSER.ID_USER                              \
			left outer join rem_gur_prov on rem_gall_get_tbl_po_z_neprobit.id_rem_galldoc= rem_gur_prov.iddoc_rem_gur_prov           \
			left outer join rem_gur_vigrt on rem_gall_get_tbl_po_z_neprobit.id_rem_galldoc= rem_gur_vigrt.iddocvigr_rem_gur_vigrt    \
where rem_z.idbase_rem_z=1 and (rem_gall_get_tbl_po_z_neprobit.tdoc_rem_galldoc='REMONT'                                            \
                                or rem_gall_get_tbl_po_z_neprobit.tdoc_rem_galldoc='REMZPOST'                                       \
								or rem_gall_get_tbl_po_z_neprobit.tdoc_rem_galldoc='REMZVID') ";
DM->Table->SelectSQL->Clear();
DM->Table->SelectSQL->Add(zapros);
DM->Table->ParamByName("PARAM_POSNACH")->AsDateTime=PosNach;
DM->Table->ParamByName("PARAM_POSCON")->AsDateTime=PosCon;
DM->Table->Active=true;
}
//---------------------------------------------------------------------------

