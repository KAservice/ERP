//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

//---------------------------------------------------------------------------

#include "UArmOf.h"
#include "UFiskReg.h"
#include "IDMSprARM.h"
#include "IDMSprOborud.h"
#include "grdapi.h"
#include "IDMQueryRead.h"
#include "math.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//����� ���������� �������
#include "HTMLHelpViewer.hpp"
#pragma link "HTMLHelpViewer"


TArmOf *ArmOf;


extern UnicodeString ComandString;
TDM * DM;

//---------------------------------------------------------------------------
__fastcall TArmOf::TArmOf(TComponent* Owner)
        : TForm(Owner)
{
glScaner=0;
glFR=0;
glDisplayPok=0;
}
//---------------------------------------------------------------------------
void __fastcall TArmOf::FormCreate(TObject *Sender)
{

//MainObject
MainObject=new TMainObject();
MainObject->Init(0,0);
InterfaceMainObject=0;
MainObject->kanQueryInterface(IID_IkanUnknown,(void**)&InterfaceMainObject);



//COM �������
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
			throw Exception("������ ��� ��������� ���������� COM");
			}
		MainObject->InterfaceGlobalCom=InterfaceGlobalCom;
		}
	else
		{
		 throw Exception("������ ��� �������� ������ COM �������!");
		}
	}
catch(Exception &exception)
	{
	ShowMessage(exception.Message);
	}



//������� �����������
IkanClassFactory * i_cf;
CLSID clsid;
InterfaceGlobalCom->kanCLSIDFromProgID("Oberon.DMFibConnection.1",&clsid);
if (InterfaceGlobalCom->kanGetClassObject(clsid,IID_IkanClassFactory,(void**)&i_cf) !=-1)
	{
	ShowMessage("������ ��� ��������� ���������� IID_IkanClassFactory ������� CLSID_TDMFibConnectionImpl!");
	}
i_cf->kanCreateInstance(IID_IDMFibConnection,(void**)&DM_Connection);
i_cf->kanRelease();


DM_Connection->TypeApplication=GC_TypeApplication_Ob;
MainObject->DM_Connection=DM_Connection;

DM=new TDM(Application);

//������� ������� ����������
AnsiString ProgramCatalog=ExtractFileDir(Application->ExeName);
if (DirectoryExists(ProgramCatalog+"\\Log")==false)
        {
        CreateDir(ProgramCatalog+"\\Log");
        }

if (DirectoryExists(ProgramCatalog+"\\Log")==true)
        {
		DM_Connection->glCatalogProtocol=ProgramCatalog+"\\Log";
		}

Application->HelpFile=ProgramCatalog+"\\ArmOfHelp.chm";

if (FileExists(ProgramCatalog+"\\language.ini")==true)
	{
	DM->cxLocalizer1->FileName=ProgramCatalog+"\\language.ini";
	DM->cxLocalizer1->Active=true;
	DM->cxLocalizer1->Locale=1049;
	}


ShowMessageOnClose=false;


