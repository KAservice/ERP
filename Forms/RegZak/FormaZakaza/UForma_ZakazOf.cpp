//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "UForma_ZakazOf.h"
#include "UDMSprNom.h"
#include "UDMSprKKM.h"
#include "UDMSprUser.h"
#include "UFiskReg.h"
#include "UDMSFirm.h"
#include "UDMSMPrig.h"
#include "UDMSprStrObject.h"
#include "UDMSprARM.h" 
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

extern TDMSprARM *glARM;
extern TDMSprUser * glUser;
extern TDMSFirm *glFirma;

//----------- фискальный регистратор -----
extern TFiskReg  *glFR;
extern bool glFRConnect;

extern void glSaveProtocol(String str);
//---------------------------------------------------------------------------
__fastcall TForma_ZakazOf::TForma_ZakazOf(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForma_ZakazOf::FormCreate(TObject *Sender)
{

DM= new TDMRegZak(Application);
Nom=new TDMSprNom(Application);
DMKlient=new TDMSprKlient(Application);
DBGrid1->DataSource=DM->DataSourceDocT;
NameStrObDBText->DataSource=DM->DataSourceDoc;
SumDoc->DataSource=DM->DataSourceDoc;
IDZakDBText->DataSource=DM->DataSourceDoc;
KrNameNomDBText->DataSource=DM->DataSourceDocT;
MPrigDBText->DataSource=DM->DataSourceDocT;
NameKlientDBText->DataSource=DM->DataSourceDoc;
NameUserDBText->DataSource=DM->DataSourceDoc;

NewElement=false;  // новый элемент
Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи
VibTovarId=0;
VibTovarIdGrp=0;
PrinterActive=false;

}
//---------------------------------------------------------------------------
void __fastcall TForma_ZakazOf::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(FOnCloseForm) FOnCloseForm(this);
delete DM;
delete Nom;
delete DMKlient;
Action=caFree;
}

