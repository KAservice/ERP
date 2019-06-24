//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <fstream.h>
#include "GlavForm.h"
#include "amc100k.h"
//#include "CashServer.h"
#include "UDMDocCheck.h"
#include "UDMSprEd.h"
#include "UDMSprNom.h"
#include "UDM.h"
#include "UDMSprUser.h"
#include "UDMSprPrice.h"
#include "UDMSprARM.h"
#include "UDMSprOborud.h"
#include "UAbout.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

bool zapusk;

TFormGl *FormGl;
amc100k *amc;
TDMDocCheck *Check;
TDMSprNom *Nom;
TDMSprEd * Ed;
TDMSprARM *glARM;
int glNumberARM;
TDMSprPrice * DMSprPrice;
extern TDMSprUser *glUser;
extern String ComandString;
void glSaveProtocol(String str);
String AddEAN13(String Cod) ;

AnsiString BaseVersion;
AnsiString ProgramVersion;
int glRegNumber;
extern bool glDemo;
extern AnsiString GetVersionProgramFile(void);
//---------------------------------------------------------------------------
__fastcall TFormGl::TFormGl(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormGl::FormCreate(TObject *Sender)
{
ProgramVersion="2.7";
LabelSostCheck->Caption="";
LabelProcent->Caption="";
LabelSummaNach->Caption="";
LabelOperation->Caption="";

amc=new amc100k(true);
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
//glUser=new TDMSprUser(Application);

}
//---------------------------------------------------------------------------
void __fastcall TFormGl::FormShow(TObject *Sender)
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
void TFormGl::OpenFormViborBase(void)
{
FormaViborBase=new TFormaViborBase(Application);
FormaViborBase->FOnCloseForm=EndViborBase;
FormaViborBase->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFormGl::EndViborBase(TObject *Sender)
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
void TFormGl::ConnectDevice(void)
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
                amc->ComName="COM"+DMSprOborud->TableCOMNAME_OBORUD->AsString;
                amc->intSetNumber=glNumberARM;
                amc->Resume();
                zapusk=true;
                break;
                }
        DMSprOborud->Table->Next();
        }

delete DMSprOborud;
delete DMSprARM;

}


//---------------------------------------------------------------------------

void __fastcall TFormGl::FormClose(TObject *Sender, TCloseAction &Action)
{
amc->Terminate();
delete amc;
delete Ed;
delete Nom;
delete Check;
delete DM;
delete glARM;
delete DMSprPrice;
//delete glUser;
}
//---------------------------------------------------------------------------
void __fastcall TFormGl::FormDestroy(TObject *Sender)
{
//Shell_NotifyIcon(NIM_DELETE, &NID);
}


//----------------------------------------------------------------------------

