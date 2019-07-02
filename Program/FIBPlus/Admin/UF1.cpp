//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "SysUtils.hpp"
#include "UF1.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprKKM.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaGurAllDoc.h"
#include "IFormaDocPrihNakl.h"
#include "IFormaDocCheck.h"

#include "IFormaDocSchet.h"
#include "IFormaDocOstNom.h"
#include "IFormaDocPer.h"
#include "IFormaDocReal.h"
#include "IFormaDocSpisNom.h"
#include "IFormaDocVosvratPost.h"
#include "IFormaDocPKO.h"
#include "IFormaDocRKO.h"
#include "IFormaDocPlatPor.h"
#include "IFormaDocPostNaSchet.h"
#include "IFormaSpiskaSprPodr.h"
#include "IFormaSpiskaSprBVNom.h"
#include "IFormaSpiskaSprStrObject.h"
#include "IFormaSpiskaSprTypePrice.h"
#include "IFormaSpiskaSprUser.h"
#include "IDMSprUser.h"
#include "IFormaSpiskaSprOborud.h"
#include "IFormaSpiskaSprMPrig.h"
#include "IFormaSpiskaSprCodeTel.h"

#include "IFormaGurDocPrihNakl.h"
#include "IFormaGurDocCheckKKM.h"
#include "IFormaGurDocPer.h"
#include "IFormaDocInv.h"
#include "IFormaSpiskaSetup.h"
#include "IFormaSpiskaSprInfBase.h"
#include "IDMSetup.h"
#include "IFormaDocRepKKM.h"
#include "IFormaSpiskaSprARM.h"
#include "IFormaSpiskaSprVesNom.h"
#include "IDMSprOborud.h"
#include "IDMSprARM.h"
#include "UAbout.h"
#include "IFormaDocOstVs.h"

#include "ISheetEditor.h"
#include "IFormaDocRealRozn.h"
#include "IFormaDocPKORozn.h"
#include "IFormaDocRKORozn.h"

#include "IFormaSpiskaTableExtPrintForm.h"

//вызов справочной системы
#include "HTMLHelpViewer.hpp"
#include "IFormaSpiskaSprInv.h"
#include "IFormaDocVosvratPok.h"
#include "IFormaDocIsmPrice.h"
#include "IFormaDocRev.h"
#include "IFormaDocSpOtrOst.h"
#include "IDMQueryRead.h"

#include "IFormaGurLog.h"
#include "IFormaSpiskaSprVidKlient.h"
#include "IFormaSpiskaSprVidNom.h"
#include "IFormaSpiskaSprDiscountAuto.h"
#include "IFormaSpiskaSprVidDiscountCard.h"
#include "IFormaSpiskaTableNumberDoc.h"
#include "IFormaSpiskaSprNakSkidok.h"
#include "IDMGurOperDiscountCard.h"
#include "IFormaGurOperDiscountCard.h"
#include "IFormaSpiskaXSetupObmen.h"
#include "IFormaSpiskaSprImportSet.h"
#include "IFormaDocVipuskProd.h"
#include "IFormaImportDocPrihNakl.h"
#include "IFormaSpiskaSprScale.h"
#include "IFormaSpiskaSprProject.h"
#include "IFormaSpiskaExtModule.h"
#include "IFormaDocSborkaKompl.h"
#include "IFormaDocRasborkaKompl.h"
#include "IFormaDocZamena.h"
#include "IFormaDocKorrVS.h"
#include "IFormaDocVipBanka.h"
#include "IFormaSpiskaSprBrand.h"
#include "IFormaDocRegAdvCust.h"
#include "IFormaDocRegBank.h"
#include "IFormaDocRegGoods.h"
#include "IFormaDocRegKassa.h"
#include "IFormaDocRegOstNom.h"
#include "IFormaDocRegPaySale.h"
#include "IFormaDocRegVsRasch.h"
#include "IFormaSpiskaSprDiscountCard_1.h"
#include "IFormaDocRegCardBalance.h"
#include "IFormaSpiskaInterfMainMenu.h"
#include "UGlobalConstant.h"
#include "IFormaSpiskaInterfToolBar.h"

#include "IFormaSpiskaObjectBasePriv.h"
#include "UGlobalFunction.h"
#include "IFormaSpiskaSprProgramModule.h"
#include "IFormaDocOtchetPost.h"
#include "IFormaDocRegOtchetPost.h"

//ГОСТИНИЦА
#include "IHOT_FormaSpiskaSprCatNom.h"
#include "IHOT_FormaSpiskaSprObject.h"
#include "IHOT_FormaSpiskaSprTypePosel.h"
#include "IHOT_FormaSpiskaSprSostNom.h"
#include "IHOT_FormaSpiskaSprNF.h"
#include "IHOT_FormaSpiskaSprPrOsnUslug.h"
#include "IHOT_FormaSpiskaSprCelPriesda.h"
#include "IHOT_FormaDocBron.h"
#include "IHOT_FormaGurAllDoc.h"
#include "IHOT_FormaDocRasm.h"
#include "IHOT_FormaDocViezd.h"
#include "IHOT_FormaSpiskaTableSostNF.h"
#include "IHOT_FormaDocReal.h"
#include "IHOT_FormaDocRaschet.h"
#include "IHOT_FormaDocOtmenaBron.h"



//СЕРВИСНЫЙ ЦЕНТР
#include "IREM_FormaGurAllDoc.h"
#include "IREM_FormaDocRemont.h"
#include "IREM_FormaSpiskaSprHardware.h"
#include "IREM_FormaDocRemontHW.h"
#include "IREM_FormaSpiskaSprKKT.h"
#include "IREM_FormaDocRemontKKT.h"
#include "IREM_FormaDocKM1.h"
#include "IREM_FormaDocKM2.h"
#include "IREM_FormaDocSetServKKT.h"
#include "IREM_FormaDocSetServHW.h"
#include "IREM_FormaSpiskaSprNeispr.h"
#include "IREM_FormaSpiskaSprModel.h"
#include "IREM_FormaSpiskaSprTypeRemont.h"
#include "IREM_FormaSpiskaSprSost.h"
#include "IREM_FormaGurZ.h"




//АРМ кассира
#include "IFormaViborSprNom.h"
#include "IFormaViborBVNom.h"
#include "IFormaDocRealRoznForCashier.h"
#include "IFormaDocPKORoznForCashier.h"
#include "IFormaDocRKORoznForCashier.h"
#include "IFormaDocVosvratPokForCashier.h"
#include "IFormaGurDocCheckKKM2.h"


#include "IDMProgramSetup.h"

#include "IART_FormaSpiskaSprInfBlockSostav.h"


#include "IFormaSpiskaStSpr1.h"

#include "IObject1CVnComp.h";

#pragma link "HTMLHelpViewer"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TF1 *F1;

TDM * DM;
//---------------------------------------------------------------------------
__fastcall TF1::TF1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TF1::FormCreate(TObject *Sender)
{

//MainObject
MainObject=new TMainObject();
MainObject->Init(0,0);
InterfaceMainObject=0;
MainObject->kanQueryInterface(IID_IkanUnknown,(void**)&InterfaceMainObject);



//COM система
DllkanGetInterfaceCom=0;
DllkanSendApplication=0;

try
	{
	dllInstanceCom=LoadLibrary("kanCom.dll");
	if(dllInstanceCom)
		{
		DllkanGetInterfaceCom=(DllkanGetInterfaceComType*)GetProcAddress(dllInstanceCom,"_kanGetInterfaceCom");
		DllkanSendApplication=(DllkanSendApplicationType*)GetProcAddress(dllInstanceCom,"_kanSendApplication");

		DllkanSendApplication(Application);

		if (DllkanGetInterfaceCom(Sysutils::StringToGUID("{7EC1A07A-155F-47B8-9C76-189FA365BA7E}"),
								IID_IkanCom,(void**)&InterfaceGlobalCom)!=-1)
			{
			throw Exception("Ошибка при получении интерфейса COM");
			}
		MainObject->InterfaceGlobalCom=InterfaceGlobalCom;
		}
	else
		{
		 throw Exception("Ошибка при загрузке модуля COM системы!");
		}
	}
catch(Exception &exception)
	{
	ShowMessage(exception.Message);
	}



//создаем подключение
IkanClassFactory * i_cf;
CLSID clsid;
InterfaceGlobalCom->kanCLSIDFromProgID("Oberon.DMFibConnection.1",&clsid);
if (InterfaceGlobalCom->kanGetClassObject(clsid,IID_IkanClassFactory,(void**)&i_cf) !=-1)
	{
	ShowMessage("Ошибка при получении интерфейса IID_IkanClassFactory объекта CLSID_TDMFibConnectionImpl!");
	}
i_cf->kanCreateInstance(IID_IDMFibConnection,(void**)&DM_Connection);
i_cf->kanRelease();


DM_Connection->TypeApplication=GC_TypeApplication_Ob;
MainObject->DM_Connection=DM_Connection;



DM=new TDM(Application);
DM_Connection->TypeApplication=GC_TypeApplication_Ob;
FormaViborBase=new TFormaViborBase(Application);
Demo=false;


UnicodeString ProgramCatalog=ExtractFileDir(Application->ExeName);

//справка
//получаем список файлов chm текущего каталога
//перебираем список и вызываем экспортируемые функции регистрации классов

TSearchRec F;
int ires=FindFirst(ProgramCatalog+"\\*.chm",faAnyFile|faDirectory,F);
while (!ires)
	{
	 if (F.Attr &faDirectory)
		{//каталог

		}
	 else
		{//файл
		UnicodeString file_chm=F.Name;
		Application->HelpFile=ProgramCatalog+"\\"+file_chm;
		}
	ires=FindNext(F);
	}
FindClose(F);


//зададим каталог протоколов
if (DirectoryExists(ProgramCatalog+"\\Log")==false)
		{
		CreateDir(ProgramCatalog+"\\Log");
		}

if (DirectoryExists(ProgramCatalog+"\\Log")==true)
		{
		DM_Connection->glCatalogProtocol=ProgramCatalog+"\\Log";
		}

//DevExpress
if (FileExists(ProgramCatalog+"\\language.ini")==true)
	{
	DM->cxLocalizer1->FileName=ProgramCatalog+"\\language.ini";
	DM->cxLocalizer1->Active=true;
	DM->cxLocalizer1->Locale=1049;
	}
ShowMessageOnClose=false;
}
//---------------------------------------------------------------------------