//---------------------------------------------------------------------------
void __fastcall TForma_ZakazOf::EndEdit(TObject *Sender)
{


if (EditRekvisit==ViborObject)
        {
        if (FormaViborSprStrObject->OutReady==true)
               {
               DM->Doc->Edit();
               DM->DocIDOB_ZAK->AsInteger=FormaViborSprStrObject->DMGrp->ElementID_STROB->AsInteger;
               DM->DocNAME_STROB->AsString=FormaViborSprStrObject->DMGrp->ElementNAME_STROB->AsString;
               DM->Doc->Post();
               }
        }


if (EditRekvisit==InputCodeStrOb)
        {
        if (FormaInputText->OutReady==true)
               {
               TDMSprStrObject * DMSprStrObject=new TDMSprStrObject(Application);

               if (DMSprStrObject->FindPoCodu(StrToInt(FormaInputText->InputText))>0)
                        {
                        DM->Doc->Edit();
                        DM->DocIDOB_ZAK->AsInteger=DMSprStrObject->ElementID_STROB->AsInteger;
                        DM->DocNAME_STROB->AsString=DMSprStrObject->ElementNAME_STROB->AsString;
                        DM->Doc->Post();

                        }
                delete DMSprStrObject;
                }
        }



if (EditRekvisit==InputCodeBV)
        {
        if (FormaInputCode->OutReady==true)
                {
                //получим ID номенклатуры
                TDMSprBVNom * DMSprBV=new TDMSprBVNom(Application);
                DMSprBV->IdPod=glARM->ElementIDPODR_SARM->AsInteger;
                if (DMSprBV->FindPoCoduBV(FormaInputCode->Code)>0)
                        {
                        Nom->IdTypePrice=glARM->ElementIDTPRICEPOD->AsInteger;
                        DM->IdTypePrice=glARM->ElementIDTPRICEPOD->AsInteger;
                        Nom->OpenElement(DMSprBV->IdNomBV);

                        DM->AddDocNewString();

                        DM->Doc->Edit();
                        DM->DocSOST_ZAK->AsInteger=1;
                        DM->Doc->Post();

                        DM->DocT->Edit();
                        DM->DocTIDNOM_ZAKT->AsInteger=VibTovarId=Nom->ElementIDNOM->AsInteger;
                        DM->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
                        DM->DocTKRNAMENOM->AsString=Nom->ElementKRNAMENOM->AsString;
                        DM->DocTTNOM->AsInteger=Nom->ElementTNOM->AsInteger;
                        DM->DocTKOLZ_ZAKT->AsFloat=FormaInputCode->Kol;

                        DM->DocTIDED_ZAKT->AsInteger=Nom->ElementIDOSNEDNOM->AsInteger;
                        DM->DocTNAMEED->AsString=Nom->OsnEdNAMEED->AsString;
                        DM->DocTKF_ZAKT->AsFloat=Nom->OsnEdKFED->AsFloat;

                        DM->DocTZNACH_PRICE->AsFloat=Nom->ElementZNACH_PRICE->AsFloat;
                        DM->DocTPRICE_ZAKT->AsFloat=DM->DocTZNACH_PRICE->AsFloat
                                                *DM->DocTKF_ZAKT->AsFloat;

                        DM->OpenMPrig();
                        DM->DocTNAME_MPRIG->AsString=DM->IBQNomNAME_MPRIG->AsString;

                        DM->DocT->Post();
                        DBGrid1->SelectedField=DM->DocTKOLZ_ZAKT;
                        }
                else
                        {
                        ShowMessage("Товар не найден!");
                        }
                delete DMSprBV;
                }
        }

if (EditRekvisit==InputCodeNom)
        {
        if (FormaInputCode->OutReady==true)
                {
                Nom->IdTypePrice=glARM->ElementIDTPRICEPOD->AsInteger;
                if (Nom->FindPoCodu(FormaInputCode->Code)>0)
                        {
                        Nom->IdTypePrice=glARM->ElementIDTPRICEPOD->AsInteger;
                        DM->IdTypePrice=glARM->ElementIDTPRICEPOD->AsInteger;

                        DM->AddDocNewString();

                        DM->Doc->Edit();
                        DM->DocSOST_ZAK->AsInteger=1;
                        DM->Doc->Post();

                        DM->DocT->Edit();
                        DM->DocTIDNOM_ZAKT->AsInteger=VibTovarId=Nom->ElementIDNOM->AsInteger;
                        DM->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
                        DM->DocTKRNAMENOM->AsString=Nom->ElementKRNAMENOM->AsString;
                        DM->DocTTNOM->AsInteger=Nom->ElementTNOM->AsInteger;
                        DM->DocTKOLZ_ZAKT->AsFloat=FormaInputCode->Kol;

                        DM->DocTIDED_ZAKT->AsInteger=Nom->ElementIDOSNEDNOM->AsInteger;
                        DM->DocTNAMEED->AsString=Nom->OsnEdNAMEED->AsString;
                        DM->DocTKF_ZAKT->AsFloat=Nom->OsnEdKFED->AsFloat;

                        DM->DocTZNACH_PRICE->AsFloat=Nom->ElementZNACH_PRICE->AsFloat;
                        DM->DocTPRICE_ZAKT->AsFloat=DM->DocTZNACH_PRICE->AsFloat
                                                *DM->DocTKF_ZAKT->AsFloat;

                        DM->OpenMPrig();
                        DM->DocTNAME_MPRIG->AsString=DM->IBQNomNAME_MPRIG->AsString;

                        DM->DocT->Post();
                        DBGrid1->SelectedField=DM->DocTKOLZ_ZAKT;
                        }
                else
                        {
                         ShowMessage("Товар не найден!");
                        }
                }

        }

if (EditRekvisit==ViborTovarSprBV)
        {
        if (SprBV->OutReady==true)
                {
                        Nom->IdTypePrice=glARM->ElementIDTPRICEPOD->AsInteger;
                        DM->IdTypePrice=glARM->ElementIDTPRICEPOD->AsInteger;
                        Nom->OpenElement(SprBV->ViborIdNom);

                        DM->AddDocNewString();

                        DM->Doc->Edit();
                        DM->DocSOST_ZAK->AsInteger=1;
                        DM->Doc->Post();

                        DM->DocT->Edit();
                        DM->DocTIDNOM_ZAKT->AsInteger=VibTovarId=Nom->ElementIDNOM->AsInteger;
                        DM->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
                        DM->DocTKRNAMENOM->AsString=Nom->ElementKRNAMENOM->AsString;
                        DM->DocTTNOM->AsInteger=Nom->ElementTNOM->AsInteger;
                        DM->DocTKOLZ_ZAKT->AsFloat=1;

                        DM->DocTIDED_ZAKT->AsInteger=Nom->ElementIDOSNEDNOM->AsInteger;
                        DM->DocTNAMEED->AsString=Nom->OsnEdNAMEED->AsString;
                        DM->DocTKF_ZAKT->AsFloat=Nom->OsnEdKFED->AsFloat;

                        DM->DocTZNACH_PRICE->AsFloat=Nom->ElementZNACH_PRICE->AsFloat;
                        DM->DocTPRICE_ZAKT->AsFloat=DM->DocTZNACH_PRICE->AsFloat
                                                *DM->DocTKF_ZAKT->AsFloat;

                        DM->OpenMPrig();
                        DM->DocTNAME_MPRIG->AsString=DM->IBQNomNAME_MPRIG->AsString;

                        DM->DocT->Post();
                        DBGrid1->SelectedField=DM->DocTKOLZ_ZAKT;
                }

        }

if (EditRekvisit==ViborNomSpr)
        {
        if (FormaViborNomSpr->OutReady==true)
                {

                        Nom->IdTypePrice=glARM->ElementIDTPRICEPOD->AsInteger;
                        DM->IdTypePrice=glARM->ElementIDTPRICEPOD->AsInteger;
                        Nom->OpenElement(FormaViborNomSpr->DM->TableIDNOM->AsInteger);

                        DM->AddDocNewString();

                        DM->Doc->Edit();
                        DM->DocSOST_ZAK->AsInteger=1;
                        DM->Doc->Post();

                        DM->DocT->Edit();
                        DM->DocTIDNOM_ZAKT->AsInteger=VibTovarId=Nom->ElementIDNOM->AsInteger;
                        DM->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
                        DM->DocTKRNAMENOM->AsString=Nom->ElementKRNAMENOM->AsString;
                        DM->DocTTNOM->AsInteger=Nom->ElementTNOM->AsInteger;
                        DM->DocTKOLZ_ZAKT->AsFloat=1;

                        DM->DocTIDED_ZAKT->AsInteger=Nom->ElementIDOSNEDNOM->AsInteger;
                        DM->DocTNAMEED->AsString=Nom->OsnEdNAMEED->AsString;
                        DM->DocTKF_ZAKT->AsFloat=Nom->OsnEdKFED->AsFloat;

                        DM->DocTZNACH_PRICE->AsFloat=Nom->ElementZNACH_PRICE->AsFloat;
                        DM->DocTPRICE_ZAKT->AsFloat=DM->DocTZNACH_PRICE->AsFloat
                                                *DM->DocTKF_ZAKT->AsFloat;

                        DM->OpenMPrig();
                        DM->DocTNAME_MPRIG->AsString=DM->IBQNomNAME_MPRIG->AsString;

                        DM->DocT->Post();
                        DBGrid1->SelectedField=DM->DocTKOLZ_ZAKT;
                }
        }



if (EditRekvisit==Edinica)
        {
        if (SpisokEd->OutReady==true)
                {
                DM->DocT->Edit();

                DM->DocTIDED_ZAKT->AsInteger=SpisokEd->DM->ElementIDED->AsInteger;
                DM->DocTNAMEED->AsString=SpisokEd->DM->ElementNAMEED->AsString;
                DM->DocTKF_ZAKT->AsFloat=SpisokEd->DM->ElementKFED->AsFloat;

                DM->DocTPRICE_ZAKT->AsFloat=DM->DocTZNACH_PRICE->AsFloat
                                                *DM->DocTKF_ZAKT->AsFloat;
                DM->DocT->Post();
                DBGrid1->SelectedField=DM->DocTKOLZ_ZAKT;
               }
        }



if (EditRekvisit==CreateCheck)
        {
        if (FormaArmKassir->OutReady==true)
               {
               if (FormaArmKassir->CheckPrint==true)
                        {
                        DM->Doc->Edit();
                        DM->DocSOST_ZAK->AsInteger=2;
                        DM->Doc->Post();
                        DM->SaveDoc();
                        UpdateForm();
                        Prosmotr=true;
                        }
                }
        }

if (EditRekvisit==CreateRealRest)
        {
        //if (DocReal->OutReady==true)
        //       {
        //       if (DocReal->OutReady==true)
        //                {
        //                DM->Doc->Edit();
        //                DM->DocSOST_ZAK->AsInteger=2;
        //                DM->Doc->Post();
       //                 DM->SaveDoc();
        //                ObnovitForm();
        //                Prosmotr=true;
        //                }
        //        }
        }

if (EditRekvisit==ViborKlient)
        {
       // if (Kalkulator->OutReady==true)
       //        {
       //        if (DMKlient->OpenElement((int)(Kalkulator->Result))>0)
        //                {
        //                DM->Doc->Edit();
        //                DM->DocIDKLIENT_ZAK->AsInteger=DMKlient->ElementIDKLIENT->AsInteger;
        //                DM->DocNAMEKLIENT->AsString=DMKlient->ElementNAMEKLIENT->AsString;
        //                DM->Doc->Post();
       //                 }
       //         }
        }



        EditRekvisit=NO;
        IdDochForm=NULL;

}

//---------------------------------------------------------------------------
void TForma_ZakazOf::UpdateForm(void)
{
if (DM->DocSOST_ZAK->AsInteger==0){SostZakaz->Caption="Открыт";}
if (DM->DocSOST_ZAK->AsInteger==1){SostZakaz->Caption="Принят";}
if (DM->DocSOST_ZAK->AsInteger==2)
        {
        SostZakaz->Caption="Оплачен";
        Prosmotr=true;
        }


if(Prosmotr==true)
        {
        ProsmotrLabel->Visible=true;
        DBGrid1->ReadOnly=true;
        }
else
        {
        ProsmotrLabel->Visible=false;
        }

UpdateSetup();
}
//-----------------------------------------------------------------------------
void TForma_ZakazOf::UpdateSetup(void)
{
int idarm=glARM->ElementID_SARM->AsInteger;
glARM->OpenElement(idarm);
StatusBar->Panels->Items[0]->Text="KKM: "+glARM->ElementNAMEKKM->AsString;
StatusBar->Panels->Items[1]->Text="Тип цен:"+glARM->ElementNAME_TPRICE->AsString;

}
//-----------------------------------------------------------------------------
//******************************************************************************
//-----------------------------------------------------------------------------

