// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

// ----------------------------------------------------------------------------
#include "UREM_FormaGurZAktPr.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IDMSetup.h"

#include "IREM_FormaDocZAktPr.h"

#include "IREM_DMZayavka.h"

#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IFormaRunExternalModule.h"

// ---------------------------------------------------------------------------
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
#pragma link "cxCheckBox"
#pragma resource "*.dfm"

// ---------------------------------------------------------------------------
__fastcall TREM_FormaGurZAktPr::TREM_FormaGurZAktPr(TComponent* Owner) : TForm
(Owner) {
	FunctionDeleteImpl = 0;
	flDeleteImpl = true;
	InterfaceMainObject = 0;
	InterfaceOwnerObject = 0;
	DM_Connection = 0;
	InterfaceGlobalCom = 0;
	TypeEvent = 0;

}

// ---------------------------------------------------------------------------
bool TREM_FormaGurZAktPr::Init(void) {
	bool result = false;
	if (InterfaceMainObject > 0) {
		// получим соединение
		IConnectionInterface * i_connection;
		InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,
			(void**) & i_connection);
		DM_Connection = i_connection->GetFibConnection();
		i_connection->kanRelease();

		// получим интерфейс COM системы для создания новых объектов
		IMainCOMInterface * i_com;
		InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,
			(void**) & i_com);
		InterfaceGlobalCom = i_com->GetCOM();
		i_com->kanRelease();
	}

	InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMGurZAktPr,
		IID_IREM_DMGurZAktPr, (void**) & DM);
	DM->Init(InterfaceMainObject, InterfaceImpl);
	cxGrid1DBTableView1->DataController->DataSource = DM->DataSourceTable;

	PosCon = Date() + EncodeTime(23, 59, 59, 999);
	PosNach = DM_Connection->GetPosNachGurnal();

	DM->PosNach = PosNach;
	DM->PosCon = PosCon;

	DM->OpenTable();

	StrOtborLabel->Caption = "";

	DM->Table->Last();
	Vibor = false;

	Vibor = false;

	// заполним список внешних модулей
	InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",
		IID_IDMTableExtPrintForm, (void**) & DMTableExtPrintForm);
	DMTableExtPrintForm->Init(InterfaceMainObject, InterfaceImpl);

	DMTableExtPrintForm->OpenTable(StringToGUID
		(Global_CLSID_TREM_FormaGurAllDocImpl), false);
	DMTableExtPrintForm->Table->First();
	while (!DMTableExtPrintForm->Table->Eof) {
		TMenuItem *menu = new TMenuItem(PopupMenuExtModule);
		menu->Caption = DMTableExtPrintForm->TableNAME_EXTPRINT_FORM->AsString;
		menu->OnClick = PopupMenuExtModuleClick;
		PopupMenuExtModule->Items->Add(menu);
		// static_cast<TPopupMenu*>(Sender)->Items->Add(Item);
		DMTableExtPrintForm->Table->Next();
	}

	DM_Connection->GetPrivForm(GCPRIV_FormaDocCheck);
	ExecPriv = DM_Connection->ExecPriv;
	InsertPriv = DM_Connection->InsertPriv;
	EditPriv = DM_Connection->EditPriv;
	DeletePriv = DM_Connection->DeletePriv;

	result = true;

	return result;
}

// ---------------------------------------------------------------------------
int TREM_FormaGurZAktPr::Done(void) {

	return -1;
}

// ---------------------------------------------------------------------------
void TREM_FormaGurZAktPr::UpdateForm(void) {

	DM->PosNach = PosNach;
	DM->PosCon = PosCon;
	LabelInterval->Caption = DateTimeToStr(PosNach) + " - " + DateTimeToStr
	(PosCon);

}

// ---------------------------------------------------------------------------
void TREM_FormaGurZAktPr::OpenTable(void) {

}
// ----------------------------------------------------------------------------

