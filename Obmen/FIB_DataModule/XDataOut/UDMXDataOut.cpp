//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMXDataOut.h"
#include "UDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"
//extern TDM * glDM;
//---------------------------------------------------------------------------
__fastcall TDMXDataOut::TDMXDataOut(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMXDataOut::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;        
}
//---------------------------------------------------------------------------
void  TDMXDataOut::OpenTable(__int64 id_base)
{
IdBase=id_base;
Table->Active=false;
Table->ParamByName( "PARAM_IDBASE")->AsInt64=id_base;
Table->Open();

}

//---------------------------------------------------------------------------

void  TDMXDataOut::NewElement(__int64 id_base, __int64 id_table_ism)
{
IdBase=id_base;
IdTableIsm=id_table_ism;
Element->Active=false;
Element->Open();
Element->Insert();

}
//---------------------------------------------------------------------------

int TDMXDataOut::OpenElement(__int64 id)
{
Id=id;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  TDMXDataOut::SaveElement()
{
bool result=true;
Id=ElementID_XDATA_OUT->AsInt64;
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
		OpenElement(Id);
		result=true;
        }
        catch(Exception &exception)
				{
			   //	IBTrUpdate->Rollback();
			    result=false;
				Error=true;
				TextError=exception.Message;
				}
return result;
}
//---------------------------------------------------------------------------
void TDMXDataOut::DeleteElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
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
				IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
        }
}
//---------------------------------------------------------------------------

bool TDMXDataOut::AddRecordDataOut(__int64 id_base,
									__int64 id_table_ism,
									int type,      //1 изменение 2 квитанция
									int result)
{
bool Res=false;
Element->Active=false;
Element->Open();
Element->Insert();

ElementIDBASE_XDATA_OUT->AsInt64=id_base;
ElementIDTISM_XDATA_OUT->AsInt64=id_table_ism;
ElementTYPE_XDATA_OUT->AsInteger=type;
ElementRESULT_XDATA_OUT->AsInteger=result;
if (SaveElement()==true)
	{
	Res=true;
	}
else
	{
	Res=false;
	}
Element->Active=false;
return Res;
}
//---------------------------------------------------------------------------
__int64 TDMXDataOut::GetIdElement(__int64 id_base, __int64 id_table_ism)
{
__int64 result=0;
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select ID_XDATA_OUT from XDATA_OUT");
pFIBQ->SQL->Add(" where IDTISM_XDATA_OUT=:PARAM_IDTABLE and");
pFIBQ->SQL->Add(" IDBASE_XDATA_OUT=:PARAM_IDBASE ");
//IBQ->SQL->Add(" (IDMESSAGE_DATA_OUT IS NULL or IDMESSAGE_DATA_OUT=0)");
pFIBQ->ParamByName("PARAM_IDTABLE")->AsInt64=id_table_ism;
pFIBQ->ParamByName("PARAM_IDBASE")->AsInt64=id_base;
pFIBQ->ExecQuery();
result=pFIBQ->FieldByName("ID_XDATA_OUT")->AsInt64;
pFIBQ->Close();
return result;
}
//---------------------------------------------------------------------------
__int64 TDMXDataOut::GetMaxIdTableIsm(__int64 id_base)
{
__int64 result=0;
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select max(IDTISM_XDATA_OUT) AS IDMAX from XDATA_OUT");
pFIBQ->SQL->Add(" where IDBASE_XDATA_OUT=:PARAM_IDBASE ");
pFIBQ->ParamByName("PARAM_IDBASE")->AsInt64=id_base;
pFIBQ->ExecQuery();
result=pFIBQ->FieldByName("IDMAX")->AsInt64;
pFIBQ->Close();
return result;
}
//---------------------------------------------------------------------------
void __fastcall TDMXDataOut::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMXDataOut::ElementNewRecord(TDataSet *DataSet)
{
ElementIDBASE_XDATA_OUT->AsInt64=IdBase;
ElementIDTISM_XDATA_OUT->AsInt64=IdTableIsm;
}
//---------------------------------------------------------------------------

