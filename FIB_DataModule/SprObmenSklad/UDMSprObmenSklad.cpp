//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMSprObmenSklad.h"
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
__fastcall TDMSprObmenSklad::TDMSprObmenSklad(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMSprObmenSklad::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;

}

//---------------------------------------------------------------------------

void  TDMSprObmenSklad::OpenTable(__int64 id_base)
{
IdBase=id_base;
Table->ParamByName("PARAM_IDBASE")->AsInt64=id_base;
Table->Open();
}
//---------------------------------------------------------------------------

void  TDMSprObmenSklad::NewElement(__int64 id_base)
{
IdBase=id_base;
Table->Append();

}
//---------------------------------------------------------------------------

void  TDMSprObmenSklad::SaveIsmen()
{
try
        {
        Table->ApplyUpdates();
		IBTrUpdate->Commit();
        OpenTable(IdBase);
        }
catch(Exception &exception)
		{
				Error=true;
				TextError=exception.Message;
        }
}
//---------------------------------------------------------------------------

void  TDMSprObmenSklad::CancelIsmen()
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
void TDMSprObmenSklad::DeleteElement()
{
Table->Delete();
}

//----------------------------------------------------------------------------
void __fastcall TDMSprObmenSklad::Table1NewRecord(TDataSet *DataSet)
{
TableIDBASE_SSKLAD_OBMEN->AsInt64=IdBase;

}
//---------------------------------------------------------------------------

void __fastcall TDMSprObmenSklad::Table1CalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;        
}
//---------------------------------------------------------------------------

