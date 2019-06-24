//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

//--------------------------------------------------------------------------
#include "UMainForm.h"
//#include "UDM.h"
#include "UDMSprUser.h"
//ключ защиты
#include "grdapi.h"
//вызов справочной системы
#include "HTMLHelpViewer.hpp"
#include "UREM_FormaGurAllDoc.h"
#include "UREM_FormaDocRemont.h"
#include "UScaner.h"
#include "UREM_FormaSpiskaSprHardware.h"
#include "UREM_FormaDocRemontHW.h"
#include "UREM_FormaSpiskaSprKKT.h"
#include "UREM_FormaDocRemontKKT.h"
#include "UREM_FormaDocKM1.h"
#include "UREM_FormaDocKM2.h"
#include "UREM_FormaDocSetServKKT.h"
#include "UREM_FormaDocSetServHW.h"
#include "UGlobalConstant.h"
#include "UFormaSpiskaInterfMainMenu.h"
#include "UDMInterfMainMenu.h"
#include "UDMInterfMainMenuGrp.h"
#include "UDM.h"
#include "UFormaSpiskaSprUser.h"
#include "UFormaSpiskaSprKKM.h"
#include "UFormaGurAllDoc.h"
#include "UFormaDocPrihNakl.h"
#include "UFormaDocCheck.h"
#include "UFormaDocSchet.h"
#include "UFormaDocOstNom.h"
#include "UFormaDocPer.h"
#include "UFormaDocReal.h"
#include "UAbout.h"
#include "UFormaDocSpisNom.h"
#include "UFormaDocVosvratPok.h"
#include "UFormaDocVosvratPost.h"
#include "UDMDocCheck.h"
#include "UFormaDocPKO.h"
#include "UFormaDocPKORozn.h"
#include "UFormaDocPlatPor.h"
#include "UFormaDocPostNaSchet.h"
#include "UFormaSpiskaSprProject.h"
#include "UDMDocOstNom.h"
#include "UFormaDocRKO.h"
#include "UFormaDocRKORozn.h"
#include "UFormaDocSborkaKompl.h"
#include "UFormaDocSchetFact.h"
#include "UFormaDocSpOtrOst.h"
#include "UFormaDocVipBanka.h"
#include "UFormaDocVipuskProd.h"
#include "UFormaSpiskaSprPodr.h"
#include "UFormaSpiskaSprBVNom.h"
#include "UFormaReportBank.h"
#include "UFormaReportDiscountDocCheck.h"
#include "UFormaReportGoodsReport.h"
#include "UFormaReportKalkKarta.h"
#include "UFormaReportKartKlient.h"
#include "UFormaReportKassa.h"
#include "UFormaReportOCBRegGoods.h"
#include "UFormaSpiskaSprStrObject.h"
#include "UFormaSpiskaSprMPrig.h"
#include "UFormaSpiskaSprCodeTel.h"
#include "UFormaDialogaReportSaleCheck.h"
#include "UFormaGurDocPrihNakl.h"
#include "UFormaGurDocCheckKKM.h"
#include "UFormaGurDocPer.h"
#include "UFormaReportOCBRegVSRasch.h"
#include "UFormaDocInv.h"
#include "UFormaReportResultReal.h"
#include "UFormaReportVipuskProd.h"
#include "UFormaReportKartTovara.h"
#include "UFormaSpiskaSprInv.h"
#include "UFormaSpiskaSetup.h"
#include "UFormaDocRepKKM.h"
#include "UFormaReportOCBRegOstNom.h"
#include "UFormaReportRashodProduct.h"
#include "UFormaSpiskaSprARM.h"
#include "UFormaSpiskaSprVesNom.h"
#include "UFormaDocOstVs.h"
#include "UFormaDocRealRozn.h"
#include "UFormaReportOCBPaySale.h"
#include "UFormaPrintPriceA.h"
#include "UFormaDocIsmPrice.h"
#include "UFormaDocRev.h"
#include "UFormaPrintExternalReport.h"
#include "UFormaSpiskaSprVidKlient.h"
#include "UFormaSpiskaSprVidNom.h"
#include "UFormaSpiskaSprVidDiscountCard.h"
#include "UDMDocInv.h"
#include "UFormaSpiskaSprCountry.h"
#include "UFormaSpiskaSprFirm.h"
#include "UFormaSpiskaSprInfBase.h"
#include "UFormaSpiskaSprKlient.h"
#include "UFormaSpiskaSprSklad.h"
#include "UFormaSpiskaSprTypePrice.h"
#include "UFormaSpiskaSprDiscountAuto.h"
#include "UFormaSpiskaTableNumberDoc.h"
#include "UFormaSpiskaSprNakSkidok.h"
#include "UFormaGurOperDiscountCard.h"
#include "UFormaSpiskaXSetupObmen.h"
#include "UFormaSpiskaSprImportSet.h"
#include "UFormaImportDocPrihNakl.h"
#include "UFormaGurLog.h"
#include "UFormaExportDoc.h"
#include "UFormaSpiskaSprScale.h"
#include "UFormaDialogaReportPoProject.h"
#include "UFormaSpiskaExtModule.h"
#include "UFormaSpiskaTableExtPrintForm.h"
#include "UFormaDocRasborkaKompl.h"
#include "UFormaDocZamena.h"
#include "UFormaDocKorrVS.h"
#include "UGlobalFunction.h"
#pragma link "HTMLHelpViewer"

#include "UAbout.h"
#include "UDMSetup.h"
#include "UDMQueryRead.h"
#include "UREM_FormaSpiskaSprNeispr.h"
#include "UREM_FormaSpiskaSprModel.h"
#include "UREM_FormaSpiskaSprTypeRem.h"
#include "UREM_FormaSpiskaSprSost.h"
#include "UREM_FormaGurZ.h"

#include "UFormaSpiskaInterfToolBar.h"
#include "UDMInterfToolBar.h"
#include "UFormaSpiskaObjectBasePriv.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDataSet"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"
TMainForm *MainForm;
//extern TDM *DM;
//extern TDMSprUser * glUser;
//
//
//
//
//UnicodeString BaseVersion;
//UnicodeString ProgramVersion;
//
//int glRegNumber; //unsigned long
//int glNumberARM;
//__int64 glIdARM;
//
TScaner * glScaner;
//
//extern bool glError;
//extern bool glDemo;
//extern UnicodeString GetVersionProgramFile(void);
//extern void AddLog(__int64 id_user,
//					int type,
//					int object,
//					int oper,
//					UnicodeString message,
//					UnicodeString code_object,
//					__int64 id_object,
//					int subsystem);
//bool glShowNDS;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{

DM_Connection=new TDM(Application);

