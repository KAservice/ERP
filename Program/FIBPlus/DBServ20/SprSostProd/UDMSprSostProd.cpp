//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMSprSostProd.h"
#include "UDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"
extern String gl_prefiks_ib;
//---------------------------------------------------------------------------
__fastcall TDMSprSostProd::TDMSprSostProd(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMSprSostProd::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
}

//---------------------------------------------------------------------------

void  TDMSprSostProd::OpenTable(__int64 NomRest)
{
WORD Year;
WORD Month;
WORD Day;
DecodeDate(Pos,Year,Month,Day);
IdNomRest=NomRest;
Table->Active=false;
Table->ParamByName("PARAM_IDNOMREST")->AsInt64=NomRest;
Table->ParamByName("PARAM_MONTH")->AsInteger=Month;
Table->Open();
}

//---------------------------------------------------------------------------

void  TDMSprSostProd::NewElement(__int64 NomRest)
{
IdNomRest=NomRest;
Table->Insert();

}
//---------------------------------------------------------------------------

void  TDMSprSostProd::SaveIsmen()
{
try
        {
        Table->ApplyUpdates();
		if (IBTrUpdate->Active==true) IBTrUpdate->Commit();
        OpenTable(IdNom);
        }
        catch(Exception &exception)
				{
			   //	IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
}
//---------------------------------------------------------------------------

void  TDMSprSostProd::CancelIsmen()
{
try
        {
        Table->CancelUpdates();
		//IBTrUpdate->Commit();
        OpenTable(IdNom);
        }
        catch(Exception &exception)
				{
				//IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
}
//---------------------------------------------------------------------------
void TDMSprSostProd::DeleteElement()
{
Table->Delete();
}
//-----------------------------------------------------------------------------




void __fastcall TDMSprSostProd::TableCalcFields(TDataSet *DataSet)
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

void __fastcall TDMSprSostProd::TableNewRecord(TDataSet *DataSet)
{
//TableIDNOM_SPROD->AsInteger=IdNom;
TableIDNOMREST_SPROD->AsInt64=IdNomRest;
TableSPIS_SPROD->AsInteger=1;

}
//---------------------------------------------------------------------------

void __fastcall TDMSprSostProd::TableSPIS_SPRODGetText(TField *Sender,
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

void __fastcall TDMSprSostProd::TableSPIS_SPRODSetText(TField *Sender,
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


