//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UHLP_FormaSpiskaSprInfBlockSostav.h"
//#include "IFormaElementaSprPropertiesValuesList.h"

#include "IHLP_DMSprImage.h"
#include "IDMQueryRead.h"

#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxCheckBox"
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
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxGridBandedTableView"
#pragma link "cxGridDBBandedTableView"
#pragma link "cxMemo"
#pragma link "cxSpinEdit"
#pragma link "cxButtonEdit"
#pragma link "cxImage"
#pragma link "cxTextEdit"
#pragma link "cxGridCardView"
#pragma link "cxGridDBCardView"
#pragma link "frxClass"
#pragma link "frxDesgn"
#pragma link "frxPreview"
#pragma link "cxPC"
#pragma link "cxImageComboBox"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall THLP_FormaSpiskaSprInfBlockSostav::THLP_FormaSpiskaSprInfBlockSostav(TComponent* Owner)
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
bool THLP_FormaSpiskaSprInfBlockSostav::Init(void)
{
bool result=false;
if (InterfaceMainObject>0)
	{
	//получим соединение
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//получим интерфейс COM системы дл€ создани€ новых объектов
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}
InterfaceGlobalCom->kanCreateObject(ProgId_HLP_DMSprInfBlockSostav,IID_IHLP_DMSprInfBlockSostav,
								 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

Vibor=false;
HintLabel->Caption="";

//заполним список внешних модулей
//InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
//												 (void**)&DMTableExtPrintForm);
//DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
//DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_THLP_FormaSpiskaSprPageElementImpl),false);
//DMTableExtPrintForm->Table->First();
//while (!DMTableExtPrintForm->Table->Eof)
//		{
//		TMenuItem *menu=new TMenuItem(PopupMenuExtModule);
//		menu->Caption=DMTableExtPrintForm->TableNAME_EXTPRINT_FORM->AsString;
//		menu->OnClick = PopupMenuExtModuleClick;
//		PopupMenuExtModule->Items->Add(menu);
//		//static_cast<TPopupMenu*>(Sender)->Items->Add(Item);
//		DMTableExtPrintForm->Table->Next();
//		}

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;

//ѕ–»¬≈Ћ≈√»»
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//---------------------------------------------------------------------------
int THLP_FormaSpiskaSprInfBlockSostav::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void THLP_FormaSpiskaSprInfBlockSostav::UpdateForm(void)
{

LabelNom->Caption=HeaderText;
DM->OpenTable(IdPage);
LoadFromBase();
}
//---------------------------------------------------------------------------

void __fastcall THLP_FormaSpiskaSprInfBlockSostav::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprImage)FormaSpiskaSprImage->kanRelease();


//получим ICallBack дл€ передачи событи€ в вызывающую форму
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
//DMTableExtPrintForm->kanRelease();
DM->kanRelease();
Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//--------------------------------------------------------------------------










//---------------------------------------------------------------------------
//¬нешние модули
void __fastcall THLP_FormaSpiskaSprInfBlockSostav::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void THLP_FormaSpiskaSprInfBlockSostav::RunExternalModule(__int64 id_module, int type_module)
{
IFormaRunExternalModule * module;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaRunExternalModule.1",IID_IFormaRunExternalModule,
						 (void**)&module);
module->Init(InterfaceMainObject,InterfaceImpl);
module->IdModule=id_module;
module->TypeTable=1;

module->ClearModule();
module->LoadModule();


//добавл€ем текущий модуль
//TScriptDMDocRealRozn * scr_doc;
if (type_module==1 || type_module==2)
	{
//
//	//надо добавить класс TScriptDMDocRealRozn
//	//методы дл€ работы с документом
//	scr_doc=new TScriptDMDocRealRozn();
//	scr_doc->AddClassesInScript(module);
//	//надо добавить текущий DM
//	scr_doc->DM=DM;
//	module->fsScript1->AddObject("TecDMDocRealRozn",scr_doc);
	}

if (type_module==3)
	{  //надо добавить переменные модул€, как минимум  IDDOC
	module->SetInt64Variables("glIdPage", glStrToInt64(DM->TableIDIB_HLP_IB_S->AsString));
	module->SetInt64Variables("glIdPageElement", glStrToInt64(DM->TableID_HLP_IB_S->AsString));
	}

module->ExecuteModule();


}
//-----------------------------------------------------------------------------
void __fastcall THLP_FormaSpiskaSprInfBlockSostav::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------
int THLP_FormaSpiskaSprInfBlockSostav::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип событи€ в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{


		if (number_procedure_end==ER_EditImage)
				{
				if (type_event==1)
					{
					EndViborImage();
					}
				FormaSpiskaSprImage=0;
				}


return -1;
}
//-----------------------------------------------------------------------------