void __fastcall TF1::FormClose(TObject *Sender, TCloseAction &Action)
{
if (DMGrpMenu !=0)
	{
	DMGrpMenu->kanRelease();
	DMGrpMenu=0;
	}


if (ShowMessageOnClose==true)
	{
	ShowMessage("Выполняем процедуру завершения программы FormClose");
	}


if(DM_Connection->pFIBData->Connected==true)
	{
	DM_Connection->AddLog(DM_Connection->UserInfoID_USER->AsInt64, 1, 0, 0,
	 "Завершение работы менеджера PAdmin.exe",	"",	0,0);
	}
//if (glScaner) if(glScaner->ConnectScaner) glScaner->Disconnect();

if (ShowMessageOnClose==true)
	{
	ShowMessage("Удаляем DM");
	}
delete DM;


if (glScaner)
	{
	if (ShowMessageOnClose==true)
		{
		ShowMessage("Попытка отключить сканер");
		}
	//if(glScaner->ConnectScaner) glScaner->Disconnect();
	glScaner->kanRelease();

	if (ShowMessageOnClose==true)
		{
		ShowMessage("Сканер отключен");
		}
	}


if (ShowMessageOnClose==true)
	{
	ShowMessage("Попытка удалить DM_Connection");
	}
DM_Connection->kanRelease();

if (ShowMessageOnClose==true)
	{
	ShowMessage("DM_Connection  удалено");
	}


if (ShowMessageOnClose==true)
	{
	ShowMessage("Попытка удалить MainObject");
	}

delete MainObject;

if (ShowMessageOnClose==true)
	{
	ShowMessage("MainObject  удален");
	}

//GrdLogout(grd,0);
//GrdCloseHandle(grd);
//GrdCleanup();

if (ShowMessageOnClose==true)
	{
	ShowMessage("Выгружены модули ключа защиты");
	}


if (ShowMessageOnClose==true)
	{
	ShowMessage("Выполняем kanDone COM системы");
	}
//попробуем выгрузить систему COM
//завершаем работу с библиотекой
typedef int (__import  DllkanDoneType(void));
DllkanDoneType * DllkanDone;
DllkanDone=0;
DllkanDone=(DllkanDoneType*)GetProcAddress(dllInstanceCom,"_kanDone");
if (DllkanDone!=0)
	{
	DllkanDone(); //  здесь выгружаются свободные модули
	}

if (ShowMessageOnClose==true)
	{
	ShowMessage("Выполнено kanDone COM системы");
	}

if (ShowMessageOnClose==true)
	{
	//покажем список невыгруженных модулей
	typedef void  (__import  DllkanShowListLoadModulesType(void));
	DllkanShowListLoadModulesType * DllkanShowListLoadModules=0;
	DllkanShowListLoadModules=(DllkanShowListLoadModulesType*)GetProcAddress(dllInstanceCom,"_kanShowListLoadModules");
	if (DllkanShowListLoadModules)
		{
		DllkanShowListLoadModules();
		}
	}


if (ShowMessageOnClose==true)
	{
	ShowMessage("InterfaceGlobalCom->kanRelease();");
	}
//удалим объект COM системы
InterfaceGlobalCom->kanRelease();

if (ShowMessageOnClose==true)
	{
	ShowMessage("InterfaceGlobalCom->kanRelease() - OK");
	}

//непосредственно выгружаем библиотеку
typedef int (__import  DllCanUnloadNowType(void));
DllCanUnloadNowType * DllCanUnloadNow;
DllCanUnloadNow=0;
DllCanUnloadNow=(DllCanUnloadNowType*)GetProcAddress(dllInstanceCom,"_kanCanUnloadNow");

		if (DllCanUnloadNow!=0)
			{
			if (DllCanUnloadNow()==-1)
				{
				//FreeLibrary(dllInstanceCom);
				}
			else
				{
				if (ShowMessageOnClose==true)
					{
					ShowMessage("Система COM не выгружена. Существуют созданные объекты.");
					}
				}
			}

if (ShowMessageOnClose==true)
	{
	ShowMessage("Завершена процедура FormClose");
	}
}
//---------------------------------------------------------------------------

void __fastcall TF1::FormShow(TObject *Sender)
{

FormaViborBase->FOnCloseForm=EndViborBase;
FormaViborBase->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TF1::EndViborBase(TObject *Sender)
{

if (FormaViborBase->OutReady==true)
        {
		DM_Connection->ConnectString=FormaViborBase->ConnectString;
		DM_Connection->PasswordUser=FormaViborBase->PasswordUser;
		DM_Connection->NameUser=FormaViborBase->NameUser;

		if(DM_Connection->GlobConnect()==true)
                {
				DM_Connection->AddLog( DM_Connection->UserInfoID_USER->AsInt64, 1, 0, 0,
				 "Запуск программы менеджера PAdmin.exe", "",0,0);

				 if (DM_Connection->UserInfoSAVENAME_SUSER->AsInteger==1)
					{
					FormaViborBase->SaveNameUser();
					}
				 else
					{
					FormaViborBase->ClearNameUser();
					}
//						if (glUser->ElementPASSWORD_USER->AsString==FormaViborBase->PasswordUser)
//								{
//								if (glUser->ElementINTERF_USER->AsInteger>=10)
//										{
										Visible=true;
										DM_Connection->OpenARMInfo(FormaViborBase->NumberARM);
                                        CheckGlobSetup();
                                        ConnectDevice();

                                        StatusBar->Panels->Items[0]->Text=FormaViborBase->NameUser;
                                        StatusBar->Panels->Items[2]->Text=DM_Connection->ConnectString;
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
				//Передвинем дату запрета редактирования
					IDMSetup * dm_setup;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
												 (void**)&dm_setup);
					dm_setup->Init(InterfaceMainObject,0);
				try
					{    
					dm_setup->OpenElement(42);
					if ((Trim(dm_setup->ElementVALUE_SETUP->AsString)=="") ||
							(dm_setup->ElementVALUE_SETUP->AsString=="0"))
						{
						}
					else
						{ //задано количество дней
						int kol_day=StrToInt(dm_setup->ElementVALUE_SETUP->AsString);
						dm_setup->OpenElement(13);
						TDate tec_pos_zapreta=dm_setup->ElementVALUE_TIMESTAMP_SETUP->AsDateTime;
						if ((Date()-kol_day)>tec_pos_zapreta)
							{
							dm_setup->Element->Edit();
							dm_setup->ElementVALUE_SETUP->AsString=DateToStr(Date()-kol_day);
							dm_setup->ElementVALUE_TIMESTAMP_SETUP->AsDateTime=Date()-kol_day;
							dm_setup->Element->Post();
							dm_setup->SaveElement();
							}
						}   
					}
				catch(...){}

    				dm_setup->OpenElement(33);
					if ((Trim(dm_setup->ElementVALUE_SETUP->AsString)=="1"))
						{
						DM_Connection->glShowNDS=true;
						}
					else
						{
						DM_Connection->glShowNDS=false;
						}

				dm_setup->kanRelease();


                }
        else
				{
				UnicodeString s="Ошибка при подключении к базе данных: "+DM_Connection->TextError;
				Application->MessageBox(s.c_str(),
				L"Ошибка при подключении к базе данных!", MB_OK + MB_ICONEXCLAMATION);
				FormaViborBase->CloseForm=false;
				}
		CreateMainMenu();
		CreateToolBar();
		RunAutoStart();
		}
else
		{
		//закрываем программу
		Close();

		}
}
//----------------------------------------------------------------------------
void TF1::ConnectDevice(void)
{
IDMSprOborud * DMSprOb;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprOborud.1",IID_IDMSprOborud,
												 (void**)&DMSprOb);
DMSprOb->Init(InterfaceMainObject,0);
DMSprOb->OpenTable(glStrToInt64(DM_Connection->ARMInfoID_SARM->AsString));

DMSprOb->Table->First();
while(!DMSprOb->Table->Eof)
		{
		//подключим сканер штрих кода

		if (Trim(DMSprOb->TableTYPE_OBORUD->AsString)=="scaner")
                {

				DM_Connection->glSaveProtocol("Попытка подключить сканер шк!");
				InterfaceGlobalCom->kanCreateObject("Oberon.Scaner.1",IID_IScaner,
												 (void**)&glScaner);
				glScaner->Init(InterfaceMainObject,0);
				glScaner->Modul=DMSprOb->TableMODUL_SOBORUD->AsString;
                glScaner->Number=1;

				AnsiString port=DMSprOb->TableCOMNAME_OBORUD->AsString ;
				AnsiString baud=DMSprOb->TableBAUDRATE_OBORUD->AsString;
				if (glScaner->InitDevice())
                        {
                        if (glScaner->Connect(port.c_str(),baud.c_str())==true)
                                {

                                glScaner->ConnectScaner=true;
                                }
                        else
                                {
                                ShowMessage("Ошибка подключения сканера: "+AnsiString(glScaner->GetTextError()));
                                glScaner->ConnectScaner=false;
								DM_Connection->glSaveProtocol("Ошибка подключения сканера: "+AnsiString(glScaner->GetTextError()));
                                }
                        }
                else
                        {
                        ShowMessage("Ошибка загрузки компоненты сканера штрих кода!");
						DM_Connection->glSaveProtocol("Ошибка загрузки компоненты сканера штрих кода!");
                        }
				}
		//фискальный регистратор
		if (Trim(DMSprOb->TableTYPE_OBORUD->AsString)=="fr")
				{
//				DM_Connection->glSaveProtocol("Попытка подключить фискальный регистратор");
//				if (DMSprOb->TableON_START_SOBORUD->AsInteger==1)
//					{
//					DMSprOb->OpenElement(glStrToInt64(DMSprOb->TableID_OBORUD->AsString));
//					AnsiString prog_id=DMSprOb->GetParameter("ProgId");
//					InterfaceGlobalCom->kanCreateObject(prog_id.c_str(),IID_IFiskReg,
//																(void**)&glFR);
//					glFR->Init(InterfaceMainObject,0);
//					MainObject->glFR=glFR;
//
//					glFR->Modul=DMSprOb->ElementMODUL_SOBORUD->AsString;
//					glFR->Number=1;
//					//glFR->InitDevice();
//					int number_port=StrToInt(DMSprOb->ElementCOMNAME_OBORUD->AsString);
//					AnsiString baud_rate=DMSprOb->ElementBAUDRATE_OBORUD->AsString;
//
//					AnsiString password=DMSprOb->GetParameter("password");
//
//					if(glFR->Connect(number_port, baud_rate, password)==true)
//						{
//						glFR->ConnectFR=true;
//
//						}
//					else
//						{
//						glFR->ConnectFR=false;
//						ShowMessage("Ошибка при подключении фискального регистратора: "+glFR->TextError);
//						DM_Connection->glSaveProtocol("Ошибка при подключении фискального регистратора: "+glFR->TextError);
//						}
//					}
			   }

		//дисплей покупателя
		bool error_display=false;
		AnsiString text_error="";
		if (Trim(DMSprOb->TableTYPE_OBORUD->AsString)=="DisplayPok")
			{
			//подключим дисплей покупателя
			InterfaceGlobalCom->kanCreateObject("Oberon.DisplayPok.1",IID_IDisplayPok,
												 (void**)&glDisplayPok);
			glDisplayPok->Init(InterfaceMainObject,0);
			MainObject->glDisplayPok=glDisplayPok;
				try
					{
					glDisplayPok->Modul=DMSprOb->TableMODUL_SOBORUD->AsString;
					glDisplayPok->InitDevice();
					AnsiString port=DMSprOb->TableCOMNAME_OBORUD->AsString ;
					AnsiString baud=DMSprOb->TableBAUDRATE_OBORUD->AsString;
					if (glDisplayPok->Connect(StrToInt(port),StrToInt(baud))==false)
						{
						error_display=true;
						text_error=glDisplayPok->TextError;
						}
					}
				catch(Exception &exception)
					{
					error_display=true;
					text_error=text_error+" "+ exception.Message;
					}

			if (error_display==true)
				{
				glDisplayPok->Disconnect();
				glDisplayPok->kanRelease();
				glDisplayPok=0;
				ShowMessage("Ошибка: "+text_error);
				}
			else
				{
				glDisplayPok->ShowString1("Добро пожаловать!",1,0,0);
				glDisplayPok->ShowString2(DM_Connection->ARMInfoNAME_SARM->AsString,1,0,0);
				}
			}

		DMSprOb->Table->Next();
        }

