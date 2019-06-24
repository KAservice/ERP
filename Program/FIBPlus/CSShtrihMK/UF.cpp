//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UF.h"
#include "UCS.h"
#include "UDM.h"
#include "UDMDocCheck.h"
#include "UDMSprNom.h"
#include "UDMSprFirm.h"
#include "UDMSprEd.h"
#include "UDMSprARM.h"
#include "UDMSOborud.h"
#include "UDMSprSklad.h"
#include "UDMSprPrice.h"
#include "UDMSprUser.h"
#include "UZapusk.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TF *F;
TCS *CS;
TDMDocCheck *Check;
TDMSprNom *Nom;
TDMSprEd * Ed;
TDMSprPrice * DMSprPrice;
extern TDMSprUser * glUser;
extern String ComandString;
void glSaveProtocol(String str);
String AddEAN13(String Cod) ;
bool zapusk;

TDMSprARM *glARM;
int glNumberARM;

AnsiString BaseVersion;
AnsiString ProgramVersion;
//---------------------------------------------------------------------------
__fastcall TF::TF(TComponent* Owner)
        : TForm(Owner)
{

}
//----------------------------------------------------------------------------
void __fastcall TF::FormCreate(TObject *Sender)
{

LabelSostCheck->Caption="";
LabelProcent->Caption="";
LabelSummaNach->Caption="";


CS=new TCS(true); //�������� �����
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

zapusk=false;
NewCheck=true; 
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TF::FormShow(TObject *Sender)
{
if (zapusk==true) return;
AnsiString connect_string="";
AnsiString set_number="";
AnsiString password_user="";
AnsiString name_user="";
int Kol=0;
//ShowMessage(ComandString);
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
                //ShowMessage("������ �����������:"+ConnectStr);
                //ShowMessage("������� �����:"+SetNumber);

                DM->ConnectString=connect_string;
                DM->PasswordUser="masterkey";
                DM->NameUser="SYSDBA";

                if(DM->GlobConnect()==true)
                        {
                        if (glUser->FindPoName(name_user)==1)
                                {
                                if (glUser->ElementPASSWORD_USER->AsString==password_user)
                                        {
                                        if (glUser->ElementINTERF_USER->AsInteger==5)
                                                {
                                                StatusBar->Panels->Items[0]->Text=glUser->ElementNAME_USER->AsString;
                                                StatusBar->Panels->Items[1]->Text=DM->ConnectString;

                                                Visible=true;
                                                glNumberARM=StrToInt(set_number);
                                                if (glARM->FindPoCodu(glNumberARM)==0)
                                                        {
                                                        ShowMessage ("�� ������� ��������� �������� �����!");
                                                        }
                                                //���������� ����������
                                                ConnectDevice();
                                                }
                                        else
                                                {
                                                OpenFormViborBase();
                                                }
                                        }
                                else
                                        {
                                        ShowMessage("�������� ������!");
                                        OpenFormViborBase();
                                        }
                                }
                        else
                                {
                                ShowMessage("������������ ��� ������������!");
                                OpenFormViborBase();
                                }

                        }
                else
                        {
                        ShowMessage("�� ������� ������������ � ���� ������!");
                        OpenFormViborBase();
                        }
                }
        catch (...)
                {
                ShowMessage("������ ��� �������� ���������� �� ��������� ������!");
                OpenFormViborBase();
                }

       }
