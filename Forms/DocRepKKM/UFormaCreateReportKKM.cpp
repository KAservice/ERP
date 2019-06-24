//---------------------------------------------------------------------------
#include "glPCH.h"
#pragma hdrstop

#include "UFormaCreateReportKKM.h"
#include "UFormaSpiskaSprKKM.h"
#include "UFormaSpiskaSprDogovor.h"
#include "UFormaDocRepKKM.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtonEdit"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaCreateReportKKM::TFormaCreateReportKKM(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
bool TFormaCreateReportKKM::Init(void)
{
bool result=false;


EditRekvisit=NO;
Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи

DateTimePicker2->Date=Date();
DateTimePicker1->Date=Date()-5;

EditFirm->Text="";
EditSklad->Text="";
EditKKM->Text="";
NumberKlEdit->Text="0";


//ПРИВЕЛЕГИИ
DM_Connection->GetPrivForm(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//--------------------------------------------------------------------------
void TFormaCreateReportKKM::UpdateForm(void)
{


}
//---------------------------------------------------------------------------

void __fastcall TFormaCreateReportKKM::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokFirm)SpisokFirm->Close() ;
if(SpisokSklad)SpisokSklad->Close();
if(SpisokKKM)SpisokKKM->Close();
Action=caFree;        
}
//---------------------------------------------------------------------------
void __fastcall TFormaCreateReportKKM::EndEdit(TObject *Sender)
{


if (EditRekvisit==ViborFirm)
        {
        if (SpisokFirm->OutReady==true)
                {

				IdFirm=SpisokFirm->DM->ElementIDFIRM->AsInt64;
                EditFirm->Text=SpisokFirm->DM->ElementNAMEFIRM->AsString;

                }
        SpisokFirm=0;
        }

if (EditRekvisit==ViborSklad)
        {
        if (SpisokSklad->OutReady==true)
                {

				IdSklad=SpisokSklad->DM->ElementIDSKLAD->AsInt64;
                EditSklad->Text=SpisokSklad->DM->ElementNAMESKLAD->AsString;

                }
        SpisokSklad=0;
        }

if (EditRekvisit==ViborKKM)
        {
        if (SpisokKKM->OutReady==true)
                {

				IdKKM=SpisokKKM->DM->ElementIDKKM->AsInt64;
                EditKKM->Text=SpisokKKM->DM->ElementNAMEKKM->AsString;

                }
        SpisokKKM=0;
        }  


EditRekvisit=NO;
IdDochForm=NULL;

}

//---------------------------------------------------------------------------

void TFormaCreateReportKKM::OpenFormSpiskaSprFirm(void)
{
if (IdDochForm==NULL)
        {
		SpisokFirm=new TFormaSpiskaSprFirm(Application);
		SpisokFirm->DM_Connection=DM_Connection;
		SpisokFirm->Init();
        if (!SpisokFirm) return;
        SpisokFirm->IdRodForm=Handle;
        SpisokFirm->Vibor=true;
        IdDochForm=SpisokFirm->Handle;
        EditRekvisit=ViborFirm;
        SpisokFirm->FOnCloseForm=EndEdit;
        SpisokFirm->Show();
        }

}
//---------------------------------------------------------------------------
void TFormaCreateReportKKM::OpenFormSpiskaSprSklad(void)
{
if (IdDochForm==NULL)
        {
		SpisokSklad=new TFormaSpiskaSprSklad(Application);
		SpisokSklad->DM_Connection=DM_Connection;
		SpisokSklad->Init();
        if (!SpisokSklad) return;
        SpisokSklad->IdRodForm=Handle;
        SpisokSklad->Vibor=true;
        IdDochForm=SpisokSklad->Handle;
        EditRekvisit=ViborSklad;
        SpisokSklad->FOnCloseForm=EndEdit;
        SpisokSklad->Show();
        }

}

//--------------------------------------------------------------------------
void TFormaCreateReportKKM::OpenFormSpiskaSprKKM(void)
{
		SpisokKKM=new TFormaSpiskaSprKKM(Application);
		SpisokKKM->DM_Connection=DM_Connection;
		SpisokKKM->Init();
        if (!SpisokKKM) return;
        SpisokKKM->IdRodForm=Handle;
        SpisokKKM->Vibor=true;
        IdDochForm=SpisokKKM->Handle;
        EditRekvisit=ViborKKM;
        SpisokKKM->FOnCloseForm=EndEdit;
        SpisokKKM->Show();

}
//--------------------------------------------------------------------------