void __fastcall TREM_FormaGurZAktPr::FormClose(TObject *Sender,
	TCloseAction &Action) {
	if (FormaViborPerioda)
		FormaViborPerioda->kanRelease();
	if (FormaSpiskaSprHardware)
		FormaSpiskaSprHardware->kanRelease();


	// получим ICallBack для передачи события в вызывающую форму
	if (InterfaceOwnerObject) {
		IkanCallBack * i_callback = 0;
		InterfaceOwnerObject->kanQueryInterface(IID_IkanCallBack,
			(void**) & i_callback);
		if (i_callback) {
			i_callback->kanExternalEvent(InterfaceImpl, ClsIdImpl, TypeEvent,
				NumberProcVibor);
		}
		i_callback->kanRelease();
	}
	DM->kanRelease();
	Action = caFree;

	if (flDeleteImpl == true) {
		if (FunctionDeleteImpl)
			FunctionDeleteImpl();
	}
}

// ---------------------------------------------------------------------------
int TREM_FormaGurZAktPr::ExternalEvent(IkanUnknown * pUnk,
	// интерфейс на дочерний объект
	REFIID id_object, // тип дочернего объекта
	int type_event, // тип события в дочернем объекте
	int number_procedure_end // номер процедуры в род. форме, обрабатывающей событие выбора
	) {

	if (number_procedure_end == ViborPerioda) {
		if (type_event == 1) {
			PosNach = FormaViborPerioda->PosNach;
			PosCon = FormaViborPerioda->PosCon;
			DM->PosNach = PosNach;
			DM->PosCon = PosCon;
			LabelInterval->Caption = DateTimeToStr(PosNach)
				+ " - " + DateTimeToStr(PosCon);

		}
		FormaViborPerioda = 0;
	}

	if (number_procedure_end == ER_ViborHardware) {
		if (type_event == 1) {
			EndViborHardware();
		}
		FormaSpiskaSprHardware = 0;
	}

	if (number_procedure_end == ER_Zayavka) {
		if (type_event == 1) {
			EndViborRemZ();
		}
		FormaGurZ = 0;
	}

	if (DM_Connection->UserInfoREOPEN_GUR_SUSER->AsInteger == 1) {
		if (IdVibHardware == 0 && IdVibZayavka == 0) {
			DM->UpdateTable();
		}
	}



	return -1;
}

// --------------------------------------------------------------------------
void TREM_FormaGurZAktPr::OpenFormDoc() {

	IREM_FormaDocZAktPr * doc;
	InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZAktPr,
		IID_IREM_FormaDocZAktPr, (void**) & doc);
	doc->Init(InterfaceMainObject, InterfaceImpl);
	if (!doc)
		return;
	// doc->IdRodForm=Handle;
	// настройка формы
	doc->DM->OpenDoc(glStrToInt64(DM->TableIDDOC_REM_DZAKTPR->AsString));
	doc->UpdateForm();

}
// ----------------------------------------------------------------------------

void __fastcall TREM_FormaGurZAktPr::FormResize(TObject *Sender) {

	StrOtborLabel->Left = cxGrid1->Left + cxGrid1->Width - StrOtborLabel->Width;

}
// ---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZAktPr::ToolButtonDeleteClick(TObject *Sender) {
	DeleteDoc();
}

// ---------------------------------------------------------------------------
void TREM_FormaGurZAktPr::DeleteDoc(void) {

	////******************************************************

	// IREM_DMDocZAktPr * doc;
	// InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZAktPr,IID_IREM_DMDocZAktPr,
	// (void**)&doc);
	// doc->Init(InterfaceMainObject,InterfaceImpl);
	// if (!doc) return;
	// //настройка формы
	// doc->OpenDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString));
	//
	// String V="Вы действительно хотите удалить документ  №"
	// +doc->DocAllNUM_REM_GALLDOC->AsString+" от "+doc->DocAllPOS_REM_GALLDOC->AsString+"?";
	// String Z="Подтверждение удаления документа";
	// if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
	// {
	// return;
	// }
	//
	// if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
	// {
	// DM->UpdateTable();
	// }
	// else
	// {
	// ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
	// }
	//
	//
	// doc->kanRelease();

}

// ----------------------------------------------------------------------------
void __fastcall TREM_FormaGurZAktPr::ToolButton3Click(TObject *Sender) {
	// if (DM->CancelDvRegDoc(Trim(DM->TableTDOC_REM_GALLDOC->AsString), glStrToInt64(DM->TableID_REM_GALLDOC->AsString))==true)
	// {
	// DM->UpdateTable();
	// }
	// else
	// {
	// ShowMessage("Не удалось отменить проведение документа. Ошибка: "+DM->TextError);
	// }

}