void THLP_FormaSpiskaSprInfBlockSostav::OpenFormaSpiskaSprImage(void)
{
if (FormaSpiskaSprImage==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_HLP_FormaSpiskaSprImage,IID_IHLP_FormaSpiskaSprImage,
													 (void**)&FormaSpiskaSprImage);
		FormaSpiskaSprImage->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprImage->UpdateForm();
		FormaSpiskaSprImage->Vibor=true;
		FormaSpiskaSprImage->NumberProcVibor=ER_EditImage;
		}
}
//----------------------------------------------------------------------------
void THLP_FormaSpiskaSprInfBlockSostav::EndViborImage(void)
{

DM->Table->Edit();
DM->TableNAME_HLP_IMG->AsString=FormaSpiskaSprImage->DM->TableNAME_HLP_IMG->AsString;
DM->TableIDIMG_HLP_IB_S->AsString=FormaSpiskaSprImage->DM->TableID_HLP_IMG->AsString;
DM->Table->Post();

}
//-----------------------------------------------------------------------------

void __fastcall THLP_FormaSpiskaSprInfBlockSostav::cxGrid1DBTableView1NAME_HLP_IMAGEPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
OpenFormaSpiskaSprImage();
}
//---------------------------------------------------------------------------



void __fastcall THLP_FormaSpiskaSprInfBlockSostav::Button3Click(TObject *Sender)
{

Memo1->Lines->Clear();

	for(int i = 0; i < frxReport1->ComponentCount; i++)
		{
		UnicodeString s;
		s=frxReport1->Components[i]->ClassName();
		Memo1->Lines->Add(s);
		s = frxReport1->Components[i]->Name;
		Memo1->Lines->Add(s);

	   if (frxReport1->Components[i]->ClassNameIs("TfrxMemoView"))
			{
			TfrxMemoView * memo;
			memo = dynamic_cast <TfrxMemoView*> (frxReport1->Components[i]);
			if (memo)
				{
				s = "Text = "+memo->Text; Memo1->Lines->Add(s);
				s = "Font->Size = "+IntToStr(memo->Font->Size); Memo1->Lines->Add(s);

				}

			}

	   if (frxReport1->Components[i]->ClassNameIs("TfrxPictureView"))
			{
			TfrxPictureView * picture;
			picture = dynamic_cast <TfrxPictureView*> (frxReport1->Components[i]);
			if (picture)
				{
				//s = "Text = "+picture->Text; Memo1->Lines->Add(s);
				//s = "Font->Size = "+IntToStr(memo->Font->Size); Memo1->Lines->Add(s);
				}

			}

		Memo1->Lines->Add("");
		}
}
//---------------------------------------------------------------------------









void __fastcall THLP_FormaSpiskaSprInfBlockSostav::ToolButtonUpdateFormClick(TObject *Sender)