DMSprOb->kanRelease();

}
//---------------------------------------------------------------------------
void TF1::RunAutoStart(void)
{
AnsiString prog_id=DM_Connection->Arm_GetParameter("AutoStart");
prog_id=Trim(prog_id);

if (prog_id!="")
	{
	if (prog_id.Length()<3)
		{
		ShowMessage("Неправильно указан ProgId модуля для запуска по умолчанию!");
		return;
		}

	if (CheckEnableNew()==true)
		{
		IMainInterface * form;
		InterfaceGlobalCom->kanCreateObject(prog_id.c_str(),IID_IMainInterface,
												 (void**)&form);
		form->Init(InterfaceMainObject,0);
		}
	}

}
//---------------------------------------------------------------------------
void __fastcall TF1::ReadShtrihCodEvent(int number, UnicodeString sh)
{



}
//----------------------------------------------------------------------------
void TF1::CheckGlobSetup(void)
{


//


}
//---------------------------------------------------------------------------
void __fastcall TF1::FormCloseQuery(TObject *Sender, bool &CanClose)
{

		UnicodeString V="Вы хотите завершить работу с программой?";
        UnicodeString Z="Завершение работы";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
                {
                }
        else
				{
				CanClose=false;
				}

if (ShowMessageOnClose==true)
	{
	ShowMessage("Завершена процедура FormCloseQuery");
	}
}
//---------------------------------------------------------------------------
void __fastcall TF1::MainMenuAboutClick(TObject *Sender)
{
TFormAbout * form=new TFormAbout(Application);
if (!form) return;
//настройка формы
form->NameProgramLabel->Caption="Модуль \"Основной модуль (АРМ менеджера)\" ";
form->VerProgLabel->Caption="Версия программы: "+glGetVersionProgramFile();

form->VerBaseLabel->Caption="Версия базы: "+DM_Connection->GetVersionBase();

form->GrPosledLabel->Visible=false;

if (Demo==true)
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


void __fastcall TF1::MainMenuHelpClick(TObject *Sender)
{
Application->HelpJump("Общее описание/Общее описание");
}
//---------------------------------------------------------------------------

void TF1::CheckKey(void)
{
//GrdStartup(GrdFMR_Local | GrdFMR_Remote );         //   &&
//
//grd=GrdCreateHandle(0, GrdCHM_SingleThread, 0);
//GrdSetAccessCodes(grd, 2103077223, 1365184227,2585575258, 5244555225);
//GrdSetFindMode(grd,
//			GrdFMR_Local | GrdFMR_Remote,        //локальный ключ   и сетвой ключ     GrdFMR_Local &&
//			GrdFM_NProg,
//			1,                   //номер программы
//			0,
//			0,
//			0,
//			0,
//			0,
//			GrdFMM_ALL,
//			GrdFMI_ALL );
//
//unsigned long  id_key=0;
//GrdFind(grd,
//			GrdF_First,
//			&id_key,
//			0);
//GrdLogin(grd,
//			0xFFFFFFFF,
//			GrdLM_PerStation );
//
//if (id_key==0) Demo=true;
//glRegNumber=id_key;

}
//---------------------------------------------------------------------------
bool TF1::CheckEnableNew(void)
{
bool result=true;
if (Demo==true)
	{ //проверим количество документов в базе данных
	IDMQueryRead *q;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
												 (void**)&q);
	q->Init(InterfaceMainObject,0);
	q->pFIBQ->SQL->Clear();
	q->pFIBQ->SQL->Add(" select MIN(galldoc.posdoc) as MINPOS from GALLDOC ");
	q->pFIBQ->SQL->Add("  where galldoc.posdoc>'25.08.2009'");
	q->pFIBQ->ExecQuery();
	double kol=0;
	if (q->pFIBQ->FieldByName("MINPOS")->AsDateTime>EncodeDate(2000,1,1))
		{
		kol=MonthSpan(Now(),q->pFIBQ->FieldByName("MINPOS")->AsDateTime);
		}
	if (kol>2)
		{
		result=false;
		AnsiString s="Демонстрационный режим! \n";
		s=s+"Превышен интервал (2 месяца) пробной эксплуатации программы.\n";
		s=s+"Необходимо приобрести полную версию.";
		ShowMessage (s);
		}
	else
		{
		result=true;
		}
	q->kanRelease();
	}
return result;
}
//----------------------------------------------------------------------------
void __fastcall TF1::MainMenuSetupMainMenuClick(TObject *Sender)
{
if (CheckEnableNew()==false) return;
IFormaSpiskaInterfMainMenu * form;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaInterfMainMenu.1",IID_IFormaSpiskaInterfMainMenu,
												 (void**)&form);
form->Init(InterfaceMainObject,0);
if (!form) return;
form->UpdateForm();
}
//-----------------------------------------------------------------------------
void __fastcall TF1::MainMenuOpenSprUserClick(TObject *Sender)
{
if (CheckEnableNew()==false) return;
IFormaSpiskaSprUser * Users;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprUser.1",IID_IFormaSpiskaSprUser,
												 (void**)&Users);
Users->Init(InterfaceMainObject,0);
if (!Users) return;
//настройка формы
Users->UpdateForm();

}
//------------------------------------------------------------------------------
void __fastcall TF1::MainMenuOpenSprProgramModuleClick(TObject *Sender)
{
if (CheckEnableNew()==false) return;
IFormaSpiskaSprProgramModule * f;
InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprProgramModule,IID_IFormaSpiskaSprProgramModule,
												 (void**)&f);
f->Init(InterfaceMainObject,0);
if (!f) return;
//настройка формы
//f->UpdateForm();
}
//-----------------------------------------------------------------------------
void __fastcall TF1::MainMenuOpenSprObjectBasePrivClick(TObject *Sender)
{
if (CheckEnableNew()==false) return;
IFormaSpiskaObjectBasePriv * f;
InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaObjectBasePriv,IID_IFormaSpiskaObjectBasePriv,
												 (void**)&f);