else
        {
        OpenFormViborBase();
        }
}
//---------------------------------------------------------------------------
void TF::OpenFormViborBase(void)
{
FormaViborBase=new TFormaViborBase(Application);
FormaViborBase->FOnCloseForm=EndViborBase;
FormaViborBase->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TF::EndViborBase(TObject *Sender)
{

if (FormaViborBase->OutReady==true)
        {
        DM->ConnectString=FormaViborBase->ConnectString;;
        DM->PasswordUser="masterkey";  //Password->Text;
        DM->NameUser="SYSDBA";  //;

        if(DM->GlobConnect()==true)
                {
                if (glUser->FindPoName(FormaViborBase->NameUser)==1)
                        {
                        if (glUser->ElementPASSWORD_USER->AsString==FormaViborBase->PasswordUser)
                                {
                                if (glUser->ElementINTERF_USER->AsInteger==5)
                                        {
                                        Visible=true;
                                        glNumberARM=FormaViborBase->NumberARM;
                                        glARM->FindPoCodu(glNumberARM);
                                        ConnectDevice();

                                        StatusBar->Panels->Items[0]->Text=FormaViborBase->NameUser;
                                        StatusBar->Panels->Items[1]->Text=DM->ConnectString;

                                       // StatusBar->Panels->Items[1]->Text=gl_prefiks_ib;
                                       // StatusBar->Panels->Items[3]->Text=BaseVersion;
                                       // StatusBar->Panels->Items[4]->Text=ProgramVersion;
                                        FormaViborBase->CloseForm=true;
                                        }
                                else
                                        {
                                        ShowMessage("������������ ��� ������������ ��� ������!");
                                        FormaViborBase->CloseForm=false;
                                        glSaveProtocol("������������ ��� ������������ ��� ������!");
                                        }

                                }
                         else
                                {
                                ShowMessage("������������ ��� ������������ ��� ������!");
                                FormaViborBase->CloseForm=false;
                                glSaveProtocol("������������ ��� ������������ ��� ������!");
                                }
                        }
                else
                        {
                        ShowMessage("������������ ��� ������������ ��� ������!");
                        FormaViborBase->CloseForm=false;
                        glSaveProtocol("������������ ��� ������������ ��� ������!");
                        }
                }
        else
                {
                ShowMessage("����������� ����� ���� � ���� ������!");
                FormaViborBase->CloseForm=false;
                glSaveProtocol("����������� ����� ���� � ���� ������!");
                }
        }
else
        {
        //��������� ���������
        Close();

        }
}
//---------------------------------------------------------------------------
void TF::ConnectDevice(void)
{
TDMSprARM * DMSprARM=new TDMSprARM(Application);
if(DMSprARM->FindPoCodu(glNumberARM)==0)
        {
        delete DMSprARM;
        return;
        }

TDMSprOborud * DMSprOborud=new TDMSprOborud(Application);
DMSprOborud->OpenTable(DMSprARM->ElementID_SARM->AsInteger);

DMSprOborud->Table->First();
while(!DMSprOborud->Table->Eof)
        {
        if (Trim(DMSprOborud->TableTYPE_OBORUD->AsString)=="kkm")
                {
                //��������� ��� � ������ ON-Line
                CS->NamePort="COM"+DMSprOborud->TableCOMNAME_OBORUD->AsString;
                CS->OpenPort();
                CS->Resume();
                zapusk=true;
                break;
                }
        DMSprOborud->Table->Next();
        }

delete DMSprOborud;
delete DMSprARM;

}
//---------------------------------------------------------------------------

void __fastcall TF::FormClose(TObject *Sender, TCloseAction &Action)
{
CS->ClosePort();
CS->Terminate();

delete Ed;
delete Nom;
delete Check;
delete glARM;
delete DM;
}
//---------------------------------------------------------------------------
bool TF::ObrabExternalEvent(void)
{
bool Res=false;
///
switch (CS->ExternalEvent)
{

        case CS->SvobProdEvent :
                {
                FSvobProd();

                } break;

        case CS->ProdPoCoduEvent :
                {
                FProdPoKodu();

                }break;
        case CS->SvobOplataEvent :
                {
                FSvobOplata();

                }break;
        case CS->SakrCheckEvent:
                {
                FSakrCheck();
                }break;
        case CS->AnnCheckEvent :
                {
                FAnnCheck();
                }break;
        case CS->PodtverEvent :
                {
                FPodtver();
                }break;
        default :
                {
                RE->Lines->Add("����������� ������� �� ���!");
                } break;
}


return Res;
}
//-----------------------------------------------------------------------------
void TF::FSvobProd(void)
{

String Stroka="������! �������� �� ��������� ����! ";
if (CS->TypeOperation==CS->Prod){Stroka=Stroka+" �������. ";}
if (CS->TypeOperation==CS->Pokupka){Stroka=Stroka+" �������. ";}
if (CS->TypeOperation==CS->VosvratProd){Stroka=Stroka+" ������� �������. ";}
if (CS->TypeOperation==CS->VosvratPokupki){Stroka=Stroka+" ������� �������. ";}

if (CS->Operation==CS->Oper){Stroka=Stroka+" ���������� ��������. ";}
if (CS->Operation==CS->Storno){Stroka=Stroka+" ������ ��������. ";}

Stroka=Stroka+" ���������� - "+FloatToStr(CS->Kol);
Stroka=Stroka+" ���� - "+FloatToStr(CS->Price);
Stroka=Stroka+" ����� - "+FloatToStr(CS->Otdel);
Stroka=Stroka+" �������� - "+FloatToStr(CS->NumberOperator);
RE->Lines->Add(Stroka);
LabelSoobshenie->Caption=Stroka;

if (NewCheck==true)
        {
        LabelSostCheck->Caption="��� ������!";
        Check->NewDoc();
        Check->OpenDoc(0);
        
        Check->DocAll->Edit();
        Check->DocAllIDFIRMDOC->AsInteger=glARM->ElementIDFIRM_SARM->AsInteger;
        Check->DocAllIDSKLDOC->AsInteger=glARM->ElementIDSKLAD_SARM->AsInteger;
        Check->DocAll->Post();

        Check->Doc->Edit();
        Check->DocIDKKMCHK->AsInteger=glARM->ElementIDKKM_SARM->AsInteger;
        Check->Doc->Post();

        NewCheck=false;
        }
Check->AddDocNewString();
Nom->FindPoCodu(1);

Check->DocT->Edit();
Check->DocTIDNOMCHKT->AsInteger=Nom->ElementIDNOM->AsInteger;
Check->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
Check->DocTIDEDCHKT->AsInteger=Nom->BasEdIDED->AsInteger;
Check->DocTNAMEED->AsString=Nom->BasEdNAMEED->AsString;
Check->DocTKOLCHKT->AsFloat=CS->Kol;
Check->DocTKFCHKT->AsFloat=1;
Check->DocTPRICECHKT->AsFloat=CS->Price;
Check->DocTSUMCHKT->AsFloat=CS->Kol*CS->Price;
Check->DocT->Post();


}
//-----------------------------------------------------------------------------
void TF::FProdPoKodu(void)
{
String Stroka="������! ������� �� ����!";

if (CS->TypeOperation==CS->Prod){Stroka=Stroka+" �������. ";}
if (CS->TypeOperation==CS->Pokupka){Stroka=Stroka+" �������. ";}
if (CS->TypeOperation==CS->VosvratProd){Stroka=Stroka+" ������� �������. ";}
if (CS->TypeOperation==CS->VosvratPokupki){Stroka=Stroka+" ������� �������. ";}

if (CS->Operation==CS->Oper){Stroka=Stroka+" ���������� ��������. ";}
if (CS->Operation==CS->Storno){Stroka=Stroka+" ������ ��������. ";}

Stroka=Stroka+" ���������� - "+FloatToStr(CS->Kol);
Stroka=Stroka+" ��� - "+IntToStr(CS->Code);
Stroka=Stroka+" �������� - "+FloatToStr(CS->NumberOperator);
RE->Lines->Add(Stroka);
LabelSoobshenie->Caption=Stroka;

if(Nom->FindPoCodu(CS->Code)==true)
        {

        Ed->OpenElement(Nom->ElementIDBASEDNOM->AsInteger);
        CS->Name=Nom->ElementNAMENOM->AsString;
        if (DMSprPrice->FindElement(glARM->ElementIDTPRICEPOD->AsInteger,Nom->ElementIDNOM->AsInteger )>0)
                {
                CS->Price=DMSprPrice->ElementZNACH_PRICE->AsFloat;
                }
        else
                {
                CS->Price=0;
                CS->Name="����� �� ������!";
                }
        }
else
        {

        String shcode=FloatToStr(CS->Code);
        shcode=AddEAN13(shcode);
        if (Ed->FindEdPoSh(shcode)>0)
                {
                if (Nom->OpenElement(Ed->ElementIDNOMED->AsInteger)>0)
                        {
                        CS->Name=Nom->ElementNAMENOM->AsString;

                        if (DMSprPrice->FindElement(glARM->ElementIDTPRICEPOD->AsInteger,Nom->ElementIDNOM->AsInteger )>0)
                                {
                                CS->Price=DMSprPrice->ElementZNACH_PRICE->AsFloat*Ed->ElementKFED->AsFloat;

                                }
                        else
                                {
                                CS->Price=0;
                                CS->Name="����� �� ������!";
                                }
                        }
                                }
                else   //�� ����� �������
                        {
                        CS->Price=0;
                        CS->Name="����� �� ������!";
                        }

        }

CS->Otdel=1;


if (NewCheck==true)
        {
        LabelSostCheck->Caption="��� ������!";
        Check->OpenDoc(0);
        Check->NewDoc();

        Check->DocAll->Edit();
        Check->DocAllIDFIRMDOC->AsInteger=glARM->ElementIDFIRM_SARM->AsInteger;
        Check->DocAllIDSKLDOC->AsInteger=glARM->ElementIDSKLAD_SARM->AsInteger;
        Check->DocAll->Post();

        Check->Doc->Edit();
        Check->DocIDKKMCHK->AsInteger=glARM->ElementIDKKM_SARM->AsInteger;
        Check->Doc->Post();
        
        NewCheck=false;
        }
Check->AddDocNewString();

Check->DocT->Edit();
Check->DocTIDNOMCHKT->AsInteger=Nom->ElementIDNOM->AsInteger;
Check->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
Check->DocTIDEDCHKT->AsInteger=Nom->BasEdIDED->AsInteger;
Check->DocTNAMEED->AsString=Nom->BasEdNAMEED->AsString;
Check->DocTKOLCHKT->AsFloat=CS->Kol;
Check->DocTKFCHKT->AsFloat=1;
Check->DocTPRICECHKT->AsFloat=CS->Price;
Check->DocTSUMCHKT->AsFloat=CS->Kol*CS->Price;
Check->DocT->Post();


Stroka="�����! ";
Stroka=Stroka+" "+CS->Name;
Stroka=Stroka+" ����:"+FloatToStr(CS->Price);
Stroka=Stroka+" �����: 1";
RE->Lines->Add(Stroka);
}
//-----------------------------------------------------------------------------
void TF::FSvobOplata(void)
{
String Stroka="������! ��������� ������! ";
if (CS->TypeOplat==CS->Nal){Stroka=Stroka+" ���������. ";}
if (CS->TypeOplat==CS->Opl2){Stroka=Stroka+" ������ 2. ";}
if (CS->TypeOplat==CS->Opl3){Stroka=Stroka+" ������ 3. ";}

if (CS->TypeOperation==CS->Prod){Stroka=Stroka+" �������. ";}
if (CS->TypeOperation==CS->Pokupka){Stroka=Stroka+" �������. ";}
if (CS->TypeOperation==CS->VosvratProd){Stroka=Stroka+" ������� �������. ";}
if (CS->TypeOperation==CS->VosvratPokupki){Stroka=Stroka+" ������� �������. ";}

if (CS->Operation==CS->Oper){Stroka=Stroka+" ���������� ��������. ";}
if (CS->Operation==CS->Storno){Stroka=Stroka+" ������ ��������. ";}

Stroka=Stroka+" ����� - "+FloatToStr(CS->SummaOplat);
Stroka=Stroka+" �������� - "+FloatToStr(CS->NumberOperator);
RE->Lines->Add(Stroka);
LabelSoobshenie->Caption=Stroka;
}
//-----------------------------------------------------------------------------
void TF::FSakrCheck(void)
{
String Stroka="�������� ����: ";
Stroka=Stroka+" �������� - "+FloatToStr(CS->NumberOperator);

if (CS->TypeOperation==CS->Prod){Stroka=Stroka+" �������. ";}
if (CS->TypeOperation==CS->Pokupka){Stroka=Stroka+" �������. ";}
if (CS->TypeOperation==CS->VosvratProd){Stroka=Stroka+" ������� �������. ";}
if (CS->TypeOperation==CS->VosvratPokupki){Stroka=Stroka+" ������� �������. ";}

Stroka=Stroka+" ����: "+DateToStr(CS->DateCheck);
Stroka=Stroka+" �����: "+TimeToStr(CS->TimeCheck);
Stroka=Stroka+" ����� ��������� - "+IntToStr(CS->NumberDoc);
Stroka=Stroka+" ����� ����- "+IntToStr(CS->NumberCheck);
RE->Lines->Add(Stroka);
LabelSoobshenie->Caption=Stroka;

Check->Doc->Edit();
Check->DocNCHECKCHK->AsInteger=CS->NumberCheck;
Check->Doc->Post();
LabelSostCheck->Caption="��� ������!";
                if (Check->SaveDoc()==true)
                        {
                        if(Check->DvRegDoc()==false)
                                {
                                RE->Lines->Add("�� ������� �������� ���!");
                                }
                        }
                else
                        {
                        RE->Lines->Add("�� ������� �������� ���!");

                        }
                NewCheck=true;







}
//-----------------------------------------------------------------------------
void TF::FAnnCheck(void)
{
String Stroka="������������� ����! ";
Stroka=Stroka+" �������� - "+FloatToStr(CS->NumberOperator);

if (CS->TypeOperation==CS->Prod){Stroka=Stroka+" �������. ";}
if (CS->TypeOperation==CS->Pokupka){Stroka=Stroka+" �������. ";}
if (CS->TypeOperation==CS->VosvratProd){Stroka=Stroka+" ������� �������. ";}
if (CS->TypeOperation==CS->VosvratPokupki){Stroka=Stroka+" ������� �������. ";}

Stroka=Stroka+" ����: "+DateToStr(CS->DateCheck);
Stroka=Stroka+" �����: "+TimeToStr(CS->TimeCheck);

Stroka=Stroka+" ����� ��������� - "+IntToStr(CS->NumberDoc);
Stroka=Stroka+" ����� ����- "+IntToStr(CS->NumberCheck);
RE->Lines->Add(Stroka);
LabelSoobshenie->Caption=Stroka;

LabelSostCheck->Caption="��� �����������!";
Check->CloseDoc();
NewCheck=true;


}
//-----------------------------------------------------------------------------
void TF::FPodtver(void)
{
String Stroka="������������� ��������! ";
RE->Lines->Add(Stroka);
LabelSoobshenie->Caption=Stroka;
}
//-----------------------------------------------------------------------------