CheckKey();
}
//---------------------------------------------------------------------------
void __fastcall TArmOf::FormClose(TObject *Sender, TCloseAction &Action)
{
if (glScaner)
	{
	//if(glScaner->ConnectScaner) glScaner->Disconnect();
	glScaner->kanRelease();
	}


if (glDisplayPok)
	{
	glDisplayPok->Disconnect();
	glDisplayPok->kanRelease();
	}

if (glFR)
	{
	if (glFR->ConnectFR==true)
		{
		glFR->Disconnect();
		}
	glFR->kanRelease();
	}

delete MainObject;
delete DM;


DM_Connection->glSaveProtocol("�������� ArmOf.exe");
DM_Connection->kanRelease();
DM_Connection=0;

GrdLogout(grd,0);
GrdCloseHandle(grd);
GrdCleanup();

if (ShowMessageOnClose==true)
	{
	//������� ������ ������������� �������
	typedef void  (__import  DllkanShowListLoadModulesType(void));
	DllkanShowListLoadModulesType * DllkanShowListLoadModules=0;
	DllkanShowListLoadModules=(DllkanShowListLoadModulesType*)GetProcAddress(dllInstanceCom,"_kanShowListLoadModules");
	if (DllkanShowListLoadModules)
		{
		DllkanShowListLoadModules();
		}
	}


//��������� ��������� ������� COM
//��������� ������ � �����������
typedef int (__import  DllkanDoneType(void));
DllkanDoneType * DllkanDone;
DllkanDone=0;
DllkanDone=(DllkanDoneType*)GetProcAddress(dllInstanceCom,"_kanDone");
if (DllkanDone!=0)
	{
	DllkanDone(); //  ����� ����������� ��������� ������
	}

if (ShowMessageOnClose==true)
	{
	//������� ������ ������������� �������
	typedef void  (__import  DllkanShowListLoadModulesType(void));
	DllkanShowListLoadModulesType * DllkanShowListLoadModules=0;
	DllkanShowListLoadModules=(DllkanShowListLoadModulesType*)GetProcAddress(dllInstanceCom,"_kanShowListLoadModules");
	if (DllkanShowListLoadModules)
		{
		DllkanShowListLoadModules();
		}
	}

//������ ������ COM �������
InterfaceGlobalCom->kanRelease();


//��������������� ��������� ����������
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
					ShowMessage("������� COM �� ���������. ���������� ��������� �������.");
					}
				}
			}


}
//----------------------------------------------------------------------------
void __fastcall TArmOf::EndViborBase(TObject *Sender)
{

if (FormaViborBase->OutReady==true)
        {
		DM_Connection->ConnectString=FormaViborBase->ConnectString;
		DM_Connection->PasswordUser=FormaViborBase->PasswordUser;  //Password->Text;
		DM_Connection->CodeUser=FormaViborBase->CodeUser;

		if(DM_Connection->GlobConnect3()==true)
				{

				Visible=true;
				DM_Connection->OpenARMInfo(FormaViborBase->NumberARM);
				ConnectDevice();

				StatusBar->Panels->Items[0]->Text=DM_Connection->UserInfoNAME_USER->AsString;
				StatusBar->Panels->Items[1]->Text=DM_Connection->ConnectString;

									   // StatusBar->Panels->Items[1]->Text=gl_prefiks_ib;
				StatusBar->Panels->Items[3]->Text=DM_Connection->GetVersionBase();
				StatusBar->Panels->Items[4]->Text=glGetVersionProgramFile();
				FormaViborBase->CloseForm=true;

                }
        else
                {
                ShowMessage("�� ������� ������������ � ���� ������!");
                FormaViborBase->CloseForm=false;
                }
        }

}
//---------------------------------------------------------------------------
void TArmOf::ConnectDevice(void)
{
IDMSprOborud * DMSprOborud;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprOborud.1",IID_IDMSprOborud,
												 (void**)&DMSprOborud);
DMSprOborud->Init(InterfaceMainObject,0);

DMSprOborud->OpenTable(glStrToInt64(DM_Connection->ARMInfoID_SARM->AsString));

