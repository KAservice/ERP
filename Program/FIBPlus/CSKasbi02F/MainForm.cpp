//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <fstream.h>
#include "MainForm.h"
#include "UDMDocCheck.h"
#include "UDMSprEd.h"
#include "UDMSprNom.h"
#include "UDM.h"
#include "UDMSprKKM.h"
#include "UDMSprPrice.h"
#include "UDMSprUser.h"
#include "UKasbi02f.h"
#include "UDMSprARM.h"
#include "UDMSprOborud.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TMainForm *MainForm;
bool zapusk;

TKkm * kkm;
TDMDocCheck *Check;
TDMSprNom *Nom;
TDMSprEd * Ed;
TDMSprKKM *KKM;
TDMSprPrice * DMSprPrice;
extern TDMSprUser * glUser;
extern String ComandString;
void glSaveProtocol(String str);


TDMSprARM *glARM;
int glNumberARM;
AnsiString BaseVersion;
AnsiString ProgramVersion;
extern AnsiString GetVersionProgramFile(void);
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{
ProgramVersion="2.7";
LabelSostCheck->Caption="";

kkm=new TKkm(true);
NewCheck=true;
zapusk=false;

DM=new TDM(Application);
//������� ������� ����������
AnsiString ProgramCatalog=ExtractFileDir(Application->ExeName);
if (DirectoryExists(ProgramCatalog+"\\Log")==false)
        {
		CreateDir(ProgramCatalog+"\\Log");
        }

if (DirectoryExists(ProgramCatalog+"\\Log")==true)
		{
		DM->glCatalogProtocol=ProgramCatalog+"\\Log";
		}

Check=new TDMDocCheck(Application);
Nom=new TDMSprNom(Application);
Ed=new TDMSprEd(Application);
glARM=new TDMSprARM(Application);
DMSprPrice=new TDMSprPrice(Application);

Price=0;
} 