FormaViborBase=new TFormaViborBase(Application);
glDemo=false;
UnicodeString ProgramCatalog=ExtractFileDir(Application->ExeName);
Application->HelpFile=ProgramCatalog+"\\RemontHelp.chm";

if (FileExists(ProgramCatalog+"\\language.ini")==true)
	{
	DM_Connection->cxLocalizer1->FileName=ProgramCatalog+"\\language.ini";
	DM_Connection->cxLocalizer1->Active=true;
	DM_Connection->cxLocalizer1->Locale=1049;
	}

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
if(DM_Connection->pFIBData->Connected==true)
	{
	//AddLog( glUser->ElementID_USER->AsInteger, 1, 0, 0, "Завершение работы Remont.exe");
	}
//if (glScaner) if(glScaner->ConnectScaner) glScaner->Disconnect();

delete DM_Connection;
//delete glUser;
GrdLogout(grd,0);
GrdCloseHandle(grd);
GrdCleanup();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
FormaViborBase->FOnCloseForm=EndViborBase;
FormaViborBase->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::EndViborBase(TObject *Sender)
{

if (FormaViborBase->OutReady==true)
        {
		DM_Connection->ConnectString=FormaViborBase->ConnectString;
		DM_Connection->PasswordUser=FormaViborBase->PasswordUser;
		DM_Connection->NameUser=FormaViborBase->NameUser;

		if(DM_Connection->GlobConnect()==true)
				{
				if (DM_Connection->UserInfoSAVENAME_SUSER->AsInteger==1)
					{
                    FormaViborBase->SaveNameUser();
					}
				//AddLog( glUser->ElementID_USER->AsInteger, 1, 0, 0, "Запуск программы Remont.exe");
//						if (glUser->ElementPASSWORD_USER->AsString==FormaViborBase->PasswordUser)
//								{
//								if (glUser->ElementINTERF_USER->AsInteger>=10)
//										{
										Visible=true;
										DM_Connection->OpenARMInfo(FormaViborBase->NumberARM);

                                        StatusBar->Panels->Items[0]->Text=FormaViborBase->NameUser;
										StatusBar->Panels->Items[2]->Text=DM_Connection->ConnectString;
                                      //  StatusBar->Panels->Items[1]->Text=gl_prefiks_ib;
										StatusBar->Panels->Items[3]->Text=DM_Connection->GetVersionBase();
										StatusBar->Panels->Items[4]->Text=glGetVersionProgramFile();
										FormaViborBase->CloseForm=true;
										CheckKey();
//                                        }
//								else
//										{
//										ShowMessage("Неправильное имя пользователя или пароль!");
//										FormaViborBase->CloseForm=false;
//										}

//                                }
//						 else
//								{
//								ShowMessage("Неправильное имя пользователя или пароль!");
//								FormaViborBase->CloseForm=false;
//								}
//						}
//				else
//						{
//					ShowMessage("Не найден пользователь в справочнике пользователей!");
//					FormaViborBase->CloseForm=false;
//						}
				CreateMainMenu();
                }
        else
				{
				UnicodeString s=L"Ошибка при подключении к базе данных: "+DM->TextError;
				Application->MessageBox(s.c_str(),
				L"Ошибка при подключении к базе данных!", MB_OK + MB_ICONEXCLAMATION);
				FormaViborBase->CloseForm=false;
				}

		}
else
		{
		//закрываем программу
		Close();

		}
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::OpenFormAboutClick(TObject *Sender)
{
TFormAbout * form=new TFormAbout(Application);
if (!form) return;
//настройка формы
form->NameProgramLabel->Caption="Модуль \"Сервисный центр\" ";
form->VerProgLabel->Caption="Версия программы: "+glGetVersionProgramFile();

form->VerBaseLabel->Caption="Версия базы: "+DM_Connection->GetVersionBase();

form->GrPosledLabel->Visible=false;

if (glDemo==true)
	{
	form->DemoLabel->Visible=true;
	}
else
	{
	form->DemoLabel->Visible=false;
	}
//получим версию файла
form->VerFileLabel->Caption="Версия файла: "+glGetVersionProgramFile();
//регистрационный номер
form->RegNumberLabel->Caption="Регистрационный номер: "+IntToStr(glRegNumber)
	+" ("+IntToHex(glRegNumber, 8)+")";

form->UpdateForm();
form->ShowModal();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TMainForm::CheckKey(void)
{
GrdStartup(GrdFMR_Local | GrdFMR_Remote );         //   && 

grd=GrdCreateHandle(0, GrdCHM_SingleThread, 0);
GrdSetAccessCodes(grd, 2103077223, 1365184227,2585575258, 5244555225);
GrdSetFindMode(grd,
			GrdFMR_Local | GrdFMR_Remote,        //локальный ключ   и сетвой ключ     GrdFMR_Local &&
			GrdFM_NProg,
			1,                   //номер программы
			0,
			0,
			0,
			0,
			0,
			GrdFMM_ALL,
			GrdFMI_ALL );

unsigned long  id_key=0;
GrdFind(grd,
			GrdF_First,
			&id_key,
			0);
GrdLogin(grd,
			0xFFFFFFFF,
			GrdLM_PerStation );

if (id_key==0) glDemo=true;
glRegNumber=id_key;
//GrdLogout(grd,0);
//GrdCloseHandle(grd);
//GrdCleanup();
}
//---------------------------------------------------------------------------
bool TMainForm::CheckEnableNew(void)
{
bool result=true;
if (glDemo==true)
	{ //проверим количество документов в базе данных
	TDMQueryRead *q=new TDMQueryRead(Application);
	q->DM_Connection=DM_Connection;
	q->Init();
	q->pFIBQ->SQL->Clear();
	q->pFIBQ->SQL->Add(" select MIN(galldoc.posdoc) as MINPOS from GALLDOC ");
	q->pFIBQ->SQL->Add("  where galldoc.posdoc>'18.08.2009'");
	q->pFIBQ->ExecQuery();
	double kol=0;
	if (q->pFIBQ->FieldByName("MINPOS")->AsDateTime>EncodeDate(2000,1,1))
		{
		kol=MonthSpan(Now(),q->pFIBQ->FieldByName("MINPOS")->AsDateTime);
		}
	if (kol>2)
		{
		result=false;
		UnicodeString s="Демонстрационный режим! \n";
		s=s+"Превышен интервал (2 месяца) пробной эксплуатации программы.\n";
		s=s+"Необходимо приобрести полную версию.";
		ShowMessage (s);
		}
	else
		{
		result=true;
		}
	delete q;
	}
return result;
}
//----------------------------------------------------------------------------




void __fastcall TMainForm::OpenHelpMainMenuClick(TObject *Sender)
{
Application->HelpJump("Remont_AllOpis");		
}
//---------------------------------------------------------------------------











void TMainForm::CreateMainMenu(void)
{
TMenuItem *menu;
TMenuItem *menu1;
TMenuItem *menu2;
TMenuItem *menu3;

//очистим меню
MainMenu->Items->Clear();

TDMInterfMainMenuGrp * dm_grp_menu=new TDMInterfMainMenuGrp(Application);
dm_grp_menu->DM_Connection=DM_Connection;
dm_grp_menu->Init();
dm_grp_menu->OpenMenuTable(GC_TypeProgMod_Remont,glStrToInt64(DM_Connection->UserInfoIDGRP_USER->AsString));


if (dm_grp_menu->MenuTable->RecordCount==0 &&
			DM_Connection->UserInfoNAME_USER->AsString=="SYSDBA")
	{//создадим меню хотя бы с возможностью настройки меню

	menu=new TMenuItem(MainMenu);
	menu->Caption="Сервис";
	MainMenu->Items->Add(menu);

	menu1=new TMenuItem(MainMenu);
	menu1->Caption="Настройка главного меню";
	menu1->OnClick = ExecuteModuleClick;
	menu1->Tag=GC_FormaSpiskaInterfMainMenu;
	menu->Insert(menu->Count,menu1);

	menu1=new TMenuItem(MainMenu);
	menu1->Caption="Пользователи";
	menu1->OnClick = ExecuteModuleClick;
	menu1->Tag=GC_FormaSpiskaSprUser;
	menu->Insert(menu->Count,menu1);
	}


__int64 id_tec_grp1=0;
__int64 id_tec_grp2=0;
__int64 id_tec_grp3=0;

int group_index=10;

dm_grp_menu->MenuTable->First();
while ( !dm_grp_menu->MenuTable->Eof)
		{

		if (dm_grp_menu->MenuTableOUT_IDGRP_1->AsInt64!=id_tec_grp1)
				{
				id_tec_grp1=dm_grp_menu->MenuTableOUT_IDGRP_1->AsInt64;
				menu=new TMenuItem(MainMenu);
				menu->Caption=dm_grp_menu->MenuTableOUT_NAMEGRP_1->AsString;
				//menu->OnClick = PopupMenuSprScaleClick;
				menu->GroupIndex=group_index;
				MainMenu->Items->Add(menu);
				group_index++;
				}


		if (dm_grp_menu->MenuTableOUT_IDGRP_2->AsInt64!=id_tec_grp2)
			{
			if (dm_grp_menu->MenuTableOUT_IDGRP_2->AsInt64!=0)
				{
				id_tec_grp2=dm_grp_menu->MenuTableOUT_IDGRP_2->AsInt64;
				menu1=new TMenuItem(MainMenu);
				menu1->Caption=dm_grp_menu->MenuTableOUT_NAMEGRP_2->AsString;
			   //	menu1->OnClick = PopupMenuSprScaleClickSubMenu;
			   //	menu1->Tag=DM->SprScaleAndGrpVesNom->RecNo;
				menu->Insert(menu->Count,menu1);
				}
			}

		if (dm_grp_menu->MenuTableOUT_IDGRP_3->AsInt64!=id_tec_grp3)
			{
			if (dm_grp_menu->MenuTableOUT_IDGRP_3->AsInt64!=0)
				{
				id_tec_grp3=dm_grp_menu->MenuTableOUT_IDGRP_3->AsInt64;
				menu2=new TMenuItem(MainMenu);
				menu2->Caption=dm_grp_menu->MenuTableOUT_NAMEGRP_3->AsString;
			   //	menu1->OnClick = PopupMenuSprScaleClickSubMenu;
			   //	menu1->Tag=DM->SprScaleAndGrpVesNom->RecNo;
				menu1->Insert(menu1->Count,menu2);
				}
			}

		//вставим непосредственно пункт меню

		if (dm_grp_menu->MenuTableOUT_IDGRP_3->AsInt64==0)
			{
			if (dm_grp_menu->MenuTableOUT_IDGRP_2->AsInt64==0)
				{
				if (dm_grp_menu->MenuTableOUT_IDGRP_1->AsInt64==0)
					{

					}
				else
					{
					menu3=new TMenuItem(MainMenu);
					menu3->Caption=dm_grp_menu->MenuTableNAME_INTERF_MAINMENU->AsString;
					menu3->OnClick = ExecuteModuleClick;
					menu3->Tag=dm_grp_menu->MenuTableMODUL_INTERF_MAINMENU->AsInteger;
					menu->Insert(menu->Count,menu3);
					}
				}
			else
				{
				menu3=new TMenuItem(MainMenu);
				menu3->Caption=dm_grp_menu->MenuTableNAME_INTERF_MAINMENU->AsString;
				menu3->OnClick = ExecuteModuleClick;
				menu3->Tag=dm_grp_menu->MenuTableMODUL_INTERF_MAINMENU->AsInteger;
				menu1->Insert(menu1->Count,menu3);
				}
			}
		else
			{
			menu3=new TMenuItem(MainMenu);
			menu3->Caption=dm_grp_menu->MenuTableNAME_INTERF_MAINMENU->AsString;
			menu3->OnClick = ExecuteModuleClick;
			menu3->Tag=dm_grp_menu->MenuTableMODUL_INTERF_MAINMENU->AsInteger;
			menu2->Insert(menu2->Count,menu3);
			}

		dm_grp_menu->MenuTable->Next();
		}

delete dm_grp_menu;

//создадим обязательные пункты меню


	menu=new TMenuItem(MainMenu);
	menu->Caption="Помощь";
	MainMenu->Items->Add(menu);

	menu1=new TMenuItem(MainMenu);
	menu1->Caption="О программе";
	menu1->OnClick = OpenFormAboutClick;
	menu->Insert(menu->Count,menu1);

	menu1=new TMenuItem(MainMenu);
	menu1->Caption="Содержание";
	menu1->OnClick = OpenHelpMainMenuClick;
	menu->Insert(menu->Count,menu1);

	menu=new TMenuItem(MainMenu);
	menu->Caption="Окна";
	MainMenu->Items->Add(menu);

	menu1=new TMenuItem(MainMenu);
	menu1->Caption="";
	menu1->OnClick = OpenFormAboutClick;
	menu->Insert(menu->Count,menu1);
//
//	menu1=new TMenuItem(MainMenu);
//	menu1->Caption="";
//	menu1->OnClick = OpenHelpMainMenuClick;
//	menu->Insert(menu->Count,menu1);

	MainForm->WindowMenu=menu;

}
//---------------------------------------------------------------------------
void TMainForm::CreateToolBar(void)
{
//загрузим в ImageList все картинки из папки Images
UnicodeString ProgramCatalog=ExtractFileDir(Application->ExeName)+"\\Images\\";
UnicodeString file_name="";
int image_index=0;
ImageListToolBar->Clear();

	TToolButton * but=new TToolButton(ToolBar1);
	but->Parent=ToolBar1;
	but->ImageIndex=-1;
	but->Style=tbsSeparator;


while (FileExists(ProgramCatalog+IntToStr(image_index)+".bmp")==true)
	{

	Graphics::TBitmap *b=new Graphics::TBitmap;
	b->LoadFromFile(ProgramCatalog+IntToStr(image_index)+".bmp");
	ImageListToolBar->AddMasked(b,b->Canvas->Pixels[1][1]);
	delete b;

    image_index++;
	}

TDMInterfToolBar * dm_tool_bar=new TDMInterfToolBar(Application);
dm_tool_bar->DM_Connection=DM_Connection;
dm_tool_bar->Init();
dm_tool_bar->OpenTable(GC_TypeProgMod_Remont,glStrToInt64(DM_Connection->UserInfoIDGRP_USER->AsString));

int kol_button=0;
dm_tool_bar->Table->First();
while (!dm_tool_bar->Table->Eof)
	{
	TToolButton * but=new TToolButton(ToolBar1);
	but->Parent=ToolBar1;
	but->OnClick=ExecuteModuleToolBarClick;
	but->Tag=dm_tool_bar->TableMODUL_INTERF_TOOLBAR->AsInteger;
	but->Caption=dm_tool_bar->TableNAME_INTERF_TOOLBAR->AsString;
	but->Hint=dm_tool_bar->TableHINT_INTERF_TOOLBAR->AsString;
	but->ShowHint=true;
	but->ImageIndex=dm_tool_bar->TableIMAGEINDEX_INTERF_TOOLBAR->AsInteger;
	if (dm_tool_bar->TableNAME_INTERF_TOOLBAR->AsString=="|")
		{
        but->Style=tbsSeparator;
		}
	dm_tool_bar->Table->Next();
	kol_button++;
	}

delete dm_tool_bar;

if (kol_button==0)
	{
    ToolBar1->Visible=false;
	}
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::ExecuteModuleToolBarClick(TObject *Sender)
{
int i= ((TToolButton*)Sender)->Tag;
ExecuteModule(i) ;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ExecuteModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->Tag;
ExecuteModule(i) ;
}
//---------------------------------------------------------------------------
void TMainForm::ExecuteModule(int num_module)
{
if (CheckEnableNew()==false) return;
switch (num_module)
        {
		case GC_FormaSpiskaInterfMainMenu :
				{
				TFormaSpiskaInterfMainMenu * form=new TFormaSpiskaInterfMainMenu(Application);
				form->DM_Connection=DM_Connection;
				form->Init();
				if (!form) return;
				form->UpdateForm();
				form->Show();
				} break;
		case GC_FormaSpiskaSprUser :
				{
				TFormaSpiskaSprUser * Users=new TFormaSpiskaSprUser(Application);
				Users->DM_Connection=DM_Connection;
				Users->Init();
				if (!Users) return;
				//настройка формы
				Users->UpdateForm();
				Users->Show();
				} break;
		case GC_REM_FormaSpiskaSprNeispr :
				{
				TREM_FormaSpiskaSprNeispr * SprNeispr=new TREM_FormaSpiskaSprNeispr(Application);
				SprNeispr->DM_Connection=DM_Connection;
				SprNeispr->Init();
				if (!SprNeispr) return;
				SprNeispr->UpdateForm();
				SprNeispr->Show();
				} break;
		case GC_REM_FormaSpiskaSprModel :
				{
				TREM_FormaSpiskaSprModel * Spr=new TREM_FormaSpiskaSprModel(Application);
				Spr->DM_Connection=DM_Connection;
				Spr->Init();
				if (!Spr) return;
				Spr->UpdateForm();
				Spr->Show();
				} break;
		case GC_REM_FormaSpiskaSprTypeRemont :
				{
				TREM_FormaSpiskaSprTypeRemont * Spr=new TREM_FormaSpiskaSprTypeRemont(Application);
				Spr->DM_Connection=DM_Connection;
				Spr->Init();
				if (!Spr) return;
				Spr->Show();
				} break;
		case GC_REM_FormaSpiskaSprSost :
				{
				TREM_FormaSpiskaSprSost * Spr=new TREM_FormaSpiskaSprSost(Application);
				Spr->DM_Connection=DM_Connection;
				Spr->Init();
				if (!Spr) return;
				Spr->Show();
				} break;
		case GC_REM_FormaGurZ :
				{
				TREM_FormaGurZ * GurZ=new TREM_FormaGurZ(Application);
				GurZ->DM_Connection=DM_Connection;
				GurZ->Init();
				if (!GurZ) return;
				GurZ->Show();
				} break;
		case GC_REM_FormaGurAllDoc :
				{
				TREM_FormaGurAllDoc * GurAllDoc=new TREM_FormaGurAllDoc(Application);
				GurAllDoc->DM_Connection=DM_Connection;
				GurAllDoc->Init();
				if (!GurAllDoc) return;
				GurAllDoc->Show();
				} break;
		case GC_REM_FormaDocRemont :
				{
				TREM_FormaDocRemont * doc=new TREM_FormaDocRemont(Application);
				doc->DM_Connection=DM_Connection;
				doc->Init();
				if (!doc) return;
				doc->DM->NewDoc();
				doc->UpdateForm();
				doc->Show();
				} break;
		case GC_REM_FormaSpiskaSprHardware :
				{
				TREM_FormaSpiskaSprHardware * spr=new TREM_FormaSpiskaSprHardware(Application);
				spr->DM_Connection=DM_Connection;
				spr->Init();
				if (!spr) return;
				spr->UpdateForm();
				spr->Show();
				} break;
		case GC_REM_FormaDocRemontHW :
				{
				TREM_FormaDocRemontHW * doc=new TREM_FormaDocRemontHW(Application);
				doc->DM_Connection=DM_Connection;
				doc->Init();
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				doc->Show();
				} break;
		case GC_REM_FormaSpiskaSprKKT :
				{
				TREM_FormaSpiskaSprKKT * spr=new TREM_FormaSpiskaSprKKT(Application);
				spr->DM_Connection=DM_Connection;
				spr->Init();
				if (!spr) return;
				//настройка формы

				spr->UpdateForm();
				spr->Show();
				} break;
		case GC_REM_FormaDocRemontKKT :
				{
				TREM_FormaDocRemontKKT * doc=new TREM_FormaDocRemontKKT(Application);
				doc->DM_Connection=DM_Connection;
				doc->Init();
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				doc->Show();
				} break;
		case GC_REM_FormaDocKM1 :
				{
				TREM_FormaDocKM1 * doc=new TREM_FormaDocKM1(Application);
				doc->DM_Connection=DM_Connection;
				doc->Init();
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				doc->Show();
				} break;
		case GC_REM_FormaDocKM2 :
				{
				TREM_FormaDocKM2 * doc=new TREM_FormaDocKM2(Application);
				doc->DM_Connection=DM_Connection;
				doc->Init();
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				doc->Show();
				} break;
		case GC_REM_FormaDocSetServKKT :
				{
				TREM_FormaDocSetServKKT * doc=new TREM_FormaDocSetServKKT(Application);
				doc->DM_Connection=DM_Connection;
				doc->Init();
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				doc->Show();
				} break;
		case GC_REM_FormaDocSetServHW :
				{
				TREM_FormaDocSetServHW * doc=new TREM_FormaDocSetServHW(Application);
				doc->DM_Connection=DM_Connection;
				doc->Init();
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				doc->Show();
				} break;
		case GC_FormaSpiskaSprFirm :
				{
				TFormaSpiskaSprFirm * SprFirm=new TFormaSpiskaSprFirm(Application);
				SprFirm->DM_Connection=DM_Connection;
				SprFirm->Init();
				if (!SprFirm) return;
				//настройка формы

				SprFirm->Show();
				} break;
		case GC_FormaSpiskaSprSklad :
				{
				TFormaSpiskaSprSklad * SprSklad=new TFormaSpiskaSprSklad(Application);
				SprSklad->DM_Connection=DM_Connection;
				SprSklad->Init();
				if (!SprSklad) return;
				//настройка формы

				SprSklad->Show();
				} break;
		case GC_FormaSpiskaSprKKM :
				{
				TFormaSpiskaSprKKM * SprKKM=new TFormaSpiskaSprKKM(Application);
				SprKKM->DM_Connection=DM_Connection;
				SprKKM->Init();
				if (!SprKKM) return;
				//настройка формы

				SprKKM->Show();
				} break;
		case GC_FormaSpiskaSprKlient :
				{
				TFormaSpiskaSprKlient * SprKlient=new TFormaSpiskaSprKlient(Application);
				SprKlient->DM_Connection=DM_Connection;
				SprKlient->Init();
				if (!SprKlient) return;
				//настройка формы
				SprKlient->UpdateForm();
				SprKlient->Show();
				} break;
		case GC_FormaSpiskaSprNom :
				{
				TFormaSpiskaSprNom * SprNom=new TFormaSpiskaSprNom(Application);
				SprNom->DM_Connection=DM_Connection;
				SprNom->Init();
				if (!SprNom) return;
				//настройка формы
				SprNom->DM->IdTypePrice=glStrToInt64(DM_Connection->UserInfoIDTPRICE_USER->AsString);

				SprNom->SpisokTypePrice->ItemIndex=SprNom->DM->GetIndexTypePrice()-1;
				SprNom->UpdateForm();
				SprNom->Show();
				} break;
		case GC_FormaGurAllDoc :
				{
				TFormaGurAllDoc * GurAllDoc=new TFormaGurAllDoc(Application);
				GurAllDoc->DM_Connection=DM_Connection;
				GurAllDoc->Init();
				if (!GurAllDoc) return;
				//настройка формы

				GurAllDoc->Show();
				} break;
		case GC_FormaDocPrihNakl :
				{
				TFormaDocPrihNakl * PrNakl=new TFormaDocPrihNakl(Application);
				PrNakl->DM_Connection=DM_Connection;
				PrNakl->Init();
				if (!PrNakl) return;
				//настройка формы
				PrNakl->DM->NewDoc();
				PrNakl->UpdateForm();
				PrNakl->Show();
				} break;
		case GC_FormaDocCheck :
				{
				TFormaDocCheck * Check=new TFormaDocCheck(Application);
				Check->DM_Connection=DM_Connection;
				Check->Init();
				if (!Check) return;
				//настройка формы
				Check->DM->NewDoc();
				Check->Operation->ItemIndex=0;
				Check->UpdateForm();
				Check->Show();
				} break;
		case GC_FormaDocSchet :
				{
				TFormaDocSchet * Schet=new TFormaDocSchet(Application);
				Schet->DM_Connection=DM_Connection;
				Schet->Init();
				if (!Schet) return;
				//настройка формы
				Schet->DM->NewDoc();
				Schet->UpdateForm();
				Schet->Show();
				} break;
		case GC_FormaDocOstNom :
				{
				TFormaDocOstNom * OstNom=new TFormaDocOstNom(Application);
				OstNom->DM_Connection=DM_Connection;
				OstNom->Init();
				if (!OstNom) return;
				//настройка формы
				OstNom->DM->NewDoc();
				OstNom->UpdateForm();
				OstNom->Show();
				} break;
		case GC_FormaDocPer :
				{
				TFormaDocPer* Per=new TFormaDocPer(Application);
				Per->DM_Connection=DM_Connection;
				Per->Init();
				if (!Per) return;
				//настройка формы
				Per->DM->NewDoc();
				Per->UpdateForm();
				Per->Show();
				} break;
		case GC_FormaDocReal :
				{
				TFormaDocReal* Real=new TFormaDocReal(Application);
				Real->DM_Connection=DM_Connection;
				Real->Init();
				if (!Real) return;
				//настройка формы
				Real->DM->NewDoc();
				Real->UpdateForm();
				Real->Show();
				} break;
		case GC_FormaDocSpisNom :
				{
				TFormaDocSpisNom* SpisNom=new TFormaDocSpisNom(Application);
				SpisNom->DM_Connection=DM_Connection;
				SpisNom->Init();
				if (!SpisNom) return;
				//настройка формы
				SpisNom->DM->NewDoc();
				SpisNom->UpdateForm();
				SpisNom->Show();
				} break;
		case GC_FormaDocVosvratPost :
				{
				TFormaDocVosvratPost* VosvratPost=new TFormaDocVosvratPost(Application);
				VosvratPost->DM_Connection=DM_Connection;
				VosvratPost->Init();
				if (!VosvratPost) return;
				//настройка формы
				VosvratPost->DM->NewDoc();
				VosvratPost->UpdateForm();
				VosvratPost->Show();
				} break;
		case GC_FormaDocPKO :
				{
				TFormaDocPKO* PKO=new TFormaDocPKO(Application);
				PKO->DM_Connection=DM_Connection;
				PKO->Init();
				if (!PKO) return;
				//настройка формы
				PKO->DM->NewDoc();
				PKO->UpdateForm();
				PKO->Show();
				} break;
		case GC_FormaDocRKO :
				{
				TFormaDocRKO* RKO=new TFormaDocRKO(Application);
				RKO->DM_Connection=DM_Connection;
				RKO->Init();
				if (!RKO) return;
				//настройка формы
				RKO->DM->NewDoc();
				RKO->UpdateForm();
				RKO->Show();
				} break;
		case GC_FormaDocPlatPor :
				{
				TFormaDocPlatPor * PlPor=new TFormaDocPlatPor(Application);
				PlPor->DM_Connection=DM_Connection;
				PlPor->Init();
				if (!PlPor) return;
				//настройка формы
				PlPor->DM->NewDoc();
				PlPor->UpdateForm();
				PlPor->Show();
				} break;
		case GC_FormaDocPostNaSchet :
				{
				TFormaDocPostNaSchet * Post=new TFormaDocPostNaSchet(Application);
				Post->DM_Connection=DM_Connection;
				Post->Init();
				if (!Post) return;
				//настройка формы
				Post->DM->NewDoc();
				Post->UpdateForm();
				Post->Show();
				} break;
		case GC_FormaSpiskaSprPodr :
				{
				TFormaSpiskaSprPodr * Podr=new TFormaSpiskaSprPodr(Application);
				Podr->DM_Connection=DM_Connection;
				Podr->Init();
				if (!Podr) return;
				//настройка формы

				Podr->Show();
				} break;
		case GC_FormaSpiskaSprBVNom :
				{
				TFormaSpiskaSprBVNom * BV=new TFormaSpiskaSprBVNom(Application);
				BV->DM_Connection=DM_Connection;
				BV->Init();
				if (!BV) return;
				//настройка формы
				BV->IdPod=glStrToInt64(DM_Connection->UserInfoIDPOD_USER->AsString);
				BV->EditPodr->Text=DM_Connection->UserInfoNAMEPOD->AsString;
				BV->UpdateForm();
				BV->Show();
				} break;
		case GC_FormaSpiskaSprStrObject :
				{
				TFormaSpiskaSprStrObject * StrOb=new TFormaSpiskaSprStrObject(Application);
				StrOb->DM_Connection=DM_Connection;
				StrOb->Init();
				if (!StrOb) return;
				//настройка формы

				StrOb->Show();
				} break;
		case GC_FormaReportOCBRegGoods :
				{
				TFormaReportOCBRegGoods * Rep=new TFormaReportOCBRegGoods(Application);
				Rep->DM_Connection=DM_Connection;
				Rep->Init();
				if (!Rep) return;
				//настройка формы

				Rep->Show();
				} break;
		case GC_FormaSpiskaSprTypePrice :
				{
				TFormaSpiskaSprTypePrice * TypePrice=new TFormaSpiskaSprTypePrice(Application);
				TypePrice->DM_Connection=DM_Connection;
				TypePrice->Init();
				if (!TypePrice) return;
				//настройка формы

				TypePrice->Show();
				} break;
		case GC_FormaSpiskaSprMPrig :
				{
				TFormaSpiskaSprMPrig * MPrig=new TFormaSpiskaSprMPrig(Application);
				MPrig->DM_Connection=DM_Connection;
				MPrig->Init();
				if (!MPrig) return;
				//настройка формы

				MPrig->Show();
				} break;
		case GC_FormaSpiskaSprCodeTel :
				{
				TFormaSpiskaSprCodeTel * SprCodeTel=new TFormaSpiskaSprCodeTel(Application);
				SprCodeTel->DM_Connection=DM_Connection;
				SprCodeTel->Init();
				if (!SprCodeTel) return;
				//настройка формы

				SprCodeTel->Show();
				} break;
		case GC_FormaDialogaReportSaleCheck :
				{
				TFormaDialogaReportSaleCheck * Rep=new TFormaDialogaReportSaleCheck(Application);
				Rep->DM_Connection=DM_Connection;
				Rep->Init();
				if (!Rep) return;
				//настройка формы

				Rep->Show();
				} break;
		case GC_FormaGurDocPrihNakl :
				{
				TFormaGurDocPrihNakl * Gur=new TFormaGurDocPrihNakl(Application);
				Gur->DM_Connection=DM_Connection;
				Gur->Init();
				if (!Gur) return;
				//настройка формы

				Gur->Show();
				} break;
		case GC_FormaGurDocCheckKKM :
				{
				TFormaGurDocCheckKKM * Gur=new TFormaGurDocCheckKKM(Application);
				Gur->DM_Connection=DM_Connection;
				Gur->Init();
				if (!Gur) return;
				//настройка формы

				Gur->Show();
				} break;
		case GC_FormaGurDocPer :
				{
				TFormaGurDocPer * Gur=new TFormaGurDocPer(Application);
				Gur->DM_Connection=DM_Connection;
				Gur->Init();
				if (!Gur) return;
				//настройка формы

				Gur->Show();
				} break;
		case GC_FormaReportOCBRegVSRasch :
				{
				TFormaReportOCBRegVSRasch * Rep=new TFormaReportOCBRegVSRasch(Application);
				Rep->DM_Connection=DM_Connection;
				Rep->Init();

				if (!Rep) return;
				//настройка формы

				Rep->Show();
				} break;
		case GC_FormaDocInv :
				{
				TFormaDocInv * Doc=new TFormaDocInv(Application);
				Doc->DM_Connection=DM_Connection;
				Doc->Init();
				if (!Doc) return;
				//настройка формы
				Doc->DM->NewDoc();
				Doc->UpdateForm();
				Doc->Show();
				} break;
		case GC_FormaDialogaReportResultReal :
				{
				TFormaDialogaReportResultReal * Rep=new TFormaDialogaReportResultReal(Application);
				Rep->DM_Connection=DM_Connection;
				Rep->Init();
				if (!Rep) return;
				//настройка формы

				Rep->Show();
				} break;
		case GC_FormaReportVipuskProd :
				{
				TFormaReportVipuskProd * Rep=new TFormaReportVipuskProd(Application);
				Rep->DM_Connection=DM_Connection;
				Rep->Init();
				if (!Rep) return;
				//настройка формы

				Rep->Show();
				} break;
		case GC_FormaReportKartTovara :
				{
				TFormaReportKartTovara * Rep=new TFormaReportKartTovara(Application);
				Rep->DM_Connection=DM_Connection;
				Rep->Init();
				if (!Rep) return;
				//настройка формы

				Rep->Show();
				} break;
		case GC_FormaSpiskaSetup :
				{
				TFormaSpiskaSetup * set=new TFormaSpiskaSetup(Application);
				set->DM_Connection=DM_Connection;
				set->Init();
				if (!set) return;
				//настройка формы

				set->Show();
				} break;
		case GC_FormaReportKartKlient :
				{
				TFormaReportKartKlient * Rep=new TFormaReportKartKlient(Application);
				Rep->DM_Connection=DM_Connection;
				Rep->Init();
				if (!Rep) return;
				//настройка формы
				Rep->Show();
				} break;
		case GC_FormaSpiskaSprInfBase :
				{
				TFormaSpiskaSprInfBase * Spr=new TFormaSpiskaSprInfBase(Application);
				Spr->DM_Connection=DM_Connection;
				Spr->Init();
				if (!Spr) return;
				//настройка формы

				Spr->DM->OpenTable();
				Spr->Show();
				} break;
		case GC_FormaDocRepKKM :
				{
				TFormaDocRepKKM * RepKKM=new TFormaDocRepKKM(Application);
				RepKKM->DM_Connection=DM_Connection;
				RepKKM->Init();
				if (!RepKKM) return;
				//настройка формы
				RepKKM->DM->NewDoc();
				RepKKM->UpdateForm();
				RepKKM->Show();
				} break;
		case GC_FormaReportKalkKarta :
				{
				TFormaReportKalkKarta * Rep=new TFormaReportKalkKarta(Application);
				Rep->DM_Connection=DM_Connection;
				Rep->Init();
				if (!Rep) return;
				//настройка формы

				Rep->Show();
				} break;
		case GC_FormaReportOCBRegOstNom :
				{
				TFormaReportOCBRegOstNom * Rep=new TFormaReportOCBRegOstNom(Application);
				Rep->DM_Connection=DM_Connection;
				Rep->Init();
				if (!Rep) return;
				//настройка формы

				Rep->Show();
				} break;
		case GC_FormaReportRashodProduct :
				{
				TFormaReportRashodProduct * Rep=new TFormaReportRashodProduct(Application);
				Rep->DM_Connection=DM_Connection;
				Rep->Init();
				if (!Rep) return;
				//настройка формы

				Rep->Show();
				} break;
		case GC_FormaSpiskaSprARM :
				{
				TFormaSpiskaSprARM * SprARM=new TFormaSpiskaSprARM(Application);
				SprARM->DM_Connection=DM_Connection;
				SprARM->Init();
				if (!SprARM) return;
				//настройка формы

				SprARM->Show();
				} break;
		case GC_FormaDocOstVs :
				{
				TFormaDocOstVs* doc=new TFormaDocOstVs(Application);
				doc->DM_Connection=DM_Connection;
				doc->Init();
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				doc->Show();
				} break;
		case GC_SheetEditor :
				{
				TSheetEditor * SE=new TSheetEditor(Application);
				if (!SE) return;
				SE->Show();
				} break;
		case GC_FormaDocRealRozn :
				{
				TFormaDocRealRozn* Real=new TFormaDocRealRozn(Application);
				Real->DM_Connection=DM_Connection;
				Real->Init();
				if (!Real) return;
				//настройка формы
				Real->DM->NewDoc();
				Real->UpdateForm();
				Real->Show();
				} break;
		case GC_FormaDocPKORozn :
				{
				TFormaDocPKORozn* doc=new TFormaDocPKORozn(Application);
				doc->DM_Connection=DM_Connection;
				doc->Init();
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				doc->Show();
				} break;
		case GC_FormaDocRKORozn :
				{
				TFormaDocRKORozn* doc=new TFormaDocRKORozn(Application);
				doc->DM_Connection=DM_Connection;
				doc->Init();
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				doc->Show();
				} break;
		case GC_FormaReportOCBPaySale :
				{
				TFormaReportOCBPaySale * Rep=new TFormaReportOCBPaySale(Application);
				Rep->DM_Connection=DM_Connection;
				Rep->Init();
				if (!Rep) return;
				//настройка формы

				Rep->Show();
				} break;
		case GC_FormaReportKassa :
				{
				TFormaReportKassa * Rep=new TFormaReportKassa(Application);
				Rep->DM_Connection=DM_Connection;
				Rep->Init();
				if (!Rep) return;
				//настройка формы

				Rep->Show();
				} break;
		case GC_FormaReportBank :
				{
				TFormaReportBank * Rep=new TFormaReportBank(Application);
				Rep->DM_Connection=DM_Connection;
				Rep->Init();
				if (!Rep) return;
				//настройка формы

				Rep->Show();
				} break;
		case GC_FormaPrintPriceA :
				{
				TFormaPrintPriceA * Rep=new TFormaPrintPriceA(Application);
				Rep->DM_Connection=DM_Connection;
				Rep->Init();
				if (!Rep) return;
				//настройка формы

				Rep->Show();
				} break;
		case GC_FormaSpiskaSprInv :
				{
				TFormaSpiskaSprInv * spr=new TFormaSpiskaSprInv(Application);
				spr->DM_Connection=DM_Connection;
				spr->Init();
				if (!spr) return;
				//настройка формы

				spr->Show();
				} break;
		case GC_FormaDocVosvratPok :
				{
				TFormaDocVosvratPok * doc=new TFormaDocVosvratPok(Application);
				doc->DM_Connection=DM_Connection;
				doc->Init();
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				doc->Show();
				} break;
		case GC_FormaDocSpOtrOst :
				{
				TFormaDocSpOtrOst * doc=new TFormaDocSpOtrOst(Application);
				doc->DM_Connection=DM_Connection;
				doc->Init();
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				doc->Show();
				} break;
		case GC_FormaDocIsmPrice :
				{
				TFormaDocIsmPrice * doc=new TFormaDocIsmPrice(Application);
				doc->DM_Connection=DM_Connection;
				doc->Init();
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				doc->Show();
				} break;
		case GC_FormaDocRev :
				{
				TFormaDocRev * doc=new TFormaDocRev(Application);
				doc->DM_Connection=DM_Connection;
				doc->Init();
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				doc->Show();
				} break;
		case GC_FormaReportDiscountDocCheck :
				{
				TFormaReportDiscountDocCheck * Rep=new TFormaReportDiscountDocCheck(Application);
				Rep->DM_Connection=DM_Connection;
				Rep->Init();
				if (!Rep) return;
				//настройка формы

				Rep->Show();
				} break;
		case GC_FormaReportGoodsReport :
				{
				TFormaReportGoodsReport * Rep=new TFormaReportGoodsReport(Application);
				Rep->DM_Connection=DM_Connection;
				Rep->Init();
				if (!Rep) return;
				//настройка формы

				Rep->Show();
				} break;
		case GC_FormaGurLog :
				{
				if (DM_Connection->UserInfoSHOW_LOG_SUSER->AsInteger==1)
					{
					TFormaGurLog * Gur=new TFormaGurLog(Application);
					Gur->DM_Connection=DM_Connection;
					Gur->Init();
					if (!Gur) return;
					//настройка формы
					Gur->Show();
					}
				else
					{
					ShowMessage("У Вас не прав доступа к журналу событий!");
					}
				} break;
		case GC_FormaSpiskaSprVidKlient :
				{
				TFormaSpiskaSprVidKlient * FormaSpiskaSprVidKlient=new TFormaSpiskaSprVidKlient(Application);
				FormaSpiskaSprVidKlient->DM_Connection=DM_Connection;
				FormaSpiskaSprVidKlient->Init();
				FormaSpiskaSprVidKlient->UpdateForm();
				FormaSpiskaSprVidKlient->Show();
				} break;
		case GC_FormaSpiskaSprVidNom :
				{
				TFormaSpiskaSprVidNom * FormaSpiskaSprVidNom=new TFormaSpiskaSprVidNom(Application);
				FormaSpiskaSprVidNom->DM_Connection=DM_Connection;
				FormaSpiskaSprVidNom->Init();
				FormaSpiskaSprVidNom->UpdateForm();
				FormaSpiskaSprVidNom->Show();
				} break;
		case GC_FormaSpiskaSprDiscountAuto :
				{
				TFormaSpiskaSprDiscountAuto * FormaSpiskaSprDiscountAuto=new TFormaSpiskaSprDiscountAuto(Application);
				FormaSpiskaSprDiscountAuto->DM_Connection=DM_Connection;
				FormaSpiskaSprDiscountAuto->Init();
				FormaSpiskaSprDiscountAuto->UpdateForm();
				FormaSpiskaSprDiscountAuto->Show();
				} break;
		case GC_FormaSpiskaSprVidDiscountCard :
				{
				TFormaSpiskaSprVidDiscountCard * spr=new TFormaSpiskaSprVidDiscountCard(Application);
				spr->DM_Connection=DM_Connection;
				spr->Init();
				spr->UpdateForm();
				spr->Show();
				} break;
		case GC_FormaSpiskaTableNumberDoc :
				{
				TFormaSpiskaTableNumberDoc * table=new TFormaSpiskaTableNumberDoc(Application);
				table->DM_Connection=DM_Connection;
				table->Init();
				table->Show();
				} break;
		case GC_FormaSpiskaSprNakSkidok :
				{
				TFormaSpiskaSprNakSkidok * spr=new TFormaSpiskaSprNakSkidok(Application);
				spr->DM_Connection=DM_Connection;
				spr->Init();
				spr->UpdateForm();
				spr->Show();
				} break;
		case GC_FormaGurOperDiscountCard :
				{
				TFormaGurOperDiscountCard * gur=new TFormaGurOperDiscountCard (Application);
				gur->DM_Connection=DM_Connection;
				gur->Init();
				gur->UpdateForm();
				gur->Show();
				} break;
		case GC_FormaSpiskaXSetupObmen :
				{
				TFormaSpiskaXSetupObmen * form=new TFormaSpiskaXSetupObmen(Application);
				form->DM_Connection=DM_Connection;
				form->Init();
				if (!form) return;
				//настройка формы

				form->Show();
				} break;
		case GC_FormaSpiskaSprImportSet :
				{
				TFormaSpiskaSprImportSet * form=new TFormaSpiskaSprImportSet(Application);
				form->DM_Connection=DM_Connection;
				form->Init();
				if (!form) return;
				//настройка формы
				form->UpdateForm();
				form->Show();
				} break;
		case GC_FormaDocVipuskProd :
				{
				TFormaDocVipuskProd* doc=new TFormaDocVipuskProd(Application);
				doc->DM_Connection=DM_Connection;
				doc->Init();
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				doc->Show();
				} break;
		case GC_FormaImportDocPrihNakl :
				{
				TFormaImportDocPrihNakl * form=new TFormaImportDocPrihNakl(Application);
				form->DM_Connection=DM_Connection;
				form->Init();

				if (!form) return;
				form->UpdateForm();
				} break;
		case GC_FormaExportDoc :
				{
				TFormaExportDoc *form=new	 TFormaExportDoc(Application);
				form->DM_Connection=DM_Connection;
				form->Init();
				if (!form) return;
				form->UpdateForm();
				} break;
		case GC_FormaSpiskaSprScale :
				{
				TFormaSpiskaSprScale * spr=new TFormaSpiskaSprScale(Application);
				spr->DM_Connection=DM_Connection;
				spr->Init();
				if (!spr) return;
				//настройка формы

				spr->Show();
				} break;
		case GC_FormaSpiskaSprProject :
				{
				TFormaSpiskaSprProject * spr=new TFormaSpiskaSprProject(Application);
				spr->DM_Connection=DM_Connection;
				spr->Init();
				if (!spr) return;
				//настройка формы
				spr->UpdateForm();
				spr->Show();
				} break;
		case GC_FormaDialogaReportPoProject :
				{
				TFormaDialogaReportPoProject * Rep=new TFormaDialogaReportPoProject(Application);
				Rep->DM_Connection=DM_Connection;
				Rep->Init();
				if (!Rep) return;
				//настройка формы

				Rep->Show();
				} break;
		case GC_FormaSpiskaExtModule :
				{
				TFormaSpiskaExtModule * form=new TFormaSpiskaExtModule(Application);
				form->DM_Connection=DM_Connection;
				form->Init();
				if (!form) return;
				//настройка формы
				form->UpdateForm();
				form->Show();
				} break;
		case GC_FormaSpiskaTableExtPrintForm :
				{
				TFormaSpiskaTableExtPrintForm * form=new TFormaSpiskaTableExtPrintForm(Application);
				form->DM_Connection=DM_Connection;
				form->Init();
				if (!form) return;
				//настройка формы

				form->Show();
				} break;
		case GC_FormaDocSborkaKompl :
				{
				TFormaDocSborkaKompl * doc=new TFormaDocSborkaKompl(Application);
				doc->DM_Connection=DM_Connection;
				doc->Init();
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				doc->Show();
				} break;
		case GC_FormaDocRasborkaKompl :
				{
				TFormaDocRasborkaKompl * doc=new TFormaDocRasborkaKompl(Application);
				doc->DM_Connection=DM_Connection;
				doc->Init();
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				doc->Show();
				} break;
		case GC_FormaDocZamena :
				{
				TFormaDocZamena * doc=new TFormaDocZamena(Application);
				doc->DM_Connection=DM_Connection;
				doc->Init();
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				doc->Show();
				} break;
		case GC_FormaDocKorrVs :
				{
				TFormaDocKorrVS * doc=new TFormaDocKorrVS(Application);
				doc->DM_Connection=DM_Connection;
				doc->Init();
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				doc->Show();
				} break;
		case GC_FormaDocVipBanka :
				{
				TFormaDocVipBanka * doc=new TFormaDocVipBanka(Application);
				doc->DM_Connection=DM_Connection;
				doc->Init();
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				doc->Show();
				} break;

        default :
                {
                 ShowMessage("Неизвестный модуль!");
                } break;
		}

}
//----------------------------------------------------------------------------