{
UpdateForm();
}
//---------------------------------------------------------------------------
void THLP_FormaSpiskaSprInfBlockSostav::LoadFromBase(void)
{

frxReport1->Clear();

TfrxReportPage * page;
TfrxBand * band;


page = new TfrxReportPage(frxReport1);
page->CreateUniqueName();
page->SetDefaults();

band = new TfrxReportTitle(page);
band->CreateUniqueName();
band->Top=0;
band->Height=1000;
band->Stretched=true;


int top=0;
//выведем заголовок
		TfrxMemoView * memo;
		memo = new TfrxMemoView(band);
		memo->CreateUniqueName();
		//memo->Tag=glStrToInt64(DM->TableID_ART_IB_S->AsString);
		memo->Text=GetZagolovokPage(IdPage);
		memo->Top=top;
		memo->Height=20;     //надо сделать раст€гиваемым
		memo->Align=baWidth;
		memo->StretchMode=smActualHeight;
		memo->HAlign=Frxclass::haCenter;
		memo->Font->Size=14;
		top=top+memo->Height;
//пробел

		memo = new TfrxMemoView(band);
		memo->CreateUniqueName();
		//memo->Tag=glStrToInt64(DM->TableID_ART_IB_S->AsString);
		memo->Text="     ";
		memo->Top=top;
		memo->Height=20;     //надо сделать раст€гиваемым
		memo->Align=baWidth;
		memo->StretchMode=smActualHeight;
		top=top+memo->Height;

//выведем таблицу
DM->OpenTable(IdPage);
DM->Table->First();



while(!DM->Table->Eof)
	{
	if (DM->TableTYPE_HLP_IB_S->AsInteger==1) //текст
		{
		TfrxMemoView * memo;
		memo = new TfrxMemoView(band);
		memo->CreateUniqueName();
		memo->Tag=glStrToInt64(DM->TableID_HLP_IB_S->AsString);
		memo->Text="     "+DM->TableTEXT_HLP_IB_S->AsString;
		memo->Top=top;
		memo->Height=50;
		if (glStrToInt64(DM->TableFONT_SIZE_HLP_IB_S->AsString)==0)
			{
			}
		else
			{
			memo->Font->Size=glStrToInt64(DM->TableFONT_SIZE_HLP_IB_S->AsString);
			}

		memo->Align=baWidth;
		memo->StretchMode=smActualHeight;

		if(DM->TableH_ALIGN_HLP_IB_S->AsInteger ==0)         //не задан
			{

			}
		else if (DM->TableH_ALIGN_HLP_IB_S->AsInteger ==1)      //лево
			{
			memo->HAlign=Frxclass::haLeft;
			}
		else if (DM->TableH_ALIGN_HLP_IB_S->AsInteger ==2)      //право
			{
			memo->HAlign=Frxclass::haRight;
			}
		else if (DM->TableH_ALIGN_HLP_IB_S->AsInteger ==3)      //центр
			{
			memo->HAlign=Frxclass::haCenter;
			}
		else if (DM->TableH_ALIGN_HLP_IB_S->AsInteger ==4)      //по ширине
			{
			memo->HAlign=Frxclass::haBlock;
			}

		top=top+memo->Height;
		}


	if (DM->TableTYPE_HLP_IB_S->AsInteger==2) //картинка
		{
        top=top+10;
		IHLP_DMSprImage *dm_image;
		InterfaceGlobalCom->kanCreateObject(ProgId_HLP_DMSprImage,IID_IHLP_DMSprImage,
										 (void**)&dm_image);
		dm_image->Init(InterfaceMainObject,InterfaceImpl);


		dm_image->OpenElement(glStrToInt64(DM->TableIDIMG_HLP_IB_S->AsString));
		TMemoryStream * s=new TMemoryStream;
		dm_image->ElementIMAGE_HLP_IMG->SaveToStream(s);
		//s->Position = 0 ;

		TfrxPictureView * picture = new TfrxPictureView(band);
		picture->CreateUniqueName();
		if (picture)
			{
			picture->Tag=glStrToInt64(DM->TableID_HLP_IB_S->AsString);
			picture->Top=top;
			picture->Left=5;
            picture->Stretched=true;
			if (dm_image->ElementHEIGHT_HLP_IMG->AsInteger ==0)
				{
				picture->Height=100;
				}
			else
				{
				picture->Height=dm_image->ElementHEIGHT_HLP_IMG->AsInteger;
				}

		   if (dm_image->ElementWIDTH_HLP_IMG->AsInteger == 0)
				{
                picture->Width=100;
				}
		   else
				{
				picture->Width=dm_image->ElementWIDTH_HLP_IMG->AsInteger;
				}
			//picture->Align=baWidth;
			picture->LoadPictureFromStream(s, true);


			}

		delete s;
		dm_image->kanRelease();
		top=top+picture->Height+10;
		}

    DM->Table->Next();
	}

frxReport1->ShowReport();


}
//---------------------------------------------------------------------------
void THLP_FormaSpiskaSprInfBlockSostav::SaveInBase(void)
{
__int64 id_rec_str=0;

	for(int i = 0; i < frxReport1->ComponentCount; i++)
		{

	   if (frxReport1->Components[i]->ClassNameIs("TfrxMemoView"))
			{
			TfrxMemoView * memo;
			memo = dynamic_cast <TfrxMemoView*> (frxReport1->Components[i]);
			if (memo)
				{
				id_rec_str=memo->Tag;
				if (id_rec_str==0)
					{//вставл€ем
					DM->NewElement(IdPage);
					id_rec_str=glStrToInt64(DM->ElementID_HLP_IB_S->AsString);
					DM->Element->Edit();
					DM->ElementTEXT_HLP_IB_S->AsString=memo->Text;
					DM->ElementTYPE_HLP_IB_S->AsInteger=1; //текст
					DM->ElementINDEX_HLP_IB_S->AsInteger=memo->Top*10; //текст

					if (memo->HAlign == Frxclass::haLeft)      //лево
						{
						DM->ElementH_ALIGN_HLP_IB_S->AsInteger = 1;
						}
					else if (memo->HAlign == Frxclass::haRight )      //право
						{
						DM->ElementH_ALIGN_HLP_IB_S->AsInteger =2;
						}
					else if (memo->HAlign == Frxclass::haCenter )      //центр
						{
						DM->ElementH_ALIGN_HLP_IB_S->AsInteger = 3;
						}
					else if (memo->HAlign == Frxclass::haBlock )      //по ширине
						{
						DM->ElementH_ALIGN_HLP_IB_S->AsInteger =4;
						}

					DM->Element->Post();
					DM->SaveElement();
					memo->Tag=id_rec_str;
					}
				else
					{  //обновл€ем
					id_rec_str=memo->Tag;
					DM->OpenElement(id_rec_str);
					DM->Element->Edit();
					DM->ElementTEXT_HLP_IB_S->AsString=memo->Text;
					DM->ElementINDEX_HLP_IB_S->AsInteger=memo->Top*10;
					if (memo->HAlign == Frxclass::haLeft)      //лево
						{
						DM->ElementH_ALIGN_HLP_IB_S->AsInteger = 1;
						}
					else if (memo->HAlign == Frxclass::haRight )      //право
						{
						DM->ElementH_ALIGN_HLP_IB_S->AsInteger =2;
						}
					else if (memo->HAlign == Frxclass::haCenter )      //центр
						{
						DM->ElementH_ALIGN_HLP_IB_S->AsInteger = 3;
						}
					else if (memo->HAlign == Frxclass::haBlock )      //по ширине
						{
						DM->ElementH_ALIGN_HLP_IB_S->AsInteger =4;
						}


					DM->Element->Post();
					DM->SaveElement();
					}
				}

			}

	   if (frxReport1->Components[i]->ClassNameIs("TfrxPictureView"))
			{
			TfrxPictureView * picture;
			picture = dynamic_cast <TfrxPictureView*> (frxReport1->Components[i]);
			if (picture)
				{
				IHLP_DMSprImage *dm_image;
				InterfaceGlobalCom->kanCreateObject(ProgId_HLP_DMSprImage,IID_IHLP_DMSprImage,
								 (void**)&dm_image);
				dm_image->Init(InterfaceMainObject,InterfaceImpl);

				__int64 id_image=0;
				id_rec_str = picture->Tag;

				if (id_rec_str == 0)
					{// вставл€ем и запись в структуру и картинку в справочник картинок
					dm_image->NewElement(0);
					TMemoryStream * s=new TMemoryStream;
					picture->Picture->Graphic->SaveToStream(s);
					dm_image->Element->Edit();
					dm_image->ElementIMAGE_HLP_IMG->LoadFromStream(s);
					dm_image->ElementHEIGHT_HLP_IMG->AsInteger=picture->Height;
					dm_image->ElementWIDTH_HLP_IMG->AsInteger=picture->Width;
					dm_image->Element->Post();
					delete s;

					id_image=glStrToInt64(dm_image->ElementID_HLP_IMG->AsString);
					dm_image->SaveElement();

					DM->NewElement(IdPage);
					id_rec_str=glStrToInt64(DM->ElementID_HLP_IB_S->AsString);
					DM->Element->Edit();
					DM->ElementTYPE_HLP_IB_S->AsInteger=2; //картинка
					DM->ElementIDIMG_HLP_IB_S->AsString=id_image;
					DM->ElementINDEX_HLP_IB_S->AsInteger=picture->Top*10;
					DM->Element->Post();
					DM->SaveElement();
					picture->Tag=id_rec_str;
					}
				else
					{ //запись в структуре есть, ищем картинку

					DM->OpenElement(id_rec_str);
					id_image=glStrToInt64(DM->ElementIDIMG_HLP_IB_S->AsString);
					dm_image->OpenElement(id_image);
					id_image=glStrToInt64(dm_image->ElementID_HLP_IMG->AsString);

						if (id_image == 0)
							{//нет картинки, вставл€ем картинку
							dm_image->NewElement(0);

							TMemoryStream * s=new TMemoryStream;
							picture->Picture->Graphic->SaveToStream(s);
							dm_image->Element->Edit();
							dm_image->ElementIMAGE_HLP_IMG->LoadFromStream(s);
							dm_image->ElementHEIGHT_HLP_IMG->AsInteger=picture->Height;
							dm_image->ElementWIDTH_HLP_IMG->AsInteger=picture->Width;
							dm_image->Element->Post();
							delete s;

							id_image=glStrToInt64(dm_image->ElementID_HLP_IMG->AsString);
							dm_image->SaveElement();

							DM->Element->Edit();
							DM->ElementTYPE_HLP_IB_S->AsInteger=2; //картинка
							DM->ElementIDIMG_HLP_IB_S->AsString=id_image;
							DM->ElementINDEX_HLP_IB_S->AsInteger=picture->Top*10;
							DM->Element->Post();
							DM->SaveElement();
							}
						else
							{  //есть запись в структуре, есть картинка, обновл€ем
							TMemoryStream * s=new TMemoryStream;
							picture->Picture->Graphic->SaveToStream(s);
							dm_image->Element->Edit();
							dm_image->ElementIMAGE_HLP_IMG->LoadFromStream(s);
							dm_image->ElementHEIGHT_HLP_IMG->AsInteger=picture->Height;
							dm_image->ElementWIDTH_HLP_IMG->AsInteger=picture->Width;
							dm_image->Element->Post();
							delete s;
							dm_image->SaveElement();
							}




					}





				dm_image->kanRelease();
				}

			}


		}



}
//-----------------------------------------------------------------------------