f->Init(InterfaceMainObject,0);
if (!f) return;
//настройка формы
//f->UpdateForm();
}
//-----------------------------------------------------------------------------
void TF1::CreateMainMenu(void)
{
TMenuItem *menu;
TMenuItem *menu1;
TMenuItem *menu2;
TMenuItem *menu3;

//очистим меню
MainMenu1->Items->Clear();


InterfaceGlobalCom->kanCreateObject("Oberon.DMInterfMainMenuGrp.1",IID_IDMInterfMainMenuGrp,
												 (void**)&DMGrpMenu);
DMGrpMenu->Init(InterfaceMainObject,0);
DMGrpMenu->OpenMenuTable(1,DM_Connection->UserInfoIDGRP_USER->AsInt64);

__int64 id_tec_grp1=0;
__int64 id_tec_grp2=0;
__int64 id_tec_grp3=0;

int group_index=10;

DMGrpMenu->MenuTable->First();
while ( !DMGrpMenu->MenuTable->Eof)
		{

		if (glStrToInt64(DMGrpMenu->MenuTableOUT_IDGRP_1->AsString)!=id_tec_grp1)
				{
				id_tec_grp1=glStrToInt64(DMGrpMenu->MenuTableOUT_IDGRP_1->AsString);
				menu=new TMenuItem(MainMenu1);
				menu->Caption=DMGrpMenu->MenuTableOUT_NAMEGRP_1->AsString;
				//menu->OnClick = PopupMenuSprScaleClick;
				menu->GroupIndex=10;
				MainMenu1->Items->Add(menu);
				group_index++;
				}


		if (glStrToInt64(DMGrpMenu->MenuTableOUT_IDGRP_2->AsString)!=id_tec_grp2)
			{
			if (glStrToInt64(DMGrpMenu->MenuTableOUT_IDGRP_2->AsString)!=0)
				{
				id_tec_grp2=glStrToInt64(DMGrpMenu->MenuTableOUT_IDGRP_2->AsString);
				menu1=new TMenuItem(MainMenu1);
				menu1->Caption=DMGrpMenu->MenuTableOUT_NAMEGRP_2->AsString;
			   	//	menu1->OnClick = PopupMenuSprScaleClickSubMenu;
				//	menu1->Tag=DM->SprScaleAndGrpVesNom->RecNo;
				menu1->GroupIndex=0;
				menu->Insert(menu->Count,menu1);
				}
			}

		if (glStrToInt64(DMGrpMenu->MenuTableOUT_IDGRP_3->AsString)!=id_tec_grp3)
			{
			if (glStrToInt64(DMGrpMenu->MenuTableOUT_IDGRP_3->AsString)!=0)
				{
				id_tec_grp3=glStrToInt64(DMGrpMenu->MenuTableOUT_IDGRP_3->AsString);
				menu2=new TMenuItem(MainMenu1);
				menu2->Caption=DMGrpMenu->MenuTableOUT_NAMEGRP_3->AsString;
				menu2->GroupIndex=0;
			   //	menu1->OnClick = PopupMenuSprScaleClickSubMenu;
			   //	menu1->Tag=DM->SprScaleAndGrpVesNom->RecNo;
				menu1->Insert(menu1->Count,menu2);
				}
			}

		//вставим непосредственно пункт меню

		if (glStrToInt64(DMGrpMenu->MenuTableOUT_IDGRP_3->AsString)==0)
			{
			if (glStrToInt64(DMGrpMenu->MenuTableOUT_IDGRP_2->AsString)==0)
				{
				if (glStrToInt64(DMGrpMenu->MenuTableOUT_IDGRP_1->AsString)==0)
					{

					}
				else
					{
					menu3=new TMenuItem(MainMenu1);
					menu3->Caption=DMGrpMenu->MenuTableNAME_INTERF_MAINMENU->AsString;
					menu3->OnClick = ExecuteModuleClick;
					menu3->Tag=DMGrpMenu->MenuTable->RecNo;
					if (DMGrpMenu->MenuTableSHORTCUT_INTERF_MAINMENU->AsString!="")
						{
						menu3->ShortCut=TextToShortCut(DMGrpMenu->MenuTableSHORTCUT_INTERF_MAINMENU->AsString);
						}
					menu->Insert(menu->Count,menu3);
					}
				}
			else
				{
				menu3=new TMenuItem(MainMenu1);
				menu3->Caption=DMGrpMenu->MenuTableNAME_INTERF_MAINMENU->AsString;
				menu3->OnClick = ExecuteModuleClick;
				menu3->Tag=DMGrpMenu->MenuTable->RecNo;
				if (DMGrpMenu->MenuTableSHORTCUT_INTERF_MAINMENU->AsString!="")
						{
						menu3->ShortCut=TextToShortCut(DMGrpMenu->MenuTableSHORTCUT_INTERF_MAINMENU->AsString);
						}
				menu1->Insert(menu1->Count,menu3);
				}
			}
		else
			{
			menu3=new TMenuItem(MainMenu1);
			menu3->Caption=DMGrpMenu->MenuTableNAME_INTERF_MAINMENU->AsString;
			menu3->OnClick = ExecuteModuleClick;
			menu3->Tag=DMGrpMenu->MenuTable->RecNo;
			if (DMGrpMenu->MenuTableSHORTCUT_INTERF_MAINMENU->AsString!="")
						{
						menu3->ShortCut=TextToShortCut(DMGrpMenu->MenuTableSHORTCUT_INTERF_MAINMENU->AsString);
						}
			menu2->Insert(menu2->Count,menu3);
			}

		DMGrpMenu->MenuTable->Next();
		}



//создадим обязательные пункты меню


	menu=new TMenuItem(MainMenu1);
	menu->Caption="Помощь";
	MainMenu1->Items->Add(menu);

	menu1=new TMenuItem(MainMenu1);
	menu1->Caption="О программе";
	menu1->OnClick = MainMenuAboutClick;
	menu->Insert(menu->Count,menu1);

	menu1=new TMenuItem(MainMenu1);
	menu1->Caption="Содержание";
	menu1->OnClick = MainMenuHelpClick;
	menu->Insert(menu->Count,menu1);


if (DM_Connection->NameUser=="SYSDBA")
	{//создадим меню хотя бы с возможностью настройки меню

	menu=new TMenuItem(MainMenu1);
	menu->Caption="Сервис для SYSDBA";
	MainMenu1->Items->Add(menu);

	menu1=new TMenuItem(MainMenu1);
	menu1->Caption="Настройка главного меню";
	menu1->OnClick = MainMenuSetupMainMenuClick;
	//menu1->Tag=GC_FormaSpiskaInterfMainMenu;
	menu->Insert(menu->Count,menu1);

	menu1=new TMenuItem(MainMenu1);
	menu1->Caption="Пользователи";
	menu1->OnClick = MainMenuOpenSprUserClick;
	//menu1->Tag=GC_FormaSpiskaSprUser;
	menu->Insert(menu->Count,menu1);

	menu1=new TMenuItem(MainMenu1);
	menu1->Caption="Программные модули";
	menu1->OnClick = MainMenuOpenSprProgramModuleClick;
	//menu1->Tag=GC_FormaSpiskaSprUser;
	menu->Insert(menu->Count,menu1);

	menu1=new TMenuItem(MainMenu1);
	menu1->Caption="Привелегии на модули";
	menu1->OnClick = MainMenuOpenSprObjectBasePrivClick;
	//menu1->Tag=GC_FormaSpiskaSprUser;
	menu->Insert(menu->Count,menu1);
	}

	menu=new TMenuItem(MainMenu1);
	menu->Caption="Окна";
	MainMenu1->Items->Add(menu);

	menu1=new TMenuItem(MainMenu1);
	menu1->Caption="";
	menu->Insert(menu->Count,menu1);




	F1->WindowMenu=menu;

}
//---------------------------------------------------------------------------
void TF1::CreateToolBar(void)
{
//проверим существование файла настроек программы
//если есть файл настроим панель кнопок
UnicodeString ProgramCatalog=ExtractFileDir(Application->ExeName);
UnicodeString file_name_program_setup=ProgramCatalog+"\\ProgramSetup.ini";

if (FileExists(file_name_program_setup)==true)
	{ //настраиваем панель кнопок
	IDMProgramSetup * dm_ps;
	InterfaceGlobalCom->kanCreateObject(ProgId_DMProgramSetup,IID_IDMProgramSetup,
													(void**)&dm_ps);
	dm_ps->Init(InterfaceMainObject,0);

	int height=dm_ps->LoadSetupInt("Global","ImageListToolBarHeight");
	int width=dm_ps->LoadSetupInt("Global","ImageListToolBarWidth");

	if (height==0  || width==0)
		{
		height=16;
		width=16;
		}

	ImageListToolBar->Height=height;
	ImageListToolBar->Width=width;
	ToolBar1->ButtonHeight=height+7;
	ToolBar1->ButtonWidth=width+7;
	ToolBar1->Height=height+12;
	dm_ps->kanRelease();

	}


//загрузим в ImageList все картинки из папки Images
UnicodeString CatalogImagesToolBar=ProgramCatalog+"\\Images\\ToolBar\\";
UnicodeString file_name="";
int image_index=0;
ImageListToolBar->Clear();

	TToolButton * but=new TToolButton(ToolBar1);
	but->Parent=ToolBar1;
	but->ImageIndex=-1;
	but->Style=tbsSeparator;


while (FileExists(CatalogImagesToolBar+IntToStr(image_index)+".bmp")==true)
	{

	Graphics::TBitmap *b=new Graphics::TBitmap;
	b->LoadFromFile(CatalogImagesToolBar+IntToStr(image_index)+".bmp");
	ImageListToolBar->AddMasked(b,b->Canvas->Pixels[1][1]);
	delete b;

	image_index++;
	}

IDMInterfToolBar * dm_tool_bar;
InterfaceGlobalCom->kanCreateObject("Oberon.DMInterfToolBar.1",IID_IDMInterfToolBar,
												 (void**)&dm_tool_bar);
dm_tool_bar->Init(InterfaceMainObject,0);
dm_tool_bar->OpenTable(1,glStrToInt64(DM_Connection->UserInfoIDGRP_USER->AsString));

int kol_button=0;
dm_tool_bar->Table->First();
while (!dm_tool_bar->Table->Eof)
	{
	TToolButton * but=new TToolButton(ToolBar1);
	but->Parent=ToolBar1;
	but->OnClick=ExecuteModuleToolBarClick;
	but->Tag=dm_tool_bar->Table->RecNo;
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

dm_tool_bar->kanRelease();

if (kol_button==0)
	{
    ToolBar1->Visible=false;
	}
}

//---------------------------------------------------------------------------
void __fastcall TF1::ExecuteModuleToolBarClick(TObject *Sender)
{
int i= ((TToolButton*)Sender)->Tag;

IDMInterfToolBar * dm_tool_bar;
InterfaceGlobalCom->kanCreateObject("Oberon.DMInterfToolBar.1",IID_IDMInterfToolBar,
												 (void**)&dm_tool_bar);
dm_tool_bar->Init(InterfaceMainObject,0);
dm_tool_bar->OpenTable(1,glStrToInt64(DM_Connection->UserInfoIDGRP_USER->AsString));
dm_tool_bar->Table->MoveBy(i-1);
UnicodeString str_guid=Trim(dm_tool_bar->TableGUIDMOD_INTERF_TOOLBAR->AsString);

dm_tool_bar->kanRelease();
ExecuteModule(str_guid);
}
//---------------------------------------------------------------------------
void __fastcall TF1::ExecuteModuleClick(TObject *Sender)
{
DMGrpMenu->MenuTable->First();
int i= ((TMenuItem*)Sender)->Tag;
DMGrpMenu->MenuTable->MoveBy(i-1);
i=DMGrpMenu->MenuTableMODUL_INTERF_MAINMENU->AsInteger;
UnicodeString str_guid=Trim(DMGrpMenu->MenuTableGUIDMOD_INTERF_MAINMENU->AsString);
ExecuteModule(str_guid);
}
//---------------------------------------------------------------------------
void TF1::ExecuteModule(UnicodeString str_guid)
{
if (CheckEnableNew()==false) return;

if (str_guid=="")
	{
	ShowMessage("Не задан GUID запускаемого модуля!");
	return;
	}

if (str_guid == Global_CLSID_TFormaSpiskaInterfMainMenuImpl)
				{
				IFormaSpiskaInterfMainMenu * form;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaInterfMainMenu.1",IID_IFormaSpiskaInterfMainMenu,
												 (void**)&form);
				form->Init(InterfaceMainObject,0);
				if (!form) return;
				form->UpdateForm();
				}

else if(str_guid == Global_CLSID_TFormaSpiskaSprUserImpl)
				{
				IFormaSpiskaSprUser * Users;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprUser.1",IID_IFormaSpiskaSprUser,
												 (void**)&Users);
				Users->Init(InterfaceMainObject,0);
				if (!Users) return;
				//настройка формы
				Users->UpdateForm();
				}

else if(str_guid == Global_CLSID_TFormaSpiskaSprFirmImpl)
				{
				IFormaSpiskaSprFirm * SprFirm;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
												 (void**)&SprFirm);
				SprFirm->Init(InterfaceMainObject,0);
				if (!SprFirm) return;
				//настройка формы

				}
else if(str_guid == Global_CLSID_TFormaSpiskaSprSkladImpl)
				{
				IFormaSpiskaSprSklad * SprSklad;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
												 (void**)&SprSklad);
				SprSklad->Init(InterfaceMainObject,0);
				if (!SprSklad) return;
				//настройка формы

				}
else if(str_guid == Global_CLSID_TFormaSpiskaSprKKMImpl)
				{
				IFormaSpiskaSprKKM * SprKKM;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKKM.1",IID_IFormaSpiskaSprKKM,
												 (void**)&SprKKM);
				SprKKM->Init(InterfaceMainObject,0);
				if (!SprKKM) return;
				//настройка формы

				}