void TForma_ZakazOf::CreateCheckKKM()
{
if(Prosmotr==true) return;
if (IdDochForm==NULL)
        {
        FormaArmKassir=new TFormaARMKassir(Application);
        if (!FormaArmKassir) return;
        FormaArmKassir->IdRodForm=Handle;
        FormaArmKassir->Vibor=true;
        IdDochForm=FormaArmKassir->Handle;
        FormaArmKassir->FOnCloseForm=EndEdit;
        EditRekvisit=CreateCheck;
        //заполним параметы чека
        FormaArmKassir->DM->NewDoc();
        FormaArmKassir->DM->DocAll->Edit();
        FormaArmKassir->DM->DocAllIDFIRMDOC->AsInteger=glARM->ElementIDFIRM_SARM->AsInteger;
        FormaArmKassir->DM->DocAllIDSKLDOC->AsInteger=glARM->ElementIDSKLAD_SARM->AsInteger;
        if (DM->DocIDKLIENT_ZAK->AsInteger>0)
                {
                FormaArmKassir->DM->DocAllIDKLDOC->AsInteger=DMKlient->ElementIDKLIENT->AsInteger;
                }

        FormaArmKassir->DM->DocAll->Post();

  //      Check->NameFirm->Caption=KKM->FirmaNAMEFIRM->AsString;
  //      Check->NameKKM->Caption=KKM->ElementNAMEKKM->AsString;
  //      Check->NameSklad->Caption=KKM->SkladNAMESKLAD->AsString;
  //      Check->NameKlient->Caption="";
  //      FormaArmKassir->NameDoc->Caption="Чек ККМ №"+Check->DM->DocAllNUMDOC->AsString
  //              +" от " +Check->DM->DocAllPOSDOC->AsString;

        FormaArmKassir->DM->Doc->Edit();
        FormaArmKassir->DM->DocIDTPRICE->AsInteger=glARM->ElementIDTPRICEPOD->AsInteger;
        FormaArmKassir->DM->DocIDKKMCHK->AsInteger=glARM->ElementIDKKM_SARM->AsInteger;
        FormaArmKassir->DM->DocPRIMCHK->AsString="Заказ №"+DM->DocID_ZAK->AsString+" "+DM->ObNAME_STROB->AsString;
        FormaArmKassir->DM->Doc->Post();

       // FormaArmKassir->Prim->Caption=Check->DM->DocPRIMCHK->AsString;


        DM->DocT->First();

        while(!DM->DocT->Eof)
                {
                FormaArmKassir->DM->AddDocNewString();
                FormaArmKassir->DM->DocT->Edit();
                FormaArmKassir->DM->DocTIDNOMCHKT->AsInteger=DM->DocTIDNOM_ZAKT->AsInteger;
                FormaArmKassir->DM->DocTNAMENOM->AsString=DM->DocTNAMENOM->AsString;
                FormaArmKassir->DM->DocTKRNAMENOM->AsString=DM->DocTKRNAMENOM->AsString;
                FormaArmKassir->DM->DocTIDEDCHKT->AsInteger=DM->DocTIDED_ZAKT->AsInteger;
                FormaArmKassir->DM->DocTNAMEED->AsString=DM->DocTNAMEED->AsString;
                FormaArmKassir->DM->DocTKOLCHKT->AsFloat=DM->DocTKOLOT_ZAKT->AsFloat;
                FormaArmKassir->DM->DocTKFCHKT->AsFloat=DM->DocTKF_ZAKT->AsFloat;
                FormaArmKassir->DM->DocTPRICECHKT->AsFloat=DM->DocTPRICE_ZAKT->AsFloat;
                FormaArmKassir->DM->DocTPRICEFULLCHKT->AsFloat=DM->DocTZNACH_PRICE->AsFloat;
                FormaArmKassir->DM->DocT->Post();
                DM->DocT->Next();
                }

       //  Check->SumCheck->Caption="Сумма: "+Check->DM->DocAllSUMDOC->AsString;
       //  Check->Nal->Caption="Наличные: "+Check->DM->DocNALCHK->AsString;
        // Check->OplataPC->Caption="Оплата плат. картой: "+Check->DM->DocOPLPCCHK->AsString;
        // Check->Sdacha->Caption="Сдача: "+Check->DM->DocSDACHA->AsString;
        FormaArmKassir->IdARM=glARM->ElementID_SARM->AsInteger;
        FormaArmKassir->CheckCreate=true;
//        FormaArmKassir->NoPrintCheckFR=true;
        FormaArmKassir->ExternalCreateCheck=false;
        FormaArmKassir->UpdateSetup();
        FormaArmKassir->UpdateParameterFR();
        FormaArmKassir->UpdateForm();
        FormaArmKassir->Nal->SetFocus();
        FormaArmKassir->Show();
        }



}
//---------------------------------------------------------------------------

bool TForma_ZakazOf::PrintZakaz(void)
{
//int TekMPrig=0;
bool Res=true;
//ErrorPrint=false;
//PrinterActive=false;

//DM->IBQPrint->Active=false;
//DM->IBQPrint->ParamByName("PARAM_IDZAK")->AsInteger=DM->DocID_ZAK->AsInteger;
//DM->IBQPrint->Active=true;

//DM->IBQPrint->First();
//while(!DM->IBQPrint->Eof)
//        {
//        if (DM->IBQPrintIDMPRIG_NOMREST->AsInteger==0)
//                {
//                 DM->IBQPrint->Next();
//                 continue;
//                }
//        if (DM->IBQPrintIDMPRIG_NOMREST->AsInteger==TekMPrig)
//                {
//                if (PrinterActive==true)
//                        {
//                        PrintString();
//                        }
//                }
//        else
//                {
 //               TekMPrig=DM->IBQPrintIDMPRIG_NOMREST->AsInteger;
//                if (PrinterActive==true)
//                        {
//                        DisconnectPrinter();
//                        }
//
//                DM->IBQMPrig->Active=false;
//                DM->IBQMPrig->ParamByName("PARAM_ID_MPRIG")->AsInteger=TekMPrig;
//                DM->IBQMPrig->Active=true;
//
//                if (PrinterActive==false)
//                        {
 //                       ConnectPrinter();
//                        PrintString();
//
//                        }
//                }
//        DM->IBQPrint->Next();
//        }
//
//if (PrinterActive==true)
//        {
//        DisconnectPrinter();
//        }
//DM->IBQPrint->Active=false;
//DM->IBQMPrig->Active=false;

//if (ErrorPrint==true)
//        {
//        Res=false;
//        }
//else
//        {
//        Res=true;
//        }
return Res;
}