void __fastcall THLP_FormaSpiskaSprInfBlockSostav::ToolButtonDesinerOpenClick(TObject *Sender)

{
frxReport1->DesignReport(false,true);
}
//---------------------------------------------------------------------------

void __fastcall THLP_FormaSpiskaSprInfBlockSostav::ToolButtonShowNoBaseClick(TObject *Sender)

{
frxReport1->ShowReport();
}
//---------------------------------------------------------------------------

void __fastcall THLP_FormaSpiskaSprInfBlockSostav::ToolButtonSaveInBaseClick(TObject *Sender)

{
SaveInBase();
}
//---------------------------------------------------------------------------



void __fastcall THLP_FormaSpiskaSprInfBlockSostav::ToolButtonsaveIsmenClick(TObject *Sender)

{
if (DM->SaveIsmen() == false)
	{
	ShowMessage(DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall THLP_FormaSpiskaSprInfBlockSostav::ToolButtonAddStringClick(TObject *Sender)

{
if (DM->TableAppend(IdPage) == false)
	{
	ShowMessage(DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall THLP_FormaSpiskaSprInfBlockSostav::ToolButtonDeleteStringClick(TObject *Sender)

{
if (DM->TableDelete() == false)
	{
	ShowMessage(DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall THLP_FormaSpiskaSprInfBlockSostav::ToolButtonPrintClick(TObject *Sender)

{
frxReport1->Print();
}
//---------------------------------------------------------------------------
UnicodeString THLP_FormaSpiskaSprInfBlockSostav::GetZagolovokPage(__int64 id_page)
{
UnicodeString result="";
//сначала надо попытатьс€ найти старую проверку
IDMQueryRead * dm_qr;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&dm_qr);
dm_qr->Init(InterfaceMainObject,0);
dm_qr->pFIBQ->Close();
dm_qr->pFIBQ->SQL->Clear();

UnicodeString zapros=
"select HLP_ib.title_HLP_ib                               \
			from HLP_ib                                   \
			where HLP_ib.id_HLP_ib=:PARAM_ID";

dm_qr->pFIBQ->SQL->Add(zapros);
dm_qr->pFIBQ->ParamByName("PARAM_ID")->AsString=id_page;
dm_qr->pFIBQ->ExecQuery();

result=dm_qr->pFIBQ->FieldByName("title_HLP_ib")->AsString;
dm_qr->pFIBQ->Close();
dm_qr->kanRelease();


return result;
}
//------------------------------------------------------------------------------