//������� �������� �����
void __fastcall TFormGl::UpdateForm()
{


switch (amc->EventKKM)
        {

        case amc->ConnectEvent :  //����������� ���
                {
                NewCheck=true;

                StrokaMemo="����������� ���������� � ���!";
                FormGl->LabelActiveKKM->Color=clGreen;
                FormGl->LabelSoobshenie->Font->Color=clGreen;
                FormGl->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                FormGl->RE->Lines->Add(StrokaMemo);
                glSaveProtocol(" ");
                FormGl->RE->Lines->Add("   ");
                } break;

        case amc->DisconnectEvent :     //���������� ���
                {
                NewCheck=true;


                FormGl->LabelActiveKKM->Color=clRed;
                StrokaMemo="��� ���������!";
                FormGl->LabelSoobshenie->Font->Color=clRed;
                FormGl->LabelSoobshenie->Caption=StrokaMemo;
                FormGl->RE->Lines->Add(StrokaMemo);
                glSaveProtocol(StrokaMemo);
                } break;

        case amc->IzmStatusKKMEvent :  //��������� ������� ���
                {


                if (amc->EstSvazKKM==true)
                        {
                        FormGl->LabelActiveKKM->Color=clGreen;
                        }
                else
                        {
                        FormGl->LabelActiveKKM->Color=clRed;
                        }

                StrokaMemo="��������� ������� ���!";
                FormGl->LabelSoobshenie->Font->Color=clRed;
                FormGl->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                FormGl->RE->Lines->Add(StrokaMemo);
                } break;

        case amc->PaketOtKKMEvent :     //����� �� ���
                {
                StrokaMemo="����� �� ���!";
                //FormGl->RichOperation->Lines->Add(StrokaMemo);
                glSaveProtocol(StrokaMemo);
                } break;
        case amc->ErrorConnectEvent:      //������ ����������� � ���
                {
                NewCheck=true;

                FormGl->LabelActiveKKM->Color=clRed;
                StrokaMemo="������ ����������� � ���!";
                FormGl->LabelSoobshenie->Font->Color=clRed;
                FormGl->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                FormGl->RE->Lines->Add(StrokaMemo);
                } break;
        case amc->ErrorObmenEvent:       //������ ������
                {
                StrokaMemo=amc->TextError;
                FormGl->LabelSoobshenie->Font->Color=clRed;
                FormGl->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                FormGl->RE->Lines->Add(StrokaMemo);
                } break;
        case amc->ZaprosPoCoduEvent:      //������ �� ����
                {

                StrokaMemo="������ �� ����!";
                 if ( amc->CheckOperation==amc->Prod )
                        {
                        StrokaMemo=StrokaMemo+" ������� ";
                        }
                        else
                        {
                        if ( amc->CheckOperation==amc->Vosvrat )
                                {
                                StrokaMemo=StrokaMemo+" ������� ";
                                }
                        else
                                {
                         StrokaMemo=StrokaMemo+" ����������� �������� ";
                                }
                         }
                StrokaMemo=StrokaMemo+" ����� ����: "+IntToStr(amc->NumberCheck);
                StrokaMemo=StrokaMemo+" ��� ������: "+FloatToStr(amc->CodeTovar);
                FormGl->LabelSoobshenie->Font->Color=clBlue;
                FormGl->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                FormGl->RE->Lines->Add(StrokaMemo);
                } break;
        case amc->ZaprosPoCoduKolEvent:     //������ �� ���� � �����������
                {
                StrokaMemo="������ �� ���� � �����������!";
                 if ( amc->CheckOperation==amc->Prod )
                        {
                        StrokaMemo=StrokaMemo+" ������� ";
                        }
                        else
                        {
                        if ( amc->CheckOperation==amc->Vosvrat )
                                {
                                StrokaMemo=StrokaMemo+" ������� ";
                                }
                        else
                                {
                         StrokaMemo=StrokaMemo+" ����������� �������� ";
                                }
                         }
                StrokaMemo=StrokaMemo+" ����� ����: "+IntToStr(amc->NumberCheck);
                StrokaMemo=StrokaMemo+" ��� ������: "+FloatToStr(amc->CodeTovar);
                StrokaMemo=StrokaMemo+" ���-��: "+FloatToStr(amc->KolTovar);
                FormGl->LabelSoobshenie->Font->Color=clBlue;
                FormGl->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                FormGl->RE->Lines->Add(StrokaMemo);
                } break;
        case amc->DobavlenieSvobSummEvent:  //���������� ��������� ����� � ���
                {
                StrokaMemo="���������� ��������� �����!";

                if ( amc->CheckOperation==amc->Prod )
                        {
                        StrokaMemo=StrokaMemo+" ������� ";
                        FormGl->LabelOperation->Caption="�������";
                        }
                        else
                        {
                        if ( amc->CheckOperation==amc->Vosvrat )
                                {
                                StrokaMemo=StrokaMemo+" ������� ";
                                FormGl->LabelOperation->Caption="�������";
                                }
                        else
                                {
                         StrokaMemo=StrokaMemo+" ����������� �������� ";
                                }
                         }
                StrokaMemo=StrokaMemo+" ����� ����: "+IntToStr(amc->NumberCheck);
                StrokaMemo=StrokaMemo+" ����� �������: "+IntToStr(amc->NumberPokupki);
                StrokaMemo=StrokaMemo+" �����: "+IntToStr(amc->Otdel);
                StrokaMemo=StrokaMemo+" ����� �������: "+FloatToStr(amc->SummaPokupki);

                if (NewCheck==true)
                        {//������� ������� ����

                        FormGl->LabelProcent->Caption="";
                        FormGl->LabelSummaNach->Caption="";
                        FormGl->LabelItog->Caption="����: ";

                        }

                 NewCheck=false;
                 FormGl->LabelNumberCheck->Caption="������� ��� �"+IntToStr(amc->NumberCheck );
                 FormGl->LabelItog->Caption="����:  "+FloatToStrF(TekSummaCheck,ffCurrency,10,2);
                 FormGl->LabelSummaCheck->Caption="�����:  "+FloatToStrF(TekSummaCheck,ffCurrency,10,2);
                 FormGl->LabelSostCheck->Font->Color=clRed;
                 FormGl->LabelSostCheck->Caption="��� ������";
                FormGl->LabelSoobshenie->Font->Color=clBlue;
                FormGl->LabelSoobshenie->Caption=StrokaMemo;

                glSaveProtocol(StrokaMemo);
                FormGl->RE->Lines->Add(StrokaMemo);
                } break;

        case amc->DobavleniePokupkiEvent:  //���������� ������� � ���
                {
                StrokaMemo="���������� �������!";

                if ( amc->CheckOperation==amc->Prod )
                        {
                        StrokaMemo=StrokaMemo+" ������� ";
                        FormGl->LabelOperation->Caption="�������";
                        }
                        else
                        {
                        if ( amc->CheckOperation==amc->Vosvrat )
                                {
                                StrokaMemo=StrokaMemo+" ������� ";
                                FormGl->LabelOperation->Caption="�������";
                                }
                        else
                                {
                         StrokaMemo=StrokaMemo+" ����������� �������� ";
                                }
                         }
                StrokaMemo=StrokaMemo+" ����� ����: "+IntToStr(amc->NumberCheck);
                StrokaMemo=StrokaMemo+" ����� �������: "+IntToStr(amc->NumberPokupki);
                StrokaMemo=StrokaMemo+" �����: "+IntToStr(amc->Otdel);
                StrokaMemo=StrokaMemo+" ����� �������: "+FloatToStr(amc->SummaPokupki);

                if (NewCheck==true)
                        {//������� ������� ����
                        FormGl->LabelProcent->Caption="";
                        FormGl->LabelSummaNach->Caption="";
                        FormGl->LabelItog->Caption="����: ";

                        }


                FormGl->LabelNumberCheck->Caption="������� ��� �"+IntToStr(amc->NumberCheck );
                FormGl->LabelItog->Caption="����:  "+FloatToStrF(TekSummaCheck,ffCurrency,10,2);
                FormGl->LabelSummaCheck->Caption="�����:  "+FloatToStrF(TekSummaCheck,ffCurrency,10,2);
                FormGl->LabelSostCheck->Font->Color=clRed;
                FormGl->LabelSostCheck->Caption="��� ������";
                FormGl->LabelSoobshenie->Font->Color=clBlue;
                FormGl->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                FormGl->RE->Lines->Add(StrokaMemo);
                } break;
        case amc->ZakrChekaEvent:       //�������� ����
                {
                StrokaMemo="�������� ����!";
                if ( amc->CheckOperation==amc->Prod )
                        {
                        StrokaMemo=StrokaMemo+" ������� ";
                        }
                        else
                        {
                        if ( amc->CheckOperation==amc->Vosvrat )
                                {
                                StrokaMemo=StrokaMemo+" ������� ";
                                }
                        else
                                {
                         StrokaMemo=StrokaMemo+" ����������� �������� ";
                                }
                         }

                StrokaMemo=StrokaMemo+" � ����: "+IntToStr(amc->NumberCheck);
                StrokaMemo=StrokaMemo+" � ��: "+IntToStr(amc->NumberKl);

               StrokaMemo=StrokaMemo+" ���: ";
               if ( amc->Oplata==amc->Nal )
                        {
                        StrokaMemo=StrokaMemo+"���.";
                        }
                        else
                        {
                        if ( amc->Oplata==amc->BesNal )
                                {
                                StrokaMemo=StrokaMemo+"������.";
                                }
                        else
                                {
                         StrokaMemo=StrokaMemo+" ����������� ������";
                                }
                         }

               StrokaMemo=StrokaMemo+" �����: " ;
               if ( amc->Nachislenie==amc->No )
                        {
                        StrokaMemo=StrokaMemo+"���";
                        FormGl->LabelProcent->Caption="";
                        FormGl->LabelSummaNach->Caption="";
                        }
               if ( amc->Nachislenie==amc->Nadbavka )
                        {
                        StrokaMemo=StrokaMemo+"��������";
                        FormGl->LabelProcent->Caption="+ "+IntToStr(amc->Procent)+"%";
                        FormGl->LabelSummaNach->Caption="��������:  "+FloatToStrF( amc->RealSummaCheck-amc->SummaCheck ,ffCurrency,10,2);

                        }
               if ( amc->Nachislenie==amc->Skidka )
                        {
                        StrokaMemo=StrokaMemo+"������";
                        FormGl->LabelProcent->Caption="- "+IntToStr(amc->Procent)+"%";
                        FormGl->LabelSummaNach->Caption="������:  "+FloatToStrF( amc->SummaCheck-amc->RealSummaCheck,ffCurrency,10,2 );
                        }
                StrokaMemo=StrokaMemo+" %: "+IntToStr(amc->Procent);
                StrokaMemo=StrokaMemo+" ���. ���.: "+IntToStr(amc->KolPokupok);
                StrokaMemo=StrokaMemo+" ��� ������: "+FloatToStr(amc->SummaCheck);
                StrokaMemo=StrokaMemo+" � �����: "+FloatToStr(amc->RealSummaCheck);

                FormGl->LabelSostCheck->Font->Color=clGreen;
                FormGl->LabelSostCheck->Caption="��� ������";
                FormGl->LabelNumberKl->Caption=" �����. ����� �"+IntToStr(amc->NumberKl);
                FormGl->LabelItog->Caption="����:  "+FloatToStrF(amc->RealSummaCheck,ffCurrency,10,2);
                FormGl->LabelSummaCheck->Caption="�����:  "+FloatToStrF(amc->SummaCheck,ffCurrency,10,2);

                FormGl->LabelSoobshenie->Font->Color=clBlue;
                FormGl->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                FormGl->RE->Lines->Add(StrokaMemo);
                glSaveProtocol(" ");
                FormGl->RE->Lines->Add("   ");

                } break;
        case amc->SbrosChekaEvent:     //����� ����
                {
                StrokaMemo="����� ����!";
                FormGl->LabelSostCheck->Font->Color=clGreen;
                FormGl->LabelSostCheck->Caption="��� �������";
                FormGl->LabelItog->Caption="����:  ";
                FormGl->LabelSummaCheck->Caption="�����:  ";
                FormGl->LabelSoobshenie->Font->Color=clBlue;
                FormGl->LabelSoobshenie->Caption=StrokaMemo;
                glSaveProtocol(StrokaMemo);
                FormGl->RE->Lines->Add(StrokaMemo);
                glSaveProtocol(" ");
                FormGl->RE->Lines->Add("   ");

                } break;
        default :
                {

                } break;
        }

}
//----------------------------------------------------------------------------
//���������� ������ ���
void  __fastcall TFormGl::ObrabotatZaprosKKM()
{

switch (amc->EventKKM)
        {

        case amc->ConnectEvent :
                {

                } break;
        case amc->DisconnectEvent :
                {


                } break;
        case amc->PaketOtKKMEvent :
                {

                } break;
        case amc->ErrorConnectEvent:
                {

                } break;
        case amc->ErrorObmenEvent:
                {

                } break;
        case amc->ZaprosPoCoduEvent:
				{
				Price=0;
                //������� ��������� ������
                StrokaMemo="�����: ";
                if (Nom->FindPoCodu(amc->CodeTovar)>0)   //���� ����� �� ����
                        {
						Ed->OpenElement(Nom->ElementIDBASEDNOM->AsInt64);
                        amc->NameTovar=Nom->ElementNAMENOM->AsString;
						StrokaMemo=StrokaMemo+Nom->ElementNAMENOM->AsString;

						Price=0;
						Price=DMSprPrice->GetValuePrice(glARM->ElementIDTPRICEPOD->AsInt64, //��� ���
														Nom->ElementIDNOM->AsInt64,         //������������
														Nom->ElementIDBASEDNOM->AsInt64,    //�������
														1,                                 //�� �������
														Nom->ElementIDBASEDNOM->AsInt64) ; //������� �������

						if ( Price > 0.001)
								{
								amc->PriceTovar=Price;
								StrokaMemo=StrokaMemo+" ����: "+FloatToStr(Price);
                                               amc->EnableOtvet=true;
                                }
                        else
                                {
                                amc->EnableOtvet=false;
                                StrokaMemo=StrokaMemo+" �� ������� ����! �� ��������!" ;
                                }
                        }
                else    //�� ����� ����� �� ����, ���� �������;
                        {
                        String shcode=FloatToStr(amc->CodeTovar);
                        shcode=AddEAN13(shcode);
                        if (Ed->FindEdPoSh(shcode)>0)
                                {
								if (Nom->OpenElement(Ed->ElementIDNOMED->AsInt64)>0)
                                        {
                                        amc->NameTovar=Nom->ElementNAMENOM->AsString;
										StrokaMemo=StrokaMemo+Nom->ElementNAMENOM->AsString;

												Price=0;
												Price=DMSprPrice->GetValuePrice(glARM->ElementIDTPRICEPOD->AsInt64, //��� ���
														Nom->ElementIDNOM->AsInt64,         //������������
														Ed->ElementIDED->AsInt64,    //�������
														Ed->ElementKFED->AsFloat,                                 //�� �������
														Nom->ElementIDBASEDNOM->AsInt64) ; //������� �������

										if ( Price > 0.001)
												{
												amc->PriceTovar=Price;
                                                StrokaMemo=StrokaMemo+" ����: "+FloatToStr(Price)
                                                          +" ��  "+Ed->ElementNAMEED->AsString+" (��: "+Ed->ElementKFED->AsString+")";
                                                amc->EnableOtvet=true;
                                                }
                                        else
                                                {
                                                amc->EnableOtvet=false;
                                                StrokaMemo=StrokaMemo+" �� ������� ����! �� ��������!" ;
                                                }
                                        }
                                }
                        else   //�� ����� �������
                                {
                                amc->EnableOtvet=false;
                                StrokaMemo=StrokaMemo+" �� ������ �����! �� ��������!";
                                }
                        }

                FormGl->RE->Lines->Add(StrokaMemo);
                glSaveProtocol(StrokaMemo);
                } break;
        case amc->ZaprosPoCoduKolEvent:
				{
				Price=0;
                 //������� ��������� ������
                int KolNom=Nom->FindPoCodu(amc->CodeTovar);
                StrokaMemo="�����: ";
                if (KolNom==1)
                        {
                        amc->NameTovar=Nom->ElementNAMENOM->AsString;
						StrokaMemo=StrokaMemo+Nom->ElementNAMENOM->AsString;

						Price=0;
						Price=DMSprPrice->GetValuePrice(glARM->ElementIDTPRICEPOD->AsInt64, //��� ���
														Nom->ElementIDNOM->AsInt64,         //������������
														Nom->ElementIDBASEDNOM->AsInt64,    //�������
														1,                                 //�� �������
														Nom->ElementIDBASEDNOM->AsInt64) ; //������� �������

						if ( Price > 0.001)
								{
								amc->PriceTovar=Price;
                                StrokaMemo=StrokaMemo+" ����: "+FloatToStr(Price);
                                amc->EnableOtvet=true;
                                }
                        else
                                {
                                amc->EnableOtvet=false;
                                StrokaMemo=StrokaMemo+" �� ������� ����! �� ��������!" ;
                                }
                        }
                else
                        {
                        amc->EnableOtvet=false;
                        StrokaMemo=StrokaMemo+" �� ������ �����! �� ��������!";
                        }
                FormGl->RE->Lines->Add(StrokaMemo);
                glSaveProtocol(StrokaMemo);
                } break;

        case amc->DobavlenieSvobSummEvent:  //���������� ��������� ����� � ���
				{
				Price=0;
                if (NewCheck==true)
                        {
                        //Check->IBTr->Rollback();
                        //Check->IBTr->StartTransaction();
                        //Check->DocAll->Active=true;
                        //Check->Doc->Active=true;
                        //Check->DocT->Active=true;
                        Check->OpenDoc(0);
                        Check->NewDoc();
                        Check->DocAll->Edit();
						Check->DocAllIDFIRMDOC->AsInt64=glARM->ElementIDFIRM_SARM->AsInt64;
						Check->DocAllIDSKLDOC->AsInt64=glARM->ElementIDSKLAD_SARM->AsInt64;
                        Check->DocAll->Post();
                        Check->Doc->Edit();

                        if (amc->CheckOperation==amc->Prod)
                                {
                                Check->DocOPERCHK->AsInteger=0;
                                }

                        if (amc->CheckOperation==amc->Vosvrat)
                                {
                                Check->DocOPERCHK->AsInteger=1;
                                }

						Check->DocIDKKMCHK->AsInt64=glARM->ElementIDKKM_SARM->AsInt64;
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
                        Check->DocTKOLCHKT->AsFloat=amc->KolTovar;
                        Check->DocTKFCHKT->AsFloat=1;
                        Check->DocTPRICECHKT->AsFloat=amc->PriceTovar;
                        Check->DocTSUMCHKT->AsFloat=amc->SummaPokupki;
                        Check->DocT->Post();
                        }
                else
                        {
                        FormGl->RE->Lines->Add("�� ������ ����� � ����� ��������� ����� (1)! ");
                        glSaveProtocol("�� ������ ����� � ����� ��������� ����� (1)! ");
                        }
                TekSummaCheck=TekSummaCheck+amc->SummaPokupki;

                } break;


        case amc->DobavleniePokupkiEvent:
                {
                if (NewCheck==true)
                        {
                        //Check->IBTr->Rollback();
                        //Check->IBTr->StartTransaction();
                        //Check->DocAll->Active=true;
                        //Check->Doc->Active=true;
                       // Check->DocT->Active=true;
                        Check->OpenDoc(0);
                        Check->NewDoc();
                        Check->DocAll->Edit();
						Check->DocAllIDFIRMDOC->AsInt64=glARM->ElementIDFIRM_SARM->AsInt64;
                        Check->DocAllIDSKLDOC->AsInteger=glARM->ElementIDSKLAD_SARM->AsInteger;
                        Check->DocAll->Post();
                        Check->Doc->Edit();
						Check->DocIDKKMCHK->AsInt64=glARM->ElementIDKKM_SARM->AsInt64;
						Check->DocIDTPRICE->AsInt64=glARM->ElementIDTPRICEPOD->AsInt64;
                        if (amc->CheckOperation==amc->Prod)
                                {
                                Check->DocOPERCHK->AsInteger=0;
                                }

                        if (amc->CheckOperation==amc->Vosvrat)
                                {
                                Check->DocOPERCHK->AsInteger=1;
                                }
                                
                        Check->Doc->Post();
                        NewCheck=false;
                        TekSummaCheck=0;
                        }
                Check->AddDocNewString();
                Check->DocT->Edit();
				Check->DocTIDNOMCHKT->AsInt64=Nom->ElementIDNOM->AsInt64;
                Check->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
                Check->DocTIDEDCHKT->AsInt64=Ed->ElementIDED->AsInt64;
                Check->DocTNAMEED->AsString=Ed->ElementNAMEED->AsString;
                Check->DocTKOLCHKT->AsFloat=amc->KolTovar;
                Check->DocTKFCHKT->AsFloat=Ed->ElementKFED->AsFloat;
                Check->DocTPRICECHKT->AsFloat=amc->PriceTovar;
                Check->DocTSUMCHKT->AsFloat=amc->SummaPokupki;
                Check->DocT->Post();
                TekSummaCheck=TekSummaCheck+amc->SummaPokupki;

                } break;
        case amc->ZakrChekaEvent:
                {
                Check->Doc->Edit();
                Check->DocNCHECKCHK->AsInteger=amc->NumberCheck;
                Check->DocNKLCHK->AsInteger=amc->NumberKl;
                Check->Doc->Post();
                if (amc->Nachislenie!=amc->No)
                        {
                        RaspredNachislenie();
                        }
                TekSummaCheck=amc->RealSummaCheck;
                if (Check->SaveDoc()==true)
                        {
                        if(Check->DvRegDoc()==false)
                                {
                                FormGl->RE->Lines->Add("�� ������� �������� ���!");
                                glSaveProtocol("�� ������� �������� ���!");
                                }
                        }
                else
                        {
                        FormGl->RE->Lines->Add("�� ������� �������� ���!");
                         glSaveProtocol("�� ������� �������� ���!");

                        }
                NewCheck=true;

                } break;
        case amc->SbrosChekaEvent:
                {
                 Check->DocT->CancelUpdates();
                 Check->Doc->CancelUpdates();
                 Check->DocAll->CancelUpdates();
                 Check->IBTr->Commit();

                NewCheck=true;
                } break;
        default :
                {

                } break;
        }
}

