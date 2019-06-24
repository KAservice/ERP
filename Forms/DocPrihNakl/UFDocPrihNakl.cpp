//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "UFDocPrihNakl.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFDocPrihNakl::TFDocPrihNakl(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TFDocPrihNakl::FormCreate(TObject *Sender)
{
DM= new TDMDocPrihNakl(Application);

DBGrid1->DataSource=DM->DataSourceDocT;
NewElement=false;  // новый элемент
Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи
VibTovarId=0;
VibTovarIdGrp=0;
FDateDoc->Date=DM->DocAll->FieldByName("POSDOC")->AsDateTime;
LabelSumma->Caption="Сумма документа:  "+FloatToStrF(DM->Summa(),ffFixed,15,2);
}
//---------------------------------------------------------------------------
void __fastcall TFDocPrihNakl::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FOnCloseForm) FOnCloseForm(this);
delete DM;
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFDocPrihNakl::EndEdit(TObject *Sender)
{
if (EditRekvisit==Tovar)
        {
        if (Nom->OutReady==true)
                {
                DM->DocT->Edit();
                DM->DocT->FieldByName("IDNOMPRNT")->AsInteger=
                                VibTovarId=Nom->DM->ElementIDNOM->AsInteger;
                VibTovarIdGrp=Nom->DM->ElementIDGRPNOM->AsInteger;
                DM->DocTNAMENOM->AsString=Nom->DM->ElementNAMENOM->AsString;
                DM->DocTTNOM->AsInteger=Nom->DM->ElementTNOM->AsInteger;
                DM->DocTKOLPRNT->AsInteger=1;
                DM->DocTIDEDPRNT->AsInteger=Nom->DM->ElementIDBASEDNOM->AsInteger;
                DM->DocTNAMEED->AsString=Nom->DM->BasEdNAMEED->AsString;
                DM->DocTKFPRNT->AsFloat=Nom->DM->BasEdKFED->AsFloat;
                DM->DocTPRICEPRNT->AsFloat=Nom->DM->ElementPRICEZNOM->AsFloat;
                DM->DocTSUMPRNT->AsFloat=DM->DocTKOLPRNT->AsFloat*
                        DM->DocTKFPRNT->AsFloat*DM->DocTPRICEPRNT->AsFloat;
                DM->DocT->Post();
               LabelSumma->Caption="Сумма документа:  "+FloatToStrF(DM->Summa(),ffFixed,15,2);
                }
        }

if (EditRekvisit==Edinica)
        {
        if (Ed->OutReady==true)
                {
                DM->DocT->Edit();
                DM->DocTIDEDPRNT->AsInteger=Ed->DM->ElementIDED->AsInteger;
                DM->DocTNAMEED->AsString=Ed->DM->Element->FieldByName("NAMEED")->AsString;
                DM->DocTKFPRNT->AsFloat=Ed->DM->ElementKFED->AsFloat;
                DM->DocTSUMPRNT->AsFloat=DM->DocTKOLPRNT->AsFloat*
                        DM->DocTKFPRNT->AsFloat*DM->DocTPRICEPRNT->AsFloat;
                DM->DocT->Post();
                LabelSumma->Caption="Сумма документа:  "+FloatToStrF(DM->Summa(),ffFixed,15,2);
                }
        }
EditRekvisit=NO;
IdDochForm=NULL;
}
//---------------------------------------------------------------------------

//----------------------------------------------------------------------------
void __fastcall TFDocPrihNakl::ButtonCloseClick(TObject *Sender)
{
        DM->DocAll->CancelUpdates();
        DM->Doc->CancelUpdates();
        DM->DocT->CancelUpdates();
Close();
}
//---------------------------------------------------------------------------
void  TFDocPrihNakl::OpenFSSprNom()
{

if (IdDochForm==NULL)
        { 
        Nom=new TFormaSpiskaSprNom(Application);
        if (!Nom) return;
        Nom->IdRodForm=Handle;
        Nom->Vibor=true;
        IdDochForm=Nom->Handle;
        EditRekvisit=Tovar;
        Nom->FOnCloseForm=EndEdit;
        Nom->Show();
        }
}
//----------------------------------------------------------------------------
void TFDocPrihNakl:: OpenFSSprEd()
{
if (IdDochForm==NULL)
        {
        Ed=new TFormaSpiskaSprEd(Application);
        if (!Ed) return;
        Ed->IdRodForm=Handle;
        Ed->Vibor=true;
        IdDochForm=Ed->Handle;
        EditRekvisit=Edinica;
        Ed->DM->OpenTable(DM->DocTIDNOMPRNT->AsInteger);
        Ed->Show();
        Ed->FOnCloseForm=EndEdit;
        }
}