// -----------------------------------------------------------------------------
void __fastcall TREM_FormaGurZAktPr::ToolButtonViborPeriodaClick
	(TObject *Sender) {
	if (FormaViborPerioda == NULL) {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaViborPerioda.1",
			IID_IFormaViborPerioda, (void**) & FormaViborPerioda);
		FormaViborPerioda->Init(InterfaceMainObject, InterfaceImpl);
		FormaViborPerioda->NumberProcVibor = ViborPerioda;
		FormaViborPerioda->PosNach = PosNach;
		FormaViborPerioda->PosCon = PosCon;

	}
}
// ---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZAktPr::ToolButtonOpenDocClick(TObject *Sender) {
	OpenFormDoc();
}
// ---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZAktPr::ToolButtonAllCancelDvRegClick
	(TObject *Sender) {
	// String V="Вы действительно хотите отменить проведение всех документов?";
	// String Z="Подтверждение отмены проведения";
	// if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
	// {
	// return;
	// }
	//
	// DM->Table->Last();
	// TFormIndicator * FormIndicator=new TFormIndicator(Application);
	// FormIndicator->Max=DM->Table->RecordCount;
	// FormIndicator->Step=1;
	// FormIndicator->LabelInfo->Caption="Проведение документов...";
	// FormIndicator->Start();
	// FormIndicator->Show();
	//
	// DM->DataSourceTable->Enabled=false;
	//
	// DM->Table->First();
	//
	// while(!DM->Table->Eof)
	// {
	//
	// try
	// {
	// if (DM->CancelDvRegDoc(Trim(DM->TableTDOC_REM_GALLDOC->AsString), glStrToInt64(DM->TableID_REM_GALLDOC->AsString))!=true)
	// {
	//
	// V="Не удалось отменить проведение документа "+
	// glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString)+
	// "  №"+DM->TableNUM_REM_GALLDOC->AsString+
	// " от "+DM->TablePOS_REM_GALLDOC->AsString +" Продолжить?";
	// Z="Ошибка отмены проведения документа!";
	// if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
	// {
	// break;
	// }
	// }
	// }
	// catch (Exception &exception)
	// {
	//
	// V="Ошибка при  отмене проведения документа \n"+
	// glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString)+"  №"+DM->TableNUM_REM_GALLDOC->AsString+
	// " от "+DM->TablePOS_REM_GALLDOC->AsString+
	// "  "+exception.Message +" Продолжить?";
	// Z="Ошибка отмены проведения документа!";
	// if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
	// {
	// break;
	// }
	//
	// }
	// FormIndicator->StepIt();
	// DM->Table->Next();
	// }
	// DM->DataSourceTable->Enabled=true;
	//
	//
	// IDMSetup * DMSetup;
	// InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
	// (void**)&DMSetup);
	// DMSetup->Init(InterfaceMainObject,InterfaceImpl);
	// DMSetup->OpenElement(315);
	// if (DMSetup->ElementVALUE_TIMESTAMP_SETUP->AsFloat==0)
	// {
	// }
	// else
	// {
	//
	// if (DMSetup->GetKolProvDocRemont(DMSetup->ElementVALUE_TIMESTAMP_SETUP->AsFloat)==0)
	// {
	// DMSetup->Element->Edit();
	// DMSetup->ElementVALUE_TIMESTAMP_SETUP->AsDateTime=0;
	// DMSetup->Element->Post();
	// DMSetup->SaveElement();
	// }
	// }
	//
	// DMSetup->kanRelease();
	// DM->UpdateTable();
	// delete FormIndicator;
}
// ---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZAktPr::ToolButtonDvRegDocClick(TObject *Sender) {
	// String V="Вы действительно хотите провести все документы?";
	// String Z="Подтверждение  проведения документов";
	// if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
	// {
	// return;
	// }
	//
	// DM->Table->First();
	////проверим будет ли восстановлена последовательность
	// IDMSetup * DMSetup;
	// InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
	// (void**)&DMSetup);
	// DMSetup->Init(InterfaceMainObject,InterfaceImpl);
	// DMSetup->OpenElement(315);
	// if (DMSetup->ElementVALUE_TIMESTAMP_SETUP->AsFloat==0)
	// {
	// }
	// else
	// {
	// if (DM->PosNach > DMSetup->ElementVALUE_TIMESTAMP_SETUP->AsDateTime)
	// {
	//
	// V= "Граница последовательности меньше позиции начала  журнала! \n";
	// V=V+"Последовательность восстановлена не будет! Продолжить? ";
	// Z="Проведение документов";
	// if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
	// {
	// DMSetup->kanRelease(); return;
	// }
	// }
	// }
	////int kol_prov_doc=DMSetup->GetKolProvDoc(DM->TablePOSDOC->AsDateTime) ;
	// if (DMSetup->GetKolProvDocRemont(DM->PosNach)!=0)
	// {
	// V="Существуют более поздние проведенные документы! Последовательность восстановлена не будет! Продолжить? \n";
	// Z="Проведение документов";
	// DM->IBQ->Close();
	// DM->IBQ->SelectSQL->Clear();
	// DM->IBQ->SelectSQL->Add("select TDOC_REM_GALLDOC, NUM_REM_GALLDOC, POS_REM_GALLDOC from REM_GALLDOC where PR_REM_GALLDOC>0  AND POS_REM_GALLDOC>:PARAM_POSDOC");
	// DM->IBQ->ParamByName("PARAM_POSDOC")->AsDateTime=DM->PosNach;
	// DM->IBQ->Active=true;
	// int kol=0;
	//
	// DM->IBQ->First();
	// while(!DM->IBQ->Eof && kol<3)
	// {
	// V=V+glGetNameDocRemont(Trim(DM->IBQ->FieldByName("TDOC_REM_GALLDOC")->AsString))
	// +" №"+DM->IBQ->FieldByName("NUM_REM_GALLDOC")->AsString
	// +" от "+DM->IBQ->FieldByName("POS_REM_GALLDOC")->AsString+"\n";
	// DM->IBQ->Next(); kol++;
	// }
	// DM->IBQ->Active=false;
	// if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
	// {
	// delete DMSetup; return;
	// }
	// }
	// else  //будет восстановлена последовательность
	// {
	// DMSetup->OpenElement(315);
	// if (DMSetup->ElementVALUE_TIMESTAMP_SETUP->AsFloat==0)
	// {
	// }
	// else
	// {
	//
	// if (DMSetup->GetKolProvDoc(DMSetup->ElementVALUE_TIMESTAMP_SETUP->AsDateTime)==0)
	// {
	// DMSetup->Element->Edit();
	// DMSetup->ElementVALUE_TIMESTAMP_SETUP->AsString="";
	// DMSetup->Element->Post();
	// DMSetup->SaveElement();
	// }
	// }
	// }
	//
	// DMSetup->kanRelease();
	//
	// DM->Table->Last();
	// TFormIndicator * FormIndicator=new TFormIndicator(Application);
	// FormIndicator->Max=DM->Table->RecordCount;
	// FormIndicator->Step=1;
	// FormIndicator->Caption="Проведение документов...";
	// FormIndicator->Start();
	// FormIndicator->Show();
	//
	// DM->DataSourceTable->Enabled=false;
	//
	// DM->Table->First();
	// while(!DM->Table->Eof)
	// {
	// try
	// {
	// if (DM->DvRegDoc(Trim(DM->TableTDOC_REM_GALLDOC->AsString), glStrToInt64(DM->TableID_REM_GALLDOC->AsString))!=true)
	// {
	//
	// V="Не удалось провести документ "+
	// glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString)+
	// "  №"+DM->TableNUM_REM_GALLDOC->AsString+
	// " от "+DM->TablePOS_REM_GALLDOC->AsString +" Продолжить?";
	// Z="Ошибка проведения документа!";
	// if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
	// {
	// break;
	// }
	// }
	// }
	// catch (Exception &exception)
	// {
	//
	// V="Ошибка при  проведении документа \n"+
	// glGetNameDocRemont(DM->TableTDOC_REM_GALLDOC->AsString)+"  №"+DM->TableNUM_REM_GALLDOC->AsString+
	// " от "+DM->TablePOS_REM_GALLDOC->AsString+
	// "  "+exception.Message +" Продолжить?";
	// Z="Ошибка проведения документа!";
	// if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
	// {
	// break;
	// }
	//
	// }
	// FormIndicator->StepIt();
	// DM->Table->Next();
	// }
	//
	// DM->DataSourceTable->Enabled=true;
	// DM->UpdateTable();
	// delete FormIndicator;
}
// ---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZAktPr::ToolButtonDelAllDocClick(TObject *Sender) {
	// String V="Вы действительно хотите удалить все документы?";
	// String Z="Подтверждение удаления";
	// if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
	// {
	// return;
	// }
	//
	// DM->Table->First();
	// while (!DM->Table->Eof)
	// {
	// DeleteAllDoc();
	// DM->Table->Next();
	// }
	//
	// DM->UpdateTable();
}
// ---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZAktPr::ToolButtonOtborClick(TObject *Sender) {

	// AnsiString s="";
	// if (ToolButtonOtbor->Down==true)  // включить отбор
	// {
	// DM->OtborVkl=true;
	//
	// if (IdKlient>0) s=s+" Контрагент: "+NameKlient;
	// if (IdFirm>0) s=s+" Фирма: "+NameFirm;
	// if (IdSklad>0) s=s+" Склад: "+NameSklad;
	// if (StringTypeDoc!="") s=s+" Тип документов : "+NameTypeDoc;
	// StrOtborLabel->Caption=s;
	// }
	// else
	// {
	// DM->OtborVkl=false;
	// StrOtborLabel->Caption=s;
	// }
	//
	// DM->IdKlient=IdKlient;
	// DM->IdSklad=IdSklad;
	// DM->IdFirm=IdFirm;
	// DM->StringTypeDoc=StringTypeDoc;
	//
	////DM->OtborPoKlient=OtborPoKlientu;
	////DM->OtborPoFirm=OtborPoFirm;
	////DM->OtborPoSklad=OtborPoSklad;
	////DM->OtborPoTypeDoc=OtborPoTypeDoc;
	// DM->UpdateTable();

}
// ---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZAktPr::ToolButtonParamOtborClick(TObject *Sender)
{

	// InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSetupOtbor.1",IID_IREM_FormaSetupOtbor,
	// (void**)&FormaSetupOtbor);
	// FormaSetupOtbor->Init(InterfaceMainObject,InterfaceImpl);
	// if (!FormaSetupOtbor ) return;
	// //FormaSetupOtbor->IdRodForm=Handle;
	// FormaSetupOtbor->NumberProcVibor=SetupOtborRekv;

}
// ---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZAktPr::ActionOpenHelpExecute(TObject *Sender) {
	Application->HelpJump("REM_GurAllDoc");
}
// ---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZAktPr::ToolButtonRefreshClick(TObject *Sender) {
	DM->UpdateTable();
}
// ---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZAktPr::cxGrid1DBTableView1DblClick
	(TObject *Sender) {
	if (Vibor == true) {
		TypeEvent = 1;
		Close();
	}
	else {
		OpenFormDoc();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZAktPr::cxGrid1DBTableView1PRDOCCustomDrawCell
	(TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
	TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone) {
	AnsiString ATextToDraw;
	if (dynamic_cast<TcxGridTableDataCellViewInfo*>(AViewInfo) != NULL) {
		ATextToDraw = AViewInfo->GridRecord->DisplayTexts
			[AViewInfo->Item->Index];
	}
	else {
		ATextToDraw = VarAsType(AViewInfo->Item->Caption, varString);
	}

	TRect ARec = AViewInfo->Bounds;
	Graphics::TBitmap *ABitmap = new Graphics::TBitmap();
	if (ATextToDraw == 1) {
		ToolBar1->Images->GetBitmap(16, ABitmap);
	}
	else {
		ToolBar1->Images->GetBitmap(17, ABitmap);
	}
	ACanvas->Canvas->FillRect(ARec);
	ACanvas->Canvas->Draw((ARec.Left + ARec.Right - ABitmap->Width) / 2,
		ARec.Top, ABitmap);
	ABitmap->Free();
	ADone = true;

}
// ---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZAktPr::cxGrid1DBTableView1KeyPress
	(TObject *Sender, char &Key) {
	if (Key == VK_RETURN) {
		if (Vibor == true) {
			TypeEvent = 1;
			Close();
		}
		else {
			OpenFormDoc();
		}
	}
}

// ---------------------------------------------------------------------------
// Внешние модули
void __fastcall TREM_FormaGurZAktPr::PopupMenuExtModuleClick(TObject *Sender) {
	int i = ((TMenuItem*)Sender)->MenuIndex;
	DMTableExtPrintForm->Table->First();
	DMTableExtPrintForm->Table->MoveBy(i);
	RunExternalModule
		(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
		DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}

// ----------------------------------------------------------------------------
void TREM_FormaGurZAktPr::RunExternalModule(__int64 id_module, int type_module)
{
	IFormaRunExternalModule * module;
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaRunExternalModule.1",
		IID_IFormaRunExternalModule, (void**) & module);
	module->Init(InterfaceMainObject, InterfaceImpl);
	module->IdModule = id_module;
	module->TypeTable = 1;

	module->ClearModule();
	module->LoadModule();

	// добавляем текущий модуль
	// TScriptDMDocRealRozn * scr_doc;
	if (type_module == 1 || type_module == 2) {
		//
		// //надо добавить класс TScriptDMDocRealRozn
		// //методы для работы с документом
		// scr_doc=new TScriptDMDocRealRozn();
		// scr_doc->AddClassesInScript(module);
		// //надо добавить текущий DM
		// scr_doc->DM=DM;
		// module->fsScript1->AddObject("TecDMDocRealRozn",scr_doc);
	}

	// надо добавить переменные модуля, как минимум  IDDOC
	module->SetInt64Variables("glIdDoc",
		glStrToInt64(DM->TableIDDOC_REM_DZAKTPR->AsString)
		);
	module->SetDateTimeVariables("glPosBegin", PosNach);
	module->SetDateTimeVariables("glPosEnd", PosCon);

	module->ExecuteModule();
}
// ---------------------------------------------------------------------------

void TREM_FormaGurZAktPr::ViborHardware(void) {

	if (FormaSpiskaSprHardware == NULL) {
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprHardware.1",
			IID_IREM_FormaSpiskaSprHardware, (void**) & FormaSpiskaSprHardware);
		FormaSpiskaSprHardware->Init(InterfaceMainObject, InterfaceImpl);
		if (!FormaSpiskaSprHardware)
			return;
		FormaSpiskaSprHardware->Vibor = true;
		FormaSpiskaSprHardware->NumberProcVibor = ER_ViborHardware;
		FormaSpiskaSprHardware->UpdateForm();
	}

}

// ----------------------------------------------------------------------------
void __fastcall TREM_FormaGurZAktPr::EndViborHardware(void) {

	// IREM_DMSprHardware * spr_hw;
	// InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprHardware,IID_IREM_DMSprHardware,
	// (void**)&spr_hw);
	// spr_hw->Init(InterfaceMainObject,InterfaceImpl);
	// spr_hw->OpenElement(glStrToInt64(FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString));
	//
	//
	// IdVibHardware=glStrToInt64(FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString);
	// NameHardwarecxButtonEdit->Text=FormaSpiskaSprHardware->DM->TableNAME_REM_SHARDWARE->AsString;
	//
	//
	// SerNumHwcxLabel->Caption=FormaSpiskaSprHardware->DM->TableSERNUM_REM_SHARDWARE->AsString;
	// SerNum2HwcxLabel->Caption=spr_hw->ElementSERNUM2_REM_SHARDWARE->AsString;
	// NameModelHwcxLabel->Caption=spr_hw->ElementNAME_REM_SMODEL->AsString;
	//
	//
	//
	// spr_hw->kanRelease();
	// FormaSpiskaSprHardware=0;
	// FindNextControl(ActiveControl,true,true,false)->SetFocus();

}

// ----------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// выбор заявки
void TREM_FormaGurZAktPr::ViborRemZ(void) {

	if (FormaGurZ == NULL) {
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaGurZ,
			IID_IREM_FormaGurZ, (void**) & FormaGurZ);
		FormaGurZ->Init(InterfaceMainObject, InterfaceImpl);
		if (!FormaGurZ)
			return;
		FormaGurZ->Vibor = true;
		FormaGurZ->NumberProcVibor = ER_Zayavka;
	}

}