void __fastcall TFormaCreateReportKKM::EditFirmPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprFirm(); 	
}
//---------------------------------------------------------------------------

void __fastcall TFormaCreateReportKKM::EditSkladPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprSklad();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaCreateReportKKM::EditKKMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprKKM();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaCreateReportKKM::cxButtonCreateClick(TObject *Sender)
{
TFormaDocRepKKM *  DocRepKKM=new TFormaDocRepKKM(Application);
DocRepKKM->DM_Connection=DM_Connection;
DocRepKKM->Init();
if (!DocRepKKM) return;

if (DocRepKKM->DM->CreateReportKKM(IdSklad, IdKKM, IdFirm,
                          (int) StrToFloat(NumberKlEdit->Text),
								DateTimePicker1->Date,
								DateTimePicker2->Date
                                )==true)
        {
        DocRepKKM->DM->NewDoc();
        DocRepKKM->DM->DocAll->Edit();
		DocRepKKM->DM->DocAllIDFIRMDOC->AsString=IdFirm;
		DocRepKKM->DM->DocAllNAMEFIRM->AsString=EditFirm->Text;
		DocRepKKM->DM->DocAllIDSKLDOC->AsString=IdSklad;
        DocRepKKM->DM->DocAllNAMESKLAD->AsString=EditSklad->Text;
        DocRepKKM->DM->DocAll->Post();

		DocRepKKM->DM->TableDoc->First();

		while(!DocRepKKM->DM->TableDoc->Eof)
                {
                DocRepKKM->DM->DocT->Insert();
				DocRepKKM->DM->DocTIDNOM_DREPKKMT->AsString=
										DocRepKKM->DM->TableDocIDNOM->AsString;
                DocRepKKM->DM->DocTNAMENOM->AsString=
										DocRepKKM->DM->TableDocNAMENOM->AsString;
				DocRepKKM->DM->DocTIDED_DREPKKMT->AsString=
										DocRepKKM->DM->TableDocIDED->AsString;
                DocRepKKM->DM->DocTNAMEED->AsString=
										DocRepKKM->DM->TableDocNAMEED->AsString;
                DocRepKKM->DM->DocTKF_DREPKKMT->AsString=1;
                DocRepKKM->DM->DocTKOL_DREPKKMT->AsString=
										DocRepKKM->DM->TableDocSUMKOL->AsFloat;

                DocRepKKM->DM->DocTPRICE_DREPKKMT->AsFloat=
										DocRepKKM->DM->TableDocSUMMA->AsFloat
                                        /(DocRepKKM->DM->DocTKOL_DREPKKMT->AsFloat*
                                        DocRepKKM->DM->DocTKF_DREPKKMT->AsFloat);

                DocRepKKM->DM->DocTSK_DREPKKMT->AsString=
										DocRepKKM->DM->TableDocSUMSK->AsFloat;
                DocRepKKM->DM->DocTNAD_DREPKKMT->AsString=
										DocRepKKM->DM->TableDocSUMNAD->AsFloat;

                DocRepKKM->DM->DocT->Post();
                
                DocRepKKM->DM->TableDoc->Next();
                }   


        DocRepKKM->DM->GetSumOplata(IdSklad, IdKKM, IdFirm,
                                (int)StrToFloat(NumberKlEdit->Text),
								DateTimePicker1->Date,
								DateTimePicker2->Date );

        DocRepKKM->DM->Doc->Edit();
        DocRepKKM->DM->DocIDKKM_DREPKKM->AsString=IdKKM;
        DocRepKKM->DM->DocNAMEKKM->AsString=EditKKM->Text;
        DocRepKKM->DM->DocNKL_DREPKKM->AsInteger=(int) StrToFloat(NumberKlEdit->Text);
        DocRepKKM->DM->DocOPLNAL_DREPKKM->AsFloat=DocRepKKM->DM->OplataNal;
        DocRepKKM->DM->DocOPLPC_DREPKKM->AsFloat=DocRepKKM->DM->OplataPC;
        DocRepKKM->DM->Doc->Post();

        DocRepKKM->UpdateForm();
        }	
}
//---------------------------------------------------------------------------

void __fastcall TFormaCreateReportKKM::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------