//---------------------------------------------------------------------------
void __fastcall TMainForm::FormDestroy(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
kkm->Terminate();
delete kkm;
delete Ed;
delete Nom;
delete Check; 
delete KKM;
delete DMSprPrice;
//delete glUser;
delete DM;
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{

if (zapusk==true) return;
AnsiString connect_string="";
AnsiString set_number="";
AnsiString password_user="";
AnsiString name_user="";
int Kol=0;
//ComandString="/localhost:C:\\Data\\SP_CENTER.gdb/1/SYSDBA/masterkey";
if (Trim(ComandString)!="")
        {
        try
                {
                for (int i=1;i<ComandString.Length()+1;i++)
						{
                        if (ComandString[i]=='/')
								{
                                Kol=Kol+1;
                                }
                        else
                                {
								if (Kol==1){connect_string=connect_string+ComandString[i];}
								if (Kol==2){set_number=set_number+ComandString[i];}
								if (Kol==3){name_user=name_user+ComandString[i];}
								if (Kol==4){password_user=password_user+ComandString[i];}
                                }
                        }
//				ShowMessage("������ �����������:"+connect_string);
//				ShowMessage("������� �����:"+set_number);
//				ShowMessage("������������:"+name_user);
//				ShowMessage("������:"+password_user);

				DM->ConnectString=Trim(connect_string);
				DM->PasswordUser=Trim(password_user);
				DM->NameUser=Trim(name_user);

                if(DM->GlobConnect()==true)
						{
						if (glUser->FindPoName(name_user)==1)
							{
							}
						else
							{
							ShowMessage("�� ������ ������������ � ����������� �������������! ���������� ��������� ������!");
							}

						StatusBar->Panels->Items[0]->Text=glUser->ElementNAME_USER->AsString;
						StatusBar->Panels->Items[1]->Text=DM->ConnectString;

						Visible=true;
						glNumberARM=StrToInt(set_number);
						if (glARM->FindPoCodu(glNumberARM)==0)
							{
							ShowMessage ("�� ������� ��������� �������� �����!");
							OpenFormViborBase();
							}
						else
							{
							//���������� ����������
							ConnectDevice();
							}

                        }
				else
						{
						ShowMessage("�� ������� ������������ � ���� ������!\n������ �����������:"+connect_string
						+"\n������� �����:"+set_number
						+"\n������������:"+name_user
						+"\n������:"+password_user);
						OpenFormViborBase();
						}
				}
		catch (...)
				{
				ShowMessage("������ ��� �������� ���������� �� ��������� ������!\n������ �����������:"+connect_string
				+"\n������� �����:"+set_number
				+"\n������������:"+name_user
				+"\n������:"+password_user);
				OpenFormViborBase();
				}

       }
else
        {
        OpenFormViborBase();
		}
}
//---------------------------------------------------------------------------
void TMainForm::OpenFormViborBase(void)
{
FormaViborBase=new TFormaViborBase(Application);
FormaViborBase->FOnCloseForm=EndViborBase;
FormaViborBase->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::EndViborBase(TObject *Sender)
{

if (FormaViborBase->OutReady==true)
        {
        DM->ConnectString=FormaViborBase->ConnectString;
		DM->PasswordUser=FormaViborBase->PasswordUser;
		DM->NameUser=FormaViborBase->NameUser;

        if(DM->GlobConnect()==true)
				{
				if (glUser->FindPoName(FormaViborBase->NameUser)==1)
						{
						}
				else
						{
						ShowMessage("�� ������ ������������ � ����������� �������������! ���������� ��������� ������!");
						}

				Visible=true;
				glNumberARM=FormaViborBase->NumberARM;
				glARM->FindPoCodu(glNumberARM);
				ConnectDevice();

				StatusBar->Panels->Items[0]->Text=FormaViborBase->NameUser;
				StatusBar->Panels->Items[1]->Text=DM->ConnectString;

				FormaViborBase->CloseForm=true;
				}
		else
                {
				ShowMessage("�� ������� ������������  � ���� ������!");
                FormaViborBase->CloseForm=false;
                glSaveProtocol("�� ������� ������������  � ���� ������!");
                }
        }
else
        {
        //��������� ���������
        Close();

        }
}
//---------------------------------------------------------------------------
void TMainForm::ConnectDevice(void)
{
TDMSprARM * DMSprARM=new TDMSprARM(Application);
if(DMSprARM->FindPoCodu(glNumberARM)==0)
        {
        delete DMSprARM;
        return;
        }

TDMSprOborud * DMSprOborud=new TDMSprOborud(Application);
DMSprOborud->OpenTable(DMSprARM->ElementID_SARM->AsInt64);

DMSprOborud->Table->First();
while(!DMSprOborud->Table->Eof)
        {
        if (Trim(DMSprOborud->TableTYPE_OBORUD->AsString)=="kkm")
                {
				//��������� ��� � ������ ON-Line
				kkm->ComName="COM"+DMSprOborud->TableCOMNAME_OBORUD->AsString;
				//������� ����� = ���������� ������
				if (DMSprOborud->GetParameterPoTable("SavNumberKKM")=="")
					{
                    ShowMessage("�� ����� ��������� ����� � ����������� ������������. �������� SavNumberKKM!");
					}
				else
					{
					kkm->intSetNumber=StrToInt(DMSprOborud->GetParameterPoTable("SavNumberKKM"));
					}
				kkm->Resume();
				zapusk=true;  
                break;
                }
        DMSprOborud->Table->Next();
        }

delete DMSprOborud;
delete DMSprARM;

}
//---------------------------------------------------------------------------

















//---------------------------------------------------------------------------
//������� �������� �����
void __fastcall TMainForm::UpdateForm()
{


switch (kkm->EventKKM)
        {

        case kkm->ConnectEvent :  //����������� ���
                {
                //NewCheck=true;
				Price=0;
                StrokaMemo="����������� ���������� � ���!";
                MainForm->LabelActiveKKM->Color=clGreen;
                MainForm->LabelSoobshenie->Font->Color=clGreen;
                MainForm->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                MainForm->RE->Lines->Add(StrokaMemo);
                glSaveProtocol(" ");
                MainForm->RE->Lines->Add("   ");
                } break;

        case kkm->DisconnectEvent :     //���������� ���
                {
                NewCheck=true;


                MainForm->LabelActiveKKM->Color=clRed;
                StrokaMemo="��� ���������!";
                MainForm->LabelSoobshenie->Font->Color=clRed;
                MainForm->LabelSoobshenie->Caption=StrokaMemo;
                MainForm->RE->Lines->Add(StrokaMemo);
                glSaveProtocol(StrokaMemo);
                } break;

        case kkm->IzmStatusKKMEvent :  //��������� ������� ���
                {


                if (kkm->EstSvazKKM==true)
                        {
                        MainForm->LabelActiveKKM->Color=clGreen;
                        }
                else
                        {
                        MainForm->LabelActiveKKM->Color=clRed;
                        }
				Price=0;
                StrokaMemo="��������� ������� ���!";
                MainForm->LabelSoobshenie->Font->Color=clRed;
                MainForm->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                MainForm->RE->Lines->Add(StrokaMemo);
                } break;

        case kkm->PaketOtKKMEvent :     //����� �� ���
                {
                StrokaMemo="����� �� ���!";
                //FormGl->RichOperation->Lines->Add(StrokaMemo);
                glSaveProtocol(StrokaMemo);
                } break;
        case kkm->ErrorConnectEvent:      //������ ����������� � ���
                {

                MainForm->LabelActiveKKM->Color=clRed;
                StrokaMemo="������ ����������� � ���!";
                MainForm->LabelSoobshenie->Font->Color=clRed;
                MainForm->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                MainForm->RE->Lines->Add(StrokaMemo);
                } break;
        case kkm->ErrorObmenEvent:       //������ ������
                {
                StrokaMemo=kkm->TextError;
                MainForm->LabelSoobshenie->Font->Color=clRed;
                MainForm->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                MainForm->RE->Lines->Add(StrokaMemo);
                } break;
        case kkm->ZaprosPoCoduEvent:      //������ �� ����
                {
				Price=0;
                StrokaMemo="������ �� ����!";
                 if ( kkm->CheckOperation==kkm->Prod )
                        {
                        StrokaMemo=StrokaMemo+" ������� ";
                        }
                        else
                        {
                        if ( kkm->CheckOperation==kkm->Vosvrat )
                                {
                                StrokaMemo=StrokaMemo+" ������� ";
                                }
                        else
                                {
                         StrokaMemo=StrokaMemo+" ����������� �������� ";
                                }
                         }
                StrokaMemo=StrokaMemo+" ����� ����: "+IntToStr(kkm->NumberCheck);
                StrokaMemo=StrokaMemo+" ��� ������: "+FloatToStr(kkm->CodeTovar);
                MainForm->LabelSoobshenie->Font->Color=clBlue;
                MainForm->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                MainForm->RE->Lines->Add(StrokaMemo);
                } break;
        case kkm->ZaprosPoShtrihCoduEvent:     //������ �� ���� � �����������
                {
                StrokaMemo="������ �� ���� � �����������!";
                 if ( kkm->CheckOperation==kkm->Prod )
                        {
                        StrokaMemo=StrokaMemo+" ������� ";
                        }
                        else
                        {
                        if ( kkm->CheckOperation==kkm->Vosvrat )
                                {
                                StrokaMemo=StrokaMemo+" ������� ";
                                }
                        else
                                {
                         StrokaMemo=StrokaMemo+" ����������� �������� ";
                                }
                         }
                StrokaMemo=StrokaMemo+" ����� ����: "+IntToStr(kkm->NumberCheck);
                StrokaMemo=StrokaMemo+" �� ������: "+kkm->ShCodeTovar;
                StrokaMemo=StrokaMemo+" ���-��: "+FloatToStr(kkm->KolTovar);
                MainForm->LabelSoobshenie->Font->Color=clBlue;
                MainForm->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                MainForm->RE->Lines->Add(StrokaMemo);
                } break;
        case kkm->DobavlenieSvobSummEvent:  //���������� ��������� ����� � ���
                {
                StrokaMemo="���������� ��������� �����!";

                if ( kkm->CheckOperation==kkm->Prod )
                        {
                        StrokaMemo=StrokaMemo+" ������� ";

                        }
                        else
                        {
                        if ( kkm->CheckOperation==kkm->Vosvrat )
                                {
                                StrokaMemo=StrokaMemo+" ������� ";

                                }
                        else
                                {
                         StrokaMemo=StrokaMemo+" ����������� �������� ";
                                }
                         }
                StrokaMemo=StrokaMemo+" ����� ����: "+IntToStr(kkm->NumberCheck);
                StrokaMemo=StrokaMemo+" ����� �������: "+IntToStr(kkm->NumberPokupki);
                StrokaMemo=StrokaMemo+" �����: "+IntToStr(kkm->Otdel);
                StrokaMemo=StrokaMemo+" ����� �������: "+FloatToStr(kkm->SummaPokupki);

                if (NewCheck==true)
                        {//������� ������� ����


                        }


                 MainForm->LabelSostCheck->Font->Color=clRed;
                 MainForm->LabelSostCheck->Caption="��� ������";
                MainForm->LabelSoobshenie->Font->Color=clBlue;
                MainForm->LabelSoobshenie->Caption=StrokaMemo;

                glSaveProtocol(StrokaMemo);
                MainForm->RE->Lines->Add(StrokaMemo);
                } break;

        case kkm->DobavleniePokupkiEvent:  //���������� ������� � ���
                {
                StrokaMemo="���������� �������!";

                if ( kkm->CheckOperation==kkm->Prod )
                        {
                        StrokaMemo=StrokaMemo+" ������� ";

                        }
                        else
                        {
                        if ( kkm->CheckOperation==kkm->Vosvrat )
                                {
                                StrokaMemo=StrokaMemo+" ������� ";

                                }
                        else
                                {
                         StrokaMemo=StrokaMemo+" ����������� �������� ";
                                }
                         }

                StrokaMemo=StrokaMemo+" ����� ����: "+IntToStr(kkm->NumberCheck);
                StrokaMemo=StrokaMemo+" ����� �������: "+IntToStr(kkm->NumberPokupki);
                StrokaMemo=StrokaMemo+" ���: "+FloatToStr(kkm->KolTovar);
                StrokaMemo=StrokaMemo+" �����: "+IntToStr(kkm->Otdel);
                StrokaMemo=StrokaMemo+" ����� �������: "+FloatToStr(kkm->SummaPokupki);

                if (NewCheck==true)
                        {//������� ������� ����


                        }


                MainForm->LabelSostCheck->Font->Color=clRed;
                MainForm->LabelSostCheck->Caption="��� ������";
                MainForm->LabelSoobshenie->Font->Color=clBlue;
                MainForm->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                MainForm->RE->Lines->Add(StrokaMemo);
                } break;
        case kkm->ZakrChekaEvent:       //�������� ����
                {
                StrokaMemo="�������� ����!";
                if ( kkm->CheckOperation==kkm->Prod )
                        {
                        StrokaMemo=StrokaMemo+" ������� ";
                        }
                        else
                        {
                        if ( kkm->CheckOperation==kkm->Vosvrat )
                                {
                                StrokaMemo=StrokaMemo+" ������� ";
                                }
                        else
                                {
                         StrokaMemo=StrokaMemo+" ����������� �������� ";
                                }
                         }

                StrokaMemo=StrokaMemo+" � ����: "+IntToStr(kkm->NumberCheck);
                StrokaMemo=StrokaMemo+" � ��: "+IntToStr(kkm->NumberKl);

               StrokaMemo=StrokaMemo+" ���: ";
               if ( kkm->Oplata==kkm->Nal )
                        {
                        StrokaMemo=StrokaMemo+"���.";
                        }
                        else
                        {
                        if ( kkm->Oplata==kkm->BesNal )
                                {
                                StrokaMemo=StrokaMemo+"������.";
                                }
                        else
                                {
                         StrokaMemo=StrokaMemo+" ����������� ������";
                                }
                         }

               StrokaMemo=StrokaMemo+" �����: " ;
               if ( kkm->Nachislenie==kkm->No )
                        {
                        StrokaMemo=StrokaMemo+"���";
                        }
               if ( kkm->Nachislenie==kkm->Nadbavka )
                        {
                        StrokaMemo=StrokaMemo+"��������";
                        }
               if ( kkm->Nachislenie==kkm->Skidka )
                        {
                        StrokaMemo=StrokaMemo+"������";
                        }
                StrokaMemo=StrokaMemo+" %: "+IntToStr(kkm->Procent);
                StrokaMemo=StrokaMemo+" ���. ���.: "+IntToStr(kkm->KolPokupok);
                StrokaMemo=StrokaMemo+" ��� ������: "+FloatToStr(kkm->SummaCheck);
                StrokaMemo=StrokaMemo+" � �����: "+FloatToStr(kkm->RealSummaCheck);

                MainForm->LabelSostCheck->Font->Color=clGreen;
                MainForm->LabelSostCheck->Caption="��� ������";


                MainForm->LabelSoobshenie->Font->Color=clBlue;
                MainForm->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                MainForm->RE->Lines->Add(StrokaMemo);


                } break;
        case kkm->SbrosChekaEvent:     //����� ����
                {
                StrokaMemo="����� ����!";
                MainForm->LabelSostCheck->Font->Color=clGreen;
                MainForm->LabelSostCheck->Caption="��� �������";
                MainForm->LabelSoobshenie->Font->Color=clBlue;
                MainForm->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                MainForm->RE->Lines->Add(StrokaMemo);
                glSaveProtocol(" ");
                MainForm->RE->Lines->Add("   ");

                } break;
        case kkm->UdaleniePokupkiEvent:     //�������� �������
                {
                StrokaMemo="�������� �������!";
                MainForm->LabelSoobshenie->Font->Color=clBlue;
                MainForm->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                MainForm->RE->Lines->Add(StrokaMemo);

                } break;
        case kkm->UnknownEvent:
                {
                MainForm->LabelSoobshenie->Font->Color=clRed;
                MainForm->LabelSoobshenie->Caption="����������� ������� �� ���!";
                MainForm->RE->Lines->Add("����������� ������� �� ���!");
                glSaveProtocol("����������� ������� �� ���!");
                StrokaMemo=kkm->TextError;
                MainForm->RE->Lines->Add(StrokaMemo);
                glSaveProtocol(StrokaMemo);
                } break;
        default :
                {

                } break;
        }

}
//----------------------------------------------------------------------------
//���������� ������ ���
void  __fastcall TMainForm::ObrabotatZaprosKKM()
{

switch (kkm->EventKKM)
        {

        case kkm->ConnectEvent :
                {

                } break;
        case kkm->DisconnectEvent :
                {


                } break;
        case kkm->PaketOtKKMEvent :
                {

                } break;
        case kkm->ErrorConnectEvent:
                {

                } break;
        case kkm->ErrorObmenEvent:
                {

                } break;
        case kkm->ZaprosPoCoduEvent:
				{
				Price=0;
                //������� ��������� ������
                int KolNom=Nom->FindPoCodu(kkm->CodeTovar);
                StrokaMemo="�����: ";
                if (KolNom==1)
                        {
                        kkm->NameTovar=Nom->ElementNAMENOM->AsString;
                        kkm->ShCodeTovar=FloatToStr(kkm->CodeTovar);
						StrokaMemo=StrokaMemo+Nom->ElementNAMENOM->AsString;

						Price=0;
						Price=DMSprPrice->GetValuePrice(glARM->ElementIDTPRICEPOD->AsInt64, //��� ���
														Nom->ElementIDNOM->AsInt64,         //������������
														Nom->ElementIDBASEDNOM->AsInt64,    //�������
														1,                                 //�� �������
														Nom->ElementIDBASEDNOM->AsInt64) ; //������� �������

						if ( Price > 0.001)
                                {
								kkm->PriceTovar=Price;
								StrokaMemo=StrokaMemo+" ����: "+FloatToStr(Price);
                                kkm->EnableOtvet=true;
                                }
                        else
                                {
                                kkm->EnableOtvet=false;
                                StrokaMemo=StrokaMemo+" �� ������� ����! �� ��������!" ;
                                }

                        }
                else
                        {
                        kkm->EnableOtvet=false;
                        StrokaMemo=StrokaMemo+" �� ������ �����! �� ��������!";
                        }
                MainForm->RE->Lines->Add(StrokaMemo);
                glSaveProtocol(StrokaMemo);
                } break;
        case kkm->ZaprosPoShtrihCoduEvent:
                {
                 //������� ��������� ������

                int KolNom=0;
                if (kkm->ShCodeTovar.Length()<6)
                        {
                        KolNom=Nom->FindPoCodu(StrToInt(kkm->ShCodeTovar));
                        }
                else
                        {

                        }

                StrokaMemo="�����: ";
                if (KolNom==1)
                        {
                        kkm->NameTovar=Nom->ElementNAMENOM->AsString;
                        kkm->CodeTovar=Nom->ElementCODENOM->AsFloat;

						StrokaMemo=StrokaMemo+Nom->ElementNAMENOM->AsString;

						Price=0;
						Price=DMSprPrice->GetValuePrice(glARM->ElementIDTPRICEPOD->AsInt64, //��� ���
														Nom->ElementIDNOM->AsInt64,         //������������
														Nom->ElementIDBASEDNOM->AsInt64,    //�������
														1,                                  //�� �������
														Nom->ElementIDBASEDNOM->AsInt64) ;  //������� �������

						if ( Price > 0.001)
								{
								kkm->PriceTovar=Price;
								StrokaMemo=StrokaMemo+" ����: "+FloatToStr(Price);
                                kkm->EnableOtvet=true;
                                }
                        else
                                {
                                kkm->EnableOtvet=false;
                                StrokaMemo=StrokaMemo+" �� ������� ����! �� ��������!" ;
                                }

                        }
                else
                        {
                        kkm->EnableOtvet=false;
                        StrokaMemo=StrokaMemo+" �� ������ �����! �� ��������!";
                        }
                MainForm->RE->Lines->Add(StrokaMemo);
                glSaveProtocol(StrokaMemo);
                } break;

        case kkm->DobavlenieSvobSummEvent:  //���������� ��������� ����� � ���
                {
                if (NewCheck==true)
                        {
                        //Check->IBTr->Rollback();
                        //Check->IBTr->StartTransaction();
                        //Check->DocAll->Active=true;
                        //Check->Doc->Active=true;
						//Check->DocT->Active=true;
						Price=0;
                        Check->OpenDoc(0);
                        Check->NewDoc();
						Check->DocAll->Edit();
						Check->DocAllIDBASE_GALLDOC->AsInt64=glARM->ElementIDBASE_SARM->AsInt64;
						Check->DocAllIDFIRMDOC->AsInt64=glARM->ElementIDFIRM_SARM->AsInt64;
						Check->DocAllIDSKLDOC->AsInt64=glARM->ElementIDSKLAD_SARM->AsInt64;
                        Check->DocAll->Post();
                        Check->Doc->Edit();

                        if (kkm->CheckOperation==kkm->Prod)
                                {
                                Check->DocOPERCHK->AsInteger=0;
                                }

                        if (kkm->CheckOperation==kkm->Vosvrat)
                                {
                                Check->DocOPERCHK->AsInteger=1;
                                }

						Check->DocIDKKMCHK->AsInt64=KKM->ElementIDKKM->AsInt64;
						Check->DocIDTPRICE->AsInt64=glARM->ElementIDTPRICEPOD->AsInt64;
                        Check->Doc->Post();
                        NewCheck=false;
                        TekSummaCheck=0;
                        }
                Nom->FindPoCodu(1);
                if (Nom->Element->RecordCount==1)
                        {
                        Check->AddDocNewString();
                        Check->DocT->Edit();
						Check->DocTIDNOMCHKT->AsInt64=Nom->ElementIDNOM->AsInt64;
                        Check->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
                        Check->DocTIDEDCHKT->AsInt64=Nom->ElementIDBASEDNOM->AsInt64;
                        Check->DocTNAMEED->AsString=Nom->BasEdNAMEED->AsString;
                        Check->DocTKOLCHKT->AsFloat=kkm->KolTovar;
                        Check->DocTKFCHKT->AsFloat=1;
                        Check->DocTPRICECHKT->AsFloat=kkm->PriceTovar;
                        Check->DocTSUMCHKT->AsFloat=kkm->SummaPokupki;
                        Check->DocT->Post();
                        }
                else
                        {
                        MainForm->RE->Lines->Add("�� ������ ����� � ����� ��������� ����� (1)! ");
                        glSaveProtocol("�� ������ ����� � ����� ��������� ����� (1)! ");
                        }
                TekSummaCheck=TekSummaCheck+kkm->SummaPokupki;

                } break;


        case kkm->DobavleniePokupkiEvent:
                {
                if (NewCheck==true)
                        {
						//Check->OpenDoc(0);
                        Check->NewDoc();
						Check->DocAll->Edit();
						Check->DocAllIDBASE_GALLDOC->AsInt64=glARM->ElementIDBASE_SARM->AsInt64;
						Check->DocAllIDFIRMDOC->AsInt64=glARM->ElementIDFIRM_SARM->AsInt64;
						Check->DocAllIDSKLDOC->AsInt64=glARM->ElementIDSKLAD_SARM->AsInt64;
                        Check->DocAll->Post();
                        Check->Doc->Edit();
						Check->DocIDKKMCHK->AsInt64=glARM->ElementIDKKM_SARM->AsInt64;

                        if (kkm->CheckOperation==kkm->Prod)
                                {
                                Check->DocOPERCHK->AsInteger=0;
                                }

                        if (kkm->CheckOperation==kkm->Vosvrat)
                                {
                                Check->DocOPERCHK->AsInteger=1;
                                }

						Check->DocIDTPRICE->AsInt64=glARM->ElementIDTPRICEPOD->AsInt64;
                        Check->Doc->Post();
                        NewCheck=false;
                        TekSummaCheck=0;
                        }
                Check->AddDocNewString();
                Check->DocT->Edit();
				Check->DocTIDNOMCHKT->AsInt64=Nom->ElementIDNOM->AsInt64;
                Check->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
				Check->DocTIDEDCHKT->AsInt64=Nom->ElementIDBASEDNOM->AsInt64;
                Check->DocTNAMEED->AsString=Nom->BasEdNAMEED->AsString;
                Check->DocTKOLCHKT->AsFloat=kkm->KolTovar;
                Check->DocTKFCHKT->AsFloat=Nom->BasEdKFED->AsFloat;
				Check->DocTPRICECHKT->AsFloat=Price;

                Check->DocT->Post();


                } break;
        case kkm->ZakrChekaEvent:
                {

                if (NewCheck==true)  //�������� ����� ���
                        {
                        StrokaMemo="���������� ��������� �����!";
                        Nom->FindPoCodu(1);
                        if (Nom->Element->RecordCount==1)
                                {
                                Check->OpenDoc(0);
                                Check->NewDoc();
								Check->DocAll->Edit();
								Check->DocAllIDBASE_GALLDOC->AsInt64=glARM->ElementIDBASE_SARM->AsInt64;
								Check->DocAllIDFIRMDOC->AsInt64=glARM->ElementIDFIRM_SARM->AsInt64;
								Check->DocAllIDSKLDOC->AsInt64=glARM->ElementIDSKLAD_SARM->AsInt64;
                                Check->DocAll->Post();
                                Check->Doc->Edit();
								Check->DocIDKKMCHK->AsInt64=glARM->ElementIDKKM_SARM->AsInt64;

                                if (kkm->CheckOperation==kkm->Prod)
                                        {
                                        Check->DocOPERCHK->AsInteger=0;
                                        }

                                if (kkm->CheckOperation==kkm->Vosvrat)
                                        {
                                        Check->DocOPERCHK->AsInteger=1;
                                        }

                                Check->DocIDTPRICE->AsInt64=glARM->ElementIDTPRICEPOD->AsInt64;
                                Check->Doc->Post();

                                TekSummaCheck=0;

                                Check->AddDocNewString();
                                Check->DocT->Edit();
								Check->DocTIDNOMCHKT->AsInt64=Nom->ElementIDNOM->AsInt64;
                                Check->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
                                Check->DocTIDEDCHKT->AsInt64=Nom->ElementIDBASEDNOM->AsInt64;
                                Check->DocTNAMEED->AsString=Nom->BasEdNAMEED->AsString;
                                Check->DocTKOLCHKT->AsFloat=1;
                                Check->DocTKFCHKT->AsFloat=1;
                                Check->DocTPRICECHKT->AsFloat=kkm->RealSummaCheck;
                                Check->DocTSUMCHKT->AsFloat=kkm->RealSummaCheck;
                                StrokaMemo=StrokaMemo+" �����:"+FloatToStr(kkm->RealSummaCheck);
                                Check->DocT->Post();
                                }
                        else
                                {
                                MainForm->RE->Lines->Add("�� ������ ����� � ����� ��������� ����� (1)! ");
                                glSaveProtocol("�� ������ ����� � ����� ��������� ����� (1)! ");
                                }
                        glSaveProtocol(StrokaMemo);
                        MainForm->RE->Lines->Add(StrokaMemo);
                        }

               //��������� ���
                Check->Doc->Edit();
                Check->DocNCHECKCHK->AsInteger=kkm->NumberCheck;
                Check->DocNKLCHK->AsInteger=kkm->NumberKl;
                Check->Doc->Post();

                RaspredNachislenie();

                Check->Doc->Edit();
                Check->DocNALCHK->AsFloat=Check->DocAllSUMDOC->AsFloat;
                Check->Doc->Post();



                if (Check->SaveDoc()==true)
                        {
                        if(Check->DvRegDoc()==false)
                                {
                                MainForm->RE->Lines->Add("�� ������� �������� ���!");
                                glSaveProtocol("�� ������� �������� ���!");
                                }
                        }
                else
                        {
                        MainForm->RE->Lines->Add("�� ������� �������� ���!");
                        glSaveProtocol("�� ������� �������� ���!");

                        }
                NewCheck=true;
                
                glSaveProtocol(" ");
                MainForm->RE->Lines->Add("   ");

                } break;
        case kkm->UdaleniePokupkiEvent:
				{
				Price=0;
                if (Check->DocT->RecordCount>0)
                        {
                        Check->DocT->Delete();
                        }
                if(Check->DocT->RecordCount==0)
						{
                        StrokaMemo="��� �������!!!";
                        MainForm->LabelSostCheck->Font->Color=clGreen;
                        MainForm->LabelSostCheck->Caption="��� �������";
                        MainForm->LabelSoobshenie->Font->Color=clBlue;
                        MainForm->LabelSoobshenie->Caption=StrokaMemo;
                        glSaveProtocol(StrokaMemo);
                        MainForm->RE->Lines->Add(StrokaMemo);
                        glSaveProtocol(" ");
                        MainForm->RE->Lines->Add("   ");
                        Check->DocT->CancelUpdates();
                        Check->Doc->CancelUpdates();
                        Check->DocAll->CancelUpdates();
                        //Check->IBTr->Commit();
                        NewCheck=true;
                        }
                } break;
        case kkm->SbrosChekaEvent:
                {
                Price=0;
                        StrokaMemo="��� �������!!!";
                        MainForm->LabelSostCheck->Font->Color=clGreen;
                        MainForm->LabelSostCheck->Caption="��� �������";
                        MainForm->LabelSoobshenie->Font->Color=clBlue;
                        MainForm->LabelSoobshenie->Caption=StrokaMemo;
                        glSaveProtocol(StrokaMemo);
                        MainForm->RE->Lines->Add(StrokaMemo);
                        glSaveProtocol(" ");
                        MainForm->RE->Lines->Add("   ");
                        Check->DocT->CancelUpdates();
                        Check->Doc->CancelUpdates();
                        Check->DocAll->CancelUpdates();
                        //Check->IBTr->Commit();
                        NewCheck=true;
                } break;


        default :
                {

                } break;
        }
}

//----------------------------------------------------------------------------
void __fastcall TMainForm::ObrabExternalEvent()
{
UpdateForm();
ObrabotatZaprosKKM();

}
//----------------------------------------------------------------------------
void TMainForm::RaspredNachislenie(void)
{
double Skidka=0;
double Nadbavka=0;
double Pr;

if (Check->DocAllSUMDOC->AsFloat==kkm->RealSummaCheck) return ;

if (Check->DocAllSUMDOC->AsFloat>kkm->RealSummaCheck)
        {
        Skidka=Check->DocAllSUMDOC->AsFloat-kkm->RealSummaCheck;
        Pr=(Skidka)/(Check->DocAllSUMDOC->AsFloat/100);
        }

if(kkm->RealSummaCheck>Check->DocAllSUMDOC->AsFloat)
        {
        Nadbavka=kkm->RealSummaCheck-Check->DocAllSUMDOC->AsFloat;
        Pr=((Nadbavka)/Check->DocAllSUMDOC->AsFloat/100);
        }


        int Kol=0;
        Check->DocT->First();
        while(!Check->DocT->Eof)
                {
                Check->DocT->Edit();
                if (Skidka>0)
                        {
                        if (Kol==Check->DocT->RecordCount-1)
                                {
                                Check->DocTSKCHKT->AsFloat=Check->DocTSKCHKT->AsFloat+Skidka;
                                }
                        else
                                {
                                Check->DocTSKCHKT->AsFloat=Check->DocTSKCHKT->AsFloat+Check->DocTSUMCHKT->AsFloat*(Pr)/100;

                                }

                        Skidka=Skidka-Check->DocTSKCHKT->AsFloat;
                        }

                if (Nadbavka>0)
                        {
                        if (Kol==Check->DocT->RecordCount-1)
                                {
                                Check->DocTNADCHKT->AsFloat=Check->DocTNADCHKT->AsFloat+Nadbavka;
                                }
                        else
                                {
                                Check->DocTNADCHKT->AsFloat=Check->DocTNADCHKT->AsFloat+Check->DocTNADCHKT->AsFloat*(Pr)/100;

                                }
                        Nadbavka=Nadbavka-Check->DocTNADCHKT->AsFloat;
                        }
                double Sk=Check->DocTSKCHKT->AsFloat;
                double Nad=Check->DocTNADCHKT->AsFloat;
                double Sum=Check->DocTPRICECHKT->AsFloat*Check->DocTKOLCHKT->AsFloat
                                -Check->DocTSKCHKT->AsFloat+Check->DocTNADCHKT->AsFloat;
               // Check->DocTPRICECHKT->AsFloat=Sum/Check->DocTKOLCHKT->AsFloat;
                Check->DocTSUMCHKT->AsFloat=Sum;
                Check->DocTNADCHKT->AsFloat=Nad;
                Check->DocTSKCHKT->AsFloat=Sk;

                Check->DocT->Post();
                Kol=Kol+1;
                Check->DocT->Next();
                }

}
//-----------------------------------------------------------------------------



void __fastcall TMainForm::FormResize(TObject *Sender)
{
int SumWidth=DBGrid1->Width-40;
DBGrid1->Columns->Items[0]->Width=0.05*SumWidth;
DBGrid1->Columns->Items[1]->Width=0.25*SumWidth;
DBGrid1->Columns->Items[2]->Width=0.1*SumWidth;
DBGrid1->Columns->Items[3]->Width=0.1*SumWidth;
DBGrid1->Columns->Items[4]->Width=0.1*SumWidth;
DBGrid1->Columns->Items[5]->Width=0.1*SumWidth;
DBGrid1->Columns->Items[6]->Width=0.1*SumWidth;
DBGrid1->Columns->Items[7]->Width=0.1*SumWidth;
DBGrid1->Columns->Items[8]->Width=0.1*SumWidth;

}
//---------------------------------------------------------------------------




