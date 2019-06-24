//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMVesNom.h"
#include "UDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
extern String gl_prefiks_ib;
//---------------------------------------------------------------------------
__fastcall TDMSprVesNom::TDMSprVesNom(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMSprVesNom::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
}

//---------------------------------------------------------------------------

void  TDMSprVesNom::OpenTable(int NomRest)
{
WORD Year;
WORD Month;
WORD Day;
DecodeDate(Pos,Year,Month,Day);
IdNomRest=NomRest;
Table->Active=false;
Table->ParamByName("PARAM_IDNOMREST")->AsInteger=NomRest;
Table->ParamByName("PARAM_MONTH")->AsInteger=Month;
Table->Open();
}

//---------------------------------------------------------------------------

void  TDMSprVesNom::NewElement(int NomRest)
{
IdNomRest=NomRest;
Table->Insert();

}
//---------------------------------------------------------------------------

void  TDMSprVesNom::SaveIsmen()
{
try
        {
        Table->ApplyUpdates();
        IBTr->Commit();
        OpenTable(IdNom);
        }
catch(...)
        {
        ShowMessage("Ошибка в данных! Транзакция отменена!");
        }
}
//---------------------------------------------------------------------------

void  TDMSprVesNom::CancelIsmen()
{
try
        {
        Table->CancelUpdates();
        IBTr->Commit();
        OpenTable(IdNom);
        }
catch(...)
        {
        ShowMessage("Ошибка в данных! Транзакция отменена!");
        }
}
//---------------------------------------------------------------------------
void TDMSprVesNom::DeleteElement()
{
Table->Delete();
}
//-----------------------------------------------------------------------------
void __fastcall TDMSprVesNom::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;

//если значения не заданы то считаем что 1

if (KFEdProd==0){KFEdProd=1;}

if (KolEdProd==0) {KolEdProd=1;}

float KFKompl=TableKF_SPROD->AsFloat;
if(KFKompl==0){KFKompl=1;}

//общий сезонный коэф.
if (TableVALUE_SSEZKF->AsFloat==0)
        {
        TableSEZKF->AsFloat=1;
        }
else
        {
        TableSEZKF->AsFloat=TableVALUE_SSEZKF->AsFloat;
        }

// сезонный к на эту продукцию данного ингридиента
if (TableVALUE_SSEZKF_SPROD->AsFloat==0)
        {
        TableSEZKF_SPROD->AsFloat=1;
        }
else
        {
        TableSEZKF_SPROD->AsFloat=TableVALUE_SSEZKF_SPROD->AsFloat;
        }


TableNABASED->AsFloat=TableSEZKF_SPROD->AsFloat*TableSEZKF->AsFloat
                        *TableBKOL_SPROD->AsFloat*KFKompl/(KolEdProd*KFEdProd);

TableNNABASED->AsFloat=TableSEZKF_SPROD->AsFloat*TableSEZKF->AsFloat
                        *TableNKOL_SPROD->AsFloat*KFKompl/(KolEdProd*KFEdProd);

}
//---------------------------------------------------------------------------

void __fastcall TDMSprVesNom::TableSPIS_SPRODGetText(TField *Sender,
      AnsiString &Text, bool DisplayText)
{
if (TableSPIS_SPROD->AsInteger==1)
        {
        Text="Да";
        }
else
        {
        Text="Нет";
        }
}
//---------------------------------------------------------------------------

void __fastcall TDMSprVesNom::TableSPIS_SPRODSetText(TField *Sender,
      const AnsiString Text)
{
if(Text=="Да")
        {
        TableSPIS_SPROD->AsInteger=1;
        }
else
        {
        TableSPIS_SPROD->AsInteger=0;
        }
}
//---------------------------------------------------------------------------

void __fastcall TDMSprVesNom::TableNewRecord(TDataSet *DataSet)
{
TableIDNOM_SPROD->AsInteger=IdNom;
TableIDNOMREST_SPROD->AsInteger=IdNomRest;
TableSPIS_SPROD->AsInteger=1;
TableGID_SSPROD->AsString=
        gl_prefiks_ib+IntToStr(TableID_SPROD->AsInteger);
}
//---------------------------------------------------------------------------

