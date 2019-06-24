//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMSprObmenInfBase.h"
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
__fastcall TDMSprObmenInfBase::TDMSprObmenInfBase(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMSprObmenInfBase::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;

}

//---------------------------------------------------------------------------

void  TDMSprObmenInfBase::OpenTable(__int64 id_base)
{
IdBase=id_base;
Table->ParamByName("PARAM_IDBASE")->AsInt64=id_base;
Table->Open();
}
//---------------------------------------------------------------------------

void  TDMSprObmenInfBase::NewElement(__int64 id_base)
{
IdBase=id_base;
Table->Append();

}
//---------------------------------------------------------------------------

void  TDMSprObmenInfBase::SaveIsmen()
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

void  TDMSprObmenInfBase::CancelIsmen()
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
void TDMSprObmenInfBase::DeleteElement()
{
Table->Delete();
}

//----------------------------------------------------------------------------


void __fastcall TDMSprObmenInfBase::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMSprObmenInfBase::TableNewRecord(TDataSet *DataSet)
{

TableIDBASE_STYPEPRICE_OBMEN->AsInt64=IdBase;	
}
//---------------------------------------------------------------------------