else if(str_guid == Global_CLSID_TFormaSpiskaSprKlientImpl)
				{
				IFormaSpiskaSprKlient * SprKlient;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
												 (void**)&SprKlient);
				SprKlient->Init(InterfaceMainObject,0);
				if (!SprKlient) return;
				//настройка формы
				SprKlient->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaSpiskaSprNomImpl)
				{
				IFormaSpiskaSprNom * SprNom;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
												 (void**)&SprNom);
				SprNom->Init(InterfaceMainObject,0);
				if (!SprNom) return;
				//настройка формы
				SprNom->IdTypePrice=DM_Connection->UserInfoIDTPRICE_USER->AsInteger;

				//SprNom->SpisokTypePrice->ItemIndex=SprNom->DM->GetIndexTypePrice()-1;
				SprNom->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaGurAllDocImpl)
				{
				IFormaGurAllDoc * GurAllDoc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaGurAllDoc.1",IID_IFormaGurAllDoc,
												 (void**)&GurAllDoc);
				GurAllDoc->Init(InterfaceMainObject,0);
				if (!GurAllDoc) return;
				//настройка формы

				}
else if(str_guid == Global_CLSID_TFormaDocPrihNaklImpl)
				{
				IFormaDocPrihNakl * PrNakl;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocPrihNakl.1",IID_IFormaDocPrihNakl,
												 (void**)&PrNakl);
				PrNakl->Init(InterfaceMainObject,0);
				if (!PrNakl) return;
				//настройка формы
				PrNakl->DM->NewDoc();
				PrNakl->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocCheckImpl)
				{
				IFormaDocCheck * Check;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocCheck.1",IID_IFormaDocCheck,
												 (void**)&Check);
				Check->Init(InterfaceMainObject,0);
				//настройка формы
				Check->DM->NewDoc();
				//Check->Operation->ItemIndex=0;
				Check->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocSchetImpl)
				{
				IFormaDocSchet * Schet;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocSchet.1",IID_IFormaDocSchet,
												 (void**)&Schet);
				Schet->Init(InterfaceMainObject,0);
				//настройка формы
				Schet->DM->NewDoc();
				Schet->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocOstNomImpl)
				{
				IFormaDocOstNom * OstNom;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocOstNom.1",IID_IFormaDocOstNom,
												 (void**)&OstNom);
				OstNom->Init(InterfaceMainObject,0);
				//настройка формы
				OstNom->DM->NewDoc();
				OstNom->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocOtchetPostImpl)
				{
				IFormaDocOtchetPost * doc;
				InterfaceGlobalCom->kanCreateObject(ProgId_FormaDocOtchetPost,IID_IFormaDocOtchetPost,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocRegOtchetPostImpl)
				{
				IFormaDocRegOtchetPost * doc;
				InterfaceGlobalCom->kanCreateObject(ProgId_FormaDocRegOtchetPost,IID_IFormaDocRegOtchetPost,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocPerImpl)
				{
				IFormaDocPer* Per;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocPer.1",IID_IFormaDocPer,
												 (void**)&Per);
				Per->Init(InterfaceMainObject,0);
				if (!Per) return;
				//настройка формы
				Per->DM->NewDoc();
				Per->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocRealImpl)
				{
				IFormaDocReal* Real;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocReal.1",IID_IFormaDocReal,
												 (void**)&Real);
				Real->Init(InterfaceMainObject,0);
				if (!Real) return;
				//настройка формы
				Real->DM->NewDoc();
				Real->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocSpisNomImpl)
				{
				IFormaDocSpisNom* SpisNom;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocSpisNom.1",IID_IFormaDocSpisNom,
												 (void**)&SpisNom);
				SpisNom->Init(InterfaceMainObject,0);
				if (!SpisNom) return;
				//настройка формы
				SpisNom->DM->NewDoc();
				SpisNom->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocVosvratPostImpl)
				{
				IFormaDocVosvratPost* VosvratPost;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocVosvratPost.1",IID_IFormaDocVosvratPost,
												 (void**)&VosvratPost);
				VosvratPost->Init(InterfaceMainObject,0);
				if (!VosvratPost) return;
				//настройка формы
				VosvratPost->DM->NewDoc();
				VosvratPost->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocPKOImpl)
				{
				IFormaDocPKO* PKO;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocPKO.1",IID_IFormaDocPKO,
												 (void**)&PKO);
				PKO->Init(InterfaceMainObject,0);
				if (!PKO) return;
				//настройка формы
				PKO->DM->NewDoc();
				PKO->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocRKOImpl)
				{
				IFormaDocRKO* RKO;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRKO.1",IID_IFormaDocRKO,
												 (void**)&RKO);
				RKO->Init(InterfaceMainObject,0);
				if (!RKO) return;
				//настройка формы
				RKO->DM->NewDoc();
				RKO->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocPlatPorImpl)
				{
				IFormaDocPlatPor * PlPor;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocPlatPor.1",IID_IFormaDocPlatPor,
												 (void**)&PlPor);
				PlPor->Init(InterfaceMainObject,0);
				if (!PlPor) return;
				//настройка формы
				PlPor->DM->NewDoc();
				PlPor->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocPostNaSchetImpl)
				{
				IFormaDocPostNaSchet * Post;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocPostNaSchet.1",IID_IFormaDocPostNaSchet,
												 (void**)&Post);
				Post->Init(InterfaceMainObject,0);
				if (!Post) return;
				//настройка формы
				Post->DM->NewDoc();
				Post->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaSpiskaSprPodrImpl)
				{
				IFormaSpiskaSprPodr * Podr;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprPodr.1",IID_IFormaSpiskaSprPodr,
												 (void**)&Podr);
				Podr->Init(InterfaceMainObject,0);
				if (!Podr) return;
				//настройка формы

				}
else if(str_guid == Global_CLSID_TFormaSpiskaSprBVNomImpl)
				{
				IFormaSpiskaSprBVNom * BV;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprBVNom.1",IID_IFormaSpiskaSprBVNom,
												 (void**)&BV);
				BV->Init(InterfaceMainObject,0);
				if (!BV) return;
				//настройка формы
				BV->IdPod=DM_Connection->UserInfoIDPOD_USER->AsInteger;
				//BV->EditPodr->Text=DM_Connection->UserInfoNAMEPOD->AsString;
				BV->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaSpiskaSprStrObjectImpl)
				{
				IFormaSpiskaSprStrObject * StrOb;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprStrObject.1",IID_IFormaSpiskaSprStrObject,
												 (void**)&StrOb);
				StrOb->Init(InterfaceMainObject,0);
				if (!StrOb) return;
				//настройка формы

				}
else if(str_guid == Global_CLSID_TFormaSpiskaSprTypePriceImpl)
				{
				IFormaSpiskaSprTypePrice * TypePrice;
				InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprTypePrice,
								IID_IFormaSpiskaSprTypePrice, (void**)&TypePrice);
				TypePrice->Init(InterfaceMainObject,0);

				//InterfaceGlobalCom->kanCreateObject(Global_CLSID_TFormaSpiskaSprTypePriceImpl,
				//				IID_IFormaSpiskaSprTypePrice, (void**)&FormaSpiskaSprTypePrice);

				if (!TypePrice) return;
				//настройка формы

				}
else if(str_guid == Global_CLSID_TFormaSpiskaSprMPrigImpl)
				{
				IFormaSpiskaSprMPrig * MPrig;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprMPrig.1",IID_IFormaSpiskaSprMPrig,
												 (void**)&MPrig);
				MPrig->Init(InterfaceMainObject,0);
				if (!MPrig) return;
				//настройка формы

				}
else if(str_guid == Global_CLSID_TFormaSpiskaSprCodeTelImpl)
				{
				IFormaSpiskaSprCodeTel * SprCodeTel;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprCodeTel.1",IID_IFormaSpiskaSprCodeTel,
												 (void**)&SprCodeTel);
				SprCodeTel->Init(InterfaceMainObject,0);
				if (!SprCodeTel) return;
				//настройка формы

				}
else if(str_guid == Global_CLSID_TFormaGurDocPrihNaklImpl)
				{
				IFormaGurDocPrihNakl * Gur;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaGurDocPrihNakl.1",IID_IFormaGurDocPrihNakl,
												 (void**)&Gur);
				Gur->Init(InterfaceMainObject,0);
				if (!Gur) return;
				//настройка формы

				}
else if(str_guid == Global_CLSID_TFormaGurDocCheckKKMImpl)
				{
				IFormaGurDocCheckKKM * Gur;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaGurDocCheckKKM.1",IID_IFormaGurDocCheckKKM,
												 (void**)&Gur);
				Gur->Init(InterfaceMainObject,0);
				if (!Gur) return;
				//настройка формы

				}
else if(str_guid == Global_CLSID_TFormaGurDocPerImpl)
				{
				IFormaGurDocPer * Gur;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaGurDocPer.1",IID_IFormaGurDocPer,
												 (void**)&Gur);
				Gur->Init(InterfaceMainObject,0);
				if (!Gur) return;
				//настройка формы

				}

else if(str_guid == Global_CLSID_TFormaDocInvImpl)
				{
				IFormaDocInv * Doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocInv.1",IID_IFormaDocInv,
												 (void**)&Doc);
				Doc->Init(InterfaceMainObject,0);
				if (!Doc) return;
				//настройка формы
				Doc->DM->NewDoc();
				//Doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaSpiskaSetupImpl)
				{
				IFormaSpiskaSetup * set;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSetup.1",IID_IFormaSpiskaSetup,
												 (void**)&set);
				set->Init(InterfaceMainObject,0);

				}
else if(str_guid == Global_CLSID_TFormaSpiskaSprInfBaseImpl)
				{
				IFormaSpiskaSprInfBase * Spr;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInfBase.1",IID_IFormaSpiskaSprInfBase,
												 (void**)&Spr);
				Spr->Init(InterfaceMainObject,0);
				if (!Spr) return;
				//настройка формы

				Spr->DM->OpenTable();
				}
else if(str_guid == Global_CLSID_TFormaDocRepKKMImpl)
				{
				IFormaDocRepKKM * RepKKM;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRepKKM.1",IID_IFormaDocRepKKM,
												 (void**)&RepKKM);
				RepKKM->Init(InterfaceMainObject,0);
				//настройка формы
				RepKKM->DM->NewDoc();
				RepKKM->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaSpiskaSprARMImpl)
				{
				IFormaSpiskaSprARM * SprARM;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprARM.1",IID_IFormaSpiskaSprARM,
												 (void**)&SprARM);
				SprARM->Init(InterfaceMainObject,0);
				if (!SprARM) return;
				//настройка формы

				}