DMSprOborud->Table->First();
while(!DMSprOborud->Table->Eof)
        {
        if (Trim(DMSprOborud->TableTYPE_OBORUD->AsString)=="scaner")
                {
                //��������� ������ ����� ����
				DM_Connection->glSaveProtocol("������� ���������� ������ ��!");
				InterfaceGlobalCom->kanCreateObject("Oberon.Scaner.1",IID_IScaner,
												 (void**)&glScaner);
				glScaner->Init(InterfaceMainObject,0);
                glScaner->Modul=DMSprOborud->TableMODUL_SOBORUD->AsString;
                glScaner->Number=1;

                AnsiString port=DMSprOborud->TableCOMNAME_OBORUD->AsString ;
                AnsiString baud=DMSprOborud->TableBAUDRATE_OBORUD->AsString;
				if (glScaner->InitDevice())
                        {
                        if (glScaner->Connect(port.c_str(),baud.c_str())==true)
                                {

                                glScaner->ConnectScaner=true;
                                }
                        else
                                {
                                ShowMessage("������ ����������� �������: "+AnsiString(glScaner->GetTextError()));
                                glScaner->ConnectScaner=false;
								DM_Connection->glSaveProtocol("������ ����������� �������: "+AnsiString(glScaner->GetTextError()));
                                }
                        }
                else
                        {
                        ShowMessage("������ �������� ���������� ������� ����� ����!");
						DM_Connection->glSaveProtocol("������ �������� ���������� ������� ����� ����!");
                        }
                }
		//���������� �����������
		if (Trim(DMSprOborud->TableTYPE_OBORUD->AsString)=="fr")
				{
				DM_Connection->glSaveProtocol("������� ���������� ���������� �����������");
				if (DMSprOborud->TableON_START_SOBORUD->AsInteger==1)
					{
					InterfaceGlobalCom->kanCreateObject("Oberon.FiskReg.1",IID_IFiskReg,
												 (void**)&glFR);
					glFR->Init(InterfaceMainObject,0);
					MainObject->glFR=glFR;
					glFR->Modul=DMSprOborud->TableMODUL_SOBORUD->AsString;
					glFR->Number=1;
					glFR->InitDevice();
					int number_port=StrToInt(DMSprOborud->TableCOMNAME_OBORUD->AsString);
					AnsiString baud_rate=DMSprOborud->TableBAUDRATE_OBORUD->AsString;

					AnsiString password=DMSprOborud->GetParameter("password");
					if(glFR->Connect(number_port, baud_rate, password)==true)
						{
						glFR->ConnectFR=true;

						}
					else
						{
						glFR->ConnectFR=false;
						ShowMessage("������ ��� ����������� ����������� ������������: "+glFR->TextError);
						DM_Connection->glSaveProtocol("������ ��� ����������� ����������� ������������: "+glFR->TextError);
						}
					}
			   }

		//������� ����������
		bool error_display=false;
		AnsiString text_error="";
		if (Trim(DMSprOborud->TableTYPE_OBORUD->AsString)=="DisplayPok")
			{
			//��������� ������� ����������
			InterfaceGlobalCom->kanCreateObject("Oberon.DisplayPok.1",IID_IDisplayPok,
												 (void**)&glDisplayPok);
			glDisplayPok->Init(InterfaceMainObject,0);
			MainObject->glDisplayPok=glDisplayPok;
				try
					{
					glDisplayPok->Modul=DMSprOborud->TableMODUL_SOBORUD->AsString;
					glDisplayPok->InitDevice();
					AnsiString port=DMSprOborud->TableCOMNAME_OBORUD->AsString ;
					AnsiString baud=DMSprOborud->TableBAUDRATE_OBORUD->AsString;
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
				ShowMessage("������: "+text_error);
				}
			else
				{
				glDisplayPok->ShowString1("����� ����������!",1,0,0);
				glDisplayPok->ShowString2(DM_Connection->ARMInfoNAME_SARM->AsString,1,0,0);
				}
			}


		DMSprOborud->Table->Next();
        }

