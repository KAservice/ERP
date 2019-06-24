//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//--------------------------------------------------------------------------
#include "UREM_FormaDocVigruska.h"
#include "IDMSprPrice.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IDMSprPrice.h"
#include "IFormaRunExternalModule.h"
#include "IDMSetup.h"
#include "IREM_DMGurAllDoc.h"
#include "IDMQueryRead.h"

// документы


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


#include "IREM_FormaDocRegOtchetPost.h"

#include "IREM_FormaDocVidachaHW.h"
#include "IREM_FormaDocVosvratHW.h"

//------------------------------------------
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
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxLookupEdit"
#pragma link "cxDBLabel"
#pragma link "cxGridBandedTableView"
#pragma link "cxGridDBBandedTableView"
#pragma link "cxLookAndFeels"
#pragma link "cxImageComboBox"
#pragma link "cxMemo"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TREM_FormaDocVigruska::TREM_FormaDocVigruska(TComponent* Owner)
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
bool TREM_FormaDocVigruska::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocVigruska,IID_IREM_DMDocVigruska, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;

DBTextFNameUser->DataSource=DM->DataSourceDocAll;

NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;

NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;

ProducercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
GUID_TRANScxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
CodeVigrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
GUIDVigrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;




Prosmotr=false;    //только просмотр
IdDoc=0;           //идентификатор текущей записи

ActionOperation=aoNO;


PosStartcxDateEdit->Date=Date()-5;
PosEndcxDateEdit->Date=Date()+EncodeTime(23,59,59,999);


//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaDocVigruskaImpl),false);
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
int TREM_FormaDocVigruska::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void TREM_FormaDocVigruska::UpdateForm(void)
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


}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaDocVigruska::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(FormaSpiskaSprKlient)FormaSpiskaSprKlient->kanRelease();

if(FormaSpiskaSprProducer)FormaSpiskaSprProducer->kanRelease();
if (REM_FormaGurAllDoc) REM_FormaGurAllDoc->kanRelease();

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
int TREM_FormaDocVigruska::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_InfBase)
		{
		if (type_event==1)
				{
				EndViborInfBase();
				}
		FormaSpiskaSprInfBase=0;
		}



if (number_procedure_end==ER_Klient)
		{
		if (type_event==1)
				{
				EndViborKlient();
				}
		FormaSpiskaSprKlient=0;
		}


if (number_procedure_end==ER_ViborProducer)
		{
		if (type_event==1)
				{
				EndViborProducer();
				}
		FormaSpiskaSprProducer=0;
		}



if (number_procedure_end==ER_ViborREM_GurAllDoc)
		{
		if (type_event==1)
				{
				 EndViborDocREM_GurAllDoc();
				}
		REM_FormaGurAllDoc=0;
		}