else if(str_guid == Global_CLSID_TFormaDocOstVsImpl)
				{
				IFormaDocOstVs* doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocOstVs.1",IID_IFormaDocOstVs,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TSheetEditorImpl)
				{
				ISheetEditor * SE;
				InterfaceGlobalCom->kanCreateObject("Oberon.SheetEditor.1",IID_ISheetEditor,
												 (void**)&SE);

				}
else if(str_guid == Global_CLSID_TFormaDocRealRoznImpl)
				{
				IFormaDocRealRozn* Real;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRealRozn.1",IID_IFormaDocRealRozn,
												 (void**)&Real);
				Real->Init(InterfaceMainObject,0);
				if (!Real) return;
				//настройка формы
				Real->DM->NewDoc();
				Real->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocPKORoznImpl)
				{
				IFormaDocPKORozn* doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocPKORozn.1",IID_IFormaDocPKORozn,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocRKORoznImpl)
				{
				IFormaDocRKORozn* doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRKORozn.1",IID_IFormaDocRKORozn,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaSpiskaSprInvImpl)
				{
				IFormaSpiskaSprInv * spr;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInv.1",IID_IFormaSpiskaSprInv,
												 (void**)&spr);
				spr->Init(InterfaceMainObject,0);
				if (!spr) return;
				//настройка формы

				}
else if(str_guid == Global_CLSID_TFormaDocVosvratPokImpl)
				{
				IFormaDocVosvratPok * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocVosvratPok.1",IID_IFormaDocVosvratPok,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocSpOtrOstImpl)
				{
				IFormaDocSpOtrOst * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocSpOtrOst.1",IID_IFormaDocSpOtrOst,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocIsmPriceImpl)
				{
				IFormaDocIsmPrice * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocIsmPrice.1",IID_IFormaDocIsmPrice,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocRevImpl)
				{
				IFormaDocRev * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRev.1",IID_IFormaDocRev,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaGurLogImpl)
				{
				if (DM_Connection->UserInfoSHOW_LOG_SUSER->AsInteger==1)
					{
					IFormaGurLog * Gur;
					InterfaceGlobalCom->kanCreateObject("Oberon.FormaGurLog.1",IID_IFormaGurLog,
												 (void**)&Gur);
					Gur->Init(InterfaceMainObject,0);
					if (!Gur) return;
					//настройка формы

					}
				else
					{
					ShowMessage("У Вас не прав доступа к журналу событий!");
					}
				}
else if(str_guid == Global_CLSID_TFormaSpiskaSprVidKlientImpl)
				{
				IFormaSpiskaSprVidKlient * FormaSpiskaSprVidKlient;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprVidKlient.1",IID_IFormaSpiskaSprVidKlient,
												 (void**)&FormaSpiskaSprVidKlient);
				FormaSpiskaSprVidKlient->Init(InterfaceMainObject,0);
				FormaSpiskaSprVidKlient->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaSpiskaSprVidNomImpl)
				{
				IFormaSpiskaSprVidNom * FormaSpiskaSprVidNom;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprVidNom.1",IID_IFormaSpiskaSprVidNom,
												 (void**)&FormaSpiskaSprVidNom);
				FormaSpiskaSprVidNom->Init(InterfaceMainObject,0);
				FormaSpiskaSprVidNom->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaSpiskaSprDiscountAutoImpl)
				{
				IFormaSpiskaSprDiscountAuto * FormaSpiskaSprDiscountAuto;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprDiscountAuto.1",IID_IFormaSpiskaSprDiscountAuto,
												 (void**)&FormaSpiskaSprDiscountAuto);
				FormaSpiskaSprDiscountAuto->Init(InterfaceMainObject,0);
				FormaSpiskaSprDiscountAuto->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaSpiskaSprVidDiscountCardImpl)
				{
				IFormaSpiskaSprVidDiscountCard * spr;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprVidDiscountCard.1",IID_IFormaSpiskaSprVidDiscountCard,
												 (void**)&spr);
				spr->Init(InterfaceMainObject,0);
				spr->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaSpiskaTableNumberDocImpl)
				{
				IFormaSpiskaTableNumberDoc * table;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaTableNumberDoc.1",IID_IFormaSpiskaTableNumberDoc,
												 (void**)&table);
				table->Init(InterfaceMainObject,0);
				}
else if(str_guid == Global_CLSID_TFormaSpiskaSprNakSkidokImpl)
				{
				IFormaSpiskaSprNakSkidok * spr;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNakSkidok.1",IID_IFormaSpiskaSprNakSkidok,
												 (void**)&spr);
				spr->Init(InterfaceMainObject,0);
				spr->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaGurOperDiscountCardImpl)
				{
				IFormaGurOperDiscountCard * gur;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaGurOperDiscountCard.1",IID_IFormaGurOperDiscountCard,
												 (void**)&gur);
				gur->Init(InterfaceMainObject,0);
				gur->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaSpiskaXSetupObmenImpl)
				{
				IFormaSpiskaXSetupObmen * form;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaXSetupObmen.1",IID_IFormaSpiskaXSetupObmen,
												 (void**)&form);
				form->Init(InterfaceMainObject,0);
				if (!form) return;
				//настройка формы

				}
else if(str_guid == Global_CLSID_TFormaSpiskaSprImportSetImpl)
				{
				IFormaSpiskaSprImportSet * form;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprImportSet.1",IID_IFormaSpiskaSprImportSet,
												 (void**)&form);
				form->Init(InterfaceMainObject,0);
				if (!form) return;
				//настройка формы
				form->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocVipuskProdImpl)
				{
				IFormaDocVipuskProd* doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocVipuskProd.1",IID_IFormaDocVipuskProd,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaSpiskaSprScaleImpl)
				{
				IFormaSpiskaSprScale * spr;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprScale.1",IID_IFormaSpiskaSprScale,
												 (void**)&spr);
				spr->Init(InterfaceMainObject,0);
				if (!spr) return;
				//настройка формы

				}
else if(str_guid == Global_CLSID_TFormaSpiskaSprProjectImpl)
				{
				IFormaSpiskaSprProject * spr;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprProject.1",IID_IFormaSpiskaSprProject,
												 (void**)&spr);
				spr->Init(InterfaceMainObject,0);
				if (!spr) return;
				//настройка формы
				spr->UpdateForm();

				}
else if(str_guid == Global_CLSID_TFormaSpiskaExtModuleImpl)
				{
				IFormaSpiskaExtModule * form;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaExtModule.1",IID_IFormaSpiskaExtModule,
												 (void**)&form);
				form->Init(InterfaceMainObject,0);
				if (!form) return;
				//настройка формы
				form->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaSpiskaTableExtPrintFormImpl)
				{
				IFormaSpiskaTableExtPrintForm * form;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaTableExtPrintForm.1",IID_IFormaSpiskaTableExtPrintForm,
												 (void**)&form);
				form->Init(InterfaceMainObject,0);
				if (!form) return;

				}