//---------------------------------------------------------------------------
bool TForma_ZakazOf::ConnectPrinter(void)
{
try
        {
        Prn=Variant::CreateObject("AddIn.S500Drv");
        }
catch (...)
        {
        PrinterActive=false;
        ShowMessage("Не удалось создать объект кухонного принтера !");
        return  PrinterActive;
        }

        Prn.OlePropertySet("ComputerName",DM->IBQMPrigCOMPNAME_OBORUD->AsString.c_str());
        Prn.OlePropertySet("ConnectionType",1) ;
        Prn.OlePropertySet("ComNumber",StrToInt(DM->IBQMPrigCOMNAME_OBORUD->AsString[4])) ;
        Prn.OlePropertySet("BaudRate",StrToInt(DM->IBQMPrigBAUDRATE_OBORUD->AsString)) ;

        Prn.OleProcedure("ServerConnect");
        if(Prn.OlePropertyGet("ResultCode")!=0)
                {
                ShowMessage("Ошибка кухонного принтера: "+Prn.OlePropertyGet("ResultCodeDescription"));
                PrinterActive=false;
                ErrorPrint=true;
                return  PrinterActive;
                }


        Prn.OleProcedure("LockPort");
        if(Prn.OlePropertyGet("ResultCode")!=0)
                {
                ShowMessage("Ошибка кухонного принтера: "+Prn.OlePropertyGet("ResultCodeDescription"));
                Prn.OleProcedure("ServerDisconnect");
                PrinterActive=false;
                ErrorPrint=true;
                return  PrinterActive;
                }

       PrinterActive=true;


       Prn.OlePropertySet("StringForPrinting","  Заказ");
       Prn.OleProcedure("PrintWideString");
       if(Prn.OlePropertyGet("ResultCode")!=0)
                {
                ShowMessage("Ошибка кухонного принтера: "+Prn.OlePropertyGet("ResultCodeDescription"));
                Prn.OleProcedure("UnlockPort");
                Prn.OleProcedure("ServerDisconnect");
                PrinterActive=false;
                ErrorPrint=true;
                return  PrinterActive;
                }

            
                String StrPrint="Дата: "+DateTimeToStr(Now());
                Prn.OlePropertySet("StringForPrinting",StrPrint.c_str());
                Prn.OleProcedure("PrintString");

                Prn.OlePropertySet("StringForPrinting",DM->IBQMPrigNAME_MPRIG->AsString.c_str());
                Prn.OleProcedure("PrintString");

                Prn.OlePropertySet("StringForPrinting",DM->DocNAME_STROB->AsString.c_str());
                Prn.OleProcedure("PrintString");

                Prn.OlePropertySet("StringForPrinting",glUser->ElementFNAME_USER->AsString.c_str());
                Prn.OleProcedure("PrintString");

                Prn.OlePropertySet("StringForPrinting"," ");
                Prn.OleProcedure("PrintString");

                Prn.OlePropertySet("StringForPrinting","------------------------------------");
                Prn.OleProcedure("PrintString");

       if(Prn.OlePropertyGet("ResultCode")!=0)
                {
                ShowMessage("Ошибка кухонного принтера: "+Prn.OlePropertyGet("ResultCodeDescription"));
                Prn.OleProcedure("UnlockPort");
                Prn.OleProcedure("ServerDisconnect");
                PrinterActive=false;
                ErrorPrint=true;
                return  PrinterActive;
                }

return PrinterActive;
}
//-----------------------------------------------------------------------------
bool TForma_ZakazOf::DisconnectPrinter(void)
{
bool result=true;
if (PrinterActive==true)
        {
        Prn.OlePropertySet("StringForPrinting","------------------------------------");
        Prn.OleProcedure("PrintString");

for(int i=1;i<8;i++)
        {
        Prn.OlePropertySet("StringForPrinting","  ");
        Prn.OleProcedure("PrintString");
        }

        if(Prn.OlePropertyGet("ResultCode")==0)
                {
                result=true;
                }
        else
                {
                result=false;
                ShowMessage("Ошибка кухонного принтера: "+Prn.OlePropertyGet("ResultCodeDescription"));
                }

        Prn.OleProcedure("Beep");

        Prn.OleProcedure("UnlockPort");
        Prn.OleProcedure("ServerDisconnect");
        PrinterActive=false;
        }

return result;

}
//-----------------------------------------------------------------------------
bool TForma_ZakazOf::PrintString(void)
{
bool result=false;
if (PrinterActive==false) return result;
String StrPr="";

                StrPr=DM->IBQPrintKRNAMENOM->AsString;

                Prn.OlePropertySet("StringForPrinting",StrPr.c_str());
                Prn.OleProcedure("PrintString");

                StrPr=" ";
                StrPr=FloatToStr(DM->IBQPrintKOLZ_ZAKT->AsFloat);
                StrPr=DopStrL(StrPr," ",6);
                StrPr=DM->IBQPrintNAMEED->AsString+" - "+StrPr;
                StrPr=DopStrL(StrPr," ",32);
                Prn.OlePropertySet("StringForPrinting",StrPr.c_str());
                Prn.OleProcedure("PrintString");

                if(Prn.OlePropertyGet("ResultCode")!=0)
                        {
                        ShowMessage("Ошибка кухонного принтера: "+Prn.OlePropertyGet("ResultCodeDescription"));
                        ErrorPrint=true;
                        }
if (ErrorPrint==true)
        {
        result=false;
        }
else
        {
        result=true;
        TLocateOptions Opt;
        Opt<<loCaseInsensitive;
        DM->DocT->Locate("ID_ZAKT",DM->IBQPrintID_ZAKT->AsString,Opt);
        if (DM->DocTID_ZAKT->AsInteger==DM->IBQPrintID_ZAKT->AsInteger)
                {
                DM->DocT->Edit();
                DM->DocTKOLPR_ZAKT->AsFloat=1;
                DM->DocT->Post();
                }
        }

return result;
}
//-----------------------------------------------------------------------------
void __fastcall TForma_ZakazOf::FormResize(TObject *Sender)
{
        int TecSumWidth=DBGrid1->Width;
        int  SumWidth=771;
        DBGrid1->Columns->Items[0]->Width=23*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[1]->Width=30*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[2]->Width=289*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[3]->Width=40*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[4]->Width=40*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[5]->Width=84*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[6]->Width=63*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[7]->Width=68*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[8]->Width=86*TecSumWidth/SumWidth;
}
//------------------------------------------------------------------------