//----------------------------------------------------------------------------
void __fastcall TFDocPrihNakl::TableDocDblClick(TObject *Sender)
{
if (DBGrid1->SelectedField->DisplayName=="NAMENOM")
        {

        DM->DocT->Edit();
        OpenFSSprNom();
        EditRekvisit=Tovar;
        }

if (DBGrid1->SelectedField->DisplayName=="NAMEED")
        {

        DM->DocT->Edit();
        OpenFSSprEd();
        EditRekvisit=Edinica;
        }

}
//---------------------------------------------------------------------------



void __fastcall TFDocPrihNakl::ToolButtonInsertClick(TObject *Sender)
{
DM->AddDocNewString();
}
//---------------------------------------------------------------------------

void __fastcall TFDocPrihNakl::ButtonSaveClick(TObject *Sender)
{

DM->SaveDoc();


}

void __fastcall TFDocPrihNakl::ToolButtonDeleteClick(TObject *Sender)
{
DM->DeleteStringDoc();
}
//---------------------------------------------------------------------------

void __fastcall TFDocPrihNakl::ButtonDvRegClick(TObject *Sender)
{

if (DM->SaveDoc()==true)
        {
        DM->DvRegDoc();
        }
}
//---------------------------------------------------------------------------

void __fastcall TFDocPrihNakl::ButtonOKClick(TObject *Sender)
{

if (DM->SaveDoc()==true)
        {
        if (DM->DvRegDoc()==true)
                {
                Close();
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TFDocPrihNakl::FDateDocChange(TObject *Sender)
{
DM->DocAll->Edit();
DM->DocAll->FieldByName("POSDOC")->AsDateTime=FDateDoc->Date;
DM->DocAll->Post();
}
//---------------------------------------------------------------------------

void __fastcall TFDocPrihNakl::DBGrid1EditButtonClick(TObject *Sender)
{
if (DBGrid1->SelectedField->DisplayName=="NAMENOM")
        {
        OpenFSSprNom();
        EditRekvisit=Tovar;
        }

if (DBGrid1->SelectedField->DisplayName=="NAMEED")
        {
        OpenFSSprEd();
        EditRekvisit=Edinica;
        }
}
//---------------------------------------------------------------------------


void __fastcall TFDocPrihNakl::DBGrid1ColExit(TObject *Sender)
{
        DM->DocT->Edit();
        DM->DocT->FieldByName("SUMPRNT")->AsFloat=DM->DocTKOLPRNT->AsFloat*
                DM->DocTKFPRNT->AsFloat*DM->DocTPRICEPRNT->AsFloat;
        DM->DocT->Post();
        LabelSumma->Caption="Сумма документа:  "+FloatToStrF(DM->Summa(),ffFixed,15,2);
}
//---------------------------------------------------------------------------

void __fastcall TFDocPrihNakl::DBGrid1Exit(TObject *Sender)
{
        DM->DocT->Edit();
        DM->DocT->FieldByName("SUMPRNT")->AsFloat=DM->DocTKOLPRNT->AsFloat*
                DM->DocTKFPRNT->AsFloat*DM->DocTPRICEPRNT->AsFloat;
        DM->DocT->Post();
        LabelSumma->Caption="Сумма документа:  "+FloatToStrF(DM->Summa(),ffFixed,15,2);
}
//---------------------------------------------------------------------------

void __fastcall TFDocPrihNakl::DBGrid1KeyPress(TObject *Sender, char &Key)
{
if (Key==VK_RETURN)
        {
        DM->DocT->Edit();
        DM->DocT->FieldByName("SUMPRNT")->AsFloat=DM->DocTKOLPRNT->AsFloat*
                DM->DocTKFPRNT->AsFloat*DM->DocTPRICEPRNT->AsFloat;
        DM->DocT->Post();
        LabelSumma->Caption="Сумма документа:  "+FloatToStrF(DM->Summa(),ffFixed,15,2);
        }
}

void __fastcall TFDocPrihNakl::FormResize(TObject *Sender)
{
int SumWidth=DBGrid1->Width-35;
DBGrid1->Columns->Items[0]->Width=0.1*SumWidth;
DBGrid1->Columns->Items[1]->Width=0.4*SumWidth;
DBGrid1->Columns->Items[2]->Width=0.1*SumWidth;
DBGrid1->Columns->Items[3]->Width=0.1*SumWidth;
DBGrid1->Columns->Items[4]->Width=0.1*SumWidth;
DBGrid1->Columns->Items[5]->Width=0.1*SumWidth;
DBGrid1->Columns->Items[6]->Width=0.1*SumWidth;
}
//---------------------------------------------------------------------------


