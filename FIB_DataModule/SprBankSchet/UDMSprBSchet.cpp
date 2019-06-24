//---------------------------------------------------------------------------

#include "glPCH.h"
#pragma hdrstop

#include "UDMSprBSchet.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMSprBSchet::TDMSprBSchet(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
bool TDMSprBSchet::Init(void)
{
bool result=false;

IBTr->DefaultDatabase=DM_Connection->pFIBData;
IBTrUpdate->DefaultDatabase=DM_Connection->pFIBData;


Table->Database=DM_Connection->pFIBData;
Element->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//--------------------------------------------------------------------------------
void TDMSprBSchet::OpenTable()
{
Table->Active=false;
Table->ParamByName("IDFIRM")->AsInt64=IdFirm;
Table->Active=true;

}
//---------------------------------------------------------------------------

int TDMSprBSchet::OpenElement(__int64 Id)  //возвращает количество элементов
{
Element->Active=false;

Element->ParamByName("ID")->AsInt64=Id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//----------------------------------------------------------------------------

void TDMSprBSchet::NewElement()
{
Element->Active=false;
Element->Open();
Element->Insert();

}
//-----------------------------------------------------------------------------

bool TDMSprBSchet::SaveElement(void)
{
bool result;
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
		result=true;
        }
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	//IBTrUpdate->Rollback();
	result=false;
	}
return result;
}
//----------------------------------------------------------------------------

void TDMSprBSchet::DeleteElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("ID")->AsInt64=Id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        Element->Delete();
        try
                {
                Element->ApplyUpdates();
                IBTrUpdate->Commit();
                }
		catch(Exception &exception)
			{
			Error=true;
			TextError=exception.Message;
			IBTrUpdate->Rollback();
			}
        }
}
//----------------------------------------------------------------------------
void __fastcall TDMSprBSchet::DataModuleDestroy(TObject *Sender)
{
Element->Active=false;
Table->Active=false;
}
//---------------------------------------------------------------------------



void __fastcall TDMSprBSchet::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMSprBSchet::ElementNewRecord(TDataSet *DataSet)
{
ElementIDFIRMBSCHET->AsInt64=IdFirm;
}
//---------------------------------------------------------------------------