else if(str_guid == Global_CLSID_TFormaDocSborkaKomplImpl)
				{
				IFormaDocSborkaKompl * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocSborkaKompl.1",IID_IFormaDocSborkaKompl,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocRasborkaKomplImpl)
				{
				IFormaDocRasborkaKompl * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRasborkaKompl.1",IID_IFormaDocRasborkaKompl,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocZamenaImpl)
				{
				IFormaDocZamena * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocZamena.1",IID_IFormaDocZamena,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocKorrVsImpl)
				{
				IFormaDocKorrVS * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocKorrVS.1",IID_IFormaDocKorrVS,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocVipBankaImpl)
				{
				IFormaDocVipBanka * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocVipBanka.1",IID_IFormaDocVipBanka,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();

				}
else if(str_guid == Global_CLSID_TFormaSpiskaSprVesNomImpl)
				{
				IFormaSpiskaSprVesNom * spr;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprVesNom.1",IID_IFormaSpiskaSprVesNom,
												 (void**)&spr);
				spr->Init(InterfaceMainObject,0);
				if (!spr) return;
				//настройка формы
				spr->DM->IdTypePrice=glStrToInt64(DM_Connection->UserInfoIDTPRICE_USER->AsString);
				spr->UpdateForm();

				}
else if(str_guid == Global_CLSID_TFormaSpiskaSprDiscountCard1Impl)
				{
				IFormaSpiskaSprDiscountCard_1 * spr;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprDiscountCard_1.1",IID_IFormaSpiskaSprDiscountCard_1,
												 (void**)&spr);
				spr->Init(InterfaceMainObject,0);
				if (!spr) return;
				//настройка формы
				spr->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocRegAdvCustImpl)
				{
				IFormaDocRegAdvCust * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRegAdvCust.1",IID_IFormaDocRegAdvCust,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocRegBankImpl)
				{
				IFormaDocRegBank * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRegBank.1",IID_IFormaDocRegBank,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocRegGoodsImpl)
				{
				IFormaDocRegGoods * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRegGoods.1",IID_IFormaDocRegGoods,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocRegOstNomImpl)
				{
				IFormaDocRegOstNom * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRegOstNom.1",IID_IFormaDocRegOstNom,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocRegKassaImpl)
				{
				IFormaDocRegKassa * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRegKassa.1",IID_IFormaDocRegKassa,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocRegPaySaleImpl)
				{
				IFormaDocRegPaySale * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRegPaySale.1",IID_IFormaDocRegPaySale,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocRegVsRaschImpl)
				{
				IFormaDocRegVsRasch * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRegVsRasch.1",IID_IFormaDocRegVsRasch,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocRegCardBalImpl)
				{
				IFormaDocRegCardBalance * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRegCardBalance.1",IID_IFormaDocRegCardBalance,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaSpiskaInterfToolBarImpl)
				{
				IFormaSpiskaInterfToolBar * form;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaInterfToolBar.1",IID_IFormaSpiskaInterfToolBar,
												 (void**)&form);
				form->Init(InterfaceMainObject,0);
				if (!form) return;
				//настройка формы
				form->UpdateForm();

				}

else if(str_guid == Global_CLSID_TFormaSpiskaObjectBasePrivImpl)
				{
				IFormaSpiskaObjectBasePriv * form;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaObjectBasePriv.1",IID_IFormaSpiskaObjectBasePriv,
												 (void**)&form);
				form->Init(InterfaceMainObject,0);
				if (!form) return;
				//настройка формы
				form->UpdateForm();

				}
        //ГОСТИНИЦА

else if(str_guid == Global_CLSID_THOT_FormaDocBronImpl)
				{
				IHOT_FormaDocBron * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaDocBron.1",IID_IHOT_FormaDocBron,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_THOT_FormaDocOtmenaBronImpl)
				{
				IHOT_FormaDocOtmenaBron * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaDocOtmenaBron.1",IID_IHOT_FormaDocOtmenaBron,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_THOT_FormaDocRaschetImpl)
				{
				IHOT_FormaDocRaschet * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaDocRaschet.1",IID_IHOT_FormaDocRaschet,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_THOT_FormaDocRasmImpl)
				{
				IHOT_FormaDocRasm * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaDocRasm.1",IID_IHOT_FormaDocRasm,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}

else if(str_guid == Global_CLSID_THOT_FormaDocRealImpl)
				{
				IHOT_FormaDocReal * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaDocReal.1",IID_IHOT_FormaDocReal,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_THOT_FormaDocViesdImpl)
				{
				IHOT_FormaDocViezd * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaDocViezd.1",IID_IHOT_FormaDocViezd,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_THOT_GurAllDocImpl)
				{
				IHOT_FormaGurAllDoc * gur;
				InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaGurAllDoc.1",IID_IHOT_FormaGurAllDoc,
												 (void**)&gur);
				gur->Init(InterfaceMainObject,0);
				if (!gur) return;
				//настройка формы

				}
else if(str_guid == Global_CLSID_THOT_FormaSpiskaSprCatNomImpl)
				{
				IHOT_FormaSpiskaSprCatNom * spr;
				InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprCatNom.1",IID_IHOT_FormaSpiskaSprCatNom,
												 (void**)&spr);
				spr->Init(InterfaceMainObject,0);
				if (!spr) return;
				//настройка формы

				}
else if(str_guid == Global_CLSID_THOT_FormaSpiskaSprCelPriesdaImpl)
				{
				IHOT_FormaSpiskaSprCelPriesda * spr;
				InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprCelPriesda.1",IID_IHOT_FormaSpiskaSprCelPriesda,
												 (void**)&spr);
				spr->Init(InterfaceMainObject,0);
				if (!spr) return;
				//настройка формы

				}
else if(str_guid == Global_CLSID_THOT_FormaSpiskaSprNFImpl)
				{
				IHOT_FormaSpiskaSprNF * spr;
				InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprNF.1",IID_IHOT_FormaSpiskaSprNF,
												 (void**)&spr);
				spr->Init(InterfaceMainObject,0);
				if (!spr) return;
				//настройка формы

				}
else if(str_guid == Global_CLSID_THOT_FormaSpiskaSprObjectImpl)
				{
				IHOT_FormaSpiskaSprObject * spr;
				InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprObject.1",IID_IHOT_FormaSpiskaSprObject,
												 (void**)&spr);
				spr->Init(InterfaceMainObject,0);
				if (!spr) return;
				//настройка формы

				}
else if(str_guid == Global_CLSID_THOT_FormaSpiskaSprPrOsnUslImpl)
				{
				IHOT_FormaSpiskaSprPrOsnUslug * spr;
				InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprPrOsnUslug.1",IID_IHOT_FormaSpiskaSprPrOsnUslug,
												 (void**)&spr);
				spr->Init(InterfaceMainObject,0);
				if (!spr) return;
				//настройка формы

				}
else if(str_guid == Global_CLSID_THOT_FormaSpiskaSprSostNomImpl)
				{
				IHOT_FormaSpiskaSprSostNom * spr;
				InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprSostNom.1",IID_IHOT_FormaSpiskaSprSostNom,
												 (void**)&spr);
				spr->Init(InterfaceMainObject,0);
				if (!spr) return;
				//настройка формы

				}
else if(str_guid == Global_CLSID_THOT_FormaSpiskaSprTypePosImpl)
				{
				IHOT_FormaSpiskaSprTypePosel * spr;
				InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprTypePosel.1",IID_IHOT_FormaSpiskaSprTypePosel,
												 (void**)&spr);
				spr->Init(InterfaceMainObject,0);
				if (!spr) return;
				//настройка формы

				}
else if(str_guid == Global_CLSID_THOT_FormaTableSostNFImpl)
				{
				IHOT_FormaSpiskaTableSostNF * spr;
				InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpTableSostNF.1",IID_IHOT_FormaSpiskaTableSostNF,
												 (void**)&spr);
				spr->Init(InterfaceMainObject,0);
				if (!spr) return;
				//настройка формы
				spr->UpdateForm();

				}

		//РЕМОНТ
else if(str_guid == Global_CLSID_TREM_FormaSpiskaSprNeisprImpl)
				{
				IREM_FormaSpiskaSprNeispr * spr;
				InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprNeispr.1",IID_IREM_FormaSpiskaSprNeispr,
												 (void**)&spr);
				spr->Init(InterfaceMainObject,0);
				spr->UpdateForm();
				}
else if(str_guid == Global_CLSID_TREM_FormaSpiskaSprModelImpl)
				{
				IREM_FormaSpiskaSprModel * Spr;
				InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprModel.1",IID_IREM_FormaSpiskaSprModel,
												 (void**)&Spr);
				Spr->Init(InterfaceMainObject,0);
				if (!Spr) return;
				Spr->UpdateForm();
				}
else if(str_guid == Global_CLSID_TREM_FormaSpiskaSprTypeRemontImpl)
				{
				IREM_FormaSpiskaSprTypeRemont * Spr;
				InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprTypeRemont.1",IID_IREM_FormaSpiskaSprTypeRemont,
												 (void**)&Spr);
				Spr->Init(InterfaceMainObject,0);
				if (!Spr) return;
				}
else if(str_guid == Global_CLSID_TREM_FormaSpiskaSprSostImpl)
				{
				IREM_FormaSpiskaSprSost * Spr;
				InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprSost.1",IID_IREM_FormaSpiskaSprSost,
												 (void**)&Spr);
				Spr->Init(InterfaceMainObject,0);
				if (!Spr) return;
				}
else if(str_guid == Global_CLSID_TREM_FormaGurZImpl)
				{
				IREM_FormaGurZ * GurZ;
				InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaGurZ.1",IID_IREM_FormaGurZ,
												 (void**)&GurZ);
				GurZ->Init(InterfaceMainObject,0);
				if (!GurZ) return;
				}
else if(str_guid == Global_CLSID_TREM_FormaGurAllDocImpl)
				{
				IREM_FormaGurAllDoc * GurAllDoc;
				InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaGurAllDoc.1",IID_IREM_FormaGurAllDoc,
												 (void**)&GurAllDoc);
				GurAllDoc->Init(InterfaceMainObject,0);
				if (!GurAllDoc) return;
				}
else if(str_guid == Global_CLSID_TREM_FormaDocRemontImpl)
				{
				IREM_FormaDocRemont * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaDocRemont.1",IID_IREM_FormaDocRemont,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TREM_FormaSpiskaSprHardwareImpl)
				{
				IREM_FormaSpiskaSprHardware * spr;
				InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprHardware.1",IID_IREM_FormaSpiskaSprHardware,
												 (void**)&spr);
				spr->Init(InterfaceMainObject,0);
				if (!spr) return;
				spr->UpdateForm();
				}
else if(str_guid == Global_CLSID_TREM_FormaDocRemontHWImpl)
				{
				IREM_FormaDocRemontHW * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaDocRemontHW.1",IID_IREM_FormaDocRemontHW,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TREM_FormaSpiskaSprKKTImpl)
				{
				IREM_FormaSpiskaSprKKT * spr;
				InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprKKT.1",IID_IREM_FormaSpiskaSprKKT,
												 (void**)&spr);
				spr->Init(InterfaceMainObject,0);
				if (!spr) return;
				//настройка формы

				spr->UpdateForm();
				}
else if(str_guid == Global_CLSID_TREM_FormaDocRemontKKTImpl)
				{
				IREM_FormaDocRemontKKT * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaDocRemontKKT.1",IID_IREM_FormaDocRemontKKT,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TREM_FormaDocKM1Impl)
				{
				IREM_FormaDocKM1 * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaDocKM1.1",IID_IREM_FormaDocKM1,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TREM_FormaDocKM2Impl)
				{
				IREM_FormaDocKM2 * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaDocKM2.1",IID_IREM_FormaDocKM2,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TREM_FormaDocSetServKKTImpl)
				{
				IREM_FormaDocSetServKKT * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaDocSetServKKT.1",IID_IREM_FormaDocSetServKKT,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TREM_FormaDocSetServHWImpl)
				{
				IREM_FormaDocSetServHW * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaDocSetServHW.1",IID_IREM_FormaDocSetServHW,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->UpdateForm();
				}

//АРМ КАССИРА

else if(str_guid == Global_CLSID_TFormaViborSprNomImpl)
				{
				IFormaViborSprNom *FormaViborSprNom;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaViborSprNom.1",IID_IFormaViborSprNom,
												 (void**)&FormaViborSprNom);
				FormaViborSprNom->Init(InterfaceMainObject,0);
				FormaViborSprNom->DM->IdTypePrice=glStrToInt64(DM_Connection->ARMInfoIDTPRICEPOD->AsString);
				//FormaViborSprNom->SpisokTypePrice->ItemIndex=FormaViborSprNom->DM->GetIndexTypePrice()-1;
				FormaViborSprNom->UpdateForm();

				}
else if(str_guid == Global_CLSID_TFormaViborSprBVNomImpl)
				{
				IFormaViborBVNom *SprBV;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaViborBVNom.1",IID_IFormaViborBVNom,
												 (void**)&SprBV);
				SprBV->Init(InterfaceMainObject,0);
				SprBV->Prosmotr=true;
				SprBV->IdPod=glStrToInt64(DM_Connection->ARMInfoIDPODR_SARM->AsString);
				//SprBV->EditPodr->Text=DMSprARM->ElementNAMEPOD->AsString;
				SprBV->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaSpiskaSprKlientImpl)
				{
				IFormaSpiskaSprKlient * SprKlient;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
												 (void**)&SprKlient);
				SprKlient->Init(InterfaceMainObject,0);
				SprKlient->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocRealRoznForCashiersImpl)
				{
				IFormaDocRealRoznForCashier * Real;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRealRoznForC.1",IID_IFormaDocRealRoznForCashier,
												 (void**)&Real);
				Real->Init(InterfaceMainObject,0);
				if (!Real) return;
				//настройка формы
				Real->DM->NewDoc();
				Real->DM->DocAll->Edit();
				Real->DM->Doc->Edit();
				if (glStrToInt64(DM_Connection->ARMInfoIDBASE_SARM->AsString)!=0)
					{
					Real->DM->DocAllIDBASE_GALLDOC->AsString=DM_Connection->ARMInfoIDBASE_SARM->AsString;
					Real->DM->DocAllNAME_SINFBASE_OBMEN->AsString=DM_Connection->ARMInfoNAME_SINFBASE_OBMEN->AsString;
					}
				if (glStrToInt64(DM_Connection->ARMInfoIDFIRM_SARM->AsString)!=0)
					{
					Real->DM->DocAllIDFIRMDOC->AsString=DM_Connection->ARMInfoIDFIRM_SARM->AsString;
					Real->DM->DocAllNAMEFIRM->AsString=DM_Connection->ARMInfoNAMEFIRM->AsString;
					}
				if(glStrToInt64(DM_Connection->ARMInfoIDSKLAD_SARM->AsString)!=0)
					{
					Real->DM->DocAllIDSKLDOC->AsString=DM_Connection->ARMInfoIDSKLAD_SARM->AsString;
					Real->DM->DocAllNAMESKLAD->AsString=DM_Connection->ARMInfoNAMESKLAD->AsString;
					}

				Real->DM->Doc->Edit();
				if(glStrToInt64(DM_Connection->ARMInfoIDTPRICEPOD->AsString)!=0)
					{
					Real->DM->DocIDTPRICE_DREALROZN->AsString=DM_Connection->ARMInfoIDTPRICEPOD->AsString;
					Real->DM->DocNAME_TPRICE->AsString=DM_Connection->ARMInfoNAME_TPRICE->AsString;
					}
				if (glStrToInt64(DM_Connection->ARMInfoIDKKM_SARM->AsString)!=0)
					{
					Real->DM->DocIDKKM_DREALROZN->AsString=DM_Connection->ARMInfoIDKKM_SARM->AsString;
					Real->DM->DocNAMEKKM->AsString=DM_Connection->ARMInfoNAMEKKM->AsString;
					}
				Real->DM->DocAll->Post();
				Real->DM->Doc->Post();
				Real->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaDocPKORoznForCashiersImpl)
				{
				IFormaDocPKORoznForCashier* doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocPKORoznForC.1",IID_IFormaDocPKORoznForCashier,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->DM->DocAll->Edit();
				if (glStrToInt64(DM_Connection->ARMInfoIDBASE_SARM->AsString)!=0)
					{
					doc->DM->DocAllIDBASE_GALLDOC->AsString=DM_Connection->ARMInfoIDBASE_SARM->AsString;
					doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=DM_Connection->ARMInfoNAME_SINFBASE_OBMEN->AsString;
					}
				if (glStrToInt64(DM_Connection->ARMInfoIDFIRM_SARM->AsString)!=0)
					{
					doc->DM->DocAllIDFIRMDOC->AsString=DM_Connection->ARMInfoIDFIRM_SARM->AsString;
					doc->DM->DocAllNAMEFIRM->AsString=DM_Connection->ARMInfoNAMEFIRM->AsString;
					}
				doc->DM->DocAll->Post();

				doc->DM->Doc->Edit();
				if (glStrToInt64(DM_Connection->ARMInfoIDKKM_SARM->AsString)!=0)
					{
					doc->DM->DocIDKKM_DPKOROZN->AsString=DM_Connection->ARMInfoIDKKM_SARM->AsString;
					doc->DM->DocNAMEKKM->AsString=DM_Connection->ARMInfoNAMEKKM->AsString;
					}
				doc->DM->Doc->Post();
				doc->UpdateForm();

				}