return -1;
}
//---------------------------------------------------------------------------
//выбор информационной базы
void TREM_FormaDocVigruska::ViborInfBase(void)
{
if (Prosmotr==true) return;
if (DM->DocAllIDBASE_REM_GUR_VIGR->ReadOnly==true) return;
if (FormaSpiskaSprInfBase==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInfBase.1",IID_IFormaSpiskaSprInfBase,
													(void**)&FormaSpiskaSprInfBase);
		FormaSpiskaSprInfBase->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprInfBase) return;
		FormaSpiskaSprInfBase->NumberProcVibor=ER_InfBase;
		FormaSpiskaSprInfBase->Vibor=true;
		FormaSpiskaSprInfBase->DM->OpenTable();
		} 
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaDocVigruska::EndViborInfBase(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBASE_REM_GUR_VIGR->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsString;
	DM->DocAllNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
	DM->DocAll->Post();

FormaSpiskaSprInfBase=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

//выбор клиента
void TREM_FormaDocVigruska::ViborKlient(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprKlient==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
		FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprKlient) return;
		FormaSpiskaSprKlient->Vibor=true;
		FormaSpiskaSprKlient->NumberProcVibor=ER_Klient;
		FormaSpiskaSprKlient->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocVigruska::EndViborKlient(void)
{
if (FormaSpiskaSprKlient==0) return;


				DM->DocAll->Edit();
				DM->DocAllIDKLIENT_REM_GUR_VIGR->AsString=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsString;
				DM->DocAllNAMEKLIENT->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
				DM->DocAll->Post();

		FormaSpiskaSprKlient=0;

FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------


void __fastcall TREM_FormaDocVigruska::NumberDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVigruska::FDateDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVigruska::PosDoccxDBDateEditPropertiesChange(
      TObject *Sender)
{
UpdateForm();
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocVigruska::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborInfBase();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocVigruska::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVigruska::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void TREM_FormaDocVigruska::BeforeSaveDoc(void)
{
//if (DM->DocAllPOSDOC->AsDateTime > Date())
//	{
//	AnsiString V="Может быть нарушена последовательность проведения документов! Изменить время документа на текущее?";
//	String Z="Внимание!";
//	if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
//		{
//		DM->DocAll->Edit();
//		DM->DocAllPOSDOC->AsDateTime=Now();
//		DM->DocAll->Post();
//		}
//	}

}
//----------------------------------------------------------------------------




void __fastcall TREM_FormaDocVigruska::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{

switch (AButtonIndex)
	{
	case 0:
		{
		ViborKlient();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocAll->Edit();
		DM->DocAllIDKLIENT_REM_GUR_VIGR->Clear();
		DM->DocAll->Post();
		}break;
	}
}
//---------------------------------------------------------------------------




void __fastcall TREM_FormaDocVigruska::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
		DM->DocAll->CancelUpdates();

		DM->DocT->CancelUpdates();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVigruska::ActionOKExecute(TObject *Sender)
{
if(Prosmotr==true) return;
TypeEvent=1;
if (DM->SaveDoc()==true)
		{
        AfterSaveDoc();

		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocVigruska::ActionSaveExecute(TObject *Sender)
{
if(Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		AfterSaveDoc();
		UpdateForm();
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TREM_FormaDocVigruska::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaDocVigruska::RunExternalModule(__int64 id_module, int type_module)
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
module->SetInt64Variables("glIdDoc", glStrToInt64(DM->DocAllID_REM_GUR_VIGR->AsString));
module->SetStringVariables("glUserName", DM_Connection->UserInfoFNAME_USER->AsString);
module->SetInt64Variables("glIdString", glStrToInt64(DM->DocTID_REM_GUR_VIGRT->AsString));

module->ExecuteModule();
}
//---------------------------------------------------------------------------




void TREM_FormaDocVigruska::AfterSaveDoc(void)
{
//
}
//-----------------------------------------------------------------------------



void __fastcall TREM_FormaDocVigruska::ProducercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{

switch (AButtonIndex)
	{
	case 0:
		{
		ViborProducer();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocAll->Edit();
		DM->DocAllIDPRODUCER_REM_GUR_VIGR->Clear();
		DM->DocAll->Post();
		}break;
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void TREM_FormaDocVigruska::ViborProducer(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprProducer==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprProducer,IID_IFormaSpiskaSprProducer,
													(void**)&FormaSpiskaSprProducer);
		FormaSpiskaSprProducer->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprProducer) return;
		FormaSpiskaSprProducer->Vibor=true;
		FormaSpiskaSprProducer->NumberProcVibor=ER_ViborProducer;
		//FormaSpiskaSprProducer->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void TREM_FormaDocVigruska::EndViborProducer(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPRODUCER_REM_GUR_VIGR->AsString=FormaSpiskaSprProducer->DM->TableID_SPRODUCER->AsString;
	DM->DocAllNAME_SPRODUCER->AsString=FormaSpiskaSprProducer->DM->TableNAME_SPRODUCER->AsString;
	DM->DocAll->Post();

FormaSpiskaSprProducer=0;

}
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
//выбор документа из полного журнала
void TREM_FormaDocVigruska::ViborDocREM_GurAllDoc(void)
{
if (REM_FormaGurAllDoc==0)
	{
	InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaGurAllDoc,IID_IREM_FormaGurAllDoc,
													(void**)&REM_FormaGurAllDoc);
	REM_FormaGurAllDoc->Init(InterfaceMainObject,InterfaceImpl);
	REM_FormaGurAllDoc->NumberProcVibor=ER_ViborREM_GurAllDoc;
	REM_FormaGurAllDoc->Vibor=true;
	}

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocVigruska::EndViborDocREM_GurAllDoc(void)
{


				if (ActionOperation==aoAddNewString)
						{
						DM->TableAppend();
						}
				DM->DocT->Edit();
				DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString=REM_FormaGurAllDoc->DM->TableID_REM_GALLDOC->AsString;
				DM->DocTNAMEFIRM->AsString=REM_FormaGurAllDoc->DM->TableNAMEFIRM->AsString;
				DM->DocTNAMESKLAD->AsString=REM_FormaGurAllDoc->DM->TableNAMESKLAD->AsString;
				DM->DocTNAMEKLIENT->AsString=REM_FormaGurAllDoc->DM->TableNAMEKLIENT->AsString;
				DM->DocTNAME_SINFBASE_OBMEN->AsString=REM_FormaGurAllDoc->DM->TableNAME_SINFBASE_OBMEN->AsString;
				DM->DocTPREFIKS_NUM_REM_GALLDOC->AsString=REM_FormaGurAllDoc->DM->TablePREFIKS_NUM_REM_GALLDOC->AsString;
				DM->DocTPR_REM_GALLDOC->AsString=REM_FormaGurAllDoc->DM->TablePR_REM_GALLDOC->AsString;
				DM->DocTNUM_REM_GALLDOC->AsString=REM_FormaGurAllDoc->DM->TableNUM_REM_GALLDOC->AsString;
				DM->DocTPOS_REM_GALLDOC->AsString=REM_FormaGurAllDoc->DM->TablePOS_REM_GALLDOC->AsString;
				DM->DocTTDOC_REM_GALLDOC->AsString=REM_FormaGurAllDoc->DM->TableTDOC_REM_GALLDOC->AsString;
				DM->DocT->Post();

		REM_FormaGurAllDoc=0;



}
//----------------------------------------------------------------------------


void __fastcall TREM_FormaDocVigruska::ToolButtonAddAllDocPoKlientuClick(TObject *Sender)

{
//

IDMQueryRead * dm_qr;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&dm_qr);
dm_qr->Init(InterfaceMainObject,0);
dm_qr->pFIBQ->Close();
dm_qr->pFIBQ->SQL->Clear();

UnicodeString zapros=                                                                                                   \
			"select rem_galldoc.*,                                                                                      \
			 suser.fname_user ,                                                                                         \
			 sinfbase_obmen.name_sinfbase_obmen,                                                                        \
			 sfirm.namefirm,                                                                                            \
			 ssklad.namesklad,                                                                                          \
			 sklient.nameklient,                                                                                        \
			 sproject.name_sproject,                                                                                    \
			 sbusiness_oper.name_sbusiness_oper                                                                         \
			from                                                                                                        \
			  rem_galldoc                                                                                               \
			left outer join SUSER on rem_galldoc.iduser_rem_galldoc=suser.id_user                                       \
			left outer join SINFBASE_OBMEN on sinfbase_obmen.id_sinfbase_obmen=rem_galldoc.idbase_rem_galldoc           \
			left outer join SFIRM on rem_galldoc.idfirm_rem_galldoc=sfirm.idfirm                                        \
			left outer join SSKLAD on rem_galldoc.idsklad_rem_galldoc=ssklad.idsklad                                    \
			left outer join SKLIENT on rem_galldoc.idklient_rem_galldoc=sklient.idklient                                \
			left outer join SPROJECT on rem_galldoc.idproject_rem_galldoc=sproject.id_sproject                          \
			left outer join sbusiness_oper on rem_galldoc.idbusinop_rem_galldoc=sbusiness_oper.id_sbusiness_oper        \
			where                                                                                                       \
			  rem_galldoc.idklient_rem_galldoc=:PARAM_IDKLIENT and                                                      \
			  (rem_galldoc.pos_rem_galldoc between :PARAM_POSNACH and :PARAM_POSCON)";



dm_qr->pFIBQ->SQL->Add(zapros);
dm_qr->pFIBQ->ParamByName("PARAM_IDKLIENT")->AsString=DM->DocAllIDKLIENT_REM_GUR_VIGR->AsString;
dm_qr->pFIBQ->ParamByName("PARAM_POSNACH")->AsDateTime=PosStartcxDateEdit->Date;
dm_qr->pFIBQ->ParamByName("PARAM_POSCON")->AsDateTime=PosEndcxDateEdit->Date;
dm_qr->pFIBQ->ExecQuery();

//dm_qr->pFIBQ->First();
while(!dm_qr->pFIBQ->Eof)
	{
	DM->TableAppend();
	DM->DocT->Edit();
	DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString=dm_qr->pFIBQ->FieldByName("ID_REM_GALLDOC")->AsString;
	DM->DocTNAMEFIRM->AsString=dm_qr->pFIBQ->FieldByName("NAMEFIRM")->AsString;
	DM->DocTNAMESKLAD->AsString=dm_qr->pFIBQ->FieldByName("NAMESKLAD")->AsString;
	DM->DocTNAMEKLIENT->AsString=dm_qr->pFIBQ->FieldByName("NAMEKLIENT")->AsString;
	DM->DocTNAME_SINFBASE_OBMEN->AsString=dm_qr->pFIBQ->FieldByName("NAME_SINFBASE_OBMEN")->AsString;
	DM->DocTPREFIKS_NUM_REM_GALLDOC->AsString=dm_qr->pFIBQ->FieldByName("PREFIKS_NUM_REM_GALLDOC")->AsString;
	DM->DocTPR_REM_GALLDOC->AsString=dm_qr->pFIBQ->FieldByName("PR_REM_GALLDOC")->AsString;
	DM->DocTNUM_REM_GALLDOC->AsString=dm_qr->pFIBQ->FieldByName("NUM_REM_GALLDOC")->AsString;
	DM->DocTPOS_REM_GALLDOC->AsString=dm_qr->pFIBQ->FieldByName("POS_REM_GALLDOC")->AsString;
	DM->DocTTDOC_REM_GALLDOC->AsString=dm_qr->pFIBQ->FieldByName("TDOC_REM_GALLDOC")->AsString;
	DM->DocT->Post();
	dm_qr->pFIBQ->Next();
	}


dm_qr->pFIBQ->Close();
dm_qr->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVigruska::AddDocStartAktPrToolButtonClick(TObject *Sender)

{
IDMQueryRead * dm_qr;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&dm_qr);
dm_qr->Init(InterfaceMainObject,0);
dm_qr->pFIBQ->Close();
dm_qr->pFIBQ->SQL->Clear();

UnicodeString zapros=
			"select REM_REP_FLY_GAR_REMONT_SP_DOC.*,                                                                    \
			 rem_galldoc.*,                                                                           \
			 suser.fname_user ,                                                                                         \
			 sinfbase_obmen.name_sinfbase_obmen,                                                                        \
			 sfirm.namefirm,                                                                                             \
			 ssklad.namesklad,                                                                                          \
			 sklient.nameklient,                                                                                         \
			 sproject.name_sproject,                                                                                    \
			 sbusiness_oper.name_sbusiness_oper                                                                         \
			from                                                                                                        \
			  REM_REP_FLY_GAR_REMONT_SP_DOC(:PARAM_POSNACH,:PARAM_POSCON,:PARAM_IDPRODUCER)                                    \
			left outer join rem_galldoc on rem_galldoc.id_rem_galldoc=REM_REP_FLY_GAR_REMONT_SP_DOC.out_iddoc                  \
			left outer join SUSER on rem_galldoc.iduser_rem_galldoc=suser.id_user                                       \
			left outer join SINFBASE_OBMEN on sinfbase_obmen.id_sinfbase_obmen=rem_galldoc.idbase_rem_galldoc           \
			left outer join SFIRM on rem_galldoc.idfirm_rem_galldoc=sfirm.idfirm                                        \
			left outer join SSKLAD on rem_galldoc.idsklad_rem_galldoc=ssklad.idsklad                                    \
			left outer join SKLIENT on rem_galldoc.idklient_rem_galldoc=sklient.idklient                                \
			left outer join SPROJECT on rem_galldoc.idproject_rem_galldoc=sproject.id_sproject                          \
			left outer join sbusiness_oper on rem_galldoc.idbusinop_rem_galldoc=sbusiness_oper.id_sbusiness_oper        \
			order by rem_galldoc.pos_rem_galldoc";



dm_qr->pFIBQ->SQL->Add(zapros);
dm_qr->pFIBQ->ParamByName("PARAM_IDPRODUCER")->AsString=DM->DocAllIDPRODUCER_REM_GUR_VIGR->AsString;
dm_qr->pFIBQ->ParamByName("PARAM_POSNACH")->AsDateTime=PosStartcxDateEdit->Date;
dm_qr->pFIBQ->ParamByName("PARAM_POSCON")->AsDateTime=PosEndcxDateEdit->Date;
dm_qr->pFIBQ->ExecQuery();

//dm_qr->pFIBQ->First();
while(!dm_qr->pFIBQ->Eof)
	{
	DM->TableAppend();
	DM->DocT->Edit();
	DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString=dm_qr->pFIBQ->FieldByName("OUT_IDDOC")->AsString;
	DM->DocTNAMEFIRM->AsString=dm_qr->pFIBQ->FieldByName("NAMEFIRM")->AsString;
	DM->DocTNAMESKLAD->AsString=dm_qr->pFIBQ->FieldByName("NAMESKLAD")->AsString;
	DM->DocTNAMEKLIENT->AsString=dm_qr->pFIBQ->FieldByName("NAMEKLIENT")->AsString;
	DM->DocTNAME_SINFBASE_OBMEN->AsString=dm_qr->pFIBQ->FieldByName("NAME_SINFBASE_OBMEN")->AsString;
	DM->DocTPREFIKS_NUM_REM_GALLDOC->AsString=dm_qr->pFIBQ->FieldByName("PREFIKS_NUM_REM_GALLDOC")->AsString;
	DM->DocTPR_REM_GALLDOC->AsString=dm_qr->pFIBQ->FieldByName("PR_REM_GALLDOC")->AsString;
	DM->DocTNUM_REM_GALLDOC->AsString=dm_qr->pFIBQ->FieldByName("NUM_REM_GALLDOC")->AsString;
	DM->DocTPOS_REM_GALLDOC->AsString=dm_qr->pFIBQ->FieldByName("POS_REM_GALLDOC")->AsString;
	DM->DocTTDOC_REM_GALLDOC->AsString=dm_qr->pFIBQ->FieldByName("TDOC_REM_GALLDOC")->AsString;
	DM->DocT->Post();
	dm_qr->pFIBQ->Next();
	}


dm_qr->pFIBQ->Close();
dm_qr->kanRelease();
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocVigruska::ActionAddStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
ActionOperation=aoAddNewString;
ViborDocREM_GurAllDoc();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVigruska::ActionDeleteStringExecute(TObject *Sender)

{
if (Prosmotr==true) return;
DM->TableDelete();
}
//---------------------------------------------------------------------------

void TREM_FormaDocVigruska::OpenFormDoc()
{

if(DM->DocTTDOC_REM_GALLDOC->AsString=="REMONT")
		{
		IREM_FormaDocRemont * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaDocRemont.1",IID_IREM_FormaDocRemont,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}

if(DM->DocTTDOC_REM_GALLDOC->AsString=="REMONTHW")
		{
		IREM_FormaDocRemontHW * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaDocRemontHW.1",IID_IREM_FormaDocRemontHW,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}

if(DM->DocTTDOC_REM_GALLDOC->AsString=="REMONTKKT")
		{
		IREM_FormaDocRemontKKT * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaDocRemontKKT.1",IID_IREM_FormaDocRemontKKT,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}

if(DM->DocTTDOC_REM_GALLDOC->AsString=="KM1")
		{
		IREM_FormaDocKM1 * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaDocKM1.1",IID_IREM_FormaDocKM1,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}

if(DM->DocTTDOC_REM_GALLDOC->AsString=="KM2")
		{
		IREM_FormaDocKM2 * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaDocKM2.1",IID_IREM_FormaDocKM2,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();

		}

if(DM->DocTTDOC_REM_GALLDOC->AsString=="SETSERVKKT")
		{
		IREM_FormaDocSetServKKT * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaDocSetServKKT.1",IID_IREM_FormaDocSetServKKT,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}

if(DM->DocTTDOC_REM_GALLDOC->AsString=="SETSERVHW")
		{
		IREM_FormaDocSetServHW * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaDocSetServHW.1",IID_IREM_FormaDocSetServHW,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}

if(DM->DocTTDOC_REM_GALLDOC->AsString=="REMPRN")
		{
		IREM_FormaDocPrihNakl * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocPrihNakl,IID_IREM_FormaDocPrihNakl,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}

if(DM->DocTTDOC_REM_GALLDOC->AsString=="REMREAL")
		{
		IREM_FormaDocReal * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocReal,IID_IREM_FormaDocReal,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}

if(DM->DocTTDOC_REM_GALLDOC->AsString=="REMOSN")
		{
		IREM_FormaDocOstNom * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocOstNom,IID_IREM_FormaDocOstNom,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}

if(DM->DocTTDOC_REM_GALLDOC->AsString=="REMSBKOMPL")
		{
		IREM_FormaDocSborkaKompl * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocSborkaKompl,IID_IREM_FormaDocSborkaKompl,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}

if(DM->DocTTDOC_REM_GALLDOC->AsString=="POSTOTDIL")
		{
		IREM_FormaDocPostOtDilera * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocPostOtDilera,IID_IREM_FormaDocPostOtDilera,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}

if(DM->DocTTDOC_REM_GALLDOC->AsString=="VOSDILERU")
		{
		IREM_FormaDocVosvratDileru * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocVosvratDileru,IID_IREM_FormaDocVosvratDileru,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}



if(DM->DocTTDOC_REM_GALLDOC->AsString=="PERSC")
		{
		IREM_FormaDocPerServCentr * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocPerServCentr,IID_IREM_FormaDocPerServCentr,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}

if(DM->DocTTDOC_REM_GALLDOC->AsString=="VOSVISSC")
		{
		IREM_FormaDocVosvratIsSC * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocVosvratIsSC,IID_IREM_FormaDocVosvratIsSC,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}

if(DM->DocTTDOC_REM_GALLDOC->AsString=="REMVPOK")
		{
		IREM_FormaDocVosvratPok * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocVosvratPok,IID_IREM_FormaDocVosvratPok,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}

if(DM->DocTTDOC_REM_GALLDOC->AsString=="REMAKT")
		{
		IREM_FormaDocAkt * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocAkt,IID_IREM_FormaDocAkt,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}

if(DM->DocTTDOC_REM_GALLDOC->AsString=="REMPER")
		{
		IREM_FormaDocPer * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocPer,IID_IREM_FormaDocPer,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}


if(DM->DocTTDOC_REM_GALLDOC->AsString=="REMZPOST")
		{
		IREM_FormaDocZPost * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZPost,IID_IREM_FormaDocZPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}

if(DM->DocTTDOC_REM_GALLDOC->AsString=="REMZVID")
		{
		IREM_FormaDocZVid * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZVid,IID_IREM_FormaDocZVid,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}

if(DM->DocTTDOC_REM_GALLDOC->AsString=="REMZPER")
		{
		IREM_FormaDocZPer * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZPer,IID_IREM_FormaDocZPer,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}

if(DM->DocTTDOC_REM_GALLDOC->AsString=="REMZSTART")
		{
		IREM_FormaDocZStart * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZStart,IID_IREM_FormaDocZStart,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}

if(DM->DocTTDOC_REM_GALLDOC->AsString=="REMZEND")
		{
		IREM_FormaDocZEnd * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZEnd,IID_IREM_FormaDocZEnd,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}

if(DM->DocTTDOC_REM_GALLDOC->AsString=="REMZOPER")
		{
		IREM_FormaDocZOper * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZOper,IID_IREM_FormaDocZOper,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}


if(DM->DocTTDOC_REM_GALLDOC->AsString=="REMZTREB")
		{
		IREM_FormaDocZTreb * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZTreb,IID_IREM_FormaDocZTreb,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}

if(DM->DocTTDOC_REM_GALLDOC->AsString=="REMZAKTPR")
		{
		IREM_FormaDocZAktPr * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZAktPr,IID_IREM_FormaDocZAktPr,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}

if(DM->DocTTDOC_REM_GALLDOC->AsString=="REMZVZAP")
		{
		IREM_FormaDocZVosvrZap * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZVosvrZap,IID_IREM_FormaDocZVosvrZap,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}


if(DM->DocTTDOC_REM_GALLDOC->AsString=="REMSPN")
		{
		IREM_FormaDocSpisNom * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocSpisNom,IID_IREM_FormaDocSpisNom,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}


if(DM->DocTTDOC_REM_GALLDOC->AsString=="REM_RGOTCHPOST")
		{
		IREM_FormaDocRegOtchetPost * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocRegOtchetPost,IID_IREM_FormaDocRegOtchetPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}

if(DM->DocTTDOC_REM_GALLDOC->AsString=="REM_VIDACHA_HW")
		{
		IREM_FormaDocVidachaHW * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocVidachaHW,IID_IREM_FormaDocVidachaHW,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}

if(DM->DocTTDOC_REM_GALLDOC->AsString=="REM_VOSVRAT_HW")
		{
		IREM_FormaDocVosvratHW * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocVosvratHW,IID_IREM_FormaDocVosvratHW,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->DocTIDDOCVIGR_REM_GUR_VIGRT->AsString));
		doc->UpdateForm();
		}
}
//----------------------------------------------------------------------------


void __fastcall TREM_FormaDocVigruska::cxGrid1DBTableView1CellDblClick(TcxCustomGridTableView *Sender,
          TcxGridTableDataCellViewInfo *ACellViewInfo, TMouseButton AButton,
          TShiftState AShift, bool &AHandled)
{
OpenFormDoc();
}
//---------------------------------------------------------------------------