DMSprOborud->kanRelease();


}
//---------------------------------------------------------------------------
void TArmOf::CheckKey(void)
{
GrdStartup(GrdFMR_Local | GrdFMR_Remote );         //   && 

grd=GrdCreateHandle(0, GrdCHM_SingleThread, 0);
GrdSetAccessCodes(grd, 2103077223, 1365184227,2585575258, 5244555225);
GrdSetFindMode(grd,
			GrdFMR_Local | GrdFMR_Remote,        //��������� ����   � ������ ����     GrdFMR_Local &&
			GrdFM_NProg,
			1,                   //����� ���������
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



//if (id_key==0)
//	{
//	glDemo=true;
//	StatusBar->Panels->Items[5]->Text="���������������� �����";
//	}
glRegNumber=id_key;
//GrdLogout(grd,0);
//GrdCloseHandle(grd);
//GrdCleanup();
}
//---------------------------------------------------------------------------
bool TArmOf::CheckEnableNew(void)
{
bool result=true;

if (DM_Connection->pFIBData->Connected==false)
	{
	ShowMessage("������������ �� ���������������!");
	return result;
	}

if (glDemo==true)
	{ //�������� ���������� ���������� � ���� ������
	IDMQueryRead *q;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
												 (void**)&q);
	q->Init(InterfaceMainObject,0);
	q->pFIBQ->SQL->Clear();
	q->pFIBQ->SQL->Add(" select MIN(galldoc.posdoc) as MINPOS from GALLDOC  ");
	q->pFIBQ->SQL->Add(" where galldoc.posdoc>'25.08.2009'");
	q->pFIBQ->ExecQuery();
	double kol=0;
	if (q->pFIBQ->FieldByName("MINPOS")->AsDateTime>EncodeDate(2000,1,1))
		{
		kol=MonthSpan(Now(),q->pFIBQ->FieldByName("MINPOS")->AsDateTime);
		}
	if (kol>2)
		{
		result=false;
		AnsiString s="���������������� �����! \n";
		s=s+"�������� �������� (2 ������) ������� ������������ ���������.\n";
		s=s+"���������� ���������� ������ ������.";
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
//---------------------------------------------------------------------------

void __fastcall TArmOf::BitBtnOpenStrObjectClick(TObject *Sender)
{
if (CheckEnableNew()==false) return;
if(glStrToInt64(DM_Connection->UserInfoID_USER->AsString)==0) return;
if (DM_Connection->pFIBData->Connected==false) return;


		IMainInterface * StrOb;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaStrObjectTouch.1",IID_IMainInterface, (void**)&StrOb);
		StrOb->Init(InterfaceMainObject,0);
		Panel1->Visible=false;

}
//---------------------------------------------------------------------------
void __fastcall TArmOf::EndEdit(TObject *Sender)
{
Panel1->Visible=true;

}
//-----------------------------------------------------------------------------

void __fastcall TArmOf::BitBtnExitClick(TObject *Sender)
{
Close();        
}
//------------------------------------------------------------------------------

void __fastcall TArmOf::Button1Click(TObject *Sender)
{

if (glFR!=0)
	{
	if (glFR->ConnectFR==true)
		{
		glFR->Disconnect();
		}
	}
DM_Connection->DisconnectBase();
StatusBar->Panels->Items[0]->Text="";

FormaViborBase=new TFormaViborBaseTouch(Application);
FormaViborBase->FOnCloseForm=EndViborBase;
FormaViborBase->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TArmOf::Button2Click(TObject *Sender)
{
if (glFR!=0)
	{
	if (glFR->ConnectFR==true)
		{
        glFR->ConnectFR=false;
		glFR->Disconnect();
		}
	}
DM_Connection->DisconnectBase();
StatusBar->Panels->Items[0]->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TArmOf::BitBtnCreateCheckClick(TObject *Sender)
{
if (CheckEnableNew()==false) return;
if(glStrToInt64(DM_Connection->UserInfoID_USER->AsString)==0) return;

		IMainInterface * form;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocCheckTouch.1",IID_IMainInterface, (void**)&form);
		form->Init(InterfaceMainObject,0);
		//Panel1->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TArmOf::ButtonPrintXReportClick(TObject *Sender)
{
if (CheckEnableNew()==false) return;
if(glStrToInt64(DM_Connection->UserInfoID_USER->AsString)==0) return;
if(glFR==0) return;
if(glFR->ConnectFR==false) return;

glFR->OpenNoFiscalCheck();

if (DM_Connection->Arm_GetParameter("STR_ZAG_1")!="")
        {
		glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_1"),1,0,1,true,false, false);
        }

if (DM_Connection->Arm_GetParameter("STR_ZAG_2")!="")
        {
		glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_2"),1,0,1,true,false, false);
        }

if (DM_Connection->Arm_GetParameter("STR_ZAG_3")!="")
        {
		glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_3"),1,0,1,true,false, false);
		}

glFR->CloseNoFiscalCheck();

glFR->PrintXReport();
}
//---------------------------------------------------------------------------

void __fastcall TArmOf::ButtonPrintZReportClick(TObject *Sender)
{
if (CheckEnableNew()==false) return;
if(glStrToInt64(DM_Connection->UserInfoID_USER->AsString)==0) return;
if(glFR==0) return;
if(glFR->ConnectFR==false) return;

glFR->OpenNoFiscalCheck();

if (DM_Connection->Arm_GetParameter("STR_ZAG_1")!="")
        {
		glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_1"),1,0,1,true,false, false);
        }

if (DM_Connection->Arm_GetParameter("STR_ZAG_2")!="")
        {
		glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_2"),1,0,1,true,false, false);
        }

if (DM_Connection->Arm_GetParameter("STR_ZAG_3")!="")
        {
		glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_3"),1,0,1,true,false, false);
		}

glFR->CloseNoFiscalCheck();

glFR->PrintZReport();
}
//---------------------------------------------------------------------------

void __fastcall TArmOf::ButtonSummaClick(TObject *Sender)
{
if (CheckEnableNew()==false) return;
if(glStrToInt64(DM_Connection->UserInfoID_USER->AsString)==0) return;

		IMainInterface * form;
		if (InterfaceGlobalCom->kanCreateObject("Oberon.FormaPrintCheckKKMTouch.1",
									IID_IMainInterface, (void**)&form)==-1)
			{
			form->Init(InterfaceMainObject,0);
			}
}
//---------------------------------------------------------------------------
void TArmOf::CheckDateTimeFR(void)
{
if (glFR==0) return;
bool set_date_time=false;
			try
				{
				//����� � ����
				TTime time_fr=glFR->GetTime();
				TTime time_pc=Time();
				TDate date_fr=glFR->GetDate();
				TDate date_pc=Date();
				if (date_fr==date_pc)
					{ //�������� �����
					//ShowMessage(TimeToStr(fabs(time_fr-time_pc))+"  "+TimeToStr(EncodeTime(0,5,0,0)));
					if (fabs(time_fr-time_pc) > EncodeTime(0,5,0,0))
						{ //������� ������ 5 �����
						set_date_time=true;
						}
					}
				else
					{
					set_date_time=true;
					}

				if (set_date_time==true && glFR->ConnectFR==true)
					{
					UnicodeString V="������� � ���������� ����� ���������� � ����������� ������������ ����� 5 �����.\n\n";
					V=V+DateToStr(date_pc)+"  "+TimeToStr(time_pc)+" - ���������\n";
					V=V+DateToStr(date_fr)+"  "+TimeToStr(time_fr)+" - ���������� �����������\n\n";
					V=V+"���������� ���� � ����� � ���������� ������������ �� ���������� ����� ����������?";
					UnicodeString Z="��������!";
					if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
						{
						V="����� ����������� ��������� �������� "+DateTimeToStr(Now())+
								". �������������� ��������� � ���������� ������������?";
						if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
							{
							if  (glFR->SetTime(Time())==true)
								{
								}
							else
								{
								ShowMessage("������ ��� ��������� �������: "+glFR->TextError);
								}

							if(glFR->SetDate(Date())==true)
								{
								}
							else
								{
								ShowMessage("������ ��� ��������� ����: "+glFR->TextError);
								}
							}
						}
					}
				}
			catch (Exception &exception)
				{
				ShowMessage("������ ��� �������� ���� � ������� ����������� ������������ - "+
						exception.Message);
				}



}
//----------------------------------------------------------------------------




void __fastcall TArmOf::ActionOpenCheckExecute(TObject *Sender)
{
if (CheckEnableNew()==false) return;
if(glStrToInt64(DM_Connection->UserInfoID_USER->AsString)==0) return;

		IMainInterface * form;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocCheckTouch.1",IID_IMainInterface, (void**)&form);
		form->Init(InterfaceMainObject,0);
		Panel1->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TArmOf::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("AllOpis");
}
//---------------------------------------------------------------------------


void __fastcall TArmOf::ApplicationEvents1Idle(TObject *Sender, bool &Done)
{
if (MDIChildCount==0)
	{
	Panel1->Visible=true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TArmOf::ButtonReportsClick(TObject *Sender)
{
if (CheckEnableNew()==false) return;
if(glStrToInt64(DM_Connection->UserInfoID_USER->AsString)==0) return;
if(glFR==0) return;
if(glFR->ConnectFR==false) return;

IMainInterface * forma;
if (InterfaceGlobalCom->kanCreateObject("Oberon.FormaReportTouchForFR.1",
					IID_IMainInterface, (void**)&forma)==-1)
	{
	forma->Init(InterfaceMainObject,0);
	Panel1->Visible=false;
	}
}
//---------------------------------------------------------------------------