//----------------------------------------------------------------------------
void __fastcall TFormGl::ObrabExternalEvent()
{

ObrabotatZaprosKKM();
UpdateForm();
}
//----------------------------------------------------------------------------
void TFormGl::RaspredNachislenie(void)
{
double Skidka=0;
double Nadbavka=0;

if (amc->Nachislenie==amc->Skidka)
        {
        Skidka=amc->SummaCheck-amc->RealSummaCheck;
        }
if(amc->Nachislenie==amc->Nadbavka)
        {
        Nadbavka=amc->RealSummaCheck-amc->SummaCheck;
        }

if (amc->Nachislenie!=amc->No )
        {
        int Kol=0;
        Check->DocT->First();
        while(!Check->DocT->Eof)
                {
                Check->DocT->Edit();
                if (amc->Nachislenie==amc->Skidka)
                        {
                        if (Kol==Check->DocT->RecordCount-1)
                                {
                                Check->DocTSKCHKT->AsFloat=Skidka;
                                }
                        else
                                {
                                Check->DocTSKCHKT->AsFloat=Check->DocTSUMCHKT->AsFloat*(amc->Procent)/100;
                                Skidka=Skidka-Check->DocTSKCHKT->AsFloat;
                                }
                        Check->DocTSUMCHKT->AsFloat=Check->DocTSUMCHKT->AsFloat-Check->DocTSKCHKT->AsFloat;

                        }

                if (amc->Nachislenie==amc->Nadbavka)
                        {
                        if (Kol==Check->DocT->RecordCount-1)
                                {
                                Check->DocTNADCHKT->AsFloat=Nadbavka;
                                }
                        else
                                {
                                Check->DocTNADCHKT->AsFloat=Check->DocTSUMCHKT->AsFloat*(amc->Procent)/100;
                                Nadbavka=Nadbavka-Check->DocTNADCHKT->AsFloat;
                                }
                        Check->DocTSUMCHKT->AsFloat=Check->DocTSUMCHKT->AsFloat+Check->DocTNADCHKT->AsFloat;

                        }


                Check->DocT->Post();
                Kol=Kol+1;
                Check->DocT->Next();
                }
        }
}
//-----------------------------------------------------------------------------




void __fastcall TFormGl::OpenAboutClick(TObject *Sender)
{
TFormAbout * form=new TFormAbout(Application);
if (!form) return;
//��������� �����
form->NameProgramLabel->Caption="�������� ������ ���-100�";
form->VerProgLabel->Caption="������ ���������: "+ProgramVersion;
form->VerBaseLabel->Caption="������ ����: "+BaseVersion;
//������� ������ �����
form->VerFileLabel->Caption="������ �����: "+GetVersionProgramFile();
//��������������� �����
form->RegNumberLabel->Caption="��������������� �����: "+IntToStr(glRegNumber)
	+" ("+IntToHex(glRegNumber, 8)+")";
//TDMSetup * DMSetup=new TDMSetup(Application);
//DMSetup->OpenElement(15);
form->GrPosledLabel->Caption="";//"������� ������������������: "
//				+DMSetup->ElementVALUE_SETUP->AsString;
//delete DMSetup;
if (glDemo==true)
	{
	form->DemoLabel->Visible=true;
	}
else
	{
	form->DemoLabel->Visible=false;
	}
form->UpdateForm();
form->ShowModal();
}
//---------------------------------------------------------------------------

