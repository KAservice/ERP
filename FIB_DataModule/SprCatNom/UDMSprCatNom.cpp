//---------------------------------------------------------------------------

#include "glPCH.h"
#pragma hdrstop

#include "UDMSprCatNom.h"
#include "UDM.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
extern String gl_prefiks_ib;
//---------------------------------------------------------------------------
__fastcall TDMSprCatNom::TDMSprCatNom(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMSprCatNom::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprCatNom::ElementCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;
}
//---------------------------------------------------------------------------
void  TDMSprCatNom::OpenTable()
{
Table->Active=false;
Table->Open();
}

//---------------------------------------------------------------------------

void  TDMSprCatNom::NewElement()
{
Element->Active=false;
Element->Open();
Element->Insert();

}
//---------------------------------------------------------------------------

int TDMSprCatNom::OpenElement(int Id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInteger=Id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

void  TDMSprCatNom::SaveElement()
{
try
        {
        Element->ApplyUpdates();
        IBTr->Commit();
        }
catch(...)
        {
        Error=true;
        TextError="Не удалось записать элемент справочника!";
        }
}
//---------------------------------------------------------------------------
void TDMSprCatNom::DeleteElement(int Id)
{
Element->Active=false;
Element->ParamByName("ID")->AsInteger=Id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        Element->Delete();
        try
                {
                Element->ApplyUpdates();
                IBTr->Commit();
                }
        catch(...)
                {
                Error=true;
                TextError="Не удалось удалить элемент справочника!";
                }
        }
}

//---------------------------------------------------------------------------
void __fastcall TDMSprCatNom::TableCalcFields(TDataSet *DataSet)
{
Table->FieldByName("RECNO")->AsInteger=Table->RecNo;
}
//---------------------------------------------------------------------------

void __fastcall TDMSprCatNom::ElementNewRecord(TDataSet *DataSet)
{
ElementGID_SCATNOM->AsString=
        gl_prefiks_ib+IntToStr(ElementID_CATNOM->AsInteger);
}
//---------------------------------------------------------------------------

