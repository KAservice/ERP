//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMSprObmenTypeDoc.h"
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
__fastcall TDMSprObmenTypeDoc::TDMSprObmenTypeDoc(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMSprObmenTypeDoc::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;

}

//---------------------------------------------------------------------------

void  TDMSprObmenTypeDoc::OpenTable(__int64 id_base)
{
IdBase=id_base;
Table->ParamByName("PARAM_IDBASE")->AsInt64=id_base;
Table->Open();
}
//---------------------------------------------------------------------------

void  TDMSprObmenTypeDoc::NewElement(__int64 id_base)
{
IdBase=id_base;
Table->Append();

}
//---------------------------------------------------------------------------

void  TDMSprObmenTypeDoc::SaveIsmen()
{
try
        {
        Table->ApplyUpdates();
		IBTrUpdate->Commit();
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

void  TDMSprObmenTypeDoc::CancelIsmen()
{
try
        {
        Table->CancelUpdates();
		//IBTrUpdate->Commit();
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
void TDMSprObmenTypeDoc::DeleteElement()
{
Table->Delete();
}

//----------------------------------------------------------------------------


void __fastcall TDMSprObmenTypeDoc::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;  	
}
//---------------------------------------------------------------------------

void __fastcall TDMSprObmenTypeDoc::TableNewRecord(TDataSet *DataSet)
{
TableIDBASE_STYPEDOC_OBMEN->AsInt64=IdBase;	
}
//---------------------------------------------------------------------------