// ----------------------------------------------------------------------------
void __fastcall TREM_FormaGurZAktPr::EndViborRemZ(void) {

	// IREM_DMZayavka *dm_z;
	// InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMZayavka,IID_IREM_DMZayavka, (void**)&dm_z);
	// dm_z->Init(InterfaceMainObject,InterfaceImpl);
	// dm_z->OpenDoc(glStrToInt64(FormaGurZ->DM->TableID_REM_Z->AsString));
	//
	// IdVibZayavka=glStrToInt64(FormaGurZ->DM->TableID_REM_Z->AsString);
	// NameZayavkacxButtonEdit->Text=FormaGurZ->DM->TableNAME_REM_Z->AsString;
	//
	// NameKlientcxLabel->Caption=FormaGurZ->DM->TableKLIENT_NAME_REM_Z->AsString;
	// NameModelcxLabel->Caption=FormaGurZ->DM->TableMODEL_REM_Z->AsString;
	// SerNumcxLabel->Caption=FormaGurZ->DM->TableSERNUM_REM_Z->AsString;
	// SerNum2cxLabel->Caption=FormaGurZ->DM->TableSERNUM2_REM_Z->AsString;
	////	DM->DocNUM_REM_Z->AsString=FormaGurZ->DM->TableNUM_REM_Z->AsString;
	////	DM->DocPOS_REM_Z->AsString=FormaGurZ->DM->TablePOS_REM_Z->AsString;
	////
	////	if (glStrToInt64(FormaGurZ->DM->TableIDKLIENT_REM_Z->AsString) > 0)
	////		{
	////		DM->DocIDKLIENT_REM_CQUERY->AsString=FormaGurZ->DM->TableIDKLIENT_REM_Z->AsString;
	////		DM->DocNAMEKLIENT->AsString=FormaGurZ->DM->TableNAMEKLIENT->AsString;
	////		}
	////
	////	DM->DocNAME_MODEL_REM_CQUERY->AsString=FormaGurZ->DM->TableMODEL_REM_Z->AsString;
	////
	////	if (DM->DocKLIENT_NAME_REM_CQUERY->AsString=="")
	////		{
	////		DM->DocKLIENT_NAME_REM_CQUERY->AsString=FormaGurZ->DM->TableKLIENT_NAME_REM_Z->AsString;
	////		}
	////	if (DM->DocKLIENT_ADR_REM_CQUERY->AsString=="")
	////		{
	////		DM->DocKLIENT_ADR_REM_CQUERY->AsString=dm_z->GurZKLIENT_ADR_REM_Z->AsString;
	////		}
	////
	////	if (DM->DocKLIENT_PHONE_REM_CQUERY->AsString=="")
	////		{
	////		DM->DocKLIENT_PHONE_REM_CQUERY->AsString=dm_z->GurZKLIENT_PHONE_REM_Z->AsString;
	////		}
	//
	// dm_z->kanRelease();
	//
	// FormaGurZ=0;
	// FindNextControl(ActiveControl,true,true,false)->SetFocus();

}