bool TForma_ZakazOf::PrintSchet(void)
{
bool result=false;
if(glFRConnect==false) return result;
String StrPr="";
if (glARM->GetParameter("STR_ZAG_1")!="")
        {
        glFR->PrintString(glARM->GetParameter("STR_ZAG_1"),1,0,0,true,false);
        }

if (glARM->GetParameter("STR_ZAG_2")!="")
        {

        glFR->PrintString(glARM->GetParameter("STR_ZAG_2"),1,0,0,true,false);
        }

if (glARM->GetParameter("STR_ZAG_3")!="")
        {

        glFR->PrintString(glARM->GetParameter("STR_ZAG_3"),1,0,0,true,false);
        }

glFR->PrintString(" ",1,0,0,true,false);
StrPr="  СЧЕТ №"+DM->DocID_ZAK->AsString;

glFR->PrintString(StrPr,1,1,0,true,false);


glFR->PrintString(" ",1,0,0,true,false);
glFR->PrintString(DM->DocNAME_STROB->AsString,1,0,0,true,false);
glFR->PrintString(DateTimeToStr(Now()),1,0,0,true,false);
glFR->PrintString(" ",1,0,0,true,false);

DM->DocT->First();
while(!DM->DocT->Eof)
        {

        if (glFR->PrintString(DM->DocTKRNAMENOM->AsString,1,0,0,true,false)==true){result=true;}else{result=false;}
        StrPr=" ";
        StrPr=FloatToStrF(DM->DocTPRICE_ZAKT->AsFloat,ffFixed,15,2)
                +" x "+FloatToStr(DM->DocTKOLOT_ZAKT->AsFloat)+" "
                +DM->DocTNAMEED->AsString+" = "
                +FloatToStrF(DM->DocTSUM_ZAKT->AsFloat,ffFixed,15,2);
        StrPr=DopStrL(StrPr," ",36);
        if(glFR->PrintString(StrPr,1,0,0,true,false)==true) {result=true;}else {result=false;}
        DM->DocT->Next();
        }

glFR->PrintString("------------------------------------",1,0,0,true,false);
glFR->PrintString(" ",1,0,0,true,false);

StrPr="Всего: "+FloatToStrF(DM->DocSUM_ZAK->AsFloat,ffCurrency,10,2);

glFR->PrintString(StrPr,1,1,0,true,false);


glFR->PrintString(" ",1,0,0,true,false);
glFR->PrintString(" ",1,0,0,true,false);
StrPr=glUser->ElementFNAME_USER->AsString;
glFR->PrintString(StrPr,1,0,0,true,false);

for(int i=0;i<7;i++)
        {
        glFR->PrintString(" ",1,0,0,true,false);
        }


if (glFR->Cut(1)==true)
        {
        result=true;
        }


return result;



}
//----------------------------------------------------------------------------
void TForma_ZakazOf::CreateDocRealRest(void)
{
//if(Prosmotr==true) return;
//if (IdDochForm==NULL)
//        {
//        DocReal=new TFormaDocRealRestTouch(Application);
//        if (!DocReal) return;
//        DocReal->IdRodForm=Handle;
//        IdDochForm=DocReal->Handle;
//        EditRekvisit=CreateRealRest;
        //заполним параметы чека
//        DocReal->DM->NewDoc();
//        DocReal->DM->DocAll->Edit();
//        DocReal->DM->DocAllIDFIRMDOC->AsInteger=glKKM->ElementIDFIRMKKM->AsInteger;
//        DocReal->DM->DocAllIDSKLDOC->AsInteger=glKKM->ElementIDSKLADKKM->AsInteger;
//        DocReal->DM->DocAllIDUSERDOC->AsInteger=DM->DocIDUSER_ZAK->AsInteger;
//        DocReal->DM->DocAllNAME_USER->AsString=DM->DocNAME_USER->AsString;
//        if (DM->DocIDKLIENT_ZAK->AsInteger>0)
//                {
//                DocReal->DM->DocAllIDKLDOC->AsInteger=DM->DocIDKLIENT_ZAK->AsInteger;
//                }

//        DocReal->DM->DocAll->Post();

//        DocReal->DM->Doc->Edit();
//        DocReal->DM->DocIDTPRICE_REALREST->AsInteger=glIdTypePrice;
//        DocReal->DM->DocPRIM_REALREST->AsString="Заказ №"+DM->DocID_ZAK->AsString+" "+DM->ObNAME_STROB->AsString;

//        DocReal->DM->Doc->Post();

//        DM->DocT->First();

//        while(!DM->DocT->Eof)
//                {
//                DocReal->DM->AddDocNewString();
//                DocReal->DM->DocT->Edit();
//                DocReal->DM->DocTIDNOM_REALRESTT->AsInteger=DM->DocTIDNOM_ZAKT->AsInteger;
//                DocReal->DM->DocTNAMENOM->AsString=DM->DocTNAMENOM->AsString;
//                DocReal->DM->DocTIDED_REALRESTT->AsInteger=DM->DocTIDED_ZAKT->AsInteger;
//                DocReal->DM->DocTNAMEED->AsString=DM->DocTNAMEED->AsString;
//                DocReal->DM->DocTKOL_REALRESTT->AsFloat=DM->DocTKOLOT_ZAKT->AsFloat;
//                DocReal->DM->DocTKF_REALRESTT->AsFloat=DM->DocTKF_ZAKT->AsFloat;
//                DocReal->DM->DocTPRICE_REALRESTT->AsFloat=DM->DocTPRICE_ZAKT->AsFloat;
//                DocReal->DM->DocT->Post();
//                DM->DocT->Next();
//                }


//                DocReal->LabelFirm->Caption="Фирма: "+glKKM->FirmaNAMEFIRM->AsString;
//                DocReal->LabelSklad->Caption="Склад: "+glKKM->SkladNAMESKLAD->AsString;
//                DocReal->LabelKlient->Caption="Контрагент: "+DM->DocNAMEKLIENT->AsString;
//                DocReal->LabelNameDoc->Caption="Акт реализации №"+DocReal->DM->DocAllNUMDOC->AsString+" от "+DocReal->DM->DocAllPOSDOC->AsString;
//                DocReal->LabelPrim->Caption="Заказ на объекте "+DM->ObNAME_STROB->AsString;
//        DocReal->UpdateForm();
//        DocReal->Show();
//        }

}
//----------------------------------------------------------------------------
void TForma_ZakazOf::VibratKlienta(void)
{
if(Prosmotr==true) return;
if (IdDochForm==NULL)
        {


        }
}
//---------------------------------------------------------------------------
void __fastcall TForma_ZakazOf::N21Click(TObject *Sender)
{
VibratKlienta();
}
//---------------------------------------------------------------------------
//***************************************************************************
void TForma_ZakazOf::OpenFormInputCodeNom(void)
{


if (IdDochForm==NULL)
        {
        UpdateSetup();
        FormaInputCode=new TFormaInputCode(Application);
        FormaInputCode->Vibor=true;
        FormaInputCode->IdRodForm=Handle;
        IdDochForm=FormaInputCode->Handle;
        FormaInputCode->FOnCloseForm=EndEdit;
        EditRekvisit=InputCodeNom;
        FormaInputCode->NameSprLabel->Caption="Справочник номенклатура:";
        FormaInputCode->ShowModal();
        }
}
//----------------------------------------------------------------------------
void TForma_ZakazOf::OpenFormInputCodeNomBV(void)
{

if(Prosmotr==true) return;

if (IdDochForm==NULL)
        {
        UpdateSetup();
        FormaInputCode=new TFormaInputCode(Application);
        FormaInputCode->Vibor=true;
        FormaInputCode->IdRodForm=Handle;
        IdDochForm=FormaInputCode->Handle;
        FormaInputCode->FOnCloseForm=EndEdit;
        EditRekvisit=InputCodeBV;
        FormaInputCode->NameSprLabel->Caption="Справочник быстрого вызова:";
        FormaInputCode->ShowModal();
        }
}
//----------------------------------------------------------------------------

void TForma_ZakazOf::OpenFormViborNomSpr(void)
{

if(Prosmotr==true) return;

if (IdDochForm==NULL)
        {
        UpdateSetup();
        FormaViborNomSpr=new TFormaViborNomSpr(Application);
        if (!FormaViborNomSpr) return;
        FormaViborNomSpr->IdRodForm=Handle;
        FormaViborNomSpr->Vibor=true;
        IdDochForm=FormaViborNomSpr->Handle;
        FormaViborNomSpr->FOnCloseForm=EndEdit;
        EditRekvisit=ViborNomSpr;
        FormaViborNomSpr->DM->IdTypePrice=glARM->ElementIDTPRICEPOD->AsInteger;
        FormaViborNomSpr->SpisokTypePrice->ItemIndex=FormaViborNomSpr->DM->GetIndexTypePrice()-1;
        FormaViborNomSpr->UpdateForm();
        FormaViborNomSpr->Show();
        }
}

