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
extern String gl_prefiks_ib;
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
void  TDMXDataOut::OpenTable(int id_base)
{
IdBase=id_base;
Table->Active=false;
Table->ParamByName( "PARAM_IDBASE")->AsInteger=id_base;
Table->Open();

}

//---------------------------------------------------------------------------

void  TDMXDataOut::NewElement(int id_base, int id_table_ism)
{
IdBase=id_base;
IdTableIsm=id_table_ism;
Element->Active=false;
Element->Open();
Element->Insert();

}
//---------------------------------------------------------------------------

int TDMXDataOut::OpenElement(int id)
{
Id=id;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInteger=id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

void  TDMXDataOut::SaveElement()
{
Id=ElementID_XDATA_OUT->AsInteger;
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
        OpenElement(Id);
        }
        catch(Exception &exception)
				{
			   //	IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
}
//---------------------------------------------------------------------------
void TDMXDataOut::DeleteElement(int id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInteger=id;
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

void TDMXDataOut::AddRecordDataOut(int id_base, int id_table_ism, int id_message)
{
Element->Active=false;
Element->Open();
Element->Insert();

ElementIDBASE_XDATA_OUT->AsInteger=id_base;
ElementIDTISM_XDATA_OUT->AsInteger=id_table_ism;
ElementIDMESSAGE_XDATA_OUT->AsInteger=id_message;
SaveElement();
Element->Active=false;

}
//---------------------------------------------------------------------------
int TDMXDataOut::GetIdElement(int id_base, int id_table_ism)
{
int result=0;
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select ID_XDATA_OUT from XDATA_OUT");
pFIBQ->SQL->Add(" where IDTISM_XDATA_OUT=:PARAM_IDTABLE and");
pFIBQ->SQL->Add(" IDBASE_XDATA_OUT=:PARAM_IDBASE ");
//IBQ->SQL->Add(" (IDMESSAGE_DATA_OUT IS NULL or IDMESSAGE_DATA_OUT=0)");
pFIBQ->ParamByName("PARAM_IDTABLE")->AsInteger=id_table_ism;
pFIBQ->ParamByName("PARAM_IDBASE")->AsInteger=id_base;
pFIBQ->ExecQuery();
result=pFIBQ->FieldByName("ID_XDATA_OUT")->AsInteger;
pFIBQ->Close();
return result;
}
//---------------------------------------------------------------------------
int TDMXDataOut::GetMaxIdTableIsm(int id_base)
{
int result=0;
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select max(IDTISM_XDATA_OUT) AS IDMAX from XDATA_OUT");
pFIBQ->SQL->Add(" where IDBASE_XDATA_OUT=:PARAM_IDBASE ");
pFIBQ->ParamByName("PARAM_IDBASE")->AsInteger=id_base;
pFIBQ->ExecQuery();
result=pFIBQ->FieldByName("IDMAX")->AsInteger;
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
ElementIDBASE_XDATA_OUT->AsInteger=IdBase;
ElementIDTISM_XDATA_OUT->AsInteger=IdTableIsm;
ElementGID_XDATA_OUT->AsString=
		gl_prefiks_ib+IntToStr(ElementID_XDATA_OUT->AsInteger);
}
//---------------------------------------------------------------------------

