//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMSprObmenTypePrice.h"
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
__fastcall TDMSprObmenTypePrice::TDMSprObmenTypePrice(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMSprObmenTypePrice::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;

}

//---------------------------------------------------------------------------

void  TDMSprObmenTypePrice::OpenTable(__int64 id_base)
{
IdBase=id_base;
Table->ParamByName("PARAM_IDBASE")->AsInt64=id_base;
Table->Open();
}
//---------------------------------------------------------------------------

void  TDMSprObmenTypePrice::NewElement(__int64 id_base)
{
IdBase=id_base;
Table->Append();

}
//---------------------------------------------------------------------------

void  TDMSprObmenTypePrice::SaveIsmen()
{
try
        {
		Table->ApplyUpdates();
		IBTrUpdate->Commit();
        OpenTable(IdBase);
        }
catch(Exception &exception)
		{
		//IBTrUpdate->Rollback();
		Error=true;
		TextError=exception.Message;
        }
}
//---------------------------------------------------------------------------

void  TDMSprObmenTypePrice::CancelIsmen()
{
try
        {
        Table->CancelUpdates();
		//IBTrUpdate->Commit();
        OpenTable(IdBase);
        }
catch(Exception &exception)
        {
	   //	IBTrUpdate->Rollback();
		Error=true;
		TextError=exception.Message;
        }
}
//---------------------------------------------------------------------------
void TDMSprObmenTypePrice::DeleteElement()
{
Table->Delete();
}

//----------------------------------------------------------------------------


void __fastcall TDMSprObmenTypePrice::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMSprObmenTypePrice::TableNewRecord(TDataSet *DataSet)
{

TableIDBASE_STYPEPRICE_OBMEN->AsInt64=IdBase;	
}
//---------------------------------------------------------------------------