//---------------------------------------------------------------------------
void TForma_ZakazOf::OpenFormViborSprBVNom(void)
{

if(Prosmotr==true) return;

if (IdDochForm==NULL)
        {
        UpdateSetup();
        SprBV=new TFormaViborBVNom(Application);
        if (!SprBV) return;
        SprBV->IdRodForm=Handle;
        SprBV->FOnCloseForm=EndEdit;
        SprBV->Vibor=true;
        SprBV->Prosmotr=true;
        SprBV->IdPod=glARM->ElementIDPODR_SARM->AsInteger;
        IdDochForm=SprBV->Handle;
        EditRekvisit=ViborTovarSprBV;
        SprBV->DBGrid1->ReadOnly=true;
        SprBV->EditPodr->Text=glARM->ElementNAMEPOD->AsString;
        SprBV->UpdateForm();
        SprBV->Show();

        }
}

//-----------------------------------------------------------------------------

void TForma_ZakazOf::OpenFormViborSprEd(void)
{
if(Prosmotr==true) return;

if (DM->DocTKOLPR_ZAKT->AsFloat==1) return;

if (IdDochForm==NULL)
        {
        SpisokEd=new TFormaViborSprEd(Application);
        if (!SpisokEd) return;
        SpisokEd->IdRodForm=Handle;
        SpisokEd->FOnCloseForm=EndEdit;
        SpisokEd->Vibor=true;
        IdDochForm=SpisokEd->Handle;
        EditRekvisit=Edinica;
        SpisokEd->IdNom=DM->DocTIDNOM_ZAKT->AsInteger;
        SpisokEd->UpdateForm();
        SpisokEd->HintLabel->Caption="Выберите единицу для заказа";
        SpisokEd->LabelNom->Caption=DM->DocTNAMENOM->AsString;
        SpisokEd->Show();

        }
}
//-----------------------------------------------------------------------------
void __fastcall TForma_ZakazOf::N2Click(TObject *Sender)
{
OpenFormInputCodeNomBV();
}
//---------------------------------------------------------------------------

void __fastcall TForma_ZakazOf::N3Click(TObject *Sender)
{
OpenFormInputCodeNom();
}
//---------------------------------------------------------------------------

void __fastcall TForma_ZakazOf::N4Click(TObject *Sender)
{
OpenFormViborSprBVNom();
}
//---------------------------------------------------------------------------

void __fastcall TForma_ZakazOf::N5Click(TObject *Sender)
{
OpenFormViborNomSpr();
}
//---------------------------------------------------------------------------
void __fastcall TForma_ZakazOf::N7Click(TObject *Sender)
{
OpenFormViborSprEd();
}
//*****************************************************************************
//-----------------------------------------------------------------------------
void __fastcall TForma_ZakazOf::N8Click(TObject *Sender)
{
String St="";
if(Prosmotr==true) return;
//if (DM->DocTKOLPR_ZAKT->AsFloat==1) return;
St="Заказ № "+DM->DocID_ZAK->AsString+"  Удалена строка:" +DM->DocTNAMENOM->AsString
                +" Кол:"+DM->DocTKOLZ_ZAKT->AsString;

glSaveProtocol(St);
DM->DeleteStringDoc();        
}
//---------------------------------------------------------------------------

void __fastcall TForma_ZakazOf::N19Click(TObject *Sender)
{
if(Prosmotr==true) return;
DM->DocT->First();

while (!DM->DocT->Eof)
        {
        DM->DocT->Edit();
        DM->DocTKOLOT_ZAKT->AsFloat=DM->DocTKOLZ_ZAKT->AsFloat;
        DM->DocT->Post();
        DM->DocT->Next();
        }        
}
//---------------------------------------------------------------------------

void __fastcall TForma_ZakazOf::N10Click(TObject *Sender)
{
if(Prosmotr==true) return;
DM->SaveDoc();
if (PrintZakaz()==true)
        {

        }
else
        {
        ShowMessage("Не удалось напечатать заказ на кухне!");
        }

DM->SaveDoc();
}
//---------------------------------------------------------------------------

void __fastcall TForma_ZakazOf::N12Click(TObject *Sender)
{
if (PrintSchet()==true)
        {

        }
else
        {
        String V="Не удалось напечатать счет!";
        String Z="Ошибка!";
        Application->MessageBox(V.c_str(),Z.c_str(),MB_OK);
        }        
}
//---------------------------------------------------------------------------

void __fastcall TForma_ZakazOf::N13Click(TObject *Sender)
{
if(Prosmotr==true) return;
DM->SaveDoc();
CreateCheckKKM();
}
//---------------------------------------------------------------------------

void __fastcall TForma_ZakazOf::N14Click(TObject *Sender)
{
if(Prosmotr==true) return;
CreateDocRealRest();
}
//---------------------------------------------------------------------------

void __fastcall TForma_ZakazOf::N17Click(TObject *Sender)
{
String V="Сохранить изменения в заказе ?";
String Z="Сохранить?";
if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
        {

        if(Prosmotr==true)
                {
                V="Нельзя сохранить изменения в заказе! Заказ открыт только для просмотра!";
                Z="Сохранить?";
                Application->MessageBox(V.c_str(),Z.c_str(),MB_OK);
                Close();
                }
        else
                {
                if (DM->SaveDoc()==true)
                        {
                        Close();
                        }
                }

        }
else
        {
        DM->CloseDoc();
        Close();
        }        
}
//---------------------------------------------------------------------------

void __fastcall TForma_ZakazOf::N15Click(TObject *Sender)
{
if(Prosmotr==true)
        {
        String V="Нельзя сохранить изменения в заказе! Заказ открыт только для просмотра!";
        String Z="Сохранить?";
        Application->MessageBox(V.c_str(),Z.c_str(),MB_OK);
        Close();
        }
else
        {
        if (DM->SaveDoc()==true)
                {
                Close();
                }
        }
}
//---------------------------------------------------------------------------