// ----------------------------------------------------------------------------
void __fastcall TREM_FormaGurZAktPr::
	NameZayavkacxButtonEditPropertiesButtonClick(TObject *Sender,
	int AButtonIndex) {

	// switch (AButtonIndex)
	// {
	// case 0:
	// {
	// ViborRemZ();
	// }break;
	// case 1:
	// {
	// IdVibZayavka=0;
	// NameZayavkacxButtonEdit->Text="";
	// NameKlientcxLabel->Caption="";
	// NameModelcxLabel->Caption="";
	// SerNumcxLabel->Caption="";
	// SerNum2cxLabel->Caption="";
	// }break;
	// }
}
// ---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZAktPr::
	NameHardwarecxButtonEditPropertiesButtonClick(TObject *Sender,
	int AButtonIndex) {

	// switch (AButtonIndex)
	// {
	// case 0:
	// {
	// ViborHardware();
	// }break;
	// case 1:
	// {
	// IdVibHardware=0;
	// NameHardwarecxButtonEdit->Text="";
	// SerNumHwcxLabel->Caption="";
	// SerNum2HwcxLabel->Caption="";
	// NameModelHwcxLabel->Caption="";
	// }break;
	// }
}
// ---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZAktPr::cxButtonOtborPoZayavkaClick
	(TObject *Sender)

{
	DM->OpenTableOnlyZayavka(IdVibZayavka);
}
// ---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZAktPr::cxButtonOtborPoHardwareClick
	(TObject *Sender)

{
	DM->OpenTableOnlyHardware(IdVibHardware);
}
// ---------------------------------------------------------------------------

