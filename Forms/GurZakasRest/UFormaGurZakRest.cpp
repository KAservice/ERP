//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaGurZakRest.h"
#include "UDMSprUser.h"
#include "UDMRegZak.h"
#include "UDMSprARM.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

extern TDMSprARM *glARM;
extern TDMSprUser * glUser;

//---------------------------------------------------------------------------
__fastcall TFormaGurZakRest::TFormaGurZakRest(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaGurZakRest::FormCreate(TObject *Sender)
{
DM=new TDMGurZakRest(Application);
DBGrid1->DataSource=DM->DataSourceTable;
DM->AllUser=true;
}
//---------------------------------------------------------------------------
void __fastcall TFormaGurZakRest::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FOnCloseForm) FOnCloseForm(this);
delete DM;
Action=caFree;
}
//---------------------------------------------------------------------------
void TFormaGurZakRest::UpdateForm(void)
{

DM->OpenTable();

}
//---------------------------------------------------------------------------
void __fastcall TFormaGurZakRest::EndEdit(TObject *Sender)
{
if (EditRekvisit==EditZakaz)
        {
        DM->UpdateTable();
        }
EditRekvisit=NO;
IdDochForm=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFormaGurZakRest::N2Click(TObject *Sender)
{
CreateNewZakaz();
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurZakRest::N3Click(TObject *Sender)
{
OpenZakaz();
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurZakRest::FormResize(TObject *Sender)
{
        int TecSumWidth=DBGrid1->Width;
        int  SumWidth=688;
        DBGrid1->Columns->Items[0]->Width=62*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[1]->Width=81*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[2]->Width=195*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[3]->Width=85*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[4]->Width=123*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[5]->Width=96*TecSumWidth/SumWidth;
}
//---------------------------------------------------------------------------
void TFormaGurZakRest::CreateNewZakaz(void)
{
if (IdDochForm==NULL)
       {

                Forma_ZakazOf=new TForma_ZakazOf(Application);
                if (!Forma_ZakazOf) return;
                Forma_ZakazOf->IdRodForm=Handle;
                IdDochForm=Forma_ZakazOf->Handle;
                Forma_ZakazOf->FOnCloseForm=EndEdit;
                EditRekvisit=EditZakaz;
                Forma_ZakazOf->DM->IdTypePrice=glARM->ElementIDTPRICEPOD->AsInteger;
                Forma_ZakazOf->DM->NewDoc(0);
                Forma_ZakazOf->DM->Doc->Edit();
                Forma_ZakazOf->DM->DocIDUSER_ZAK->AsInteger=glUser->ElementID_USER->AsInteger;
                Forma_ZakazOf->DM->DocNAME_USER->AsString=glUser->ElementNAME_USER->AsString;
                Forma_ZakazOf->DM->Doc->Post();
                Forma_ZakazOf->UpdateForm();
                Forma_ZakazOf->Show();
        }


}
//-----------------------------------------------------------------------------
void TFormaGurZakRest::OpenZakaz(void)
{
if (IdDochForm==NULL)
        {

                Forma_ZakazOf=new TForma_ZakazOf(Application);
                if (!Forma_ZakazOf) return;
                Forma_ZakazOf->IdRodForm=Handle;
                Forma_ZakazOf->FOnCloseForm=EndEdit;
                IdDochForm=Forma_ZakazOf->Handle;
                EditRekvisit=EditZakaz;
                Forma_ZakazOf->DM->IdTypePrice=glARM->ElementIDTPRICEPOD->AsInteger;
                Forma_ZakazOf->DM->OpenDoc(DM->TableID_ZAK->AsInteger);

                if (glUser->UserOK==false)
                        {
                        Forma_ZakazOf->Prosmotr=true;

                        }

                if (glUser->ElementID_USER->AsInteger!=Forma_ZakazOf->DM->DocIDUSER_ZAK->AsInteger)
                        {
                        Forma_ZakazOf->Prosmotr=true;
                        }

                //но администратору разрешим
                if (glUser->ElementINTERF_USER->AsInteger==10)
                        {
                        Forma_ZakazOf->Prosmotr=false;
                        }
                Forma_ZakazOf->UpdateForm();
                Forma_ZakazOf->Show();

         }


}
//-----------------------------------------------------------------------------
void TFormaGurZakRest::DeleteZakaz(void)
{
TDMRegZak *RegZak=new TDMRegZak(Application);
if (!RegZak) return;
RegZak->OpenDoc(DM->TableID_ZAK->AsInteger) ;

bool RasrDel=false;
String V;
String Z;
if (glUser->ElementID_USER->AsInteger!=RegZak->DocIDUSER_ZAK->AsInteger)
        {
        V="Нельзя удалять чужие заказы!";
        Z="Удалить?";
        Application->MessageBox(V.c_str(),Z.c_str(),MB_OK);
        RasrDel=false;
        }
else
        {
        RasrDel=true;
        }

if (RegZak->DocSOST_ZAK->AsInteger!=2)
        {
        V="Нельзя удалять неоплаченные заказы!";
        Z="Удалить?";
        Application->MessageBox(V.c_str(),Z.c_str(),MB_OK);
        RasrDel=false;
        }

//но администратору разрешим
if ((glUser->ElementINTERF_USER->AsInteger==10) && (RegZak->DocSOST_ZAK->AsInteger==2))
        {

        String V="Удалить заказ?";
        String Z="Удалить?";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
                {
                RasrDel=true;
                }
        }

if (RasrDel==true)
        {
        RegZak->DeleteDoc(DM->TableID_ZAK->AsInteger);
        }

UpdateForm();
}
//--------------------------------------------------------------------------
void TFormaGurZakRest::OpenSpisokAllZakaz(void)
{
DM->AllUser=true;
UpdateForm();
}
//--------------------------------------------------------------------------
void TFormaGurZakRest::OpenSpisokMainZakas(void)
{

DM->AllUser=false;
DM->IdUser=glUser->ElementID_USER->AsInteger;
UpdateForm();

}
//----------------------------------------------------------------------------
void __fastcall TFormaGurZakRest::N6Click(TObject *Sender)
{
OpenSpisokMainZakas();
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurZakRest::BitBtn4Click(TObject *Sender)
{
OpenSpisokMainZakas();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurZakRest::N7Click(TObject *Sender)
{
OpenSpisokAllZakaz();
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurZakRest::BitBtn5Click(TObject *Sender)
{
OpenSpisokAllZakaz();
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurZakRest::N4Click(TObject *Sender)
{
DeleteZakaz();
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurZakRest::BitBtn3Click(TObject *Sender)
{
DeleteZakaz();
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurZakRest::BitBtn6Click(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurZakRest::DBGrid1DblClick(TObject *Sender)
{
OpenZakaz();
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurZakRest::DBGrid1KeyPress(TObject *Sender,
      char &Key)
{
if (Key==VK_RETURN)
        {
        OpenZakaz();
        }

if (Key==VK_ESCAPE)
        {
        Close();
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurZakRest::BitBtn2Click(TObject *Sender)
{

CreateNewZakaz();
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurZakRest::BitBtn1Click(TObject *Sender)
{
OpenZakaz();
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurZakRest::N8Click(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------