void __fastcall TForma_ZakazOf::DBGrid1KeyPress(TObject *Sender, char &Key)
{
if (Key==VK_ESCAPE)
        {
        if(Prosmotr==true)
                {
                String V="Нельзя сохранить изменения в заказе! Заказ открыт только для просмотра!";
                String Z="Сохранить?";
                Application->MessageBox(V.c_str(),Z.c_str(),MB_OK);
                Close();
                }
        else
                {
                if (DM->SaveDoc()==true)
                        {
                        Close();
                        }
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForma_ZakazOf::Name_ZakDBEditKeyPress(TObject *Sender,
      char &Key)
{
if (Key==VK_ESCAPE)
        {
        if(Prosmotr==true)
                {
                String V="Нельзя сохранить изменения в заказе! Заказ открыт только для просмотра!";
                String Z="Сохранить?";
                Application->MessageBox(V.c_str(),Z.c_str(),MB_OK);
                Close();
                }
        else
                {
                if (DM->SaveDoc()==true)
                        {
                        Close();
                        }
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForma_ZakazOf::N11Click(TObject *Sender)
{
PrintPaperSchet();
}

//---------------------------------------------------------------------------
void TForma_ZakazOf::PrintPaperSchet(void)
{
TPrintFormAll  *PrintForm=new TPrintFormAll(Application);
if (!PrintForm) return;


numRow=1;
numCol=1;
porNumStr=1;


//шапка
OutputZagolovokReport(PrintForm);

//таблица

DM->DocT->First();
while(!DM->DocT->Eof)
        {

        OutputString(PrintForm);numRow++; porNumStr++;

        DM->DocT->Next();
        }

OutputPodavalReport(PrintForm);

PrintForm->Show();
PrintForm->F1->PrintGridLines=false;
PrintForm->F1->FilePrint(0) ;
delete PrintForm;

}
//---------------------------------------------------------------------------
void TForma_ZakazOf::OutputZagolovokReport(TPrintFormAll *prForm)
{
prForm->F1->SetDefaultFont ( "MS Sans Serif", 8);
prForm->F1->PrintLandscape=true;

numRow=1;
numCol=1;

prForm->F1->Row=numRow;
prForm->F1->Col=2;
prForm->F1->SetFont ( "MS Sans Serif", 12, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=glFirma->ElementFNAMEFIRM->AsString; numRow++;

prForm->F1->Row=numRow;
prForm->F1->Text=" ИНН "+glFirma->ElementINNFIRM->AsString; numRow++;

prForm->F1->Row=numRow;
prForm->F1->Text=glFirma->ElementPADRFIRM->AsString;
numRow++; numRow++;

prForm->F1->Col=2;
prForm->F1->Row=numRow;
prForm->F1->SetFont ( "MS Sans Serif", 16, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->SetAlignment( 2, 0, 2, 0);
prForm->F1->Text="СЧЕТ №"+DM->DocID_ZAK->AsString+" от "+DateToStr(Now());
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow+2,numCol+2,true);
numRow++; numRow++;

prForm->F1->Col=2;
prForm->F1->Row=numRow;
prForm->F1->SetFont ( "MS Sans Serif", 12, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=DM->DocNAME_STROB->AsString;
numRow++;


prForm->F1->Col=4;
prForm->F1->Row=numRow;
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 12, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=TimeToStr(Time());
numRow++;

//заголовок таблицы
prForm->F1->Col=1;
prForm->F1->ColWidth[numCol]=10;


numCol=2;
prForm->F1->Row=numRow;
prForm->F1->Col=numCol;
prForm->F1->Text="№";
prForm->F1->SetAlignment( 3, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->SetBorder(1,0,0,0,1,1,1,1,1,200,1);
prForm->F1->ColWidth[numCol]=500;
prForm->F1->RowHeight[numRow]=400;
numCol++;

prForm->F1->Col=numCol;
prForm->F1->ColWidth[numCol]=3000;
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="Наименование";
prForm->F1->SetBorder(1,0,0,0,1,1,1,1,1,200,1);
prForm->F1->SetAlignment( 3, 0, 2, 0);

numCol++;

prForm->F1->Col=numCol;
prForm->F1->ColWidth[numCol]=1000;
prForm->F1->SetAlignment( 3, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="Сумма";
prForm->F1->SetBorder(1,0,0,0,1,1,1,1,1,200,1);
numCol++;
numRow++;

}
//------------------------------------------------------------------------------
void TForma_ZakazOf::OutputString(TPrintFormAll *prForm)
{
numCol=2;

prForm->F1->Row=numRow;
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 3, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=IntToStr(porNumStr); numCol++;
//prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);

prForm->F1->Col=numCol;
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=DM->DocTKRNAMENOM->AsString;
//prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
prForm->F1->SetAlignment( 2, 0, 2, 0);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);
numCol++;

numRow++;

numCol=3;
prForm->F1->Row=numRow;
String StrPr=" ";
prForm->F1->SetFont ( "MS Sans Serif", 12, 1, 0, 0, 0, 1, 1, 1 );
StrPr=FloatToStrF(DM->DocTPRICE_ZAKT->AsFloat,ffFixed,15,2)
                +" x "+FloatToStr(DM->DocTKOLOT_ZAKT->AsFloat)+" "
                +DM->DocTNAMEED->AsString;
//StrPr=DopStrL(StrPr," ",36);


prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->Text=StrPr;  numCol++;
//prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);

prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 12, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=FloatToStrF(DM->DocTSUM_ZAKT->AsFloat,ffFixed,10,2); numCol++;
//prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);

}


//------------------------------------------------------------------------------
void TForma_ZakazOf::OutputPodavalReport(TPrintFormAll *prForm)
{
//numRow++;
prForm->F1->Row=numRow;
prForm->F1->Col=2;
prForm->F1->SetBorder(-1,0,0,1,0,0,0,0,0,0,0);

prForm->F1->Col=3;
prForm->F1->SetBorder(-1,0,0,1,0,0,0,0,0,0,0);

prForm->F1->Col=4;
prForm->F1->SetBorder(-1,0,0,1,0,0,0,0,0,0,0);

prForm->F1->Col=4;

prForm->F1->SetFont ( "MS Sans Serif", 14, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->SetBorder(-1,0,0,1,0,0,0,0,0,0,0);
prForm->F1->Text="Всего: "+FloatToStrF(DM->DocSUM_ZAK->AsFloat,ffFixed,10,2);
prForm->F1->RowHeight[numRow]=500;
//prForm->F1->SetRowHeightAuto(numRow,numCol,numRow+2,numCol+2,true);

numRow++;numRow++;

//prForm->F1->Col=2;
//prForm->F1->Row=numRow;
//prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
//prForm->F1->SetAlignment( 2, 0, 2, 0);
//prForm->F1->Text=CurrencyPropis(DM->DocSUM_ZAK->AsFloat);
//numRow++;numRow++;

prForm->F1->Col=2;
prForm->F1->Row=numRow;
prForm->F1->Text="Официант: "+DM->DocNAME_USER->AsString;
numRow++;numRow++;

prForm->F1->Col=2;
prForm->F1->Row=numRow;
prForm->F1->Text="Подпись    _______________________________________ ";
numRow++;numRow++;


}
//---------------------------------------------------------------
void __fastcall TForma_ZakazOf::N16Click(TObject *Sender)
{
if(Prosmotr==true) return;
DM->SaveDoc();
if (PrintPaperZakaz()==true)
        {

        }
else
        {
        ShowMessage("Не удалось напечатать заказ на кухне!");
        }

DM->SaveDoc();
}
//---------------------------------------------------------------------------

bool TForma_ZakazOf::PrintPaperZakaz(void)
{
//int TekMPrig=0;
bool Res=false;
ErrorPrint=false;
PrintZagolovok=false;
TPrintFormAll  *PrintForm;

//if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;

int KolStr=0;

TDMSprMPrig * DMSprMPrig=new TDMSprMPrig (Application);
DMSprMPrig->OpenTable();
DMSprMPrig->Table->First();
while(!DMSprMPrig->Table->Eof)
        {
        DM->DocT->First();
        while(!DM->DocT->Eof)
                {
                if (DMSprMPrig->TableID_MPRIG->AsInteger==DM->DocTIDMPRIG_ZAKT->AsInteger
                        && DM->DocTKOLPR_ZAKT->AsInteger==0)
                        {
                         if (KolStr==0)
                                {
                                numRow=1;
                                numCol=1;
                                porNumStr=1;
                                PrintForm=new TPrintFormAll(Application);
                                PrintZagolovokPaperZakaz(PrintForm, DMSprMPrig->TableNAME_MPRIG->AsString);
                                }

                        PrintStringPaperZakaz(PrintForm);
                        KolStr++;porNumStr++;
                        }

                DM->DocT->Next();
                }

        if (KolStr>0)
                {
                PrintPodvalPaperZakaz(PrintForm);
                //печатаем заказ на принтере
                PrintForm->Show();
                PrintForm->F1->PrintGridLines=false;
                PrintForm->F1->FilePrint(0) ;
                delete PrintForm;
                KolStr=0;
                }
        DMSprMPrig->Table->Next();
        }


Res=true;
delete DMSprMPrig;
return Res;
}

//---------------------------------------------------------------------------
bool TForma_ZakazOf::PrintZagolovokPaperZakaz(TPrintFormAll *prForm, String nameMPrig)
{

PrintZagolovok=true;
prForm->F1->SetDefaultFont ( "MS Sans Serif", 8);
prForm->F1->PrintLandscape=true;


numRow=1;
numCol=1;

prForm->F1->Row=numRow;
prForm->F1->Col=2;
prForm->F1->SetFont ( "MS Sans Serif", 12, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=glFirma->ElementFNAMEFIRM->AsString;
numRow++;

prForm->F1->Row=numRow;
prForm->F1->Text=" ИНН "+glFirma->ElementINNFIRM->AsString;
numRow++;

prForm->F1->Row=numRow;
prForm->F1->Text=glFirma->ElementPADRFIRM->AsString;
numRow++; numRow++;



prForm->F1->Col=2;
prForm->F1->Row=numRow;
prForm->F1->SetFont ( "MS Sans Serif", 16, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->SetAlignment( 2, 0, 2, 0);
prForm->F1->Text="Заказ №"+DM->DocID_ZAK->AsString+" от "
                +DateToStr(Now());
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow+2,numCol+2,true);
numRow++;

prForm->F1->Row=numRow;
prForm->F1->SetFont ( "MS Sans Serif", 16, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="   ("+nameMPrig+")";

numRow++; numRow++;



prForm->F1->Col=2;
prForm->F1->Row=numRow;
prForm->F1->SetFont ( "MS Sans Serif", 12, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=DM->DocNAME_STROB->AsString;
numRow++;


prForm->F1->Col=4;
prForm->F1->Row=numRow;
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 12, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=TimeToStr(Time());
numRow++;

//заголовок таблицы
prForm->F1->Col=1;
prForm->F1->ColWidth[numCol]=10;


numCol=2;
prForm->F1->Row=numRow;
prForm->F1->Col=numCol;
prForm->F1->Text="№";
prForm->F1->SetAlignment( 3, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->SetBorder(1,0,0,0,1,1,1,1,1,200,1);
prForm->F1->ColWidth[numCol]=500;
prForm->F1->RowHeight[numRow]=400;
numCol++;

prForm->F1->Col=numCol;
prForm->F1->ColWidth[numCol]=3000;
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="Наименование";
prForm->F1->SetBorder(1,0,0,0,1,1,1,1,1,200,1);
prForm->F1->SetAlignment( 3, 0, 2, 0);

numCol++;

prForm->F1->Col=numCol;
prForm->F1->ColWidth[numCol]=1000;
prForm->F1->SetAlignment( 3, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="Кол.";
prForm->F1->SetBorder(1,0,0,0,1,1,1,1,1,200,1);
numCol++;
//numRow++;

return PrintZagolovok;
}
//-----------------------------------------------------------------------------
bool TForma_ZakazOf::PrintPodvalPaperZakaz(TPrintFormAll *prForm)
{
bool result=true;
if (PrintZagolovok==true)
        {
//numRow++;
//prForm->F1->Col=2;
//prForm->F1->Row=numRow;
//prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
//prForm->F1->SetAlignment( 2, 0, 2, 0);
//prForm->F1->Text=CurrencyPropis(DM->DocSUM_ZAK->AsFloat);
//numRow++;numRow++;

numRow++;
prForm->F1->Row=numRow;
prForm->F1->Col=2;
prForm->F1->SetBorder(-1,0,0,1,0,0,0,0,0,0,0);

prForm->F1->Col=3;
prForm->F1->SetBorder(-1,0,0,1,0,0,0,0,0,0,0);

prForm->F1->Col=4;
prForm->F1->SetBorder(-1,0,0,1,0,0,0,0,0,0,0);

prForm->F1->Col=2;
prForm->F1->Row=numRow;
prForm->F1->Text="Официант: "+DM->DocNAME_USER->AsString;
numRow++;numRow++;

prForm->F1->Col=2;
prForm->F1->Row=numRow;
prForm->F1->Text="Подпись    _______________________________________ ";
numRow++;numRow++;
        }

return result;

}
//-----------------------------------------------------------------------------
bool TForma_ZakazOf::PrintStringPaperZakaz(TPrintFormAll *prForm)
{
bool result=true;
numCol=2;
numRow++;
prForm->F1->Row=numRow;
prForm->F1->Col=numCol;
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->SetAlignment( 3, 0, 2, 0);
prForm->F1->Text=IntToStr(porNumStr); numCol++;
//prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);

prForm->F1->Col=numCol;
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=DM->DocTNAMENOM->AsString;
//prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
prForm->F1->SetAlignment( 2, 0, 2, 0);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);
numCol++;

numRow++;

numCol=3;
prForm->F1->Row=numRow;
String StrPr=" ";
prForm->F1->SetFont ( "MS Sans Serif", 12, 1, 0, 0, 0, 1, 1, 1 );
StrPr=DM->DocTNAMEED->AsString;
//StrPr=DopStrL(StrPr," ",36);


prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->Text=StrPr;  numCol++;
//prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);

prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 12, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=FloatToStr(DM->DocTKOLZ_ZAKT->AsFloat); numCol++;
//prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);

        result=true;
//        TLocateOptions Opt;
//        Opt<<loCaseInsensitive;
//        DM->DocT->Locate("ID_ZAKT",DM->IBQPrintID_ZAKT->AsString,Opt);
//        if (DM->DocTID_ZAKT->AsInteger==DM->IBQPrintID_ZAKT->AsInteger)
//                {
                DM->DocT->Edit();
                DM->DocTKOLPR_ZAKT->AsFloat=1;
                DM->DocT->Post();
//                }

return result;
}
//-------------------------------------------------------------------------------------
void __fastcall TForma_ZakazOf::N24Click(TObject *Sender)
{
OpenFormInputCodeStrOb();
}
//---------------------------------------------------------------------------
void TForma_ZakazOf::OpenFormInputCodeStrOb(void)
{

if (IdDochForm==NULL)
        {
        FormaInputText=new TFormaInputText(Application);
        FormaInputText->Vibor=true;
        FormaInputText->IdRodForm=Handle;
        FormaInputText->FOnCloseForm=EndEdit;
        IdDochForm=FormaInputText->Handle;
        EditRekvisit=InputCodeStrOb;
        FormaInputText->NameLabel->Caption="Введите код объекта:";
        FormaInputText->Caption="Код объекта";
        FormaInputText->ShowModal();
        }
}
//----------------------------------------------------------------------------
void TForma_ZakazOf::OpenFormViborObject(void)
{
if (IdDochForm==NULL)
        {
        FormaViborSprStrObject=new TFormaViborSprStrObject(Application);
        FormaViborSprStrObject->Vibor=true;
        FormaViborSprStrObject->IdRodForm=Handle;
        FormaViborSprStrObject->FOnCloseForm=EndEdit;
        IdDochForm=FormaViborSprStrObject->Handle;
        EditRekvisit=ViborObject;
        FormaViborSprStrObject->ShowModal();
        }
}
//---------------------------------------------------------------------------
void __fastcall TForma_ZakazOf::N23Click(TObject *Sender)
{
OpenFormViborObject();
}
//---------------------------------------------------------------------------