else if(str_guid == Global_CLSID_TFormaDocRKORoznForCashiersImpl)
				{
				IFormaDocRKORoznForCashier * doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRKORoznForC.1",IID_IFormaDocRKORoznForCashier,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->DM->DocAll->Edit();
				if (glStrToInt64(DM_Connection->ARMInfoIDBASE_SARM->AsString)!=0)
					{
					doc->DM->DocAllIDBASE_GALLDOC->AsString=DM_Connection->ARMInfoIDBASE_SARM->AsString;
					doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=DM_Connection->ARMInfoNAME_SINFBASE_OBMEN->AsString;
					}
				if (glStrToInt64(DM_Connection->ARMInfoIDFIRM_SARM->AsString)!=0)
					{
					doc->DM->DocAllIDFIRMDOC->AsString=DM_Connection->ARMInfoIDFIRM_SARM->AsString;
					doc->DM->DocAllNAMEFIRM->AsString=DM_Connection->ARMInfoNAMEFIRM->AsString;
					}
				doc->DM->DocAll->Post();

				doc->DM->Doc->Edit();
				if (glStrToInt64(DM_Connection->ARMInfoIDKKM_SARM->AsString)!=0)
					{
					doc->DM->DocIDKKM_DRKOROZN->AsString=DM_Connection->ARMInfoIDKKM_SARM->AsString;
					doc->DM->DocNAMEKKM->AsString=DM_Connection->ARMInfoNAMEKKM->AsString;
					}
				doc->DM->Doc->Post();
				doc->UpdateForm();
				}
else if(str_guid == Global_CLSID_TFormaVosvratPokForCashiersImpl)
				{
				IFormaDocVosvratPokForCashier* doc;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocVosvratPokForC.1",IID_IFormaDocVosvratPokForCashier,
												 (void**)&doc);
				doc->Init(InterfaceMainObject,0);
				if (!doc) return;
				//настройка формы
				doc->DM->NewDoc();
				doc->DM->DocAll->Edit();
				if (glStrToInt64(DM_Connection->ARMInfoIDBASE_SARM->AsString)!=0)
					{
					doc->DM->DocAllIDBASE_GALLDOC->AsString=DM_Connection->ARMInfoIDBASE_SARM->AsString;
					doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=DM_Connection->ARMInfoNAME_SINFBASE_OBMEN->AsString;
					}
				if (glStrToInt64(DM_Connection->ARMInfoIDFIRM_SARM->AsString)!=0)
					{
					doc->DM->DocAllIDFIRMDOC->AsString=DM_Connection->ARMInfoIDFIRM_SARM->AsString;
					doc->DM->DocAllNAMEFIRM->AsString=DM_Connection->ARMInfoNAMEFIRM->AsString;
					}
				if (glStrToInt64(DM_Connection->ARMInfoIDSKLAD_SARM->AsString)!=0)
					{
					doc->DM->DocAllIDSKLDOC->AsString=DM_Connection->ARMInfoIDSKLAD_SARM->AsString;
					doc->DM->DocAllNAMESKLAD->AsString=DM_Connection->ARMInfoNAMESKLAD->AsString;
					}
				doc->DM->DocAll->Post();

				//получим закупочный и розничный тип цен
				doc->DM->Doc->Edit();
				doc->DM->DocIDRTPRICE_DVPOK->AsString=DM_Connection->ARMInfoIDTPRICEPOD->AsString;
				IDMSetup * s;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
												 (void**)&s);
				s->Init(InterfaceMainObject,0);
				s->OpenElement(30);
				if (Trim(s->ElementVALUE_SETUP->AsString )!="")
					{
					doc->DM->DocIDTPRICE_DVPOK->AsString=StrToInt64(s->ElementVALUE_SETUP->AsString);
					}
				s->kanRelease();
				doc->DM->Doc->Post();
				doc->UpdateForm();

				}
else if(str_guid == Global_CLSID_TFormaGurCheckKKM2Impl)
				{
				IFormaGurDocCheckKKM2 * Gur;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaGurDocCheckKKM2.1",IID_IFormaGurDocCheckKKM2,
												 (void**)&Gur);
				Gur->Init(InterfaceMainObject,0);
				Gur->IdKKM=glStrToInt64(DM_Connection->ARMInfoIDKKM_SARM->AsString);
//				Gur->NameKKMLabel->Caption=DM_Connection->ARMInfoNAMEKKM->AsString;
				Gur->UpdateForm();
				}
else if(str_guid == Global_CLSID_TART_FormaSpiskaSprInfBlockSostavImpl)
				{
				IART_FormaSpiskaSprInfBlockSostav * inf_block;
				InterfaceGlobalCom->kanCreateObject(ProgId_ART_FormaSpiskaSprInfBlockSostav,IID_IART_FormaSpiskaSprInfBlockSostav,
												 (void**)&inf_block);
				inf_block->Init(InterfaceMainObject,0);

				IDMInterfMainMenu * dm_main_menu;
				InterfaceGlobalCom->kanCreateObject(ProgId_DMInterfMainMenu,IID_IDMInterfMainMenu,
								 (void**)&dm_main_menu);
				dm_main_menu->Init(InterfaceMainObject,0);
				dm_main_menu->OpenElement(glStrToInt64(DMGrpMenu->MenuTableID_INTERF_MAINMENU->AsString));

				if (dm_main_menu->ElementFL_OPEN_EL_INTERF_MAINMENU->AsInteger ==1)
					{//открываем эелемент
					inf_block->IdPage=glStrToInt64(dm_main_menu->ElementIDEL_INTERF_MAINMENU->AsString);
					inf_block->UpdateForm();
					}


				dm_main_menu->kanRelease();
				}
//КОНЕЦ АРМ КАССИРА
else
				{
				IMainInterface * modul;
				IkanClassFactory * i_cf;
				bool error=false;
				UnicodeString text_error="";
//
				text_error="Получаем интерфейс фабрики классов \n";
				if (InterfaceGlobalCom->kanGetClassObject(StringToGUID(str_guid),IID_IkanClassFactory,(void**)&i_cf) ==-1)
					{
					text_error=text_error+"Получили интерфейс фабрики классов \n";
					text_error=text_error+"Непосредственно создаем объект  \n";
					if(i_cf->kanCreateInstance(IID_IMainInterface,(void**)&modul)==-1)
						{
						text_error=text_error+"Создали объект  \n";
						}
					else
						{
						error=true;
						text_error=text_error+"Ошибка при получении интерфейса "+GUIDToString(IID_IMainInterface)+" объекта "+str_guid+"!\n";
						}
					i_cf->kanRelease();
					text_error=text_error+"Создан объект: "+str_guid+"\n";
					}
				else
					{
					error=true;
					text_error=text_error+"Ошибка при получении интерфейса IID_IkanClassFactory объекта "+str_guid+"\n!";
					}

				if (error==false)
					{
					modul->Init(InterfaceMainObject,0);
					if(str_guid == Global_CLSID_TFormaSpiskaStSpr1Impl)
						{
						IFormaSpiskaStSpr1 * spr1;
						if(modul->kanQueryInterface(IID_IFormaSpiskaStSpr1,(void**)&spr1) == -1)
							{
							if(spr1->CreateObject("FormaSpiskaSprSklad")==true)
								{

								}
							else
								{


								}
							}
						}
					}
				else
					{
                    ShowMessage(text_error);
					}


				}

}
//----------------------------------------------------------------------------









void __fastcall TF1::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("AllOpis");
}
//---------------------------------------------------------------------------

void __fastcall TF1::ActionShowMessageOnCloseExecute(TObject *Sender)
{
ShowMessageOnClose=true;
Close();
}
//---------------------------------------------------------------------------


//IObject1CVnComp * Object1CVnComp;
//
//InterfaceGlobalCom->kanCreateObject(ProgId_Object1CVnComp,IID_IkanClassFactory,
//												 (void**)&Object1CVnComp);
//Object1CVnComp->InitVC();
//
//
//int num_metod=Object1CVnComp->FindMethod(L"ПолучитьОписание");
//int kol_parameter_metoda=Object1CVnComp->GetNParams(num_metod);    //количество параметров метода
//
//bool fl_return_value=Object1CVnComp->HasRetVal(num_metod);  ///Возвращается флаг наличия у метода с порядковым номером lMethodNum возвращаемого значения: true для методов с возвращаемым значением и false в противном случае.
//
//TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
//TkasVariant * variant_result=new TkasVariant;
//
//if (fl_return_value==true)
//	 {
//	 Object1CVnComp->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda);
//	 }
//else
//	{
//	Object1CVnComp->CallAsProc(num_metod,in_parameter, kol_parameter_metoda);
//	}

