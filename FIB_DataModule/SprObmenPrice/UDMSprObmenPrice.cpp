//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMSprObmenPrice.h"
#include "UDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
extern String gl_prefiks_ib;
//---------------------------------------------------------------------------
__fastcall TDMSprObmenPrice::TDMSprObmenPrice(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMSprObmenPrice::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;

}

//---------------------------------------------------------------------------

void  TDMSprObmenPrice::OpenTable(int id_base)
{
IdBase=id_base;
Table->ParamByName("PARAM_IDBASE")->AsInteger=id_base;
Table->Open();
}
//---------------------------------------------------------------------------

void  TDMSprObmenPrice::NewElement(int id_base)
{
IdBase=id_base;
Table->Insert();

}
//---------------------------------------------------------------------------

void  TDMSprObmenPrice::SaveIsmen()
{
try
        {
        Table->ApplyUpdates();
        IBTr->Commit();
        OpenTable(IdBase);
        }
catch(...)
        {
        ShowMessage("Ошибка в данных! Транзакция отменена!");
        }
}
//---------------------------------------------------------------------------

void  TDMSprObmenPrice::CancelIsmen()
{
try
        {
        Table->CancelUpdates();
        IBTr->Commit();
        OpenTable(IdBase);
        }
catch(...)
        {
        ShowMessage("Ошибка в данных! Транзакция отменена!");
        }
}
//---------------------------------------------------------------------------
void TDMSprObmenPrice::DeleteElement()
{
Table->Delete();
}

//----------------------------------------------------------------------------
void __fastcall TDMSprObmenPrice::TableNewRecord(TDataSet *DataSet)
{
TableGID_SSKLAD_OBMEN->AsString=
        gl_prefiks_ib+IntToStr(TableID_SSKLAD_OBMEN->AsInteger);
TableIDBASE_SSKLAD_OBMEN->AsInteger=IdBase;

}
//---------------------------------------------------------------------------

void __fastcall TDMSprObmenPrice::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;        
}
//---------------------------------------------------------------------------

